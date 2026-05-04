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
	pokemart Lobby_MartItems
# 243 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 244 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 248 "data/maps/Lobby/scripts.pory"
Lobby_MartItems:
# 249 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 250 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 251 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 252 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 253 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 254 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 255 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 256 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 257 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 258 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 259 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 260 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 261 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 262 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 263 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 264 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 265 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 266 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 267 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 268 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 269 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 270 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 271 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 272 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 273 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 274 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 275 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 276 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 277 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_Roxas_IntroFirstBattle::
# 281 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 282 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 285 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 287 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 288 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 289 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 290 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 291 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 292 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 293 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 294 "data/maps/Lobby/scripts.pory"
	delay 20
# 295 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 296 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 297 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 298 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 299 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 300 "data/maps/Lobby/scripts.pory"
	delay 20
# 301 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 283 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 306 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 307 "data/maps/Lobby/scripts.pory"
	closemessage
# 308 "data/maps/Lobby/scripts.pory"
	delay 20
# 309 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 313 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 314 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 310 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 320 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 321 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 324 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 328 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 322 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 325 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 335 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 336 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 337 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 338 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 339 "data/maps/Lobby/scripts.pory"
	waitstate
# 340 "data/maps/Lobby/scripts.pory"
	lock
# 341 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 347 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 342 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 343 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 344 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 352 "data/maps/Lobby/scripts.pory"
	lock
# 353 "data/maps/Lobby/scripts.pory"
	faceplayer
# 354 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 405 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 406 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 407 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 408 "data/maps/Lobby/scripts.pory"
	delay 20
# 409 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 410 "data/maps/Lobby/scripts.pory"
	delay 20
# 411 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 412 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 413 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 414 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 415 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 416 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 417 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 418 "data/maps/Lobby/scripts.pory"
	lock
# 419 "data/maps/Lobby/scripts.pory"
	delay 20
# 420 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 421 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 422 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 423 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 355 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 356 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 357 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 360 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 362 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 363 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 364 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 368 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 373 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 374 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 377 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 378 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 379 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 380 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 381 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 382 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 383 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 384 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 391 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 392 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 395 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 397 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 398 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 399 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 401 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 402 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 358 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 365 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 366 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 369 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 370 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 385 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 386 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 387 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 388 "data/maps/Lobby/scripts.pory"
	delay 40
# 389 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 393 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 435 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 436 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 437 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 440 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 443 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 446 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 438 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 441 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 444 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 447 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 455 "data/maps/Lobby/scripts.pory"
	lock
# 456 "data/maps/Lobby/scripts.pory"
	faceplayer
# 457 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 458 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 459 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 460 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 464 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 465 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 466 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 471 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 472 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 477 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 478 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 483 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 484 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 489 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 490 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 495 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 496 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 501 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 502 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 507 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 508 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 513 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
# 518 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 8
# 519 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 520 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 521 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
# 526 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 527 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33
# 531 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34
# 535 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
# 539 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36
# 543 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37
# 547 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
# 551 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39
# 555 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 560 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 467 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 468 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 469 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 473 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 474 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 475 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 479 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 480 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 481 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 485 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 486 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 487 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 491 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 492 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 493 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 497 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 498 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 499 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 503 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 504 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 505 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 509 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 510 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 511 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 514 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 515 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 522 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 523 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33:
# 528 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 529 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 530 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 532 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 533 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 534 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 536 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 537 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 538 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36:
# 540 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 541 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 542 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 544 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 545 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 546 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 548 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 549 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 550 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39:
# 552 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 553 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 554 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 556 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 557 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 558 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31


Lobby_EventScript_ShowFakemonDexInfo::
# 564 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 565 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 566 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 567 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 570 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 572 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 573 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 574 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 575 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 578 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 579 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 580 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 583 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 584 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 585 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 588 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 589 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 590 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 591 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 592 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 568 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 576 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 581 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 586 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 597 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_Cope::
# 602 "data/maps/Lobby/scripts.pory"
	lock
# 603 "data/maps/Lobby/scripts.pory"
	faceplayer
# 604 "data/maps/Lobby/scripts.pory"
	checkitem ITEM_DEVON_SCOPE
# 605 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_Cope_2
# 611 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 612 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 613 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Lobby_EventScript_Cope_Movement_0
# 614 "data/maps/Lobby/scripts.pory"
	waitse
# 615 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 616 "data/maps/Lobby/scripts.pory"
	giveitem ITEM_DEVON_SCOPE
# 617 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
Lobby_EventScript_Cope_1:
# 619 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Cope_2:
# 607 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Cope_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
	goto Lobby_EventScript_Cope_1


Lobby_EventScript_QREventInfoKid::
# 624 "data/maps/Lobby/scripts.pory"
	lock
# 625 "data/maps/Lobby/scripts.pory"
	faceplayer
# 626 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 627 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 628 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 629 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_AdminCountNPC::
# 634 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_AdminCountNPC, MSGBOX_NPC
	end


Lobby_EventScript_Pokebox::
# 653 "data/maps/Lobby/scripts.pory"
	lock
# 654 "data/maps/Lobby/scripts.pory"
	waitse
# 655 "data/maps/Lobby/scripts.pory"
	playse SE_PC_ON
# 656 "data/maps/Lobby/scripts.pory"
	setmetatile 8, 3, METATILE_lobby_PC_ON, FALSE
# 657 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 658 "data/maps/Lobby/scripts.pory"
	waitse
# 659 "data/maps/Lobby/scripts.pory"
	delay 10
# 660 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Pokebox_3
Lobby_EventScript_Pokebox_1:
# 672 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Pokebox_MainMenu
	return

Lobby_EventScript_Pokebox_2:
# 661 "data/maps/Lobby/scripts.pory"
	playse SE_PC_LOGIN
# 662 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Pokebox_SoftwareUpdate, MSGBOX_AUTOCLOSE_CENTER
# 663 "data/maps/Lobby/scripts.pory"
	waitse
# 664 "data/maps/Lobby/scripts.pory"
	delay 10
# 665 "data/maps/Lobby/scripts.pory"
	playse SE_USE_ITEM
# 666 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Pokebox_SoftwareUpdateExplanation, MSGBOX_AUTOCLOSE_CENTER
# 667 "data/maps/Lobby/scripts.pory"
	waitse
# 668 "data/maps/Lobby/scripts.pory"
	delay 20
# 669 "data/maps/Lobby/scripts.pory"
	setflag FLAG_LOBBY_POKEBOX_POST_WAH_UPDATE_SEEN
	goto Lobby_EventScript_Pokebox_1

Lobby_EventScript_Pokebox_3:
# 660 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_LOBBY_POKEBOX_POST_WAH_UPDATE_SEEN, Lobby_EventScript_Pokebox_2
	goto Lobby_EventScript_Pokebox_1


Lobby_EventScript_Pokebox_MainMenu::
# 676 "data/maps/Lobby/scripts.pory"
	playse SE_PC_LOGIN
# 677 "data/maps/Lobby/scripts.pory"
	message Lobby_Text_Pokebox_MainPrompt
# 678 "data/maps/Lobby/scripts.pory"
	waitmessage
# 679 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_Pokebox_MainMenu_Text_0, 0
# 680 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_Pokebox_MainMenu_Text_1, 1
# 681 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 2
# 682 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 3, 0, 0, DYN_MULTICHOICE_CB_NONE
# 683 "data/maps/Lobby/scripts.pory"
	closemessage
# 684 "data/maps/Lobby/scripts.pory"
	delay 10
# 685 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 686 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_Pokebox_MainMenu_2
# 694 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_Pokebox_MainMenu_3
# 697 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Pokebox_Shutdown
	return

Lobby_EventScript_Pokebox_MainMenu_2:
# 687 "data/maps/Lobby/scripts.pory"
	callnative StartPokeBoxFromField_CB2
# 688 "data/maps/Lobby/scripts.pory"
	waitstate
# 689 "data/maps/Lobby/scripts.pory"
	playse SE_PC_OFF
# 690 "data/maps/Lobby/scripts.pory"
	setmetatile 8, 3, METATILE_lobby_PC_OFF, FALSE
# 691 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 692 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Pokebox_MainMenu_3:
# 695 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Pokebox_HelpMenu
	return


Lobby_EventScript_Pokebox_HelpMenu::
# 702 "data/maps/Lobby/scripts.pory"
	message Lobby_Text_Pokebox_HelpPrompt
# 703 "data/maps/Lobby/scripts.pory"
	waitmessage
# 704 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_Pokebox_HelpMenu_Text_0, 0
# 705 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_Pokebox_HelpMenu_Text_1, 1
# 706 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_Pokebox_HelpMenu_Text_2, 2
# 707 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 3, 0, 0, DYN_MULTICHOICE_CB_NONE
# 708 "data/maps/Lobby/scripts.pory"
	closemessage
# 709 "data/maps/Lobby/scripts.pory"
	delay 10
# 710 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 711 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_Pokebox_HelpMenu_2
# 719 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_Pokebox_HelpMenu_3
# 724 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Pokebox_MainMenu
	return

Lobby_EventScript_Pokebox_HelpMenu_2:
# 712 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Pokebox_HelpMenu_6
# 715 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Pokebox_HelpSwapsBeforeChallenge, MSGBOX_AUTOCLOSE
Lobby_EventScript_Pokebox_HelpMenu_5:
# 717 "data/maps/Lobby/scripts.pory"
	delay 10
# 718 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Pokebox_HelpMenu
	return

Lobby_EventScript_Pokebox_HelpMenu_3:
# 720 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Pokebox_HelpUnlock, MSGBOX_AUTOCLOSE
# 721 "data/maps/Lobby/scripts.pory"
	delay 10
# 722 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Pokebox_HelpMenu
	return

Lobby_EventScript_Pokebox_HelpMenu_6:
# 713 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Pokebox_HelpSwapsAfterChallenge, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_Pokebox_HelpMenu_5


Lobby_EventScript_Pokebox_Shutdown::
# 729 "data/maps/Lobby/scripts.pory"
	playse SE_PC_OFF
# 730 "data/maps/Lobby/scripts.pory"
	setmetatile 8, 3, METATILE_lobby_PC_OFF, FALSE
# 731 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 732 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Turbo::
# 766 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Turbo_Text_0, MSGBOX_NPC
	end


# 288 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 288 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 288 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 290 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 290 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 290 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 290 "data/maps/Lobby/scripts.pory"
	face_player
# 290 "data/maps/Lobby/scripts.pory"
	delay_16
# 290 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 613 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Cope_Movement_0:
# 613 "data/maps/Lobby/scripts.pory"
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

Lobby_EventScript_Shop_Text_1:
# 243 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 283 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 285 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 291 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 295 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 298 "data/maps/Lobby/scripts.pory"
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
# 306 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 322 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: elige\n"
	.string "a tres de tus bichos.\p"
	.string "Yo voy a salir con mi legendario, así que\n"
	.string "más te vale elegir bien.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 328 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate para\n"
	.string "enfrentar a mi legendario.$"

Lobby_EventScript_Roxas_Text_0:
# 377 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 379 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 387 "data/maps/Lobby/scripts.pory"
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
# 393 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 395 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 399 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 405 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 409 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 417 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras, loco!$"

Lobby_EventScript_Roxas_Text_9:
# 420 "data/maps/Lobby/scripts.pory"
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
# 422 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 457 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 514 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 519 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 522 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 565 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokedex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 568 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 570 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 572 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 576 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 589 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 592 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 597 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_EventScript_Cope_Text_0:
# 607 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Estás list{OA} para intentar el desafío?$"

Lobby_EventScript_Cope_Text_1:
# 611 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!\p"
	.string "¿Has visto a Tile?$"

Lobby_EventScript_Cope_Text_2:
# 615 "data/maps/Lobby/scripts.pory"
	.string "¿Cómo? ¿No sabes quién es?\n"
	.string "Es mi famoso Kecleon.\p"
	.string "Lo he perdido de vista y no sé por dónde\n"
	.string "se ha metido... Además, ¡me ha robado el\l"
	.string "kit de objetos que le doy a los\l"
	.string "entrenadores del desafío!\p"
	.string "Hazme un favor y búscale por mí.\n"
	.string "Toma, llévate esto.$"

Lobby_EventScript_Cope_Text_3:
# 617 "data/maps/Lobby/scripts.pory"
	.string "Con el Detector Devon podrás ver dónde\n"
	.string "se esconde Tile.$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 626 "data/maps/Lobby/scripts.pory"
	.string "Un chico de la zona creativa te da un\n"
	.string "regalo por completar un evento\l"
	.string "especial.\p"
	.string "Es imposible adivinar lo que hay que\n"
	.string "hacer sin mirar el vídeo.\p"
	.string "¡Incluso tuve que cambiar de orden a\n"
	.string "dos de los Pokémon de mi equipo!\p"
	.string "Eso sí, me gustó el premio por completar\n"
	.string "el evento, ¡valió la pena!$"

Lobby_EventScript_Pokebox_MainMenu_Text_0:
# 679 "data/maps/Lobby/scripts.pory"
	.string "Acceder a PC$"

Lobby_EventScript_Pokebox_MainMenu_Text_1:
# 680 "data/maps/Lobby/scripts.pory"
	.string "¿Cómo funciona?$"

Lobby_EventScript_Pokebox_HelpMenu_Text_0:
# 704 "data/maps/Lobby/scripts.pory"
	.string "¿Cuántos Pokémon puedo cambiar?$"

Lobby_EventScript_Pokebox_HelpMenu_Text_1:
# 705 "data/maps/Lobby/scripts.pory"
	.string "¿Cómo desbloqueo nuevos Pokémon?$"

Lobby_EventScript_Pokebox_HelpMenu_Text_2:
# 706 "data/maps/Lobby/scripts.pory"
	.string "Volver$"

Lobby_EventScript_Turbo_Text_0:
# 766 "data/maps/Lobby/scripts.pory"
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
# 430 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_Text_AdminCountNPC::
# 638 "data/maps/Lobby/scripts.pory"
	.string "Dicen que son 21 salas para completar\n"
	.string "el desafío…\p"
	.string "Para la cantidad de administradores que \n"
	.string "hubo en la historia de WAH, hay algo que\l"
	.string "no termina de cuadrar.\p"
	.string "¿Habrán dejado a algunos afuera de la \n"
	.string "celebración?\p"
	.string "¿Cómo lo resolvieron?$"

Lobby_Text_Pokebox_SoftwareUpdate::
# 736 "data/maps/Lobby/scripts.pory"
	.string "¡El software de la PC se ha actualizado!$"

Lobby_Text_Pokebox_SoftwareUpdateExplanation::
# 740 "data/maps/Lobby/scripts.pory"
	.string "Ahora puedes cambiar hasta 3 Pokémon\n"
	.string "de tu equipo y sustituirlos por Pokémon\l"
	.string "de la caja, en lugar de solo 1.$"

Lobby_Text_Pokebox_MainPrompt::
# 744 "data/maps/Lobby/scripts.pory"
	.string "¿Qué quieres hacer?$"

Lobby_Text_Pokebox_HelpPrompt::
# 748 "data/maps/Lobby/scripts.pory"
	.string "¿Sobre qué quieres saber?$"

Lobby_Text_Pokebox_HelpSwapsBeforeChallenge::
# 752 "data/maps/Lobby/scripts.pory"
	.string "Puedes reemplazar solo uno de los\n"
	.string "Pokémon predefinidos del equipo\l"
	.string "seleccionado por uno de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 5\l"
	.string "Pokémon del equipo original.$"

Lobby_Text_Pokebox_HelpSwapsAfterChallenge::
# 756 "data/maps/Lobby/scripts.pory"
	.string "Puedes reemplazar hasta 3 Pokémon\n"
	.string "predefinidos del equipo seleccionado\l"
	.string "por Pokémon de la caja.\p"
	.string "Puedes hacerlo las veces que quieras,\n"
	.string "pero siempre tendrás al menos 3\l"
	.string "Pokémon del equipo original.$"

Lobby_Text_Pokebox_HelpUnlock::
# 761 "data/maps/Lobby/scripts.pory"
	.string "Algunos Pokémon se desbloquean\n"
	.string "comprándolos en la PC.\p"
	.string "Otros, se obtienen avanzando en el\n"
	.string "juego, consiguiendo Logros o con\l"
	.string "eventos especiales.\p"
	.string "Para descubrir cómo desbloquear un\n"
	.string "Pokémon, presiona {COLOR RED}A{COLOR DARK_GRAY} en su sombra.$"
