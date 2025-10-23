CheveRoom_MapScripts::
	.byte 0


CheveRoom_EventScript_Cheve::
# 4 "data/maps/CheveRoom/scripts.pory"
	lock
# 5 "data/maps/CheveRoom/scripts.pory"
	faceplayer
# 6 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_0
# 7 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer
# 8 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 9 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_1
# 10 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 11 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 12 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 13 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_2
# 14 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 15 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 16 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE
# 17 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer::
# 22 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 23 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 24 "data/maps/CheveRoom/scripts.pory"
	case DIR_NORTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3
# 27 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4
# 30 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5
# 33 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6
CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1:
	return

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3:
# 25 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4:
# 28 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceUp
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5:
# 31 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceRight
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6:
# 34 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceLeft
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1


CheveRoom_EventScript_CuttableTree::
# 41 "data/maps/CheveRoom/scripts.pory"
	lock
# 42 "data/maps/CheveRoom/scripts.pory"
	moveobjecttopos LOCALID_PLAYER, 6, 5, DIR_NORTH
# 43 "data/maps/CheveRoom/scripts.pory"
	waitmovement 0
# 44 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_0
# 45 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_0
# 53 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_1, MSGBOX_AUTOCLOSE
# 54 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 55 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 56 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 57 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 58 "data/maps/CheveRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 59 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 60 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_CHEVE, MAP_CHEVE_ROOM
# 61 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 62 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 63 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 64 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 65 "data/maps/CheveRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 66 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 68 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_TREE, Movement_CutTreeDown
# 69 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 70 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown2
# 71 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_2
# 72 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 74 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 75 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_3
# 76 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 77 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_4
# 78 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 79 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SmileWithDelay48
# 80 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 81 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_5
# 82 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown2
# 83 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_6
# 84 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 85 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HappyWithDelay48
# 86 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_7
# 87 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_EventScript_CuttableTree_Text_8
# 88 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_9
# 89 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 90 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SweatDropWithDelay48
# 91 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 92 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_10
# 93 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown2
# 94 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 95 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_11
# 96 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 97 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 98 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_12
# 99 "data/maps/CheveRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 100 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 101 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE
# 102 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_CHEVE
# 103 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_TREE
# 104 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_CHEVEROOM_HIDE_TREE
# 105 "data/maps/CheveRoom/scripts.pory"
	setobjectxyperm LOCALID_CHEVEROOM_CHEVE, 6, 4
# 106 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 107 "data/maps/CheveRoom/scripts.pory"
	release
	end


# 46 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_0:
# 47 "data/maps/CheveRoom/scripts.pory"
	emote_double_exclamation_mark
# 48 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 49 "data/maps/CheveRoom/scripts.pory"
	jump_in_place_up
# 50 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 51 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
# 52 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

CheveRoom_EventScript_Cheve_Text_0:
# 6 "data/maps/CheveRoom/scripts.pory"
	.string "¿Así que volviste? No me digas…\n"
	.string "¿querés la revancha?$"

CheveRoom_EventScript_Cheve_Text_1:
# 9 "data/maps/CheveRoom/scripts.pory"
	.string "Ni lo sueñes. Estoy en pleno proceso\n"
	.string "creativo… o sea, procrastinando.$"

CheveRoom_EventScript_Cheve_Text_2:
# 13 "data/maps/CheveRoom/scripts.pory"
	.string "Igual te agradezco la visita. Es lindo\n"
	.string "cuando alguien vuelve a tu habitación,\l"
	.string "aunque sea para saludar al árbol que no\l"
	.string "era árbol.$"

CheveRoom_EventScript_Cheve_Text_3:
# 16 "data/maps/CheveRoom/scripts.pory"
	.string "¡Saludos!$"

CheveRoom_EventScript_CuttableTree_Text_0:
# 44 "data/maps/CheveRoom/scripts.pory"
	.string "¿Por qué me estás mirando así?$"

CheveRoom_EventScript_CuttableTree_Text_1:
# 53 "data/maps/CheveRoom/scripts.pory"
	.string "¿Quieres cortarme?\p"
	.string "¡No me lastimes, soy Cheve!$"

CheveRoom_EventScript_CuttableTree_Text_2:
# 71 "data/maps/CheveRoom/scripts.pory"
	.string "Caíste redondit{OA}. ¿En serio creíste que\n"
	.string "yo era un árbol?$"

CheveRoom_EventScript_CuttableTree_Text_3:
# 75 "data/maps/CheveRoom/scripts.pory"
	.string "Pero bueno… no esperaba que llegaras\n"
	.string "hasta mi habitación.\p"
	.string "¡Y menos después de derrotar a mi gran\n"
	.string "amigo Javi4315!$"

CheveRoom_EventScript_CuttableTree_Text_4:
# 77 "data/maps/CheveRoom/scripts.pory"
	.string "A él lo respeto mucho, así que… digamos\n"
	.string "que ya me caes bien por eso.$"

CheveRoom_EventScript_CuttableTree_Text_5:
# 81 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que es mi turno de poner a\n"
	.string "prueba tu suerte.$"

CheveRoom_EventScript_CuttableTree_Text_6:
# 83 "data/maps/CheveRoom/scripts.pory"
	.string "Aunque aviso… no soy muy fan de los\n"
	.string "combates largos.\p"
	.string "Prefiero procrastinar… ¡mi acción\n"
	.string "favorita!$"

CheveRoom_EventScript_CuttableTree_Text_7:
# 86 "data/maps/CheveRoom/scripts.pory"
	.string "¡Vamos!$"

CheveRoom_EventScript_CuttableTree_Text_8:
# 87 "data/maps/CheveRoom/scripts.pory"
	.string "¡Muy buen combate! Me recordó a mis\n"
	.string "enfrentamientos con Xavi.$"

CheveRoom_EventScript_CuttableTree_Text_9:
# 88 "data/maps/CheveRoom/scripts.pory"
	.string "Uf… qué paliza.$"

CheveRoom_EventScript_CuttableTree_Text_10:
# 92 "data/maps/CheveRoom/scripts.pory"
	.string "Me dan ganas de postergar mi revancha\n"
	.string "hasta el próximo siglo.\p"
	.string "Pero, eh, no me malinterpretes… ¡fue\n"
	.string "divertido!$"

CheveRoom_EventScript_CuttableTree_Text_11:
# 95 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que eso tiene este lugar:\n"
	.string "siempre alguien nuevo llega a tu\l"
	.string "habitación, y cuando se va, deja un\l"
	.string "pequeño cuadro más colgado en la pared.\p"
	.string "El mío ya tiene bastantes, pero este\n"
	.string "combate merece uno nuevo.$"

CheveRoom_EventScript_CuttableTree_Text_12:
# 98 "data/maps/CheveRoom/scripts.pory"
	.string "Vamos, sigue adelante. Seguro el\n"
	.string "próximo piso te tiene guardada otra\l"
	.string "sorpresa.$"
