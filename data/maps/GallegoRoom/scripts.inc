GallegoRoom_MapScripts::
# 5 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GallegoRoom_OnLoad
# 2 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/GallegoRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, GallegoRoom_OnWarp_PlayerTurnNorth
	.2byte 0


GallegoRoom_OnLoad::
# 9 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_OnLoad_2
GallegoRoom_OnLoad_1:
	end

GallegoRoom_OnLoad_2:
# 10 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto GallegoRoom_OnLoad_1


GallegoRoom_OnWarp_PlayerTurnNorth::
# 16 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


GallegoRoom_EventScript_Gallego::
# 21 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_EventScript_Gallego_2
# 31 "data/maps/GallegoRoom/scripts.pory"
	lock
# 32 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_0
# 33 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_2, MSGBOX_AUTOCLOSE_TOP
# 34 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_1
# 47 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_3, MSGBOX_AUTOCLOSE_TOP
# 48 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 49 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 50 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 51 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 52 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer
# 53 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_4, MSGBOX_AUTOCLOSE
# 54 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 55 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_2
# 64 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_5, MSGBOX_AUTOCLOSE
# 65 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 66 "data/maps/GallegoRoom/scripts.pory"
	delay 40
# 67 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_6, MSGBOX_AUTOCLOSE
# 68 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HeartWithDelay48
# 70 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_7, MSGBOX_AUTOCLOSE
# 71 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_MoveAwayFromPlayer
# 72 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_8, MSGBOX_AUTOCLOSE
# 73 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_FacePlayer
# 74 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_9, MSGBOX_AUTOCLOSE
# 75 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 77 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_MoveTowardsPlayer
# 78 "data/maps/GallegoRoom/scripts.pory"
	delay 50
# 79 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 80 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 81 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_Gallego_6
# 83 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_7
# 85 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_Gallego_8
# 87 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_9
GallegoRoom_EventScript_Gallego_4:
# 90 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_10, MSGBOX_AUTOCLOSE
# 91 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 92 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_Gallego_12
# 100 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_13
# 108 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_Gallego_14
# 115 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_15
GallegoRoom_EventScript_Gallego_10:
# 122 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_11, MSGBOX_AUTOCLOSE
# 123 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 124 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer
# 125 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_12
# 126 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 127 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_11
# 135 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_13
# 136 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_EventScript_Gallego_Text_14
# 137 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_15, MSGBOX_AUTOCLOSE
# 138 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 140 "data/maps/GallegoRoom/scripts.pory"
	delay 60
# 141 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_16, MSGBOX_AUTOCLOSE
# 142 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 143 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 144 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 145 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_17, MSGBOX_AUTOCLOSE
# 146 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_12
# 153 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_18, MSGBOX_AUTOCLOSE
# 154 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 155 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 156 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_19, MSGBOX_AUTOCLOSE
# 157 "data/maps/GallegoRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GALLEGO
# 158 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_2:
# 22 "data/maps/GallegoRoom/scripts.pory"
	lock
# 23 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 24 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_0, MSGBOX_AUTOCLOSE
# 25 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 26 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 27 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_1, MSGBOX_AUTOCLOSE
# 28 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_6:
# 82 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_3
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_7:
# 84 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_4
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_8:
# 86 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_9:
# 88 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_6
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_12:
# 93 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_7
	goto GallegoRoom_EventScript_Gallego_10

GallegoRoom_EventScript_Gallego_13:
# 101 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_8
	goto GallegoRoom_EventScript_Gallego_10

GallegoRoom_EventScript_Gallego_14:
# 109 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_9
	goto GallegoRoom_EventScript_Gallego_10

GallegoRoom_EventScript_Gallego_15:
# 116 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_10
	goto GallegoRoom_EventScript_Gallego_10


GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer::
# 163 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 164 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 165 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_3
# 168 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_4
# 171 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_5
# 174 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_6
GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1:
	return

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_3:
# 166 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceDown
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_4:
# 169 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceUp
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_5:
# 172 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceRight
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_6:
# 175 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceLeft
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1


GallegoRoom_EventScript_MoveAwayFromPlayer::
# 182 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 183 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 184 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 185 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_MoveAwayFromPlayer_3
# 190 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_MoveAwayFromPlayer_4
# 195 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_MoveAwayFromPlayer_5
GallegoRoom_EventScript_MoveAwayFromPlayer_1:
# 201 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
	return

GallegoRoom_EventScript_MoveAwayFromPlayer_3:
# 186 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 187 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 188 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1

GallegoRoom_EventScript_MoveAwayFromPlayer_4:
# 191 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 192 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 193 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1

GallegoRoom_EventScript_MoveAwayFromPlayer_5:
# 196 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 197 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 198 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1


GallegoRoom_EventScript_MoveTowardsPlayer::
# 206 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 207 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 208 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 209 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_MoveTowardsPlayer_3
# 214 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_MoveTowardsPlayer_4
# 219 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_MoveTowardsPlayer_5
GallegoRoom_EventScript_MoveTowardsPlayer_1:
# 226 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
	return

GallegoRoom_EventScript_MoveTowardsPlayer_3:
# 210 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 211 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 212 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1

GallegoRoom_EventScript_MoveTowardsPlayer_4:
# 215 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 216 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 217 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1

GallegoRoom_EventScript_MoveTowardsPlayer_5:
# 220 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 221 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 222 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 223 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_GALLEGOROOM_GALLEGO, DIR_WEST
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1


# 32 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_0:
# 32 "data/maps/GallegoRoom/scripts.pory"
	reveal_trainer
	step_end

# 35 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_1:
# 36 "data/maps/GallegoRoom/scripts.pory"
	emote_thinking
# 37 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 37 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 37 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 38 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 39 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 39 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 40 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 41 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 41 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 42 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 43 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 43 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 44 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 45 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 45 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_2:
# 57 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 58 "data/maps/GallegoRoom/scripts.pory"
	emote_double_exclamation_mark
# 59 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 60 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 60 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 61 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 62 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 82 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_3:
# 82 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 82 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 82 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 82 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 82 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 82 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 82 "data/maps/GallegoRoom/scripts.pory"
	face_down
	step_end

# 84 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_4:
# 84 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 84 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 84 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 84 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 84 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 84 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 84 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 86 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_5:
# 86 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 86 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 86 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 86 "data/maps/GallegoRoom/scripts.pory"
	face_right
	step_end

# 88 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_6:
# 88 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 88 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 88 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 88 "data/maps/GallegoRoom/scripts.pory"
	face_left
	step_end

# 93 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_7:
# 94 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 95 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 95 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 96 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 97 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 97 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 98 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 99 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 101 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_8:
# 102 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 103 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 103 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 104 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 105 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 105 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 106 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 107 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 109 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_9:
# 110 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 111 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 111 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 112 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 113 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 116 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_10:
# 117 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 118 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 118 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 119 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 120 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 127 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_11:
# 128 "data/maps/GallegoRoom/scripts.pory"
	emote_versus
# 129 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 130 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 131 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 132 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 133 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 146 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_12:
# 147 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 148 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 149 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 150 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 151 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

GallegoRoom_EventScript_Gallego_Text_0:
# 24 "data/maps/GallegoRoom/scripts.pory"
	.string "La chispa que ha vuelto a encender mi\n"
	.string "sueño ha prendido una llama que crece\l"
	.string "por momentos.$"

GallegoRoom_EventScript_Gallego_Text_1:
# 27 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Continúa en busca del tuyo, y\n"
	.string "volveremos a encontrarnos en el camino!$"

GallegoRoom_EventScript_Gallego_Text_2:
# 33 "data/maps/GallegoRoom/scripts.pory"
	.string "Ay, no, creo que me ha visto… No puedo\n"
	.string "dejar que me encuentren todavía…\p"
	.string "¿Y si me quedo muy quieto? ¿Seré capaz\n"
	.string "de escabullirme?$"

GallegoRoom_EventScript_Gallego_Text_3:
# 47 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, tendré que aceptarlo, supongo\n"
	.string "que no podía ocultarme para siempre.$"

GallegoRoom_EventScript_Gallego_Text_4:
# 53 "data/maps/GallegoRoom/scripts.pory"
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
# 64 "data/maps/GallegoRoom/scripts.pory"
	.string "Y mira tú, veinte años ya… ¡veinte!$"

GallegoRoom_EventScript_Gallego_Text_6:
# 67 "data/maps/GallegoRoom/scripts.pory"
	.string "El aniversario me ha pillado totalmente\n"
	.string "por sorpresa. ¡Si hasta hace diez años\l"
	.string "desde que me dejé ver por última vez!\p"
	.string "Y aún con esas, ese pedazo de mi vida lo\n"
	.string "recuerdo como si hubiese sido ayer.$"

GallegoRoom_EventScript_Gallego_Text_7:
# 70 "data/maps/GallegoRoom/scripts.pory"
	.string "Siempre tuve el sueño de crear un juego\n"
	.string "que capturara el alma de la segunda\l"
	.string "generación, con aquella estética y ese\l"
	.string "'no sé qué' del que siempre he estado\l"
	.string "enamorado.\p"
	.string "Me pasé años picando piedra entre\n"
	.string "bytes en hexadecimal y rutinas de ASM,\l"
	.string "insertando gráficos y música a las\l"
	.string "bravas en la ROM…$"

GallegoRoom_EventScript_Gallego_Text_8:
# 72 "data/maps/GallegoRoom/scripts.pory"
	.string "Pero me iba a volver loco con todo\n"
	.string "aquello… demasiado difícil, los bugs\l"
	.string "aparecían como setas a cada cambio.$"

GallegoRoom_EventScript_Gallego_Text_9:
# 74 "data/maps/GallegoRoom/scripts.pory"
	.string "Y justo cuando lo dejé, cuando me rendí,\n"
	.string "aparecieron las herramientas modernas.\p"
	.string "El disassembly, los motores… todo lo que\n"
	.string "habría necesitado entonces, apareció,\l"
	.string "casi como si fuese una burla a mi\l"
	.string "esfuerzo.$"

GallegoRoom_EventScript_Gallego_Text_10:
# 90 "data/maps/GallegoRoom/scripts.pory"
	.string "Como ves, aún conservo mis viejas Game\n"
	.string "Boy Color.$"

GallegoRoom_EventScript_Gallego_Text_11:
# 122 "data/maps/GallegoRoom/scripts.pory"
	.string "Algunas ni siquiera encienden, pero\n"
	.string "siguen ahí.\p"
	.string "A pesar de todo, después de tanto\n"
	.string "tiempo, mi sueño todavía vive…\p"
	.string "El sueño no tiene fin: la maquinaria en\n"
	.string "mi cabeza todavía no se ha detenido…$"

GallegoRoom_EventScript_Gallego_Text_12:
# 125 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, suficiente reflexión por ahora.\n"
	.string "Vamos a ver si no se me ha olvidado\l"
	.string "combatir en este tiempo.$"

GallegoRoom_EventScript_Gallego_Text_13:
# 135 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Enséñame cuánto ha evolucionado la\n"
	.string "nueva generación!$"

GallegoRoom_EventScript_Gallego_Text_14:
# 136 "data/maps/GallegoRoom/scripts.pory"
	.string "Uff.. pues sí que me he quedado\n"
	.string "anticuado.$"

GallegoRoom_EventScript_Gallego_Text_15:
# 137 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece que las nuevas generaciones de\n"
	.string "entrenadores son mucho más duras de\l"
	.string "roer.\p"
	.string "Pero verte combatir me devuelve la\n"
	.string "chispa de antaño.$"

GallegoRoom_EventScript_Gallego_Text_16:
# 141 "data/maps/GallegoRoom/scripts.pory"
	.string "Es curioso… abandoné justo antes de\n"
	.string "que todo se volviera más fácil, y aun\l"
	.string "así, sigo pensando en volver.\p"
	.string "No puedo negar que soy un cabezota sin\n"
	.string "remedio…$"

GallegoRoom_EventScript_Gallego_Text_17:
# 145 "data/maps/GallegoRoom/scripts.pory"
	.string "Supongo que algunos sueños no se\n"
	.string "apagan.$"

GallegoRoom_EventScript_Gallego_Text_18:
# 153 "data/maps/GallegoRoom/scripts.pory"
	.string "Ve, continúa, ¡busca tu sueño y\n"
	.string "abrázalo con fuerza!$"

GallegoRoom_EventScript_Gallego_Text_19:
# 156 "data/maps/GallegoRoom/scripts.pory"
	.string "Yo me quedaré aquí un rato más…\n"
	.string "recordando mis viejos intentos y\l"
	.string "soñando con un nuevo y emocionante\l"
	.string "comienzo.$"
