ReyBooRoom_MapScripts::
# 8 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ReyBooRoom_OnLoad
# 5 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/ReyBooRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ReyBooRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ReyBooRoom_OnLoad::
# 13 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REY_BOO, ReyBooRoom_OnLoad_2
ReyBooRoom_OnLoad_1:
	end

ReyBooRoom_OnLoad_2:
# 14 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ReyBooRoom_OnLoad_1


ReyBooRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ReyBooRoom_EventScript_BooEncounter::
# 25 "data/maps/ReyBooRoom/scripts.pory"
	lock
# 26 "data/maps/ReyBooRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 27 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 28 "data/maps/ReyBooRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 29 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 31 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_IdeaWithDelay48
# 32 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 33 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight2
# 34 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 35 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 36 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 37 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 38 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_ThinkingWithDelay48
# 39 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 40 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 41 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 42 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 43 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 44 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 45 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 47 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 48 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 49 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 51 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 52 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 53 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 54 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 68 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 79 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 80 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 81 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 82 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 83 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 84 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 85 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 86 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 87 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 88 "data/maps/ReyBooRoom/scripts.pory"
	switch VAR_TEMP_0
# 89 "data/maps/ReyBooRoom/scripts.pory"
	case 4, ReyBooRoom_EventScript_BooEncounter_3
# 91 "data/maps/ReyBooRoom/scripts.pory"
	case 5, ReyBooRoom_EventScript_BooEncounter_4
# 93 "data/maps/ReyBooRoom/scripts.pory"
	case 7, ReyBooRoom_EventScript_BooEncounter_5
# 95 "data/maps/ReyBooRoom/scripts.pory"
	case 8, ReyBooRoom_EventScript_BooEncounter_6
ReyBooRoom_EventScript_BooEncounter_1:
# 98 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 99 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 100 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 101 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 102 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 103 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 104 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 105 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 106 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 107 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 108 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 109 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 110 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 111 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 112 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 113 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 114 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7, speaker = SP_NAME_REY_BOO
# 115 "data/maps/ReyBooRoom/scripts.pory"
	call ReyBooRoom_EventScript_ReyBooBattle
# 116 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 117 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 118 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_8, speaker = SP_NAME_REY_BOO
# 119 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 120 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 121 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 122 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceDown2
# 123 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 124 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 125 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 126 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 127 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 128 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 129 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 130 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 131 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 132 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 133 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 134 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 135 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 136 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 137 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE_TOP
# 138 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 140 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 141 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 142 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 143 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 144 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 145 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 146 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 147 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 148 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 149 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 150 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 151 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 152 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 153 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 154 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 155 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 156 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 157 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_12
# 158 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 159 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 160 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 161 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 162 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 163 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 164 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 165 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 166 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_REY_BOO_ROOM_STATE, 1
# 167 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 168 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 169 "data/maps/ReyBooRoom/scripts.pory"
	release
	end

ReyBooRoom_EventScript_BooEncounter_3:
# 90 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_4:
# 92 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_5:
# 94 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_6:
# 96 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto ReyBooRoom_EventScript_BooEncounter_1


ReyBooRoom_EventScript_ReyBooBattle::
# 174 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReyBooRoom_EventScript_ReyBooBattle_2
# 177 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REYBOO
# 178 "data/maps/ReyBooRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 179 "data/maps/ReyBooRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReyBooRoom_EventScript_ReyBooBattle_5
# 182 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE, ReyBooRoom_Text_ReyBooDefeated
ReyBooRoom_EventScript_ReyBooBattle_1:
# 185 "data/maps/ReyBooRoom/scripts.pory"
	special HealPlayerParty
	return

ReyBooRoom_EventScript_ReyBooBattle_2:
# 175 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1

ReyBooRoom_EventScript_ReyBooBattle_5:
# 180 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1


# 46 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 46 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
# 46 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 46 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 46 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 50 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 50 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 50 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 50 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 50 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 55 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 56 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 57 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 57 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 58 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 58 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 68 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 70 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 70 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 78 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 81 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 81 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 82 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 82 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 82 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 82 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 82 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 82 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 100 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 100 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 100 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 100 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 100 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 100 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 100 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 103 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 103 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 103 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 103 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 103 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 110 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 110 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 110 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 110 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 116 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 116 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 116 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 116 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 116 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 116 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 116 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 148 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 148 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 148 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 148 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 148 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 148 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 148 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 152 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 152 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
	step_end

# 157 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_12:
# 157 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 157 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 32 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 35 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 41 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 47 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 102 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 104 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 109 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 114 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 118 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 121 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 137 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 140 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 146 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 151 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 155 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"

ReyBooRoom_Text_ReyBooDefeated::
# 189 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"
