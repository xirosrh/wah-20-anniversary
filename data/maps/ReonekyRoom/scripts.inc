ReonekyRoom_MapScripts::
# 5 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ReonekyRoom_OnTransition
# 9 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ReonekyRoom_OnLoad
# 2 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ReonekyRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 6 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, ReonekyRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

ReonekyRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/ReonekyRoom/scripts.pory"
	map_script_2 VAR_REONEKY_ROOM_STATE, 0, ReonekyRoom_OnFrame
	.2byte 0

ReonekyRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/ReonekyRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, ReonekyRoom_OnWarp_PlayerTurnNorth
	.2byte 0


ReonekyRoom_OnLoad::
# 13 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_OnLoad_2
ReonekyRoom_OnLoad_1:
	end

ReonekyRoom_OnLoad_2:
# 14 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto ReonekyRoom_OnLoad_1


ReonekyRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


ReonekyRoom_OnTransition::
# 26 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_REONEKY_ROOM_STATE, 0
	goto_if_eq ReonekyRoom_OnTransition_2
ReonekyRoom_OnTransition_1:
# 30 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_REONEKY_ROOM_STATE, 1
	goto_if_eq ReonekyRoom_OnTransition_5
ReonekyRoom_OnTransition_4:
	end

ReonekyRoom_OnTransition_2:
# 27 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 28 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
	goto ReonekyRoom_OnTransition_1

ReonekyRoom_OnTransition_5:
# 31 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 32 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 33 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxy LOCALID_REOROOM_REONEKY, 6, 4
# 34 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
	goto ReonekyRoom_OnTransition_4


ReonekyRoom_OnFrame::
# 40 "data/maps/ReonekyRoom/scripts.pory"
	release
# 41 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 42 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 43 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 44 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 45 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 46 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 47 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 48 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 49 "data/maps/ReonekyRoom/scripts.pory"
	release
# 50 "data/maps/ReonekyRoom/scripts.pory"
	delay 80
# 51 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 52 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 53 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 54 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 59 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 60 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 61 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 62 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 63 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 64 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3, speaker = SP_NAME_REONEKY
# 65 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 66 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 67 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 68 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_VersusWithDelay48
# 69 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 70 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_2
# 77 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_3
# 84 "data/maps/ReonekyRoom/scripts.pory"
	release
# 85 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 86 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 87 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 88 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 89 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 90 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 91 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_FIRE
# 92 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 93 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 94 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 95 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight2
# 96 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 97 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 98 "data/maps/ReonekyRoom/scripts.pory"
	release
# 99 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 100 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 101 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 102 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 103 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 104 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 105 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 106 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 107 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 108 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 109 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 110 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 111 "data/maps/ReonekyRoom/scripts.pory"
	release
# 112 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 113 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 114 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_4
# 134 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 135 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 136 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight2
# 137 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 138 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 139 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 140 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 141 "data/maps/ReonekyRoom/scripts.pory"
	release
# 142 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 143 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 145 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_5
# 146 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 147 "data/maps/ReonekyRoom/scripts.pory"
	release
# 148 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 149 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 150 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 151 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 152 "data/maps/ReonekyRoom/scripts.pory"
	release
# 153 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 154 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft2
# 155 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 156 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_TYPHLOSION
# 157 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 158 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 159 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_REONEKY_ROOM_STATE, 1
# 160 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_6
# 161 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 162 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 163 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 164 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 165 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 166 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 171 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 181 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 182 "data/maps/ReonekyRoom/scripts.pory"
	release
# 183 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 184 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 185 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 186 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 187 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 188 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 189 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 190 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 191 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 192 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 193 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 194 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 195 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 201 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5, speaker = SP_NAME_REONEKY
# 202 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_EventScript_Reoneky_Text_6
# 203 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 204 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 205 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 206 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 207 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 208 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 209 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 210 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 211 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 172 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 173 "data/maps/ReonekyRoom/scripts.pory"
	release
# 174 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 175 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 176 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 177 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 178 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


# 54 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 55 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 56 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 56 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 57 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 58 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 60 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 60 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
# 60 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 60 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 60 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 60 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 60 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 70 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 71 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 72 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 73 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 74 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 75 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 77 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 78 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 79 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 80 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 81 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 82 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 83 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 114 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 115 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 116 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_right
# 117 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 118 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 118 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 118 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 118 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 118 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 119 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 120 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 121 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 122 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 123 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 124 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 125 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 126 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 127 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 128 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 129 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 130 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 131 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 132 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 145 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 145 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 145 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 145 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 145 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 160 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_6:
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 160 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 160 "data/maps/ReonekyRoom/scripts.pory"
	face_down
	step_end

# 195 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 196 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
# 197 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 198 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 198 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 199 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 200 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

ReonekyRoom_OnFrame_Text_0:
# 46 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 51 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 61 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionado…$"

ReonekyRoom_OnFrame_Text_3:
# 64 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 66 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 87 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 137 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 142 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 148 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela…\p"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill… Va con el Miata tuneao y\l"
	.string "nunca lo multan, solo lo paran para\l"
	.string "echarse fotos…$"

ReonekyRoom_OnFrame_Text_9:
# 153 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin… Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 175 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad!\p"
	.string "No dejes que te detengan y sobre todo,\n"
	.string "disfruta del momento.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 184 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 188 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.\p"
	.string "Soy Reoneky, experto en llevar el\n"
	.string "prefijo 'ex' tanto ámbito laboral como\l"
	.string "profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 190 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 193 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie… Sentía que no era\n"
	.string "nadie… Y eso lo cambió el WAH.\p"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.\p"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 201 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 202 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"

ReonekyRoom_EventScript_Reoneky_Text_7:
# 203 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"
