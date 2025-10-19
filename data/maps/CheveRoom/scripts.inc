CheveRoom_MapScripts::
	.byte 0


CheveRoom_EventScript_Cheve::
# 4 "data/maps/CheveRoom/scripts.pory"
	lock
# 5 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_0
# 6 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_EventScript_Cheve_Text_1
# 7 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_CuttableTree::
# 12 "data/maps/CheveRoom/scripts.pory"
	lock
# 13 "data/maps/CheveRoom/scripts.pory"
	moveobjecttopos LOCALID_PLAYER, 6, 5, DIR_NORTH
# 14 "data/maps/CheveRoom/scripts.pory"
	waitmovement 0
# 15 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_0
# 16 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 17 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_0
# 23 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_1, MSGBOX_AUTOCLOSE
# 24 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 26 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 27 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 28 "data/maps/CheveRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 29 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 30 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_CHEVE, MAP_CHEVE_ROOM
# 31 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 32 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 33 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 34 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 35 "data/maps/CheveRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 36 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 38 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_TREE, Movement_CutTreeDown
# 39 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 40 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown2
# 41 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_2
# 42 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 45 "data/maps/CheveRoom/scripts.pory"
	release
	end


# 17 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_0:
# 18 "data/maps/CheveRoom/scripts.pory"
	emote_double_exclamation_mark
# 19 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 20 "data/maps/CheveRoom/scripts.pory"
	jump_in_place_up
# 21 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 22 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
	step_end

CheveRoom_EventScript_Cheve_Text_0:
# 5 "data/maps/CheveRoom/scripts.pory"
	.string "Holi$"

CheveRoom_EventScript_Cheve_Text_1:
# 6 "data/maps/CheveRoom/scripts.pory"
	.string "asd$"

CheveRoom_EventScript_CuttableTree_Text_0:
# 15 "data/maps/CheveRoom/scripts.pory"
	.string "¿Por qué me estás mirando así?$"

CheveRoom_EventScript_CuttableTree_Text_1:
# 23 "data/maps/CheveRoom/scripts.pory"
	.string "¿Quieres cortarme?\p"
	.string "¡No me lastimes, soy Cheve!$"

CheveRoom_EventScript_CuttableTree_Text_2:
# 41 "data/maps/CheveRoom/scripts.pory"
	.string "Caíste redondit{OA}. ¿En serio creíste que\n"
	.string "yo era un árbol?$"
