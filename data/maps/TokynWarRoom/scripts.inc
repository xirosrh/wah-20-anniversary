TokynWarRoom_MapScripts::
# 7 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TokynWarRoom_OnLoad
# 4 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TokynWarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

TokynWarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/TokynWarRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, TokynWarRoom_OnWarp_PlayerTurnNorth
	.2byte 0


TokynWarRoom_OnLoad::
# 12 "data/maps/TokynWarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR, TokynWarRoom_OnLoad_2
TokynWarRoom_OnLoad_1:
	end

TokynWarRoom_OnLoad_2:
# 13 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto TokynWarRoom_OnLoad_1


TokynWarRoom_OnWarp_PlayerTurnNorth::
# 19 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


TokynWarRoom_EventScript_MainCutscene::
# 24 "data/maps/TokynWarRoom/scripts.pory"
	lockall
# 25 "data/maps/TokynWarRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 26 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 27 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 28 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 29 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_SurpriseWithDelay48
# 30 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_0
# 31 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 32 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 33 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 34 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_1
# 35 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 36 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_1, speaker = SP_NAME_WAR
# 37 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 38 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_2
# 39 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 41 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 42 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 43 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 44 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 45 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 46 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_4
# 47 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 48 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 49 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 50 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 52 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 53 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 54 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 55 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HappyWithDelay48
# 56 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 57 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 58 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 59 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 60 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 61 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 62 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 63 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 64 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 66 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 67 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 68 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 69 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkRight
# 70 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 71 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_ThinkingWithDelay48
# 72 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 73 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkInPlaceLeft
# 74 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 75 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 76 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 77 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 78 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 79 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 80 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 81 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 82 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkLeft
# 83 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 84 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 85 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 86 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_5
# 87 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_6
# 88 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_PLAYER, TokynWarRoom_EventScript_MainCutscene_Movement_7
# 89 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement LOCALID_TOKYNWARROOM_WAR
# 90 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_TokynWarBattle
# 91 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 93 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 94 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 96 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 98 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_10
# 99 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 100 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 101 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 102 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_11
# 103 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 104 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 106 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 107 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 108 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_12
# 109 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 110 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 111 "data/maps/TokynWarRoom/scripts.pory"
	delay 40
# 112 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkRight
# 113 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 114 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 115 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 116 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 117 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 118 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 119 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_13
# 120 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_13
# 121 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 122 "data/maps/TokynWarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 123 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TEMP_A, 2
# 124 "data/maps/TokynWarRoom/scripts.pory"
	releaseall
	return


TokynWarRoom_EventScript_War::
# 129 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 130 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 131 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq TokynWarRoom_EventScript_War_2
# 136 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_War_Text_0, speaker = SP_NAME_WAR
# 137 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_XDWithDelay48
# 139 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_War_2:
# 132 "data/maps/TokynWarRoom/scripts.pory"
	release
# 133 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_Tokyn::
# 144 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 145 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 146 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq TokynWarRoom_EventScript_Tokyn_2
# 151 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_0, speaker = SP_NAME_TOKYN
# 152 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 153 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 154 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_1, speaker = SP_NAME_TOKYN
# 155 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_Tokyn_2:
# 147 "data/maps/TokynWarRoom/scripts.pory"
	release
# 148 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_MagikarpJumping::
# 161 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 162 "data/maps/TokynWarRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 163 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_BALLOON_RED
# 164 "data/maps/TokynWarRoom/scripts.pory"
	switch VAR_TEMP_0
# 165 "data/maps/TokynWarRoom/scripts.pory"
	case 5, TokynWarRoom_EventScript_MagikarpJumping_3
# 168 "data/maps/TokynWarRoom/scripts.pory"
	case 6, TokynWarRoom_EventScript_MagikarpJumping_4
# 171 "data/maps/TokynWarRoom/scripts.pory"
	case 7, TokynWarRoom_EventScript_MagikarpJumping_5
TokynWarRoom_EventScript_MagikarpJumping_1:
# 175 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 176 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_M_DIVE
# 177 "data/maps/TokynWarRoom/scripts.pory"
	delay 70
# 178 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_LEFT, VAR_TEMP_2
# 179 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_RIGHT, VAR_TEMP_3
# 180 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 181 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 182 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 183 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 184 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TEMP_A, 1
# 185 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_MagikarpJumping_3:
# 166 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 102, 60, VAR_TEMP_2
# 167 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 166, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_4:
# 169 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 86, 60, VAR_TEMP_2
# 170 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 150, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_5:
# 172 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 70, 60, VAR_TEMP_2
# 173 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 134, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1


TokynWarRoom_EventScript_TokynWarBattle::
# 190 "data/maps/TokynWarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, TokynWarRoom_EventScript_TokynWarBattle_2
# 193 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_TOKYN
# 194 "data/maps/TokynWarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 195 "data/maps/TokynWarRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 196 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_WAR
# 197 "data/maps/TokynWarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 199 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq TokynWarRoom_EventScript_TokynWarBattle_5
# 206 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TokynWarRoom_EventScript_TokynWarBattle_11
# 209 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_ALTERNATIVE, TokynWarRoom_Text_WarDefeated
TokynWarRoom_EventScript_TokynWarBattle_1:
# 213 "data/maps/TokynWarRoom/scripts.pory"
	special HealPlayerParty
	return

TokynWarRoom_EventScript_TokynWarBattle_2:
# 191 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1

TokynWarRoom_EventScript_TokynWarBattle_5:
# 200 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TokynWarRoom_EventScript_TokynWarBattle_8
# 203 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_ALTERNATIVE, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1

TokynWarRoom_EventScript_TokynWarBattle_8:
# 201 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1

TokynWarRoom_EventScript_TokynWarBattle_11:
# 207 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1


# 30 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_0:
# 30 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 30 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 30 "data/maps/TokynWarRoom/scripts.pory"
	face_right
	step_end

# 34 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_1:
# 34 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 34 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 34 "data/maps/TokynWarRoom/scripts.pory"
	face_left
	step_end

# 38 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_2:
# 38 "data/maps/TokynWarRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 42 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_3:
# 42 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
	step_end

# 46 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_4:
# 46 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 46 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 86 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_5:
# 86 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 86 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 86 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 86 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_6:
# 87 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 87 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 87 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 87 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 88 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_7:
# 88 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 88 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 88 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 88 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 88 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 88 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 88 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 88 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
	step_end

# 92 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_8:
# 92 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 92 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
	step_end

# 97 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_9:
# 97 "data/maps/TokynWarRoom/scripts.pory"
	jump_left
# 97 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 97 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 97 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 98 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_10:
# 98 "data/maps/TokynWarRoom/scripts.pory"
	jump_right
# 98 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 98 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 98 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 102 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_11:
# 102 "data/maps/TokynWarRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 108 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_12:
# 108 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 108 "data/maps/TokynWarRoom/scripts.pory"
	walk_left
	step_end

# 119 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_13:
# 119 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 119 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 119 "data/maps/TokynWarRoom/scripts.pory"
	face_down
	step_end

TokynWarRoom_EventScript_MainCutscene_Text_0:
# 32 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vaya sorpresa! No esperaba ver una\n"
	.string "cara nueva por aquí.$"

TokynWarRoom_EventScript_MainCutscene_Text_1:
# 36 "data/maps/TokynWarRoom/scripts.pory"
	.string "Yo tampoco tengo idea de quién eres,\n"
	.string "pero eso no importa.$"

TokynWarRoom_EventScript_MainCutscene_Text_2:
# 49 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Estamos aquí para verlo!$"

TokynWarRoom_EventScript_MainCutscene_Text_3:
# 53 "data/maps/TokynWarRoom/scripts.pory"
	.string "Es un placer poder participar de esta\n"
	.string "celebración contigo.$"

TokynWarRoom_EventScript_MainCutscene_Text_4:
# 57 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Qué te parece un combate de a dos,\n"
	.string "War?$"

TokynWarRoom_EventScript_MainCutscene_Text_5:
# 67 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Unir fuerzas como en los viejos\n"
	.string "tiempos?$"

TokynWarRoom_EventScript_MainCutscene_Text_6:
# 72 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Hace años no hacemos eso! Pero me\n"
	.string "gusta. Una buena celebración merece\l"
	.string "algo especial.$"

TokynWarRoom_EventScript_MainCutscene_Text_7:
# 77 "data/maps/TokynWarRoom/scripts.pory"
	.string "Entonces está decidido.$"

TokynWarRoom_EventScript_MainCutscene_Text_8:
# 80 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vamos!$"

TokynWarRoom_EventScript_MainCutscene_Text_9:
# 84 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Que gane el mejor!$"

TokynWarRoom_EventScript_MainCutscene_Text_10:
# 110 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Pero qué locura de combate! Hoy sí que\n"
	.string "nos diste trabajo en serio.$"

TokynWarRoom_EventScript_MainCutscene_Text_11:
# 114 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por compartir este momento con\n"
	.string "nosotros. Fue un encuentro digno para\l"
	.string "esta celebración.\p"
	.string "Es increíble cómo un solo combate\n"
	.string "puede traer de vuelta tantas memorias.$"

TokynWarRoom_EventScript_MainCutscene_Text_12:
# 118 "data/maps/TokynWarRoom/scripts.pory"
	.string "Ya puedes seguir, pero recuerda: Nunca\n"
	.string "olvides seguir tus sueños.$"

TokynWarRoom_EventScript_War_Text_0:
# 136 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Quieres otra? ¡Ni loco!\p"
	.string "Tokyn me tira charla motivadora si\n"
	.string "pierdo dos veces seguidas.\p"
	.string "Pero estuvo buenísimo, eh.$"

TokynWarRoom_EventScript_Tokyn_Text_0:
# 151 "data/maps/TokynWarRoom/scripts.pory"
	.string "Me alegra muchísimo haber sido\n"
	.string "convocado para esta celebración.\p"
	.string "Estar acá, compartir un combate así… me\n"
	.string "trajo muy buenos recuerdos.$"

TokynWarRoom_EventScript_Tokyn_Text_1:
# 154 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por hacerlo especial.$"

TokynWarRoom_Text_TokynDefeated::
# 217 "data/maps/TokynWarRoom/scripts.pory"
	.string "Qué bien se sintió este combate… hacía\n"
	.string "tiempo que no disfrutaba uno así.$"

TokynWarRoom_Text_WarDefeated::
# 221 "data/maps/TokynWarRoom/scripts.pory"
	.string "Bueno… ahora sí sé quién eres. Vaya\n"
	.string "forma de presentarte.$"
