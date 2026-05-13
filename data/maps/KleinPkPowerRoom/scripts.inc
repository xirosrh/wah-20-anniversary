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
	special ShowMapNamePopup
# 39 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_0
# 41 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 43 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 44 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 45 "data/maps/KleinPkPowerRoom/scripts.pory"
	special HideMapNamePopUpWindow
# 46 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 47 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 48 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 49 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_1
# 50 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 51 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 52 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 53 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 54 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 55 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 56 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 57 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 58 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 59 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 60 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 61 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 62 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 63 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 64 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 65 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 66 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 67 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 68 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 69 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 70 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 71 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 72 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 73 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 74 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 75 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 76 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 77 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 78 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 80 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 81 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 82 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 83 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 84 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 85 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 86 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 87 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 88 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 89 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 90 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 91 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 92 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 93 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 94 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 95 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 96 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 97 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 98 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 99 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 100 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 101 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 102 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 103 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 104 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 105 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 106 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 107 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 109 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 110 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 111 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 112 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_CALL
# 113 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 114 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 115 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_ON
# 116 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 117 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_2
# 118 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 119 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 120 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 121 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 122 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 123 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 124 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 125 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 126 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 127 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 128 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_3
# 129 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 130 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 131 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 132 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_4
# 133 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 134 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 135 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 136 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 137 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 138 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovementandwait LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_OnFrame_Movement_5
# 140 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 141 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 142 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 143 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 144 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 145 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 146 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 147 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 148 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 149 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 151 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 152 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_7
# 153 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 154 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 155 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadedefaultbgm
# 156 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 60
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_8
# 158 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 159 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_B_PIKE, FALSE
# 160 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 161 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 162 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_3
# 163 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 164 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 165 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 166 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 167 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 168 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_9
# 169 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 170 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 171 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 172 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_OnFrame_Movement_10
# 174 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 175 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 176 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadedefaultbgm
# 177 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 178 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end


KleinPkPowerRoom_EventScript_BotonRojo::
# 183 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 184 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_2
# 190 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_1, MSGBOX_YESNO
# 191 "data/maps/KleinPkPowerRoom/scripts.pory"
	closemessage
# 192 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq KleinPkPowerRoom_EventScript_BotonRojo_5
KleinPkPowerRoom_EventScript_BotonRojo_1:
# 271 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end

KleinPkPowerRoom_EventScript_BotonRojo_2:
# 186 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_0, MSGBOX_AUTOCLOSE
	goto KleinPkPowerRoom_EventScript_BotonRojo_1

KleinPkPowerRoom_EventScript_BotonRojo_5:
# 194 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_CLICK
# 195 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 196 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 197 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_SUCCESS
# 198 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_kleinpkpower_SCREEN_JAIL_OPEN, 1
# 199 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 200 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 201 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 30
# 202 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_UNLOCK
# 203 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_OpenJail
# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_0
# 205 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_1
# 206 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 207 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 208 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 209 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 210 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 211 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_LEDGE
# 212 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_6
# 213 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 214 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 215 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 216 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_2
# 217 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 218 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 219 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_B_PIKE, FALSE
# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 221 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_3
# 222 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 223 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 224 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_OnFrame_Movement_9
# 225 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 226 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 227 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 228 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 229 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_4
# 230 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 231 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_KleinBattle
# 232 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 233 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_5
# 234 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 235 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_6
# 237 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 238 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 239 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_7
# 240 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 241 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 242 "data/maps/KleinPkPowerRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 243 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_8
# 245 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 246 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_9
# 247 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_PLAYER
# 248 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 249 "data/maps/KleinPkPowerRoom/scripts.pory"
	playse SE_PIN
# 250 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_4
# 251 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 252 "data/maps/KleinPkPowerRoom/scripts.pory"
	call KleinPkPowerRoom_EventScript_PkPowerBattle
# 253 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_BotonRojo_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
# 254 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 255 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxy LOCALID_KLEINROOM_PKPOWER, 2, 4
# 256 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_PKPOWER, 2, 4
# 257 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_PKPOWER, MOVEMENT_TYPE_FACE_UP
# 258 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxy LOCALID_KLEINROOM_KLEIN, 2, 7
# 259 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectxyperm LOCALID_KLEINROOM_KLEIN, 2, 7
# 260 "data/maps/KleinPkPowerRoom/scripts.pory"
	setobjectmovementtype LOCALID_KLEINROOM_KLEIN, MOVEMENT_TYPE_FACE_UP
# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 262 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 263 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_PLAYER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_11
# 264 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_NONE
# 265 "data/maps/KleinPkPowerRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 266 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 267 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	goto KleinPkPowerRoom_EventScript_BotonRojo_1


KleinPkPowerRoom_EventScript_OpenJail::
# 276 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_DOOR_OPENING_1, 0
# 277 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 278 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 10
# 279 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_DOOR_OPENING_2, 0
# 280 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 281 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 10
# 282 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_DOOR_OPENING_3, 0
# 283 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 284 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay 10
# 285 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatile 9, 5, METATILE_room_kleinpkpower_JAIL_FLOOR, 0
# 286 "data/maps/KleinPkPowerRoom/scripts.pory"
	special DrawWholeMapView
# 287 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitse
# 288 "data/maps/KleinPkPowerRoom/scripts.pory"
	setmetatileelevation 9, 6, 0
	return


KleinPkPowerRoom_EventScript_KleinBattle::
# 293 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, KleinPkPowerRoom_EventScript_KleinBattle_2
# 296 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_KLEIN
# 297 "data/maps/KleinPkPowerRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 298 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq KleinPkPowerRoom_EventScript_KleinBattle_5
# 301 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE, KleinPkPowerRoom_Text_KleinDefeated
KleinPkPowerRoom_EventScript_KleinBattle_1:
# 304 "data/maps/KleinPkPowerRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_KLEIN
# 305 "data/maps/KleinPkPowerRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	return

KleinPkPowerRoom_EventScript_KleinBattle_2:
# 294 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_MAIN, KleinPkPowerRoom_Text_KleinDefeated
	goto KleinPkPowerRoom_EventScript_KleinBattle_1

KleinPkPowerRoom_EventScript_KleinBattle_5:
# 299 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_KLEIN_MAIN, KleinPkPowerRoom_Text_KleinDefeated
	goto KleinPkPowerRoom_EventScript_KleinBattle_1


KleinPkPowerRoom_EventScript_PkPowerBattle::
# 314 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, KleinPkPowerRoom_EventScript_PkPowerBattle_2
# 317 "data/maps/KleinPkPowerRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_PKPOWER
# 318 "data/maps/KleinPkPowerRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 319 "data/maps/KleinPkPowerRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq KleinPkPowerRoom_EventScript_PkPowerBattle_5
# 322 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_ALTERNATIVE, KleinPkPowerRoom_Text_PkPowerDefeated
KleinPkPowerRoom_EventScript_PkPowerBattle_1:
# 325 "data/maps/KleinPkPowerRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_PKPOWER
	return

KleinPkPowerRoom_EventScript_PkPowerBattle_2:
# 315 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_MAIN, KleinPkPowerRoom_Text_PkPowerDefeated
	goto KleinPkPowerRoom_EventScript_PkPowerBattle_1

KleinPkPowerRoom_EventScript_PkPowerBattle_5:
# 320 "data/maps/KleinPkPowerRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_PKPOWER_MAIN, KleinPkPowerRoom_Text_PkPowerDefeated
	goto KleinPkPowerRoom_EventScript_PkPowerBattle_1


KleinPkPowerRoom_EventScript_PkPower::
# 334 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 335 "data/maps/KleinPkPowerRoom/scripts.pory"
	faceplayer
# 336 "data/maps/KleinPkPowerRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_PKPOWER, KleinPkPowerRoom_EventScript_PkPower_2
# 340 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_PkPower_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
KleinPkPowerRoom_EventScript_PkPower_1:
# 342 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_PKPOWER, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 343 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_PKPOWER
# 344 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end

KleinPkPowerRoom_EventScript_PkPower_2:
# 337 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_PkPower_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_PKPOWER
	goto KleinPkPowerRoom_EventScript_PkPower_1


KleinPkPowerRoom_EventScript_Klein::
# 349 "data/maps/KleinPkPowerRoom/scripts.pory"
	lock
# 350 "data/maps/KleinPkPowerRoom/scripts.pory"
	faceplayer
# 351 "data/maps/KleinPkPowerRoom/scripts.pory"
	msgbox KleinPkPowerRoom_EventScript_Klein_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_KLEIN
# 352 "data/maps/KleinPkPowerRoom/scripts.pory"
	applymovement LOCALID_KLEINROOM_KLEIN, KleinPkPowerRoom_EventScript_BotonRojo_Movement_10
# 353 "data/maps/KleinPkPowerRoom/scripts.pory"
	waitmovement LOCALID_KLEINROOM_KLEIN
# 354 "data/maps/KleinPkPowerRoom/scripts.pory"
	release
	end


# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_0:
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
# 40 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

# 49 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_1:
# 49 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 59 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_2:
# 59 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_in_place_up
	step_end

# 62 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_3:
# 62 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_thinking
	step_end

# 74 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_4:
# 74 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_angry
	step_end

# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_5:
# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_angry
# 139 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_in_place_up
	step_end

# 143 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_6:
# 143 "data/maps/KleinPkPowerRoom/scripts.pory"
	jump_in_place_down
	step_end

# 152 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_7:
# 152 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
# 152 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_8:
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 157 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

# 168 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_9:
# 168 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
	step_end

# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_OnFrame_Movement_10:
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_left
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	delay_16
# 173 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_up
	step_end

# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_0:
# 204 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 205 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_1:
# 205 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
# 205 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
	step_end

# 216 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_2:
# 216 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_happy
	step_end

# 221 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_3:
# 221 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 221 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
	step_end

# 229 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_4:
# 229 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_versus
	step_end

# 233 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_5:
# 233 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_down
# 233 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_question_mark
	step_end

# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_6:
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_down
# 236 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_right
	step_end

# 239 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_7:
# 239 "data/maps/KleinPkPowerRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_8:
# 244 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_right
	step_end

# 246 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_9:
# 246 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_left
	step_end

# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_10:
# 261 "data/maps/KleinPkPowerRoom/scripts.pory"
	face_up
	step_end

# 263 "data/maps/KleinPkPowerRoom/scripts.pory"
KleinPkPowerRoom_EventScript_BotonRojo_Movement_11:
# 263 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_left
# 263 "data/maps/KleinPkPowerRoom/scripts.pory"
	walk_up
	step_end

KleinPkPowerRoom_OnFrame_Text_0:
# 61 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.\n"
	.string "¿En qué puedo ayudarte?$"

KleinPkPowerRoom_OnFrame_Text_1:
# 65 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Que el Güindous no arranca?\n"
	.string "¿Y qué aparece en pantalla?$"

KleinPkPowerRoom_OnFrame_Text_2:
# 69 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Nada?\n"
	.string "¿Pero… tienes el ordenador encendido?$"

KleinPkPowerRoom_OnFrame_Text_3:
# 75 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Pues enchúfalo, hombre!\n"
	.string "¡Esas cosas se comprueban antes!$"

KleinPkPowerRoom_OnFrame_Text_4:
# 90 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.\n"
	.string "¿Qué necesitas?$"

KleinPkPowerRoom_OnFrame_Text_5:
# 94 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Cómo que has perdido el cursor!?\n"
	.string "¿Has probado a mover el ratón?$"

KleinPkPowerRoom_OnFrame_Text_6:
# 98 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "No será el ratón inalámbrico...\n"
	.string "¿Tiene pilas?$"

KleinPkPowerRoom_OnFrame_Text_7:
# 104 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Joder! ¡Pues pónselas!$"

KleinPkPowerRoom_OnFrame_Text_8:
# 119 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Aquí el soporte técnico.$"

KleinPkPowerRoom_OnFrame_Text_9:
# 123 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Que cuál es la tecla de “cualquier\n"
	.string "tecla”!? ¿¡Pero qué pregunta es esa!?$"

KleinPkPowerRoom_OnFrame_Text_10:
# 127 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Pues si el mensaje dice “pulse\n"
	.string "cualquier tecla”, haz lo que dice!$"

KleinPkPowerRoom_OnFrame_Text_11:
# 133 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Que no hay ninguna tecla que se llame\n"
	.string "“cualquier tecla”! ¡Pulsa una tecla\l"
	.string "cualquiera y ya!$"

KleinPkPowerRoom_OnFrame_Text_12:
# 140 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Esto es increíble! ¿Pero cómo puede\n"
	.string "haber gente así? ¡Estoy rodeado de\l"
	.string "inútiles! Pero se va a acabar...\p"
	.string "¡Los voy a echar a todos!\n"
	.string "¡A la puta calle!$"

KleinPkPowerRoom_OnFrame_Text_13:
# 150 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Eh, tú! ¡Aquí! ¡Ven!$"

KleinPkPowerRoom_OnFrame_Text_14:
# 160 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Sabes quién soy?$"

KleinPkPowerRoom_OnFrame_Text_15:
# 166 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Claro... Tú qué vas a saber...\n"
	.string "Soy Klein, el webmaster de WaH.\p"
	.string "Oye... Tienes que ayudarme, ¡la he liado\n"
	.string "parda!\p"
	.string "He hackeado al Perro Sanxe y para colmo\n"
	.string "me han metido en esta cárcel a la vez\l"
	.string "que se ha caído el foro...\n"
	.string "¿Puedes liberarme?$"

KleinPkPowerRoom_OnFrame_Text_16:
# 172 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Que no sabes cómo liberarme? ¡Pues es\n"
	.string "muy fácil!\p"
	.string "¿Ves ese botón rojo?$"

KleinPkPowerRoom_OnFrame_Text_17:
# 175 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Sí, ese botón! ¡Púlsalo y podré salir!\p"
	.string "¡Vamos, no me hagas esperar más, que\n"
	.string "tengo que levantar el foro!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_0:
# 186 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "La celda ya está abierta.$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_1:
# 190 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Quieres pulsar el botón rojo?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_2:
# 220 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Sí! ¡Soy libre!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_3:
# 227 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "Por cierto... ¿Tú quién eras?\n"
	.string "¿No será una trampa para encerrarme de\l"
	.string "nuevo?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_4:
# 243 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿¡Pero qué!?$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_5:
# 248 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Qué estáis haciendo?\n"
	.string "¡Si acabo de pagar la fianza para\l"
	.string "sacarlo de la cárcel!\p"
	.string "¿No podías quedarte quietecito tú\n"
	.string "también? Bah, qué más da...\p"
	.string "¡Venga, a levantar el foro!\n"
	.string "¡Que lleva caído todo el día!$"

KleinPkPowerRoom_EventScript_BotonRojo_Text_6:
# 253 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Perfecto! ¡Has superado la prueba!\n"
	.string "Hay que saber actuar bajo presión.\p"
	.string "¡Vamos, a levantar el foro!$"

KleinPkPowerRoom_EventScript_PkPower_Text_0:
# 337 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Pero mira que eres pesado eh? ¿Tú no\n"
	.string "tienes amigos u otra persona a la que\l"
	.string "molestar?$"

KleinPkPowerRoom_EventScript_PkPower_Text_1:
# 340 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿No ves que estoy ocupado?$"

KleinPkPowerRoom_EventScript_Klein_Text_0:
# 351 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Equipo de Investigación?\n"
	.string "¿O Equipo de la mierda?\p"
	.string "Qué te importa a ti el hackeo al Perro.$"

KleinPkPowerRoom_Text_KleinDefeated::
# 309 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¿Y ahora qué?\n"
	.string "¿Al talego de nuevo?$"

KleinPkPowerRoom_Text_PkPowerDefeated::
# 329 "data/maps/KleinPkPowerRoom/scripts.pory"
	.string "¡Vaya tela! ¡A seguir trabajando!$"
