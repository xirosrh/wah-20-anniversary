DragonMountain_Top_MapScripts::
# 2 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 5 "data/maps/DragonMountain_Top/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/DragonMountain_Top/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, DragonMountain_Top_OnWarp
	.2byte 0

DragonMountain_Top_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 6 "data/maps/DragonMountain_Top/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, DragonMountain_Top_OnFrame
	.2byte 0


DragonMountain_Top_OnWarp::
# 12 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 13 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
	end


DragonMountain_Top_OnFrame::
# 18 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 19 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 20 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_ABRA, MAP_DRAGON_MOUNTAIN_TOP
# 21 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_PLAYER, MAP_DRAGON_MOUNTAIN_TOP
# 22 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_WEST
# 23 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 24 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 25 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 26 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 27 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 28 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 29 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 30 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_SPECIES ( ABRA )
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_NORMAL
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
# 33 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_TEMP_1, 1
# 34 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end


DragonMountain_Top_EventScript_Abra::
# 40 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 41 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 42 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_ABRA, Common_Movement_FacePlayer
# 43 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 44 "data/maps/DragonMountain_Top/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 45 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
# 46 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountain_Top_EventScript_Abra_Text_0, MSGBOX_YESNO
# 48 "data/maps/DragonMountain_Top/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq DragonMountain_Top_EventScript_Abra_2
DragonMountain_Top_EventScript_Abra_1:
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	release
	end

DragonMountain_Top_EventScript_Abra_2:
# 49 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 50 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 51 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 52 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 54 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 1
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	warp MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
	goto DragonMountain_Top_EventScript_Abra_1


DragonMountan_Top_EventScript_Sergio::
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 70 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 72 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 73 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 74 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 75 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 76 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 77 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 81 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 89 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_1
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 118 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 120 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 121 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_2
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 126 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_EventScript_Sergio_Text_7
# 128 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_3
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 131 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 132 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 133 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 136 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 137 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 138 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 139 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_4
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 142 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 144 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 147 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_5
# 149 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_6
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_7
# 152 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_PLAYER
# 153 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_EAST
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 157 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 158 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 160 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 161 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 163 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 165 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SERGIO
# 166 "data/maps/DragonMountain_Top/scripts.pory"
	setvar VAR_SERGIO_ROOM_STATE, 2
# 167 "data/maps/DragonMountain_Top/scripts.pory"
	warp MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 168 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 169 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
	end


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 175 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 176 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 177 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 180 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 183 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 186 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 178 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 181 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 184 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 187 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 78 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 102 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 124 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 129 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 140 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 148 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 148 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 150 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_right
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 150 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

# 151 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_left
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 151 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
	step_end

DragonMountain_Top_EventScript_Abra_Text_0:
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Deseas volver a la sala de Sergio?$"

DragonMountan_Top_EventScript_Sergio_Text_0:
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 74 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no ibamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 77 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco. Quién sabe… a lo mejor es\n"
	.string "que soy el mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?\n"
	.string "Admiro que hayas llegado hasta aquí, se\l"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí! Ha llegado el momento de\n"
	.string "combatir, y mis dragones no se\l"
	.string "contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Wow! ¡Eso ha sido brutal!$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes\n"
	.string "dormido, ¡que hay un montón de cosas\l"
	.string "por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	.string "TODO Frase sergio$"
