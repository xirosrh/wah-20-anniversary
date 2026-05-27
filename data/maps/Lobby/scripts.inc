Lobby_MapScripts::
# 2 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Lobby_OnTransition
# 3 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Lobby_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 4 "data/maps/Lobby/scripts.pory"
	map_script_2 VAR_EXPLAIN_NEW_CHALLENGE_MODES_LOBBY, 1, Lobby_OnFrame_ExplainNewChallengeModes
	.2byte 0


Lobby_OnFrame_ExplainNewChallengeModes::
# 9 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Lobby_OnFrame_ExplainNewChallengeModes_Movement_0
# 10 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 11 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 12 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 13 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_HeartWithDelay48
# 14 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 15 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 16 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_JumpInPlaceRight
# 17 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 18 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_JumpInPlaceRight
# 19 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 20 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 21 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 22 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 23 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_JumpInPlaceRight
# 24 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 25 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 26 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 27 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 28 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_WEST
# 29 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 30 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_ThinkingWithDelay48
# 31 "data/maps/Lobby/scripts.pory"
	delay 40
# 32 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 33 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_OnFrame_ExplainNewChallengeModes_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 34 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 35 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_HappyWithDelay48
# 36 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Lobby_OnFrame_ExplainNewChallengeModes_Movement_1
# 37 "data/maps/Lobby/scripts.pory"
	setvar VAR_EXPLAIN_NEW_CHALLENGE_MODES_LOBBY, 2
	end


Lobby_OnTransition::
# 42 "data/maps/Lobby/scripts.pory"
	setrespawn HEAL_LOCATION_LOBBY
	end


Lobby_EventScript_StartChallenge::
# 47 "data/maps/Lobby/scripts.pory"
	lock
# 48 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_FacePlayer
# 49 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 50 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_DoubleExclamationMarkWithDelay48
# 51 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 52 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 53 "data/maps/Lobby/scripts.pory"
	delay 20
# 54 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 55 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_StartChallenge_2
Lobby_EventScript_StartChallenge_1:
# 68 "data/maps/Lobby/scripts.pory"
	setspeaker SP_NAME_COPE
# 69 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_StartChallenge_Text_3
# 70 "data/maps/Lobby/scripts.pory"
	waitmessage
# 71 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_4, 0
# 72 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_5, 1
# 73 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_6, 2
# 74 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 4
# 75 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 76 "data/maps/Lobby/scripts.pory"
	closemessage
# 77 "data/maps/Lobby/scripts.pory"
	delay 10
# 78 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 79 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_5
# 84 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_6
# 90 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_StartChallenge_7
# 97 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	return

Lobby_EventScript_StartChallenge_2:
# 56 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_1, MSGBOX_YESNO, speaker = SP_NAME_COPE
# 57 "data/maps/Lobby/scripts.pory"
	closemessage
# 58 "data/maps/Lobby/scripts.pory"
	delay 10
# 59 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_9
# 65 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_5:
# 80 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 81 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 82 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 83 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_6:
# 85 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE
# 86 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 87 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 88 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 89 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_7:
# 91 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE
# 92 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 93 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 94 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 95 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_9:
# 60 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 61 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 62 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 63 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	goto Lobby_EventScript_StartChallenge_1


Lobby_StartChallenge_CancelledChallenge::
# 102 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 103 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_Surprise
# 104 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 105 "data/maps/Lobby/scripts.pory"
	delay 60
# 106 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 107 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 108 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 109 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_EnterOmegaRoom::
# 114 "data/maps/Lobby/scripts.pory"
	special SetWahChallengeInitialAchievementFlags
# 115 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_Kecleon_ResetFlags
# 116 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 117 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 118 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 119 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 120 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 121 "data/maps/Lobby/scripts.pory"
	waitstate
# 122 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 128 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 129 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 130 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 131 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 132 "data/maps/Lobby/scripts.pory"
	delay 5
# 133 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 134 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 135 "data/maps/Lobby/scripts.pory"
	delay 5
# 136 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 137 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 143 "data/maps/Lobby/scripts.pory"
	lock
# 144 "data/maps/Lobby/scripts.pory"
	faceplayer
# 145 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 146 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 155 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 157 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 158 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 147 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 148 "data/maps/Lobby/scripts.pory"
	waitstate
# 149 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 152 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 150 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 169 "data/maps/Lobby/scripts.pory"
	lock
# 170 "data/maps/Lobby/scripts.pory"
	faceplayer
# 171 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 172 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 181 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 183 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 184 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 173 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 174 "data/maps/Lobby/scripts.pory"
	waitstate
# 175 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 178 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 176 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_BufferVictoryWordFromCountVar::
# 194 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_2
# 197 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferVictoryWordFromCountVar_1:
# 199 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_6
# 202 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2
Lobby_EventScript_BufferVictoryWordFromCountVar_5:
	return

Lobby_EventScript_BufferVictoryWordFromCountVar_2:
# 195 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_1

Lobby_EventScript_BufferVictoryWordFromCountVar_6:
# 200 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_5


Lobby_EventScript_BufferTimeWordFromCountVar::
# 208 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_2
# 211 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferTimeWordFromCountVar_1:
# 213 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_6
# 216 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_1
Lobby_EventScript_BufferTimeWordFromCountVar_5:
	return

Lobby_EventScript_BufferTimeWordFromCountVar_2:
# 209 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_1

Lobby_EventScript_BufferTimeWordFromCountVar_6:
# 214 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_5


Lobby_EventScript_ChallengeHistorian::
# 222 "data/maps/Lobby/scripts.pory"
	lock
# 223 "data/maps/Lobby/scripts.pory"
	faceplayer
# 225 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_0, MSGBOX_AUTOCLOSE
# 226 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 227 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_ChallengeHistorian_2
# 238 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 239 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 240 "data/maps/Lobby/scripts.pory"
	faceplayer
# 241 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT
# 242 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 243 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_2
# 244 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT
# 245 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 246 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_3
# 247 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT
# 248 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 249 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_4
# 250 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_COMPLETION_COUNT
# 251 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferTimeWordFromCountVar
# 252 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_5
# 253 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 5
	goto_if_gt Lobby_EventScript_ChallengeHistorian_5
# 259 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_7, MSGBOX_AUTOCLOSE
# 260 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 261 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
Lobby_EventScript_ChallengeHistorian_4:
# 263 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 264 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_2:
# 228 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 229 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 230 "data/maps/Lobby/scripts.pory"
	faceplayer
# 231 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_1, MSGBOX_AUTOCLOSE
# 232 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 233 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 234 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 235 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_5:
# 254 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_6, MSGBOX_AUTOCLOSE
# 255 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 256 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
	goto Lobby_EventScript_ChallengeHistorian_4


Lobby_EventScript_Shop::
# 270 "data/maps/Lobby/scripts.pory"
	lock
# 271 "data/maps/Lobby/scripts.pory"
	faceplayer
# 272 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Shop_4
Lobby_EventScript_Shop_3:
# 277 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_1
# 278 "data/maps/Lobby/scripts.pory"
	waitmessage
Lobby_EventScript_Shop_1:
# 280 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 281 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Shop_2:
# 273 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 274 "data/maps/Lobby/scripts.pory"
	waitmessage
# 275 "data/maps/Lobby/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto Lobby_EventScript_Shop_1

Lobby_EventScript_Shop_4:
# 272 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, Lobby_EventScript_Shop_2
	goto Lobby_EventScript_Shop_3


Lobby_EventScript_Roxas_IntroFirstBattle::
# 286 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 287 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 290 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 292 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 293 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 294 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 295 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 296 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 297 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 298 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 299 "data/maps/Lobby/scripts.pory"
	delay 20
# 300 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 301 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 302 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 303 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 304 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 305 "data/maps/Lobby/scripts.pory"
	delay 20
# 306 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 288 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 311 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 312 "data/maps/Lobby/scripts.pory"
	closemessage
# 313 "data/maps/Lobby/scripts.pory"
	delay 20
# 314 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 318 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 319 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 315 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 325 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 326 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 329 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 333 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 327 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 330 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 340 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 341 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 342 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 343 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 344 "data/maps/Lobby/scripts.pory"
	waitstate
# 345 "data/maps/Lobby/scripts.pory"
	lock
# 346 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 352 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 347 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 348 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 349 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 357 "data/maps/Lobby/scripts.pory"
	lock
# 358 "data/maps/Lobby/scripts.pory"
	faceplayer
# 359 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 410 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 411 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 412 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 413 "data/maps/Lobby/scripts.pory"
	delay 20
# 414 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 415 "data/maps/Lobby/scripts.pory"
	delay 20
# 416 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 417 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 418 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 419 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 420 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 421 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 422 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 423 "data/maps/Lobby/scripts.pory"
	lock
# 424 "data/maps/Lobby/scripts.pory"
	delay 20
# 425 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 426 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 427 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 428 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 360 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 361 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 362 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 365 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 367 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 368 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 369 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 373 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 378 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 379 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 382 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 383 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 384 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 385 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 386 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 387 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 388 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 395 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 396 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 399 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 401 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 402 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 403 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 405 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 406 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 407 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 363 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 370 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 371 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 374 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 375 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 389 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 390 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 391 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 392 "data/maps/Lobby/scripts.pory"
	delay 40
# 393 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 397 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 440 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 441 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 442 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 445 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 448 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 451 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 443 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 446 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 449 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 452 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 460 "data/maps/Lobby/scripts.pory"
	lock
# 461 "data/maps/Lobby/scripts.pory"
	faceplayer
# 462 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 463 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 464 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 465 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 469 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 470 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 471 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 476 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 477 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 482 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 483 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 488 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 489 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 494 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 495 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 500 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 501 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 506 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_JARDINO
# 507 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 512 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_OCEADINO
# 513 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 518 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_TYRADINO
# 519 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25:
# 524 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 525 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28:
# 530 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 531 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 536 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MICAEL
# 537 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 542 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MOLIKAI
# 543 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 548 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_DIRAEI
# 549 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 554 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_LUGIA_SHADOW
# 555 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43:
# 560 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47
# 565 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 15
# 566 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 567 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 568 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50
# 573 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 574 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54
# 578 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55
# 582 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56
# 586 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57
# 590 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58
# 594 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59
# 598 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60
# 602 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61
# 606 "data/maps/Lobby/scripts.pory"
	case 8, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62
# 610 "data/maps/Lobby/scripts.pory"
	case 9, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63
# 614 "data/maps/Lobby/scripts.pory"
	case 10, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64
# 618 "data/maps/Lobby/scripts.pory"
	case 11, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65
# 622 "data/maps/Lobby/scripts.pory"
	case 12, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66
# 626 "data/maps/Lobby/scripts.pory"
	case 13, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67
# 630 "data/maps/Lobby/scripts.pory"
	case 14, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52:
# 635 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 472 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 473 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 474 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 478 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 479 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 480 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 484 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 485 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 486 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 490 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 491 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 492 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 496 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 497 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 498 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 502 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 503 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 504 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 508 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_JARDINO
# 509 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 510 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 514 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OCEADINO
# 515 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 516 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 520 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYRADINO
# 521 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 8
# 522 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 526 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 527 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 9
# 528 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32:
# 532 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 533 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 10
# 534 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 538 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MICAEL
# 539 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 11
# 540 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 544 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLIKAI
# 545 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 12
# 546 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41:
# 550 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIRAEI
# 551 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 13
# 552 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44:
# 556 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_SHADOW
# 557 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 14
# 558 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47:
# 561 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 562 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50:
# 569 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 570 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54:
# 575 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 576 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 577 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55:
# 579 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 580 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 581 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56:
# 583 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 584 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 585 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57:
# 587 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 588 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 589 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58:
# 591 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 592 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 593 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59:
# 595 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 596 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 597 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60:
# 599 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_JARDINO, 10, 3
# 600 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_JARDINO
# 601 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61:
# 603 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_OCEADINO, 10, 3
# 604 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_OCEADINO
# 605 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62:
# 607 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_TYRADINO, 10, 3
# 608 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRADINO
# 609 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63:
# 611 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 612 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 613 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64:
# 615 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 616 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 617 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65:
# 619 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MICAEL, 10, 3
# 620 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MICAEL
# 621 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66:
# 623 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MOLIKAI, 10, 3
# 624 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLIKAI
# 625 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67:
# 627 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_DIRAEI, 10, 3
# 628 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIRAEI
# 629 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68:
# 631 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_LUGIA_SHADOW, 10, 3
# 632 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA_SHADOW
# 633 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52


Lobby_EventScript_ShowFakemonDexInfo::
# 639 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 640 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 641 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 642 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 645 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 647 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 648 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 649 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 650 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 653 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 654 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 655 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 658 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 659 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 660 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 663 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 664 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 665 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 666 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 667 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 643 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 651 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 656 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 661 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 672 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Cope::
# 677 "data/maps/Lobby/scripts.pory"
	lock
# 678 "data/maps/Lobby/scripts.pory"
	faceplayer
# 679 "data/maps/Lobby/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 680 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_Cope_2
# 689 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 690 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 691 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Lobby_EventScript_Cope_Movement_0
# 692 "data/maps/Lobby/scripts.pory"
	waitse
# 693 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 694 "data/maps/Lobby/scripts.pory"
	delay 10
# 695 "data/maps/Lobby/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 696 "data/maps/Lobby/scripts.pory"
	closemessage
# 697 "data/maps/Lobby/scripts.pory"
	delay 20
# 698 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
Lobby_EventScript_Cope_1:
# 700 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Cope_2:
# 682 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 683 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 684 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_SmileWithDelay48
# 685 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
	goto Lobby_EventScript_Cope_1


Lobby_EventScript_QREventInfoKid::
# 705 "data/maps/Lobby/scripts.pory"
	lock
# 706 "data/maps/Lobby/scripts.pory"
	faceplayer
# 707 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 708 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 709 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 710 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire::
# 715 "data/maps/Lobby/scripts.pory"
	lock
# 716 "data/maps/Lobby/scripts.pory"
	faceplayer
# 717 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_0, MSGBOX_AUTOCLOSE
# 718 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 719 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_2
# 726 "data/maps/Lobby/scripts.pory"
	delay 20
# 727 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 728 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 729 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 730 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_5
# 737 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_6
# 740 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_2:
# 720 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 721 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Surprise
# 722 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_1, MSGBOX_AUTOCLOSE
# 723 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_5:
# 731 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_2, MSGBOX_YESNO
# 732 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_8
# 735 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_6:
# 738 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_8:
# 733 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	return


Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft::
# 745 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0, MSGBOX_AUTOCLOSE
# 746 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions::
# 751 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0, MSGBOX_AUTOCLOSE
# 752 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater::
# 757 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0, MSGBOX_AUTOCLOSE
# 758 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NextQuestion::
# 763 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 764 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 765 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 766 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2
# 772 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3
# 774 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_NONE_THIS_TALK, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4
# 779 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2:
# 767 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0, MSGBOX_YESNO
# 768 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7
Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6:
# 771 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3:
# 773 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4:
# 775 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1, MSGBOX_AUTOCLOSE
# 776 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7:
# 769 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6


Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion::
# 784 "data/maps/Lobby/scripts.pory"
	addvar VAR_BETA_MON_QUESTIONNAIRE_ASK_COUNT, 1
# 785 "data/maps/Lobby/scripts.pory"
	switch VAR_0x8004
# 786 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_GOROCHU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3
# 789 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_TAABAN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4
# 792 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_BOMUSHIKAA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5
# 795 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_MADAAMU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6
# 798 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_AKUERIA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7
# 801 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_LATIKEN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8
Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1:
# 805 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion
	return

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3:
# 787 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Gorochu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4:
# 790 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Taaban
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5:
# 793 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6:
# 796 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Madaamu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7:
# 799 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Akueria
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8:
# 802 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Latiken
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1


Lobby_EventScript_BetaMonQuestionnaire_Gorochu::
# 809 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0
# 810 "data/maps/Lobby/scripts.pory"
	waitmessage
# 811 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1, 0
# 812 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2, 1
# 813 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3, 2
# 814 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4, 3
# 815 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 816 "data/maps/Lobby/scripts.pory"
	closemessage
# 817 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2
# 822 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2:
# 818 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_GOROCHU
# 819 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5, MSGBOX_AUTOCLOSE
# 820 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1


Lobby_EventScript_BetaMonQuestionnaire_Taaban::
# 828 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0
# 829 "data/maps/Lobby/scripts.pory"
	waitmessage
# 830 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1, 0
# 831 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2, 1
# 832 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3, 2
# 833 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4, 3
# 834 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 835 "data/maps/Lobby/scripts.pory"
	closemessage
# 836 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Taaban_2
# 841 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Taaban_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Taaban_2:
# 837 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_TAABAN
# 838 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5, MSGBOX_AUTOCLOSE
# 839 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Taaban_1


Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa::
# 847 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0
# 848 "data/maps/Lobby/scripts.pory"
	waitmessage
# 849 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1, 0
# 850 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2, 1
# 851 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3, 2
# 852 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4, 3
# 853 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 854 "data/maps/Lobby/scripts.pory"
	closemessage
# 855 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2
# 860 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2:
# 856 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_BOMUSHIKAA
# 857 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5, MSGBOX_AUTOCLOSE
# 858 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1


Lobby_EventScript_BetaMonQuestionnaire_Madaamu::
# 866 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0
# 867 "data/maps/Lobby/scripts.pory"
	waitmessage
# 868 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1, 0
# 869 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2, 1
# 870 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3, 2
# 871 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4, 3
# 872 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 873 "data/maps/Lobby/scripts.pory"
	closemessage
# 874 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2
# 879 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2:
# 875 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_MADAAMU
# 876 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5, MSGBOX_AUTOCLOSE
# 877 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1


Lobby_EventScript_BetaMonQuestionnaire_Akueria::
# 885 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0
# 886 "data/maps/Lobby/scripts.pory"
	waitmessage
# 887 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1, 0
# 888 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2, 1
# 889 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3, 2
# 890 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4, 3
# 891 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 892 "data/maps/Lobby/scripts.pory"
	closemessage
# 893 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Akueria_2
# 898 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Akueria_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Akueria_2:
# 894 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_AKUERIA
# 895 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5, MSGBOX_AUTOCLOSE
# 896 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Akueria_1


Lobby_EventScript_BetaMonQuestionnaire_Latiken::
# 904 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0, MSGBOX_AUTOCLOSE
# 905 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
# 906 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 907 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 908 "data/maps/Lobby/scripts.pory"
	waitmessage
# 909 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2, 0
# 910 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3, 1
# 911 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4, 2
# 912 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5, 3
# 913 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 914 "data/maps/Lobby/scripts.pory"
	closemessage
# 915 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_2
# 920 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6, MSGBOX_AUTOCLOSE
# 921 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
# 922 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 923 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 924 "data/maps/Lobby/scripts.pory"
	waitmessage
# 925 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7, 0
# 926 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8, 1
# 927 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9, 2
# 928 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10, 3
# 929 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 930 "data/maps/Lobby/scripts.pory"
	closemessage
# 931 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_5
# 936 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11, MSGBOX_AUTOCLOSE
# 937 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_BLAZIKEN, CRY_MODE_NORMAL
# 938 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 939 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 940 "data/maps/Lobby/scripts.pory"
	waitmessage
# 941 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12, 0
# 942 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13, 1
# 943 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14, 2
# 944 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15, 3
# 945 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 946 "data/maps/Lobby/scripts.pory"
	closemessage
# 947 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Latiken_8
# 952 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Latiken_7:
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_2:
# 916 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_5:
# 932 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_8:
# 948 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_LATIKEN
# 949 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16, MSGBOX_AUTOCLOSE
# 950 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Latiken_7


Lobby_EventScript_Pokebox::
# 962 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_C, 8
# 963 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_D, 3
# 964 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_OFF
# 965 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_ON
# 966 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


Lobby_EventScript_Turbo::
# 971 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Turbo_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Notes::
# 976 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Notes_Text_0, MSGBOX_SIGN
	end


# 9 "data/maps/Lobby/scripts.pory"
Lobby_OnFrame_ExplainNewChallengeModes_Movement_0:
# 9 "data/maps/Lobby/scripts.pory"
	walk_down
# 9 "data/maps/Lobby/scripts.pory"
	walk_down
# 9 "data/maps/Lobby/scripts.pory"
	walk_down
# 9 "data/maps/Lobby/scripts.pory"
	walk_down
# 9 "data/maps/Lobby/scripts.pory"
	face_right
	step_end

# 36 "data/maps/Lobby/scripts.pory"
Lobby_OnFrame_ExplainNewChallengeModes_Movement_1:
# 36 "data/maps/Lobby/scripts.pory"
	walk_up
# 36 "data/maps/Lobby/scripts.pory"
	walk_up
# 36 "data/maps/Lobby/scripts.pory"
	walk_up
# 36 "data/maps/Lobby/scripts.pory"
	walk_up
# 36 "data/maps/Lobby/scripts.pory"
	face_down
	step_end

# 293 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 293 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 293 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 295 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 295 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 295 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 295 "data/maps/Lobby/scripts.pory"
	face_player
# 295 "data/maps/Lobby/scripts.pory"
	delay_16
# 295 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 691 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Cope_Movement_0:
# 691 "data/maps/Lobby/scripts.pory"
	emote_question_mark
	step_end

Lobby_OnFrame_ExplainNewChallengeModes_Text_0:
# 11 "data/maps/Lobby/scripts.pory"
	.string "¡Increíble, {PLAYER}! Has superado el\n"
	.string "desafío por completo.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_1:
# 14 "data/maps/Lobby/scripts.pory"
	.string "¡Pero no creas que esto ha terminado!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_2:
# 19 "data/maps/Lobby/scripts.pory"
	.string "¡Todavía tienes muchas cosas por\n"
	.string "hacer!\p"
	.string "A partir de ahora has desbloqueado\n"
	.string "nuevas formas de jugar el desafío.$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_3:
# 21 "data/maps/Lobby/scripts.pory"
	.string "¡Ahora puedes combatir en modalidad\n"
	.string "{COLOR BLUE}batallas dobles{COLOR DARK_GRAY}!\p"
	.string "Cada combate será en formato doble:\n"
	.string "dos Pokémon en campo, ¡el doble de caos!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_4:
# 24 "data/maps/Lobby/scripts.pory"
	.string "¿Y si quieres pensar un poco más?\n"
	.string "Entonces las {COLOR RED}batallas inversas{COLOR DARK_GRAY} son\l"
	.string "para ti!\p"
	.string "¡La tabla de tipos está al revés! Lo\n"
	.string "resistente será débil, y viceversa.\p"
	.string "¡Ya no podrás combatir en modo\n"
	.string "automático!$"

Lobby_OnFrame_ExplainNewChallengeModes_Text_5:
# 27 "data/maps/Lobby/scripts.pory"
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
# 33 "data/maps/Lobby/scripts.pory"
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
# 51 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 56 "data/maps/Lobby/scripts.pory"
	.string "¿Así que ya estás list{OA} para intentar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_2:
# 62 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Adelante, ¡te deseo mucha\n"
	.string "suerte y sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_3:
# 69 "data/maps/Lobby/scripts.pory"
	.string "¿En qué modo quieres afrontar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_4:
# 71 "data/maps/Lobby/scripts.pory"
	.string "Estándar$"

Lobby_EventScript_StartChallenge_Text_5:
# 72 "data/maps/Lobby/scripts.pory"
	.string "Batallas dobles$"

Lobby_EventScript_StartChallenge_Text_6:
# 73 "data/maps/Lobby/scripts.pory"
	.string "Batallas inversas$"

Lobby_EventScript_StartChallenge_Text_7:
# 74 "data/maps/Lobby/scripts.pory"
	.string "Salir$"

Lobby_EventScript_StartChallenge_Text_8:
# 88 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas dobles.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_9:
# 94 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas inversas.\p"
	.string "Las efectividades de tipo se invierten:\n"
	.string "lo que normalmente es súper efectivo\l"
	.string "será poco efectivo y viceversa.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_StartChallenge_CancelledChallenge_Text_0:
# 104 "data/maps/Lobby/scripts.pory"
	.string "¿Así que no te sientes list{OA}?$"

Lobby_StartChallenge_CancelledChallenge_Text_1:
# 106 "data/maps/Lobby/scripts.pory"
	.string "Recuerda que las personas de la sala de\n"
	.string "espera pueden ayudar en tu\l"
	.string "preparación.$"

Lobby_EventScript_TeamSelector_Text_0:
# 145 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que tu equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 150 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 171 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy la encargada de la selección\n"
	.string "de dificultad del desafío.\p"
	.string "No parece que la dificultad actual sea\n"
	.string "la adecuada para ti.\p"
	.string "¿Quieres cambiar el nivel de dificultad?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 176 "data/maps/Lobby/scripts.pory"
	.string "¡Listo! La dificultad ha sido actualizada.\n¡Buena suerte con el desafío!$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0:
# 195 "data/maps/Lobby/scripts.pory"
	.string "0$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1:
# 200 "data/maps/Lobby/scripts.pory"
	.string "victoria$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2:
# 202 "data/maps/Lobby/scripts.pory"
	.string "victorias$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_0:
# 214 "data/maps/Lobby/scripts.pory"
	.string "vez$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_1:
# 216 "data/maps/Lobby/scripts.pory"
	.string "veces$"

Lobby_EventScript_ChallengeHistorian_Text_0:
# 225 "data/maps/Lobby/scripts.pory"
	.string "¡Ey, {PLAYER}!\p"
	.string "No trabajo aquí ni nada, pero me\n"
	.string "encanta sacar estadísticas.\p"
	.string "Me quedo en la sala de espera\n"
	.string "observando a todos los que entran y lo\l"
	.string "anoto todo.$"

Lobby_EventScript_ChallengeHistorian_Text_1:
# 231 "data/maps/Lobby/scripts.pory"
	.string "Veo que aún no has completado el\n"
	.string "desafío ni una vez.\p"
	.string "Todavía no te has ganado un lugar en\n"
	.string "mis notas.$"

Lobby_EventScript_ChallengeHistorian_Text_2:
# 243 "data/maps/Lobby/scripts.pory"
	.string "Según mi cuaderno, en modo estándar\n"
	.string "llevas {STR_VAR_1} {STR_VAR_2}.\p"
	.string "¡Nada mal, de verdad!$"

Lobby_EventScript_ChallengeHistorian_Text_3:
# 246 "data/maps/Lobby/scripts.pory"
	.string "En batallas dobles tienes\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ahí se nota quién piensa dos turnos por\n"
	.string "adelantado.$"

Lobby_EventScript_ChallengeHistorian_Text_4:
# 249 "data/maps/Lobby/scripts.pory"
	.string "Y en batallas invertidas sumas\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ese modo le da vuelta la cabeza a\n"
	.string "cualquiera.$"

Lobby_EventScript_ChallengeHistorian_Text_5:
# 252 "data/maps/Lobby/scripts.pory"
	.string "En total, has completado el desafío\n"
	.string "{STR_VAR_1} {STR_VAR_2}.$"

Lobby_EventScript_ChallengeHistorian_Text_6:
# 254 "data/maps/Lobby/scripts.pory"
	.string "¡Si sigues así, voy a tener que comprar\n"
	.string "otro cuaderno para registrar tus\l"
	.string "números!$"

Lobby_EventScript_ChallengeHistorian_Text_7:
# 259 "data/maps/Lobby/scripts.pory"
	.string "Aún no son tantas victorias, pero sigue\n"
	.string "así.$"

Lobby_EventScript_Shop_Text_0:
# 273 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¡Hemos ampliado el catálogo!\p"
	.string "Ahora también puedes comprar objetos\n"
	.string "de combate.\p"
	.string "¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 277 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 288 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 290 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 296 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 300 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la última\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 303 "data/maps/Lobby/scripts.pory"
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
# 311 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tú de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 327 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: elige\n"
	.string "a tres de tus bichos.\p"
	.string "Yo voy a salir con mi legendario, así que\n"
	.string "más te vale elegir bien.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 333 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate para\n"
	.string "enfrentar a mi legendario.$"

Lobby_EventScript_Roxas_Text_0:
# 382 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 384 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 391 "data/maps/Lobby/scripts.pory"
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
# 397 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 399 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 403 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 410 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 414 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 422 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras, loco!$"

Lobby_EventScript_Roxas_Text_9:
# 425 "data/maps/Lobby/scripts.pory"
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
# 427 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 462 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 561 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 566 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 569 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 640 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokédex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 643 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 645 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 647 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 651 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 664 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 667 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 672 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_EventScript_Cope_Text_0:
# 682 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Estás list{OA} para intentar el desafío?$"

Lobby_EventScript_Cope_Text_1:
# 685 "data/maps/Lobby/scripts.pory"
	.string "¿Y ya has podido encontrar a Tile?\p"
	.string "Debe encontrarse en alguna sala... ¡Es\n"
	.string "tan escurridizo!\p"
	.string "Recuerda que puedes usar el Detector\n"
	.string "Devon para encontrarlo.\p"
	.string "¡Seguro cada vez que lo encuentres te\n"
	.string "dará un premio!$"

Lobby_EventScript_Cope_Text_2:
# 689 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Has visto a Tile?$"

Lobby_EventScript_Cope_Text_3:
# 693 "data/maps/Lobby/scripts.pory"
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
# 698 "data/maps/Lobby/scripts.pory"
	.string "Con el Detector Devon podrás ver dónde\n"
	.string "se esconde Tile.\p"
	.string "Le he agregado una nueva\n"
	.string "característica que permite saber si\l"
	.string "hay un Pokémon invisible cerca.\p"
	.string "¡Espero lo encuentres!$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 707 "data/maps/Lobby/scripts.pory"
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
# 717 "data/maps/Lobby/scripts.pory"
	.string "¡Buenas! Soy el maestro de los\n"
	.string "cuestionarios.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_1:
# 722 "data/maps/Lobby/scripts.pory"
	.string "Así que aún no has completado el\n"
	.string "desafío.\l"
	.string "...\l"
	.string "...\p"
	.string "Cuando lo superes, vuelve y te haré un\n"
	.string "cuestionario especial.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_2:
# 731 "data/maps/Lobby/scripts.pory"
	.string "Te haré una pregunta por cada vez que\n"
	.string "hayas completado el desafío.\p"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "¿Quieres que te haga una pregunta?$"

Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0:
# 745 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "Completa el desafío otra vez y vuelve\n"
	.string "por aquí.$"

Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0:
# 751 "data/maps/Lobby/scripts.pory"
	.string "¡Ya has respondido todas mis\n"
	.string "preguntas! ¿Qué te parecen los Pokémon\l"
	.string "que has conseguido?$"

Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0:
# 757 "data/maps/Lobby/scripts.pory"
	.string "De acuerdo. Puedes volver cuando\n"
	.string "quieras.$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0:
# 767 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "¿Quieres seguir respondiendo?$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1:
# 775 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "Por ahora no tengo más preguntas\n"
	.string "distintas para hacerte.\p"
	.string "Vuelve a hablarme en otro momento.$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0:
# 809 "data/maps/Lobby/scripts.pory"
	.string "¿Qué Pokémon es naranja, tiene una cola\n"
	.string "larga y a todo el mundo le encanta el\l"
	.string "que evoluciona en él?$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1:
# 811 "data/maps/Lobby/scripts.pory"
	.string "Raichu$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2:
# 812 "data/maps/Lobby/scripts.pory"
	.string "Arcanine$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3:
# 813 "data/maps/Lobby/scripts.pory"
	.string "Floatzel$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4:
# 814 "data/maps/Lobby/scripts.pory"
	.string "Simisear$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5:
# 819 "data/maps/Lobby/scripts.pory"
	.string "Pues con este Pokémon te encontrarás.$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0:
# 828 "data/maps/Lobby/scripts.pory"
	.string "Mi amigo siempre va con su Bro detrás.\p"
	.string "¿Qué Pokémon es mi amigo?$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1:
# 830 "data/maps/Lobby/scripts.pory"
	.string "Slowking$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2:
# 831 "data/maps/Lobby/scripts.pory"
	.string "Slowbro$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3:
# 832 "data/maps/Lobby/scripts.pory"
	.string "Slowpoke$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4:
# 833 "data/maps/Lobby/scripts.pory"
	.string "Shellder$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5:
# 838 "data/maps/Lobby/scripts.pory"
	.string "Pues con su Bro te irás.$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0:
# 847 "data/maps/Lobby/scripts.pory"
	.string "Blanco como la nieve y una carita mona.\p"
	.string "¿Quién es?$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1:
# 849 "data/maps/Lobby/scripts.pory"
	.string "Whismur$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2:
# 850 "data/maps/Lobby/scripts.pory"
	.string "Aipom$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3:
# 851 "data/maps/Lobby/scripts.pory"
	.string "Dewgong$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4:
# 852 "data/maps/Lobby/scripts.pory"
	.string "Snorunt$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5:
# 857 "data/maps/Lobby/scripts.pory"
	.string "¡Pues este se le parece!$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0:
# 866 "data/maps/Lobby/scripts.pory"
	.string "El Capitán Puerro blande su espada en\n"
	.string "el bosque.\p"
	.string "¿Quién es realmente el Capitán Puerro?$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1:
# 868 "data/maps/Lobby/scripts.pory"
	.string "Kartana$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2:
# 869 "data/maps/Lobby/scripts.pory"
	.string "Gallade$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3:
# 870 "data/maps/Lobby/scripts.pory"
	.string "Farfetch'd$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4:
# 871 "data/maps/Lobby/scripts.pory"
	.string "Scyther$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5:
# 876 "data/maps/Lobby/scripts.pory"
	.string "Exacto. Ese filo también despertó la\n"
	.string "curiosidad de Madaamu.$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0:
# 885 "data/maps/Lobby/scripts.pory"
	.string "Adivina, adivinanza.\p"
	.string "¿Qué serpiente azul tiene una evolución\n"
	.string "naranja?$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1:
# 887 "data/maps/Lobby/scripts.pory"
	.string "Gyarados$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2:
# 888 "data/maps/Lobby/scripts.pory"
	.string "Dratini$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3:
# 889 "data/maps/Lobby/scripts.pory"
	.string "Milotic$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4:
# 890 "data/maps/Lobby/scripts.pory"
	.string "Dunsparce$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5:
# 895 "data/maps/Lobby/scripts.pory"
	.string "Pues su primo te ha visto luchar y te\n"
	.string "espera.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0:
# 904 "data/maps/Lobby/scripts.pory"
	.string "Adivina, adivinanza.\p"
	.string "¿Qué Pokémon hace este grito?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1:
# 907 "data/maps/Lobby/scripts.pory"
	.string "¿Quién fue?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2:
# 909 "data/maps/Lobby/scripts.pory"
	.string "Jirachi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3:
# 910 "data/maps/Lobby/scripts.pory"
	.string "Celebi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4:
# 911 "data/maps/Lobby/scripts.pory"
	.string "Mew$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5:
# 912 "data/maps/Lobby/scripts.pory"
	.string "Deoxys$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6:
# 920 "data/maps/Lobby/scripts.pory"
	.string "Oh, correcto. Ahora mismo intenta\n"
	.string "adivinar este.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7:
# 925 "data/maps/Lobby/scripts.pory"
	.string "Latios$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8:
# 926 "data/maps/Lobby/scripts.pory"
	.string "Latias$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9:
# 927 "data/maps/Lobby/scripts.pory"
	.string "Altaria$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10:
# 928 "data/maps/Lobby/scripts.pory"
	.string "Flygon$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11:
# 936 "data/maps/Lobby/scripts.pory"
	.string "Oh, volviste a acertar. Ahora este.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12:
# 941 "data/maps/Lobby/scripts.pory"
	.string "Blaziken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13:
# 942 "data/maps/Lobby/scripts.pory"
	.string "Combusken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14:
# 943 "data/maps/Lobby/scripts.pory"
	.string "Infernape$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15:
# 944 "data/maps/Lobby/scripts.pory"
	.string "Lucario$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16:
# 949 "data/maps/Lobby/scripts.pory"
	.string "Increíble, acertaste otra vez. Es\n"
	.string "impresionante.\p"
	.string "Ten esto.$"

Lobby_EventScript_Turbo_Text_0:
# 971 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que existe un modo turbo para\n"
	.string "vivir la aventura a toda velocidad?\p"
	.string "Desde el menú de opciones puedes\n"
	.string "configurar tu velocidad de texto, de\l"
	.string "caminar, ¡y un turbo para los combates!\p"
	.string "¿Te animas a probarlo?$"

Lobby_EventScript_Notes_Text_0:
# 976 "data/maps/Lobby/scripts.pory"
	.string "Parecen apuntes llenos de\n"
	.string "estadísticas y observaciones.\p"
	.string "Algunas páginas están tan gastadas\n"
	.string "que cuesta leerlas.$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 163 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_DifficultySelector_Cancelled::
# 188 "data/maps/Lobby/scripts.pory"
	.string "¡Entendido! Si cambias de opinión,\n"
	.string "estaré por aquí.$"

Lobby_Text_Roxas_PlayerCancelled::
# 435 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_Text_FailedToUnlock::
# 957 "data/maps/Lobby/scripts.pory"
	.string "Oh, ¡fallaste!$"
