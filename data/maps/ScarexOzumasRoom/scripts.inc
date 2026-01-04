ScarexOzumasRoom_MapScripts::
# 4 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ScarexOzumasRoom_OnTransition
# 8 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ScarexOzumasRoom_OnLoad
# 5 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ScarexOzumasRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ScarexOzumasRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ScarexOzumasRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ScarexOzumasRoom_OnLoad::
# 13 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_OnLoad_3
ScarexOzumasRoom_OnLoad_1:
	end

ScarexOzumasRoom_OnLoad_2:
# 14 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ScarexOzumasRoom_OnLoad_1

ScarexOzumasRoom_OnLoad_3:
# 13 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_OnLoad_2
	goto ScarexOzumasRoom_OnLoad_1


ScarexOzumasRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ScarexOzumasRoom_OnTransition::
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq ScarexOzumasRoom_OnTransition_2
ScarexOzumasRoom_OnTransition_1:
	end

ScarexOzumasRoom_OnTransition_2:
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxy LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
# 28 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
	goto ScarexOzumasRoom_OnTransition_1


ScarexOzumasRoom_EventScript_EnterRoom::
# 34 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 35 "data/maps/ScarexOzumasRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 36 "data/maps/ScarexOzumasRoom/scripts.pory"
	special SpawnCameraObject
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 39 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 41 "data/maps/ScarexOzumasRoom/scripts.pory"
	showobjectat LOCALID_SCAREXOZUROOM_OZUMAS, MAP_SCAREX_OZUMAS_ROOM
# 42 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 43 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 44 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkDown
# 45 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 46 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_EnterRoom_Movement_0
# 62 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
# 63 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 64 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_QuestionMarkWithDelay48
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_EnterRoom_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 66 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_1
# 73 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_FaceLeft
# 74 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_2
# 95 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 96 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 97 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 98 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 99 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_SCAREXOZUROOM_OZUMAS, DIR_SOUTH
# 100 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 101 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 102 "data/maps/ScarexOzumasRoom/scripts.pory"
	special RemoveCameraObject
# 103 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 104 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end


ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer::
# 110 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 111 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3
# 115 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4
# 118 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5
# 121 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6
ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1:
	return

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3:
# 113 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceDown
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4:
# 116 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceUp
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5:
# 119 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceRight
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6:
# 122 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceLeft
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1


ScarexOzumasRoom_EventScript_Ozumas::
# 129 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_2
# 142 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 143 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 144 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 146 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 147 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 148 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SmileWithDelay48
# 150 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_4, MSGBOX_AUTOCLOSE speaker = SP_NAME_OZUMAS
# 151 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 152 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 153 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_5
# 156 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
ScarexOzumasRoom_EventScript_Ozumas_4:
# 158 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 159 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_7, speaker = SP_NAME_OZUMAS
# 160 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 161 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_MAIN, ScarexOzumasRoom_EventScript_Ozumas_Text_8
# 162 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 163 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 164 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq ScarexOzumasRoom_EventScript_Ozumas_12
# 164 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq ScarexOzumasRoom_EventScript_Ozumas_12
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_2
ScarexOzumasRoom_EventScript_Ozumas_11:
# 169 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 170 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 171 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 172 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_18
ScarexOzumasRoom_EventScript_Ozumas_17:
# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 179 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 180 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_JumpInPlaceDown2
# 181 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 182 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 183 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_21
ScarexOzumasRoom_EventScript_Ozumas_20:
# 186 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OZUMAS
# 187 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_2:
# 130 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 131 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 132 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 133 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 134 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 135 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_9
ScarexOzumasRoom_EventScript_Ozumas_8:
# 139 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_5:
# 154 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
	goto ScarexOzumasRoom_EventScript_Ozumas_4

ScarexOzumasRoom_EventScript_Ozumas_9:
# 136 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 137 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_1, speaker = SP_NAME_OZUMAS
	goto ScarexOzumasRoom_EventScript_Ozumas_8

ScarexOzumasRoom_EventScript_Ozumas_12:
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_1
	goto ScarexOzumasRoom_EventScript_Ozumas_11

ScarexOzumasRoom_EventScript_Ozumas_18:
# 173 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 174 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
	goto ScarexOzumasRoom_EventScript_Ozumas_17

ScarexOzumasRoom_EventScript_Ozumas_21:
# 184 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
	goto ScarexOzumasRoom_EventScript_Ozumas_20


ScarexOzumasRoom_EventScript_Scarex::
# 192 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 193 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 194 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Scarex_2
# 224 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 225 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SurpriseWithDelay48
# 226 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 227 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 228 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 229 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HeartWithDelay48
# 230 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 231 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 232 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 10
# 233 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 238 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 239 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HappyWithDelay48
# 240 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 241 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 30
# 242 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 243 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 244 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 245 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 246 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VersusWithDelay48
# 247 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 252 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 257 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 258 "data/maps/ScarexOzumasRoom/scripts.pory"
	getdirectiontoface VAR_RESULT, LOCALID_PLAYER, LOCALID_SCAREXOZUROOM_SCAREX
# 259 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 260 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_Scarex_6
# 263 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_Scarex_7
# 266 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_Scarex_8
# 269 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_Scarex_9
ScarexOzumasRoom_EventScript_Scarex_4:
# 273 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_MAIN, ScarexOzumasRoom_EventScript_Scarex_Text_0
# 274 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 275 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VWithDelay48
# 276 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 277 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Scarex_23
ScarexOzumasRoom_EventScript_Scarex_22:
# 283 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SCAREX
# 284 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Scarex_2:
# 195 "data/maps/ScarexOzumasRoom/scripts.pory"
	random 10
# 196 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 197 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 198 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 0, ScarexOzumasRoom_EventScript_Scarex_12
# 200 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 1, ScarexOzumasRoom_EventScript_Scarex_13
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 2, ScarexOzumasRoom_EventScript_Scarex_14
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 3, ScarexOzumasRoom_EventScript_Scarex_15
# 206 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 4, ScarexOzumasRoom_EventScript_Scarex_16
# 208 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 5, ScarexOzumasRoom_EventScript_Scarex_17
# 210 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 6, ScarexOzumasRoom_EventScript_Scarex_18
# 212 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 7, ScarexOzumasRoom_EventScript_Scarex_19
# 214 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 8, ScarexOzumasRoom_EventScript_Scarex_20
# 216 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 9, ScarexOzumasRoom_EventScript_Scarex_21
ScarexOzumasRoom_EventScript_Scarex_10:
# 219 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 220 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Scarex_6:
# 261 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_7:
# 264 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_8:
# 267 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_9:
# 270 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_12:
# 199 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SurpriseWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_13:
# 201 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SmileWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_14:
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HappyWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_15:
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_AngryWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_16:
# 207 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HeartWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_17:
# 209 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SweatDropWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_18:
# 211 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_CryWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_19:
# 213 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_20:
# 215 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_ThinkingWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_21:
# 217 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SadWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_23:
# 278 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_FaceRight
# 279 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 280 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 281 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_FacePlayer
	goto ScarexOzumasRoom_EventScript_Scarex_22


# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_0:
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 49 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 50 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 51 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 52 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
# 53 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 54 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_right
# 55 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 56 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_up
# 57 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_left
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 60 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
	step_end

# 67 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_1:
# 68 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 70 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
# 71 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
	step_end

# 74 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_2:
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 76 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 77 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 78 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 79 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 80 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 80 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 81 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 83 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 84 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 85 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 85 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 86 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 87 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 88 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 88 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 89 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 90 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 91 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
# 92 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 93 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 93 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_0:
# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock_facing_direction
# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
	unlock_facing_direction
# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_1:
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_thinking
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_2:
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_thinking
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 233 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Scarex_Movement_0:
# 234 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock_facing_direction
# 235 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 235 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 236 "data/maps/ScarexOzumasRoom/scripts.pory"
	unlock_facing_direction
	step_end

ScarexOzumasRoom_EventScript_EnterRoom_Text_0:
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Y Scarex? Se supone ya debería estar\n"
	.string "aquí.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_0:
# 132 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Oye, estuve repitiendo nuestro combate\n"
	.string "en mi cabeza, y no puedo mentir: me\l"
	.string "diste una buena paliza.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_1:
# 137 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Ya has demostrado tu fuerza. Ahora ve a\n"
	.string "enfrentarte a Scarex.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_2:
# 144 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Bueno, parece que ha llegado el momento\n"
	.string "que teníamos pendiente.\p"
	.string "Soy Ozumas, de la sangre de la\n"
	.string "legendaria dinastía Mendrax.\p"
	.string "Hace mucho, fuimos muy conocidos,\n"
	.string "sobretodo por nunca escapar a un reto.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_3:
# 147 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Así que no me conoces? Pues no te\n"
	.string "preocupes, han pasado muchos años ya.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_4:
# 150 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres saber algo de mí, te diré que\n"
	.string "desde siempre me atrajeron las\l"
	.string "historias de Johto.\p"
	.string "Pasé años tratando de contar al mundo\n"
	.string "sus leyendas.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_5:
# 154 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Parece que ya has derrotado a Scarex,\n"
	.string "así que si logras vencerme, podrás\l"
	.string "avanzar.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_6:
# 156 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres avanzar, primero tendrás que\n"
	.string "derrotar a Scarex y a mí.\p"
	.string "Parece que yo seré tu primer\n"
	.string "contrincante.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_7:
# 159 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Vamos a ver qué historia sale de esta\n"
	.string "batalla.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_8:
# 161 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¡Eso ha estado muy guay!$"

ScarexOzumasRoom_EventScript_Ozumas_Text_9:
# 162 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Has demostrado que tienes fuerza y\n"
	.string "convicción… ¡te felicito!$"

ScarexOzumasRoom_EventScript_Ozumas_Text_10:
# 169 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Pero si quieres ganar, aún queda un\n"
	.string "largo camino por delante…$"

ScarexOzumasRoom_EventScript_Ozumas_Text_11:
# 173 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Primero, deberás enfrentarte a Scarex\n"
	.string "para poder avanzar a la siguiente sala.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_12:
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Más adelante, aguarda una batalla\n"
	.string "contra alguien muy cercano a mí.\p"
	.string "Es un gran amigo y rival. Quizá lo\n"
	.string "conozcas, se llama Xiros.\p"
	.string "Será esa prueba la que determine si\n"
	.string "realmente puedes ganar el desafío.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_13:
# 181 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Estoy seguro de que lo harás genial.\n"
	.string "¡Mucha suerte!$"

ScarexOzumasRoom_EventScript_Scarex_Text_0:
# 273 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "...$"
