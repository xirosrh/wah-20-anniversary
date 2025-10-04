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
	setflag FLAG_JACKROOM_HIDE_POKEBALL1
# 10 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL2
# 11 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL3
# 12 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL4
# 13 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_SPOINK_LEFT
# 14 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_SPOINK_RIGHT
# 15 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_ELECTRODE
	end


JackJohnsonRoom_OnFrame::
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
	clearflag FLAG_JACKROOM_HIDE_POKEBALL3
# 110 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_POKEBALL4
# 111 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_BALL3
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_BALL4
# 113 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_BALL3, MAP_JACK_JOHNSON_ROOM
# 114 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_BALL4, MAP_JACK_JOHNSON_ROOM
# 115 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_BALL3, Common_Movement_WalkDiagSouthEast
# 116 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_BALL4, Common_Movement_WalkDiagSouthEast
# 117 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 119 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 120 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_BALL3
# 121 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_BALL4
# 122 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_SPOINK_LEFT
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_SPOINK_RIGHT
# 124 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_LEFT
# 125 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_RIGHT
# 126 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 127 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_LEFT, JackJohnsonRoom_Movement_SpoinkHighJump
# 128 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_RIGHT, JackJohnsonRoom_Movement_SpoinkHighJump
# 129 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 131 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 132 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_ELECTRODE
# 133 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_ELECTRODE
# 134 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 135 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_ORB
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	special DoOrbEffect
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 139 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 140 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8006, 8
# 141 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 142 "data/maps/JackJohnsonRoom/scripts.pory"
	special ShakeCamera
# 143 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 147 "data/maps/JackJohnsonRoom/scripts.pory"
	special FadeOutOrbEffect
# 148 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 149 "data/maps/JackJohnsonRoom/scripts.pory"
	special RemoveCameraObject
# 150 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_JACK_JOHNSON_ROOM_STATE, 1
# 151 "data/maps/JackJohnsonRoom/scripts.pory"
	release
	end


# 155 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SpoinkHighJump:
# 156 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
# 157 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_up
# 158 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_down
# 159 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
	step_end

# 162 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc1:
# 163 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 163 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 163 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 164 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 165 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 165 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 165 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 166 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 166 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 167 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 167 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 167 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 168 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 171 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc3:
# 172 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 173 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 174 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 175 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 175 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 175 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 175 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 176 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 176 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 176 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 177 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_left
# 178 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 178 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 179 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 180 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 180 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 181 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 184 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc4:
# 185 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 186 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 188 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 189 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 190 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 190 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 190 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 191 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 191 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 192 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 193 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 194 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 194 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 195 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 196 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 197 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 200 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc2:
# 201 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 201 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 202 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 204 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 204 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 205 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 206 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 206 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 207 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 208 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_3_left
# 209 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 210 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 211 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 212 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_up
# 213 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 217 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc1And3:
# 218 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right
# 219 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 220 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 221 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 222 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 223 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
	step_end

# 226 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc2And4:
# 227 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 228 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 229 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 230 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 231 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 232 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 235 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SecondCombinationNpcs:
# 236 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 236 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 237 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 237 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 240 "data/maps/JackJohnsonRoom/scripts.pory"
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
