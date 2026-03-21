Achievements_EventScript_Eval_WinWahChallenge::
# 5 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE
# 6 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_Standard::
# 11 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_STANDARD
# 12 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_Double::
# 17 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_DOUBLE
# 18 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_Random::
# 23 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM
# 24 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllAdmins::
# 29 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_ADMINS
# 30 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_5Times::
# 35 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_5_TIMES
# 36 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_HardMode::
# 41 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_WAH_CHALLENGE_HARD_MODE
# 42 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_UnlockAllPokemon::
# 48 "data/scripts/achievements.pory"
	setvar VAR_0x8004, UNLOCK_ALL_POKEMON
# 49 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaborators::
# 54 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS
# 55 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common::
# 60 "data/scripts/achievements.pory"
	delay 30
# 61 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_CheckAndCompleteAchievement
# 62 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Achievements_EventScript_Eval_Common_2
Achievements_EventScript_Eval_Common_1:
	return

Achievements_EventScript_Eval_Common_2:
# 64 "data/scripts/achievements.pory"
	special Special_BufferAchievementTitle
# 65 "data/scripts/achievements.pory"
	special Special_StartAchievementConfetti
# 66 "data/scripts/achievements.pory"
	msgbox Achievements_EventScript_Eval_Common_Text_0, MSGBOX_AUTOCLOSE_CENTER
# 67 "data/scripts/achievements.pory"
	special Special_StopAchievementConfetti
	goto Achievements_EventScript_Eval_Common_1


Achievements_EventScript_Eval_Common_Text_0:
# 66 "data/scripts/achievements.pory"
	.string "¡Felicidades! Has completado el logro:\n"
	.string "“{STR_VAR_1}”$"
