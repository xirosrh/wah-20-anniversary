GallegoRoom_MapScripts::
# 7 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GallegoRoom_OnLoad
# 8 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, GallegoRoom_OnTransition
# 4 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/GallegoRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, GallegoRoom_OnWarp_PlayerTurnNorth
	.2byte 0


GallegoRoom_OnLoad::
# 12 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_OnLoad_2
GallegoRoom_OnLoad_1:
	end

GallegoRoom_OnLoad_2:
# 13 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
# 14 "data/maps/GallegoRoom/scripts.pory"
	setobjectmovementtype LOCALID_GALLEGOROOM_GALLEGO, MOVEMENT_TYPE_FACE_DOWN
	goto GallegoRoom_OnLoad_1


GallegoRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


GallegoRoom_OnTransition::
# 25 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Gallego
	end


GallegoRoom_EventScript_Gallego::
# 30 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_EventScript_Gallego_2
# 40 "data/maps/GallegoRoom/scripts.pory"
	lock
# 41 "data/maps/GallegoRoom/scripts.pory"
	special HideMapNamePopUpWindow
# 42 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 43 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 44 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_6
# 52 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_7
GallegoRoom_EventScript_Gallego_4:
# 59 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_2
# 60 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_2, MSGBOX_AUTOCLOSE_TOP
# 61 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 62 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_3
# 74 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_3, MSGBOX_AUTOCLOSE_TOP
# 75 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 77 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 78 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 79 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceDown
# 80 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 81 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 82 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 83 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_4
# 84 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 85 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 86 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 87 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 88 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
# 92 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 93 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 94 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_6
# 99 "data/maps/GallegoRoom/scripts.pory"
	delay 40
# 100 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 101 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 102 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HeartWithDelay48
# 103 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 104 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 105 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 106 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 107 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 108 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 109 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_FacePlayer
# 110 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 111 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 112 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 113 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 114 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 115 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
# 117 "data/maps/GallegoRoom/scripts.pory"
	delay 50
# 118 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_7
# 123 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 124 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 125 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_8
# 126 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 127 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 128 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_GALLEGOROOM_GALLEGO, DIR_NORTH
# 129 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 130 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 131 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 132 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceUp
# 133 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 134 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_9
# 140 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp
# 141 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 142 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 143 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_10
# 150 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 151 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 152 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 153 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_11
# 154 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 155 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 156 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_GallegoBattle
# 157 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 158 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 159 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 160 "data/maps/GallegoRoom/scripts.pory"
	delay 60
# 161 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 162 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 163 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 164 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 165 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 166 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 167 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
# 171 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 172 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 173 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 174 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_6
# 179 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_18, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 180 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 181 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_19, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 182 "data/maps/GallegoRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GALLEGO
# 183 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 184 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_2:
# 31 "data/maps/GallegoRoom/scripts.pory"
	lock
# 32 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 33 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 34 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 36 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 37 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_6:
# 45 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_0
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_7:
# 53 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_1
	goto GallegoRoom_EventScript_Gallego_4


GallegoRoom_EventScript_TV::
# 189 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_TV_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Monkfear::
# 194 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Monkfear_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Saturnape::
# 199 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Saturnape_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Gameboy1::
# 204 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gameboy1_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Gameboy2::
# 209 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gameboy2_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_DrawingsAndCoffee::
# 214 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 215 "data/maps/GallegoRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq GallegoRoom_EventScript_DrawingsAndCoffee_2
# 218 "data/maps/GallegoRoom/scripts.pory"
	goto GallegoRoom_EventScript_Drawings
GallegoRoom_EventScript_DrawingsAndCoffee_1:
	end

GallegoRoom_EventScript_DrawingsAndCoffee_2:
# 216 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_DrawingsAndCoffee_Text_0, MSGBOX_SIGN
	goto GallegoRoom_EventScript_DrawingsAndCoffee_1


GallegoRoom_EventScript_Drawings::
# 224 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Drawings_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Shelf::
# 229 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Shelf_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Library::
# 234 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Library_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Drawer::
# 239 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Drawer_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_NES::
# 244 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_NES_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Bin::
# 249 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_TEMP_0
# 250 "data/maps/GallegoRoom/scripts.pory"
	case 0, GallegoRoom_EventScript_Bin_3
# 253 "data/maps/GallegoRoom/scripts.pory"
	case 1, GallegoRoom_EventScript_Bin_4
# 256 "data/maps/GallegoRoom/scripts.pory"
	case 2, GallegoRoom_EventScript_Bin_5
GallegoRoom_EventScript_Bin_1:
	end

GallegoRoom_EventScript_Bin_3:
# 251 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Bin_Text_0, MSGBOX_SIGN
# 252 "data/maps/GallegoRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto GallegoRoom_EventScript_Bin_1

GallegoRoom_EventScript_Bin_4:
# 254 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Bin_Text_1, MSGBOX_SIGN
# 255 "data/maps/GallegoRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto GallegoRoom_EventScript_Bin_1

GallegoRoom_EventScript_Bin_5:
# 257 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Bin_Text_2, MSGBOX_SIGN
	goto GallegoRoom_EventScript_Bin_1


GallegoRoom_EventScript_GallegoBattle::
# 263 "data/maps/GallegoRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, GallegoRoom_EventScript_GallegoBattle_2
# 266 "data/maps/GallegoRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_GALLEGO
# 267 "data/maps/GallegoRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 268 "data/maps/GallegoRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GallegoRoom_EventScript_GallegoBattle_5
# 271 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_ALTERNATIVE, GallegoRoom_Text_GallegoDefeated
GallegoRoom_EventScript_GallegoBattle_1:
	return

GallegoRoom_EventScript_GallegoBattle_2:
# 264 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_Text_GallegoDefeated
	goto GallegoRoom_EventScript_GallegoBattle_1

GallegoRoom_EventScript_GallegoBattle_5:
# 269 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_Text_GallegoDefeated
	goto GallegoRoom_EventScript_GallegoBattle_1


# 45 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_0:
# 46 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 47 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 47 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 48 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 49 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 53 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_1:
# 54 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 55 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 56 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 59 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_2:
# 59 "data/maps/GallegoRoom/scripts.pory"
	reveal_trainer
# 59 "data/maps/GallegoRoom/scripts.pory"
	walk_in_place_up
	step_end

# 62 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_3:
# 63 "data/maps/GallegoRoom/scripts.pory"
	emote_thinking
# 64 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 64 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 64 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 65 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 66 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 66 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 67 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 68 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 68 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 69 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 70 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 71 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 72 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 72 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 83 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_4:
# 83 "data/maps/GallegoRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 88 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_5:
# 89 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 90 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
	step_end

# 94 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_6:
# 95 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 96 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 97 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 118 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_7:
# 119 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 120 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 120 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 120 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 121 "data/maps/GallegoRoom/scripts.pory"
	walk_right
	step_end

# 125 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_8:
# 125 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 125 "data/maps/GallegoRoom/scripts.pory"
	face_right
	step_end

# 134 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_9:
# 135 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 136 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 136 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 136 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 137 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 138 "data/maps/GallegoRoom/scripts.pory"
	face_down
	step_end

# 143 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_10:
# 144 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 145 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_down
# 146 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 147 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 148 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 153 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_11:
# 153 "data/maps/GallegoRoom/scripts.pory"
	emote_versus
	step_end

GallegoRoom_EventScript_Gallego_Text_0:
# 33 "data/maps/GallegoRoom/scripts.pory"
	.string "The spark that rekindled my dream has\n"
	.string "lit a flame that grows by the moment.$"

GallegoRoom_EventScript_Gallego_Text_1:
# 36 "data/maps/GallegoRoom/scripts.pory"
	.string "Keep chasing yours, and we'll meet again\n"
	.string "on the road!$"

GallegoRoom_EventScript_Gallego_Text_2:
# 60 "data/maps/GallegoRoom/scripts.pory"
	.string "Oh no, I think they saw me… I can't let\n"
	.string "them find me yet…\p"
	.string "What if I keep very still? Could I\n"
	.string "manage to slip away?$"

GallegoRoom_EventScript_Gallego_Text_3:
# 74 "data/maps/GallegoRoom/scripts.pory"
	.string "Well, I'll have to accept it, I guess I\n"
	.string "couldn't hide forever.$"

GallegoRoom_EventScript_Gallego_Text_4:
# 80 "data/maps/GallegoRoom/scripts.pory"
	.string "Hi! I'm Gallego13, and for years I've\n"
	.string "watched from the shadows.\p"
	.string "You could almost say I didn't leave, I\n"
	.string "just hid.\p"
	.string "Now and then I'd peek in on our dear\n"
	.string "community, saying nothing, watching the\l"
	.string "progress and how it evolved…\p"
	.string "I never meant it to last so long, but\n"
	.string "studies and then life made me lose all\l"
	.string "track of time.\p"
	.string "Before I knew it, I'd gotten used to\n"
	.string "watching this world from a distance.$"

GallegoRoom_EventScript_Gallego_Text_5:
# 86 "data/maps/GallegoRoom/scripts.pory"
	.string "And look at that, twenty years… twenty!$"

GallegoRoom_EventScript_Gallego_Text_6:
# 100 "data/maps/GallegoRoom/scripts.pory"
	.string "The anniversary caught me completely\n"
	.string "by surprise.\p"
	.string "It's even been ten years since I was\n"
	.string "last seen!\p"
	.string "And even so, that piece of my life I\n"
	.string "remember like it was yesterday.$"

GallegoRoom_EventScript_Gallego_Text_7:
# 103 "data/maps/GallegoRoom/scripts.pory"
	.string "I always dreamed of making a game that\n"
	.string "captured the soul of the second\l"
	.string "generation, with that look and that\l"
	.string "“certain something” I've always been in\l"
	.string "love with.\p"
	.string "I spent years grinding away in hex\n"
	.string "bytes and ASM routines, shoving\l"
	.string "graphics and music into the ROM by\l"
	.string "brute force…$"

GallegoRoom_EventScript_Gallego_Text_8:
# 108 "data/maps/GallegoRoom/scripts.pory"
	.string "But it was driving me crazy, all of it…\n"
	.string "too hard, and the bugs sprouted like\l"
	.string "weeds with every change.$"

GallegoRoom_EventScript_Gallego_Text_9:
# 110 "data/maps/GallegoRoom/scripts.pory"
	.string "And right when I quit, when I gave up,\n"
	.string "the modern tools appeared.\p"
	.string "The disassembly, the engines… all I\n"
	.string "would've needed back then showed up,\l"
	.string "almost like a mockery of my effort.$"

GallegoRoom_EventScript_Gallego_Text_10:
# 124 "data/maps/GallegoRoom/scripts.pory"
	.string "As you can see, I still keep my old Game\n"
	.string "Boy Colors.$"

GallegoRoom_EventScript_Gallego_Text_11:
# 130 "data/maps/GallegoRoom/scripts.pory"
	.string "Some don't even turn on, but they're\n"
	.string "still here.\p"
	.string "In spite of it all, after so much time, my\n"
	.string "dream still lives on…\p"
	.string "The dream has no end: the gears in my\n"
	.string "head still haven't stopped…$"

GallegoRoom_EventScript_Gallego_Text_12:
# 133 "data/maps/GallegoRoom/scripts.pory"
	.string "Anyway, enough reflecting for now.$"

GallegoRoom_EventScript_Gallego_Text_13:
# 141 "data/maps/GallegoRoom/scripts.pory"
	.string "Let's see if I still remember how to\n"
	.string "battle after all this time.$"

GallegoRoom_EventScript_Gallego_Text_14:
# 151 "data/maps/GallegoRoom/scripts.pory"
	.string "Show me how much the new generation\n"
	.string "has evolved!$"

GallegoRoom_EventScript_Gallego_Text_15:
# 157 "data/maps/GallegoRoom/scripts.pory"
	.string "Looks like the new generations of\n"
	.string "trainers are a much tougher nut to\l"
	.string "crack.\p"
	.string "But watching you battle brings back\n"
	.string "the old spark.$"

GallegoRoom_EventScript_Gallego_Text_16:
# 161 "data/maps/GallegoRoom/scripts.pory"
	.string "Funny… I quit right before everything\n"
	.string "got easier, and even so, I keep thinking\l"
	.string "of coming back.\p"
	.string "I can't deny I'm a hopeless stubborn\n"
	.string "fool…$"

GallegoRoom_EventScript_Gallego_Text_17:
# 165 "data/maps/GallegoRoom/scripts.pory"
	.string "I guess some dreams just don't burn\n"
	.string "out.$"

GallegoRoom_EventScript_Gallego_Text_18:
# 179 "data/maps/GallegoRoom/scripts.pory"
	.string "Go on, keep going, chase your dream and\n"
	.string "hold it tight!$"

GallegoRoom_EventScript_Gallego_Text_19:
# 181 "data/maps/GallegoRoom/scripts.pory"
	.string "I'll stay here a little longer…\n"
	.string "remembering my old attempts and\l"
	.string "dreaming of a new and exciting\l"
	.string "beginning.$"

GallegoRoom_EventScript_TV_Text_0:
# 189 "data/maps/GallegoRoom/scripts.pory"
	.string "Looks like there's a half-finished game\n"
	.string "of the original Castlevania.\p"
	.string "A curious way to blow off steam.$"

GallegoRoom_EventScript_Monkfear_Text_0:
# 194 "data/maps/GallegoRoom/scripts.pory"
	.string "Looks like a fakémon design with\na second-generation look.\pIt has a data sheet:\nType: Water/Dark.\lSpecies: Aquaterror.\pEvolution line: Monkfear doesn't evolve.$"

GallegoRoom_EventScript_Saturnape_Text_0:
# 199 "data/maps/GallegoRoom/scripts.pory"
	.string "Looks like a fakémon design with\na second-generation look.\pIt has a data sheet:\nType: Psychic.\lSpecies: Alien Monkey.\pEvolution line: Marskey (LV. 30) >\nSaturnape.$"

GallegoRoom_EventScript_Gameboy1_Text_0:
# 204 "data/maps/GallegoRoom/scripts.pory"
	.string "It's a Game Boy Color.\p"
	.string "Looks like there's a game in progress\n"
	.string "deep inside a huge forest.\p"
	.string "Okay, I'll step out and… it just crashed.\n"
	.string "Great.$"

GallegoRoom_EventScript_Gameboy2_Text_0:
# 209 "data/maps/GallegoRoom/scripts.pory"
	.string "It's a Game Boy Color.\p"
	.string "The game's saved right before the\n"
	.string "starter-selection scene in a game I\l"
	.string "don't recognize…\p"
	.string "Oops! It just reset the moment the\n"
	.string "battle began.\p"
	.string "What a letdown.$"

GallegoRoom_EventScript_DrawingsAndCoffee_Text_0:
# 216 "data/maps/GallegoRoom/scripts.pory"
	.string "A half-drunk latte.\p"
	.string "Looks like someone left it\n"
	.string "half-finished in a hurry.$"

GallegoRoom_EventScript_Drawings_Text_0:
# 224 "data/maps/GallegoRoom/scripts.pory"
	.string "They look like designs of various\n"
	.string "fakémon and Pokémon from generations\l"
	.string "after the second, in the Game Boy Color\l"
	.string "style.\p"
	.string "They're mixed in with very old\n"
	.string "university notes.\p"
	.string "Looks like no one's tidied up here in a\n"
	.string "decade.$"

GallegoRoom_EventScript_Shelf_Text_0:
# 229 "data/maps/GallegoRoom/scripts.pory"
	.string "It's a collection of books and notes\n"
	.string "from university mixed with volumes of\l"
	.string "manga.\p"
	.string "It doesn't look very organized.$"

GallegoRoom_EventScript_Library_Text_0:
# 234 "data/maps/GallegoRoom/scripts.pory"
	.string "There's a huge row of black hardcover\n"
	.string "volumes.\p"
	.string "On the spine you can read “Berserk” in\n"
	.string "red letters.$"

GallegoRoom_EventScript_Drawer_Text_0:
# 239 "data/maps/GallegoRoom/scripts.pory"
	.string "It's a cabinet full of consoles and\n"
	.string "video games from different eras,\l"
	.string "stacked in various compartments.\p"
	.string "You can't see the back of it.$"

GallegoRoom_EventScript_NES_Text_0:
# 244 "data/maps/GallegoRoom/scripts.pory"
	.string "It's an NES, a little dusty, but it works\n"
	.string "perfectly.\p"
	.string "So retro!$"

GallegoRoom_EventScript_Bin_Text_0:
# 251 "data/maps/GallegoRoom/scripts.pory"
	.string "Nothing, just junk here… I think.$"

GallegoRoom_EventScript_Bin_Text_1:
# 254 "data/maps/GallegoRoom/scripts.pory"
	.string "I told you there's only junk here. Stop\n"
	.string "searching.$"

GallegoRoom_EventScript_Bin_Text_2:
# 257 "data/maps/GallegoRoom/scripts.pory"
	.string "At the bottom you find a strange image.\n"
	.string "It's clearly a second- generation\l"
	.string "design, but you're sure it's Flamigo, a\l"
	.string "recent Pokémon.\p"
	.string "What sense does this make?$"

GallegoRoom_Text_GallegoDefeated::
# 277 "data/maps/GallegoRoom/scripts.pory"
	.string "Phew… I really have fallen behind the\n"
	.string "times.$"
