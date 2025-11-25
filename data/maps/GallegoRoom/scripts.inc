GallegoRoom_MapScripts::
	.byte 0


GallegoRoom_EventScript_Gallego::
# 4 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_EventScript_Gallego_2
# 14 "data/maps/GallegoRoom/scripts.pory"
	lock
# 15 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_0
# 16 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_2, MSGBOX_AUTOCLOSE_TOP
# 17 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_1
# 30 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_3, MSGBOX_AUTOCLOSE_TOP
# 31 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 32 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 33 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 34 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 35 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer
# 36 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_4, MSGBOX_AUTOCLOSE
# 37 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 38 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 39 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_2
# 47 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_5, MSGBOX_AUTOCLOSE
# 48 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/GallegoRoom/scripts.pory"
	delay 40
# 50 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_6, MSGBOX_AUTOCLOSE
# 51 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HeartWithDelay48
# 53 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_7, MSGBOX_AUTOCLOSE
# 54 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_MoveAwayFromPlayer
# 55 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_8, MSGBOX_AUTOCLOSE
# 56 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_FacePlayer
# 57 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_9, MSGBOX_AUTOCLOSE
# 58 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 59 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 60 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_MoveTowardsPlayer
# 61 "data/maps/GallegoRoom/scripts.pory"
	delay 50
# 62 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 63 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 64 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_Gallego_6
# 66 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_7
# 68 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_Gallego_8
# 70 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_9
GallegoRoom_EventScript_Gallego_4:
# 73 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_10, MSGBOX_AUTOCLOSE
# 74 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 75 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_Gallego_12
# 83 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_13
# 91 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_Gallego_14
# 98 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_15
GallegoRoom_EventScript_Gallego_10:
# 105 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_11, MSGBOX_AUTOCLOSE
# 106 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 107 "data/maps/GallegoRoom/scripts.pory"
	call GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer
# 108 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_12
# 109 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 110 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_11
# 118 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_13
# 119 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_EventScript_Gallego_Text_14
# 120 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_15, MSGBOX_AUTOCLOSE
# 121 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 122 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 123 "data/maps/GallegoRoom/scripts.pory"
	delay 60
# 124 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_16, MSGBOX_AUTOCLOSE
# 125 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 127 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 128 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_17, MSGBOX_AUTOCLOSE
# 129 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_12
# 136 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_18, MSGBOX_AUTOCLOSE
# 137 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 138 "data/maps/GallegoRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 139 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_19, MSGBOX_AUTOCLOSE
# 140 "data/maps/GallegoRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GALLEGO
# 141 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_2:
# 5 "data/maps/GallegoRoom/scripts.pory"
	lock
# 6 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 7 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_0, MSGBOX_AUTOCLOSE
# 8 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 9 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 10 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_1, MSGBOX_AUTOCLOSE
# 11 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_6:
# 65 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_3
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_7:
# 67 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_4
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_8:
# 69 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_9:
# 71 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_6
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_12:
# 76 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_7
	goto GallegoRoom_EventScript_Gallego_10

GallegoRoom_EventScript_Gallego_13:
# 84 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_8
	goto GallegoRoom_EventScript_Gallego_10

GallegoRoom_EventScript_Gallego_14:
# 92 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_9
	goto GallegoRoom_EventScript_Gallego_10

GallegoRoom_EventScript_Gallego_15:
# 99 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_10
	goto GallegoRoom_EventScript_Gallego_10


GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer::
# 146 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 147 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 148 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_3
# 151 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_4
# 154 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_5
# 157 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_6
GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1:
	return

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_3:
# 149 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceDown
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_4:
# 152 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceUp
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_5:
# 155 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceRight
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1

GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_6:
# 158 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceLeft
	goto GallegoRoom_EventScript_WalkInPlaceGallegoFacingPlayer_1


GallegoRoom_EventScript_MoveAwayFromPlayer::
# 165 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 166 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 167 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 168 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_MoveAwayFromPlayer_3
# 173 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_MoveAwayFromPlayer_4
# 178 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_MoveAwayFromPlayer_5
# 183 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_MoveAwayFromPlayer_6
GallegoRoom_EventScript_MoveAwayFromPlayer_1:
# 189 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
	return

GallegoRoom_EventScript_MoveAwayFromPlayer_3:
# 169 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 170 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 171 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1

GallegoRoom_EventScript_MoveAwayFromPlayer_4:
# 174 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 175 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 176 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1

GallegoRoom_EventScript_MoveAwayFromPlayer_5:
# 179 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkLeft2
# 180 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft2
# 181 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1

GallegoRoom_EventScript_MoveAwayFromPlayer_6:
# 184 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkRight2
# 185 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
# 186 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveAwayFromPlayer_1


GallegoRoom_EventScript_MoveTowardsPlayer::
# 194 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 195 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 196 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 197 "data/maps/GallegoRoom/scripts.pory"
	case DIR_NORTH, GallegoRoom_EventScript_MoveTowardsPlayer_3
# 202 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_MoveTowardsPlayer_4
# 207 "data/maps/GallegoRoom/scripts.pory"
	case DIR_WEST, GallegoRoom_EventScript_MoveTowardsPlayer_5
# 212 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_MoveTowardsPlayer_6
GallegoRoom_EventScript_MoveTowardsPlayer_1:
# 218 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
	return

GallegoRoom_EventScript_MoveTowardsPlayer_3:
# 198 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 199 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 200 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1

GallegoRoom_EventScript_MoveTowardsPlayer_4:
# 203 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 204 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 205 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1

GallegoRoom_EventScript_MoveTowardsPlayer_5:
# 208 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkRight2
# 209 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
# 210 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1

GallegoRoom_EventScript_MoveTowardsPlayer_6:
# 213 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkLeft2
# 214 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft2
# 215 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
	goto GallegoRoom_EventScript_MoveTowardsPlayer_1


# 15 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_0:
# 15 "data/maps/GallegoRoom/scripts.pory"
	reveal_trainer
	step_end

# 18 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_1:
# 19 "data/maps/GallegoRoom/scripts.pory"
	emote_thinking
# 20 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 20 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 20 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 21 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 22 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 22 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 23 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 24 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 24 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 25 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 26 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 26 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 27 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 28 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 28 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 39 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_2:
# 40 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 41 "data/maps/GallegoRoom/scripts.pory"
	emote_double_exclamation_mark
# 42 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 43 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 43 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 44 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 45 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 65 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_3:
# 65 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 65 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 65 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 65 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 65 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 65 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 65 "data/maps/GallegoRoom/scripts.pory"
	face_down
	step_end

# 67 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_4:
# 67 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 67 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 67 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 67 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 67 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 67 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 67 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 69 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_5:
# 69 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 69 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 69 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 69 "data/maps/GallegoRoom/scripts.pory"
	face_right
	step_end

# 71 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_6:
# 71 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 71 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 71 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 71 "data/maps/GallegoRoom/scripts.pory"
	face_left
	step_end

# 76 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_7:
# 77 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 78 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 78 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 79 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 80 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 80 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 81 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 82 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 84 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_8:
# 85 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 86 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 86 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 87 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 88 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 88 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 89 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 90 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 92 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_9:
# 93 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 94 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 94 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 95 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 96 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 99 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_10:
# 100 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 101 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 101 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 102 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 103 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 110 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_11:
# 111 "data/maps/GallegoRoom/scripts.pory"
	emote_versus
# 112 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 113 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 114 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 115 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 116 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 129 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_12:
# 130 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 131 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 132 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 133 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 134 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

GallegoRoom_EventScript_Gallego_Text_0:
# 7 "data/maps/GallegoRoom/scripts.pory"
	.string "La chispa que ha vuelto a encender mi\n"
	.string "sueño ha prendido una llama que crece\l"
	.string "por momentos.$"

GallegoRoom_EventScript_Gallego_Text_1:
# 10 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Continúa en busca del tuyo, y\n"
	.string "volveremos a encontrarnos en el camino!$"

GallegoRoom_EventScript_Gallego_Text_2:
# 16 "data/maps/GallegoRoom/scripts.pory"
	.string "Ay, no, creo que me ha visto… No puedo\n"
	.string "dejar que me encuentren todavía…\p"
	.string "¿Y si me quedo muy quieto? ¿Seré capaz\n"
	.string "de escabullirme?$"

GallegoRoom_EventScript_Gallego_Text_3:
# 30 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, tendré que aceptarlo, supongo\n"
	.string "que no podía ocultarme para siempre.$"

GallegoRoom_EventScript_Gallego_Text_4:
# 36 "data/maps/GallegoRoom/scripts.pory"
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
# 47 "data/maps/GallegoRoom/scripts.pory"
	.string "Y mira tú, veinte años ya… ¡veinte!$"

GallegoRoom_EventScript_Gallego_Text_6:
# 50 "data/maps/GallegoRoom/scripts.pory"
	.string "El aniversario me ha pillado totalmente\n"
	.string "por sorpresa. ¡Si hasta hace diez años\l"
	.string "desde que me dejé ver por última vez!\p"
	.string "Y aún con esas, ese pedazo de mi vida lo\n"
	.string "recuerdo como si hubiese sido ayer.$"

GallegoRoom_EventScript_Gallego_Text_7:
# 53 "data/maps/GallegoRoom/scripts.pory"
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
# 55 "data/maps/GallegoRoom/scripts.pory"
	.string "Pero me iba a volver loco con todo\n"
	.string "aquello… demasiado difícil, los bugs\l"
	.string "aparecían como setas a cada cambio.$"

GallegoRoom_EventScript_Gallego_Text_9:
# 57 "data/maps/GallegoRoom/scripts.pory"
	.string "Y justo cuando lo dejé, cuando me rendí,\n"
	.string "aparecieron las herramientas modernas.\p"
	.string "El disassembly, los motores… todo lo que\n"
	.string "habría necesitado entonces, apareció,\l"
	.string "casi como si fuese una burla a mi\l"
	.string "esfuerzo.$"

GallegoRoom_EventScript_Gallego_Text_10:
# 73 "data/maps/GallegoRoom/scripts.pory"
	.string "Como ves, aún conservo mis viejas Game\n"
	.string "Boy Color.$"

GallegoRoom_EventScript_Gallego_Text_11:
# 105 "data/maps/GallegoRoom/scripts.pory"
	.string "Algunas ni siquiera encienden, pero\n"
	.string "siguen ahí.\p"
	.string "A pesar de todo, después de tanto\n"
	.string "tiempo, mi sueño todavía vive…\p"
	.string "El sueño no tiene fin: la maquinaria en\n"
	.string "mi cabeza todavía no se ha detenido…$"

GallegoRoom_EventScript_Gallego_Text_12:
# 108 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, suficiente reflexión por ahora.\n"
	.string "Vamos a ver si no se me ha olvidado\l"
	.string "combatir en este tiempo.$"

GallegoRoom_EventScript_Gallego_Text_13:
# 118 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Enséñame cuánto ha evolucionado la\n"
	.string "nueva generación!$"

GallegoRoom_EventScript_Gallego_Text_14:
# 119 "data/maps/GallegoRoom/scripts.pory"
	.string "Uff.. pues sí que me he quedado\n"
	.string "anticuado.$"

GallegoRoom_EventScript_Gallego_Text_15:
# 120 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece que las nuevas generaciones de\n"
	.string "entrenadores son mucho más duras de\l"
	.string "roer.\p"
	.string "Pero verte combatir me devuelve la\n"
	.string "chispa de antaño.$"

GallegoRoom_EventScript_Gallego_Text_16:
# 124 "data/maps/GallegoRoom/scripts.pory"
	.string "Es curioso… abandoné justo antes de\n"
	.string "que todo se volviera más fácil, y aun\l"
	.string "así, sigo pensando en volver.\p"
	.string "No puedo negar que soy un cabezota sin\n"
	.string "remedio…$"

GallegoRoom_EventScript_Gallego_Text_17:
# 128 "data/maps/GallegoRoom/scripts.pory"
	.string "Supongo que algunos sueños no se\n"
	.string "apagan.$"

GallegoRoom_EventScript_Gallego_Text_18:
# 136 "data/maps/GallegoRoom/scripts.pory"
	.string "Ve, continúa, ¡busca tu sueño y\n"
	.string "abrázalo con fuerza!$"

GallegoRoom_EventScript_Gallego_Text_19:
# 139 "data/maps/GallegoRoom/scripts.pory"
	.string "Yo me quedaré aquí un rato más…\n"
	.string "recordando mis viejos intentos y\l"
	.string "soñando con un nuevo y emocionante\l"
	.string "comienzo.$"
