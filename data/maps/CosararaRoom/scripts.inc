CosararaRoom_MapScripts::
# 5 "data/maps/CosararaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CosararaRoom_OnLoad
# 2 "data/maps/CosararaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CosararaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

CosararaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/CosararaRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, CosararaRoom_OnWarp_PlayerTurnNorth
	.2byte 0


CosararaRoom_OnLoad::
# 10 "data/maps/CosararaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_COSARARA, CosararaRoom_OnLoad_2
CosararaRoom_OnLoad_1:
	end

CosararaRoom_OnLoad_2:
# 11 "data/maps/CosararaRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto CosararaRoom_OnLoad_1


CosararaRoom_OnWarp_PlayerTurnNorth::
# 17 "data/maps/CosararaRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


CosararaRoom_EventScript_Cosarara::
# 22 "data/maps/CosararaRoom/scripts.pory"
	lock
# 23 "data/maps/CosararaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_COSARARA, CosararaRoom_EventScript_Cosarara_2
# 36 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 37 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 38 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_HappyWithDelay48
# 39 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 40 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 41 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 42 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 43 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 44 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, CosararaRoom_EventScript_Cosarara_Movement_1
# 45 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 46 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_LockPC
# 47 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 48 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 49 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 50 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_SweatDropWithDelay48
# 52 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 53 "data/maps/CosararaRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 54 "data/maps/CosararaRoom/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/CosararaRoom/scripts.pory"
	case DIR_NORTH, CosararaRoom_EventScript_Cosarara_6
# 58 "data/maps/CosararaRoom/scripts.pory"
	case DIR_WEST, CosararaRoom_EventScript_Cosarara_7
# 61 "data/maps/CosararaRoom/scripts.pory"
	case DIR_EAST, CosararaRoom_EventScript_Cosarara_8
CosararaRoom_EventScript_Cosarara_4:
# 65 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 66 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 67 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, CosararaRoom_EventScript_Cosarara_Movement_2
# 68 "data/maps/CosararaRoom/scripts.pory"
	waitse
# 69 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_CosararaBattle
# 70 "data/maps/CosararaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_COSARARA
# 71 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 72 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 73 "data/maps/CosararaRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 74 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 75 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_FaceUp
# 76 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 77 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_UnlockPC
# 78 "data/maps/CosararaRoom/scripts.pory"
	release
	end

CosararaRoom_EventScript_Cosarara_2:
# 24 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, CosararaRoom_EventScript_Cosarara_Movement_0
# 26 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_LockPC
# 27 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 28 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 29 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COSARARA
# 30 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_FaceUp
# 31 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 32 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_UnlockPC
# 33 "data/maps/CosararaRoom/scripts.pory"
	release
	end

CosararaRoom_EventScript_Cosarara_6:
# 56 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto CosararaRoom_EventScript_Cosarara_4

CosararaRoom_EventScript_Cosarara_7:
# 59 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto CosararaRoom_EventScript_Cosarara_4

CosararaRoom_EventScript_Cosarara_8:
# 62 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto CosararaRoom_EventScript_Cosarara_4


CosararaRoom_EventScript_CosararaBattle::
# 83 "data/maps/CosararaRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, CosararaRoom_EventScript_CosararaBattle_2
# 86 "data/maps/CosararaRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_COSARARA
# 87 "data/maps/CosararaRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 88 "data/maps/CosararaRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CosararaRoom_EventScript_CosararaBattle_5
# 91 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE, CosararaRoom_Text_CosararaDefeated
CosararaRoom_EventScript_CosararaBattle_1:
# 94 "data/maps/CosararaRoom/scripts.pory"
	special HealPlayerParty
	return

CosararaRoom_EventScript_CosararaBattle_2:
# 84 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_MAIN, CosararaRoom_Text_CosararaDefeated
	goto CosararaRoom_EventScript_CosararaBattle_1

CosararaRoom_EventScript_CosararaBattle_5:
# 89 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_MAIN, CosararaRoom_Text_CosararaDefeated
	goto CosararaRoom_EventScript_CosararaBattle_1


CosararaRoom_EventScript_LockPC::
# 103 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 1, METATILE_room_cosarara_PC_LOCKED_1, TRUE
# 104 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_cosarara_PC_LOCKED_2, TRUE
# 105 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_cosarara_PC_LOCKED_3, TRUE
# 106 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_cosarara_PC_LOCKED_4, TRUE
# 107 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_cosarara_PC_LOCKED_5, TRUE
# 108 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 2, METATILE_room_cosarara_PC_LOCKED_6, TRUE
# 109 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_cosarara_PC_LOCKED_7, TRUE
# 110 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_cosarara_PC_LOCKED_8, TRUE
# 111 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_cosarara_PC_LOCKED_9, TRUE
# 112 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_cosarara_PC_LOCKED_10, TRUE
# 113 "data/maps/CosararaRoom/scripts.pory"
	special DrawWholeMapView
	return


CosararaRoom_EventScript_UnlockPC::
# 118 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 1, METATILE_room_cosarara_PC_MATRIX_1, TRUE
# 119 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 1, METATILE_room_cosarara_PC_MATRIX_2, TRUE
# 120 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 1, METATILE_room_cosarara_PC_MATRIX_3, TRUE
# 121 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 1, METATILE_room_cosarara_PC_MATRIX_4, TRUE
# 122 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 1, METATILE_room_cosarara_PC_MATRIX_5, TRUE
# 123 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 1, 2, METATILE_room_cosarara_PC_MATRIX_6, TRUE
# 124 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 2, 2, METATILE_room_cosarara_PC_MATRIX_7, TRUE
# 125 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 3, 2, METATILE_room_cosarara_PC_MATRIX_8, TRUE
# 126 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 4, 2, METATILE_room_cosarara_PC_MATRIX_9, TRUE
# 127 "data/maps/CosararaRoom/scripts.pory"
	setmetatile 5, 2, METATILE_room_cosarara_PC_MATRIX_10, TRUE
# 128 "data/maps/CosararaRoom/scripts.pory"
	special DrawWholeMapView
	return


# 25 "data/maps/CosararaRoom/scripts.pory"
CosararaRoom_EventScript_Cosarara_Movement_0:
# 25 "data/maps/CosararaRoom/scripts.pory"
	face_player
# 25 "data/maps/CosararaRoom/scripts.pory"
	emote_exclamation_mark
# 25 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 25 "data/maps/CosararaRoom/scripts.pory"
	face_up
# 25 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 25 "data/maps/CosararaRoom/scripts.pory"
	delay_16
	step_end

# 44 "data/maps/CosararaRoom/scripts.pory"
CosararaRoom_EventScript_Cosarara_Movement_1:
# 44 "data/maps/CosararaRoom/scripts.pory"
	face_player
# 44 "data/maps/CosararaRoom/scripts.pory"
	emote_question_mark
# 44 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 44 "data/maps/CosararaRoom/scripts.pory"
	face_up
# 44 "data/maps/CosararaRoom/scripts.pory"
	delay_16
# 44 "data/maps/CosararaRoom/scripts.pory"
	delay_16
	step_end

# 67 "data/maps/CosararaRoom/scripts.pory"
CosararaRoom_EventScript_Cosarara_Movement_2:
# 67 "data/maps/CosararaRoom/scripts.pory"
	emote_versus
	step_end

CosararaRoom_EventScript_Cosarara_Text_0:
# 29 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Y tú eres? Ahhh sí ya me acuerdo de ti,\n"
	.string "{PLAYER}.\p"
	.string "¡Deseo que te vaya bien!$"

CosararaRoom_EventScript_Cosarara_Text_1:
# 36 "data/maps/CosararaRoom/scripts.pory"
	.string "Lo he logrado.$"

CosararaRoom_EventScript_Cosarara_Text_2:
# 40 "data/maps/CosararaRoom/scripts.pory"
	.string "He completado una nueva extracción no\n"
	.string "autorizada de todos los registros de la\l"
	.string "comunidad.\p"
	.string "La construimos entre todos, así que\n"
	.string "creo que tiene un valor que vale la pena\l"
	.string "preservar.$"

CosararaRoom_EventScript_Cosarara_Text_3:
# 45 "data/maps/CosararaRoom/scripts.pory"
	.string "Voy a bloquear mi computadora…$"

CosararaRoom_EventScript_Cosarara_Text_4:
# 49 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Y tú quién eras? ¿Has cambiado de nick\n"
	.string "recientemente?\p"
	.string "Es que me pierdo, ¡no me da la memoria!$"

CosararaRoom_EventScript_Cosarara_Text_5:
# 65 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Así que eres {PLAYER} y quieres\n"
	.string "combatir? Acepto el reto.$"

CosararaRoom_EventScript_Cosarara_Text_6:
# 72 "data/maps/CosararaRoom/scripts.pory"
	.string "Ha sido una buena batalla, {PLAYER}.\n"
	.string "Creo que te recordaré.\p"
	.string "Recuerda no cambiar de nick, ya que me\n"
	.string "cuesta mucho saber quién es quien.\p"
	.string "Ya puedes avanzar.$"

CosararaRoom_Text_CosararaDefeated::
# 98 "data/maps/CosararaRoom/scripts.pory"
	.string "Me ha hecho muy feliz esta batalla.$"
