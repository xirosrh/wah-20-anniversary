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
	compare VAR_TEMP_0, 0
	goto_if_eq DavZeroRoom_OnTransition_2
DavZeroRoom_OnTransition_1:
	end

DavZeroRoom_OnTransition_2:
# 30 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 31 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_TEMP_2
	goto DavZeroRoom_OnTransition_1


DavZeroRoom_OnFrame::
# 37 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_0
# 38 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 39 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 10, 5
# 40 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 41 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 42 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_SCHOOLGIRL, DavZeroRoom_Movement_GirlAndBoyLearning
# 44 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_SCHOOLBOY, DavZeroRoom_Movement_GirlAndBoyLearning
# 45 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/DavZeroRoom/scripts.pory"
	waitse
# 47 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 48 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_DAVZERO, DIR_WEST
# 49 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_DoubleExclamationMarkWithDelay48
# 51 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 52 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 53 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 54 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_1
# 55 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft4
# 56 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement LOCALID_ZEROROOM_DAVZERO
# 57 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 58 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 59 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 60 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_3, DavZeroRoom_OnFrame_Text_4, DavZeroRoom_OnFrame_Text_5
# 61 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DavZeroRoom_OnFrame_2
DavZeroRoom_OnFrame_1:
# 66 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 67 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 68 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 69 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_2
# 70 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 71 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 72 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_3
# 73 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_DAVZERO, DIR_EAST
# 74 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 75 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SweatDropWithDelay48
# 77 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 78 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_4
# 79 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 80 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight
# 81 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 82 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkLeft2
# 83 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 84 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_JumpInPlaceLeftRight
# 85 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 86 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight2
# 87 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 88 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 89 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SmileWithDelay48
# 90 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 91 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 92 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_5
# 93 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 94 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
# 95 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement LOCALID_ZEROROOM_DAVZERO
# 96 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 97 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 98 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 99 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 100 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 101 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_16
# 102 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 103 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_CryWithDelay48
# 104 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 105 "data/maps/DavZeroRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 106 "data/maps/DavZeroRoom/scripts.pory"
	addobject LOCALID_ZEROROOM_POKEBALL
# 107 "data/maps/DavZeroRoom/scripts.pory"
	showobjectat LOCALID_ZEROROOM_POKEBALL, MAP_DAV_ZERO_ROOM
# 108 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 109 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 110 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_BALL_OPEN
# 111 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 112 "data/maps/DavZeroRoom/scripts.pory"
	removeobject LOCALID_ZEROROOM_POKEBALL
# 113 "data/maps/DavZeroRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 114 "data/maps/DavZeroRoom/scripts.pory"
	addobject LOCALID_ZEROROOM_MILOTIC
# 115 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 116 "data/maps/DavZeroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_ZEROROOM_DAVZERO, MOVEMENT_TYPE_FACE_DOWN
# 117 "data/maps/DavZeroRoom/scripts.pory"
	release
# 118 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_18, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 119 "data/maps/DavZeroRoom/scripts.pory"
	call DavZeroRoom_EventScript_DavZeroBattle
# 120 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 121 "data/maps/DavZeroRoom/scripts.pory"
	removeobject LOCALID_ZEROROOM_MILOTIC
# 122 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 123 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkDown2
# 124 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_19, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 125 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_ThinkingWithDelay48
# 127 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_20, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 128 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 129 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_21, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 130 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 131 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 132 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_22, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 133 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 134 "data/maps/DavZeroRoom/scripts.pory"
	closemessage
# 135 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 136 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_6
# 137 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_23, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 138 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 139 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_24, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 140 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 141 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 142 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_25, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 143 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HeartWithDelay48
# 145 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_26, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 146 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 147 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_27, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 148 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 150 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 151 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkUp2
# 152 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_28, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 153 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 154 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_FaceDown
# 155 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_29, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 156 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 157 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkDown2
# 158 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_30, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 159 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 160 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_31, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 161 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_ThinkingWithDelay48
# 162 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_32, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 163 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 164 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_33, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 165 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_34, DavZeroRoom_OnFrame_Text_35, DavZeroRoom_OnFrame_Text_36, DavZeroRoom_OnFrame_Text_37
# 166 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_38, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
# 167 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 168 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SmileWithDelay48
# 169 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 170 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 171 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 172 "data/maps/DavZeroRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 173 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 174 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 175 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 176 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_7
# 177 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 178 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_DAVZERO
# 179 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_OnFrame_2:
# 63 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 64 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_DAVZERO
	goto DavZeroRoom_OnFrame_1


DavZeroRoom_EventScript_DavZeroBattle::
# 184 "data/maps/DavZeroRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DavZeroRoom_EventScript_DavZeroBattle_2
# 187 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_DAVZERO
# 188 "data/maps/DavZeroRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 189 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DavZeroRoom_EventScript_DavZeroBattle_5
# 192 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE, DavZeroRoom_Text_DavZeroDefeated
DavZeroRoom_EventScript_DavZeroBattle_1:
# 195 "data/maps/DavZeroRoom/scripts.pory"
	special HealPlayerParty
	return

DavZeroRoom_EventScript_DavZeroBattle_2:
# 185 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_MAIN, DavZeroRoom_Text_DavZeroDefeated
	goto DavZeroRoom_EventScript_DavZeroBattle_1

DavZeroRoom_EventScript_DavZeroBattle_5:
# 190 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_MAIN, DavZeroRoom_Text_DavZeroDefeated
	goto DavZeroRoom_EventScript_DavZeroBattle_1


# 202 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_Movement_GirlAndBoyLearning:
# 203 "data/maps/DavZeroRoom/scripts.pory"
	emote_idea
# 204 "data/maps/DavZeroRoom/scripts.pory"
	walk_in_place_up
# 205 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
# 205 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

DavZeroRoom_EventScript_SchoolGirl::
# 209 "data/maps/DavZeroRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 210 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq DavZeroRoom_EventScript_SchoolGirl_2
# 213 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 214 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 215 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolGirl_Text_0, MSGBOX_AUTOCLOSE
# 216 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLGIRL, DIR_NORTH
# 217 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_EventScript_SchoolGirl_2:
	end


DavZeroRoom_EventScript_SchoolBoy::
# 222 "data/maps/DavZeroRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 223 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq DavZeroRoom_EventScript_SchoolBoy_2
# 226 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 227 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 228 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolBoy_Text_0
# 229 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 230 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_SCHOOLBOY, Common_Movement_SmileWithDelay48
# 231 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolBoy_Text_1, MSGBOX_AUTOCLOSE
# 232 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 233 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 234 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 235 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLBOY, DIR_NORTH
# 236 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_EventScript_SchoolBoy_2:
	end


DavZeroRoom_EventScript_Zero::
# 241 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_Zero_Text_0, MSGBOX_NPC
	end


# 37 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_0:
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 37 "data/maps/DavZeroRoom/scripts.pory"
	face_right
	step_end

# 54 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_1:
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 69 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_2:
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 69 "data/maps/DavZeroRoom/scripts.pory"
	face_left
	step_end

# 72 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_3:
# 72 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 72 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 72 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 72 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 72 "data/maps/DavZeroRoom/scripts.pory"
	face_left
	step_end

# 78 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_4:
# 78 "data/maps/DavZeroRoom/scripts.pory"
	emote_happy
# 78 "data/maps/DavZeroRoom/scripts.pory"
	jump_in_place_right
# 78 "data/maps/DavZeroRoom/scripts.pory"
	jump_in_place_right
# 78 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

# 92 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_5:
# 92 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 92 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 92 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 92 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 92 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 136 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_6:
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 136 "data/maps/DavZeroRoom/scripts.pory"
	emote_thinking
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 136 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 136 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 176 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_7:
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 176 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 176 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

DavZeroRoom_OnFrame_Text_0:
# 41 "data/maps/DavZeroRoom/scripts.pory"
	.string "Bien, recordad: las palabras agudas se\n"
	.string "acentúan cuando acaban en vocal, {COLOR RED}n{COLOR DARK_GRAY} o {COLOR BLUE}s{COLOR DARK_GRAY}.$"

DavZeroRoom_OnFrame_Text_1:
# 53 "data/maps/DavZeroRoom/scripts.pory"
	.string "Esperad un segundo… ¡Creo que hoy\n"
	.string "tenemos compañía!$"

DavZeroRoom_OnFrame_Text_2:
# 59 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ajá, con que por fin has llegado hasta\n"
	.string "aquí.\p"
	.string "Es un placer verte, ¿me reconoces?$"

DavZeroRoom_OnFrame_Text_3:
# 60 "data/maps/DavZeroRoom/scripts.pory"
	.string "Sí, ¡eres inconfundible!$"

DavZeroRoom_OnFrame_Text_4:
# 60 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me suenas, ¡pareces Machoke!$"

DavZeroRoom_OnFrame_Text_5:
# 60 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Debería conocerte?$"

DavZeroRoom_OnFrame_Text_6:
# 64 "data/maps/DavZeroRoom/scripts.pory"
	.string "En breves sabrás quién soy.$"

DavZeroRoom_OnFrame_Text_7:
# 74 "data/maps/DavZeroRoom/scripts.pory"
	.string "He tenido que dejar de hacer mi cuarta\n"
	.string "serie con 110 kg en press de banca.\p"
	.string "Todo porque escuchaba que un\n"
	.string "contendiente se acercaba a este nivel.\p"
	.string "Y justo me has pillado enseñando las\n"
	.string "reglas de acentuación a mi alumnado…$"

DavZeroRoom_OnFrame_Text_8:
# 77 "data/maps/DavZeroRoom/scripts.pory"
	.string "A ver, menos mal que pueden practicar\n"
	.string "un rato mientras combatimos.\p"
	.string "Aunque creo que estarán muy\n"
	.string "expectantes, porque presiento que\l"
	.string "este será un combate sin parangón.$"

DavZeroRoom_OnFrame_Text_9:
# 81 "data/maps/DavZeroRoom/scripts.pory"
	.string "Dime… ¿cuál es tu objetivo? ¿quieres\n"
	.string "desafiar al loco con lanzallamas que te\l"
	.string "espera al final?$"

DavZeroRoom_OnFrame_Text_10:
# 83 "data/maps/DavZeroRoom/scripts.pory"
	.string "A estas alturas ya lo sabrás, ya que\n"
	.string "para llegar aquí te has debido\l"
	.string "enfrentar a diversos compañeros.$"

DavZeroRoom_OnFrame_Text_11:
# 85 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡Pero yo no te lo pondré nada fácil en\n"
	.string "este combate!\p"
	.string "He estado entrenando cuerpo, mente y\n"
	.string "Pokémon esperando tu llegada.$"

DavZeroRoom_OnFrame_Text_12:
# 87 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pocos aspirantes logran llegar hasta\n"
	.string "aquí. Enhorabuena.$"

DavZeroRoom_OnFrame_Text_13:
# 90 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ven, posicionémonos en la zona de\n"
	.string "combate.$"

DavZeroRoom_OnFrame_Text_14:
# 97 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Sabes? Muchos creen que un combate\n"
	.string "es pura fuerza, pero para mí es memoria.\p"
	.string "Cada ataque, cada estrategia, cada\n"
	.string "fallo… es un recordatorio de quiénes\l"
	.string "fuimos y en qué nos convertimos.$"

DavZeroRoom_OnFrame_Text_15:
# 99 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quiero que te quede claro lo siguiente:\n"
	.string "no soy tu rival.\p"
	.string "Soy la voz que te recuerda que cada\n"
	.string "paso, incluso dentro de estas cuatro\l"
	.string "paredes, puede marcarte más de lo que\l"
	.string "crees.$"

DavZeroRoom_OnFrame_Text_16:
# 101 "data/maps/DavZeroRoom/scripts.pory"
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
# 104 "data/maps/DavZeroRoom/scripts.pory"
	.string "Bueno, ya está bien, que al final me\n"
	.string "pongo intenso y esto acabará\l"
	.string "pareciendo un poema de Benedetti…\p"
	.string "Y en esta ocasión no traigo rosas para\n"
	.string "acompañarlo, sino Pokéball.$"

DavZeroRoom_OnFrame_Text_18:
# 118 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡No te amedrentes ahora!$"

DavZeroRoom_OnFrame_Text_19:
# 124 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hoy has sido tú quien ha salido\n"
	.string "victorioso, y lo reconozco sin rodeos.\p"
	.string "Aunque debes tener claro que no\n"
	.string "siempre te alzarás con la victoria.$"

DavZeroRoom_OnFrame_Text_20:
# 127 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pero escucha algo: la derrota no es el\n"
	.string "final de nada. Al contrario, es un\l"
	.string "espejo.\p"
	.string "Refleja lo que todavía no queremos ver\n"
	.string "de nosotros mismos, aquello que\l"
	.string "evitamos afrontar.$"

DavZeroRoom_OnFrame_Text_21:
# 129 "data/maps/DavZeroRoom/scripts.pory"
	.string "Yo también lo he aprendido así,\n"
	.string "perdiendo, equivocándome, cayendo una\l"
	.string "y otra vez…$"

DavZeroRoom_OnFrame_Text_22:
# 132 "data/maps/DavZeroRoom/scripts.pory"
	.string "Riéndome.$"

DavZeroRoom_OnFrame_Text_23:
# 137 "data/maps/DavZeroRoom/scripts.pory"
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
# 139 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quiero que entiendas eso.$"

DavZeroRoom_OnFrame_Text_25:
# 142 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hoy me has derrotado, y me alegra que lo\n"
	.string "hayas hecho.\p"
	.string "Porque eso significa que tú también\n"
	.string "estás aprendiendo lo que de verdad\l"
	.string "importa…\p"
	.string "Y que yo también tengo cosas que\n"
	.string "aprender.$"

DavZeroRoom_OnFrame_Text_26:
# 145 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quédate con eso, porque es un\n"
	.string "conocimiento que ningún Pokémon,\l"
	.string "ningún rival y ninguna medalla pueden\l"
	.string "quitarte jamás.$"

DavZeroRoom_OnFrame_Text_27:
# 147 "data/maps/DavZeroRoom/scripts.pory"
	.string "Definitivamente no me equivocaba:\n"
	.string "tienes una mirada diferente.\p"
	.string "Estoy orgulloso de que hayas vencido,\n"
	.string "porque cada victoria como la tuya\l"
	.string "mantiene viva la llama de este lugar.$"

DavZeroRoom_OnFrame_Text_28:
# 152 "data/maps/DavZeroRoom/scripts.pory"
	.string "Aquí termina nuestro encuentro, pero\n"
	.string "no tu camino.\p"
	.string "Yo solo fui un obstáculo, como esas\n"
	.string "mancuernas que parecen imposibles\l"
	.string "hasta que un día te das cuenta de que\l"
	.string "puedes con ellas.$"

DavZeroRoom_OnFrame_Text_29:
# 155 "data/maps/DavZeroRoom/scripts.pory"
	.string "Y oye, si algún día coincidimos en el\n"
	.string "gimnasio, no me mires raro si te pido que\l"
	.string "me ayudes a subir la barra.\p"
	.string "Nadie es invencible.$"

DavZeroRoom_OnFrame_Text_30:
# 158 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ahora ve, compañero. Sigue tu camino,\n"
	.string "comete errores y aprende.$"

DavZeroRoom_OnFrame_Text_31:
# 160 "data/maps/DavZeroRoom/scripts.pory"
	.string "No tengas miedo de perder. Lo peor que\n"
	.string "puedes hacer es dejar de intentarlo por\l"
	.string "miedo a no estar a la altura.\p"
	.string "Yo lo sé bien… demasiadas veces me\n"
	.string "quedé paralizado pensando en qué dirán\l"
	.string "de mí, en si mis errores me definían.$"

DavZeroRoom_OnFrame_Text_32:
# 162 "data/maps/DavZeroRoom/scripts.pory"
	.string "No eres tus fracasos, ni tus caídas, ni\n"
	.string "lo que el resto piense de ti.\p"
	.string "Eres todo lo que haces a pesar de ellos.\n"
	.string "Si hoy has sido capaz de vencerme aquí,\l"
	.string "en este lugar, recuerda que también\l"
	.string "serás capaz de enfrentarte a cualquier\l"
	.string "cosa ahí fuera.$"

DavZeroRoom_OnFrame_Text_33:
# 164 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Qué pasa, por qué me miras así?$"

DavZeroRoom_OnFrame_Text_34:
# 165 "data/maps/DavZeroRoom/scripts.pory"
	.string "Gran consejo, digno de un sabio.$"

DavZeroRoom_OnFrame_Text_35:
# 165 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me hiciste pensar un poco.$"

DavZeroRoom_OnFrame_Text_36:
# 165 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Falta mucho del discurso?$"

DavZeroRoom_OnFrame_Text_37:
# 165 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Eso fue una clase?$"

DavZeroRoom_OnFrame_Text_38:
# 166 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿No te esperabas esto? Qué quieres que\n"
	.string "te diga… Yo tan solo soy Zero.$"

DavZeroRoom_EventScript_SchoolGirl_Text_0:
# 215 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Te cuento un secreto? Ya terminé la\n"
	.string "escuela hace años.\p"
	.string "¡Solamente vengo aquí porque Zero es\n"
	.string "tan interesante!\p"
	.string "Podría quedarme todo el día\n"
	.string "escuchándolo hablar.$"

DavZeroRoom_EventScript_SchoolBoy_Text_0:
# 228 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡El profe Zero es muy guay!$"

DavZeroRoom_EventScript_SchoolBoy_Text_1:
# 231 "data/maps/DavZeroRoom/scripts.pory"
	.string "Cuando teníamos seis años nos enseñó\n"
	.string "inglés y aprendimos los meses del año al\l"
	.string "ritmo de La Macarena.$"

DavZeroRoom_EventScript_Zero_Text_0:
# 241 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pendiente$"

DavZeroRoom_Text_DavZeroDefeated::
# 199 "data/maps/DavZeroRoom/scripts.pory"
	.string "Uf… no puedo negarlo, me has\n"
	.string "sorprendido.\p"
	.string "Ha sido uno de esos combates que a\n"
	.string "mí me gustan: intensos, donde cada\l"
	.string "movimiento parece pesar el doble\l"
	.string "y cada decisión importa.$"
