HallOfFame_MapScripts::
# 2 "data/maps/HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HallOfFame_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 5 "data/maps/HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, HallOfFame_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

HallOfFame_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, HallOfFame_OnFrame
	.2byte 0

HallOfFame_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, HallOfFame_OnWarp
	.2byte 0


HallOfFame_OnWarp::
# 11 "data/maps/HallOfFame/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


HallOfFame_OnFrame::
# 16 "data/maps/HallOfFame/scripts.pory"
	lockall
# 17 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkUp6
# 18 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp6
# 19 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 20 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterRight
# 21 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 22 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 23 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 24 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkUp5
# 25 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp5
# 26 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 27 "data/maps/HallOfFame/scripts.pory"
	delay 20
# 28 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterRight
# 29 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 30 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 31 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 32 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterUp
# 33 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 34 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 35 "data/maps/HallOfFame/scripts.pory"
	delay 20
# 36 "data/maps/HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 37 "data/maps/HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 38 "data/maps/HallOfFame/scripts.pory"
	delay 40
# 39 "data/maps/HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 40 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_SetGameClearFlags
# 41 "data/maps/HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 42 "data/maps/HallOfFame/scripts.pory"
	special GameClear
# 43 "data/maps/HallOfFame/scripts.pory"
	waitstate
# 44 "data/maps/HallOfFame/scripts.pory"
	releaseall
	end


HallOfFame_EventScript_SetGameClearFlags::
# 49 "data/maps/HallOfFame/scripts.pory"
	call EventScript_ClearWahAdminFlags
# 49 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_COMPLETED
# 50 "data/maps/HallOfFame/scripts.pory"
	special RandomizeWahAdminTeams
	return


HallOfFame_OnFrame_Text_0:
# 23 "data/maps/HallOfFame/scripts.pory"
	.string "TODO$"
