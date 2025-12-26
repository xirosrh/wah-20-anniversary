SergioRoom_MapScripts::
# 4 "data/maps/SergioRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SergioRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 7 "data/maps/SergioRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SergioRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SergioRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, SergioRoom_OnWarp
	.2byte 0

SergioRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, SergioRoom_OnFrame
	.2byte 0


SergioRoom_OnWarp::
# 14 "data/maps/SergioRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SERGIO, SergioRoom_OnWarp_2
# 18 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 19 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 20 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
# 21 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
SergioRoom_OnWarp_1:
	end

SergioRoom_OnWarp_2:
# 15 "data/maps/SergioRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 16 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto SergioRoom_OnWarp_1


SergioRoom_OnFrame::
# 27 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 28 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 29 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 30 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 31 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 32 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
# 33 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_EAST
# 34 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 35 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SERGIO, DIR_WEST
# 36 "data/maps/SergioRoom/scripts.pory"
	release
# 37 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 38 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 39 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 40 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 41 "data/maps/SergioRoom/scripts.pory"
	release
# 42 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 43 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 44 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 45 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO
# 46 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 47 "data/maps/SergioRoom/scripts.pory"
	release
# 48 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 49 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_Movement_0
# 50 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 51 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, Common_Movement_WalkInPlaceDown
# 52 "data/maps/SergioRoom/scripts.pory"
	delay 10
# 53 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_Movement_1
# 54 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_Movement_2
# 55 "data/maps/SergioRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 56 "data/maps/SergioRoom/scripts.pory"
	warp MAP_HALL_OF_FAME, WARP_ID_HALL_OF_FAME
# 57 "data/maps/SergioRoom/scripts.pory"
	waitstate
# 58 "data/maps/SergioRoom/scripts.pory"
	releaseall
	end


SergioRoom_EventScript_Abra::
# 64 "data/maps/SergioRoom/scripts.pory"
	lock
# 65 "data/maps/SergioRoom/scripts.pory"
	release
# 66 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_ABRA, Common_Movement_FacePlayer
# 67 "data/maps/SergioRoom/scripts.pory"
	release
# 68 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 69 "data/maps/SergioRoom/scripts.pory"
	releaseall
# 70 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 71 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Abra_Text_0, MSGBOX_YESNO
# 72 "data/maps/SergioRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SergioRoom_EventScript_Abra_2
SergioRoom_EventScript_Abra_1:
# 84 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_Abra_2:
# 73 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 74 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 75 "data/maps/SergioRoom/scripts.pory"
	release
# 76 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 77 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 78 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 79 "data/maps/SergioRoom/scripts.pory"
	release
# 80 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 81 "data/maps/SergioRoom/scripts.pory"
	warp MAP_DRAGON_MOUNTAIN_TOP, WARP_ID_DRAGON_MOUNTAIN_TOP
# 82 "data/maps/SergioRoom/scripts.pory"
	waitstate
	goto SergioRoom_EventScript_Abra_1


# 49 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_Movement_0:
# 49 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 49 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 49 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 49 "data/maps/SergioRoom/scripts.pory"
	face_down
	step_end

# 53 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_Movement_1:
# 53 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 53 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 53 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 53 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 53 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 53 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 53 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 54 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_Movement_2:
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_in_place_fast_up
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 54 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 54 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

SergioRoom_EventScript_Abra_Text_0:
# 71 "data/maps/SergioRoom/scripts.pory"
	.string "Parece que Abra quiere\n"
	.string "teletransportarte a otro lugar.\l"
	.string "¿Deseas ir?$"
