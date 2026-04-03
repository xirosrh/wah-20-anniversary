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
	turnobject LOCALID_PLAYER, DIR_NORTH
# 83 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 84 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 85 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 86 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 87 "data/maps/Lobby/scripts.pory"
	waitstate
# 88 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 94 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 95 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 96 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 97 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 98 "data/maps/Lobby/scripts.pory"
	delay 5
# 99 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 100 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 101 "data/maps/Lobby/scripts.pory"
	delay 5
# 102 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 103 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 109 "data/maps/Lobby/scripts.pory"
	lock
# 110 "data/maps/Lobby/scripts.pory"
	faceplayer
# 111 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 112 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 121 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 123 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 124 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 113 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 114 "data/maps/Lobby/scripts.pory"
	waitstate
# 115 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 118 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 116 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 135 "data/maps/Lobby/scripts.pory"
	lock
# 136 "data/maps/Lobby/scripts.pory"
	faceplayer
# 137 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 138 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 147 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 149 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 150 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 139 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 140 "data/maps/Lobby/scripts.pory"
	waitstate
# 141 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 144 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 142 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_BufferVictoryWordFromCountVar::
# 160 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_2
# 163 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferVictoryWordFromCountVar_1:
# 165 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferVictoryWordFromCountVar_6
# 168 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2
Lobby_EventScript_BufferVictoryWordFromCountVar_5:
	return

Lobby_EventScript_BufferVictoryWordFromCountVar_2:
# 161 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_1

Lobby_EventScript_BufferVictoryWordFromCountVar_6:
# 166 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1
	goto Lobby_EventScript_BufferVictoryWordFromCountVar_5


Lobby_EventScript_BufferTimeWordFromCountVar::
# 174 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_2
# 177 "data/maps/Lobby/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8004
Lobby_EventScript_BufferTimeWordFromCountVar_1:
# 179 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8004, 1
	goto_if_eq Lobby_EventScript_BufferTimeWordFromCountVar_6
# 182 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_1
Lobby_EventScript_BufferTimeWordFromCountVar_5:
	return

Lobby_EventScript_BufferTimeWordFromCountVar_2:
# 175 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_1, Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_1

Lobby_EventScript_BufferTimeWordFromCountVar_6:
# 180 "data/maps/Lobby/scripts.pory"
	bufferstring STR_VAR_2, Lobby_EventScript_BufferTimeWordFromCountVar_Text_0
	goto Lobby_EventScript_BufferTimeWordFromCountVar_5


Lobby_EventScript_ChallengeHistorian::
# 188 "data/maps/Lobby/scripts.pory"
	lock
# 189 "data/maps/Lobby/scripts.pory"
	faceplayer
# 191 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_0, MSGBOX_AUTOCLOSE
# 192 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 193 "data/maps/Lobby/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_ChallengeHistorian_2
# 204 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 205 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 206 "data/maps/Lobby/scripts.pory"
	faceplayer
# 207 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_STANDARD_COMPLETION_COUNT
# 208 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 209 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_2
# 210 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_DOUBLE_COMPLETION_COUNT
# 211 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 212 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_3
# 213 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_INVERSE_COMPLETION_COUNT
# 214 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferVictoryWordFromCountVar
# 215 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_4
# 216 "data/maps/Lobby/scripts.pory"
	copyvar VAR_0x8004, VAR_WAH_CHALLENGE_COMPLETION_COUNT
# 217 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_BufferTimeWordFromCountVar
# 218 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_5
# 219 "data/maps/Lobby/scripts.pory"
	compare VAR_WAH_CHALLENGE_COMPLETION_COUNT, 5
	goto_if_gt Lobby_EventScript_ChallengeHistorian_5
# 225 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_7, MSGBOX_AUTOCLOSE
# 226 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 227 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
Lobby_EventScript_ChallengeHistorian_4:
# 229 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 230 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_2:
# 194 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 195 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 196 "data/maps/Lobby/scripts.pory"
	faceplayer
# 197 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_1, MSGBOX_AUTOCLOSE
# 198 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 199 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SadWithDelay48
# 200 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 201 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_ChallengeHistorian_5:
# 220 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ChallengeHistorian_Text_6, MSGBOX_AUTOCLOSE
# 221 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 222 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
	goto Lobby_EventScript_ChallengeHistorian_4


Lobby_EventScript_Shop::
# 236 "data/maps/Lobby/scripts.pory"
	lock
# 237 "data/maps/Lobby/scripts.pory"
	faceplayer
# 238 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 239 "data/maps/Lobby/scripts.pory"
	waitmessage
# 240 "data/maps/Lobby/scripts.pory"
	pokemart Lobby_MartItems
# 241 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 242 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 246 "data/maps/Lobby/scripts.pory"
Lobby_MartItems:
# 247 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 248 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 249 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 250 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 251 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 252 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 253 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 254 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 255 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 256 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 257 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 258 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 259 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 260 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 261 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 262 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 263 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 264 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 265 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 266 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 267 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 268 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 269 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 270 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 271 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 272 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 273 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 274 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 275 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_Roxas_IntroFirstBattle::
# 279 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 280 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 283 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 285 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 286 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 287 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 288 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 289 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 290 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 291 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 292 "data/maps/Lobby/scripts.pory"
	delay 20
# 293 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 294 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 295 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 296 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 297 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 298 "data/maps/Lobby/scripts.pory"
	delay 20
# 299 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 281 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 304 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 305 "data/maps/Lobby/scripts.pory"
	closemessage
# 306 "data/maps/Lobby/scripts.pory"
	delay 20
# 307 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 311 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 312 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 308 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 318 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 319 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 322 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 326 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 320 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 323 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 333 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 334 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 335 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 336 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 337 "data/maps/Lobby/scripts.pory"
	waitstate
# 338 "data/maps/Lobby/scripts.pory"
	lock
# 339 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 345 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 340 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 341 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 342 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 350 "data/maps/Lobby/scripts.pory"
	lock
# 351 "data/maps/Lobby/scripts.pory"
	faceplayer
# 352 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 403 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 404 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 405 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 406 "data/maps/Lobby/scripts.pory"
	delay 20
# 407 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 408 "data/maps/Lobby/scripts.pory"
	delay 20
# 409 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 410 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 411 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 412 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 413 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 414 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 415 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 416 "data/maps/Lobby/scripts.pory"
	lock
# 417 "data/maps/Lobby/scripts.pory"
	delay 20
# 418 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 419 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 420 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 421 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 353 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 354 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 355 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 358 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 360 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 361 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 362 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 366 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 371 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 372 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 375 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 376 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 377 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 378 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 379 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 380 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 381 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 382 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 389 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 390 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 393 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 395 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 396 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 397 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 399 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 400 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 356 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 363 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 364 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 367 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 368 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 383 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 384 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 385 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 386 "data/maps/Lobby/scripts.pory"
	delay 40
# 387 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 391 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 433 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 434 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 435 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 438 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 441 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 444 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 436 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 439 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 442 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 445 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 453 "data/maps/Lobby/scripts.pory"
	lock
# 454 "data/maps/Lobby/scripts.pory"
	faceplayer
# 455 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 456 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 457 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 458 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 462 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 463 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 464 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 469 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 470 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 475 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 476 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 481 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 482 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 487 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 488 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 493 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 494 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 499 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 500 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 505 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 506 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 511 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
# 516 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_8, 8
# 517 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 518 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 519 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
# 524 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 525 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33
# 529 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34
# 533 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
# 537 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36
# 541 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37
# 545 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
# 549 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39
# 553 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 558 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 465 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 466 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 467 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 471 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 472 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 473 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 477 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 478 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 479 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 483 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 484 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 485 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 489 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 490 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 491 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 495 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 496 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 497 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 501 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 502 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 503 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 507 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 508 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 509 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 512 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 513 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 520 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 521 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33:
# 526 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 527 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 528 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 530 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 531 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 532 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 534 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 535 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 536 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36:
# 538 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 539 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 540 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 542 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 543 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 544 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 546 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 547 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 548 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39:
# 550 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 551 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 552 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 554 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 555 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 556 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31


Lobby_EventScript_ShowFakemonDexInfo::
# 562 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 563 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 564 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 565 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 568 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 570 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 571 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 572 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 573 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 576 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 577 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 578 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 581 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 582 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 583 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 586 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 587 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 588 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 589 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 590 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 566 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 574 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 579 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 584 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 595 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_QREventInfoKid::
# 600 "data/maps/Lobby/scripts.pory"
	lock
# 601 "data/maps/Lobby/scripts.pory"
	faceplayer
# 602 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 603 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 604 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 605 "data/maps/Lobby/scripts.pory"
	release
	end


# 286 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 286 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 286 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 288 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 288 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 288 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 288 "data/maps/Lobby/scripts.pory"
	face_player
# 288 "data/maps/Lobby/scripts.pory"
	delay_16
# 288 "data/maps/Lobby/scripts.pory"
	delay_16
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
# 111 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 116 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 137 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy la encargada de la selección\n"
	.string "de dificultad del desafío.\p"
	.string "No parece que la dificultad actual sea\n"
	.string "la adecuada para ti.\p"
	.string "¿Quieres cambiar el nivel de dificultad?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 142 "data/maps/Lobby/scripts.pory"
	.string "¡Listo! La dificultad ha sido actualizada.\n¡Buena suerte con el desafío!$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_0:
# 161 "data/maps/Lobby/scripts.pory"
	.string "0$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_1:
# 166 "data/maps/Lobby/scripts.pory"
	.string "victoria$"

Lobby_EventScript_BufferVictoryWordFromCountVar_Text_2:
# 168 "data/maps/Lobby/scripts.pory"
	.string "victorias$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_0:
# 180 "data/maps/Lobby/scripts.pory"
	.string "vez$"

Lobby_EventScript_BufferTimeWordFromCountVar_Text_1:
# 182 "data/maps/Lobby/scripts.pory"
	.string "veces$"

Lobby_EventScript_ChallengeHistorian_Text_0:
# 191 "data/maps/Lobby/scripts.pory"
	.string "¡Hey, {PLAYER}! No trabajo aquí ni\n"
	.string "nada, pero me encanta sacar\l"
	.string "estadísticas.\p"
	.string "Me quedo en la sala de espera\n"
	.string "observando a todos los que entran y lo\l"
	.string "anoto todo.$"

Lobby_EventScript_ChallengeHistorian_Text_1:
# 197 "data/maps/Lobby/scripts.pory"
	.string "Veo que aún no has completado el\n"
	.string "desafío ni una vez.\p"
	.string "Todavía no te has ganado un lugar en\n"
	.string "mis notas.$"

Lobby_EventScript_ChallengeHistorian_Text_2:
# 209 "data/maps/Lobby/scripts.pory"
	.string "Según mi cuaderno, en modo estándar\n"
	.string "llevas {STR_VAR_1} {STR_VAR_2}.\p"
	.string "¡Nada mal, de verdad!$"

Lobby_EventScript_ChallengeHistorian_Text_3:
# 212 "data/maps/Lobby/scripts.pory"
	.string "En batallas dobles tienes\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ahí se nota quién piensa dos turnos por\n"
	.string "adelantado.$"

Lobby_EventScript_ChallengeHistorian_Text_4:
# 215 "data/maps/Lobby/scripts.pory"
	.string "Y en batallas invertidas sumas\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "Ese modo le da vuelta la cabeza a\n"
	.string "cualquiera.$"

Lobby_EventScript_ChallengeHistorian_Text_5:
# 218 "data/maps/Lobby/scripts.pory"
	.string "En total, has completado el desafío\n"
	.string "{STR_VAR_1} {STR_VAR_2}.$"

Lobby_EventScript_ChallengeHistorian_Text_6:
# 220 "data/maps/Lobby/scripts.pory"
	.string "¡Si sigues así, voy a tener que comprar\n"
	.string "otro cuaderno para registrar tus\l"
	.string "números!$"

Lobby_EventScript_ChallengeHistorian_Text_7:
# 225 "data/maps/Lobby/scripts.pory"
	.string "Aún no son tantas victorias, pero sigue\n"
	.string "así.$"

Lobby_EventScript_Shop_Text_0:
# 238 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 241 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 281 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 283 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 289 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 293 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 296 "data/maps/Lobby/scripts.pory"
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
# 304 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 320 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: elige\n"
	.string "a tres de tus bichos.\p"
	.string "Yo voy a salir con mi legendario, así que\n"
	.string "más te vale elegir bien.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 326 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate para\n"
	.string "enfrentar a mi legendario.$"

Lobby_EventScript_Roxas_Text_0:
# 375 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 377 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 385 "data/maps/Lobby/scripts.pory"
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
# 391 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 393 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 397 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 403 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 407 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 415 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras, loco!$"

Lobby_EventScript_Roxas_Text_9:
# 418 "data/maps/Lobby/scripts.pory"
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
# 420 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 455 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 512 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 517 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 520 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 563 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokedex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 566 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 568 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 570 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 574 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 587 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 590 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 595 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 602 "data/maps/Lobby/scripts.pory"
	.string "Un chico de la zona creativa te da un\n"
	.string "regalo por completar un evento\l"
	.string "especial.\p"
	.string "Es imposible adivinar lo que hay que\n"
	.string "hacer sin mirar el vídeo.\p"
	.string "¡Incluso tuve que cambiar de orden a\n"
	.string "dos de los Pokémon de mi equipo!\p"
	.string "Eso sí, me gustó el premio por completar\n"
	.string "el evento, ¡valió la pena!$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 129 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_DifficultySelector_Cancelled::
# 154 "data/maps/Lobby/scripts.pory"
	.string "¡Entendido! Si cambias de opinión,\n"
	.string "estaré por aquí.$"

Lobby_Text_Roxas_PlayerCancelled::
# 428 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"
