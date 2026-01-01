ReyBooRoom_MapScripts::
# 5 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ReyBooRoom_OnLoad
# 2 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/ReyBooRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ReyBooRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ReyBooRoom_OnLoad::
# 10 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REY_BOO, ReyBooRoom_OnLoad_2
ReyBooRoom_OnLoad_1:
	end

ReyBooRoom_OnLoad_2:
# 11 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ReyBooRoom_OnLoad_1


ReyBooRoom_OnWarp_PlayerTurnNorth::
# 17 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ReyBooRoom_EventScript_BooEncounter::
# 22 "data/maps/ReyBooRoom/scripts.pory"
	lock
# 23 "data/maps/ReyBooRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 24 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 25 "data/maps/ReyBooRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 26 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 27 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_IdeaWithDelay48
# 29 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 30 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight2
# 31 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 32 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 33 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 34 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_ThinkingWithDelay48
# 36 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 37 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 38 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 39 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 40 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 41 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 42 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 44 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 45 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 46 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 48 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 49 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 50 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 51 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 65 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 76 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 78 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 79 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 80 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 81 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 82 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 83 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_REYBOOROOM_HIDE_VIGOROTH
# 84 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 85 "data/maps/ReyBooRoom/scripts.pory"
	switch VAR_TEMP_0
# 86 "data/maps/ReyBooRoom/scripts.pory"
	case 4, ReyBooRoom_EventScript_BooEncounter_3
# 88 "data/maps/ReyBooRoom/scripts.pory"
	case 5, ReyBooRoom_EventScript_BooEncounter_4
# 90 "data/maps/ReyBooRoom/scripts.pory"
	case 7, ReyBooRoom_EventScript_BooEncounter_5
# 92 "data/maps/ReyBooRoom/scripts.pory"
	case 8, ReyBooRoom_EventScript_BooEncounter_6
ReyBooRoom_EventScript_BooEncounter_1:
# 95 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 96 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 97 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 98 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 99 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 100 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 101 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 102 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 103 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 104 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 105 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 106 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 107 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 108 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 109 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 110 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 111 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7, speaker = SP_NAME_REY_BOO
# 113 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReyBooRoom_EventScript_BooEncounter_8
# 116 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 12
# 117 "data/maps/ReyBooRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 118 "data/maps/ReyBooRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReyBooRoom_EventScript_BooEncounter_11
# 121 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE, ReyBooRoom_EventScript_BooEncounter_Text_8
ReyBooRoom_EventScript_BooEncounter_7:
# 124 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 125 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 126 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9, speaker = SP_NAME_REY_BOO
# 127 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 128 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 129 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 130 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceDown2
# 131 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 132 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 133 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 134 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 135 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 136 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 137 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 138 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 139 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 140 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 141 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 142 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 143 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 144 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 145 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE_TOP
# 146 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 147 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 148 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 149 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 150 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 151 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 152 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 153 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 154 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 155 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 156 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 157 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 158 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 159 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 160 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 161 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 162 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 163 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 164 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 165 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_12
# 166 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 167 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 168 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 169 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_REYBOOROOM_HIDE_BOO
# 170 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 171 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 172 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 173 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 174 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_REY_BOO_ROOM_STATE, 1
# 175 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 176 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 177 "data/maps/ReyBooRoom/scripts.pory"
	release
	end

ReyBooRoom_EventScript_BooEncounter_3:
# 87 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_4:
# 89 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_5:
# 91 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_6:
# 93 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_8:
# 114 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_EventScript_BooEncounter_Text_8
	goto ReyBooRoom_EventScript_BooEncounter_7

ReyBooRoom_EventScript_BooEncounter_11:
# 119 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_EventScript_BooEncounter_Text_8
	goto ReyBooRoom_EventScript_BooEncounter_7


# 43 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 43 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
# 43 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 43 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 43 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 47 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 47 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 47 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 47 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 47 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 52 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 53 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 57 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 57 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 58 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 58 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 58 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 58 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 65 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 67 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 67 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 68 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 68 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 68 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 68 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 70 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 70 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 70 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 70 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 75 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 78 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 78 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 79 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 79 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 79 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 79 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 97 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 97 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 97 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 97 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 97 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 97 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 97 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 100 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 100 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 100 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 100 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 100 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 107 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 107 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 107 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 107 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 124 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 124 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 124 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 124 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 124 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 124 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 124 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 156 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 156 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 156 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 156 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 156 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 156 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 156 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 160 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 160 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
	step_end

# 165 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_12:
# 165 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 165 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 29 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 32 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 38 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 44 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 99 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 101 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 106 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 111 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 114 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 126 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 129 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 145 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 148 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 154 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 159 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_15:
# 163 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"
