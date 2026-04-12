HallOfFame_MapScripts::
# 4 "data/maps/HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, HallOfFame_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 7 "data/maps/HallOfFame/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, HallOfFame_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

HallOfFame_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, HallOfFame_OnFrame
	.2byte 0

HallOfFame_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/HallOfFame/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, HallOfFame_OnWarp
	.2byte 0


HallOfFame_OnWarp::
# 13 "data/maps/HallOfFame/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


HallOfFame_OnFrame::
# 18 "data/maps/HallOfFame/scripts.pory"
	lockall
# 19 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkUp3
# 20 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp3
# 21 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 22 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterRight
# 23 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 24 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 25 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 26 "data/maps/HallOfFame/scripts.pory"
	playse SE_PIN
# 27 "data/maps/HallOfFame/scripts.pory"
	applymovementandwait LOCALID_HALLOFFAME_SERGIO, Common_Movement_HappyWithDelay48
# 28 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 29 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkUp4
# 30 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp4
# 31 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 32 "data/maps/HallOfFame/scripts.pory"
	delay 20
# 33 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterRight
# 34 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 35 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 36 "data/maps/HallOfFame/scripts.pory"
	msgbox HallOfFame_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 37 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_HALLOFFAME_SERGIO, Common_Movement_WalkInPlaceFasterUp
# 38 "data/maps/HallOfFame/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 39 "data/maps/HallOfFame/scripts.pory"
	waitmovement 0
# 40 "data/maps/HallOfFame/scripts.pory"
	delay 20
# 41 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_TEMP_1
# 42 "data/maps/HallOfFame/scripts.pory"
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 43 "data/maps/HallOfFame/scripts.pory"
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD
# 44 "data/maps/HallOfFame/scripts.pory"
	delay 40
# 45 "data/maps/HallOfFame/scripts.pory"
	setvar VAR_TEMP_1, 1
# 46 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_SetGameClear
# 47 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_EvalAchievements
# 48 "data/maps/HallOfFame/scripts.pory"
	call HallOfFame_EventScript_ResetWahChallenge
# 49 "data/maps/HallOfFame/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 24
# 50 "data/maps/HallOfFame/scripts.pory"
	special GameClear
# 51 "data/maps/HallOfFame/scripts.pory"
	waitstate
# 52 "data/maps/HallOfFame/scripts.pory"
	releaseall
	end


HallOfFame_EventScript_EvalAchievements::
# 57 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge
# 58 "data/maps/HallOfFame/scripts.pory"
	switch VAR_WAH_CHALLENGE_MODE
# 59 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE, HallOfFame_EventScript_EvalAchievements_3
# 61 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE, HallOfFame_EventScript_EvalAchievements_4
HallOfFame_EventScript_EvalAchievements_1:
# 64 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_5Times
# 65 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_10Times
# 66 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahEachModeTwice
# 67 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_HardMode
# 68 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_WithElectrodeS
	return

HallOfFame_EventScript_EvalAchievements_3:
# 60 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Double
	goto HallOfFame_EventScript_EvalAchievements_1

HallOfFame_EventScript_EvalAchievements_4:
# 62 "data/maps/HallOfFame/scripts.pory"
	call Achievements_EventScript_Eval_WinWahChallenge_Inverse
	goto HallOfFame_EventScript_EvalAchievements_1


HallOfFame_EventScript_SetGameClear::
# 73 "data/maps/HallOfFame/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, HallOfFame_EventScript_SetGameClear_2
HallOfFame_EventScript_SetGameClear_1:
# 77 "data/maps/HallOfFame/scripts.pory"
	switch VAR_WAH_CHALLENGE_MODE
# 78 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD, HallOfFame_EventScript_SetGameClear_6
# 80 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE, HallOfFame_EventScript_SetGameClear_7
# 83 "data/maps/HallOfFame/scripts.pory"
	case VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE, HallOfFame_EventScript_SetGameClear_8
HallOfFame_EventScript_SetGameClear_4:
# 87 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_COMPLETION_COUNT, 1
	return

HallOfFame_EventScript_SetGameClear_2:
# 74 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_COMPLETED
# 75 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_EXPLAIN_NEW_CHALLENGE_MODES
	goto HallOfFame_EventScript_SetGameClear_1

HallOfFame_EventScript_SetGameClear_6:
# 79 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_7:
# 81 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_DOUBLE_COMPLETED
# 82 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4

HallOfFame_EventScript_SetGameClear_8:
# 84 "data/maps/HallOfFame/scripts.pory"
	setflag FLAG_WAH_CHALLENGE_INVERSE_COMPLETED
# 85 "data/maps/HallOfFame/scripts.pory"
	addvar VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT, 1
	goto HallOfFame_EventScript_SetGameClear_4


HallOfFame_EventScript_ResetWahChallenge::
# 92 "data/maps/HallOfFame/scripts.pory"
	call EventScript_ResetWahChallenge
# 93 "data/maps/HallOfFame/scripts.pory"
	special RandomizeWahAdminTeams
	return


HallOfFame_OnFrame_Text_0:
# 25 "data/maps/HallOfFame/scripts.pory"
	.string "¡Bienvenid{OA} al Salón de la Fama!$"

HallOfFame_OnFrame_Text_1:
# 28 "data/maps/HallOfFame/scripts.pory"
	.string "Aquí quedan registrados los nombres y\n"
	.string "Pokémon de quienes lograron superar\l"
	.string "este desafío.$"

HallOfFame_OnFrame_Text_2:
# 36 "data/maps/HallOfFame/scripts.pory"
	.string "¡Es hora de grabar tu nombre en la\n"
	.string "historia de WAH!$"
