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
	playbgm MUS_TEAM_ORIGEN_TO, FALSE
# 46 "data/maps/ReonekyRoom/scripts.pory"
	release
# 47 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 48 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 49 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 50 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 52 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 53 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 54 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 55 "data/maps/ReonekyRoom/scripts.pory"
	release
# 56 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_NORMAL
# 57 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 58 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 59 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 60 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 61 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 66 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 67 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 68 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 70 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 71 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_2
# 72 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 73 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_3
# 74 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 75 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 76 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 77 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3, speaker = SP_NAME_REONEKY
# 78 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 79 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 80 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 81 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_Versus
# 82 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 83 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_ENCOUNTER
# 84 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 85 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 86 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_4
# 93 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_EFFECTIVE
# 94 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_5
# 101 "data/maps/ReonekyRoom/scripts.pory"
	release
# 102 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 103 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 104 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 105 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 106 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 107 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 108 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 109 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 110 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 111 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 112 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 113 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 114 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 115 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 116 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 117 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 118 "data/maps/ReonekyRoom/scripts.pory"
	release
# 119 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 120 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL2
# 121 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 122 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 123 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 124 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_SUPER_EFFECTIVE
# 125 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 126 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 127 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 128 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 129 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 130 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_3
# 131 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 132 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 133 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 134 "data/maps/ReonekyRoom/scripts.pory"
	release
# 135 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 136 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 137 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_6
# 144 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 145 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FAINT_ATTACK
# 146 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_7
# 161 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 162 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 163 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 164 "data/maps/ReonekyRoom/scripts.pory"
	fadedefaultbgm
# 165 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 166 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 167 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 168 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 169 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 170 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 171 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 172 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 173 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 174 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 175 "data/maps/ReonekyRoom/scripts.pory"
	release
# 176 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 177 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 178 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 179 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_8
# 180 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 181 "data/maps/ReonekyRoom/scripts.pory"
	release
# 182 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 183 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 184 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 185 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 186 "data/maps/ReonekyRoom/scripts.pory"
	release
# 187 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 188 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 189 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft
# 190 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 191 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft
# 192 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_NORMAL
# 193 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 194 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_BALL_OPEN
# 195 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 196 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 197 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 198 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 199 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 200 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_9
# 201 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 202 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 203 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 204 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 205 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 206 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 211 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 221 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 222 "data/maps/ReonekyRoom/scripts.pory"
	release
# 223 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 224 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 225 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 226 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 227 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 228 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 229 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 230 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 231 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 232 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 233 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 234 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 235 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 238 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 239 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 240 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_1
# 244 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5, speaker = SP_NAME_REONEKY
# 245 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 246 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_2
# 247 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 248 "data/maps/ReonekyRoom/scripts.pory"
	call ReonekyRoom_EventScript_ReonekyBattle
# 249 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 250 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 251 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 252 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 253 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 254 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 255 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 256 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 257 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 212 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 213 "data/maps/ReonekyRoom/scripts.pory"
	release
# 214 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 215 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 216 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 217 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 218 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_ReonekyBattle::
# 262 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReonekyRoom_EventScript_ReonekyBattle_2
# 265 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REONEKY
# 266 "data/maps/ReonekyRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 267 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReonekyRoom_EventScript_ReonekyBattle_5
# 270 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE, ReonekyRoom_Text_ReonekyDefeated
ReonekyRoom_EventScript_ReonekyBattle_1:
# 273 "data/maps/ReonekyRoom/scripts.pory"
	special HealPlayerParty
	return

ReonekyRoom_EventScript_ReonekyBattle_2:
# 263 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1

ReonekyRoom_EventScript_ReonekyBattle_5:
# 268 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1


# 61 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 62 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 63 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 63 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 64 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 65 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 67 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 67 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
	step_end

# 71 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 71 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
	step_end

# 73 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 73 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 73 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 73 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 73 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 86 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 87 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 88 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 89 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 90 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 91 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 94 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 95 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 96 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 97 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 98 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 99 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 100 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 137 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_6:
# 138 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 139 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_right
# 140 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 142 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 146 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_7:
# 147 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 148 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 149 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 150 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 151 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 152 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 153 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 154 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 155 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 156 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 157 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 158 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 159 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 179 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_8:
# 179 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 179 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 179 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 179 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 200 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_9:
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 200 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 200 "data/maps/ReonekyRoom/scripts.pory"
	face_down
	step_end

# 235 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 236 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 237 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
	step_end

# 240 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_1:
# 241 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 242 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 243 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

# 246 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_2:
# 246 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
	step_end

ReonekyRoom_OnFrame_Text_0:
# 52 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 58 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 74 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionada…$"

ReonekyRoom_OnFrame_Text_3:
# 77 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 79 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, Cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 104 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 171 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 176 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 182 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela…\p"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill… Va con el Miata tuneao y\l"
	.string "nunca lo multan, solo lo paran para\l"
	.string "echarse fotos…$"

ReonekyRoom_OnFrame_Text_9:
# 187 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin… Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 215 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad!\p"
	.string "No dejes que te detengan y sobre todo,\n"
	.string "disfruta del momento.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 224 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 228 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.\p"
	.string "Soy Reoneky, experto en llevar el\n"
	.string "prefijo 'ex' tanto ámbito laboral como\l"
	.string "profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 230 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 233 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie… Sentía que no era\n"
	.string "nadie… Y eso lo cambió el WAH.\p"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.\p"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 244 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 249 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"

ReonekyRoom_Text_ReonekyDefeated::
# 277 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"
