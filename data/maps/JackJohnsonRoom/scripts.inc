JackJohnsonRoom_MapScripts::
# 5 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JackJohnsonRoom_OnTransition
# 2 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script_2 VAR_JACK_JOHNSON_ROOM_STATE, 0, JackJohnsonRoom_OnFrame
	.2byte 0


JackJohnsonRoom_OnTransition::
# 9 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_NPC1_BALL
# 10 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_NPC3_BALL
# 11 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_NPC4_BALL
# 12 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_SPOINK_LEFT
# 13 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_SPOINK_RIGHT
# 14 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_ELECTRODE
	end


JackJohnsonRoom_OnFrame::
# 19 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 20 "data/maps/JackJohnsonRoom/scripts.pory"
	special SpawnCameraObject
# 21 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 22 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 23 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 24 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkInPlaceUp
# 25 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 26 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkInPlaceDown
# 27 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkInPlaceDown
# 28 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkInPlaceDown
# 29 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkInPlaceDown
# 30 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 32 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 33 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 34 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 35 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkLeftLockFacingDirection
# 36 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkRightLockFacingDirection
# 37 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkLeftLockFacingDirection
# 38 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkRightLockFacingDirection
# 39 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 10
# 41 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkDownLockFacingDirection
# 42 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkDownLockFacingDirection
# 43 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkUpLockFacingDirection
# 44 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkUpLockFacingDirection
# 45 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 47 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 48 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 49 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 50 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 51 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_JumpDownLockFacingDirection
# 53 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpUpLockFacingDirection
# 54 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpInPlaceLeft
# 55 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_JumpInPlaceRight
# 56 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC3
# 57 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpDownFaceLeft
# 58 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpDownFaceRight
# 59 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 60 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 61 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 62 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 63 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 64 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 66 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 67 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 68 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 69 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 70 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 71 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 72 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 73 "data/maps/JackJohnsonRoom/scripts.pory"
	release
# 74 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_0
# 80 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 81 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 83 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	lock
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_FaceLeft
# 86 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkDown
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_1
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_2
# 89 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 90 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE
# 91 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_JumpRoundNpc1
# 92 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_JumpRoundNpc3
# 93 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_JumpRoundNpc4
# 94 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_JumpRoundNpc2
# 95 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_3
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_4
# 98 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_5
# 99 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_6
# 100 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC1
# 101 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_FACE_DOWN
# 102 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_FACE_DOWN
# 103 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_FACE_DOWN
# 104 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_FACE_DOWN
# 105 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 106 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 107 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 108 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 109 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_NPC3_BALL
# 110 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_NPC4_BALL
# 111 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC3_BALL
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC4_BALL
# 113 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC3_BALL, MAP_JACK_JOHNSON_ROOM
# 114 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC4_BALL, MAP_JACK_JOHNSON_ROOM
# 115 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3_BALL, Common_Movement_WalkDiagSouthEast
# 116 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4_BALL, Common_Movement_WalkDiagSouthEast
# 117 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 119 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 120 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC3_BALL
# 121 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC4_BALL
# 122 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_SPOINK_LEFT
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_SPOINK_RIGHT
# 124 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_LEFT
# 125 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_RIGHT
# 126 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 127 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_LEFT, JackJohnsonRoom_Movement_SpoinkHighJump
# 128 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_RIGHT, JackJohnsonRoom_Movement_SpoinkHighJump
# 129 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 130 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 131 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_SPOINK_LEFT
# 132 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_SPOINK_RIGHT
# 133 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 134 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_7
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_8
# 144 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_9
# 150 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_10
# 156 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC4
# 157 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_NPC1_BALL
# 158 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC1_BALL
# 159 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC1_BALL, MAP_JACK_JOHNSON_ROOM
# 160 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1_BALL, Common_Movement_WalkDiagSouthEast
# 161 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 162 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 163 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 164 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC1_BALL
# 165 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_ELECTRODE
# 166 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_ELECTRODE
# 167 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 168 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 169 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_11
# 174 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_12
# 179 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_13
# 184 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_14
# 189 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 191 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 192 "data/maps/JackJohnsonRoom/scripts.pory"
	setweather WEATHER_NONE
# 193 "data/maps/JackJohnsonRoom/scripts.pory"
	doweather
# 194 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_RESULT, 2
# 195 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_ORB
# 196 "data/maps/JackJohnsonRoom/scripts.pory"
	special DoOrbEffect
# 197 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 198 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 199 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8006, 8
# 200 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 201 "data/maps/JackJohnsonRoom/scripts.pory"
	special ShakeCamera
# 202 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_15
# 209 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 210 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 211 "data/maps/JackJohnsonRoom/scripts.pory"
	special FadeOutOrbEffect
# 212 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 213 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_ELECTRODE
# 214 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 215 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 216 "data/maps/JackJohnsonRoom/scripts.pory"
	getobjectxy LOCALID_JACKROOM_JACK, CURRENT_POSITION, VAR_TEMP_C, VAR_TEMP_D
# 217 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_C, VAR_TEMP_D
# 218 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 219 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 220 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_DoubleExclamationMarkWithDelay48
# 221 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 222 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 223 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_WalkUp5
# 224 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp5
# 225 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 226 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_WEST
# 227 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_9
# 228 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_16
# 233 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_10
# 234 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_SOUTH
# 235 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 236 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_ExclamationMarkWithDelay48
# 237 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_CAMERA, JackJohnsonRoom_OnFrame_Movement_17
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_18
# 240 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 241 "data/maps/JackJohnsonRoom/scripts.pory"
	special RemoveCameraObject
# 242 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_12
# 243 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_JACK_JOHNSON_ROOM_STATE, 1
# 244 "data/maps/JackJohnsonRoom/scripts.pory"
	release
	end


# 248 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SpoinkHighJump:
# 249 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
# 250 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_up
# 251 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_down
# 252 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
	step_end

# 255 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc1:
# 256 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 256 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 256 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 257 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 258 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 258 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 258 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 259 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 259 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 260 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 260 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 260 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 261 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 264 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc3:
# 265 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 266 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 267 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 268 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 268 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 268 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 268 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 269 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 269 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 269 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 270 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_left
# 271 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 271 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 272 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 273 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 273 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 274 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 277 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc4:
# 278 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 279 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 281 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 282 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 283 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 283 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 283 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 284 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 284 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 285 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 286 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 287 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 287 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 288 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 289 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 290 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 293 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc2:
# 294 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 294 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 295 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 297 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 297 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 298 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 299 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 299 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 300 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 301 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_3_left
# 302 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 303 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 304 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 305 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_up
# 306 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 310 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc1And3:
# 311 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right
# 312 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 313 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 314 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 315 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 316 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
	step_end

# 319 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc2And4:
# 320 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 321 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 322 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 323 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 324 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 325 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 328 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SecondCombinationNpcs:
# 329 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 329 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 330 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 330 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 331 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 331 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 332 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 332 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 333 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down
	step_end

# 75 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_0:
# 76 "data/maps/JackJohnsonRoom/scripts.pory"
	emote_happy
# 77 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up
# 78 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 78 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_1:
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 88 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_2:
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 96 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_3:
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
	step_end

# 97 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_4:
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 98 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_5:
# 98 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 98 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 98 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 98 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 99 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_6:
# 99 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 99 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 99 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 134 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_7:
# 135 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 137 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 138 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_8:
# 139 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 140 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
# 141 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 142 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 143 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 144 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_9:
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 146 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
# 147 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 148 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 148 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 149 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 150 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_10:
# 151 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 151 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 152 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
# 153 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 154 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 154 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 155 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 169 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_11:
# 170 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 171 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 171 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 172 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 174 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_12:
# 175 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 176 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_left
# 176 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_left
# 177 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 179 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_13:
# 180 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 181 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_right
# 181 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_right
# 182 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 184 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_14:
# 185 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 186 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 186 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 203 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_15:
# 204 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
# 205 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 206 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_3_left
# 207 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 228 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_16:
# 229 "data/maps/JackJohnsonRoom/scripts.pory"
	face_up
# 230 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 231 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 238 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_17:
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
	step_end

# 239 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_18:
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

JackJohnsonRoom_OnFrame_Text_0:
# 23 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Desde el principio! ¡Quiero que cada\n"
	.string "movimiento sea perfecto!$"

JackJohnsonRoom_OnFrame_Text_1:
# 32 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Empecemos!$"

JackJohnsonRoom_OnFrame_Text_2:
# 46 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Uno, dos… salto ya!$"

JackJohnsonRoom_OnFrame_Text_3:
# 59 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Giro! ¡Más energía, que parezca un\n"
	.string "huracán!$"

JackJohnsonRoom_OnFrame_Text_4:
# 80 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Perfecto! ¡Lo hemos clavado!$"

JackJohnsonRoom_OnFrame_Text_5:
# 83 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Formación!$"

JackJohnsonRoom_OnFrame_Text_6:
# 90 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Ahora!$"

JackJohnsonRoom_OnFrame_Text_7:
# 168 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Preparados para la detonación\n"
	.string "elegante!$"

JackJohnsonRoom_OnFrame_Text_8:
# 221 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Alto!$"

JackJohnsonRoom_OnFrame_Text_9:
# 227 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Qué estabas haciendo? Ya viste como\n"
	.string "es esto: una distracción y a volar.$"

JackJohnsonRoom_OnFrame_Text_10:
# 233 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Estuvo cerca… muy cerca, pero hasta\n"
	.string "que salga impecable, no descansaremos.$"

JackJohnsonRoom_OnFrame_Text_11:
# 237 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Y tú? ¿Qué haces ahí parado?$"

JackJohnsonRoom_OnFrame_Text_12:
# 242 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Si no vas a unirte al ensayo… voy a\n"
	.string "tener que retarte a un combate.$"
