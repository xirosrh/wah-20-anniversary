WahRoomsShared_OpenDoor::
# 3 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 4 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 5 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 6 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 7 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 8 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 9 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 10 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 11 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 12 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_CloseDoor::
# 17 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 18 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 19 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 20 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 21 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 22 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 23 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 24 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 25 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Closed, TRUE
# 26 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_SetDoorAsOpen::
# 31 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
	return


WahRoomsShared_SetPlayerTeleportGfxVars::
# 36 "data/scripts/wah_rooms_shared.pory"
	checkplayergender
# 37 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, MALE
	goto_if_eq WahRoomsShared_SetPlayerTeleportGfxVars_2
# 42 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_MAY_NORMAL
# 43 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_MAY_TELEPORTING_1
# 44 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_MAY_TELEPORTING_2
WahRoomsShared_SetPlayerTeleportGfxVars_1:
	return

WahRoomsShared_SetPlayerTeleportGfxVars_2:
# 38 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 39 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 40 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
	goto WahRoomsShared_SetPlayerTeleportGfxVars_1


WahRoomsShared_UpdatePlayerSpriteNormal::
# 50 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 51 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_D
# 52 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting1::
# 57 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 58 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 59 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting2::
# 64 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 65 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_F
# 66 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_Kecleon::
# 73 "data/scripts/wah_rooms_shared.pory"
	lock
# 74 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 75 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 76 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 99 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 101 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 78 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 79 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 81 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
# 82 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 83 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 84 "data/scripts/wah_rooms_shared.pory"
	waitse
# 85 "data/scripts/wah_rooms_shared.pory"
	playse SE_PIN
# 86 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, WahRoomsShared_Kecleon_Movement_0
# 87 "data/scripts/wah_rooms_shared.pory"
	waitse
# 88 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 89 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 90 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 91 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 92 "data/scripts/wah_rooms_shared.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 93 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 94 "data/scripts/wah_rooms_shared.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_Recompensa::
# 106 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_KECLEON_ENTREGA_TERA_ORB, WahRoomsShared_Kecleon_Recompensa_2
# 116 "data/scripts/wah_rooms_shared.pory"
	random 2
# 117 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 119 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Recompensa_6
# 122 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Recompensa_7
WahRoomsShared_Kecleon_Recompensa_1:
	return

WahRoomsShared_Kecleon_Recompensa_2:
# 108 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_TERA_ORB
# 109 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_KECLEON_ENTREGA_TERA_ORB
# 110 "data/scripts/wah_rooms_shared.pory"
	setflag B_FLAG_TERA_ORB_CHARGED
# 111 "data/scripts/wah_rooms_shared.pory"
	setflag B_FLAG_TERA_ORB_NO_COST
	return

WahRoomsShared_Kecleon_Recompensa_6:
# 120 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Dinero
	goto WahRoomsShared_Kecleon_Recompensa_1

WahRoomsShared_Kecleon_Recompensa_7:
# 123 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion
	goto WahRoomsShared_Kecleon_Recompensa_1


WahRoomsShared_Kecleon_Dinero::
# 132 "data/scripts/wah_rooms_shared.pory"
	showmoneybox 0, 0
# 133 "data/scripts/wah_rooms_shared.pory"
	random 10
# 134 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 136 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_3
# 137 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_3
# 138 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_3
# 139 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_3
# 143 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_Dinero_4
# 144 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_Dinero_4
# 145 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_Dinero_4
# 149 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_Dinero_5
# 150 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_Dinero_5
# 154 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_Dinero_6
WahRoomsShared_Kecleon_Dinero_1:
# 159 "data/scripts/wah_rooms_shared.pory"
	delay 30
# 160 "data/scripts/wah_rooms_shared.pory"
	playse SE_SHOP
# 161 "data/scripts/wah_rooms_shared.pory"
	updatemoneybox
# 162 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 164 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_9
# 167 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_10
# 170 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_11
# 173 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_12
WahRoomsShared_Kecleon_Dinero_7:
# 177 "data/scripts/wah_rooms_shared.pory"
	hidemoneybox
	return

WahRoomsShared_Kecleon_Dinero_3:
# 140 "data/scripts/wah_rooms_shared.pory"
	addmoney 5000
# 141 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 0
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_4:
# 146 "data/scripts/wah_rooms_shared.pory"
	addmoney 8000
# 147 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 1
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_5:
# 151 "data/scripts/wah_rooms_shared.pory"
	addmoney 10000
# 152 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 2
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_6:
# 155 "data/scripts/wah_rooms_shared.pory"
	addmoney 15000
# 156 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 3
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_9:
# 165 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_0, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_10:
# 168 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_1, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_11:
# 171 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_2, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_12:
# 174 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_3, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7


WahRoomsShared_Kecleon_KitCuracion::
# 182 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_Text_0, MSGBOX_AUTOCLOSE
# 183 "data/scripts/wah_rooms_shared.pory"
	random 2
# 184 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 186 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_KitCuracion_3
# 191 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_KitCuracion_4
WahRoomsShared_Kecleon_KitCuracion_1:
	return

WahRoomsShared_Kecleon_KitCuracion_3:
# 187 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_REVIVE, 1
# 188 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 189 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_RESTORE, 3
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_4:
# 192 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 193 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_POTION, 2
# 194 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_HEAL, 2
	goto WahRoomsShared_Kecleon_KitCuracion_1


WahRoomsShared_Kecleon_ResetFlags::
# 201 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 202 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 203 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 204 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 205 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 206 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 207 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 208 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 209 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 210 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 211 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 212 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 213 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 214 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 215 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 216 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 217 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 218 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 219 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 220 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 221 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SERGIO
# 223 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 224 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 226 "data/scripts/wah_rooms_shared.pory"
	random 4
# 227 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 228 "data/scripts/wah_rooms_shared.pory"
	random 21
# 229 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 231 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 234 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 237 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 240 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 243 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 246 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 249 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 252 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 255 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 258 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 261 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 264 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 267 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 270 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 273 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 276 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 279 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 282 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 285 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 288 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
# 291 "data/scripts/wah_rooms_shared.pory"
	case 20, WahRoomsShared_Kecleon_ResetFlags_25
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 232 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 235 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 238 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 241 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 244 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 247 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 250 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 253 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 256 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 259 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 262 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 265 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 268 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 271 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 274 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 277 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 280 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 283 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 286 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 289 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_25:
# 292 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SERGIO
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 302 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 304 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 307 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 310 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 313 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 305 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 308 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 311 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 314 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 323 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 325 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 328 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 331 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 334 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 326 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 329 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 332 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 335 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 344 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 346 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 349 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 352 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 355 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 347 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 350 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 353 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 356 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 365 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 367 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 370 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 373 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 376 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 368 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 371 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 374 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 377 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 386 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 388 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 391 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 394 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 397 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 389 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 2, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 392 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 395 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 10, 5
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 398 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 407 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 409 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 412 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 415 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 418 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 410 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 413 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 416 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 419 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 428 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 430 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 433 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 436 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 439 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 431 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 434 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 437 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 440 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 449 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 451 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 454 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 457 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 460 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 452 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 455 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 458 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 461 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 470 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 472 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 475 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 478 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 481 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 473 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 476 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 479 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 482 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 491 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 493 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 496 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 499 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 502 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 494 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 497 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 500 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 503 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 512 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 514 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 517 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 520 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 523 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 515 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 518 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 521 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 524 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 533 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 535 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 538 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 541 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 544 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 536 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 539 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 542 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 545 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 554 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 556 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 559 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 562 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 565 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 557 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 11, 4
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 560 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 10
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 563 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 566 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 3, 12
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 575 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 577 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 580 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 583 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 586 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 578 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 581 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 584 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 587 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 596 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 598 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 601 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 604 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 607 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 599 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 602 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 605 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 608 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 617 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 619 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 622 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 625 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 628 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 620 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 623 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 626 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 629 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 638 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 640 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 643 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 646 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 649 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 641 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 644 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 647 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 650 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 659 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 661 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 664 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 667 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 670 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 662 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 665 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 668 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 671 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 680 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 682 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 685 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 688 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 691 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 683 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 686 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 689 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 692 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 701 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 703 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 706 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 709 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 712 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 704 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 707 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 710 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 713 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 722 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 724 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 727 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 730 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 733 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 725 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 728 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 731 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 734 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


# 86 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_Kecleon_Movement_0:
# 86 "data/scripts/wah_rooms_shared.pory"
	emote_exclamation_mark
	step_end

WahRoomsShared_Kecleon_Text_0:
# 81 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"

WahRoomsShared_Kecleon_Dinero_Text_0:
# 165 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 5000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_1:
# 168 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 8000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_2:
# 171 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 10000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_3:
# 174 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 15000¥!$"

WahRoomsShared_Kecleon_KitCuracion_Text_0:
# 182 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado un kit de\n"
	.string "curación!$"
