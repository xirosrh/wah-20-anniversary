CheveRoom_MapScripts::
# 2 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheveRoom_OnTransition
# 6 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CheveRoom_OnLoad
# 3 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CheveRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

CheveRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/CheveRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, CheveRoom_OnWarp_PlayerTurnNorth
	.2byte 0


CheveRoom_OnLoad::
# 11 "data/maps/CheveRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_CHEVE, CheveRoom_OnLoad_2
CheveRoom_OnLoad_1:
	end

CheveRoom_OnLoad_2:
# 12 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto CheveRoom_OnLoad_1


CheveRoom_OnWarp_PlayerTurnNorth::
# 18 "data/maps/CheveRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


CheveRoom_OnTransition::
# 23 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_MEGANIUM
# 24 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_POKEBALL
	return


CheveRoom_EventScript_Cheve::
# 28 "data/maps/CheveRoom/scripts.pory"
	lock
# 29 "data/maps/CheveRoom/scripts.pory"
	faceplayer
# 30 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_0, speaker = SP_NAME_CHEVE
# 31 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer
# 32 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 33 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 34 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 36 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 37 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_2, speaker = SP_NAME_CHEVE
# 38 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 39 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 40 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 41 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer::
# 46 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 47 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 48 "data/maps/CheveRoom/scripts.pory"
	case DIR_NORTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3
# 51 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4
# 54 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5
# 57 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6
CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1:
	return

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3:
# 49 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4:
# 52 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceUp
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5:
# 55 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceRight
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6:
# 58 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceLeft
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1


CheveRoom_EventScript_CuttableTree::
# 65 "data/maps/CheveRoom/scripts.pory"
	lock
# 66 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 67 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 68 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_CuttableTree_3
# 76 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_CuttableTree_4
# 83 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_CuttableTree_5
CheveRoom_EventScript_CuttableTree_1:
# 90 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 91 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_3
# 99 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 100 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 101 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 102 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 103 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 104 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkUp2
# 105 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 106 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 107 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 108 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_CHEVE, MAP_CHEVE_ROOM
# 109 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 110 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 111 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 112 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 113 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 114 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 115 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 116 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_CHEVEROOM_HIDE_POKEBALL
# 117 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_POKEBALL
# 118 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_POKEBALL, MAP_CHEVE_ROOM
# 119 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 120 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 121 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 122 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_POKEBALL
# 123 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_CHEVEROOM_HIDE_MEGANIUM
# 124 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_MEGANIUM
# 125 "data/maps/CheveRoom/scripts.pory"
	waitse
# 126 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 127 "data/maps/CheveRoom/scripts.pory"
	release
# 128 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_MEGANIUM, CheveRoom_EventScript_CuttableTree_Movement_4
# 134 "data/maps/CheveRoom/scripts.pory"
	playse SE_M_CUT
# 135 "data/maps/CheveRoom/scripts.pory"
	waitmovement 0
# 136 "data/maps/CheveRoom/scripts.pory"
	release
# 137 "data/maps/CheveRoom/scripts.pory"
	load_field_pic FP_CUT_ATTACK, 121, 75, VAR_TEMP_2
# 138 "data/maps/CheveRoom/scripts.pory"
	delay 60
# 139 "data/maps/CheveRoom/scripts.pory"
	destroy_field_pic FP_CUT_ATTACK, VAR_TEMP_2
# 140 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_TREE, Movement_CutTreeDown
# 141 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 142 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 143 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 144 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_MEGANIUM
# 145 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_MEGANIUM
# 146 "data/maps/CheveRoom/scripts.pory"
	waitse
# 147 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 148 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 149 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown3
# 150 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 151 "data/maps/CheveRoom/scripts.pory"
	waitmovement LOCALID_CHEVEROOM_CHEVE
# 152 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 153 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 154 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 155 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 156 "data/maps/CheveRoom/scripts.pory"
	delay 30
# 157 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_4, speaker = SP_NAME_CHEVE
# 158 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 159 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 160 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 161 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SmileWithDelay48
# 162 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 163 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_6, speaker = SP_NAME_CHEVE
# 164 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown2
# 165 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 166 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 167 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WinkWithDelay48
# 168 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_8, speaker = SP_NAME_CHEVE
# 169 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_EventScript_CuttableTree_Text_9
# 170 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 171 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 172 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SweatDropWithDelay48
# 173 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 174 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 175 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown2
# 176 "data/maps/CheveRoom/scripts.pory"
	delay 30
# 177 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 178 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 179 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 180 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_13, speaker = SP_NAME_CHEVE
# 181 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 182 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 183 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 184 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_CHEVE
# 185 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_TREE
# 186 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_TREE
# 187 "data/maps/CheveRoom/scripts.pory"
	setobjectxyperm LOCALID_CHEVEROOM_CHEVE, 6, 5
# 188 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 189 "data/maps/CheveRoom/scripts.pory"
	release
	end

CheveRoom_EventScript_CuttableTree_3:
# 69 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_0
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_4:
# 77 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_1
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_5:
# 84 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_2
	goto CheveRoom_EventScript_CuttableTree_1


# 69 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_0:
# 70 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 71 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 71 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 72 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 73 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 77 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_1:
# 78 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 79 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 80 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 84 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_2:
# 85 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 86 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 87 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 92 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_3:
# 93 "data/maps/CheveRoom/scripts.pory"
	emote_double_exclamation_mark
# 94 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 95 "data/maps/CheveRoom/scripts.pory"
	jump_in_place_up
# 96 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 97 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
# 98 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 128 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_4:
# 129 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 130 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 131 "data/maps/CheveRoom/scripts.pory"
	jump_up
# 132 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
	step_end

CheveRoom_EventScript_Cheve_Text_0:
# 30 "data/maps/CheveRoom/scripts.pory"
	.string "¿Así que volviste? No me digas…\n"
	.string "¿querés la revancha?$"

CheveRoom_EventScript_Cheve_Text_1:
# 33 "data/maps/CheveRoom/scripts.pory"
	.string "Ni lo sueñes. Estoy en pleno proceso\n"
	.string "creativo… o sea, procrastinando.$"

CheveRoom_EventScript_Cheve_Text_2:
# 37 "data/maps/CheveRoom/scripts.pory"
	.string "Igual te agradezco la visita. Es lindo\n"
	.string "cuando alguien vuelve a tu habitación,\l"
	.string "aunque sea para saludar al árbol que no\l"
	.string "era árbol.$"

CheveRoom_EventScript_Cheve_Text_3:
# 40 "data/maps/CheveRoom/scripts.pory"
	.string "¡Saludos!$"

CheveRoom_EventScript_CuttableTree_Text_0:
# 90 "data/maps/CheveRoom/scripts.pory"
	.string "¿Por qué me estás mirando así?$"

CheveRoom_EventScript_CuttableTree_Text_1:
# 99 "data/maps/CheveRoom/scripts.pory"
	.string "¿Quieres cortarme?\p"
	.string "¡No me lastimes, soy Cheve!$"

CheveRoom_EventScript_CuttableTree_Text_2:
# 114 "data/maps/CheveRoom/scripts.pory"
	.string "¡Ve, Plantita!$"

CheveRoom_EventScript_CuttableTree_Text_3:
# 153 "data/maps/CheveRoom/scripts.pory"
	.string "Caíste redondit{OA}. ¿En serio creíste que\n"
	.string "yo era un árbol?$"

CheveRoom_EventScript_CuttableTree_Text_4:
# 157 "data/maps/CheveRoom/scripts.pory"
	.string "Pero bueno… no esperaba que llegaras\n"
	.string "hasta mi habitación.\p"
	.string "¡Y menos después de derrotar a mi gran\n"
	.string "amigo Javi4315!$"

CheveRoom_EventScript_CuttableTree_Text_5:
# 159 "data/maps/CheveRoom/scripts.pory"
	.string "A él lo respeto mucho, así que… digamos\n"
	.string "que ya me caes bien por eso.$"

CheveRoom_EventScript_CuttableTree_Text_6:
# 163 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que es mi turno de poner a\n"
	.string "prueba tu suerte.$"

CheveRoom_EventScript_CuttableTree_Text_7:
# 165 "data/maps/CheveRoom/scripts.pory"
	.string "Aunque aviso… no soy muy fan de los\n"
	.string "combates largos.\p"
	.string "Prefiero procrastinar… ¡mi acción\n"
	.string "favorita!$"

CheveRoom_EventScript_CuttableTree_Text_8:
# 168 "data/maps/CheveRoom/scripts.pory"
	.string "¡Vamos!$"

CheveRoom_EventScript_CuttableTree_Text_9:
# 169 "data/maps/CheveRoom/scripts.pory"
	.string "¡Muy buen combate! Me recordó a mis\n"
	.string "enfrentamientos con Xavi.$"

CheveRoom_EventScript_CuttableTree_Text_10:
# 170 "data/maps/CheveRoom/scripts.pory"
	.string "Uf… qué paliza.$"

CheveRoom_EventScript_CuttableTree_Text_11:
# 174 "data/maps/CheveRoom/scripts.pory"
	.string "Me dan ganas de postergar mi revancha\n"
	.string "hasta el próximo siglo.\p"
	.string "Pero, eh, no me malinterpretes… ¡fue\n"
	.string "divertido!$"

CheveRoom_EventScript_CuttableTree_Text_12:
# 177 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que eso tiene este lugar:\n"
	.string "siempre alguien nuevo llega a tu\l"
	.string "habitación, y cuando se va, deja un\l"
	.string "pequeño cuadro más colgado en la pared.\p"
	.string "El mío ya tiene bastantes, pero este\n"
	.string "combate merece uno nuevo.$"

CheveRoom_EventScript_CuttableTree_Text_13:
# 180 "data/maps/CheveRoom/scripts.pory"
	.string "Vamos, sigue adelante. Seguro el\n"
	.string "próximo piso te tiene guardada otra\l"
	.string "sorpresa.$"
