KleinPkPowerRoom_MapScripts::
# 5 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, KleinPkPowerRoom_OnLoad
# 2 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, KleinPkPowerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 6 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, KleinPkPowerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

KleinPkPowerRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, KleinPkPowerRoom_OnFrame
	.2byte 0

KleinPkPowerRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, KleinPkPowerRoom_OnWarp_PlayerTurnNorth
	.2byte 0


KleinPkPowerRoom_OnLoad::
# 13 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_KLEIN, KleinPkPowerRoom_OnLoad_3
KleinPkPowerRoom_OnLoad_1:
	end

KleinPkPowerRoom_OnLoad_2:
# 14 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 7, 5, 0x270, 1
# 15 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, 0x25B, 0
# 16 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatileelevation 9, 6, 0
# 17 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_PKPOWER, 2, 4
# 18 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_PKPOWER, MOVEMENT_TYPE_FACE_UP
# 19 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_KLEIN, 2, 7
# 20 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_KLEIN, MOVEMENT_TYPE_FACE_UP
# 21 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto KleinPkPowerRoom_OnLoad_1

KleinPkPowerRoom_OnLoad_3:
# 13 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_OnLoad_2
	goto KleinPkPowerRoom_OnLoad_1


KleinPkPowerRoom_OnWarp_PlayerTurnNorth::
# 27 "data/maps/KleinPkPowerRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


KleinPkPowerRoom_OnFrame::
# 32 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_0
# 34 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 36 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 37 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 38 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 41 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_1
# 42 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 43 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 44 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 45 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 46 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 47 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 48 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 49 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 50 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 51 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 52 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 53 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 54 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 55 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 56 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 57 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 58 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 59 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 60 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 61 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 62 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 63 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 64 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 65 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 66 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 67 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 68 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 69 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 70 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 71 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 73 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 74 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 75 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 76 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 77 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 78 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 79 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 80 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 81 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 82 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 83 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 84 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 85 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 86 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 87 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 88 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 89 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 90 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 91 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 92 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 93 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 94 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 95 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 97 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 98 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 99 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 100 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 101 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 103 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 104 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 105 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 106 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 107 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 108 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 109 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 110 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 111 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 112 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 113 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 114 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 115 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 116 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 117 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 118 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 119 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 120 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 121 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 122 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 123 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 124 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 125 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 127 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 128 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 129 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 130 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 131 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 132 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 133 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 134 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_5
# 135 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 136 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 137 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 138 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 140 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 141 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 142 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 143 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 144 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 145 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 146 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 147 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_7
# 149 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 151 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadedefaultbgm
# 152 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_8
# 154 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_B_PIKE, FALSE
# 156 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 158 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_3
# 159 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 160 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 161 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 162 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 163 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 164 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_9
# 165 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 166 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 167 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 168 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_10
# 170 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 172 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadedefaultbgm
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 174 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end


KleinPkPowerRoom_EventScript_BotonRojo::
# 179 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 180 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_2
# 186 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_1, MSGBOX_YESNO
# 187 "data/maps/KleinPkPowerRoom/scripts.pory"
	closemessage
# 188 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq KleinPkPowerRoom_EventScript_BotonRojo_5
KleinPkPowerRoom_EventScript_BotonRojo_1:
# 268 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end

KleinPkPowerRoom_EventScript_BotonRojo_2:
# 182 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_0, MSGBOX_AUTOCLOSE
	goto KleinPkPowerRoom_EventScript_BotonRojo_1

KleinPkPowerRoom_EventScript_BotonRojo_5:
# 190 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_CLICK
# 191 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 192 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 193 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_SUCCESS
# 194 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 7, 5, 0x270, 1
# 195 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 196 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 197 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 198 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_UNLOCK
# 199 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, 0x25B, 0
# 200 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 201 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 202 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatileelevation 9, 6, 0
# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_0
# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_1
# 205 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 206 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 207 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 208 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 209 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 210 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 211 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 212 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 213 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 214 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 215 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_2
# 216 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 217 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 218 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_B_PIKE, FALSE
# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_3
# 221 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 222 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 223 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_9
# 224 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 225 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 226 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 227 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 228 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_4
# 229 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 230 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_KleinBattle
# 231 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 232 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_5
# 233 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_6
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 237 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 238 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_7
# 239 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 240 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 241 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 242 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 243 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_8
# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 245 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_9
# 246 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 247 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 248 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 249 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_4
# 250 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 251 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_PkPowerBattle
# 252 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 253 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 254 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxy LOCALID_KLEINROOM_PKPOWER, 2, 4
# 255 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_PKPOWER, 2, 4
# 256 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_PKPOWER, MOVEMENT_TYPE_FACE_UP
# 257 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxy LOCALID_KLEINROOM_KLEIN, 2, 7
# 258 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_KLEIN, 2, 7
# 259 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_KLEIN, MOVEMENT_TYPE_FACE_UP
# 260 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 262 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_11
# 263 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_NONE
# 264 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 265 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
	goto KleinPkPowerRoom_EventScript_BotonRojo_1


KleinPkPowerRoom_EventScript_KleinBattle::
# 273 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, KleinPkPowerRoom_EventScript_KleinBattle_2
# 276 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_KLEIN
# 277 "data/maps/KleinPkPowerRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 278 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq KleinPkPowerRoom_EventScript_KleinBattle_5
# 281 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE, KleinPkPowerRoom_Text_KleinDefeated
KleinPkPowerRoom_EventScript_KleinBattle_1:
# 284 "data/maps/KleinPkPowerRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_KLEIN
# 285 "data/maps/KleinPkPowerRoom/scripts.pory"
	special HealPlayerParty
	return

KleinPkPowerRoom_EventScript_KleinBattle_2:
# 274 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_MAIN, KleinPkPowerRoom_Text_KleinDefeated
	goto KleinPkPowerRoom_EventScript_KleinBattle_1

KleinPkPowerRoom_EventScript_KleinBattle_5:
# 279 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_MAIN, KleinPkPowerRoom_Text_KleinDefeated
	goto KleinPkPowerRoom_EventScript_KleinBattle_1


KleinPkPowerRoom_EventScript_PkPowerBattle::
# 294 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, KleinPkPowerRoom_EventScript_PkPowerBattle_2
# 297 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_PKPOWER
# 298 "data/maps/KleinPkPowerRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 299 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq KleinPkPowerRoom_EventScript_PkPowerBattle_5
# 302 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE, KleinPkPowerRoom_Text_PkPowerDefeated
KleinPkPowerRoom_EventScript_PkPowerBattle_1:
# 305 "data/maps/KleinPkPowerRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_PKPOWER
# 306 "data/maps/KleinPkPowerRoom/scripts.pory"
	special HealPlayerParty
	return

KleinPkPowerRoom_EventScript_PkPowerBattle_2:
# 295 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_MAIN, KleinPkPowerRoom_Text_PkPowerDefeated
	goto KleinPkPowerRoom_EventScript_PkPowerBattle_1

KleinPkPowerRoom_EventScript_PkPowerBattle_5:
# 300 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_MAIN, KleinPkPowerRoom_Text_PkPowerDefeated
	goto KleinPkPowerRoom_EventScript_PkPowerBattle_1


KleinPkPowerRoom_EventScript_PkPower::
# 315 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 316 "data/maps/KleinPkPowerRoom/scripts.pory"
	faceplayer
# 317 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_EventScript_PkPower_2
# 321 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_PkPower_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
KleinPkPowerRoom_EventScript_PkPower_1:
# 323 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 324 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 325 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end

KleinPkPowerRoom_EventScript_PkPower_2:
# 318 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_PkPower_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
	goto KleinPkPowerRoom_EventScript_PkPower_1


KleinPkPowerRoom_EventScript_Klein::
# 330 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 331 "data/maps/KleinPkPowerRoom/scripts.pory"
	faceplayer
# 332 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_Klein_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 333 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 334 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 335 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end


# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_0:
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

# 41 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_1:
# 41 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 51 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_2:
# 51 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_in_place_up
	step_end

# 54 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_3:
# 54 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_thinking
	step_end

# 66 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_4:
# 66 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_angry
	step_end

# 134 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_5:
# 134 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_angry
# 134 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_in_place_up
	step_end

# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_6:
# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
	jump_in_place_down
	step_end

# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_7:
# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_8:
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

# 164 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_9:
# 164 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
	step_end

# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_10:
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_left
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_up
	step_end

# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_0:
# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_1:
# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
	step_end

# 215 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_2:
# 215 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_happy
	step_end

# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_3:
# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
	step_end

# 228 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_4:
# 228 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_versus
	step_end

# 232 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_5:
# 232 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_down
# 232 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
	step_end

# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_6:
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 238 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_7:
# 238 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 243 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_8:
# 243 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
	step_end

# 245 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_9:
# 245 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_left
	step_end

# 260 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_10:
# 260 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_up
	step_end

# 262 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_11:
# 262 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
# 262 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

KleinPkPowerRoom_OnFrame_Text_0:
# 53 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.\n"
	.string "¿En qué puedo ayudarte?$"

KleinPkPowerRoom_OnFrame_Text_1:
# 57 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Que el Güindous no arranca?\n"
	.string "¿Y qué aparece en pantalla?$"

KleinPkPowerRoom_OnFrame_Text_2:
# 61 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Nada?\n"
	.string "¿Pero… tienes el ordenador encendido?$"

KleinPkPowerRoom_OnFrame_Text_3:
# 67 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Pues enchúfalo, hombre!\n"
	.string "¡Esas cosas se comprueban antes!$"

KleinPkPowerRoom_OnFrame_Text_4:
# 83 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.\n"
	.string "¿Qué necesitas?$"

KleinPkPowerRoom_OnFrame_Text_5:
# 87 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Cómo que has perdido el cursor!?\n"
	.string "¿Has probado a mover el ratón?$"

KleinPkPowerRoom_OnFrame_Text_6:
# 91 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "No será el ratón inalámbrico...\n"
	.string "¿Tiene pilas?$"

KleinPkPowerRoom_OnFrame_Text_7:
# 97 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Joder! ¡Pues pónselas!$"

KleinPkPowerRoom_OnFrame_Text_8:
# 113 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.$"

KleinPkPowerRoom_OnFrame_Text_9:
# 117 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Que cuál es la tecla de “cualquier\n"
	.string "tecla”!? ¿¡Pero qué pregunta es esa!?$"

KleinPkPowerRoom_OnFrame_Text_10:
# 121 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Pues si el mensaje dice “pulse\n"
	.string "cualquier tecla”, haz lo que dice!$"

KleinPkPowerRoom_OnFrame_Text_11:
# 127 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Que no hay ninguna tecla que se llame\n"
	.string "“cualquier tecla”! ¡Pulsa una tecla\l"
	.string "cualquiera y ya!$"

KleinPkPowerRoom_OnFrame_Text_12:
# 135 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Esto es increíble! ¿Pero cómo puede\n"
	.string "haber gente así? ¡Estoy rodeado de\l"
	.string "inútiles! Pero se va a acabar...\p"
	.string "¡Los voy a echar a todos!\n"
	.string "¡A la puta calle!$"

KleinPkPowerRoom_OnFrame_Text_13:
# 146 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Eh, tú! ¡Aquí! ¡Ven!$"

KleinPkPowerRoom_OnFrame_Text_14:
# 156 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Sabes quién soy?$"

KleinPkPowerRoom_OnFrame_Text_15:
# 162 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Claro... Tú qué vas a saber...\n"
	.string "Soy Klein, el webmaster de WaH.\p"
	.string "Oye... Tienes que ayudarme, ¡la he liado\n"
	.string "parda!\p"
	.string "He hackeado al Perro Sanxe y para colmo\n"
	.string "me han metido en esta cárcel a la vez\l"
	.string "que se ha caído el foro...\n"
	.string "¿Puedes liberarme?$"

KleinPkPowerRoom_OnFrame_Text_16:
# 168 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Que no sabes cómo liberarme? ¡Pues es\n"
	.string "muy fácil!\p"
	.string "¿Ves ese botón rojo?$"

KleinPkPowerRoom_OnFrame_Text_17:
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Sí, ese botón! ¡Púlsalo y podré salir!\p"
	.string "¡Vamos, no me hagas esperar más, que\n"
	.string "tengo que levantar el foro!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_0:
# 182 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "La celda ya está abierta.$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_1:
# 186 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Quieres pulsar el botón rojo?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_2:
# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Sí! ¡Soy libre!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_3:
# 226 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Por cierto... ¿Tú quién eras?\n"
	.string "¿No será una trampa para encerrarme de\l"
	.string "nuevo?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_4:
# 242 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Pero qué!?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_5:
# 247 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Qué estáis haciendo?\n"
	.string "¡Si acabo de pagar la fianza para\l"
	.string "sacarlo de la cárcel!\p"
	.string "¿No podías quedarte quietecito tú\n"
	.string "también? Bah, qué más da...\p"
	.string "¡Venga, a levantar el foro!\n"
	.string "¡Que lleva caído todo el día!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_6:
# 252 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Perfecto! ¡Has superado la prueba!\n"
	.string "Hay que saber actuar bajo presión.\p"
	.string "¡Vamos, a levantar el foro!$"

KleinPkPowerRoom_EventScript_PkPower_Text_0:
# 318 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

KleinPkPowerRoom_EventScript_PkPower_Text_1:
# 321 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿No ves que estoy ocupado?$"

KleinPkPowerRoom_EventScript_Klein_Text_0:
# 332 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Equipo de Investigación?\n"
	.string "¿O Equipo de la mierda?\p"
	.string "Qué te importa a ti el hackeo al Perro.$"

KleinPkPowerRoom_Text_KleinDefeated::
# 289 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Y ahora qué?\n"
	.string "¿Al talego de nuevo?$"

KleinPkPowerRoom_Text_PkPowerDefeated::
# 310 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Vaya tela! ¡A seguir trabajando!$"
