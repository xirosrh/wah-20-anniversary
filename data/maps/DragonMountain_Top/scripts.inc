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
	playse SE_WARP_OUT
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 33 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 34 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 35 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_WEST
# 36 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 37 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 38 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 39 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 40 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 41 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 42 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 43 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 44 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 45 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 46 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end


DragonMountain_Top_EventScript_Abra::
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 54 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_ABRA, Common_Movement_FacePlayer
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountain_Top_EventScript_Abra_Text_0, MSGBOX_YESNO
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DragonMountain_Top_EventScript_Abra_2
DragonMountain_Top_EventScript_Abra_1:
# 75 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end

DragonMountain_Top_EventScript_Abra_2:
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_IN
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 64 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 65 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 70 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 1
# 72 "data/maps/DragonMountain_Top/scripts.pory"
	warpsilent MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 73 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
	goto DragonMountain_Top_EventScript_Abra_1


DragonMountan_Top_EventScript_Sergio::
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 81 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_XDWithDelay48
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_1
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_2
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 110 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMark
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 118 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 120 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 121 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 126 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_3
# 136 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 137 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 138 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 139 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 142 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 144 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	waitmoncry
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 147 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 149 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_4
# 153 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_5
# 157 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 158 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_NORMAL
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_6
# 160 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 161 "data/maps/DragonMountain_Top/scripts.pory"
	delay 60
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_SergioBattle
# 163 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_7
# 165 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_DRAGONITE, CRY_MODE_WEAK
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_8
# 168 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 169 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 171 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 172 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 14
# 173 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 14
# 174 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 175 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 176 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 177 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 178 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 179 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_9
# 181 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 182 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_9
# 184 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 185 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 187 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 188 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 189 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 190 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 12
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 192 "data/maps/DragonMountain_Top/scripts.pory"
	clearflag FLAG_TEMP_1
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	addobject LOCALID_MOUNTAINTOP_MOLTRES
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_MOLTRES, MAP_DRAGON_MOUNTAIN_TOP
# 195 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_M_WING_ATTACK
# 196 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 197 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_NORTH
# 198 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_NORMAL
# 199 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 200 "data/maps/DragonMountain_Top/scripts.pory"
	setspeaker SP_NAME_SERGIO
# 201 "data/maps/DragonMountain_Top/scripts.pory"
	message DragonMountan_Top_EventScript_Sergio_Text_12
# 202 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 203 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 204 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 205 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 206 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 208 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_M_WING_ATTACK
# 211 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft8
# 212 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 213 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 214 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 14
# 215 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 216 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 217 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 218 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 219 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 220 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 221 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 222 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 223 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 224 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 225 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 226 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_Heart
# 227 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 228 "data/maps/DragonMountain_Top/scripts.pory"
	delay 60
# 229 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 230 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 231 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_10
# 232 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 233 "data/maps/DragonMountain_Top/scripts.pory"
	clearflag FLAG_TEMP_2
# 234 "data/maps/DragonMountain_Top/scripts.pory"
	addobject LOCALID_MOUNTAINTOP_ABRA_2
# 235 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 236 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA_2, MAP_DRAGON_MOUNTAIN_TOP
# 237 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA_2, DIR_NORTH
# 238 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 239 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 240 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 241 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 242 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 243 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 244 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 245 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 246 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_11
# 247 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_12
# 248 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_PLAYER
# 249 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA_2, DIR_EAST
# 250 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 251 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_IN
# 252 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 253 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 254 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 255 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 256 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 257 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA_2, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 258 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 259 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 260 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 261 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 262 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SERGIO
# 263 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 264 "data/maps/DragonMountain_Top/scripts.pory"
	warpsilent MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 265 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 266 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
	end


DragonMountan_Top_EventScript_SergioBattle::
# 271 "data/maps/DragonMountain_Top/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DragonMountan_Top_EventScript_SergioBattle_2
# 274 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SERGIO
# 275 "data/maps/DragonMountain_Top/scripts.pory"
	special ShouldUseAlternativeTeam
# 276 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DragonMountan_Top_EventScript_SergioBattle_5
# 279 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE, DragonMountan_Top_Text_SergioDefeated
DragonMountan_Top_EventScript_SergioBattle_1:
# 282 "data/maps/DragonMountain_Top/scripts.pory"
	special HealPlayerParty
	return

DragonMountan_Top_EventScript_SergioBattle_2:
# 272 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_Text_SergioDefeated
	goto DragonMountan_Top_EventScript_SergioBattle_1

DragonMountan_Top_EventScript_SergioBattle_5:
# 277 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_Text_SergioDefeated
	goto DragonMountan_Top_EventScript_SergioBattle_1


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 292 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 293 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 294 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 297 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 300 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 303 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 295 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 298 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 301 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 304 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 93 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
	step_end

# 96 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
	step_end

# 99 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 127 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 128 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 131 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 132 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 133 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 152 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 156 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
	step_end

# 159 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 164 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
	step_end

# 167 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_8:
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 180 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_9:
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 231 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_10:
# 231 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 231 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 231 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 246 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_11:
# 246 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 246 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_right
# 246 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 246 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

# 247 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_12:
# 247 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 247 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
	step_end

DragonMountain_Top_EventScript_Abra_Text_0:
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Deseas volver a la sala de Sergio?$"

DragonMountan_Top_EventScript_Sergio_Text_0:
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no ibamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Quién sabe… a lo mejor es que soy el\n"
	.string "mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Admiro que hayas llegado hasta aquí, se\n"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ha llegado el momento de combatir, y mis\n"
	.string "dragones no se contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 184 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_11:
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes\n"
	.string "dormido, ¡que hay un montón de cosas\l"
	.string "por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_12:
# 201 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Mira quien apareció aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_13:
# 219 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Moltres es un Pokémon que siempre nos\n"
	.string "ha acompañado, porque renacemos de\l"
	.string "nuestras cenizas como el ave fénix.$"

DragonMountan_Top_EventScript_Sergio_Text_14:
# 222 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Que locura que ya llevemos 20 años\n"
	.string "entre todos construyendo esta\l"
	.string "comunidad.\p"
	.string "Ha pasado mucho tiempo, pero me siento\n"
	.string "muy orgulloso de que entre todos\l"
	.string "hayamos colaborado y puesto en común\l"
	.string "nuestro conocimiento, buscando\l"
	.string "mantener el espíritu divertido.$"

DragonMountan_Top_EventScript_Sergio_Text_15:
# 227 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Mil gracias por haber formado parte de\n"
	.string "esta celebración!$"

DragonMountan_Top_EventScript_Sergio_Text_16:
# 229 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora ven, acompañame, es hora de dejar\n"
	.string "registro de tu hazaña en el Salón de la\l"
	.string "fama.$"

DragonMountan_Top_Text_SergioDefeated::
# 286 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Eso ha sido brutal!$"
