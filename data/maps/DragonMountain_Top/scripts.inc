DragonMountain_Top_MapScripts::
	.byte 0


DragonMountan_Top_EventScript_Sergio::
# 5 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 6 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 7 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 8 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 9 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 10 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 11 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 12 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 13 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 14 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 15 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 16 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 18 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 19 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 20 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 21 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 22 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 23 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 24 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 25 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 26 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 27 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 28 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 29 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 30 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 33 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 34 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 35 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 36 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 37 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 38 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 39 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 40 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 41 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_1
# 50 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 51 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 52 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 54 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_2
# 64 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 65 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_EventScript_Sergio_Text_7
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_3
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 70 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 72 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 73 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 74 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 75 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 76 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 77 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_4
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 81 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_5
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_6
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_6
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_7
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_8
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	warp MAP_HALL_OF_FAME, WARP_ID_HALL_OF_FAME
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 110 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 17 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 41 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 42 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 43 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 44 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 45 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 46 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 48 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 63 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 68 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 79 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 87 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 89 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
	step_end

# 93 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	walk_in_place_down
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	set_invisible
	step_end

# 94 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_8:
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	walk_in_place_down
	step_end

DragonMountan_Top_EventScript_Sergio_Text_0:
# 7 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 13 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no ibamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 16 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 19 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco. Quién sabe… a lo mejor es\n"
	.string "que soy el mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 23 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 29 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?\n"
	.string "Admiro que hayas llegado hasta aquí, se\l"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí! Ha llegado el momento de\n"
	.string "combatir, y mis dragones no se\l"
	.string "contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Wow! ¡Eso ha sido brutal!$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes\n"
	.string "dormido, ¡que hay un montón de cosas\l"
	.string "por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	.string "TODO Frase sergio$"
