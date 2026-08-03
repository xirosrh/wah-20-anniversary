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
# 42 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Boy2::
# 47 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy2_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_AStartGaming::
# 52 "data/maps/RestRoom/scripts.pory"
	lock
# 53 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 54 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_AStartGaming_Text_0, MSGBOX_NPC, speaker = SP_NAME_A_START_GAMING
# 55 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
	end


RestRoom_EventScript_PlayerCounterpart::
# 61 "data/maps/RestRoom/scripts.pory"
	lock
# 62 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 63 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 64 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 65 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_0, MSGBOX_AUTOCLOSE
# 66 "data/maps/RestRoom/scripts.pory"
	delay 48
# 67 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_1, MSGBOX_AUTOCLOSE
# 68 "data/maps/RestRoom/scripts.pory"
	delay 10
# 69 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 70 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 71 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_2, MSGBOX_AUTOCLOSE
# 72 "data/maps/RestRoom/scripts.pory"
	delay 48
# 73 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Raizen_TalkOnly::
# 78 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 79 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 80 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 81 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 82 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 83 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 84 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 85 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 86 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return


RestRoom_EventScript_Raizen_IntroFirstBattle::
# 90 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 91 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 93 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 94 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 95 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
	return


RestRoom_EventScript_Raizen_IntroRematch::
# 100 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 101 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 102 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 103 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 104 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 105 "data/maps/RestRoom/scripts.pory"
	setspeaker SP_NAME_RAIZEN
# 106 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Raizen_IntroRematch_Text_2
# 107 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 108 "data/maps/RestRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 109 "data/maps/RestRoom/scripts.pory"
	closemessage
# 110 "data/maps/RestRoom/scripts.pory"
	delay 20
# 111 "data/maps/RestRoom/scripts.pory"
	switch VAR_RESULT
# 112 "data/maps/RestRoom/scripts.pory"
	case 0, RestRoom_EventScript_Raizen_IntroRematch_2
# 118 "data/maps/RestRoom/scripts.pory"
	case 1, RestRoom_EventScript_Raizen_IntroRematch_3
# 121 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 122 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 123 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 124 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return

RestRoom_EventScript_Raizen_IntroRematch_2:
# 113 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 114 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 115 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 116 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
	return

RestRoom_EventScript_Raizen_IntroRematch_3:
# 119 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_TalkOnly
	return


RestRoom_EventScript_Raizen_OnFinishEvent::
# 129 "data/maps/RestRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 130 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Raizen::
# 135 "data/maps/RestRoom/scripts.pory"
	lock
# 136 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 137 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Raizen_2
RestRoom_EventScript_Raizen_1:
# 141 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_REST_ROOM_RAIZEN, RestRoom_EventScript_Raizen_5
# 144 "data/maps/RestRoom/scripts.pory"
	call RestRoom_EventScript_Raizen_IntroFirstBattle
RestRoom_EventScript_Raizen_4:
# 147 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 148 "data/maps/RestRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 149 "data/maps/RestRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 150 "data/maps/RestRoom/scripts.pory"
	waitmovement 0
# 151 "data/maps/RestRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 152 "data/maps/RestRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_TRANSLATOR_RAIZEN, RestRoom_Text_Raizen_OnDefeat
# 153 "data/maps/RestRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 154 "data/maps/RestRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 156 "data/maps/RestRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq RestRoom_EventScript_Raizen_9
# 167 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 168 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 169 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
RestRoom_EventScript_Raizen_8:
# 172 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 173 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_OnFinishEvent
	return

RestRoom_EventScript_Raizen_2:
# 138 "data/maps/RestRoom/scripts.pory"
	goto RestRoom_EventScript_Raizen_TalkOnly
	goto RestRoom_EventScript_Raizen_1

RestRoom_EventScript_Raizen_5:
# 142 "data/maps/RestRoom/scripts.pory"
	call RestRoom_EventScript_Raizen_IntroRematch
	goto RestRoom_EventScript_Raizen_4

RestRoom_EventScript_Raizen_9:
# 157 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 158 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 159 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Raizen_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RAIZEN
# 160 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 161 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 162 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_REST_ROOM_RAIZEN, RestRoom_EventScript_Raizen_12
	goto RestRoom_EventScript_Raizen_8

RestRoom_EventScript_Raizen_12:
# 163 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_DEFEATED_REST_ROOM_RAIZEN
# 164 "data/maps/RestRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatTranslatorRaizen
	goto RestRoom_EventScript_Raizen_8


RestRoom_EventScript_Shop::
# 181 "data/maps/RestRoom/scripts.pory"
	lock
# 182 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 183 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Shop_4
RestRoom_EventScript_Shop_3:
# 189 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_1
# 190 "data/maps/RestRoom/scripts.pory"
	waitmessage
RestRoom_EventScript_Shop_1:
# 192 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 193 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 194 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 195 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Shop_2:
# 184 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 185 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 186 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto RestRoom_EventScript_Shop_1

RestRoom_EventScript_Shop_4:
# 183 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, RestRoom_EventScript_Shop_2
	goto RestRoom_EventScript_Shop_3


RestRoom_EventScript_Pokebox::
# 200 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 201 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 202 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 203 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 204 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


RestRoom_EventScript_Boy1_Text_0:
# 21 "data/maps/RestRoom/scripts.pory"
	.string "Phew, finally a rest area!$"

RestRoom_EventScript_Boy1_Text_1:
# 23 "data/maps/RestRoom/scripts.pory"
	.string "For a moment I thought all 21 rooms\n"
	.string "were back-to-back with no break…$"

RestRoom_EventScript_Boy1_Text_2:
# 29 "data/maps/RestRoom/scripts.pory"
	.string "I'm struggling; I need to prepare better\n"
	.string "for the next rooms.\p"
	.string "I'll tweak some moves, buy some healing\n"
	.string "items, and…\p"
	.string "I think I'll buy a {STR_VAR_1}! I saw\n"
	.string "it's only {STR_VAR_2} in the PC - it's\l"
	.string "a steal!$"

RestRoom_EventScript_Girl1_Text_0:
# 38 "data/maps/RestRoom/scripts.pory"
	.string "The room designs are incredible!$"

RestRoom_EventScript_Girl1_Text_1:
# 41 "data/maps/RestRoom/scripts.pory"
	.string "A theater, a jungle… even a cinema!\p"
	.string "Can you imagine how much work goes into\n"
	.string "all this?$"

RestRoom_EventScript_Boy2_Text_0:
# 47 "data/maps/RestRoom/scripts.pory"
	.string "The prices in this shop are a total\n"
	.string "ripoff!\p"
	.string "I should have bought everything I\n"
	.string "needed before coming in.$"

RestRoom_EventScript_AStartGaming_Text_0:
# 54 "data/maps/RestRoom/scripts.pory"
	.string "En un principio iba a colaborar como\n"
	.string "traductor en los esfuerzos de\l"
	.string "internacionalización.\p"
	.string "Pero al final aquí estoy, ¡disfrutando\n"
	.string "mientras supero el desafío!$"

RestRoom_EventScript_PlayerCounterpart_Text_0:
# 65 "data/maps/RestRoom/scripts.pory"
	.string "What a surprise, {PLAYER}!$"

RestRoom_EventScript_PlayerCounterpart_Text_1:
# 67 "data/maps/RestRoom/scripts.pory"
	.string "So you're taking part in the challenge\n"
	.string "too?\p"
	.string "Every room teaches us something about\n"
	.string "the community's leaders!\p"
	.string "I've learned a lot from them!$"

RestRoom_EventScript_PlayerCounterpart_Text_2:
# 71 "data/maps/RestRoom/scripts.pory"
	.string "How exciting!$"

RestRoom_EventScript_Raizen_TalkOnly_Text_0:
# 78 "data/maps/RestRoom/scripts.pory"
	.string "Aunque no lo parezca, vengo de muy\n"
	.string "lejos.\p"
	.string "De Konoha, nada menos.$"

RestRoom_EventScript_Raizen_TalkOnly_Text_1:
# 81 "data/maps/RestRoom/scripts.pory"
	.string "Soy traductor.\p"
	.string "Me llamaron para que todo lo que ocurre\n"
	.string "aquí pudiera conocerse también en\l"
	.string "otras tierras.$"

RestRoom_EventScript_Raizen_TalkOnly_Text_2:
# 83 "data/maps/RestRoom/scripts.pory"
	.string "No es una misión de rango S, ¡pero\n"
	.string "alguien tenía que hacerla!$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_0:
# 90 "data/maps/RestRoom/scripts.pory"
	.string "¡Así que has completado el desafío!$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_1:
# 93 "data/maps/RestRoom/scripts.pory"
	.string "Para mí, ser traductor es sencillo.\p"
	.string "Lo difícil será traducir la paliza que\n"
	.string "pienso darte.$"

RestRoom_EventScript_Raizen_IntroFirstBattle_Text_2:
# 95 "data/maps/RestRoom/scripts.pory"
	.string "¡Vamos, enséñame de qué eres capaz!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_0:
# 100 "data/maps/RestRoom/scripts.pory"
	.string "¡Has regresado!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_1:
# 103 "data/maps/RestRoom/scripts.pory"
	.string "¿Vienes por la revancha? Admito que no\n"
	.string "esperaba recibir otra misión tan\l"
	.string "pronto.\p"
	.string "Esta vez no habrá pergaminos ni\n"
	.string "palabras que traducir.\p"
	.string "Solo tú, yo y nuestros Pokémon.$"

RestRoom_EventScript_Raizen_IntroRematch_Text_2:
# 106 "data/maps/RestRoom/scripts.pory"
	.string "¿Qué dices?$"

RestRoom_EventScript_Raizen_IntroRematch_Text_3:
# 113 "data/maps/RestRoom/scripts.pory"
	.string "¡Misión aceptada!$"

RestRoom_EventScript_Raizen_IntroRematch_Text_4:
# 116 "data/maps/RestRoom/scripts.pory"
	.string "Prepárate, porque esta vez pienso\n"
	.string "completarla.$"

RestRoom_EventScript_Raizen_IntroRematch_Text_5:
# 121 "data/maps/RestRoom/scripts.pory"
	.string "Entendido. Dejaré esta misión\n"
	.string "pendiente.\p"
	.string "Vuelve cuando estés list{OA}.$"

RestRoom_EventScript_Raizen_Text_0:
# 159 "data/maps/RestRoom/scripts.pory"
	.string "¡Incomprensible!\p"
	.string "Mi estrategia no tuvo traducción en el\n"
	.string "campo de batalla.$"

RestRoom_EventScript_Raizen_Text_1:
# 167 "data/maps/RestRoom/scripts.pory"
	.string "El resultado es claro en cualquier\n"
	.string "idioma: aún te falta mucho por\l"
	.string "aprender.$"

RestRoom_EventScript_Shop_Text_0:
# 184 "data/maps/RestRoom/scripts.pory"
	.string "Hi! We've expanded the catalog!\p"
	.string "Now you can also buy battle items.\p"
	.string "How can I help you?\n"
	.string "We're a little pricier here!$"

RestRoom_EventScript_Shop_Text_1:
# 189 "data/maps/RestRoom/scripts.pory"
	.string "Hi! How can I help you?\nWe're a little pricier here!$"

RestRoom_Text_Raizen_OnDefeat::
# 176 "data/maps/RestRoom/scripts.pory"
	.string "No he entendido nada...$"
