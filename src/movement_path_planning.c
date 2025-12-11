#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "fieldmap.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_specials.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"
#include "constants/maps.h"

#include "movement_path_planning.h"
#include "malloc.h"



// --------------------------------------------------------------------
//           IMPLEMENTACIÓN DE LAS ESTRUCTURAS DINÁMICAS
// --------------------------------------------------------------------

// "Set" (explorados)
void InitSet(Set *set, unsigned int capacity)
{
    set->size = 0;
    set->capacity = capacity;
    // Reservamos espacio para "capacity" enteros (estados)
    set->value = (int *)AllocZeroed(sizeof(int) * capacity);
}

void FreeSet(Set *set)
{
    if (set->value != NULL)
        Free(set->value);

    set->value = NULL;
    set->size = 0;
    set->capacity = 0;
}


// "PriorityQueue"
void InitPriorityQueue(PriorityQueue *queue, unsigned int capacity)
{
    int i;
    queue->size = 0;
    queue->capacity = capacity;

    // Reservamos espacio para las prioridades (float) y los nodos (Node)
    queue->priority = (float *)AllocZeroed(sizeof(float) * capacity);
    queue->value    = (Node  *)AllocZeroed(sizeof(Node)  * capacity);

    // IMPORTANTE: Cada nodo de 'queue->value' debe reservar
    // su propio array 'path' dinámico. 
    for (i = 0; i < (int)capacity; i++)
    {
        // Reservamos un array de 'MAXPATH' para el campo 'path'
        queue->value[i].path = (int *)AllocZeroed(sizeof(int) * MAXPATH);
    }
}

void FreePriorityQueue(PriorityQueue *queue)
{
    if (queue->value != NULL)
    {
        // Liberamos 'path' de cada nodo
        for (int i = 0; i < (int)queue->capacity; i++)
        {
            if (queue->value[i].path != NULL)
                Free(queue->value[i].path);
            queue->value[i].path = NULL;
        }
        Free(queue->value);
    }

    if (queue->priority != NULL)
        Free(queue->priority);

    queue->priority = NULL;
    queue->value    = NULL;
    queue->size     = 0;
    queue->capacity = 0;
}


// --------------------------------------------------------------------
//                      FUNCIONES AUXILIARES
// --------------------------------------------------------------------

void swapNode(struct Node *a, struct Node *b)
{
    Node temp = *b;
    *b = *a;
    *a = temp;
}

void swap(float *a, float *b)
{
    float temp = *b;
    *b = *a;
    *a = temp;
}

u32 my_abs(s32 x)
{
    return (x < 0) ? (u32)(-x) : (u32)x;
}

u32 L1Distance(s32 x0, s32 y0, s32 xf, s32 yf)
{
    //Manhatan distance used as heuristic
    return my_abs(x0 - xf) + my_abs(y0 - yf);
}


float CalcHeuristic(struct Node *node, s32 xgoal,s32 ygoal)
{
    float heuristic = HEUR_WEIGHT*L1Distance(node->coords.x, node->coords.y, xgoal, ygoal);
    heuristic *= (1.0f + 1.0f / MAXPATH);
    return heuristic;
}



// --------------------------------------------------------------------
//                        GESTIÓN DEL SET
// --------------------------------------------------------------------

int isInSet(struct Set *set, int num)
{
    int i;
    for (i = 0; i < (int)set->size; i++)
    {
        if (set->value[i] == num)
            return 1;
    }
    return 0;
}

void setInsert(struct Set *set, int num)
{
    if (set->size >= set->capacity)
        return; // Evitar overflow (o re-dimensionar en tu caso)
    
    if (!isInSet(set, num))
    {
        set->value[set->size] = num;
        set->size++;
    }
}


// --------------------------------------------------------------------
//                   GESTIÓN DE LA COLA DE PRIORIDAD
// --------------------------------------------------------------------

// Ajusta el heap (min-heap) a partir de índice i
static void heapify(struct PriorityQueue *queue, int i)
{
    if (queue->size <= 1)
        return;

    int shortest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < (int)queue->size && queue->priority[l] < queue->priority[shortest])
        shortest = l;
    if (r < (int)queue->size && queue->priority[r] < queue->priority[shortest])
        shortest = r;

    if (shortest != i)
    {
        swap(&queue->priority[i], &queue->priority[shortest]);
        swapNode(&queue->value[i], &queue->value[shortest]);
        heapify(queue, shortest);
    }
}

int isInQueue(struct PriorityQueue *queue, int num)
{
    int i;
    for (i = 0; i < (int)queue->size; i++)
    {
        if (queue->value[i].state == num)
            return 1;
    }
    return 0;
}

void isInQueueWithHigherPath(struct PriorityQueue *queue, struct Node newNode)
{
    int i, j;
    for (i = 0; i < (int)queue->size; i++)
    {
        if (queue->value[i].state == newNode.state)
        {
            // ¿El nuevo nodo tiene mejor (menor) "cost"?
            if (queue->value[i].cost > newNode.cost)
            {
                // Ajustamos la prioridad
                queue->priority[i] -= (queue->value[i].cost - newNode.cost);

                // Copiamos toda la información de 'newNode' (profundo):
                queue->value[i].state = newNode.state;
                queue->value[i].coords = newNode.coords;
                queue->value[i].cost   = newNode.cost;
                queue->value[i].currentElevation = newNode.currentElevation;

                // Copiamos el path dinámico
                // (newNode.path pertenece a un Node "afuera" - hay que copiar su contenido)
                // Se asume que newNode.path[i] está correcto hasta newNode.cost
                // Copiamos siempre hasta MAXPATH para no dejar basura
                for (j = 0; j < MAXPATH; j++)
                {
                    queue->value[i].path[j] = newNode.path[j];
                }

                // Re-heapify
                for (j = queue->size / 2 - 1; j >= 0; j--)
                    heapify(queue, j);
                return;
            }
        }
    }
}

// Inserta un nuevo nodo
void insert(struct PriorityQueue *queue, struct Node newNode, int heuristic)
{
    if (queue->size >= queue->capacity)
        return; // Overflow de la cola

    // Calculamos la prioridad
    float priorityValue = newNode.cost + heuristic;

    // Colocamos al final
    int idx = queue->size;
    queue->priority[idx] = priorityValue;

    // Copiamos la información del nodo (deep copy)
    queue->value[idx].state           = newNode.state;
    queue->value[idx].coords          = newNode.coords;
    queue->value[idx].cost            = newNode.cost;
    queue->value[idx].currentElevation= newNode.currentElevation;

    // Copiamos el path
    for (int i = 0; i < MAXPATH; i++)
    {
        queue->value[idx].path[i] = newNode.path[i];
    }

    // Incrementamos tamaño
    queue->size++;

    // Reajustamos el heap bottom-up
    for (int i = queue->size / 2 - 1; i >= 0; i--)
        heapify(queue, i);
}

// Extrae el nodo con menor prioridad
struct Node pop(struct PriorityQueue *queue, int i)
{
    // Copiamos el nodo a retornar
    struct Node element = queue->value[i];

    // Intercambiamos con el último en la cola
    swapNode(&queue->value[i], &queue->value[queue->size - 1]);
    swap(&queue->priority[i], &queue->priority[queue->size - 1]);

    // Reducimos tamaño
    queue->size--;

    // Re-heapify
    for (int j = queue->size / 2 - 1; j >= 0; j--)
        heapify(queue, j);

    return element;
}


// --------------------------------------------------------------------
//               FUNCIONES DE ELEVACIÓN, CREAR HIJOS, ETC
// --------------------------------------------------------------------

u8 getElevation(u8 prevZ, s16 x, s16 y)
{
    // Si la elevación es 0xF, se mantiene la anterior
    u8 mapZ = MapGridGetElevationAt(x + 7, y + 7);
    return (mapZ == 0xF) ? prevZ : mapZ;
}

/**
 * getChild
 *  Genera un nodo hijo (child) a partir del 'parent', aplicando el movimiento i.
 *  Copia el path del padre y añade el nuevo movimiento al final.
 */
void getChild(const Node *parent, int move, Node *child)
{
    int i;
    child->coords.x = parent->coords.x + moves[move].x;
    child->coords.y = parent->coords.y + moves[move].y;
    child->cost = parent->cost + 1;

    child->currentElevation = getElevation(parent->currentElevation,
                                           parent->coords.x,
                                           parent->coords.y);

    // Copiamos la ruta anterior (hasta parent->cost)
    for (i = 0; i < parent->cost; i++)
    {
        child->path[i] = parent->path[i];
    }

    // Agregamos el nuevo movimiento
    child->path[parent->cost] = move;
}

void CalculateSolution(const Node *node)
{
    int i;
    SolutionPath = AllocZeroed(node->cost + 1);

    for (i = 0; i < node->cost; i++)
        SolutionPath[i] = moves_walk[node->path[i]];

    SolutionPath[node->cost] = MOVEMENT_ACTION_STEP_END;
}


// --------------------------------------------------------------------
//                       BÚSQUEDA DE CAMINO
// --------------------------------------------------------------------

static int isMoveNotPossible(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir, u8 currentElevation)
{
    return CheckCollisionAtCoords(objectEvent, x + 7, y + 7, dir + 1, currentElevation);
}

/**
 * searchPath
 *  Realiza la búsqueda (A*, Dijkstra, etc.) y rellena SolutionPath si se encuentra ruta.
 *  Devuelve 1 si éxito, 0 si falla.
 */
static int searchPath(struct ObjectEvent *objectEvent, s32 x, s32 y, s32 facing)
{
    // Creamos nodos "locales" para manipular en el bucle:
    // OJO: Como cada Node usa path dinámico, debemos reservar path también para estos
    Node startNode = {0}, node = {0}, child = {0};
    startNode.path = AllocZeroed(sizeof(int) * MAXPATH);
    node.path      = AllocZeroed(sizeof(int) * MAXPATH);
    child.path     = AllocZeroed(sizeof(int) * MAXPATH);

    // Estructuras dinámicas (Set y PriorityQueue)
    PriorityQueue frontier;
    Set explored;

    // Inicializamos
    InitSet(&explored, MAXNODES);
    InitPriorityQueue(&frontier, MAXNODES);

    u32 MapWidth = GetMapLayout(gSaveBlock1Ptr->mapLayoutId)->width;

    // Nodo inicial
    startNode.coords.x = objectEvent->currentCoords.x - 7;
    startNode.coords.y = objectEvent->currentCoords.y - 7;
    startNode.state    = startNode.coords.x + MapWidth * startNode.coords.y;
    startNode.cost     = 0;
    startNode.currentElevation = getElevation(objectEvent->currentElevation,
                                              startNode.coords.x,
                                              startNode.coords.y);

    // Insertamos en la cola
    insert(&frontier, startNode, CalcHeuristic(&startNode, x, y));

    // Bucle principal
    while (1)
    {
        // Si la cola está vacía, no hay ruta
        if (frontier.size == 0)
        {
            // Liberamos todo antes de salir
            FreeSet(&explored);
            FreePriorityQueue(&frontier);

            Free(startNode.path);
            Free(node.path);
            Free(child.path);
            return 0;
        }

        // Sacamos el nodo con menor prioridad
        node = pop(&frontier, 0);

        if (node.coords.x == x && node.coords.y == y)
        {
            CalculateSolution(&node);

            // Liberar estructuras
            FreeSet(&explored);
            FreePriorityQueue(&frontier);

            // Liberar paths de los nodos locales
            Free(startNode.path);
            Free(node.path);   // Ojo, 'node.path' ya apunta al array interno 
                               // copiado en pop(), pero está bien liberarlo
            Free(child.path);

            return 1;
        }

        // Marcamos como explorado
        setInsert(&explored, node.state);

        // Generamos hijos si no superamos la longitud máxima
        if (node.cost < MAXPATH)
        {
            int i;
            for (i = 0; i < 4; i++) //4 = moves_count
            {
                // Evita retrocesos directos (opcional)
                if (node.cost == 0 || !(i + node.path[node.cost - 1] == 1 || i + node.path[node.cost - 1] == 5))
                {
                    // Si el movimiento es posible
                    if (!isMoveNotPossible(objectEvent,
                                           node.coords.x + moves[i].x,
                                           node.coords.y + moves[i].y,
                                           i,
                                           node.currentElevation))
                    {
                        // Llenamos 'child' copiando 'node' + movimiento i
                        // Primero, limpiamos child para que no se mezclen rutas previas
                        // (o podríamos hacerlo en getChild) 
                        for (int c = 0; c < MAXPATH; c++)
                            child.path[c] = 0;

                        getChild(&node, i, &child);
                        child.state = child.coords.x + MapWidth * child.coords.y;

                        // Si el siguiente movimiento es el objetivo, agregamos "face" si falta
                        if (child.coords.x == x && child.coords.y == y)
                        {
                            if ((i + 1) != facing)
                            {
                                // Añade la acción "face" al final
                                child.path[child.cost] = facing - 1 + 4; // 4 = moves_count
                                child.cost++;
                            }
                        }

                        if (!isInSet(&explored, child.state) && !isInQueue(&frontier, child.state))
                        {
                            // Insertamos en la cola
                            insert(&frontier, child, CalcHeuristic(&child, x, y));
                        }
                        else if (isInQueue(&frontier, child.state))
                        {
                            // Si ya está en la cola, vemos si tenemos un camino mejor
                            isInQueueWithHigherPath(&frontier, child);
                        }
                    }
                }
            }
        }
    }
}


// Función pública que llama al pathfinding y, si hay ruta, la ejecuta
void MovementPathPlanning_MoveObjectToPos(u8 localId, u8 mapNum, u8 mapGroup, u8 x_goal, u8 y_goal, u8 facing)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        if (searchPath(&gObjectEvents[objectEventId], x_goal, y_goal, facing))
        {
            ScriptMovement_StartObjectMovementScript(localId, mapNum, mapGroup, SolutionPath);
            SetMovingNpcId(localId);
        }
    }
}

void MoveObjectToPosWithVars()
{
    u16 localId = gSpecialVar_0x8008;
    u16 posX    = gSpecialVar_0x8004;
    u16 posY    = gSpecialVar_0x8005;
    u16 facing  = gSpecialVar_0x8009;

    MovementPathPlanning_MoveObjectToPos(localId,
                                         gSaveBlock1Ptr->location.mapNum,
                                         gSaveBlock1Ptr->location.mapGroup,
                                         posX,
                                         posY,
                                         facing);
}
