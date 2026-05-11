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
# 150 "data/scripts/wah_rooms_shared.pory"
	.2byte ITEM_DRAGONINITE
	.2byte ITEM_NONE

WahRoomsShared_OpenDoor::
# 154 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 155 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 156 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 157 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 158 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 159 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 160 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 161 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 162 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 163 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_CloseDoor::
# 168 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 169 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 170 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 171 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 172 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 173 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 174 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 175 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 176 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Closed, TRUE
# 177 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_SetDoorAsOpen::
# 182 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
	return


WahRoomsShared_SetPlayerTeleportGfxVars::
# 187 "data/scripts/wah_rooms_shared.pory"
	checkplayergender
# 188 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, MALE
	goto_if_eq WahRoomsShared_SetPlayerTeleportGfxVars_2
# 193 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_MAY_NORMAL
# 194 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_MAY_TELEPORTING_1
# 195 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_MAY_TELEPORTING_2
WahRoomsShared_SetPlayerTeleportGfxVars_1:
	return

WahRoomsShared_SetPlayerTeleportGfxVars_2:
# 189 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 190 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 191 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
	goto WahRoomsShared_SetPlayerTeleportGfxVars_1


WahRoomsShared_UpdatePlayerSpriteNormal::
# 201 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 202 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_D
# 203 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting1::
# 208 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 209 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 210 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting2::
# 215 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 216 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_F
# 217 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_Kecleon::
# 224 "data/scripts/wah_rooms_shared.pory"
	lock
# 225 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 226 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 227 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 255 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 257 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 229 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 230 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 232 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
# 233 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 234 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 235 "data/scripts/wah_rooms_shared.pory"
	waitse
# 236 "data/scripts/wah_rooms_shared.pory"
	playse SE_PIN
# 237 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, WahRoomsShared_Kecleon_Movement_0
# 238 "data/scripts/wah_rooms_shared.pory"
	waitse
# 239 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 240 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 241 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 242 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 243 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_TO_BLACK
# 244 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 245 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_FROM_BLACK
# 246 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 247 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_FOUND_TILE_KECLEON, WahRoomsShared_Kecleon_7
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_7:
# 248 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_FOUND_TILE_KECLEON
# 249 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_FoundTileKecleon
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_Recompensa::
# 262 "data/scripts/wah_rooms_shared.pory"
	random 2
# 263 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 265 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Recompensa_3
# 268 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Recompensa_4
WahRoomsShared_Kecleon_Recompensa_1:
	return

WahRoomsShared_Kecleon_Recompensa_3:
# 266 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Dinero
	goto WahRoomsShared_Kecleon_Recompensa_1

WahRoomsShared_Kecleon_Recompensa_4:
# 269 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion
	goto WahRoomsShared_Kecleon_Recompensa_1


WahRoomsShared_Kecleon_Dinero::
# 277 "data/scripts/wah_rooms_shared.pory"
	random 10
# 278 "data/scripts/wah_rooms_shared.pory"
	showmoneybox 0, 0
# 279 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 281 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_3
# 282 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_3
# 283 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_3
# 284 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_3
# 288 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_Dinero_4
# 289 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_Dinero_4
# 290 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_Dinero_4
# 294 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_Dinero_5
# 295 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_Dinero_5
# 299 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_Dinero_6
WahRoomsShared_Kecleon_Dinero_1:
# 304 "data/scripts/wah_rooms_shared.pory"
	delay 30
# 305 "data/scripts/wah_rooms_shared.pory"
	playse SE_SHOP
# 306 "data/scripts/wah_rooms_shared.pory"
	updatemoneybox
# 307 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 309 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_9
# 312 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_10
# 315 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_11
# 318 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_12
WahRoomsShared_Kecleon_Dinero_7:
# 322 "data/scripts/wah_rooms_shared.pory"
	hidemoneybox
	return

WahRoomsShared_Kecleon_Dinero_3:
# 285 "data/scripts/wah_rooms_shared.pory"
	addmoney 5000
# 286 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 0
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_4:
# 291 "data/scripts/wah_rooms_shared.pory"
	addmoney 8000
# 292 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 1
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_5:
# 296 "data/scripts/wah_rooms_shared.pory"
	addmoney 10000
# 297 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 2
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_6:
# 300 "data/scripts/wah_rooms_shared.pory"
	addmoney 15000
# 301 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 3
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_9:
# 310 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_0, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_10:
# 313 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_1, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_11:
# 316 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_2, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_12:
# 319 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_3, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7


WahRoomsShared_Kecleon_KitCuracion_BagFull::
# 327 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0, MSGBOX_DEFAULT
# 328 "data/scripts/wah_rooms_shared.pory"
	closemessage
	return


WahRoomsShared_Kecleon_KitCuracion::
# 333 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_Text_0, MSGBOX_DEFAULT
# 334 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 335 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 336 "data/scripts/wah_rooms_shared.pory"
	random 2
# 337 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 339 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_KitCuracion_3
# 357 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_KitCuracion_4
WahRoomsShared_Kecleon_KitCuracion_1:
	return

WahRoomsShared_Kecleon_KitCuracion_3:
# 340 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_REVIVE, 1
# 341 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_6
# 345 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 346 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_12
# 350 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_RESTORE, 3
# 351 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 352 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_18
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_4:
# 358 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 359 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_9
# 363 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_POTION, 2
# 364 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_15
# 368 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_HEAL, 2
# 369 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 370 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_21
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_6:
# 342 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_9:
# 360 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_12:
# 347 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_15:
# 365 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_18:
# 353 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_21:
# 371 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return


WahRoomsShared_Kecleon_ResetFlags::
# 380 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 381 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 382 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 383 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 384 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 385 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 386 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 387 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 388 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 389 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 390 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 391 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 392 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 393 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 394 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 395 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 396 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 397 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 398 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 399 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 400 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SERGIO
# 402 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 403 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 405 "data/scripts/wah_rooms_shared.pory"
	random 4
# 406 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 407 "data/scripts/wah_rooms_shared.pory"
	random 21
# 408 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 410 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 413 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 416 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 419 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 422 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 425 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 428 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 431 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 434 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 437 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 440 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 443 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 446 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 449 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 452 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 455 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 458 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 461 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 464 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 467 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
# 470 "data/scripts/wah_rooms_shared.pory"
	case 20, WahRoomsShared_Kecleon_ResetFlags_25
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 411 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 414 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 417 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 420 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 423 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 426 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 429 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 432 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 435 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 438 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 441 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 444 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 447 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 450 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 453 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 456 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 459 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 462 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 465 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 468 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_25:
# 471 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SERGIO
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 481 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 483 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 486 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 489 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 492 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 484 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 487 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 490 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 493 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 502 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 504 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 507 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 510 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 513 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 505 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 508 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 511 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 514 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 523 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 525 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 528 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 531 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 534 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 526 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 529 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 532 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 535 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 544 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 546 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 549 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 552 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 555 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 547 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 550 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 553 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 556 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 565 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 567 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 570 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 573 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 576 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 568 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 2, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 571 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 574 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 10, 5
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 577 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 586 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 588 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 591 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 594 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 597 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 589 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 592 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 595 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 598 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 607 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 609 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 612 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 615 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 618 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 610 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 613 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 616 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 619 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 628 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 630 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 633 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 636 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 639 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 631 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 634 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 637 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 640 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 649 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 651 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 654 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 657 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 660 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 652 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 655 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 658 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 661 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 670 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 672 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 675 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 678 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 681 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 673 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 676 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 679 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 682 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 691 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 693 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 696 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 699 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 702 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 694 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 697 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 700 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 703 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 712 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 714 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 717 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 720 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 723 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 715 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 718 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 721 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 724 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 733 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 735 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 738 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 741 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 744 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 736 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 11, 4
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 739 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 10
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 742 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 745 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 3, 12
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 754 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 756 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 759 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 762 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 765 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 757 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 760 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 763 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 766 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 775 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 777 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 780 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 783 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 786 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 778 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 781 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 784 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 787 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 796 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 798 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 801 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 804 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 807 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 799 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 802 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 805 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 808 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 817 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 819 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 822 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 825 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 828 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 820 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 823 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 826 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 829 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 838 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 840 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 843 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 846 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 849 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 841 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 844 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 847 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 850 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 859 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 861 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 864 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 867 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 870 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 862 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 865 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 868 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 871 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 880 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 882 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 885 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 888 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 891 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 883 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 886 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 889 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 892 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 901 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 903 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 906 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 909 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 912 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 904 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 907 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 910 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 913 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 923 "data/scripts/wah_rooms_shared.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 924 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 925 "data/scripts/wah_rooms_shared.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 928 "data/scripts/wah_rooms_shared.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 931 "data/scripts/wah_rooms_shared.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 934 "data/scripts/wah_rooms_shared.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 926 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 929 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 932 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 935 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


WahRoomsShared_EventScript_AfterBattle::
# 942 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 943 "data/scripts/wah_rooms_shared.pory"
	special HealPlayerParty
# 944 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_Avaricia
# 945 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_RESULT, VAR_0x8008
	return


# 237 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_Kecleon_Movement_0:
# 237 "data/scripts/wah_rooms_shared.pory"
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
# 232 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"

WahRoomsShared_Kecleon_Dinero_Text_0:
# 310 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 5000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_1:
# 313 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 8000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_2:
# 316 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 10000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_3:
# 319 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 15000¥!$"

WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0:
# 327 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tu MOCHILA está llena!\nTile no pudo dejarte el resto del kit.$"

WahRoomsShared_Kecleon_KitCuracion_Text_0:
# 333 "data/scripts/wah_rooms_shared.pory"
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
