CheveRoom_MapScripts::
# 2 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheveRoom_OnTransition
	.byte 0


CheveRoom_OnTransition::
# 6 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_MEGANIUM
# 7 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_POKEBALL
	return


CheveRoom_EventScript_Cheve::
# 11 "data/maps/CheveRoom/scripts.pory"
	lock
# 12 "data/maps/CheveRoom/scripts.pory"
	faceplayer
# 13 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_0
# 14 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer
# 15 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 16 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_1
# 17 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 19 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 20 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_2
# 21 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 22 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 23 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE
# 24 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer::
# 29 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 30 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/CheveRoom/scripts.pory"
	case DIR_NORTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3
# 34 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4
# 37 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5
# 40 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6
CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1:
	return

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3:
# 32 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4:
# 35 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceUp
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5:
# 38 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceRight
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6:
# 41 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceLeft
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1


CheveRoom_EventScript_CuttableTree::
# 48 "data/maps/CheveRoom/scripts.pory"
	lock
# 49 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 50 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 51 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_CuttableTree_3
# 59 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_CuttableTree_4
# 66 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_CuttableTree_5
CheveRoom_EventScript_CuttableTree_1:
# 73 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_0
# 74 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_3
# 82 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_1, MSGBOX_AUTOCLOSE
# 83 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 84 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 85 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 86 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 87 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkUp2
# 88 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 89 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 90 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 91 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_CHEVE, MAP_CHEVE_ROOM
# 92 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 93 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 94 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 95 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 96 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 97 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_2, MSGBOX_AUTOCLOSE
# 98 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 99 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_CHEVEROOM_HIDE_POKEBALL
# 100 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_POKEBALL
# 101 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_POKEBALL, MAP_CHEVE_ROOM
# 102 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 103 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 104 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 105 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_POKEBALL
# 106 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_CHEVEROOM_HIDE_MEGANIUM
# 107 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_MEGANIUM
# 108 "data/maps/CheveRoom/scripts.pory"
	waitse
# 109 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 110 "data/maps/CheveRoom/scripts.pory"
	release
# 111 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_MEGANIUM, CheveRoom_EventScript_CuttableTree_Movement_4
# 117 "data/maps/CheveRoom/scripts.pory"
	playse SE_M_CUT
# 118 "data/maps/CheveRoom/scripts.pory"
	waitmovement 0
# 119 "data/maps/CheveRoom/scripts.pory"
	release
# 120 "data/maps/CheveRoom/scripts.pory"
	load_field_pic FP_CUT_ATTACK, 121, 75, VAR_TEMP_2
# 121 "data/maps/CheveRoom/scripts.pory"
	delay 60
# 122 "data/maps/CheveRoom/scripts.pory"
	destroy_field_pic FP_CUT_ATTACK, VAR_TEMP_2
# 123 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_TREE, Movement_CutTreeDown
# 124 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 125 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 126 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 127 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_MEGANIUM
# 128 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_MEGANIUM
# 129 "data/maps/CheveRoom/scripts.pory"
	waitse
# 130 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 131 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 132 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown3
# 133 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 134 "data/maps/CheveRoom/scripts.pory"
	waitmovement LOCALID_CHEVEROOM_CHEVE
# 135 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 136 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_3
# 137 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 139 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 140 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_4
# 141 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 142 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_5
# 143 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SmileWithDelay48
# 145 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 146 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_6
# 147 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown2
# 148 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_7
# 149 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 150 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WinkWithDelay48
# 151 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_8
# 152 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_EventScript_CuttableTree_Text_9
# 153 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_10
# 154 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 155 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SweatDropWithDelay48
# 156 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 157 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_11
# 158 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown2
# 159 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 160 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_12
# 161 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 162 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 163 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_13
# 164 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 165 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 166 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE
# 167 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_CHEVE
# 168 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_TREE
# 169 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_TREE
# 170 "data/maps/CheveRoom/scripts.pory"
	setobjectxyperm LOCALID_CHEVEROOM_CHEVE, 6, 5
# 171 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 172 "data/maps/CheveRoom/scripts.pory"
	release
	end

CheveRoom_EventScript_CuttableTree_3:
# 52 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_0
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_4:
# 60 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_1
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_5:
# 67 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_2
	goto CheveRoom_EventScript_CuttableTree_1


# 52 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_0:
# 53 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 54 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 54 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 55 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 56 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 60 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_1:
# 61 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 62 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 63 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 67 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_2:
# 68 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 69 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 70 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 75 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_3:
# 76 "data/maps/CheveRoom/scripts.pory"
	emote_double_exclamation_mark
# 77 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 78 "data/maps/CheveRoom/scripts.pory"
	jump_in_place_up
# 79 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 80 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
# 81 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 111 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_4:
# 112 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 113 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 114 "data/maps/CheveRoom/scripts.pory"
	jump_up
# 115 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
	step_end

CheveRoom_EventScript_Cheve_Text_0:
# 13 "data/maps/CheveRoom/scripts.pory"
	.string "¿Así que volviste? No me digas…\n"
	.string "¿querés la revancha?$"

CheveRoom_EventScript_Cheve_Text_1:
# 16 "data/maps/CheveRoom/scripts.pory"
	.string "Ni lo sueñes. Estoy en pleno proceso\n"
	.string "creativo… o sea, procrastinando.$"

CheveRoom_EventScript_Cheve_Text_2:
# 20 "data/maps/CheveRoom/scripts.pory"
	.string "Igual te agradezco la visita. Es lindo\n"
	.string "cuando alguien vuelve a tu habitación,\l"
	.string "aunque sea para saludar al árbol que no\l"
	.string "era árbol.$"

CheveRoom_EventScript_Cheve_Text_3:
# 23 "data/maps/CheveRoom/scripts.pory"
	.string "¡Saludos!$"

CheveRoom_EventScript_CuttableTree_Text_0:
# 73 "data/maps/CheveRoom/scripts.pory"
	.string "¿Por qué me estás mirando así?$"

CheveRoom_EventScript_CuttableTree_Text_1:
# 82 "data/maps/CheveRoom/scripts.pory"
	.string "¿Quieres cortarme?\p"
	.string "¡No me lastimes, soy Cheve!$"

CheveRoom_EventScript_CuttableTree_Text_2:
# 97 "data/maps/CheveRoom/scripts.pory"
	.string "¡Ve, Plantita!$"

CheveRoom_EventScript_CuttableTree_Text_3:
# 136 "data/maps/CheveRoom/scripts.pory"
	.string "Caíste redondit{OA}. ¿En serio creíste que\n"
	.string "yo era un árbol?$"

CheveRoom_EventScript_CuttableTree_Text_4:
# 140 "data/maps/CheveRoom/scripts.pory"
	.string "Pero bueno… no esperaba que llegaras\n"
	.string "hasta mi habitación.\p"
	.string "¡Y menos después de derrotar a mi gran\n"
	.string "amigo Javi4315!$"

CheveRoom_EventScript_CuttableTree_Text_5:
# 142 "data/maps/CheveRoom/scripts.pory"
	.string "A él lo respeto mucho, así que… digamos\n"
	.string "que ya me caes bien por eso.$"

CheveRoom_EventScript_CuttableTree_Text_6:
# 146 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que es mi turno de poner a\n"
	.string "prueba tu suerte.$"

CheveRoom_EventScript_CuttableTree_Text_7:
# 148 "data/maps/CheveRoom/scripts.pory"
	.string "Aunque aviso… no soy muy fan de los\n"
	.string "combates largos.\p"
	.string "Prefiero procrastinar… ¡mi acción\n"
	.string "favorita!$"

CheveRoom_EventScript_CuttableTree_Text_8:
# 151 "data/maps/CheveRoom/scripts.pory"
	.string "¡Vamos!$"

CheveRoom_EventScript_CuttableTree_Text_9:
# 152 "data/maps/CheveRoom/scripts.pory"
	.string "¡Muy buen combate! Me recordó a mis\n"
	.string "enfrentamientos con Xavi.$"

CheveRoom_EventScript_CuttableTree_Text_10:
# 153 "data/maps/CheveRoom/scripts.pory"
	.string "Uf… qué paliza.$"

CheveRoom_EventScript_CuttableTree_Text_11:
# 157 "data/maps/CheveRoom/scripts.pory"
	.string "Me dan ganas de postergar mi revancha\n"
	.string "hasta el próximo siglo.\p"
	.string "Pero, eh, no me malinterpretes… ¡fue\n"
	.string "divertido!$"

CheveRoom_EventScript_CuttableTree_Text_12:
# 160 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que eso tiene este lugar:\n"
	.string "siempre alguien nuevo llega a tu\l"
	.string "habitación, y cuando se va, deja un\l"
	.string "pequeño cuadro más colgado en la pared.\p"
	.string "El mío ya tiene bastantes, pero este\n"
	.string "combate merece uno nuevo.$"

CheveRoom_EventScript_CuttableTree_Text_13:
# 163 "data/maps/CheveRoom/scripts.pory"
	.string "Vamos, sigue adelante. Seguro el\n"
	.string "próximo piso te tiene guardada otra\l"
	.string "sorpresa.$"
