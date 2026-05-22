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
	.string "Bien, recordad: las palabras agudas se\n"
	.string "acentúan cuando acaban en vocal, {COLOR RED}n{COLOR DARK_GRAY} o {COLOR BLUE}s{COLOR DARK_GRAY}.$"

DavZeroRoom_OnFrame_Text_1:
# 55 "data/maps/DavZeroRoom/scripts.pory"
	.string "Esperad un segundo… ¡Creo que hoy\n"
	.string "tenemos compañía!$"

DavZeroRoom_OnFrame_Text_2:
# 61 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ajá, con que por fin has llegado hasta\n"
	.string "aquí.\p"
	.string "Es un placer verte, ¿me reconoces?$"

DavZeroRoom_OnFrame_Text_3:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "Sí, ¡eres inconfundible!$"

DavZeroRoom_OnFrame_Text_4:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me suenas, ¡pareces Machoke!$"

DavZeroRoom_OnFrame_Text_5:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Debería conocerte?$"

DavZeroRoom_OnFrame_Text_6:
# 66 "data/maps/DavZeroRoom/scripts.pory"
	.string "En breves sabrás quién soy.$"

DavZeroRoom_OnFrame_Text_7:
# 76 "data/maps/DavZeroRoom/scripts.pory"
	.string "He tenido que dejar de hacer mi cuarta\n"
	.string "serie con 110 kg en press de banca.\p"
	.string "Todo porque escuchaba que un\n"
	.string "contendiente se acercaba a este nivel.\p"
	.string "Y justo me has pillado enseñando las\n"
	.string "reglas de acentuación a mi alumnado…$"

DavZeroRoom_OnFrame_Text_8:
# 79 "data/maps/DavZeroRoom/scripts.pory"
	.string "A ver, menos mal que pueden practicar\n"
	.string "un rato mientras combatimos.\p"
	.string "Aunque creo que estarán muy\n"
	.string "expectantes, porque presiento que\l"
	.string "este será un combate sin parangón.$"

DavZeroRoom_OnFrame_Text_9:
# 90 "data/maps/DavZeroRoom/scripts.pory"
	.string "Dime… ¿cuál es tu objetivo? ¿quieres\n"
	.string "desafiar al loco con lanzallamas que te\l"
	.string "espera al final?$"

DavZeroRoom_OnFrame_Text_10:
# 92 "data/maps/DavZeroRoom/scripts.pory"
	.string "A estas alturas ya lo sabrás, ya que\n"
	.string "para llegar aquí te has debido\l"
	.string "enfrentar a diversos compañeros.$"

DavZeroRoom_OnFrame_Text_11:
# 95 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡Pero yo no te lo pondré nada fácil en\n"
	.string "este combate!\p"
	.string "He estado entrenando cuerpo, mente y\n"
	.string "Pokémon esperando tu llegada.$"

DavZeroRoom_OnFrame_Text_12:
# 97 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pocos aspirantes logran llegar hasta\n"
	.string "aquí.\p"
	.string "Enhorabuena.$"

DavZeroRoom_OnFrame_Text_13:
# 100 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ven, posicionémonos en la zona de\n"
	.string "combate.$"

DavZeroRoom_OnFrame_Text_14:
# 107 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Sabes? Muchos creen que un combate\n"
	.string "es pura fuerza, pero para mí es memoria.\p"
	.string "Cada ataque, cada estrategia, cada\n"
	.string "fallo… es un recordatorio de quiénes\l"
	.string "fuimos y en qué nos convertimos.$"

DavZeroRoom_OnFrame_Text_15:
# 109 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quiero que te quede claro lo siguiente:\n"
	.string "no soy tu rival.\p"
	.string "Soy la voz que te recuerda que cada\n"
	.string "paso, incluso dentro de estas cuatro\l"
	.string "paredes, puede marcarte más de lo que\l"
	.string "crees.$"

DavZeroRoom_OnFrame_Text_16:
# 112 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hay quien lucha para ganar, y hay quien\n"
	.string "lucha para no volver a cometer el mismo\l"
	.string "fallo.\p"
	.string "¿Cuál de esos eres tú? Déjame\n"
	.string "comprobarlo, ya que tu mirada me\l"
	.string "produce curiosidad…\p"
	.string "Me hace recordar aquella época loca en\n"
	.string "la que frecuentaba aquel lugar que\l"
	.string "antaño fue nuestro hogar.$"

DavZeroRoom_OnFrame_Text_17:
# 115 "data/maps/DavZeroRoom/scripts.pory"
	.string "Bueno, ya está bien, que al final me\n"
	.string "pongo intenso y esto acabará\l"
	.string "pareciendo un poema de Benedetti…\p"
	.string "Y en esta ocasión no traigo rosas para\n"
	.string "acompañarlo, sino Pokéball.$"

DavZeroRoom_OnFrame_Text_18:
# 129 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡No te amedrentes ahora!$"

DavZeroRoom_OnFrame_Text_19:
# 139 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hoy has sido tú quien ha salido\n"
	.string "victorios{OA}, y lo reconozco sin rodeos.\p"
	.string "Aunque debes tener claro que no\n"
	.string "siempre te alzarás con la victoria.$"

DavZeroRoom_OnFrame_Text_20:
# 142 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pero escucha algo: la derrota no es el\n"
	.string "final de nada.\p"
	.string "Al contrario, es un espejo.\p"
	.string "Refleja lo que todavía no queremos ver\n"
	.string "de nosotros mismos, aquello que\l"
	.string "evitamos afrontar.$"

DavZeroRoom_OnFrame_Text_21:
# 144 "data/maps/DavZeroRoom/scripts.pory"
	.string "Yo también lo he aprendido así,\n"
	.string "perdiendo, equivocándome, cayendo una\l"
	.string "y otra vez…$"

DavZeroRoom_OnFrame_Text_22:
# 146 "data/maps/DavZeroRoom/scripts.pory"
	.string "Riéndome.$"

DavZeroRoom_OnFrame_Text_23:
# 154 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Sabes? El éxito y la victoria no está\n"
	.string "en acumular triunfos, ni en aplastar\l"
	.string "rivales, ni siquiera en vencerme a mí\l"
	.string "ahora.\p"
	.string "El éxito está en levantarte después de\n"
	.string "caer, en seguir caminando con las\l"
	.string "cicatrices bien visibles, en no rendirte\l"
	.string "aunque la vida o un combate te hayan\l"
	.string "dejado tocado.$"

DavZeroRoom_OnFrame_Text_24:
# 156 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quiero que entiendas eso.$"

DavZeroRoom_OnFrame_Text_25:
# 159 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hoy me has derrotado, y me alegra que lo\n"
	.string "hayas hecho.\p"
	.string "Porque eso significa que tú también\n"
	.string "estás aprendiendo lo que de verdad\l"
	.string "importa…\p"
	.string "Y que yo también tengo cosas que\n"
	.string "aprender.$"

DavZeroRoom_OnFrame_Text_26:
# 162 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quédate con eso, porque es un\n"
	.string "conocimiento que ningún Pokémon,\l"
	.string "ningún rival y ninguna medalla pueden\l"
	.string "quitarte jamás.$"

DavZeroRoom_OnFrame_Text_27:
# 164 "data/maps/DavZeroRoom/scripts.pory"
	.string "Definitivamente no me equivocaba:\n"
	.string "tienes una mirada diferente.\p"
	.string "Estoy orgulloso de que hayas vencido,\n"
	.string "porque cada victoria como la tuya\l"
	.string "mantiene viva la llama de este lugar.$"

DavZeroRoom_OnFrame_Text_28:
# 169 "data/maps/DavZeroRoom/scripts.pory"
	.string "Aquí termina nuestro encuentro, pero\n"
	.string "no tu camino.\p"
	.string "Yo solo fui un obstáculo, como esas\n"
	.string "mancuernas que parecen imposibles\l"
	.string "hasta que un día te das cuenta de que\l"
	.string "puedes con ellas.$"

DavZeroRoom_OnFrame_Text_29:
# 172 "data/maps/DavZeroRoom/scripts.pory"
	.string "Y oye, si algún día coincidimos en el\n"
	.string "gimnasio, no me mires raro si te pido que\l"
	.string "me ayudes a subir la barra.\p"
	.string "Nadie es invencible.$"

DavZeroRoom_OnFrame_Text_30:
# 175 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ahora ve, compañer{OA}. Sigue tu camino,\n"
	.string "comete errores y aprende.$"

DavZeroRoom_OnFrame_Text_31:
# 177 "data/maps/DavZeroRoom/scripts.pory"
	.string "No tengas miedo de perder.\p"
	.string "Lo peor que puedes hacer es dejar de\n"
	.string "intentarlo por miedo a no estar a la\l"
	.string "altura.\p"
	.string "Yo lo sé bien… demasiadas veces me\n"
	.string "quedé paralizado pensando en qué dirán\l"
	.string "de mí, en si mis errores me definían.$"

DavZeroRoom_OnFrame_Text_32:
# 180 "data/maps/DavZeroRoom/scripts.pory"
	.string "No eres tus fracasos, ni tus caídas, ni\n"
	.string "lo que el resto piense de ti.\p"
	.string "Eres todo lo que haces a pesar de ellos.\p"
	.string "Si hoy has sido capaz de vencerme aquí,\n"
	.string "en este lugar, recuerda que también\l"
	.string "serás capaz de enfrentarte a cualquier\l"
	.string "cosa ahí fuera.$"

DavZeroRoom_OnFrame_Text_33:
# 182 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Qué pasa, por qué me miras así?$"

DavZeroRoom_OnFrame_Text_34:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "Gran consejo, digno de un sabio.$"

DavZeroRoom_OnFrame_Text_35:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me hiciste pensar un poco.$"

DavZeroRoom_OnFrame_Text_36:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Falta mucho del discurso?$"

DavZeroRoom_OnFrame_Text_37:
# 183 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Eso fue una clase?$"

DavZeroRoom_OnFrame_Text_38:
# 184 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿No te esperabas esto? Qué quieres que\n"
	.string "te diga… Yo tan solo soy Zero.$"

DavZeroRoom_EventScript_SchoolGirl_Text_0:
# 233 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Te cuento un secreto? Ya terminé la\n"
	.string "escuela hace años.\p"
	.string "¡Solamente vengo aquí porque Zero es\n"
	.string "tan interesante!\p"
	.string "Podría quedarme todo el día\n"
	.string "escuchándolo hablar.$"

DavZeroRoom_EventScript_SchoolBoy_Text_0:
# 246 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡El profe Zero es muy guay!$"

DavZeroRoom_EventScript_SchoolBoy_Text_1:
# 249 "data/maps/DavZeroRoom/scripts.pory"
	.string "Cuando teníamos seis años nos enseñó\n"
	.string "inglés y aprendimos los meses del año al\l"
	.string "ritmo de La Macarena.$"

DavZeroRoom_EventScript_Zero_Text_0:
# 261 "data/maps/DavZeroRoom/scripts.pory"
	.string "Si quieres otra frase profunda, trae\n"
	.string "ticket.\p"
	.string "Mi trabajo aquí acabó.$"

DavZeroRoom_EventScript_Dumbbells_Text_0:
# 270 "data/maps/DavZeroRoom/scripts.pory"
	.string "Las mancuernas pesan lo suficiente\n"
	.string "como para no ser decorativas.$"

DavZeroRoom_EventScript_PC_Text_0:
# 275 "data/maps/DavZeroRoom/scripts.pory"
	.string "Es un portátil encendido con un fondo\n"
	.string "de pantalla del Valencia CF.\p"
	.string "Hay más pestañas abiertas que\n"
	.string "multicuentas del Team NoHack.$"

DavZeroRoom_EventScript_Notes_Text_0:
# 280 "data/maps/DavZeroRoom/scripts.pory"
	.string "Son varias hojas que se encuentran en\n"
	.string "el suelo.\p"
	.string "Parecen ser apuntes de ideas para un\n"
	.string "libro de poesía.$"

DavZeroRoom_EventScript_Library1_Text_0:
# 285 "data/maps/DavZeroRoom/scripts.pory"
	.string "Parece una recopilación de libros de\n"
	.string "poesía.\p"
	.string "Uno destaca entre los demás: “Un\n"
	.string "lustro de soliloquio”.\p"
	.string "El autor figura como Zero.$"

DavZeroRoom_EventScript_Library2_Text_0:
# 290 "data/maps/DavZeroRoom/scripts.pory"
	.string "Esta estantería contiene una serie de\n"
	.string "fascículos.\p"
	.string "Todos tienen el mismo título: “Historia\n"
	.string "de Whack a Hack: Desde 2005”.\p"
	.string "Echando una ojeada rápida a algunos, se\n"
	.string "leen nombres como Deryko, Inmortal\l"
	.string "Kaktus, Franco Kuchiki, C!ro, Lon, Frax,\l"
	.string "Acspower o Kalawus.$"

DavZeroRoom_EventScript_Library3_Text_0:
# 295 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hay material educativo, guías\n"
	.string "pedagógicas, educación emocional y\l"
	.string "psicología.\p"
	.string "Muchos apartados sobre resolución de\n"
	.string "conflictos están subrayados.\p"
	.string "Parece que alguien esperaba que\n"
	.string "sirvieran para algo… Y que también\l"
	.string "intentó aplicarlos fuera de clase.$"

DavZeroRoom_EventScript_Tredmill_Text_0:
# 300 "data/maps/DavZeroRoom/scripts.pory"
	.string "Es una cinta de correr con pantalla\n"
	.string "incorporada.\p"
	.string "Está puesto un capítulo de One Piece.$"

DavZeroRoom_EventScript_TrashCan_Text_0:
# 305 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡Has encontrado el sentido de la vida!\n"
	.string "Ah no, son botellas abolladas,\l"
	.string "borradores que no sobrevivieron a la\l"
	.string "autocrítica y… ¿tarjetas de Fortnite\l"
	.string "usadas?$"

DavZeroRoom_EventScript_Box1_Text_0:
# 310 "data/maps/DavZeroRoom/scripts.pory"
	.string "Dentro de esta caja hay consolas. Se\n"
	.string "llega a ver una SNES y una Nintendo 64\l"
	.string "junto a Zelda Majora's Mask.\p"
	.string "También hay un cartucho de Super Mario\n"
	.string "World 2: Yoshi's Island.$"

DavZeroRoom_EventScript_Box2_Text_0:
# 315 "data/maps/DavZeroRoom/scripts.pory"
	.string "Dentro de esta caja hay videojuegos y\n"
	.string "figuras. Sobresalen dos cuyos títulos\l"
	.string "son “Mother 3” y “Phoenix Wright: Ace\l"
	.string "Attorney”.$"

DavZeroRoom_EventScript_StackedPlates_Text_0:
# 320 "data/maps/DavZeroRoom/scripts.pory"
	.string "Parecen discos de peso… o donuts\n"
	.string "gigantes para un Snorlax con una dieta\l"
	.string "muy estricta.$"

DavZeroRoom_Text_DavZeroDefeated::
# 217 "data/maps/DavZeroRoom/scripts.pory"
	.string "Uf… no puedo negarlo, me has\n"
	.string "sorprendido.\p"
	.string "Ha sido uno de esos combates que a\n"
	.string "mí me gustan: intensos, donde cada\l"
	.string "movimiento parece pesar el doble\l"
	.string "y cada decisión importa.$"
