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


RestRoom_EventScript_Pokebox::
	end


RestRoom_EventScript_Boy1_Text_0:
# 12 "data/maps/RestRoom/scripts.pory"
	.string "PENDIENTE$"
