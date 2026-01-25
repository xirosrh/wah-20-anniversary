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
	setflag FLAG_TEMP_1
# 28 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_2
	return


CheveRoom_EventScript_Cheve::
# 32 "data/maps/CheveRoom/scripts.pory"
	lock
# 33 "data/maps/CheveRoom/scripts.pory"
	faceplayer
# 34 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_0, speaker = SP_NAME_CHEVE
# 35 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer
# 36 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 37 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 38 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 39 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 40 "data/maps/CheveRoom/scripts.pory"
	delay 10
# 41 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_2, speaker = SP_NAME_CHEVE
# 42 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 44 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 45 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer::
# 50 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 51 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 52 "data/maps/CheveRoom/scripts.pory"
	case DIR_NORTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3
# 55 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4
# 58 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5
# 61 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6
CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1:
	return

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_3:
# 53 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_4:
# 56 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceUp
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_5:
# 59 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceRight
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1

CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_6:
# 62 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceLeft
	goto CheveRoom_EventScript_WalkInPlaceCheveFacingPlayer_1


CheveRoom_EventScript_CuttableTree::
# 69 "data/maps/CheveRoom/scripts.pory"
	lock
# 70 "data/maps/CheveRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 71 "data/maps/CheveRoom/scripts.pory"
	switch VAR_RESULT
# 72 "data/maps/CheveRoom/scripts.pory"
	case DIR_SOUTH, CheveRoom_EventScript_CuttableTree_3
# 80 "data/maps/CheveRoom/scripts.pory"
	case DIR_WEST, CheveRoom_EventScript_CuttableTree_4
# 87 "data/maps/CheveRoom/scripts.pory"
	case DIR_EAST, CheveRoom_EventScript_CuttableTree_5
CheveRoom_EventScript_CuttableTree_1:
# 94 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 95 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_3
# 97 "data/maps/CheveRoom/scripts.pory"
	waitse
# 98 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 99 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_4
# 102 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 103 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_5
# 107 "data/maps/CheveRoom/scripts.pory"
	waitse
# 108 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 109 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 110 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 111 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 112 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 113 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CAMERA, Common_Movement_WalkUp2
# 114 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 115 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 116 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 117 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_CHEVE, MAP_CHEVE_ROOM
# 118 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 119 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 120 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown
# 121 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 122 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_CloseDoor
# 123 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 124 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 125 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 126 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_POKEBALL
# 127 "data/maps/CheveRoom/scripts.pory"
	showobjectat LOCALID_CHEVEROOM_POKEBALL, MAP_CHEVE_ROOM
# 128 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 129 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 130 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 131 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_POKEBALL
# 132 "data/maps/CheveRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 133 "data/maps/CheveRoom/scripts.pory"
	addobject LOCALID_CHEVEROOM_MEGANIUM
# 134 "data/maps/CheveRoom/scripts.pory"
	waitse
# 135 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 136 "data/maps/CheveRoom/scripts.pory"
	release
# 137 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 138 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_MEGANIUM, CheveRoom_EventScript_CuttableTree_Movement_6
# 142 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 143 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_MEGANIUM, CheveRoom_EventScript_CuttableTree_Movement_7
# 147 "data/maps/CheveRoom/scripts.pory"
	waitmovement 0
# 148 "data/maps/CheveRoom/scripts.pory"
	release
# 149 "data/maps/CheveRoom/scripts.pory"
	playse SE_M_CUT
# 150 "data/maps/CheveRoom/scripts.pory"
	load_field_pic FP_CUT_ATTACK, 121, 75, VAR_TEMP_2
# 151 "data/maps/CheveRoom/scripts.pory"
	delay 60
# 152 "data/maps/CheveRoom/scripts.pory"
	destroy_field_pic FP_CUT_ATTACK, VAR_TEMP_2
# 153 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_TREE, Movement_CutTreeDown
# 154 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 155 "data/maps/CheveRoom/scripts.pory"
	playse SE_BALL_OPEN
# 156 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 157 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_MEGANIUM
# 158 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 159 "data/maps/CheveRoom/scripts.pory"
	waitse
# 160 "data/maps/CheveRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 161 "data/maps/CheveRoom/scripts.pory"
	special SpawnCameraObject
# 162 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkDown3
# 163 "data/maps/CheveRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 164 "data/maps/CheveRoom/scripts.pory"
	waitmovement LOCALID_CHEVEROOM_CHEVE
# 165 "data/maps/CheveRoom/scripts.pory"
	special RemoveCameraObject
# 166 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 167 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 168 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_XDWithDelay48
# 169 "data/maps/CheveRoom/scripts.pory"
	delay 30
# 170 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_4, speaker = SP_NAME_CHEVE
# 171 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 172 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 173 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 174 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SmileWithDelay48
# 175 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 176 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_6, speaker = SP_NAME_CHEVE
# 177 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 178 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 179 "data/maps/CheveRoom/scripts.pory"
	waitse
# 180 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 181 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 182 "data/maps/CheveRoom/scripts.pory"
	waitse
# 183 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 184 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 185 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WinkWithDelay48
# 186 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_8, speaker = SP_NAME_CHEVE
# 187 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 188 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, CheveRoom_EventScript_CuttableTree_Movement_8
# 189 "data/maps/CheveRoom/scripts.pory"
	waitse
# 190 "data/maps/CheveRoom/scripts.pory"
	call CheveRoom_EventScript_CheveBattle
# 191 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 192 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 193 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_SweatDropWithDelay48
# 194 "data/maps/CheveRoom/scripts.pory"
	delay 20
# 195 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 196 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 197 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 198 "data/maps/CheveRoom/scripts.pory"
	waitse
# 199 "data/maps/CheveRoom/scripts.pory"
	playse SE_LEDGE
# 200 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_JumpInPlaceDown
# 201 "data/maps/CheveRoom/scripts.pory"
	delay 30
# 202 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 203 "data/maps/CheveRoom/scripts.pory"
	playse SE_PIN
# 204 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_HeartWithDelay48
# 205 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CuttableTree_Text_12, speaker = SP_NAME_CHEVE
# 206 "data/maps/CheveRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 207 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_CHEVEROOM_CHEVE, Common_Movement_WalkInPlaceDown
# 208 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_Cheve_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CHEVE
# 209 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_CHEVE
# 210 "data/maps/CheveRoom/scripts.pory"
	removeobject LOCALID_CHEVEROOM_TREE
# 211 "data/maps/CheveRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 212 "data/maps/CheveRoom/scripts.pory"
	setobjectxyperm LOCALID_CHEVEROOM_CHEVE, 6, 5
# 213 "data/maps/CheveRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_CHEVEROOM_CHEVE, MOVEMENT_TYPE_FACE_DOWN
# 214 "data/maps/CheveRoom/scripts.pory"
	release
	end

CheveRoom_EventScript_CuttableTree_3:
# 73 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_0
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_4:
# 81 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_1
	goto CheveRoom_EventScript_CuttableTree_1

CheveRoom_EventScript_CuttableTree_5:
# 88 "data/maps/CheveRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CheveRoom_EventScript_CuttableTree_Movement_2
	goto CheveRoom_EventScript_CuttableTree_1


CheveRoom_EventScript_CheveBattle::
# 219 "data/maps/CheveRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, CheveRoom_EventScript_CheveBattle_2
# 222 "data/maps/CheveRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_CHEVE
# 223 "data/maps/CheveRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 224 "data/maps/CheveRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CheveRoom_EventScript_CheveBattle_5
# 227 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_ALTERNATIVE, CheveRoom_Text_CheveDefeated
CheveRoom_EventScript_CheveBattle_1:
# 230 "data/maps/CheveRoom/scripts.pory"
	special HealPlayerParty
	return

CheveRoom_EventScript_CheveBattle_2:
# 220 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_Text_CheveDefeated
	goto CheveRoom_EventScript_CheveBattle_1

CheveRoom_EventScript_CheveBattle_5:
# 225 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_Text_CheveDefeated
	goto CheveRoom_EventScript_CheveBattle_1


# 73 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_0:
# 74 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 75 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 75 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 76 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 77 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 81 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_1:
# 82 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 83 "data/maps/CheveRoom/scripts.pory"
	walk_left
# 84 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 88 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_2:
# 89 "data/maps/CheveRoom/scripts.pory"
	walk_down
# 90 "data/maps/CheveRoom/scripts.pory"
	walk_right
# 91 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 96 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_3:
# 96 "data/maps/CheveRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 99 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_4:
# 100 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 101 "data/maps/CheveRoom/scripts.pory"
	jump_in_place_up
	step_end

# 103 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_5:
# 104 "data/maps/CheveRoom/scripts.pory"
	jump_down
# 105 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
# 106 "data/maps/CheveRoom/scripts.pory"
	face_up
	step_end

# 138 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_6:
# 139 "data/maps/CheveRoom/scripts.pory"
	lock_facing_direction
# 140 "data/maps/CheveRoom/scripts.pory"
	jump_down
	step_end

# 143 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_7:
# 144 "data/maps/CheveRoom/scripts.pory"
	jump_up
# 145 "data/maps/CheveRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 188 "data/maps/CheveRoom/scripts.pory"
CheveRoom_EventScript_CuttableTree_Movement_8:
# 188 "data/maps/CheveRoom/scripts.pory"
	emote_versus
	step_end

CheveRoom_EventScript_Cheve_Text_0:
# 34 "data/maps/CheveRoom/scripts.pory"
	.string "¿Así que volviste? No me digas…\n"
	.string "¿querés la revancha?$"

CheveRoom_EventScript_Cheve_Text_1:
# 37 "data/maps/CheveRoom/scripts.pory"
	.string "Ni lo sueñes. Estoy en pleno proceso\n"
	.string "creativo… o sea, procrastinando.$"

CheveRoom_EventScript_Cheve_Text_2:
# 41 "data/maps/CheveRoom/scripts.pory"
	.string "Igual te agradezco la visita. Es lindo\n"
	.string "cuando alguien vuelve a tu habitación,\l"
	.string "aunque sea para saludar al árbol que no\l"
	.string "era árbol.$"

CheveRoom_EventScript_Cheve_Text_3:
# 44 "data/maps/CheveRoom/scripts.pory"
	.string "¡Saludos!$"

CheveRoom_EventScript_CuttableTree_Text_0:
# 94 "data/maps/CheveRoom/scripts.pory"
	.string "¿Por qué me estás mirando así?$"

CheveRoom_EventScript_CuttableTree_Text_1:
# 108 "data/maps/CheveRoom/scripts.pory"
	.string "¿Quieres cortarme?\p"
	.string "¡No me lastimes, soy Cheve!$"

CheveRoom_EventScript_CuttableTree_Text_2:
# 123 "data/maps/CheveRoom/scripts.pory"
	.string "¡Ve, Plantita!$"

CheveRoom_EventScript_CuttableTree_Text_3:
# 166 "data/maps/CheveRoom/scripts.pory"
	.string "Caíste redondit{OA}. ¿En serio creíste que\n"
	.string "yo era un árbol?$"

CheveRoom_EventScript_CuttableTree_Text_4:
# 170 "data/maps/CheveRoom/scripts.pory"
	.string "Pero bueno… no esperaba que llegaras\n"
	.string "hasta mi habitación.\p"
	.string "¡Y menos después de derrotar a mi gran\n"
	.string "amigo Javi4315!$"

CheveRoom_EventScript_CuttableTree_Text_5:
# 172 "data/maps/CheveRoom/scripts.pory"
	.string "A él lo respeto mucho, así que… digamos\n"
	.string "que ya me caes bien por eso.$"

CheveRoom_EventScript_CuttableTree_Text_6:
# 176 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que es mi turno de poner a\n"
	.string "prueba tu suerte.$"

CheveRoom_EventScript_CuttableTree_Text_7:
# 183 "data/maps/CheveRoom/scripts.pory"
	.string "Aunque aviso… no soy muy fan de los\n"
	.string "combates largos.\p"
	.string "Prefiero procrastinar… ¡mi acción\n"
	.string "favorita!$"

CheveRoom_EventScript_CuttableTree_Text_8:
# 186 "data/maps/CheveRoom/scripts.pory"
	.string "¡Vamos!$"

CheveRoom_EventScript_CuttableTree_Text_9:
# 191 "data/maps/CheveRoom/scripts.pory"
	.string "Uf… qué paliza.$"

CheveRoom_EventScript_CuttableTree_Text_10:
# 195 "data/maps/CheveRoom/scripts.pory"
	.string "Me dan ganas de postergar mi revancha\n"
	.string "hasta el próximo siglo.\p"
	.string "Pero, eh, no me malinterpretes… ¡fue\n"
	.string "divertido!$"

CheveRoom_EventScript_CuttableTree_Text_11:
# 202 "data/maps/CheveRoom/scripts.pory"
	.string "Supongo que eso tiene este lugar:\n"
	.string "siempre alguien nuevo llega a tu\l"
	.string "habitación, y cuando se va, deja un\l"
	.string "pequeño cuadro más colgado en la pared.\p"
	.string "El mío ya tiene bastantes, pero este\n"
	.string "combate merece uno nuevo.$"

CheveRoom_EventScript_CuttableTree_Text_12:
# 205 "data/maps/CheveRoom/scripts.pory"
	.string "Vamos, sigue adelante. Seguro el\n"
	.string "próximo piso te tiene guardada otra\l"
	.string "sorpresa.$"

CheveRoom_Text_CheveDefeated::
# 234 "data/maps/CheveRoom/scripts.pory"
	.string "¡Muy buen combate! Me recordó a mis\n"
	.string "enfrentamientos con Xavi.$"
