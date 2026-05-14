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


RestRoom_EventScript_Shop::
# 71 "data/maps/RestRoom/scripts.pory"
	lock
# 72 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 73 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 74 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 75 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 76 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 77 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 78 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Pokebox::
# 83 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 84 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 85 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 86 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 87 "data/maps/RestRoom/scripts.pory"
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

RestRoom_EventScript_Shop_Text_0:
# 73 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?\n¡Aquí somos un poco más caros!$"
