DavZeroRoom_MapScripts::
# 2 "data/maps/DavZeroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DavZeroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DavZeroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/DavZeroRoom/scripts.pory"
	map_script_2 VAR_DAVZERO_ROOM_STATE, 0, DavZeroRoom_OnFrame
	.2byte 0


DavZeroRoom_OnFrame::
# 8 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_0
# 9 "data/maps/DavZeroRoom/scripts.pory"
	special SpawnCameraObject
# 10 "data/maps/DavZeroRoom/scripts.pory"
	directcameramovementtopos 16, 6
# 11 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 12 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_0
# 13 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 14 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_SCHOOLGIRL, DavZeroRoom_Movement_GirlAndBoySurprised
# 15 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_SCHOOLBOY, DavZeroRoom_Movement_GirlAndBoySurprised
# 16 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 17 "data/maps/DavZeroRoom/scripts.pory"
	waitse
# 18 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 19 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_DAVZERO, DIR_WEST
# 20 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 21 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_DoubleExclamationMarkWithDelay48
# 22 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 23 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkInPlaceDown
# 24 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 25 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_1
# 26 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, DavZeroRoom_OnFrame_Movement_2
# 27 "data/maps/DavZeroRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 29 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_2
# 30 "data/maps/DavZeroRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, DavZeroRoom_OnFrame_Text_3, DavZeroRoom_OnFrame_Text_4, DavZeroRoom_OnFrame_Text_5
# 31 "data/maps/DavZeroRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq DavZeroRoom_OnFrame_2
DavZeroRoom_OnFrame_1:
# 35 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 36 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_HappyWithDelay48
# 37 "data/maps/DavZeroRoom/scripts.pory"
	closemessage
# 38 "data/maps/DavZeroRoom/scripts.pory"
	delay 10
# 39 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, DavZeroRoom_OnFrame_Movement_3
# 40 "data/maps/DavZeroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, DavZeroRoom_OnFrame_Movement_4
# 41 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 42 "data/maps/DavZeroRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_SweatDropWithDelay48
# 44 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 45 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_JumpInPlaceRight2
# 46 "data/maps/DavZeroRoom/scripts.pory"
	delay 20
# 47 "data/maps/DavZeroRoom/scripts.pory"
	applymovementandwait LOCALID_ZEROROOM_DAVZERO, Common_Movement_WalkRight4
# 48 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_9
# 57 "data/maps/DavZeroRoom/scripts.pory"
	setvar VAR_DAVZERO_ROOM_STATE, 1
# 58 "data/maps/DavZeroRoom/scripts.pory"
	release
	end

DavZeroRoom_OnFrame_2:
# 33 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_OnFrame_Text_6
	goto DavZeroRoom_OnFrame_1


# 62 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_Movement_GirlAndBoySurprised:
# 63 "data/maps/DavZeroRoom/scripts.pory"
	emote_surprise
# 64 "data/maps/DavZeroRoom/scripts.pory"
	walk_in_place_up
# 65 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
# 65 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

DavZeroRoom_EventScript_SchoolGirl::
# 69 "data/maps/DavZeroRoom/scripts.pory"
	lock
# 70 "data/maps/DavZeroRoom/scripts.pory"
	faceplayer
# 71 "data/maps/DavZeroRoom/scripts.pory"
	msgbox DavZeroRoom_EventScript_SchoolGirl_Text_0, MSGBOX_AUTOCLOSE
# 72 "data/maps/DavZeroRoom/scripts.pory"
	turnobject LOCALID_ZEROROOM_SCHOOLGIRL, DIR_NORTH
# 73 "data/maps/DavZeroRoom/scripts.pory"
	release
	end


DavZeroRoom_EventScript_SchoolBoy::
	return


# 8 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_0:
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 8 "data/maps/DavZeroRoom/scripts.pory"
	face_right
	step_end

# 25 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_1:
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 25 "data/maps/DavZeroRoom/scripts.pory"
	face_down
	step_end

# 26 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_2:
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 26 "data/maps/DavZeroRoom/scripts.pory"
	delay_16
	step_end

# 39 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_3:
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 39 "data/maps/DavZeroRoom/scripts.pory"
	walk_left
# 39 "data/maps/DavZeroRoom/scripts.pory"
	face_right
	step_end

# 40 "data/maps/DavZeroRoom/scripts.pory"
DavZeroRoom_OnFrame_Movement_4:
# 40 "data/maps/DavZeroRoom/scripts.pory"
	walk_up
# 40 "data/maps/DavZeroRoom/scripts.pory"
	face_left
	step_end

DavZeroRoom_OnFrame_Text_0:
# 12 "data/maps/DavZeroRoom/scripts.pory"
	.string "Bien, recordad: las palabras agudas se\n"
	.string "acentúan cuando acaban en vocal, {COLOR RED}n{COLOR DARK_GRAY} o {COLOR BLUE}s{COLOR DARK_GRAY}.$"

DavZeroRoom_OnFrame_Text_1:
# 24 "data/maps/DavZeroRoom/scripts.pory"
	.string "Esperad un segundo... ¡Creo que hoy\n"
	.string "tenemos compañía!$"

DavZeroRoom_OnFrame_Text_2:
# 29 "data/maps/DavZeroRoom/scripts.pory"
	.string "Ajá, con que por fin has llegado hasta\n"
	.string "aquí.\p"
	.string "Es un placer verte, ¿me reconoces?$"

DavZeroRoom_OnFrame_Text_3:
# 30 "data/maps/DavZeroRoom/scripts.pory"
	.string "Sí, ¡eres inconfundible!$"

DavZeroRoom_OnFrame_Text_4:
# 30 "data/maps/DavZeroRoom/scripts.pory"
	.string "Me suenas, ¡pareces Machoke!$"

DavZeroRoom_OnFrame_Text_5:
# 30 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Debería conocerte?$"

DavZeroRoom_OnFrame_Text_6:
# 33 "data/maps/DavZeroRoom/scripts.pory"
	.string "En breves sabrás quién soy.$"

DavZeroRoom_OnFrame_Text_7:
# 41 "data/maps/DavZeroRoom/scripts.pory"
	.string "He tenido que dejar de hacer mi cuarta\n"
	.string "serie con 110 kg en press de banca.\p"
	.string "Todo porque escuchaba que un\n"
	.string "contendiente se acercaba a este nivel.\p"
	.string "Y justo me has pillado enseñando las\n"
	.string "reglas de acentuación a mi alumnado…$"

DavZeroRoom_OnFrame_Text_8:
# 44 "data/maps/DavZeroRoom/scripts.pory"
	.string "A ver, menos mal que pueden practicar\n"
	.string "un rato mientras combatimos.\p"
	.string "Aunque creo que estarán muy\n"
	.string "expectantes, porque presiento que\l"
	.string "este será un combate sin parangón.$"

DavZeroRoom_OnFrame_Text_9:
# 48 "data/maps/DavZeroRoom/scripts.pory"
	.string "Dime… ¿cuál es tu objetivo? ¿quieres\n"
	.string "desafiar al loco con lanzallamas que te\l"
	.string "espera al final?$"

DavZeroRoom_EventScript_SchoolGirl_Text_0:
# 71 "data/maps/DavZeroRoom/scripts.pory"
	.string "¿Sabías qué? Ya terminé la escuela\n"
	.string "hace años.\p"
	.string "¡Solamente vengo aquí porque Zero es\n"
	.string "tan sexy!\p"
	.string "Será nuestro secreto, shhh.$"
