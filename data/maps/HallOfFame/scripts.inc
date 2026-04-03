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
	call HallOfFame_EventScript_SetGameClear
# 41 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_EvalAchievements
# 42 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_ResetWahChallenge
# 43 "data/maps/HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 44 "data/maps/HallOfFame/scripts.pory"
	special GameClear
# 45 "data/maps/HallOfFame/scripts.pory"
	waitstate
# 46 "data/maps/HallOfFame/scripts.pory"
	releaseall
	end


HallOfFame_EventScript_EvalAchievements::
# 51 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge
# 52 "data/maps/HallOfFame/scripts.pory"
	switch VAR_WAH_CHALLENGE_MODE
# 53 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE, HallOfFame_EventScript_EvalAchievements_3
# 55 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE, HallOfFame_EventScript_EvalAchievements_4
HallOfFame_EventScript_EvalAchievements_1:
# 58 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_5Times
# 59 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_HardMode
	return

HallOfFame_EventScript_EvalAchievements_3:
# 54 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Double
	goto HallOfFame_EventScript_EvalAchievements_1

HallOfFame_EventScript_EvalAchievements_4:
# 56 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Inverse
	goto HallOfFame_EventScript_EvalAchievements_1


HallOfFame_EventScript_SetGameClear::
# 64 "data/maps/HallOfFame/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, HallOfFame_EventScript_SetGameClear_2
HallOfFame_EventScript_SetGameClear_1:
# 68 "data/maps/HallOfFame/scripts.pory"
	switch VAR_WAH_CHALLENGE_MODE
# 69 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD, HallOfFame_EventScript_SetGameClear_6
# 71 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE, HallOfFame_EventScript_SetGameClear_7
# 74 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE, HallOfFame_EventScript_SetGameClear_8
HallOfFame_EventScript_SetGameClear_4:
# 80 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_COMPLETION_COUNT, 1
	return

HallOfFame_EventScript_SetGameClear_2:
# 65 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_COMPLETED
# 66 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_EXPLAIN_NEW_CHALLENGE_MODES
	goto HallOfFame_EventScript_SetGameClear_1

HallOfFame_EventScript_SetGameClear_6:
# 70 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_7:
# 72 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_DOUBLE_COMPLETED
# 73 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_8:
# 75 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_INVERSE_COMPLETED
# 76 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4


HallOfFame_EventScript_ResetWahChallenge::
# 85 "data/maps/HallOfFame/scripts.pory"
	call EventScript_ResetWahChallenge
# 86 "data/maps/HallOfFame/scripts.pory"
	special RandomizeWahAdminTeams
	return


HallOfFame_OnFrame_Text_0:
# 23 "data/maps/HallOfFame/scripts.pory"
	.string "TODO$"
