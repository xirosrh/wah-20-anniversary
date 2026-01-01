#include "direct_movement_to_pos.h"
#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "malloc.h"
#include "script.h"
#include "script_movement.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"

static u8 *GenerateDirectMovementsToPos(s16 x_initial, s16 y_initial, s16 x_goal, s16 y_goal)
{
    u8 *movements = AllocZeroed(MAX_DIRECT_MOVEMENTS_TO_POS);
    u8 currentPos = 0;

    while (x_goal != x_initial && currentPos + 1 < MAX_DIRECT_MOVEMENTS_TO_POS)
    {
        if (x_goal > x_initial)
        {
            movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_RIGHT;
            x_initial++;
        }
        else
        {
            movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_LEFT;
            x_initial--;
        }
        currentPos++;
    }

    while (y_goal != y_initial && currentPos + 1 < MAX_DIRECT_MOVEMENTS_TO_POS)
    {
        if (y_goal > y_initial)
        {
            movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_DOWN;
            y_initial++;
        }
        else
        {
            movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_UP;
            y_initial--;
        }
        currentPos++;
    }

    movements[currentPos] = MOVEMENT_ACTION_STEP_END;
    return movements;
}

void DirectMovementToPos(void)
{
    u8 localId = gSpecialVar_0x8008;
    s16 x_goal = gSpecialVar_0x8004;
    s16 y_goal = gSpecialVar_0x8005;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    u8 objEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objEventId))
        return;

    s16 x_initial = gObjectEvents[objEventId].currentCoords.x - MAP_OFFSET;
    s16 y_initial = gObjectEvents[objEventId].currentCoords.y - MAP_OFFSET;
    ScriptMovement_StartObjectMovementScript(localId, mapNum, mapGroup, GenerateDirectMovementsToPos(x_initial, y_initial, x_goal, y_goal));
    SetMovingNpcId(localId);
}
