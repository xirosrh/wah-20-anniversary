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
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_0
# 13 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight2
# 14 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_1, MSGBOX_AUTOCLOSE
# 15 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 16 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 17 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_ThinkingWithDelay48
# 18 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 19 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceRight2
# 20 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_2, MSGBOX_AUTOCLOSE
# 21 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 22 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkRight
# 23 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 24 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_0
# 26 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_3, MSGBOX_AUTOCLOSE
# 27 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 28 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_HELP, FALSE
# 29 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_WalkInPlaceLeft
# 30 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceRight
# 31 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, Common_Movement_JumpInPlaceLeft
# 32 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 33 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_1
# 46 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_2
# 57 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/ReyBooRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 59 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_3
# 60 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_VIGOROTH, ReyBooRoom_EventScript_BooEncounter_Movement_4
# 61 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement LOCALID_REYBOOROOM_VIGOROTH
# 62 "data/maps/ReyBooRoom/scripts.pory"
	fadedefaultbgm
# 63 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 64 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_REYBOOROOM_HIDE_VIGOROTH
# 65 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_VIGOROTH
# 66 "data/maps/ReyBooRoom/scripts.pory"
	moveobjecttopos LOCALID_PLAYER, 6, 8, DIR_NORTH
# 67 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/ReyBooRoom/scripts.pory"
	delay 30
# 69 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_5
# 70 "data/maps/ReyBooRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 71 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_4, MSGBOX_AUTOCLOSE
# 72 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_6
# 73 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_5, MSGBOX_AUTOCLOSE
# 74 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_FaceDown
# 75 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ExclamationMarkWithDelay48
# 77 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_6, MSGBOX_AUTOCLOSE
# 78 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 79 "data/maps/ReyBooRoom/scripts.pory"
	applymovement LOCALID_CAMERA, ReyBooRoom_EventScript_BooEncounter_Movement_7
# 80 "data/maps/ReyBooRoom/scripts.pory"
	waitmovement 0
# 81 "data/maps/ReyBooRoom/scripts.pory"
	special RemoveCameraObject
# 82 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_7
# 83 "data/maps/ReyBooRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REYBOO_MAIN, ReyBooRoom_EventScript_BooEncounter_Text_8
# 84 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, ReyBooRoom_EventScript_BooEncounter_Movement_8
# 85 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_9
# 86 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_WEATHER_GROUDON, FALSE
# 87 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_WalkInPlaceDown
# 88 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_10, MSGBOX_AUTOCLOSE
# 89 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_JumpInPlaceDown2
# 90 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 91 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 92 "data/maps/ReyBooRoom/scripts.pory"
	delay 10
# 93 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 94 "data/maps/ReyBooRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 95 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 96 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 97 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8006, 6
# 98 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 99 "data/maps/ReyBooRoom/scripts.pory"
	special ShakeCamera
# 100 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 101 "data/maps/ReyBooRoom/scripts.pory"
	fadeoutbgm 1
# 102 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 103 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_FAILURE
# 104 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_11, MSGBOX_AUTOCLOSE_TOP
# 105 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_PIN
# 106 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_XWithDelay48
# 107 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_12
# 108 "data/maps/ReyBooRoom/scripts.pory"
	delay 20
# 109 "data/maps/ReyBooRoom/scripts.pory"
	turnobject LOCALID_REYBOOROOM_BOO, DIR_NORTH
# 110 "data/maps/ReyBooRoom/scripts.pory"
	applymovementandwait LOCALID_REYBOOROOM_BOO, Common_Movement_ThinkingWithDelay48
# 111 "data/maps/ReyBooRoom/scripts.pory"
	msgbox ReyBooRoom_EventScript_BooEncounter_Text_13
# 118 "data/maps/ReyBooRoom/scripts.pory"
	playse SE_CONTEST_CONDITION_LOSE
# 119 "data/maps/ReyBooRoom/scripts.pory"
	waitse
# 120 "data/maps/ReyBooRoom/scripts.pory"
	playbgm MUS_CONTEST_RESULTS, FALSE
# 121 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_REYBOOROOM_HIDE_BOO
# 122 "data/maps/ReyBooRoom/scripts.pory"
	removeobject LOCALID_REYBOOROOM_BOO
# 123 "data/maps/ReyBooRoom/scripts.pory"
	setvar VAR_REY_BOO_ROOM_STATE, 1
# 124 "data/maps/ReyBooRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 125 "data/maps/ReyBooRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REY_BOO
# 126 "data/maps/ReyBooRoom/scripts.pory"
	release
	end


# 25 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_0:
# 25 "data/maps/ReyBooRoom/scripts.pory"
	emote_angry
# 25 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 25 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_right
# 25 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
	step_end

# 33 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_1:
# 34 "data/maps/ReyBooRoom/scripts.pory"
	emote_surprise
# 35 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 35 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 36 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 36 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 37 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 37 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 37 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 37 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 38 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 38 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 39 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 40 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 41 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 42 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 42 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 42 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 43 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 43 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 44 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
	step_end

# 46 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_2:
# 47 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 47 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 47 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 47 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 48 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 48 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 49 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 50 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 50 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 51 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 52 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 52 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_down
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 53 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_right
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 54 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 55 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_left
# 56 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
	step_end

# 59 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_3:
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 59 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_up
# 59 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 60 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_4:
# 60 "data/maps/ReyBooRoom/scripts.pory"
	delay_16
# 60 "data/maps/ReyBooRoom/scripts.pory"
	jump_in_place_up
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_faster_up
# 60 "data/maps/ReyBooRoom/scripts.pory"
	walk_in_place_up
# 60 "data/maps/ReyBooRoom/scripts.pory"
	set_invisible
	step_end

# 69 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_5:
# 69 "data/maps/ReyBooRoom/scripts.pory"
	face_down
# 69 "data/maps/ReyBooRoom/scripts.pory"
	set_visible
# 69 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 69 "data/maps/ReyBooRoom/scripts.pory"
	delay_8
# 69 "data/maps/ReyBooRoom/scripts.pory"
	face_up
	step_end

# 72 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_6:
# 72 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 72 "data/maps/ReyBooRoom/scripts.pory"
	face_up
	step_end

# 78 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_7:
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
# 78 "data/maps/ReyBooRoom/scripts.pory"
	walk_down
	step_end

# 84 "data/maps/ReyBooRoom/scripts.pory"
ReyBooRoom_EventScript_BooEncounter_Movement_8:
# 84 "data/maps/ReyBooRoom/scripts.pory"
	lock_facing_direction
# 84 "data/maps/ReyBooRoom/scripts.pory"
	jump_up
# 84 "data/maps/ReyBooRoom/scripts.pory"
	unlock_facing_direction
	step_end

ReyBooRoom_EventScript_BooEncounter_Text_0:
# 12 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Esta es la mejor idea del mundo, con\n"
	.string "esto podré jubilarme, yupi!\p"
	.string "¡Vamos a ello!$"

ReyBooRoom_EventScript_BooEncounter_Text_1:
# 14 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Adelante, usa Día de Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_2:
# 20 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Vamos, saca tu energía cósmica, Día de\n"
	.string "Pago!$"

ReyBooRoom_EventScript_BooEncounter_Text_3:
# 26 "data/maps/ReyBooRoom/scripts.pory"
	.string "Maldito mono…$"

ReyBooRoom_EventScript_BooEncounter_Text_4:
# 71 "data/maps/ReyBooRoom/scripts.pory"
	.string "Menos mal.$"

ReyBooRoom_EventScript_BooEncounter_Text_5:
# 73 "data/maps/ReyBooRoom/scripts.pory"
	.string "Madre mía, qué mala bestia…$"

ReyBooRoom_EventScript_BooEncounter_Text_6:
# 77 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Ejem…!$"

ReyBooRoom_EventScript_BooEncounter_Text_7:
# 82 "data/maps/ReyBooRoom/scripts.pory"
	.string "De modo que eres tú quien me ha\n"
	.string "invocado…$"

ReyBooRoom_EventScript_BooEncounter_Text_8:
# 83 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Madre mía!$"

ReyBooRoom_EventScript_BooEncounter_Text_9:
# 85 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien, has pasado la prueba física…\n"
	.string "Ahora prepárate para la inesperada…$"

ReyBooRoom_EventScript_BooEncounter_Text_10:
# 88 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Mis fenomenales poderes!$"

ReyBooRoom_EventScript_BooEncounter_Text_11:
# 104 "data/maps/ReyBooRoom/scripts.pory"
	.string "Batería baja {DOWN_ARROW}$"

ReyBooRoom_EventScript_BooEncounter_Text_12:
# 107 "data/maps/ReyBooRoom/scripts.pory"
	.string "¡Maldita sea!$"

ReyBooRoom_EventScript_BooEncounter_Text_13:
# 111 "data/maps/ReyBooRoom/scripts.pory"
	.string "Muy bien…$"
