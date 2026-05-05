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
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Boy1_1
# 30 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_1, MSGBOX_AUTOCLOSE
# 31 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 32 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_2, MSGBOX_AUTOCLOSE
# 33 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 34 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 35 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_3, MSGBOX_AUTOCLOSE
# 36 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Boy1_1:
# 15 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 16 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Surprise
# 17 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_AUTOCLOSE
# 24 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 26 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Girl1::
# 42 "data/maps/RestRoom/scripts.pory"
	lock
# 43 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 44 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_0, MSGBOX_AUTOCLOSE
# 45 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 47 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_1, MSGBOX_AUTOCLOSE
# 50 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Boy2::
# 55 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy2_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_PlayerCounterpart::
# 60 "data/maps/RestRoom/scripts.pory"
	lock
# 61 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 62 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 64 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_0, MSGBOX_AUTOCLOSE
# 65 "data/maps/RestRoom/scripts.pory"
	delay 48
# 66 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_1, MSGBOX_AUTOCLOSE
# 67 "data/maps/RestRoom/scripts.pory"
	delay 10
# 68 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 70 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_2, MSGBOX_AUTOCLOSE
# 71 "data/maps/RestRoom/scripts.pory"
	delay 48
# 72 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Shop::
# 77 "data/maps/RestRoom/scripts.pory"
	lock
# 78 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 79 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 80 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 81 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 82 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 83 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 84 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Pokebox::
# 89 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 90 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 91 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 92 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 93 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


RestRoom_EventScript_Boy1_Text_0:
# 17 "data/maps/RestRoom/scripts.pory"
	.string "¿En serio ya ganaste el desafío?\n"
	.string "¿Y decidiste repetirlo?\p"
	.string "Definitivamente no estamos jugando en\n"
	.string "el mismo nivel.\p"
	.string "¡Aún no me he atrevido a continuar!$"

RestRoom_EventScript_Boy1_Text_1:
# 30 "data/maps/RestRoom/scripts.pory"
	.string "¡Uf, al fin una zona de descanso!$"

RestRoom_EventScript_Boy1_Text_2:
# 32 "data/maps/RestRoom/scripts.pory"
	.string "Por un momento pensé que las 21 salas\n"
	.string "eran seguidas sin pausa…$"

RestRoom_EventScript_Boy1_Text_3:
# 35 "data/maps/RestRoom/scripts.pory"
	.string "Voy a ajustar algunos ataques, comprar\n"
	.string "items curativos y seguir.$"

RestRoom_EventScript_Girl1_Text_0:
# 44 "data/maps/RestRoom/scripts.pory"
	.string "¡Los diseños de las salas son\n"
	.string "increíbles!$"

RestRoom_EventScript_Girl1_Text_1:
# 47 "data/maps/RestRoom/scripts.pory"
	.string "Un teatro, una jungla… ¡hasta un cine!\n"
	.string "¿Te imaginas cuánto trabajo hay\l"
	.string "detrás de todo esto?$"

RestRoom_EventScript_Boy2_Text_0:
# 55 "data/maps/RestRoom/scripts.pory"
	.string "¡Los precios de esta tienda son una\n"
	.string "estafa!\p"
	.string "Tendría que haber comprado todo lo\n"
	.string "necesario antes de entrar.$"

RestRoom_EventScript_PlayerCounterpart_Text_0:
# 64 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué sorpresa, {PLAYER}!$"

RestRoom_EventScript_PlayerCounterpart_Text_1:
# 66 "data/maps/RestRoom/scripts.pory"
	.string "¿Así que también estás participando en\n"
	.string "el desafío?\p"
	.string "¡Cada sala nos enseña algo sobre los\n"
	.string "líderes de la comunidad!\p"
	.string "¡He aprendido mucho de ellos!$"

RestRoom_EventScript_PlayerCounterpart_Text_2:
# 70 "data/maps/RestRoom/scripts.pory"
	.string "¡Qué emocionante!$"

RestRoom_EventScript_Shop_Text_0:
# 79 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?\n¡Aquí somos un poco más caros!$"
