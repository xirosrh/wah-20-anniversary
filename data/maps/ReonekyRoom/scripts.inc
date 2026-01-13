ReonekyRoom_MapScripts::
# 10 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ReonekyRoom_OnTransition
# 14 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ReonekyRoom_OnLoad
# 7 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ReonekyRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 11 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ReonekyRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ReonekyRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 8 "data/maps/ReonekyRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, ReonekyRoom_OnFrame
	.2byte 0

ReonekyRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 12 "data/maps/ReonekyRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ReonekyRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ReonekyRoom_OnLoad::
# 18 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_OnLoad_2
ReonekyRoom_OnLoad_1:
	end

ReonekyRoom_OnLoad_2:
# 19 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ReonekyRoom_OnLoad_1


ReonekyRoom_OnWarp_PlayerTurnNorth::
# 25 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ReonekyRoom_OnTransition::
# 31 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq ReonekyRoom_OnTransition_2
ReonekyRoom_OnTransition_1:
# 35 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq ReonekyRoom_OnTransition_5
ReonekyRoom_OnTransition_4:
	end

ReonekyRoom_OnTransition_2:
# 32 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 33 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
	goto ReonekyRoom_OnTransition_1

ReonekyRoom_OnTransition_5:
# 36 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 37 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 38 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxy LOCALID_REOROOM_REONEKY, 6, 4
# 39 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
	goto ReonekyRoom_OnTransition_4


ReonekyRoom_OnFrame::
# 45 "data/maps/ReonekyRoom/scripts.pory"
	release
# 46 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 47 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 48 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 49 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 51 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 52 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 53 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 54 "data/maps/ReonekyRoom/scripts.pory"
	release
# 55 "data/maps/ReonekyRoom/scripts.pory"
	delay 80
# 56 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 57 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 58 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 59 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 64 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 65 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 66 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 67 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 69 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3, speaker = SP_NAME_REONEKY
# 70 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 71 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 72 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_VersusWithDelay48
# 74 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 75 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_2
# 82 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_3
# 89 "data/maps/ReonekyRoom/scripts.pory"
	release
# 90 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 91 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 92 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 93 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 94 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 95 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 96 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 97 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 98 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 99 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 100 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight2
# 101 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 102 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 103 "data/maps/ReonekyRoom/scripts.pory"
	release
# 104 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 105 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 106 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 107 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 108 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 109 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 110 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 111 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 112 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_3
# 113 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 114 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 115 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 116 "data/maps/ReonekyRoom/scripts.pory"
	release
# 117 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 118 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 119 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_4
# 139 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 140 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 141 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight2
# 142 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 143 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 144 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 145 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 146 "data/maps/ReonekyRoom/scripts.pory"
	release
# 147 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 148 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 150 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_5
# 151 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 152 "data/maps/ReonekyRoom/scripts.pory"
	release
# 153 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 154 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 155 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 156 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 157 "data/maps/ReonekyRoom/scripts.pory"
	release
# 158 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 159 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft2
# 160 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 161 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 162 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 163 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 164 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 165 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_6
# 166 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 167 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 168 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 169 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 170 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 171 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 176 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 186 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 187 "data/maps/ReonekyRoom/scripts.pory"
	release
# 188 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 189 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 190 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 191 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 192 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 193 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 194 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 195 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 196 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 197 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 198 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 199 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 200 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 206 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5, speaker = SP_NAME_REONEKY
# 207 "data/maps/ReonekyRoom/scripts.pory"
	call ReonekyRoom_EventScript_ReonekyBattle
# 208 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 209 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 210 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 211 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 212 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 213 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 214 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 215 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 216 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 177 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 178 "data/maps/ReonekyRoom/scripts.pory"
	release
# 179 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 180 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 181 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 182 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 183 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_ReonekyBattle::
# 221 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReonekyRoom_EventScript_ReonekyBattle_2
# 224 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REONEKY
# 225 "data/maps/ReonekyRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 226 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReonekyRoom_EventScript_ReonekyBattle_5
# 229 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE, ReonekyRoom_Text_ReonekyDefeated
ReonekyRoom_EventScript_ReonekyBattle_1:
# 232 "data/maps/ReonekyRoom/scripts.pory"
	special HealPlayerParty
	return

ReonekyRoom_EventScript_ReonekyBattle_2:
# 222 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1

ReonekyRoom_EventScript_ReonekyBattle_5:
# 227 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1


# 59 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 60 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 61 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 61 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 62 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 63 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 65 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 65 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
# 65 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 65 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 65 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 65 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 65 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 75 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 76 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 77 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 78 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 79 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 80 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 82 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 83 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 84 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 85 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 86 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 87 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 88 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 119 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 120 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 121 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_right
# 122 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 123 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 123 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 123 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 123 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 123 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 124 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 125 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 126 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 127 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 128 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 129 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 130 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 131 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 132 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 133 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 134 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 135 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 136 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 137 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 150 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 150 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 150 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 150 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 150 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 165 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_6:
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 165 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 165 "data/maps/ReonekyRoom/scripts.pory"
	face_down
	step_end

# 200 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 201 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
# 202 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 203 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 203 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 204 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 205 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

ReonekyRoom_OnFrame_Text_0:
# 51 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 56 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 66 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionado…$"

ReonekyRoom_OnFrame_Text_3:
# 69 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 71 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 92 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 142 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 147 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 153 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela…\p"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill… Va con el Miata tuneao y\l"
	.string "nunca lo multan, solo lo paran para\l"
	.string "echarse fotos…$"

ReonekyRoom_OnFrame_Text_9:
# 158 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin… Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 180 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad!\p"
	.string "No dejes que te detengan y sobre todo,\n"
	.string "disfruta del momento.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 189 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 193 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.\p"
	.string "Soy Reoneky, experto en llevar el\n"
	.string "prefijo 'ex' tanto ámbito laboral como\l"
	.string "profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 195 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 198 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie… Sentía que no era\n"
	.string "nadie… Y eso lo cambió el WAH.\p"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.\p"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 206 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 208 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"

ReonekyRoom_Text_ReonekyDefeated::
# 236 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"
