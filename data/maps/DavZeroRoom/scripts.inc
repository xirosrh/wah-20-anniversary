DavZeroRoom_MapScripts::
# 9 "data/maps/DavZeroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DavZeroRoom_OnTransition
# 10 "data/maps/DavZeroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DavZeroRoom_OnLoad
# 6 "data/maps/DavZeroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DavZeroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 11 "data/maps/DavZeroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DavZeroRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

DavZeroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/DavZeroRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, DavZeroRoom_OnFrame
	.2byte 0

DavZeroRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 12 "data/maps/DavZeroRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, DavZeroRoom_OnWarp_PlayerTurnNorth
	.2byte 0


DavZeroRoom_OnLoad::
# 17 "data/maps/DavZeroRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_DAVZERO, DavZeroRoom_OnLoad_2
DavZeroRoom_OnLoad_1:
	end

DavZeroRoom_OnLoad_2:
# 18 "data/maps/DavZeroRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto DavZeroRoom_OnLoad_1


DavZeroRoom_OnWarp_PlayerTurnNorth::
# 24 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


DavZeroRoom_OnTransition::
# 29 "data/maps/DavZeroRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_DavZero
# 30 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq DavZeroRoom_OnTransition_2
DavZeroRoom_OnTransition_1:
	end

DavZeroRoom_OnTransition_2:
# 31 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 32 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_TEMP_2
	goto DavZeroRoom_OnTransition_1


DavZeroRoom_OnFrame::
# 38 "data/maps/DavZeroRoom/scripts.pory"
	special ShowMapNamePopup
# 39 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_0
# 40 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 41 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 10, 5
# 42 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 44 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_SCHOOLGIRL, DavZeroRoom_Movement_GirlAndBoyLearning
# 46 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_SCHOOLBOY, DavZeroRoom_Movement_GirlAndBoyLearning
# 47 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 48 "data/maps/DavZeroRoom/scripts.pory"
	waitse
# 49 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 50 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_DAVZERO, DIR_WEST
# 51 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_DoubleExclamationMarkWithDelay48
# 53 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 54 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 55 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 56 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_1
# 57 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft4
# 58 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement LOCALID_ZEROROOM_DAVZERO
# 59 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 60 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 61 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 62 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_3, DavZeroRoom_OnFrame_Text_4, DavZeroRoom_OnFrame_Text_5
# 63 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DavZeroRoom_OnFrame_2
DavZeroRoom_OnFrame_1:
# 68 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 70 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 71 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_2
# 72 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 74 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_3
# 75 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_DAVZERO, DIR_EAST
# 76 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 77 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SweatDropWithDelay48
# 79 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 80 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 81 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_4
# 82 "data/maps/DavZeroRoom/scripts.pory"
	waitse
# 83 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_LEDGE
# 84 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_5
# 85 "data/maps/DavZeroRoom/scripts.pory"
	waitse
# 86 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_6
# 88 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 89 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight
# 90 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 91 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkLeft2
# 92 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 93 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_LEDGE
# 94 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_JumpInPlaceLeftRight
# 95 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 96 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight2
# 97 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 98 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 99 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SmileWithDelay48
# 100 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 101 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 102 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_7
# 103 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 104 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
# 105 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement LOCALID_ZEROROOM_DAVZERO
# 106 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 107 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 108 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 109 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 110 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 111 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 112 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 113 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 114 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_CryWithDelay48
# 115 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 116 "data/maps/DavZeroRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 117 "data/maps/DavZeroRoom/scripts.pory"
	addobject LOCALID_ZEROROOM_POKEBALL
# 118 "data/maps/DavZeroRoom/scripts.pory"
	showobjectat LOCALID_ZEROROOM_POKEBALL, MAP_DAV_ZERO_ROOM
# 119 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 120 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 121 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_BALL_OPEN
# 122 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 123 "data/maps/DavZeroRoom/scripts.pory"
	removeobject LOCALID_ZEROROOM_POKEBALL
# 124 "data/maps/DavZeroRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 125 "data/maps/DavZeroRoom/scripts.pory"
	addobject LOCALID_ZEROROOM_MILOTIC
# 126 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 127 "data/maps/DavZeroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_ZEROROOM_DAVZERO, MOVEMENT_TYPE_FACE_DOWN
# 128 "data/maps/DavZeroRoom/scripts.pory"
	release
# 129 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_18, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 130 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 131 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_8
# 132 "data/maps/DavZeroRoom/scripts.pory"
	waitse
# 133 "data/maps/DavZeroRoom/scripts.pory"
	call DavZeroRoom_EventScript_DavZeroBattle
# 134 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_BALL_OPEN
# 135 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 136 "data/maps/DavZeroRoom/scripts.pory"
	removeobject LOCALID_ZEROROOM_MILOTIC
# 137 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 138 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkDown2
# 139 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_19, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 140 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 141 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_ThinkingWithDelay48
# 142 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_20, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 143 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 144 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_21, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 145 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 146 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_22, MSGBOX_AUTOCLOSE, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 147 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 148 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 149 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 150 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 151 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_9
# 152 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 153 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_10
# 154 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_23, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 155 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 156 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_24, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 157 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 158 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 159 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_25, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 160 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 161 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HeartWithDelay48
# 162 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_26, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 163 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 164 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_27, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 165 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 166 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 167 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 168 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkUp2
# 169 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_28, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 170 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 171 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_FaceDown
# 172 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_29, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 173 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 174 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkDown2
# 175 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_30, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 176 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 177 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_31, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 178 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 179 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_ThinkingWithDelay48
# 180 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_32, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 181 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 182 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_33, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 183 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_34, DavZeroRoom_OnFrame_Text_35, DavZeroRoom_OnFrame_Text_36, DavZeroRoom_OnFrame_Text_37
# 184 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_38, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 185 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 186 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SmileWithDelay48
# 187 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 188 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 189 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 190 "data/maps/DavZeroRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 191 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 192 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 193 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 194 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_11
# 195 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 196 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_DAVZERO
# 197 "data/maps/DavZeroRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 198 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_OnFrame_2:
# 65 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 66 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
	goto DavZeroRoom_OnFrame_1


DavZeroRoom_EventScript_DavZeroBattle::
# 203 "data/maps/DavZeroRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DavZeroRoom_EventScript_DavZeroBattle_2
# 206 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_DAVZERO
# 207 "data/maps/DavZeroRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 208 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DavZeroRoom_EventScript_DavZeroBattle_5
# 211 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE, DavZeroRoom_Text_DavZeroDefeated
DavZeroRoom_EventScript_DavZeroBattle_1:
	return

DavZeroRoom_EventScript_DavZeroBattle_2:
# 204 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_MAIN, DavZeroRoom_Text_DavZeroDefeated
	goto DavZeroRoom_EventScript_DavZeroBattle_1

DavZeroRoom_EventScript_DavZeroBattle_5:
# 209 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_MAIN, DavZeroRoom_Text_DavZeroDefeated
	goto DavZeroRoom_EventScript_DavZeroBattle_1


# 220 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_Movement_GirlAndBoyLearning:
# 221 "data/maps/DavZeroRoom/scripts.pory"
	emote_idea
# 222 "data/maps/DavZeroRoom/scripts.pory"
	walk_in_place_up
# 223 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
# 223 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

DavZeroRoom_EventScript_SchoolGirl::
# 227 "data/maps/DavZeroRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 228 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq DavZeroRoom_EventScript_SchoolGirl_2
# 231 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 232 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 233 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolGirl_Text_0, MSGBOX_AUTOCLOSE
# 234 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLGIRL, DIR_NORTH
# 235 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_EventScript_SchoolGirl_2:
	end


DavZeroRoom_EventScript_SchoolBoy::
# 240 "data/maps/DavZeroRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 241 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq DavZeroRoom_EventScript_SchoolBoy_2
# 244 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 245 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 246 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolBoy_Text_0
# 247 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 248 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_SCHOOLBOY, Common_Movement_SmileWithDelay48
# 249 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolBoy_Text_1, MSGBOX_AUTOCLOSE
# 250 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 251 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 252 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 253 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLBOY, DIR_NORTH
# 254 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_EventScript_SchoolBoy_2:
	end


DavZeroRoom_EventScript_Zero::
# 259 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 260 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 261 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Zero_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 262 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 263 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_XDWithDelay48
# 264 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_DAVZERO, DIR_SOUTH
# 265 "data/maps/DavZeroRoom/scripts.pory"
	release
	end


DavZeroRoom_EventScript_Dumbbells::
# 270 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Dumbbells_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_PC::
# 275 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_PC_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Notes::
# 280 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Notes_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Library1::
# 285 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Library1_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Library2::
# 290 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Library2_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Library3::
# 295 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Library3_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Tredmill::
# 300 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Tredmill_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_TrashCan::
# 305 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_TrashCan_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Box1::
# 310 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Box1_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_Box2::
# 315 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Box2_Text_0, MSGBOX_SIGN
	end


DavZeroRoom_EventScript_StackedPlates::
# 320 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_StackedPlates_Text_0, MSGBOX_SIGN
	end


# 39 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_0:
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 39 "data/maps/DavZeroRoom/scripts.pory"
	face_right
	step_end

# 56 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_1:
# 56 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 56 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 56 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 56 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 56 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 56 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 71 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_2:
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 71 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 71 "data/maps/DavZeroRoom/scripts.pory"
	face_left
	step_end

# 74 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_3:
# 74 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 74 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 74 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 74 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 74 "data/maps/DavZeroRoom/scripts.pory"
	face_left
	step_end

# 81 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_4:
# 81 "data/maps/DavZeroRoom/scripts.pory"
	emote_happy
	step_end

# 84 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_5:
# 84 "data/maps/DavZeroRoom/scripts.pory"
	jump_in_place_right
	step_end

# 87 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_6:
# 87 "data/maps/DavZeroRoom/scripts.pory"
	jump_in_place_right
# 87 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

# 102 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_7:
# 102 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 102 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 102 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 102 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 102 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 131 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_8:
# 131 "data/maps/DavZeroRoom/scripts.pory"
	emote_versus
	step_end

# 151 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_9:
# 151 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
	step_end

# 153 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_10:
# 153 "data/maps/DavZeroRoom/scripts.pory"
	emote_thinking
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 153 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 153 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 194 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_11:
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 194 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 194 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

DavZeroRoom_OnFrame_Text_0:
# 43 "data/maps/DavZeroRoom/scripts.pory"
	.string "All right, class, remember: it's 'i' before\n"
	.string "{COLOR RED}e{COLOR DARK_GRAY}, except after {COLOR BLUE}c{COLOR DARK_GRAY}.$"

DavZeroRoom_OnFrame_Text_1:
# 55 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hold on a second… I think today we have\n"
	.string "company!$"

DavZeroRoom_OnFrame_Text_2:
# 61 "data/maps/DavZeroRoom/scripts.pory"
	.string "Aha, so you've finally made it here.\p"
	.string "It's a pleasure to see you. Do you\n"
	.string "recognize me?$"

DavZeroRoom_OnFrame_Text_3:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "Yes, you're unmistakable!$"

DavZeroRoom_OnFrame_Text_4:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "You look familiar - like a Machoke!$"

DavZeroRoom_OnFrame_Text_5:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "Should I know you?$"

DavZeroRoom_OnFrame_Text_6:
# 66 "data/maps/DavZeroRoom/scripts.pory"
	.string "You'll soon find out who I am.$"

DavZeroRoom_OnFrame_Text_7:
# 76 "data/maps/DavZeroRoom/scripts.pory"
	.string "I had to cut short my fourth set at 110\n"
	.string "kg on the bench press.\p"
	.string "All because I heard a contender was\n"
	.string "reaching this level.\p"
	.string "And you caught me right as I was\n"
	.string "teaching the spelling rules to my\l"
	.string "students…$"

DavZeroRoom_OnFrame_Text_8:
# 79 "data/maps/DavZeroRoom/scripts.pory"
	.string "Well, at least they can practice a while\n"
	.string "as we battle.\p"
	.string "Though I think they'll be quite eager to\n"
	.string "watch, because I sense this'll be a\l"
	.string "battle without equal.$"

DavZeroRoom_OnFrame_Text_9:
# 90 "data/maps/DavZeroRoom/scripts.pory"
	.string "Tell me… what's your goal? Do you want\n"
	.string "to challenge the flamethrower-wielding\l"
	.string "madman waiting at the end?$"

DavZeroRoom_OnFrame_Text_10:
# 92 "data/maps/DavZeroRoom/scripts.pory"
	.string "By now you must know, since to get here\n"
	.string "you've had to face several colleagues\l"
	.string "of mine.$"

DavZeroRoom_OnFrame_Text_11:
# 95 "data/maps/DavZeroRoom/scripts.pory"
	.string "But I won't make it easy for you in this\n"
	.string "battle!\p"
	.string "I've been training body, mind, and\n"
	.string "Pokémon awaiting your arrival.$"

DavZeroRoom_OnFrame_Text_12:
# 97 "data/maps/DavZeroRoom/scripts.pory"
	.string "Few challengers manage to make it this\n"
	.string "far.\p"
	.string "Congratulations.$"

DavZeroRoom_OnFrame_Text_13:
# 100 "data/maps/DavZeroRoom/scripts.pory"
	.string "Come, let's take our places in the\n"
	.string "battle area.$"

DavZeroRoom_OnFrame_Text_14:
# 107 "data/maps/DavZeroRoom/scripts.pory"
	.string "You know? Many think a battle is pure\n"
	.string "strength, but to me it's memory.\p"
	.string "Every attack, every strategy, every\n"
	.string "mistake… is a reminder of who we were\l"
	.string "and what we became.$"

DavZeroRoom_OnFrame_Text_15:
# 109 "data/maps/DavZeroRoom/scripts.pory"
	.string "Let me make this clear: I'm not your\n"
	.string "rival.\p"
	.string "I'm the voice reminding you that every\n"
	.string "step, even within these four walls, can\l"
	.string "shape you more than you think.$"

DavZeroRoom_OnFrame_Text_16:
# 112 "data/maps/DavZeroRoom/scripts.pory"
	.string "Some fight to win, and some fight to\n"
	.string "never make the same mistake again.\p"
	.string "Which of those are you? Let me find out,\n"
	.string "because your gaze makes me curious…\p"
	.string "It reminds me of that crazy time when I\n"
	.string "used to hang around that place that\l"
	.string "was once our home.$"

DavZeroRoom_OnFrame_Text_17:
# 115 "data/maps/DavZeroRoom/scripts.pory"
	.string "Well, that's enough - I'm getting too\n"
	.string "intense and this'll end up sounding like\l"
	.string "a Benedetti poem…\p"
	.string "And this time I didn't bring roses to go\n"
	.string "with it - just Poké Balls.$"

DavZeroRoom_OnFrame_Text_18:
# 129 "data/maps/DavZeroRoom/scripts.pory"
	.string "Don't lose your nerve now!$"

DavZeroRoom_OnFrame_Text_19:
# 139 "data/maps/DavZeroRoom/scripts.pory"
	.string "Today you're the one who came out\n"
	.string "victorious, and I'll admit it plainly.\p"
	.string "But you must understand that you won't\n"
	.string "always come out on top.$"

DavZeroRoom_OnFrame_Text_20:
# 142 "data/maps/DavZeroRoom/scripts.pory"
	.string "But listen: defeat is not the end of\n"
	.string "anything.\p"
	.string "On the contrary, it's a mirror.\p"
	.string "It reflects what we still don't want to\n"
	.string "see in ourselves - the things we avoid\l"
	.string "facing.$"

DavZeroRoom_OnFrame_Text_21:
# 144 "data/maps/DavZeroRoom/scripts.pory"
	.string "I learned it that way too, losing,\n"
	.string "messing up, falling again and again…$"

DavZeroRoom_OnFrame_Text_22:
# 146 "data/maps/DavZeroRoom/scripts.pory"
	.string "Laughing all the while.$"

DavZeroRoom_OnFrame_Text_23:
# 154 "data/maps/DavZeroRoom/scripts.pory"
	.string "You know? Success and victory aren't\n"
	.string "about piling up wins, or crushing rivals,\l"
	.string "or even in beating me right now.\p"
	.string "Success is getting up after you fall, in\n"
	.string "walking on with your scars in plain\l"
	.string "sight, in not giving up even when life or\l"
	.string "a battle has left you shaken.$"

DavZeroRoom_OnFrame_Text_24:
# 156 "data/maps/DavZeroRoom/scripts.pory"
	.string "I want you to understand that.$"

DavZeroRoom_OnFrame_Text_25:
# 159 "data/maps/DavZeroRoom/scripts.pory"
	.string "Today you beat me, and I'm glad you did.\p"
	.string "Because it means you're also learning\n"
	.string "what really matters…\p"
	.string "And that I still have things to learn\n"
	.string "too.$"

DavZeroRoom_OnFrame_Text_26:
# 162 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hold on to that, because it's knowledge\n"
	.string "no Pokémon, no rival, and no badge can\l"
	.string "ever take from you.$"

DavZeroRoom_OnFrame_Text_27:
# 164 "data/maps/DavZeroRoom/scripts.pory"
	.string "I definitely wasn't wrong: you've got a\n"
	.string "different look in your eye.\p"
	.string "I'm proud that you won, because every\n"
	.string "victory like yours keeps the flame of\l"
	.string "this place alive.$"

DavZeroRoom_OnFrame_Text_28:
# 169 "data/maps/DavZeroRoom/scripts.pory"
	.string "Our encounter ends here, but not your\n"
	.string "journey.\p"
	.string "I was just an obstacle, like those\n"
	.string "dumbbells that seem impossible until\l"
	.string "one day you realize you can lift them.$"

DavZeroRoom_OnFrame_Text_29:
# 172 "data/maps/DavZeroRoom/scripts.pory"
	.string "And hey, if we ever cross paths at the\n"
	.string "gym, don't give me a weird look if I ask\l"
	.string "you to spot me on the bar.\p"
	.string "No one is invincible.$"

DavZeroRoom_OnFrame_Text_30:
# 175 "data/maps/DavZeroRoom/scripts.pory"
	.string "Now go, my friend. Follow your path, make\n"
	.string "mistakes, and learn.$"

DavZeroRoom_OnFrame_Text_31:
# 177 "data/maps/DavZeroRoom/scripts.pory"
	.string "Don't be afraid to lose.\p"
	.string "The worst thing you can do is stop\n"
	.string "trying out of fear you won't measure up.\p"
	.string "I know it well… too many times I froze,\n"
	.string "worrying about what others would say\l"
	.string "about me, whether my mistakes defined\l"
	.string "me.$"

DavZeroRoom_OnFrame_Text_32:
# 180 "data/maps/DavZeroRoom/scripts.pory"
	.string "You are not your failures, your falls, or\n"
	.string "what others think of you.\p"
	.string "You are everything you do in spite of\n"
	.string "them.\p"
	.string "If today you were able to beat me here,\n"
	.string "in this place, remember you'll also be\l"
	.string "able to face anything out there.$"

DavZeroRoom_OnFrame_Text_33:
# 182 "data/maps/DavZeroRoom/scripts.pory"
	.string "What is it? Why are you looking at me\n"
	.string "like that?$"

DavZeroRoom_OnFrame_Text_34:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "Great advice, worthy of a sage.$"

DavZeroRoom_OnFrame_Text_35:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "You made me think a little.$"

DavZeroRoom_OnFrame_Text_36:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "Is there much more of this speech?$"

DavZeroRoom_OnFrame_Text_37:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "Was that a lecture?$"

DavZeroRoom_OnFrame_Text_38:
# 184 "data/maps/DavZeroRoom/scripts.pory"
	.string "Didn't expect this?\p"
	.string "What can I say? I'm just Zero.$"

DavZeroRoom_EventScript_SchoolGirl_Text_0:
# 233 "data/maps/DavZeroRoom/scripts.pory"
	.string "Want to hear a secret? I finished\n"
	.string "school years ago.\p"
	.string "I only come here because Zero is so\n"
	.string "interesting!\p"
	.string "I could listen to him talk all day.$"

DavZeroRoom_EventScript_SchoolBoy_Text_0:
# 246 "data/maps/DavZeroRoom/scripts.pory"
	.string "Mr. Zero is super cool!$"

DavZeroRoom_EventScript_SchoolBoy_Text_1:
# 249 "data/maps/DavZeroRoom/scripts.pory"
	.string "When we were six he taught us English,\n"
	.string "and we learned the months of the year\l"
	.string "to the tune of La Macarena.$"

DavZeroRoom_EventScript_Zero_Text_0:
# 261 "data/maps/DavZeroRoom/scripts.pory"
	.string "If you want another deep quote, bring a\n"
	.string "ticket.\p"
	.string "My work here is done.$"

DavZeroRoom_EventScript_Dumbbells_Text_0:
# 270 "data/maps/DavZeroRoom/scripts.pory"
	.string "The dumbbells are heavy enough not to\n"
	.string "be just for show.$"

DavZeroRoom_EventScript_PC_Text_0:
# 275 "data/maps/DavZeroRoom/scripts.pory"
	.string "It's a laptop that's on, with a Valencia\n"
	.string "CF wallpaper.\p"
	.string "There are more tabs open than Team\n"
	.string "NoHack has alt accounts.$"

DavZeroRoom_EventScript_Notes_Text_0:
# 280 "data/maps/DavZeroRoom/scripts.pory"
	.string "There are several sheets lying on the\n"
	.string "floor.\p"
	.string "They look like notes of ideas for a\n"
	.string "poetry book.$"

DavZeroRoom_EventScript_Library1_Text_0:
# 285 "data/maps/DavZeroRoom/scripts.pory"
	.string "It looks like a collection of poetry\n"
	.string "books.\p"
	.string "One stands out from the rest: “A\n"
	.string "Lustrum of Soliloquy.”\p"
	.string "The author is listed as Zero.$"

DavZeroRoom_EventScript_Library2_Text_0:
# 290 "data/maps/DavZeroRoom/scripts.pory"
	.string "This shelf holds a series of\n"
	.string "installments.\p"
	.string "They all share the same title: “History\n"
	.string "of Whack a Hack: Since 2005.”\p"
	.string "Skimming a few of them, you can read\n"
	.string "names like Deryko, Inmortal Kaktus,\l"
	.string "Franco Kuchiki, C!ro, Lon, Frax,\l"
	.string "Acspower, and Kalawus.$"

DavZeroRoom_EventScript_Library3_Text_0:
# 295 "data/maps/DavZeroRoom/scripts.pory"
	.string "There's educational material, teaching\n"
	.string "guides, emotional education, and\l"
	.string "psychology.\p"
	.string "Many sections on conflict resolution\n"
	.string "are underlined.\p"
	.string "It seems someone hoped they'd be good\n"
	.string "for something… and also tried to apply\l"
	.string "them outside of class.$"

DavZeroRoom_EventScript_Tredmill_Text_0:
# 300 "data/maps/DavZeroRoom/scripts.pory"
	.string "It's a treadmill with a built-in screen.\p"
	.string "An episode of One Piece is playing.$"

DavZeroRoom_EventScript_TrashCan_Text_0:
# 305 "data/maps/DavZeroRoom/scripts.pory"
	.string "You've found the meaning of life! Oh\n"
	.string "wait, it's dented bottles, drafts that\l"
	.string "didn't survive their author's\l"
	.string "self-criticism, and… used Fortnite\l"
	.string "cards?$"

DavZeroRoom_EventScript_Box1_Text_0:
# 310 "data/maps/DavZeroRoom/scripts.pory"
	.string "Inside this box are consoles. You can\n"
	.string "spot a SNES and a Nintendo 64 alongside\l"
	.string "Zelda: Majora's Mask.\p"
	.string "There's also a cartridge of Super Mario\n"
	.string "World 2: Yoshi's Island.$"

DavZeroRoom_EventScript_Box2_Text_0:
# 315 "data/maps/DavZeroRoom/scripts.pory"
	.string "Inside this box are video games and\n"
	.string "figures. Two stand out, titled “Mother\l"
	.string "3” and “Phoenix Wright: Ace Attorney.”$"

DavZeroRoom_EventScript_StackedPlates_Text_0:
# 320 "data/maps/DavZeroRoom/scripts.pory"
	.string "They look like weight plates… or giant\n"
	.string "donuts for a Snorlax on a very strict\l"
	.string "diet.$"

DavZeroRoom_Text_DavZeroDefeated::
# 217 "data/maps/DavZeroRoom/scripts.pory"
	.string "Phew… I can't deny it, you've surprised\n"
	.string "me.\p"
	.string "It was one of those battles I love:\n"
	.string "intense, where every move seems to\l"
	.string "weigh twice as much and every decision\l"
	.string "matters.$"
