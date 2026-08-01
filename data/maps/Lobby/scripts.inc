Lobby_MapScripts::
# 5 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Lobby_OnTransition
# 6 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 7 "data/maps/Lobby/scripts.pory"
	map_script_2 VAR_EXPLAIN_NEW_CHALLENGE_MODES_LOBBY, 1, Lobby_OnFrame_ExplainNewChallengeModes
	.2byte 0


Lobby_OnFrame_ExplainNewChallengeModes::
# 12 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Lobby_OnFrame_ExplainNewChallengeModes_Movement_0
# 13 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 14 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 15 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 16 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_HeartWithDelay48
# 17 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 18 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 19 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_JumpInPlaceRight
# 20 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 21 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_JumpInPlaceRight
# 22 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 23 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 24 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 25 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 26 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_JumpInPlaceRight
# 27 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 28 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 29 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 30 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 31 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_WEST
# 32 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 33 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_ThinkingWithDelay48
# 34 "data/maps/Lobby/scripts.pory"
	delay 40
# 35 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 36 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 37 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 38 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_HappyWithDelay48
# 39 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Lobby_OnFrame_ExplainNewChallengeModes_Movement_1
# 40 "data/maps/Lobby/scripts.pory"
	setvar VAR_EXPLAIN_NEW_CHALLENGE_MODES_LOBBY, 2
	end


Lobby_OnTransition::
# 45 "data/maps/Lobby/scripts.pory"
	setrespawn HEAL_LOCATION_LOBBY
	end


Lobby_EventScript_StartChallenge::
# 50 "data/maps/Lobby/scripts.pory"
	lock
# 51 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_FacePlayer
# 52 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 53 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_DoubleExclamationMarkWithDelay48
# 54 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 55 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 56 "data/maps/Lobby/scripts.pory"
	delay 20
# 57 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 58 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_StartChallenge_2
Lobby_EventScript_StartChallenge_1:
# 71 "data/maps/Lobby/scripts.pory"
	setspeaker SP_NAME_COPE
# 72 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_StartChallenge_Text_3
# 73 "data/maps/Lobby/scripts.pory"
	waitmessage
# 74 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_4, 0
# 75 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_5, 1
# 76 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_6, 2
# 77 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 3
# 78 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 4
# 79 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, 0, 0, DYN_MULTICHOICE_CB_NONE
# 80 "data/maps/Lobby/scripts.pory"
	closemessage
# 81 "data/maps/Lobby/scripts.pory"
	delay 10
# 82 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 83 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_5
# 88 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_6
# 94 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_StartChallenge_7
# 100 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_StartChallenge_8
# 111 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	return

Lobby_EventScript_StartChallenge_2:
# 59 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_1, MSGBOX_YESNO, speaker = SP_NAME_COPE
# 60 "data/maps/Lobby/scripts.pory"
	closemessage
# 61 "data/maps/Lobby/scripts.pory"
	delay 10
# 62 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_10
# 68 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_5:
# 84 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 85 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 86 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 87 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_6:
# 89 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE
# 90 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 91 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 92 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 93 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_7:
# 95 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE
# 96 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 97 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 98 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 99 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_8:
# 101 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM
# 102 "data/maps/Lobby/scripts.pory"
	special Special_StartWahRandomTeam
# 103 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Lobby_EventScript_StartChallenge_14
Lobby_EventScript_StartChallenge_13:
# 107 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 108 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 109 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_10:
# 63 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 64 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 65 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 66 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_14:
# 104 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_NONE
# 105 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_RandomTeamFailed
	goto Lobby_EventScript_StartChallenge_13


Lobby_StartChallenge_CancelledChallenge::
# 116 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 117 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_Surprise
# 118 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 119 "data/maps/Lobby/scripts.pory"
	delay 60
# 120 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 121 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 122 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 123 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_RandomTeamFailed::
# 128 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_RandomTeamFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 129 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 130 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 131 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_EnterOmegaRoom::
# 136 "data/maps/Lobby/scripts.pory"
	special SetWahChallengeInitialAchievementFlags
# 137 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_Kecleon_ResetFlags
# 138 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 139 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 140 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 141 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 142 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 143 "data/maps/Lobby/scripts.pory"
	waitstate
# 144 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 150 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 151 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 152 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 153 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 154 "data/maps/Lobby/scripts.pory"
	delay 5
# 155 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 156 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 157 "data/maps/Lobby/scripts.pory"
	delay 5
# 158 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 159 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 165 "data/maps/Lobby/scripts.pory"
	lock
# 166 "data/maps/Lobby/scripts.pory"
	faceplayer
# 167 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 168 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 177 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 179 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 180 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 169 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 170 "data/maps/Lobby/scripts.pory"
	waitstate
# 171 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 174 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 172 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 191 "data/maps/Lobby/scripts.pory"
	lock
# 192 "data/maps/Lobby/scripts.pory"
	faceplayer
# 193 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 194 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 203 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 205 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 206 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 195 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 196 "data/maps/Lobby/scripts.pory"
	waitstate
# 197 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 200 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 198 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_BufferVictoryWordFromCountVar::
# 216 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_2
# 219 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferVictoryWordFromCountVar_1:
# 221 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_6
# 224 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2
Lobby_EventScript_BufferVictoryWordFromCountVar_5:
	return

Lobby_EventScript_BufferVictoryWordFromCountVar_2:
# 217 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_1

Lobby_EventScript_BufferVictoryWordFromCountVar_6:
# 222 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_5


Lobby_EventScript_BufferTimeWordFromCountVar::
# 230 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_2
# 233 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferTimeWordFromCountVar_1:
# 235 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_6
# 238 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_1
Lobby_EventScript_BufferTimeWordFromCountVar_5:
	return

Lobby_EventScript_BufferTimeWordFromCountVar_2:
# 231 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_1

Lobby_EventScript_BufferTimeWordFromCountVar_6:
# 236 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_5


Lobby_EventScript_ChallengeHistorian::
# 244 "data/maps/Lobby/scripts.pory"
	lock
# 245 "data/maps/Lobby/scripts.pory"
	faceplayer
# 247 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_0, MSGBOX_AUTOCLOSE
# 248 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 249 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_ChallengeHistorian_2
# 260 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 261 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 262 "data/maps/Lobby/scripts.pory"
	faceplayer
# 263 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT
# 264 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 265 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_2
# 266 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT
# 267 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 268 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_3
# 269 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT
# 270 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 271 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_4
# 272 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_RANDOM_COMPLETION_COUNT
# 273 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 274 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_5
# 275 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_COMPLETION_COUNT
# 276 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferTimeWordFromCountVar
# 277 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_6
# 278 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 5
	goto_if_gt Lobby_EventScript_ChallengeHistorian_5
# 284 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_8, MSGBOX_AUTOCLOSE
# 285 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 286 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
Lobby_EventScript_ChallengeHistorian_4:
# 288 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 289 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_2:
# 250 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 251 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 252 "data/maps/Lobby/scripts.pory"
	faceplayer
# 253 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_1, MSGBOX_AUTOCLOSE
# 254 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 255 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 256 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 257 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_5:
# 279 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_7, MSGBOX_AUTOCLOSE
# 280 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 281 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
	goto Lobby_EventScript_ChallengeHistorian_4


Lobby_EventScript_Shop::
# 295 "data/maps/Lobby/scripts.pory"
	lock
# 296 "data/maps/Lobby/scripts.pory"
	faceplayer
# 297 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Shop_4
Lobby_EventScript_Shop_3:
# 302 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_1
# 303 "data/maps/Lobby/scripts.pory"
	waitmessage
Lobby_EventScript_Shop_1:
# 305 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 306 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Shop_2:
# 298 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 299 "data/maps/Lobby/scripts.pory"
	waitmessage
# 300 "data/maps/Lobby/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto Lobby_EventScript_Shop_1

Lobby_EventScript_Shop_4:
# 297 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, Lobby_EventScript_Shop_2
	goto Lobby_EventScript_Shop_3


Lobby_EventScript_Roxas_IntroFirstBattle::
# 311 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 312 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 315 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 317 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 318 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 319 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 320 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 321 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 322 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 323 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 324 "data/maps/Lobby/scripts.pory"
	delay 20
# 325 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 326 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 327 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 328 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 329 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 330 "data/maps/Lobby/scripts.pory"
	delay 20
# 331 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 313 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 336 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 337 "data/maps/Lobby/scripts.pory"
	closemessage
# 338 "data/maps/Lobby/scripts.pory"
	delay 20
# 339 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 343 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 344 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 340 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 350 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 351 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 354 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 358 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 352 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 355 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 365 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 366 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 367 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 368 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 369 "data/maps/Lobby/scripts.pory"
	waitstate
# 370 "data/maps/Lobby/scripts.pory"
	lock
# 371 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 377 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 372 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 373 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 374 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 382 "data/maps/Lobby/scripts.pory"
	lock
# 383 "data/maps/Lobby/scripts.pory"
	faceplayer
# 384 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 435 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 436 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 437 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 438 "data/maps/Lobby/scripts.pory"
	delay 20
# 439 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 440 "data/maps/Lobby/scripts.pory"
	delay 20
# 441 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 442 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 443 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 444 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 445 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 446 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 447 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 448 "data/maps/Lobby/scripts.pory"
	lock
# 449 "data/maps/Lobby/scripts.pory"
	delay 20
# 450 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 451 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 452 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 453 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 385 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 386 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 387 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 390 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 392 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 393 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 394 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 398 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 403 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 404 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 407 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 408 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 409 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 410 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 411 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 412 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 413 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 420 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 421 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 424 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 426 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 427 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 428 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 430 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 431 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 432 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 388 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 395 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 396 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 399 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 400 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 414 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 415 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 416 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 417 "data/maps/Lobby/scripts.pory"
	delay 40
# 418 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 422 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 465 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 466 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 467 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 470 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 473 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 476 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 468 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 471 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 474 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 477 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 485 "data/maps/Lobby/scripts.pory"
	lock
# 486 "data/maps/Lobby/scripts.pory"
	faceplayer
# 487 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 488 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 489 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 490 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 494 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 495 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 496 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 501 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 502 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 507 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 508 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 513 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 514 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 519 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 520 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 525 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 526 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 531 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_JARDINO
# 532 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 537 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_OCEADINO
# 538 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 543 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_TYRADINO
# 544 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25:
# 549 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 550 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28:
# 555 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 556 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 561 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MICAEL
# 562 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 567 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MOLIKAI
# 568 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 573 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_DIRAEI
# 574 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 579 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_LUGIA_SHADOW
# 580 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43:
# 585 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47
# 590 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 15
# 591 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 592 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 593 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50
# 598 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 599 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54
# 603 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55
# 607 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56
# 611 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57
# 615 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58
# 619 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59
# 623 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60
# 627 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61
# 631 "data/maps/Lobby/scripts.pory"
	case 8, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62
# 635 "data/maps/Lobby/scripts.pory"
	case 9, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63
# 639 "data/maps/Lobby/scripts.pory"
	case 10, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64
# 643 "data/maps/Lobby/scripts.pory"
	case 11, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65
# 647 "data/maps/Lobby/scripts.pory"
	case 12, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66
# 651 "data/maps/Lobby/scripts.pory"
	case 13, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67
# 655 "data/maps/Lobby/scripts.pory"
	case 14, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52:
# 660 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 497 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 498 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 499 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 503 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 504 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 505 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 509 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 510 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 511 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 515 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 516 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 517 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 521 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 522 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 523 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 527 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 528 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 529 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 533 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_JARDINO
# 534 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 535 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 539 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OCEADINO
# 540 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 541 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 545 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYRADINO
# 546 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 8
# 547 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 551 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 552 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 9
# 553 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32:
# 557 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 558 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 10
# 559 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 563 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MICAEL
# 564 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 11
# 565 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 569 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLIKAI
# 570 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 12
# 571 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41:
# 575 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIRAEI
# 576 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 13
# 577 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44:
# 581 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_SHADOW
# 582 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 14
# 583 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47:
# 586 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 587 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50:
# 594 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 595 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54:
# 600 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 601 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 602 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55:
# 604 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 605 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 606 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56:
# 608 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 609 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 610 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57:
# 612 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 613 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 614 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58:
# 616 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 617 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 618 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59:
# 620 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 621 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 622 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60:
# 624 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_JARDINO, 10, 3
# 625 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_JARDINO
# 626 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61:
# 628 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_OCEADINO, 10, 3
# 629 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_OCEADINO
# 630 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62:
# 632 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_TYRADINO, 10, 3
# 633 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRADINO
# 634 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63:
# 636 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 637 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 638 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64:
# 640 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 641 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 642 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65:
# 644 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MICAEL, 10, 3
# 645 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MICAEL
# 646 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66:
# 648 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MOLIKAI, 10, 3
# 649 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLIKAI
# 650 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67:
# 652 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_DIRAEI, 10, 3
# 653 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIRAEI
# 654 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68:
# 656 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_LUGIA_SHADOW, 10, 3
# 657 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA_SHADOW
# 658 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52


Lobby_EventScript_ShowFakemonDexInfo::
# 664 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 665 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 666 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 667 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 670 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 672 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 673 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 674 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 675 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 678 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 679 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 680 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 683 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 684 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 685 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 688 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 689 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 690 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 691 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 692 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 668 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 676 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 681 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 686 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 697 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Cope::
# 702 "data/maps/Lobby/scripts.pory"
	lock
# 703 "data/maps/Lobby/scripts.pory"
	faceplayer
# 704 "data/maps/Lobby/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 705 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_Cope_2
# 714 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 715 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 716 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Lobby_EventScript_Cope_Movement_0
# 717 "data/maps/Lobby/scripts.pory"
	waitse
# 718 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 719 "data/maps/Lobby/scripts.pory"
	delay 10
# 720 "data/maps/Lobby/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 721 "data/maps/Lobby/scripts.pory"
	closemessage
# 722 "data/maps/Lobby/scripts.pory"
	delay 20
# 723 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
Lobby_EventScript_Cope_1:
# 725 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Cope_2:
# 707 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 708 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 709 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 710 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
	goto Lobby_EventScript_Cope_1


Lobby_EventScript_QREventInfoKid::
# 730 "data/maps/Lobby/scripts.pory"
	lock
# 731 "data/maps/Lobby/scripts.pory"
	faceplayer
# 732 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 733 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 734 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 735 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire::
# 740 "data/maps/Lobby/scripts.pory"
	lock
# 741 "data/maps/Lobby/scripts.pory"
	faceplayer
# 742 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_0, MSGBOX_AUTOCLOSE
# 743 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 744 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_2
# 751 "data/maps/Lobby/scripts.pory"
	delay 20
# 752 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 753 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 754 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 755 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_5
# 762 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_6
# 765 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_2:
# 745 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 746 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Surprise
# 747 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_1, MSGBOX_AUTOCLOSE
# 748 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_5:
# 756 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_2, MSGBOX_YESNO
# 757 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_8
# 760 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_6:
# 763 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_8:
# 758 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	return


Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft::
# 770 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0, MSGBOX_AUTOCLOSE
# 771 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions::
# 776 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0, MSGBOX_AUTOCLOSE
# 777 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater::
# 782 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0, MSGBOX_AUTOCLOSE
# 783 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NextQuestion::
# 788 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 789 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 790 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 791 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2
# 797 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3
# 799 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_NONE_THIS_TALK, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4
# 804 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2:
# 792 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0, MSGBOX_YESNO
# 793 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7
Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6:
# 796 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3:
# 798 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4:
# 800 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1, MSGBOX_AUTOCLOSE
# 801 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7:
# 794 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6


Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion::
# 809 "data/maps/Lobby/scripts.pory"
	addvar VAR_BETA_MON_QUESTIONNAIRE_ASK_COUNT, 1
# 810 "data/maps/Lobby/scripts.pory"
	switch VAR_0x8004
# 811 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_GOROCHU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3
# 814 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_TAABAN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4
# 817 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_BOMUSHIKAA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5
# 820 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_MADAAMU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6
# 823 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_AKUERIA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7
# 826 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_LATIKEN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8
Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1:
# 830 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion
	return

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3:
# 812 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Gorochu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4:
# 815 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Taaban
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5:
# 818 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6:
# 821 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Madaamu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7:
# 824 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Akueria
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8:
# 827 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Latiken
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1


Lobby_EventScript_BetaMonQuestionnaire_Gorochu::
# 834 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0
# 835 "data/maps/Lobby/scripts.pory"
	waitmessage
# 836 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1, 0
# 837 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2, 1
# 838 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3, 2
# 839 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4, 3
# 840 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 841 "data/maps/Lobby/scripts.pory"
	closemessage
# 842 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2
# 847 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2:
# 843 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_GOROCHU
# 844 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5, MSGBOX_AUTOCLOSE
# 845 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1


Lobby_EventScript_BetaMonQuestionnaire_Taaban::
# 853 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0
# 854 "data/maps/Lobby/scripts.pory"
	waitmessage
# 855 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1, 0
# 856 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2, 1
# 857 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3, 2
# 858 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4, 3
# 859 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 860 "data/maps/Lobby/scripts.pory"
	closemessage
# 861 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Taaban_2
# 866 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Taaban_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Taaban_2:
# 862 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_TAABAN
# 863 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5, MSGBOX_AUTOCLOSE
# 864 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Taaban_1


Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa::
# 872 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0
# 873 "data/maps/Lobby/scripts.pory"
	waitmessage
# 874 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1, 0
# 875 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2, 1
# 876 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3, 2
# 877 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4, 3
# 878 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 879 "data/maps/Lobby/scripts.pory"
	closemessage
# 880 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2
# 885 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2:
# 881 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_BOMUSHIKAA
# 882 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5, MSGBOX_AUTOCLOSE
# 883 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1


Lobby_EventScript_BetaMonQuestionnaire_Madaamu::
# 891 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0
# 892 "data/maps/Lobby/scripts.pory"
	waitmessage
# 893 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1, 0
# 894 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2, 1
# 895 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3, 2
# 896 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4, 3
# 897 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 898 "data/maps/Lobby/scripts.pory"
	closemessage
# 899 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2
# 904 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2:
# 900 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_MADAAMU
# 901 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5, MSGBOX_AUTOCLOSE
# 902 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1


Lobby_EventScript_BetaMonQuestionnaire_Akueria::
# 910 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0
# 911 "data/maps/Lobby/scripts.pory"
	waitmessage
# 912 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1, 0
# 913 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2, 1
# 914 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3, 2
# 915 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4, 3
# 916 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 917 "data/maps/Lobby/scripts.pory"
	closemessage
# 918 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Akueria_2
# 923 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Akueria_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Akueria_2:
# 919 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_AKUERIA
# 920 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5, MSGBOX_AUTOCLOSE
# 921 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Akueria_1


Lobby_EventScript_BetaMonQuestionnaire_Latiken::
# 929 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0, MSGBOX_AUTOCLOSE
# 930 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
# 931 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 932 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 933 "data/maps/Lobby/scripts.pory"
	waitmessage
# 934 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2, 0
# 935 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3, 1
# 936 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4, 2
# 937 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5, 3
# 938 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 939 "data/maps/Lobby/scripts.pory"
	closemessage
# 940 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_2
# 945 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6, MSGBOX_AUTOCLOSE
# 946 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
# 947 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 948 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 949 "data/maps/Lobby/scripts.pory"
	waitmessage
# 950 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7, 0
# 951 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8, 1
# 952 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9, 2
# 953 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10, 3
# 954 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 955 "data/maps/Lobby/scripts.pory"
	closemessage
# 956 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_5
# 961 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11, MSGBOX_AUTOCLOSE
# 962 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_BLAZIKEN, CRY_MODE_NORMAL
# 963 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 964 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 965 "data/maps/Lobby/scripts.pory"
	waitmessage
# 966 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12, 0
# 967 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13, 1
# 968 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14, 2
# 969 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15, 3
# 970 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 971 "data/maps/Lobby/scripts.pory"
	closemessage
# 972 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Latiken_8
# 977 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Latiken_7:
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_2:
# 941 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_5:
# 957 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_8:
# 973 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_LATIKEN
# 974 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16, MSGBOX_AUTOCLOSE
# 975 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Latiken_7


Lobby_EventScript_Pokebox::
# 987 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_C, 8
# 988 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_D, 3
# 989 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_OFF
# 990 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_ON
# 991 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


Lobby_EventScript_Turbo::
# 996 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Turbo_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Notes::
# 1001 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Notes_Text_0, MSGBOX_SIGN
	end


# 12 "data/maps/Lobby/scripts.pory"
Lobby_OnFrame_ExplainNewChallengeModes_Movement_0:
# 12 "data/maps/Lobby/scripts.pory"
	walk_down
# 12 "data/maps/Lobby/scripts.pory"
	walk_down
# 12 "data/maps/Lobby/scripts.pory"
	walk_down
# 12 "data/maps/Lobby/scripts.pory"
	walk_down
# 12 "data/maps/Lobby/scripts.pory"
	face_right
	step_end

# 39 "data/maps/Lobby/scripts.pory"
Lobby_OnFrame_ExplainNewChallengeModes_Movement_1:
# 39 "data/maps/Lobby/scripts.pory"
	walk_up
# 39 "data/maps/Lobby/scripts.pory"
	walk_up
# 39 "data/maps/Lobby/scripts.pory"
	walk_up
# 39 "data/maps/Lobby/scripts.pory"
	walk_up
# 39 "data/maps/Lobby/scripts.pory"
	face_down
	step_end

# 318 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 318 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 318 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 320 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 320 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 320 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 320 "data/maps/Lobby/scripts.pory"
	face_player
# 320 "data/maps/Lobby/scripts.pory"
	delay_16
# 320 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 716 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Cope_Movement_0:
# 716 "data/maps/Lobby/scripts.pory"
	emote_question_mark
	step_end

Lobby_OnFrame_ExplainNewChallengeModes_Text_0:
# 14 "data/maps/Lobby/scripts.pory"
	.string "¡Increíble, {PLAYER}! Has superado el\n"
	.string "desafío por completo.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_1:
# 17 "data/maps/Lobby/scripts.pory"
	.string "¡Pero no creas que esto ha terminado!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_2:
# 22 "data/maps/Lobby/scripts.pory"
	.string "¡Todavía tienes muchas cosas por\n"
	.string "hacer!\p"
	.string "A partir de ahora has desbloqueado\n"
	.string "nuevas formas de jugar el desafío.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_3:
# 24 "data/maps/Lobby/scripts.pory"
	.string "¡Ahora puedes combatir en modalidad\n"
	.string "{COLOR BLUE}batallas dobles{COLOR DARK_GRAY}!\p"
	.string "Cada combate será en formato doble:\n"
	.string "dos Pokémon en campo, ¡el doble de caos!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_4:
# 27 "data/maps/Lobby/scripts.pory"
	.string "¿Y si quieres pensar un poco más?\n"
	.string "Entonces las {COLOR RED}batallas inversas{COLOR DARK_GRAY} son\l"
	.string "para ti!\p"
	.string "¡La tabla de tipos está al revés! Lo\n"
	.string "resistente será débil, y viceversa.\p"
	.string "¡Ya no podrás combatir en modo\n"
	.string "automático!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_5:
# 30 "data/maps/Lobby/scripts.pory"
	.string "¡Y eso no es todo!\p"
	.string "Sin importar la modalidad que elijas,\n"
	.string "cada administrador tendrá dos equipos\l"
	.string "posibles para utilizar.\p"
	.string "Su {COLOR BLUE}equipo principal{COLOR DARK_GRAY}, que ya conoces, o\n"
	.string "un {COLOR RED}equipo alternativo{COLOR DARK_GRAY}.\p"
	.string "Nunca sabrás cuál te podrá tocar, lo\n"
	.string "que significa que cada recorrido podría\l"
	.string "sentirse completamente diferente.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_6:
# 36 "data/maps/Lobby/scripts.pory"
	.string "¡Casi lo olvidaba!\p"
	.string "También puedes explorar la {COLOR BLUE}Zona\n"
	.string "creativa{COLOR DARK_GRAY}.\p"
	.string "¡Varios de los creadores del desafío\n"
	.string "están ansiosos por enfrentarte!\p"
	.string "Y si buscas completar todo al 100%, aún\n"
	.string "quedan muchos {COLOR BLUE}logros{COLOR DARK_GRAY} por conseguir.\p"
	.string "Con todo lo que te queda por hacer,\n"
	.string "¡seguro te vas a divertir mucho!$"

Lobby_EventScript_StartChallenge_Text_0:
# 54 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 59 "data/maps/Lobby/scripts.pory"
	.string "¿Así que ya estás list{OA} para intentar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_2:
# 65 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Adelante, ¡te deseo mucha\n"
	.string "suerte y sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_3:
# 72 "data/maps/Lobby/scripts.pory"
	.string "¿En qué modo quieres afrontar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_4:
# 74 "data/maps/Lobby/scripts.pory"
	.string "Estándar$"

Lobby_EventScript_StartChallenge_Text_5:
# 75 "data/maps/Lobby/scripts.pory"
	.string "Batallas dobles$"

Lobby_EventScript_StartChallenge_Text_6:
# 76 "data/maps/Lobby/scripts.pory"
	.string "Batallas inversas$"

Lobby_EventScript_StartChallenge_Text_7:
# 77 "data/maps/Lobby/scripts.pory"
	.string "Equipo aleatorio$"

Lobby_EventScript_StartChallenge_Text_8:
# 78 "data/maps/Lobby/scripts.pory"
	.string "Salir$"

Lobby_EventScript_StartChallenge_Text_9:
# 92 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas dobles.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_10:
# 98 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas inversas.\p"
	.string "Las efectividades de tipo se invierten:\n"
	.string "lo que normalmente es súper efectivo\l"
	.string "será poco efectivo y viceversa.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_11:
# 108 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Afrontarás el desafío con\n"
	.string "un equipo elegido completamente al\l"
	.string "azar.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_StartChallenge_CancelledChallenge_Text_0:
# 118 "data/maps/Lobby/scripts.pory"
	.string "¿Así que no te sientes list{OA}?$"

Lobby_StartChallenge_CancelledChallenge_Text_1:
# 120 "data/maps/Lobby/scripts.pory"
	.string "Recuerda que las personas de la sala de\n"
	.string "espera pueden ayudar en tu\l"
	.string "preparación.$"

Lobby_StartChallenge_RandomTeamFailed_Text_0:
# 128 "data/maps/Lobby/scripts.pory"
	.string "No pude preparar seis Pokémon\n"
	.string "distintos para el desafío.\p"
	.string "Comprueba que llevas un equipo\n"
	.string "completo e inténtalo de nuevo.$"

Lobby_EventScript_TeamSelector_Text_0:
# 167 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que tu equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 172 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 193 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy la encargada de la selección\n"
	.string "de dificultad del desafío.\p"
	.string "No parece que la dificultad actual sea\n"
	.string "la adecuada para ti.\p"
	.string "¿Quieres cambiar el nivel de dificultad?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 198 "data/maps/Lobby/scripts.pory"
	.string "¡Listo! La dificultad ha sido actualizada.\n¡Buena suerte con el desafío!$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0:
# 217 "data/maps/Lobby/scripts.pory"
	.string "0$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1:
# 222 "data/maps/Lobby/scripts.pory"
	.string "victoria$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2:
# 224 "data/maps/Lobby/scripts.pory"
	.string "victorias$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_0:
# 236 "data/maps/Lobby/scripts.pory"
	.string "vez$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_1:
# 238 "data/maps/Lobby/scripts.pory"
	.string "veces$"

Lobby_EventScript_ChallengeHistorian_Text_0:
# 247 "data/maps/Lobby/scripts.pory"
	.string "¡Ey, {PLAYER}!\p"
	.string "No trabajo aquí ni nada, pero me\n"
	.string "encanta sacar estadísticas.\p"
	.string "Me quedo en la sala de espera\n"
	.string "observando a todos los que entran y lo\l"
	.string "anoto todo.$"

Lobby_EventScript_ChallengeHistorian_Text_1:
# 253 "data/maps/Lobby/scripts.pory"
	.string "Veo que aún no has completado el\n"
	.string "desafío ni una vez.\p"
	.string "Todavía no te has ganado un lugar en\n"
	.string "mis notas.$"

Lobby_EventScript_ChallengeHistorian_Text_2:
# 265 "data/maps/Lobby/scripts.pory"
	.string "Según mi cuaderno, en modo estándar\n"
	.string "llevas {STR_VAR_1} {STR_VAR_2}.\p"
	.string "¡Nada mal, de verdad!$"

Lobby_EventScript_ChallengeHistorian_Text_3:
# 268 "data/maps/Lobby/scripts.pory"
	.string "En batallas dobles tienes\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ahí se nota quién piensa dos turnos por\n"
	.string "adelantado.$"

Lobby_EventScript_ChallengeHistorian_Text_4:
# 271 "data/maps/Lobby/scripts.pory"
	.string "Y en batallas invertidas sumas\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ese modo le da vuelta la cabeza a\n"
	.string "cualquiera.$"

Lobby_EventScript_ChallengeHistorian_Text_5:
# 274 "data/maps/Lobby/scripts.pory"
	.string "Con equipos aleatorios llevas\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "¡Ahí nunca sabes qué compañeros te van\n"
	.string "a tocar!$"

Lobby_EventScript_ChallengeHistorian_Text_6:
# 277 "data/maps/Lobby/scripts.pory"
	.string "En total, has completado el desafío\n"
	.string "{STR_VAR_1} {STR_VAR_2}.$"

Lobby_EventScript_ChallengeHistorian_Text_7:
# 279 "data/maps/Lobby/scripts.pory"
	.string "¡Si sigues así, voy a tener que comprar\n"
	.string "otro cuaderno para registrar tus\l"
	.string "números!$"

Lobby_EventScript_ChallengeHistorian_Text_8:
# 284 "data/maps/Lobby/scripts.pory"
	.string "Aún no son tantas victorias, pero sigue\n"
	.string "así.$"

Lobby_EventScript_Shop_Text_0:
# 298 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¡Hemos ampliado el catálogo!\p"
	.string "Ahora también puedes comprar objetos\n"
	.string "de combate.\p"
	.string "¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 302 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 313 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 315 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 321 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 325 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la última\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 328 "data/maps/Lobby/scripts.pory"
	.string "Terminé mi investigación en el\n"
	.string "Archipiélago Suzuka… es una historia\l"
	.string "larga, tendrías que haberlo visto…\p"
	.string "No sabes lo que fue… Pero logré dar con\n"
	.string "el rastro de esa fuerza que estaba\l"
	.string "causando tantos males y estoy listo\l"
	.string "para probar si realmente este bicho es\l"
	.string "tan legendario como dicen las crónicas\l"
	.string "del archipiélago.$"

Lobby_EventScript_Roxas_IntroRematch_Text_0:
# 336 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tú de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 352 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: elige\n"
	.string "a tres de tus bichos.\p"
	.string "Yo voy a salir con mi legendario, así que\n"
	.string "más te vale elegir bien.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 358 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate para\n"
	.string "enfrentar a mi legendario.$"

Lobby_EventScript_Roxas_Text_0:
# 407 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 409 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 416 "data/maps/Lobby/scripts.pory"
	.string "¡Nooo, me estás cargando! Ni con la\n"
	.string "fuerza de este Pokémon oscuro te pude\l"
	.string "ganar.\p"
	.string "Ahora me cierra por qué a vos te dejaron\n"
	.string "pasar a las salas y a mí me sacaron de\l"
	.string "un voleo.\p"
	.string "Tenés algo distinto, pasta de campeón,\n"
	.string "no es solo fuerza bruta.\p"
	.string "La verdad, me cerraste la boca. Bien\n"
	.string "ganado.$"

Lobby_EventScript_Roxas_Text_3:
# 422 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 424 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 428 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 435 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 439 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 447 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras, loco!$"

Lobby_EventScript_Roxas_Text_9:
# 450 "data/maps/Lobby/scripts.pory"
	.string "Pero bueno, tampoco me voy a quedar acá\n"
	.string "llorando.\p"
	.string "Estoy tras un barco que desapareció al\n"
	.string "oeste de las Islas Naranja, el\l"
	.string "archipiélago Suzuka.\p"
	.string "El Team Rocket anda haciendo de las\n"
	.string "suyas y dicen que hay un bicho oscuro\l"
	.string "con ojos rojos que es un peligro…\l"
	.string "aterrador…\p"
	.string "Habrá que investigar y ver qué onda…$"

Lobby_EventScript_Roxas_Text_10:
# 452 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 487 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 586 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 591 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 594 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 665 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokédex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 668 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 670 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 672 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 676 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 689 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 692 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 697 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_EventScript_Cope_Text_0:
# 707 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Estás list{OA} para intentar el desafío?$"

Lobby_EventScript_Cope_Text_1:
# 710 "data/maps/Lobby/scripts.pory"
	.string "¿Y ya has podido encontrar a Tile?\p"
	.string "Debe encontrarse en alguna sala... ¡Es\n"
	.string "tan escurridizo!\p"
	.string "Recuerda que puedes usar el Detector\n"
	.string "Devon para encontrarlo.\p"
	.string "¡Seguro cada vez que lo encuentres te\n"
	.string "dará un premio!$"

Lobby_EventScript_Cope_Text_2:
# 714 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Has visto a Tile?$"

Lobby_EventScript_Cope_Text_3:
# 718 "data/maps/Lobby/scripts.pory"
	.string "¿Cómo? ¿No sabes quién es?\n"
	.string "Es mi famoso Kecleon.\p"
	.string "Lo he perdido de vista y no sé por dónde\n"
	.string "se ha metido...\p"
	.string "Además, ¡me ha robado el kit de objetos\n"
	.string "que le doy a los entrenadores del\l"
	.string "desafío!\p"
	.string "Hazme un favor y búscale por mí.\n"
	.string "Toma, llévate esto.$"

Lobby_EventScript_Cope_Text_4:
# 723 "data/maps/Lobby/scripts.pory"
	.string "Con el Detector Devon podrás ver dónde\n"
	.string "se esconde Tile.\p"
	.string "Le he agregado una nueva\n"
	.string "característica que permite saber si\l"
	.string "hay un Pokémon invisible cerca.\p"
	.string "¡Espero lo encuentres!$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 732 "data/maps/Lobby/scripts.pory"
	.string "Un chico de la zona creativa te da un\n"
	.string "regalo por completar un evento\l"
	.string "especial.\p"
	.string "Es imposible adivinar lo que hay que\n"
	.string "hacer sin mirar el vídeo.\p"
	.string "¡Incluso tuve que cambiar de orden a\n"
	.string "dos de los Pokémon de mi equipo!\p"
	.string "Eso sí, me gustó el premio por completar\n"
	.string "el evento, ¡valió la pena!$"

Lobby_EventScript_BetaMonQuestionnaire_Text_0:
# 742 "data/maps/Lobby/scripts.pory"
	.string "¡Buenas! Soy el maestro de los\n"
	.string "cuestionarios.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_1:
# 747 "data/maps/Lobby/scripts.pory"
	.string "Así que aún no has completado el\n"
	.string "desafío.\l"
	.string "...\l"
	.string "...\p"
	.string "Cuando lo superes, vuelve y te haré un\n"
	.string "cuestionario especial.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_2:
# 756 "data/maps/Lobby/scripts.pory"
	.string "Te haré una pregunta por cada vez que\n"
	.string "hayas completado el desafío.\p"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "¿Quieres que te haga una pregunta?$"

Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0:
# 770 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "Completa el desafío otra vez y vuelve\n"
	.string "por aquí.$"

Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0:
# 776 "data/maps/Lobby/scripts.pory"
	.string "¡Ya has respondido todas mis\n"
	.string "preguntas! ¿Qué te parecen los Pokémon\l"
	.string "que has conseguido?$"

Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0:
# 782 "data/maps/Lobby/scripts.pory"
	.string "De acuerdo. Puedes volver cuando\n"
	.string "quieras.$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0:
# 792 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "¿Quieres seguir respondiendo?$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1:
# 800 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "Por ahora no tengo más preguntas\n"
	.string "distintas para hacerte.\p"
	.string "Vuelve a hablarme en otro momento.$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0:
# 834 "data/maps/Lobby/scripts.pory"
	.string "¿Qué Pokémon es naranja, tiene una cola\n"
	.string "larga y a todo el mundo le encanta el\l"
	.string "que evoluciona en él?$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1:
# 836 "data/maps/Lobby/scripts.pory"
	.string "Raichu$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2:
# 837 "data/maps/Lobby/scripts.pory"
	.string "Arcanine$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3:
# 838 "data/maps/Lobby/scripts.pory"
	.string "Floatzel$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4:
# 839 "data/maps/Lobby/scripts.pory"
	.string "Simisear$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5:
# 844 "data/maps/Lobby/scripts.pory"
	.string "Pues con este Pokémon te encontrarás.$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0:
# 853 "data/maps/Lobby/scripts.pory"
	.string "Mi amigo siempre va con su Bro detrás.\p"
	.string "¿Qué Pokémon es mi amigo?$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1:
# 855 "data/maps/Lobby/scripts.pory"
	.string "Slowking$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2:
# 856 "data/maps/Lobby/scripts.pory"
	.string "Slowbro$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3:
# 857 "data/maps/Lobby/scripts.pory"
	.string "Slowpoke$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4:
# 858 "data/maps/Lobby/scripts.pory"
	.string "Shellder$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5:
# 863 "data/maps/Lobby/scripts.pory"
	.string "Pues con su Bro te irás.$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0:
# 872 "data/maps/Lobby/scripts.pory"
	.string "Blanco como la nieve y una carita mona.\p"
	.string "¿Quién es?$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1:
# 874 "data/maps/Lobby/scripts.pory"
	.string "Whismur$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2:
# 875 "data/maps/Lobby/scripts.pory"
	.string "Aipom$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3:
# 876 "data/maps/Lobby/scripts.pory"
	.string "Dewgong$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4:
# 877 "data/maps/Lobby/scripts.pory"
	.string "Snorunt$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5:
# 882 "data/maps/Lobby/scripts.pory"
	.string "¡Pues este se le parece!$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0:
# 891 "data/maps/Lobby/scripts.pory"
	.string "El Capitán Puerro blande su espada en\n"
	.string "el bosque.\p"
	.string "¿Quién es realmente el Capitán Puerro?$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1:
# 893 "data/maps/Lobby/scripts.pory"
	.string "Kartana$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2:
# 894 "data/maps/Lobby/scripts.pory"
	.string "Gallade$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3:
# 895 "data/maps/Lobby/scripts.pory"
	.string "Farfetch'd$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4:
# 896 "data/maps/Lobby/scripts.pory"
	.string "Scyther$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5:
# 901 "data/maps/Lobby/scripts.pory"
	.string "Exacto. Ese filo también despertó la\n"
	.string "curiosidad de Madaamu.$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0:
# 910 "data/maps/Lobby/scripts.pory"
	.string "Adivina, adivinanza.\p"
	.string "¿Qué serpiente azul tiene una evolución\n"
	.string "naranja?$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1:
# 912 "data/maps/Lobby/scripts.pory"
	.string "Gyarados$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2:
# 913 "data/maps/Lobby/scripts.pory"
	.string "Dratini$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3:
# 914 "data/maps/Lobby/scripts.pory"
	.string "Milotic$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4:
# 915 "data/maps/Lobby/scripts.pory"
	.string "Dunsparce$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5:
# 920 "data/maps/Lobby/scripts.pory"
	.string "Pues su primo te ha visto luchar y te\n"
	.string "espera.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0:
# 929 "data/maps/Lobby/scripts.pory"
	.string "Adivina, adivinanza.\p"
	.string "¿Qué Pokémon hace este grito?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1:
# 932 "data/maps/Lobby/scripts.pory"
	.string "¿Quién fue?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2:
# 934 "data/maps/Lobby/scripts.pory"
	.string "Jirachi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3:
# 935 "data/maps/Lobby/scripts.pory"
	.string "Celebi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4:
# 936 "data/maps/Lobby/scripts.pory"
	.string "Mew$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5:
# 937 "data/maps/Lobby/scripts.pory"
	.string "Deoxys$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6:
# 945 "data/maps/Lobby/scripts.pory"
	.string "Oh, correcto. Ahora mismo intenta\n"
	.string "adivinar este.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7:
# 950 "data/maps/Lobby/scripts.pory"
	.string "Latios$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8:
# 951 "data/maps/Lobby/scripts.pory"
	.string "Latias$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9:
# 952 "data/maps/Lobby/scripts.pory"
	.string "Altaria$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10:
# 953 "data/maps/Lobby/scripts.pory"
	.string "Flygon$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11:
# 961 "data/maps/Lobby/scripts.pory"
	.string "Oh, volviste a acertar. Ahora este.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12:
# 966 "data/maps/Lobby/scripts.pory"
	.string "Blaziken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13:
# 967 "data/maps/Lobby/scripts.pory"
	.string "Combusken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14:
# 968 "data/maps/Lobby/scripts.pory"
	.string "Infernape$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15:
# 969 "data/maps/Lobby/scripts.pory"
	.string "Lucario$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16:
# 974 "data/maps/Lobby/scripts.pory"
	.string "Increíble, acertaste otra vez. Es\n"
	.string "impresionante.\p"
	.string "Ten esto.$"

Lobby_EventScript_Turbo_Text_0:
# 996 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que existe un modo turbo para\n"
	.string "vivir la aventura a toda velocidad?\p"
	.string "Desde el menú de opciones puedes\n"
	.string "configurar tu velocidad de texto, de\l"
	.string "caminar, ¡y un turbo para los combates!\p"
	.string "¿Te animas a probarlo?$"

Lobby_EventScript_Notes_Text_0:
# 1001 "data/maps/Lobby/scripts.pory"
	.string "Parecen apuntes llenos de\n"
	.string "estadísticas y observaciones.\p"
	.string "Algunas páginas están tan gastadas\n"
	.string "que cuesta leerlas.$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 185 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_DifficultySelector_Cancelled::
# 210 "data/maps/Lobby/scripts.pory"
	.string "¡Entendido! Si cambias de opinión,\n"
	.string "estaré por aquí.$"

Lobby_Text_Roxas_PlayerCancelled::
# 460 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_Text_FailedToUnlock::
# 982 "data/maps/Lobby/scripts.pory"
	.string "Oh, ¡fallaste!$"
