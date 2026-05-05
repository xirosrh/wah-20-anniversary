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
# 49 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_EventScript_Pokebox_MainMenu_3
# 52 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_Shutdown
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_2:
# 42 "data/scripts/wah_rooms_shared.pory"
	callnative StartPokeBoxFromField_CB2
# 43 "data/scripts/wah_rooms_shared.pory"
	waitstate
# 44 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_OFF
# 45 "data/scripts/wah_rooms_shared.pory"
	setmetatile VAR_TEMP_C, VAR_TEMP_D, VAR_TEMP_E, FALSE
# 46 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 47 "data/scripts/wah_rooms_shared.pory"
	release
	return

WahRoomsShared_EventScript_Pokebox_MainMenu_3:
# 50 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return


WahRoomsShared_EventScript_Pokebox_HelpMenu::
# 57 "data/scripts/wah_rooms_shared.pory"
	message WahRoomsShared_Text_Pokebox_HelpPrompt
# 58 "data/scripts/wah_rooms_shared.pory"
	waitmessage
# 59 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_0, 0
# 60 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_1, 1
# 61 "data/scripts/wah_rooms_shared.pory"
	dynmultipush WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_2, 2
# 62 "data/scripts/wah_rooms_shared.pory"
	dynmultistack 0, 0, FALSE, 3, 0, 0, DYN_MULTICHOICE_CB_NONE
# 63 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 64 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 65 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 66 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_EventScript_Pokebox_HelpMenu_2
# 74 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_EventScript_Pokebox_HelpMenu_3
# 79 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_MainMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_2:
# 67 "data/scripts/wah_rooms_shared.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, WahRoomsShared_EventScript_Pokebox_HelpMenu_6
# 70 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpSwapsBeforeChallenge, MSGBOX_AUTOCLOSE
WahRoomsShared_EventScript_Pokebox_HelpMenu_5:
# 72 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 73 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_3:
# 75 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpUnlock, MSGBOX_AUTOCLOSE
# 76 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 77 "data/scripts/wah_rooms_shared.pory"
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu
	return

WahRoomsShared_EventScript_Pokebox_HelpMenu_6:
# 68 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Text_Pokebox_HelpSwapsAfterChallenge, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_EventScript_Pokebox_HelpMenu_5


WahRoomsShared_EventScript_Pokebox_Shutdown::
# 84 "data/scripts/wah_rooms_shared.pory"
	playse SE_PC_OFF
# 85 "data/scripts/wah_rooms_shared.pory"
	setmetatile VAR_TEMP_C, VAR_TEMP_D, VAR_TEMP_E, FALSE
# 86 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 87 "data/scripts/wah_rooms_shared.pory"
	release
	return


	.align 2
# 120 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_MartItems:
# 121 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_HYPER_POTION
# 122 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_POTION
# 123 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_FULL_RESTORE
# 124 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ETHER
# 125 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_ETHER
# 126 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ELIXIR
# 127 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_ELIXIR
# 128 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_REVIVE
# 129 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MAX_REVIVE
# 130 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_REVIVAL_HERB
# 131 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_BAXCALIBURITE
# 132 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DRAGALGITE
# 133 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_TYRANITARITE
# 134 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DARKRANITE
# 135 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ALAKAZITE
# 136 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_LUCARIONITE
# 137 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_LUCARIONITE_Z
# 138 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MEWTWONITE_X
# 139 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_MEWTWONITE_Y
# 140 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CHARIZARDITE_X
# 141 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 142 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_GALLADITE
# 143 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_GLALITITE
# 144 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_FROSLASSITE
# 145 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_CLEFABLITE
# 146 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_HOUNDOOMINITE
# 147 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_AGGRONITE
# 148 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_ZYGARDITE
# 149 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

WahRoomsShared_OpenDoor::
# 153 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 154 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 155 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 156 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 157 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 158 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 159 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 160 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 161 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 162 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_CloseDoor::
# 167 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 168 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 169 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 170 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 171 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 172 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 173 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 174 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 175 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Closed, TRUE
# 176 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_SetDoorAsOpen::
# 181 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
	return


WahRoomsShared_SetPlayerTeleportGfxVars::
# 186 "data/scripts/wah_rooms_shared.pory"
	checkplayergender
# 187 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, MALE
	goto_if_eq WahRoomsShared_SetPlayerTeleportGfxVars_2
# 192 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_MAY_NORMAL
# 193 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_MAY_TELEPORTING_1
# 194 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_MAY_TELEPORTING_2
WahRoomsShared_SetPlayerTeleportGfxVars_1:
	return

WahRoomsShared_SetPlayerTeleportGfxVars_2:
# 188 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 189 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 190 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
	goto WahRoomsShared_SetPlayerTeleportGfxVars_1


WahRoomsShared_UpdatePlayerSpriteNormal::
# 200 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 201 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_D
# 202 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting1::
# 207 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 208 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 209 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting2::
# 214 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 215 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_F
# 216 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_Kecleon::
# 223 "data/scripts/wah_rooms_shared.pory"
	lock
# 224 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 225 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 226 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 254 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 256 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 228 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 229 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 231 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
# 232 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 233 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 234 "data/scripts/wah_rooms_shared.pory"
	waitse
# 235 "data/scripts/wah_rooms_shared.pory"
	playse SE_PIN
# 236 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, WahRoomsShared_Kecleon_Movement_0
# 237 "data/scripts/wah_rooms_shared.pory"
	waitse
# 238 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 239 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 240 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 241 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 242 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_TO_BLACK
# 243 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 244 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_FROM_BLACK
# 245 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 246 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_FOUND_TILE_KECLEON, WahRoomsShared_Kecleon_7
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_7:
# 247 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_FOUND_TILE_KECLEON
# 248 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_FoundTileKecleon
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_Recompensa::
# 261 "data/scripts/wah_rooms_shared.pory"
	random 2
# 262 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 264 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Recompensa_3
# 267 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Recompensa_4
WahRoomsShared_Kecleon_Recompensa_1:
	return

WahRoomsShared_Kecleon_Recompensa_3:
# 265 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Dinero
	goto WahRoomsShared_Kecleon_Recompensa_1

WahRoomsShared_Kecleon_Recompensa_4:
# 268 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion
	goto WahRoomsShared_Kecleon_Recompensa_1


WahRoomsShared_Kecleon_Dinero::
# 276 "data/scripts/wah_rooms_shared.pory"
	random 10
# 277 "data/scripts/wah_rooms_shared.pory"
	showmoneybox 0, 0
# 278 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 280 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_3
# 281 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_3
# 282 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_3
# 283 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_3
# 287 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_Dinero_4
# 288 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_Dinero_4
# 289 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_Dinero_4
# 293 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_Dinero_5
# 294 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_Dinero_5
# 298 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_Dinero_6
WahRoomsShared_Kecleon_Dinero_1:
# 303 "data/scripts/wah_rooms_shared.pory"
	delay 30
# 304 "data/scripts/wah_rooms_shared.pory"
	playse SE_SHOP
# 305 "data/scripts/wah_rooms_shared.pory"
	updatemoneybox
# 306 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 308 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_9
# 311 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_10
# 314 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_11
# 317 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_12
WahRoomsShared_Kecleon_Dinero_7:
# 321 "data/scripts/wah_rooms_shared.pory"
	hidemoneybox
	return

WahRoomsShared_Kecleon_Dinero_3:
# 284 "data/scripts/wah_rooms_shared.pory"
	addmoney 5000
# 285 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 0
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_4:
# 290 "data/scripts/wah_rooms_shared.pory"
	addmoney 8000
# 291 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 1
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_5:
# 295 "data/scripts/wah_rooms_shared.pory"
	addmoney 10000
# 296 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 2
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_6:
# 299 "data/scripts/wah_rooms_shared.pory"
	addmoney 15000
# 300 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 3
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_9:
# 309 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_0, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_10:
# 312 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_1, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_11:
# 315 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_2, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_12:
# 318 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_3, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7


WahRoomsShared_Kecleon_KitCuracion_BagFull::
# 326 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0, MSGBOX_DEFAULT
# 327 "data/scripts/wah_rooms_shared.pory"
	closemessage
	return


WahRoomsShared_Kecleon_KitCuracion::
# 332 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_Text_0, MSGBOX_DEFAULT
# 333 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 334 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 335 "data/scripts/wah_rooms_shared.pory"
	random 2
# 336 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 338 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_KitCuracion_3
# 356 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_KitCuracion_4
WahRoomsShared_Kecleon_KitCuracion_1:
	return

WahRoomsShared_Kecleon_KitCuracion_3:
# 339 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_REVIVE, 1
# 340 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_6
# 344 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 345 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_12
# 349 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_RESTORE, 3
# 350 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 351 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_18
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_4:
# 357 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 358 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_9
# 362 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_POTION, 2
# 363 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_15
# 367 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_HEAL, 2
# 368 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 369 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_21
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_6:
# 341 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_9:
# 359 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_12:
# 346 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_15:
# 364 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_18:
# 352 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_21:
# 370 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return


WahRoomsShared_Kecleon_ResetFlags::
# 379 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 380 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 381 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 382 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 383 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 384 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 385 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 386 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 387 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 388 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 389 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 390 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 391 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 392 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 393 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 394 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 395 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 396 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 397 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 398 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 399 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SERGIO
# 401 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 402 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 404 "data/scripts/wah_rooms_shared.pory"
	random 4
# 405 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 406 "data/scripts/wah_rooms_shared.pory"
	random 21
# 407 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 409 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 412 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 415 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 418 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 421 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 424 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 427 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 430 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 433 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 436 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 439 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 442 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 445 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 448 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 451 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 454 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 457 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 460 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 463 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 466 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
# 469 "data/scripts/wah_rooms_shared.pory"
	case 20, WahRoomsShared_Kecleon_ResetFlags_25
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 410 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 413 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 416 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 419 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 422 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 425 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 428 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 431 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 434 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 437 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 440 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 443 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 446 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 449 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 452 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 455 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 458 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 461 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 464 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 467 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_25:
# 470 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SERGIO
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 480 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 482 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 485 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 488 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 491 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 483 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 486 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 489 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 492 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 501 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 503 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 506 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 509 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 512 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 504 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 507 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 510 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 513 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 522 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 524 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 527 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 530 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 533 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 525 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 528 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 531 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 534 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 543 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 545 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 548 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 551 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 554 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 546 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 549 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 552 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 555 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 564 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 566 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 569 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 572 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 575 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 567 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 2, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 570 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 573 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 10, 5
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 576 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 585 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 587 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 590 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 593 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 596 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 588 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 591 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 594 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 597 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 606 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 608 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 611 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 614 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 617 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 609 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 612 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 615 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 618 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 627 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 629 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 632 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 635 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 638 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 630 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 633 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 636 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 639 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 648 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 650 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 653 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 656 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 659 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 651 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 654 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 657 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 660 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 669 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 671 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 674 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 677 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 680 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 672 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 675 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 678 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 681 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 690 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 692 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 695 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 698 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 701 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 693 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 696 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 699 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 702 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 711 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 713 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 716 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 719 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 722 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 714 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 717 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 720 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 723 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 732 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 734 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 737 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 740 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 743 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 735 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 11, 4
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 738 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 10
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 741 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 744 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 3, 12
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 753 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 755 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 758 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 761 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 764 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 756 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 759 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 762 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 765 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 774 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 776 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 779 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 782 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 785 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 777 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 780 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 783 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 786 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 795 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 797 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 800 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 803 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 806 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 798 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 801 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 804 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 807 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 816 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 818 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 821 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 824 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 827 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 819 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 822 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 825 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 828 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 837 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 839 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 842 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 845 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 848 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 840 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 843 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 846 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 849 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 858 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 860 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 863 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 866 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 869 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 861 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 864 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 867 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 870 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 879 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 881 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 884 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 887 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 890 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 882 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 885 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 888 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 891 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 900 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 902 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 905 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 908 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 911 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 903 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 906 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 909 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 912 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 922 "data/scripts/wah_rooms_shared.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 923 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 924 "data/scripts/wah_rooms_shared.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 927 "data/scripts/wah_rooms_shared.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 930 "data/scripts/wah_rooms_shared.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 933 "data/scripts/wah_rooms_shared.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 925 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 928 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 931 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 934 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


# 236 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_Kecleon_Movement_0:
# 236 "data/scripts/wah_rooms_shared.pory"
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
# 59 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cuántos Pokémon puedo cambiar?$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_1:
# 60 "data/scripts/wah_rooms_shared.pory"
	.string "¿Cómo desbloqueo nuevos Pokémon?$"

WahRoomsShared_EventScript_Pokebox_HelpMenu_Text_2:
# 61 "data/scripts/wah_rooms_shared.pory"
	.string "Volver$"

WahRoomsShared_Kecleon_Text_0:
# 231 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"

WahRoomsShared_Kecleon_Dinero_Text_0:
# 309 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 5000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_1:
# 312 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 8000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_2:
# 315 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 10000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_3:
# 318 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 15000¥!$"

WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0:
# 326 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tu MOCHILA está llena!\nTile no pudo dejarte el resto del kit.$"

WahRoomsShared_Kecleon_KitCuracion_Text_0:
# 332 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado un kit de\n"
	.string "curación!$"

WahRoomsShared_Text_Pokebox_SoftwareUpdate::
# 91 "data/scripts/wah_rooms_shared.pory"
	.string "¡El software de la PC se ha actualizado!$"

WahRoomsShared_Text_Pokebox_SoftwareUpdateExplanation::
# 95 "data/scripts/wah_rooms_shared.pory"
	.string "Ahora puedes cambiar hasta 3 Pokémon\n"
	.string "de tu equipo y sustituirlos por Pokémon\l"
	.string "de la caja, en lugar de solo 1.$"

WahRoomsShared_Text_Pokebox_MainPrompt::
# 99 "data/scripts/wah_rooms_shared.pory"
	.string "¿Qué quieres hacer?$"

WahRoomsShared_Text_Pokebox_HelpPrompt::
# 103 "data/scripts/wah_rooms_shared.pory"
	.string "¿Sobre qué quieres saber?$"

WahRoomsShared_Text_Pokebox_HelpSwapsBeforeChallenge::
# 107 "data/scripts/wah_rooms_shared.pory"
	.string "Puedes reemplazar solo uno de los\n"
	.string "Pokémon predefinidos del equipo\l"
	.string "seleccionado por uno de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 5\l"
	.string "Pokémon del equipo original.$"

WahRoomsShared_Text_Pokebox_HelpSwapsAfterChallenge::
# 111 "data/scripts/wah_rooms_shared.pory"
	.string "Puedes reemplazar hasta 3 Pokémon\n"
	.string "predefinidos del equipo seleccionado\l"
	.string "por Pokémon de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 3\l"
	.string "Pokémon del equipo original.$"

WahRoomsShared_Text_Pokebox_HelpUnlock::
# 116 "data/scripts/wah_rooms_shared.pory"
	.string "Algunos Pokémon se desbloquean\n"
	.string "comprándolos en la PC.\p"
	.string "Otros, se obtienen avanzando en el\n"
	.string "juego, consiguiendo Logros o con\l"
	.string "eventos especiales.\p"
	.string "Para descubrir cómo desbloquear un\n"
	.string "Pokémon, presiona {COLOR RED}A{COLOR DARK_GRAY} en su sombra.$"
