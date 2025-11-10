EingRoom_MapScripts::
# 2 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EingRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EingRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/EingRoom/scripts.pory"
	map_script_2 VAR_EING_ROOM_STATE, 0, EingRoom_OnFrame
	.2byte 0


EingRoom_OnFrame::
# 8 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 9 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 5, 7
# 10 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 11 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Fishing
# 12 "data/maps/EingRoom/scripts.pory"
	setvar VAR_EING_ROOM_STATE, 1
# 13 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 14 "data/maps/EingRoom/scripts.pory"
	release
	end

