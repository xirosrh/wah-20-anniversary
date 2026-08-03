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


Achievements_EventScript_Eval_WinWahChallenge_Random::
# 24 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM
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


Achievements_EventScript_Eval_WinWahChallenge_WithoutLegendaries::
# 55 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_WIN_WAH_CHALLENGE_WITHOUT_LEGENDARIES
# 56 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_UnlockAllPokemon::
# 62 "data/scripts/achievements.pory"
	setvar VAR_0x8004, UNLOCK_ALL_POKEMON
# 63 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_FoundTileKecleon::
# 68 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_FOUND_TILE_KECLEON
# 69 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaborators::
# 74 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS
# 75 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatAllCollaboratorsNoFaints::
# 80 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS_NO_FAINTS
# 81 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common::
# 86 "data/scripts/achievements.pory"
	delay 30
# 87 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_CheckAndCompleteAchievement
# 88 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Achievements_EventScript_Eval_Common_2
Achievements_EventScript_Eval_Common_1:
	return

Achievements_EventScript_Eval_Common_2:
# 89 "data/scripts/achievements.pory"
	special Special_BufferAchievementTitle
# 90 "data/scripts/achievements.pory"
	playse SE_APPLAUSE
# 91 "data/scripts/achievements.pory"
	special Special_StartAchievementConfetti
# 92 "data/scripts/achievements.pory"
	setflag FLAG_TRANSPARENT_BOX
# 93 "data/scripts/achievements.pory"
	msgbox Achievements_EventScript_Eval_Common_Text_0, MSGBOX_AUTOCLOSE_CENTER
# 94 "data/scripts/achievements.pory"
	special Special_ClearTransparentBox
# 95 "data/scripts/achievements.pory"
	waitse
# 96 "data/scripts/achievements.pory"
	special Special_StopAchievementConfetti
# 97 "data/scripts/achievements.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Achievements_EventScript_Eval_Common_1


Pokebox_EventScript_ShowUnlocks::
# 103 "data/scripts/achievements.pory"
	delay 20
# 104 "data/scripts/achievements.pory"
	specialvar VAR_RESULT, Special_FindNextPokeboxUnlock
# 105 "data/scripts/achievements.pory"
	compare VAR_RESULT, TRUE
	goto_if_ne Pokebox_EventScript_ShowUnlocks_2
# 108 "data/scripts/achievements.pory"
	playse SE_PIN
# 109 "data/scripts/achievements.pory"
	showmonpic VAR_0x8005, 10, 3
# 110 "data/scripts/achievements.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8005
# 111 "data/scripts/achievements.pory"
	msgbox Pokebox_EventScript_ShowUnlocks_Text_0, MSGBOX_AUTOCLOSE
# 112 "data/scripts/achievements.pory"
	hidemonpic
# 113 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_UnlockAllPokemon
# 114 "data/scripts/achievements.pory"
	call Pokebox_EventScript_ShowUnlocks
	return

Pokebox_EventScript_ShowUnlocks_2:
	return


Achievements_EventScript_Eval_Avaricia::
# 118 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_AVARICIA
# 119 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_DefeatTranslatorRaizen::
# 124 "data/scripts/achievements.pory"
	setvar VAR_0x8004, ACHIEVEMENT_DEFEAT_TRANSLATOR_RAIZEN
# 125 "data/scripts/achievements.pory"
	call Achievements_EventScript_Eval_Common
	return


Achievements_EventScript_Eval_Common_Text_0:
# 93 "data/scripts/achievements.pory"
	.string "¡Felicidades! Has completado el logro:\n"
	.string "“{STR_VAR_1}”$"

Pokebox_EventScript_ShowUnlocks_Text_0:
# 111 "data/scripts/achievements.pory"
	.string "¡Has desbloqueado a {STR_VAR_1}!\nYa está disponible en la PC.$"
