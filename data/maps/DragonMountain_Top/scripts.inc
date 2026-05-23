DragonMountain_Top_MapScripts::
# 11 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DragonMountain_Top_OnTransition
# 5 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 8 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/DragonMountain_Top/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, DragonMountain_Top_OnWarp
	.2byte 0

DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 9 "data/maps/DragonMountain_Top/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, DragonMountain_Top_OnFrame
	.2byte 0


DragonMountain_Top_OnWarp::
# 16 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 18 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_MOLTRES, MAP_DRAGON_MOUNTAIN_TOP
# 19 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_TEMP_2
	end


DragonMountain_Top_OnTransition::
# 25 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_TEMP_1
	end


DragonMountain_Top_OnFrame::
# 30 "data/maps/DragonMountain_Top/scripts.pory"
	special ShowMapNamePopup
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_OUT
# 33 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 34 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 35 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 36 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 37 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_WEST
# 38 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 39 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 40 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 41 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 42 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 43 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 44 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 45 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 46 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteNormal
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 48 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 49 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end


DragonMountain_Top_EventScript_Abra::
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_ABRA, Common_Movement_FacePlayer
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountain_Top_EventScript_Abra_Text_0, MSGBOX_YESNO
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DragonMountain_Top_EventScript_Abra_2
DragonMountain_Top_EventScript_Abra_1:
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end

DragonMountain_Top_EventScript_Abra_2:
# 64 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 65 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_IN
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 70 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 72 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 73 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 74 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 1
# 75 "data/maps/DragonMountain_Top/scripts.pory"
	warpsilent MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 76 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
	goto DragonMountain_Top_EventScript_Abra_1


DragonMountan_Top_EventScript_Sergio::
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_XDWithDelay48
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_1
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_2
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 110 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMark
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 118 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 120 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 121 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 126 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 128 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_3
# 139 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 142 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 144 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 147 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	waitmoncry
# 149 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 153 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_4
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 157 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 158 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_5
# 160 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 161 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_6
# 163 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	delay 60
# 165 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_SergioBattle
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_7
# 168 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 169 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_WEAK
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_8
# 171 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 172 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 173 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 174 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 175 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 14
# 176 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 14
# 177 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 178 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 179 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 181 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 182 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_9
# 184 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 185 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_9
# 187 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 188 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 189 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 190 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 192 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 12
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 195 "data/maps/DragonMountain_Top/scripts.pory"
	clearflag FLAG_TEMP_1
# 196 "data/maps/DragonMountain_Top/scripts.pory"
	addobject LOCALID_MOUNTAINTOP_MOLTRES
# 197 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_MOLTRES, MAP_DRAGON_MOUNTAIN_TOP
# 198 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_M_WING_ATTACK
# 199 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 200 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_NORTH
# 201 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_NORMAL
# 202 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 203 "data/maps/DragonMountain_Top/scripts.pory"
	setspeaker SP_NAME_SERGIO
# 204 "data/maps/DragonMountain_Top/scripts.pory"
	message DragonMountan_Top_EventScript_Sergio_Text_12
# 205 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 206 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 208 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 211 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 212 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 213 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_M_WING_ATTACK
# 214 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft8
# 215 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 216 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 217 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 14
# 218 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 219 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 220 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 221 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 222 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 223 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 224 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 225 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 226 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 227 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 228 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 229 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_Heart
# 230 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 231 "data/maps/DragonMountain_Top/scripts.pory"
	delay 60
# 232 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 233 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 234 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 235 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_10
# 236 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 237 "data/maps/DragonMountain_Top/scripts.pory"
	clearflag FLAG_TEMP_2
# 238 "data/maps/DragonMountain_Top/scripts.pory"
	addobject LOCALID_MOUNTAINTOP_ABRA_2
# 239 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_OUT
# 240 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 241 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA_2, MAP_DRAGON_MOUNTAIN_TOP
# 242 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA_2, DIR_NORTH
# 243 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 244 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 245 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 246 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 247 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 248 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 249 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 250 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 251 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_11
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_12
# 253 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_PLAYER
# 254 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA_2, DIR_EAST
# 255 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 256 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_SetPlayerTeleportGfxVars
# 257 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_IN
# 258 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 259 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting2
# 260 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 261 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 262 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 263 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 264 "data/maps/DragonMountain_Top/scripts.pory"
	call WahRoomsShared_UpdatePlayerSpriteTeleporting1
# 265 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 266 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 267 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 268 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SERGIO
# 269 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 270 "data/maps/DragonMountain_Top/scripts.pory"
	warpsilent MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 271 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 272 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
	end


DragonMountan_Top_EventScript_SergioBattle::
# 277 "data/maps/DragonMountain_Top/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DragonMountan_Top_EventScript_SergioBattle_2
# 280 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SERGIO
# 281 "data/maps/DragonMountain_Top/scripts.pory"
	special ShouldUseAlternativeTeam
# 282 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DragonMountan_Top_EventScript_SergioBattle_5
# 285 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE, DragonMountan_Top_Text_SergioDefeated
DragonMountan_Top_EventScript_SergioBattle_1:
	return

DragonMountan_Top_EventScript_SergioBattle_2:
# 278 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_Text_SergioDefeated
	goto DragonMountan_Top_EventScript_SergioBattle_1

DragonMountan_Top_EventScript_SergioBattle_5:
# 283 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_Text_SergioDefeated
	goto DragonMountan_Top_EventScript_SergioBattle_1


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 297 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 298 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 299 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 302 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 305 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 308 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 300 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 303 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 306 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 309 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 96 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
	step_end

# 99 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
	step_end

# 102 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 130 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 131 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 132 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 133 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 136 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 137 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 155 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 159 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
	step_end

# 162 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 167 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
	step_end

# 170 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_8:
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 183 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_9:
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 235 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_10:
# 235 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 235 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 235 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 251 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_11:
# 251 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 251 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_right
# 251 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 251 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

# 252 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_12:
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_left
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
	step_end

DragonMountain_Top_EventScript_Abra_Text_0:
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Deseas volver a la sala de Serg!o?$"

DragonMountan_Top_EventScript_Sergio_Text_0:
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no íbamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Quién sabe… a lo mejor es que soy el\n"
	.string "mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Admiro que hayas llegado hasta aquí, sé\n"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 157 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ha llegado el momento de combatir, y mis\n"
	.string "dragones no se contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 187 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_11:
# 189 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes dormid{OA},\n"
	.string "¡que hay un montón de cosas por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_12:
# 204 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Mira quien apareció aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_13:
# 222 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Moltres es un Pokémon que siempre nos\n"
	.string "ha acompañado, porque renacemos de\l"
	.string "nuestras cenizas como el ave fénix.$"

DragonMountan_Top_EventScript_Sergio_Text_14:
# 225 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Qué locura que ya llevemos 20 años\n"
	.string "entre todos construyendo esta\l"
	.string "comunidad.\p"
	.string "Ha pasado mucho tiempo, pero me siento\n"
	.string "muy orgulloso de que entre todos\l"
	.string "hayamos colaborado y puesto en común\l"
	.string "nuestro conocimiento, buscando\l"
	.string "mantener el espíritu divertido.$"

DragonMountan_Top_EventScript_Sergio_Text_15:
# 230 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Mil gracias por haber formado parte de\n"
	.string "esta celebración!$"

DragonMountan_Top_EventScript_Sergio_Text_16:
# 232 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora ven, acompañame; es hora de dejar\n"
	.string "registro de tu hazaña en el Salón de la\l"
	.string "fama.$"

DragonMountan_Top_Text_SergioDefeated::
# 291 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Eso ha sido brutal!$"
