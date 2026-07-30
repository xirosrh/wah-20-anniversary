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
	special ShowMapNamePopup
# 45 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 46 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_OUT
# 47 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 48 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 49 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 50 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 51 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_WEST
# 52 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 53 "data/maps/SergioRoom/scripts.pory"
	release
# 54 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 55 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 56 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 57 "data/maps/SergioRoom/scripts.pory"
	release
# 58 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 59 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 60 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteNormal
# 61 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 62 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
# 63 "data/maps/SergioRoom/scripts.pory"
	release
	end


SergioRoom_OnFrame_AfterSergioBattle::
# 68 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 69 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_OUT
# 70 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 71 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 72 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 73 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_ABRA, MAP_SERGIO_ROOM
# 74 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_SERGIO_ROOM
# 75 "data/maps/SergioRoom/scripts.pory"
	showobjectat LOCALID_SERGIOROOM_SERGIO, MAP_SERGIO_ROOM
# 76 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_ABRA, DIR_EAST
# 77 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 78 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SERGIO, DIR_WEST
# 79 "data/maps/SergioRoom/scripts.pory"
	release
# 80 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 81 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 82 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 83 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 84 "data/maps/SergioRoom/scripts.pory"
	release
# 85 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 86 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 87 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteNormal
# 88 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_SERGIO, OBJ_EVENT_GFX_SERGIO
# 89 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 90 "data/maps/SergioRoom/scripts.pory"
	release
# 91 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 92 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_0
# 93 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 94 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, Common_Movement_WalkInPlaceDown
# 95 "data/maps/SergioRoom/scripts.pory"
	delay 10
# 96 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 97 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_1
# 98 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 99 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_2
# 100 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_OnFrame_AfterSergioBattle_Movement_3
# 101 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_SERGIOROOM_SERGIO, SergioRoom_OnFrame_AfterSergioBattle_Movement_4
# 102 "data/maps/SergioRoom/scripts.pory"
	applymovement LOCALID_PLAYER, SergioRoom_OnFrame_AfterSergioBattle_Movement_5
# 103 "data/maps/SergioRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 104 "data/maps/SergioRoom/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 105 "data/maps/SergioRoom/scripts.pory"
	warp MAP_HALL_OF_FAME, WARP_ID_HALL_OF_FAME
# 106 "data/maps/SergioRoom/scripts.pory"
	waitstate
# 107 "data/maps/SergioRoom/scripts.pory"
	releaseall
	end


SergioRoom_EventScript_Abra::
# 113 "data/maps/SergioRoom/scripts.pory"
	lock
# 114 "data/maps/SergioRoom/scripts.pory"
	release
# 115 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_ABRA, Common_Movement_FacePlayer
# 116 "data/maps/SergioRoom/scripts.pory"
	release
# 117 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 118 "data/maps/SergioRoom/scripts.pory"
	releaseall
# 119 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 120 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Abra_Text_0, MSGBOX_YESNO
# 121 "data/maps/SergioRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SergioRoom_EventScript_Abra_2
SergioRoom_EventScript_Abra_1:
# 135 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_Abra_2:
# 122 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 123 "data/maps/SergioRoom/scripts.pory"
	playse SE_WARP_IN
# 124 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 125 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 126 "data/maps/SergioRoom/scripts.pory"
	release
# 127 "data/maps/SergioRoom/scripts.pory"
	delay 30
# 128 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 129 "data/maps/SergioRoom/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 130 "data/maps/SergioRoom/scripts.pory"
	release
# 131 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 132 "data/maps/SergioRoom/scripts.pory"
	warpsilent MAP_DRAGON_MOUNTAIN_TOP, WARP_ID_DRAGON_MOUNTAIN_TOP
# 133 "data/maps/SergioRoom/scripts.pory"
	waitstate
	goto SergioRoom_EventScript_Abra_1


SergioRoom_EventScript_SecurityGuardTrigger::
# 140 "data/maps/SergioRoom/scripts.pory"
	lock
# 141 "data/maps/SergioRoom/scripts.pory"
	playse SE_PIN
# 142 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_SECURITYGUARD, SergioRoom_EventScript_SecurityGuardTrigger_Movement_0
# 143 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_Text_0, MSGBOX_AUTOCLOSE
# 144 "data/maps/SergioRoom/scripts.pory"
	delay 48
# 145 "data/maps/SergioRoom/scripts.pory"
	getdirectiontoface VAR_TEMP_A, LOCALID_PLAYER, LOCALID_SERGIOROOM_SECURITYGUARD
# 146 "data/maps/SergioRoom/scripts.pory"
	switch VAR_TEMP_A
# 147 "data/maps/SergioRoom/scripts.pory"
	case DIR_EAST, SergioRoom_EventScript_SecurityGuardTrigger_3
# 149 "data/maps/SergioRoom/scripts.pory"
	case DIR_WEST, SergioRoom_EventScript_SecurityGuardTrigger_4
SergioRoom_EventScript_SecurityGuardTrigger_1:
# 152 "data/maps/SergioRoom/scripts.pory"
	playse SE_PIN
# 153 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 154 "data/maps/SergioRoom/scripts.pory"
	waitmovement 0
# 155 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance, MSGBOX_AUTOCLOSE
# 156 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 157 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_SERGIOROOM_SECURITYGUARD, DIR_SOUTH
# 158 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_SecurityGuardTrigger_3:
# 148 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto SergioRoom_EventScript_SecurityGuardTrigger_1

SergioRoom_EventScript_SecurityGuardTrigger_4:
# 150 "data/maps/SergioRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto SergioRoom_EventScript_SecurityGuardTrigger_1


SergioRoom_EventScript_SecurityGuard::
# 167 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance, MSGBOX_NPC
	end


SergioRoom_EventScript_Colmillo::
# 172 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Colmillo_Text_0, MSGBOX_SIGN
	end


# 92 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_0:
# 92 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 92 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 92 "data/maps/SergioRoom/scripts.pory"
	walk_fast_left
# 92 "data/maps/SergioRoom/scripts.pory"
	face_down
	step_end

# 96 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_1:
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 96 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
	step_end

# 99 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_2:
# 99 "data/maps/SergioRoom/scripts.pory"
	walk_in_place_fast_up
	step_end

# 100 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_3:
# 100 "data/maps/SergioRoom/scripts.pory"
	walk_fast_right
# 100 "data/maps/SergioRoom/scripts.pory"
	walk_fast_down
# 100 "data/maps/SergioRoom/scripts.pory"
	face_left
	step_end

# 101 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_4:
# 101 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 101 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 101 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 101 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 102 "data/maps/SergioRoom/scripts.pory"
SergioRoom_OnFrame_AfterSergioBattle_Movement_5:
# 102 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 102 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 102 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 102 "data/maps/SergioRoom/scripts.pory"
	walk_fast_up
# 102 "data/maps/SergioRoom/scripts.pory"
	set_invisible
	step_end

# 142 "data/maps/SergioRoom/scripts.pory"
SergioRoom_EventScript_SecurityGuardTrigger_Movement_0:
# 142 "data/maps/SergioRoom/scripts.pory"
	emote_double_exclamation_mark
# 142 "data/maps/SergioRoom/scripts.pory"
	face_player
	step_end

SergioRoom_EventScript_Abra_Text_0:
# 120 "data/maps/SergioRoom/scripts.pory"
	.string "It seems Abra wants to teleport you\n"
	.string "somewhere else. Do you want to go?$"

SergioRoom_EventScript_SecurityGuardTrigger_Text_0:
# 143 "data/maps/SergioRoom/scripts.pory"
	.string "Hold it right there!$"

SergioRoom_EventScript_Colmillo_Text_0:
# 172 "data/maps/SergioRoom/scripts.pory"
	.string "It's a fang from a giant dragon\n"
	.string "Pokémon.$"

SergioRoom_EventScript_SecurityGuardTrigger_CantAdvance::
# 162 "data/maps/SergioRoom/scripts.pory"
	.string "You can't advance to the Hall of Fame\n"
	.string "until you defeat Serg!o.\p"
	.string "Where could he have gone?$"
