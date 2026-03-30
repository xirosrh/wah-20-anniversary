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
	setspeaker SP_NAME_COPE
# 20 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_StartChallenge_Text_1
# 21 "data/maps/Lobby/scripts.pory"
	waitmessage
# 22 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_2, 0
# 23 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_3, 1
# 24 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_StartChallenge_2
Lobby_EventScript_StartChallenge_1:
# 27 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_5, 4
# 28 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 4, 0, 0, DYN_MULTICHOICE_CB_NONE
# 29 "data/maps/Lobby/scripts.pory"
	closemessage
# 30 "data/maps/Lobby/scripts.pory"
	delay 10
# 31 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 32 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_5
# 37 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_6
# 43 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_StartChallenge_7
# 50 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 51 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_COPE, Common_Movement_Surprise
# 52 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 53 "data/maps/Lobby/scripts.pory"
	delay 60
# 54 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 55 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 56 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
# 57 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_StartChallenge_2:
# 25 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_4, 2
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_5:
# 33 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD
# 34 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 35 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 36 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_6:
# 38 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_DOUBLE
# 39 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 40 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 41 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 42 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return

Lobby_EventScript_StartChallenge_7:
# 44 "data/maps/Lobby/scripts.pory"
	setvar VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_INVERSE
# 45 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 46 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 47 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 48 "data/maps/Lobby/scripts.pory"
	goto Lobby_StartChallenge_EnterOmegaRoom
	return


Lobby_StartChallenge_EnterOmegaRoom::
# 63 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 64 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_OpenDoor
# 65 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 66 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 67 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 68 "data/maps/Lobby/scripts.pory"
	waitstate
# 69 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_OpenDoor::
# 75 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_Delay32
# 76 "data/maps/Lobby/scripts.pory"
	playse SE_DOOR
# 77 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening1, FALSE
# 78 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 79 "data/maps/Lobby/scripts.pory"
	delay 5
# 80 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Opening2, FALSE
# 81 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
# 82 "data/maps/Lobby/scripts.pory"
	delay 5
# 83 "data/maps/Lobby/scripts.pory"
	setmetatile 7, 2, METATILE_RoomGeneral_Door_Open, FALSE
# 84 "data/maps/Lobby/scripts.pory"
	special DrawWholeMapView
	return


Lobby_EventScript_TeamSelector::
# 90 "data/maps/Lobby/scripts.pory"
	lock
# 91 "data/maps/Lobby/scripts.pory"
	faceplayer
# 92 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 93 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 102 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 104 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 105 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 94 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 95 "data/maps/Lobby/scripts.pory"
	waitstate
# 96 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 99 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 97 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 116 "data/maps/Lobby/scripts.pory"
	lock
# 117 "data/maps/Lobby/scripts.pory"
	faceplayer
# 118 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 119 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 128 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 130 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 131 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 120 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 121 "data/maps/Lobby/scripts.pory"
	waitstate
# 122 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 125 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 123 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_Shop::
# 141 "data/maps/Lobby/scripts.pory"
	lock
# 142 "data/maps/Lobby/scripts.pory"
	faceplayer
# 143 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 144 "data/maps/Lobby/scripts.pory"
	waitmessage
# 145 "data/maps/Lobby/scripts.pory"
	pokemart Lobby_MartItems
# 146 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 147 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 151 "data/maps/Lobby/scripts.pory"
Lobby_MartItems:
# 152 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 153 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 154 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 155 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 156 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 157 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 158 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 159 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 160 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 161 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 162 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 163 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 164 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 165 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 166 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 167 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 168 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 169 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 170 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 171 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 172 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 173 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 174 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 175 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 176 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 177 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 178 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 179 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 180 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_Roxas_IntroFirstBattle::
# 184 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 185 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 188 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 190 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 191 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 192 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 193 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 194 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 195 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 196 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 197 "data/maps/Lobby/scripts.pory"
	delay 20
# 198 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 199 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 200 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 201 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 202 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 203 "data/maps/Lobby/scripts.pory"
	delay 20
# 204 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 186 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 209 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 210 "data/maps/Lobby/scripts.pory"
	closemessage
# 211 "data/maps/Lobby/scripts.pory"
	delay 20
# 212 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 216 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 217 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 213 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_ExplainPartyLimit
	return


Lobby_EventScript_Roxas_ExplainPartyLimit::
# 223 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 224 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_ExplainPartyLimit_3
# 227 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_ExplainPartyLimit_4
# 231 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_ExplainPartyLimit_1:
	return

Lobby_EventScript_Roxas_ExplainPartyLimit_3:
# 225 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1

Lobby_EventScript_Roxas_ExplainPartyLimit_4:
# 228 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_ExplainPartyLimit_1


Lobby_EventScript_Roxas_SelectPlayerMons::
# 238 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 239 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 240 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 241 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 242 "data/maps/Lobby/scripts.pory"
	waitstate
# 243 "data/maps/Lobby/scripts.pory"
	lock
# 244 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_SelectPlayerMons_2
# 250 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
	return

Lobby_EventScript_Roxas_SelectPlayerMons_2:
# 245 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 246 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 247 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Roxas::
# 255 "data/maps/Lobby/scripts.pory"
	lock
# 256 "data/maps/Lobby/scripts.pory"
	faceplayer
# 257 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 308 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 309 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 310 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 311 "data/maps/Lobby/scripts.pory"
	delay 20
# 312 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 313 "data/maps/Lobby/scripts.pory"
	delay 20
# 314 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 315 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 316 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 317 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 318 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 319 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 320 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 321 "data/maps/Lobby/scripts.pory"
	lock
# 322 "data/maps/Lobby/scripts.pory"
	delay 20
# 323 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 324 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 325 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 326 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_1:
# 258 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 259 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 260 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 263 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 265 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 266 "data/maps/Lobby/scripts.pory"
	switch VAR_DIFFICULTY
# 267 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_EASY, Lobby_EventScript_Roxas_10
# 271 "data/maps/Lobby/scripts.pory"
	case DIFFICULTY_NORMAL, Lobby_EventScript_Roxas_11
# 276 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 277 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
Lobby_EventScript_Roxas_8:
# 280 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 281 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 282 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 283 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 284 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 285 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 286 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 287 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_14
# 294 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 295 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_18
# 298 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_17:
# 300 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 301 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 302 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_13:
# 304 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllAdmins
# 305 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_Roxas_5:
# 261 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_10:
# 268 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 269 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_11:
# 272 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 3
# 273 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_SelectPlayerMons
	goto Lobby_EventScript_Roxas_8

Lobby_EventScript_Roxas_14:
# 288 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 289 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_X
# 290 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 291 "data/maps/Lobby/scripts.pory"
	delay 40
# 292 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_13

Lobby_EventScript_Roxas_18:
# 296 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_17


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 338 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 339 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 340 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 343 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 346 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 349 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 341 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 344 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 347 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 350 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 358 "data/maps/Lobby/scripts.pory"
	lock
# 359 "data/maps/Lobby/scripts.pory"
	faceplayer
# 360 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 361 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 362 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 363 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 367 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 368 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 369 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 374 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 375 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 380 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 381 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 386 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 387 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 392 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 393 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 398 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 399 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 404 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 405 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 410 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 411 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 416 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
# 421 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_5, 8
# 422 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 423 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 424 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
# 429 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 430 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33
# 434 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34
# 438 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
# 442 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36
# 446 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37
# 450 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
# 454 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39
# 458 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 463 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 370 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 371 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 372 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 376 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 377 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 378 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 382 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 383 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 384 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 388 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 389 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 390 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 394 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 395 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 396 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 400 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 401 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 402 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 406 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 407 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 408 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 412 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 413 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 414 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 417 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 418 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 425 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 426 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33:
# 431 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 432 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 433 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 435 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 436 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 437 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 439 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 440 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 441 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36:
# 443 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 444 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 445 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 447 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 448 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 449 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 451 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 452 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 453 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39:
# 455 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 456 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 457 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 459 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 460 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 461 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31


Lobby_EventScript_ShowFakemonDexInfo::
# 467 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 468 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 469 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 470 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 473 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 475 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 476 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 477 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 478 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 481 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 482 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 483 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 486 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 487 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 488 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 491 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 492 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 493 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 494 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 495 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 471 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 479 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 484 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 489 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 500 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


Lobby_EventScript_QREventInfoKid::
# 505 "data/maps/Lobby/scripts.pory"
	lock
# 506 "data/maps/Lobby/scripts.pory"
	faceplayer
# 507 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_QREventInfoKid_Text_0, MSGBOX_AUTOCLOSE
# 508 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 509 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 510 "data/maps/Lobby/scripts.pory"
	release
	end


# 191 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 191 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 191 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 193 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 193 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 193 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 193 "data/maps/Lobby/scripts.pory"
	face_player
# 193 "data/maps/Lobby/scripts.pory"
	delay_16
# 193 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

Lobby_EventScript_StartChallenge_Text_0:
# 15 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 20 "data/maps/Lobby/scripts.pory"
	.string "¿En qué modo quieres afrontar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_2:
# 22 "data/maps/Lobby/scripts.pory"
	.string "Estándar$"

Lobby_EventScript_StartChallenge_Text_3:
# 23 "data/maps/Lobby/scripts.pory"
	.string "Batallas dobles$"

Lobby_EventScript_StartChallenge_Text_4:
# 25 "data/maps/Lobby/scripts.pory"
	.string "Batallas inversas$"

Lobby_EventScript_StartChallenge_Text_5:
# 27 "data/maps/Lobby/scripts.pory"
	.string "Salir$"

Lobby_EventScript_StartChallenge_Text_6:
# 35 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Adelante, ¡te deseo mucha\n"
	.string "suerte y sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_7:
# 41 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas dobles.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_8:
# 47 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas inversas.\p"
	.string "Las efectividades de tipo se invierten:\n"
	.string "lo que normalmente es súper efectivo\l"
	.string "será poco efectivo y viceversa.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_9:
# 52 "data/maps/Lobby/scripts.pory"
	.string "¿Así que no te sientes list{OA}?$"

Lobby_EventScript_StartChallenge_Text_10:
# 54 "data/maps/Lobby/scripts.pory"
	.string "Recuerda que las personas de la sala de\n"
	.string "espera pueden ayudar en tu\l"
	.string "preparación.$"

Lobby_EventScript_TeamSelector_Text_0:
# 92 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 97 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 118 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy la encargada de la selección\n"
	.string "de dificultad del desafío.\p"
	.string "No parece que la dificultad actual sea\n"
	.string "la adecuada para ti.\p"
	.string "¿Quieres cambiar el nivel de dificultad?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 123 "data/maps/Lobby/scripts.pory"
	.string "¡Listo! La dificultad ha sido actualizada.\n¡Buena suerte con el desafío!$"

Lobby_EventScript_Shop_Text_0:
# 143 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 146 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 186 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 188 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 194 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 198 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 201 "data/maps/Lobby/scripts.pory"
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
# 209 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_0:
# 225 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: elegí\n"
	.string "a tres de tus bichos.\p"
	.string "Yo voy a salir con mi legendario, así que\n"
	.string "más te vale elegir bien.$"

Lobby_EventScript_Roxas_ExplainPartyLimit_Text_1:
# 231 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate para\n"
	.string "enfrentar a mi legendario.$"

Lobby_EventScript_Roxas_Text_0:
# 280 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 282 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 290 "data/maps/Lobby/scripts.pory"
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
# 296 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 298 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 302 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 308 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 312 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 320 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras loco!$"

Lobby_EventScript_Roxas_Text_9:
# 323 "data/maps/Lobby/scripts.pory"
	.string "Pero bueno, tampoco me voy a quedar acá\n"
	.string "llorando.\p"
	.string "Estoy tras un barco que desapareció al\n"
	.string "oeste de las Islas Naranja, el\l"
	.string "archipiélago Suzuka.\p"
	.string "El Team Rocket anda haciendo de las\n"
	.string "suyas y dicen que hay un bicho oscuro\l"
	.string "con ojos rojos que es un peligro…\l"
	.string "Aterrador…\p"
	.string "Habrá que investigar y ver que onda…$"

Lobby_EventScript_Roxas_Text_10:
# 325 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 360 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 417 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 422 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 425 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 468 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokedex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 471 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 473 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 475 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 479 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 492 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 495 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 500 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_EventScript_QREventInfoKid_Text_0:
# 507 "data/maps/Lobby/scripts.pory"
	.string "Un chico de la zona creativa te da un\n"
	.string "regalo por completar un evento\l"
	.string "especial.\p"
	.string "Es imposible adivinar lo que hay que\n"
	.string "hacer sin mirar el video.\p"
	.string "¡Incluso tuve que cambiar de orden a\n"
	.string "dos de los Pokémon de mi equipo!\p"
	.string "Eso sí, me gustó el premio por completar\n"
	.string "el evento, ¡valió la pena!$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 110 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_DifficultySelector_Cancelled::
# 135 "data/maps/Lobby/scripts.pory"
	.string "¡Entendido! Si cambias de opinión,\n"
	.string "estaré por aquí.$"

Lobby_Text_Roxas_PlayerCancelled::
# 333 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"
