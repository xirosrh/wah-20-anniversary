EventScript_ResetWahChallenge::
# 2 "data/scripts/wah_challenge.pory"
	call EventScript_ClearWahAdminFlags
# 3 "data/scripts/wah_challenge.pory"
	clearflag FLAG_FORCE_DOUBLE_BATTLE
# 4 "data/scripts/wah_challenge.pory"
	clearflag FLAG_INVERSE_BATTLE
# 5 "data/scripts/wah_challenge.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_NONE
	return


EventScript_ClearWahAdminFlags::
# 10 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OMEGA
# 11 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_MAIN
# 12 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OMEGA_ALTERNATIVE
# 14 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GOCE
# 15 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_MAIN
# 16 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GOCE_ALTERNATIVE
# 18 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 19 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_MAIN
# 20 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE
# 21 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_MAIN
# 22 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_WAR_ALTERNATIVE
# 24 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_JACK_JOHNSON
# 25 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN
# 26 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_ALTERNATIVE
# 28 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SCAREX
# 29 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_MAIN
# 30 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SCAREX_ALTERNATIVE
# 32 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_OZUMAS
# 33 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_MAIN
# 34 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_OZUMAS_ALTERNATIVE
# 36 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_COSARARA
# 37 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_MAIN
# 38 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_COSARARA_ALTERNATIVE
# 40 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 41 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_MAIN
# 42 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE
# 43 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_MAIN
# 44 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE
# 46 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_AGUIAR
# 47 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_MAIN
# 48 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE
# 50 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_ANGEL
# 51 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_MAIN
# 52 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_ANGEL_ALTERNATIVE
# 54 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 55 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_MAIN
# 56 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE
# 57 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_MAIN
# 58 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE
# 60 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REY_BOO
# 61 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_MAIN
# 62 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REYBOO_ALTERNATIVE
# 64 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_DAVZERO
# 65 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_MAIN
# 66 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_DAVZERO_ALTERNATIVE
# 68 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 69 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_MAIN
# 70 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE
# 71 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_MAIN
# 72 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE
# 74 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_GALLEGO
# 75 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_MAIN
# 76 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_GALLEGO_ALTERNATIVE
# 78 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_REONEKY
# 79 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_MAIN
# 80 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE
# 82 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_CHEVE
# 83 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_MAIN
# 84 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_CHEVE_ALTERNATIVE
# 86 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_BARO
# 87 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_MAIN
# 88 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_BARO_ALTERNATIVE
# 90 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_KLEIN
# 91 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_MAIN
# 92 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE
# 94 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_PKPOWER
# 95 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_MAIN
# 96 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE
# 98 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_EING
# 99 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_MAIN
# 100 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_EING_ALTERNATIVE
# 102 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_XIROS
# 103 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_MAIN
# 104 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_XIROS_ALTERNATIVE
# 106 "data/scripts/wah_challenge.pory"
	clearflag FLAG_DEFEATED_ADMIN_SERGIO
# 107 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_MAIN
# 108 "data/scripts/wah_challenge.pory"
	cleartrainerflag TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE
# 110 "data/scripts/wah_challenge.pory"
	setvar VAR_SERGIO_ROOM_STATE, 0
	return

