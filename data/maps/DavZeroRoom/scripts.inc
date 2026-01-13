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
	directcameramovementtopos 16, 6
# 40 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 41 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_0
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
	msgbox DavZeroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 54 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_1
# 55 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, DavZeroRoom_OnFrame_Movement_2
# 56 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 57 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 58 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_2
# 59 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_3, DavZeroRoom_OnFrame_Text_4, DavZeroRoom_OnFrame_Text_5
# 60 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DavZeroRoom_OnFrame_2
DavZeroRoom_OnFrame_1:
# 64 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 65 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 66 "data/maps/DavZeroRoom/scripts.pory"
	closemessage
# 67 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 68 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_3
# 69 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_4
# 70 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 71 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 72 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SweatDropWithDelay48
# 73 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 74 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_5
# 75 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 76 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight4
# 77 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_9
# 78 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkLeft
# 79 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_10
# 80 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_JumpInPlaceLeftRight
# 81 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_11
# 82 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight
# 83 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_12
# 84 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 85 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SmileWithDelay48
# 86 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE
# 87 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_6
# 88 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_7
# 89 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 90 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 91 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 92 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_14
# 93 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 94 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_15
# 95 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 96 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_16
# 97 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_CryWithDelay48
# 99 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE
# 100 "data/maps/DavZeroRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 101 "data/maps/DavZeroRoom/scripts.pory"
	addobject LOCALID_ZEROROOM_POKEBALL
# 102 "data/maps/DavZeroRoom/scripts.pory"
	showobjectat LOCALID_ZEROROOM_POKEBALL, MAP_DAV_ZERO_ROOM
# 103 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 104 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 105 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_BALL_OPEN
# 106 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 107 "data/maps/DavZeroRoom/scripts.pory"
	removeobject LOCALID_ZEROROOM_POKEBALL
# 108 "data/maps/DavZeroRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 109 "data/maps/DavZeroRoom/scripts.pory"
	addobject LOCALID_ZEROROOM_MILOTIC
# 110 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 111 "data/maps/DavZeroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_ZEROROOM_DAVZERO, MOVEMENT_TYPE_FACE_DOWN
# 112 "data/maps/DavZeroRoom/scripts.pory"
	release
# 113 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_18
# 114 "data/maps/DavZeroRoom/scripts.pory"
	call DavZeroRoom_EventScript_DavZeroBattle
# 115 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 116 "data/maps/DavZeroRoom/scripts.pory"
	removeobject LOCALID_ZEROROOM_MILOTIC
# 117 "data/maps/DavZeroRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 118 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkDown3
# 119 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_19
# 120 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 121 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_ThinkingWithDelay48
# 122 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_20
# 123 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 124 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_21
# 125 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 127 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_22
# 128 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 129 "data/maps/DavZeroRoom/scripts.pory"
	closemessage
# 130 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 131 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_8
# 132 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_23
# 133 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 134 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_24
# 135 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 136 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 137 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_25
# 138 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SweatDropWithDelay48
# 140 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_26
# 141 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 142 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_27, MSGBOX_AUTOCLOSE
# 143 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 145 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 146 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkUp2
# 147 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_28
# 148 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_FaceDown
# 149 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_29, MSGBOX_AUTOCLOSE
# 150 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 151 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkDown2
# 152 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_30
# 153 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 154 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_31
# 155 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_ThinkingWithDelay48
# 156 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_32
# 157 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 158 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_33
# 159 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 4, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_34, DavZeroRoom_OnFrame_Text_35, DavZeroRoom_OnFrame_Text_36, DavZeroRoom_OnFrame_Text_37
# 160 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_38
# 161 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 162 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SmileWithDelay48
# 164 "data/maps/DavZeroRoom/scripts.pory"
	setmetatile 9, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
# 165 "data/maps/DavZeroRoom/scripts.pory"
	special DrawWholeMapView
# 166 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 167 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_9
# 168 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 169 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 9, 12
# 170 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 171 "data/maps/DavZeroRoom/scripts.pory"
	special RemoveCameraObject
# 172 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 173 "data/maps/DavZeroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_DAVZERO
# 174 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_OnFrame_2:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_6
	goto DavZeroRoom_OnFrame_1


DavZeroRoom_EventScript_DavZeroBattle::
# 179 "data/maps/DavZeroRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DavZeroRoom_EventScript_DavZeroBattle_2
# 182 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_DAVZERO
# 183 "data/maps/DavZeroRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 184 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DavZeroRoom_EventScript_DavZeroBattle_5
# 187 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE, DavZeroRoom_Text_DavZeroDefeated
DavZeroRoom_EventScript_DavZeroBattle_1:
# 190 "data/maps/DavZeroRoom/scripts.pory"
	special HealPlayerParty
	return

DavZeroRoom_EventScript_DavZeroBattle_2:
# 180 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_MAIN, DavZeroRoom_Text_DavZeroDefeated
	goto DavZeroRoom_EventScript_DavZeroBattle_1

DavZeroRoom_EventScript_DavZeroBattle_5:
# 185 "data/maps/DavZeroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_DAVZERO_MAIN, DavZeroRoom_Text_DavZeroDefeated
	goto DavZeroRoom_EventScript_DavZeroBattle_1


# 197 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_Movement_GirlAndBoyLearning:
# 198 "data/maps/DavZeroRoom/scripts.pory"
	emote_idea
# 199 "data/maps/DavZeroRoom/scripts.pory"
	walk_in_place_up
# 200 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
# 200 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

DavZeroRoom_EventScript_SchoolGirl::
# 204 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 205 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 206 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolGirl_Text_0, MSGBOX_AUTOCLOSE
# 207 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLGIRL, DIR_NORTH
# 208 "data/maps/DavZeroRoom/scripts.pory"
	release
	end


DavZeroRoom_EventScript_SchoolBoy::
# 213 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 214 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 215 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolBoy_Text_0
# 216 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 217 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_SCHOOLBOY, Common_Movement_SmileWithDelay48
# 218 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolBoy_Text_1, MSGBOX_AUTOCLOSE
# 219 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 220 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 221 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 222 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLBOY, DIR_NORTH
# 223 "data/maps/DavZeroRoom/scripts.pory"
	release
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
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 54 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 55 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_2:
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 55 "data/maps/DavZeroRoom/scripts.pory"
	delay_8
	step_end

# 68 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_3:
# 68 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 68 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 68 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 68 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 68 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 68 "data/maps/DavZeroRoom/scripts.pory"
	face_right
	step_end

# 69 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_4:
# 69 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 69 "data/maps/DavZeroRoom/scripts.pory"
	face_left
	step_end

# 74 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_5:
# 74 "data/maps/DavZeroRoom/scripts.pory"
	emote_happy
# 74 "data/maps/DavZeroRoom/scripts.pory"
	jump_in_place_right
# 74 "data/maps/DavZeroRoom/scripts.pory"
	jump_in_place_right
# 74 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_6:
# 87 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 87 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 87 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 87 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
	step_end

# 88 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_7:
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	walk_down
# 88 "data/maps/DavZeroRoom/scripts.pory"
	face_up
	step_end

# 131 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_8:
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 131 "data/maps/DavZeroRoom/scripts.pory"
	emote_thinking
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 131 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 131 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 167 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_9:
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
	walk_right
# 167 "data/maps/DavZeroRoom/scripts.pory"
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
# 58 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ajá, con que por fin has llegado hasta\n"
	.string "aquí.\p"
	.string "Es un placer verte, ¿me reconoces?$"

DavZeroRoom_OnFrame_Text_3:
# 59 "data/maps/DavZeroRoom/scripts.pory"
	.string "Sí, ¡eres inconfundible!$"

DavZeroRoom_OnFrame_Text_4:
# 59 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me suenas, ¡pareces Machoke!$"

DavZeroRoom_OnFrame_Text_5:
# 59 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Debería conocerte?$"

DavZeroRoom_OnFrame_Text_6:
# 62 "data/maps/DavZeroRoom/scripts.pory"
	.string "En breves sabrás quién soy.$"

DavZeroRoom_OnFrame_Text_7:
# 70 "data/maps/DavZeroRoom/scripts.pory"
	.string "He tenido que dejar de hacer mi cuarta\n"
	.string "serie con 110 kg en press de banca.\p"
	.string "Todo porque escuchaba que un\n"
	.string "contendiente se acercaba a este nivel.\p"
	.string "Y justo me has pillado enseñando las\n"
	.string "reglas de acentuación a mi alumnado…$"

DavZeroRoom_OnFrame_Text_8:
# 73 "data/maps/DavZeroRoom/scripts.pory"
	.string "A ver, menos mal que pueden practicar\n"
	.string "un rato mientras combatimos.\p"
	.string "Aunque creo que estarán muy\n"
	.string "expectantes, porque presiento que\l"
	.string "este será un combate sin parangón.$"

DavZeroRoom_OnFrame_Text_9:
# 77 "data/maps/DavZeroRoom/scripts.pory"
	.string "Dime… ¿cuál es tu objetivo? ¿quieres\n"
	.string "desafiar al loco con lanzallamas que te\l"
	.string "espera al final?$"

DavZeroRoom_OnFrame_Text_10:
# 79 "data/maps/DavZeroRoom/scripts.pory"
	.string "A estas alturas ya lo sabrás, ya que\n"
	.string "para llegar aquí te has debido\l"
	.string "enfrentar a diversos compañeros.$"

DavZeroRoom_OnFrame_Text_11:
# 81 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡Pero yo no te lo pondré nada fácil en\n"
	.string "este combate!\p"
	.string "He estado entrenando cuerpo, mente y\n"
	.string "Pokémon esperando tu llegada.$"

DavZeroRoom_OnFrame_Text_12:
# 83 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pocos aspirantes logran llegar hasta\n"
	.string "aquí. Enhorabuena.$"

DavZeroRoom_OnFrame_Text_13:
# 86 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ven, vayamos a la zona de combate.$"

DavZeroRoom_OnFrame_Text_14:
# 92 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Sabes? Muchos creen que un combate\n"
	.string "es pura fuerza, pero para mí es memoria.\p"
	.string "Cada ataque, cada estrategia, cada\n"
	.string "fallo… es un recordatorio de quiénes\l"
	.string "fuimos y en qué nos convertimos.$"

DavZeroRoom_OnFrame_Text_15:
# 94 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quiero que te quede claro lo siguiente:\n"
	.string "no soy tu rival.\p"
	.string "Soy la voz que te recuerda que cada\n"
	.string "paso, incluso dentro de estas cuatro\l"
	.string "paredes, puede marcarte más de lo que\l"
	.string "crees.$"

DavZeroRoom_OnFrame_Text_16:
# 96 "data/maps/DavZeroRoom/scripts.pory"
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
# 99 "data/maps/DavZeroRoom/scripts.pory"
	.string "Bueno, ya está bien, que al final me\n"
	.string "pongo intenso y esto acabará\l"
	.string "pareciendo un poema de Benedetti…\p"
	.string "Y en esta ocasión no traigo rosas para\n"
	.string "acompañarlo, sino Pokéball.$"

DavZeroRoom_OnFrame_Text_18:
# 113 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡No te amedrentes ahora!$"

DavZeroRoom_OnFrame_Text_19:
# 119 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hoy has sido tú quien ha salido\n"
	.string "victorioso, y lo reconozco sin rodeos.\p"
	.string "Aunque debes tener claro que no\n"
	.string "siempre te alzarás con la victoria.$"

DavZeroRoom_OnFrame_Text_20:
# 122 "data/maps/DavZeroRoom/scripts.pory"
	.string "Pero escucha algo: la derrota no es el\n"
	.string "final de nada. Al contrario, es un\l"
	.string "espejo.\p"
	.string "Refleja lo que todavía no queremos ver\n"
	.string "de nosotros mismos, aquello que\l"
	.string "evitamos afrontar.$"

DavZeroRoom_OnFrame_Text_21:
# 124 "data/maps/DavZeroRoom/scripts.pory"
	.string "Yo también lo he aprendido así,\n"
	.string "perdiendo, equivocándome, cayendo una\l"
	.string "y otra vez…$"

DavZeroRoom_OnFrame_Text_22:
# 127 "data/maps/DavZeroRoom/scripts.pory"
	.string "Riéndome.$"

DavZeroRoom_OnFrame_Text_23:
# 132 "data/maps/DavZeroRoom/scripts.pory"
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
# 134 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quiero que entiendas eso.$"

DavZeroRoom_OnFrame_Text_25:
# 137 "data/maps/DavZeroRoom/scripts.pory"
	.string "Hoy me has derrotado, y me alegra que lo\n"
	.string "hayas hecho.\p"
	.string "Porque eso significa que tú también\n"
	.string "estás aprendiendo lo que de verdad\l"
	.string "importa…\p"
	.string "Y que yo también tengo cosas que\n"
	.string "aprender.$"

DavZeroRoom_OnFrame_Text_26:
# 140 "data/maps/DavZeroRoom/scripts.pory"
	.string "Quédate con eso, porque es un\n"
	.string "conocimiento que ningún Pokémon,\l"
	.string "ningún rival y ninguna medalla pueden\l"
	.string "quitarte jamás.$"

DavZeroRoom_OnFrame_Text_27:
# 142 "data/maps/DavZeroRoom/scripts.pory"
	.string "Definitivamente no me equivocaba:\n"
	.string "tienes una mirada diferente.\p"
	.string "Estoy orgulloso de que hayas vencido,\n"
	.string "porque cada victoria como la tuya\l"
	.string "mantiene viva la llama de este lugar.$"

DavZeroRoom_OnFrame_Text_28:
# 147 "data/maps/DavZeroRoom/scripts.pory"
	.string "Aquí termina nuestro encuentro, pero\n"
	.string "no tu camino.\p"
	.string "Yo solo fui un obstáculo, como esas\n"
	.string "mancuernas que parecen imposibles\l"
	.string "hasta que un día te das cuenta de que\l"
	.string "puedes con ellas.$"

DavZeroRoom_OnFrame_Text_29:
# 149 "data/maps/DavZeroRoom/scripts.pory"
	.string "Y oye, si algún día coincidimos en el\n"
	.string "gimnasio, no me mires raro si te pido que\l"
	.string "me ayudes a subir la barra.\p"
	.string "Nadie es invencible.$"

DavZeroRoom_OnFrame_Text_30:
# 152 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ahora ve, compañero. Sigue tu camino,\n"
	.string "comete errores y aprende.$"

DavZeroRoom_OnFrame_Text_31:
# 154 "data/maps/DavZeroRoom/scripts.pory"
	.string "No tengas miedo de perder. Lo peor que\n"
	.string "puedes hacer es dejar de intentarlo por\l"
	.string "miedo a no estar a la altura.\p"
	.string "Yo lo sé bien… demasiadas veces me\n"
	.string "quedé paralizado pensando en qué dirán\l"
	.string "de mí, en si mis errores me definían.$"

DavZeroRoom_OnFrame_Text_32:
# 156 "data/maps/DavZeroRoom/scripts.pory"
	.string "No eres tus fracasos, ni tus caídas, ni\n"
	.string "lo que el resto piense de ti.\p"
	.string "Eres todo lo que haces a pesar de ellos.\n"
	.string "Si hoy has sido capaz de vencerme aquí,\l"
	.string "en este lugar, recuerda que también\l"
	.string "serás capaz de enfrentarte a cualquier\l"
	.string "cosa ahí fuera.$"

DavZeroRoom_OnFrame_Text_33:
# 158 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Qué pasa, por qué me miras así?$"

DavZeroRoom_OnFrame_Text_34:
# 159 "data/maps/DavZeroRoom/scripts.pory"
	.string "Gran consejo, digno de un sabio.$"

DavZeroRoom_OnFrame_Text_35:
# 159 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me hiciste pensar un poco.$"

DavZeroRoom_OnFrame_Text_36:
# 159 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Falta mucho del discurso?$"

DavZeroRoom_OnFrame_Text_37:
# 159 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Eso fue una clase?$"

DavZeroRoom_OnFrame_Text_38:
# 160 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿No te esperabas esto? Qué quieres que\n"
	.string "te diga... Yo tan solo soy Zero.$"

DavZeroRoom_EventScript_SchoolGirl_Text_0:
# 206 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Te cuento un secreto? Ya terminé la\n"
	.string "escuela hace años.\p"
	.string "¡Solamente vengo aquí porque Zero es\n"
	.string "tan interesante!\p"
	.string "Podría quedarme todo el día\n"
	.string "escuchándolo hablar.$"

DavZeroRoom_EventScript_SchoolBoy_Text_0:
# 215 "data/maps/DavZeroRoom/scripts.pory"
	.string "¡El profe Zero es muy guay!$"

DavZeroRoom_EventScript_SchoolBoy_Text_1:
# 218 "data/maps/DavZeroRoom/scripts.pory"
	.string "Cuando teníamos seis años nos enseñó\n"
	.string "inglés y aprendimos los meses del año al\l"
	.string "ritmo de La Macarena.$"

DavZeroRoom_Text_DavZeroDefeated::
# 194 "data/maps/DavZeroRoom/scripts.pory"
	.string "Uf… no puedo negarlo, me has\n"
	.string "sorprendido.\p"
	.string "Ha sido uno de esos combates que a\n"
	.string "mí me gustan: intensos, donde cada\l"
	.string "movimiento parece pesar el doble\l"
	.string "y cada decisión importa.$"
