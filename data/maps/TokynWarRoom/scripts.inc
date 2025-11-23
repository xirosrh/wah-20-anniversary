TokynWarRoom_MapScripts::
	.byte 0


TokynWarRoom_EventScript_MainCutscene::
# 5 "data/maps/TokynWarRoom/scripts.pory"
	lockall
# 6 "data/maps/TokynWarRoom/scripts.pory"
	moveobjecttopos LOCALID_PLAYER, 6, 7, DIR_NORTH
# 7 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 8 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 9 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_SurpriseWithDelay48
# 10 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_0
# 11 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 12 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_0, MSGBOX_AUTOCLOSE
# 13 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 14 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_1
# 15 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 16 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_1
# 17 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_2
# 19 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_2, MSGBOX_AUTOCLOSE
# 20 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 21 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 22 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 23 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_3, MSGBOX_AUTOCLOSE
# 24 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HappyWithDelay48
# 26 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 27 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_4, MSGBOX_AUTOCLOSE
# 28 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_JumpInPlaceLeft2
# 29 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 30 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_5, MSGBOX_AUTOCLOSE
# 31 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 32 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkRight
# 33 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 34 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_ThinkingWithDelay48
# 35 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_6, MSGBOX_AUTOCLOSE
# 36 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkInPlaceLeft
# 37 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 38 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 39 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 40 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_7, MSGBOX_AUTOCLOSE
# 41 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 42 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 43 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_8, MSGBOX_AUTOCLOSE
# 44 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 45 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkLeft
# 46 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 47 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_9, MSGBOX_AUTOCLOSE
# 48 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 49 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 50 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_4
# 51 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_PLAYER, TokynWarRoom_EventScript_MainCutscene_Movement_5
# 52 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement LOCALID_TOKYNWARROOM_WAR
# 53 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_11
# 54 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 55 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_6
# 56 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_7
# 57 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 59 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 60 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_12, MSGBOX_AUTOCLOSE
# 61 "data/maps/TokynWarRoom/scripts.pory"
	delay 40
# 62 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkRight
# 63 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 64 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_13, MSGBOX_AUTOCLOSE
# 65 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 66 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 67 "data/maps/TokynWarRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 68 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_14, MSGBOX_AUTOCLOSE
# 69 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 70 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 71 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 72 "data/maps/TokynWarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 73 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TOKYN_WAR_ROOM_STATE, 2
# 74 "data/maps/TokynWarRoom/scripts.pory"
	releaseall
	return


TokynWarRoom_EventScript_War::
# 79 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 80 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 81 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TOKYN_WAR_ROOM_STATE, 0
	goto_if_eq TokynWarRoom_EventScript_War_2
# 86 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_War_Text_0
# 87 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 88 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_XDWithDelay48
# 89 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_War_2:
# 82 "data/maps/TokynWarRoom/scripts.pory"
	release
# 83 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_Tokyn::
# 94 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 95 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 96 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TOKYN_WAR_ROOM_STATE, 0
	goto_if_eq TokynWarRoom_EventScript_Tokyn_2
# 101 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_0
# 102 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 103 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 104 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_1
# 105 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_Tokyn_2:
# 97 "data/maps/TokynWarRoom/scripts.pory"
	release
# 98 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_Magikarp::
# 111 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 112 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 70, 55, VAR_TEMP_2
# 113 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 134, 55, VAR_TEMP_3
# 114 "data/maps/TokynWarRoom/scripts.pory"
	delay 100
# 115 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_LEFT, VAR_TEMP_2
# 116 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_RIGHT, VAR_TEMP_3
# 117 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TOKYN_WAR_ROOM_STATE, 1
# 118 "data/maps/TokynWarRoom/scripts.pory"
	release
	end


# 10 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_0:
# 10 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 10 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 10 "data/maps/TokynWarRoom/scripts.pory"
	face_right
	step_end

# 14 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_1:
# 14 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 14 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 14 "data/maps/TokynWarRoom/scripts.pory"
	face_left
	step_end

# 18 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_2:
# 18 "data/maps/TokynWarRoom/scripts.pory"
	emote_exclamation_mark
# 18 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 18 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 18 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 49 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_3:
# 49 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 49 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 49 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 49 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 50 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_4:
# 50 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 50 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 50 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 50 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 51 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_5:
# 51 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 51 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 51 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 51 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 51 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 51 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 51 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 51 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
	step_end

# 55 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_6:
# 55 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 55 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
# 55 "data/maps/TokynWarRoom/scripts.pory"
	jump_left
# 55 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 55 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 55 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_7:
# 56 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 56 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
# 56 "data/maps/TokynWarRoom/scripts.pory"
	jump_right
# 56 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 56 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 56 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 59 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_8:
# 59 "data/maps/TokynWarRoom/scripts.pory"
	emote_double_exclamation_mark
# 59 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 59 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 59 "data/maps/TokynWarRoom/scripts.pory"
	walk_left
	step_end

# 69 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_9:
# 69 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 69 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 69 "data/maps/TokynWarRoom/scripts.pory"
	face_down
	step_end

TokynWarRoom_EventScript_MainCutscene_Text_0:
# 12 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vaya sorpresa! No esperaba ver una\n"
	.string "cara nueva por aquí.$"

TokynWarRoom_EventScript_MainCutscene_Text_1:
# 16 "data/maps/TokynWarRoom/scripts.pory"
	.string "Yo tampoco tengo idea de quién eres,\n"
	.string "pero eso no importa.$"

TokynWarRoom_EventScript_MainCutscene_Text_2:
# 19 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Estamos aquí para verlo!$"

TokynWarRoom_EventScript_MainCutscene_Text_3:
# 23 "data/maps/TokynWarRoom/scripts.pory"
	.string "Es un placer poder participar de esta\n"
	.string "celebración contigo.$"

TokynWarRoom_EventScript_MainCutscene_Text_4:
# 27 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Qué te parece un combate de a dos,\n"
	.string "War?$"

TokynWarRoom_EventScript_MainCutscene_Text_5:
# 30 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Unir fuerzas como en los viejos\n"
	.string "tiempos?$"

TokynWarRoom_EventScript_MainCutscene_Text_6:
# 35 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Hace años no hacemos eso! Pero me\n"
	.string "gusta. Una buena celebración merece\l"
	.string "algo especial.$"

TokynWarRoom_EventScript_MainCutscene_Text_7:
# 40 "data/maps/TokynWarRoom/scripts.pory"
	.string "Entonces está decidido.$"

TokynWarRoom_EventScript_MainCutscene_Text_8:
# 43 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vamos!$"

TokynWarRoom_EventScript_MainCutscene_Text_9:
# 47 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Que gane el mejor!$"

TokynWarRoom_EventScript_MainCutscene_Text_10:
# 53 "data/maps/TokynWarRoom/scripts.pory"
	.string "Qué bien se sintió este combate… hacía\n"
	.string "tiempo que no disfrutaba uno así.$"

TokynWarRoom_EventScript_MainCutscene_Text_11:
# 53 "data/maps/TokynWarRoom/scripts.pory"
	.string "Bueno… ahora sí sé quién eres. Vaya\n"
	.string "forma de presentarte.$"

TokynWarRoom_EventScript_MainCutscene_Text_12:
# 60 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Pero qué locura de combate! Hoy sí que\n"
	.string "nos diste trabajo en serio.$"

TokynWarRoom_EventScript_MainCutscene_Text_13:
# 64 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por compartir este momento con\n"
	.string "nosotros. Fue un encuentro digno para\l"
	.string "esta celebración.\p"
	.string "Es increíble cómo un solo combate\n"
	.string "puede traer de vuelta tantas memorias.$"

TokynWarRoom_EventScript_MainCutscene_Text_14:
# 68 "data/maps/TokynWarRoom/scripts.pory"
	.string "Ya puedes seguir, pero recuerda: Nunca\n"
	.string "olvides seguir tus sueños.$"

TokynWarRoom_EventScript_War_Text_0:
# 86 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Quieres otra? ¡Ni loco!\p"
	.string "Tokyn me tira charla motivadora si\n"
	.string "pierdo dos veces seguidas.\p"
	.string "Pero estuvo buenísimo, eh.$"

TokynWarRoom_EventScript_Tokyn_Text_0:
# 101 "data/maps/TokynWarRoom/scripts.pory"
	.string "Me alegra muchísimo haber sido\n"
	.string "convocado para esta celebración.\p"
	.string "Estar acá, compartir un combate así… me\n"
	.string "trajo muy buenos recuerdos.$"

TokynWarRoom_EventScript_Tokyn_Text_1:
# 104 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por hacerlo especial.$"
