AngelRoom_MapScripts::
	.byte 0


AngelRoom_EventScript_Angel::
# 5 "data/maps/AngelRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_ANGEL, AngelRoom_EventScript_Angel_2
# 10 "data/maps/AngelRoom/scripts.pory"
	lock
# 11 "data/maps/AngelRoom/scripts.pory"
	faceplayer
# 12 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 13 "data/maps/AngelRoom/scripts.pory"
	applymovement LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_0
# 19 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_1, MSGBOX_AUTOCLOSE
# 20 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 21 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 22 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_2, MSGBOX_AUTOCLOSE
# 23 "data/maps/AngelRoom/scripts.pory"
	delay 10
# 24 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_HappyWithDelay48
# 26 "data/maps/AngelRoom/scripts.pory"
	waitse
# 27 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 28 "data/maps/AngelRoom/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_TEMP_0
# 29 "data/maps/AngelRoom/scripts.pory"
	switch VAR_TEMP_0
# 30 "data/maps/AngelRoom/scripts.pory"
	case DIR_NORTH, AngelRoom_EventScript_Angel_6
# 33 "data/maps/AngelRoom/scripts.pory"
	case DIR_SOUTH, AngelRoom_EventScript_Angel_7
# 36 "data/maps/AngelRoom/scripts.pory"
	case DIR_WEST, AngelRoom_EventScript_Angel_8
# 39 "data/maps/AngelRoom/scripts.pory"
	case DIR_EAST, AngelRoom_EventScript_Angel_9
AngelRoom_EventScript_Angel_4:
# 43 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_3, MSGBOX_AUTOCLOSE
# 44 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/AngelRoom/scripts.pory"
	switch VAR_TEMP_0
# 46 "data/maps/AngelRoom/scripts.pory"
	case DIR_NORTH, AngelRoom_EventScript_Angel_12
# 49 "data/maps/AngelRoom/scripts.pory"
	case DIR_SOUTH, AngelRoom_EventScript_Angel_13
# 52 "data/maps/AngelRoom/scripts.pory"
	case DIR_WEST, AngelRoom_EventScript_Angel_14
# 55 "data/maps/AngelRoom/scripts.pory"
	case DIR_EAST, AngelRoom_EventScript_Angel_15
AngelRoom_EventScript_Angel_10:
# 59 "data/maps/AngelRoom/scripts.pory"
	waitse
# 60 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_4
# 62 "data/maps/AngelRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AngelRoom_EventScript_Angel_17
# 65 "data/maps/AngelRoom/scripts.pory"
	setvar VAR_0x8004, 7
# 66 "data/maps/AngelRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 67 "data/maps/AngelRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AngelRoom_EventScript_Angel_20
# 70 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_ALTERNATIVE, AngelRoom_EventScript_Angel_Text_5
AngelRoom_EventScript_Angel_16:
# 73 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 74 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/AngelRoom/scripts.pory"
	applymovement LOCALID_ANGELROOM_ANGEL, Common_Movement_ExclamationMarkWithDelay48
# 76 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_6, MSGBOX_AUTOCLOSE
# 77 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 78 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 79 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_7, MSGBOX_AUTOCLOSE
# 80 "data/maps/AngelRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 81 "data/maps/AngelRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_ANGEL
# 82 "data/maps/AngelRoom/scripts.pory"
	release
	end

AngelRoom_EventScript_Angel_2:
# 6 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_0, MSGBOX_NPC
# 7 "data/maps/AngelRoom/scripts.pory"
	release
	end

AngelRoom_EventScript_Angel_6:
# 31 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkUp2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_7:
# 34 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkDown2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_8:
# 37 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkLeft2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_9:
# 40 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkRight2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_12:
# 47 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_1
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_13:
# 50 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_2
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_14:
# 53 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_3
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_15:
# 56 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_4
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_17:
# 63 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_MAIN, AngelRoom_EventScript_Angel_Text_5
	goto AngelRoom_EventScript_Angel_16

AngelRoom_EventScript_Angel_20:
# 68 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_MAIN, AngelRoom_EventScript_Angel_Text_5
	goto AngelRoom_EventScript_Angel_16


# 13 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_0:
# 14 "data/maps/AngelRoom/scripts.pory"
	emote_double_exclamation_mark
# 15 "data/maps/AngelRoom/scripts.pory"
	lock_facing_direction
# 16 "data/maps/AngelRoom/scripts.pory"
	jump_in_place_down
# 17 "data/maps/AngelRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 47 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_1:
# 47 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 47 "data/maps/AngelRoom/scripts.pory"
	jump_2_down
# 47 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 47 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 50 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_2:
# 50 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 50 "data/maps/AngelRoom/scripts.pory"
	jump_2_up
# 50 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 50 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 53 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_3:
# 53 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 53 "data/maps/AngelRoom/scripts.pory"
	jump_2_right
# 53 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 53 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_4:
# 56 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 56 "data/maps/AngelRoom/scripts.pory"
	jump_2_left
# 56 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 56 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

AngelRoom_EventScript_Angel_Text_0:
# 6 "data/maps/AngelRoom/scripts.pory"
	.string "¡Me alegro de verte de nuevo! Espero\n"
	.string "que sigas siendo tan fuerte como la\l"
	.string "última vez.$"

AngelRoom_EventScript_Angel_Text_1:
# 19 "data/maps/AngelRoom/scripts.pory"
	.string "¡Cuánto tiempo!$"

AngelRoom_EventScript_Angel_Text_2:
# 22 "data/maps/AngelRoom/scripts.pory"
	.string "Ha pasado mucho desde la última vez,\n"
	.string "¿verdad?\p"
	.string "Espero que este reencuentro… ¡SEA\n"
	.string "MEMORABLE!$"

AngelRoom_EventScript_Angel_Text_3:
# 43 "data/maps/AngelRoom/scripts.pory"
	.string "Veamos tu potencial.$"

AngelRoom_EventScript_Angel_Text_4:
# 60 "data/maps/AngelRoom/scripts.pory"
	.string "¡Ven! ¡Atácame con todo lo que tengas!$"

AngelRoom_EventScript_Angel_Text_5:
# 63 "data/maps/AngelRoom/scripts.pory"
	.string "¿Así que este es el poder de la nueva\n"
	.string "generación?$"

AngelRoom_EventScript_Angel_Text_6:
# 76 "data/maps/AngelRoom/scripts.pory"
	.string "¡Increíble! ¡El poder de la nueva\n"
	.string "generación es asombroso!$"

AngelRoom_EventScript_Angel_Text_7:
# 79 "data/maps/AngelRoom/scripts.pory"
	.string "No esperaba perder y aún así, no me\n"
	.string "dejaste opciones.\p"
	.string "Dejo en tus manos el legado de toda mi\n"
	.string "generación. ¡Espero de verdad que\l"
	.string "volvamos a encontrarnos algún día y\l"
	.string "poder volver a pelear juntos!$"
