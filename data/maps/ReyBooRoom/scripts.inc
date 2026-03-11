ReyBooRoom_MapScripts::
# 9 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ReyBooRoom_OnLoad
# 10 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ReyBooRoom_OnTransition
# 6 "data/maps/ReyBooRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ReyBooRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/ReyBooRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ReyBooRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ReyBooRoom_OnLoad::
# 15 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REY_BOO, ReyBooRoom_OnLoad_2
ReyBooRoom_OnLoad_1:
	end

ReyBooRoom_OnLoad_2:
# 16 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ReyBooRoom_OnLoad_1


ReyBooRoom_OnWarp_PlayerTurnNorth::
# 22 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ReyBooRoom_OnTransition::
# 27 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_ReyBoo
	end


ReyBooRoom_EventScript_BooEncounter::
# 32 "data/maps/ReyBooRoom/scripts.pory"
	lock
# 33 "data/maps/ReyBooRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 34 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/ReyBooRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 36 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 37 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 38 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_IdeaWithDelay48
# 39 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 40 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 41 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 42 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 43 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 44 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 45 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 46 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 47 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 48 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 49 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_VIGOROTH, DIR_SOUTH
# 50 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 52 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 53 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 54 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 55 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 56 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 57 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 58 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 59 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 60 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 61 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 62 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 63 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 64 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 65 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 66 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 67 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 68 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 70 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 71 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 72 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 73 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 74 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 76 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 77 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 90 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 101 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 102 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 103 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 104 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 105 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 106 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 107 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 108 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 109 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 110 "data/maps/ReyBooRoom/scripts.pory"
	switch VAR_TEMP_0
# 111 "data/maps/ReyBooRoom/scripts.pory"
	case 4, ReyBooRoom_EventScript_BooEncounter_3
# 113 "data/maps/ReyBooRoom/scripts.pory"
	case 5, ReyBooRoom_EventScript_BooEncounter_4
# 115 "data/maps/ReyBooRoom/scripts.pory"
	case 7, ReyBooRoom_EventScript_BooEncounter_5
# 117 "data/maps/ReyBooRoom/scripts.pory"
	case 8, ReyBooRoom_EventScript_BooEncounter_6
ReyBooRoom_EventScript_BooEncounter_1:
# 120 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 121 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 122 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 123 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 124 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 125 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 126 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 127 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 128 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 129 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 130 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 131 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 132 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 133 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 134 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 135 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 136 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7, speaker = SP_NAME_REY_BOO
# 137 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_12
# 139 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 140 "data/maps/ReyBooRoom/scripts.pory"
	call ReyBooRoom_EventScript_ReyBooBattle
# 141 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 142 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_13
# 143 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 144 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_14
# 145 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 146 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_8, speaker = SP_NAME_REY_BOO
# 147 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 148 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 149 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 150 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 151 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_15
# 152 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 153 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_LEDGE
# 154 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_15
# 155 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 156 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_RG_CARD_FLIPPING
# 157 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 158 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 159 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 160 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_RG_CARD_FLIPPING
# 161 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 162 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 163 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 164 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 165 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 166 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 167 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 168 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 169 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 170 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 171 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 172 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 173 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE_TOP
# 174 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 175 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 176 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 177 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 178 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 179 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 180 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 181 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 182 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 183 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 184 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_16
# 185 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 186 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 187 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 188 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_17
# 189 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 190 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 191 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REY_BOO
# 192 "data/maps/ReyBooRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 193 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_18
# 194 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 195 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 196 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 197 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 198 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 199 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 200 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 201 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 202 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_TEMP_2, 1
# 203 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 204 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 205 "data/maps/ReyBooRoom/scripts.pory"
	release
	end

ReyBooRoom_EventScript_BooEncounter_3:
# 112 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_4:
# 114 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_5:
# 116 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto ReyBooRoom_EventScript_BooEncounter_1

ReyBooRoom_EventScript_BooEncounter_6:
# 118 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto ReyBooRoom_EventScript_BooEncounter_1


ReyBooRoom_EventScript_ReyBooBattle::
# 210 "data/maps/ReyBooRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReyBooRoom_EventScript_ReyBooBattle_2
# 213 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REYBOO
# 214 "data/maps/ReyBooRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 215 "data/maps/ReyBooRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReyBooRoom_EventScript_ReyBooBattle_5
# 218 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE, ReyBooRoom_Text_ReyBooDefeated
ReyBooRoom_EventScript_ReyBooBattle_1:
# 221 "data/maps/ReyBooRoom/scripts.pory"
	special HealPlayerParty
	return

ReyBooRoom_EventScript_ReyBooBattle_2:
# 211 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1

ReyBooRoom_EventScript_ReyBooBattle_5:
# 216 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_Text_ReyBooDefeated
	goto ReyBooRoom_EventScript_ReyBooBattle_1


# 41 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 41 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
	step_end

# 51 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 51 "data/maps/ReyBooRoom/scripts.pory"
	emote_thinking
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	face_left
	step_end

# 58 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 58 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
	step_end

# 64 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 64 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 64 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 69 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 69 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 69 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 69 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 77 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 78 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 79 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 81 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 82 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 82 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 83 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 83 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 83 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 83 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 84 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 84 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 85 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 86 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 86 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 86 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 87 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 87 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 88 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 90 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 91 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 92 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 92 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 93 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 93 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 93 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 93 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 94 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 94 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 95 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 95 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 95 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 95 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 96 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 96 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 97 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 97 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 97 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 97 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 98 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 98 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 98 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 99 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 99 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 100 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 103 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 103 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 103 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 104 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 104 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 104 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 104 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 104 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 104 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 122 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 122 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 122 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 122 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 122 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 122 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 122 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 125 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 125 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 125 "data/maps/ReyBooRoom/scripts.pory"
	face_up
# 125 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 125 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 132 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 132 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 132 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 132 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 138 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_12:
# 138 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
	step_end

# 142 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_13:
# 142 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
	step_end

# 144 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_14:
# 144 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 144 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 144 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 144 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 144 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 151 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_15:
# 151 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_down
	step_end

# 184 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_16:
# 184 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 184 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 184 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
# 184 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 184 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 184 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 188 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_17:
# 188 "data/maps/ReyBooRoom/scripts.pory"
	walk_slow_up
	step_end

# 193 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_18:
# 193 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 193 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 39 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 47 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 53 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 66 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 124 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 126 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 131 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 136 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 146 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 149 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 173 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 176 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 182 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 187 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 191 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"

ReyBooRoom_Text_ReyBooDefeated::
# 225 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"
