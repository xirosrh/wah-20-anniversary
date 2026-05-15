Lobby_MapScripts::
# 2 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Lobby_OnTransition
	.byte 0


Lobby_OnTransition::
# 6 "data/maps/Lobby/scripts.pory"
	setrespawn HEAL_LOCATION_LOBBY
	end


Lobby_EventScript_StartChallenge::
# 11 "data/maps/Lobby/scripts.pory"
	lock
# 12 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_FacePlayer
# 13 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 14 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_DoubleExclamationMarkWithDelay48
# 15 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 16 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 17 "data/maps/Lobby/scripts.pory"
	delay 20
# 18 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_WalkInPlaceRight
# 19 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_EXPLAIN_NEW_CHALLENGE_MODES, Lobby_EventScript_StartChallenge_2
Lobby_EventScript_StartChallenge_1:
# 23 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_StartChallenge_5
Lobby_EventScript_StartChallenge_4:
# 36 "data/maps/Lobby/scripts.pory"
	setspeaker SP_NAME_COPE
# 37 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_StartChallenge_Text_4
# 38 "data/maps/Lobby/scripts.pory"
	waitmessage
# 39 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_5, 0
# 40 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_6, 1
# 41 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_7, 2
# 42 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 4
# 43 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 44 "data/maps/Lobby/scripts.pory"
	closemessage
# 45 "data/maps/Lobby/scripts.pory"
	delay 10
# 46 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 47 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_8
# 52 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_9
# 58 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_StartChallenge_10
# 65 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	return

Lobby_EventScript_StartChallenge_2:
# 20 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 21 "data/maps/Lobby/scripts.pory"
	clearflag FLAG_EXPLAIN_NEW_CHALLENGE_MODES
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_5:
# 24 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_YESNO, speaker = SP_NAME_COPE
# 25 "data/maps/Lobby/scripts.pory"
	closemessage
# 26 "data/maps/Lobby/scripts.pory"
	delay 10
# 27 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_12
# 33 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_CancelledChallenge
	goto Lobby_EventScript_StartChallenge_4

Lobby_EventScript_StartChallenge_8:
# 48 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 49 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 50 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 51 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_9:
# 53 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE
# 54 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 55 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 56 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 57 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_10:
# 59 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE
# 60 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 61 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 62 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 63 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_12:
# 28 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 29 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 30 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 31 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	goto Lobby_EventScript_StartChallenge_4


Lobby_StartChallenge_CancelledChallenge::
# 70 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 71 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_Surprise
# 72 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 73 "data/maps/Lobby/scripts.pory"
	delay 60
# 74 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_StartChallenge_CancelledChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 75 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 76 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 77 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_StartChallenge_EnterOmegaRoom::
# 82 "data/maps/Lobby/scripts.pory"
	special SetWahChallengeInitialAchievementFlags
# 83 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_Kecleon_ResetFlags
# 84 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 85 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 86 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 87 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 88 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 89 "data/maps/Lobby/scripts.pory"
	waitstate
# 90 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 96 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 97 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 98 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 99 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 100 "data/maps/Lobby/scripts.pory"
	delay 5
# 101 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 102 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 103 "data/maps/Lobby/scripts.pory"
	delay 5
# 104 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 105 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 111 "data/maps/Lobby/scripts.pory"
	lock
# 112 "data/maps/Lobby/scripts.pory"
	faceplayer
# 113 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 114 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 123 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 125 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 126 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 115 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 116 "data/maps/Lobby/scripts.pory"
	waitstate
# 117 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 120 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 118 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 137 "data/maps/Lobby/scripts.pory"
	lock
# 138 "data/maps/Lobby/scripts.pory"
	faceplayer
# 139 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 140 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 149 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 151 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 152 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 141 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 142 "data/maps/Lobby/scripts.pory"
	waitstate
# 143 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 146 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 144 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_BufferVictoryWordFromCountVar::
# 162 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_2
# 165 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferVictoryWordFromCountVar_1:
# 167 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_6
# 170 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2
Lobby_EventScript_BufferVictoryWordFromCountVar_5:
	return

Lobby_EventScript_BufferVictoryWordFromCountVar_2:
# 163 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_1

Lobby_EventScript_BufferVictoryWordFromCountVar_6:
# 168 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_5


Lobby_EventScript_BufferTimeWordFromCountVar::
# 176 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_2
# 179 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferTimeWordFromCountVar_1:
# 181 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_6
# 184 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_1
Lobby_EventScript_BufferTimeWordFromCountVar_5:
	return

Lobby_EventScript_BufferTimeWordFromCountVar_2:
# 177 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_1

Lobby_EventScript_BufferTimeWordFromCountVar_6:
# 182 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_5


Lobby_EventScript_ChallengeHistorian::
# 190 "data/maps/Lobby/scripts.pory"
	lock
# 191 "data/maps/Lobby/scripts.pory"
	faceplayer
# 193 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_0, MSGBOX_AUTOCLOSE
# 194 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 195 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_ChallengeHistorian_2
# 206 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 207 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 208 "data/maps/Lobby/scripts.pory"
	faceplayer
# 209 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT
# 210 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 211 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_2
# 212 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT
# 213 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 214 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_3
# 215 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT
# 216 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 217 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_4
# 218 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_COMPLETION_COUNT
# 219 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferTimeWordFromCountVar
# 220 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_5
# 221 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 5
	goto_if_gt Lobby_EventScript_ChallengeHistorian_5
# 227 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_7, MSGBOX_AUTOCLOSE
# 228 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 229 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
Lobby_EventScript_ChallengeHistorian_4:
# 231 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 232 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_2:
# 196 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 197 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 198 "data/maps/Lobby/scripts.pory"
	faceplayer
# 199 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_1, MSGBOX_AUTOCLOSE
# 200 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 201 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 202 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 203 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_5:
# 222 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_6, MSGBOX_AUTOCLOSE
# 223 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 224 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
	goto Lobby_EventScript_ChallengeHistorian_4


Lobby_EventScript_Shop::
# 238 "data/maps/Lobby/scripts.pory"
	lock
# 239 "data/maps/Lobby/scripts.pory"
	faceplayer
# 240 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 241 "data/maps/Lobby/scripts.pory"
	waitmessage
# 242 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 243 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas_IntroFirstBattle::
# 248 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 249 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 252 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 254 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 255 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 256 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 257 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 258 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 259 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 260 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 261 "data/maps/Lobby/scripts.pory"
	delay 20
# 262 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 263 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 264 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 265 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 266 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 267 "data/maps/Lobby/scripts.pory"
	delay 20
# 268 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 250 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 273 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 274 "data/maps/Lobby/scripts.pory"
	closemessage
# 275 "data/maps/Lobby/scripts.pory"
	delay 20
# 276 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 280 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 281 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 277 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 287 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 288 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 291 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 295 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 289 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 292 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 302 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 303 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 304 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 305 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 306 "data/maps/Lobby/scripts.pory"
	waitstate
# 307 "data/maps/Lobby/scripts.pory"
	lock
# 308 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 314 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 309 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 310 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 311 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 319 "data/maps/Lobby/scripts.pory"
	lock
# 320 "data/maps/Lobby/scripts.pory"
	faceplayer
# 321 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 372 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 373 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 374 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 375 "data/maps/Lobby/scripts.pory"
	delay 20
# 376 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 377 "data/maps/Lobby/scripts.pory"
	delay 20
# 378 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 379 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 380 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 381 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 382 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 383 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 384 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 385 "data/maps/Lobby/scripts.pory"
	lock
# 386 "data/maps/Lobby/scripts.pory"
	delay 20
# 387 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 388 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 389 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 390 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 322 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 323 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 324 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 327 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 329 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 330 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 331 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 335 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 340 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 341 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 344 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 345 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 346 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 347 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 348 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 349 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 350 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 357 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 358 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 361 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 363 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 364 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 365 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 367 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 368 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 369 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 325 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 332 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 333 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 336 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 337 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 351 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 352 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 353 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 354 "data/maps/Lobby/scripts.pory"
	delay 40
# 355 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 359 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 402 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 403 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 404 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 407 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 410 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 413 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 405 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 408 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 411 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 414 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 422 "data/maps/Lobby/scripts.pory"
	lock
# 423 "data/maps/Lobby/scripts.pory"
	faceplayer
# 424 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 425 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 426 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 427 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 431 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 432 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 433 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 438 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 439 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 444 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 445 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 450 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 451 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 456 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 457 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 462 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 463 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 468 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_JARDINO
# 469 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 474 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_OCEADINO
# 475 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 480 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_TYRADINO
# 481 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25:
# 486 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 487 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28:
# 492 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 493 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 498 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MICAEL
# 499 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 504 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MOLIKAI
# 505 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 510 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_DIRAEI
# 511 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 516 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_LUGIA_SHADOW
# 517 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43:
# 522 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47
# 527 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 15
# 528 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 529 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 530 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 14
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50
# 535 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 536 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54
# 540 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55
# 544 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56
# 548 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57
# 552 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58
# 556 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59
# 560 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60
# 564 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61
# 568 "data/maps/Lobby/scripts.pory"
	case 8, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62
# 572 "data/maps/Lobby/scripts.pory"
	case 9, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63
# 576 "data/maps/Lobby/scripts.pory"
	case 10, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64
# 580 "data/maps/Lobby/scripts.pory"
	case 11, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65
# 584 "data/maps/Lobby/scripts.pory"
	case 12, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66
# 588 "data/maps/Lobby/scripts.pory"
	case 13, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67
# 592 "data/maps/Lobby/scripts.pory"
	case 14, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52:
# 597 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 434 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 435 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 436 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 440 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 441 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 442 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 446 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 447 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 448 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 452 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 453 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 454 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 458 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 459 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 460 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 464 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 465 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 466 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 470 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_JARDINO
# 471 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 472 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 476 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OCEADINO
# 477 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 478 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 482 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_TYRADINO
# 483 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 8
# 484 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_25

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 488 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 489 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 9
# 490 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_28

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_32:
# 494 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 495 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 10
# 496 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 500 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MICAEL
# 501 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 11
# 502 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 506 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MOLIKAI
# 507 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 12
# 508 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_41:
# 512 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_DIRAEI
# 513 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 13
# 514 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_44:
# 518 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LUGIA_SHADOW
# 519 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 14
# 520 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_43

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_47:
# 523 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 524 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_50:
# 531 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 532 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_54:
# 537 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 538 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 539 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_55:
# 541 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 542 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 543 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_56:
# 545 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 546 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 547 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_57:
# 549 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 550 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 551 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_58:
# 553 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 554 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 555 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_59:
# 557 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 558 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 559 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_60:
# 561 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_JARDINO, 10, 3
# 562 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_JARDINO
# 563 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_61:
# 565 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_OCEADINO, 10, 3
# 566 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_OCEADINO
# 567 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_62:
# 569 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_TYRADINO, 10, 3
# 570 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_TYRADINO
# 571 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_63:
# 573 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 574 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 575 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_64:
# 577 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 578 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 579 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_65:
# 581 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MICAEL, 10, 3
# 582 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MICAEL
# 583 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_66:
# 585 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MOLIKAI, 10, 3
# 586 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLIKAI
# 587 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_67:
# 589 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_DIRAEI, 10, 3
# 590 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_DIRAEI
# 591 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_68:
# 593 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_LUGIA_SHADOW, 10, 3
# 594 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_LUGIA_SHADOW
# 595 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_52


Lobby_EventScript_ShowFakemonDexInfo::
# 601 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 602 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 603 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 604 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 607 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 609 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 610 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 611 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 612 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 615 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 616 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 617 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 620 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 621 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 622 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 625 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 626 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 627 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 628 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 629 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 605 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 613 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 618 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 623 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 634 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Cope::
# 639 "data/maps/Lobby/scripts.pory"
	lock
# 640 "data/maps/Lobby/scripts.pory"
	faceplayer
# 641 "data/maps/Lobby/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 642 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_Cope_2
# 648 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 649 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 650 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Lobby_EventScript_Cope_Movement_0
# 651 "data/maps/Lobby/scripts.pory"
	waitse
# 652 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 653 "data/maps/Lobby/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 654 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
Lobby_EventScript_Cope_1:
# 656 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Cope_2:
# 644 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
	goto Lobby_EventScript_Cope_1


Lobby_EventScript_QREventInfoKid::
# 661 "data/maps/Lobby/scripts.pory"
	lock
# 662 "data/maps/Lobby/scripts.pory"
	faceplayer
# 663 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 664 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 665 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 666 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire::
# 671 "data/maps/Lobby/scripts.pory"
	lock
# 672 "data/maps/Lobby/scripts.pory"
	faceplayer
# 673 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_0, MSGBOX_AUTOCLOSE
# 674 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 675 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_2
# 682 "data/maps/Lobby/scripts.pory"
	delay 20
# 683 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_0, 0
# 684 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 685 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 686 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_5
# 693 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_6
# 696 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_2:
# 676 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 677 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Surprise
# 678 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_1, MSGBOX_AUTOCLOSE
# 679 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_5:
# 687 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Text_2, MSGBOX_YESNO
# 688 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_8
# 691 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_6:
# 694 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_8:
# 689 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	return


Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft::
# 701 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0, MSGBOX_AUTOCLOSE
# 702 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions::
# 707 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0, MSGBOX_AUTOCLOSE
# 708 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater::
# 713 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0, MSGBOX_AUTOCLOSE
# 714 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_BetaMonQuestionnaire_NextQuestion::
# 719 "data/maps/Lobby/scripts.pory"
	special Special_BufferBetaMonQuestionnaireCounters
# 720 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, Special_TryPickBetaMonQuestion
# 721 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 722 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_QUESTION, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2
# 728 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_ALL_UNLOCKED, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3
# 730 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_PICK_NONE_THIS_TALK, Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4
# 735 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_2:
# 723 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0, MSGBOX_YESNO
# 724 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7
Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6:
# 727 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_3:
# 729 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions
	return

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_4:
# 731 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1, MSGBOX_AUTOCLOSE
# 732 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_7:
# 725 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_6


Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion::
# 740 "data/maps/Lobby/scripts.pory"
	addvar VAR_BETA_MON_QUESTIONNAIRE_ASK_COUNT, 1
# 741 "data/maps/Lobby/scripts.pory"
	switch VAR_0x8004
# 742 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_GOROCHU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3
# 745 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_TAABAN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4
# 748 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_BOMUSHIKAA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5
# 751 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_MADAAMU, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6
# 754 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_AKUERIA, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7
# 757 "data/maps/Lobby/scripts.pory"
	case BETA_MON_QUESTION_LATIKEN, Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8
Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1:
# 761 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_BetaMonQuestionnaire_NextQuestion
	return

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_3:
# 743 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Gorochu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_4:
# 746 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Taaban
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_5:
# 749 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_6:
# 752 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Madaamu
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_7:
# 755 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Akueria
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1

Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_8:
# 758 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BetaMonQuestionnaire_Latiken
	goto Lobby_EventScript_BetaMonQuestionnaire_AskPickedQuestion_1


Lobby_EventScript_BetaMonQuestionnaire_Gorochu::
# 765 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0
# 766 "data/maps/Lobby/scripts.pory"
	waitmessage
# 767 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1, 0
# 768 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2, 1
# 769 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3, 2
# 770 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4, 3
# 771 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 772 "data/maps/Lobby/scripts.pory"
	closemessage
# 773 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2
# 778 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_2:
# 774 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_GOROCHU
# 775 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5, MSGBOX_AUTOCLOSE
# 776 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Gorochu_1


Lobby_EventScript_BetaMonQuestionnaire_Taaban::
# 784 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0
# 785 "data/maps/Lobby/scripts.pory"
	waitmessage
# 786 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1, 0
# 787 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2, 1
# 788 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3, 2
# 789 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4, 3
# 790 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 791 "data/maps/Lobby/scripts.pory"
	closemessage
# 792 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Taaban_2
# 797 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Taaban_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Taaban_2:
# 793 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_TAABAN
# 794 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5, MSGBOX_AUTOCLOSE
# 795 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Taaban_1


Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa::
# 803 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0
# 804 "data/maps/Lobby/scripts.pory"
	waitmessage
# 805 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1, 0
# 806 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2, 1
# 807 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3, 2
# 808 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4, 3
# 809 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 810 "data/maps/Lobby/scripts.pory"
	closemessage
# 811 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2
# 816 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_2:
# 812 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_BOMUSHIKAA
# 813 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5, MSGBOX_AUTOCLOSE
# 814 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_1


Lobby_EventScript_BetaMonQuestionnaire_Madaamu::
# 822 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0
# 823 "data/maps/Lobby/scripts.pory"
	waitmessage
# 824 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1, 0
# 825 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2, 1
# 826 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3, 2
# 827 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4, 3
# 828 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 829 "data/maps/Lobby/scripts.pory"
	closemessage
# 830 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2
# 835 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_2:
# 831 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_MADAAMU
# 832 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5, MSGBOX_AUTOCLOSE
# 833 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Madaamu_1


Lobby_EventScript_BetaMonQuestionnaire_Akueria::
# 841 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0
# 842 "data/maps/Lobby/scripts.pory"
	waitmessage
# 843 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1, 0
# 844 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2, 1
# 845 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3, 2
# 846 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4, 3
# 847 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 848 "data/maps/Lobby/scripts.pory"
	closemessage
# 849 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Akueria_2
# 854 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Akueria_1:
	return

Lobby_EventScript_BetaMonQuestionnaire_Akueria_2:
# 850 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_AKUERIA
# 851 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5, MSGBOX_AUTOCLOSE
# 852 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Akueria_1


Lobby_EventScript_BetaMonQuestionnaire_Latiken::
# 860 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0, MSGBOX_AUTOCLOSE
# 861 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_JIRACHI, CRY_MODE_NORMAL
# 862 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 863 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 864 "data/maps/Lobby/scripts.pory"
	waitmessage
# 865 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2, 0
# 866 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3, 1
# 867 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4, 2
# 868 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5, 3
# 869 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 870 "data/maps/Lobby/scripts.pory"
	closemessage
# 871 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_2
# 876 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6, MSGBOX_AUTOCLOSE
# 877 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_LATIAS, CRY_MODE_NORMAL
# 878 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 879 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 880 "data/maps/Lobby/scripts.pory"
	waitmessage
# 881 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7, 0
# 882 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8, 1
# 883 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9, 2
# 884 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10, 3
# 885 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 886 "data/maps/Lobby/scripts.pory"
	closemessage
# 887 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_ne Lobby_EventScript_BetaMonQuestionnaire_Latiken_5
# 892 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11, MSGBOX_AUTOCLOSE
# 893 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_BLAZIKEN, CRY_MODE_NORMAL
# 894 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 895 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1
# 896 "data/maps/Lobby/scripts.pory"
	waitmessage
# 897 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12, 0
# 898 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13, 1
# 899 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14, 2
# 900 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15, 3
# 901 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, TRUE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 902 "data/maps/Lobby/scripts.pory"
	closemessage
# 903 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_BetaMonQuestionnaire_Latiken_8
# 908 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
Lobby_EventScript_BetaMonQuestionnaire_Latiken_7:
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_2:
# 872 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_5:
# 888 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FailedToUnlock, MSGBOX_AUTOCLOSE
	return

Lobby_EventScript_BetaMonQuestionnaire_Latiken_8:
# 904 "data/maps/Lobby/scripts.pory"
	setflag FLAG_POKEBOX_UNLOCK_BETA_LATIKEN
# 905 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16, MSGBOX_AUTOCLOSE
# 906 "data/maps/Lobby/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
	goto Lobby_EventScript_BetaMonQuestionnaire_Latiken_7


Lobby_EventScript_Pokebox::
# 918 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_C, 8
# 919 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_D, 3
# 920 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_OFF
# 921 "data/maps/Lobby/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_ON
# 922 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


Lobby_EventScript_Turbo::
# 927 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Turbo_Text_0, MSGBOX_NPC
	end


# 255 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 255 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 255 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 257 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 257 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 257 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 257 "data/maps/Lobby/scripts.pory"
	face_player
# 257 "data/maps/Lobby/scripts.pory"
	delay_16
# 257 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 650 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Cope_Movement_0:
# 650 "data/maps/Lobby/scripts.pory"
	emote_question_mark
	step_end

Lobby_EventScript_StartChallenge_Text_0:
# 15 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 20 "data/maps/Lobby/scripts.pory"
	.string "¡Increíble, {PLAYER}! Has superado el\n"
	.string "desafío por completo.\p"
	.string "A partir de ahora puedes volver a\n"
	.string "enfrentarlo en otras modalidades:\l"
	.string "batallas dobles y batallas inversas.\p"
	.string "¡Seguro que te van a divertir un montón!$"

Lobby_EventScript_StartChallenge_Text_2:
# 24 "data/maps/Lobby/scripts.pory"
	.string "¿Así que ya estás list{OA} para intentar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_3:
# 30 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Adelante, ¡te deseo mucha\n"
	.string "suerte y sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_4:
# 37 "data/maps/Lobby/scripts.pory"
	.string "¿En qué modo quieres afrontar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_5:
# 39 "data/maps/Lobby/scripts.pory"
	.string "Estándar$"

Lobby_EventScript_StartChallenge_Text_6:
# 40 "data/maps/Lobby/scripts.pory"
	.string "Batallas dobles$"

Lobby_EventScript_StartChallenge_Text_7:
# 41 "data/maps/Lobby/scripts.pory"
	.string "Batallas inversas$"

Lobby_EventScript_StartChallenge_Text_8:
# 42 "data/maps/Lobby/scripts.pory"
	.string "Salir$"

Lobby_EventScript_StartChallenge_Text_9:
# 56 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas dobles.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_10:
# 62 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas inversas.\p"
	.string "Las efectividades de tipo se invierten:\n"
	.string "lo que normalmente es súper efectivo\l"
	.string "será poco efectivo y viceversa.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_StartChallenge_CancelledChallenge_Text_0:
# 72 "data/maps/Lobby/scripts.pory"
	.string "¿Así que no te sientes list{OA}?$"

Lobby_StartChallenge_CancelledChallenge_Text_1:
# 74 "data/maps/Lobby/scripts.pory"
	.string "Recuerda que las personas de la sala de\n"
	.string "espera pueden ayudar en tu\l"
	.string "preparación.$"

Lobby_EventScript_TeamSelector_Text_0:
# 113 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 118 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 139 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy la encargada de la selección\n"
	.string "de dificultad del desafío.\p"
	.string "No parece que la dificultad actual sea\n"
	.string "la adecuada para ti.\p"
	.string "¿Quieres cambiar el nivel de dificultad?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 144 "data/maps/Lobby/scripts.pory"
	.string "¡Listo! La dificultad ha sido actualizada.\n¡Buena suerte con el desafío!$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0:
# 163 "data/maps/Lobby/scripts.pory"
	.string "0$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1:
# 168 "data/maps/Lobby/scripts.pory"
	.string "victoria$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2:
# 170 "data/maps/Lobby/scripts.pory"
	.string "victorias$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_0:
# 182 "data/maps/Lobby/scripts.pory"
	.string "vez$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_1:
# 184 "data/maps/Lobby/scripts.pory"
	.string "veces$"

Lobby_EventScript_ChallengeHistorian_Text_0:
# 193 "data/maps/Lobby/scripts.pory"
	.string "¡Hey, {PLAYER}! No trabajo aquí ni\n"
	.string "nada, pero me encanta sacar\l"
	.string "estadísticas.\p"
	.string "Me quedo en la sala de espera\n"
	.string "observando a todos los que entran y lo\l"
	.string "anoto todo.$"

Lobby_EventScript_ChallengeHistorian_Text_1:
# 199 "data/maps/Lobby/scripts.pory"
	.string "Veo que aún no has completado el\n"
	.string "desafío ni una vez.\p"
	.string "Todavía no te has ganado un lugar en\n"
	.string "mis notas.$"

Lobby_EventScript_ChallengeHistorian_Text_2:
# 211 "data/maps/Lobby/scripts.pory"
	.string "Según mi cuaderno, en modo estándar\n"
	.string "llevas {STR_VAR_1} {STR_VAR_2}.\p"
	.string "¡Nada mal, de verdad!$"

Lobby_EventScript_ChallengeHistorian_Text_3:
# 214 "data/maps/Lobby/scripts.pory"
	.string "En batallas dobles tienes\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ahí se nota quién piensa dos turnos por\n"
	.string "adelantado.$"

Lobby_EventScript_ChallengeHistorian_Text_4:
# 217 "data/maps/Lobby/scripts.pory"
	.string "Y en batallas invertidas sumas\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ese modo le da vuelta la cabeza a\n"
	.string "cualquiera.$"

Lobby_EventScript_ChallengeHistorian_Text_5:
# 220 "data/maps/Lobby/scripts.pory"
	.string "En total, has completado el desafío\n"
	.string "{STR_VAR_1} {STR_VAR_2}.$"

Lobby_EventScript_ChallengeHistorian_Text_6:
# 222 "data/maps/Lobby/scripts.pory"
	.string "¡Si sigues así, voy a tener que comprar\n"
	.string "otro cuaderno para registrar tus\l"
	.string "números!$"

Lobby_EventScript_ChallengeHistorian_Text_7:
# 227 "data/maps/Lobby/scripts.pory"
	.string "Aún no son tantas victorias, pero sigue\n"
	.string "así.$"

Lobby_EventScript_Shop_Text_0:
# 240 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 250 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 252 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 258 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 262 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 265 "data/maps/Lobby/scripts.pory"
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
# 273 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 289 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: elige\n"
	.string "a tres de tus bichos.\p"
	.string "Yo voy a salir con mi legendario, así que\n"
	.string "más te vale elegir bien.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 295 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate para\n"
	.string "enfrentar a mi legendario.$"

Lobby_EventScript_Roxas_Text_0:
# 344 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 346 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 353 "data/maps/Lobby/scripts.pory"
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
# 359 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 361 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 365 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 372 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 376 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 384 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras, loco!$"

Lobby_EventScript_Roxas_Text_9:
# 387 "data/maps/Lobby/scripts.pory"
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
# 389 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 424 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 523 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 528 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 531 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 602 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokedex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 605 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 607 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 609 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 613 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 626 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 629 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 634 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_EventScript_Cope_Text_0:
# 644 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Estás list{OA} para intentar el desafío?$"

Lobby_EventScript_Cope_Text_1:
# 648 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Has visto a Tile?$"

Lobby_EventScript_Cope_Text_2:
# 652 "data/maps/Lobby/scripts.pory"
	.string "¿Cómo? ¿No sabes quién es?\n"
	.string "Es mi famoso Kecleon.\p"
	.string "Lo he perdido de vista y no sé por dónde\n"
	.string "se ha metido... Además, ¡me ha robado el\l"
	.string "kit de objetos que le doy a los\l"
	.string "entrenadores del desafío!\p"
	.string "Hazme un favor y búscale por mí.\n"
	.string "Toma, llévate esto.$"

Lobby_EventScript_Cope_Text_3:
# 654 "data/maps/Lobby/scripts.pory"
	.string "Con el Detector Devon podrás ver dónde\n"
	.string "se esconde Tile.$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 663 "data/maps/Lobby/scripts.pory"
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
# 673 "data/maps/Lobby/scripts.pory"
	.string "¡Buenas! Soy el maestro de los\n"
	.string "cuestionarios.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_1:
# 678 "data/maps/Lobby/scripts.pory"
	.string "Así que aún no has completado el\n"
	.string "desafío.\l"
	.string "...\l"
	.string "...\p"
	.string "Cuando lo superes, vuelve y te haré un\n"
	.string "cuestionario especial.$"

Lobby_EventScript_BetaMonQuestionnaire_Text_2:
# 687 "data/maps/Lobby/scripts.pory"
	.string "Te haré una pregunta por cada vez que\n"
	.string "hayas completado el desafío.\p"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "¿Quieres que te haga una pregunta?$"

Lobby_EventScript_BetaMonQuestionnaire_NoAttemptsLeft_Text_0:
# 701 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "Completa el desafío otra vez y vuelve\n"
	.string "por aquí.$"

Lobby_EventScript_BetaMonQuestionnaire_NoMoreQuestions_Text_0:
# 707 "data/maps/Lobby/scripts.pory"
	.string "¡Ya has respondido todas mis\n"
	.string "preguntas! ¿Qué te parecen los Pokémon\l"
	.string "que has conseguido?$"

Lobby_EventScript_BetaMonQuestionnaire_SeeYouLater_Text_0:
# 713 "data/maps/Lobby/scripts.pory"
	.string "De acuerdo. Puedes volver cuando\n"
	.string "quieras.$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_0:
# 723 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "¿Quieres seguir respondiendo?$"

Lobby_EventScript_BetaMonQuestionnaire_NextQuestion_Text_1:
# 731 "data/maps/Lobby/scripts.pory"
	.string "Has completado el desafío\n"
	.string "{STR_VAR_1} veces.\p"
	.string "Ya te hice {STR_VAR_2} preguntas.\p"
	.string "Te quedan {STR_VAR_3} intentos\n"
	.string "disponibles.\p"
	.string "Por ahora no tengo más preguntas\n"
	.string "distintas para hacerte.\p"
	.string "Vuelve a hablarme en otro momento.$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_0:
# 765 "data/maps/Lobby/scripts.pory"
	.string "¿Qué Pokémon es naranja, tiene una cola\n"
	.string "larga y a todo el mundo le encanta el\l"
	.string "que evoluciona en él?$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_1:
# 767 "data/maps/Lobby/scripts.pory"
	.string "Raichu$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_2:
# 768 "data/maps/Lobby/scripts.pory"
	.string "Arcanine$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_3:
# 769 "data/maps/Lobby/scripts.pory"
	.string "Floatzel$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_4:
# 770 "data/maps/Lobby/scripts.pory"
	.string "Simisear$"

Lobby_EventScript_BetaMonQuestionnaire_Gorochu_Text_5:
# 775 "data/maps/Lobby/scripts.pory"
	.string "Pues con este Pokémon te encontrarás.$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_0:
# 784 "data/maps/Lobby/scripts.pory"
	.string "Mi amigo siempre va con su Bro detrás.\p"
	.string "¿Qué Pokémon es mi amigo?$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_1:
# 786 "data/maps/Lobby/scripts.pory"
	.string "Slowking$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_2:
# 787 "data/maps/Lobby/scripts.pory"
	.string "Slowbro$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_3:
# 788 "data/maps/Lobby/scripts.pory"
	.string "Slowpoke$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_4:
# 789 "data/maps/Lobby/scripts.pory"
	.string "Shellder$"

Lobby_EventScript_BetaMonQuestionnaire_Taaban_Text_5:
# 794 "data/maps/Lobby/scripts.pory"
	.string "Pues con su Bro te irás.$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_0:
# 803 "data/maps/Lobby/scripts.pory"
	.string "Blanco como la nieve y una carita mona.\p"
	.string "¿Quién es?$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_1:
# 805 "data/maps/Lobby/scripts.pory"
	.string "Whismur$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_2:
# 806 "data/maps/Lobby/scripts.pory"
	.string "Aipom$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_3:
# 807 "data/maps/Lobby/scripts.pory"
	.string "Dewgong$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_4:
# 808 "data/maps/Lobby/scripts.pory"
	.string "Snorunt$"

Lobby_EventScript_BetaMonQuestionnaire_Bomushikaa_Text_5:
# 813 "data/maps/Lobby/scripts.pory"
	.string "¡Pues este se le parece!$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_0:
# 822 "data/maps/Lobby/scripts.pory"
	.string "El Capitán Puerro blande su espada en\n"
	.string "el bosque.\p"
	.string "¿Quién es realmente el Capitán Puerro?$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_1:
# 824 "data/maps/Lobby/scripts.pory"
	.string "Kartana$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_2:
# 825 "data/maps/Lobby/scripts.pory"
	.string "Gallade$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_3:
# 826 "data/maps/Lobby/scripts.pory"
	.string "Farfetch'd$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_4:
# 827 "data/maps/Lobby/scripts.pory"
	.string "Scyther$"

Lobby_EventScript_BetaMonQuestionnaire_Madaamu_Text_5:
# 832 "data/maps/Lobby/scripts.pory"
	.string "Exacto. Ese filo también despertó la\n"
	.string "curiosidad de Madaamu.$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_0:
# 841 "data/maps/Lobby/scripts.pory"
	.string "Adivina, adivinanza.\p"
	.string "¿Qué serpiente azul tiene una evolución\n"
	.string "naranja?$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_1:
# 843 "data/maps/Lobby/scripts.pory"
	.string "Gyarados$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_2:
# 844 "data/maps/Lobby/scripts.pory"
	.string "Dratini$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_3:
# 845 "data/maps/Lobby/scripts.pory"
	.string "Milotic$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_4:
# 846 "data/maps/Lobby/scripts.pory"
	.string "Dunsparce$"

Lobby_EventScript_BetaMonQuestionnaire_Akueria_Text_5:
# 851 "data/maps/Lobby/scripts.pory"
	.string "Pues su primo te ha visto luchar y te\n"
	.string "espera.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_0:
# 860 "data/maps/Lobby/scripts.pory"
	.string "Adivina, adivinanza.\p"
	.string "¿Qué Pokémon hace este grito?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_1:
# 863 "data/maps/Lobby/scripts.pory"
	.string "¿Quién fue?$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_2:
# 865 "data/maps/Lobby/scripts.pory"
	.string "Jirachi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_3:
# 866 "data/maps/Lobby/scripts.pory"
	.string "Celebi$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_4:
# 867 "data/maps/Lobby/scripts.pory"
	.string "Mew$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_5:
# 868 "data/maps/Lobby/scripts.pory"
	.string "Deoxys$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_6:
# 876 "data/maps/Lobby/scripts.pory"
	.string "Oh, correcto. Ahora mismo intenta\n"
	.string "adivinar este.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_7:
# 881 "data/maps/Lobby/scripts.pory"
	.string "Latios$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_8:
# 882 "data/maps/Lobby/scripts.pory"
	.string "Latias$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_9:
# 883 "data/maps/Lobby/scripts.pory"
	.string "Altaria$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_10:
# 884 "data/maps/Lobby/scripts.pory"
	.string "Flygon$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_11:
# 892 "data/maps/Lobby/scripts.pory"
	.string "Oh, volviste a acertar. Ahora este.$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_12:
# 897 "data/maps/Lobby/scripts.pory"
	.string "Blaziken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_13:
# 898 "data/maps/Lobby/scripts.pory"
	.string "Combusken$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_14:
# 899 "data/maps/Lobby/scripts.pory"
	.string "Infernape$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_15:
# 900 "data/maps/Lobby/scripts.pory"
	.string "Lucario$"

Lobby_EventScript_BetaMonQuestionnaire_Latiken_Text_16:
# 905 "data/maps/Lobby/scripts.pory"
	.string "Increíble, acertaste otra vez. Es\n"
	.string "impresionante.\p"
	.string "Ten esto.$"

Lobby_EventScript_Turbo_Text_0:
# 927 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías qué existe un modo turbo para\n"
	.string "vivir la aventura a toda velocidad?\p"
	.string "Desde el menú de opciones puedes\n"
	.string "configurar tu velocidad de texto, de\l"
	.string "caminar, ¡y un turbo para los combates!\p"
	.string "¿Te animas a probarlo?$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 131 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_DifficultySelector_Cancelled::
# 156 "data/maps/Lobby/scripts.pory"
	.string "¡Entendido! Si cambias de opinión,\n"
	.string "estaré por aquí.$"

Lobby_Text_Roxas_PlayerCancelled::
# 397 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_Text_FailedToUnlock::
# 913 "data/maps/Lobby/scripts.pory"
	.string "Oh, ¡fallaste!$"
