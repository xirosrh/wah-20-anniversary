ReyBooRoom_MapScripts::
	.byte 0


ReyBooRoom_EventScript_BooEncounter::
# 6 "data/maps/ReyBooRoom/scripts.pory"
	lock
# 7 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 8 "data/maps/ReyBooRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 9 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 10 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 11 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_IdeaWithDelay48
# 12 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_0, MSGBOX_AUTOCLOSE
# 13 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight2
# 14 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 15 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE
# 16 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 17 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_ThinkingWithDelay48
# 19 "data/maps/ReyBooRoom/scripts.pory"
	delay 40
# 20 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 21 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE
# 22 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 23 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 24 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 25 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 26 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 27 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE
# 28 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 29 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 30 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 31 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 32 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 33 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 34 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 35 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 48 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 59 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 60 "data/maps/ReyBooRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 61 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 62 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 63 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 64 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 65 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 66 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_REYBOOROOM_HIDE_VIGOROTH
# 67 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 68 "data/maps/ReyBooRoom/scripts.pory"
	moveobjecttopos LOCALID_PLAYER, 6, 8, DIR_NORTH
# 69 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 71 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 72 "data/maps/ReyBooRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 73 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE
# 74 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 75 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE
# 76 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 77 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 79 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE
# 80 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 81 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 82 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 83 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 84 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7
# 85 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_EventScript_BooEncounter_Text_8
# 86 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_9
# 87 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 88 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9
# 89 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 90 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 91 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE
# 92 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceDown2
# 93 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 94 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 95 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 96 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 97 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 98 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 99 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 100 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 101 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 102 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 103 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 104 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 105 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 106 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 107 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE_TOP
# 108 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 109 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 110 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12, MSGBOX_AUTOCLOSE
# 111 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 112 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 113 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 114 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 115 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 116 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13, MSGBOX_AUTOCLOSE
# 117 "data/maps/ReyBooRoom/scripts.pory"
	special SpawnCameraObject
# 118 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_10
# 119 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp3
# 120 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 121 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_14, MSGBOX_AUTOCLOSE
# 122 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkUp
# 123 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 124 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_SOUTH
# 125 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_15, MSGBOX_AUTOCLOSE
# 126 "data/maps/ReyBooRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 127 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_11
# 128 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 129 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 130 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 131 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_REYBOOROOM_HIDE_BOO
# 132 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 133 "data/maps/ReyBooRoom/scripts.pory"
	delay 50
# 134 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkDown3
# 135 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 136 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_REY_BOO_ROOM_STATE, 1
# 137 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 138 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 139 "data/maps/ReyBooRoom/scripts.pory"
	release
	end


# 26 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 26 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
# 26 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 26 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 26 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 30 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 30 "data/maps/ReyBooRoom/scripts.pory"
	emote_versus
# 30 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_left
# 30 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 30 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 35 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 36 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 37 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 37 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 38 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 38 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 42 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 42 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 43 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 43 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 43 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 43 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 44 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 44 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 44 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 45 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 46 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 48 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 50 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 50 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 52 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 52 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 56 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 57 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 57 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 58 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 61 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 61 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 61 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 62 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 62 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 62 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 62 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 62 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 71 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 71 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 71 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 71 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 71 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 71 "data/maps/ReyBooRoom/scripts.pory"
	face_up
	step_end

# 74 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 74 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 74 "data/maps/ReyBooRoom/scripts.pory"
	face_up
	step_end

# 80 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 80 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 86 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_9:
# 86 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 86 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 86 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 86 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
# 86 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 86 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 118 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_10:
# 118 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 118 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 118 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 118 "data/maps/ReyBooRoom/scripts.pory"
	face_down
	step_end

# 127 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_11:
# 127 "data/maps/ReyBooRoom/scripts.pory"
	walk_up
# 127 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 12 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 15 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 21 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 27 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 73 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 75 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 79 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 84 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 85 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 88 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 91 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 107 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 110 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 116 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"

ReyBooRoom_EventScript_BooEncounter_Text_14:
# 121 "data/maps/ReyBooRoom/scripts.pory"
	.string "Por esta vez has ganado.$"

ReyBooRoom_EventScript_BooEncounter_Text_15:
# 125 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Volveré!$"
