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
	playse SE_LEDGE
# 35 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 36 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 37 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 38 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 39 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 40 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 41 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 42 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 43 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_VIGOROTH, DIR_SOUTH
# 44 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 46 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 47 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 48 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 49 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 50 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 51 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 53 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 54 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 55 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 56 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 57 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 58 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 59 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 60 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 61 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 62 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 64 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 65 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 66 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 67 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 68 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 70 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 71 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 84 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 95 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 96 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 97 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 98 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 99 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 100 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 101 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 102 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 103 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 104 "data/maps/ReyBooRoom/scripts.pory"
	switch VAR_TEMP_0
# 105 "data/maps/ReyBooRoom/scripts.pory"
	case 4, ReyBooRoom_EventScript_BooEncounter_3
# 107 "data/maps/ReyBooRoom/scripts.pory"
	case 5, ReyBooRoom_EventScript_BooEncounter_4
# 109 "data/maps/ReyBooRoom/scripts.pory"
	case 7, ReyBooRoom_EventScript_BooEncounter_5
# 111 "data/maps/ReyBooRoom/scripts.pory"
	case 8, ReyBooRoom_EventScript_BooEncounter_6
ReyBooRoom_EventScript_BooEncounter_1:
# 114 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 115 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 116 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 117 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 118 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 119 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 120 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 121 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 122 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 123 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 124 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 125 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 126 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 127 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 128 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 129 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 130 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7, speaker = SP_NAME_REY_BOO
# 131 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 132 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_12
# 133 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 134 "data/maps/ReyBooRoom/scripts.pory"
	call ReyBooRoom_EventScript_ReyBooBattle
# 135 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 136 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_13
# 137 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 138 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_14
# 139 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 140 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_8, speaker = SP_NAME_REY_BOO
# 141 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 142 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 143 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 144 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 145 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_15
# 146 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 147 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 148 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_15
# 149 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 150 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_RG_CARD_FLIPPING
# 151 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 152 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 153 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 154 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_RG_CARD_FLIPPING
# 155 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 156 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 157 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 158 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 159 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 160 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 161 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 162 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 163 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 164 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 165 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 166 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 167 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE_TOP
# 168 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 169 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 170 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 171 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 172 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 173 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 174 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 175 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 176 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 177 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 178 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_16
# 179 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 180 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 181 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 182 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_17
# 183 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 184 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 185 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 186 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 187 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_18
# 188 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 189 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 190 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 191 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 192 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 193 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 194 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 195 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 196 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 197 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 198 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 199 "data/maps/ReyBooRoom/scripts.pory"
	release
	end

ReyBooRoom_EventScript_BooEncounter_3:
# 106 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_4:
# 108 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_5:
# 110 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_6:
# 112 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto ReyBooRoom_EventScript_BooEncounter_1


ReyBooRoom_EventScript_ReyBooBattle::
# 204 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReyBooRoom_EventScript_ReyBooBattle_2
# 207 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REYBOO
# 208 "data/maps/ReyBooRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 209 "data/maps/ReyBooRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReyBooRoom_EventScript_ReyBooBattle_5
# 212 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE, ReyBooRoom_Text_ReyBooDefeated
ReyBooRoom_EventScript_ReyBooBattle_1:
# 215 "data/maps/ReyBooRoom/scripts.pory"
	special HealPlayerParty
	return

ReyBooRoom_EventScript_ReyBooBattle_2:
# 205 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1

ReyBooRoom_EventScript_ReyBooBattle_5:
# 210 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1


# 35 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 35 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
	step_end

# 45 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 45 "data/maps/ReyBooRoom/scripts.pory"
	emote_thinking
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 45 "data/maps/ReyBooRoom/scripts.pory"
	face_left
	step_end

# 52 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 52 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
	step_end

# 58 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 58 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 58 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 63 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 63 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 63 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 63 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 63 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 71 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 72 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
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
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 77 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 82 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 84 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 86 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 86 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 87 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 87 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 87 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 87 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 88 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 88 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 89 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 89 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 89 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 89 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 90 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 90 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 92 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 92 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 92 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 93 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 93 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 94 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 97 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 97 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 97 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 98 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 98 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 98 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 98 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 98 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 98 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 116 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 116 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 116 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 116 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 116 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 116 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 116 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 119 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 119 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 119 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 119 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 119 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 126 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 126 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 126 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 126 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 132 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_12:
# 132 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
	step_end

# 136 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_13:
# 136 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
	step_end

# 138 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_14:
# 138 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 138 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 138 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 138 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 138 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 145 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_15:
# 145 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_down
	step_end

# 178 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_16:
# 178 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 178 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 178 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 178 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 178 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 178 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 182 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_17:
# 182 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
	step_end

# 187 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_18:
# 187 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 187 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 33 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 41 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 47 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 60 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 118 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 120 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 125 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 130 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 140 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 143 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 167 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 170 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 176 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 181 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 185 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"

ReyBooRoom_Text_ReyBooDefeated::
# 219 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"
