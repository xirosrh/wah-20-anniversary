TokynWarRoom_MapScripts::
# 7 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TokynWarRoom_OnLoad
# 8 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TokynWarRoom_OnTransition
# 4 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TokynWarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

TokynWarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/TokynWarRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, TokynWarRoom_OnWarp_PlayerTurnNorth
	.2byte 0


TokynWarRoom_OnLoad::
# 13 "data/maps/TokynWarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR, TokynWarRoom_OnLoad_2
TokynWarRoom_OnLoad_1:
	end

TokynWarRoom_OnLoad_2:
# 14 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto TokynWarRoom_OnLoad_1


TokynWarRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


TokynWarRoom_OnTransition::
# 25 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_TokynWar
	end


TokynWarRoom_EventScript_MainCutscene::
# 30 "data/maps/TokynWarRoom/scripts.pory"
	lockall
# 31 "data/maps/TokynWarRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 32 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 33 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 34 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_SurpriseWithDelay48
# 36 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_0
# 37 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 38 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 39 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 40 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_1
# 41 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 42 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_1, speaker = SP_NAME_WAR
# 43 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 44 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_2
# 45 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 47 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 48 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 49 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 51 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 52 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_4
# 53 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 54 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 55 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 56 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 57 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 58 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 59 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 60 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 61 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HappyWithDelay48
# 62 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 63 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 64 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 65 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 66 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 67 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 68 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 69 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 70 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 72 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 73 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 74 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 75 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkRight
# 76 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 77 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_ThinkingWithDelay48
# 78 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 79 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkInPlaceLeft
# 80 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 81 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 82 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 83 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 84 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 85 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 86 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 87 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 88 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkLeft
# 89 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 90 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 91 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_5
# 93 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_6
# 94 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_PLAYER, TokynWarRoom_EventScript_MainCutscene_Movement_7
# 95 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement LOCALID_TOKYNWARROOM_WAR
# 96 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_TokynWarBattle
# 97 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 99 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 100 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 101 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 102 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 103 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 104 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_10
# 105 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 106 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 107 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 108 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_11
# 109 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 110 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 111 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 112 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 113 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_LEDGE
# 114 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_12
# 115 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 116 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 117 "data/maps/TokynWarRoom/scripts.pory"
	delay 40
# 118 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkRight
# 119 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 120 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 121 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 122 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 123 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 124 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 125 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_13
# 126 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_13
# 127 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 128 "data/maps/TokynWarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 129 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TEMP_A, 2
# 130 "data/maps/TokynWarRoom/scripts.pory"
	releaseall
	return


TokynWarRoom_EventScript_War::
# 135 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 136 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 137 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq TokynWarRoom_EventScript_War_2
# 142 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_War_Text_0, speaker = SP_NAME_WAR
# 143 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_XDWithDelay48
# 145 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_War_2:
# 138 "data/maps/TokynWarRoom/scripts.pory"
	release
# 139 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_Tokyn::
# 150 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 151 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 152 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TEMP_A, 0
	goto_if_eq TokynWarRoom_EventScript_Tokyn_2
# 157 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_0, speaker = SP_NAME_TOKYN
# 158 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 159 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 160 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_1, speaker = SP_NAME_TOKYN
# 161 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_Tokyn_2:
# 153 "data/maps/TokynWarRoom/scripts.pory"
	release
# 154 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_MagikarpJumping::
# 167 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 168 "data/maps/TokynWarRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 169 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_BALLOON_RED
# 170 "data/maps/TokynWarRoom/scripts.pory"
	switch VAR_TEMP_0
# 171 "data/maps/TokynWarRoom/scripts.pory"
	case 5, TokynWarRoom_EventScript_MagikarpJumping_3
# 174 "data/maps/TokynWarRoom/scripts.pory"
	case 6, TokynWarRoom_EventScript_MagikarpJumping_4
# 177 "data/maps/TokynWarRoom/scripts.pory"
	case 7, TokynWarRoom_EventScript_MagikarpJumping_5
TokynWarRoom_EventScript_MagikarpJumping_1:
# 181 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 182 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_M_DIVE
# 183 "data/maps/TokynWarRoom/scripts.pory"
	delay 70
# 184 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_LEFT, VAR_TEMP_2
# 185 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_RIGHT, VAR_TEMP_3
# 186 "data/maps/TokynWarRoom/scripts.pory"
	waitse
# 187 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 188 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 189 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 190 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TEMP_A, 1
# 191 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_MagikarpJumping_3:
# 172 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 102, 60, VAR_TEMP_2
# 173 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 166, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_4:
# 175 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 86, 60, VAR_TEMP_2
# 176 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 150, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_5:
# 178 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 70, 60, VAR_TEMP_2
# 179 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 134, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1


TokynWarRoom_EventScript_TokynWarBattle::
# 196 "data/maps/TokynWarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, TokynWarRoom_EventScript_TokynWarBattle_2
# 199 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_TOKYN
# 200 "data/maps/TokynWarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 201 "data/maps/TokynWarRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 202 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_WAR
# 203 "data/maps/TokynWarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 205 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq TokynWarRoom_EventScript_TokynWarBattle_5
# 212 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TokynWarRoom_EventScript_TokynWarBattle_11
# 215 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_ALTERNATIVE, TokynWarRoom_Text_WarDefeated
TokynWarRoom_EventScript_TokynWarBattle_1:
# 219 "data/maps/TokynWarRoom/scripts.pory"
	special HealPlayerParty
	return

TokynWarRoom_EventScript_TokynWarBattle_2:
# 197 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1

TokynWarRoom_EventScript_TokynWarBattle_5:
# 206 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TokynWarRoom_EventScript_TokynWarBattle_8
# 209 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_ALTERNATIVE, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1

TokynWarRoom_EventScript_TokynWarBattle_8:
# 207 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1

TokynWarRoom_EventScript_TokynWarBattle_11:
# 213 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE, TokynWarRoom_Text_TokynDefeated, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_Text_WarDefeated
	goto TokynWarRoom_EventScript_TokynWarBattle_1


# 36 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_0:
# 36 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 36 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 36 "data/maps/TokynWarRoom/scripts.pory"
	face_right
	step_end

# 40 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_1:
# 40 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 40 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 40 "data/maps/TokynWarRoom/scripts.pory"
	face_left
	step_end

# 44 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_2:
# 44 "data/maps/TokynWarRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 48 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_3:
# 48 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
	step_end

# 52 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_4:
# 52 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 52 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 92 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_5:
# 92 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 92 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 92 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 92 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 93 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_6:
# 93 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 93 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 93 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 93 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 94 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_7:
# 94 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 94 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 94 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 94 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 94 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 94 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 94 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 94 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
	step_end

# 98 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_8:
# 98 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 98 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
	step_end

# 103 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_9:
# 103 "data/maps/TokynWarRoom/scripts.pory"
	jump_left
# 103 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 103 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 103 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 104 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_10:
# 104 "data/maps/TokynWarRoom/scripts.pory"
	jump_right
# 104 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 104 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 104 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 108 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_11:
# 108 "data/maps/TokynWarRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 114 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_12:
# 114 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 114 "data/maps/TokynWarRoom/scripts.pory"
	walk_left
	step_end

# 125 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_13:
# 125 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 125 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 125 "data/maps/TokynWarRoom/scripts.pory"
	face_down
	step_end

TokynWarRoom_EventScript_MainCutscene_Text_0:
# 38 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vaya sorpresa! No esperaba ver una\n"
	.string "cara nueva por aquí.$"

TokynWarRoom_EventScript_MainCutscene_Text_1:
# 42 "data/maps/TokynWarRoom/scripts.pory"
	.string "Yo tampoco tengo idea de quién eres,\n"
	.string "pero eso no importa.$"

TokynWarRoom_EventScript_MainCutscene_Text_2:
# 55 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Estamos aquí para verlo!$"

TokynWarRoom_EventScript_MainCutscene_Text_3:
# 59 "data/maps/TokynWarRoom/scripts.pory"
	.string "Es un placer poder participar de esta\n"
	.string "celebración contigo.$"

TokynWarRoom_EventScript_MainCutscene_Text_4:
# 63 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Qué te parece un combate de a dos,\n"
	.string "War?$"

TokynWarRoom_EventScript_MainCutscene_Text_5:
# 73 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Unir fuerzas como en los viejos\n"
	.string "tiempos?$"

TokynWarRoom_EventScript_MainCutscene_Text_6:
# 78 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Hace años no hacemos eso! Pero me\n"
	.string "gusta. Una buena celebración merece\l"
	.string "algo especial.$"

TokynWarRoom_EventScript_MainCutscene_Text_7:
# 83 "data/maps/TokynWarRoom/scripts.pory"
	.string "Entonces está decidido.$"

TokynWarRoom_EventScript_MainCutscene_Text_8:
# 86 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vamos!$"

TokynWarRoom_EventScript_MainCutscene_Text_9:
# 90 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Que gane el mejor!$"

TokynWarRoom_EventScript_MainCutscene_Text_10:
# 116 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Pero qué locura de combate! Hoy sí que\n"
	.string "nos diste trabajo en serio.$"

TokynWarRoom_EventScript_MainCutscene_Text_11:
# 120 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por compartir este momento con\n"
	.string "nosotros. Fue un encuentro digno para\l"
	.string "esta celebración.\p"
	.string "Es increíble cómo un solo combate\n"
	.string "puede traer de vuelta tantas memorias.$"

TokynWarRoom_EventScript_MainCutscene_Text_12:
# 124 "data/maps/TokynWarRoom/scripts.pory"
	.string "Ya puedes seguir, pero recuerda: Nunca\n"
	.string "olvides seguir tus sueños.$"

TokynWarRoom_EventScript_War_Text_0:
# 142 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Quieres otra? ¡Ni loco!\p"
	.string "Tokyn me tira charla motivadora si\n"
	.string "pierdo dos veces seguidas.\p"
	.string "Pero estuvo buenísimo, eh.$"

TokynWarRoom_EventScript_Tokyn_Text_0:
# 157 "data/maps/TokynWarRoom/scripts.pory"
	.string "Me alegra muchísimo haber sido\n"
	.string "convocado para esta celebración.\p"
	.string "Estar acá, compartir un combate así… me\n"
	.string "trajo muy buenos recuerdos.$"

TokynWarRoom_EventScript_Tokyn_Text_1:
# 160 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por hacerlo especial.$"

TokynWarRoom_Text_TokynDefeated::
# 223 "data/maps/TokynWarRoom/scripts.pory"
	.string "Qué bien se sintió este combate… hacía\n"
	.string "tiempo que no disfrutaba uno así.$"

TokynWarRoom_Text_WarDefeated::
# 227 "data/maps/TokynWarRoom/scripts.pory"
	.string "Bueno… ahora sí sé quién eres. Vaya\n"
	.string "forma de presentarte.$"
