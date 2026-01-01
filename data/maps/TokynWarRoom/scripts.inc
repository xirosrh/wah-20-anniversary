TokynWarRoom_MapScripts::
# 5 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, TokynWarRoom_OnLoad
# 2 "data/maps/TokynWarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TokynWarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

TokynWarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/TokynWarRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, TokynWarRoom_OnWarp_PlayerTurnNorth
	.2byte 0


TokynWarRoom_OnLoad::
# 10 "data/maps/TokynWarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR, TokynWarRoom_OnLoad_2
TokynWarRoom_OnLoad_1:
	end

TokynWarRoom_OnLoad_2:
# 11 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto TokynWarRoom_OnLoad_1


TokynWarRoom_OnWarp_PlayerTurnNorth::
# 17 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


TokynWarRoom_EventScript_MainCutscene::
# 22 "data/maps/TokynWarRoom/scripts.pory"
	lockall
# 23 "data/maps/TokynWarRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 24 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 25 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 26 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 27 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_SurpriseWithDelay48
# 28 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_0
# 29 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 30 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 31 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 32 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_1
# 33 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 34 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_1, speaker = SP_NAME_WAR
# 35 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 36 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_2
# 37 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 38 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 39 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 40 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 41 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 42 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HappyWithDelay48
# 44 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 45 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 46 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_JumpInPlaceLeft2
# 47 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 48 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 49 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 50 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkRight
# 51 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_ThinkingWithDelay48
# 53 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 54 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkInPlaceLeft
# 55 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 56 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 57 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 58 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 59 "data/maps/TokynWarRoom/scripts.pory"
	delay 30
# 60 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkInPlaceRight
# 61 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 62 "data/maps/TokynWarRoom/scripts.pory"
	delay 20
# 63 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_WalkLeft
# 64 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 65 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 66 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 67 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_3
# 68 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_4
# 69 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_PLAYER, TokynWarRoom_EventScript_MainCutscene_Movement_5
# 70 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement LOCALID_TOKYNWARROOM_WAR
# 72 "data/maps/TokynWarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, TokynWarRoom_EventScript_MainCutscene_2
# 75 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_0x8004, 19
# 76 "data/maps/TokynWarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 77 "data/maps/TokynWarRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 78 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_0x8004, 20
# 79 "data/maps/TokynWarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 81 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq TokynWarRoom_EventScript_MainCutscene_5
# 88 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TokynWarRoom_EventScript_MainCutscene_11
# 91 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_ALTERNATIVE, TokynWarRoom_EventScript_MainCutscene_Text_11
TokynWarRoom_EventScript_MainCutscene_1:
# 95 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_6
# 97 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_7
# 98 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 99 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 100 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_8
# 101 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_WAR
# 102 "data/maps/TokynWarRoom/scripts.pory"
	delay 40
# 103 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_WalkRight
# 104 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 105 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 106 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 107 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 108 "data/maps/TokynWarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 109 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_MainCutscene_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_TOKYN
# 110 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_TOKYN, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 111 "data/maps/TokynWarRoom/scripts.pory"
	applymovement LOCALID_TOKYNWARROOM_WAR, TokynWarRoom_EventScript_MainCutscene_Movement_9
# 112 "data/maps/TokynWarRoom/scripts.pory"
	waitmovement 0
# 113 "data/maps/TokynWarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR
# 114 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TOKYN_WAR_ROOM_STATE, 2
# 115 "data/maps/TokynWarRoom/scripts.pory"
	releaseall
	return

TokynWarRoom_EventScript_MainCutscene_2:
# 73 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_11
	goto TokynWarRoom_EventScript_MainCutscene_1

TokynWarRoom_EventScript_MainCutscene_5:
# 82 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq TokynWarRoom_EventScript_MainCutscene_8
# 85 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_ALTERNATIVE, TokynWarRoom_EventScript_MainCutscene_Text_11
	goto TokynWarRoom_EventScript_MainCutscene_1

TokynWarRoom_EventScript_MainCutscene_8:
# 83 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_11
	goto TokynWarRoom_EventScript_MainCutscene_1

TokynWarRoom_EventScript_MainCutscene_11:
# 89 "data/maps/TokynWarRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_TOKYN_ALTERNATIVE, TokynWarRoom_EventScript_MainCutscene_Text_10, TRAINER_WAH_ADMIN_WAR_MAIN, TokynWarRoom_EventScript_MainCutscene_Text_11
	goto TokynWarRoom_EventScript_MainCutscene_1


TokynWarRoom_EventScript_War::
# 120 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 121 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 122 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TOKYN_WAR_ROOM_STATE, 0
	goto_if_eq TokynWarRoom_EventScript_War_2
# 127 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_War_Text_0, speaker = SP_NAME_WAR
# 128 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 129 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_WAR, Common_Movement_XDWithDelay48
# 130 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_War_2:
# 123 "data/maps/TokynWarRoom/scripts.pory"
	release
# 124 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_Tokyn::
# 135 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 136 "data/maps/TokynWarRoom/scripts.pory"
	faceplayer
# 137 "data/maps/TokynWarRoom/scripts.pory"
	compare VAR_TOKYN_WAR_ROOM_STATE, 0
	goto_if_eq TokynWarRoom_EventScript_Tokyn_2
# 142 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_0, speaker = SP_NAME_TOKYN
# 143 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_TOKYNWARROOM_TOKYN, Common_Movement_HeartWithDelay48
# 145 "data/maps/TokynWarRoom/scripts.pory"
	msgbox TokynWarRoom_EventScript_Tokyn_Text_1, speaker = SP_NAME_TOKYN
# 146 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_Tokyn_2:
# 138 "data/maps/TokynWarRoom/scripts.pory"
	release
# 139 "data/maps/TokynWarRoom/scripts.pory"
	call TokynWarRoom_EventScript_MainCutscene
	end


TokynWarRoom_EventScript_MagikarpJumping::
# 152 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 153 "data/maps/TokynWarRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 154 "data/maps/TokynWarRoom/scripts.pory"
	switch VAR_TEMP_0
# 155 "data/maps/TokynWarRoom/scripts.pory"
	case 5, TokynWarRoom_EventScript_MagikarpJumping_3
# 158 "data/maps/TokynWarRoom/scripts.pory"
	case 6, TokynWarRoom_EventScript_MagikarpJumping_4
# 161 "data/maps/TokynWarRoom/scripts.pory"
	case 7, TokynWarRoom_EventScript_MagikarpJumping_5
TokynWarRoom_EventScript_MagikarpJumping_1:
# 165 "data/maps/TokynWarRoom/scripts.pory"
	delay 70
# 166 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_LEFT, VAR_TEMP_2
# 167 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_RIGHT, VAR_TEMP_3
# 168 "data/maps/TokynWarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 169 "data/maps/TokynWarRoom/scripts.pory"
	playse SE_PIN
# 170 "data/maps/TokynWarRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 171 "data/maps/TokynWarRoom/scripts.pory"
	setvar VAR_TOKYN_WAR_ROOM_STATE, 1
# 172 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

TokynWarRoom_EventScript_MagikarpJumping_3:
# 156 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 102, 60, VAR_TEMP_2
# 157 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 166, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_4:
# 159 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 86, 60, VAR_TEMP_2
# 160 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 150, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1

TokynWarRoom_EventScript_MagikarpJumping_5:
# 162 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 70, 60, VAR_TEMP_2
# 163 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 134, 60, VAR_TEMP_3
	goto TokynWarRoom_EventScript_MagikarpJumping_1


# 28 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_0:
# 28 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 28 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 28 "data/maps/TokynWarRoom/scripts.pory"
	face_right
	step_end

# 32 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_1:
# 32 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 32 "data/maps/TokynWarRoom/scripts.pory"
	walk_down
# 32 "data/maps/TokynWarRoom/scripts.pory"
	face_left
	step_end

# 36 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_2:
# 36 "data/maps/TokynWarRoom/scripts.pory"
	emote_exclamation_mark
# 36 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 36 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 36 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 67 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_3:
# 67 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 67 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 67 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_right
# 67 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 68 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_4:
# 68 "data/maps/TokynWarRoom/scripts.pory"
	emote_versus
# 68 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 68 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 68 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 69 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_5:
# 69 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 69 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 69 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 69 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 69 "data/maps/TokynWarRoom/scripts.pory"
	face_left
# 69 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
# 69 "data/maps/TokynWarRoom/scripts.pory"
	face_right
# 69 "data/maps/TokynWarRoom/scripts.pory"
	delay_8
	step_end

# 96 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_6:
# 96 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 96 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
# 96 "data/maps/TokynWarRoom/scripts.pory"
	jump_left
# 96 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 96 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 96 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 97 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_7:
# 97 "data/maps/TokynWarRoom/scripts.pory"
	emote_x
# 97 "data/maps/TokynWarRoom/scripts.pory"
	lock_facing_direction
# 97 "data/maps/TokynWarRoom/scripts.pory"
	jump_right
# 97 "data/maps/TokynWarRoom/scripts.pory"
	unlock_facing_direction
# 97 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
# 97 "data/maps/TokynWarRoom/scripts.pory"
	delay_16
	step_end

# 100 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_8:
# 100 "data/maps/TokynWarRoom/scripts.pory"
	emote_double_exclamation_mark
# 100 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 100 "data/maps/TokynWarRoom/scripts.pory"
	jump_in_place_left
# 100 "data/maps/TokynWarRoom/scripts.pory"
	walk_left
	step_end

# 110 "data/maps/TokynWarRoom/scripts.pory"
TokynWarRoom_EventScript_MainCutscene_Movement_9:
# 110 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 110 "data/maps/TokynWarRoom/scripts.pory"
	walk_up
# 110 "data/maps/TokynWarRoom/scripts.pory"
	face_down
	step_end

TokynWarRoom_EventScript_MainCutscene_Text_0:
# 30 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vaya sorpresa! No esperaba ver una\n"
	.string "cara nueva por aquí.$"

TokynWarRoom_EventScript_MainCutscene_Text_1:
# 34 "data/maps/TokynWarRoom/scripts.pory"
	.string "Yo tampoco tengo idea de quién eres,\n"
	.string "pero eso no importa.$"

TokynWarRoom_EventScript_MainCutscene_Text_2:
# 37 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Estamos aquí para verlo!$"

TokynWarRoom_EventScript_MainCutscene_Text_3:
# 41 "data/maps/TokynWarRoom/scripts.pory"
	.string "Es un placer poder participar de esta\n"
	.string "celebración contigo.$"

TokynWarRoom_EventScript_MainCutscene_Text_4:
# 45 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Qué te parece un combate de a dos,\n"
	.string "War?$"

TokynWarRoom_EventScript_MainCutscene_Text_5:
# 48 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Unir fuerzas como en los viejos\n"
	.string "tiempos?$"

TokynWarRoom_EventScript_MainCutscene_Text_6:
# 53 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Hace años no hacemos eso! Pero me\n"
	.string "gusta. Una buena celebración merece\l"
	.string "algo especial.$"

TokynWarRoom_EventScript_MainCutscene_Text_7:
# 58 "data/maps/TokynWarRoom/scripts.pory"
	.string "Entonces está decidido.$"

TokynWarRoom_EventScript_MainCutscene_Text_8:
# 61 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Vamos!$"

TokynWarRoom_EventScript_MainCutscene_Text_9:
# 65 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Que gane el mejor!$"

TokynWarRoom_EventScript_MainCutscene_Text_10:
# 73 "data/maps/TokynWarRoom/scripts.pory"
	.string "Qué bien se sintió este combate… hacía\n"
	.string "tiempo que no disfrutaba uno así.$"

TokynWarRoom_EventScript_MainCutscene_Text_11:
# 73 "data/maps/TokynWarRoom/scripts.pory"
	.string "Bueno… ahora sí sé quién eres. Vaya\n"
	.string "forma de presentarte.$"

TokynWarRoom_EventScript_MainCutscene_Text_12:
# 101 "data/maps/TokynWarRoom/scripts.pory"
	.string "¡Pero qué locura de combate! Hoy sí que\n"
	.string "nos diste trabajo en serio.$"

TokynWarRoom_EventScript_MainCutscene_Text_13:
# 105 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por compartir este momento con\n"
	.string "nosotros. Fue un encuentro digno para\l"
	.string "esta celebración.\p"
	.string "Es increíble cómo un solo combate\n"
	.string "puede traer de vuelta tantas memorias.$"

TokynWarRoom_EventScript_MainCutscene_Text_14:
# 109 "data/maps/TokynWarRoom/scripts.pory"
	.string "Ya puedes seguir, pero recuerda: Nunca\n"
	.string "olvides seguir tus sueños.$"

TokynWarRoom_EventScript_War_Text_0:
# 127 "data/maps/TokynWarRoom/scripts.pory"
	.string "¿Quieres otra? ¡Ni loco!\p"
	.string "Tokyn me tira charla motivadora si\n"
	.string "pierdo dos veces seguidas.\p"
	.string "Pero estuvo buenísimo, eh.$"

TokynWarRoom_EventScript_Tokyn_Text_0:
# 142 "data/maps/TokynWarRoom/scripts.pory"
	.string "Me alegra muchísimo haber sido\n"
	.string "convocado para esta celebración.\p"
	.string "Estar acá, compartir un combate así… me\n"
	.string "trajo muy buenos recuerdos.$"

TokynWarRoom_EventScript_Tokyn_Text_1:
# 145 "data/maps/TokynWarRoom/scripts.pory"
	.string "Gracias por hacerlo especial.$"
