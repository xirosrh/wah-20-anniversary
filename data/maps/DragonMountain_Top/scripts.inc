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
	end


DragonMountan_Top_EventScript_Sergio::
# 45 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 46 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 48 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 49 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 50 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 51 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 52 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 54 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 55 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_0
# 58 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 60 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 61 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 62 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 64 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 65 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 66 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 67 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 68 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_DoubleExclamationMarkWithDelay48
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 70 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 71 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 72 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 73 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 74 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 75 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 76 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 77 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 78 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 79 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 80 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 81 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_1
# 90 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 91 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 92 "data/maps/DragonMountain_Top/scripts.pory"
	delay 50
# 93 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 94 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 95 "data/maps/DragonMountain_Top/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 15, 13
# 96 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 97 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE, Common_Movement_WalkDown6
# 98 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown4
# 99 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_MOUNTAINTOP_SERGIODRAGONITE
# 100 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
# 101 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_6, MSGBOX_AUTOCLOSE
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_2
# 104 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 105 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_SERGIO_MAIN, DragonMountan_Top_EventScript_Sergio_Text_7
# 107 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_FAILURE
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIODRAGONITE, DragonMountan_Top_EventScript_Sergio_Movement_3
# 109 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 110 "data/maps/DragonMountain_Top/scripts.pory"
	delay 100
# 111 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 112 "data/maps/DragonMountain_Top/scripts.pory"
	showobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 113 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxyperm LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 114 "data/maps/DragonMountain_Top/scripts.pory"
	setobjectxy LOCALID_MOUNTAINTOP_SERGIO, 16, 13
# 115 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_SERGIO, DIR_WEST
# 116 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 117 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIODRAGONITE, MAP_DRAGON_MOUNTAIN_TOP
# 118 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_4
# 120 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 121 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 123 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 124 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 126 "data/maps/DragonMountain_Top/scripts.pory"
	call DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_5
# 128 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_MOUNTAINTOP_SERGIO, DragonMountan_Top_EventScript_Sergio_Movement_6
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, DragonMountan_Top_EventScript_Sergio_Movement_7
# 131 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_PLAYER
# 132 "data/maps/DragonMountain_Top/scripts.pory"
	turnobject LOCALID_MOUNTAINTOP_ABRA, DIR_EAST
# 133 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 134 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 135 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 136 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_2
# 137 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 138 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 139 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 140 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_PLAYER, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 141 "data/maps/DragonMountain_Top/scripts.pory"
	updateobjectsprite LOCALID_MOUNTAINTOP_SERGIO, OBJ_EVENT_GFX_SERGIO_TELEPORTING_1
# 142 "data/maps/DragonMountain_Top/scripts.pory"
	release
# 143 "data/maps/DragonMountain_Top/scripts.pory"
	delay 20
# 144 "data/maps/DragonMountain_Top/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_SERGIO
# 145 "data/maps/DragonMountain_Top/scripts.pory"
	warp MAP_SERGIO_ROOM, WARP_ID_SERGIO_ROOM_ABRA
# 146 "data/maps/DragonMountain_Top/scripts.pory"
	waitstate
# 147 "data/maps/DragonMountain_Top/scripts.pory"
	releaseall
	end


DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer::
# 153 "data/maps/DragonMountain_Top/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 154 "data/maps/DragonMountain_Top/scripts.pory"
	switch VAR_RESULT
# 155 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_NORTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3
# 158 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_SOUTH, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4
# 161 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_WEST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5
# 164 "data/maps/DragonMountain_Top/scripts.pory"
	case DIR_EAST, DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6
DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1:
	return

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_3:
# 156 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceDown
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_4:
# 159 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceUp
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_5:
# 162 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceRight
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1

DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_6:
# 165 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_WalkInPlaceLeft
	goto DragonMountan_Top_EventScript_WalkInPlaceSergioFacingPlayer_1


# 57 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_0:
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	emote_smile
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 57 "data/maps/DragonMountain_Top/scripts.pory"
	face_player
	step_end

# 81 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_1:
# 82 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
# 83 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 84 "data/maps/DragonMountain_Top/scripts.pory"
	face_right
# 85 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 86 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
# 87 "data/maps/DragonMountain_Top/scripts.pory"
	delay_16
# 88 "data/maps/DragonMountain_Top/scripts.pory"
	face_up
	step_end

# 103 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_2:
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	emote_versus
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_down
# 103 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 108 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_3:
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	disable_jump_landing_ground_effect
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	lock_facing_direction
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	emote_x
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	jump_up
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	unlock_facing_direction
# 108 "data/maps/DragonMountain_Top/scripts.pory"
	enable_jump_landing_ground_effect
	step_end

# 119 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_4:
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
# 119 "data/maps/DragonMountain_Top/scripts.pory"
	jump_in_place_left
	step_end

# 127 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_5:
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	walk_down
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	walk_left
# 127 "data/maps/DragonMountain_Top/scripts.pory"
	face_down
	step_end

# 129 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_6:
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_right
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 129 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

# 130 "data/maps/DragonMountain_Top/scripts.pory"
DragonMountan_Top_EventScript_Sergio_Movement_7:
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_left
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	walk_fast_down
# 130 "data/maps/DragonMountain_Top/scripts.pory"
	face_left
	step_end

DragonMountan_Top_EventScript_Sergio_Text_0:
# 47 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 53 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey ti{OA}! ¿qué tal? ¿de verdad pensabas\n"
	.string "que no ibamos a hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 56 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o… ¡me alegra ver gente nueva\n"
	.string "por aquí!$"

DragonMountan_Top_EventScript_Sergio_Text_3:
# 59 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Qué? ¿No te esperabas encontrarme en\n"
	.string "este pico, a tres pasos de caerme?\p"
	.string "Yo tampoco. Quién sabe… a lo mejor es\n"
	.string "que soy el mesías.$"

DragonMountan_Top_EventScript_Sergio_Text_4:
# 63 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Dime ti{OA}, ¿qué buscas por aquí?$"

DragonMountan_Top_EventScript_Sergio_Text_5:
# 69 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¿Eh? ¿Así que quieres combatir ahora?\n"
	.string "Admiro que hayas llegado hasta aquí, se\l"
	.string "que a veces soy difícil de encontrar.\p"
	.string "Pero todavía no estoy listo para\n"
	.string "combatir.$"

DragonMountan_Top_EventScript_Sergio_Text_6:
# 102 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ahora sí! Ha llegado el momento de\n"
	.string "combatir, y mis dragones no se\l"
	.string "contendrán.\p"
	.string "¡Dragonite, desata toda tu furia sobre\n"
	.string "el campo de batalla!$"

DragonMountan_Top_EventScript_Sergio_Text_7:
# 106 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Wow! ¡Eso ha sido brutal!$"

DragonMountan_Top_EventScript_Sergio_Text_8:
# 120 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Felicidades! ¡Has cumplido el sueño de\n"
	.string "WAH!$"

DragonMountan_Top_EventScript_Sergio_Text_9:
# 122 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Ahora por supuesto no te quedes\n"
	.string "dormido, ¡que hay un montón de cosas\l"
	.string "por hacer!$"

DragonMountan_Top_EventScript_Sergio_Text_10:
# 125 "data/maps/DragonMountain_Top/scripts.pory"
	.string "TODO Frase sergio$"
