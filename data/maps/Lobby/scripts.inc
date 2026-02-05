Lobby_MapScripts::
# 2 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Lobby_OnTransition
	.byte 0


Lobby_OnTransition::
# 6 "data/maps/Lobby/scripts.pory"
	setrespawn HEAL_LOCATION_LOBBY
	end


Lobby_EventScript_StartChallenge::
# 11 "data/maps/Lobby/scripts.pory"
	lock
# 12 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_POLICE, Common_Movement_FacePlayer
# 13 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_YESNO
# 14 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_2
# 18 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 19 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_POLICE, DIR_SOUTH
Lobby_EventScript_StartChallenge_1:
# 21 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_StartChallenge_2:
# 15 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 16 "data/maps/Lobby/scripts.pory"
	waitstate
	goto Lobby_EventScript_StartChallenge_1


Lobby_EventScript_TeamSelector::
# 27 "data/maps/Lobby/scripts.pory"
	lock
# 28 "data/maps/Lobby/scripts.pory"
	faceplayer
# 29 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 30 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 39 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 41 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 42 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 31 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 32 "data/maps/Lobby/scripts.pory"
	waitstate
# 33 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 36 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 34 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_Shop::
# 53 "data/maps/Lobby/scripts.pory"
	lock
# 54 "data/maps/Lobby/scripts.pory"
	faceplayer
# 55 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 56 "data/maps/Lobby/scripts.pory"
	waitmessage
# 57 "data/maps/Lobby/scripts.pory"
	pokemart MyMartItems
# 58 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 59 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 64 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 131 "data/maps/Lobby/scripts.pory"
	lockall
# 132 "data/maps/Lobby/scripts.pory"
	faceplayer
# 133 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 134 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 135 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 136 "data/maps/Lobby/scripts.pory"
	delay 20
# 137 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 138 "data/maps/Lobby/scripts.pory"
	delay 20
# 139 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 140 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 141 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 142 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_Movement_0
# 143 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 144 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Roxas_Movement_1
# 145 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 146 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 147 "data/maps/Lobby/scripts.pory"
	lockall
# 148 "data/maps/Lobby/scripts.pory"
	delay 20
# 149 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 150 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 151 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 152 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_1:
# 65 "data/maps/Lobby/scripts.pory"
	lockall
# 66 "data/maps/Lobby/scripts.pory"
	faceplayer
# 67 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 68 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 69 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 70 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_5
# 73 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_4:
# 75 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 76 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_Movement_0
# 77 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_Movement_1
# 79 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 80 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 81 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 82 "data/maps/Lobby/scripts.pory"
	delay 20
# 83 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 84 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 85 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 86 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 87 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 88 "data/maps/Lobby/scripts.pory"
	delay 20
# 89 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 90 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 91 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 92 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 93 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 94 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 95 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 96 "data/maps/Lobby/scripts.pory"
	waitstate
# 97 "data/maps/Lobby/scripts.pory"
	lockall
# 98 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_9
# 104 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 105 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 106 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 107 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ROXAS, Lobby_EventScript_Roxas_Text_8
# 108 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 109 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 110 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_12
# 117 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 118 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_16
# 121 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_15:
# 123 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 124 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 125 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_11:
# 127 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 128 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_5:
# 71 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_9:
# 99 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 100 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 101 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_12:
# 111 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 112 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_X
# 113 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_DEFAULT
# 114 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 115 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_11

Lobby_EventScript_Roxas_16:
# 119 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_15


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 158 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 159 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 160 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 163 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 166 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 169 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 161 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 164 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 167 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 170 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


	.align 2
# 177 "data/maps/Lobby/scripts.pory"
MyMartItems:
# 178 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 179 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 180 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 181 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 182 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 183 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 184 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 185 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 186 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 187 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 189 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 190 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 192 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 193 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 195 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 196 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 197 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 198 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 199 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 200 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 201 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 202 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 203 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 204 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 205 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 206 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

# 76 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_Movement_0:
# 76 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 76 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 78 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_Movement_1:
# 78 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 78 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 78 "data/maps/Lobby/scripts.pory"
	face_player
# 78 "data/maps/Lobby/scripts.pory"
	delay_16
# 78 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

Lobby_EventScript_StartChallenge_Text_0:
# 13 "data/maps/Lobby/scripts.pory"
	.string "Pendiente textos, ¿empezar desafío?$"

Lobby_EventScript_TeamSelector_Text_0:
# 29 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 34 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_Shop_Text_0:
# 55 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 58 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_Text_0:
# 71 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_Text_1:
# 73 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_Text_2:
# 79 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_Text_3:
# 83 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_Text_4:
# 86 "data/maps/Lobby/scripts.pory"
	.string "Terminé mi investigación en el\n"
	.string "Archipiélago Suzuka… es una historia\l"
	.string "larga, tendrías que haberlo visto…\p"
	.string "No sabes lo que fue… Pero logré dar con\n"
	.string "el rastro de esa fuerza que estaba\l"
	.string "causando tantos males y estoy listo\l"
	.string "para probar si realmente este bicho es\l"
	.string "tan legendario como dicen las crónicas\l"
	.string "del archipiélago.$"

Lobby_EventScript_Roxas_Text_5:
# 93 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate.$"

Lobby_EventScript_Roxas_Text_6:
# 100 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tienes miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_EventScript_Roxas_Text_7:
# 105 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_8:
# 107 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_9:
# 113 "data/maps/Lobby/scripts.pory"
	.string "¡Nooo, me estás cargando! Ni con la\n"
	.string "fuerza de este Pokémon oscuro te pude\l"
	.string "ganar.\p"
	.string "Ahora me cierra por qué a vos te dejaron\n"
	.string "pasar a las salas y a mí me sacaron de\l"
	.string "un voleo.\p"
	.string "Tenés algo distinto, pasta de campeón,\n"
	.string "no es solo fuerza bruta.\p"
	.string "La verdad, me cerraste la boca. Bien\n"
	.string "ganado.$"

Lobby_EventScript_Roxas_Text_10:
# 119 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_11:
# 121 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_12:
# 125 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_13:
# 133 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_14:
# 137 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_15:
# 145 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras loco!$"

Lobby_EventScript_Roxas_Text_16:
# 149 "data/maps/Lobby/scripts.pory"
	.string "Pero bueno, tampoco me voy a quedar acá\n"
	.string "llorando.\p"
	.string "Estoy tras un barco que desapareció al\n"
	.string "oeste de las Islas Naranja, el\l"
	.string "archipiélago Suzuka.\p"
	.string "El Team Rocket anda haciendo de las\n"
	.string "suyas y dicen que hay un bicho oscuro\l"
	.string "con ojos rojos que es un peligro…\l"
	.string "Aterrador…\p"
	.string "Habrá que investigar y ver que onda…$"

Lobby_EventScript_Roxas_Text_17:
# 151 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones. ¡Suerte,\l"
	.string "espero que a vos sí te den bola!$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 47 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"
