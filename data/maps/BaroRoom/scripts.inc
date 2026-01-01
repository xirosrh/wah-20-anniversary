BaroRoom_MapScripts::
# 8 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BaroRoom_OnLoad
# 2 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BaroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 5 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BaroRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BaroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/BaroRoom/scripts.pory"
	map_script_2 VAR_BARO_ROOM_STATE, 0, BaroRoom_OnFrame
	.2byte 0

BaroRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/BaroRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, BaroRoom_OnWarp_PlayerTurnNorth
	.2byte 0


BaroRoom_OnLoad::
# 13 "data/maps/BaroRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_BARO, BaroRoom_OnLoad_2
BaroRoom_OnLoad_1:
	end

BaroRoom_OnLoad_2:
# 14 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto BaroRoom_OnLoad_1


BaroRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/BaroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


BaroRoom_OnFrame::
# 25 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, BaroRoom_OnFrame_Movement_0
# 35 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 36 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 37 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 38 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkRight2
# 39 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 41 "data/maps/BaroRoom/scripts.pory"
	showobjectat LOCALID_BAROROOM_BARO, MAP_BARO_ROOM
# 42 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 43 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 44 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceLeft
# 45 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceRight
# 46 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_ExclamationMarkWithDelay48
# 48 "data/maps/BaroRoom/scripts.pory"
	delay 10
# 49 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 50 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft
# 51 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 52 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft2
# 53 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft2
# 54 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 55 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_1
# 56 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 57 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 58 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 59 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 60 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_SweatDropWithDelay48
# 61 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 62 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 63 "data/maps/BaroRoom/scripts.pory"
	setspeaker SP_NAME_BARO
# 64 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 65 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_2
# 66 "data/maps/BaroRoom/scripts.pory"
	message BaroRoom_OnFrame_Text_3
# 67 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 69 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 70 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 71 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 72 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_5, speaker = SP_NAME_BARO
# 73 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceDown
# 74 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_OnFrame_Text_6
# 75 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 76 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 77 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_HappyWithDelay48
# 78 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 79 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 80 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 81 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_3
# 84 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
# 85 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkRight2
# 86 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 87 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 88 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 89 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_FaceLeft
# 90 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 91 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 92 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 93 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_FaceRight
# 94 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 95 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_4
# 96 "data/maps/BaroRoom/scripts.pory"
	removeobject LOCALID_BAROROOM_BARO
# 97 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_BAROROOM_HIDE_BARO
# 98 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 99 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkLeft2
# 100 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 101 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 102 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 103 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 104 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_BARO_ROOM_STATE, 1
# 105 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_BARO
# 106 "data/maps/BaroRoom/scripts.pory"
	release
	end


BaroRoom_EventScript_OpenSideDoor::
# 112 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 113 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 114 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 115 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 116 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 117 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 118 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 119 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 120 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 121 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 122 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 123 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 124 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPEN_UP, 0
# 125 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPEN_DOWN, 0
# 126 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_CloseSideDoor::
# 131 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 132 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 133 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 134 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 135 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 136 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 137 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 138 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 139 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 140 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 141 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 142 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 143 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_CLOSED_UP, 0
# 144 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_CLOSED_DOWN, 0
# 145 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


# 25 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_0:
# 26 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 26 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 26 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 26 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 26 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 27 "data/maps/BaroRoom/scripts.pory"
	face_right
# 28 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 29 "data/maps/BaroRoom/scripts.pory"
	face_left
# 30 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 31 "data/maps/BaroRoom/scripts.pory"
	face_up
# 32 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 33 "data/maps/BaroRoom/scripts.pory"
	face_down
# 34 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 55 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_1:
# 55 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 55 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 55 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 55 "data/maps/BaroRoom/scripts.pory"
	face_down
	step_end

# 65 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_2:
# 65 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 65 "data/maps/BaroRoom/scripts.pory"
	emote_surprise
# 65 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 65 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 65 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 81 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_3:
# 82 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 82 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 82 "data/maps/BaroRoom/scripts.pory"
	walk_down
	step_end

# 95 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_4:
# 95 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 95 "data/maps/BaroRoom/scripts.pory"
	walk_in_place_right
# 95 "data/maps/BaroRoom/scripts.pory"
	set_invisible
	step_end

BaroRoom_OnFrame_Text_0:
# 49 "data/maps/BaroRoom/scripts.pory"
	.string "Erhm… Tú eres {PLAYER}, ¿no?\n"
	.string "Encantado, soy Baro.$"

BaroRoom_OnFrame_Text_1:
# 58 "data/maps/BaroRoom/scripts.pory"
	.string "En fin… En qué jaleos se mete uno…$"

BaroRoom_OnFrame_Text_2:
# 61 "data/maps/BaroRoom/scripts.pory"
	.string "¿Yo estaba en una comunidad? ¿En\n"
	.string "serio? ¿De Pokémon?$"

BaroRoom_OnFrame_Text_3:
# 66 "data/maps/BaroRoom/scripts.pory"
	.string "Wow.$"

BaroRoom_OnFrame_Text_4:
# 70 "data/maps/BaroRoom/scripts.pory"
	.string "Vaya tiempos… En fin.$"

BaroRoom_OnFrame_Text_5:
# 72 "data/maps/BaroRoom/scripts.pory"
	.string "Supongo que lo de reminiscir del pasado\n"
	.string "es apropiado para el momento.\l"
	.string "Tu viaje y todo eso.\p"
	.string "En fin, nada, que me han pedido que me\n"
	.string "pase por aquí a hacer una peleilla\l"
	.string "contigo. ¿Vamos?$"

BaroRoom_OnFrame_Text_6:
# 74 "data/maps/BaroRoom/scripts.pory"
	.string "En fin…$"

BaroRoom_OnFrame_Text_7:
# 75 "data/maps/BaroRoom/scripts.pory"
	.string "El Pikachu no te lo esperabas, ¿eh?$"

BaroRoom_OnFrame_Text_8:
# 79 "data/maps/BaroRoom/scripts.pory"
	.string "Pues ya estaría. Ya he cumplido. Chao.$"

BaroRoom_OnFrame_Text_9:
# 91 "data/maps/BaroRoom/scripts.pory"
	.string "Bueno, buena suerte y tal.$"
