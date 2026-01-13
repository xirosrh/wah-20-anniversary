XirosRoom_MapScripts::
# 2 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, XirosRoom_OnLoad
# 3 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, XirosRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

XirosRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/XirosRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, XirosRoom_OnWarp_PlayerTurnNorth
	.2byte 0


XirosRoom_OnLoad::
# 9 "data/maps/XirosRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_XIROS, XirosRoom_OnLoad_2
XirosRoom_OnLoad_1:
	end

XirosRoom_OnLoad_2:
# 10 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto XirosRoom_OnLoad_1


XirosRoom_OnWarp_PlayerTurnNorth::
# 16 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


XirosRoom_EventScript_Xiros::
# 21 "data/maps/XirosRoom/scripts.pory"
	faceplayer
# 22 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_MAIN, XirosRoom_EventScript_Xiros_Text_0
# 23 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_XIROS
# 24 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 25 "data/maps/XirosRoom/scripts.pory"
	release
	end


XirosRoom_EventScript_Xiros_Text_0:
# 22 "data/maps/XirosRoom/scripts.pory"
	.string "Pendiente$"
