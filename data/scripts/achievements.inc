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


Achievements_EventScript_Eval_WinWahChallenge_Inverse::
# 18 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_INVERSE
# 19 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllAdmins::
# 24 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_ADMINS
# 25 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_5Times::
# 30 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_5_TIMES
# 31 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_HardMode::
# 36 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_WAH_CHALLENGE_HARD_MODE
# 37 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_WithElectrodeS::
# 43 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_WITH_ELECTRODES
# 44 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_WinWahChallenge_WithoutLegendaries::
# 49 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_WITHOUT_LEGENDARIES
# 50 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_UnlockAllPokemon::
# 56 "data/scripts/achievements.pory"
	setvar VAR_0x8004, UNLOCK_ALL_POKEMON
# 57 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_FoundTileKecleon::
# 62 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_FOUND_TILE_KECLEON
# 63 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaborators::
# 68 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS
# 69 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaboratorsNoFaints::
# 74 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS_NO_FAINTS
# 75 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common::
# 80 "data/scripts/achievements.pory"
	delay 30
# 81 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_CheckAndCompleteAchievement
# 82 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Achievements_EventScript_Eval_Common_2
Achievements_EventScript_Eval_Common_1:
	return

Achievements_EventScript_Eval_Common_2:
# 83 "data/scripts/achievements.pory"
	special Special_BufferAchievementTitle
# 84 "data/scripts/achievements.pory"
	playse SE_APPLAUSE
# 85 "data/scripts/achievements.pory"
	special Special_StartAchievementConfetti
# 86 "data/scripts/achievements.pory"
	setflag FLAG_TRANSPARENT_BOX
# 87 "data/scripts/achievements.pory"
	msgbox Achievements_EventScript_Eval_Common_Text_0, MSGBOX_AUTOCLOSE_CENTER
# 88 "data/scripts/achievements.pory"
	special Special_ClearTransparentBox
# 89 "data/scripts/achievements.pory"
	waitse
# 90 "data/scripts/achievements.pory"
	special Special_StopAchievementConfetti
# 91 "data/scripts/achievements.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Achievements_EventScript_Eval_Common_1


Pokebox_EventScript_ShowUnlocks::
# 97 "data/scripts/achievements.pory"
	delay 20
# 98 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_FindNextPokeboxUnlock
# 99 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne Pokebox_EventScript_ShowUnlocks_2
# 102 "data/scripts/achievements.pory"
	playse SE_PIN
# 103 "data/scripts/achievements.pory"
	showmonpic VAR_0x8005, 10, 3
# 104 "data/scripts/achievements.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 105 "data/scripts/achievements.pory"
	msgbox Pokebox_EventScript_ShowUnlocks_Text_0, MSGBOX_AUTOCLOSE
# 106 "data/scripts/achievements.pory"
	hidemonpic
# 107 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_UnlockAllPokemon
# 108 "data/scripts/achievements.pory"
	call Pokebox_EventScript_ShowUnlocks
	return

Pokebox_EventScript_ShowUnlocks_2:
	return


Achievements_EventScript_Eval_Avaricia::
# 112 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_AVARICIA
# 113 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatTranslatorRaizen::
# 118 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_TRANSLATOR_RAIZEN
# 119 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common_Text_0:
# 87 "data/scripts/achievements.pory"
	.string "¡Felicidades! Has completado el logro:\n"
	.string "“{STR_VAR_1}”$"

Pokebox_EventScript_ShowUnlocks_Text_0:
# 105 "data/scripts/achievements.pory"
	.string "¡Has desbloqueado a {STR_VAR_1}!\nYa está disponible en la PC.$"
