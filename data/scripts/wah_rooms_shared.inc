WahRoomsShared_EventScript_Shop::
# 3 "data/scripts/wah_rooms_shared.pory"
	special OpenWahRoomsSharedMart
# 4 "data/scripts/wah_rooms_shared.pory"
	waitstate
# 5 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_EventScript_Shop_Text_0, MSGBOX_AUTOCLOSE
	return


WahRoomsShared_EventScript_Pokebox::
# 10 "data/scripts/wah_rooms_shared.pory"
	lock
# 11 "data/scripts/wah_rooms_shared.pory"
	compare VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM
	goto_if_eq WahRoomsShared_EventScript_Pokebox_2
# 16 "data/scripts/wah_rooms_shared.pory"
	waitse
# 17 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_ON
# 18 "data/scripts/wah_rooms_shared.pory"
	setmetatile VAR_TEMP_C, VAR_TEMP_D, VAR_TEMP_F, FALSE
# 19 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 20 "data/scripts/wah_rooms_shared.pory"
	waitse
# 21 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 22 "data/scripts/wah_rooms_shared.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, WahRoomsShared_EventScript_Pokebox_6
WahRoomsShared_EventScript_Pokebox_4:
# 34 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_MainMenu
	return

WahRoomsShared_EventScript_Pokebox_2:
# 12 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_RandomTeamBlocked, MSGBOX_AUTOCLOSE
# 13 "data/scripts/wah_rooms_shared.pory"
	release
	return

WahRoomsShared_EventScript_Pokebox_5:
# 23 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_LOGIN
# 24 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_SoftwareUpdate, MSGBOX_AUTOCLOSE_CENTER
# 25 "data/scripts/wah_rooms_shared.pory"
	waitse
# 26 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 27 "data/scripts/wah_rooms_shared.pory"
	playse SE_USE_ITEM
# 28 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_SoftwareUpdateExplanation, MSGBOX_AUTOCLOSE_CENTER
# 29 "data/scripts/wah_rooms_shared.pory"
	waitse
# 30 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 31 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_LOBBY_POKEBOX_POST_WAH_UPDATE_SEEN
	goto WahRoomsShared_EventScript_Pokebox_4

WahRoomsShared_EventScript_Pokebox_6:
# 22 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_LOBBY_POKEBOX_POST_WAH_UPDATE_SEEN, WahRoomsShared_EventScript_Pokebox_5
	goto WahRoomsShared_EventScript_Pokebox_4


WahRoomsShared_EventScript_Pokebox_MainMenu::
# 38 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_LOGIN
# 39 "data/scripts/wah_rooms_shared.pory"
	message WahRoomsShared_Text_Pokebox_MainPrompt
# 40 "data/scripts/wah_rooms_shared.pory"
	waitmessage
# 41 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_0, 0
# 42 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_1, 1
# 43 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_2, 2
# 44 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_3, 3
# 45 "data/scripts/wah_rooms_shared.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 46 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 47 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 48 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 49 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_EventScript_Pokebox_MainMenu_2
# 53 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_EventScript_Pokebox_MainMenu_3
# 55 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_EventScript_Pokebox_MainMenu_4
# 58 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_Shutdown
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_2:
# 50 "data/scripts/wah_rooms_shared.pory"
	callnative StartPokeBoxFromField_CB2
# 51 "data/scripts/wah_rooms_shared.pory"
	waitstate
# 52 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_Shutdown
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_3:
# 54 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_4:
# 56 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_Discord
	return


WahRoomsShared_EventScript_Pokebox_Discord::
# 63 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_EventScript_Pokebox_Discord_Text_0
# 64 "data/scripts/wah_rooms_shared.pory"
	load_field_pic FP_WAH_QR, 120, 80
# 65 "data/scripts/wah_rooms_shared.pory"
	waitbuttonpress
# 66 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 67 "data/scripts/wah_rooms_shared.pory"
	destroy_field_pic FP_WAH_QR
# 68 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_MainMenu
	return


WahRoomsShared_EventScript_Pokebox_HelpMenu::
# 73 "data/scripts/wah_rooms_shared.pory"
	message WahRoomsShared_Text_Pokebox_HelpPrompt
# 74 "data/scripts/wah_rooms_shared.pory"
	waitmessage
# 75 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_0, 0
# 76 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_1, 1
# 77 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_2, 2
# 78 "data/scripts/wah_rooms_shared.pory"
	dynmultistack 0, 0, FALSE, 3, 0, 0, DYN_MULTICHOICE_CB_NONE
# 79 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 80 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 81 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 82 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_EventScript_Pokebox_HelpMenu_2
# 90 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_EventScript_Pokebox_HelpMenu_3
# 95 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_MainMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_2:
# 83 "data/scripts/wah_rooms_shared.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, WahRoomsShared_EventScript_Pokebox_HelpMenu_6
# 86 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpSwapsBeforeChallenge, MSGBOX_AUTOCLOSE
WahRoomsShared_EventScript_Pokebox_HelpMenu_5:
# 88 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 89 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_3:
# 91 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpUnlock, MSGBOX_AUTOCLOSE
# 92 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 93 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_6:
# 84 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpSwapsAfterChallenge, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu_5


WahRoomsShared_EventScript_Pokebox_Shutdown::
# 100 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_OFF
# 101 "data/scripts/wah_rooms_shared.pory"
	setmetatile VAR_TEMP_C, VAR_TEMP_D, VAR_TEMP_E, FALSE
# 102 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 103 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_UnlockAllPokemon
# 104 "data/scripts/wah_rooms_shared.pory"
	release
	return


WahRoomsShared_OpenDoor::
# 142 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 143 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 144 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 145 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 146 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 147 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 148 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 149 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 150 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 151 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_CloseDoor::
# 156 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 157 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 158 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 159 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 160 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 161 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 162 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 163 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 164 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Closed, TRUE
# 165 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_SetDoorAsOpen::
# 170 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
	return


WahRoomsShared_SetPlayerTeleportGfxVars::
# 175 "data/scripts/wah_rooms_shared.pory"
	checkplayergender
# 176 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, MALE
	goto_if_eq WahRoomsShared_SetPlayerTeleportGfxVars_2
# 181 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_MAY_NORMAL
# 182 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_MAY_TELEPORTING_1
# 183 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_MAY_TELEPORTING_2
WahRoomsShared_SetPlayerTeleportGfxVars_1:
	return

WahRoomsShared_SetPlayerTeleportGfxVars_2:
# 177 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 178 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 179 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
	goto WahRoomsShared_SetPlayerTeleportGfxVars_1


WahRoomsShared_UpdatePlayerSpriteNormal::
# 189 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 190 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_D
# 191 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting1::
# 196 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 197 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 198 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting2::
# 203 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 204 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_F
# 205 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_Kecleon::
# 212 "data/scripts/wah_rooms_shared.pory"
	lock
# 213 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 214 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 215 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 243 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 245 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 217 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 218 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 220 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
# 221 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 222 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 223 "data/scripts/wah_rooms_shared.pory"
	waitse
# 224 "data/scripts/wah_rooms_shared.pory"
	playse SE_PIN
# 225 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, WahRoomsShared_Kecleon_Movement_0
# 226 "data/scripts/wah_rooms_shared.pory"
	waitse
# 227 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 228 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 229 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 230 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 231 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_TO_BLACK
# 232 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 233 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_FROM_BLACK
# 234 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 235 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_FOUND_TILE_KECLEON, WahRoomsShared_Kecleon_7
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_7:
# 236 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_FOUND_TILE_KECLEON
# 237 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_FoundTileKecleon
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_DevonScope_UseFromBag::
# 250 "data/scripts/wah_rooms_shared.pory"
	lockall
# 251 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_DevonScope_UseFromBag_Text_0, MSGBOX_DEFAULT
# 252 "data/scripts/wah_rooms_shared.pory"
	specialvar VAR_RESULT, HasInvisibleKecleonOnCurrentMap
# 253 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_DevonScope_UseFromBag_2
# 256 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_DevonScope_Text_NotDetected, MSGBOX_DEFAULT
WahRoomsShared_DevonScope_UseFromBag_1:
# 258 "data/scripts/wah_rooms_shared.pory"
	releaseall
	end

WahRoomsShared_DevonScope_UseFromBag_2:
# 254 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_DevonScope_Text_Detected, MSGBOX_DEFAULT
	goto WahRoomsShared_DevonScope_UseFromBag_1


WahRoomsShared_Kecleon_Recompensa::
# 271 "data/scripts/wah_rooms_shared.pory"
	random 2
# 272 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 274 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Recompensa_3
# 277 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Recompensa_4
WahRoomsShared_Kecleon_Recompensa_1:
	return

WahRoomsShared_Kecleon_Recompensa_3:
# 275 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Dinero
	goto WahRoomsShared_Kecleon_Recompensa_1

WahRoomsShared_Kecleon_Recompensa_4:
# 278 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos
	goto WahRoomsShared_Kecleon_Recompensa_1


WahRoomsShared_Kecleon_Dinero::
# 286 "data/scripts/wah_rooms_shared.pory"
	random 10
# 287 "data/scripts/wah_rooms_shared.pory"
	showmoneybox 0, 0
# 288 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 290 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_3
# 291 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_3
# 292 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_3
# 293 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_3
# 297 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_Dinero_4
# 298 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_Dinero_4
# 299 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_Dinero_4
# 303 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_Dinero_5
# 304 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_Dinero_5
# 308 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_Dinero_6
WahRoomsShared_Kecleon_Dinero_1:
# 313 "data/scripts/wah_rooms_shared.pory"
	delay 30
# 314 "data/scripts/wah_rooms_shared.pory"
	playse SE_SHOP
# 315 "data/scripts/wah_rooms_shared.pory"
	updatemoneybox
# 316 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 318 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_9
# 321 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_10
# 324 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_11
# 327 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_12
WahRoomsShared_Kecleon_Dinero_7:
# 331 "data/scripts/wah_rooms_shared.pory"
	hidemoneybox
	return

WahRoomsShared_Kecleon_Dinero_3:
# 294 "data/scripts/wah_rooms_shared.pory"
	addmoney 5000
# 295 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 0
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_4:
# 300 "data/scripts/wah_rooms_shared.pory"
	addmoney 8000
# 301 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 1
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_5:
# 305 "data/scripts/wah_rooms_shared.pory"
	addmoney 10000
# 306 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 2
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_6:
# 309 "data/scripts/wah_rooms_shared.pory"
	addmoney 15000
# 310 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 3
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_9:
# 319 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_0, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_10:
# 322 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_1, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_11:
# 325 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_2, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_12:
# 328 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_3, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7


WahRoomsShared_Kecleon_KitObjetos_BagFull::
# 336 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitObjetos_BagFull_Text_0, MSGBOX_DEFAULT
# 337 "data/scripts/wah_rooms_shared.pory"
	closemessage
	return


WahRoomsShared_Kecleon_KitObjetos::
# 342 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitObjetos_Text_0, MSGBOX_DEFAULT
# 343 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 344 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 345 "data/scripts/wah_rooms_shared.pory"
	random 3
# 346 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 348 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_KitObjetos_3
# 371 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_KitObjetos_4
# 394 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_KitObjetos_5
WahRoomsShared_Kecleon_KitObjetos_1:
	return

WahRoomsShared_Kecleon_KitObjetos_3:
# 349 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_ABILITY_CAPSULE, 1
# 350 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_7
# 354 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_REVIVE, 1
# 355 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_16
# 359 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 360 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_25
# 364 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_RESTORE, 3
# 365 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 366 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_31
	goto WahRoomsShared_Kecleon_KitObjetos_1

WahRoomsShared_Kecleon_KitObjetos_4:
# 372 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_ABILITY_PATCH, 1
# 373 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_10
# 377 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 378 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_19
# 382 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_POTION, 2
# 383 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_28
# 387 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_HEAL, 2
# 388 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 389 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_34
	goto WahRoomsShared_Kecleon_KitObjetos_1

WahRoomsShared_Kecleon_KitObjetos_5:
# 395 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_ABILITY_CAPSULE, 2
# 396 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_13
# 400 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_ABILITY_PATCH, 2
# 401 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 402 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitObjetos_22
	goto WahRoomsShared_Kecleon_KitObjetos_1

WahRoomsShared_Kecleon_KitObjetos_7:
# 351 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_10:
# 374 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_13:
# 397 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_16:
# 356 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_19:
# 379 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_22:
# 403 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_25:
# 361 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_28:
# 384 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_31:
# 367 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return

WahRoomsShared_Kecleon_KitObjetos_34:
# 390 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitObjetos_BagFull
	return


WahRoomsShared_Kecleon_ResetFlags::
# 412 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 413 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 414 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 415 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 416 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 417 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 418 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 419 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 420 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 421 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 422 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 423 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 424 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 425 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 426 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 427 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 428 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 429 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 430 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 431 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 432 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SERGIO
# 434 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 435 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 437 "data/scripts/wah_rooms_shared.pory"
	random 4
# 438 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 439 "data/scripts/wah_rooms_shared.pory"
	random 21
# 440 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 442 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 445 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 448 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 451 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 454 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 457 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 460 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 463 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 466 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 469 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 472 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 475 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 478 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 481 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 484 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 487 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 490 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 493 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 496 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 499 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
# 502 "data/scripts/wah_rooms_shared.pory"
	case 20, WahRoomsShared_Kecleon_ResetFlags_25
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 443 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 446 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 449 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 452 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 455 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 458 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 461 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 464 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 467 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 470 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 473 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 476 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 479 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 482 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 485 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 488 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 491 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 494 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 497 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 500 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_25:
# 503 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SERGIO
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 513 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 515 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 518 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 521 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 524 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 516 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 519 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 522 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 525 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 534 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 536 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 539 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 542 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 545 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 537 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 540 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 543 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 546 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 555 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 557 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 560 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 563 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 566 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 558 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 561 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 564 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 567 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 576 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 578 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 581 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 584 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 587 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 579 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 582 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 585 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 588 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 597 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 599 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 602 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 605 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 608 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 600 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 603 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 606 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 609 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 618 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 620 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 623 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 626 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 629 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 621 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 624 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 627 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 630 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 639 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 641 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 644 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 647 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 650 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 642 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 645 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 648 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 651 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 660 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 662 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 665 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 668 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 671 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 663 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 666 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 669 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 672 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 681 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 683 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 686 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 689 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 692 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 684 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 687 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 690 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 693 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 702 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 704 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 707 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 710 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 713 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 705 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 708 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 711 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 714 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 723 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 725 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 728 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 731 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 734 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 726 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 729 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 732 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 735 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 744 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 746 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 749 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 752 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 755 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 747 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 750 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 753 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 756 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 765 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 767 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 770 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 773 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 776 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 768 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 11, 4
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 771 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 10
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 774 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 777 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 3, 12
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 786 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 788 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 791 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 794 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 797 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 789 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 792 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 795 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 798 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 807 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 809 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 812 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 815 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 818 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 810 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 813 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 816 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 819 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 828 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 830 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 833 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 836 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 839 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 831 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 834 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 837 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 840 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 849 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 851 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 854 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 857 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 860 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 852 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 855 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 858 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 861 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 870 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 872 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 875 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 878 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 881 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 873 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 876 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 879 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 882 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 891 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 893 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 896 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 899 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 902 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 894 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 897 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 900 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 903 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 912 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 914 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 917 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 920 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 923 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 915 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 918 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 921 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 924 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 933 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 935 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 938 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 941 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 944 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 936 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 939 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 942 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 945 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 955 "data/scripts/wah_rooms_shared.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 956 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 957 "data/scripts/wah_rooms_shared.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 960 "data/scripts/wah_rooms_shared.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 963 "data/scripts/wah_rooms_shared.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 966 "data/scripts/wah_rooms_shared.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 958 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 961 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 964 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 967 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


WahRoomsShared_EventScript_AfterBattle::
# 974 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 975 "data/scripts/wah_rooms_shared.pory"
	special HealPlayerParty
# 976 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_Avaricia
# 977 "data/scripts/wah_rooms_shared.pory"
	call Pokebox_EventScript_ShowUnlocks
# 978 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_RESULT, VAR_0x8008
	return


# 225 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_Kecleon_Movement_0:
# 225 "data/scripts/wah_rooms_shared.pory"
	emote_exclamation_mark
	step_end

WahRoomsShared_EventScript_Shop_Text_0:
# 5 "data/scripts/wah_rooms_shared.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_0:
# 41 "data/scripts/wah_rooms_shared.pory"
	.string "Acceder a PC$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_1:
# 42 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cómo funciona?$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_2:
# 43 "data/scripts/wah_rooms_shared.pory"
	.string "Discord$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_3:
# 44 "data/scripts/wah_rooms_shared.pory"
	.string "Salir$"

WahRoomsShared_EventScript_Pokebox_Discord_Text_0:
# 63 "data/scripts/wah_rooms_shared.pory"
	.string "Escanea este QR para acceder a la\n"
	.string "comunidad de Whack a Hack\l"
	.string "(https://whackahack.com).\p"
	.string "Ahí podrás reportar errores que hayas\n"
	.string "encontrado al realizar este desafío,\l"
	.string "dar tu opinión y conocer una gran\l"
	.string "comunidad.$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_0:
# 75 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cuántos Pokémon puedo cambiar?$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_1:
# 76 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cómo desbloqueo nuevos Pokémon?$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_2:
# 77 "data/scripts/wah_rooms_shared.pory"
	.string "Volver$"

WahRoomsShared_Kecleon_Text_0:
# 220 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"

WahRoomsShared_DevonScope_UseFromBag_Text_0:
# 251 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.$"

WahRoomsShared_Kecleon_Dinero_Text_0:
# 319 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 5000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_1:
# 322 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 8000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_2:
# 325 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 10000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_3:
# 328 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 15000¥!$"

WahRoomsShared_Kecleon_KitObjetos_BagFull_Text_0:
# 336 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tu MOCHILA está llena!\nTile no pudo dejarte el resto del paquete.$"

WahRoomsShared_Kecleon_KitObjetos_Text_0:
# 342 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado un paquete de\n"
	.string "objetos!$"

WahRoomsShared_Text_Pokebox_SoftwareUpdate::
# 108 "data/scripts/wah_rooms_shared.pory"
	.string "¡El software de la PC se ha actualizado!$"

WahRoomsShared_Text_Pokebox_SoftwareUpdateExplanation::
# 112 "data/scripts/wah_rooms_shared.pory"
	.string "Ahora puedes cambiar hasta 3 Pokémon\n"
	.string "de tu equipo y sustituirlos por Pokémon\l"
	.string "de la caja, en lugar de solo 1.$"

WahRoomsShared_Text_Pokebox_MainPrompt::
# 116 "data/scripts/wah_rooms_shared.pory"
	.string "¿Qué quieres hacer?$"

WahRoomsShared_Text_Pokebox_RandomTeamBlocked::
# 120 "data/scripts/wah_rooms_shared.pory"
	.string "No puedes acceder a la PokéBox durante\n"
	.string "el desafío con Equipo aleatorio.\p"
	.string "Tu equipo original se restaurará cuando\n"
	.string "termine el desafío.$"

WahRoomsShared_Text_Pokebox_HelpPrompt::
# 124 "data/scripts/wah_rooms_shared.pory"
	.string "¿Sobre qué quieres saber?$"

WahRoomsShared_Text_Pokebox_HelpSwapsBeforeChallenge::
# 128 "data/scripts/wah_rooms_shared.pory"
	.string "Puedes reemplazar solo uno de los\n"
	.string "Pokémon predefinidos del equipo\l"
	.string "seleccionado por uno de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 5\l"
	.string "Pokémon del equipo original.$"

WahRoomsShared_Text_Pokebox_HelpSwapsAfterChallenge::
# 132 "data/scripts/wah_rooms_shared.pory"
	.string "Puedes reemplazar hasta 3 Pokémon\n"
	.string "predefinidos del equipo seleccionado\l"
	.string "por Pokémon de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 3\l"
	.string "Pokémon del equipo original.$"

WahRoomsShared_Text_Pokebox_HelpUnlock::
# 137 "data/scripts/wah_rooms_shared.pory"
	.string "Algunos Pokémon se desbloquean\n"
	.string "comprándolos en la PC.\p"
	.string "Otros, se obtienen avanzando en el\n"
	.string "juego, consiguiendo Logros o con\l"
	.string "eventos especiales.\p"
	.string "Para descubrir cómo desbloquear un\n"
	.string "Pokémon, presiona {COLOR RED}A{COLOR DARK_GRAY} en su sombra.$"

WahRoomsShared_DevonScope_Text_Detected::
# 262 "data/scripts/wah_rooms_shared.pory"
	.string "¡El detector reacciona!\p"
	.string "Hay un Pokémon invisible cerca.$"

WahRoomsShared_DevonScope_Text_NotDetected::
# 266 "data/scripts/wah_rooms_shared.pory"
	.string "No detecta ningún Pokémon invisible\n"
	.string "cerca.$"
