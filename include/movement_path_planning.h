#ifndef GUARD_MOVEMENT_PATH_PLANNING_H
#define GUARD_MOVEMENT_PATH_PLANNING_H
#include "event_object_movement.h"
#include "malloc.h"

// Movimientos básicos (x,y)
static const struct Coords16 moves[] = 
{
    { 0,  1},
    { 0, -1},
    {-1,  0},
    { 1,  0},
};

// Movimientos equivalentes a acciones del motor (caminata, etc.)
static const u32 moves_walk[] = 
{
    MOVEMENT_ACTION_WALK_NORMAL_DOWN, 
    MOVEMENT_ACTION_WALK_NORMAL_UP,
    MOVEMENT_ACTION_WALK_NORMAL_LEFT, 
    MOVEMENT_ACTION_WALK_NORMAL_RIGHT,
    MOVEMENT_ACTION_FACE_DOWN,
    MOVEMENT_ACTION_FACE_UP,
    MOVEMENT_ACTION_FACE_LEFT,
    MOVEMENT_ACTION_FACE_RIGHT,
};

// Guarda la ruta final a ejecutar
static EWRAM_DATA u8 *SolutionPath = NULL; 

#define MAXPATH   50   // Máx. longitud de ruta final
#define MAXNODES  100  // Máx. nodos en la cola/sets
#define HEUR_WEIGHT 1  // Peso para la heurística (A*, Dijkstra, etc.)

typedef struct Node {
    int state;
    struct Coords16 coords;
    int cost;
    u8 currentElevation;
    // En lugar de un arreglo estático, usamos un puntero:
    int *path; 
} Node;


//--------------------
// Estructura para "Set" (explorados)
//--------------------
typedef struct Set {
  unsigned int size;       // Cantidad de elementos
  unsigned int capacity;   // Capacidad total
  int *value;              // Arreglo dinámico con los estados
} Set;

//--------------------
// Estructura de cola de prioridad
//--------------------
typedef struct PriorityQueue {
  unsigned int size;       // Cantidad de elementos
  unsigned int capacity;   // Capacidad total
  float *priority;         // Prioridades
  struct Node *value;      // Nodos en la cola (cada uno con su path dinámico)
} PriorityQueue;


//--------------- Funciones para "Set" ---------------
void InitSet(Set *set, unsigned int capacity);
void FreeSet(Set *set);
int  isInSet(struct Set *set, int num);
void setInsert(struct Set *set, int num);

//--------------- Funciones para "PriorityQueue" ---------------
void InitPriorityQueue(PriorityQueue *queue, unsigned int capacity);
void FreePriorityQueue(PriorityQueue *queue);

//--------------- Utilidades varias ---------------
void swapNode(struct Node *a, struct Node *b);
void swap(float *a, float *b);
u32  my_abs(s32 x);
u32  L1Distance(s32 x0, s32 y0, s32 xf, s32 yf);
float CalcHeuristic(struct Node *node, s32 xgoal, s32 ygoal);

int  isInQueue(struct PriorityQueue *queue, int num);
void isInQueueWithHigherPath(struct PriorityQueue *queue, struct Node newNode);
void insert(struct PriorityQueue *queue, struct Node newNode, int heuristic);
struct Node pop(struct PriorityQueue *queue, int i);

//--------------- Nodos/hijos ---------------
u8   getElevation(u8 prevZ, s16 x, s16 y);
void getChild(const Node *parent, int move, Node *child);
void getSolution(const Node *node);

//--------------- Función principal ---------------
void MoveObjectToPosWithVars();

void MovementPathPlanning_MoveObjectToPos(u8 localId, u8 mapNum, u8 mapGroup, u8 x, u8 y, u8 facing);


#endif // GUARD_MOVEMENT_PATH_PLANNING_H
