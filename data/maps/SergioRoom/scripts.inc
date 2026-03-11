SergioRoom_MapScripts::
# 13 "data/maps/SergioRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SergioRoom_OnTransition
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


SergioRoom_OnTransition::
# 18 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Sergio
	end


SergioRoom_OnWarp_Initial::
# 23 "data/maps/SergioRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 24 "data/maps/SergioRoom/scripts.pory"
	removeobject LOCALID_SERGIOROOM_SERGIO
# 25 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


SergioRoom_OnWarp_AbraReturns::
# 30 "data/maps/SergioRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 31 "data/maps/SergioRoom/scripts.pory"
	removeobject LOCALID_SERGIOROOM_SERGIO
# 32 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 33 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
	return


SergioRoom_OnWarp_AfterSergioBattle::
# 37 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 38 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 39 "data/maps/SergioRoom/scripts.pory"
	hideobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
	end


SergioRoom_OnFrame_AbraReturns::
# 44 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_OUT
# 45 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 46 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 47 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 48 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 49 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_WEST
# 50 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 51 "data/maps/SergioRoom/scripts.pory"
	release
# 52 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 53 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 54 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 55 "data/maps/SergioRoom/scripts.pory"
	release
# 56 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 57 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 58 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 59 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 60 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
# 61 "data/maps/SergioRoom/scripts.pory"
	release
	end


SergioRoom_OnFrame_AfterSergioBattle::
# 66 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_OUT
# 67 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 68 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 69 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 70 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 71 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 72 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
# 73 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_EAST
# 74 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 75 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SERGIO, DIR_WEST
# 76 "data/maps/SergioRoom/scripts.pory"
	release
# 77 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 78 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 79 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 80 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 81 "data/maps/SergioRoom/scripts.pory"
	release
# 82 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 83 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 84 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 85 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO
# 86 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 87 "data/maps/SergioRoom/scripts.pory"
	release
# 88 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 89 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_0
# 90 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 91 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, Common_Movement_WalkInPlaceDown
# 92 "data/maps/SergioRoom/scripts.pory"
	delay 10
# 93 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 94 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 95 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 96 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_2
# 97 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_OnFrame_AfterSergioBattle_Movement_3
# 98 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_4
# 99 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_5
# 100 "data/maps/SergioRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 101 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 102 "data/maps/SergioRoom/scripts.pory"
	warp MAP_HALL_OF_FAME, WARP_ID_HALL_OF_FAME
# 103 "data/maps/SergioRoom/scripts.pory"
	waitstate
# 104 "data/maps/SergioRoom/scripts.pory"
	releaseall
	end


SergioRoom_EventScript_Abra::
# 110 "data/maps/SergioRoom/scripts.pory"
	lock
# 111 "data/maps/SergioRoom/scripts.pory"
	release
# 112 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_ABRA, Common_Movement_FacePlayer
# 113 "data/maps/SergioRoom/scripts.pory"
	release
# 114 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 115 "data/maps/SergioRoom/scripts.pory"
	releaseall
# 116 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 117 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Abra_Text_0, MSGBOX_YESNO
# 118 "data/maps/SergioRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SergioRoom_EventScript_Abra_2
SergioRoom_EventScript_Abra_1:
# 131 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_Abra_2:
# 119 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_IN
# 120 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 121 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 122 "data/maps/SergioRoom/scripts.pory"
	release
# 123 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 124 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 125 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 126 "data/maps/SergioRoom/scripts.pory"
	release
# 127 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 128 "data/maps/SergioRoom/scripts.pory"
	warpsilent MAP_DRAGON_MOUNTAIN_TOP, WARP_ID_DRAGON_MOUNTAIN_TOP
# 129 "data/maps/SergioRoom/scripts.pory"
	waitstate
	goto SergioRoom_EventScript_Abra_1


SergioRoom_EventScript_SecurityGuardTrigger::
# 136 "data/maps/SergioRoom/scripts.pory"
	lock
# 137 "data/maps/SergioRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_EventScript_SecurityGuardTrigger_Movement_0
# 139 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_Text_0, MSGBOX_AUTOCLOSE
# 140 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 141 "data/maps/SergioRoom/scripts.pory"
	getdirectiontoface VAR_TEMP_A, LOCALID_PLAYER, LOCALID_SERGIOROOM_SECURITYGUARD
# 142 "data/maps/SergioRoom/scripts.pory"
	switch VAR_TEMP_A
# 143 "data/maps/SergioRoom/scripts.pory"
	case DIR_EAST, SergioRoom_EventScript_SecurityGuardTrigger_3
# 145 "data/maps/SergioRoom/scripts.pory"
	case DIR_WEST, SergioRoom_EventScript_SecurityGuardTrigger_4
SergioRoom_EventScript_SecurityGuardTrigger_1:
# 148 "data/maps/SergioRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 150 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 151 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance, MSGBOX_AUTOCLOSE
# 152 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 153 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SECURITYGUARD, DIR_SOUTH
# 154 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_SecurityGuardTrigger_3:
# 144 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto SergioRoom_EventScript_SecurityGuardTrigger_1

SergioRoom_EventScript_SecurityGuardTrigger_4:
# 146 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto SergioRoom_EventScript_SecurityGuardTrigger_1


SergioRoom_EventScript_SecurityGuard::
# 163 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance, MSGBOX_NPC
	end


# 89 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_0:
# 89 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 89 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 89 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 89 "data/maps/SergioRoom/scripts.pory"
	face_down
	step_end

# 93 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_1:
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 93 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
	step_end

# 96 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_2:
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_in_place_fast_up
	step_end

# 97 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_3:
# 97 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 97 "data/maps/SergioRoom/scripts.pory"
	walk_fast_down
# 97 "data/maps/SergioRoom/scripts.pory"
	face_left
	step_end

# 98 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_4:
# 98 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 98 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 98 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 98 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 99 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_5:
# 99 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 99 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 99 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 99 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 99 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 138 "data/maps/SergioRoom/scripts.pory"
SergioRoom_EventScript_SecurityGuardTrigger_Movement_0:
# 138 "data/maps/SergioRoom/scripts.pory"
	emote_double_exclamation_mark
# 138 "data/maps/SergioRoom/scripts.pory"
	face_player
# 138 "data/maps/SergioRoom/scripts.pory"
	delay_16
# 138 "data/maps/SergioRoom/scripts.pory"
	delay_16
# 138 "data/maps/SergioRoom/scripts.pory"
	delay_16
	step_end

SergioRoom_EventScript_Abra_Text_0:
# 117 "data/maps/SergioRoom/scripts.pory"
	.string "Parece que Abra quiere\n"
	.string "teletransportarte a otro lugar.\l"
	.string "¿Deseas ir?$"

SergioRoom_EventScript_SecurityGuardTrigger_Text_0:
# 139 "data/maps/SergioRoom/scripts.pory"
	.string "¡Alto ahí!$"

SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance::
# 158 "data/maps/SergioRoom/scripts.pory"
	.string "No puedes avanzar al hall de la fama\n"
	.string "hasta no derrotar a Serg!o.\p"
	.string "¿Dónde habrá ido?$"
