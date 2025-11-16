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
# 11 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_TRAINER_IN_WATER
	goto EingRoom_OnTransition_1


EingRoom_OnFrame::
# 17 "data/maps/EingRoom/scripts.pory"
	release
# 18 "data/maps/EingRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 19 "data/maps/EingRoom/scripts.pory"
	special SpawnCameraObject
# 20 "data/maps/EingRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 21 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 22 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceDown
# 23 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_0
# 24 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_0
# 26 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 27 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/EingRoom/scripts.pory"
	delay 30
# 29 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_1
# 30 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 31 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_2
# 32 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 33 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_WalkInPlaceLeft
# 34 "data/maps/EingRoom/scripts.pory"
	hideobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 35 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_EINGROOM_HIDE_EING_FISHING
# 36 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_EING_FISHING
# 37 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING_FISHING, MAP_EING_ROOM
# 38 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING_FISHING, Common_Movement_Fishing
# 39 "data/maps/EingRoom/scripts.pory"
	setflag FLAG_EINGROOM_HIDE_EING_FISHING
# 40 "data/maps/EingRoom/scripts.pory"
	removeobject LOCALID_EINGROOM_EING_FISHING
# 41 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_EING, MAP_EING_ROOM
# 42 "data/maps/EingRoom/scripts.pory"
	clearflag FLAG_EINGROOM_HIDE_TRAINER_IN_WATER
# 43 "data/maps/EingRoom/scripts.pory"
	addobject LOCALID_EINGROOM_TRAINER_IN_WATER
# 44 "data/maps/EingRoom/scripts.pory"
	showobjectat LOCALID_EINGROOM_TRAINER_IN_WATER, MAP_EING_ROOM
# 45 "data/maps/EingRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/EingRoom/scripts.pory"
	applymovement LOCALID_EINGROOM_EING, EingRoom_OnFrame_Movement_3
# 47 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 48 "data/maps/EingRoom/scripts.pory"
	delay 30
# 49 "data/maps/EingRoom/scripts.pory"
	applymovementandwait LOCALID_EINGROOM_EING, Common_Movement_FaceRight
# 50 "data/maps/EingRoom/scripts.pory"
	msgbox EingRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 51 "data/maps/EingRoom/scripts.pory"
	turnobject LOCALID_EINGROOM_EING, DIR_WEST
# 52 "data/maps/EingRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 53 "data/maps/EingRoom/scripts.pory"
	waitmovement 0
# 54 "data/maps/EingRoom/scripts.pory"
	setvar VAR_EING_ROOM_STATE, 1
# 55 "data/maps/EingRoom/scripts.pory"
	special RemoveCameraObject
# 56 "data/maps/EingRoom/scripts.pory"
	release
	end


# 25 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_0:
# 25 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 25 "data/maps/EingRoom/scripts.pory"
	jump_in_place_down
# 25 "data/maps/EingRoom/scripts.pory"
	delay_16
# 25 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 29 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_1:
# 29 "data/maps/EingRoom/scripts.pory"
	walk_right
# 29 "data/maps/EingRoom/scripts.pory"
	walk_right
# 29 "data/maps/EingRoom/scripts.pory"
	walk_left
# 29 "data/maps/EingRoom/scripts.pory"
	walk_left
# 29 "data/maps/EingRoom/scripts.pory"
	walk_right
# 29 "data/maps/EingRoom/scripts.pory"
	walk_right
# 29 "data/maps/EingRoom/scripts.pory"
	walk_left
# 29 "data/maps/EingRoom/scripts.pory"
	walk_left
	step_end

# 31 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_2:
# 31 "data/maps/EingRoom/scripts.pory"
	emote_idea
# 31 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 31 "data/maps/EingRoom/scripts.pory"
	delay_16
# 31 "data/maps/EingRoom/scripts.pory"
	delay_16
	step_end

# 46 "data/maps/EingRoom/scripts.pory"
EingRoom_OnFrame_Movement_3:
# 46 "data/maps/EingRoom/scripts.pory"
	emote_angry
# 46 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 46 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
# 46 "data/maps/EingRoom/scripts.pory"
	jump_in_place_left
	step_end

EingRoom_OnFrame_Text_0:
# 23 "data/maps/EingRoom/scripts.pory"
	.string "Malditos Xiros y Serg!o, que se han\n"
	.string "pirado dejándome a mí con el marrón de\l"
	.string "administrar la página web y el foro…$"

EingRoom_OnFrame_Text_1:
# 26 "data/maps/EingRoom/scripts.pory"
	.string "¡Y yo sin las malditas creedenciales!$"

EingRoom_OnFrame_Text_2:
# 32 "data/maps/EingRoom/scripts.pory"
	.string "A ver si las han tirado al fondo del mar\n"
	.string "como una prueba para desafiarme y ver\l"
	.string "si soy digno de administrar WAH…\p"
	.string "¡Voy a ver si las pesco!$"

EingRoom_OnFrame_Text_3:
# 47 "data/maps/EingRoom/scripts.pory"
	.string "¡Maldita sea! ¿Otro entrenador?$"

EingRoom_OnFrame_Text_4:
# 50 "data/maps/EingRoom/scripts.pory"
	.string "Esto se está pareciendo a mi rutina de\n"
	.string "wildbattles dobles del Hoenn\l"
	.string "Adventures…$"
