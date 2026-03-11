CosararaRoom_MapScripts::
# 5 "data/maps/CosararaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CosararaRoom_OnLoad
# 6 "data/maps/CosararaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CosararaRoom_OnTransition
# 2 "data/maps/CosararaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CosararaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

CosararaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/CosararaRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, CosararaRoom_OnWarp_PlayerTurnNorth
	.2byte 0


CosararaRoom_OnLoad::
# 11 "data/maps/CosararaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_COSARARA, CosararaRoom_OnLoad_2
CosararaRoom_OnLoad_1:
	end

CosararaRoom_OnLoad_2:
# 12 "data/maps/CosararaRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto CosararaRoom_OnLoad_1


CosararaRoom_OnWarp_PlayerTurnNorth::
# 18 "data/maps/CosararaRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


CosararaRoom_OnTransition::
# 23 "data/maps/CosararaRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Cosarara
	end


CosararaRoom_EventScript_Cosarara::
# 28 "data/maps/CosararaRoom/scripts.pory"
	lock
# 29 "data/maps/CosararaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_COSARARA, CosararaRoom_EventScript_Cosarara_2
# 42 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 43 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 44 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_HappyWithDelay48
# 45 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 46 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 47 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 48 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 49 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, CosararaRoom_EventScript_Cosarara_Movement_1
# 51 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 52 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_LockPC
# 53 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 54 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 55 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 56 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 57 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_SweatDropWithDelay48
# 58 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 59 "data/maps/CosararaRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 60 "data/maps/CosararaRoom/scripts.pory"
	switch VAR_RESULT
# 61 "data/maps/CosararaRoom/scripts.pory"
	case DIR_NORTH, CosararaRoom_EventScript_Cosarara_6
# 64 "data/maps/CosararaRoom/scripts.pory"
	case DIR_WEST, CosararaRoom_EventScript_Cosarara_7
# 67 "data/maps/CosararaRoom/scripts.pory"
	case DIR_EAST, CosararaRoom_EventScript_Cosarara_8
CosararaRoom_EventScript_Cosarara_4:
# 71 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 72 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, CosararaRoom_EventScript_Cosarara_Movement_2
# 74 "data/maps/CosararaRoom/scripts.pory"
	waitse
# 75 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_CosararaBattle
# 76 "data/maps/CosararaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_COSARARA
# 77 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 78 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 79 "data/maps/CosararaRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 80 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 81 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_FaceUp
# 82 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 83 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_UnlockPC
# 84 "data/maps/CosararaRoom/scripts.pory"
	release
	end

CosararaRoom_EventScript_Cosarara_2:
# 30 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 31 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, CosararaRoom_EventScript_Cosarara_Movement_0
# 32 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_LockPC
# 33 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 34 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 35 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 36 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_FaceUp
# 37 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 38 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_UnlockPC
# 39 "data/maps/CosararaRoom/scripts.pory"
	release
	end

CosararaRoom_EventScript_Cosarara_6:
# 62 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto CosararaRoom_EventScript_Cosarara_4

CosararaRoom_EventScript_Cosarara_7:
# 65 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto CosararaRoom_EventScript_Cosarara_4

CosararaRoom_EventScript_Cosarara_8:
# 68 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto CosararaRoom_EventScript_Cosarara_4


CosararaRoom_EventScript_CosararaBattle::
# 89 "data/maps/CosararaRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, CosararaRoom_EventScript_CosararaBattle_2
# 92 "data/maps/CosararaRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_COSARARA
# 93 "data/maps/CosararaRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 94 "data/maps/CosararaRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CosararaRoom_EventScript_CosararaBattle_5
# 97 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE, CosararaRoom_Text_CosararaDefeated
CosararaRoom_EventScript_CosararaBattle_1:
# 100 "data/maps/CosararaRoom/scripts.pory"
	special HealPlayerParty
	return

CosararaRoom_EventScript_CosararaBattle_2:
# 90 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_MAIN, CosararaRoom_Text_CosararaDefeated
	goto CosararaRoom_EventScript_CosararaBattle_1

CosararaRoom_EventScript_CosararaBattle_5:
# 95 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_MAIN, CosararaRoom_Text_CosararaDefeated
	goto CosararaRoom_EventScript_CosararaBattle_1


CosararaRoom_EventScript_LockPC::
# 109 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 1, METATILE_room_cosarara_PC_LOCKED_1, TRUE
# 110 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_cosarara_PC_LOCKED_2, TRUE
# 111 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_cosarara_PC_LOCKED_3, TRUE
# 112 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_cosarara_PC_LOCKED_4, TRUE
# 113 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_cosarara_PC_LOCKED_5, TRUE
# 114 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 2, METATILE_room_cosarara_PC_LOCKED_6, TRUE
# 115 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_cosarara_PC_LOCKED_7, TRUE
# 116 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_cosarara_PC_LOCKED_8, TRUE
# 117 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_cosarara_PC_LOCKED_9, TRUE
# 118 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_cosarara_PC_LOCKED_10, TRUE
# 119 "data/maps/CosararaRoom/scripts.pory"
	special DrawWholeMapView
	return


CosararaRoom_EventScript_UnlockPC::
# 124 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 1, METATILE_room_cosarara_PC_MATRIX_1, TRUE
# 125 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_cosarara_PC_MATRIX_2, TRUE
# 126 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_cosarara_PC_MATRIX_3, TRUE
# 127 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_cosarara_PC_MATRIX_4, TRUE
# 128 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_cosarara_PC_MATRIX_5, TRUE
# 129 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 2, METATILE_room_cosarara_PC_MATRIX_6, TRUE
# 130 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_cosarara_PC_MATRIX_7, TRUE
# 131 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_cosarara_PC_MATRIX_8, TRUE
# 132 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_cosarara_PC_MATRIX_9, TRUE
# 133 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_cosarara_PC_MATRIX_10, TRUE
# 134 "data/maps/CosararaRoom/scripts.pory"
	special DrawWholeMapView
	return


# 31 "data/maps/CosararaRoom/scripts.pory"
CosararaRoom_EventScript_Cosarara_Movement_0:
# 31 "data/maps/CosararaRoom/scripts.pory"
	face_player
# 31 "data/maps/CosararaRoom/scripts.pory"
	emote_exclamation_mark
# 31 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 31 "data/maps/CosararaRoom/scripts.pory"
	face_up
# 31 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 31 "data/maps/CosararaRoom/scripts.pory"
	delay_16
	step_end

# 50 "data/maps/CosararaRoom/scripts.pory"
CosararaRoom_EventScript_Cosarara_Movement_1:
# 50 "data/maps/CosararaRoom/scripts.pory"
	face_player
# 50 "data/maps/CosararaRoom/scripts.pory"
	emote_question_mark
# 50 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 50 "data/maps/CosararaRoom/scripts.pory"
	face_up
# 50 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 50 "data/maps/CosararaRoom/scripts.pory"
	delay_16
	step_end

# 73 "data/maps/CosararaRoom/scripts.pory"
CosararaRoom_EventScript_Cosarara_Movement_2:
# 73 "data/maps/CosararaRoom/scripts.pory"
	emote_versus
	step_end

CosararaRoom_EventScript_Cosarara_Text_0:
# 35 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Y tú eres? Ahhh sí ya me acuerdo de ti,\n"
	.string "{PLAYER}.\p"
	.string "¡Deseo que te vaya bien!$"

CosararaRoom_EventScript_Cosarara_Text_1:
# 42 "data/maps/CosararaRoom/scripts.pory"
	.string "Lo he logrado.$"

CosararaRoom_EventScript_Cosarara_Text_2:
# 46 "data/maps/CosararaRoom/scripts.pory"
	.string "He completado una nueva extracción no\n"
	.string "autorizada de todos los registros de la\l"
	.string "comunidad.\p"
	.string "La construimos entre todos, así que\n"
	.string "creo que tiene un valor que vale la pena\l"
	.string "preservar.$"

CosararaRoom_EventScript_Cosarara_Text_3:
# 51 "data/maps/CosararaRoom/scripts.pory"
	.string "Voy a bloquear mi computadora…$"

CosararaRoom_EventScript_Cosarara_Text_4:
# 55 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Y tú quién eras? ¿Has cambiado de nick\n"
	.string "recientemente?\p"
	.string "Es que me pierdo, ¡no me da la memoria!$"

CosararaRoom_EventScript_Cosarara_Text_5:
# 71 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Así que eres {PLAYER} y quieres\n"
	.string "combatir? Acepto el reto.$"

CosararaRoom_EventScript_Cosarara_Text_6:
# 78 "data/maps/CosararaRoom/scripts.pory"
	.string "Ha sido una buena batalla, {PLAYER}.\n"
	.string "Creo que te recordaré.\p"
	.string "Recuerda no cambiar de nick, ya que me\n"
	.string "cuesta mucho saber quién es quien.\p"
	.string "Ya puedes avanzar.$"

CosararaRoom_Text_CosararaDefeated::
# 104 "data/maps/CosararaRoom/scripts.pory"
	.string "Me ha hecho muy feliz esta batalla.$"
