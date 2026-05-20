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
	clearflag FLAG_WAH_CHALLENGE_STARTED_WITHOUT_LEGENDARIES
# 7 "data/scripts/wah_challenge.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_NONE
# 8 "data/scripts/wah_challenge.pory"
	special RandomizeWahAdminTeams
	return


EventScript_ClearWahAdminFlags::
# 13 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OMEGA
# 14 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_MAIN
# 15 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_ALTERNATIVE
# 17 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GOCE
# 18 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_MAIN
# 19 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_ALTERNATIVE
# 21 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 22 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_MAIN
# 23 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE
# 24 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_MAIN
# 25 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_ALTERNATIVE
# 27 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_JACK_JOHNSON
# 28 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN
# 29 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_ALTERNATIVE
# 31 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SCAREX
# 32 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_MAIN
# 33 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_ALTERNATIVE
# 35 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OZUMAS
# 36 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_MAIN
# 37 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_ALTERNATIVE
# 39 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_COSARARA
# 40 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_MAIN
# 41 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE
# 43 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 44 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_MAIN
# 45 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE
# 46 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_MAIN
# 47 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE
# 49 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_AGUIAR
# 50 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_MAIN
# 51 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE
# 53 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_ANGEL
# 54 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_MAIN
# 55 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_ALTERNATIVE
# 57 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 58 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_MAIN
# 59 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE
# 60 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_MAIN
# 61 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE
# 63 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REY_BOO
# 64 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_MAIN
# 65 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE
# 67 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_DAVZERO
# 68 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_MAIN
# 69 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE
# 71 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 72 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_MAIN
# 73 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE
# 74 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_MAIN
# 75 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE
# 77 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GALLEGO
# 78 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_MAIN
# 79 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_ALTERNATIVE
# 81 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REONEKY
# 82 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_MAIN
# 83 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE
# 85 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_CHEVE
# 86 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_MAIN
# 87 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_ALTERNATIVE
# 89 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_BARO
# 90 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_MAIN
# 91 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_ALTERNATIVE
# 93 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_KLEIN
# 94 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_MAIN
# 95 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE
# 97 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_PKPOWER
# 98 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_MAIN
# 99 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE
# 101 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_EING
# 102 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_MAIN
# 103 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_ALTERNATIVE
# 105 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_XIROS
# 106 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_MAIN
# 107 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_ALTERNATIVE
# 109 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SERGIO
# 110 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_MAIN
# 111 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE
# 113 "data/scripts/wah_challenge.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
	return

