AngelRoom_MapScripts::
# 5 "data/maps/AngelRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AngelRoom_OnLoad
# 6 "data/maps/AngelRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AngelRoom_OnTransition
# 2 "data/maps/AngelRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AngelRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

AngelRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/AngelRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, AngelRoom_OnWarp_PlayerTurnNorth
	.2byte 0


AngelRoom_OnWarp_PlayerTurnNorth::
# 11 "data/maps/AngelRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


AngelRoom_OnLoad::
# 15 "data/maps/AngelRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_ANGEL, AngelRoom_OnLoad_2
AngelRoom_OnLoad_1:
	end

AngelRoom_OnLoad_2:
# 16 "data/maps/AngelRoom/scripts.pory"
	call AngelRoom_EventScript_SetScreenAsClosed
# 17 "data/maps/AngelRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto AngelRoom_OnLoad_1


AngelRoom_OnTransition::
# 22 "data/maps/AngelRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Angel
	end


AngelRoom_EventScript_Angel::
# 26 "data/maps/AngelRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_ANGEL, AngelRoom_EventScript_Angel_2
# 31 "data/maps/AngelRoom/scripts.pory"
	lock
# 32 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 33 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 34 "data/maps/AngelRoom/scripts.pory"
	faceplayer
# 35 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 36 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_0
# 37 "data/maps/AngelRoom/scripts.pory"
	waitse
# 38 "data/maps/AngelRoom/scripts.pory"
	playse SE_LEDGE
# 39 "data/maps/AngelRoom/scripts.pory"
	applymovement LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_1
# 44 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 45 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 47 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 48 "data/maps/AngelRoom/scripts.pory"
	delay 10
# 49 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_HappyWithDelay48
# 51 "data/maps/AngelRoom/scripts.pory"
	waitse
# 52 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 53 "data/maps/AngelRoom/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_TEMP_0
# 54 "data/maps/AngelRoom/scripts.pory"
	switch VAR_TEMP_0
# 55 "data/maps/AngelRoom/scripts.pory"
	case DIR_NORTH, AngelRoom_EventScript_Angel_6
# 58 "data/maps/AngelRoom/scripts.pory"
	case DIR_SOUTH, AngelRoom_EventScript_Angel_7
# 61 "data/maps/AngelRoom/scripts.pory"
	case DIR_WEST, AngelRoom_EventScript_Angel_8
# 64 "data/maps/AngelRoom/scripts.pory"
	case DIR_EAST, AngelRoom_EventScript_Angel_9
AngelRoom_EventScript_Angel_4:
# 68 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 69 "data/maps/AngelRoom/scripts.pory"
	playse SE_LEDGE
# 70 "data/maps/AngelRoom/scripts.pory"
	switch VAR_TEMP_0
# 71 "data/maps/AngelRoom/scripts.pory"
	case DIR_NORTH, AngelRoom_EventScript_Angel_12
# 74 "data/maps/AngelRoom/scripts.pory"
	case DIR_SOUTH, AngelRoom_EventScript_Angel_13
# 77 "data/maps/AngelRoom/scripts.pory"
	case DIR_WEST, AngelRoom_EventScript_Angel_14
# 80 "data/maps/AngelRoom/scripts.pory"
	case DIR_EAST, AngelRoom_EventScript_Angel_15
AngelRoom_EventScript_Angel_10:
# 84 "data/maps/AngelRoom/scripts.pory"
	waitse
# 85 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_5, speaker = SP_NAME_ANGEL
# 86 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 87 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_6
# 88 "data/maps/AngelRoom/scripts.pory"
	waitse
# 89 "data/maps/AngelRoom/scripts.pory"
	call AngelRoom_EventScript_AngelBattle
# 90 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 91 "data/maps/AngelRoom/scripts.pory"
	applymovement LOCALID_ANGELROOM_ANGEL, Common_Movement_SurpriseWithDelay48
# 92 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 93 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 95 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 96 "data/maps/AngelRoom/scripts.pory"
	call AngelRoom_EventScript_TurnOffScreen
# 97 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 98 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 99 "data/maps/AngelRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 100 "data/maps/AngelRoom/scripts.pory"
	special SpawnCameraObject
# 101 "data/maps/AngelRoom/scripts.pory"
	directcameramovementtopos 6, 2
# 102 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 103 "data/maps/AngelRoom/scripts.pory"
	call AngelRoom_EventScript_CloseScreen
# 104 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 105 "data/maps/AngelRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 106 "data/maps/AngelRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 107 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 108 "data/maps/AngelRoom/scripts.pory"
	special RemoveCameraObject
# 109 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 110 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 111 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 112 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_HappyWithDelay48
# 113 "data/maps/AngelRoom/scripts.pory"
	waitse
# 114 "data/maps/AngelRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 115 "data/maps/AngelRoom/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq AngelRoom_EventScript_Angel_17
# 122 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_8
# 124 "data/maps/AngelRoom/scripts.pory"
	setobjectxy LOCALID_ANGELROOM_ANGEL, 5, 5
# 125 "data/maps/AngelRoom/scripts.pory"
	setobjectxyperm LOCALID_ANGELROOM_ANGEL, 5, 5
# 126 "data/maps/AngelRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_ANGELROOM_ANGEL, MOVEMENT_TYPE_FACE_RIGHT
AngelRoom_EventScript_Angel_16:
# 128 "data/maps/AngelRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_ANGEL
# 129 "data/maps/AngelRoom/scripts.pory"
	release
	end

AngelRoom_EventScript_Angel_2:
# 27 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_0, MSGBOX_NPC, speaker = SP_NAME_ANGEL
# 28 "data/maps/AngelRoom/scripts.pory"
	release
	end

AngelRoom_EventScript_Angel_6:
# 56 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkUp2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_7:
# 59 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkDown2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_8:
# 62 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkLeft2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_9:
# 65 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkRight2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_12:
# 72 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_2
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_13:
# 75 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_3
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_14:
# 78 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_4
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_15:
# 81 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_5
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_17:
# 116 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_7
# 118 "data/maps/AngelRoom/scripts.pory"
	setobjectxy LOCALID_ANGELROOM_ANGEL, 7, 5
# 119 "data/maps/AngelRoom/scripts.pory"
	setobjectxyperm LOCALID_ANGELROOM_ANGEL, 7, 5
# 120 "data/maps/AngelRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_ANGELROOM_ANGEL, MOVEMENT_TYPE_FACE_LEFT
	goto AngelRoom_EventScript_Angel_16


AngelRoom_EventScript_AngelBattle::
# 134 "data/maps/AngelRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AngelRoom_EventScript_AngelBattle_2
# 137 "data/maps/AngelRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_ANGEL
# 138 "data/maps/AngelRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 139 "data/maps/AngelRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AngelRoom_EventScript_AngelBattle_5
# 142 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_ALTERNATIVE, AngelRoom_Text_AngelDefeated
AngelRoom_EventScript_AngelBattle_1:
# 145 "data/maps/AngelRoom/scripts.pory"
	special HealPlayerParty
	return

AngelRoom_EventScript_AngelBattle_2:
# 135 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_MAIN, AngelRoom_Text_AngelDefeated
	goto AngelRoom_EventScript_AngelBattle_1

AngelRoom_EventScript_AngelBattle_5:
# 140 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_MAIN, AngelRoom_Text_AngelDefeated
	goto AngelRoom_EventScript_AngelBattle_1


AngelRoom_EventScript_TurnOffScreen::
# 154 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_angel_SCREEN_OFF_TOP_LEFT, TRUE
# 155 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 156 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 157 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 158 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 159 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 160 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 161 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 1, METATILE_room_angel_SCREEN_OFF_TOP_CENTER, TRUE
# 162 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 1, METATILE_room_angel_SCREEN_OFF_TOP_RIGHT, TRUE
# 163 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_LEFT, TRUE
# 164 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 165 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 166 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 167 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 168 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 169 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 170 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_CENTER, TRUE
# 171 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_angel_SCREEN_OFF_MIDDLE_RIGHT, TRUE
# 172 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_LEFT, TRUE
# 173 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 174 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 175 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 176 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 177 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 178 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 179 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_CENTER, TRUE
# 180 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 3, METATILE_room_angel_SCREEN_OFF_BOTTOM_RIGHT, TRUE
# 181 "data/maps/AngelRoom/scripts.pory"
	special DrawWholeMapView
	return


AngelRoom_EventScript_CloseScreen::
# 186 "data/maps/AngelRoom/scripts.pory"
	playse SE_WARP_OUT
# 187 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_angel_SCREEN_CLOSING_1_LEFT, TRUE
# 188 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 189 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 190 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 191 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 192 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 193 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 194 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_angel_SCREEN_CLOSING_1_CENTER, TRUE
# 195 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_angel_SCREEN_CLOSING_1_RIGHT, TRUE
# 196 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 197 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 198 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 199 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 200 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 201 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 202 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 203 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 204 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 205 "data/maps/AngelRoom/scripts.pory"
	special DrawWholeMapView
# 206 "data/maps/AngelRoom/scripts.pory"
	delay 5
# 207 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_angel_SCREEN_CLOSING_2_LEFT, TRUE
# 208 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_angel_SCREEN_CLOSING_2_CENTER, TRUE
# 209 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_angel_SCREEN_CLOSING_2_CENTER, TRUE
# 210 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_angel_SCREEN_CLOSING_2_DOOR_1, TRUE
# 211 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 2, METATILE_room_angel_SCREEN_CLOSING_2_DOOR_2, TRUE
# 212 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 2, METATILE_room_angel_SCREEN_CLOSING_2_DOOR_3, TRUE
# 213 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 2, METATILE_room_angel_SCREEN_CLOSING_2_CENTER, TRUE
# 214 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_angel_SCREEN_CLOSING_2_CENTER, TRUE
# 215 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_angel_SCREEN_CLOSING_2_RIGHT, TRUE
# 216 "data/maps/AngelRoom/scripts.pory"
	special DrawWholeMapView
# 217 "data/maps/AngelRoom/scripts.pory"
	delay 5
# 218 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_angel_SCREEN_CLOSING_3_LEFT, TRUE
# 219 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_angel_SCREEN_CLOSING_3_CENTER, TRUE
# 220 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_angel_SCREEN_CLOSING_3_CENTER, TRUE
# 221 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_angel_SCREEN_CLOSING_3_DOOR_1, TRUE
# 222 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 1, METATILE_room_angel_SCREEN_CLOSING_3_DOOR_2, TRUE
# 223 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 1, METATILE_room_angel_SCREEN_CLOSING_3_DOOR_3, TRUE
# 224 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 1, METATILE_room_angel_SCREEN_CLOSING_3_CENTER, TRUE
# 225 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 1, METATILE_room_angel_SCREEN_CLOSING_3_CENTER, TRUE
# 226 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 1, METATILE_room_angel_SCREEN_CLOSING_3_RIGHT, TRUE
# 228 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_angel_WALL, TRUE
# 229 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_angel_WALL, TRUE
# 230 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_angel_WALL, TRUE
# 231 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_angel_DOOR_LEFT, TRUE
# 232 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 2, METATILE_room_angel_DOOR_CENTER, TRUE
# 233 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 2, METATILE_room_angel_DOOR_RIGHT, TRUE
# 234 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 2, METATILE_room_angel_WALL, TRUE
# 235 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_angel_WALL, TRUE
# 236 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_angel_WALL, TRUE
# 237 "data/maps/AngelRoom/scripts.pory"
	special DrawWholeMapView
# 238 "data/maps/AngelRoom/scripts.pory"
	delay 5
# 239 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_angel_SCREEN_CLOSED_LEFT, TRUE
# 240 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 241 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 242 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_angel_SCREEN_CLOSED_DOOR_LEFT, TRUE
# 243 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 1, METATILE_room_angel_SCREEN_CLOSED_DOOR_CENTER, TRUE
# 244 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 1, METATILE_room_angel_SCREEN_CLOSED_DOOR_RIGHT, TRUE
# 245 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 246 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 247 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 1, METATILE_room_angel_SCREEN_CLOSED_RIGHT, TRUE
# 248 "data/maps/AngelRoom/scripts.pory"
	special DrawWholeMapView
	return


AngelRoom_EventScript_SetScreenAsClosed::
# 252 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 253 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 254 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 255 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 256 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 257 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 258 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 259 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 260 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 3, METATILE_room_angel_SCREEN_FLOOR, FALSE
# 261 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_angel_WALL, TRUE
# 262 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_angel_WALL, TRUE
# 263 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_angel_WALL, TRUE
# 264 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_angel_DOOR_LEFT, TRUE
# 265 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 2, METATILE_room_angel_DOOR_CENTER, TRUE
# 266 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 2, METATILE_room_angel_DOOR_RIGHT, TRUE
# 267 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 2, METATILE_room_angel_WALL, TRUE
# 268 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_angel_WALL, TRUE
# 269 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_angel_WALL, TRUE
# 270 "data/maps/AngelRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_angel_SCREEN_CLOSED_LEFT, TRUE
# 271 "data/maps/AngelRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 272 "data/maps/AngelRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 273 "data/maps/AngelRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_angel_SCREEN_CLOSED_DOOR_LEFT, TRUE
# 274 "data/maps/AngelRoom/scripts.pory"
	setmetatile 6, 1, METATILE_room_angel_SCREEN_CLOSED_DOOR_CENTER, TRUE
# 275 "data/maps/AngelRoom/scripts.pory"
	setmetatile 7, 1, METATILE_room_angel_SCREEN_CLOSED_DOOR_RIGHT, TRUE
# 276 "data/maps/AngelRoom/scripts.pory"
	setmetatile 8, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 277 "data/maps/AngelRoom/scripts.pory"
	setmetatile 9, 1, METATILE_room_angel_SCREEN_CLOSED_CENTER, TRUE
# 278 "data/maps/AngelRoom/scripts.pory"
	setmetatile 10, 1, METATILE_room_angel_SCREEN_CLOSED_RIGHT, TRUE
# 279 "data/maps/AngelRoom/scripts.pory"
	special DrawWholeMapView
	return


# 36 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_0:
# 36 "data/maps/AngelRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 39 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_1:
# 40 "data/maps/AngelRoom/scripts.pory"
	lock_facing_direction
# 41 "data/maps/AngelRoom/scripts.pory"
	jump_in_place_down
# 42 "data/maps/AngelRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 72 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_2:
# 72 "data/maps/AngelRoom/scripts.pory"
	jump_2_down
# 72 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 72 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 75 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_3:
# 75 "data/maps/AngelRoom/scripts.pory"
	jump_2_up
# 75 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 75 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 78 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_4:
# 78 "data/maps/AngelRoom/scripts.pory"
	jump_2_right
# 78 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 78 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 81 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_5:
# 81 "data/maps/AngelRoom/scripts.pory"
	jump_2_left
# 81 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 81 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_6:
# 87 "data/maps/AngelRoom/scripts.pory"
	emote_versus
	step_end

# 116 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_7:
# 117 "data/maps/AngelRoom/scripts.pory"
	lock_facing_direction
# 117 "data/maps/AngelRoom/scripts.pory"
	walk_right
# 117 "data/maps/AngelRoom/scripts.pory"
	unlock_facing_direction
# 117 "data/maps/AngelRoom/scripts.pory"
	face_left
	step_end

# 122 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_8:
# 123 "data/maps/AngelRoom/scripts.pory"
	face_right
# 123 "data/maps/AngelRoom/scripts.pory"
	lock_facing_direction
# 123 "data/maps/AngelRoom/scripts.pory"
	walk_left
# 123 "data/maps/AngelRoom/scripts.pory"
	unlock_facing_direction
# 123 "data/maps/AngelRoom/scripts.pory"
	face_right
	step_end

AngelRoom_EventScript_Angel_Text_0:
# 27 "data/maps/AngelRoom/scripts.pory"
	.string "¡Me alegro de verte de nuevo! Espero\n"
	.string "que sigas siendo tan fuerte como la\l"
	.string "última vez.$"

AngelRoom_EventScript_Angel_Text_1:
# 32 "data/maps/AngelRoom/scripts.pory"
	.string "¡Mola muchísimo tener un cine propio\n"
	.string "dentro de mi sala!\p"
	.string "Aquí las obras maestras se disfrutan\n"
	.string "de verdad.$"

AngelRoom_EventScript_Angel_Text_2:
# 44 "data/maps/AngelRoom/scripts.pory"
	.string "¡Cuánto tiempo!$"

AngelRoom_EventScript_Angel_Text_3:
# 47 "data/maps/AngelRoom/scripts.pory"
	.string "Ha pasado mucho desde la última vez,\n"
	.string "¿verdad?\p"
	.string "Espero que este reencuentro… ¡SEA\n"
	.string "MEMORABLE!$"

AngelRoom_EventScript_Angel_Text_4:
# 68 "data/maps/AngelRoom/scripts.pory"
	.string "Veamos tu potencial.$"

AngelRoom_EventScript_Angel_Text_5:
# 85 "data/maps/AngelRoom/scripts.pory"
	.string "¡Ven! ¡Atácame con todo lo que tengas!$"

AngelRoom_EventScript_Angel_Text_6:
# 92 "data/maps/AngelRoom/scripts.pory"
	.string "¡Increíble! ¡El poder de la nueva\n"
	.string "generación es asombroso!$"

AngelRoom_EventScript_Angel_Text_7:
# 95 "data/maps/AngelRoom/scripts.pory"
	.string "No esperaba perder y aún así, no me\n"
	.string "dejaste opciones.\p"
	.string "Sin duda, la función ha terminado.$"

AngelRoom_EventScript_Angel_Text_8:
# 98 "data/maps/AngelRoom/scripts.pory"
	.string "Te abriré la puerta para que puedas\n"
	.string "continuar con tu viaje.$"

AngelRoom_EventScript_Angel_Text_9:
# 110 "data/maps/AngelRoom/scripts.pory"
	.string "Dejo en tus manos el legado de toda mi\n"
	.string "generación. ¡Espero de verdad que\l"
	.string "volvamos a encontrarnos algún día y\l"
	.string "poder volver a pelear juntos!$"

AngelRoom_Text_AngelDefeated::
# 149 "data/maps/AngelRoom/scripts.pory"
	.string "¿Así que este es el poder de la nueva\n"
	.string "generación?$"
