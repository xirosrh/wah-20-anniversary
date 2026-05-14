BaroRoom_MapScripts::
# 11 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, BaroRoom_OnLoad
# 12 "data/maps/BaroRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BaroRoom_OnTransition
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
# 17 "data/maps/BaroRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_BARO, BaroRoom_OnLoad_2
BaroRoom_OnLoad_1:
	end

BaroRoom_OnLoad_2:
# 18 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto BaroRoom_OnLoad_1


BaroRoom_OnWarp_PlayerTurnNorth::
# 24 "data/maps/BaroRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


BaroRoom_OnTransition::
# 29 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Baro
	end


BaroRoom_OnFrame::
# 34 "data/maps/BaroRoom/scripts.pory"
	special ShowMapNamePopup
# 35 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, BaroRoom_OnFrame_Movement_0
# 45 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 47 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 48 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkRight2
# 49 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 51 "data/maps/BaroRoom/scripts.pory"
	showobjectat LOCALID_BAROROOM_BARO, MAP_BARO_ROOM
# 52 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 53 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 54 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceLeft
# 55 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceRight
# 56 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 57 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_ExclamationMarkWithDelay48
# 58 "data/maps/BaroRoom/scripts.pory"
	delay 10
# 59 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 60 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft
# 61 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 62 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft2
# 63 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft2
# 64 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 65 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_1
# 66 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 67 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 68 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 69 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 70 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_SweatDropWithDelay48
# 71 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 72 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 73 "data/maps/BaroRoom/scripts.pory"
	setspeaker SP_NAME_BARO
# 74 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_2
# 76 "data/maps/BaroRoom/scripts.pory"
	message BaroRoom_OnFrame_Text_3
# 77 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 78 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 79 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 80 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 81 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 82 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_5, speaker = SP_NAME_BARO
# 83 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceDown
# 84 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 85 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_3
# 86 "data/maps/BaroRoom/scripts.pory"
	waitse
# 87 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_BaroBattle
# 88 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 89 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 90 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_HappyWithDelay48
# 91 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 92 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 93 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 94 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_4
# 97 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
# 98 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkRight2
# 99 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 100 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 101 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 102 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_FaceLeft
# 103 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 104 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 105 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 106 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_FaceRight
# 107 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 108 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_5
# 109 "data/maps/BaroRoom/scripts.pory"
	removeobject LOCALID_BAROROOM_BARO
# 110 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 111 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 112 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkLeft2
# 113 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 114 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 115 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 116 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 117 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 118 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_BARO
# 119 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 120 "data/maps/BaroRoom/scripts.pory"
	release
	end


BaroRoom_EventScript_OpenSideDoor::
# 126 "data/maps/BaroRoom/scripts.pory"
	playse SE_RG_DOOR
# 127 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 128 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 129 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 130 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 131 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 132 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 133 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 134 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 135 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 136 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 137 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 138 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 139 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPEN_UP, 0
# 140 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPEN_DOWN, 0
# 141 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_CloseSideDoor::
# 146 "data/maps/BaroRoom/scripts.pory"
	playse SE_FU_ZAKU
# 147 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 148 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 149 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 150 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 151 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 152 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 153 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 154 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 155 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 156 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 157 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 158 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 159 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_CLOSED_UP, 0
# 160 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_CLOSED_DOWN, 0
# 161 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_BaroBattle::
# 166 "data/maps/BaroRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, BaroRoom_EventScript_BaroBattle_2
# 169 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BARO
# 170 "data/maps/BaroRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 171 "data/maps/BaroRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BaroRoom_EventScript_BaroBattle_5
# 174 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_ALTERNATIVE, BaroRoom_Text_BaroDefeated
BaroRoom_EventScript_BaroBattle_1:
	return

BaroRoom_EventScript_BaroBattle_2:
# 167 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_Text_BaroDefeated
	goto BaroRoom_EventScript_BaroBattle_1

BaroRoom_EventScript_BaroBattle_5:
# 172 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_Text_BaroDefeated
	goto BaroRoom_EventScript_BaroBattle_1


BaroRoom_EventScript_PlugOink::
# 185 "data/maps/BaroRoom/scripts.pory"
	lock
# 186 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_PLUGOINK, BaroRoom_EventScript_PlugOink_Movement_0
# 187 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 188 "data/maps/BaroRoom/scripts.pory"
	playmoncry SPECIES_PLUGOINK, CRY_MODE_NORMAL
# 189 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_EventScript_PlugOink_Text_0, MSGBOX_DEFAULT
# 190 "data/maps/BaroRoom/scripts.pory"
	waitmoncry
# 191 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 192 "data/maps/BaroRoom/scripts.pory"
	goto_if_unset FLAG_MET_BARO_ROOM_PLUGOINK, BaroRoom_EventScript_PlugOink_2
BaroRoom_EventScript_PlugOink_1:
# 196 "data/maps/BaroRoom/scripts.pory"
	release
	end

BaroRoom_EventScript_PlugOink_2:
# 193 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_MET_BARO_ROOM_PLUGOINK
# 194 "data/maps/BaroRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto BaroRoom_EventScript_PlugOink_1


BaroRoom_EventScript_Sever::
# 201 "data/maps/BaroRoom/scripts.pory"
	lock
# 202 "data/maps/BaroRoom/scripts.pory"
	faceplayer
# 203 "data/maps/BaroRoom/scripts.pory"
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
# 204 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_EventScript_Sever_Text_0, MSGBOX_DEFAULT
# 205 "data/maps/BaroRoom/scripts.pory"
	waitmoncry
# 206 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 207 "data/maps/BaroRoom/scripts.pory"
	release
	end


BaroRoom_EventScript_Seeg::
# 212 "data/maps/BaroRoom/scripts.pory"
	lock
# 213 "data/maps/BaroRoom/scripts.pory"
	faceplayer
# 214 "data/maps/BaroRoom/scripts.pory"
	playmoncry SPECIES_TREECKO, CRY_MODE_NORMAL
# 215 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_EventScript_Seeg_Text_0, MSGBOX_DEFAULT
# 216 "data/maps/BaroRoom/scripts.pory"
	waitmoncry
# 217 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 218 "data/maps/BaroRoom/scripts.pory"
	release
	end


# 35 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_0:
# 36 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 36 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 36 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 36 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 36 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 37 "data/maps/BaroRoom/scripts.pory"
	face_right
# 38 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 39 "data/maps/BaroRoom/scripts.pory"
	face_left
# 40 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 41 "data/maps/BaroRoom/scripts.pory"
	face_up
# 42 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 43 "data/maps/BaroRoom/scripts.pory"
	face_down
# 44 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 65 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_1:
# 65 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 65 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 65 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 65 "data/maps/BaroRoom/scripts.pory"
	face_down
	step_end

# 75 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_2:
# 75 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 75 "data/maps/BaroRoom/scripts.pory"
	emote_surprise
# 75 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 75 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 75 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 85 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_3:
# 85 "data/maps/BaroRoom/scripts.pory"
	emote_versus
	step_end

# 94 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_4:
# 95 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 95 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 95 "data/maps/BaroRoom/scripts.pory"
	walk_down
	step_end

# 108 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_5:
# 108 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 108 "data/maps/BaroRoom/scripts.pory"
	walk_in_place_right
# 108 "data/maps/BaroRoom/scripts.pory"
	set_invisible
	step_end

# 186 "data/maps/BaroRoom/scripts.pory"
BaroRoom_EventScript_PlugOink_Movement_0:
# 186 "data/maps/BaroRoom/scripts.pory"
	face_player
# 186 "data/maps/BaroRoom/scripts.pory"
	lock_facing_direction
# 186 "data/maps/BaroRoom/scripts.pory"
	jump_in_place_down
# 186 "data/maps/BaroRoom/scripts.pory"
	jump_in_place_down
# 186 "data/maps/BaroRoom/scripts.pory"
	unlock_facing_direction
# 186 "data/maps/BaroRoom/scripts.pory"
	face_player
	step_end

BaroRoom_OnFrame_Text_0:
# 59 "data/maps/BaroRoom/scripts.pory"
	.string "Erhm… Tú eres {PLAYER}, ¿no?\n"
	.string "Encantado, soy Baro.$"

BaroRoom_OnFrame_Text_1:
# 68 "data/maps/BaroRoom/scripts.pory"
	.string "En fin… En qué jaleos se mete uno…$"

BaroRoom_OnFrame_Text_2:
# 71 "data/maps/BaroRoom/scripts.pory"
	.string "¿Yo estaba en una comunidad? ¿En\n"
	.string "serio? ¿De Pokémon?$"

BaroRoom_OnFrame_Text_3:
# 76 "data/maps/BaroRoom/scripts.pory"
	.string "Wow.$"

BaroRoom_OnFrame_Text_4:
# 80 "data/maps/BaroRoom/scripts.pory"
	.string "Vaya tiempos… En fin.$"

BaroRoom_OnFrame_Text_5:
# 82 "data/maps/BaroRoom/scripts.pory"
	.string "Supongo que lo de reminiscir del pasado\n"
	.string "es apropiado para el momento.\l"
	.string "Tu viaje y todo eso.\p"
	.string "En fin, nada, que me han pedido que me\n"
	.string "pase por aquí a hacer una peleilla\l"
	.string "contigo. ¿Vamos?$"

BaroRoom_OnFrame_Text_6:
# 88 "data/maps/BaroRoom/scripts.pory"
	.string "El Pikachu no te lo esperabas, ¿eh?$"

BaroRoom_OnFrame_Text_7:
# 92 "data/maps/BaroRoom/scripts.pory"
	.string "Pues ya estaría. Ya he cumplido. Chao.$"

BaroRoom_OnFrame_Text_8:
# 104 "data/maps/BaroRoom/scripts.pory"
	.string "Bueno, buena suerte y tal.$"

BaroRoom_EventScript_PlugOink_Text_0:
# 189 "data/maps/BaroRoom/scripts.pory"
	.string "Oink, oink, oink…$"

BaroRoom_EventScript_Sever_Text_0:
# 204 "data/maps/BaroRoom/scripts.pory"
	.string "¡Sever!$"

BaroRoom_EventScript_Seeg_Text_0:
# 215 "data/maps/BaroRoom/scripts.pory"
	.string "See, see.$"

BaroRoom_Text_BaroDefeated::
# 180 "data/maps/BaroRoom/scripts.pory"
	.string "En fin…$"
