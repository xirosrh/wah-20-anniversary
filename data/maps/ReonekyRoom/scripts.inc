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
	call WahRoomsShared_Kecleon_SetSala_Reoneky
# 32 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq ReonekyRoom_OnTransition_2
ReonekyRoom_OnTransition_1:
# 36 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq ReonekyRoom_OnTransition_5
ReonekyRoom_OnTransition_4:
	end

ReonekyRoom_OnTransition_2:
# 33 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 34 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
	goto ReonekyRoom_OnTransition_1

ReonekyRoom_OnTransition_5:
# 37 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 38 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 39 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxy LOCALID_REOROOM_REONEKY, 6, 4
# 40 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
	goto ReonekyRoom_OnTransition_4


ReonekyRoom_OnFrame::
# 46 "data/maps/ReonekyRoom/scripts.pory"
	playbgm MUS_TEAM_ORIGEN_TO, FALSE
# 47 "data/maps/ReonekyRoom/scripts.pory"
	release
# 48 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 49 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 50 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 51 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 53 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 54 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 55 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 56 "data/maps/ReonekyRoom/scripts.pory"
	release
# 57 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_NORMAL
# 58 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 59 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 60 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 61 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 62 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 67 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 68 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 69 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 70 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 71 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 72 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_2
# 73 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 74 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_3
# 75 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 76 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 78 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3, speaker = SP_NAME_REONEKY
# 79 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 80 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 81 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 82 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_Versus
# 83 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 84 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_ENCOUNTER
# 85 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 86 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 87 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_4
# 94 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_EFFECTIVE
# 95 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_5
# 102 "data/maps/ReonekyRoom/scripts.pory"
	release
# 103 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 104 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 105 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 106 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 107 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 108 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 109 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 110 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 111 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 112 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 113 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 114 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 115 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 116 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 117 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 118 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 119 "data/maps/ReonekyRoom/scripts.pory"
	release
# 120 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 121 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL2
# 122 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 123 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 124 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 125 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_SUPER_EFFECTIVE
# 126 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 127 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 128 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 129 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 130 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 131 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_3
# 132 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 133 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 134 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 135 "data/maps/ReonekyRoom/scripts.pory"
	release
# 136 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 137 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_6
# 145 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 146 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FAINT_ATTACK
# 147 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_7
# 162 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 163 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 164 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 165 "data/maps/ReonekyRoom/scripts.pory"
	fadedefaultbgm
# 166 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 167 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 168 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 169 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 170 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 171 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 172 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 173 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 174 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 175 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 176 "data/maps/ReonekyRoom/scripts.pory"
	release
# 177 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 178 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 179 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 180 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_8
# 181 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 182 "data/maps/ReonekyRoom/scripts.pory"
	release
# 183 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 184 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 185 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 186 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 187 "data/maps/ReonekyRoom/scripts.pory"
	release
# 188 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 189 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 190 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft
# 191 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 192 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft
# 193 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_NORMAL
# 194 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 195 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_BALL_OPEN
# 196 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 197 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 198 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 199 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 200 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 201 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_9
# 202 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 203 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 204 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 205 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 206 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 207 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 212 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 222 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 223 "data/maps/ReonekyRoom/scripts.pory"
	release
# 224 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 225 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 226 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 227 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 228 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 229 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 230 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 231 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 232 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 233 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 234 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 235 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 236 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 239 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 240 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 241 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_1
# 245 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5, speaker = SP_NAME_REONEKY
# 246 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 247 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_2
# 248 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 249 "data/maps/ReonekyRoom/scripts.pory"
	call ReonekyRoom_EventScript_ReonekyBattle
# 250 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 251 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 252 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 253 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 254 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 255 "data/maps/ReonekyRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 256 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 257 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 258 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 213 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 214 "data/maps/ReonekyRoom/scripts.pory"
	release
# 215 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 216 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 217 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 218 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 219 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_ReonekyBattle::
# 263 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReonekyRoom_EventScript_ReonekyBattle_2
# 266 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REONEKY
# 267 "data/maps/ReonekyRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 268 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReonekyRoom_EventScript_ReonekyBattle_5
# 271 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE, ReonekyRoom_Text_ReonekyDefeated
ReonekyRoom_EventScript_ReonekyBattle_1:
# 274 "data/maps/ReonekyRoom/scripts.pory"
	special HealPlayerParty
	return

ReonekyRoom_EventScript_ReonekyBattle_2:
# 264 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1

ReonekyRoom_EventScript_ReonekyBattle_5:
# 269 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1


# 62 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 63 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 64 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 64 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 65 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 66 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 68 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 68 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
	step_end

# 72 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 72 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
	step_end

# 74 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 74 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 74 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 74 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 74 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 88 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 89 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 90 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 91 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 92 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 95 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 96 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 97 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 98 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 99 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 100 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 101 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 138 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_6:
# 139 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 140 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_right
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 142 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 142 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 142 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 142 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 142 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 143 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 147 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_7:
# 148 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 149 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 150 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 151 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 152 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 153 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 154 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 155 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 156 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 157 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 158 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 159 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 160 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 180 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_8:
# 180 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 180 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 180 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 180 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 201 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_9:
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 201 "data/maps/ReonekyRoom/scripts.pory"
	walk_up
# 201 "data/maps/ReonekyRoom/scripts.pory"
	face_down
	step_end

# 236 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 237 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 238 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
	step_end

# 241 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_1:
# 242 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 243 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 244 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

# 247 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_2:
# 247 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
	step_end

ReonekyRoom_OnFrame_Text_0:
# 53 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 59 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 75 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionada…$"

ReonekyRoom_OnFrame_Text_3:
# 78 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 80 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, Cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 105 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 172 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 177 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 183 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela…\p"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill… Va con el Miata tuneao y\l"
	.string "nunca lo multan, solo lo paran para\l"
	.string "echarse fotos…$"

ReonekyRoom_OnFrame_Text_9:
# 188 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin… Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 216 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad!\p"
	.string "No dejes que te detengan y sobre todo,\n"
	.string "disfruta del momento.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 225 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 229 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.\p"
	.string "Soy Reoneky, experto en llevar el\n"
	.string "prefijo 'ex' tanto ámbito laboral como\l"
	.string "profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 231 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 234 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie… Sentía que no era\n"
	.string "nadie… Y eso lo cambió el WAH.\p"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.\p"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 245 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 250 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"

ReonekyRoom_Text_ReonekyDefeated::
# 278 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"
