#include "direct_camera_movement_to_pos.h"
#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "malloc.h"
#include "script.h"
#include "script_movement.h"
#include "constants/event_objects.h"


u8* DoGenerateDirectCameraMovementsToPos(s16 x_initial, s16 y_initial, s16 x_goal, s16 y_goal, bool8 goTop, bool8 goRight)
{
    u8 * movements = AllocZeroed(MAX_DIRECT_CAMERA_MOVEMENTS);
    bool8 hasChangedX = FALSE;
    bool8 hasChangedY = FALSE;
    s16 current_x = x_initial;
    s16 current_y = y_initial;
    u8 currentPos = 0;
    while(x_goal != current_x || y_goal != current_y)
    {
        if(x_goal != current_x)
        {
            if(goRight)
            {
                current_x++;
            }
            else
            {
                current_x--;
            }
            hasChangedX = TRUE;
        }
        if(y_goal != current_y)
        {
            if(goTop)
            {
                current_y--;
            }
            else 
            {
                current_y++;
            }
            hasChangedY = TRUE;
        }

        if(hasChangedX && hasChangedY)
        {
            if(goTop && goRight)
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_UP_RIGHT;
            }
            else if(goTop)
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_UP_LEFT;
            }
            else if(goRight)
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_DOWN_RIGHT;
            }
            else 
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_DIAGONAL_DOWN_LEFT;
            }
        } 
        else if(hasChangedX) 
        {
            if(goRight)
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_RIGHT;
            }
            else
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_LEFT;
            }
        } 
        else 
        {
            if(goTop)
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_UP;
            }
            else
            {
                movements[currentPos] = MOVEMENT_ACTION_WALK_NORMAL_DOWN;
            }
        }
        currentPos++;
        hasChangedX = FALSE;
        hasChangedY = FALSE;
    }
    movements[currentPos] = MOVEMENT_ACTION_STEP_END;
    return movements;
}

u8* GenerateDirectCameraMovementsToPos(s16 x_initial, s16 y_initial, s16 x_goal, s16 y_goal)
{
    
    bool8 goTop;
    bool8 goRight;
   
    if(x_goal >= x_initial)
    {
        if(y_goal >= y_initial)
        {
            goTop = FALSE;
            goRight = TRUE;
        }
        else
        {
            goTop = TRUE;
            goRight = TRUE;
        }
    }
    else
    {
        if(y_goal >= y_initial)
        {
            goTop = FALSE;
            goRight = FALSE;
        }
        else
        {
            goTop = TRUE;
            goRight = FALSE;
        }
    }
    return DoGenerateDirectCameraMovementsToPos(x_initial, y_initial, x_goal, y_goal, goTop, goRight);
}


void DirectCameraMovementsToPos() 
{
    s16 x_goal = gSpecialVar_0x8004;
    s16 y_goal = gSpecialVar_0x8005;
    u8 mapNum = gSaveBlock1Ptr->location.mapNum;
    u8 mapGroup = gSaveBlock1Ptr->location.mapGroup;
    s16 x_initial = gSaveBlock1Ptr->pos.x;
    s16 y_initial = gSaveBlock1Ptr->pos.y;
    u8* movements = GenerateDirectCameraMovementsToPos(x_initial, y_initial,x_goal,y_goal);
    ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_CAMERA, mapNum, mapGroup, movements);
    SetMovingNpcId(OBJ_EVENT_ID_CAMERA);
}
