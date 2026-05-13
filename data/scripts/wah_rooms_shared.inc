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
	.2byte ITEM_NONE

WahRoomsShared_OpenDoor::
# 157 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 158 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 159 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 160 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 161 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 162 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 163 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 164 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 165 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 166 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_CloseDoor::
# 171 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 172 "data/scripts/wah_rooms_shared.pory"
	playse SE_DOOR
# 173 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 174 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 175 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 176 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 177 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
# 178 "data/scripts/wah_rooms_shared.pory"
	delay 5
# 179 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Closed, TRUE
# 180 "data/scripts/wah_rooms_shared.pory"
	special DrawWholeMapView
	return


WahRoomsShared_SetDoorAsOpen::
# 185 "data/scripts/wah_rooms_shared.pory"
	setmetatile 6, 2, METATILE_RoomGeneral_Door_Open, FALSE
	return


WahRoomsShared_SetPlayerTeleportGfxVars::
# 190 "data/scripts/wah_rooms_shared.pory"
	checkplayergender
# 191 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, MALE
	goto_if_eq WahRoomsShared_SetPlayerTeleportGfxVars_2
# 196 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_MAY_NORMAL
# 197 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_MAY_TELEPORTING_1
# 198 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_MAY_TELEPORTING_2
WahRoomsShared_SetPlayerTeleportGfxVars_1:
	return

WahRoomsShared_SetPlayerTeleportGfxVars_2:
# 192 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_D, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 193 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_E, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 194 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_TEMP_F, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
	goto WahRoomsShared_SetPlayerTeleportGfxVars_1


WahRoomsShared_UpdatePlayerSpriteNormal::
# 204 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 205 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_D
# 206 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting1::
# 211 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 212 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_E
# 213 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_UpdatePlayerSpriteTeleporting2::
# 218 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_0x8004, LOCALID_PLAYER
# 219 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8005, VAR_TEMP_F
# 220 "data/scripts/wah_rooms_shared.pory"
	special UpdateObjectEventSprite
	return


WahRoomsShared_Kecleon::
# 227 "data/scripts/wah_rooms_shared.pory"
	lock
# 228 "data/scripts/wah_rooms_shared.pory"
	faceplayer
# 229 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 230 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_2
# 258 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_SomethingUnseeable, MSGBOX_DEFAULT
WahRoomsShared_Kecleon_1:
# 260 "data/scripts/wah_rooms_shared.pory"
	release
	end

WahRoomsShared_Kecleon_2:
# 232 "data/scripts/wah_rooms_shared.pory"
	msgbox Kecleon_Text_WantToUseDevonScope, MSGBOX_YESNO
# 233 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_5
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_5:
# 235 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Text_0, MSGBOX_AUTOCLOSE
# 236 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 237 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Movement_KecleonAppears
# 238 "data/scripts/wah_rooms_shared.pory"
	waitse
# 239 "data/scripts/wah_rooms_shared.pory"
	playse SE_PIN
# 240 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, WahRoomsShared_Kecleon_Movement_0
# 241 "data/scripts/wah_rooms_shared.pory"
	waitse
# 242 "data/scripts/wah_rooms_shared.pory"
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
# 243 "data/scripts/wah_rooms_shared.pory"
	delay 40
# 244 "data/scripts/wah_rooms_shared.pory"
	waitmoncry
# 245 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Recompensa
# 246 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_TO_BLACK
# 247 "data/scripts/wah_rooms_shared.pory"
	removeobject VAR_LAST_TALKED
# 248 "data/scripts/wah_rooms_shared.pory"
	fadescreen FADE_FROM_BLACK
# 249 "data/scripts/wah_rooms_shared.pory"
	delay 20
# 250 "data/scripts/wah_rooms_shared.pory"
	goto_if_unset FLAG_FOUND_TILE_KECLEON, WahRoomsShared_Kecleon_7
	goto WahRoomsShared_Kecleon_1

WahRoomsShared_Kecleon_7:
# 251 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_FOUND_TILE_KECLEON
# 252 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_FoundTileKecleon
	goto WahRoomsShared_Kecleon_1


WahRoomsShared_Kecleon_Recompensa::
# 265 "data/scripts/wah_rooms_shared.pory"
	random 2
# 266 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 268 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Recompensa_3
# 271 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Recompensa_4
WahRoomsShared_Kecleon_Recompensa_1:
	return

WahRoomsShared_Kecleon_Recompensa_3:
# 269 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_Dinero
	goto WahRoomsShared_Kecleon_Recompensa_1

WahRoomsShared_Kecleon_Recompensa_4:
# 272 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion
	goto WahRoomsShared_Kecleon_Recompensa_1


WahRoomsShared_Kecleon_Dinero::
# 280 "data/scripts/wah_rooms_shared.pory"
	random 10
# 281 "data/scripts/wah_rooms_shared.pory"
	showmoneybox 0, 0
# 282 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 284 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_3
# 285 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_3
# 286 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_3
# 287 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_3
# 291 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_Dinero_4
# 292 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_Dinero_4
# 293 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_Dinero_4
# 297 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_Dinero_5
# 298 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_Dinero_5
# 302 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_Dinero_6
WahRoomsShared_Kecleon_Dinero_1:
# 307 "data/scripts/wah_rooms_shared.pory"
	delay 30
# 308 "data/scripts/wah_rooms_shared.pory"
	playse SE_SHOP
# 309 "data/scripts/wah_rooms_shared.pory"
	updatemoneybox
# 310 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 312 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_Dinero_9
# 315 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_Dinero_10
# 318 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_Dinero_11
# 321 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_Dinero_12
WahRoomsShared_Kecleon_Dinero_7:
# 325 "data/scripts/wah_rooms_shared.pory"
	hidemoneybox
	return

WahRoomsShared_Kecleon_Dinero_3:
# 288 "data/scripts/wah_rooms_shared.pory"
	addmoney 5000
# 289 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 0
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_4:
# 294 "data/scripts/wah_rooms_shared.pory"
	addmoney 8000
# 295 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 1
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_5:
# 299 "data/scripts/wah_rooms_shared.pory"
	addmoney 10000
# 300 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 2
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_6:
# 303 "data/scripts/wah_rooms_shared.pory"
	addmoney 15000
# 304 "data/scripts/wah_rooms_shared.pory"
	setvar VAR_RESULT, 3
	goto WahRoomsShared_Kecleon_Dinero_1

WahRoomsShared_Kecleon_Dinero_9:
# 313 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_0, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_10:
# 316 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_1, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_11:
# 319 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_2, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7

WahRoomsShared_Kecleon_Dinero_12:
# 322 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_Dinero_Text_3, MSGBOX_AUTOCLOSE
	goto WahRoomsShared_Kecleon_Dinero_7


WahRoomsShared_Kecleon_KitCuracion_BagFull::
# 330 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0, MSGBOX_DEFAULT
# 331 "data/scripts/wah_rooms_shared.pory"
	closemessage
	return


WahRoomsShared_Kecleon_KitCuracion::
# 336 "data/scripts/wah_rooms_shared.pory"
	msgbox WahRoomsShared_Kecleon_KitCuracion_Text_0, MSGBOX_DEFAULT
# 337 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 338 "data/scripts/wah_rooms_shared.pory"
	delay 10
# 339 "data/scripts/wah_rooms_shared.pory"
	random 2
# 340 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 342 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_KitCuracion_3
# 360 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_KitCuracion_4
WahRoomsShared_Kecleon_KitCuracion_1:
	return

WahRoomsShared_Kecleon_KitCuracion_3:
# 343 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_REVIVE, 1
# 344 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_6
# 348 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 349 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_12
# 353 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_RESTORE, 3
# 354 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 355 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_18
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_4:
# 361 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_REVIVE, 2
# 362 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_9
# 366 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_MAX_POTION, 2
# 367 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_15
# 371 "data/scripts/wah_rooms_shared.pory"
	giveitem ITEM_FULL_HEAL, 2
# 372 "data/scripts/wah_rooms_shared.pory"
	closemessage
# 373 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq WahRoomsShared_Kecleon_KitCuracion_21
	goto WahRoomsShared_Kecleon_KitCuracion_1

WahRoomsShared_Kecleon_KitCuracion_6:
# 345 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_9:
# 363 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_12:
# 350 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_15:
# 368 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_18:
# 356 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return

WahRoomsShared_Kecleon_KitCuracion_21:
# 374 "data/scripts/wah_rooms_shared.pory"
	call WahRoomsShared_Kecleon_KitCuracion_BagFull
	return


WahRoomsShared_Kecleon_ResetFlags::
# 383 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_OMEGA
# 384 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GOCE
# 385 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
# 386 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
# 387 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
# 388 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_COSARARA
# 389 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
# 390 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
# 391 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_ANGEL
# 392 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
# 393 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REYBOO
# 394 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
# 395 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
# 396 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
# 397 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_REONEKY
# 398 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_CHEVE
# 399 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_BARO
# 400 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
# 401 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_EING
# 402 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_XIROS
# 403 "data/scripts/wah_rooms_shared.pory"
	setflag FLAG_HIDE_KECLEON_ROOM_SERGIO
# 405 "data/scripts/wah_rooms_shared.pory"
	checkitem ITEM_DEVON_SCOPE
# 406 "data/scripts/wah_rooms_shared.pory"
	compare VAR_RESULT, 0
	goto_if_ne WahRoomsShared_Kecleon_ResetFlags_2
WahRoomsShared_Kecleon_ResetFlags_1:
	return

WahRoomsShared_Kecleon_ResetFlags_2:
# 408 "data/scripts/wah_rooms_shared.pory"
	random 4
# 409 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_KECLEON_POSITION, VAR_RESULT
# 410 "data/scripts/wah_rooms_shared.pory"
	random 21
# 411 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 413 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_ResetFlags_5
# 416 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_ResetFlags_6
# 419 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_ResetFlags_7
# 422 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_ResetFlags_8
# 425 "data/scripts/wah_rooms_shared.pory"
	case 4, WahRoomsShared_Kecleon_ResetFlags_9
# 428 "data/scripts/wah_rooms_shared.pory"
	case 5, WahRoomsShared_Kecleon_ResetFlags_10
# 431 "data/scripts/wah_rooms_shared.pory"
	case 6, WahRoomsShared_Kecleon_ResetFlags_11
# 434 "data/scripts/wah_rooms_shared.pory"
	case 7, WahRoomsShared_Kecleon_ResetFlags_12
# 437 "data/scripts/wah_rooms_shared.pory"
	case 8, WahRoomsShared_Kecleon_ResetFlags_13
# 440 "data/scripts/wah_rooms_shared.pory"
	case 9, WahRoomsShared_Kecleon_ResetFlags_14
# 443 "data/scripts/wah_rooms_shared.pory"
	case 10, WahRoomsShared_Kecleon_ResetFlags_15
# 446 "data/scripts/wah_rooms_shared.pory"
	case 11, WahRoomsShared_Kecleon_ResetFlags_16
# 449 "data/scripts/wah_rooms_shared.pory"
	case 12, WahRoomsShared_Kecleon_ResetFlags_17
# 452 "data/scripts/wah_rooms_shared.pory"
	case 13, WahRoomsShared_Kecleon_ResetFlags_18
# 455 "data/scripts/wah_rooms_shared.pory"
	case 14, WahRoomsShared_Kecleon_ResetFlags_19
# 458 "data/scripts/wah_rooms_shared.pory"
	case 15, WahRoomsShared_Kecleon_ResetFlags_20
# 461 "data/scripts/wah_rooms_shared.pory"
	case 16, WahRoomsShared_Kecleon_ResetFlags_21
# 464 "data/scripts/wah_rooms_shared.pory"
	case 17, WahRoomsShared_Kecleon_ResetFlags_22
# 467 "data/scripts/wah_rooms_shared.pory"
	case 18, WahRoomsShared_Kecleon_ResetFlags_23
# 470 "data/scripts/wah_rooms_shared.pory"
	case 19, WahRoomsShared_Kecleon_ResetFlags_24
# 473 "data/scripts/wah_rooms_shared.pory"
	case 20, WahRoomsShared_Kecleon_ResetFlags_25
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_5:
# 414 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_OMEGA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_6:
# 417 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GOCE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_7:
# 420 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_TOKYNWAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_8:
# 423 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JACKJOHNSON
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_9:
# 426 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SCAREXOZUMAS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_10:
# 429 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_COSARARA
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_11:
# 432 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DRIVEKATHERINE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_12:
# 435 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_AGUIAR
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_13:
# 438 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_ANGEL
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_14:
# 441 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SAYERBLAX
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_15:
# 444 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REYBOO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_16:
# 447 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_DAVZERO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_17:
# 450 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_JAVSJAVI4315
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_18:
# 453 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_GALLEGO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_19:
# 456 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_REONEKY
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_20:
# 459 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_CHEVE
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_21:
# 462 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_BARO
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_22:
# 465 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_KLEINPKPOWER
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_23:
# 468 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_EING
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_24:
# 471 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_XIROS
	goto WahRoomsShared_Kecleon_ResetFlags_1

WahRoomsShared_Kecleon_ResetFlags_25:
# 474 "data/scripts/wah_rooms_shared.pory"
	clearflag FLAG_HIDE_KECLEON_ROOM_SERGIO
	goto WahRoomsShared_Kecleon_ResetFlags_1


WahRoomsShared_Kecleon_SetSala_Omega::
# 484 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 486 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Omega_3
# 489 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Omega_4
# 492 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Omega_5
# 495 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Omega_6
WahRoomsShared_Kecleon_SetSala_Omega_1:
	return

WahRoomsShared_Kecleon_SetSala_Omega_3:
# 487 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_4:
# 490 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_5:
# 493 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_Omega_1

WahRoomsShared_Kecleon_SetSala_Omega_6:
# 496 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_OMEGAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Omega_1


WahRoomsShared_Kecleon_SetSala_Goce::
# 505 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 507 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Goce_3
# 510 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Goce_4
# 513 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Goce_5
# 516 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Goce_6
WahRoomsShared_Kecleon_SetSala_Goce_1:
	return

WahRoomsShared_Kecleon_SetSala_Goce_3:
# 508 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 7, 3
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_4:
# 511 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 8, 6
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_5:
# 514 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Goce_1

WahRoomsShared_Kecleon_SetSala_Goce_6:
# 517 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GOCEROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Goce_1


WahRoomsShared_Kecleon_SetSala_TokynWar::
# 526 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 528 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_TokynWar_3
# 531 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_TokynWar_4
# 534 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_TokynWar_5
# 537 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_TokynWar_6
WahRoomsShared_Kecleon_SetSala_TokynWar_1:
	return

WahRoomsShared_Kecleon_SetSala_TokynWar_3:
# 529 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 5, 3
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_4:
# 532 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_5:
# 535 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1

WahRoomsShared_Kecleon_SetSala_TokynWar_6:
# 538 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_TOKYNWARROOM_KECLEON, 9, 6
	goto WahRoomsShared_Kecleon_SetSala_TokynWar_1


WahRoomsShared_Kecleon_SetSala_JackJohnson::
# 547 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 549 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JackJohnson_3
# 552 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JackJohnson_4
# 555 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JackJohnson_5
# 558 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JackJohnson_6
WahRoomsShared_Kecleon_SetSala_JackJohnson_1:
	return

WahRoomsShared_Kecleon_SetSala_JackJohnson_3:
# 550 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_4:
# 553 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_5:
# 556 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1

WahRoomsShared_Kecleon_SetSala_JackJohnson_6:
# 559 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JACKROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_JackJohnson_1


WahRoomsShared_Kecleon_SetSala_ScarexOzumas::
# 568 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 570 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3
# 573 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4
# 576 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5
# 579 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6
WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1:
	return

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_3:
# 571 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 2, 3
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_4:
# 574 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_5:
# 577 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 10, 5
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1

WahRoomsShared_Kecleon_SetSala_ScarexOzumas_6:
# 580 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SCAREXOZUROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ScarexOzumas_1


WahRoomsShared_Kecleon_SetSala_Cosarara::
# 589 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 591 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cosarara_3
# 594 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cosarara_4
# 597 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cosarara_5
# 600 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cosarara_6
WahRoomsShared_Kecleon_SetSala_Cosarara_1:
	return

WahRoomsShared_Kecleon_SetSala_Cosarara_3:
# 592 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 4
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_4:
# 595 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 3, 8
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_5:
# 598 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1

WahRoomsShared_Kecleon_SetSala_Cosarara_6:
# 601 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_COSARARAROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Cosarara_1


WahRoomsShared_Kecleon_SetSala_DriveKatherine::
# 610 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 612 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DriveKatherine_3
# 615 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DriveKatherine_4
# 618 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DriveKatherine_5
# 621 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DriveKatherine_6
WahRoomsShared_Kecleon_SetSala_DriveKatherine_1:
	return

WahRoomsShared_Kecleon_SetSala_DriveKatherine_3:
# 613 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_4:
# 616 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 1, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_5:
# 619 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1

WahRoomsShared_Kecleon_SetSala_DriveKatherine_6:
# 622 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_DRIVEKATHERINEROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_DriveKatherine_1


WahRoomsShared_Kecleon_SetSala_Aguiar::
# 631 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 633 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Aguiar_3
# 636 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Aguiar_4
# 639 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Aguiar_5
# 642 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Aguiar_6
WahRoomsShared_Kecleon_SetSala_Aguiar_1:
	return

WahRoomsShared_Kecleon_SetSala_Aguiar_3:
# 634 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 1, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_4:
# 637 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_5:
# 640 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 10, 4
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1

WahRoomsShared_Kecleon_SetSala_Aguiar_6:
# 643 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_AGUIARROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_Aguiar_1


WahRoomsShared_Kecleon_SetSala_Angel::
# 652 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 654 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Angel_3
# 657 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Angel_4
# 660 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Angel_5
# 663 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Angel_6
WahRoomsShared_Kecleon_SetSala_Angel_1:
	return

WahRoomsShared_Kecleon_SetSala_Angel_3:
# 655 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_4:
# 658 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_5:
# 661 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 9, 5
	goto WahRoomsShared_Kecleon_SetSala_Angel_1

WahRoomsShared_Kecleon_SetSala_Angel_6:
# 664 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ANGELROOM_KECLEON, 11, 9
	goto WahRoomsShared_Kecleon_SetSala_Angel_1


WahRoomsShared_Kecleon_SetSala_SayerBlax::
# 673 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 675 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_SayerBlax_3
# 678 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_SayerBlax_4
# 681 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_SayerBlax_5
# 684 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_SayerBlax_6
WahRoomsShared_Kecleon_SetSala_SayerBlax_1:
	return

WahRoomsShared_Kecleon_SetSala_SayerBlax_3:
# 676 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 4, 5
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_4:
# 679 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 8, 9
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_5:
# 682 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1

WahRoomsShared_Kecleon_SetSala_SayerBlax_6:
# 685 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_KECLEON, 9, 11
	goto WahRoomsShared_Kecleon_SetSala_SayerBlax_1


WahRoomsShared_Kecleon_SetSala_ReyBoo::
# 694 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 696 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_ReyBoo_3
# 699 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_ReyBoo_4
# 702 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_ReyBoo_5
# 705 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_ReyBoo_6
WahRoomsShared_Kecleon_SetSala_ReyBoo_1:
	return

WahRoomsShared_Kecleon_SetSala_ReyBoo_3:
# 697 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_4:
# 700 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 5, 4
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_5:
# 703 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1

WahRoomsShared_Kecleon_SetSala_ReyBoo_6:
# 706 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REYBOOROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_ReyBoo_1


WahRoomsShared_Kecleon_SetSala_DavZero::
# 715 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 717 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_DavZero_3
# 720 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_DavZero_4
# 723 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_DavZero_5
# 726 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_DavZero_6
WahRoomsShared_Kecleon_SetSala_DavZero_1:
	return

WahRoomsShared_Kecleon_SetSala_DavZero_3:
# 718 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 4
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_4:
# 721 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 3, 7
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_5:
# 724 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1

WahRoomsShared_Kecleon_SetSala_DavZero_6:
# 727 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_ZEROROOM_KECLEON, 9, 9
	goto WahRoomsShared_Kecleon_SetSala_DavZero_1


WahRoomsShared_Kecleon_SetSala_JavsJavi::
# 736 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 738 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_JavsJavi_3
# 741 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_JavsJavi_4
# 744 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_JavsJavi_5
# 747 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_JavsJavi_6
WahRoomsShared_Kecleon_SetSala_JavsJavi_1:
	return

WahRoomsShared_Kecleon_SetSala_JavsJavi_3:
# 739 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 11, 4
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_4:
# 742 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 10
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_5:
# 745 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 1, 5
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1

WahRoomsShared_Kecleon_SetSala_JavsJavi_6:
# 748 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_KECLEON, 3, 12
	goto WahRoomsShared_Kecleon_SetSala_JavsJavi_1


WahRoomsShared_Kecleon_SetSala_Gallego::
# 757 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 759 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Gallego_3
# 762 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Gallego_4
# 765 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Gallego_5
# 768 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Gallego_6
WahRoomsShared_Kecleon_SetSala_Gallego_1:
	return

WahRoomsShared_Kecleon_SetSala_Gallego_3:
# 760 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 3, 4
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_4:
# 763 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_5:
# 766 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 11, 6
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1

WahRoomsShared_Kecleon_SetSala_Gallego_6:
# 769 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_GALLEGOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Gallego_1


WahRoomsShared_Kecleon_SetSala_Reoneky::
# 778 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 780 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Reoneky_3
# 783 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Reoneky_4
# 786 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Reoneky_5
# 789 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Reoneky_6
WahRoomsShared_Kecleon_SetSala_Reoneky_1:
	return

WahRoomsShared_Kecleon_SetSala_Reoneky_3:
# 781 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_4:
# 784 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_5:
# 787 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 8, 4
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1

WahRoomsShared_Kecleon_SetSala_Reoneky_6:
# 790 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_REOROOM_KECLEON, 9, 10
	goto WahRoomsShared_Kecleon_SetSala_Reoneky_1


WahRoomsShared_Kecleon_SetSala_Cheve::
# 799 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 801 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Cheve_3
# 804 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Cheve_4
# 807 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Cheve_5
# 810 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Cheve_6
WahRoomsShared_Kecleon_SetSala_Cheve_1:
	return

WahRoomsShared_Kecleon_SetSala_Cheve_3:
# 802 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 2, 8
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_4:
# 805 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_5:
# 808 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 11, 7
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1

WahRoomsShared_Kecleon_SetSala_Cheve_6:
# 811 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_CHEVEROOM_KECLEON, 3, 11
	goto WahRoomsShared_Kecleon_SetSala_Cheve_1


WahRoomsShared_Kecleon_SetSala_Baro::
# 820 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 822 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Baro_3
# 825 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Baro_4
# 828 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Baro_5
# 831 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Baro_6
WahRoomsShared_Kecleon_SetSala_Baro_1:
	return

WahRoomsShared_Kecleon_SetSala_Baro_3:
# 823 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 4, 3
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_4:
# 826 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_5:
# 829 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 1, 12
	goto WahRoomsShared_Kecleon_SetSala_Baro_1

WahRoomsShared_Kecleon_SetSala_Baro_6:
# 832 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_BAROROOM_KECLEON, 3, 6
	goto WahRoomsShared_Kecleon_SetSala_Baro_1


WahRoomsShared_Kecleon_SetSala_KelinPkPower::
# 841 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 843 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_KelinPkPower_3
# 846 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_KelinPkPower_4
# 849 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_KelinPkPower_5
# 852 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_KelinPkPower_6
WahRoomsShared_Kecleon_SetSala_KelinPkPower_1:
	return

WahRoomsShared_Kecleon_SetSala_KelinPkPower_3:
# 844 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 2, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_4:
# 847 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 10
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_5:
# 850 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 11, 5
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1

WahRoomsShared_Kecleon_SetSala_KelinPkPower_6:
# 853 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_KLEINROOM_KECLEON, 1, 7
	goto WahRoomsShared_Kecleon_SetSala_KelinPkPower_1


WahRoomsShared_Kecleon_SetSala_Eing::
# 862 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 864 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Eing_3
# 867 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Eing_4
# 870 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Eing_5
# 873 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Eing_6
WahRoomsShared_Kecleon_SetSala_Eing_1:
	return

WahRoomsShared_Kecleon_SetSala_Eing_3:
# 865 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 5, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_4:
# 868 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 4, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_5:
# 871 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 8
	goto WahRoomsShared_Kecleon_SetSala_Eing_1

WahRoomsShared_Kecleon_SetSala_Eing_6:
# 874 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_EINGROOM_KECLEON, 8, 5
	goto WahRoomsShared_Kecleon_SetSala_Eing_1


WahRoomsShared_Kecleon_SetSala_Xiros::
# 883 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 885 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Xiros_3
# 888 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Xiros_4
# 891 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Xiros_5
# 894 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Xiros_6
WahRoomsShared_Kecleon_SetSala_Xiros_1:
	return

WahRoomsShared_Kecleon_SetSala_Xiros_3:
# 886 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 5
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_4:
# 889 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 2, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_5:
# 892 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 9, 7
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1

WahRoomsShared_Kecleon_SetSala_Xiros_6:
# 895 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_XIROSROOM_KECLEON, 10, 3
	goto WahRoomsShared_Kecleon_SetSala_Xiros_1


WahRoomsShared_Kecleon_SetSala_Sergio::
# 904 "data/scripts/wah_rooms_shared.pory"
	switch VAR_KECLEON_POSITION
# 906 "data/scripts/wah_rooms_shared.pory"
	case 0, WahRoomsShared_Kecleon_SetSala_Sergio_3
# 909 "data/scripts/wah_rooms_shared.pory"
	case 1, WahRoomsShared_Kecleon_SetSala_Sergio_4
# 912 "data/scripts/wah_rooms_shared.pory"
	case 2, WahRoomsShared_Kecleon_SetSala_Sergio_5
# 915 "data/scripts/wah_rooms_shared.pory"
	case 3, WahRoomsShared_Kecleon_SetSala_Sergio_6
WahRoomsShared_Kecleon_SetSala_Sergio_1:
	return

WahRoomsShared_Kecleon_SetSala_Sergio_3:
# 907 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 10, 9
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_4:
# 910 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 4, 10
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_5:
# 913 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 2, 11
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1

WahRoomsShared_Kecleon_SetSala_Sergio_6:
# 916 "data/scripts/wah_rooms_shared.pory"
	setobjectxyperm LOCALID_SERGIOROOM_KECLEON, 9, 13
	goto WahRoomsShared_Kecleon_SetSala_Sergio_1


WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 926 "data/scripts/wah_rooms_shared.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 927 "data/scripts/wah_rooms_shared.pory"
	switch VAR_RESULT
# 928 "data/scripts/wah_rooms_shared.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 931 "data/scripts/wah_rooms_shared.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 934 "data/scripts/wah_rooms_shared.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 937 "data/scripts/wah_rooms_shared.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 929 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 932 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 935 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 938 "data/scripts/wah_rooms_shared.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


WahRoomsShared_EventScript_AfterBattle::
# 945 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 946 "data/scripts/wah_rooms_shared.pory"
	special HealPlayerParty
# 947 "data/scripts/wah_rooms_shared.pory"
	call Achievements_EventScript_Eval_Avaricia
# 948 "data/scripts/wah_rooms_shared.pory"
	copyvar VAR_RESULT, VAR_0x8008
	return


# 240 "data/scripts/wah_rooms_shared.pory"
WahRoomsShared_Kecleon_Movement_0:
# 240 "data/scripts/wah_rooms_shared.pory"
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
# 235 "data/scripts/wah_rooms_shared.pory"
	.string "{PLAYER} usó el Detector Devon.\p"
	.string "¡Un POKéMON que era invisible\n"
	.string "se ha vuelto completamente visible!$"

WahRoomsShared_Kecleon_Dinero_Text_0:
# 313 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 5000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_1:
# 316 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 8000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_2:
# 319 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 10000¥!$"

WahRoomsShared_Kecleon_Dinero_Text_3:
# 322 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tile te ha entregado 15000¥!$"

WahRoomsShared_Kecleon_KitCuracion_BagFull_Text_0:
# 330 "data/scripts/wah_rooms_shared.pory"
	.string "¡Tu MOCHILA está llena!\nTile no pudo dejarte el resto del kit.$"

WahRoomsShared_Kecleon_KitCuracion_Text_0:
# 336 "data/scripts/wah_rooms_shared.pory"
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
