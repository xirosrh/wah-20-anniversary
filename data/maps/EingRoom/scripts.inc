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
	special ShowMapNamePopup
# 42 "data/maps/EingRoom/scripts.pory"
	release
# 43 "data/maps/EingRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 44 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 45 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 46 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 47 "data/maps/EingRoom/scripts.pory"
	special HideMapNamePopUpWindow
# 48 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
# 49 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 50 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 51 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 52 "data/maps/EingRoom/scripts.pory"
	waitse
# 53 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 54 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 55 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 56 "data/maps/EingRoom/scripts.pory"
	delay 30
# 57 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 58 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 59 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 60 "data/maps/EingRoom/scripts.pory"
	waitse
# 61 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 62 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_4
# 63 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 64 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_5
# 65 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 66 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 67 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 68 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 69 "data/maps/EingRoom/scripts.pory"
	playse SE_M_DOUBLE_TEAM
# 70 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 71 "data/maps/EingRoom/scripts.pory"
	delay 90
# 72 "data/maps/EingRoom/scripts.pory"
	playse SE_M_DIVE
# 73 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 75 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 76 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 77 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 78 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_TRAINER_IN_WATER
# 79 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_TRAINER_IN_WATER, MAP_EING_ROOM
# 80 "data/maps/EingRoom/scripts.pory"
	waitse
# 81 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 82 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 83 "data/maps/EingRoom/scripts.pory"
	waitse
# 84 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 85 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 86 "data/maps/EingRoom/scripts.pory"
	waitse
# 87 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 88 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 89 "data/maps/EingRoom/scripts.pory"
	waitse
# 90 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 91 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 92 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 93 "data/maps/EingRoom/scripts.pory"
	delay 30
# 94 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 95 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 96 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 97 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 98 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 99 "data/maps/EingRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 100 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
# 101 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 102 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_Eing::
# 107 "data/maps/EingRoom/scripts.pory"
	lock
# 108 "data/maps/EingRoom/scripts.pory"
	faceplayer
# 109 "data/maps/EingRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_EING, EingRoom_EventScript_Eing_2
# 118 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 119 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_0
# 120 "data/maps/EingRoom/scripts.pory"
	waitse
# 121 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 122 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_1
# 123 "data/maps/EingRoom/scripts.pory"
	waitse
# 124 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 125 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_2
# 126 "data/maps/EingRoom/scripts.pory"
	waitse
# 127 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 128 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 129 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 130 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 131 "data/maps/EingRoom/scripts.pory"
	delay 40
# 132 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 133 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 134 "data/maps/EingRoom/scripts.pory"
	delay 30
# 135 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 136 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 137 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_3
# 142 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 143 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_4
# 149 "data/maps/EingRoom/scripts.pory"
	delay 30
# 150 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_JumpToPlayerDirection
# 151 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 152 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 153 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Versus
# 154 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 155 "data/maps/EingRoom/scripts.pory"
	delay 30
# 156 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_EingBattle
# 157 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 158 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 159 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 160 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_EING
# 161 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 162 "data/maps/EingRoom/scripts.pory"
	release
	end

EingRoom_EventScript_Eing_2:
# 110 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 111 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 112 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 113 "data/maps/EingRoom/scripts.pory"
	delay 50
# 114 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 115 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_EingBattle::
# 167 "data/maps/EingRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, EingRoom_EventScript_EingBattle_2
# 171 "data/maps/EingRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_EING
# 172 "data/maps/EingRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 173 "data/maps/EingRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EingRoom_EventScript_EingBattle_5
# 177 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_ALTERNATIVE, EingRoom_Text_EingDefeated
# 178 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_POKEBOX_WON_EING_ALTERNATIVE
EingRoom_EventScript_EingBattle_1:
	return

EingRoom_EventScript_EingBattle_2:
# 168 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
# 169 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_POKEBOX_WON_EING_MAIN
	goto EingRoom_EventScript_EingBattle_1

EingRoom_EventScript_EingBattle_5:
# 174 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
# 175 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_POKEBOX_WON_EING_MAIN
	goto EingRoom_EventScript_EingBattle_1


EingRoom_EventScript_WalkInPlaceEingFacingPlayer::
# 189 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 190 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 191 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3
# 194 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4
# 197 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5
# 200 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6
EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1:
	return

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3:
# 192 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4:
# 195 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceUp
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5:
# 198 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceRight
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6:
# 201 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1


EingRoom_EventScript_JumpToPlayerDirection::
# 209 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 210 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 211 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 212 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_JumpToPlayerDirection_3
# 215 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_JumpToPlayerDirection_4
# 218 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_JumpToPlayerDirection_5
# 221 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_JumpToPlayerDirection_6
EingRoom_EventScript_JumpToPlayerDirection_1:
	return

EingRoom_EventScript_JumpToPlayerDirection_3:
# 213 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_0
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_4:
# 216 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_1
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_5:
# 219 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_2
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_6:
# 222 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_3
	goto EingRoom_EventScript_JumpToPlayerDirection_1


EingRoom_EventScript_Flotador::
# 230 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Flotador_Text_0, MSGBOX_SIGN
	end


EingRoom_EventScript_Taburete::
# 236 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Taburete_Text_0, MSGBOX_SIGN
	end


EingRoom_EventScript_Cubo::
# 242 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Cubo_Text_0, MSGBOX_SIGN
	end


# 51 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 51 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
	step_end

# 54 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 54 "data/maps/EingRoom/scripts.pory"
	emote_angry
	step_end

# 57 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 57 "data/maps/EingRoom/scripts.pory"
	walk_right
# 57 "data/maps/EingRoom/scripts.pory"
	walk_right
# 57 "data/maps/EingRoom/scripts.pory"
	walk_left
# 57 "data/maps/EingRoom/scripts.pory"
	walk_left
# 57 "data/maps/EingRoom/scripts.pory"
	walk_right
# 57 "data/maps/EingRoom/scripts.pory"
	walk_right
# 57 "data/maps/EingRoom/scripts.pory"
	walk_left
# 57 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 59 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 59 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

# 62 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_4:
# 62 "data/maps/EingRoom/scripts.pory"
	emote_idea
	step_end

# 64 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_5:
# 64 "data/maps/EingRoom/scripts.pory"
	walk_left
# 64 "data/maps/EingRoom/scripts.pory"
	walk_in_place_left
	step_end

# 119 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_0:
# 119 "data/maps/EingRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 122 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_1:
# 122 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 122 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
	step_end

# 125 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_2:
# 125 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 125 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 125 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 137 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_3:
# 138 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 139 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 140 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 141 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 144 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_4:
# 145 "data/maps/EingRoom/scripts.pory"
	face_away_player
# 146 "data/maps/EingRoom/scripts.pory"
	emote_thinking
# 147 "data/maps/EingRoom/scripts.pory"
	delay_16
# 147 "data/maps/EingRoom/scripts.pory"
	delay_16
# 147 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 213 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_0:
# 213 "data/maps/EingRoom/scripts.pory"
	jump_in_place_up_down
	step_end

# 216 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_1:
# 216 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down_up
	step_end

# 219 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_2:
# 219 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left_right
	step_end

# 222 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_3:
# 222 "data/maps/EingRoom/scripts.pory"
	jump_in_place_right_left
	step_end

EingRoom_OnFrame_Text_0:
# 49 "data/maps/EingRoom/scripts.pory"
	.string "Damn Xiros and Serg!o, running off and\n"
	.string "leaving me stuck with the hassle of\l"
	.string "running the website and the forum…$"

EingRoom_OnFrame_Text_1:
# 55 "data/maps/EingRoom/scripts.pory"
	.string "And me without the darn credentials!$"

EingRoom_OnFrame_Text_2:
# 63 "data/maps/EingRoom/scripts.pory"
	.string "Maybe they threw them to the bottom of\n"
	.string "the sea as a test to challenge me and\l"
	.string "see if I'm worthy of running WAH…\p"
	.string "I'll go see if I can fish them out!$"

EingRoom_OnFrame_Text_3:
# 92 "data/maps/EingRoom/scripts.pory"
	.string "For crying out loud! Another trainer?$"

EingRoom_OnFrame_Text_4:
# 95 "data/maps/EingRoom/scripts.pory"
	.string "This is starting to feel like my routine\n"
	.string "of double wild battles from Hoenn\l"
	.string "Adventures…$"

EingRoom_EventScript_Eing_Text_0:
# 112 "data/maps/EingRoom/scripts.pory"
	.string "Man, you're persistent, huh? Don't you\n"
	.string "have friends or someone else to\l"
	.string "bother?$"

EingRoom_EventScript_Eing_Text_1:
# 127 "data/maps/EingRoom/scripts.pory"
	.string "Well, if it isn't a visitor! What do you\n"
	.string "want? Can't you see I'm busy?$"

EingRoom_EventScript_Eing_Text_2:
# 132 "data/maps/EingRoom/scripts.pory"
	.string "If you want a nick change, you'll have\n"
	.string "to wait, and if you get cheeky I'll ban\l"
	.string "you, got it?$"

EingRoom_EventScript_Eing_Text_3:
# 142 "data/maps/EingRoom/scripts.pory"
	.string "What? You want to challenge me to a\n"
	.string "Pokémon battle?$"

EingRoom_EventScript_Eing_Text_4:
# 151 "data/maps/EingRoom/scripts.pory"
	.string "Fine, get ready, because I'm going all\n"
	.string "out - no crying to me afterward!$"

EingRoom_EventScript_Eing_Text_5:
# 157 "data/maps/EingRoom/scripts.pory"
	.string "Congrats, kid; now move on to the next\n"
	.string "room and leave me be - I was very busy…$"

EingRoom_EventScript_Flotador_Text_0:
# 230 "data/maps/EingRoom/scripts.pory"
	.string "It's a float ring like the ones\n"
	.string "lifeguards use.$"

EingRoom_EventScript_Taburete_Text_0:
# 236 "data/maps/EingRoom/scripts.pory"
	.string "It's a stool for sitting on.\p"
	.string "But you can't sit on it.$"

EingRoom_EventScript_Cubo_Text_0:
# 242 "data/maps/EingRoom/scripts.pory"
	.string "It's a bucket... for trash?\n"
	.string "Oh, no. Here's the bait.$"

EingRoom_Text_EingDefeated::
# 184 "data/maps/EingRoom/scripts.pory"
	.string "Look at that - and they seemed\n"
	.string "clueless at first!$"
