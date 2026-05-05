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
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_Girl1::
# 17 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_PlayerCounterpart::
# 22 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_Shop::
# 27 "data/maps/RestRoom/scripts.pory"
	lock
# 28 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 29 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 30 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 31 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 32 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 33 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 34 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Pokebox::
	end


RestRoom_EventScript_Boy1_Text_0:
# 12 "data/maps/RestRoom/scripts.pory"
	.string "PENDIENTE$"

RestRoom_EventScript_Shop_Text_0:
# 29 "data/maps/RestRoom/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?\n¡Aquí somos un poco más caros!$"
