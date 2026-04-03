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
	return


EventScript_ClearWahAdminFlags::
# 11 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OMEGA
# 12 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_MAIN
# 13 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_ALTERNATIVE
# 15 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GOCE
# 16 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_MAIN
# 17 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_ALTERNATIVE
# 19 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 20 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_MAIN
# 21 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE
# 22 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_MAIN
# 23 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_ALTERNATIVE
# 25 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_JACK_JOHNSON
# 26 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN
# 27 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_ALTERNATIVE
# 29 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SCAREX
# 30 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_MAIN
# 31 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_ALTERNATIVE
# 33 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OZUMAS
# 34 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_MAIN
# 35 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_ALTERNATIVE
# 37 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_COSARARA
# 38 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_MAIN
# 39 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE
# 41 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 42 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_MAIN
# 43 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE
# 44 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_MAIN
# 45 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE
# 47 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_AGUIAR
# 48 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_MAIN
# 49 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE
# 51 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_ANGEL
# 52 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_MAIN
# 53 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_ALTERNATIVE
# 55 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 56 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_MAIN
# 57 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE
# 58 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_MAIN
# 59 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE
# 61 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REY_BOO
# 62 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_MAIN
# 63 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE
# 65 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_DAVZERO
# 66 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_MAIN
# 67 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE
# 69 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 70 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_MAIN
# 71 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE
# 72 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_MAIN
# 73 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE
# 75 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GALLEGO
# 76 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_MAIN
# 77 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_ALTERNATIVE
# 79 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REONEKY
# 80 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_MAIN
# 81 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE
# 83 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_CHEVE
# 84 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_MAIN
# 85 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_ALTERNATIVE
# 87 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_BARO
# 88 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_MAIN
# 89 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_ALTERNATIVE
# 91 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_KLEIN
# 92 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_MAIN
# 93 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE
# 95 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_PKPOWER
# 96 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_MAIN
# 97 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE
# 99 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_EING
# 100 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_MAIN
# 101 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_ALTERNATIVE
# 103 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_XIROS
# 104 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_MAIN
# 105 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_ALTERNATIVE
# 107 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SERGIO
# 108 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_MAIN
# 109 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE
# 111 "data/scripts/wah_challenge.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
	return

