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
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_ThinkingWithDelay48
# 41 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 42 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 43 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_VIGOROTH, DIR_WEST
# 44 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 45 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 46 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 47 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 48 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 49 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 50 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 51 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 52 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 53 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 54 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 55 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 56 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 57 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 71 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 82 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 83 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 84 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 85 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 86 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 87 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 88 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 89 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 90 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 91 "data/maps/ReyBooRoom/scripts.pory"
	switch VAR_TEMP_0
# 92 "data/maps/ReyBooRoom/scripts.pory"
	case 4, ReyBooRoom_EventScript_BooEncounter_3
# 94 "data/maps/ReyBooRoom/scripts.pory"
	case 5, ReyBooRoom_EventScript_BooEncounter_4
# 96 "data/maps/ReyBooRoom/scripts.pory"
	case 7, ReyBooRoom_EventScript_BooEncounter_5
# 98 "data/maps/ReyBooRoom/scripts.pory"
	case 8, ReyBooRoom_EventScript_BooEncounter_6
ReyBooRoom_EventScript_BooEncounter_1:
# 101 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 102 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 103 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 104 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 105 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 106 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 107 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 108 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 109 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 110 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 111 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 112 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 113 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 114 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 115 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 117 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7, speaker = SP_NAME_REY_BOO
# 118 "data/maps/ReyBooRoom/scripts.pory"
	call ReyBooRoom_EventScript_ReyBooBattle
# 119 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 120 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 121 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_8, speaker = SP_NAME_REY_BOO
# 122 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 123 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 124 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 125 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceDown2
# 126 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 127 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 128 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 129 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 130 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 131 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 132 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 133 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 134 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 135 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 136 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 137 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 138 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 139 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 140 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE_TOP
# 141 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 142 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 143 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 144 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 145 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 146 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 147 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 148 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 149 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 150 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 151 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 152 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 153 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 154 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 155 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 156 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 157 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 158 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 159 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 160 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_12
# 161 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 162 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 163 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 164 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 165 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 166 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 167 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 168 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 169 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 170 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 171 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 172 "data/maps/ReyBooRoom/scripts.pory"
	release
	end

ReyBooRoom_EventScript_BooEncounter_3:
# 93 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_4:
# 95 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_5:
# 97 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_6:
# 99 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto ReyBooRoom_EventScript_BooEncounter_1


ReyBooRoom_EventScript_ReyBooBattle::
# 177 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReyBooRoom_EventScript_ReyBooBattle_2
# 180 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REYBOO
# 181 "data/maps/ReyBooRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 182 "data/maps/ReyBooRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReyBooRoom_EventScript_ReyBooBattle_5
# 185 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE, ReyBooRoom_Text_ReyBooDefeated
ReyBooRoom_EventScript_ReyBooBattle_1:
# 188 "data/maps/ReyBooRoom/scripts.pory"
	special HealPlayerParty
	return

ReyBooRoom_EventScript_ReyBooBattle_2:
# 178 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1

ReyBooRoom_EventScript_ReyBooBattle_5:
# 183 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1


# 49 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 49 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
# 49 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 49 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 49 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 53 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 53 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 53 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 53 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 58 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 59 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 64 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 65 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 66 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 67 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 67 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 67 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 68 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 68 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 71 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 73 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 75 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 76 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 81 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 84 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 84 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 84 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 85 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 85 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 85 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 85 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 103 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 103 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 103 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 103 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 103 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 103 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 103 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 106 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 106 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 106 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 106 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 106 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 113 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 113 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 113 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 113 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 119 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 119 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 119 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 119 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 119 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 119 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 119 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 151 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 151 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 151 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 151 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 151 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 151 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 151 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 155 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 155 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
	step_end

# 160 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_12:
# 160 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 160 "data/maps/ReyBooRoom/scripts.pory"
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
# 44 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 50 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 105 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 107 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 112 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 117 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 121 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 124 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 140 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 143 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 149 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 154 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 158 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"

ReyBooRoom_Text_ReyBooDefeated::
# 192 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"
