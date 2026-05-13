RestRoom_MapScripts::
# 2 "data/maps/RestRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RestRoom_OnTransition
	.byte 0


RestRoom_OnTransition::
# 7 "data/maps/RestRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	end


RestRoom_EventScript_Boy1::
# 12 "data/maps/RestRoom/scripts.pory"
	lock
# 13 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 14 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_AUTOCLOSE
# 15 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 16 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_1, MSGBOX_AUTOCLOSE
# 17 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 19 "data/maps/RestRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRENINJA
# 20 "data/maps/RestRoom/scripts.pory"
	specialvar VAR_RESULT, Special_BufferPokeboxBuyOfferFromSpecies
# 21 "data/maps/RestRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RestRoom_EventScript_Boy1_2
RestRoom_EventScript_Boy1_1:
# 24 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Boy1_2:
# 22 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_2, MSGBOX_AUTOCLOSE
	goto RestRoom_EventScript_Boy1_1


RestRoom_EventScript_Girl1::
# 29 "data/maps/RestRoom/scripts.pory"
	lock
# 30 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 31 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_0, MSGBOX_AUTOCLOSE
# 32 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 33 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 34 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_1, MSGBOX_AUTOCLOSE
# 37 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Boy2::
# 42 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy2_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_PlayerCounterpart::
# 47 "data/maps/RestRoom/scripts.pory"
	lock
# 48 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 49 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 51 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_0, MSGBOX_AUTOCLOSE
# 52 "data/maps/RestRoom/scripts.pory"
	delay 48
# 53 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_1, MSGBOX_AUTOCLOSE
# 54 "data/maps/RestRoom/scripts.pory"
	delay 10
# 55 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 57 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_2, MSGBOX_AUTOCLOSE
# 58 "data/maps/RestRoom/scripts.pory"
	delay 48
# 59 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Shop::
# 64 "data/maps/RestRoom/scripts.pory"
	lock
# 65 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 66 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 67 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 68 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 69 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 70 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 71 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Pokebox::
# 76 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 77 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 78 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 79 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 80 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


RestRoom_EventScript_Boy1_Text_0:
# 14 "data/maps/RestRoom/scripts.pory"
	.string "¡Uf, al fin una zona de descanso!$"

RestRoom_EventScript_Boy1_Text_1:
# 16 "data/maps/RestRoom/scripts.pory"
	.string "Por un momento pensé que las 21 salas\n"
	.string "eran seguidas sin pausa…$"

RestRoom_EventScript_Boy1_Text_2:
# 22 "data/maps/RestRoom/scripts.pory"
	.string "Me viene costando, necesito prepararme\n"
	.string "mejor para las próximas salas.\p"
	.string "Voy a ajustar algunos ataques, comprar\n"
	.string "objetos curativos y…\p"
	.string "¡Creo que compraré un {STR_VAR_1}!\n"
	.string "Vi que en la PC está a solo\l"
	.string "{STR_VAR_2}, ¡está regalado!$"

RestRoom_EventScript_Girl1_Text_0:
# 31 "data/maps/RestRoom/scripts.pory"
	.string "¡Los diseños de las salas son\n"
	.string "increíbles!$"

RestRoom_EventScript_Girl1_Text_1:
# 34 "data/maps/RestRoom/scripts.pory"
	.string "Un teatro, una jungla… ¡hasta un cine!\n"
	.string "¿Te imaginas cuánto trabajo hay\l"
	.string "detrás de todo esto?$"

RestRoom_EventScript_Boy2_Text_0:
# 42 "data/maps/RestRoom/scripts.pory"
	.string "¡Los precios de esta tienda son una\n"
	.string "estafa!\p"
	.string "Tendría que haber comprado todo lo\n"
	.string "necesario antes de entrar.$"

RestRoom_EventScript_PlayerCounterpart_Text_0:
# 51 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué sorpresa, {PLAYER}!$"

RestRoom_EventScript_PlayerCounterpart_Text_1:
# 53 "data/maps/RestRoom/scripts.pory"
	.string "¿Así que también estás participando en\n"
	.string "el desafío?\p"
	.string "¡Cada sala nos enseña algo sobre los\n"
	.string "líderes de la comunidad!\p"
	.string "¡He aprendido mucho de ellos!$"

RestRoom_EventScript_PlayerCounterpart_Text_2:
# 57 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué emocionante!$"

RestRoom_EventScript_Shop_Text_0:
# 66 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?\n¡Aquí somos un poco más caros!$"
