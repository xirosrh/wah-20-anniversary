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
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_DoubleExclamationMarkWithDelay48
# 30 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 31 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 32 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 33 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 34 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_WEST
# 35 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 36 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_ThinkingWithDelay48
# 37 "data/maps/Lobby/scripts.pory"
	delay 40
# 38 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 39 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 40 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 41 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_HappyWithDelay48
# 42 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Lobby_OnFrame_ExplainNewChallengeModes_Movement_1
# 43 "data/maps/Lobby/scripts.pory"
	setvar VAR_EXPLAIN_NEW_CHALLENGE_MODES_LOBBY, 2
	end


Lobby_OnTransition::
# 48 "data/maps/Lobby/scripts.pory"
	setrespawn HEAL_LOCATION_LOBBY
	end


Lobby_EventScript_StartChallenge::
# 53 "data/maps/Lobby/scripts.pory"
	lock
# 54 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_FacePlayer
# 55 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 56 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_DoubleExclamationMarkWithDelay48
# 57 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 58 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 59 "data/maps/Lobby/scripts.pory"
	delay 20
# 60 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 61 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_StartChallenge_2
Lobby_EventScript_StartChallenge_1:
# 74 "data/maps/Lobby/scripts.pory"
	setspeaker SP_NAME_COPE
# 75 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_StartChallenge_Text_3
# 76 "data/maps/Lobby/scripts.pory"
	waitmessage
# 77 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_4, 0
# 78 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_5, 1
# 79 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_6, 2
# 80 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 3
# 81 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 4
# 82 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, 0, 0, DYN_MULTICHOICE_CB_NONE
# 83 "data/maps/Lobby/scripts.pory"
	closemessage
# 84 "data/maps/Lobby/scripts.pory"
	delay 10
# 85 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 86 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_5
# 91 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_6
# 97 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_StartChallenge_7
# 103 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_StartChallenge_8
# 114 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	return

Lobby_EventScript_StartChallenge_2:
# 62 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_1, MSGBOX_YESNO, speaker = SP_NAME_COPE
# 63 "data/maps/Lobby/scripts.pory"
	closemessage
# 64 "data/maps/Lobby/scripts.pory"
	delay 10
# 65 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_10
# 71 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_5:
# 87 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 88 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 89 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 90 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_6:
# 92 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE
# 93 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 94 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 95 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 96 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_7:
# 98 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE
# 99 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 100 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 101 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 102 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_8:
# 104 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM
# 105 "data/maps/Lobby/scripts.pory"
	special Special_StartWahRandomTeam
# 106 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq Lobby_EventScript_StartChallenge_14
Lobby_EventScript_StartChallenge_13:
# 110 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 111 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 112 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_10:
# 66 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 67 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 68 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 69 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_14:
# 107 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_NONE
# 108 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_RandomTeamFailed
	goto Lobby_EventScript_StartChallenge_13


Lobby_StartChallenge_CancelledChallenge::
# 119 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 120 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_Surprise
# 121 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 122 "data/maps/Lobby/scripts.pory"
	delay 60
# 123 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 124 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 125 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 126 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_RandomTeamFailed::
# 131 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_RandomTeamFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 132 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 133 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 134 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_EnterOmegaRoom::
# 139 "data/maps/Lobby/scripts.pory"
	special SetWahChallengeInitialAchievementFlags
# 140 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_Kecleon_ResetFlags
# 141 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 142 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 143 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 144 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 145 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 146 "data/maps/Lobby/scripts.pory"
	waitstate
# 147 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 153 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 154 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 155 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 156 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 157 "data/maps/Lobby/scripts.pory"
	delay 5
# 158 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 159 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 160 "data/maps/Lobby/scripts.pory"
	delay 5
# 161 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 162 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 168 "data/maps/Lobby/scripts.pory"
	lock
# 169 "data/maps/Lobby/scripts.pory"
	faceplayer
# 170 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 171 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 180 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 182 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 183 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 172 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 173 "data/maps/Lobby/scripts.pory"
	waitstate
# 174 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 177 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 175 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 194 "data/maps/Lobby/scripts.pory"
	lock
# 195 "data/maps/Lobby/scripts.pory"
	faceplayer
# 196 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 197 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 206 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 208 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 209 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 198 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 199 "data/maps/Lobby/scripts.pory"
	waitstate
# 200 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 203 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 201 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_BufferVictoryWordFromCountVar::
# 219 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_2
# 222 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferVictoryWordFromCountVar_1:
# 224 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_6
# 227 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2
Lobby_EventScript_BufferVictoryWordFromCountVar_5:
	return

Lobby_EventScript_BufferVictoryWordFromCountVar_2:
# 220 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_1

Lobby_EventScript_BufferVictoryWordFromCountVar_6:
# 225 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_5


Lobby_EventScript_BufferTimeWordFromCountVar::
# 233 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_2
# 236 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferTimeWordFromCountVar_1:
# 238 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_6
# 241 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_1
Lobby_EventScript_BufferTimeWordFromCountVar_5:
	return

Lobby_EventScript_BufferTimeWordFromCountVar_2:
# 234 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_1

Lobby_EventScript_BufferTimeWordFromCountVar_6:
# 239 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_5


Lobby_EventScript_ChallengeHistorian::
# 247 "data/maps/Lobby/scripts.pory"
	lock
# 248 "data/maps/Lobby/scripts.pory"
	faceplayer
# 250 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_0, MSGBOX_AUTOCLOSE
# 251 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 252 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_ChallengeHistorian_2
# 263 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 264 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 265 "data/maps/Lobby/scripts.pory"
	faceplayer
# 266 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT
# 267 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 268 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_2
# 269 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT
# 270 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 271 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_3
# 272 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT
# 273 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 274 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_4
# 275 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_RANDOM_COMPLETION_COUNT
# 276 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 277 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_5
# 278 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_COMPLETION_COUNT
# 279 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferTimeWordFromCountVar
# 280 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_6
# 281 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 5
	goto_if_gt Lobby_EventScript_ChallengeHistorian_5
# 287 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_8, MSGBOX_AUTOCLOSE
# 288 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 289 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
Lobby_EventScript_ChallengeHistorian_4:
# 291 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 292 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_2:
# 253 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 254 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 255 "data/maps/Lobby/scripts.pory"
	faceplayer
# 256 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_1, MSGBOX_AUTOCLOSE
# 257 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 258 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 259 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 260 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_5:
# 282 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_7, MSGBOX_AUTOCLOSE
# 283 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 284 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
	goto Lobby_EventScript_ChallengeHistorian_4


Lobby_EventScript_Shop::
# 298 "data/maps/Lobby/scripts.pory"
	lock
# 299 "data/maps/Lobby/scripts.pory"
	faceplayer
# 300 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Shop_4
Lobby_EventScript_Shop_3:
# 305 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_1
# 306 "data/maps/Lobby/scripts.pory"
	waitmessage
Lobby_EventScript_Shop_1:
# 308 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 309 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Shop_2:
# 301 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 302 "data/maps/Lobby/scripts.pory"
	waitmessage
# 303 "data/maps/Lobby/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto Lobby_EventScript_Shop_1

Lobby_EventScript_Shop_4:
# 300 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, Lobby_EventScript_Shop_2
	goto Lobby_EventScript_Shop_3


Lobby_EventScript_Roxas_IntroFirstBattle::
# 314 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 315 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 318 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 320 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 321 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 322 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 323 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 324 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 325 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 326 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 327 "data/maps/Lobby/scripts.pory"
	delay 20
# 328 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 329 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 330 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 331 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 332 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 333 "data/maps/Lobby/scripts.pory"
	delay 20
# 334 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 316 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 339 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 340 "data/maps/Lobby/scripts.pory"
	closemessage
# 341 "data/maps/Lobby/scripts.pory"
	delay 20
# 342 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 346 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 347 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 343 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 353 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 354 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 357 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 361 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 355 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 358 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 368 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 369 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 370 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 371 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 372 "data/maps/Lobby/scripts.pory"
	waitstate
# 373 "data/maps/Lobby/scripts.pory"
	lock
# 374 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 380 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 375 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 376 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 377 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 385 "data/maps/Lobby/scripts.pory"
	lock
# 386 "data/maps/Lobby/scripts.pory"
	faceplayer
# 387 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 438 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 439 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 440 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 441 "data/maps/Lobby/scripts.pory"
	delay 20
# 442 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 443 "data/maps/Lobby/scripts.pory"
	delay 20
# 444 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 445 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 446 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 447 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 448 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 449 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 450 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 451 "data/maps/Lobby/scripts.pory"
	lock
# 452 "data/maps/Lobby/scripts.pory"
	delay 20
# 453 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 454 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 455 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 456 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 388 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 389 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 390 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 393 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 395 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 396 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 397 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 401 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 406 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 407 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 410 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 411 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 412 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 413 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 414 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 415 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 416 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 423 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 424 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 427 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 429 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 430 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 431 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 433 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 434 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 435 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 391 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 398 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 399 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 402 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 403 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 417 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 418 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 419 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 420 "data/maps/Lobby/scripts.pory"
	delay 40
# 421 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 425 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 468 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 469 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 470 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 473 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 476 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 479 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 471 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 474 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 477 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 480 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 488 "data/maps/Lobby/scripts.pory"
	lock
# 489 "data/maps/Lobby/scripts.pory"
	faceplayer
# 490 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 491 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 492 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 493 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 497 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 498 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 499 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 504 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 505 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 510 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 511 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 516 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 517 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 522 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 523 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 528 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 529 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 534 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_JARDINO
# 535 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 540 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_OCEADINO
# 541 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 546 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_TYRADINO
# 547 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25:
# 552 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 553 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28:
# 558 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 559 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 564 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MICAEL
# 565 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 570 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MOLIKAI
# 571 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 576 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_DIRAEI
# 577 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 582 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_LUGIA_SHADOW
# 583 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43:
# 588 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47
# 593 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 15
# 594 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 595 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 596 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50
# 601 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 602 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54
# 606 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55
# 610 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56
# 614 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57
# 618 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58
# 622 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59
# 626 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60
# 630 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61
# 634 "data/maps/Lobby/scripts.pory"
	case 8, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62
# 638 "data/maps/Lobby/scripts.pory"
	case 9, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63
# 642 "data/maps/Lobby/scripts.pory"
	case 10, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64
# 646 "data/maps/Lobby/scripts.pory"
	case 11, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65
# 650 "data/maps/Lobby/scripts.pory"
	case 12, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66
# 654 "data/maps/Lobby/scripts.pory"
	case 13, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67
# 658 "data/maps/Lobby/scripts.pory"
	case 14, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52:
# 663 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 500 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 501 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 502 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 506 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 507 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 508 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 512 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 513 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 514 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 518 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 519 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 520 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 524 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 525 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 526 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 530 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 531 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 532 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 536 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_JARDINO
# 537 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 538 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 542 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OCEADINO
# 543 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 544 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 548 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYRADINO
# 549 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 8
# 550 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 554 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 555 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 9
# 556 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32:
# 560 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 561 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 10
# 562 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 566 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MICAEL
# 567 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 11
# 568 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 572 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLIKAI
# 573 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 12
# 574 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41:
# 578 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIRAEI
# 579 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 13
# 580 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44:
# 584 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_SHADOW
# 585 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 14
# 586 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47:
# 589 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 590 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50:
# 597 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 598 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54:
# 603 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 604 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 605 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55:
# 607 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 608 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 609 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56:
# 611 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 612 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 613 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57:
# 615 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 616 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 617 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58:
# 619 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 620 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 621 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59:
# 623 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 624 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 625 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60:
# 627 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_JARDINO, 10, 3
# 628 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_JARDINO
# 629 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61:
# 631 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_OCEADINO, 10, 3
# 632 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_OCEADINO
# 633 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62:
# 635 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_TYRADINO, 10, 3
# 636 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRADINO
# 637 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63:
# 639 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 640 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 641 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64:
# 643 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 644 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 645 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65:
# 647 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MICAEL, 10, 3
# 648 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MICAEL
# 649 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66:
# 651 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MOLIKAI, 10, 3
# 652 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLIKAI
# 653 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67:
# 655 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_DIRAEI, 10, 3
# 656 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIRAEI
# 657 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68:
# 659 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_LUGIA_SHADOW, 10, 3
# 660 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA_SHADOW
# 661 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52


Lobby_EventScript_ShowFakemonDexInfo::
# 667 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 668 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 669 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 670 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 673 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 675 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 676 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 677 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 678 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 681 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 682 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 683 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 686 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 687 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 688 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 691 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 692 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 693 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 694 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 695 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 671 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 679 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 684 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 689 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 700 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Cope::
# 705 "data/maps/Lobby/scripts.pory"
	lock
# 706 "data/maps/Lobby/scripts.pory"
	faceplayer
# 707 "data/maps/Lobby/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 708 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_Cope_2
# 717 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 718 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 719 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Lobby_EventScript_Cope_Movement_0
# 720 "data/maps/Lobby/scripts.pory"
	waitse
# 721 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 722 "data/maps/Lobby/scripts.pory"
	delay 10
# 723 "data/maps/Lobby/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 724 "data/maps/Lobby/scripts.pory"
	closemessage
# 725 "data/maps/Lobby/scripts.pory"
	delay 20
# 726 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
Lobby_EventScript_Cope_1:
# 728 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Cope_2:
# 710 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 711 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 712 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 713 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
	goto Lobby_EventScript_Cope_1


Lobby_EventScript_QREventInfoKid::
# 733 "data/maps/Lobby/scripts.pory"
	lock
# 734 "data/maps/Lobby/scripts.pory"
	faceplayer
# 735 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 736 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 737 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 738 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire::
# 743 "data/maps/Lobby/scripts.pory"
	lock
# 744 "data/maps/Lobby/scripts.pory"
	faceplayer
# 745 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_0, MSGBOX_AUTOCLOSE
# 746 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 747 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_2
# 754 "data/maps/Lobby/scripts.pory"
	delay 20
# 755 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 756 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 757 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 758 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_5
# 765 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_6
# 768 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_2:
# 748 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 749 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Surprise
# 750 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_1, MSGBOX_AUTOCLOSE
# 751 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_5:
# 759 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_2, MSGBOX_YESNO
# 760 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_8
# 763 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_6:
# 766 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_8:
# 761 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	return


Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft::
# 773 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0, MSGBOX_AUTOCLOSE
# 774 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions::
# 779 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0, MSGBOX_AUTOCLOSE
# 780 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater::
# 785 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0, MSGBOX_AUTOCLOSE
# 786 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NextQuestion::
# 791 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 792 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 793 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 794 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2
# 800 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3
# 802 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_NONE_THIS_TALK, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4
# 807 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2:
# 795 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0, MSGBOX_YESNO
# 796 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7
Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6:
# 799 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3:
# 801 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4:
# 803 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1, MSGBOX_AUTOCLOSE
# 804 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7:
# 797 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6


Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion::
# 812 "data/maps/Lobby/scripts.pory"
	addvar VAR_BETA_MON_QUESTIONNAIRE_ASK_COUNT, 1
# 813 "data/maps/Lobby/scripts.pory"
	switch VAR_0x8004
# 814 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_GOROCHU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3
# 817 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_TAABAN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4
# 820 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_BOMUSHIKAA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5
# 823 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_MADAAMU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6
# 826 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_AKUERIA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7
# 829 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_LATIKEN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8
Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1:
# 833 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion
	return

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3:
# 815 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Gorochu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4:
# 818 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Taaban
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5:
# 821 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6:
# 824 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Madaamu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7:
# 827 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Akueria
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8:
# 830 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Latiken
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1


Lobby_EventScript_BetaMonQuestionnaire_Gorochu::
# 837 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0
# 838 "data/maps/Lobby/scripts.pory"
	waitmessage
# 839 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1, 0
# 840 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2, 1
# 841 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3, 2
# 842 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4, 3
# 843 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 844 "data/maps/Lobby/scripts.pory"
	closemessage
# 845 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2
# 850 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2:
# 846 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_GOROCHU
# 847 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5, MSGBOX_AUTOCLOSE
# 848 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1


Lobby_EventScript_BetaMonQuestionnaire_Taaban::
# 856 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0
# 857 "data/maps/Lobby/scripts.pory"
	waitmessage
# 858 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1, 0
# 859 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2, 1
# 860 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3, 2
# 861 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4, 3
# 862 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 863 "data/maps/Lobby/scripts.pory"
	closemessage
# 864 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Taaban_2
# 869 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Taaban_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Taaban_2:
# 865 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_TAABAN
# 866 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5, MSGBOX_AUTOCLOSE
# 867 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Taaban_1


Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa::
# 875 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0
# 876 "data/maps/Lobby/scripts.pory"
	waitmessage
# 877 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1, 0
# 878 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2, 1
# 879 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3, 2
# 880 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4, 3
# 881 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 882 "data/maps/Lobby/scripts.pory"
	closemessage
# 883 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2
# 888 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2:
# 884 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_BOMUSHIKAA
# 885 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5, MSGBOX_AUTOCLOSE
# 886 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1


Lobby_EventScript_BetaMonQuestionnaire_Madaamu::
# 894 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0
# 895 "data/maps/Lobby/scripts.pory"
	waitmessage
# 896 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1, 0
# 897 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2, 1
# 898 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3, 2
# 899 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4, 3
# 900 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 901 "data/maps/Lobby/scripts.pory"
	closemessage
# 902 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2
# 907 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2:
# 903 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_MADAAMU
# 904 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5, MSGBOX_AUTOCLOSE
# 905 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1


Lobby_EventScript_BetaMonQuestionnaire_Akueria::
# 913 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0
# 914 "data/maps/Lobby/scripts.pory"
	waitmessage
# 915 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1, 0
# 916 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2, 1
# 917 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3, 2
# 918 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4, 3
# 919 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 920 "data/maps/Lobby/scripts.pory"
	closemessage
# 921 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Akueria_2
# 926 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Akueria_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Akueria_2:
# 922 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_AKUERIA
# 923 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5, MSGBOX_AUTOCLOSE
# 924 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Akueria_1


Lobby_EventScript_BetaMonQuestionnaire_Latiken::
# 932 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0, MSGBOX_AUTOCLOSE
# 933 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
# 934 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 935 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 936 "data/maps/Lobby/scripts.pory"
	waitmessage
# 937 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2, 0
# 938 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3, 1
# 939 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4, 2
# 940 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5, 3
# 941 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 942 "data/maps/Lobby/scripts.pory"
	closemessage
# 943 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_2
# 948 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6, MSGBOX_AUTOCLOSE
# 949 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
# 950 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 951 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 952 "data/maps/Lobby/scripts.pory"
	waitmessage
# 953 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7, 0
# 954 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8, 1
# 955 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9, 2
# 956 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10, 3
# 957 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 958 "data/maps/Lobby/scripts.pory"
	closemessage
# 959 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_5
# 964 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11, MSGBOX_AUTOCLOSE
# 965 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_BLAZIKEN, CRY_MODE_NORMAL
# 966 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 967 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 968 "data/maps/Lobby/scripts.pory"
	waitmessage
# 969 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12, 0
# 970 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13, 1
# 971 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14, 2
# 972 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15, 3
# 973 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 974 "data/maps/Lobby/scripts.pory"
	closemessage
# 975 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Latiken_8
# 980 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Latiken_7:
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_2:
# 944 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_5:
# 960 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_8:
# 976 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_LATIKEN
# 977 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16, MSGBOX_AUTOCLOSE
# 978 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Latiken_7


Lobby_EventScript_Pokebox::
# 990 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_C, 8
# 991 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_D, 3
# 992 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_OFF
# 993 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_ON
# 994 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


Lobby_EventScript_Turbo::
# 999 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Turbo_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Notes::
# 1004 "data/maps/Lobby/scripts.pory"
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

# 42 "data/maps/Lobby/scripts.pory"
Lobby_OnFrame_ExplainNewChallengeModes_Movement_1:
# 42 "data/maps/Lobby/scripts.pory"
	walk_up
# 42 "data/maps/Lobby/scripts.pory"
	walk_up
# 42 "data/maps/Lobby/scripts.pory"
	walk_up
# 42 "data/maps/Lobby/scripts.pory"
	walk_up
# 42 "data/maps/Lobby/scripts.pory"
	face_down
	step_end

# 321 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 321 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 321 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 323 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 323 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 323 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 323 "data/maps/Lobby/scripts.pory"
	face_player
# 323 "data/maps/Lobby/scripts.pory"
	delay_16
# 323 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 719 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Cope_Movement_0:
# 719 "data/maps/Lobby/scripts.pory"
	emote_question_mark
	step_end

Lobby_OnFrame_ExplainNewChallengeModes_Text_0:
# 14 "data/maps/Lobby/scripts.pory"
	.string "Incredible, {PLAYER}! You've beaten\n"
	.string "the challenge completely.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_1:
# 17 "data/maps/Lobby/scripts.pory"
	.string "But don't think this is over!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_2:
# 22 "data/maps/Lobby/scripts.pory"
	.string "You've still got plenty left to do!\p"
	.string "From now on you've unlocked new ways to\n"
	.string "play the challenge.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_3:
# 24 "data/maps/Lobby/scripts.pory"
	.string "Now you can battle in {COLOR BLUE}Double Battle{COLOR DARK_GRAY}\n"
	.string "mode!\p"
	.string "Every battle will be a double: two\n"
	.string "Pokémon out, double the chaos!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_4:
# 27 "data/maps/Lobby/scripts.pory"
	.string "Want to think a bit harder? Then\n"
	.string "{COLOR RED}Inverse Battles{COLOR DARK_GRAY} are for you!\p"
	.string "The type chart is flipped! What's\n"
	.string "resistant becomes weak, and vice versa.\p"
	.string "You can no longer battle in auto mode!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_5:
# 30 "data/maps/Lobby/scripts.pory"
	.string "If you trust your luck, you can try\n"
	.string "{COLOR GREEN}Random Team{COLOR DARK_GRAY} mode.\p"
	.string "When you start, you'll get a team of 6\n"
	.string "random Pokémon from the available ones.\p"
	.string "You can't change that team during the\n"
	.string "run, and you'll get yours back when the\l"
	.string "challenge ends.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_6:
# 33 "data/maps/Lobby/scripts.pory"
	.string "And that's not all!\p"
	.string "No matter which mode you pick, each\n"
	.string "admin will have two possible teams to\l"
	.string "use.\p"
	.string "Their {COLOR BLUE}main team{COLOR DARK_GRAY}, which you know, or an\n"
	.string "{COLOR RED}alternate team{COLOR DARK_GRAY}.\p"
	.string "You'll never know which you'll face,\n"
	.string "which means each run could feel\l"
	.string "completely different.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_7:
# 39 "data/maps/Lobby/scripts.pory"
	.string "I almost forgot!\p"
	.string "You can also explore the {COLOR BLUE}Creative Zone{COLOR DARK_GRAY}.\p"
	.string "Several of the challenge's creators are\n"
	.string "eager to take you on!\p"
	.string "And if you want 100% completion, there\n"
	.string "are still many {COLOR BLUE}achievements{COLOR DARK_GRAY} to earn.\p"
	.string "With everything left to do, you're sure\n"
	.string "to have a blast!$"

Lobby_EventScript_StartChallenge_Text_0:
# 57 "data/maps/Lobby/scripts.pory"
	.string "Hi {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 62 "data/maps/Lobby/scripts.pory"
	.string "So you're ready to take on the\n"
	.string "challenge?$"

Lobby_EventScript_StartChallenge_Text_2:
# 68 "data/maps/Lobby/scripts.pory"
	.string "Excellent! Go ahead - I wish you lots of\n"
	.string "luck and, above all, have fun!$"

Lobby_EventScript_StartChallenge_Text_3:
# 75 "data/maps/Lobby/scripts.pory"
	.string "How do you want to take on the\n"
	.string "challenge?$"

Lobby_EventScript_StartChallenge_Text_4:
# 77 "data/maps/Lobby/scripts.pory"
	.string "Standard$"

Lobby_EventScript_StartChallenge_Text_5:
# 78 "data/maps/Lobby/scripts.pory"
	.string "Double Battles$"

Lobby_EventScript_StartChallenge_Text_6:
# 79 "data/maps/Lobby/scripts.pory"
	.string "Inverse Battles$"

Lobby_EventScript_StartChallenge_Text_7:
# 80 "data/maps/Lobby/scripts.pory"
	.string "Random Team$"

Lobby_EventScript_StartChallenge_Text_8:
# 81 "data/maps/Lobby/scripts.pory"
	.string "Exit$"

Lobby_EventScript_StartChallenge_Text_9:
# 95 "data/maps/Lobby/scripts.pory"
	.string "Excellent! The challenge will be in\n"
	.string "Double Battle mode.\p"
	.string "Go ahead, I wish you lots of luck and,\n"
	.string "above all, have fun!$"

Lobby_EventScript_StartChallenge_Text_10:
# 101 "data/maps/Lobby/scripts.pory"
	.string "Excellent! The challenge will be in\n"
	.string "Inverse Battle mode.\p"
	.string "Type effectiveness is inverted: what's\n"
	.string "normally super effective becomes not\l"
	.string "very effective, and vice versa.\p"
	.string "Go ahead, I wish you lots of luck and,\n"
	.string "above all, have fun!$"

Lobby_EventScript_StartChallenge_Text_11:
# 111 "data/maps/Lobby/scripts.pory"
	.string "Excellent! You'll take on the challenge\n"
	.string "with a completely randomly-chosen\l"
	.string "team.\p"
	.string "Go ahead! I wish you lots of luck, and\n"
	.string "above all, have fun!$"

Lobby_StartChallenge_CancelledChallenge_Text_0:
# 121 "data/maps/Lobby/scripts.pory"
	.string "So you don't feel ready?$"

Lobby_StartChallenge_CancelledChallenge_Text_1:
# 123 "data/maps/Lobby/scripts.pory"
	.string "Remember, the people in the waiting\n"
	.string "room can help with your preparation.$"

Lobby_StartChallenge_RandomTeamFailed_Text_0:
# 131 "data/maps/Lobby/scripts.pory"
	.string "I couldn't prepare six different\n"
	.string "Pokémon for the challenge.\p"
	.string "Make sure you have a full team and try\n"
	.string "again.$"

Lobby_EventScript_TeamSelector_Text_0:
# 170 "data/maps/Lobby/scripts.pory"
	.string "Hi! I'm in charge of team selection for\n"
	.string "the challenge.\p"
	.string "Your current team is good, but I think\n"
	.string "you can get a better one.\p"
	.string "Want to choose another team?$"

Lobby_EventScript_TeamSelector_Text_1:
# 175 "data/maps/Lobby/scripts.pory"
	.string "Excellent choice! Now that's a winning\n"
	.string "team.\p"
	.string "Go for glory!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 196 "data/maps/Lobby/scripts.pory"
	.string "Hi! I'm in charge of difficulty selection\n"
	.string "for the challenge.\p"
	.string "The current difficulty doesn't seem\n"
	.string "right for you.\p"
	.string "Want to change the difficulty level?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 201 "data/maps/Lobby/scripts.pory"
	.string "Done! The difficulty's been updated.\nGood luck with the challenge!$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0:
# 220 "data/maps/Lobby/scripts.pory"
	.string "0$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1:
# 225 "data/maps/Lobby/scripts.pory"
	.string "win$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2:
# 227 "data/maps/Lobby/scripts.pory"
	.string "wins$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_0:
# 239 "data/maps/Lobby/scripts.pory"
	.string "time$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_1:
# 241 "data/maps/Lobby/scripts.pory"
	.string "times$"

Lobby_EventScript_ChallengeHistorian_Text_0:
# 250 "data/maps/Lobby/scripts.pory"
	.string "Hey, {PLAYER}!\p"
	.string "I don't work here or anything, but I\n"
	.string "love crunching stats.\p"
	.string "I hang out in the waiting room watching\n"
	.string "everyone who comes in, and I note it all\l"
	.string "down.$"

Lobby_EventScript_ChallengeHistorian_Text_1:
# 256 "data/maps/Lobby/scripts.pory"
	.string "I see you haven't completed the\n"
	.string "challenge even once.\p"
	.string "You haven't earned a spot in my notes\n"
	.string "yet.$"

Lobby_EventScript_ChallengeHistorian_Text_2:
# 268 "data/maps/Lobby/scripts.pory"
	.string "According to my notebook, in standard\n"
	.string "mode you have {STR_VAR_1}\l"
	.string "{STR_VAR_2}.\p"
	.string "Not bad at all, really!$"

Lobby_EventScript_ChallengeHistorian_Text_3:
# 271 "data/maps/Lobby/scripts.pory"
	.string "In double battles you have\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "That's where you see who thinks two\n"
	.string "turns ahead.$"

Lobby_EventScript_ChallengeHistorian_Text_4:
# 274 "data/maps/Lobby/scripts.pory"
	.string "And in inverse battles you've racked up\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "That mode turns anyone's head inside\n"
	.string "out.$"

Lobby_EventScript_ChallengeHistorian_Text_5:
# 277 "data/maps/Lobby/scripts.pory"
	.string "With random teams you've got\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "You never know which teammates you'll\n"
	.string "end up with!$"

Lobby_EventScript_ChallengeHistorian_Text_6:
# 280 "data/maps/Lobby/scripts.pory"
	.string "In total, you've completed the\n"
	.string "challenge {STR_VAR_1}\l"
	.string "{STR_VAR_2}.$"

Lobby_EventScript_ChallengeHistorian_Text_7:
# 282 "data/maps/Lobby/scripts.pory"
	.string "If you keep this up, I'll have to buy\n"
	.string "another notebook to record your\l"
	.string "numbers!$"

Lobby_EventScript_ChallengeHistorian_Text_8:
# 287 "data/maps/Lobby/scripts.pory"
	.string "Not that many wins yet, but keep it up.$"

Lobby_EventScript_Shop_Text_0:
# 301 "data/maps/Lobby/scripts.pory"
	.string "Hi! We've expanded the catalog!\p"
	.string "Now you can also buy battle items.\p"
	.string "How can I help you?$"

Lobby_EventScript_Shop_Text_1:
# 305 "data/maps/Lobby/scripts.pory"
	.string "Hi! How can I help you?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 316 "data/maps/Lobby/scripts.pory"
	.string "Well, look at you! The new champ!\n"
	.string "Congrats, man!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 318 "data/maps/Lobby/scripts.pory"
	.string "Well, look at you! The new champ!\n"
	.string "Congrats, girl!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 324 "data/maps/Lobby/scripts.pory"
	.string "I see you gave it to those traitors in\n"
	.string "the rooms… Glad someone finally\l"
	.string "knocked 'em down a peg.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 328 "data/maps/Lobby/scripts.pory"
	.string "Remember what I told you last time?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 331 "data/maps/Lobby/scripts.pory"
	.string "I finished my research in the Suzuka\n"
	.string "Archipelago… it's a long story, you\l"
	.string "should've seen it…\p"
	.string "You have no idea… But I picked up the\n"
	.string "trail of that force that was causing so\l"
	.string "much trouble, and I'm ready to test if\l"
	.string "this thing's really as legendary as the\l"
	.string "archipelago's chronicles claim.$"

Lobby_EventScript_Roxas_IntroRematch_Text_0:
# 339 "data/maps/Lobby/scripts.pory"
	.string "Hey, you again! Want to battle my\n"
	.string "legendary again?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 355 "data/maps/Lobby/scripts.pory"
	.string "Let's make it interesting: pick three of\n"
	.string "your critters.\p"
	.string "I'll send out my legendary, so you'd\n"
	.string "better choose well.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 361 "data/maps/Lobby/scripts.pory"
	.string "Let's make it interesting: a\n"
	.string "one-on-one.\p"
	.string "Pick your best critter and get ready to\n"
	.string "face my legendary.$"

Lobby_EventScript_Roxas_Text_0:
# 410 "data/maps/Lobby/scripts.pory"
	.string "Let's see if you can handle it!$"

Lobby_EventScript_Roxas_Text_1:
# 412 "data/maps/Lobby/scripts.pory"
	.string "Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 419 "data/maps/Lobby/scripts.pory"
	.string "Noo, you've gotta be kidding! Not even\n"
	.string "the power of this dark Pokémon could\l"
	.string "beat you.\p"
	.string "Now I get why they let you into the\n"
	.string "rooms and tossed me out on my ear.\p"
	.string "You've got something special, champ\n"
	.string "material - not just brute force.\p"
	.string "Honestly, you shut me up. Well earned.$"

Lobby_EventScript_Roxas_Text_3:
# 425 "data/maps/Lobby/scripts.pory"
	.string "Man, just like I figured… The power of\n"
	.string "this thing is out of this world; not even\l"
	.string "you, the champ, could take it.$"

Lobby_EventScript_Roxas_Text_4:
# 431 "data/maps/Lobby/scripts.pory"
	.string "If you ever swing by the Suzuka\n"
	.string "Archipelago, watch yourself, ace, 'cause\l"
	.string "out there this one won't cut you any\l"
	.string "slack.\p"
	.string "Better luck next time.$"

Lobby_EventScript_Roxas_Text_5:
# 438 "data/maps/Lobby/scripts.pory"
	.string "Don't bother asking… They won't let me\n"
	.string "through either…$"

Lobby_EventScript_Roxas_Text_6:
# 442 "data/maps/Lobby/scripts.pory"
	.string "They say being a WAH Leader in the\n"
	.string "Suzuka Archipelago for just two weeks\l"
	.string "isn't “enough of a track record” to\l"
	.string "take part.$"

Lobby_EventScript_Roxas_Text_7:
# 450 "data/maps/Lobby/scripts.pory"
	.string "The nerve of these guys, man!$"

Lobby_EventScript_Roxas_Text_8:
# 453 "data/maps/Lobby/scripts.pory"
	.string "But hey, I'm not gonna sit here crying\n"
	.string "about it.\p"
	.string "I'm after a ship that vanished west of\n"
	.string "the Orange Islands, the Suzuka\l"
	.string "Archipelago.\p"
	.string "Team Rocket's up to its old tricks, and\n"
	.string "they say there's a dark creature with\l"
	.string "red eyes that's dangerous… sounds\l"
	.string "terrifying…\p"
	.string "I gotta investigate and see what's up…$"

Lobby_EventScript_Roxas_Text_9:
# 455 "data/maps/Lobby/scripts.pory"
	.string "Hey, sorry, I'd better get back to my\n"
	.string "research.\p"
	.string "Good luck, I hope they actually give you\n"
	.string "the time of day!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 490 "data/maps/Lobby/scripts.pory"
	.string "I'm the expert on the species exclusive\n"
	.string "to Whack a Hack.\p"
	.string "I'll tell you all about them, but only the\n"
	.string "ones you've seen.\p"
	.string "I don't want to spoil the surprise!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 589 "data/maps/Lobby/scripts.pory"
	.string "Every species you've seen is common\n"
	.string "knowledge!\p"
	.string "Go battle in the rooms and you'll see\n"
	.string "what I'm talking about!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 594 "data/maps/Lobby/scripts.pory"
	.string "Which species would you like to know\n"
	.string "more about?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 597 "data/maps/Lobby/scripts.pory"
	.string "If you want to know more, I'll be here!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 668 "data/maps/Lobby/scripts.pory"
	.string "Since you don't have a Pokédex, its\n"
	.string "description is:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 671 "data/maps/Lobby/scripts.pory"
	.string "Its type is: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 673 "data/maps/Lobby/scripts.pory"
	.string "Its types are: {STR_VAR_2} and {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 675 "data/maps/Lobby/scripts.pory"
	.string "And I bet you didn't know this!\nIts abilities are:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 679 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 692 "data/maps/Lobby/scripts.pory"
	.string "One last fact! How good are its base\n"
	.string "stats?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 695 "data/maps/Lobby/scripts.pory"
	.string "And that's all about {STR_VAR_1}.\nHope you found it useful.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 700 "data/maps/Lobby/scripts.pory"
	.string "Did you know that you can see your\n"
	.string "achievements on the back of your\l"
	.string "Trainer Card?\p"
	.string "You can also see the requirements for\n"
	.string "earning each one!$"

Lobby_EventScript_Cope_Text_0:
# 710 "data/maps/Lobby/scripts.pory"
	.string "Hi {PLAYER}!\p"
	.string "Are you ready to take on the challenge?$"

Lobby_EventScript_Cope_Text_1:
# 713 "data/maps/Lobby/scripts.pory"
	.string "Have you managed to find Tile yet?\p"
	.string "He must be in one of the rooms... He's so\n"
	.string "slippery!\p"
	.string "Remember you can use the Devon\n"
	.string "Detector to find him.\p"
	.string "I bet every time you find him he'll give\n"
	.string "you a prize!$"

Lobby_EventScript_Cope_Text_2:
# 717 "data/maps/Lobby/scripts.pory"
	.string "Hi {PLAYER}!\p"
	.string "Have you seen Tile?$"

Lobby_EventScript_Cope_Text_3:
# 721 "data/maps/Lobby/scripts.pory"
	.string "What? You don't know who he is?\n"
	.string "He's my famous Kecleon.\p"
	.string "I've lost sight of him and have no idea\n"
	.string "where he's gotten to...\p"
	.string "On top of that, he stole the item kit I\n"
	.string "give to the challenge's trainers!\p"
	.string "Do me a favor and look for him.\n"
	.string "Here, take this.$"

Lobby_EventScript_Cope_Text_4:
# 726 "data/maps/Lobby/scripts.pory"
	.string "With the Devon Scope you can see where\n"
	.string "Tile is hiding.\p"
	.string "I've added a new feature that tells you\n"
	.string "if there's an invisible Pokémon nearby.\p"
	.string "Hope you find him!$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 735 "data/maps/Lobby/scripts.pory"
	.string "A guy in the Creative Zone gives you a\n"
	.string "gift for completing a special event.\p"
	.string "There's no way to guess what you have\n"
	.string "to do without watching the video.\p"
	.string "I even had to reorder two of the\n"
	.string "Pokémon on my team!\p"
	.string "That said, I liked the reward for the\n"
	.string "event, it was worth it!$"

Lobby_EventScript_BetaMonQuestionnaire_Text_0:
# 745 "data/maps/Lobby/scripts.pory"
	.string "Hey there! I'm the quiz master.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_1:
# 750 "data/maps/Lobby/scripts.pory"
	.string "So you haven't completed the challenge\n"
	.string "yet.\l"
	.string "...\l"
	.string "...\p"
	.string "When you beat it, come back and I'll give\n"
	.string "you a special quiz.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_2:
# 759 "data/maps/Lobby/scripts.pory"
	.string "I'll ask one question for each time\n"
	.string "you've completed the challenge.\p"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "Want me to ask you a question?$"

Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0:
# 773 "data/maps/Lobby/scripts.pory"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "Complete the challenge again and come\n"
	.string "back here.$"

Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0:
# 779 "data/maps/Lobby/scripts.pory"
	.string "You've already answered all my\n"
	.string "questions! What do you think of the\l"
	.string "Pokémon you've gotten?$"

Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0:
# 785 "data/maps/Lobby/scripts.pory"
	.string "All right. Come back whenever you like.$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0:
# 795 "data/maps/Lobby/scripts.pory"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "Want to keep answering?$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1:
# 803 "data/maps/Lobby/scripts.pory"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "For now I don't have any more new\n"
	.string "questions for you.\p"
	.string "Come talk to me another time.$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0:
# 837 "data/maps/Lobby/scripts.pory"
	.string "Which Pokémon is orange, has a long tail,\n"
	.string "and everyone loves the one it evolves\l"
	.string "into?$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1:
# 839 "data/maps/Lobby/scripts.pory"
	.string "Raichu$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2:
# 840 "data/maps/Lobby/scripts.pory"
	.string "Arcanine$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3:
# 841 "data/maps/Lobby/scripts.pory"
	.string "Floatzel$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4:
# 842 "data/maps/Lobby/scripts.pory"
	.string "Simisear$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5:
# 847 "data/maps/Lobby/scripts.pory"
	.string "Well, this is the Pokémon you'll meet.$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0:
# 856 "data/maps/Lobby/scripts.pory"
	.string "My friend always has his Bro in tow.\p"
	.string "Which Pokémon is my friend?$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1:
# 858 "data/maps/Lobby/scripts.pory"
	.string "Slowking$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2:
# 859 "data/maps/Lobby/scripts.pory"
	.string "Slowbro$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3:
# 860 "data/maps/Lobby/scripts.pory"
	.string "Slowpoke$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4:
# 861 "data/maps/Lobby/scripts.pory"
	.string "Shellder$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5:
# 866 "data/maps/Lobby/scripts.pory"
	.string "Then off you go with his Bro.$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0:
# 875 "data/maps/Lobby/scripts.pory"
	.string "White as snow with a cute little face.\p"
	.string "Who is it?$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1:
# 877 "data/maps/Lobby/scripts.pory"
	.string "Whismur$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2:
# 878 "data/maps/Lobby/scripts.pory"
	.string "Aipom$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3:
# 879 "data/maps/Lobby/scripts.pory"
	.string "Dewgong$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4:
# 880 "data/maps/Lobby/scripts.pory"
	.string "Snorunt$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5:
# 885 "data/maps/Lobby/scripts.pory"
	.string "Well, this one looks like it!$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0:
# 894 "data/maps/Lobby/scripts.pory"
	.string "Captain Leek brandishes his sword in\n"
	.string "the forest.\p"
	.string "Who's really Captain Leek?$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1:
# 896 "data/maps/Lobby/scripts.pory"
	.string "Kartana$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2:
# 897 "data/maps/Lobby/scripts.pory"
	.string "Gallade$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3:
# 898 "data/maps/Lobby/scripts.pory"
	.string "Farfetch'd$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4:
# 899 "data/maps/Lobby/scripts.pory"
	.string "Scyther$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5:
# 904 "data/maps/Lobby/scripts.pory"
	.string "Exactly. That blade also sparked\n"
	.string "Madaamu's curiosity.$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0:
# 913 "data/maps/Lobby/scripts.pory"
	.string "Riddle me this.\p"
	.string "Which blue serpent has an orange\n"
	.string "evolution?$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1:
# 915 "data/maps/Lobby/scripts.pory"
	.string "Gyarados$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2:
# 916 "data/maps/Lobby/scripts.pory"
	.string "Dratini$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3:
# 917 "data/maps/Lobby/scripts.pory"
	.string "Milotic$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4:
# 918 "data/maps/Lobby/scripts.pory"
	.string "Dunsparce$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5:
# 923 "data/maps/Lobby/scripts.pory"
	.string "Well, its cousin has watched you battle\n"
	.string "and awaits you.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0:
# 932 "data/maps/Lobby/scripts.pory"
	.string "Riddle me this.\p"
	.string "Which Pokémon makes this cry?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1:
# 935 "data/maps/Lobby/scripts.pory"
	.string "Who was it?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2:
# 937 "data/maps/Lobby/scripts.pory"
	.string "Jirachi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3:
# 938 "data/maps/Lobby/scripts.pory"
	.string "Celebi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4:
# 939 "data/maps/Lobby/scripts.pory"
	.string "Mew$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5:
# 940 "data/maps/Lobby/scripts.pory"
	.string "Deoxys$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6:
# 948 "data/maps/Lobby/scripts.pory"
	.string "Oh, correct. Now try to guess this one.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7:
# 953 "data/maps/Lobby/scripts.pory"
	.string "Latios$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8:
# 954 "data/maps/Lobby/scripts.pory"
	.string "Latias$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9:
# 955 "data/maps/Lobby/scripts.pory"
	.string "Altaria$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10:
# 956 "data/maps/Lobby/scripts.pory"
	.string "Flygon$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11:
# 964 "data/maps/Lobby/scripts.pory"
	.string "Oh, right again. Now this one.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12:
# 969 "data/maps/Lobby/scripts.pory"
	.string "Blaziken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13:
# 970 "data/maps/Lobby/scripts.pory"
	.string "Combusken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14:
# 971 "data/maps/Lobby/scripts.pory"
	.string "Infernape$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15:
# 972 "data/maps/Lobby/scripts.pory"
	.string "Lucario$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16:
# 977 "data/maps/Lobby/scripts.pory"
	.string "Incredible, you got it again. That's\n"
	.string "impressive.\p"
	.string "Take this.$"

Lobby_EventScript_Turbo_Text_0:
# 999 "data/maps/Lobby/scripts.pory"
	.string "Did you know there's a turbo mode you\n"
	.string "can use to blaze through the adventure\l"
	.string "at full speed?\p"
	.string "From the options menu you can set your\n"
	.string "text speed, walking speed, and a turbo\l"
	.string "for battles!\p"
	.string "Care to give it a try?$"

Lobby_EventScript_Notes_Text_0:
# 1004 "data/maps/Lobby/scripts.pory"
	.string "They look like notes full of stats and\n"
	.string "observations.\p"
	.string "Some pages are so worn they're hard to\n"
	.string "read.$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 188 "data/maps/Lobby/scripts.pory"
	.string "Well, well! A brave kid, huh?\nSo you think you'll win with THAT team...\pGood luck - you're gonna need it!$"

Lobby_Text_DifficultySelector_Cancelled::
# 213 "data/maps/Lobby/scripts.pory"
	.string "Got it! If you change your mind, I'll be\n"
	.string "around.$"

Lobby_Text_Roxas_PlayerCancelled::
# 463 "data/maps/Lobby/scripts.pory"
	.string "So you're scared of my legendary\n"
	.string "critter? And yet you won the rooms!$"

Lobby_Text_FailedToUnlock::
# 985 "data/maps/Lobby/scripts.pory"
	.string "Oh, you missed!$"
