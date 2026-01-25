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
	waitmovement 0
# 67 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 68 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 69 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_2
# 70 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 71 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_3
# 72 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 73 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 75 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3, speaker = SP_NAME_REONEKY
# 76 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 77 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 78 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 79 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_VersusWithDelay48
# 80 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 81 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_4
# 88 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_EFFECTIVE
# 89 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_5
# 96 "data/maps/ReonekyRoom/scripts.pory"
	release
# 97 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 98 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 99 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 100 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 101 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 102 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 103 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 104 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 105 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 106 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 107 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 108 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 109 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 110 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 111 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 112 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 113 "data/maps/ReonekyRoom/scripts.pory"
	release
# 114 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 115 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL2
# 116 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 117 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 118 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 119 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_SUPER_EFFECTIVE
# 120 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 121 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 122 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 123 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 124 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 125 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_3
# 126 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 127 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 128 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 129 "data/maps/ReonekyRoom/scripts.pory"
	release
# 130 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 131 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 132 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_6
# 139 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 140 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FAINT_ATTACK
# 141 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_7
# 156 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 157 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 158 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 159 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 160 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 161 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 162 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 163 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 164 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 165 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 166 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 167 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 168 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 169 "data/maps/ReonekyRoom/scripts.pory"
	release
# 170 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 171 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 172 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 173 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_8
# 174 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 175 "data/maps/ReonekyRoom/scripts.pory"
	release
# 176 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 177 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 178 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 179 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 180 "data/maps/ReonekyRoom/scripts.pory"
	release
# 181 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 182 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 183 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft
# 184 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 185 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft
# 186 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_BALL_OPEN
# 187 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 188 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 189 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 190 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 191 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 192 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_9
# 193 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 194 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 195 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 196 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 197 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 198 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 203 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 213 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 214 "data/maps/ReonekyRoom/scripts.pory"
	release
# 215 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 216 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 217 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 218 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 219 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 220 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 221 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 222 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 223 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 224 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 225 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 226 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 227 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 230 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 231 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 232 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_1
# 236 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5, speaker = SP_NAME_REONEKY
# 237 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 238 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_2
# 239 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 240 "data/maps/ReonekyRoom/scripts.pory"
	call ReonekyRoom_EventScript_ReonekyBattle
# 241 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 242 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 243 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 244 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 245 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 246 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 247 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 248 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 249 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 204 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 205 "data/maps/ReonekyRoom/scripts.pory"
	release
# 206 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 207 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 208 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 209 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 210 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_ReonekyBattle::
# 254 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReonekyRoom_EventScript_ReonekyBattle_2
# 257 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REONEKY
# 258 "data/maps/ReonekyRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 259 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReonekyRoom_EventScript_ReonekyBattle_5
# 262 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE, ReonekyRoom_Text_ReonekyDefeated
ReonekyRoom_EventScript_ReonekyBattle_1:
# 265 "data/maps/ReonekyRoom/scripts.pory"
	special HealPlayerParty
	return

ReonekyRoom_EventScript_ReonekyBattle_2:
# 255 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1

ReonekyRoom_EventScript_ReonekyBattle_5:
# 260 "data/maps/ReonekyRoom/scripts.pory"
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
	step_end

# 69 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 69 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
	step_end

# 71 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 71 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 71 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 71 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 71 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 81 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 82 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 83 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 85 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 86 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 89 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 90 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 91 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 92 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 93 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 94 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 95 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 132 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_6:
# 133 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 134 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_right
# 135 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 136 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 136 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 136 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 136 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 136 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 137 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 141 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_7:
# 142 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 143 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 144 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 145 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 146 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 147 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 148 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 149 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 150 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 151 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 152 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 153 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 154 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 173 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_8:
# 173 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 173 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 173 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 173 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 192 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_9:
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 192 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 192 "data/maps/ReonekyRoom/scripts.pory"
	face_down
	step_end

# 227 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 228 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 229 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
	step_end

# 232 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_1:
# 233 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 234 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 235 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

# 238 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_2:
# 238 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
	step_end

ReonekyRoom_OnFrame_Text_0:
# 51 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 56 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 72 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionado…$"

ReonekyRoom_OnFrame_Text_3:
# 75 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 77 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 99 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 165 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 170 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 176 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela…\p"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill… Va con el Miata tuneao y\l"
	.string "nunca lo multan, solo lo paran para\l"
	.string "echarse fotos…$"

ReonekyRoom_OnFrame_Text_9:
# 181 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin… Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 207 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad!\p"
	.string "No dejes que te detengan y sobre todo,\n"
	.string "disfruta del momento.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 216 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 220 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.\p"
	.string "Soy Reoneky, experto en llevar el\n"
	.string "prefijo 'ex' tanto ámbito laboral como\l"
	.string "profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 222 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 225 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie… Sentía que no era\n"
	.string "nadie… Y eso lo cambió el WAH.\p"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.\p"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 236 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 241 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"

ReonekyRoom_Text_ReonekyDefeated::
# 269 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"
