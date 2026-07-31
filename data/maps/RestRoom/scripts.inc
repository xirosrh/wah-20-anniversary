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


RestRoom_EventScript_PlayerCounterpart::
# 54 "data/maps/RestRoom/scripts.pory"
	lock
# 55 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 56 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 57 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 58 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_0, MSGBOX_AUTOCLOSE
# 59 "data/maps/RestRoom/scripts.pory"
	delay 48
# 60 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_1, MSGBOX_AUTOCLOSE
# 61 "data/maps/RestRoom/scripts.pory"
	delay 10
# 62 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 64 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_2, MSGBOX_AUTOCLOSE
# 65 "data/maps/RestRoom/scripts.pory"
	delay 48
# 66 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Raizen_TalkOnly::
# 71 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 72 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 74 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 75 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 76 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 77 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 79 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return


RestRoom_EventScript_Raizen_IntroFirstBattle::
# 83 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 84 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 85 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 86 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 87 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 88 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
	return


RestRoom_EventScript_Raizen_IntroRematch::
# 93 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 94 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 95 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 96 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 97 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 98 "data/maps/RestRoom/scripts.pory"
	setspeaker SP_NAME_RAIZEN
# 99 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Raizen_IntroRematch_Text_2
# 100 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 101 "data/maps/RestRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 102 "data/maps/RestRoom/scripts.pory"
	closemessage
# 103 "data/maps/RestRoom/scripts.pory"
	delay 20
# 104 "data/maps/RestRoom/scripts.pory"
	switch VAR_RESULT
# 105 "data/maps/RestRoom/scripts.pory"
	case 0, RestRoom_EventScript_Raizen_IntroRematch_2
# 111 "data/maps/RestRoom/scripts.pory"
	case 1, RestRoom_EventScript_Raizen_IntroRematch_3
# 114 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 115 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 116 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 117 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return

RestRoom_EventScript_Raizen_IntroRematch_2:
# 106 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 107 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 108 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 109 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
	return

RestRoom_EventScript_Raizen_IntroRematch_3:
# 112 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_TalkOnly
	return


RestRoom_EventScript_Raizen_OnFinishEvent::
# 122 "data/maps/RestRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 123 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Raizen::
# 128 "data/maps/RestRoom/scripts.pory"
	lock
# 129 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 130 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Raizen_2
RestRoom_EventScript_Raizen_1:
# 134 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_REST_ROOM_RAIZEN, RestRoom_EventScript_Raizen_5
# 137 "data/maps/RestRoom/scripts.pory"
	call RestRoom_EventScript_Raizen_IntroFirstBattle
RestRoom_EventScript_Raizen_4:
# 140 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 141 "data/maps/RestRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 142 "data/maps/RestRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 143 "data/maps/RestRoom/scripts.pory"
	waitmovement 0
# 144 "data/maps/RestRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 145 "data/maps/RestRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_TRANSLATOR_RAIZEN, RestRoom_Text_Raizen_OnDefeat
# 146 "data/maps/RestRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 147 "data/maps/RestRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 149 "data/maps/RestRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RestRoom_EventScript_Raizen_9
# 160 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 161 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 162 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
RestRoom_EventScript_Raizen_8:
# 165 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 166 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return

RestRoom_EventScript_Raizen_2:
# 131 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_TalkOnly
	goto RestRoom_EventScript_Raizen_1

RestRoom_EventScript_Raizen_5:
# 135 "data/maps/RestRoom/scripts.pory"
	call RestRoom_EventScript_Raizen_IntroRematch
	goto RestRoom_EventScript_Raizen_4

RestRoom_EventScript_Raizen_9:
# 150 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 151 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 152 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 153 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 154 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 155 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_REST_ROOM_RAIZEN, RestRoom_EventScript_Raizen_12
	goto RestRoom_EventScript_Raizen_8

RestRoom_EventScript_Raizen_12:
# 156 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_DEFEATED_REST_ROOM_RAIZEN
# 157 "data/maps/RestRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatTranslatorRaizen
	goto RestRoom_EventScript_Raizen_8


RestRoom_EventScript_Shop::
# 174 "data/maps/RestRoom/scripts.pory"
	lock
# 175 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 176 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Shop_4
RestRoom_EventScript_Shop_3:
# 182 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_1
# 183 "data/maps/RestRoom/scripts.pory"
	waitmessage
RestRoom_EventScript_Shop_1:
# 185 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 186 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 187 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 188 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Shop_2:
# 177 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 178 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 179 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto RestRoom_EventScript_Shop_1

RestRoom_EventScript_Shop_4:
# 176 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, RestRoom_EventScript_Shop_2
	goto RestRoom_EventScript_Shop_3


RestRoom_EventScript_Pokebox::
# 193 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 194 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 195 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 196 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 197 "data/maps/RestRoom/scripts.pory"
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

RestRoom_EventScript_PlayerCounterpart_Text_0:
# 58 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué sorpresa, {PLAYER}!$"

RestRoom_EventScript_PlayerCounterpart_Text_1:
# 60 "data/maps/RestRoom/scripts.pory"
	.string "¿Así que también estás participando en\n"
	.string "el desafío?\p"
	.string "¡Cada sala nos enseña algo sobre los\n"
	.string "líderes de la comunidad!\p"
	.string "¡He aprendido mucho de ellos!$"

RestRoom_EventScript_PlayerCounterpart_Text_2:
# 64 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué emocionante!$"

RestRoom_EventScript_Raizen_TalkOnly_Text_0:
# 71 "data/maps/RestRoom/scripts.pory"
	.string "Aunque no lo parezca, vengo de muy\n"
	.string "lejos.\p"
	.string "De Konoha, nada menos.$"

RestRoom_EventScript_Raizen_TalkOnly_Text_1:
# 74 "data/maps/RestRoom/scripts.pory"
	.string "Soy traductor.\p"
	.string "Me llamaron para que todo lo que ocurre\n"
	.string "aquí pudiera conocerse también en\l"
	.string "otras tierras.$"

RestRoom_EventScript_Raizen_TalkOnly_Text_2:
# 76 "data/maps/RestRoom/scripts.pory"
	.string "No es una misión de rango S, ¡pero\n"
	.string "alguien tenía que hacerla!$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_0:
# 83 "data/maps/RestRoom/scripts.pory"
	.string "¡Así que has completado el desafío!$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_1:
# 86 "data/maps/RestRoom/scripts.pory"
	.string "Para mí, ser traductor es sencillo.\p"
	.string "Lo difícil será traducir la paliza que\n"
	.string "pienso darte.$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_2:
# 88 "data/maps/RestRoom/scripts.pory"
	.string "¡Vamos, enséñame de qué eres capaz!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_0:
# 93 "data/maps/RestRoom/scripts.pory"
	.string "¡Has regresado!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_1:
# 96 "data/maps/RestRoom/scripts.pory"
	.string "¿Vienes por la revancha? Admito que no\n"
	.string "esperaba recibir otra misión tan\l"
	.string "pronto.\p"
	.string "Esta vez no habrá pergaminos ni\n"
	.string "palabras que traducir.\p"
	.string "Solo tú, yo y nuestros Pokémon.$"

RestRoom_EventScript_Raizen_IntroRematch_Text_2:
# 99 "data/maps/RestRoom/scripts.pory"
	.string "¿Qué dices?$"

RestRoom_EventScript_Raizen_IntroRematch_Text_3:
# 106 "data/maps/RestRoom/scripts.pory"
	.string "¡Misión aceptada!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_4:
# 109 "data/maps/RestRoom/scripts.pory"
	.string "Prepárate, porque esta vez pienso\n"
	.string "completarla.$"

RestRoom_EventScript_Raizen_IntroRematch_Text_5:
# 114 "data/maps/RestRoom/scripts.pory"
	.string "Entendido. Dejaré esta misión\n"
	.string "pendiente.\p"
	.string "Vuelve cuando estés list{OA}.$"

RestRoom_EventScript_Raizen_Text_0:
# 152 "data/maps/RestRoom/scripts.pory"
	.string "¡Incomprensible!\p"
	.string "Mi estrategia no tuvo traducción en el\n"
	.string "campo de batalla.$"

RestRoom_EventScript_Raizen_Text_1:
# 160 "data/maps/RestRoom/scripts.pory"
	.string "El resultado es claro en cualquier\n"
	.string "idioma: aún te falta mucho por\l"
	.string "aprender.$"

RestRoom_EventScript_Shop_Text_0:
# 177 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¡Hemos ampliado el catálogo!\p"
	.string "Ahora también puedes comprar objetos\n"
	.string "de combate.\p"
	.string "¿En qué puedo ayudarte?\n"
	.string "¡Aquí somos un poco más caros!$"

RestRoom_EventScript_Shop_Text_1:
# 182 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?\n¡Aquí somos un poco más caros!$"

RestRoom_Text_Raizen_OnDefeat::
# 169 "data/maps/RestRoom/scripts.pory"
	.string "No he entendido nada...$"
