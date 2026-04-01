Achievements_EventScript_Eval_WinWahChallenge::
# 6 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE
# 7 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_Double::
# 12 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_DOUBLE
# 13 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_Random::
# 18 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM
# 19 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_Inverse::
# 24 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_INVERSE
# 25 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllAdmins::
# 30 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_ADMINS
# 31 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_5Times::
# 36 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_5_TIMES
# 37 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_HardMode::
# 42 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_WAH_CHALLENGE_HARD_MODE
# 43 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_WithoutLegendaries::
# 48 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_WITHOUT_LEGENDARIES
# 49 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_WithElectrodeS::
# 54 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_WITH_ELECTRODES
# 55 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_UnlockAllPokemon::
# 61 "data/scripts/achievements.pory"
	setvar VAR_0x8004, UNLOCK_ALL_POKEMON
# 62 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaborators::
# 67 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS
# 68 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common::
# 73 "data/scripts/achievements.pory"
	delay 30
# 74 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_CheckAndCompleteAchievement
# 75 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Achievements_EventScript_Eval_Common_2
Achievements_EventScript_Eval_Common_1:
	return

Achievements_EventScript_Eval_Common_2:
# 76 "data/scripts/achievements.pory"
	special Special_BufferAchievementTitle
# 77 "data/scripts/achievements.pory"
	playse SE_APPLAUSE
# 78 "data/scripts/achievements.pory"
	special Special_StartAchievementConfetti
# 79 "data/scripts/achievements.pory"
	setflag FLAG_TRANSPARENT_BOX
# 80 "data/scripts/achievements.pory"
	msgbox Achievements_EventScript_Eval_Common_Text_0, MSGBOX_AUTOCLOSE_CENTER
# 81 "data/scripts/achievements.pory"
	special Special_ClearTransparentBox
# 82 "data/scripts/achievements.pory"
	waitse
# 83 "data/scripts/achievements.pory"
	special Special_StopAchievementConfetti
	goto Achievements_EventScript_Eval_Common_1


Achievements_EventScript_Eval_Common_Text_0:
# 80 "data/scripts/achievements.pory"
	.string "¡Felicidades! Has completado el logro:\n"
	.string "“{STR_VAR_1}”$"
