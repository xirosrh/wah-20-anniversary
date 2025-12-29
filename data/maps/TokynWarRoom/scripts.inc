TokynWarRoom_MapScripts::
	.byte 0


TokynWarRoom_EventScript_MainCutscene::
# 5 "data/maps/TokynWarRoom/scripts.pory"
	lockall
# 6 "data/maps/TokynWarRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 7 "data/maps/TokynWarRoom/scripts.pory"
	switch VAR_TEMP_0
# 8 "data/maps/TokynWarRoom/scripts.pory"
	case 4, TokynWarRoom_EventScript_MainCutscene_3
# 10 "data/maps/TokynWarRoom/scripts.pory"
	case 5, TokynWarRoom_EventScript_MainCutscene_4
# 12 "data/maps/TokynWarRoom/scripts.pory"
	case 7, TokynWarRoom_EventScript_MainCutscene_5
# 14 "data/maps/TokynWarRoom/scripts.pory"
	case 8, TokynWarRoom_EventScript_MainCutscene_6
TokynWarRoom_EventScript_MainCutscene_1:
# 17 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 18 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 19 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_SurpriseWithDelay48
# 20 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_0
# 21 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 22 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 23 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 24 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_1
# 25 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 26 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_1, speaker = SP_NAME_WAR
# 27 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_2
# 29 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 30 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 32 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 33 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 34 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HappyWithDelay48
# 36 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 37 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 38 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_JumpInPlaceLeft2
# 39 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 40 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 41 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 42 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkRight
# 43 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 44 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_ThinkingWithDelay48
# 45 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 46 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkInPlaceLeft
# 47 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 48 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 49 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 50 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 51 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 52 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 53 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 54 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 55 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkLeft
# 56 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 57 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 58 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 59 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 60 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_4
# 61 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_PLAYER, TokynWarRoom_EventScript_MainCutscene_Movement_5
# 62 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement LOCALID_TOKYNWARROOM_WAR
# 63 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_11
# 64 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 65 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_6
# 66 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_7
# 67 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 70 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 71 "data/maps/TokynWarRoom/scripts.pory"
	delay 40
# 72 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkRight
# 73 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 74 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 75 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 77 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 78 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 79 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 80 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 81 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/TokynWarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 83 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TOKYN_WAR_ROOM_STATE, 2
# 84 "data/maps/TokynWarRoom/scripts.pory"
	releaseall
	return

TokynWarRoom_EventScript_MainCutscene_3:
# 9 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight2
	goto TokynWarRoom_EventScript_MainCutscene_1

TokynWarRoom_EventScript_MainCutscene_4:
# 11 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkRight
	goto TokynWarRoom_EventScript_MainCutscene_1

TokynWarRoom_EventScript_MainCutscene_5:
# 13 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft
	goto TokynWarRoom_EventScript_MainCutscene_1

TokynWarRoom_EventScript_MainCutscene_6:
# 15 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkLeft2
	goto TokynWarRoom_EventScript_MainCutscene_1


TokynWarRoom_EventScript_War::
# 89 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 90 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 91 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TOKYN_WAR_ROOM_STATE, 0
	goto_if_eq TokynWarRoom_EventScript_War_2
# 96 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_War_Text_0, speaker = SP_NAME_WAR
# 97 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_XDWithDelay48
# 99 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_War_2:
# 92 "data/maps/TokynWarRoom/scripts.pory"
	release
# 93 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_Tokyn::
# 104 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 105 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 106 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TOKYN_WAR_ROOM_STATE, 0
	goto_if_eq TokynWarRoom_EventScript_Tokyn_2
# 111 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_0, speaker = SP_NAME_TOKYN
# 112 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 113 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 114 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_1, speaker = SP_NAME_TOKYN
# 115 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_Tokyn_2:
# 107 "data/maps/TokynWarRoom/scripts.pory"
	release
# 108 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_MagikarpJumping::
# 121 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 122 "data/maps/TokynWarRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 123 "data/maps/TokynWarRoom/scripts.pory"
	switch VAR_TEMP_0
# 124 "data/maps/TokynWarRoom/scripts.pory"
	case 5, TokynWarRoom_EventScript_MagikarpJumping_3
# 127 "data/maps/TokynWarRoom/scripts.pory"
	case 6, TokynWarRoom_EventScript_MagikarpJumping_4
# 130 "data/maps/TokynWarRoom/scripts.pory"
	case 7, TokynWarRoom_EventScript_MagikarpJumping_5
TokynWarRoom_EventScript_MagikarpJumping_1:
# 134 "data/maps/TokynWarRoom/scripts.pory"
	delay 70
# 135 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_LEFT, VAR_TEMP_2
# 136 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_RIGHT, VAR_TEMP_3
# 137 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 138 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 140 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TOKYN_WAR_ROOM_STATE, 1
# 141 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_MagikarpJumping_3:
# 125 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 102, 60, VAR_TEMP_2
# 126 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 166, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_4:
# 128 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 86, 60, VAR_TEMP_2
# 129 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 150, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_5:
# 131 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 70, 60, VAR_TEMP_2
# 132 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 134, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1


# 20 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_0:
# 20 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 20 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 20 "data/maps/TokynWarRoom/scripts.pory"
	face_right
	step_end

# 24 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_1:
# 24 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 24 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 24 "data/maps/TokynWarRoom/scripts.pory"
	face_left
	step_end

# 28 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_2:
# 28 "data/maps/TokynWarRoom/scripts.pory"
	emote_exclamation_mark
# 28 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 28 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 28 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 59 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_3:
# 59 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 59 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 59 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 59 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 60 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_4:
# 60 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 60 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 60 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 60 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 61 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_5:
# 61 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 61 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 61 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 61 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 61 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 61 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 61 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 61 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
	step_end

# 65 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_6:
# 65 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 65 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
# 65 "data/maps/TokynWarRoom/scripts.pory"
	jump_left
# 65 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 65 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 65 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 66 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_7:
# 66 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 66 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
# 66 "data/maps/TokynWarRoom/scripts.pory"
	jump_right
# 66 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 66 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 66 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 69 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_8:
# 69 "data/maps/TokynWarRoom/scripts.pory"
	emote_double_exclamation_mark
# 69 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 69 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 69 "data/maps/TokynWarRoom/scripts.pory"
	walk_left
	step_end

# 79 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_9:
# 79 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 79 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 79 "data/maps/TokynWarRoom/scripts.pory"
	face_down
	step_end

TokynWarRoom_EventScript_MainCutscene_Text_0:
# 22 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vaya sorpresa! No esperaba ver una\n"
	.string "cara nueva por aquí.$"

TokynWarRoom_EventScript_MainCutscene_Text_1:
# 26 "data/maps/TokynWarRoom/scripts.pory"
	.string "Yo tampoco tengo idea de quién eres,\n"
	.string "pero eso no importa.$"

TokynWarRoom_EventScript_MainCutscene_Text_2:
# 29 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Estamos aquí para verlo!$"

TokynWarRoom_EventScript_MainCutscene_Text_3:
# 33 "data/maps/TokynWarRoom/scripts.pory"
	.string "Es un placer poder participar de esta\n"
	.string "celebración contigo.$"

TokynWarRoom_EventScript_MainCutscene_Text_4:
# 37 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Qué te parece un combate de a dos,\n"
	.string "War?$"

TokynWarRoom_EventScript_MainCutscene_Text_5:
# 40 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Unir fuerzas como en los viejos\n"
	.string "tiempos?$"

TokynWarRoom_EventScript_MainCutscene_Text_6:
# 45 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Hace años no hacemos eso! Pero me\n"
	.string "gusta. Una buena celebración merece\l"
	.string "algo especial.$"

TokynWarRoom_EventScript_MainCutscene_Text_7:
# 50 "data/maps/TokynWarRoom/scripts.pory"
	.string "Entonces está decidido.$"

TokynWarRoom_EventScript_MainCutscene_Text_8:
# 53 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vamos!$"

TokynWarRoom_EventScript_MainCutscene_Text_9:
# 57 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Que gane el mejor!$"

TokynWarRoom_EventScript_MainCutscene_Text_10:
# 63 "data/maps/TokynWarRoom/scripts.pory"
	.string "Qué bien se sintió este combate… hacía\n"
	.string "tiempo que no disfrutaba uno así.$"

TokynWarRoom_EventScript_MainCutscene_Text_11:
# 63 "data/maps/TokynWarRoom/scripts.pory"
	.string "Bueno… ahora sí sé quién eres. Vaya\n"
	.string "forma de presentarte.$"

TokynWarRoom_EventScript_MainCutscene_Text_12:
# 70 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Pero qué locura de combate! Hoy sí que\n"
	.string "nos diste trabajo en serio.$"

TokynWarRoom_EventScript_MainCutscene_Text_13:
# 74 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por compartir este momento con\n"
	.string "nosotros. Fue un encuentro digno para\l"
	.string "esta celebración.\p"
	.string "Es increíble cómo un solo combate\n"
	.string "puede traer de vuelta tantas memorias.$"

TokynWarRoom_EventScript_MainCutscene_Text_14:
# 78 "data/maps/TokynWarRoom/scripts.pory"
	.string "Ya puedes seguir, pero recuerda: Nunca\n"
	.string "olvides seguir tus sueños.$"

TokynWarRoom_EventScript_War_Text_0:
# 96 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Quieres otra? ¡Ni loco!\p"
	.string "Tokyn me tira charla motivadora si\n"
	.string "pierdo dos veces seguidas.\p"
	.string "Pero estuvo buenísimo, eh.$"

TokynWarRoom_EventScript_Tokyn_Text_0:
# 111 "data/maps/TokynWarRoom/scripts.pory"
	.string "Me alegra muchísimo haber sido\n"
	.string "convocado para esta celebración.\p"
	.string "Estar acá, compartir un combate así… me\n"
	.string "trajo muy buenos recuerdos.$"

TokynWarRoom_EventScript_Tokyn_Text_1:
# 114 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por hacerlo especial.$"
