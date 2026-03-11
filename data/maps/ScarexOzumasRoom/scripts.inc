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
	call WahRoomsShared_Kecleon_SetSala_ScarexOzumas
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq ScarexOzumasRoom_OnTransition_2
ScarexOzumasRoom_OnTransition_1:
	end

ScarexOzumasRoom_OnTransition_2:
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 28 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxy LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
# 29 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
	goto ScarexOzumasRoom_OnTransition_1


ScarexOzumasRoom_EventScript_EnterRoom::
# 35 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 36 "data/maps/ScarexOzumasRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	special SpawnCameraObject
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 39 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 41 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 42 "data/maps/ScarexOzumasRoom/scripts.pory"
	showobjectat LOCALID_SCAREXOZUROOM_OZUMAS, MAP_SCAREX_OZUMAS_ROOM
# 43 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 44 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 45 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkDown
# 46 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_EnterRoom_Movement_0
# 63 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
# 64 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_QuestionMarkWithDelay48
# 66 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_EnterRoom_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 67 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_FALL
# 70 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_1
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 76 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_WALL_HIT
# 77 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 78 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 79 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_2
# 80 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 81 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_FaceLeft
# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_3
# 85 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 86 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_4
# 90 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_5
# 96 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_6
# 101 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 102 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_7
# 107 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 108 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_8
# 113 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 114 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_9
# 119 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 120 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_10
# 124 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 125 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 127 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 128 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 129 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 130 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_SCAREXOZUROOM_OZUMAS, DIR_SOUTH
# 131 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 132 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 133 "data/maps/ScarexOzumasRoom/scripts.pory"
	special RemoveCameraObject
# 134 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 135 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end


ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer::
# 141 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 142 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 143 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3
# 146 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4
# 149 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5
# 152 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6
ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1:
	return

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3:
# 144 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceDown
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4:
# 147 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceUp
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5:
# 150 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceRight
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6:
# 153 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceLeft
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1


ScarexOzumasRoom_EventScript_Ozumas::
# 160 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_2
# 173 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 174 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 175 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 176 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 177 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_1
# 179 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 180 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 181 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 182 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 183 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SmileWithDelay48
# 184 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_4, MSGBOX_AUTOCLOSE speaker = SP_NAME_OZUMAS
# 185 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 186 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 187 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_5
# 190 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
ScarexOzumasRoom_EventScript_Ozumas_4:
# 192 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 193 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_7, speaker = SP_NAME_OZUMAS
# 194 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 195 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 196 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_2
# 197 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 198 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_OzumasBattle
# 199 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 200 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 201 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq ScarexOzumasRoom_EventScript_Ozumas_12
# 202 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq ScarexOzumasRoom_EventScript_Ozumas_12
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_4
ScarexOzumasRoom_EventScript_Ozumas_11:
# 207 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 208 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 209 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 210 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_18
ScarexOzumasRoom_EventScript_Ozumas_17:
# 215 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 216 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 217 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 218 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 219 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 220 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 221 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 222 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 223 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 224 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 225 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 226 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 227 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_21
ScarexOzumasRoom_EventScript_Ozumas_20:
# 230 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OZUMAS
# 231 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_2:
# 161 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 162 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 163 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 164 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 165 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 166 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_9
ScarexOzumasRoom_EventScript_Ozumas_8:
# 170 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_5:
# 188 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
	goto ScarexOzumasRoom_EventScript_Ozumas_4

ScarexOzumasRoom_EventScript_Ozumas_9:
# 167 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 168 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_1, speaker = SP_NAME_OZUMAS
	goto ScarexOzumasRoom_EventScript_Ozumas_8

ScarexOzumasRoom_EventScript_Ozumas_12:
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_Movement_3
	goto ScarexOzumasRoom_EventScript_Ozumas_11

ScarexOzumasRoom_EventScript_Ozumas_18:
# 211 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OZUMAS
# 212 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
	goto ScarexOzumasRoom_EventScript_Ozumas_17

ScarexOzumasRoom_EventScript_Ozumas_21:
# 228 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
	goto ScarexOzumasRoom_EventScript_Ozumas_20


ScarexOzumasRoom_EventScript_OzumasBattle::
# 236 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ScarexOzumasRoom_EventScript_OzumasBattle_2
# 239 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_OZUMAS
# 240 "data/maps/ScarexOzumasRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 241 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ScarexOzumasRoom_EventScript_OzumasBattle_5
# 244 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_ALTERNATIVE, ScarexOzumasRoom_Text_OzumasDefeated
ScarexOzumasRoom_EventScript_OzumasBattle_1:
# 247 "data/maps/ScarexOzumasRoom/scripts.pory"
	special HealPlayerParty
	return

ScarexOzumasRoom_EventScript_OzumasBattle_2:
# 237 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_MAIN, ScarexOzumasRoom_Text_OzumasDefeated
	goto ScarexOzumasRoom_EventScript_OzumasBattle_1

ScarexOzumasRoom_EventScript_OzumasBattle_5:
# 242 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_MAIN, ScarexOzumasRoom_Text_OzumasDefeated
	goto ScarexOzumasRoom_EventScript_OzumasBattle_1


ScarexOzumasRoom_EventScript_Scarex::
# 256 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 257 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 258 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Scarex_2
# 288 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 289 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SurpriseWithDelay48
# 290 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 291 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 292 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 293 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HeartWithDelay48
# 294 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 295 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 296 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 10
# 297 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 298 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 299 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 300 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 301 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 302 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 306 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 307 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 308 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HappyWithDelay48
# 309 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 310 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 30
# 311 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 312 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 313 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 314 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 315 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 316 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VersusWithDelay48
# 317 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 318 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Ozumas_Movement_0
# 319 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 320 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 321 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 322 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Ozumas_Movement_5
# 323 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 324 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 325 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_LEDGE
# 326 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 330 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_PLAYER, ScarexOzumasRoom_EventScript_Scarex_Movement_0
# 334 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 335 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 336 "data/maps/ScarexOzumasRoom/scripts.pory"
	getdirectiontoface VAR_RESULT, LOCALID_PLAYER, LOCALID_SCAREXOZUROOM_SCAREX
# 337 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 338 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_Scarex_6
# 341 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_Scarex_7
# 344 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_Scarex_8
# 347 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_Scarex_9
ScarexOzumasRoom_EventScript_Scarex_4:
# 351 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_ScarexBattle
# 352 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 353 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VWithDelay48
# 354 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 355 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Scarex_23
ScarexOzumasRoom_EventScript_Scarex_22:
# 361 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SCAREX
# 362 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Scarex_2:
# 259 "data/maps/ScarexOzumasRoom/scripts.pory"
	random 10
# 260 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 261 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 262 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 0, ScarexOzumasRoom_EventScript_Scarex_12
# 264 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 1, ScarexOzumasRoom_EventScript_Scarex_13
# 266 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 2, ScarexOzumasRoom_EventScript_Scarex_14
# 268 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 3, ScarexOzumasRoom_EventScript_Scarex_15
# 270 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 4, ScarexOzumasRoom_EventScript_Scarex_16
# 272 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 5, ScarexOzumasRoom_EventScript_Scarex_17
# 274 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 6, ScarexOzumasRoom_EventScript_Scarex_18
# 276 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 7, ScarexOzumasRoom_EventScript_Scarex_19
# 278 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 8, ScarexOzumasRoom_EventScript_Scarex_20
# 280 "data/maps/ScarexOzumasRoom/scripts.pory"
	case 9, ScarexOzumasRoom_EventScript_Scarex_21
ScarexOzumasRoom_EventScript_Scarex_10:
# 283 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitse
# 284 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Scarex_6:
# 339 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_7:
# 342 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_8:
# 345 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_9:
# 348 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
	goto ScarexOzumasRoom_EventScript_Scarex_4

ScarexOzumasRoom_EventScript_Scarex_12:
# 263 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SurpriseWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_13:
# 265 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SmileWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_14:
# 267 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HappyWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_15:
# 269 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_AngryWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_16:
# 271 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_HeartWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_17:
# 273 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SweatDropWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_18:
# 275 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_CryWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_19:
# 277 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_VWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_20:
# 279 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_ThinkingWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_21:
# 281 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_SadWithDelay48
	goto ScarexOzumasRoom_EventScript_Scarex_10

ScarexOzumasRoom_EventScript_Scarex_23:
# 356 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_FaceRight
# 357 "data/maps/ScarexOzumasRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 358 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 359 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, Common_Movement_FacePlayer
	goto ScarexOzumasRoom_EventScript_Scarex_22


ScarexOzumasRoom_EventScript_ScarexBattle::
# 367 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ScarexOzumasRoom_EventScript_ScarexBattle_2
# 370 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SCAREX
# 371 "data/maps/ScarexOzumasRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 372 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ScarexOzumasRoom_EventScript_ScarexBattle_5
# 375 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_ALTERNATIVE, ScarexOzumasRoom_Text_ScarexDefeated
ScarexOzumasRoom_EventScript_ScarexBattle_1:
# 378 "data/maps/ScarexOzumasRoom/scripts.pory"
	special HealPlayerParty
	return

ScarexOzumasRoom_EventScript_ScarexBattle_2:
# 368 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_MAIN, ScarexOzumasRoom_Text_ScarexDefeated
	goto ScarexOzumasRoom_EventScript_ScarexBattle_1

ScarexOzumasRoom_EventScript_ScarexBattle_5:
# 373 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SCAREX_MAIN, ScarexOzumasRoom_Text_ScarexDefeated
	goto ScarexOzumasRoom_EventScript_ScarexBattle_1


# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_0:
# 49 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 50 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 51 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 52 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 53 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
# 54 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 55 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_right
# 56 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 57 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_up
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_left
# 60 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 61 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
	step_end

# 70 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_1:
# 71 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 72 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 73 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
	step_end

# 79 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_2:
# 79 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
	step_end

# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_3:
# 83 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 83 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 83 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
	step_end

# 86 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_4:
# 87 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 88 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
	step_end

# 91 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_5:
# 92 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 93 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 94 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 94 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

# 97 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_6:
# 98 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 99 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
	step_end

# 102 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_7:
# 103 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 104 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 105 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 105 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
	step_end

# 108 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_8:
# 109 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 110 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 111 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 111 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
	step_end

# 114 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_9:
# 115 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 116 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 117 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
	step_end

# 120 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_10:
# 121 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 122 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 122 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

# 176 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_0:
# 176 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock_facing_direction
	step_end

# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_1:
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	unlock_facing_direction
# 178 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 196 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_2:
# 196 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_versus
	step_end

# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_3:
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_thinking
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_left
# 203 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_4:
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_thinking
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_up
# 205 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_player
	step_end

# 219 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Ozumas_Movement_5:
# 219 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
	step_end

# 302 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_Scarex_Movement_0:
# 303 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down
# 304 "data/maps/ScarexOzumasRoom/scripts.pory"
	unlock_facing_direction
	step_end

ScarexOzumasRoom_EventScript_EnterRoom_Text_0:
# 66 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Y Scarex? Se supone ya debería estar\n"
	.string "aquí.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_0:
# 163 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Oye, estuve repitiendo nuestro combate\n"
	.string "en mi cabeza, y no puedo mentir: me\l"
	.string "diste una buena paliza.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_1:
# 168 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Ya has demostrado tu fuerza. Ahora ve a\n"
	.string "enfrentarte a Scarex.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_2:
# 175 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Bueno, parece que ha llegado el momento\n"
	.string "que teníamos pendiente.\p"
	.string "Soy Ozumas, de la sangre de la\n"
	.string "legendaria dinastía Mendrax.\p"
	.string "Hace mucho, fuimos muy conocidos,\n"
	.string "sobretodo por nunca escapar a un reto.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_3:
# 181 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Así que no me conoces? Pues no te\n"
	.string "preocupes, han pasado muchos años ya.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_4:
# 184 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres saber algo de mí, te diré que\n"
	.string "desde siempre me atrajeron las\l"
	.string "historias de Johto.\p"
	.string "Pasé años tratando de contar al mundo\n"
	.string "sus leyendas.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_5:
# 188 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Parece que ya has derrotado a Scarex,\n"
	.string "así que si logras vencerme, podrás\l"
	.string "avanzar.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_6:
# 190 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres avanzar, primero tendrás que\n"
	.string "derrotar a Scarex y a mí.\p"
	.string "Parece que yo seré tu primer\n"
	.string "contrincante.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_7:
# 193 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Vamos a ver qué historia sale de esta\n"
	.string "batalla.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_8:
# 199 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Has demostrado que tienes fuerza y\n"
	.string "convicción… ¡te felicito!$"

ScarexOzumasRoom_EventScript_Ozumas_Text_9:
# 207 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Pero si quieres ganar, aún queda un\n"
	.string "largo camino por delante…$"

ScarexOzumasRoom_EventScript_Ozumas_Text_10:
# 211 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Primero, deberás enfrentarte a Scarex\n"
	.string "para poder avanzar a la siguiente sala.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_11:
# 216 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Más adelante, aguarda una batalla\n"
	.string "contra alguien muy cercano a mí.\p"
	.string "Es un gran amigo y rival. Quizá lo\n"
	.string "conozcas, se llama Xiros.\p"
	.string "Será esa prueba la que determine si\n"
	.string "realmente puedes ganar el desafío.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_12:
# 226 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Estoy seguro de que lo harás genial.\n"
	.string "¡Mucha suerte!$"

ScarexOzumasRoom_Text_OzumasDefeated::
# 251 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¡Eso ha estado muy guay!$"

ScarexOzumasRoom_Text_ScarexDefeated::
# 382 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "…$"
