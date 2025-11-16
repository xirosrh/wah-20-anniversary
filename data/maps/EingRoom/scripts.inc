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
	end

EingRoom_OnTransition_2:
# 10 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_EING_FISHING
	goto EingRoom_OnTransition_1


EingRoom_OnFrame::
# 16 "data/maps/EingRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 17 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 18 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 19 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 20 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
# 21 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 22 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 23 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 24 "data/maps/EingRoom/scripts.pory"
	delay 30
# 25 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 26 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 27 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 28 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 29 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 30 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 31 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_EINGROOM_HIDE_EING_FISHING
# 32 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 33 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 34 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 35 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_EING_FISHING
# 36 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 37 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 38 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 39 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 40 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 41 "data/maps/EingRoom/scripts.pory"
	delay 30
# 42 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 43 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 44 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 45 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 46 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 47 "data/maps/EingRoom/scripts.pory"
	setvar VAR_EING_ROOM_STATE, 1
# 48 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 49 "data/maps/EingRoom/scripts.pory"
	release
	end


# 23 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 23 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 23 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 23 "data/maps/EingRoom/scripts.pory"
	delay_16
# 23 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 25 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 25 "data/maps/EingRoom/scripts.pory"
	walk_right
# 25 "data/maps/EingRoom/scripts.pory"
	walk_right
# 25 "data/maps/EingRoom/scripts.pory"
	walk_left
# 25 "data/maps/EingRoom/scripts.pory"
	walk_left
# 25 "data/maps/EingRoom/scripts.pory"
	walk_right
# 25 "data/maps/EingRoom/scripts.pory"
	walk_right
# 25 "data/maps/EingRoom/scripts.pory"
	walk_left
# 25 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 27 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 27 "data/maps/EingRoom/scripts.pory"
	emote_idea
# 27 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 27 "data/maps/EingRoom/scripts.pory"
	delay_16
# 27 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 39 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 39 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 39 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 39 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 39 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

EingRoom_OnFrame_Text_0:
# 21 "data/maps/EingRoom/scripts.pory"
	.string "Malditos Xiros y Serg!o, que se han\n"
	.string "pirado dejándome a mí con el marrón de\l"
	.string "administrar la página web y el foro… y\l"
	.string "yo sin las malditas creedenciales.$"

EingRoom_OnFrame_Text_1:
# 28 "data/maps/EingRoom/scripts.pory"
	.string "A ver si las han tirado al fondo del mar\n"
	.string "como una prueba para desafiarme y ver\l"
	.string "si soy digno de administrar WAH…\p"
	.string "¡Voy a ver si las pesco!$"

EingRoom_OnFrame_Text_2:
# 40 "data/maps/EingRoom/scripts.pory"
	.string "¡Maldita sea! ¿Otro entrenador?$"

EingRoom_OnFrame_Text_3:
# 43 "data/maps/EingRoom/scripts.pory"
	.string "Esto se está pareciendo a mi rutina de\n"
	.string "wildbattles dobles del Hoenn\l"
	.string "Adventures…$"
