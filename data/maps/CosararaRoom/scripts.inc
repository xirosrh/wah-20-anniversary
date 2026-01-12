CosararaRoom_MapScripts::
	.byte 0


CosararaRoom_EventScript_Cosarara::
# 5 "data/maps/CosararaRoom/scripts.pory"
	lock
# 6 "data/maps/CosararaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_COSARARA, CosararaRoom_EventScript_Cosarara_2
# 13 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_1, MSGBOX_AUTOCLOSE
# 14 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 15 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_HappyWithDelay48
# 16 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 17 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_2, MSGBOX_AUTOCLOSE
# 18 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 19 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 20 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 21 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_QuestionMarkWithDelay48
# 22 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_3, MSGBOX_AUTOCLOSE
# 23 "data/maps/CosararaRoom/scripts.pory"
	playse SE_PIN
# 24 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_SweatDropWithDelay48
# 25 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 26 "data/maps/CosararaRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 27 "data/maps/CosararaRoom/scripts.pory"
	switch VAR_RESULT
# 28 "data/maps/CosararaRoom/scripts.pory"
	case DIR_NORTH, CosararaRoom_EventScript_Cosarara_6
# 31 "data/maps/CosararaRoom/scripts.pory"
	case DIR_WEST, CosararaRoom_EventScript_Cosarara_7
# 34 "data/maps/CosararaRoom/scripts.pory"
	case DIR_EAST, CosararaRoom_EventScript_Cosarara_8
CosararaRoom_EventScript_Cosarara_4:
# 38 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_4
# 39 "data/maps/CosararaRoom/scripts.pory"
	call CosararaRoom_EventScript_CosararaBattle
# 40 "data/maps/CosararaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_COSARARA
# 41 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 42 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_5, MSGBOX_AUTOCLOSE
# 43 "data/maps/CosararaRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 44 "data/maps/CosararaRoom/scripts.pory"
	delay 20
# 45 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_FaceUp
# 46 "data/maps/CosararaRoom/scripts.pory"
	release
	end

CosararaRoom_EventScript_Cosarara_2:
# 7 "data/maps/CosararaRoom/scripts.pory"
	faceplayer
# 8 "data/maps/CosararaRoom/scripts.pory"
	msgbox CosararaRoom_EventScript_Cosarara_Text_0
# 9 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_COSARARAROOM_COSARARA, Common_Movement_FaceUp
# 10 "data/maps/CosararaRoom/scripts.pory"
	release
	end

CosararaRoom_EventScript_Cosarara_6:
# 29 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto CosararaRoom_EventScript_Cosarara_4

CosararaRoom_EventScript_Cosarara_7:
# 32 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto CosararaRoom_EventScript_Cosarara_4

CosararaRoom_EventScript_Cosarara_8:
# 35 "data/maps/CosararaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto CosararaRoom_EventScript_Cosarara_4


CosararaRoom_EventScript_CosararaBattle::
# 51 "data/maps/CosararaRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, CosararaRoom_EventScript_CosararaBattle_2
# 54 "data/maps/CosararaRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_COSARARA
# 55 "data/maps/CosararaRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 56 "data/maps/CosararaRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CosararaRoom_EventScript_CosararaBattle_5
# 59 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE, CosararaRoom_Text_CosararaDefeated
CosararaRoom_EventScript_CosararaBattle_1:
# 62 "data/maps/CosararaRoom/scripts.pory"
	special HealPlayerParty
	return

CosararaRoom_EventScript_CosararaBattle_2:
# 52 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_MAIN, CosararaRoom_Text_CosararaDefeated
	goto CosararaRoom_EventScript_CosararaBattle_1

CosararaRoom_EventScript_CosararaBattle_5:
# 57 "data/maps/CosararaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_COSARARA_MAIN, CosararaRoom_Text_CosararaDefeated
	goto CosararaRoom_EventScript_CosararaBattle_1


CosararaRoom_EventScript_Cosarara_Text_0:
# 8 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Y tú eres? Ahhh sí ya me acuerdo de ti,\n"
	.string "{PLAYER}.\p"
	.string "¡Deseo que te vaya bien!$"

CosararaRoom_EventScript_Cosarara_Text_1:
# 13 "data/maps/CosararaRoom/scripts.pory"
	.string "Lo he logrado.$"

CosararaRoom_EventScript_Cosarara_Text_2:
# 17 "data/maps/CosararaRoom/scripts.pory"
	.string "He completado una nueva extracción no\n"
	.string "autorizada de todos los registros de la\l"
	.string "comunidad.\p"
	.string "La construimos entre todos, así que\n"
	.string "creo que tiene un valor que vale la pena\l"
	.string "preservar.$"

CosararaRoom_EventScript_Cosarara_Text_3:
# 22 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Y tú quién eras? ¿Has cambiado de nick\n"
	.string "recientemente?\p"
	.string "Es que me pierdo, ¡no me da la memoria!$"

CosararaRoom_EventScript_Cosarara_Text_4:
# 38 "data/maps/CosararaRoom/scripts.pory"
	.string "¿Así que eres {PLAYER} y quieres\n"
	.string "combatir? Acepto el reto.$"

CosararaRoom_EventScript_Cosarara_Text_5:
# 42 "data/maps/CosararaRoom/scripts.pory"
	.string "Ha sido una buena batalla, {PLAYER}.\n"
	.string "Creo que te recordaré.\p"
	.string "Recuerda no cambiar de nick, ya que me\n"
	.string "cuesta mucho saber quién es quien.\p"
	.string "Ya puedes avanzar.$"

CosararaRoom_Text_CosararaDefeated::
# 66 "data/maps/CosararaRoom/scripts.pory"
	.string "Me ha hecho muy feliz esta batalla.$"
