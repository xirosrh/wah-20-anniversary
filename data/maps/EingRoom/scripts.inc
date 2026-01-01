EingRoom_MapScripts::
# 5 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EingRoom_OnTransition
# 2 "data/maps/EingRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EingRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EingRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/EingRoom/scripts.pory"
	map_script_2 VAR_EING_ROOM_STATE, 0, EingRoom_OnFrame
	.2byte 0


EingRoom_OnTransition::
# 9 "data/maps/EingRoom/scripts.pory"
	compare VAR_EING_ROOM_STATE, 0
	goto_if_eq EingRoom_OnTransition_2
EingRoom_OnTransition_1:
# 13 "data/maps/EingRoom/scripts.pory"
	compare VAR_EING_ROOM_STATE, 1
	goto_if_eq EingRoom_OnTransition_5
EingRoom_OnTransition_4:
	end

EingRoom_OnTransition_2:
# 10 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_EING_FISHING
# 11 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_TRAINER_IN_WATER
	goto EingRoom_OnTransition_1

EingRoom_OnTransition_5:
# 14 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
	goto EingRoom_OnTransition_4


EingRoom_OnFrame::
# 20 "data/maps/EingRoom/scripts.pory"
	release
# 21 "data/maps/EingRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 22 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 23 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 24 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 25 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
# 26 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_0
# 27 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 29 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 30 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/EingRoom/scripts.pory"
	delay 30
# 32 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 33 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 34 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 35 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 36 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 37 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 38 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_EINGROOM_HIDE_EING_FISHING
# 39 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 40 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 41 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 42 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_EING_FISHING
# 43 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 44 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 45 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_EINGROOM_HIDE_TRAINER_IN_WATER
# 46 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_TRAINER_IN_WATER
# 47 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_TRAINER_IN_WATER, MAP_EING_ROOM
# 48 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 49 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 50 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 51 "data/maps/EingRoom/scripts.pory"
	delay 30
# 52 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 53 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 54 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 55 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 56 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 57 "data/maps/EingRoom/scripts.pory"
	setvar VAR_EING_ROOM_STATE, 1
# 58 "data/maps/EingRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_EINGROOM_EING, MOVEMENT_TYPE_FACE_LEFT
# 59 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 60 "data/maps/EingRoom/scripts.pory"
	release
	end


EingRoom_EventScript_Eing::
# 65 "data/maps/EingRoom/scripts.pory"
	lock
# 66 "data/maps/EingRoom/scripts.pory"
	faceplayer
# 67 "data/maps/EingRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_EING, EingRoom_EventScript_Eing_2
# 74 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_0
# 81 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_1, MSGBOX_AUTOCLOSE
# 82 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 83 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Angry
# 84 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 85 "data/maps/EingRoom/scripts.pory"
	delay 40
# 86 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_2, MSGBOX_AUTOCLOSE
# 87 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 88 "data/maps/EingRoom/scripts.pory"
	delay 30
# 89 "data/maps/EingRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 90 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_1
# 95 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_3, MSGBOX_AUTOCLOSE
# 96 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 97 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_Eing_Movement_2
# 103 "data/maps/EingRoom/scripts.pory"
	delay 30
# 104 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_JumpToPlayerDirection
# 105 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_4, MSGBOX_AUTOCLOSE
# 106 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_Versus
# 107 "data/maps/EingRoom/scripts.pory"
	call EingRoom_EventScript_WalkInPlaceEingFacingPlayer
# 108 "data/maps/EingRoom/scripts.pory"
	delay 30
# 110 "data/maps/EingRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, EingRoom_EventScript_Eing_5
# 113 "data/maps/EingRoom/scripts.pory"
	setvar VAR_0x8004, 18
# 114 "data/maps/EingRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 115 "data/maps/EingRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EingRoom_EventScript_Eing_8
# 118 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_ALTERNATIVE, EingRoom_EventScript_Eing_Text_5
EingRoom_EventScript_Eing_4:
# 121 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_6
# 122 "data/maps/EingRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 123 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 124 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_EING
# 125 "data/maps/EingRoom/scripts.pory"
	release
	end

EingRoom_EventScript_Eing_2:
# 68 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, Common_Movement_AngryWithDelay48
# 69 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_EventScript_Eing_Text_0, MSGBOX_AUTOCLOSE
# 70 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/EingRoom/scripts.pory"
	release
	end

EingRoom_EventScript_Eing_5:
# 111 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_EventScript_Eing_Text_5
	goto EingRoom_EventScript_Eing_4

EingRoom_EventScript_Eing_8:
# 116 "data/maps/EingRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_EING_MAIN, EingRoom_EventScript_Eing_Text_5
	goto EingRoom_EventScript_Eing_4


EingRoom_EventScript_WalkInPlaceEingFacingPlayer::
# 130 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 131 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 132 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3
# 135 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4
# 138 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5
# 141 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6
EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1:
	return

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_3:
# 133 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_4:
# 136 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceUp
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_5:
# 139 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceRight
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1

EingRoom_EventScript_WalkInPlaceEingFacingPlayer_6:
# 142 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
	goto EingRoom_EventScript_WalkInPlaceEingFacingPlayer_1


EingRoom_EventScript_JumpToPlayerDirection::
# 150 "data/maps/EingRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 151 "data/maps/EingRoom/scripts.pory"
	switch VAR_RESULT
# 152 "data/maps/EingRoom/scripts.pory"
	case DIR_NORTH, EingRoom_EventScript_JumpToPlayerDirection_3
# 155 "data/maps/EingRoom/scripts.pory"
	case DIR_SOUTH, EingRoom_EventScript_JumpToPlayerDirection_4
# 158 "data/maps/EingRoom/scripts.pory"
	case DIR_WEST, EingRoom_EventScript_JumpToPlayerDirection_5
# 161 "data/maps/EingRoom/scripts.pory"
	case DIR_EAST, EingRoom_EventScript_JumpToPlayerDirection_6
EingRoom_EventScript_JumpToPlayerDirection_1:
	return

EingRoom_EventScript_JumpToPlayerDirection_3:
# 153 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_0
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_4:
# 156 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_1
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_5:
# 159 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_2
	goto EingRoom_EventScript_JumpToPlayerDirection_1

EingRoom_EventScript_JumpToPlayerDirection_6:
# 162 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_EventScript_JumpToPlayerDirection_Movement_3
	goto EingRoom_EventScript_JumpToPlayerDirection_1


# 28 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 28 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 28 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 28 "data/maps/EingRoom/scripts.pory"
	delay_16
# 28 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 32 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 32 "data/maps/EingRoom/scripts.pory"
	walk_right
# 32 "data/maps/EingRoom/scripts.pory"
	walk_right
# 32 "data/maps/EingRoom/scripts.pory"
	walk_left
# 32 "data/maps/EingRoom/scripts.pory"
	walk_left
# 32 "data/maps/EingRoom/scripts.pory"
	walk_right
# 32 "data/maps/EingRoom/scripts.pory"
	walk_right
# 32 "data/maps/EingRoom/scripts.pory"
	walk_left
# 32 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 34 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 34 "data/maps/EingRoom/scripts.pory"
	emote_idea
# 34 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 34 "data/maps/EingRoom/scripts.pory"
	delay_16
# 34 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 49 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 49 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 49 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 49 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 49 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

# 75 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_0:
# 76 "data/maps/EingRoom/scripts.pory"
	emote_double_exclamation_mark
# 77 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 78 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 78 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 79 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 80 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 90 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_1:
# 91 "data/maps/EingRoom/scripts.pory"
	lock_facing_direction
# 92 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 93 "data/maps/EingRoom/scripts.pory"
	unlock_facing_direction
# 94 "data/maps/EingRoom/scripts.pory"
	face_player
	step_end

# 98 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_Eing_Movement_2:
# 99 "data/maps/EingRoom/scripts.pory"
	face_away_player
# 100 "data/maps/EingRoom/scripts.pory"
	emote_thinking
# 101 "data/maps/EingRoom/scripts.pory"
	delay_16
# 101 "data/maps/EingRoom/scripts.pory"
	delay_16
# 101 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 153 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_0:
# 153 "data/maps/EingRoom/scripts.pory"
	jump_in_place_up_down
	step_end

# 156 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_1:
# 156 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down_up
	step_end

# 159 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_2:
# 159 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left_right
	step_end

# 162 "data/maps/EingRoom/scripts.pory"
EingRoom_EventScript_JumpToPlayerDirection_Movement_3:
# 162 "data/maps/EingRoom/scripts.pory"
	jump_in_place_right_left
	step_end

EingRoom_OnFrame_Text_0:
# 26 "data/maps/EingRoom/scripts.pory"
	.string "Malditos Xiros y Serg!o, que se han\n"
	.string "pirado dejándome a mí con el marrón de\l"
	.string "administrar la página web y el foro…$"

EingRoom_OnFrame_Text_1:
# 29 "data/maps/EingRoom/scripts.pory"
	.string "¡Y yo sin las malditas creedenciales!$"

EingRoom_OnFrame_Text_2:
# 35 "data/maps/EingRoom/scripts.pory"
	.string "A ver si las han tirado al fondo del mar\n"
	.string "como una prueba para desafiarme y ver\l"
	.string "si soy digno de administrar WAH…\p"
	.string "¡Voy a ver si las pesco!$"

EingRoom_OnFrame_Text_3:
# 50 "data/maps/EingRoom/scripts.pory"
	.string "¡Maldita sea! ¿Otro entrenador?$"

EingRoom_OnFrame_Text_4:
# 53 "data/maps/EingRoom/scripts.pory"
	.string "Esto se está pareciendo a mi rutina de\n"
	.string "wildbattles dobles del Hoenn\l"
	.string "Adventures…$"

EingRoom_EventScript_Eing_Text_0:
# 69 "data/maps/EingRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

EingRoom_EventScript_Eing_Text_1:
# 81 "data/maps/EingRoom/scripts.pory"
	.string "¡Coño si tenemos visita! ¿Qué quieres?\n"
	.string "¿No ves que estoy ocupado?$"

EingRoom_EventScript_Eing_Text_2:
# 86 "data/maps/EingRoom/scripts.pory"
	.string "Si quieres un cambio de nick, tendrás\n"
	.string "que esperar y como te pongas tonto te\l"
	.string "baneo, ¿eh?$"

EingRoom_EventScript_Eing_Text_3:
# 95 "data/maps/EingRoom/scripts.pory"
	.string "¿Cómo? ¿Que quieres retarme a un\n"
	.string "combate Pokémon?$"

EingRoom_EventScript_Eing_Text_4:
# 105 "data/maps/EingRoom/scripts.pory"
	.string "Está bien, prepárate porque iré con\n"
	.string "todo, ¡luego no me llores!$"

EingRoom_EventScript_Eing_Text_5:
# 111 "data/maps/EingRoom/scripts.pory"
	.string "¡Míralo, si parecía tonto al principio!$"

EingRoom_EventScript_Eing_Text_6:
# 121 "data/maps/EingRoom/scripts.pory"
	.string "Enhorabuena chaval, ahora avanza a la\n"
	.string "siguiente sala y déjame tranquilo, que\l"
	.string "estaba muy ocupado...$"
