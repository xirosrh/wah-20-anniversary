SergioRoom_MapScripts::
# 4 "data/maps/SergioRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SergioRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 9 "data/maps/SergioRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SergioRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SergioRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_SERGIO_ROOM_STATE, 0, SergioRoom_OnWarp_Initial
# 6 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_SERGIO_ROOM_STATE, 1, SergioRoom_OnWarp_AbraReturns
# 7 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_SERGIO_ROOM_STATE, 2, SergioRoom_OnWarp_AfterSergioBattle
	.2byte 0

SergioRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 10 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_SERGIO_ROOM_STATE, 1, SergioRoom_OnFrame_AbraReturns
# 11 "data/maps/SergioRoom/scripts.pory"
	map_script_2 VAR_SERGIO_ROOM_STATE, 2, SergioRoom_OnFrame_AfterSergioBattle
	.2byte 0


SergioRoom_OnWarp_Initial::
# 19 "data/maps/SergioRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 20 "data/maps/SergioRoom/scripts.pory"
	removeobject LOCALID_SERGIOROOM_SERGIO
# 21 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


SergioRoom_OnWarp_AbraReturns::
# 26 "data/maps/SergioRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 27 "data/maps/SergioRoom/scripts.pory"
	removeobject LOCALID_SERGIOROOM_SERGIO
# 28 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 29 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
	return


SergioRoom_OnWarp_AfterSergioBattle::
# 33 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 34 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 35 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
	end


SergioRoom_OnFrame_AbraReturns::
# 40 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 41 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 42 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 43 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 44 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_WEST
# 45 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 46 "data/maps/SergioRoom/scripts.pory"
	release
# 47 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 48 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 49 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 50 "data/maps/SergioRoom/scripts.pory"
	release
# 51 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 52 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 53 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 54 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 55 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
# 56 "data/maps/SergioRoom/scripts.pory"
	release
	end


SergioRoom_OnFrame_AfterSergioBattle::
# 61 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 62 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 63 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 64 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 65 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 66 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
# 67 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_EAST
# 68 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 69 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SERGIO, DIR_WEST
# 70 "data/maps/SergioRoom/scripts.pory"
	release
# 71 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 72 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 73 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 74 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 75 "data/maps/SergioRoom/scripts.pory"
	release
# 76 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 77 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 78 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 79 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO
# 80 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 81 "data/maps/SergioRoom/scripts.pory"
	release
# 82 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 83 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_0
# 84 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 85 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, Common_Movement_WalkInPlaceDown
# 86 "data/maps/SergioRoom/scripts.pory"
	delay 10
# 87 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 88 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 89 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 90 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_2
# 91 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_OnFrame_AfterSergioBattle_Movement_3
# 92 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_4
# 93 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_5
# 94 "data/maps/SergioRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 95 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 96 "data/maps/SergioRoom/scripts.pory"
	warp MAP_HALL_OF_FAME, WARP_ID_HALL_OF_FAME
# 97 "data/maps/SergioRoom/scripts.pory"
	waitstate
# 98 "data/maps/SergioRoom/scripts.pory"
	releaseall
	end


SergioRoom_EventScript_Abra::
# 104 "data/maps/SergioRoom/scripts.pory"
	lock
# 105 "data/maps/SergioRoom/scripts.pory"
	release
# 106 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_ABRA, Common_Movement_FacePlayer
# 107 "data/maps/SergioRoom/scripts.pory"
	release
# 108 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 109 "data/maps/SergioRoom/scripts.pory"
	releaseall
# 110 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 111 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Abra_Text_0, MSGBOX_YESNO
# 112 "data/maps/SergioRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SergioRoom_EventScript_Abra_2
SergioRoom_EventScript_Abra_1:
# 124 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_Abra_2:
# 113 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 114 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 115 "data/maps/SergioRoom/scripts.pory"
	release
# 116 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 117 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 118 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 119 "data/maps/SergioRoom/scripts.pory"
	release
# 120 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 121 "data/maps/SergioRoom/scripts.pory"
	warp MAP_DRAGON_MOUNTAIN_TOP, WARP_ID_DRAGON_MOUNTAIN_TOP
# 122 "data/maps/SergioRoom/scripts.pory"
	waitstate
	goto SergioRoom_EventScript_Abra_1


SergioRoom_EventScript_SecurityGuardTrigger::
# 129 "data/maps/SergioRoom/scripts.pory"
	release
	end


SergioRoom_EventScript_SecurityGuard::
# 134 "data/maps/SergioRoom/scripts.pory"
	release
	end


# 83 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_0:
# 83 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 83 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 83 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 83 "data/maps/SergioRoom/scripts.pory"
	face_down
	step_end

# 87 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_1:
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
	step_end

# 90 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_2:
# 90 "data/maps/SergioRoom/scripts.pory"
	walk_in_place_fast_up
	step_end

# 91 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_3:
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_down
# 91 "data/maps/SergioRoom/scripts.pory"
	face_left
	step_end

# 92 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_4:
# 92 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 92 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 92 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 92 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 93 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_5:
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

SergioRoom_EventScript_Abra_Text_0:
# 111 "data/maps/SergioRoom/scripts.pory"
	.string "Parece que Abra quiere\n"
	.string "teletransportarte a otro lugar.\l"
	.string "¿Deseas ir?$"
