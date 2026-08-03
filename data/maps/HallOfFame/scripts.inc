HallOfFame_MapScripts::
# 3 "data/maps/HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HallOfFame_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 6 "data/maps/HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, HallOfFame_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

HallOfFame_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, HallOfFame_OnFrame
	.2byte 0

HallOfFame_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, HallOfFame_OnWarp
	.2byte 0


HallOfFame_OnWarp::
# 12 "data/maps/HallOfFame/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


HallOfFame_OnFrame::
# 17 "data/maps/HallOfFame/scripts.pory"
	lockall
# 18 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkUp3
# 19 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp3
# 20 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 21 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterRight
# 22 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 23 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 24 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 25 "data/maps/HallOfFame/scripts.pory"
	playse SE_PIN
# 26 "data/maps/HallOfFame/scripts.pory"
	applymovementandwait LOCALID_HALLOFFAME_SERGIO, Common_Movement_HappyWithDelay48
# 27 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 28 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkUp4
# 29 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
# 30 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 31 "data/maps/HallOfFame/scripts.pory"
	delay 20
# 32 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterRight
# 33 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 34 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 35 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 36 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterUp
# 37 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 38 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 39 "data/maps/HallOfFame/scripts.pory"
	delay 20
# 40 "data/maps/HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 41 "data/maps/HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 42 "data/maps/HallOfFame/scripts.pory"
	delay 40
# 43 "data/maps/HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 44 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_SetGameClear
# 45 "data/maps/HallOfFame/scripts.pory"
	special SetWahChallengeFinalAchievementFlags
# 46 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_EvalAchievements
# 47 "data/maps/HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 48 "data/maps/HallOfFame/scripts.pory"
	special GameClear
# 49 "data/maps/HallOfFame/scripts.pory"
	waitstate
# 50 "data/maps/HallOfFame/scripts.pory"
	releaseall
	end


HallOfFame_EventScript_EvalAchievements::
# 55 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge
# 56 "data/maps/HallOfFame/scripts.pory"
	switch VAR_WAH_CHALLENGE_MODE
# 57 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE, HallOfFame_EventScript_EvalAchievements_3
# 59 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE, HallOfFame_EventScript_EvalAchievements_4
# 61 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM, HallOfFame_EventScript_EvalAchievements_5
HallOfFame_EventScript_EvalAchievements_1:
# 64 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_5Times
# 65 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_HardMode
# 66 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_WithElectrodeS
# 67 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_WithoutLegendaries
	return

HallOfFame_EventScript_EvalAchievements_3:
# 58 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Double
	goto HallOfFame_EventScript_EvalAchievements_1

HallOfFame_EventScript_EvalAchievements_4:
# 60 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Inverse
	goto HallOfFame_EventScript_EvalAchievements_1

HallOfFame_EventScript_EvalAchievements_5:
# 62 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Random
	goto HallOfFame_EventScript_EvalAchievements_1


HallOfFame_EventScript_SetGameClear::
# 72 "data/maps/HallOfFame/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, HallOfFame_EventScript_SetGameClear_2
HallOfFame_EventScript_SetGameClear_1:
# 76 "data/maps/HallOfFame/scripts.pory"
	switch VAR_WAH_CHALLENGE_MODE
# 77 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD, HallOfFame_EventScript_SetGameClear_6
# 79 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE, HallOfFame_EventScript_SetGameClear_7
# 82 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE, HallOfFame_EventScript_SetGameClear_8
# 85 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM, HallOfFame_EventScript_SetGameClear_9
HallOfFame_EventScript_SetGameClear_4:
# 89 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_COMPLETION_COUNT, 1
	return

HallOfFame_EventScript_SetGameClear_2:
# 73 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_COMPLETED
# 74 "data/maps/HallOfFame/scripts.pory"
	setvar VAR_EXPLAIN_NEW_CHALLENGE_MODES_LOBBY, 1
	goto HallOfFame_EventScript_SetGameClear_1

HallOfFame_EventScript_SetGameClear_6:
# 78 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_7:
# 80 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_DOUBLE_COMPLETED
# 81 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_8:
# 83 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_INVERSE_COMPLETED
# 84 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_9:
# 86 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_RANDOM_COMPLETED
# 87 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_RANDOM_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4


HallOfFame_OnFrame_Text_0:
# 24 "data/maps/HallOfFame/scripts.pory"
	.string "Welcome to the Hall of Fame!$"

HallOfFame_OnFrame_Text_1:
# 27 "data/maps/HallOfFame/scripts.pory"
	.string "Here the names and Pokémon of those\n"
	.string "who managed to beat this challenge are\l"
	.string "recorded.$"

HallOfFame_OnFrame_Text_2:
# 35 "data/maps/HallOfFame/scripts.pory"
	.string "It's time to carve your name into WAH\n"
	.string "history!$"
