BaroRoom_MapScripts::
# 11 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BaroRoom_OnLoad
# 5 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BaroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 8 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BaroRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

BaroRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/BaroRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, BaroRoom_OnFrame
	.2byte 0

BaroRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 9 "data/maps/BaroRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, BaroRoom_OnWarp_PlayerTurnNorth
	.2byte 0


BaroRoom_OnLoad::
# 16 "data/maps/BaroRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_BARO, BaroRoom_OnLoad_2
BaroRoom_OnLoad_1:
	end

BaroRoom_OnLoad_2:
# 17 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto BaroRoom_OnLoad_1


BaroRoom_OnWarp_PlayerTurnNorth::
# 23 "data/maps/BaroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


BaroRoom_OnFrame::
# 28 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, BaroRoom_OnFrame_Movement_0
# 38 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 39 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 40 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 41 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkRight2
# 42 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 44 "data/maps/BaroRoom/scripts.pory"
	showobjectat LOCALID_BAROROOM_BARO, MAP_BARO_ROOM
# 45 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 46 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 47 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceLeft
# 48 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceRight
# 49 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_ExclamationMarkWithDelay48
# 51 "data/maps/BaroRoom/scripts.pory"
	delay 10
# 52 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 53 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft
# 54 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 55 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft2
# 56 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft2
# 57 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_1
# 59 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 60 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 61 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 62 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_SweatDropWithDelay48
# 64 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 65 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 66 "data/maps/BaroRoom/scripts.pory"
	setspeaker SP_NAME_BARO
# 67 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 68 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_2
# 69 "data/maps/BaroRoom/scripts.pory"
	message BaroRoom_OnFrame_Text_3
# 70 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 72 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 73 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 74 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 75 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_5, speaker = SP_NAME_BARO
# 76 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceDown
# 77 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_BaroBattle
# 78 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 79 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 80 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_HappyWithDelay48
# 81 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 82 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 83 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 84 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_3
# 87 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
# 88 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkRight2
# 89 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 90 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 91 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 92 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_FaceLeft
# 93 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 95 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 96 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_FaceRight
# 97 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 98 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_4
# 99 "data/maps/BaroRoom/scripts.pory"
	removeobject LOCALID_BAROROOM_BARO
# 100 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 101 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 102 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkLeft2
# 103 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 104 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 105 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 106 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 107 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 108 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_BARO
# 109 "data/maps/BaroRoom/scripts.pory"
	release
	end


BaroRoom_EventScript_OpenSideDoor::
# 115 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 116 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 117 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 118 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 119 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 120 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 121 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 122 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 123 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 124 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 125 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 126 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 127 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPEN_UP, 0
# 128 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPEN_DOWN, 0
# 129 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_CloseSideDoor::
# 134 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 135 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 136 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 137 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 138 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 139 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 140 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 141 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 142 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 143 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 144 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 145 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 146 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_CLOSED_UP, 0
# 147 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_CLOSED_DOWN, 0
# 148 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_BaroBattle::
# 153 "data/maps/BaroRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, BaroRoom_EventScript_BaroBattle_2
# 156 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BARO
# 157 "data/maps/BaroRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 158 "data/maps/BaroRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BaroRoom_EventScript_BaroBattle_5
# 161 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_ALTERNATIVE, BaroRoom_Text_BaroDefeated
BaroRoom_EventScript_BaroBattle_1:
# 164 "data/maps/BaroRoom/scripts.pory"
	special HealPlayerParty
	return

BaroRoom_EventScript_BaroBattle_2:
# 154 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_Text_BaroDefeated
	goto BaroRoom_EventScript_BaroBattle_1

BaroRoom_EventScript_BaroBattle_5:
# 159 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_Text_BaroDefeated
	goto BaroRoom_EventScript_BaroBattle_1


# 28 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_0:
# 29 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 29 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 29 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 29 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 29 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 30 "data/maps/BaroRoom/scripts.pory"
	face_right
# 31 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 32 "data/maps/BaroRoom/scripts.pory"
	face_left
# 33 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 34 "data/maps/BaroRoom/scripts.pory"
	face_up
# 35 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 36 "data/maps/BaroRoom/scripts.pory"
	face_down
# 37 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 58 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_1:
# 58 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 58 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 58 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 58 "data/maps/BaroRoom/scripts.pory"
	face_down
	step_end

# 68 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_2:
# 68 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 68 "data/maps/BaroRoom/scripts.pory"
	emote_surprise
# 68 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 68 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 68 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 84 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_3:
# 85 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 85 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 85 "data/maps/BaroRoom/scripts.pory"
	walk_down
	step_end

# 98 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_4:
# 98 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 98 "data/maps/BaroRoom/scripts.pory"
	walk_in_place_right
# 98 "data/maps/BaroRoom/scripts.pory"
	set_invisible
	step_end

BaroRoom_OnFrame_Text_0:
# 52 "data/maps/BaroRoom/scripts.pory"
	.string "Erhm… Tú eres {PLAYER}, ¿no?\n"
	.string "Encantado, soy Baro.$"

BaroRoom_OnFrame_Text_1:
# 61 "data/maps/BaroRoom/scripts.pory"
	.string "En fin… En qué jaleos se mete uno…$"

BaroRoom_OnFrame_Text_2:
# 64 "data/maps/BaroRoom/scripts.pory"
	.string "¿Yo estaba en una comunidad? ¿En\n"
	.string "serio? ¿De Pokémon?$"

BaroRoom_OnFrame_Text_3:
# 69 "data/maps/BaroRoom/scripts.pory"
	.string "Wow.$"

BaroRoom_OnFrame_Text_4:
# 73 "data/maps/BaroRoom/scripts.pory"
	.string "Vaya tiempos… En fin.$"

BaroRoom_OnFrame_Text_5:
# 75 "data/maps/BaroRoom/scripts.pory"
	.string "Supongo que lo de reminiscir del pasado\n"
	.string "es apropiado para el momento.\l"
	.string "Tu viaje y todo eso.\p"
	.string "En fin, nada, que me han pedido que me\n"
	.string "pase por aquí a hacer una peleilla\l"
	.string "contigo. ¿Vamos?$"

BaroRoom_OnFrame_Text_6:
# 78 "data/maps/BaroRoom/scripts.pory"
	.string "El Pikachu no te lo esperabas, ¿eh?$"

BaroRoom_OnFrame_Text_7:
# 82 "data/maps/BaroRoom/scripts.pory"
	.string "Pues ya estaría. Ya he cumplido. Chao.$"

BaroRoom_OnFrame_Text_8:
# 94 "data/maps/BaroRoom/scripts.pory"
	.string "Bueno, buena suerte y tal.$"

BaroRoom_Text_BaroDefeated::
# 168 "data/maps/BaroRoom/scripts.pory"
	.string "En fin…$"
