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
	waitse
# 68 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_FALL
# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_1
# 74 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_WALL_HIT
# 76 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 77 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_2
# 79 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 80 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_FaceLeft
# 81 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_3
# 84 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 85 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_4
# 89 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 90 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_5
# 95 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 96 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_6
# 100 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 101 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_7
# 106 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 107 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_8
# 112 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 113 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_9
# 118 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 119 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_10
# 123 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 124 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 125 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 126 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 127 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 128 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 129 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_SCAREXOZUROOM_OZUMAS, DIR_SOUTH
# 130 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 131 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 132 "data/maps/ScarexOzumasRoom/scripts.pory"
	special RemoveCameraObject
# 133 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 134 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end


ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer::
# 140 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 141 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 142 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3
# 145 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4
# 148 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5
# 151 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6
ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1:
	return

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3:
# 143 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceDown
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4:
# 146 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceUp
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5:
# 149 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceRight
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6:
# 152 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceLeft
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1


ScarexOzumasRoom_EventScript_Ozumas::
# 159 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_2
# 172 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 173 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 174 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 175 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 176 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_1
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 179 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 180 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 181 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 182 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SmileWithDelay48
# 183 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_4, MSGBOX_AUTOCLOSE speaker = SP_NAME_OZUMAS
# 184 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 185 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 186 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_5
# 189 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
ScarexOzumasRoom_EventScript_Ozumas_4:
# 191 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 192 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_7, speaker = SP_NAME_OZUMAS
# 193 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 194 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 195 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_2
# 196 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 197 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_OzumasBattle
# 198 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 199 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 200 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 201 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq ScarexOzumasRoom_EventScript_Ozumas_12
# 201 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq ScarexOzumasRoom_EventScript_Ozumas_12
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_4
ScarexOzumasRoom_EventScript_Ozumas_11:
# 206 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 207 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 208 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 209 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_18
ScarexOzumasRoom_EventScript_Ozumas_17:
# 214 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 215 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 216 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 217 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 218 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 219 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 220 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 221 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 222 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 223 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 224 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 225 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 226 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_21
ScarexOzumasRoom_EventScript_Ozumas_20:
# 229 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OZUMAS
# 230 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_2:
# 160 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 161 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 162 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 163 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 164 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_9
ScarexOzumasRoom_EventScript_Ozumas_8:
# 169 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_5:
# 187 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
	goto ScarexOzumasRoom_EventScript_Ozumas_4

ScarexOzumasRoom_EventScript_Ozumas_9:
# 166 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_1, speaker = SP_NAME_OZUMAS
	goto ScarexOzumasRoom_EventScript_Ozumas_8

ScarexOzumasRoom_EventScript_Ozumas_12:
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_3
	goto ScarexOzumasRoom_EventScript_Ozumas_11

ScarexOzumasRoom_EventScript_Ozumas_18:
# 210 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 211 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
	goto ScarexOzumasRoom_EventScript_Ozumas_17

ScarexOzumasRoom_EventScript_Ozumas_21:
# 227 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
	goto ScarexOzumasRoom_EventScript_Ozumas_20


ScarexOzumasRoom_EventScript_OzumasBattle::
# 235 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ScarexOzumasRoom_EventScript_OzumasBattle_2
# 238 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_OZUMAS
# 239 "data/maps/ScarexOzumasRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 240 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ScarexOzumasRoom_EventScript_OzumasBattle_5
# 243 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_ALTERNATIVE, ScarexOzumasRoom_Text_OzumasDefeated
ScarexOzumasRoom_EventScript_OzumasBattle_1:
# 246 "data/maps/ScarexOzumasRoom/scripts.pory"
	special HealPlayerParty
	return

ScarexOzumasRoom_EventScript_OzumasBattle_2:
# 236 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_MAIN, ScarexOzumasRoom_Text_OzumasDefeated
	goto ScarexOzumasRoom_EventScript_OzumasBattle_1

ScarexOzumasRoom_EventScript_OzumasBattle_5:
# 241 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_MAIN, ScarexOzumasRoom_Text_OzumasDefeated
	goto ScarexOzumasRoom_EventScript_OzumasBattle_1


ScarexOzumasRoom_EventScript_Scarex::
# 255 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 256 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 257 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Scarex_2
# 287 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 288 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SurpriseWithDelay48
# 289 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 290 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 291 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 292 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HeartWithDelay48
# 293 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 294 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 295 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 10
# 296 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 297 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 298 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 299 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 300 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 301 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 305 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 306 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 307 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HappyWithDelay48
# 308 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 309 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 30
# 310 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 311 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 312 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 313 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 314 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 315 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VersusWithDelay48
# 316 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 317 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 318 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 319 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 320 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 321 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 322 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 323 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 324 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 325 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 329 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 333 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 334 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 335 "data/maps/ScarexOzumasRoom/scripts.pory"
	getdirectiontoface VAR_RESULT, LOCALID_PLAYER, LOCALID_SCAREXOZUROOM_SCAREX
# 336 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 337 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_Scarex_6
# 340 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_Scarex_7
# 343 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_Scarex_8
# 346 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_Scarex_9
ScarexOzumasRoom_EventScript_Scarex_4:
# 350 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_ScarexBattle
# 351 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 352 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VWithDelay48
# 353 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 354 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Scarex_23
ScarexOzumasRoom_EventScript_Scarex_22:
# 360 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SCAREX
# 361 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Scarex_2:
# 258 "data/maps/ScarexOzumasRoom/scripts.pory"
	random 10
# 259 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 260 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 261 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 0, ScarexOzumasRoom_EventScript_Scarex_12
# 263 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 1, ScarexOzumasRoom_EventScript_Scarex_13
# 265 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 2, ScarexOzumasRoom_EventScript_Scarex_14
# 267 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 3, ScarexOzumasRoom_EventScript_Scarex_15
# 269 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 4, ScarexOzumasRoom_EventScript_Scarex_16
# 271 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 5, ScarexOzumasRoom_EventScript_Scarex_17
# 273 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 6, ScarexOzumasRoom_EventScript_Scarex_18
# 275 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 7, ScarexOzumasRoom_EventScript_Scarex_19
# 277 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 8, ScarexOzumasRoom_EventScript_Scarex_20
# 279 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 9, ScarexOzumasRoom_EventScript_Scarex_21
ScarexOzumasRoom_EventScript_Scarex_10:
# 282 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 283 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Scarex_6:
# 338 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_7:
# 341 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_8:
# 344 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_9:
# 347 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_12:
# 262 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SurpriseWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_13:
# 264 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SmileWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_14:
# 266 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HappyWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_15:
# 268 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_AngryWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_16:
# 270 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HeartWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_17:
# 272 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SweatDropWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_18:
# 274 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_CryWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_19:
# 276 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_20:
# 278 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_ThinkingWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_21:
# 280 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SadWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_23:
# 355 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_FaceRight
# 356 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 357 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 358 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_FacePlayer
	goto ScarexOzumasRoom_EventScript_Scarex_22


ScarexOzumasRoom_EventScript_ScarexBattle::
# 366 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ScarexOzumasRoom_EventScript_ScarexBattle_2
# 369 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SCAREX
# 370 "data/maps/ScarexOzumasRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 371 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ScarexOzumasRoom_EventScript_ScarexBattle_5
# 374 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_ALTERNATIVE, ScarexOzumasRoom_Text_ScarexDefeated
ScarexOzumasRoom_EventScript_ScarexBattle_1:
# 377 "data/maps/ScarexOzumasRoom/scripts.pory"
	special HealPlayerParty
	return

ScarexOzumasRoom_EventScript_ScarexBattle_2:
# 367 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_MAIN, ScarexOzumasRoom_Text_ScarexDefeated
	goto ScarexOzumasRoom_EventScript_ScarexBattle_1

ScarexOzumasRoom_EventScript_ScarexBattle_5:
# 372 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_MAIN, ScarexOzumasRoom_Text_ScarexDefeated
	goto ScarexOzumasRoom_EventScript_ScarexBattle_1


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

# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_1:
# 70 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 71 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 72 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
	step_end

# 78 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_2:
# 78 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
	step_end

# 81 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_3:
# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
	step_end

# 85 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_4:
# 86 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 87 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
	step_end

# 90 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_5:
# 91 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 92 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 93 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 93 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

# 96 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_6:
# 97 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 98 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
	step_end

# 101 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_7:
# 102 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 103 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 104 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 104 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
	step_end

# 107 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_8:
# 108 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 109 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 110 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 110 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
	step_end

# 113 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_9:
# 114 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 115 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 116 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
	step_end

# 119 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_10:
# 120 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 121 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 121 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

# 175 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_0:
# 175 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock_facing_direction
	step_end

# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_1:
# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
	unlock_facing_direction
# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 195 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_2:
# 195 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_versus
	step_end

# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_3:
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_thinking
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_4:
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_thinking
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 204 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 218 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_5:
# 218 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
	step_end

# 301 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Scarex_Movement_0:
# 302 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 303 "data/maps/ScarexOzumasRoom/scripts.pory"
	unlock_facing_direction
	step_end

ScarexOzumasRoom_EventScript_EnterRoom_Text_0:
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Y Scarex? Se supone ya debería estar\n"
	.string "aquí.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_0:
# 162 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Oye, estuve repitiendo nuestro combate\n"
	.string "en mi cabeza, y no puedo mentir: me\l"
	.string "diste una buena paliza.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_1:
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Ya has demostrado tu fuerza. Ahora ve a\n"
	.string "enfrentarte a Scarex.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_2:
# 174 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Bueno, parece que ha llegado el momento\n"
	.string "que teníamos pendiente.\p"
	.string "Soy Ozumas, de la sangre de la\n"
	.string "legendaria dinastía Mendrax.\p"
	.string "Hace mucho, fuimos muy conocidos,\n"
	.string "sobretodo por nunca escapar a un reto.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_3:
# 180 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Así que no me conoces? Pues no te\n"
	.string "preocupes, han pasado muchos años ya.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_4:
# 183 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres saber algo de mí, te diré que\n"
	.string "desde siempre me atrajeron las\l"
	.string "historias de Johto.\p"
	.string "Pasé años tratando de contar al mundo\n"
	.string "sus leyendas.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_5:
# 187 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Parece que ya has derrotado a Scarex,\n"
	.string "así que si logras vencerme, podrás\l"
	.string "avanzar.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_6:
# 189 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres avanzar, primero tendrás que\n"
	.string "derrotar a Scarex y a mí.\p"
	.string "Parece que yo seré tu primer\n"
	.string "contrincante.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_7:
# 192 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Vamos a ver qué historia sale de esta\n"
	.string "batalla.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_8:
# 198 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Has demostrado que tienes fuerza y\n"
	.string "convicción… ¡te felicito!$"

ScarexOzumasRoom_EventScript_Ozumas_Text_9:
# 206 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Pero si quieres ganar, aún queda un\n"
	.string "largo camino por delante…$"

ScarexOzumasRoom_EventScript_Ozumas_Text_10:
# 210 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Primero, deberás enfrentarte a Scarex\n"
	.string "para poder avanzar a la siguiente sala.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_11:
# 215 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Más adelante, aguarda una batalla\n"
	.string "contra alguien muy cercano a mí.\p"
	.string "Es un gran amigo y rival. Quizá lo\n"
	.string "conozcas, se llama Xiros.\p"
	.string "Será esa prueba la que determine si\n"
	.string "realmente puedes ganar el desafío.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_12:
# 225 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Estoy seguro de que lo harás genial.\n"
	.string "¡Mucha suerte!$"

ScarexOzumasRoom_Text_OzumasDefeated::
# 250 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¡Eso ha estado muy guay!$"

ScarexOzumasRoom_Text_ScarexDefeated::
# 381 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "…$"
