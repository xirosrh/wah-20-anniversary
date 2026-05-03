KleinPkPowerRoom_MapScripts::
# 5 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, KleinPkPowerRoom_OnLoad
# 9 "data/maps/KleinPkPowerRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, KleinPkPowerRoom_OnTransition
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
# 14 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_KLEIN, KleinPkPowerRoom_OnLoad_3
KleinPkPowerRoom_OnLoad_1:
	end

KleinPkPowerRoom_OnLoad_2:
# 15 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_kleinpkpower_SCREEN_JAIL_OPEN, 1
# 16 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_FLOOR, 0
# 17 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatileelevation 9, 6, 0
# 18 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_PKPOWER, 2, 4
# 19 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_PKPOWER, MOVEMENT_TYPE_FACE_UP
# 20 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_KLEIN, 2, 7
# 21 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_KLEIN, MOVEMENT_TYPE_FACE_UP
# 22 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto KleinPkPowerRoom_OnLoad_1

KleinPkPowerRoom_OnLoad_3:
# 14 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_OnLoad_2
	goto KleinPkPowerRoom_OnLoad_1


KleinPkPowerRoom_OnWarp_PlayerTurnNorth::
# 28 "data/maps/KleinPkPowerRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


KleinPkPowerRoom_OnTransition::
# 33 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_KelinPkPower
	end


KleinPkPowerRoom_OnFrame::
# 38 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_0
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 42 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 43 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 44 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 45 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 46 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_1
# 48 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 49 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 50 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 51 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 52 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 53 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 54 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 55 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 56 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 57 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 58 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 59 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 60 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 61 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 62 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 63 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 64 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 65 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 66 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 67 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 68 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 69 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 70 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 71 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 72 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 73 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 74 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 75 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 76 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 78 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 79 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 80 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 81 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 82 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 83 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 84 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 85 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 86 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 87 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 88 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 89 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 90 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 91 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 92 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 93 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 94 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 95 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 96 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 97 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 98 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 99 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 100 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 101 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 102 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 103 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 104 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 105 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 107 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 108 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 109 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 110 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 111 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 112 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 113 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 114 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 115 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 116 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 117 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 118 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 119 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 120 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 121 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 122 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 123 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 124 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 125 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 126 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 127 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 128 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 129 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 130 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 131 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 132 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 133 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 134 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 135 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 136 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 137 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_5
# 138 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 140 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 141 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 142 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 143 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 144 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 145 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 146 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 147 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 149 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_7
# 151 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 152 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadedefaultbgm
# 154 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_8
# 156 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_B_PIKE, FALSE
# 158 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 159 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 160 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_3
# 161 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 162 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 163 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 164 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 165 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 166 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_9
# 167 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 168 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 170 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_10
# 172 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 174 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadedefaultbgm
# 175 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 176 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end


KleinPkPowerRoom_EventScript_BotonRojo::
# 181 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 182 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_2
# 188 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_1, MSGBOX_YESNO
# 189 "data/maps/KleinPkPowerRoom/scripts.pory"
	closemessage
# 190 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq KleinPkPowerRoom_EventScript_BotonRojo_5
KleinPkPowerRoom_EventScript_BotonRojo_1:
# 267 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end

KleinPkPowerRoom_EventScript_BotonRojo_2:
# 184 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_0, MSGBOX_AUTOCLOSE
	goto KleinPkPowerRoom_EventScript_BotonRojo_1

KleinPkPowerRoom_EventScript_BotonRojo_5:
# 192 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_CLICK
# 193 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 194 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 195 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_SUCCESS
# 196 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_kleinpkpower_SCREEN_JAIL_OPEN, 1
# 197 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 198 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 199 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 200 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_UNLOCK
# 201 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_OpenJail
# 202 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_0
# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_1
# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 205 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 206 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 207 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 208 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 209 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 210 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 211 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 212 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 213 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 214 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_2
# 215 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 216 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 217 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_B_PIKE, FALSE
# 218 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_3
# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 221 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 222 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_9
# 223 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 224 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 225 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 226 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 227 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_4
# 228 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 229 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_KleinBattle
# 230 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 231 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_5
# 232 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 233 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_6
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 237 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_7
# 238 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 239 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 240 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 241 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 242 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_8
# 243 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_9
# 245 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 246 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 247 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 248 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_4
# 249 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 250 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_PkPowerBattle
# 251 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 252 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 253 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxy LOCALID_KLEINROOM_PKPOWER, 2, 4
# 254 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_PKPOWER, 2, 4
# 255 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_PKPOWER, MOVEMENT_TYPE_FACE_UP
# 256 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxy LOCALID_KLEINROOM_KLEIN, 2, 7
# 257 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_KLEIN, 2, 7
# 258 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_KLEIN, MOVEMENT_TYPE_FACE_UP
# 259 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 260 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_11
# 262 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_NONE
# 263 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 264 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
	goto KleinPkPowerRoom_EventScript_BotonRojo_1


KleinPkPowerRoom_EventScript_OpenJail::
# 272 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_DOOR_OPENING_1, 0
# 273 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 274 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 10
# 275 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_DOOR_OPENING_2, 0
# 276 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 277 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 10
# 278 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_DOOR_OPENING_3, 0
# 279 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 280 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 10
# 281 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_FLOOR, 0
# 282 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 283 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 284 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatileelevation 9, 6, 0
	return


KleinPkPowerRoom_EventScript_KleinBattle::
# 289 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, KleinPkPowerRoom_EventScript_KleinBattle_2
# 292 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_KLEIN
# 293 "data/maps/KleinPkPowerRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 294 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq KleinPkPowerRoom_EventScript_KleinBattle_5
# 297 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE, KleinPkPowerRoom_Text_KleinDefeated
KleinPkPowerRoom_EventScript_KleinBattle_1:
# 300 "data/maps/KleinPkPowerRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_KLEIN
# 301 "data/maps/KleinPkPowerRoom/scripts.pory"
	special HealPlayerParty
	return

KleinPkPowerRoom_EventScript_KleinBattle_2:
# 290 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_MAIN, KleinPkPowerRoom_Text_KleinDefeated
	goto KleinPkPowerRoom_EventScript_KleinBattle_1

KleinPkPowerRoom_EventScript_KleinBattle_5:
# 295 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_MAIN, KleinPkPowerRoom_Text_KleinDefeated
	goto KleinPkPowerRoom_EventScript_KleinBattle_1


KleinPkPowerRoom_EventScript_PkPowerBattle::
# 310 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, KleinPkPowerRoom_EventScript_PkPowerBattle_2
# 313 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_PKPOWER
# 314 "data/maps/KleinPkPowerRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 315 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq KleinPkPowerRoom_EventScript_PkPowerBattle_5
# 318 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE, KleinPkPowerRoom_Text_PkPowerDefeated
KleinPkPowerRoom_EventScript_PkPowerBattle_1:
# 321 "data/maps/KleinPkPowerRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_PKPOWER
# 322 "data/maps/KleinPkPowerRoom/scripts.pory"
	special HealPlayerParty
	return

KleinPkPowerRoom_EventScript_PkPowerBattle_2:
# 311 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_MAIN, KleinPkPowerRoom_Text_PkPowerDefeated
	goto KleinPkPowerRoom_EventScript_PkPowerBattle_1

KleinPkPowerRoom_EventScript_PkPowerBattle_5:
# 316 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_MAIN, KleinPkPowerRoom_Text_PkPowerDefeated
	goto KleinPkPowerRoom_EventScript_PkPowerBattle_1


KleinPkPowerRoom_EventScript_PkPower::
# 331 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 332 "data/maps/KleinPkPowerRoom/scripts.pory"
	faceplayer
# 333 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_EventScript_PkPower_2
# 337 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_PkPower_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
KleinPkPowerRoom_EventScript_PkPower_1:
# 339 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 340 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 341 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end

KleinPkPowerRoom_EventScript_PkPower_2:
# 334 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_PkPower_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
	goto KleinPkPowerRoom_EventScript_PkPower_1


KleinPkPowerRoom_EventScript_Klein::
# 346 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 347 "data/maps/KleinPkPowerRoom/scripts.pory"
	faceplayer
# 348 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_Klein_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 349 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 350 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 351 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end


# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_0:
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

# 47 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_1:
# 47 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 57 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_2:
# 57 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_in_place_up
	step_end

# 60 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_3:
# 60 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_thinking
	step_end

# 72 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_4:
# 72 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_angry
	step_end

# 137 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_5:
# 137 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_angry
# 137 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_in_place_up
	step_end

# 141 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_6:
# 141 "data/maps/KleinPkPowerRoom/scripts.pory"
	jump_in_place_down
	step_end

# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_7:
# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_8:
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

# 166 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_9:
# 166 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
	step_end

# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_10:
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_left
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_up
	step_end

# 202 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_0:
# 202 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_1:
# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
	step_end

# 214 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_2:
# 214 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_happy
	step_end

# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_3:
# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
	step_end

# 227 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_4:
# 227 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_versus
	step_end

# 231 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_5:
# 231 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_down
# 231 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
	step_end

# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_6:
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 237 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_7:
# 237 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 242 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_8:
# 242 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
	step_end

# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_9:
# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_left
	step_end

# 259 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_10:
# 259 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_up
	step_end

# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_11:
# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

KleinPkPowerRoom_OnFrame_Text_0:
# 59 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.\n"
	.string "¿En qué puedo ayudarte?$"

KleinPkPowerRoom_OnFrame_Text_1:
# 63 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Que el Güindous no arranca?\n"
	.string "¿Y qué aparece en pantalla?$"

KleinPkPowerRoom_OnFrame_Text_2:
# 67 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Nada?\n"
	.string "¿Pero… tienes el ordenador encendido?$"

KleinPkPowerRoom_OnFrame_Text_3:
# 73 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Pues enchúfalo, hombre!\n"
	.string "¡Esas cosas se comprueban antes!$"

KleinPkPowerRoom_OnFrame_Text_4:
# 88 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.\n"
	.string "¿Qué necesitas?$"

KleinPkPowerRoom_OnFrame_Text_5:
# 92 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Cómo que has perdido el cursor!?\n"
	.string "¿Has probado a mover el ratón?$"

KleinPkPowerRoom_OnFrame_Text_6:
# 96 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "No será el ratón inalámbrico...\n"
	.string "¿Tiene pilas?$"

KleinPkPowerRoom_OnFrame_Text_7:
# 102 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Joder! ¡Pues pónselas!$"

KleinPkPowerRoom_OnFrame_Text_8:
# 117 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.$"

KleinPkPowerRoom_OnFrame_Text_9:
# 121 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Que cuál es la tecla de “cualquier\n"
	.string "tecla”!? ¿¡Pero qué pregunta es esa!?$"

KleinPkPowerRoom_OnFrame_Text_10:
# 125 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Pues si el mensaje dice “pulse\n"
	.string "cualquier tecla”, haz lo que dice!$"

KleinPkPowerRoom_OnFrame_Text_11:
# 131 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Que no hay ninguna tecla que se llame\n"
	.string "“cualquier tecla”! ¡Pulsa una tecla\l"
	.string "cualquiera y ya!$"

KleinPkPowerRoom_OnFrame_Text_12:
# 138 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Esto es increíble! ¿Pero cómo puede\n"
	.string "haber gente así? ¡Estoy rodeado de\l"
	.string "inútiles! Pero se va a acabar...\p"
	.string "¡Los voy a echar a todos!\n"
	.string "¡A la puta calle!$"

KleinPkPowerRoom_OnFrame_Text_13:
# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Eh, tú! ¡Aquí! ¡Ven!$"

KleinPkPowerRoom_OnFrame_Text_14:
# 158 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Sabes quién soy?$"

KleinPkPowerRoom_OnFrame_Text_15:
# 164 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Claro... Tú qué vas a saber...\n"
	.string "Soy Klein, el webmaster de WaH.\p"
	.string "Oye... Tienes que ayudarme, ¡la he liado\n"
	.string "parda!\p"
	.string "He hackeado al Perro Sanxe y para colmo\n"
	.string "me han metido en esta cárcel a la vez\l"
	.string "que se ha caído el foro...\n"
	.string "¿Puedes liberarme?$"

KleinPkPowerRoom_OnFrame_Text_16:
# 170 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Que no sabes cómo liberarme? ¡Pues es\n"
	.string "muy fácil!\p"
	.string "¿Ves ese botón rojo?$"

KleinPkPowerRoom_OnFrame_Text_17:
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Sí, ese botón! ¡Púlsalo y podré salir!\p"
	.string "¡Vamos, no me hagas esperar más, que\n"
	.string "tengo que levantar el foro!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_0:
# 184 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "La celda ya está abierta.$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_1:
# 188 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Quieres pulsar el botón rojo?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_2:
# 218 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Sí! ¡Soy libre!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_3:
# 225 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Por cierto... ¿Tú quién eras?\n"
	.string "¿No será una trampa para encerrarme de\l"
	.string "nuevo?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_4:
# 241 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Pero qué!?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_5:
# 246 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Qué estáis haciendo?\n"
	.string "¡Si acabo de pagar la fianza para\l"
	.string "sacarlo de la cárcel!\p"
	.string "¿No podías quedarte quietecito tú\n"
	.string "también? Bah, qué más da...\p"
	.string "¡Venga, a levantar el foro!\n"
	.string "¡Que lleva caído todo el día!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_6:
# 251 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Perfecto! ¡Has superado la prueba!\n"
	.string "Hay que saber actuar bajo presión.\p"
	.string "¡Vamos, a levantar el foro!$"

KleinPkPowerRoom_EventScript_PkPower_Text_0:
# 334 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

KleinPkPowerRoom_EventScript_PkPower_Text_1:
# 337 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿No ves que estoy ocupado?$"

KleinPkPowerRoom_EventScript_Klein_Text_0:
# 348 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Equipo de Investigación?\n"
	.string "¿O Equipo de la mierda?\p"
	.string "Qué te importa a ti el hackeo al Perro.$"

KleinPkPowerRoom_Text_KleinDefeated::
# 305 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Y ahora qué?\n"
	.string "¿Al talego de nuevo?$"

KleinPkPowerRoom_Text_PkPowerDefeated::
# 326 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Vaya tela! ¡A seguir trabajando!$"
