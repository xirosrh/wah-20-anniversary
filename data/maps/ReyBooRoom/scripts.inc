ReyBooRoom_MapScripts::
# 9 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ReyBooRoom_OnLoad
# 6 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/ReyBooRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ReyBooRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ReyBooRoom_OnLoad::
# 14 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REY_BOO, ReyBooRoom_OnLoad_2
ReyBooRoom_OnLoad_1:
	end

ReyBooRoom_OnLoad_2:
# 15 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ReyBooRoom_OnLoad_1


ReyBooRoom_OnWarp_PlayerTurnNorth::
# 21 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ReyBooRoom_EventScript_BooEncounter::
# 26 "data/maps/ReyBooRoom/scripts.pory"
	lock
# 27 "data/maps/ReyBooRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 28 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 29 "data/maps/ReyBooRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 30 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 32 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_IdeaWithDelay48
# 33 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 34 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight2
# 35 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 36 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 37 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 38 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_VIGOROTH, DIR_SOUTH
# 39 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 40 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 41 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 42 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 43 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 44 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 45 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 46 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 48 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 49 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 50 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 52 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 53 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 54 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 55 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 56 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 69 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 80 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 81 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 82 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 83 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 84 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 85 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 86 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 87 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 88 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 89 "data/maps/ReyBooRoom/scripts.pory"
	switch VAR_TEMP_0
# 90 "data/maps/ReyBooRoom/scripts.pory"
	case 4, ReyBooRoom_EventScript_BooEncounter_3
# 92 "data/maps/ReyBooRoom/scripts.pory"
	case 5, ReyBooRoom_EventScript_BooEncounter_4
# 94 "data/maps/ReyBooRoom/scripts.pory"
	case 7, ReyBooRoom_EventScript_BooEncounter_5
# 96 "data/maps/ReyBooRoom/scripts.pory"
	case 8, ReyBooRoom_EventScript_BooEncounter_6
ReyBooRoom_EventScript_BooEncounter_1:
# 99 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 100 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 101 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 102 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 103 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 104 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 105 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 106 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 107 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 108 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 109 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 110 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 111 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 112 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 113 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 114 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 115 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7, speaker = SP_NAME_REY_BOO
# 116 "data/maps/ReyBooRoom/scripts.pory"
	call ReyBooRoom_EventScript_ReyBooBattle
# 117 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 118 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 119 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_8, speaker = SP_NAME_REY_BOO
# 120 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 121 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 122 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 123 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceDown2
# 124 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 125 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 126 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 127 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 128 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 129 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 130 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 131 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 132 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 133 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 134 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 135 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 136 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 137 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 138 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE_TOP
# 139 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 140 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 141 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 142 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 143 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 144 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 145 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 146 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 147 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 148 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 149 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 150 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 151 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 152 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 153 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_12
# 154 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 155 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 156 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 157 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 158 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_13
# 159 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 160 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 161 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 162 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 163 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 164 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 165 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 166 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 167 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 168 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 169 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 170 "data/maps/ReyBooRoom/scripts.pory"
	release
	end

ReyBooRoom_EventScript_BooEncounter_3:
# 91 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_4:
# 93 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_5:
# 95 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_6:
# 97 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto ReyBooRoom_EventScript_BooEncounter_1


ReyBooRoom_EventScript_ReyBooBattle::
# 175 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReyBooRoom_EventScript_ReyBooBattle_2
# 178 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REYBOO
# 179 "data/maps/ReyBooRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 180 "data/maps/ReyBooRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReyBooRoom_EventScript_ReyBooBattle_5
# 183 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE, ReyBooRoom_Text_ReyBooDefeated
ReyBooRoom_EventScript_ReyBooBattle_1:
# 186 "data/maps/ReyBooRoom/scripts.pory"
	special HealPlayerParty
	return

ReyBooRoom_EventScript_ReyBooBattle_2:
# 176 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1

ReyBooRoom_EventScript_ReyBooBattle_5:
# 181 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1


# 40 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 40 "data/maps/ReyBooRoom/scripts.pory"
	emote_thinking
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	face_left
	step_end

# 47 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 47 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
# 47 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 47 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 47 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 51 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 51 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 51 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 51 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 57 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
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
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 67 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 69 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
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
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 79 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 82 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 82 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 82 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 83 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 83 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 83 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 83 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 83 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 83 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 101 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 101 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 101 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 101 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 101 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 101 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 101 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 104 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 104 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 104 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 104 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 104 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 111 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 111 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 111 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 111 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 117 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 117 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 117 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 117 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 117 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 117 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 117 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 149 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 149 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 149 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 149 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 149 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 149 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 149 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 153 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_12:
# 153 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
	step_end

# 158 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_13:
# 158 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 158 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 33 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 36 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 42 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 48 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 103 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 105 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 110 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 115 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 119 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 122 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 138 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 141 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 147 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 152 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 156 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"

ReyBooRoom_Text_ReyBooDefeated::
# 190 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"
