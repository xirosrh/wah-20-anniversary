BaroRoom_MapScripts::
# 2 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BaroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

BaroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/BaroRoom/scripts.pory"
	map_script_2 VAR_BARO_ROOM_STATE, 0, BaroRoom_OnFrame
	.2byte 0


BaroRoom_OnFrame::
# 8 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, BaroRoom_OnFrame_Movement_0
# 18 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 19 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 20 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 21 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkRight3
# 22 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 23 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 24 "data/maps/BaroRoom/scripts.pory"
	showobjectat LOCALID_BAROROOM_BARO, MAP_BARO_ROOM
# 25 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 26 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 27 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceLeft
# 28 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceRight
# 29 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 30 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_ExclamationMarkWithDelay48
# 31 "data/maps/BaroRoom/scripts.pory"
	delay 10
# 32 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 33 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft
# 34 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 35 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft3
# 36 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft3
# 37 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 38 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_1
# 39 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 40 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 41 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 42 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_SweatDropWithDelay48
# 44 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_2
# 45 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_2
# 47 "data/maps/BaroRoom/scripts.pory"
	message BaroRoom_OnFrame_Text_3
# 48 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 50 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 51 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_5
# 52 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceDown
# 53 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_OnFrame_Text_6
# 54 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 55 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_HappyWithDelay48
# 57 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 58 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 59 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_3
# 62 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight3
# 63 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkRight3
# 64 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 66 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 67 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_FaceLeft
# 68 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE
# 70 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 71 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_FaceRight
# 72 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 73 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_4
# 74 "data/maps/BaroRoom/scripts.pory"
	removeobject LOCALID_BAROROOM_BARO
# 75 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_BAROROOM_HIDE_BARO
# 76 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 77 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkLeft3
# 78 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 79 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 80 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 81 "data/maps/BaroRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 82 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_BARO_ROOM_STATE, 1
# 83 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_BARO
# 84 "data/maps/BaroRoom/scripts.pory"
	release
	end


BaroRoom_EventScript_OpenSideDoor::
# 91 "data/maps/BaroRoom/scripts.pory"
	setmetatile 12, 6, METATILE_EliteFour_SideDoor_Open, FALSE
# 92 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_CloseSideDoor::
# 98 "data/maps/BaroRoom/scripts.pory"
	setmetatile 12, 6, METATILE_EliteFour_SideDoor_Closed, FALSE
# 99 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


# 8 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_0:
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 9 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 10 "data/maps/BaroRoom/scripts.pory"
	face_right
# 11 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 12 "data/maps/BaroRoom/scripts.pory"
	face_left
# 13 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 14 "data/maps/BaroRoom/scripts.pory"
	face_up
# 15 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 16 "data/maps/BaroRoom/scripts.pory"
	face_down
# 17 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 38 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_1:
# 38 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 38 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 38 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 38 "data/maps/BaroRoom/scripts.pory"
	face_down
	step_end

# 46 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_2:
# 46 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 46 "data/maps/BaroRoom/scripts.pory"
	emote_surprise
# 46 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 46 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 46 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 59 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_3:
# 60 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 60 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 60 "data/maps/BaroRoom/scripts.pory"
	walk_down
	step_end

# 73 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_4:
# 73 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 73 "data/maps/BaroRoom/scripts.pory"
	walk_in_place_right
# 73 "data/maps/BaroRoom/scripts.pory"
	set_invisible
	step_end

BaroRoom_OnFrame_Text_0:
# 32 "data/maps/BaroRoom/scripts.pory"
	.string "Erhm… Tú eres {PLAYER}, ¿no?\n"
	.string "Encantado, soy Baro.$"

BaroRoom_OnFrame_Text_1:
# 41 "data/maps/BaroRoom/scripts.pory"
	.string "En fin… En qué jaleos se mete uno…$"

BaroRoom_OnFrame_Text_2:
# 44 "data/maps/BaroRoom/scripts.pory"
	.string "¿Yo estaba en una comunidad? ¿En\n"
	.string "serio? ¿De Pokémon?$"

BaroRoom_OnFrame_Text_3:
# 47 "data/maps/BaroRoom/scripts.pory"
	.string "Wow.$"

BaroRoom_OnFrame_Text_4:
# 49 "data/maps/BaroRoom/scripts.pory"
	.string "Vaya tiempos… En fin.$"

BaroRoom_OnFrame_Text_5:
# 51 "data/maps/BaroRoom/scripts.pory"
	.string "Supongo que lo de reminiscir del pasado\n"
	.string "es apropiado para el momento.\l"
	.string "Tu viaje y todo eso.\p"
	.string "En fin, nada, que me han pedido que me\n"
	.string "pase por aquí a hacer una peleilla\l"
	.string "contigo. ¿Vamos?$"

BaroRoom_OnFrame_Text_6:
# 53 "data/maps/BaroRoom/scripts.pory"
	.string "En fin…$"

BaroRoom_OnFrame_Text_7:
# 54 "data/maps/BaroRoom/scripts.pory"
	.string "El Pikachu no te lo esperabas, ¿eh?$"

BaroRoom_OnFrame_Text_8:
# 57 "data/maps/BaroRoom/scripts.pory"
	.string "Pues ya estaría. Ya he cumplido. Chao.$"

BaroRoom_OnFrame_Text_9:
# 69 "data/maps/BaroRoom/scripts.pory"
	.string "Bueno, buena suerte y tal.$"
