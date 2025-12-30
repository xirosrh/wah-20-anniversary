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
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 29 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 30 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_WEST
# 33 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 34 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 35 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 36 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 37 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 38 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 39 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 40 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 41 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 42 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 43 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 44 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end


DragonMountain_Top_EventScript_Abra::
# 50 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 51 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 52 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_ABRA, Common_Movement_FacePlayer
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 54 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountain_Top_EventScript_Abra_Text_0, MSGBOX_YESNO
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DragonMountain_Top_EventScript_Abra_2
DragonMountain_Top_EventScript_Abra_1:
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end

DragonMountain_Top_EventScript_Abra_2:
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 64 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 65 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 1
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	warp MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
	goto DragonMountain_Top_EventScript_Abra_1


DragonMountan_Top_EventScript_Sergio::
# 76 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 77 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 81 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 110 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_1
# 121 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 126 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 128 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 131 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 132 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 133 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_2
# 136 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 137 "data/maps/DragonMountain_Top/scripts.pory"
	delay 60
# 138 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_EventScript_Sergio_Text_7
# 139 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_3
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 142 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 144 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 147 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 149 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_4
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 153 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 158 "data/maps/DragonMountain_Top/scripts.pory"
	clearflag FLAG_TEMP_1
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	addobject LOCALID_MOUNTAINTOP_MOLTRES
# 160 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_MOLTRES, MAP_DRAGON_MOUNTAIN_TOP
# 161 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_NORTH
# 163 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_NORMAL
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 165 "data/maps/DragonMountain_Top/scripts.pory"
	setspeaker SP_NAME_SERGIO
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	message DragonMountan_Top_EventScript_Sergio_Text_10
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 168 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 169 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 170 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 171 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 172 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_DoubleExclamationMarkWithDelay48
# 173 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft3
# 174 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_MOLTRES
# 175 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_MOLTRES, Common_Movement_WalkLeft8
# 176 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 177 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 178 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 179 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 181 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 182 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 184 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 185 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_13, speaker = SP_NAME_SERGIO
# 187 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 188 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HeartWithDelay48
# 189 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 190 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_5
# 192 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_6
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_7
# 195 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_PLAYER
# 196 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_EAST
# 197 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 198 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 199 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 200 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 201 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 202 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 203 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 204 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 205 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 206 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 207 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 208 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SERGIO
# 209 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 210 "data/maps/DragonMountain_Top/scripts.pory"
	warp MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 211 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 212 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
	end


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 218 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 219 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 223 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 226 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 229 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 221 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 224 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 227 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 230 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 88 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 112 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 118 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 135 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 140 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 151 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 191 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 191 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 193 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_right
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 193 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

# 194 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_left
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 194 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
	step_end

DragonMountain_Top_EventScript_Abra_Text_0:
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Deseas volver a la sala de Sergio?$"

DragonMountan_Top_EventScript_Sergio_Text_0:
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no ibamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco. Quién sabe… a lo mejor es\n"
	.string "que soy el mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?\n"
	.string "Admiro que hayas llegado hasta aquí, se\l"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí! Ha llegado el momento de\n"
	.string "combatir, y mis dragones no se\l"
	.string "contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 138 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Eso ha sido brutal!$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes\n"
	.string "dormido, ¡que hay un montón de cosas\l"
	.string "por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Guau! ¡Mira quien apareció aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_11:
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Moltres es un Pokémon que siempre nos\n"
	.string "ha acompañado, porque renacemos de\l"
	.string "nuestras cenizas como el ave fénix.$"

DragonMountan_Top_EventScript_Sergio_Text_12:
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Que locura que ya llevemos 20 años\n"
	.string "entre todos construyendo esta\l"
	.string "comunidad.\p"
	.string "Ha pasado mucho tiempo, pero me siento\n"
	.string "muy orgulloso de que entre todos\l"
	.string "hayamos colaborado y poniendo en común\l"
	.string "nuestro conocimiento, buscando\l"
	.string "mantener el espíritu divertido.$"

DragonMountan_Top_EventScript_Sergio_Text_13:
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	.string "\p"
	.string "¡Mil gracias por haber formado parte de\n"
	.string "esta celebración!$"

DragonMountan_Top_EventScript_Sergio_Text_14:
# 189 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora ven, acompañame, es hora de dejar\n"
	.string "registro de tu hazaña en el hall de la\l"
	.string "fama.$"
