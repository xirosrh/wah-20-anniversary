DragonMountain_Top_MapScripts::
# 10 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DragonMountain_Top_OnTransition
# 4 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 7 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 5 "data/maps/DragonMountain_Top/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, DragonMountain_Top_OnWarp
	.2byte 0

DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/DragonMountain_Top/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, DragonMountain_Top_OnFrame
	.2byte 0


DragonMountain_Top_OnWarp::
# 15 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 16 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_MOLTRES, MAP_DRAGON_MOUNTAIN_TOP
	end


DragonMountain_Top_OnTransition::
# 23 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_TEMP_1
	end


DragonMountain_Top_OnFrame::
# 28 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_OUT
# 29 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 30 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 33 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_WEST
# 34 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 35 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 36 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 37 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 38 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 39 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 40 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 41 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 42 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 43 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 44 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 45 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end


DragonMountain_Top_EventScript_Abra::
# 51 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 52 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_ABRA, Common_Movement_FacePlayer
# 54 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountain_Top_EventScript_Abra_Text_0, MSGBOX_YESNO
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DragonMountain_Top_EventScript_Abra_2
DragonMountain_Top_EventScript_Abra_1:
# 73 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end

DragonMountain_Top_EventScript_Abra_2:
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_IN
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 64 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 65 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 1
# 70 "data/maps/DragonMountain_Top/scripts.pory"
	warpsilent MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
	goto DragonMountain_Top_EventScript_Abra_1


DragonMountan_Top_EventScript_Sergio::
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 81 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_1
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_2
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 110 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 118 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 120 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 121 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_3
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 131 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 132 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 133 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 136 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 137 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 138 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 139 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 142 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 144 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_4
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 147 "data/maps/DragonMountain_Top/scripts.pory"
	delay 60
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_SergioBattle
# 149 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_5
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 153 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 157 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 158 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 160 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 161 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_6
# 163 "data/maps/DragonMountain_Top/scripts.pory"
	waitse
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_LEDGE
# 165 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_6
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 168 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 169 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 172 "data/maps/DragonMountain_Top/scripts.pory"
	clearflag FLAG_TEMP_1
# 173 "data/maps/DragonMountain_Top/scripts.pory"
	addobject LOCALID_MOUNTAINTOP_MOLTRES
# 174 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_MOLTRES, MAP_DRAGON_MOUNTAIN_TOP
# 175 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_M_WING_ATTACK
# 176 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 177 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_NORTH
# 178 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_NORMAL
# 179 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	setspeaker SP_NAME_SERGIO
# 181 "data/maps/DragonMountain_Top/scripts.pory"
	message DragonMountan_Top_EventScript_Sergio_Text_9
# 182 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 184 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 185 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 187 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 188 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 189 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 190 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_M_WING_ATTACK
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft8
# 192 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 195 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 196 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 197 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 198 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 199 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 200 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 201 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 202 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_12, speaker = SP_NAME_SERGIO
# 203 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 204 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HeartWithDelay48
# 205 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 206 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_7
# 208 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_8
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_9
# 211 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_PLAYER
# 212 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_EAST
# 213 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 214 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_WARP_IN
# 215 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 216 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 217 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 218 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 219 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 220 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 221 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 222 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 223 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 224 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 225 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SERGIO
# 226 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 227 "data/maps/DragonMountain_Top/scripts.pory"
	warpsilent MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 228 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 229 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
	end


DragonMountan_Top_EventScript_SergioBattle::
# 234 "data/maps/DragonMountain_Top/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DragonMountan_Top_EventScript_SergioBattle_2
# 237 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SERGIO
# 238 "data/maps/DragonMountain_Top/scripts.pory"
	special ShouldUseAlternativeTeam
# 239 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DragonMountan_Top_EventScript_SergioBattle_5
# 242 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_ALTERNATIVE, DragonMountan_Top_Text_SergioDefeated
DragonMountan_Top_EventScript_SergioBattle_1:
# 245 "data/maps/DragonMountain_Top/scripts.pory"
	special HealPlayerParty
	return

DragonMountan_Top_EventScript_SergioBattle_2:
# 235 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_Text_SergioDefeated
	goto DragonMountan_Top_EventScript_SergioBattle_1

DragonMountan_Top_EventScript_SergioBattle_5:
# 240 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_Text_SergioDefeated
	goto DragonMountan_Top_EventScript_SergioBattle_1


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 255 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 256 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 257 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 260 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 263 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 266 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 258 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 261 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 264 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 267 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 91 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
	step_end

# 94 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
	step_end

# 97 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 121 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 126 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 128 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 145 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 150 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 162 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 207 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 209 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_8:
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_right
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

# 210 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_9:
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_left
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
	step_end

DragonMountain_Top_EventScript_Abra_Text_0:
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Deseas volver a la sala de Sergio?$"

DragonMountan_Top_EventScript_Sergio_Text_0:
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no ibamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco. Quién sabe… a lo mejor es\n"
	.string "que soy el mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?\n"
	.string "Admiro que hayas llegado hasta aquí, se\l"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí! Ha llegado el momento de\n"
	.string "combatir, y mis dragones no se\l"
	.string "contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 168 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes\n"
	.string "dormido, ¡que hay un montón de cosas\l"
	.string "por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 181 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Mira quien apareció aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 196 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Moltres es un Pokémon que siempre nos\n"
	.string "ha acompañado, porque renacemos de\l"
	.string "nuestras cenizas como el ave fénix.$"

DragonMountan_Top_EventScript_Sergio_Text_11:
# 199 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Que locura que ya llevemos 20 años\n"
	.string "entre todos construyendo esta\l"
	.string "comunidad.\p"
	.string "Ha pasado mucho tiempo, pero me siento\n"
	.string "muy orgulloso de que entre todos\l"
	.string "hayamos colaborado y poniendo en común\l"
	.string "nuestro conocimiento, buscando\l"
	.string "mantener el espíritu divertido.$"

DragonMountan_Top_EventScript_Sergio_Text_12:
# 202 "data/maps/DragonMountain_Top/scripts.pory"
	.string "\p"
	.string "¡Mil gracias por haber formado parte de\n"
	.string "esta celebración!$"

DragonMountan_Top_EventScript_Sergio_Text_13:
# 205 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora ven, acompañame, es hora de dejar\n"
	.string "registro de tu hazaña en el hall de la\l"
	.string "fama.$"

DragonMountan_Top_Text_SergioDefeated::
# 249 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Eso ha sido brutal!$"
