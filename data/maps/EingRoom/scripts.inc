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
	playse SE_PIN
# 48 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 49 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 50 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/EingRoom/scripts.pory"
	delay 30
# 52 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 53 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 54 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 55 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 56 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 57 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 58 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 59 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 60 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 61 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 62 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 63 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 64 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 65 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 66 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_TRAINER_IN_WATER
# 67 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_TRAINER_IN_WATER, MAP_EING_ROOM
# 68 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_4
# 70 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 71 "data/maps/EingRoom/scripts.pory"
	delay 30
# 72 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 73 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 74 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 75 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 76 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/EingRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 78 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
# 79 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 80 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_Eing::
# 85 "data/maps/EingRoom/scripts.pory"
	lock
# 86 "data/maps/EingRoom/scripts.pory"
	faceplayer
# 87 "data/maps/EingRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_EING, EingRoom_EventScript_Eing_2
# 94 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 95 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_0
# 101 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 102 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 103 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 104 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 105 "data/maps/EingRoom/scripts.pory"
	delay 40
# 106 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 107 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 108 "data/maps/EingRoom/scripts.pory"
	delay 30
# 109 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 110 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_1
# 115 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 116 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 117 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 118 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_2
# 123 "data/maps/EingRoom/scripts.pory"
	delay 30
# 124 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_JumpToPlayerDirection
# 125 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 126 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Versus
# 127 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 128 "data/maps/EingRoom/scripts.pory"
	delay 30
# 129 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_EingBattle
# 130 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_5, speaker = SP_NAME_EING
# 131 "data/maps/EingRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 132 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 133 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_EING
# 134 "data/maps/EingRoom/scripts.pory"
	release
	end

EingRoom_EventScript_Eing_2:
# 88 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, Common_Movement_AngryWithDelay48
# 89 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_EING
# 90 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 91 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_EingBattle::
# 139 "data/maps/EingRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, EingRoom_EventScript_EingBattle_2
# 142 "data/maps/EingRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_EING
# 143 "data/maps/EingRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 144 "data/maps/EingRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EingRoom_EventScript_EingBattle_5
# 147 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_ALTERNATIVE, EingRoom_Text_EingDefeated
EingRoom_EventScript_EingBattle_1:
# 150 "data/maps/EingRoom/scripts.pory"
	special HealPlayerParty
	return

EingRoom_EventScript_EingBattle_2:
# 140 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
	goto EingRoom_EventScript_EingBattle_1

EingRoom_EventScript_EingBattle_5:
# 145 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_Text_EingDefeated
	goto EingRoom_EventScript_EingBattle_1


EingRoom_EventScript_WalkInPlaceEingFacingPlayer::
# 159 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 160 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3
# 164 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4
# 167 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5
# 170 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6
EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1:
	return

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3:
# 162 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4:
# 165 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceUp
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5:
# 168 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceRight
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6:
# 171 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1


EingRoom_EventScript_JumpToPlayerDirection::
# 179 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 180 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 181 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_JumpToPlayerDirection_3
# 184 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_JumpToPlayerDirection_4
# 187 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_JumpToPlayerDirection_5
# 190 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_JumpToPlayerDirection_6
EingRoom_EventScript_JumpToPlayerDirection_1:
	return

EingRoom_EventScript_JumpToPlayerDirection_3:
# 182 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_0
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_4:
# 185 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_1
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_5:
# 188 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_2
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_6:
# 191 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_3
	goto EingRoom_EventScript_JumpToPlayerDirection_1


# 48 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 48 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 48 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 48 "data/maps/EingRoom/scripts.pory"
	delay_16
# 48 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 52 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 52 "data/maps/EingRoom/scripts.pory"
	walk_right
# 52 "data/maps/EingRoom/scripts.pory"
	walk_right
# 52 "data/maps/EingRoom/scripts.pory"
	walk_left
# 52 "data/maps/EingRoom/scripts.pory"
	walk_left
# 52 "data/maps/EingRoom/scripts.pory"
	walk_right
# 52 "data/maps/EingRoom/scripts.pory"
	walk_right
# 52 "data/maps/EingRoom/scripts.pory"
	walk_left
# 52 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 54 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 54 "data/maps/EingRoom/scripts.pory"
	emote_idea
# 54 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 54 "data/maps/EingRoom/scripts.pory"
	delay_16
# 54 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 56 "data/maps/EingRoom/scripts.pory"
	walk_left
# 56 "data/maps/EingRoom/scripts.pory"
	walk_in_place_left
	step_end

# 69 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_4:
# 69 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 69 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 69 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 69 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

# 95 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_0:
# 96 "data/maps/EingRoom/scripts.pory"
	emote_double_exclamation_mark
# 97 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 98 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 98 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 99 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 100 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 110 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_1:
# 111 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 112 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 113 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 114 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 118 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_2:
# 119 "data/maps/EingRoom/scripts.pory"
	face_away_player
# 120 "data/maps/EingRoom/scripts.pory"
	emote_thinking
# 121 "data/maps/EingRoom/scripts.pory"
	delay_16
# 121 "data/maps/EingRoom/scripts.pory"
	delay_16
# 121 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 182 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_0:
# 182 "data/maps/EingRoom/scripts.pory"
	jump_in_place_up_down
	step_end

# 185 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_1:
# 185 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down_up
	step_end

# 188 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_2:
# 188 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left_right
	step_end

# 191 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_3:
# 191 "data/maps/EingRoom/scripts.pory"
	jump_in_place_right_left
	step_end

EingRoom_OnFrame_Text_0:
# 46 "data/maps/EingRoom/scripts.pory"
	.string "Malditos Xiros y Serg!o, que se han\n"
	.string "pirado dejándome a mí con el marrón de\l"
	.string "administrar la página web y el foro…$"

EingRoom_OnFrame_Text_1:
# 49 "data/maps/EingRoom/scripts.pory"
	.string "¡Y yo sin las malditas creedenciales!$"

EingRoom_OnFrame_Text_2:
# 55 "data/maps/EingRoom/scripts.pory"
	.string "A ver si las han tirado al fondo del mar\n"
	.string "como una prueba para desafiarme y ver\l"
	.string "si soy digno de administrar WAH…\p"
	.string "¡Voy a ver si las pesco!$"

EingRoom_OnFrame_Text_3:
# 70 "data/maps/EingRoom/scripts.pory"
	.string "¡Maldita sea! ¿Otro entrenador?$"

EingRoom_OnFrame_Text_4:
# 73 "data/maps/EingRoom/scripts.pory"
	.string "Esto se está pareciendo a mi rutina de\n"
	.string "wildbattles dobles del Hoenn\l"
	.string "Adventures…$"

EingRoom_EventScript_Eing_Text_0:
# 89 "data/maps/EingRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

EingRoom_EventScript_Eing_Text_1:
# 101 "data/maps/EingRoom/scripts.pory"
	.string "¡Coño si tenemos visita! ¿Qué quieres?\n"
	.string "¿No ves que estoy ocupado?$"

EingRoom_EventScript_Eing_Text_2:
# 106 "data/maps/EingRoom/scripts.pory"
	.string "Si quieres un cambio de nick, tendrás\n"
	.string "que esperar y como te pongas tonto te\l"
	.string "baneo, ¿eh?$"

EingRoom_EventScript_Eing_Text_3:
# 115 "data/maps/EingRoom/scripts.pory"
	.string "¿Cómo? ¿Que quieres retarme a un\n"
	.string "combate Pokémon?$"

EingRoom_EventScript_Eing_Text_4:
# 125 "data/maps/EingRoom/scripts.pory"
	.string "Está bien, prepárate porque iré con\n"
	.string "todo, ¡luego no me llores!$"

EingRoom_EventScript_Eing_Text_5:
# 130 "data/maps/EingRoom/scripts.pory"
	.string "Enhorabuena chaval, ahora avanza a la\n"
	.string "siguiente sala y déjame tranquilo, que\l"
	.string "estaba muy ocupado...$"

EingRoom_Text_EingDefeated::
# 154 "data/maps/EingRoom/scripts.pory"
	.string "¡Míralo, si parecía tonto al principio!$"
