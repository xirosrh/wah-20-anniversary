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
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 4
# 78 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 79 "data/maps/Lobby/scripts.pory"
	closemessage
# 80 "data/maps/Lobby/scripts.pory"
	delay 10
# 81 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 82 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_5
# 87 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_6
# 93 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_StartChallenge_7
# 100 "data/maps/Lobby/scripts.pory"
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
	goto_if_eq Lobby_EventScript_StartChallenge_9
# 68 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_5:
# 83 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 84 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 85 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 86 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_6:
# 88 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE
# 89 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 90 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 91 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 92 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_7:
# 94 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE
# 95 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 96 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 97 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 98 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_9:
# 63 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 64 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 65 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 66 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	goto Lobby_EventScript_StartChallenge_1


Lobby_StartChallenge_CancelledChallenge::
# 105 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 106 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_Surprise
# 107 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 108 "data/maps/Lobby/scripts.pory"
	delay 60
# 109 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 110 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 111 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 112 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_EnterOmegaRoom::
# 117 "data/maps/Lobby/scripts.pory"
	special SetWahChallengeInitialAchievementFlags
# 118 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_Kecleon_ResetFlags
# 119 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 120 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 121 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 122 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 123 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 124 "data/maps/Lobby/scripts.pory"
	waitstate
# 125 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 131 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 132 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 133 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 134 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 135 "data/maps/Lobby/scripts.pory"
	delay 5
# 136 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 137 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 138 "data/maps/Lobby/scripts.pory"
	delay 5
# 139 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 140 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 146 "data/maps/Lobby/scripts.pory"
	lock
# 147 "data/maps/Lobby/scripts.pory"
	faceplayer
# 148 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 149 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 158 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 160 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 161 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 150 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 151 "data/maps/Lobby/scripts.pory"
	waitstate
# 152 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 155 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 153 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 172 "data/maps/Lobby/scripts.pory"
	lock
# 173 "data/maps/Lobby/scripts.pory"
	faceplayer
# 174 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 175 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 184 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 186 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 187 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 176 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 177 "data/maps/Lobby/scripts.pory"
	waitstate
# 178 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 181 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 179 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_BufferVictoryWordFromCountVar::
# 197 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_2
# 200 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferVictoryWordFromCountVar_1:
# 202 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_6
# 205 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2
Lobby_EventScript_BufferVictoryWordFromCountVar_5:
	return

Lobby_EventScript_BufferVictoryWordFromCountVar_2:
# 198 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_1

Lobby_EventScript_BufferVictoryWordFromCountVar_6:
# 203 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_5


Lobby_EventScript_BufferTimeWordFromCountVar::
# 211 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_2
# 214 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferTimeWordFromCountVar_1:
# 216 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_6
# 219 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_1
Lobby_EventScript_BufferTimeWordFromCountVar_5:
	return

Lobby_EventScript_BufferTimeWordFromCountVar_2:
# 212 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_1

Lobby_EventScript_BufferTimeWordFromCountVar_6:
# 217 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_5


Lobby_EventScript_ChallengeHistorian::
# 225 "data/maps/Lobby/scripts.pory"
	lock
# 226 "data/maps/Lobby/scripts.pory"
	faceplayer
# 228 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_0, MSGBOX_AUTOCLOSE
# 229 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 230 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_ChallengeHistorian_2
# 241 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 242 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 243 "data/maps/Lobby/scripts.pory"
	faceplayer
# 244 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT
# 245 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 246 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_2
# 247 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT
# 248 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 249 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_3
# 250 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT
# 251 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 252 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_4
# 253 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_COMPLETION_COUNT
# 254 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferTimeWordFromCountVar
# 255 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_5
# 256 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 5
	goto_if_gt Lobby_EventScript_ChallengeHistorian_5
# 262 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_7, MSGBOX_AUTOCLOSE
# 263 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 264 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
Lobby_EventScript_ChallengeHistorian_4:
# 266 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 267 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_2:
# 231 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 232 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 233 "data/maps/Lobby/scripts.pory"
	faceplayer
# 234 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_1, MSGBOX_AUTOCLOSE
# 235 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 236 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 237 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 238 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_5:
# 257 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_6, MSGBOX_AUTOCLOSE
# 258 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 259 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
	goto Lobby_EventScript_ChallengeHistorian_4


Lobby_EventScript_Shop::
# 273 "data/maps/Lobby/scripts.pory"
	lock
# 274 "data/maps/Lobby/scripts.pory"
	faceplayer
# 275 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Shop_4
Lobby_EventScript_Shop_3:
# 280 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_1
# 281 "data/maps/Lobby/scripts.pory"
	waitmessage
Lobby_EventScript_Shop_1:
# 283 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 284 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Shop_2:
# 276 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 277 "data/maps/Lobby/scripts.pory"
	waitmessage
# 278 "data/maps/Lobby/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto Lobby_EventScript_Shop_1

Lobby_EventScript_Shop_4:
# 275 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, Lobby_EventScript_Shop_2
	goto Lobby_EventScript_Shop_3


Lobby_EventScript_Roxas_IntroFirstBattle::
# 289 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 290 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 293 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 295 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 296 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 297 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 298 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 299 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 300 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 301 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 302 "data/maps/Lobby/scripts.pory"
	delay 20
# 303 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 304 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 305 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 306 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 307 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 308 "data/maps/Lobby/scripts.pory"
	delay 20
# 309 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 291 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 314 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 315 "data/maps/Lobby/scripts.pory"
	closemessage
# 316 "data/maps/Lobby/scripts.pory"
	delay 20
# 317 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 321 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 322 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 318 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 328 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 329 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 332 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 336 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 330 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 333 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 343 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 344 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 345 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 346 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 347 "data/maps/Lobby/scripts.pory"
	waitstate
# 348 "data/maps/Lobby/scripts.pory"
	lock
# 349 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 355 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 350 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 351 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 352 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 360 "data/maps/Lobby/scripts.pory"
	lock
# 361 "data/maps/Lobby/scripts.pory"
	faceplayer
# 362 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 413 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 414 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 415 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 416 "data/maps/Lobby/scripts.pory"
	delay 20
# 417 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 418 "data/maps/Lobby/scripts.pory"
	delay 20
# 419 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 420 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 421 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 422 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 423 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 424 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 425 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 426 "data/maps/Lobby/scripts.pory"
	lock
# 427 "data/maps/Lobby/scripts.pory"
	delay 20
# 428 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 429 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 430 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 431 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 363 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 364 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 365 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 368 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 370 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 371 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 372 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 376 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 381 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 382 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 385 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 386 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 387 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 388 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 389 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 390 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 391 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 398 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 399 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 402 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 404 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 405 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 406 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 408 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 409 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 410 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 366 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 373 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 374 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 377 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 378 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 392 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 393 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 394 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 395 "data/maps/Lobby/scripts.pory"
	delay 40
# 396 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 400 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 443 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 444 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 445 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 448 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 451 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 454 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 446 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 449 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 452 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 455 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 463 "data/maps/Lobby/scripts.pory"
	lock
# 464 "data/maps/Lobby/scripts.pory"
	faceplayer
# 465 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 466 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 467 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 468 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 472 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 473 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 474 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 479 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 480 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 485 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 486 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 491 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 492 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 497 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 498 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 503 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 504 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 509 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_JARDINO
# 510 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 515 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_OCEADINO
# 516 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 521 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_TYRADINO
# 522 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25:
# 527 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 528 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28:
# 533 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 534 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 539 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MICAEL
# 540 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 545 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MOLIKAI
# 546 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 551 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_DIRAEI
# 552 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 557 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_LUGIA_SHADOW
# 558 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43:
# 563 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47
# 568 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 15
# 569 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 570 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 571 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50
# 576 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 577 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54
# 581 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55
# 585 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56
# 589 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57
# 593 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58
# 597 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59
# 601 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60
# 605 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61
# 609 "data/maps/Lobby/scripts.pory"
	case 8, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62
# 613 "data/maps/Lobby/scripts.pory"
	case 9, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63
# 617 "data/maps/Lobby/scripts.pory"
	case 10, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64
# 621 "data/maps/Lobby/scripts.pory"
	case 11, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65
# 625 "data/maps/Lobby/scripts.pory"
	case 12, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66
# 629 "data/maps/Lobby/scripts.pory"
	case 13, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67
# 633 "data/maps/Lobby/scripts.pory"
	case 14, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52:
# 638 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 475 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 476 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 477 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 481 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 482 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 483 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 487 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 488 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 489 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 493 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 494 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 495 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 499 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 500 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 501 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 505 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 506 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 507 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 511 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_JARDINO
# 512 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 513 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 517 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OCEADINO
# 518 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 519 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 523 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYRADINO
# 524 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 8
# 525 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 529 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 530 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 9
# 531 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32:
# 535 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 536 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 10
# 537 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 541 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MICAEL
# 542 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 11
# 543 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 547 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLIKAI
# 548 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 12
# 549 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41:
# 553 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIRAEI
# 554 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 13
# 555 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44:
# 559 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_SHADOW
# 560 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 14
# 561 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47:
# 564 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 565 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50:
# 572 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 573 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54:
# 578 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 579 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 580 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55:
# 582 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 583 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 584 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56:
# 586 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 587 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 588 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57:
# 590 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 591 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 592 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58:
# 594 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 595 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 596 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59:
# 598 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 599 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 600 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60:
# 602 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_JARDINO, 10, 3
# 603 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_JARDINO
# 604 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61:
# 606 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_OCEADINO, 10, 3
# 607 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_OCEADINO
# 608 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62:
# 610 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_TYRADINO, 10, 3
# 611 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRADINO
# 612 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63:
# 614 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 615 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 616 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64:
# 618 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 619 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 620 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65:
# 622 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MICAEL, 10, 3
# 623 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MICAEL
# 624 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66:
# 626 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MOLIKAI, 10, 3
# 627 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLIKAI
# 628 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67:
# 630 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_DIRAEI, 10, 3
# 631 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIRAEI
# 632 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68:
# 634 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_LUGIA_SHADOW, 10, 3
# 635 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA_SHADOW
# 636 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52


Lobby_EventScript_ShowFakemonDexInfo::
# 642 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 643 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 644 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 645 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 648 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 650 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 651 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 652 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 653 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 656 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 657 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 658 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 661 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 662 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 663 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 666 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 667 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 668 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 669 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 670 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 646 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 654 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 659 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 664 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 675 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Cope::
# 680 "data/maps/Lobby/scripts.pory"
	lock
# 681 "data/maps/Lobby/scripts.pory"
	faceplayer
# 682 "data/maps/Lobby/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 683 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_Cope_2
# 692 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 693 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 694 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Lobby_EventScript_Cope_Movement_0
# 695 "data/maps/Lobby/scripts.pory"
	waitse
# 696 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 697 "data/maps/Lobby/scripts.pory"
	delay 10
# 698 "data/maps/Lobby/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 699 "data/maps/Lobby/scripts.pory"
	closemessage
# 700 "data/maps/Lobby/scripts.pory"
	delay 20
# 701 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
Lobby_EventScript_Cope_1:
# 703 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Cope_2:
# 685 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 686 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 687 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 688 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
	goto Lobby_EventScript_Cope_1


Lobby_EventScript_QREventInfoKid::
# 708 "data/maps/Lobby/scripts.pory"
	lock
# 709 "data/maps/Lobby/scripts.pory"
	faceplayer
# 710 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 711 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 712 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 713 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire::
# 718 "data/maps/Lobby/scripts.pory"
	lock
# 719 "data/maps/Lobby/scripts.pory"
	faceplayer
# 720 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_0, MSGBOX_AUTOCLOSE
# 721 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 722 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_2
# 729 "data/maps/Lobby/scripts.pory"
	delay 20
# 730 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 731 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 732 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 733 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_5
# 740 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_6
# 743 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_2:
# 723 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 724 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Surprise
# 725 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_1, MSGBOX_AUTOCLOSE
# 726 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_5:
# 734 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_2, MSGBOX_YESNO
# 735 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_8
# 738 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_6:
# 741 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_8:
# 736 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	return


Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft::
# 748 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0, MSGBOX_AUTOCLOSE
# 749 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions::
# 754 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0, MSGBOX_AUTOCLOSE
# 755 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater::
# 760 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0, MSGBOX_AUTOCLOSE
# 761 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NextQuestion::
# 766 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 767 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 768 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 769 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2
# 775 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3
# 777 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_NONE_THIS_TALK, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4
# 782 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2:
# 770 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0, MSGBOX_YESNO
# 771 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7
Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6:
# 774 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3:
# 776 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4:
# 778 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1, MSGBOX_AUTOCLOSE
# 779 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7:
# 772 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6


Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion::
# 787 "data/maps/Lobby/scripts.pory"
	addvar VAR_BETA_MON_QUESTIONNAIRE_ASK_COUNT, 1
# 788 "data/maps/Lobby/scripts.pory"
	switch VAR_0x8004
# 789 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_GOROCHU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3
# 792 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_TAABAN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4
# 795 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_BOMUSHIKAA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5
# 798 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_MADAAMU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6
# 801 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_AKUERIA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7
# 804 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_LATIKEN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8
Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1:
# 808 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion
	return

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3:
# 790 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Gorochu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4:
# 793 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Taaban
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5:
# 796 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6:
# 799 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Madaamu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7:
# 802 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Akueria
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8:
# 805 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Latiken
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1


Lobby_EventScript_BetaMonQuestionnaire_Gorochu::
# 812 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0
# 813 "data/maps/Lobby/scripts.pory"
	waitmessage
# 814 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1, 0
# 815 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2, 1
# 816 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3, 2
# 817 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4, 3
# 818 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 819 "data/maps/Lobby/scripts.pory"
	closemessage
# 820 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2
# 825 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2:
# 821 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_GOROCHU
# 822 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5, MSGBOX_AUTOCLOSE
# 823 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1


Lobby_EventScript_BetaMonQuestionnaire_Taaban::
# 831 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0
# 832 "data/maps/Lobby/scripts.pory"
	waitmessage
# 833 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1, 0
# 834 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2, 1
# 835 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3, 2
# 836 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4, 3
# 837 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 838 "data/maps/Lobby/scripts.pory"
	closemessage
# 839 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Taaban_2
# 844 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Taaban_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Taaban_2:
# 840 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_TAABAN
# 841 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5, MSGBOX_AUTOCLOSE
# 842 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Taaban_1


Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa::
# 850 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0
# 851 "data/maps/Lobby/scripts.pory"
	waitmessage
# 852 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1, 0
# 853 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2, 1
# 854 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3, 2
# 855 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4, 3
# 856 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 857 "data/maps/Lobby/scripts.pory"
	closemessage
# 858 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2
# 863 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2:
# 859 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_BOMUSHIKAA
# 860 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5, MSGBOX_AUTOCLOSE
# 861 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1


Lobby_EventScript_BetaMonQuestionnaire_Madaamu::
# 869 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0
# 870 "data/maps/Lobby/scripts.pory"
	waitmessage
# 871 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1, 0
# 872 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2, 1
# 873 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3, 2
# 874 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4, 3
# 875 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 876 "data/maps/Lobby/scripts.pory"
	closemessage
# 877 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2
# 882 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2:
# 878 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_MADAAMU
# 879 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5, MSGBOX_AUTOCLOSE
# 880 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1


Lobby_EventScript_BetaMonQuestionnaire_Akueria::
# 888 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0
# 889 "data/maps/Lobby/scripts.pory"
	waitmessage
# 890 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1, 0
# 891 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2, 1
# 892 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3, 2
# 893 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4, 3
# 894 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 895 "data/maps/Lobby/scripts.pory"
	closemessage
# 896 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Akueria_2
# 901 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Akueria_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Akueria_2:
# 897 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_AKUERIA
# 898 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5, MSGBOX_AUTOCLOSE
# 899 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Akueria_1


Lobby_EventScript_BetaMonQuestionnaire_Latiken::
# 907 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0, MSGBOX_AUTOCLOSE
# 908 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
# 909 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 910 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 911 "data/maps/Lobby/scripts.pory"
	waitmessage
# 912 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2, 0
# 913 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3, 1
# 914 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4, 2
# 915 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5, 3
# 916 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 917 "data/maps/Lobby/scripts.pory"
	closemessage
# 918 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_2
# 923 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6, MSGBOX_AUTOCLOSE
# 924 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
# 925 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 926 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 927 "data/maps/Lobby/scripts.pory"
	waitmessage
# 928 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7, 0
# 929 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8, 1
# 930 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9, 2
# 931 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10, 3
# 932 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 933 "data/maps/Lobby/scripts.pory"
	closemessage
# 934 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_5
# 939 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11, MSGBOX_AUTOCLOSE
# 940 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_BLAZIKEN, CRY_MODE_NORMAL
# 941 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 942 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 943 "data/maps/Lobby/scripts.pory"
	waitmessage
# 944 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12, 0
# 945 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13, 1
# 946 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14, 2
# 947 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15, 3
# 948 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 949 "data/maps/Lobby/scripts.pory"
	closemessage
# 950 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Latiken_8
# 955 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Latiken_7:
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_2:
# 919 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_5:
# 935 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_8:
# 951 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_LATIKEN
# 952 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16, MSGBOX_AUTOCLOSE
# 953 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Latiken_7


Lobby_EventScript_Pokebox::
# 965 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_C, 8
# 966 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_D, 3
# 967 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_OFF
# 968 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_ON
# 969 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


Lobby_EventScript_Turbo::
# 974 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Turbo_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Notes::
# 979 "data/maps/Lobby/scripts.pory"
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

# 296 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 296 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 296 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 298 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 298 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 298 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 298 "data/maps/Lobby/scripts.pory"
	face_player
# 298 "data/maps/Lobby/scripts.pory"
	delay_16
# 298 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 694 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Cope_Movement_0:
# 694 "data/maps/Lobby/scripts.pory"
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
	.string "And that's not all!\p"
	.string "No matter which mode you pick, each\n"
	.string "admin will have two possible teams to\l"
	.string "use.\p"
	.string "Their {COLOR BLUE}main team{COLOR DARK_GRAY}, which you know, or an\n"
	.string "{COLOR RED}alternate team{COLOR DARK_GRAY}.\p"
	.string "You'll never know which you'll face,\n"
	.string "which means each run could feel\l"
	.string "completely different.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_6:
# 36 "data/maps/Lobby/scripts.pory"
	.string "I almost forgot!\p"
	.string "You can also explore the {COLOR BLUE}Creative Zone{COLOR DARK_GRAY}.\p"
	.string "Several of the challenge's creators are\n"
	.string "eager to take you on!\p"
	.string "And if you want 100% completion, there\n"
	.string "are still many {COLOR BLUE}achievements{COLOR DARK_GRAY} to earn.\p"
	.string "With everything left to do, you're sure\n"
	.string "to have a blast!$"

Lobby_EventScript_StartChallenge_Text_0:
# 54 "data/maps/Lobby/scripts.pory"
	.string "Hi {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 59 "data/maps/Lobby/scripts.pory"
	.string "So you're ready to take on the\n"
	.string "challenge?$"

Lobby_EventScript_StartChallenge_Text_2:
# 65 "data/maps/Lobby/scripts.pory"
	.string "Excellent! Go ahead - I wish you lots of\n"
	.string "luck and, above all, have fun!$"

Lobby_EventScript_StartChallenge_Text_3:
# 72 "data/maps/Lobby/scripts.pory"
	.string "How do you want to take on the\n"
	.string "challenge?$"

Lobby_EventScript_StartChallenge_Text_4:
# 74 "data/maps/Lobby/scripts.pory"
	.string "Standard$"

Lobby_EventScript_StartChallenge_Text_5:
# 75 "data/maps/Lobby/scripts.pory"
	.string "Double Battles$"

Lobby_EventScript_StartChallenge_Text_6:
# 76 "data/maps/Lobby/scripts.pory"
	.string "Inverse Battles$"

Lobby_EventScript_StartChallenge_Text_7:
# 77 "data/maps/Lobby/scripts.pory"
	.string "Exit$"

Lobby_EventScript_StartChallenge_Text_8:
# 91 "data/maps/Lobby/scripts.pory"
	.string "Excellent! The challenge will be in\n"
	.string "Double Battle mode.\p"
	.string "Go ahead, I wish you lots of luck and,\n"
	.string "above all, have fun!$"

Lobby_EventScript_StartChallenge_Text_9:
# 97 "data/maps/Lobby/scripts.pory"
	.string "Excellent! The challenge will be in\n"
	.string "Inverse Battle mode.\p"
	.string "Type effectiveness is inverted: what's\n"
	.string "normally super effective becomes not\l"
	.string "very effective, and vice versa.\p"
	.string "Go ahead, I wish you lots of luck and,\n"
	.string "above all, have fun!$"

Lobby_StartChallenge_CancelledChallenge_Text_0:
# 107 "data/maps/Lobby/scripts.pory"
	.string "So you don't feel ready?$"

Lobby_StartChallenge_CancelledChallenge_Text_1:
# 109 "data/maps/Lobby/scripts.pory"
	.string "Remember, the people in the waiting\n"
	.string "room can help with your preparation.$"

Lobby_EventScript_TeamSelector_Text_0:
# 148 "data/maps/Lobby/scripts.pory"
	.string "Hi! I'm in charge of team selection for\n"
	.string "the challenge.\p"
	.string "Your current team is good, but I think\n"
	.string "you can get a better one.\p"
	.string "Want to choose another team?$"

Lobby_EventScript_TeamSelector_Text_1:
# 153 "data/maps/Lobby/scripts.pory"
	.string "Excellent choice! Now that's a winning\n"
	.string "team.\p"
	.string "Go for glory!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 174 "data/maps/Lobby/scripts.pory"
	.string "Hi! I'm in charge of difficulty selection\n"
	.string "for the challenge.\p"
	.string "The current difficulty doesn't seem\n"
	.string "right for you.\p"
	.string "Want to change the difficulty level?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 179 "data/maps/Lobby/scripts.pory"
	.string "Done! The difficulty's been updated.\nGood luck with the challenge!$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0:
# 198 "data/maps/Lobby/scripts.pory"
	.string "0$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1:
# 203 "data/maps/Lobby/scripts.pory"
	.string "win$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2:
# 205 "data/maps/Lobby/scripts.pory"
	.string "wins$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_0:
# 217 "data/maps/Lobby/scripts.pory"
	.string "time$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_1:
# 219 "data/maps/Lobby/scripts.pory"
	.string "times$"

Lobby_EventScript_ChallengeHistorian_Text_0:
# 228 "data/maps/Lobby/scripts.pory"
	.string "Hey, {PLAYER}!\p"
	.string "I don't work here or anything, but I\n"
	.string "love crunching stats.\p"
	.string "I hang out in the waiting room watching\n"
	.string "everyone who comes in, and I note it all\l"
	.string "down.$"

Lobby_EventScript_ChallengeHistorian_Text_1:
# 234 "data/maps/Lobby/scripts.pory"
	.string "I see you haven't completed the\n"
	.string "challenge even once.\p"
	.string "You haven't earned a spot in my notes\n"
	.string "yet.$"

Lobby_EventScript_ChallengeHistorian_Text_2:
# 246 "data/maps/Lobby/scripts.pory"
	.string "According to my notebook, in standard\n"
	.string "mode you have {STR_VAR_1}\l"
	.string "{STR_VAR_2}.\p"
	.string "Not bad at all, really!$"

Lobby_EventScript_ChallengeHistorian_Text_3:
# 249 "data/maps/Lobby/scripts.pory"
	.string "In double battles you have\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "That's where you see who thinks two\n"
	.string "turns ahead.$"

Lobby_EventScript_ChallengeHistorian_Text_4:
# 252 "data/maps/Lobby/scripts.pory"
	.string "And in inverse battles you've racked up\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "That mode turns anyone's head inside\n"
	.string "out.$"

Lobby_EventScript_ChallengeHistorian_Text_5:
# 255 "data/maps/Lobby/scripts.pory"
	.string "In total, you've completed the\n"
	.string "challenge {STR_VAR_1}\l"
	.string "{STR_VAR_2}.$"

Lobby_EventScript_ChallengeHistorian_Text_6:
# 257 "data/maps/Lobby/scripts.pory"
	.string "If you keep this up, I'll have to buy\n"
	.string "another notebook to record your\l"
	.string "numbers!$"

Lobby_EventScript_ChallengeHistorian_Text_7:
# 262 "data/maps/Lobby/scripts.pory"
	.string "Not that many wins yet, but keep it up.$"

Lobby_EventScript_Shop_Text_0:
# 276 "data/maps/Lobby/scripts.pory"
	.string "Hi! We've expanded the catalog!\p"
	.string "Now you can also buy battle items.\p"
	.string "How can I help you?$"

Lobby_EventScript_Shop_Text_1:
# 280 "data/maps/Lobby/scripts.pory"
	.string "Hi! How can I help you?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 291 "data/maps/Lobby/scripts.pory"
	.string "Well, look at you! The new champ!\n"
	.string "Congrats, man!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 293 "data/maps/Lobby/scripts.pory"
	.string "Well, look at you! The new champ!\n"
	.string "Congrats, girl!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 299 "data/maps/Lobby/scripts.pory"
	.string "I see you gave it to those traitors in\n"
	.string "the rooms… Glad someone finally\l"
	.string "knocked 'em down a peg.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 303 "data/maps/Lobby/scripts.pory"
	.string "Remember what I told you last time?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 306 "data/maps/Lobby/scripts.pory"
	.string "I finished my research in the Suzuka\n"
	.string "Archipelago… it's a long story, you\l"
	.string "should've seen it…\p"
	.string "You have no idea… But I picked up the\n"
	.string "trail of that force that was causing so\l"
	.string "much trouble, and I'm ready to test if\l"
	.string "this thing's really as legendary as the\l"
	.string "archipelago's chronicles claim.$"

Lobby_EventScript_Roxas_IntroRematch_Text_0:
# 314 "data/maps/Lobby/scripts.pory"
	.string "Hey, you again! Want to battle my\n"
	.string "legendary again?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 330 "data/maps/Lobby/scripts.pory"
	.string "Let's make it interesting: pick three of\n"
	.string "your critters.\p"
	.string "I'll send out my legendary, so you'd\n"
	.string "better choose well.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 336 "data/maps/Lobby/scripts.pory"
	.string "Let's make it interesting: a\n"
	.string "one-on-one.\p"
	.string "Pick your best critter and get ready to\n"
	.string "face my legendary.$"

Lobby_EventScript_Roxas_Text_0:
# 385 "data/maps/Lobby/scripts.pory"
	.string "Let's see if you can handle it!$"

Lobby_EventScript_Roxas_Text_1:
# 387 "data/maps/Lobby/scripts.pory"
	.string "Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 394 "data/maps/Lobby/scripts.pory"
	.string "Noo, you've gotta be kidding! Not even\n"
	.string "the power of this dark Pokémon could\l"
	.string "beat you.\p"
	.string "Now I get why they let you into the\n"
	.string "rooms and tossed me out on my ear.\p"
	.string "You've got something special, champ\n"
	.string "material - not just brute force.\p"
	.string "Honestly, you shut me up. Well earned.$"

Lobby_EventScript_Roxas_Text_3:
# 400 "data/maps/Lobby/scripts.pory"
	.string "Man, just like I figured… The power of\n"
	.string "this thing is out of this world; not even\l"
	.string "you, the champ, could take it.$"

Lobby_EventScript_Roxas_Text_4:
# 406 "data/maps/Lobby/scripts.pory"
	.string "If you ever swing by the Suzuka\n"
	.string "Archipelago, watch yourself, ace, 'cause\l"
	.string "out there this one won't cut you any\l"
	.string "slack.\p"
	.string "Better luck next time.$"

Lobby_EventScript_Roxas_Text_5:
# 413 "data/maps/Lobby/scripts.pory"
	.string "Don't bother asking… They won't let me\n"
	.string "through either…$"

Lobby_EventScript_Roxas_Text_6:
# 417 "data/maps/Lobby/scripts.pory"
	.string "They say being a WAH Leader in the\n"
	.string "Suzuka Archipelago for just two weeks\l"
	.string "isn't “enough of a track record” to\l"
	.string "take part.$"

Lobby_EventScript_Roxas_Text_7:
# 425 "data/maps/Lobby/scripts.pory"
	.string "The nerve of these guys, man!$"

Lobby_EventScript_Roxas_Text_8:
# 428 "data/maps/Lobby/scripts.pory"
	.string "But hey, I'm not gonna sit here crying\n"
	.string "about it.\p"
	.string "I'm after a ship that vanished west of\n"
	.string "the Orange Islands, the Suzuka\l"
	.string "Archipelago.\p"
	.string "Team Rocket's up to its old tricks, and\n"
	.string "they say there's a dark creature with\l"
	.string "red eyes that's dangerous… terrifying…\p"
	.string "Gotta investigate and see what's up…$"

Lobby_EventScript_Roxas_Text_9:
# 430 "data/maps/Lobby/scripts.pory"
	.string "Hey, sorry, I'd better get back to my\n"
	.string "research.\p"
	.string "Good luck - hope they actually give you\n"
	.string "the time of day!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 465 "data/maps/Lobby/scripts.pory"
	.string "I'm the expert on the species exclusive\n"
	.string "to Whack a Hack.\p"
	.string "I'll tell you all about them, but only the\n"
	.string "ones you've seen.\p"
	.string "I don't want to spoil the surprise!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 564 "data/maps/Lobby/scripts.pory"
	.string "Every species you've seen is common\n"
	.string "knowledge!\p"
	.string "Go battle in the rooms and you'll see\n"
	.string "what I'm talking about!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 569 "data/maps/Lobby/scripts.pory"
	.string "Which species would you like to know\n"
	.string "more about?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 572 "data/maps/Lobby/scripts.pory"
	.string "If you want to know more, I'll be here!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 643 "data/maps/Lobby/scripts.pory"
	.string "Since you don't have a Pokédex, its\n"
	.string "description is:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 646 "data/maps/Lobby/scripts.pory"
	.string "Its type is: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 648 "data/maps/Lobby/scripts.pory"
	.string "Its types are: {STR_VAR_2} and {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 650 "data/maps/Lobby/scripts.pory"
	.string "And I bet you didn't know this!\nIts abilities are:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 654 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 667 "data/maps/Lobby/scripts.pory"
	.string "One last fact! How good are its base\n"
	.string "stats?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 670 "data/maps/Lobby/scripts.pory"
	.string "And that's all about {STR_VAR_1}.\nHope you found it useful.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 675 "data/maps/Lobby/scripts.pory"
	.string "Did you know that on the back of your\n"
	.string "Trainer Card you can see your\l"
	.string "achievements?\p"
	.string "You can also see the requirements for\n"
	.string "earning each one!$"

Lobby_EventScript_Cope_Text_0:
# 685 "data/maps/Lobby/scripts.pory"
	.string "Hi {PLAYER}!\p"
	.string "Are you ready to take on the challenge?$"

Lobby_EventScript_Cope_Text_1:
# 688 "data/maps/Lobby/scripts.pory"
	.string "Have you managed to find Tile yet?\p"
	.string "He must be in one of the rooms... He's so\n"
	.string "slippery!\p"
	.string "Remember you can use the Devon\n"
	.string "Detector to find him.\p"
	.string "I bet every time you find him he'll give\n"
	.string "you a prize!$"

Lobby_EventScript_Cope_Text_2:
# 692 "data/maps/Lobby/scripts.pory"
	.string "Hi {PLAYER}!\p"
	.string "Have you seen Tile?$"

Lobby_EventScript_Cope_Text_3:
# 696 "data/maps/Lobby/scripts.pory"
	.string "What? You don't know who he is?\n"
	.string "He's my famous Kecleon.\p"
	.string "I've lost sight of him and have no idea\n"
	.string "where he's gotten to...\p"
	.string "On top of that, he stole the item kit I\n"
	.string "give to the challenge's trainers!\p"
	.string "Do me a favor and look for him.\n"
	.string "Here, take this.$"

Lobby_EventScript_Cope_Text_4:
# 701 "data/maps/Lobby/scripts.pory"
	.string "With the Devon Scope you can see\n"
	.string "where Tile is hiding.\p"
	.string "I've added a new feature that tells you\n"
	.string "if there's an invisible Pokémon nearby.\p"
	.string "Hope you find him!$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 710 "data/maps/Lobby/scripts.pory"
	.string "A guy in the Creative Zone gives you a\n"
	.string "gift for completing a special event.\p"
	.string "There's no way to guess what you have\n"
	.string "to do without watching the video.\p"
	.string "I even had to reorder two of the\n"
	.string "Pokémon on my team!\p"
	.string "That said, I liked the reward for the\n"
	.string "event, it was worth it!$"

Lobby_EventScript_BetaMonQuestionnaire_Text_0:
# 720 "data/maps/Lobby/scripts.pory"
	.string "Hey there! I'm the quiz master.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_1:
# 725 "data/maps/Lobby/scripts.pory"
	.string "So you haven't completed the challenge\n"
	.string "yet.\l"
	.string "...\l"
	.string "...\p"
	.string "When you beat it, come back and I'll give\n"
	.string "you a special quiz.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_2:
# 734 "data/maps/Lobby/scripts.pory"
	.string "I'll ask one question for each time\n"
	.string "you've completed the challenge.\p"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "Want me to ask you a question?$"

Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0:
# 748 "data/maps/Lobby/scripts.pory"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "Complete the challenge again and come\n"
	.string "back here.$"

Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0:
# 754 "data/maps/Lobby/scripts.pory"
	.string "You've already answered all my\n"
	.string "questions! What do you think of the\l"
	.string "Pokémon you've gotten?$"

Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0:
# 760 "data/maps/Lobby/scripts.pory"
	.string "All right. Come back whenever you like.$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0:
# 770 "data/maps/Lobby/scripts.pory"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "Want to keep answering?$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1:
# 778 "data/maps/Lobby/scripts.pory"
	.string "You've completed the challenge\n"
	.string "{STR_VAR_1} times.\p"
	.string "I've already asked you {STR_VAR_2}\n"
	.string "questions.\p"
	.string "You have {STR_VAR_3} attempts left.\p"
	.string "For now I don't have any more new\n"
	.string "questions for you.\p"
	.string "Come talk to me another time.$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0:
# 812 "data/maps/Lobby/scripts.pory"
	.string "Which Pokémon is orange, has a long tail,\n"
	.string "and everyone loves the one it evolves\l"
	.string "into?$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1:
# 814 "data/maps/Lobby/scripts.pory"
	.string "Raichu$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2:
# 815 "data/maps/Lobby/scripts.pory"
	.string "Arcanine$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3:
# 816 "data/maps/Lobby/scripts.pory"
	.string "Floatzel$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4:
# 817 "data/maps/Lobby/scripts.pory"
	.string "Simisear$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5:
# 822 "data/maps/Lobby/scripts.pory"
	.string "Well, this is the Pokémon you'll meet.$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0:
# 831 "data/maps/Lobby/scripts.pory"
	.string "My friend always has his Bro in tow.\p"
	.string "Which Pokémon is my friend?$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1:
# 833 "data/maps/Lobby/scripts.pory"
	.string "Slowking$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2:
# 834 "data/maps/Lobby/scripts.pory"
	.string "Slowbro$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3:
# 835 "data/maps/Lobby/scripts.pory"
	.string "Slowpoke$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4:
# 836 "data/maps/Lobby/scripts.pory"
	.string "Shellder$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5:
# 841 "data/maps/Lobby/scripts.pory"
	.string "Then off you go with his Bro.$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0:
# 850 "data/maps/Lobby/scripts.pory"
	.string "White as snow with a cute little face.\p"
	.string "Who is it?$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1:
# 852 "data/maps/Lobby/scripts.pory"
	.string "Whismur$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2:
# 853 "data/maps/Lobby/scripts.pory"
	.string "Aipom$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3:
# 854 "data/maps/Lobby/scripts.pory"
	.string "Dewgong$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4:
# 855 "data/maps/Lobby/scripts.pory"
	.string "Snorunt$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5:
# 860 "data/maps/Lobby/scripts.pory"
	.string "Well, this one looks like it!$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0:
# 869 "data/maps/Lobby/scripts.pory"
	.string "Captain Leek brandishes his sword in\n"
	.string "the forest.\p"
	.string "Who's really Captain Leek?$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1:
# 871 "data/maps/Lobby/scripts.pory"
	.string "Kartana$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2:
# 872 "data/maps/Lobby/scripts.pory"
	.string "Gallade$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3:
# 873 "data/maps/Lobby/scripts.pory"
	.string "Farfetch'd$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4:
# 874 "data/maps/Lobby/scripts.pory"
	.string "Scyther$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5:
# 879 "data/maps/Lobby/scripts.pory"
	.string "Exactly. That blade also sparked\n"
	.string "Madaamu's curiosity.$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0:
# 888 "data/maps/Lobby/scripts.pory"
	.string "Riddle me this.\p"
	.string "Which blue serpent has an orange\n"
	.string "evolution?$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1:
# 890 "data/maps/Lobby/scripts.pory"
	.string "Gyarados$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2:
# 891 "data/maps/Lobby/scripts.pory"
	.string "Dratini$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3:
# 892 "data/maps/Lobby/scripts.pory"
	.string "Milotic$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4:
# 893 "data/maps/Lobby/scripts.pory"
	.string "Dunsparce$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5:
# 898 "data/maps/Lobby/scripts.pory"
	.string "Well, its cousin has watched you battle\n"
	.string "and awaits you.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0:
# 907 "data/maps/Lobby/scripts.pory"
	.string "Riddle me this.\p"
	.string "Which Pokémon makes this cry?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1:
# 910 "data/maps/Lobby/scripts.pory"
	.string "Who was it?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2:
# 912 "data/maps/Lobby/scripts.pory"
	.string "Jirachi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3:
# 913 "data/maps/Lobby/scripts.pory"
	.string "Celebi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4:
# 914 "data/maps/Lobby/scripts.pory"
	.string "Mew$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5:
# 915 "data/maps/Lobby/scripts.pory"
	.string "Deoxys$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6:
# 923 "data/maps/Lobby/scripts.pory"
	.string "Oh, correct. Now try to guess this one.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7:
# 928 "data/maps/Lobby/scripts.pory"
	.string "Latios$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8:
# 929 "data/maps/Lobby/scripts.pory"
	.string "Latias$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9:
# 930 "data/maps/Lobby/scripts.pory"
	.string "Altaria$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10:
# 931 "data/maps/Lobby/scripts.pory"
	.string "Flygon$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11:
# 939 "data/maps/Lobby/scripts.pory"
	.string "Oh, right again. Now this one.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12:
# 944 "data/maps/Lobby/scripts.pory"
	.string "Blaziken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13:
# 945 "data/maps/Lobby/scripts.pory"
	.string "Combusken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14:
# 946 "data/maps/Lobby/scripts.pory"
	.string "Infernape$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15:
# 947 "data/maps/Lobby/scripts.pory"
	.string "Lucario$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16:
# 952 "data/maps/Lobby/scripts.pory"
	.string "Incredible, you got it again. That's\n"
	.string "impressive.\p"
	.string "Take this.$"

Lobby_EventScript_Turbo_Text_0:
# 974 "data/maps/Lobby/scripts.pory"
	.string "Did you know there's a turbo mode to\n"
	.string "blaze through the adventure at full\l"
	.string "speed?\p"
	.string "From the options menu you can set your\n"
	.string "text speed, walking speed, and turbo\l"
	.string "mode for battles!\p"
	.string "Care to give it a try?$"

Lobby_EventScript_Notes_Text_0:
# 979 "data/maps/Lobby/scripts.pory"
	.string "They look like notes full of stats and\n"
	.string "observations.\p"
	.string "Some pages are so worn they're hard to\n"
	.string "read.$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 166 "data/maps/Lobby/scripts.pory"
	.string "Well, well! A brave kid, huh?\nSo you think you'll win with THAT team...\pGood luck - you're gonna need it!$"

Lobby_Text_DifficultySelector_Cancelled::
# 191 "data/maps/Lobby/scripts.pory"
	.string "Got it! If you change your mind, I'll be\n"
	.string "around.$"

Lobby_Text_Roxas_PlayerCancelled::
# 438 "data/maps/Lobby/scripts.pory"
	.string "So you're scared of my legendary\n"
	.string "critter? And yet you won the rooms!$"

Lobby_Text_FailedToUnlock::
# 960 "data/maps/Lobby/scripts.pory"
	.string "Oh, you missed!$"
