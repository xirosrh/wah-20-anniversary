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
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_0
# 90 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 91 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 92 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 93 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 94 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 95 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_2
# 99 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 100 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 101 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 102 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer
# 103 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 10
# 104 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 105 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 106 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 107 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 108 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_Drive_6
# 111 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_Drive_7
# 114 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_Drive_8
# 117 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_Drive_9
DriveKatherineRoom_EventScript_Drive_4:
# 121 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 122 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 40
# 123 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 124 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_JumpDown
# 125 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 126 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 127 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 128 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 129 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_5, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 130 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 131 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_7
# 132 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 133 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 134 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 135 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_6, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 136 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 137 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_SurpriseWithDelay48
# 139 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_7, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 140 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 141 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 142 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_EAST
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_8, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 144 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
# 145 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_8
# 147 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_9, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 148 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 150 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_10, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 152 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceDown
# 153 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_DRIVEKATHERINEROOM_DRIVE, DIR_SOUTH
# 154 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_11, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 155 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 156 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_12, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 157 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 158 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_9
# 159 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_9
# 160 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 161 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 162 "data/maps/DriveKatherineRoom/scripts.pory"
	call DriveKatherineRoom_EventScript_DriveKatherineBattle
# 163 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 164 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattleEmote
# 165 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattleEmote
# 166 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 167 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 168 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_Movement_SurpriseAfterBattleJump
# 169 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovement LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_Movement_SurpriseAfterBattleJump
# 170 "data/maps/DriveKatherineRoom/scripts.pory"
	waitmovement 0
# 171 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 172 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkDown
# 173 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_13, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 174 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
# 175 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 176 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_14, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 177 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 178 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_HappyWithDelay48
# 179 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 15
# 180 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkDown
# 181 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_15, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 182 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_PIN
# 183 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_HeartWithDelay48
# 184 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 185 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 186 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 187 "data/maps/DriveKatherineRoom/scripts.pory"
	waitse
# 188 "data/maps/DriveKatherineRoom/scripts.pory"
	playse SE_LEDGE
# 189 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, DriveKatherineRoom_EventScript_Drive_Movement_1
# 190 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_16, MSGBOX_AUTOCLOSE, SP_NAME_DRIVE
# 191 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 30
# 192 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_8
# 193 "data/maps/DriveKatherineRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_EAST
# 194 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Drive_Text_17, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 195 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, Common_Movement_WalkInPlaceLeft
# 196 "data/maps/DriveKatherineRoom/scripts.pory"
	delay 20
# 197 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Katherine_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_KATHERINE
# 198 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 199 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_KATHERINE, DriveKatherineRoom_EventScript_Drive_Movement_10
# 200 "data/maps/DriveKatherineRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE
# 201 "data/maps/DriveKatherineRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 202 "data/maps/DriveKatherineRoom/scripts.pory"
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
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_3
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_7:
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_4
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_8:
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_5
	goto DriveKatherineRoom_EventScript_Drive_4

DriveKatherineRoom_EventScript_Drive_9:
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, DriveKatherineRoom_EventScript_Drive_Movement_6
	goto DriveKatherineRoom_EventScript_Drive_4


# 206 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattleEmote:
# 207 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_surprise
	step_end

# 210 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_Movement_SurpriseAfterBattleJump:
# 211 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
# 212 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_up
# 213 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 214 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 214 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
# 214 "data/maps/DriveKatherineRoom/scripts.pory"
	delay_16
	step_end

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer::
# 218 "data/maps/DriveKatherineRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 219 "data/maps/DriveKatherineRoom/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_NORTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3
# 223 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_SOUTH, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4
# 226 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_WEST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5
# 229 "data/maps/DriveKatherineRoom/scripts.pory"
	case DIR_EAST, DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6
DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1:
	return

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_3:
# 221 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceDown
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_4:
# 224 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceUp
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_5:
# 227 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceRight
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1

DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_6:
# 230 "data/maps/DriveKatherineRoom/scripts.pory"
	applymovementandwait LOCALID_DRIVEKATHERINEROOM_DRIVE, Common_Movement_WalkInPlaceLeft
	goto DriveKatherineRoom_EventScript_WalkInPlaceDriveFacingPlayer_1


DriveKatherineRoom_EventScript_DriveKatherineBattle::
# 237 "data/maps/DriveKatherineRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, DriveKatherineRoom_EventScript_DriveKatherineBattle_2
# 240 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_DRIVE
# 241 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 242 "data/maps/DriveKatherineRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 243 "data/maps/DriveKatherineRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_KATHERINE
# 244 "data/maps/DriveKatherineRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 246 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_5
# 253 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_11
# 256 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_Text_KatherineDefeated
DriveKatherineRoom_EventScript_DriveKatherineBattle_1:
	return

DriveKatherineRoom_EventScript_DriveKatherineBattle_2:
# 238 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_5:
# 247 "data/maps/DriveKatherineRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DriveKatherineRoom_EventScript_DriveKatherineBattle_8
# 250 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_ALTERNATIVE, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_8:
# 248 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_MAIN, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1

DriveKatherineRoom_EventScript_DriveKatherineBattle_11:
# 254 "data/maps/DriveKatherineRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_DRIVE_ALTERNATIVE, DriveKatherineRoom_Text_DriveDefeated, TRAINER_WAH_ADMIN_KATHERINE_MAIN, DriveKatherineRoom_Text_KatherineDefeated
	goto DriveKatherineRoom_EventScript_DriveKatherineBattle_1


DriveKatherineRoom_EventScript_Bottles::
# 272 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Bottles_Text_0, MSGBOX_SIGN
	end


DriveKatherineRoom_EventScript_Dispenser::
# 277 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Dispenser_Text_0, MSGBOX_SIGN
	end


DriveKatherineRoom_EventScript_Trash::
# 282 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Trash_Text_0, MSGBOX_SIGN
	end


DriveKatherineRoom_EventScript_Cabinet::
# 287 "data/maps/DriveKatherineRoom/scripts.pory"
	msgbox DriveKatherineRoom_EventScript_Cabinet_Text_0, MSGBOX_SIGN
	end


# 87 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_0:
# 88 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_double_exclamation_mark
# 89 "data/maps/DriveKatherineRoom/scripts.pory"
	lock_facing_direction
	step_end

# 92 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_1:
# 92 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 95 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_2:
# 96 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
# 97 "data/maps/DriveKatherineRoom/scripts.pory"
	unlock_facing_direction
# 98 "data/maps/DriveKatherineRoom/scripts.pory"
	face_player
	step_end

# 109 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_3:
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 109 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
	step_end

# 112 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_4:
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 112 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
	step_end

# 115 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_5:
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 115 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
	step_end

# 118 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_6:
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
# 118 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_right
	step_end

# 131 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_7:
# 131 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_smile
	step_end

# 146 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_8:
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_down
# 146 "data/maps/DriveKatherineRoom/scripts.pory"
	face_left
	step_end

# 158 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_9:
# 158 "data/maps/DriveKatherineRoom/scripts.pory"
	emote_versus
# 158 "data/maps/DriveKatherineRoom/scripts.pory"
	jump_in_place_down
	step_end

# 199 "data/maps/DriveKatherineRoom/scripts.pory"
DriveKatherineRoom_EventScript_Drive_Movement_10:
# 199 "data/maps/DriveKatherineRoom/scripts.pory"
	walk_up
# 199 "data/maps/DriveKatherineRoom/scripts.pory"
	face_down
	step_end

DriveKatherineRoom_EventScript_Katherine_Text_0:
# 30 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Those who feel welcome always come\n"
	.string "back.\p"
	.string "Thanks for stopping by again.$"

DriveKatherineRoom_EventScript_Katherine_Text_1:
# 33 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Meow revoir!$"

DriveKatherineRoom_EventScript_Katherine_Text_2:
# 39 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Oh, hi there. Welcome to this room; here\n"
	.string "everything's set up to celebrate.$"

DriveKatherineRoom_EventScript_Katherine_Text_3:
# 42 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "So you want to beat this challenge?$"

DriveKatherineRoom_EventScript_Katherine_Text_4:
# 45 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Perfect. I'd be delighted to lend you a\n"
	.string "paw… I mean, a hand.$"

DriveKatherineRoom_EventScript_Katherine_Text_5:
# 48 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "But first, you should talk to Drive. He's\n"
	.string "got his speech ready… and believe me,\l"
	.string "he's dying to deliver it.$"

DriveKatherineRoom_EventScript_Drive_Text_0:
# 77 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Ah, the guest of honor returns!$"

DriveKatherineRoom_EventScript_Drive_Text_1:
# 80 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "If you're here for another duel, I'm\n"
	.string "afraid the kitchen is already closed.$"

DriveKatherineRoom_EventScript_Drive_Text_2:
# 99 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Ah, at last a diner with an appetite for\n"
	.string "a party!$"

DriveKatherineRoom_EventScript_Drive_Text_3:
# 101 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Come, we've got a special seat for you.$"

DriveKatherineRoom_EventScript_Drive_Text_4:
# 126 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Welcome to the grand restaurant of the\n"
	.string "celebration.\p"
	.string "Here we serve freshly made emotions\n"
	.string "and memories slow-cooked over low heat.\p"
	.string "My name is Drive, and today I'll be your\n"
	.string "chef and maître d' of the banquet.\p"
	.string "Today, the main course is YOU!$"

DriveKatherineRoom_EventScript_Drive_Text_5:
# 129 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Every dish tells a story, and every\n"
	.string "battle… a recipe for the soul!$"

DriveKatherineRoom_EventScript_Drive_Text_6:
# 135 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "We'll start with an appetizer of\n"
	.string "enthusiasm, a touch of curiosity, and a\l"
	.string "pinch of madness.$"

DriveKatherineRoom_EventScript_Drive_Text_7:
# 139 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Then, the main course: a delicious\n"
	.string "double duel.$"

DriveKatherineRoom_EventScript_Drive_Text_8:
# 143 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Katherine, are the ingredients ready?$"

DriveKatherineRoom_EventScript_Drive_Text_9:
# 147 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "All chopped and prepped, Drive.$"

DriveKatherineRoom_EventScript_Drive_Text_10:
# 151 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "But remember: it's not all about\n"
	.string "winning.\p"
	.string "What matters is moving with grace… and\n"
	.string "always landing on your feet.\p"
	.string "Let's welcome them as they deserve.$"

DriveKatherineRoom_EventScript_Drive_Text_11:
# 154 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Then, let the banquet begin!$"

DriveKatherineRoom_EventScript_Drive_Text_12:
# 156 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Two chefs, one banquet, a new\n"
	.string "challenge.\p"
	.string "To your stoves, Trainer!$"

DriveKatherineRoom_EventScript_Drive_Text_13:
# 173 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "An intense, balanced flavor…\n"
	.string "unforgettable…$"

DriveKatherineRoom_EventScript_Drive_Text_14:
# 176 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "If every celebration had this touch,\n"
	.string "the world would be an eternal feast.$"

DriveKatherineRoom_EventScript_Drive_Text_15:
# 181 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "It was a perfect dance. In every step\n"
	.string "you could feel the joy of this day,\l"
	.string "almost as if the room were purring with\l"
	.string "emotion.\p"
	.string "Thank you for sharing it with us.$"

DriveKatherineRoom_EventScript_Drive_Text_16:
# 190 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "I'll drink to that!$"

DriveKatherineRoom_EventScript_Drive_Text_17:
# 194 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "You've cleared this room with elegance.\n"
	.string "Keep enjoying the celebration… and\l"
	.string "until we meet again…$"

DriveKatherineRoom_EventScript_Bottles_Text_0:
# 272 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Some bottles have names that are\n"
	.string "impossible to pronounce.\p"
	.string "There's one called “Whack a Cola.”$"

DriveKatherineRoom_EventScript_Dispenser_Text_0:
# 277 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "The water from the dispenser is\n"
	.string "incredibly cold.$"

DriveKatherineRoom_EventScript_Trash_Text_0:
# 282 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "The wastebasket gives off a faint smell\n"
	.string "of food.$"

DriveKatherineRoom_EventScript_Cabinet_Text_0:
# 287 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "The cabinet is full of plates, glasses,\n"
	.string "and cups.\p"
	.string "Everything's carefully organized by\n"
	.string "size and type.$"

DriveKatherineRoom_Text_DriveDefeated::
# 263 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Now THAT was a feast!$"

DriveKatherineRoom_Text_KatherineDefeated::
# 267 "data/maps/DriveKatherineRoom/scripts.pory"
	.string "Smooth, harmonious… I loved it.$"
