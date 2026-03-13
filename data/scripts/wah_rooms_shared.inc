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


WahRoomsShared_Kecleon::
# 38 "data/scripts/wah_rooms_shared.pory"
	lock
# 39 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 40 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 41 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 64 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 66 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 43 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 44 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 46 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_UseDevonScopeMonAttacked, MSGBOX_AUTOCLOSE
# 47 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 48 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 49 "data/scripts/wah_rooms_shared.pory"
	waitse
# 50 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 51 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 52 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 57 "data/scripts/wah_rooms_shared.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 58 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 59 "data/scripts/wah_rooms_shared.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_ResetFlags::
# 73 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 74 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 75 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 76 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 77 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 78 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 79 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 80 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 81 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 82 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 83 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 84 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 85 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 86 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 87 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 88 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 89 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 90 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 91 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 92 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 94 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 95 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 97 "data/scripts/wah_rooms_shared.pory"
	random 4
# 98 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 99 "data/scripts/wah_rooms_shared.pory"
	random 20
# 100 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 102 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 105 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 108 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 111 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 114 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 117 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 120 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 123 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 126 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 129 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 132 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 135 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 138 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 141 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 144 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 147 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 150 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 153 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 156 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 159 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 103 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 106 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 109 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 112 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 115 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 118 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 121 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 124 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 127 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 130 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 133 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 136 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 139 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 142 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 145 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 148 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 151 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 154 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 157 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 160 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 170 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 172 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 175 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 178 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 181 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 173 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 176 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 179 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 182 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 191 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 193 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 196 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 199 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 202 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 194 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 197 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 200 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 203 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 212 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 214 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 217 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 220 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 223 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 215 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 218 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 221 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 224 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 233 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 235 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 238 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 241 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 244 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 236 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 239 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 242 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 245 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 254 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 256 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 259 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 262 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 265 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 257 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 2, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 260 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 263 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 10, 5
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 266 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 275 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 277 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 280 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 283 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 286 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 278 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 281 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 284 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 287 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 296 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 298 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 301 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 304 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 307 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 299 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 302 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 305 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 308 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 317 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 319 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 322 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 325 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 328 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 320 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 323 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 326 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 329 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 338 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 340 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 343 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 346 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 349 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 341 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 344 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 347 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 350 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 359 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 361 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 364 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 367 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 370 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 362 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 365 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 368 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 371 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 380 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 382 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 385 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 388 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 391 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 383 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 386 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 389 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 392 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 401 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 403 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 406 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 409 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 412 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 404 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 407 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 410 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 413 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 422 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 424 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 427 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 430 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 433 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 425 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 428 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 431 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 434 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 443 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 445 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 448 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 451 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 454 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 446 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 449 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 452 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 455 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 464 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 466 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 469 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 472 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 475 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 467 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 470 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 473 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 476 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 485 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 487 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 490 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 493 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 496 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 488 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 491 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 494 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 497 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 506 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 508 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 511 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 514 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 517 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 509 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 512 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 515 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 518 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 527 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 529 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 532 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 535 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 538 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 530 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 533 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 536 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 539 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 548 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 550 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 553 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 556 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 559 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 551 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 554 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 557 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 560 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 569 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 571 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 574 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 577 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 580 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 572 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 575 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 578 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 581 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 590 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 592 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 595 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 598 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 601 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 593 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 596 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 599 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 602 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

