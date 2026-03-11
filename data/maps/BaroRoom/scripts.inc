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
	applymovementandwait LOCALID_PLAYER, BaroRoom_OnFrame_Movement_0
# 44 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 46 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 47 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkRight2
# 48 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 50 "data/maps/BaroRoom/scripts.pory"
	showobjectat LOCALID_BAROROOM_BARO, MAP_BARO_ROOM
# 51 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 52 "data/maps/BaroRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_BAROROOM_BARO, MOVEMENT_TYPE_FACE_LEFT
# 53 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceLeft
# 54 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceRight
# 55 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_ExclamationMarkWithDelay48
# 57 "data/maps/BaroRoom/scripts.pory"
	delay 10
# 58 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 59 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft
# 60 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 61 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft2
# 62 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkLeft2
# 63 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 64 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_1
# 65 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 66 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 67 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 68 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_SweatDropWithDelay48
# 70 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 71 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 72 "data/maps/BaroRoom/scripts.pory"
	setspeaker SP_NAME_BARO
# 73 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 74 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_2
# 75 "data/maps/BaroRoom/scripts.pory"
	message BaroRoom_OnFrame_Text_3
# 76 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/BaroRoom/scripts.pory"
	closemessage
# 78 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 79 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 80 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 81 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_5, speaker = SP_NAME_BARO
# 82 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_WalkInPlaceDown
# 83 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 84 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_3
# 85 "data/maps/BaroRoom/scripts.pory"
	waitse
# 86 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_BaroBattle
# 87 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 88 "data/maps/BaroRoom/scripts.pory"
	playse SE_PIN
# 89 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_HappyWithDelay48
# 90 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 91 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 92 "data/maps/BaroRoom/scripts.pory"
	special SpawnCameraObject
# 93 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_4
# 96 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight2
# 97 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_WalkRight2
# 98 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 99 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 100 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
# 101 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_BARO, Common_Movement_FaceLeft
# 102 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
# 103 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_BARO
# 104 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 105 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, Common_Movement_FaceRight
# 106 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_OpenSideDoor
# 107 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_BAROROOM_BARO, BaroRoom_OnFrame_Movement_5
# 108 "data/maps/BaroRoom/scripts.pory"
	removeobject LOCALID_BAROROOM_BARO
# 109 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 110 "data/maps/BaroRoom/scripts.pory"
	call BaroRoom_EventScript_CloseSideDoor
# 111 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkLeft2
# 112 "data/maps/BaroRoom/scripts.pory"
	special RemoveCameraObject
# 113 "data/maps/BaroRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_FaceUp
# 114 "data/maps/BaroRoom/scripts.pory"
	delay 20
# 115 "data/maps/BaroRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 116 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 117 "data/maps/BaroRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_BARO
# 118 "data/maps/BaroRoom/scripts.pory"
	release
	end


BaroRoom_EventScript_OpenSideDoor::
# 124 "data/maps/BaroRoom/scripts.pory"
	playse SE_RG_DOOR
# 125 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 126 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 127 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 128 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 129 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 130 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 131 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 132 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 133 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 134 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 135 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 136 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 137 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPEN_UP, 0
# 138 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPEN_DOWN, 0
# 139 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_CloseSideDoor::
# 144 "data/maps/BaroRoom/scripts.pory"
	playse SE_FU_ZAKU
# 145 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_3_UP, 0
# 146 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_3_DOWN, 0
# 147 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 148 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 149 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_2_UP, 0
# 150 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_2_DOWN, 0
# 151 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 152 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 153 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_OPENING_1_UP, 0
# 154 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_OPENING_1_DOWN, 0
# 155 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
# 156 "data/maps/BaroRoom/scripts.pory"
	delay 5
# 157 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Baro_DOOR_CLOSED_UP, 0
# 158 "data/maps/BaroRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Baro_DOOR_CLOSED_DOWN, 0
# 159 "data/maps/BaroRoom/scripts.pory"
	special DrawWholeMapView
	return


BaroRoom_EventScript_BaroBattle::
# 164 "data/maps/BaroRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, BaroRoom_EventScript_BaroBattle_2
# 167 "data/maps/BaroRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BARO
# 168 "data/maps/BaroRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 169 "data/maps/BaroRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq BaroRoom_EventScript_BaroBattle_5
# 172 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_ALTERNATIVE, BaroRoom_Text_BaroDefeated
BaroRoom_EventScript_BaroBattle_1:
# 175 "data/maps/BaroRoom/scripts.pory"
	special HealPlayerParty
	return

BaroRoom_EventScript_BaroBattle_2:
# 165 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_Text_BaroDefeated
	goto BaroRoom_EventScript_BaroBattle_1

BaroRoom_EventScript_BaroBattle_5:
# 170 "data/maps/BaroRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_BARO_MAIN, BaroRoom_Text_BaroDefeated
	goto BaroRoom_EventScript_BaroBattle_1


BaroRoom_EventScript_PlugOink::
# 184 "data/maps/BaroRoom/scripts.pory"
	lock
# 185 "data/maps/BaroRoom/scripts.pory"
	applymovement LOCALID_BAROROOM_PLUGOINK, BaroRoom_EventScript_PlugOink_Movement_0
# 186 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_EventScript_PlugOink_Text_0, MSGBOX_AUTOCLOSE
# 187 "data/maps/BaroRoom/scripts.pory"
	waitmovement 0
	end


BaroRoom_EventScript_Sever::
# 192 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_EventScript_Sever_Text_0, MSGBOX_NPC
	end


BaroRoom_EventScript_Seeg::
# 197 "data/maps/BaroRoom/scripts.pory"
	msgbox BaroRoom_EventScript_Seeg_Text_0, MSGBOX_NPC
	end


# 34 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_0:
# 35 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 35 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 35 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 35 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 35 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 36 "data/maps/BaroRoom/scripts.pory"
	face_right
# 37 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 38 "data/maps/BaroRoom/scripts.pory"
	face_left
# 39 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 40 "data/maps/BaroRoom/scripts.pory"
	face_up
# 41 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 42 "data/maps/BaroRoom/scripts.pory"
	face_down
# 43 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 64 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_1:
# 64 "data/maps/BaroRoom/scripts.pory"
	walk_up
# 64 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 64 "data/maps/BaroRoom/scripts.pory"
	walk_left
# 64 "data/maps/BaroRoom/scripts.pory"
	face_down
	step_end

# 74 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_2:
# 74 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 74 "data/maps/BaroRoom/scripts.pory"
	emote_surprise
# 74 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 74 "data/maps/BaroRoom/scripts.pory"
	delay_16
# 74 "data/maps/BaroRoom/scripts.pory"
	delay_16
	step_end

# 84 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_3:
# 84 "data/maps/BaroRoom/scripts.pory"
	emote_versus
	step_end

# 93 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_4:
# 94 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 94 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 94 "data/maps/BaroRoom/scripts.pory"
	walk_down
	step_end

# 107 "data/maps/BaroRoom/scripts.pory"
BaroRoom_OnFrame_Movement_5:
# 107 "data/maps/BaroRoom/scripts.pory"
	walk_right
# 107 "data/maps/BaroRoom/scripts.pory"
	walk_in_place_right
# 107 "data/maps/BaroRoom/scripts.pory"
	set_invisible
	step_end

# 185 "data/maps/BaroRoom/scripts.pory"
BaroRoom_EventScript_PlugOink_Movement_0:
# 185 "data/maps/BaroRoom/scripts.pory"
	face_player
# 185 "data/maps/BaroRoom/scripts.pory"
	lock_facing_direction
# 185 "data/maps/BaroRoom/scripts.pory"
	jump_in_place_down
# 185 "data/maps/BaroRoom/scripts.pory"
	jump_in_place_down
# 185 "data/maps/BaroRoom/scripts.pory"
	unlock_facing_direction
# 185 "data/maps/BaroRoom/scripts.pory"
	face_player
	step_end

BaroRoom_OnFrame_Text_0:
# 58 "data/maps/BaroRoom/scripts.pory"
	.string "Erhm… Tú eres {PLAYER}, ¿no?\n"
	.string "Encantado, soy Baro.$"

BaroRoom_OnFrame_Text_1:
# 67 "data/maps/BaroRoom/scripts.pory"
	.string "En fin… En qué jaleos se mete uno…$"

BaroRoom_OnFrame_Text_2:
# 70 "data/maps/BaroRoom/scripts.pory"
	.string "¿Yo estaba en una comunidad? ¿En\n"
	.string "serio? ¿De Pokémon?$"

BaroRoom_OnFrame_Text_3:
# 75 "data/maps/BaroRoom/scripts.pory"
	.string "Wow.$"

BaroRoom_OnFrame_Text_4:
# 79 "data/maps/BaroRoom/scripts.pory"
	.string "Vaya tiempos… En fin.$"

BaroRoom_OnFrame_Text_5:
# 81 "data/maps/BaroRoom/scripts.pory"
	.string "Supongo que lo de reminiscir del pasado\n"
	.string "es apropiado para el momento.\l"
	.string "Tu viaje y todo eso.\p"
	.string "En fin, nada, que me han pedido que me\n"
	.string "pase por aquí a hacer una peleilla\l"
	.string "contigo. ¿Vamos?$"

BaroRoom_OnFrame_Text_6:
# 87 "data/maps/BaroRoom/scripts.pory"
	.string "El Pikachu no te lo esperabas, ¿eh?$"

BaroRoom_OnFrame_Text_7:
# 91 "data/maps/BaroRoom/scripts.pory"
	.string "Pues ya estaría. Ya he cumplido. Chao.$"

BaroRoom_OnFrame_Text_8:
# 103 "data/maps/BaroRoom/scripts.pory"
	.string "Bueno, buena suerte y tal.$"

BaroRoom_EventScript_PlugOink_Text_0:
# 186 "data/maps/BaroRoom/scripts.pory"
	.string "Oink, oink, oink…$"

BaroRoom_EventScript_Sever_Text_0:
# 192 "data/maps/BaroRoom/scripts.pory"
	.string "¡Sever!$"

BaroRoom_EventScript_Seeg_Text_0:
# 197 "data/maps/BaroRoom/scripts.pory"
	.string "See, see.$"

BaroRoom_Text_BaroDefeated::
# 179 "data/maps/BaroRoom/scripts.pory"
	.string "En fin…$"
