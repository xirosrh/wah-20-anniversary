ScarexOzumasRoom_MapScripts::
# 4 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ScarexOzumasRoom_OnTransition
	.byte 0


ScarexOzumasRoom_OnTransition::
# 8 "data/maps/ScarexOzumasRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq ScarexOzumasRoom_OnTransition_2
ScarexOzumasRoom_OnTransition_1:
	end

ScarexOzumasRoom_OnTransition_2:
# 9 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 10 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 11 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxy LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
# 12 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
	goto ScarexOzumasRoom_OnTransition_1


ScarexOzumasRoom_EventScript_EnterRoom::
# 18 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 19 "data/maps/ScarexOzumasRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 20 "data/maps/ScarexOzumasRoom/scripts.pory"
	special SpawnCameraObject
# 21 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 22 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 23 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	showobjectat LOCALID_SCAREXOZUROOM_OZUMAS, MAP_SCAREX_OZUMAS_ROOM
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 28 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkDown
# 29 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 30 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 31 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_EnterRoom_Movement_0
# 46 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_OZUMAS, 8, 5
# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_QuestionMarkWithDelay48
# 49 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_EnterRoom_Text_0, MSGBOX_AUTOCLOSE
# 50 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_1
# 57 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_FaceLeft
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_2
# 79 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 80 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 81 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 82 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 83 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_SCAREXOZUROOM_OZUMAS, DIR_SOUTH
# 84 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 85 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 86 "data/maps/ScarexOzumasRoom/scripts.pory"
	special RemoveCameraObject
# 87 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 88 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end


ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer::
# 94 "data/maps/ScarexOzumasRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 95 "data/maps/ScarexOzumasRoom/scripts.pory"
	switch VAR_RESULT
# 96 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_NORTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3
# 99 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_SOUTH, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4
# 102 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_WEST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5
# 105 "data/maps/ScarexOzumasRoom/scripts.pory"
	case DIR_EAST, ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6
ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1:
	return

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_3:
# 97 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceDown
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_4:
# 100 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceUp
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_5:
# 103 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceRight
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1

ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_6:
# 106 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkInPlaceLeft
	goto ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer_1


ScarexOzumasRoom_EventScript_Ozumas::
# 113 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OZUMAS, ScarexOzumasRoom_EventScript_Ozumas_2
# 123 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 124 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 125 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_2
# 127 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 128 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_3
# 129 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 130 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_HappyWithDelay48
# 131 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_4
# 132 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_5
# 135 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_6
ScarexOzumasRoom_EventScript_Ozumas_4:
# 137 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_7
# 138 "data/maps/ScarexOzumasRoom/scripts.pory"
	call ScarexOzumasRoom_EventScript_WalkInPlaceOzumasFacingPlayer
# 139 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 140 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_VersusWithDelay48
# 141 "data/maps/ScarexOzumasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OZUMAS_MAIN, ScarexOzumasRoom_EventScript_Ozumas_Text_8
# 142 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_9
# 143 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_12
ScarexOzumasRoom_EventScript_Ozumas_11:
# 146 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_11
# 147 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 148 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_12
# 149 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_15
ScarexOzumasRoom_EventScript_Ozumas_14:
# 152 "data/maps/ScarexOzumasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OZUMAS
# 153 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_2:
# 114 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 115 "data/maps/ScarexOzumasRoom/scripts.pory"
	faceplayer
# 116 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_0
# 117 "data/maps/ScarexOzumasRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMIN_SCAREX, ScarexOzumasRoom_EventScript_Ozumas_9
ScarexOzumasRoom_EventScript_Ozumas_8:
# 120 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end

ScarexOzumasRoom_EventScript_Ozumas_5:
# 133 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_5
	goto ScarexOzumasRoom_EventScript_Ozumas_4

ScarexOzumasRoom_EventScript_Ozumas_9:
# 118 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_1
	goto ScarexOzumasRoom_EventScript_Ozumas_8

ScarexOzumasRoom_EventScript_Ozumas_12:
# 144 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_Ozumas_Text_10
	goto ScarexOzumasRoom_EventScript_Ozumas_11

ScarexOzumasRoom_EventScript_Ozumas_15:
# 150 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
	goto ScarexOzumasRoom_EventScript_Ozumas_14


ScarexOzumasRoom_EventScript_Scarex::
	end


# 31 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_0:
# 32 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 33 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 34 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 35 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 36 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_right
# 39 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_up
# 41 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 42 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_left
# 43 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 44 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
	step_end

# 51 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_1:
# 52 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 53 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 54 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
# 55 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
	step_end

# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_2:
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 60 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 61 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 62 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 63 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 64 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 64 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 66 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 67 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 68 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 70 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 71 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 72 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 72 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 73 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 74 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
# 76 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 77 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 77 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

ScarexOzumasRoom_EventScript_EnterRoom_Text_0:
# 49 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Y Scarex? Se supone ya debería estar\n"
	.string "aquí.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_0:
# 116 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Oye, estuve repitiendo nuestro combate\n"
	.string "en mi cabeza, y no puedo mentir: me\l"
	.string "diste una buena paliza.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_1:
# 118 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Ya has demostrado tu fuerza. Ahora ve a\n"
	.string "enfrentarte a Scarex.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_2:
# 125 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Bueno, parece que ha llegado el momento\n"
	.string "que teníamos pendiente.\p"
	.string "Soy Ozumas, de la sangre de la\n"
	.string "legendaria dinastía Mendrax.\p"
	.string "Hace mucho, fuimos muy conocidos,\n"
	.string "sobretodo por nunca escapar a un reto.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_3:
# 128 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Así que no me conoces? Pues no te\n"
	.string "preocupes, han pasado muchos años ya.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_4:
# 131 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres saber algo de mí, te diré que\n"
	.string "desde siempre me atrajeron las\l"
	.string "historias de Johto.\p"
	.string "Pasé años tratando de contar al mundo\n"
	.string "sus leyendas.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_5:
# 133 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Parece que ya has derrotado a Scarex,\n"
	.string "así que si logras vencerme, podrás\l"
	.string "avanzar.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_6:
# 135 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Si quieres avanzar, primero tendrás que\n"
	.string "derrotar a Scarex y a mí.\p"
	.string "Parece que yo seré tu primer\n"
	.string "contrincante.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_7:
# 137 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Vamos a ver qué historia sale de esta\n"
	.string "batalla.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_8:
# 141 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¡Eso ha estado muy guay!$"

ScarexOzumasRoom_EventScript_Ozumas_Text_9:
# 142 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Has demostrado que tienes fuerza y\n"
	.string "convicción… ¡te felicito!\p"
	.string "Pero si quieres ganar, aún queda un\n"
	.string "largo camino por delante…$"

ScarexOzumasRoom_EventScript_Ozumas_Text_10:
# 144 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Primero, deberás enfrentarte a Scarex\n"
	.string "para poder avanzar a la siguiente sala.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_11:
# 146 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Más adelante, aguarda una batalla\n"
	.string "contra alguien muy cercano a mí.\p"
	.string "Es un gran amigo y rival. Quizá lo\n"
	.string "conozcas, se llama Xiros.\p"
	.string "Será esa prueba la que determine si\n"
	.string "realmente puedes ganar el desafío.$"

ScarexOzumasRoom_EventScript_Ozumas_Text_12:
# 148 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "Estoy seguro de que lo harás genial.\n"
	.string "¡Mucha suerte!$"
