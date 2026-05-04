EventScript_ResetWahChallenge::
# 2 "data/scripts/wah_challenge.pory"
	call EventScript_ClearWahAdminFlags
# 3 "data/scripts/wah_challenge.pory"
	clearflag FLAG_FORCE_DOUBLE_BATTLE
# 4 "data/scripts/wah_challenge.pory"
	clearflag FLAG_INVERSE_BATTLE
# 5 "data/scripts/wah_challenge.pory"
	clearflag FLAG_WAH_CHALLENGE_STARTED_WITH_ELECTRODES
# 6 "data/scripts/wah_challenge.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_NONE
# 7 "data/scripts/wah_challenge.pory"
	special RandomizeWahAdminTeams
	return


EventScript_ClearWahAdminFlags::
# 12 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OMEGA
# 13 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_MAIN
# 14 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_ALTERNATIVE
# 16 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GOCE
# 17 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_MAIN
# 18 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_ALTERNATIVE
# 20 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 21 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_MAIN
# 22 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE
# 23 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_MAIN
# 24 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_ALTERNATIVE
# 26 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_JACK_JOHNSON
# 27 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN
# 28 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_ALTERNATIVE
# 30 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SCAREX
# 31 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_MAIN
# 32 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_ALTERNATIVE
# 34 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OZUMAS
# 35 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_MAIN
# 36 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_ALTERNATIVE
# 38 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_COSARARA
# 39 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_MAIN
# 40 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE
# 42 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 43 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_MAIN
# 44 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE
# 45 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_MAIN
# 46 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE
# 48 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_AGUIAR
# 49 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_MAIN
# 50 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE
# 52 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_ANGEL
# 53 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_MAIN
# 54 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_ALTERNATIVE
# 56 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 57 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_MAIN
# 58 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE
# 59 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_MAIN
# 60 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE
# 62 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REY_BOO
# 63 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_MAIN
# 64 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE
# 66 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_DAVZERO
# 67 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_MAIN
# 68 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE
# 70 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 71 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_MAIN
# 72 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE
# 73 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_MAIN
# 74 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE
# 76 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GALLEGO
# 77 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_MAIN
# 78 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_ALTERNATIVE
# 80 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REONEKY
# 81 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_MAIN
# 82 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE
# 84 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_CHEVE
# 85 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_MAIN
# 86 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_ALTERNATIVE
# 88 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_BARO
# 89 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_MAIN
# 90 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_ALTERNATIVE
# 92 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_KLEIN
# 93 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_MAIN
# 94 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE
# 96 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_PKPOWER
# 97 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_MAIN
# 98 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE
# 100 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_EING
# 101 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_MAIN
# 102 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_ALTERNATIVE
# 104 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_XIROS
# 105 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_MAIN
# 106 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_ALTERNATIVE
# 108 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SERGIO
# 109 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_MAIN
# 110 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE
# 112 "data/scripts/wah_challenge.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
	return

