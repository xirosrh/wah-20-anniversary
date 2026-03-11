EingRoom_MapScripts::
# 9 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EingRoom_OnTransition
# 10 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EingRoom_OnLoad
# 6 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EingRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 11 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EingRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

EingRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/EingRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, EingRoom_OnFrame
	.2byte 0

EingRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 12 "data/maps/EingRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, EingRoom_OnWarp_PlayerTurnNorth
	.2byte 0


EingRoom_OnLoad::
# 17 "data/maps/EingRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_EING, EingRoom_OnLoad_2
EingRoom_OnLoad_1:
	end

EingRoom_OnLoad_2:
# 18 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto EingRoom_OnLoad_1


EingRoom_OnWarp_PlayerTurnNorth::
# 24 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


EingRoom_OnTransition::
# 29 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Eing
# 30 "data/maps/EingRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq EingRoom_OnTransition_2
EingRoom_OnTransition_1:
# 34 "data/maps/EingRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EingRoom_OnTransition_5
EingRoom_OnTransition_4:
	end

EingRoom_OnTransition_2:
# 31 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 32 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_2
	goto EingRoom_OnTransition_1

EingRoom_OnTransition_5:
# 35 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
	goto EingRoom_OnTransition_4


EingRoom_OnFrame::
# 41 "data/maps/EingRoom/scripts.pory"
	release
# 42 "data/maps/EingRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 43 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 44 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 45 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
# 47 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 48 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 49 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 50 "data/maps/EingRoom/scripts.pory"
	waitse
# 51 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 53 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 54 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/EingRoom/scripts.pory"
	delay 30
# 56 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 57 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 58 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 59 "data/maps/EingRoom/scripts.pory"
	waitse
# 60 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 61 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_4
# 62 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 63 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_5
# 64 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 65 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 66 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 67 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 68 "data/maps/EingRoom/scripts.pory"
	playse SE_M_DOUBLE_TEAM
# 69 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 70 "data/maps/EingRoom/scripts.pory"
	delay 90
# 71 "data/maps/EingRoom/scripts.pory"
	playse SE_M_DIVE
# 72 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 73 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 74 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 75 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 76 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 77 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_TRAINER_IN_WATER
# 78 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_TRAINER_IN_WATER, MAP_EING_ROOM
# 79 "data/maps/EingRoom/scripts.pory"
	waitse
# 80 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 81 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 82 "data/maps/EingRoom/scripts.pory"
	waitse
# 83 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 84 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 85 "data/maps/EingRoom/scripts.pory"
	waitse
# 86 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 88 "data/maps/EingRoom/scripts.pory"
	waitse
# 89 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 90 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 91 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 92 "data/maps/EingRoom/scripts.pory"
	delay 30
# 93 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 94 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 95 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 96 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 97 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 98 "data/maps/EingRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 99 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
# 100 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 101 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_Eing::
# 106 "data/maps/EingRoom/scripts.pory"
	lock
# 107 "data/maps/EingRoom/scripts.pory"
	faceplayer
# 108 "data/maps/EingRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_EING, EingRoom_EventScript_Eing_2
# 116 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 117 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_0
# 118 "data/maps/EingRoom/scripts.pory"
	waitse
# 119 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 120 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_1
# 121 "data/maps/EingRoom/scripts.pory"
	waitse
# 122 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 123 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_2
# 124 "data/maps/EingRoom/scripts.pory"
	waitse
# 125 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 126 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 127 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 128 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 129 "data/maps/EingRoom/scripts.pory"
	delay 40
# 130 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 131 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 132 "data/maps/EingRoom/scripts.pory"
	delay 30
# 133 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 134 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 135 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_3
# 140 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 141 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 142 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 143 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_4
# 148 "data/maps/EingRoom/scripts.pory"
	delay 30
# 149 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_JumpToPlayerDirection
# 150 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 151 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 152 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Versus
# 153 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 154 "data/maps/EingRoom/scripts.pory"
	delay 30
# 155 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_EingBattle
# 156 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_5, speaker = SP_NAME_EING
# 157 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 158 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 159 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_EING
# 160 "data/maps/EingRoom/scripts.pory"
	release
	end

EingRoom_EventScript_Eing_2:
# 109 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 110 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, Common_Movement_AngryWithDelay48
# 111 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 112 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 113 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_EingBattle::
# 165 "data/maps/EingRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, EingRoom_EventScript_EingBattle_2
# 168 "data/maps/EingRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_EING
# 169 "data/maps/EingRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 170 "data/maps/EingRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EingRoom_EventScript_EingBattle_5
# 173 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_ALTERNATIVE, EingRoom_Text_EingDefeated
EingRoom_EventScript_EingBattle_1:
# 176 "data/maps/EingRoom/scripts.pory"
	special HealPlayerParty
	return

EingRoom_EventScript_EingBattle_2:
# 166 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
	goto EingRoom_EventScript_EingBattle_1

EingRoom_EventScript_EingBattle_5:
# 171 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
	goto EingRoom_EventScript_EingBattle_1


EingRoom_EventScript_WalkInPlaceEingFacingPlayer::
# 185 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 186 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 187 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3
# 190 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4
# 193 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5
# 196 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6
EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1:
	return

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3:
# 188 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4:
# 191 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceUp
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5:
# 194 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceRight
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6:
# 197 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1


EingRoom_EventScript_JumpToPlayerDirection::
# 205 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 206 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 207 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 208 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_JumpToPlayerDirection_3
# 211 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_JumpToPlayerDirection_4
# 214 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_JumpToPlayerDirection_5
# 217 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_JumpToPlayerDirection_6
EingRoom_EventScript_JumpToPlayerDirection_1:
	return

EingRoom_EventScript_JumpToPlayerDirection_3:
# 209 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_0
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_4:
# 212 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_1
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_5:
# 215 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_2
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_6:
# 218 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_3
	goto EingRoom_EventScript_JumpToPlayerDirection_1


# 49 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 49 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
	step_end

# 52 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 52 "data/maps/EingRoom/scripts.pory"
	emote_angry
	step_end

# 56 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 56 "data/maps/EingRoom/scripts.pory"
	walk_right
# 56 "data/maps/EingRoom/scripts.pory"
	walk_right
# 56 "data/maps/EingRoom/scripts.pory"
	walk_left
# 56 "data/maps/EingRoom/scripts.pory"
	walk_left
# 56 "data/maps/EingRoom/scripts.pory"
	walk_right
# 56 "data/maps/EingRoom/scripts.pory"
	walk_right
# 56 "data/maps/EingRoom/scripts.pory"
	walk_left
# 56 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 58 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 58 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

# 61 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_4:
# 61 "data/maps/EingRoom/scripts.pory"
	emote_idea
	step_end

# 63 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_5:
# 63 "data/maps/EingRoom/scripts.pory"
	walk_left
# 63 "data/maps/EingRoom/scripts.pory"
	walk_in_place_left
	step_end

# 117 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_0:
# 117 "data/maps/EingRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 120 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_1:
# 120 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 120 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
	step_end

# 123 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_2:
# 123 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 123 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 123 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 135 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_3:
# 136 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 137 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 138 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 139 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 143 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_4:
# 144 "data/maps/EingRoom/scripts.pory"
	face_away_player
# 145 "data/maps/EingRoom/scripts.pory"
	emote_thinking
# 146 "data/maps/EingRoom/scripts.pory"
	delay_16
# 146 "data/maps/EingRoom/scripts.pory"
	delay_16
# 146 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 209 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_0:
# 209 "data/maps/EingRoom/scripts.pory"
	jump_in_place_up_down
	step_end

# 212 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_1:
# 212 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down_up
	step_end

# 215 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_2:
# 215 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left_right
	step_end

# 218 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_3:
# 218 "data/maps/EingRoom/scripts.pory"
	jump_in_place_right_left
	step_end

EingRoom_OnFrame_Text_0:
# 47 "data/maps/EingRoom/scripts.pory"
	.string "Malditos Xiros y Serg!o, que se han\n"
	.string "pirado dejándome a mí con el marrón de\l"
	.string "administrar la página web y el foro…$"

EingRoom_OnFrame_Text_1:
# 53 "data/maps/EingRoom/scripts.pory"
	.string "¡Y yo sin las malditas credenciales!$"

EingRoom_OnFrame_Text_2:
# 62 "data/maps/EingRoom/scripts.pory"
	.string "A ver si las han tirado al fondo del mar\n"
	.string "como una prueba para desafiarme y ver\l"
	.string "si soy digno de administrar WAH…\p"
	.string "¡Voy a ver si las pesco!$"

EingRoom_OnFrame_Text_3:
# 91 "data/maps/EingRoom/scripts.pory"
	.string "¡Maldita sea! ¿Otro entrenador?$"

EingRoom_OnFrame_Text_4:
# 94 "data/maps/EingRoom/scripts.pory"
	.string "Esto se está pareciendo a mi rutina de\n"
	.string "wildbattles dobles del Hoenn\l"
	.string "Adventures…$"

EingRoom_EventScript_Eing_Text_0:
# 111 "data/maps/EingRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

EingRoom_EventScript_Eing_Text_1:
# 125 "data/maps/EingRoom/scripts.pory"
	.string "¡Coño si tenemos visita! ¿Qué quieres?\n"
	.string "¿No ves que estoy ocupado?$"

EingRoom_EventScript_Eing_Text_2:
# 130 "data/maps/EingRoom/scripts.pory"
	.string "Si quieres un cambio de nick, tendrás\n"
	.string "que esperar y como te pongas tonto te\l"
	.string "baneo, ¿eh?$"

EingRoom_EventScript_Eing_Text_3:
# 140 "data/maps/EingRoom/scripts.pory"
	.string "¿Cómo? ¿Que quieres retarme a un\n"
	.string "combate Pokémon?$"

EingRoom_EventScript_Eing_Text_4:
# 150 "data/maps/EingRoom/scripts.pory"
	.string "Está bien, prepárate porque iré con\n"
	.string "todo, ¡luego no me llores!$"

EingRoom_EventScript_Eing_Text_5:
# 156 "data/maps/EingRoom/scripts.pory"
	.string "Enhorabuena chaval, ahora avanza a la\n"
	.string "siguiente sala y déjame tranquilo, que\l"
	.string "estaba muy ocupado...$"

EingRoom_Text_EingDefeated::
# 180 "data/maps/EingRoom/scripts.pory"
	.string "¡Míralo, si parecía tonto al principio!$"
