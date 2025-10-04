JackJohnsonRoom_MapScripts::
# 5 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JackJohnsonRoom_OnTransition
# 2 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script_2 VAR_JACK_JOHNSON_ROOM_STATE, 0, JackJohnsonRoom_OnFrame
	.2byte 0


JackJohnsonRoom_OnTransition::
# 9 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL1
# 10 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL2
# 11 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL3
# 12 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_POKEBALL4
	end


JackJohnsonRoom_OnFrame::
# 17 "data/maps/JackJohnsonRoom/scripts.pory"
	special SpawnCameraObject
# 18 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 19 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 20 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 21 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkInPlaceUp
# 22 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 23 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkInPlaceDown
# 24 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkInPlaceDown
# 25 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkInPlaceDown
# 26 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkInPlaceDown
# 27 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 29 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 30 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 31 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 32 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkLeftLockFacingDirection
# 33 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkRightLockFacingDirection
# 34 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkLeftLockFacingDirection
# 35 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkRightLockFacingDirection
# 36 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 37 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 10
# 38 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkDownLockFacingDirection
# 39 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkDownLockFacingDirection
# 40 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkUpLockFacingDirection
# 41 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkUpLockFacingDirection
# 42 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 44 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 45 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 46 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 47 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 48 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_JumpDownLockFacingDirection
# 50 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpUpLockFacingDirection
# 51 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpInPlaceLeft
# 52 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_JumpInPlaceRight
# 53 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC3
# 54 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpDownFaceLeft
# 55 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpDownFaceRight
# 56 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 57 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 58 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 59 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 60 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 61 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 62 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 63 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 64 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 65 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 66 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 67 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 68 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 69 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 70 "data/maps/JackJohnsonRoom/scripts.pory"
	release
# 71 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 72 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_0
# 77 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 78 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 79 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 80 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE
# 81 "data/maps/JackJohnsonRoom/scripts.pory"
	lock
# 82 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_FaceLeft
# 83 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkDown
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_1
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_2
# 86 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_JumpRoundNpc1
# 89 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_JumpRoundNpc3
# 90 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_JumpRoundNpc4
# 91 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_JumpRoundNpc2
# 92 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 94 "data/maps/JackJohnsonRoom/scripts.pory"
	special RemoveCameraObject
# 95 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_JACK_JOHNSON_ROOM_STATE, 1
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	release
	end


# 100 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc1:
# 101 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 101 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 101 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 102 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 103 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 103 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 103 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 104 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 104 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 105 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 105 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 105 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
	step_end

# 108 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc3:
# 109 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 110 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 111 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 113 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 113 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 113 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 114 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_left
# 115 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 115 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 116 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 117 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 117 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
	step_end

# 120 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc4:
# 121 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 122 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 124 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 125 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 126 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 126 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 126 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 127 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 127 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 128 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 129 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 130 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 130 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 131 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 132 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
	step_end

# 135 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc2:
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 137 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 139 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 139 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 140 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 141 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 141 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 142 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 142 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 143 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 144 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 146 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 147 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_up
	step_end

# 151 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc1And3:
# 152 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right
# 153 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 154 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 155 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 156 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 157 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
	step_end

# 160 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc2And4:
# 161 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 162 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 163 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 164 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 165 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 166 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 169 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SecondCombinationNpcs:
# 170 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 170 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 171 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 171 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 172 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 172 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 173 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 173 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 174 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down
	step_end

# 72 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_0:
# 73 "data/maps/JackJohnsonRoom/scripts.pory"
	emote_happy
# 74 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up
# 75 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 75 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

# 84 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_1:
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 85 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_2:
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

JackJohnsonRoom_OnFrame_Text_0:
# 20 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Desde el principio! ¡Quiero que cada\n"
	.string "movimiento sea perfecto!$"

JackJohnsonRoom_OnFrame_Text_1:
# 29 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Empecemos!$"

JackJohnsonRoom_OnFrame_Text_2:
# 43 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Uno, dos… salto ya!$"

JackJohnsonRoom_OnFrame_Text_3:
# 56 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Giro! ¡Más energía, que parezca un\n"
	.string "huracán!$"

JackJohnsonRoom_OnFrame_Text_4:
# 77 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Perfecto! ¡Lo hemos clavado!$"

JackJohnsonRoom_OnFrame_Text_5:
# 80 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Formación!$"

JackJohnsonRoom_OnFrame_Text_6:
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Ahora!$"
