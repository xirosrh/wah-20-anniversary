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


Achievements_EventScript_Eval_WinWahChallenge_WithElectrodeS::
# 49 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_WITH_ELECTRODES
# 50 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_UnlockAllPokemon::
# 56 "data/scripts/achievements.pory"
	setvar VAR_0x8004, UNLOCK_ALL_POKEMON
# 57 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaborators::
# 62 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS
# 63 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common::
# 68 "data/scripts/achievements.pory"
	delay 30
# 69 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_CheckAndCompleteAchievement
# 70 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Achievements_EventScript_Eval_Common_2
Achievements_EventScript_Eval_Common_1:
	return

Achievements_EventScript_Eval_Common_2:
# 71 "data/scripts/achievements.pory"
	special Special_BufferAchievementTitle
# 72 "data/scripts/achievements.pory"
	playse SE_APPLAUSE
# 73 "data/scripts/achievements.pory"
	special Special_StartAchievementConfetti
# 74 "data/scripts/achievements.pory"
	setflag FLAG_TRANSPARENT_BOX
# 75 "data/scripts/achievements.pory"
	msgbox Achievements_EventScript_Eval_Common_Text_0, MSGBOX_AUTOCLOSE_CENTER
# 76 "data/scripts/achievements.pory"
	special Special_ClearTransparentBox
# 77 "data/scripts/achievements.pory"
	waitse
# 78 "data/scripts/achievements.pory"
	special Special_StopAchievementConfetti
	goto Achievements_EventScript_Eval_Common_1


Achievements_EventScript_Eval_Common_Text_0:
# 75 "data/scripts/achievements.pory"
	.string "¡Felicidades! Has completado el logro:\n"
	.string "“{STR_VAR_1}”$"
