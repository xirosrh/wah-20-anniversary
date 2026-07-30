CheveRoom_MapScripts::
# 6 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, CheveRoom_OnTransition
# 10 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, CheveRoom_OnLoad
# 7 "data/maps/CheveRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CheveRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

CheveRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/CheveRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, CheveRoom_OnWarp_PlayerTurnNorth
	.2byte 0


CheveRoom_OnLoad::
# 15 "data/maps/CheveRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_CHEVE, CheveRoom_OnLoad_2
CheveRoom_OnLoad_1:
	end

CheveRoom_OnLoad_2:
# 16 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto CheveRoom_OnLoad_1


CheveRoom_OnWarp_PlayerTurnNorth::
# 22 "data/maps/CheveRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


CheveRoom_OnTransition::
# 27 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Cheve
# 28 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 29 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_2
	end


CheveRoom_EventScript_Cheve::
# 34 "data/maps/CheveRoom/scripts.pory"
	lock
# 35 "data/maps/CheveRoom/scripts.pory"
	faceplayer
# 36 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 37 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer
# 38 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 39 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 40 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 41 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 42 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 43 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 44 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 46 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 47 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer::
# 52 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 53 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 54 "data/maps/CheveRoom/scripts.pory"
	case DIR_NORTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3
# 57 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4
# 60 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5
# 63 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6
CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1:
	return

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3:
# 55 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4:
# 58 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceUp
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5:
# 61 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceRight
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6:
# 64 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceLeft
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1


CheveRoom_EventScript_CuttableTree::
# 71 "data/maps/CheveRoom/scripts.pory"
	lock
# 72 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 73 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 74 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_CuttableTree_3
# 82 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_CuttableTree_4
# 89 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_CuttableTree_5
CheveRoom_EventScript_CuttableTree_1:
# 96 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 97 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 98 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_3
# 99 "data/maps/CheveRoom/scripts.pory"
	waitse
# 100 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 101 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_4
# 104 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_5
# 109 "data/maps/CheveRoom/scripts.pory"
	waitse
# 110 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 111 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 112 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 113 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 114 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 115 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkUp2
# 116 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 117 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 118 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 119 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_CHEVE, MAP_CHEVE_ROOM
# 120 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 121 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 122 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 123 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 124 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 125 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 126 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 127 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 128 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_POKEBALL
# 129 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_POKEBALL, MAP_CHEVE_ROOM
# 130 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 131 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 132 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 133 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_POKEBALL
# 134 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 135 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_MEGANIUM
# 136 "data/maps/CheveRoom/scripts.pory"
	waitse
# 137 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 138 "data/maps/CheveRoom/scripts.pory"
	release
# 139 "data/maps/CheveRoom/scripts.pory"
	playmoncry SPECIES_MEGANIUM, CRY_MODE_NORMAL
# 140 "data/maps/CheveRoom/scripts.pory"
	waitmoncry
# 141 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 142 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_MEGANIUM, CheveRoom_EventScript_CuttableTree_Movement_6
# 146 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 147 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_MEGANIUM, CheveRoom_EventScript_CuttableTree_Movement_7
# 151 "data/maps/CheveRoom/scripts.pory"
	waitmovement 0
# 152 "data/maps/CheveRoom/scripts.pory"
	release
# 153 "data/maps/CheveRoom/scripts.pory"
	playse SE_M_CUT
# 154 "data/maps/CheveRoom/scripts.pory"
	load_field_pic FP_CUT_ATTACK, 121, 75, VAR_TEMP_2
# 155 "data/maps/CheveRoom/scripts.pory"
	delay 60
# 156 "data/maps/CheveRoom/scripts.pory"
	destroy_field_pic FP_CUT_ATTACK, VAR_TEMP_2
# 157 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_TREE, Movement_CutTreeDown
# 158 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 159 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 160 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 161 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_MEGANIUM
# 162 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 163 "data/maps/CheveRoom/scripts.pory"
	waitse
# 164 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 165 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 166 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown3
# 167 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 168 "data/maps/CheveRoom/scripts.pory"
	waitmovement LOCALID_CHEVEROOM_CHEVE
# 169 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 170 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 171 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 172 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 173 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 174 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 175 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 176 "data/maps/CheveRoom/scripts.pory"
	delay 30
# 177 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 178 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 179 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 180 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 181 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 182 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SmileWithDelay48
# 183 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 184 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 185 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 186 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 187 "data/maps/CheveRoom/scripts.pory"
	waitse
# 188 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 189 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 190 "data/maps/CheveRoom/scripts.pory"
	waitse
# 191 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 192 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 193 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WinkWithDelay48
# 194 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_9, speaker = SP_NAME_CHEVE
# 195 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 196 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, CheveRoom_EventScript_CuttableTree_Movement_8
# 197 "data/maps/CheveRoom/scripts.pory"
	waitse
# 198 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_CheveBattle
# 199 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 200 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 201 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SweatDropWithDelay48
# 202 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 203 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 204 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 205 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 206 "data/maps/CheveRoom/scripts.pory"
	waitse
# 207 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 208 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 209 "data/maps/CheveRoom/scripts.pory"
	delay 30
# 210 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 211 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 212 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 213 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 214 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 215 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 216 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 217 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_CHEVE
# 218 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_TREE
# 219 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 220 "data/maps/CheveRoom/scripts.pory"
	setobjectxyperm LOCALID_CHEVEROOM_CHEVE, 6, 5
# 221 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 222 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 223 "data/maps/CheveRoom/scripts.pory"
	release
	end

CheveRoom_EventScript_CuttableTree_3:
# 75 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_0
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_4:
# 83 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_1
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_5:
# 90 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_2
	goto CheveRoom_EventScript_CuttableTree_1


CheveRoom_EventScript_CheveBattle::
# 228 "data/maps/CheveRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, CheveRoom_EventScript_CheveBattle_2
# 231 "data/maps/CheveRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_CHEVE
# 232 "data/maps/CheveRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 233 "data/maps/CheveRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CheveRoom_EventScript_CheveBattle_5
# 236 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_ALTERNATIVE, CheveRoom_Text_CheveDefeated
CheveRoom_EventScript_CheveBattle_1:
	return

CheveRoom_EventScript_CheveBattle_2:
# 229 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_Text_CheveDefeated
	goto CheveRoom_EventScript_CheveBattle_1

CheveRoom_EventScript_CheveBattle_5:
# 234 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_Text_CheveDefeated
	goto CheveRoom_EventScript_CheveBattle_1


# 75 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_0:
# 76 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 77 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 77 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 78 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 79 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 83 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_1:
# 84 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 85 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 86 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 90 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_2:
# 91 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 92 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 93 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 98 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_3:
# 98 "data/maps/CheveRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 101 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_4:
# 102 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 103 "data/maps/CheveRoom/scripts.pory"
	jump_in_place_up
	step_end

# 105 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_5:
# 106 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 107 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
# 108 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 142 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_6:
# 143 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 144 "data/maps/CheveRoom/scripts.pory"
	jump_down
	step_end

# 147 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_7:
# 148 "data/maps/CheveRoom/scripts.pory"
	jump_up
# 149 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 196 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_8:
# 196 "data/maps/CheveRoom/scripts.pory"
	emote_versus
	step_end

CheveRoom_EventScript_Cheve_Text_0:
# 36 "data/maps/CheveRoom/scripts.pory"
	.string "So you came back? Don't tell me… you\n"
	.string "want a rematch?$"

CheveRoom_EventScript_Cheve_Text_1:
# 39 "data/maps/CheveRoom/scripts.pory"
	.string "Don't even dream of it. I'm in the middle\n"
	.string "of a creative process… i.e.,\l"
	.string "procrastinating.$"

CheveRoom_EventScript_Cheve_Text_2:
# 43 "data/maps/CheveRoom/scripts.pory"
	.string "I appreciate the visit, though.\p"
	.string "It's nice when someone comes back to\n"
	.string "your room, even if it's just to say hi to\l"
	.string "the tree that wasn't a tree.$"

CheveRoom_EventScript_Cheve_Text_3:
# 46 "data/maps/CheveRoom/scripts.pory"
	.string "Greetings!$"

CheveRoom_EventScript_CuttableTree_Text_0:
# 96 "data/maps/CheveRoom/scripts.pory"
	.string "Why are you looking at me like that?$"

CheveRoom_EventScript_CuttableTree_Text_1:
# 110 "data/maps/CheveRoom/scripts.pory"
	.string "You want to Cut me down?\p"
	.string "Don't hurt me, I'm Cheve!$"

CheveRoom_EventScript_CuttableTree_Text_2:
# 125 "data/maps/CheveRoom/scripts.pory"
	.string "Go, Sprout!$"

CheveRoom_EventScript_CuttableTree_Text_3:
# 170 "data/maps/CheveRoom/scripts.pory"
	.string "You fell for it completely.$"

CheveRoom_EventScript_CuttableTree_Text_4:
# 173 "data/maps/CheveRoom/scripts.pory"
	.string "Did you really think I was a tree?$"

CheveRoom_EventScript_CuttableTree_Text_5:
# 177 "data/maps/CheveRoom/scripts.pory"
	.string "But hey… I didn't expect you to make it\n"
	.string "all the way to my room.\p"
	.string "And even less after beating my great\n"
	.string "friend Javi4315!$"

CheveRoom_EventScript_CuttableTree_Text_6:
# 180 "data/maps/CheveRoom/scripts.pory"
	.string "I respect him a lot, so… let's say that\n"
	.string "alone makes me like you.$"

CheveRoom_EventScript_CuttableTree_Text_7:
# 184 "data/maps/CheveRoom/scripts.pory"
	.string "I guess it's my turn to put your luck to\n"
	.string "the test.$"

CheveRoom_EventScript_CuttableTree_Text_8:
# 191 "data/maps/CheveRoom/scripts.pory"
	.string "Fair warning, though… I'm not a big fan\n"
	.string "of long battles.\p"
	.string "I'd rather procrastinate… my favorite\n"
	.string "activity!$"

CheveRoom_EventScript_CuttableTree_Text_9:
# 194 "data/maps/CheveRoom/scripts.pory"
	.string "Let's go!$"

CheveRoom_EventScript_CuttableTree_Text_10:
# 199 "data/maps/CheveRoom/scripts.pory"
	.string "Ugh… what a beating.$"

CheveRoom_EventScript_CuttableTree_Text_11:
# 203 "data/maps/CheveRoom/scripts.pory"
	.string "Makes me want to put off my rematch\n"
	.string "until next century.\p"
	.string "But hey, don't get me wrong… it was fun!$"

CheveRoom_EventScript_CuttableTree_Text_12:
# 210 "data/maps/CheveRoom/scripts.pory"
	.string "I guess that's what this place is like:\n"
	.string "someone new always shows up at your\l"
	.string "room, and when they leave, they hang\l"
	.string "one more little painting on the wall.\p"
	.string "Mine's got quite a few already, but this\n"
	.string "battle deserves a new one.$"

CheveRoom_EventScript_CuttableTree_Text_13:
# 213 "data/maps/CheveRoom/scripts.pory"
	.string "Come on, keep going.\p"
	.string "I'm sure the next floor has another\n"
	.string "surprise in store for you.$"

CheveRoom_Text_CheveDefeated::
# 242 "data/maps/CheveRoom/scripts.pory"
	.string "Great battle! It reminded me of my\n"
	.string "showdowns with Xavi.$"
