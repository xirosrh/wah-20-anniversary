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
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 41 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_OUT
# 42 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 43 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 44 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 45 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 46 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_WEST
# 47 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 48 "data/maps/SergioRoom/scripts.pory"
	release
# 49 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 50 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 51 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 52 "data/maps/SergioRoom/scripts.pory"
	release
# 53 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 54 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 55 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteNormal
# 56 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 57 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
# 58 "data/maps/SergioRoom/scripts.pory"
	release
	end


SergioRoom_OnFrame_AfterSergioBattle::
# 63 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 64 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_OUT
# 65 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 66 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 67 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 68 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 69 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 70 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
# 71 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_EAST
# 72 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 73 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SERGIO, DIR_WEST
# 74 "data/maps/SergioRoom/scripts.pory"
	release
# 75 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 76 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 77 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 78 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 79 "data/maps/SergioRoom/scripts.pory"
	release
# 80 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 81 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 82 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteNormal
# 83 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO
# 84 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 85 "data/maps/SergioRoom/scripts.pory"
	release
# 86 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 87 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_0
# 88 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 89 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, Common_Movement_WalkInPlaceDown
# 90 "data/maps/SergioRoom/scripts.pory"
	delay 10
# 91 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 92 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 93 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_2
# 95 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_OnFrame_AfterSergioBattle_Movement_3
# 96 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_4
# 97 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_5
# 98 "data/maps/SergioRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 99 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 100 "data/maps/SergioRoom/scripts.pory"
	warp MAP_HALL_OF_FAME, WARP_ID_HALL_OF_FAME
# 101 "data/maps/SergioRoom/scripts.pory"
	waitstate
# 102 "data/maps/SergioRoom/scripts.pory"
	releaseall
	end


SergioRoom_EventScript_Abra::
# 108 "data/maps/SergioRoom/scripts.pory"
	lock
# 109 "data/maps/SergioRoom/scripts.pory"
	release
# 110 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_ABRA, Common_Movement_FacePlayer
# 111 "data/maps/SergioRoom/scripts.pory"
	release
# 112 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 113 "data/maps/SergioRoom/scripts.pory"
	releaseall
# 114 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 115 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Abra_Text_0, MSGBOX_YESNO
# 116 "data/maps/SergioRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SergioRoom_EventScript_Abra_2
SergioRoom_EventScript_Abra_1:
# 130 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_Abra_2:
# 117 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 118 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_IN
# 119 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 120 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 121 "data/maps/SergioRoom/scripts.pory"
	release
# 122 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 123 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 124 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 125 "data/maps/SergioRoom/scripts.pory"
	release
# 126 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 127 "data/maps/SergioRoom/scripts.pory"
	warpsilent MAP_DRAGON_MOUNTAIN_TOP, WARP_ID_DRAGON_MOUNTAIN_TOP
# 128 "data/maps/SergioRoom/scripts.pory"
	waitstate
	goto SergioRoom_EventScript_Abra_1


SergioRoom_EventScript_SecurityGuardTrigger::
# 135 "data/maps/SergioRoom/scripts.pory"
	lock
# 136 "data/maps/SergioRoom/scripts.pory"
	playse SE_PIN
# 137 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_EventScript_SecurityGuardTrigger_Movement_0
# 138 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_Text_0, MSGBOX_AUTOCLOSE
# 139 "data/maps/SergioRoom/scripts.pory"
	delay 48
# 140 "data/maps/SergioRoom/scripts.pory"
	getdirectiontoface VAR_TEMP_A, LOCALID_PLAYER, LOCALID_SERGIOROOM_SECURITYGUARD
# 141 "data/maps/SergioRoom/scripts.pory"
	switch VAR_TEMP_A
# 142 "data/maps/SergioRoom/scripts.pory"
	case DIR_EAST, SergioRoom_EventScript_SecurityGuardTrigger_3
# 144 "data/maps/SergioRoom/scripts.pory"
	case DIR_WEST, SergioRoom_EventScript_SecurityGuardTrigger_4
SergioRoom_EventScript_SecurityGuardTrigger_1:
# 147 "data/maps/SergioRoom/scripts.pory"
	playse SE_PIN
# 148 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 149 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 150 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance, MSGBOX_AUTOCLOSE
# 151 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 152 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SECURITYGUARD, DIR_SOUTH
# 153 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_SecurityGuardTrigger_3:
# 143 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto SergioRoom_EventScript_SecurityGuardTrigger_1

SergioRoom_EventScript_SecurityGuardTrigger_4:
# 145 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto SergioRoom_EventScript_SecurityGuardTrigger_1


SergioRoom_EventScript_SecurityGuard::
# 162 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance, MSGBOX_NPC
	end


# 87 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_0:
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 87 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 87 "data/maps/SergioRoom/scripts.pory"
	face_down
	step_end

# 91 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_1:
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 91 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
	step_end

# 94 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_2:
# 94 "data/maps/SergioRoom/scripts.pory"
	walk_in_place_fast_up
	step_end

# 95 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_3:
# 95 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 95 "data/maps/SergioRoom/scripts.pory"
	walk_fast_down
# 95 "data/maps/SergioRoom/scripts.pory"
	face_left
	step_end

# 96 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_4:
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 96 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 97 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_5:
# 97 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 97 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 97 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 97 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 97 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 137 "data/maps/SergioRoom/scripts.pory"
SergioRoom_EventScript_SecurityGuardTrigger_Movement_0:
# 137 "data/maps/SergioRoom/scripts.pory"
	emote_double_exclamation_mark
# 137 "data/maps/SergioRoom/scripts.pory"
	face_player
	step_end

SergioRoom_EventScript_Abra_Text_0:
# 115 "data/maps/SergioRoom/scripts.pory"
	.string "Parece que Abra quiere\n"
	.string "teletransportarte a otro lugar.\l"
	.string "¿Deseas ir?$"

SergioRoom_EventScript_SecurityGuardTrigger_Text_0:
# 138 "data/maps/SergioRoom/scripts.pory"
	.string "¡Alto ahí!$"

SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance::
# 157 "data/maps/SergioRoom/scripts.pory"
	.string "No puedes avanzar al hall de la fama\n"
	.string "hasta no derrotar a Serg!o.\p"
	.string "¿Dónde habrá ido?$"
