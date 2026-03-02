DriveKatherineRoom_MapScripts::
# 5 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, DriveKatherineRoom_OnLoad
# 2 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, DriveKatherineRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

DriveKatherineRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/DriveKatherineRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, DriveKatherineRoom_OnWarp_PlayerTurnNorth
	.2byte 0


DriveKatherineRoom_OnLoad::
# 9 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_OnLoad_2
DriveKatherineRoom_OnLoad_1:
	end

DriveKatherineRoom_OnLoad_2:
# 10 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto DriveKatherineRoom_OnLoad_1


DriveKatherineRoom_OnWarp_PlayerTurnNorth::
# 16 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


DriveKatherineRoom_EventScript_Katherine::
# 21 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_EventScript_Katherine_2
# 31 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 32 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 33 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 34 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HappyWithDelay48
# 36 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 37 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_PlayerWalkInPlace
# 38 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 39 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 40 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 41 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 42 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_5, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 43 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_KATHERINE, DIR_SOUTH
# 44 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Katherine_2:
# 22 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 23 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 24 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 25 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 26 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 27 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 28 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end


DriveKatherineRoom_EventScript_PlayerWalkInPlace::
# 49 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 50 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 51 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_PlayerWalkInPlace_3
# 54 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_PlayerWalkInPlace_4
# 57 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_PlayerWalkInPlace_5
# 60 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_PlayerWalkInPlace_6
DriveKatherineRoom_EventScript_PlayerWalkInPlace_1:
	return

DriveKatherineRoom_EventScript_PlayerWalkInPlace_3:
# 52 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_4:
# 55 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_5:
# 58 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1

DriveKatherineRoom_EventScript_PlayerWalkInPlace_6:
# 61 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_PlayerWalkInPlace_1


DriveKatherineRoom_EventScript_Drive::
# 68 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE, DriveKatherineRoom_EventScript_Drive_2
# 78 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 79 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 80 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 81 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_0
# 84 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 85 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 86 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 88 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 90 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_2
# 95 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 96 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 97 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 98 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 99 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer
# 100 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 10
# 101 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 102 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 103 "data/maps/DriveKatherineRoom/scripts.pory"
	special GetPlayerFacingDirection
# 104 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 105 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_Drive_6
# 108 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_Drive_7
# 111 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_Drive_8
# 114 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_Drive_9
DriveKatherineRoom_EventScript_Drive_4:
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 119 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 40
# 120 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_JumpDown
# 122 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 123 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 124 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 125 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 126 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_5, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 127 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 128 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_7
# 129 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 130 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 131 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 132 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_6, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 133 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 134 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 135 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_SurpriseWithDelay48
# 136 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_7, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 137 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 138 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 139 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_EAST
# 140 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_8, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 141 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
# 142 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_8
# 144 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_9, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 145 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 147 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 148 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_10, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 149 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceDown
# 150 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_11, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 152 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 153 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_12, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 154 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 155 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_9
# 156 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_9
# 157 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 158 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 159 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_DriveKatherineBattle
# 160 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattleEmote
# 162 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattleEmote
# 163 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 164 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 165 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattleJump
# 166 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattleJump
# 167 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 168 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 169 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkDown
# 170 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_13, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 171 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 172 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 173 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_14, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 174 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 175 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 176 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 15
# 177 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkDown
# 178 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_15, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 179 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 180 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 181 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 182 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 183 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 184 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 185 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 186 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 187 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 188 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_16, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 189 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 190 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 191 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_8
# 192 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 193 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_17, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 194 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceLeft
# 195 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 196 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 197 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 198 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_10
# 199 "data/maps/DriveKatherineRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 200 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Drive_2:
# 69 "data/maps/DriveKatherineRoom/scripts.pory"
	lock
# 70 "data/maps/DriveKatherineRoom/scripts.pory"
	faceplayer
# 71 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 72 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 74 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 75 "data/maps/DriveKatherineRoom/scripts.pory"
	release
	end

DriveKatherineRoom_EventScript_Drive_6:
# 106 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_3
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_7:
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_4
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_8:
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_5
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_9:
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_6
	goto DriveKatherineRoom_EventScript_Drive_4


# 204 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattleEmote:
# 205 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_surprise
	step_end

# 208 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattleJump:
# 209 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
# 210 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_up
# 211 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 212 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 212 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 212 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
	step_end

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer::
# 216 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 217 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 218 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3
# 221 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4
# 224 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5
# 227 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6
DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1:
	return

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3:
# 219 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4:
# 222 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5:
# 225 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6:
# 228 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1


DriveKatherineRoom_EventScript_DriveKatherineBattle::
# 235 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DriveKatherineRoom_EventScript_DriveKatherineBattle_2
# 238 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_DRIVE
# 239 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 240 "data/maps/DriveKatherineRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 241 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_KATHERINE
# 242 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 244 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_5
# 251 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_11
# 254 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_Text_KatherineDefeated
DriveKatherineRoom_EventScript_DriveKatherineBattle_1:
# 258 "data/maps/DriveKatherineRoom/scripts.pory"
	special HealPlayerParty
	return

DriveKatherineRoom_EventScript_DriveKatherineBattle_2:
# 236 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_5:
# 245 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_8
# 248 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_8:
# 246 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_11:
# 252 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1


# 81 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_0:
# 82 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_double_exclamation_mark
# 83 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
	step_end

# 87 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_1:
# 87 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 91 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_2:
# 92 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
# 93 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 94 "data/maps/DriveKatherineRoom/scripts.pory"
	face_player
	step_end

# 106 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_3:
# 106 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 106 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
	step_end

# 109 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_4:
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
	step_end

# 112 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_5:
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
	step_end

# 115 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_6:
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
	step_end

# 128 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_7:
# 128 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_smile
	step_end

# 143 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_8:
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	face_left
	step_end

# 155 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_9:
# 155 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_versus
# 155 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 198 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_10:
# 198 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_up
# 198 "data/maps/DriveKatherineRoom/scripts.pory"
	face_down
	step_end

DriveKatherineRoom_EventScript_Katherine_Text_0:
# 24 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Siempre vuelve quien se siente bien\n"
	.string "recibido.\p"
	.string "Gracias por pasar otra vez.$"

DriveKatherineRoom_EventScript_Katherine_Text_1:
# 27 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Miau revoir!$"

DriveKatherineRoom_EventScript_Katherine_Text_2:
# 33 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Oh, holis. Bienvenid{OA} a esta sala, aquí\n"
	.string "todo está preparado para celebrar.$"

DriveKatherineRoom_EventScript_Katherine_Text_3:
# 36 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¿Así que quieres superar este desafío?$"

DriveKatherineRoom_EventScript_Katherine_Text_4:
# 39 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Perfecto. Estaré encantada de echarte\n"
	.string "una pata… quiero decir, una mano.$"

DriveKatherineRoom_EventScript_Katherine_Text_5:
# 42 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Pero antes, deberías hablar con Drive.\n"
	.string "Tiene su discurso preparado… y créeme,\l"
	.string "está deseando soltarlo.$"

DriveKatherineRoom_EventScript_Drive_Text_0:
# 71 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Ah, {ELLA} invitad{OA} de honor regresa!$"

DriveKatherineRoom_EventScript_Drive_Text_1:
# 74 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Si vienes por otro duelo, me temo que la\n"
	.string "cocina ya cerró.$"

DriveKatherineRoom_EventScript_Drive_Text_2:
# 95 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Ah, por fin un comensal con hambre de\n"
	.string "fiesta!$"

DriveKatherineRoom_EventScript_Drive_Text_3:
# 98 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Ven, tenemos un lugar especial para ti.$"

DriveKatherineRoom_EventScript_Drive_Text_4:
# 123 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Bienvenid{OA} al gran restaurante de la\n"
	.string "celebración.\p"
	.string "Aquí servimos emociones recién hechas\n"
	.string "y recuerdos al fuego lento.\p"
	.string "Mi nombre es Drive, y hoy seré tu chef y\n"
	.string "maître del banquete.\p"
	.string "Hoy, ¡el plato principal eres tú!$"

DriveKatherineRoom_EventScript_Drive_Text_5:
# 126 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Cada plato cuenta una historia, y cada\n"
	.string "batalla… ¡una receta para el alma!$"

DriveKatherineRoom_EventScript_Drive_Text_6:
# 132 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Empezaremos con un entrante de\n"
	.string "entusiasmo, un toque de curiosidad y\l"
	.string "una pizca de locura.$"

DriveKatherineRoom_EventScript_Drive_Text_7:
# 136 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Después, el plato principal: un duelo\n"
	.string "doble delicioso.$"

DriveKatherineRoom_EventScript_Drive_Text_8:
# 140 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Katherine, ¿listos los ingredientes?$"

DriveKatherineRoom_EventScript_Drive_Text_9:
# 144 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Todos cortados y preparados, Drive.$"

DriveKatherineRoom_EventScript_Drive_Text_10:
# 148 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Pero recuerda: no todo se trata de\n"
	.string "ganar. Lo importante es moverse con\l"
	.string "gracia… y caer siempre de pie.\p"
	.string "Vamos a darle la bienvenida como se\n"
	.string "merece.$"

DriveKatherineRoom_EventScript_Drive_Text_11:
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Entonces, que empiece el banquete!$"

DriveKatherineRoom_EventScript_Drive_Text_12:
# 153 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Dos chefs, un banquete, un nuevo\n"
	.string "desafío.\p"
	.string "¡A tus hornallas, entrenador{A}!$"

DriveKatherineRoom_EventScript_Drive_Text_13:
# 170 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Un sabor intenso, equilibrado…\n"
	.string "inolvidable…$"

DriveKatherineRoom_EventScript_Drive_Text_14:
# 173 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Si cada celebración tuviera este toque,\n"
	.string "el mundo sería un festín eterno.$"

DriveKatherineRoom_EventScript_Drive_Text_15:
# 178 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Fue una danza perfecta. En cada paso\n"
	.string "se sentía la alegría de este día, casi\l"
	.string "como si la sala estuviera ronroneando\l"
	.string "de emoción.\p"
	.string "Gracias por compartirlo con nosotros.$"

DriveKatherineRoom_EventScript_Drive_Text_16:
# 188 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Brindo por eso!$"

DriveKatherineRoom_EventScript_Drive_Text_17:
# 193 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Has superado esta sala con elegancia.\n"
	.string "Sigue disfrutando de la celebración… y\l"
	.string "hasta que nos volvamos a ver…$"

DriveKatherineRoom_Text_DriveDefeated::
# 262 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "¡Eso sí que fue un festín!$"

DriveKatherineRoom_Text_KatherineDefeated::
# 266 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Suave, armonioso… me ha encantado.$"
