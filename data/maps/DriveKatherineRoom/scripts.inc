DriveKatherineRoom_MapScripts::
	.byte 0


DriveKatherineRoom_EventScript_Katherine::
# 4 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_EventScript_Katherine_2
# 14 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 15 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 16 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_2, MSGBOX_AUTOCLOSE
# 17 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HappyWithDelay48
# 19 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_3, MSGBOX_AUTOCLOSE
# 20 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_PlayerWalkInPlace
# 21 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 22 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_4
# 23 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 24 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 25 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_5
# 26 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_KATHERINE, DIR_SOUTH
# 27 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Katherine_2:
# 5 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 6 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 7 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_0, MSGBOX_AUTOCLOSE
# 8 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 9 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 10 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE
# 11 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end


DriveKatherineRoom_EventScript_PlayerWalkInPlace::
# 32 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 33 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 34 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_PlayerWalkInPlace_3
# 37 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_PlayerWalkInPlace_4
# 40 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_PlayerWalkInPlace_5
# 43 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_PlayerWalkInPlace_6
DriveKatherineRoom_EventScript_PlayerWalkInPlace_1:
	return

DriveKatherineRoom_EventScript_PlayerWalkInPlace_3:
# 35 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_4:
# 38 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_5:
# 41 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_6:
# 44 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1


DriveKatherineRoom_EventScript_Drive::
# 51 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_EventScript_Drive_2
# 61 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 62 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 63 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 64 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_0
# 69 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_2, MSGBOX_AUTOCLOSE
# 70 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 71 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 72 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_3, MSGBOX_AUTOCLOSE
# 73 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer
# 74 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 10
# 75 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 76 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 77 "data/maps/DriveKatherineRoom/scripts.pory"
	moveobjecttopos LOCALID_PLAYER, 6, 8, DIR_NORTH
# 78 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 79 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 40
# 80 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_JumpDown
# 81 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_4, MSGBOX_AUTOCLOSE
# 82 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 83 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 84 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_5, MSGBOX_AUTOCLOSE
# 85 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 86 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 87 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_6, MSGBOX_AUTOCLOSE
# 88 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 89 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_SurpriseWithDelay48
# 90 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_7, MSGBOX_AUTOCLOSE
# 91 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 92 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 93 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_EAST
# 94 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_8
# 95 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
# 96 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 10
# 97 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_2
# 98 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_9, MSGBOX_AUTOCLOSE
# 99 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 100 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 101 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 102 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_10, MSGBOX_AUTOCLOSE
# 103 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceDown
# 104 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 105 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_11, MSGBOX_AUTOCLOSE
# 106 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 107 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_12, MSGBOX_AUTOCLOSE
# 108 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_3
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_3
# 110 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DriveKatherineRoom_EventScript_Drive_5
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, 14
# 116 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 117 "data/maps/DriveKatherineRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, 15
# 119 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq DriveKatherineRoom_EventScript_Drive_8
# 128 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_Drive_14
# 131 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_EventScript_Drive_Text_13, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_EventScript_Drive_Text_14
DriveKatherineRoom_EventScript_Drive_4:
# 135 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattle
# 136 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattle
# 137 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 138 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 139 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkDown
# 140 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_15, MSGBOX_AUTOCLOSE
# 141 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 142 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_16, MSGBOX_AUTOCLOSE
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 144 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 145 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 15
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkDown
# 147 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_17, MSGBOX_AUTOCLOSE
# 148 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 150 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_4
# 152 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_18, MSGBOX_AUTOCLOSE
# 153 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 154 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 155 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_2
# 156 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 157 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_19
# 158 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceLeft
# 159 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE
# 160 "data/maps/DriveKatherineRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_5
# 162 "data/maps/DriveKatherineRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 163 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Drive_2:
# 52 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 53 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 54 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_0, MSGBOX_AUTOCLOSE
# 55 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 57 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_1, MSGBOX_AUTOCLOSE
# 58 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Drive_5:
# 113 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_EventScript_Drive_Text_13, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_EventScript_Drive_Text_14
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_8:
# 122 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_Drive_11
# 125 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_EventScript_Drive_Text_13, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_EventScript_Drive_Text_14
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_11:
# 123 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_EventScript_Drive_Text_13, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_EventScript_Drive_Text_14
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_14:
# 129 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_EventScript_Drive_Text_13, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_EventScript_Drive_Text_14
	goto DriveKatherineRoom_EventScript_Drive_4


# 167 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattle:
# 168 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_surprise
# 169 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
# 170 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_up
# 171 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 172 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 172 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 172 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
	step_end

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer::
# 176 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 177 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 178 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3
# 181 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4
# 184 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5
# 187 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6
DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1:
	return

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3:
# 179 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4:
# 182 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5:
# 185 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6:
# 188 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1


# 64 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_0:
# 65 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_double_exclamation_mark
# 66 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
# 67 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
# 67 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
# 68 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 86 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_1:
# 86 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_smile
# 86 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 97 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_2:
# 97 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 97 "data/maps/DriveKatherineRoom/scripts.pory"
	face_left
	step_end

# 108 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_3:
# 108 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_versus
# 108 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 151 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_4:
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 161 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_5:
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_up
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	face_down
	step_end

DriveKatherineRoom_EventScript_Katherine_Text_0:
# 7 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Siempre vuelve quien se siente bien\n"
	.string "recibido.\p"
	.string "Gracias por pasar otra vez.$"

DriveKatherineRoom_EventScript_Katherine_Text_1:
# 10 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Miau revoir.$"

DriveKatherineRoom_EventScript_Katherine_Text_2:
# 16 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Oh, hola. Bienvenid{OA} a esta sala, aquí\n"
	.string "todo está preparado para celebrar.$"

DriveKatherineRoom_EventScript_Katherine_Text_3:
# 19 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¿Así que quieres superar este desafío?$"

DriveKatherineRoom_EventScript_Katherine_Text_4:
# 22 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Perfecto, estaré encantada de\n"
	.string "ayudarte.$"

DriveKatherineRoom_EventScript_Katherine_Text_5:
# 25 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Pero antes, debes hablar con Drive.\n"
	.string "Tiene su discurso preparado… y está\l"
	.string "muy entusiasmado.$"

DriveKatherineRoom_EventScript_Drive_Text_0:
# 54 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Ah, {ELLA} invitad{OA} de honor regresa!$"

DriveKatherineRoom_EventScript_Drive_Text_1:
# 57 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Si vienes por otro duelo, me temo que la\n"
	.string "cocina ya cerró.$"

DriveKatherineRoom_EventScript_Drive_Text_2:
# 69 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Ah, por fin un comensal con hambre de\n"
	.string "fiesta!$"

DriveKatherineRoom_EventScript_Drive_Text_3:
# 72 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Ven, tenemos un lugar especial para ti.$"

DriveKatherineRoom_EventScript_Drive_Text_4:
# 81 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Bienvenid{OA} al gran restaurante de la\n"
	.string "celebración.\p"
	.string "Aquí servimos emociones recién hechas\n"
	.string "y recuerdos al fuego lento.\p"
	.string "Mi nombre es Drive, y hoy seré tu chef y\n"
	.string "maître del banquete.\p"
	.string "Hoy, ¡el plato principal eres tú!$"

DriveKatherineRoom_EventScript_Drive_Text_5:
# 84 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Cada plato cuenta una historia, y cada\n"
	.string "batalla… ¡una receta para el alma!$"

DriveKatherineRoom_EventScript_Drive_Text_6:
# 87 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Empezaremos con un entrante de\n"
	.string "entusiasmo, un toque de curiosidad y\l"
	.string "una pizca de locura.$"

DriveKatherineRoom_EventScript_Drive_Text_7:
# 90 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Después, el plato principal: un duelo\n"
	.string "doble delicioso.$"

DriveKatherineRoom_EventScript_Drive_Text_8:
# 94 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Katherine, ¿listos los ingredientes?$"

DriveKatherineRoom_EventScript_Drive_Text_9:
# 98 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Todos cortados y preparados, Drive.$"

DriveKatherineRoom_EventScript_Drive_Text_10:
# 102 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Pero recuerda: no todo se trata de\n"
	.string "ganar, sino de disfrutar el proceso.\p"
	.string "Vamos a darle la bienvenida como se\n"
	.string "merece.$"

DriveKatherineRoom_EventScript_Drive_Text_11:
# 105 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Entonces, que empiece el banquete!$"

DriveKatherineRoom_EventScript_Drive_Text_12:
# 107 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Dos chefs, un banquete, un nuevo\n"
	.string "desafío.\p"
	.string "¡A tus hornallas, entrenador{A}!$"

DriveKatherineRoom_EventScript_Drive_Text_13:
# 113 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Eso sí que fue un festín!$"

DriveKatherineRoom_EventScript_Drive_Text_14:
# 113 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Suave, armonioso… me ha encantado.$"

DriveKatherineRoom_EventScript_Drive_Text_15:
# 140 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Un sabor intenso, equilibrado…\n"
	.string "inolvidable…$"

DriveKatherineRoom_EventScript_Drive_Text_16:
# 142 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Si cada celebración tuviera este toque,\n"
	.string "el mundo sería un festín eterno.$"

DriveKatherineRoom_EventScript_Drive_Text_17:
# 147 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Fue una danza perfecta. En cada paso\n"
	.string "se sentía la alegría de este día.\p"
	.string "Gracias por compartirlo con nosotros.$"

DriveKatherineRoom_EventScript_Drive_Text_18:
# 152 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Brindo por eso!$"

DriveKatherineRoom_EventScript_Drive_Text_19:
# 157 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Has superado esta sala con elegancia.\n"
	.string "Sigue disfrutando de la celebración… y\l"
	.string "hasta que nos volvamos a ver…$"
