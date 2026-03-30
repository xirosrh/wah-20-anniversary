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
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
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
# 55 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 57 "data/scripts/wah_rooms_shared.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 58 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 59 "data/scripts/wah_rooms_shared.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_Recompensa::
	return


WahRoomsShared_Kecleon_ResetFlags::
# 75 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 76 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 77 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 78 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 79 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 80 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 81 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 82 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 83 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 84 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 85 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 86 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 87 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 88 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 89 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 90 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 91 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 92 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 93 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 94 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 96 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 97 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 99 "data/scripts/wah_rooms_shared.pory"
	random 4
# 100 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 101 "data/scripts/wah_rooms_shared.pory"
	random 20
# 102 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 104 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 107 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 110 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 113 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 116 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 119 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 122 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 125 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 128 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 131 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 134 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 137 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 140 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 143 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 146 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 149 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 152 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 155 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 158 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 161 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 105 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 108 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 111 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 114 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 117 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 120 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 123 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 126 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 129 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 132 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 135 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 138 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 141 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 144 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 147 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 150 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 153 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 156 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 159 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 162 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 172 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 174 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 177 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 180 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 183 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 175 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 178 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 181 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 184 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 193 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 195 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 198 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 201 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 204 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 196 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 199 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 202 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 205 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 214 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 216 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 219 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 222 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 225 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 217 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 220 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 223 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 226 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 235 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 237 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 240 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 243 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 246 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 238 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 241 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 244 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 247 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 256 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 258 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 261 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 264 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 267 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 259 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 2, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 262 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 265 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 10, 5
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 268 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 277 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 279 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 282 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 285 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 288 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 280 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 283 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 286 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 289 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 298 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 300 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 303 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 306 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 309 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 301 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 304 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 307 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 310 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 319 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 321 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 324 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 327 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 330 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 322 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 325 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 328 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 331 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 340 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 342 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 345 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 348 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 351 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 343 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 346 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 349 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 352 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 361 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 363 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 366 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 369 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 372 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 364 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 367 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 370 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 373 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 382 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 384 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 387 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 390 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 393 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 385 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 388 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 391 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 394 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 403 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 405 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 408 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 411 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 414 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 406 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 409 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 412 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 415 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 424 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 426 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 429 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 432 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 435 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 427 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 430 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 433 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 436 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 0, 0
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 445 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 447 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 450 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 453 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 456 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 448 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 451 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 454 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 457 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 466 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 468 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 471 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 474 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 477 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 469 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 472 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 475 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 478 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 487 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 489 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 492 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 495 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 498 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 490 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 493 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 496 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 499 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 508 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 510 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 513 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 516 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 519 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 511 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 514 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 517 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 520 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 529 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 531 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 534 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 537 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 540 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 532 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 535 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 538 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 541 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 550 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 552 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 555 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 558 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 561 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 553 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 556 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 559 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 562 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 571 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 573 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 576 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 579 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 582 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 574 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 577 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 580 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 583 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 592 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 594 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 597 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 600 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 603 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 595 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 598 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 601 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 604 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


WahRoomsShared_Kecleon_Text_0:
# 46 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"
