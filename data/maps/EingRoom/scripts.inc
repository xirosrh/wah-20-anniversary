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
	compare VAR_TEMP_0, 0
	goto_if_eq EingRoom_OnTransition_2
EingRoom_OnTransition_1:
# 33 "data/maps/EingRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EingRoom_OnTransition_5
EingRoom_OnTransition_4:
	end

EingRoom_OnTransition_2:
# 30 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 31 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_2
	goto EingRoom_OnTransition_1

EingRoom_OnTransition_5:
# 34 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
	goto EingRoom_OnTransition_4


EingRoom_OnFrame::
# 40 "data/maps/EingRoom/scripts.pory"
	release
# 41 "data/maps/EingRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 42 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 43 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 44 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 45 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
# 46 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 47 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 48 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 49 "data/maps/EingRoom/scripts.pory"
	waitse
# 50 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 52 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 53 "data/maps/EingRoom/scripts.pory"
	delay 30
# 54 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 55 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 56 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 57 "data/maps/EingRoom/scripts.pory"
	waitse
# 58 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 59 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_4
# 60 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 61 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_5
# 62 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 63 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 64 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 65 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 66 "data/maps/EingRoom/scripts.pory"
	playse SE_M_DOUBLE_TEAM
# 67 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 68 "data/maps/EingRoom/scripts.pory"
	delay 90
# 69 "data/maps/EingRoom/scripts.pory"
	playse SE_M_DIVE
# 70 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 72 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 73 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 74 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 75 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_TRAINER_IN_WATER
# 76 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_TRAINER_IN_WATER, MAP_EING_ROOM
# 77 "data/maps/EingRoom/scripts.pory"
	waitse
# 78 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 79 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
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
	playse SE_PIN
# 88 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 89 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 90 "data/maps/EingRoom/scripts.pory"
	delay 30
# 91 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 92 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 93 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 94 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 95 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 96 "data/maps/EingRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 97 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
# 98 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 99 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_Eing::
# 104 "data/maps/EingRoom/scripts.pory"
	lock
# 105 "data/maps/EingRoom/scripts.pory"
	faceplayer
# 106 "data/maps/EingRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_EING, EingRoom_EventScript_Eing_2
# 115 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 116 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_0
# 117 "data/maps/EingRoom/scripts.pory"
	waitse
# 118 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 119 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_1
# 120 "data/maps/EingRoom/scripts.pory"
	waitse
# 121 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 122 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_2
# 123 "data/maps/EingRoom/scripts.pory"
	waitse
# 124 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 125 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 127 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 128 "data/maps/EingRoom/scripts.pory"
	delay 40
# 129 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 130 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 131 "data/maps/EingRoom/scripts.pory"
	delay 30
# 132 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 133 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 134 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_3
# 139 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 140 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 141 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_4
# 146 "data/maps/EingRoom/scripts.pory"
	delay 30
# 147 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_JumpToPlayerDirection
# 148 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 149 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 150 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Versus
# 151 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 152 "data/maps/EingRoom/scripts.pory"
	delay 30
# 153 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_EingBattle
# 154 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_5, speaker = SP_NAME_EING
# 155 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 156 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 157 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_EING
# 158 "data/maps/EingRoom/scripts.pory"
	release
	end

EingRoom_EventScript_Eing_2:
# 107 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 108 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 109 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 110 "data/maps/EingRoom/scripts.pory"
	delay 50
# 111 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 112 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_EingBattle::
# 163 "data/maps/EingRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, EingRoom_EventScript_EingBattle_2
# 166 "data/maps/EingRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_EING
# 167 "data/maps/EingRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 168 "data/maps/EingRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EingRoom_EventScript_EingBattle_5
# 171 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_ALTERNATIVE, EingRoom_Text_EingDefeated
EingRoom_EventScript_EingBattle_1:
# 174 "data/maps/EingRoom/scripts.pory"
	special HealPlayerParty
	return

EingRoom_EventScript_EingBattle_2:
# 164 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
	goto EingRoom_EventScript_EingBattle_1

EingRoom_EventScript_EingBattle_5:
# 169 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
	goto EingRoom_EventScript_EingBattle_1


EingRoom_EventScript_WalkInPlaceEingFacingPlayer::
# 183 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 184 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 185 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3
# 188 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4
# 191 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5
# 194 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6
EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1:
	return

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3:
# 186 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4:
# 189 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceUp
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5:
# 192 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceRight
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6:
# 195 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1


EingRoom_EventScript_JumpToPlayerDirection::
# 203 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 204 "data/maps/EingRoom/scripts.pory"
	playse SE_LEDGE
# 205 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 206 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_JumpToPlayerDirection_3
# 209 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_JumpToPlayerDirection_4
# 212 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_JumpToPlayerDirection_5
# 215 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_JumpToPlayerDirection_6
EingRoom_EventScript_JumpToPlayerDirection_1:
	return

EingRoom_EventScript_JumpToPlayerDirection_3:
# 207 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_0
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_4:
# 210 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_1
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_5:
# 213 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_2
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_6:
# 216 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_3
	goto EingRoom_EventScript_JumpToPlayerDirection_1


# 48 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 48 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
	step_end

# 51 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 51 "data/maps/EingRoom/scripts.pory"
	emote_angry
	step_end

# 54 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 54 "data/maps/EingRoom/scripts.pory"
	walk_right
# 54 "data/maps/EingRoom/scripts.pory"
	walk_right
# 54 "data/maps/EingRoom/scripts.pory"
	walk_left
# 54 "data/maps/EingRoom/scripts.pory"
	walk_left
# 54 "data/maps/EingRoom/scripts.pory"
	walk_right
# 54 "data/maps/EingRoom/scripts.pory"
	walk_right
# 54 "data/maps/EingRoom/scripts.pory"
	walk_left
# 54 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 56 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 56 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

# 59 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_4:
# 59 "data/maps/EingRoom/scripts.pory"
	emote_idea
	step_end

# 61 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_5:
# 61 "data/maps/EingRoom/scripts.pory"
	walk_left
# 61 "data/maps/EingRoom/scripts.pory"
	walk_in_place_left
	step_end

# 116 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_0:
# 116 "data/maps/EingRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 119 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_1:
# 119 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 119 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
	step_end

# 122 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_2:
# 122 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 122 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 122 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 134 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_3:
# 135 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 136 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 137 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 138 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 141 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_4:
# 142 "data/maps/EingRoom/scripts.pory"
	face_away_player
# 143 "data/maps/EingRoom/scripts.pory"
	emote_thinking
# 144 "data/maps/EingRoom/scripts.pory"
	delay_16
# 144 "data/maps/EingRoom/scripts.pory"
	delay_16
# 144 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 207 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_0:
# 207 "data/maps/EingRoom/scripts.pory"
	jump_in_place_up_down
	step_end

# 210 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_1:
# 210 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down_up
	step_end

# 213 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_2:
# 213 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left_right
	step_end

# 216 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_3:
# 216 "data/maps/EingRoom/scripts.pory"
	jump_in_place_right_left
	step_end

EingRoom_OnFrame_Text_0:
# 46 "data/maps/EingRoom/scripts.pory"
	.string "Malditos Xiros y Serg!o, que se han\n"
	.string "pirado dejándome a mí con el marrón de\l"
	.string "administrar la página web y el foro…$"

EingRoom_OnFrame_Text_1:
# 52 "data/maps/EingRoom/scripts.pory"
	.string "¡Y yo sin las malditas credenciales!$"

EingRoom_OnFrame_Text_2:
# 60 "data/maps/EingRoom/scripts.pory"
	.string "A ver si las han tirado al fondo del mar\n"
	.string "como una prueba para desafiarme y ver\l"
	.string "si soy digno de administrar WAH…\p"
	.string "¡Voy a ver si las pesco!$"

EingRoom_OnFrame_Text_3:
# 89 "data/maps/EingRoom/scripts.pory"
	.string "¡Maldita sea! ¿Otro entrenador?$"

EingRoom_OnFrame_Text_4:
# 92 "data/maps/EingRoom/scripts.pory"
	.string "Esto se está pareciendo a mi rutina de\n"
	.string "wildbattles dobles del Hoenn\l"
	.string "Adventures…$"

EingRoom_EventScript_Eing_Text_0:
# 109 "data/maps/EingRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

EingRoom_EventScript_Eing_Text_1:
# 124 "data/maps/EingRoom/scripts.pory"
	.string "¡Coño si tenemos visita! ¿Qué quieres?\n"
	.string "¿No ves que estoy ocupado?$"

EingRoom_EventScript_Eing_Text_2:
# 129 "data/maps/EingRoom/scripts.pory"
	.string "Si quieres un cambio de nick, tendrás\n"
	.string "que esperar y como te pongas tonto te\l"
	.string "baneo, ¿eh?$"

EingRoom_EventScript_Eing_Text_3:
# 139 "data/maps/EingRoom/scripts.pory"
	.string "¿Cómo? ¿Que quieres retarme a un\n"
	.string "combate Pokémon?$"

EingRoom_EventScript_Eing_Text_4:
# 148 "data/maps/EingRoom/scripts.pory"
	.string "Está bien, prepárate porque iré con\n"
	.string "todo, ¡luego no me llores!$"

EingRoom_EventScript_Eing_Text_5:
# 154 "data/maps/EingRoom/scripts.pory"
	.string "Enhorabuena chaval, ahora avanza a la\n"
	.string "siguiente sala y déjame tranquilo, que\l"
	.string "estaba muy ocupado...$"

EingRoom_Text_EingDefeated::
# 178 "data/maps/EingRoom/scripts.pory"
	.string "¡Míralo, si parecía tonto al principio!$"
