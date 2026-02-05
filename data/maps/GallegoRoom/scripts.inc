GallegoRoom_MapScripts::
# 7 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GallegoRoom_OnLoad
# 4 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/GallegoRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, GallegoRoom_OnWarp_PlayerTurnNorth
	.2byte 0


GallegoRoom_OnLoad::
# 11 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_OnLoad_2
GallegoRoom_OnLoad_1:
	end

GallegoRoom_OnLoad_2:
# 12 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto GallegoRoom_OnLoad_1


GallegoRoom_OnWarp_PlayerTurnNorth::
# 18 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


GallegoRoom_EventScript_Gallego::
# 23 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_EventScript_Gallego_2
# 33 "data/maps/GallegoRoom/scripts.pory"
	lock
# 34 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 35 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 36 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_6
# 44 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_7
GallegoRoom_EventScript_Gallego_4:
# 51 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_2
# 52 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_2, MSGBOX_AUTOCLOSE_TOP
# 53 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 54 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_3
# 66 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_3, MSGBOX_AUTOCLOSE_TOP
# 67 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 68 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 69 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 70 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 71 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceDown
# 72 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 73 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 74 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_4
# 76 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 78 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 79 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
# 83 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 84 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 85 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 86 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_6
# 91 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 92 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 93 "data/maps/GallegoRoom/scripts.pory"
	delay 40
# 94 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 95 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HeartWithDelay48
# 97 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 98 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 99 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 100 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 101 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 102 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 103 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_FacePlayer
# 104 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 105 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 106 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 107 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 108 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 109 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 110 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
# 111 "data/maps/GallegoRoom/scripts.pory"
	delay 50
# 112 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_7
# 117 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 118 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 119 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_8
# 120 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 121 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 122 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_GALLEGOROOM_GALLEGO, DIR_NORTH
# 123 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 124 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 125 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 126 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceUp
# 127 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 128 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_9
# 134 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp
# 135 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_13, speaker = SP_NAME_GALLEGO
# 136 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 137 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_10
# 144 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 145 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_14, speaker = SP_NAME_GALLEGO
# 146 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 147 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_11
# 148 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 149 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_GallegoBattle
# 150 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 151 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 152 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 153 "data/maps/GallegoRoom/scripts.pory"
	delay 60
# 154 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 155 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 156 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 157 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 158 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 159 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 160 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
# 164 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 165 "data/maps/GallegoRoom/scripts.pory"
	waitse
# 166 "data/maps/GallegoRoom/scripts.pory"
	playse SE_LEDGE
# 167 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_6
# 172 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_18, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 173 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 174 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 175 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_19, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 176 "data/maps/GallegoRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GALLEGO
# 177 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_2:
# 24 "data/maps/GallegoRoom/scripts.pory"
	lock
# 25 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 26 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 27 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 29 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 30 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_6:
# 37 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_0
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_7:
# 45 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_1
	goto GallegoRoom_EventScript_Gallego_4


GallegoRoom_EventScript_TV::
# 182 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_TV_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Monkfear::
# 187 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Monkfear_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Saturnape::
# 192 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Saturnape_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Gameboy1::
# 197 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gameboy1_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Gameboy2::
# 202 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gameboy2_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Coffee::
# 207 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Coffee_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Drawings::
# 212 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Drawings_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Shelf::
# 217 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Shelf_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Library::
# 222 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Library_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Drawer::
# 227 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Drawer_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_NES::
# 232 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_NES_Text_0, MSGBOX_SIGN
	end


GallegoRoom_EventScript_Bin::
# 237 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_TEMP_0
# 238 "data/maps/GallegoRoom/scripts.pory"
	case 0, GallegoRoom_EventScript_Bin_3
# 241 "data/maps/GallegoRoom/scripts.pory"
	case 1, GallegoRoom_EventScript_Bin_4
# 244 "data/maps/GallegoRoom/scripts.pory"
	case 2, GallegoRoom_EventScript_Bin_5
GallegoRoom_EventScript_Bin_1:
	end

GallegoRoom_EventScript_Bin_3:
# 239 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Bin_Text_0, MSGBOX_SIGN
# 240 "data/maps/GallegoRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto GallegoRoom_EventScript_Bin_1

GallegoRoom_EventScript_Bin_4:
# 242 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Bin_Text_1, MSGBOX_SIGN
# 243 "data/maps/GallegoRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto GallegoRoom_EventScript_Bin_1

GallegoRoom_EventScript_Bin_5:
# 245 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Bin_Text_2, MSGBOX_SIGN
	goto GallegoRoom_EventScript_Bin_1


GallegoRoom_EventScript_GallegoBattle::
# 251 "data/maps/GallegoRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, GallegoRoom_EventScript_GallegoBattle_2
# 254 "data/maps/GallegoRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_GALLEGO
# 255 "data/maps/GallegoRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 256 "data/maps/GallegoRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GallegoRoom_EventScript_GallegoBattle_5
# 259 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_ALTERNATIVE, GallegoRoom_Text_GallegoDefeated
GallegoRoom_EventScript_GallegoBattle_1:
# 262 "data/maps/GallegoRoom/scripts.pory"
	special HealPlayerParty
	return

GallegoRoom_EventScript_GallegoBattle_2:
# 252 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_Text_GallegoDefeated
	goto GallegoRoom_EventScript_GallegoBattle_1

GallegoRoom_EventScript_GallegoBattle_5:
# 257 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_Text_GallegoDefeated
	goto GallegoRoom_EventScript_GallegoBattle_1


# 37 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_0:
# 38 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 39 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 39 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 40 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 41 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 45 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_1:
# 46 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 47 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 48 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 51 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_2:
# 51 "data/maps/GallegoRoom/scripts.pory"
	reveal_trainer
# 51 "data/maps/GallegoRoom/scripts.pory"
	walk_in_place_up
	step_end

# 54 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_3:
# 55 "data/maps/GallegoRoom/scripts.pory"
	emote_thinking
# 56 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 56 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 56 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 57 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 58 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 58 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 59 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 60 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 60 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 61 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 62 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 63 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 64 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 64 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 75 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_4:
# 75 "data/maps/GallegoRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 79 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_5:
# 80 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 81 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
	step_end

# 86 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_6:
# 87 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 88 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 89 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 112 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_7:
# 113 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 114 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 114 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 114 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 115 "data/maps/GallegoRoom/scripts.pory"
	walk_right
	step_end

# 119 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_8:
# 119 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 119 "data/maps/GallegoRoom/scripts.pory"
	face_right
	step_end

# 128 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_9:
# 129 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 130 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 130 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 130 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 131 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 132 "data/maps/GallegoRoom/scripts.pory"
	face_down
	step_end

# 137 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_10:
# 138 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 139 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 140 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 141 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 142 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 147 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_11:
# 147 "data/maps/GallegoRoom/scripts.pory"
	emote_versus
	step_end

GallegoRoom_EventScript_Gallego_Text_0:
# 26 "data/maps/GallegoRoom/scripts.pory"
	.string "La chispa que ha vuelto a encender mi\n"
	.string "sueño ha prendido una llama que crece\l"
	.string "por momentos.$"

GallegoRoom_EventScript_Gallego_Text_1:
# 29 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Continúa en busca del tuyo, y\n"
	.string "volveremos a encontrarnos en el camino!$"

GallegoRoom_EventScript_Gallego_Text_2:
# 52 "data/maps/GallegoRoom/scripts.pory"
	.string "Ay, no, creo que me ha visto… No puedo\n"
	.string "dejar que me encuentren todavía…\p"
	.string "¿Y si me quedo muy quieto? ¿Seré capaz\n"
	.string "de escabullirme?$"

GallegoRoom_EventScript_Gallego_Text_3:
# 66 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, tendré que aceptarlo, supongo\n"
	.string "que no podía ocultarme para siempre.$"

GallegoRoom_EventScript_Gallego_Text_4:
# 72 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Hola! Soy Gallego13, y llevo años\n"
	.string "observando desde las sombras.\p"
	.string "Casi podría decir que en vez de irme, me\n"
	.string "escondí.\p"
	.string "De vez en cuando echaba un ojo por\n"
	.string "nuestra querida comunidad, sin decir\l"
	.string "nada, viendo los avances y cómo\l"
	.string "evolucionaba…\p"
	.string "Nunca quise que fuese tan largo, pero\n"
	.string "los estudios y después la vida me\l"
	.string "hicieron perder la noción del tiempo.\p"
	.string "Antes de que me diera cuenta, me\n"
	.string "acostumbré a ver este mundo desde la\l"
	.string "distancia.$"

GallegoRoom_EventScript_Gallego_Text_5:
# 91 "data/maps/GallegoRoom/scripts.pory"
	.string "Y mira tú, veinte años ya… ¡veinte!$"

GallegoRoom_EventScript_Gallego_Text_6:
# 94 "data/maps/GallegoRoom/scripts.pory"
	.string "El aniversario me ha pillado totalmente\n"
	.string "por sorpresa. ¡Si hasta hace diez años\l"
	.string "desde que me dejé ver por última vez!\p"
	.string "Y aún con esas, ese pedazo de mi vida lo\n"
	.string "recuerdo como si hubiese sido ayer.$"

GallegoRoom_EventScript_Gallego_Text_7:
# 97 "data/maps/GallegoRoom/scripts.pory"
	.string "Siempre tuve el sueño de crear un juego\n"
	.string "que capturara el alma de la segunda\l"
	.string "generación, con aquella estética y ese\l"
	.string "“no sé qué” del que siempre he estado\l"
	.string "enamorado.\p"
	.string "Me pasé años picando piedra entre\n"
	.string "bytes en hexadecimal y rutinas de ASM,\l"
	.string "insertando gráficos y música a las\l"
	.string "bravas en la ROM…$"

GallegoRoom_EventScript_Gallego_Text_8:
# 102 "data/maps/GallegoRoom/scripts.pory"
	.string "Pero me iba a volver loco con todo\n"
	.string "aquello… demasiado difícil, los bugs\l"
	.string "aparecían como setas a cada cambio.$"

GallegoRoom_EventScript_Gallego_Text_9:
# 104 "data/maps/GallegoRoom/scripts.pory"
	.string "Y justo cuando lo dejé, cuando me rendí,\n"
	.string "aparecieron las herramientas modernas.\p"
	.string "El disassembly, los motores… todo lo que\n"
	.string "habría necesitado entonces, apareció,\l"
	.string "casi como si fuese una burla a mi\l"
	.string "esfuerzo.$"

GallegoRoom_EventScript_Gallego_Text_10:
# 118 "data/maps/GallegoRoom/scripts.pory"
	.string "Como ves, aún conservo mis viejas Game\n"
	.string "Boy Color.$"

GallegoRoom_EventScript_Gallego_Text_11:
# 124 "data/maps/GallegoRoom/scripts.pory"
	.string "Algunas ni siquiera encienden, pero\n"
	.string "siguen ahí.\p"
	.string "A pesar de todo, después de tanto\n"
	.string "tiempo, mi sueño todavía vive…\p"
	.string "El sueño no tiene fin: la maquinaria en\n"
	.string "mi cabeza todavía no se ha detenido…$"

GallegoRoom_EventScript_Gallego_Text_12:
# 127 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, suficiente reflexión por ahora.$"

GallegoRoom_EventScript_Gallego_Text_13:
# 135 "data/maps/GallegoRoom/scripts.pory"
	.string "Vamos a ver si no se me ha olvidado\n"
	.string "combatir en este tiempo.$"

GallegoRoom_EventScript_Gallego_Text_14:
# 145 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Enséñame cuánto ha evolucionado la\n"
	.string "nueva generación!$"

GallegoRoom_EventScript_Gallego_Text_15:
# 150 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece que las nuevas generaciones de\n"
	.string "entrenadores son mucho más duras de\l"
	.string "roer.\p"
	.string "Pero verte combatir me devuelve la\n"
	.string "chispa de antaño.$"

GallegoRoom_EventScript_Gallego_Text_16:
# 154 "data/maps/GallegoRoom/scripts.pory"
	.string "Es curioso… abandoné justo antes de\n"
	.string "que todo se volviera más fácil, y aun\l"
	.string "así, sigo pensando en volver.\p"
	.string "No puedo negar que soy un cabezota sin\n"
	.string "remedio…$"

GallegoRoom_EventScript_Gallego_Text_17:
# 158 "data/maps/GallegoRoom/scripts.pory"
	.string "Supongo que algunos sueños no se\n"
	.string "apagan.$"

GallegoRoom_EventScript_Gallego_Text_18:
# 172 "data/maps/GallegoRoom/scripts.pory"
	.string "Ve, continúa, ¡busca tu sueño y\n"
	.string "abrázalo con fuerza!$"

GallegoRoom_EventScript_Gallego_Text_19:
# 175 "data/maps/GallegoRoom/scripts.pory"
	.string "Yo me quedaré aquí un rato más…\n"
	.string "recordando mis viejos intentos y\l"
	.string "soñando con un nuevo y emocionante\l"
	.string "comienzo.$"

GallegoRoom_EventScript_TV_Text_0:
# 182 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece que tiene a medias una partida\n"
	.string "del Castlevania original.\p"
	.string "Curiosa forma de liberar el estrés.$"

GallegoRoom_EventScript_Monkfear_Text_0:
# 187 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece el diseño de un fakémon con\nestética de segunda generación.\pTiene una ficha:\nTipo: Agua/siniestro.\lEspecie: Acuaterror.\pLínea evolutiva: Monkfear no evoluciona.$"

GallegoRoom_EventScript_Saturnape_Text_0:
# 192 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece el diseño de un fakémon con\nestética de segunda generación.\pTiene una ficha:\nTipo: Psíquico.\lEspecie: Mono alien.\pLínea evolutiva: Marskey (LV. 30) >\nSaturnape.$"

GallegoRoom_EventScript_Gameboy1_Text_0:
# 197 "data/maps/GallegoRoom/scripts.pory"
	.string "Es una Gameboy Color. Parece que tiene\n"
	.string "una partida en marcha en el interior de\l"
	.string "un bosque enorme.\p"
	.string "Vale, voy a salir y… acaba de crashear.\n"
	.string "Vaya.$"

GallegoRoom_EventScript_Gameboy2_Text_0:
# 202 "data/maps/GallegoRoom/scripts.pory"
	.string "Es una Gameboy Color. La partida está\n"
	.string "guardada antes de la escena de\l"
	.string "selección de inicial en un juego que no\l"
	.string "conozco…\p"
	.string "¡Uy! Se acaba de reiniciar nada más\n"
	.string "entrar en combate. Vaya chasco.$"

GallegoRoom_EventScript_Coffee_Text_0:
# 207 "data/maps/GallegoRoom/scripts.pory"
	.string "Un café con leche a medio beber. Parece\n"
	.string "como si alguien se lo hubiese dejado a\l"
	.string "medias por la prisa.$"

GallegoRoom_EventScript_Drawings_Text_0:
# 212 "data/maps/GallegoRoom/scripts.pory"
	.string "Parecen diseños de varios fakémon y\n"
	.string "Pokémon de generaciones posteriores a\l"
	.string "la segunda en el estilo de la Gameboy\l"
	.string "Color.\p"
	.string "Están entremezclados con apuntes muy\n"
	.string "viejos de la universidad.\p"
	.string "Parece que nadie ha puesto orden aquí\n"
	.string "en una década.$"

GallegoRoom_EventScript_Shelf_Text_0:
# 217 "data/maps/GallegoRoom/scripts.pory"
	.string "Es una colección de libros y apuntes de\n"
	.string "la universidad mezclada con tomos de\l"
	.string "manga.\p"
	.string "No parece muy organizada.$"

GallegoRoom_EventScript_Library_Text_0:
# 222 "data/maps/GallegoRoom/scripts.pory"
	.string "Hay una fila enorme de tomos negros de\n"
	.string "tapa dura.\p"
	.string "En el lomo se puede leer “Berserk” en\n"
	.string "letras rojas.$"

GallegoRoom_EventScript_Drawer_Text_0:
# 227 "data/maps/GallegoRoom/scripts.pory"
	.string "Es un mueble lleno de consolas y\n"
	.string "videojuegos de distintas épocas,\l"
	.string "apilados en varios compartimentos.\p"
	.string "No se ve el fondo.$"

GallegoRoom_EventScript_NES_Text_0:
# 232 "data/maps/GallegoRoom/scripts.pory"
	.string "Es una NES, un poco polvorienta, pero\n"
	.string "funciona perfectamente. ¡Qué retro!$"

GallegoRoom_EventScript_Bin_Text_0:
# 239 "data/maps/GallegoRoom/scripts.pory"
	.string "Nada, aquí solo hay basura… creo.$"

GallegoRoom_EventScript_Bin_Text_1:
# 242 "data/maps/GallegoRoom/scripts.pory"
	.string "Te he dicho que aquí solo hay basura.\n"
	.string "Deja de buscar.$"

GallegoRoom_EventScript_Bin_Text_2:
# 245 "data/maps/GallegoRoom/scripts.pory"
	.string "Encuentras al fondo una imagen\n"
	.string "extraña. Es un diseño claramente de la\l"
	.string "segunda generación, pero estás seguro\l"
	.string "de que es Flamigo, un Pokémon reciente.\p"
	.string "¿Qué sentido tiene esto?$"

GallegoRoom_Text_GallegoDefeated::
# 266 "data/maps/GallegoRoom/scripts.pory"
	.string "Uff… pues sí que me he quedado\n"
	.string "anticuado.$"
