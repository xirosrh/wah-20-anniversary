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
	special ShowMapNamePopup
# 48 "data/maps/ReonekyRoom/scripts.pory"
	release
# 49 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 50 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 51 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 52 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 53 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 54 "data/maps/ReonekyRoom/scripts.pory"
	special HideMapNamePopUpWindow
# 55 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 56 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 57 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 58 "data/maps/ReonekyRoom/scripts.pory"
	release
# 59 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_NORMAL
# 60 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 61 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 62 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 64 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 69 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 70 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 71 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 72 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 73 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 74 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_2
# 75 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 76 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_2
# 77 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 78 "data/maps/ReonekyRoom/scripts.pory"
	delay 60
# 79 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3, speaker = SP_NAME_REONEKY
# 80 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 81 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 82 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 83 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_Versus
# 84 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 85 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_TYPHLOSION, CRY_MODE_ENCOUNTER
# 86 "data/maps/ReonekyRoom/scripts.pory"
	waitmoncry
# 87 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 88 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_3
# 95 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_EFFECTIVE
# 96 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_4
# 103 "data/maps/ReonekyRoom/scripts.pory"
	release
# 104 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 105 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 106 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 107 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 108 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 109 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 110 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 111 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 112 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 113 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 114 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 115 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 116 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 117 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight
# 118 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 119 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 120 "data/maps/ReonekyRoom/scripts.pory"
	release
# 121 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 122 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL2
# 123 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 124 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 125 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 126 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_SUPER_EFFECTIVE
# 127 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 128 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 129 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 130 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 131 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 132 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_TEMP_3
# 133 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 134 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 135 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 136 "data/maps/ReonekyRoom/scripts.pory"
	release
# 137 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 138 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_5
# 146 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 147 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FAINT_ATTACK
# 148 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_6
# 163 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 164 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 165 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 166 "data/maps/ReonekyRoom/scripts.pory"
	fadedefaultbgm
# 167 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 168 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 169 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 170 "data/maps/ReonekyRoom/scripts.pory"
	waitse
# 171 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_LEDGE
# 172 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight
# 173 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
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
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_7
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
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_8
# 202 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 10
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
	call WahRoomsShared_EventScript_AfterBattle
# 259 "data/maps/ReonekyRoom/scripts.pory"
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
# 264 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, ReonekyRoom_EventScript_ReonekyBattle_2
# 267 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_REONEKY
# 268 "data/maps/ReonekyRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 269 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq ReonekyRoom_EventScript_ReonekyBattle_5
# 272 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_ALTERNATIVE, ReonekyRoom_Text_ReonekyDefeated
ReonekyRoom_EventScript_ReonekyBattle_1:
	return

ReonekyRoom_EventScript_ReonekyBattle_2:
# 265 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1

ReonekyRoom_EventScript_ReonekyBattle_5:
# 270 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_Text_ReonekyDefeated
	goto ReonekyRoom_EventScript_ReonekyBattle_1


ReonekyRoom_EventScript_Trash::
# 284 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Trash_Text_0, MSGBOX_SIGN
	end


ReonekyRoom_EventScript_Hydrant::
# 289 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Hydrant_Text_0, MSGBOX_SIGN
	end


ReonekyRoom_EventScript_Bidon::
# 294 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Bidon_Text_0, MSGBOX_SIGN
	end


# 64 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 65 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 66 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 66 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 67 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 68 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 70 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 70 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
	step_end

# 74 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 74 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
	step_end

# 88 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 89 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 90 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 91 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 92 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 93 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 96 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 97 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 98 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 99 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 100 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 101 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 102 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 139 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 140 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 141 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_right
# 142 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 143 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 143 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 143 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 143 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 143 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 144 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 148 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_6:
# 149 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 150 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 151 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 152 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 153 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 154 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 155 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 156 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 157 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 158 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 159 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 160 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 161 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 180 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_7:
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
ReonekyRoom_OnFrame_Movement_8:
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
# 55 "data/maps/ReonekyRoom/scripts.pory"
	.string "Spitfire, keep your distance!$"

ReonekyRoom_OnFrame_Text_1:
# 61 "data/maps/ReonekyRoom/scripts.pory"
	.string "That possessed tow truck is the\n"
	.string "embodiment of bureaucratic injustice!$"

ReonekyRoom_OnFrame_Text_2:
# 77 "data/maps/ReonekyRoom/scripts.pory"
	.string "Laughing, huh? Amateur…$"

ReonekyRoom_OnFrame_Text_3:
# 79 "data/maps/ReonekyRoom/scripts.pory"
	.string "I was parked perfectly - I won't give in\n"
	.string "to this unjust fine!$"

ReonekyRoom_OnFrame_Text_4:
# 81 "data/maps/ReonekyRoom/scripts.pory"
	.string "Spitfire, Zen Headbutt!$"

ReonekyRoom_OnFrame_Text_5:
# 106 "data/maps/ReonekyRoom/scripts.pory"
	.string "Now's our chance! Flame Wheel!$"

ReonekyRoom_OnFrame_Text_6:
# 173 "data/maps/ReonekyRoom/scripts.pory"
	.string "There, off you go!$"

ReonekyRoom_OnFrame_Text_7:
# 177 "data/maps/ReonekyRoom/scripts.pory"
	.string "You rock, you rule, buddy! We shook off\n"
	.string "the ghost of the fine!$"

ReonekyRoom_OnFrame_Text_8:
# 183 "data/maps/ReonekyRoom/scripts.pory"
	.string "Good thing J15 said he had it under\n"
	.string "control, what a mess…\p"
	.string "I really should have listened to\n"
	.string "Keltill… He drives his tuned-up Miata\l"
	.string "and never gets fined, they only pull him\l"
	.string "over to take photos with it…$"

ReonekyRoom_OnFrame_Text_9:
# 188 "data/maps/ReonekyRoom/scripts.pory"
	.string "Anyway… you did great, buddy, time to\n"
	.string "rest!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 216 "data/maps/ReonekyRoom/scripts.pory"
	.string "A stroke of luck happens when you seize\n"
	.string "a good opportunity!\p"
	.string "Don't let anyone stop you… and above\n"
	.string "all, enjoy the moment.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 225 "data/maps/ReonekyRoom/scripts.pory"
	.string "Hey! Quite a show you just witnessed,\n"
	.string "huh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 229 "data/maps/ReonekyRoom/scripts.pory"
	.string "By now you probably know what I do\n"
	.string "here, so let me introduce myself.\p"
	.string "I'm Reoneky, expert at carrying the\n"
	.string "prefix “ex,” in both my work and my\l"
	.string "career.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 231 "data/maps/ReonekyRoom/scripts.pory"
	.string "I might look like an emo, but I consider\n"
	.string "myself more introspective than\l"
	.string "anything.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 234 "data/maps/ReonekyRoom/scripts.pory"
	.string "I was nobody… I felt like I was nobody…\n"
	.string "and WaH changed that.\p"
	.string "So enough with the sentimentality and\n"
	.string "introductions - let's get to it.\p"
	.string "Cool head, warm heart, that's how the\n"
	.string "game is played.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 245 "data/maps/ReonekyRoom/scripts.pory"
	.string "Let's give it everything!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 250 "data/maps/ReonekyRoom/scripts.pory"
	.string "You show promise. Talent has limits;\n"
	.string "effort and passion don't.$"

ReonekyRoom_EventScript_Trash_Text_0:
# 284 "data/maps/ReonekyRoom/scripts.pory"
	.string "The wastebasket is completely empty.\p"
	.string "People may have thrown their trash out\n"
	.string "on the street.$"

ReonekyRoom_EventScript_Hydrant_Text_0:
# 289 "data/maps/ReonekyRoom/scripts.pory"
	.string "It's a small hydrant painted bright red.$"

ReonekyRoom_EventScript_Bidon_Text_0:
# 294 "data/maps/ReonekyRoom/scripts.pory"
	.string "It's a drum filled to the top with used\n"
	.string "oil.$"

ReonekyRoom_Text_ReonekyDefeated::
# 278 "data/maps/ReonekyRoom/scripts.pory"
	.string "Good battle - I had fun like a kid.$"
