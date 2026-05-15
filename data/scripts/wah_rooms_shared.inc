WahRoomsShared_EventScript_Shop::
# 2 "data/scripts/wah_rooms_shared.pory"
	pokemart WahRoomsShared_MartItems
# 3 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_EventScript_Shop_Text_0, MSGBOX_AUTOCLOSE
	return


WahRoomsShared_EventScript_Pokebox::
# 8 "data/scripts/wah_rooms_shared.pory"
	lock
# 9 "data/scripts/wah_rooms_shared.pory"
	waitse
# 10 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_ON
# 11 "data/scripts/wah_rooms_shared.pory"
	setmetatile VAR_TEMP_C, VAR_TEMP_D, VAR_TEMP_F, FALSE
# 12 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 13 "data/scripts/wah_rooms_shared.pory"
	waitse
# 14 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 15 "data/scripts/wah_rooms_shared.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, WahRoomsShared_EventScript_Pokebox_3
WahRoomsShared_EventScript_Pokebox_1:
# 27 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_MainMenu
	return

WahRoomsShared_EventScript_Pokebox_2:
# 16 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_LOGIN
# 17 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_SoftwareUpdate, MSGBOX_AUTOCLOSE_CENTER
# 18 "data/scripts/wah_rooms_shared.pory"
	waitse
# 19 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 20 "data/scripts/wah_rooms_shared.pory"
	playse SE_USE_ITEM
# 21 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_SoftwareUpdateExplanation, MSGBOX_AUTOCLOSE_CENTER
# 22 "data/scripts/wah_rooms_shared.pory"
	waitse
# 23 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 24 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_LOBBY_POKEBOX_POST_WAH_UPDATE_SEEN
	goto WahRoomsShared_EventScript_Pokebox_1

WahRoomsShared_EventScript_Pokebox_3:
# 15 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_LOBBY_POKEBOX_POST_WAH_UPDATE_SEEN, WahRoomsShared_EventScript_Pokebox_2
	goto WahRoomsShared_EventScript_Pokebox_1


WahRoomsShared_EventScript_Pokebox_MainMenu::
# 31 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_LOGIN
# 32 "data/scripts/wah_rooms_shared.pory"
	message WahRoomsShared_Text_Pokebox_MainPrompt
# 33 "data/scripts/wah_rooms_shared.pory"
	waitmessage
# 34 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_0, 0
# 35 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_1, 1
# 36 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_MainMenu_Text_2, 2
# 37 "data/scripts/wah_rooms_shared.pory"
	dynmultistack 0, 0, FALSE, 3, 0, 0, DYN_MULTICHOICE_CB_NONE
# 38 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 39 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 40 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 41 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_EventScript_Pokebox_MainMenu_2
# 45 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_EventScript_Pokebox_MainMenu_3
# 48 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_Shutdown
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_2:
# 42 "data/scripts/wah_rooms_shared.pory"
	callnative StartPokeBoxFromField_CB2
# 43 "data/scripts/wah_rooms_shared.pory"
	waitstate
# 44 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_Shutdown
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_3:
# 46 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return


WahRoomsShared_EventScript_Pokebox_HelpMenu::
# 53 "data/scripts/wah_rooms_shared.pory"
	message WahRoomsShared_Text_Pokebox_HelpPrompt
# 54 "data/scripts/wah_rooms_shared.pory"
	waitmessage
# 55 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_0, 0
# 56 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_1, 1
# 57 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_2, 2
# 58 "data/scripts/wah_rooms_shared.pory"
	dynmultistack 0, 0, FALSE, 3, 0, 0, DYN_MULTICHOICE_CB_NONE
# 59 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 60 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 61 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 62 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_EventScript_Pokebox_HelpMenu_2
# 70 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_EventScript_Pokebox_HelpMenu_3
# 75 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_MainMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_2:
# 63 "data/scripts/wah_rooms_shared.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, WahRoomsShared_EventScript_Pokebox_HelpMenu_6
# 66 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpSwapsBeforeChallenge, MSGBOX_AUTOCLOSE
WahRoomsShared_EventScript_Pokebox_HelpMenu_5:
# 68 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 69 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_3:
# 71 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpUnlock, MSGBOX_AUTOCLOSE
# 72 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 73 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_6:
# 64 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpSwapsAfterChallenge, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu_5


WahRoomsShared_EventScript_Pokebox_Shutdown::
# 80 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_OFF
# 81 "data/scripts/wah_rooms_shared.pory"
	setmetatile VAR_TEMP_C, VAR_TEMP_D, VAR_TEMP_E, FALSE
# 82 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 83 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_UnlockAllPokemon
# 84 "data/scripts/wah_rooms_shared.pory"
	release
	return


	.align 2
# 117 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_MartItems:
# 118 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_HYPER_POTION
# 119 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_POTION
# 120 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_FULL_RESTORE
# 121 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ETHER
# 122 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_ETHER
# 123 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ELIXIR
# 124 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_ELIXIR
# 125 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_REVIVE
# 126 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_REVIVE
# 127 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_REVIVAL_HERB
# 128 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_BAXCALIBURITE
# 129 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DRAGALGITE
# 130 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_TYRANITARITE
# 131 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DARKRANITE
# 132 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ALAKAZITE
# 133 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_LUCARIONITE
# 134 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_LUCARIONITE_Z
# 135 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MEWTWONITE_X
# 136 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MEWTWONITE_Y
# 137 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CHARIZARDITE_X
# 138 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 139 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_GALLADITE
# 140 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_GLALITITE
# 141 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_FROSLASSITE
# 142 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CLEFABLITE
# 143 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_HOUNDOOMINITE
# 144 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_AGGRONITE
# 145 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ZYGARDITE
# 146 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_VICTREEBELITE
# 147 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DRAGONINITE
# 148 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_GRENINJITE
# 149 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MEGANIUMITE
# 150 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_FERALIGITE
# 151 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_STARAPTITE
# 152 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CHESNAUGHTITE
# 153 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DELPHOXITE
# 154 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_EXCADRITE
# 155 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_SKARMORITE
	.2byte ITEM_NONE

WahRoomsShared_OpenDoor::
# 159 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 160 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 161 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 162 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 163 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 164 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 165 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 166 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 167 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 168 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_CloseDoor::
# 173 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 174 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 175 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 176 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 177 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 178 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 179 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 180 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 181 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Closed, TRUE
# 182 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_SetDoorAsOpen::
# 187 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
	return


WahRoomsShared_SetPlayerTeleportGfxVars::
# 192 "data/scripts/wah_rooms_shared.pory"
	checkplayergender
# 193 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, MALE
	goto_if_eq WahRoomsShared_SetPlayerTeleportGfxVars_2
# 198 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_MAY_NORMAL
# 199 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_MAY_TELEPORTING_1
# 200 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_MAY_TELEPORTING_2
WahRoomsShared_SetPlayerTeleportGfxVars_1:
	return

WahRoomsShared_SetPlayerTeleportGfxVars_2:
# 194 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 195 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 196 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
	goto WahRoomsShared_SetPlayerTeleportGfxVars_1


WahRoomsShared_UpdatePlayerSpriteNormal::
# 206 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 207 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_D
# 208 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting1::
# 213 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 214 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 215 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting2::
# 220 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 221 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_F
# 222 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_Kecleon::
# 229 "data/scripts/wah_rooms_shared.pory"
	lock
# 230 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 231 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 232 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 260 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 262 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 234 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 235 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 237 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
# 238 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 239 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 240 "data/scripts/wah_rooms_shared.pory"
	waitse
# 241 "data/scripts/wah_rooms_shared.pory"
	playse SE_PIN
# 242 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, WahRoomsShared_Kecleon_Movement_0
# 243 "data/scripts/wah_rooms_shared.pory"
	waitse
# 244 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 245 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 246 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 247 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 248 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_TO_BLACK
# 249 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 250 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_FROM_BLACK
# 251 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 252 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_FOUND_TILE_KECLEON, WahRoomsShared_Kecleon_7
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_7:
# 253 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_FOUND_TILE_KECLEON
# 254 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_FoundTileKecleon
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_Recompensa::
# 267 "data/scripts/wah_rooms_shared.pory"
	random 2
# 268 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 270 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Recompensa_3
# 273 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Recompensa_4
WahRoomsShared_Kecleon_Recompensa_1:
	return

WahRoomsShared_Kecleon_Recompensa_3:
# 271 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Dinero
	goto WahRoomsShared_Kecleon_Recompensa_1

WahRoomsShared_Kecleon_Recompensa_4:
# 274 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion
	goto WahRoomsShared_Kecleon_Recompensa_1


WahRoomsShared_Kecleon_Dinero::
# 282 "data/scripts/wah_rooms_shared.pory"
	random 10
# 283 "data/scripts/wah_rooms_shared.pory"
	showmoneybox 0, 0
# 284 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 286 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_3
# 287 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_3
# 288 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_3
# 289 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_3
# 293 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_Dinero_4
# 294 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_Dinero_4
# 295 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_Dinero_4
# 299 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_Dinero_5
# 300 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_Dinero_5
# 304 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_Dinero_6
WahRoomsShared_Kecleon_Dinero_1:
# 309 "data/scripts/wah_rooms_shared.pory"
	delay 30
# 310 "data/scripts/wah_rooms_shared.pory"
	playse SE_SHOP
# 311 "data/scripts/wah_rooms_shared.pory"
	updatemoneybox
# 312 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 314 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_9
# 317 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_10
# 320 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_11
# 323 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_12
WahRoomsShared_Kecleon_Dinero_7:
# 327 "data/scripts/wah_rooms_shared.pory"
	hidemoneybox
	return

WahRoomsShared_Kecleon_Dinero_3:
# 290 "data/scripts/wah_rooms_shared.pory"
	addmoney 5000
# 291 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 0
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_4:
# 296 "data/scripts/wah_rooms_shared.pory"
	addmoney 8000
# 297 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 1
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_5:
# 301 "data/scripts/wah_rooms_shared.pory"
	addmoney 10000
# 302 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 2
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_6:
# 305 "data/scripts/wah_rooms_shared.pory"
	addmoney 15000
# 306 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 3
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_9:
# 315 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_0, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_10:
# 318 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_1, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_11:
# 321 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_2, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_12:
# 324 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_3, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7


WahRoomsShared_Kecleon_KitCuracion_BagFull::
# 332 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0, MSGBOX_DEFAULT
# 333 "data/scripts/wah_rooms_shared.pory"
	closemessage
	return


WahRoomsShared_Kecleon_KitCuracion::
# 338 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_Text_0, MSGBOX_DEFAULT
# 339 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 340 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 341 "data/scripts/wah_rooms_shared.pory"
	random 2
# 342 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 344 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_KitCuracion_3
# 362 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_KitCuracion_4
WahRoomsShared_Kecleon_KitCuracion_1:
	return

WahRoomsShared_Kecleon_KitCuracion_3:
# 345 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_REVIVE, 1
# 346 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_6
# 350 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 351 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_12
# 355 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_RESTORE, 3
# 356 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 357 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_18
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_4:
# 363 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 364 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_9
# 368 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_POTION, 2
# 369 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_15
# 373 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_HEAL, 2
# 374 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 375 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_21
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_6:
# 347 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_9:
# 365 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_12:
# 352 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_15:
# 370 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_18:
# 358 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_21:
# 376 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return


WahRoomsShared_Kecleon_ResetFlags::
# 385 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 386 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 387 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 388 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 389 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 390 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 391 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 392 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 393 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 394 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 395 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 396 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 397 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 398 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 399 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 400 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 401 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 402 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 403 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 404 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 405 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SERGIO
# 407 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 408 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 410 "data/scripts/wah_rooms_shared.pory"
	random 4
# 411 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 412 "data/scripts/wah_rooms_shared.pory"
	random 21
# 413 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 415 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 418 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 421 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 424 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 427 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 430 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 433 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 436 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 439 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 442 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 445 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 448 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 451 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 454 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 457 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 460 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 463 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 466 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 469 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 472 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
# 475 "data/scripts/wah_rooms_shared.pory"
	case 20, WahRoomsShared_Kecleon_ResetFlags_25
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 416 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 419 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 422 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 425 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 428 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 431 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 434 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 437 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 440 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 443 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 446 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 449 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 452 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 455 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 458 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 461 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 464 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 467 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 470 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 473 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_25:
# 476 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SERGIO
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 486 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 488 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 491 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 494 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 497 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 489 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 492 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 495 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 498 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 507 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 509 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 512 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 515 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 518 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 510 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 513 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 516 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 519 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 528 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 530 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 533 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 536 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 539 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 531 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 534 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 537 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 540 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 549 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 551 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 554 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 557 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 560 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 552 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 555 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 558 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 561 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 570 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 572 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 575 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 578 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 581 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 573 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 576 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 579 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 582 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 591 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 593 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 596 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 599 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 602 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 594 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 597 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 600 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 603 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 612 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 614 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 617 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 620 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 623 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 615 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 618 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 621 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 624 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 633 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 635 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 638 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 641 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 644 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 636 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 639 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 642 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 645 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 654 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 656 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 659 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 662 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 665 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 657 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 660 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 663 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 666 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 675 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 677 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 680 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 683 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 686 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 678 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 681 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 684 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 687 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 696 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 698 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 701 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 704 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 707 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 699 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 702 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 705 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 708 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 717 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 719 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 722 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 725 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 728 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 720 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 723 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 726 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 729 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 738 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 740 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 743 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 746 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 749 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 741 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 11, 4
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 744 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 10
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 747 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 750 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 3, 12
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 759 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 761 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 764 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 767 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 770 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 762 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 765 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 768 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 771 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 780 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 782 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 785 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 788 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 791 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 783 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 786 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 789 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 792 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 801 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 803 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 806 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 809 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 812 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 804 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 807 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 810 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 813 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 822 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 824 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 827 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 830 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 833 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 825 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 828 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 831 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 834 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 843 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 845 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 848 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 851 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 854 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 846 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 849 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 852 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 855 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 864 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 866 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 869 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 872 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 875 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 867 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 870 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 873 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 876 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 885 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 887 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 890 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 893 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 896 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 888 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 891 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 894 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 897 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 906 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 908 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 911 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 914 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 917 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 909 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 912 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 915 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 918 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 928 "data/scripts/wah_rooms_shared.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 929 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 930 "data/scripts/wah_rooms_shared.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 933 "data/scripts/wah_rooms_shared.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 936 "data/scripts/wah_rooms_shared.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 939 "data/scripts/wah_rooms_shared.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 931 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 934 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 937 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 940 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


WahRoomsShared_EventScript_AfterBattle::
# 947 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 948 "data/scripts/wah_rooms_shared.pory"
	special HealPlayerParty
# 949 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_Avaricia
# 950 "data/scripts/wah_rooms_shared.pory"
	call Pokebox_EventScript_ShowUnlocks
# 951 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_RESULT, VAR_0x8008
	return


# 242 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_Kecleon_Movement_0:
# 242 "data/scripts/wah_rooms_shared.pory"
	emote_exclamation_mark
	step_end

WahRoomsShared_EventScript_Shop_Text_0:
# 3 "data/scripts/wah_rooms_shared.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_0:
# 34 "data/scripts/wah_rooms_shared.pory"
	.string "Acceder a PC$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_1:
# 35 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cómo funciona?$"

WahRoomsShared_EventScript_Pokebox_MainMenu_Text_2:
# 36 "data/scripts/wah_rooms_shared.pory"
	.string "Salir$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_0:
# 55 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cuántos Pokémon puedo cambiar?$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_1:
# 56 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cómo desbloqueo nuevos Pokémon?$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_2:
# 57 "data/scripts/wah_rooms_shared.pory"
	.string "Volver$"

WahRoomsShared_Kecleon_Text_0:
# 237 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"

WahRoomsShared_Kecleon_Dinero_Text_0:
# 315 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 5000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_1:
# 318 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 8000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_2:
# 321 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 10000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_3:
# 324 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 15000¥!$"

WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0:
# 332 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tu MOCHILA está llena!\nTile no pudo dejarte el resto del kit.$"

WahRoomsShared_Kecleon_KitCuracion_Text_0:
# 338 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado un kit de\n"
	.string "curación!$"

WahRoomsShared_Text_Pokebox_SoftwareUpdate::
# 88 "data/scripts/wah_rooms_shared.pory"
	.string "¡El software de la PC se ha actualizado!$"

WahRoomsShared_Text_Pokebox_SoftwareUpdateExplanation::
# 92 "data/scripts/wah_rooms_shared.pory"
	.string "Ahora puedes cambiar hasta 3 Pokémon\n"
	.string "de tu equipo y sustituirlos por Pokémon\l"
	.string "de la caja, en lugar de solo 1.$"

WahRoomsShared_Text_Pokebox_MainPrompt::
# 96 "data/scripts/wah_rooms_shared.pory"
	.string "¿Qué quieres hacer?$"

WahRoomsShared_Text_Pokebox_HelpPrompt::
# 100 "data/scripts/wah_rooms_shared.pory"
	.string "¿Sobre qué quieres saber?$"

WahRoomsShared_Text_Pokebox_HelpSwapsBeforeChallenge::
# 104 "data/scripts/wah_rooms_shared.pory"
	.string "Puedes reemplazar solo uno de los\n"
	.string "Pokémon predefinidos del equipo\l"
	.string "seleccionado por uno de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 5\l"
	.string "Pokémon del equipo original.$"

WahRoomsShared_Text_Pokebox_HelpSwapsAfterChallenge::
# 108 "data/scripts/wah_rooms_shared.pory"
	.string "Puedes reemplazar hasta 3 Pokémon\n"
	.string "predefinidos del equipo seleccionado\l"
	.string "por Pokémon de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 3\l"
	.string "Pokémon del equipo original.$"

WahRoomsShared_Text_Pokebox_HelpUnlock::
# 113 "data/scripts/wah_rooms_shared.pory"
	.string "Algunos Pokémon se desbloquean\n"
	.string "comprándolos en la PC.\p"
	.string "Otros, se obtienen avanzando en el\n"
	.string "juego, consiguiendo Logros o con\l"
	.string "eventos especiales.\p"
	.string "Para descubrir cómo desbloquear un\n"
	.string "Pokémon, presiona {COLOR RED}A{COLOR DARK_GRAY} en su sombra.$"
