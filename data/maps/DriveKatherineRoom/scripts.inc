DriveKatherineRoom_MapScripts::
# 5 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DriveKatherineRoom_OnLoad
# 6 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DriveKatherineRoom_OnTransition
# 2 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DriveKatherineRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

DriveKatherineRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, DriveKatherineRoom_OnWarp_PlayerTurnNorth
	.2byte 0


DriveKatherineRoom_OnLoad::
# 10 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_OnLoad_2
DriveKatherineRoom_OnLoad_1:
	end

DriveKatherineRoom_OnLoad_2:
# 11 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto DriveKatherineRoom_OnLoad_1


DriveKatherineRoom_OnWarp_PlayerTurnNorth::
# 17 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


DriveKatherineRoom_OnTransition::
# 22 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_DriveKatherine
	end


DriveKatherineRoom_EventScript_Katherine::
# 27 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_EventScript_Katherine_2
# 37 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 38 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 39 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 40 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 41 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HappyWithDelay48
# 42 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 43 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_PlayerWalkInPlace
# 44 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 45 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 46 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 48 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_5, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 49 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_KATHERINE, DIR_SOUTH
# 50 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Katherine_2:
# 28 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 29 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 30 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 31 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 32 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 33 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 34 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end


DriveKatherineRoom_EventScript_PlayerWalkInPlace::
# 55 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 56 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 57 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_PlayerWalkInPlace_3
# 60 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_PlayerWalkInPlace_4
# 63 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_PlayerWalkInPlace_5
# 66 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_PlayerWalkInPlace_6
DriveKatherineRoom_EventScript_PlayerWalkInPlace_1:
	return

DriveKatherineRoom_EventScript_PlayerWalkInPlace_3:
# 58 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_4:
# 61 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_5:
# 64 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_6:
# 67 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1


DriveKatherineRoom_EventScript_Drive::
# 74 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_EventScript_Drive_2
# 84 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 85 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 86 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 87 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_0
# 90 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 91 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 92 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 93 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 94 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 96 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_2
# 101 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 102 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 103 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 104 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 105 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer
# 106 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 10
# 107 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 108 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	special GetPlayerFacingDirection
# 110 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 111 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_Drive_6
# 114 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_Drive_7
# 117 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_Drive_8
# 120 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_Drive_9
DriveKatherineRoom_EventScript_Drive_4:
# 124 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 125 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 40
# 126 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 127 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_JumpDown
# 128 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 129 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 130 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 131 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 132 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_5, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 133 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 134 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_7
# 135 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 136 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 137 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 138 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_6, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 139 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 140 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 141 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_SurpriseWithDelay48
# 142 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_7, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 144 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 145 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_EAST
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_8, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 147 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
# 148 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 149 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_8
# 150 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_9, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 152 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 153 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 154 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_10, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 155 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceDown
# 156 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 157 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_11, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 158 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 159 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_12, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 160 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_9
# 162 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_9
# 163 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 164 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 165 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_DriveKatherineBattle
# 166 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 167 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattleEmote
# 168 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattleEmote
# 169 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 170 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 171 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattleJump
# 172 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattleJump
# 173 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 174 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 175 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkDown
# 176 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_13, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 177 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 178 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 179 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_14, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 180 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 181 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 182 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 15
# 183 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkDown
# 184 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_15, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 185 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 186 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 187 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 188 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 189 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 190 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 191 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 192 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 193 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 194 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_16, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 195 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 196 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 197 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_8
# 198 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 199 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_17, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 200 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceLeft
# 201 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 202 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 203 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 204 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_10
# 205 "data/maps/DriveKatherineRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 206 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Drive_2:
# 75 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 76 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 77 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 78 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 79 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 80 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 81 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Drive_6:
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_3
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_7:
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_4
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_8:
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_5
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_9:
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_6
	goto DriveKatherineRoom_EventScript_Drive_4


# 210 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattleEmote:
# 211 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_surprise
	step_end

# 214 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattleJump:
# 215 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
# 216 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_up
# 217 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 218 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 218 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 218 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
	step_end

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer::
# 222 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 223 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 224 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3
# 227 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4
# 230 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5
# 233 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6
DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1:
	return

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3:
# 225 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4:
# 228 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5:
# 231 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6:
# 234 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1


DriveKatherineRoom_EventScript_DriveKatherineBattle::
# 241 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DriveKatherineRoom_EventScript_DriveKatherineBattle_2
# 244 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_DRIVE
# 245 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 246 "data/maps/DriveKatherineRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 247 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_KATHERINE
# 248 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 250 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_5
# 257 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_11
# 260 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_Text_KatherineDefeated
DriveKatherineRoom_EventScript_DriveKatherineBattle_1:
# 264 "data/maps/DriveKatherineRoom/scripts.pory"
	special HealPlayerParty
	return

DriveKatherineRoom_EventScript_DriveKatherineBattle_2:
# 242 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_5:
# 251 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_8
# 254 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_8:
# 252 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_11:
# 258 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1


# 87 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_0:
# 88 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_double_exclamation_mark
# 89 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
	step_end

# 93 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_1:
# 93 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 97 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_2:
# 98 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
# 99 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 100 "data/maps/DriveKatherineRoom/scripts.pory"
	face_player
	step_end

# 112 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_3:
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
	step_end

# 115 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_4:
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
	step_end

# 118 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_5:
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
	step_end

# 121 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_6:
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
	step_end

# 134 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_7:
# 134 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_smile
	step_end

# 149 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_8:
# 149 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 149 "data/maps/DriveKatherineRoom/scripts.pory"
	face_left
	step_end

# 161 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_9:
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_versus
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 204 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_10:
# 204 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_up
# 204 "data/maps/DriveKatherineRoom/scripts.pory"
	face_down
	step_end

DriveKatherineRoom_EventScript_Katherine_Text_0:
# 30 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Siempre vuelve quien se siente bien\n"
	.string "recibido.\p"
	.string "Gracias por pasar otra vez.$"

DriveKatherineRoom_EventScript_Katherine_Text_1:
# 33 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Miau revoir!$"

DriveKatherineRoom_EventScript_Katherine_Text_2:
# 39 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Oh, holis. Bienvenid{OA} a esta sala, aquí\n"
	.string "todo está preparado para celebrar.$"

DriveKatherineRoom_EventScript_Katherine_Text_3:
# 42 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¿Así que quieres superar este desafío?$"

DriveKatherineRoom_EventScript_Katherine_Text_4:
# 45 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Perfecto. Estaré encantada de echarte\n"
	.string "una pata… quiero decir, una mano.$"

DriveKatherineRoom_EventScript_Katherine_Text_5:
# 48 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Pero antes, deberías hablar con Drive.\n"
	.string "Tiene su discurso preparado… y créeme,\l"
	.string "está deseando soltarlo.$"

DriveKatherineRoom_EventScript_Drive_Text_0:
# 77 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Ah, {ELLA} invitad{OA} de honor regresa!$"

DriveKatherineRoom_EventScript_Drive_Text_1:
# 80 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Si vienes por otro duelo, me temo que la\n"
	.string "cocina ya cerró.$"

DriveKatherineRoom_EventScript_Drive_Text_2:
# 101 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Ah, por fin un comensal con hambre de\n"
	.string "fiesta!$"

DriveKatherineRoom_EventScript_Drive_Text_3:
# 104 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Ven, tenemos un lugar especial para ti.$"

DriveKatherineRoom_EventScript_Drive_Text_4:
# 129 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Bienvenid{OA} al gran restaurante de la\n"
	.string "celebración.\p"
	.string "Aquí servimos emociones recién hechas\n"
	.string "y recuerdos al fuego lento.\p"
	.string "Mi nombre es Drive, y hoy seré tu chef y\n"
	.string "maître del banquete.\p"
	.string "Hoy, ¡el plato principal eres tú!$"

DriveKatherineRoom_EventScript_Drive_Text_5:
# 132 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Cada plato cuenta una historia, y cada\n"
	.string "batalla… ¡una receta para el alma!$"

DriveKatherineRoom_EventScript_Drive_Text_6:
# 138 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Empezaremos con un entrante de\n"
	.string "entusiasmo, un toque de curiosidad y\l"
	.string "una pizca de locura.$"

DriveKatherineRoom_EventScript_Drive_Text_7:
# 142 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Después, el plato principal: un duelo\n"
	.string "doble delicioso.$"

DriveKatherineRoom_EventScript_Drive_Text_8:
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Katherine, ¿listos los ingredientes?$"

DriveKatherineRoom_EventScript_Drive_Text_9:
# 150 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Todos cortados y preparados, Drive.$"

DriveKatherineRoom_EventScript_Drive_Text_10:
# 154 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Pero recuerda: no todo se trata de\n"
	.string "ganar. Lo importante es moverse con\l"
	.string "gracia… y caer siempre de pie.\p"
	.string "Vamos a darle la bienvenida como se\n"
	.string "merece.$"

DriveKatherineRoom_EventScript_Drive_Text_11:
# 157 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Entonces, que empiece el banquete!$"

DriveKatherineRoom_EventScript_Drive_Text_12:
# 159 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Dos chefs, un banquete, un nuevo\n"
	.string "desafío.\p"
	.string "¡A tus hornallas, entrenador{A}!$"

DriveKatherineRoom_EventScript_Drive_Text_13:
# 176 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Un sabor intenso, equilibrado…\n"
	.string "inolvidable…$"

DriveKatherineRoom_EventScript_Drive_Text_14:
# 179 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Si cada celebración tuviera este toque,\n"
	.string "el mundo sería un festín eterno.$"

DriveKatherineRoom_EventScript_Drive_Text_15:
# 184 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Fue una danza perfecta. En cada paso\n"
	.string "se sentía la alegría de este día, casi\l"
	.string "como si la sala estuviera ronroneando\l"
	.string "de emoción.\p"
	.string "Gracias por compartirlo con nosotros.$"

DriveKatherineRoom_EventScript_Drive_Text_16:
# 194 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Brindo por eso!$"

DriveKatherineRoom_EventScript_Drive_Text_17:
# 199 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Has superado esta sala con elegancia.\n"
	.string "Sigue disfrutando de la celebración… y\l"
	.string "hasta que nos volvamos a ver…$"

DriveKatherineRoom_Text_DriveDefeated::
# 268 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Eso sí que fue un festín!$"

DriveKatherineRoom_Text_KatherineDefeated::
# 272 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Suave, armonioso… me ha encantado.$"
