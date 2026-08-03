RestRoom_MapScripts::
# 2 "data/maps/RestRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RestRoom_OnTransition
# 3 "data/maps/RestRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RestRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

RestRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/RestRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, RestRoom_OnWarp_PlayerTurnNorth
	.2byte 0


RestRoom_OnWarp_PlayerTurnNorth::
# 10 "data/maps/RestRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


RestRoom_OnTransition::
# 14 "data/maps/RestRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	end


RestRoom_EventScript_Boy1::
# 19 "data/maps/RestRoom/scripts.pory"
	lock
# 20 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 21 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_AUTOCLOSE
# 22 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 23 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_1, MSGBOX_AUTOCLOSE
# 24 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 26 "data/maps/RestRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRENINJA
# 27 "data/maps/RestRoom/scripts.pory"
	specialvar VAR_RESULT, Special_BufferPokeboxBuyOfferFromSpecies
# 28 "data/maps/RestRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RestRoom_EventScript_Boy1_2
RestRoom_EventScript_Boy1_1:
# 31 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Boy1_2:
# 29 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_2, MSGBOX_AUTOCLOSE
	goto RestRoom_EventScript_Boy1_1


RestRoom_EventScript_Girl1::
# 36 "data/maps/RestRoom/scripts.pory"
	lock
# 37 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 38 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_0, MSGBOX_AUTOCLOSE
# 39 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 40 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 41 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_1, MSGBOX_AUTOCLOSE
# 44 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Boy2::
# 49 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy2_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_AStartGaming::
# 54 "data/maps/RestRoom/scripts.pory"
	lock
# 55 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 56 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_AStartGaming_Text_0, MSGBOX_NPC, speaker = SP_NAME_A_START_GAMING
# 57 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 58 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
	end


RestRoom_EventScript_PlayerCounterpart::
# 63 "data/maps/RestRoom/scripts.pory"
	lock
# 64 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 65 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 66 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 67 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_0, MSGBOX_AUTOCLOSE
# 68 "data/maps/RestRoom/scripts.pory"
	delay 48
# 69 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_1, MSGBOX_AUTOCLOSE
# 70 "data/maps/RestRoom/scripts.pory"
	delay 10
# 71 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 72 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 73 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_2, MSGBOX_AUTOCLOSE
# 74 "data/maps/RestRoom/scripts.pory"
	delay 48
# 75 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Raizen_TalkOnly::
# 80 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 81 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 82 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 83 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 84 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 85 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 86 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 87 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 88 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return


RestRoom_EventScript_Raizen_IntroFirstBattle::
# 92 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 93 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 94 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 95 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 96 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 97 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
	return


RestRoom_EventScript_Raizen_IntroRematch::
# 102 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 103 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 104 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 105 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 106 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 107 "data/maps/RestRoom/scripts.pory"
	setspeaker SP_NAME_RAIZEN
# 108 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Raizen_IntroRematch_Text_2
# 109 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 110 "data/maps/RestRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 111 "data/maps/RestRoom/scripts.pory"
	closemessage
# 112 "data/maps/RestRoom/scripts.pory"
	delay 20
# 113 "data/maps/RestRoom/scripts.pory"
	switch VAR_RESULT
# 114 "data/maps/RestRoom/scripts.pory"
	case 0, RestRoom_EventScript_Raizen_IntroRematch_2
# 120 "data/maps/RestRoom/scripts.pory"
	case 1, RestRoom_EventScript_Raizen_IntroRematch_3
# 123 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 124 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 125 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 126 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return

RestRoom_EventScript_Raizen_IntroRematch_2:
# 115 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 116 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 117 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 118 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
	return

RestRoom_EventScript_Raizen_IntroRematch_3:
# 121 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_TalkOnly
	return


RestRoom_EventScript_Raizen_OnFinishEvent::
# 131 "data/maps/RestRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 132 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Raizen::
# 137 "data/maps/RestRoom/scripts.pory"
	lock
# 138 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 139 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Raizen_2
RestRoom_EventScript_Raizen_1:
# 143 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_REST_ROOM_RAIZEN, RestRoom_EventScript_Raizen_5
# 146 "data/maps/RestRoom/scripts.pory"
	call RestRoom_EventScript_Raizen_IntroFirstBattle
RestRoom_EventScript_Raizen_4:
# 149 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 150 "data/maps/RestRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 151 "data/maps/RestRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 152 "data/maps/RestRoom/scripts.pory"
	waitmovement 0
# 153 "data/maps/RestRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 154 "data/maps/RestRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_TRANSLATOR_RAIZEN, RestRoom_Text_Raizen_OnDefeat
# 155 "data/maps/RestRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 156 "data/maps/RestRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 158 "data/maps/RestRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RestRoom_EventScript_Raizen_9
# 169 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 170 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 171 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
RestRoom_EventScript_Raizen_8:
# 174 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 175 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return

RestRoom_EventScript_Raizen_2:
# 140 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_TalkOnly
	goto RestRoom_EventScript_Raizen_1

RestRoom_EventScript_Raizen_5:
# 144 "data/maps/RestRoom/scripts.pory"
	call RestRoom_EventScript_Raizen_IntroRematch
	goto RestRoom_EventScript_Raizen_4

RestRoom_EventScript_Raizen_9:
# 159 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 160 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 161 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 162 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 163 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 164 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_REST_ROOM_RAIZEN, RestRoom_EventScript_Raizen_12
	goto RestRoom_EventScript_Raizen_8

RestRoom_EventScript_Raizen_12:
# 165 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_DEFEATED_REST_ROOM_RAIZEN
# 166 "data/maps/RestRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatTranslatorRaizen
	goto RestRoom_EventScript_Raizen_8


RestRoom_EventScript_Shop::
# 183 "data/maps/RestRoom/scripts.pory"
	lock
# 184 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 185 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Shop_4
RestRoom_EventScript_Shop_3:
# 191 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_1
# 192 "data/maps/RestRoom/scripts.pory"
	waitmessage
RestRoom_EventScript_Shop_1:
# 194 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 195 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 196 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 197 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Shop_2:
# 186 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 187 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 188 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto RestRoom_EventScript_Shop_1

RestRoom_EventScript_Shop_4:
# 185 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, RestRoom_EventScript_Shop_2
	goto RestRoom_EventScript_Shop_3


RestRoom_EventScript_Pokebox::
# 202 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 203 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 204 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 205 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 206 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


RestRoom_EventScript_Boy1_Text_0:
# 21 "data/maps/RestRoom/scripts.pory"
	.string "¡Uf, al fin una zona de descanso!$"

RestRoom_EventScript_Boy1_Text_1:
# 23 "data/maps/RestRoom/scripts.pory"
	.string "Por un momento pensé que las 21 salas\n"
	.string "eran seguidas sin pausa…$"

RestRoom_EventScript_Boy1_Text_2:
# 29 "data/maps/RestRoom/scripts.pory"
	.string "Me viene costando, necesito prepararme\n"
	.string "mejor para las próximas salas.\p"
	.string "Voy a ajustar algunos ataques, comprar\n"
	.string "objetos curativos y…\p"
	.string "¡Creo que compraré un {STR_VAR_1}!\n"
	.string "Vi que en la PC está a solo\l"
	.string "{STR_VAR_2}, ¡está regalado!$"

RestRoom_EventScript_Girl1_Text_0:
# 38 "data/maps/RestRoom/scripts.pory"
	.string "¡Los diseños de las salas son\n"
	.string "increíbles!$"

RestRoom_EventScript_Girl1_Text_1:
# 41 "data/maps/RestRoom/scripts.pory"
	.string "Un teatro, una jungla… ¡hasta un cine!\n"
	.string "¿Te imaginas cuánto trabajo hay\l"
	.string "detrás de todo esto?$"

RestRoom_EventScript_Boy2_Text_0:
# 49 "data/maps/RestRoom/scripts.pory"
	.string "¡Los precios de esta tienda son una\n"
	.string "estafa!\p"
	.string "Tendría que haber comprado todo lo\n"
	.string "necesario antes de entrar.$"

RestRoom_EventScript_AStartGaming_Text_0:
# 56 "data/maps/RestRoom/scripts.pory"
	.string "En un principio iba a colaborar como\n"
	.string "traductor en los esfuerzos de\l"
	.string "internacionalización.\p"
	.string "Pero al final aquí estoy, ¡disfrutando\n"
	.string "mientras supero el desafío!$"

RestRoom_EventScript_PlayerCounterpart_Text_0:
# 67 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué sorpresa, {PLAYER}!$"

RestRoom_EventScript_PlayerCounterpart_Text_1:
# 69 "data/maps/RestRoom/scripts.pory"
	.string "¿Así que también estás participando en\n"
	.string "el desafío?\p"
	.string "¡Cada sala nos enseña algo sobre los\n"
	.string "líderes de la comunidad!\p"
	.string "¡He aprendido mucho de ellos!$"

RestRoom_EventScript_PlayerCounterpart_Text_2:
# 73 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué emocionante!$"

RestRoom_EventScript_Raizen_TalkOnly_Text_0:
# 80 "data/maps/RestRoom/scripts.pory"
	.string "Aunque no lo parezca, vengo de muy\n"
	.string "lejos.\p"
	.string "De Konoha, nada menos.$"

RestRoom_EventScript_Raizen_TalkOnly_Text_1:
# 83 "data/maps/RestRoom/scripts.pory"
	.string "Soy traductor.\p"
	.string "Me llamaron para que todo lo que ocurre\n"
	.string "aquí pudiera conocerse también en\l"
	.string "otras tierras.$"

RestRoom_EventScript_Raizen_TalkOnly_Text_2:
# 85 "data/maps/RestRoom/scripts.pory"
	.string "No es una misión de rango S, ¡pero\n"
	.string "alguien tenía que hacerla!$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_0:
# 92 "data/maps/RestRoom/scripts.pory"
	.string "¡Así que has completado el desafío!$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_1:
# 95 "data/maps/RestRoom/scripts.pory"
	.string "Para mí, ser traductor es sencillo.\p"
	.string "Lo difícil será traducir la paliza que\n"
	.string "pienso darte.$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_2:
# 97 "data/maps/RestRoom/scripts.pory"
	.string "¡Vamos, enséñame de qué eres capaz!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_0:
# 102 "data/maps/RestRoom/scripts.pory"
	.string "¡Has regresado!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_1:
# 105 "data/maps/RestRoom/scripts.pory"
	.string "¿Vienes por la revancha? Admito que no\n"
	.string "esperaba recibir otra misión tan\l"
	.string "pronto.\p"
	.string "Esta vez no habrá pergaminos ni\n"
	.string "palabras que traducir.\p"
	.string "Solo tú, yo y nuestros Pokémon.$"

RestRoom_EventScript_Raizen_IntroRematch_Text_2:
# 108 "data/maps/RestRoom/scripts.pory"
	.string "¿Qué dices?$"

RestRoom_EventScript_Raizen_IntroRematch_Text_3:
# 115 "data/maps/RestRoom/scripts.pory"
	.string "¡Misión aceptada!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_4:
# 118 "data/maps/RestRoom/scripts.pory"
	.string "Prepárate, porque esta vez pienso\n"
	.string "completarla.$"

RestRoom_EventScript_Raizen_IntroRematch_Text_5:
# 123 "data/maps/RestRoom/scripts.pory"
	.string "Entendido. Dejaré esta misión\n"
	.string "pendiente.\p"
	.string "Vuelve cuando estés list{OA}.$"

RestRoom_EventScript_Raizen_Text_0:
# 161 "data/maps/RestRoom/scripts.pory"
	.string "¡Incomprensible!\p"
	.string "Mi estrategia no tuvo traducción en el\n"
	.string "campo de batalla.$"

RestRoom_EventScript_Raizen_Text_1:
# 169 "data/maps/RestRoom/scripts.pory"
	.string "El resultado es claro en cualquier\n"
	.string "idioma: aún te falta mucho por\l"
	.string "aprender.$"

RestRoom_EventScript_Shop_Text_0:
# 186 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¡Hemos ampliado el catálogo!\p"
	.string "Ahora también puedes comprar objetos\n"
	.string "de combate.\p"
	.string "¿En qué puedo ayudarte?\n"
	.string "¡Aquí somos un poco más caros!$"

RestRoom_EventScript_Shop_Text_1:
# 191 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?\n¡Aquí somos un poco más caros!$"

RestRoom_Text_Raizen_OnDefeat::
# 178 "data/maps/RestRoom/scripts.pory"
	.string "No he entendido nada...$"
