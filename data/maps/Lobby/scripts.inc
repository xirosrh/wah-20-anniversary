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
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, Lobby_EventScript_StartChallenge_Text_2, Lobby_EventScript_StartChallenge_Text_3, Lobby_EventScript_StartChallenge_Text_4
# 23 "data/maps/Lobby/scripts.pory"
	closemessage
# 24 "data/maps/Lobby/scripts.pory"
	delay 10
# 25 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 26 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_StartChallenge_3
# 35 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_StartChallenge_4
# 46 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 47 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_LOBBY_COPE, Common_Movement_SurpriseWithDelay48
# 48 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 49 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 50 "data/maps/Lobby/scripts.pory"
	delay 20
# 51 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 52 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 53 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
Lobby_EventScript_StartChallenge_1:
# 55 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_StartChallenge_3:
# 27 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 28 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 29 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 30 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_OpenDoor
# 31 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp
# 32 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 33 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 34 "data/maps/Lobby/scripts.pory"
	waitstate
	goto Lobby_EventScript_StartChallenge_1

Lobby_EventScript_StartChallenge_4:
# 36 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 37 "data/maps/Lobby/scripts.pory"
	setflag FLAG_FORCE_DOUBLE_BATTLE
# 38 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 39 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 40 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_OpenDoor
# 41 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp
# 42 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 43 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 44 "data/maps/Lobby/scripts.pory"
	waitstate
	goto Lobby_EventScript_StartChallenge_1


Lobby_EventScript_TeamSelector::
# 61 "data/maps/Lobby/scripts.pory"
	lock
# 62 "data/maps/Lobby/scripts.pory"
	faceplayer
# 63 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 64 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 73 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 75 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 76 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 65 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 66 "data/maps/Lobby/scripts.pory"
	waitstate
# 67 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 70 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 68 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_DifficultySelector::
# 87 "data/maps/Lobby/scripts.pory"
	lock
# 88 "data/maps/Lobby/scripts.pory"
	faceplayer
# 89 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_0, MSGBOX_YESNO
# 90 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_DifficultySelector_2
# 99 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_DifficultySelector_1:
# 101 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 102 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_DifficultySelector_2:
# 91 "data/maps/Lobby/scripts.pory"
	special OpenDifficultySelectorFromField
# 92 "data/maps/Lobby/scripts.pory"
	waitstate
# 93 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_DifficultySelector_5
# 96 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_DifficultySelector_Cancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1

Lobby_EventScript_DifficultySelector_5:
# 94 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_DifficultySelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_DifficultySelector_1


Lobby_EventScript_Shop::
# 112 "data/maps/Lobby/scripts.pory"
	lock
# 113 "data/maps/Lobby/scripts.pory"
	faceplayer
# 114 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 115 "data/maps/Lobby/scripts.pory"
	waitmessage
# 116 "data/maps/Lobby/scripts.pory"
	pokemart Lobby_MartItems
# 117 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 118 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 122 "data/maps/Lobby/scripts.pory"
Lobby_MartItems:
# 123 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 124 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 125 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 126 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 127 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 128 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 129 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 130 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 131 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 132 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 133 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 134 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 135 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 136 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 137 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 138 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 139 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 140 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 141 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 142 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 143 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 144 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 145 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 146 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 147 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 148 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 149 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 150 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 151 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_Roxas_IntroFirstBattle::
# 155 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 156 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 159 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 161 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 162 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 163 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 164 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 165 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 166 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 167 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 168 "data/maps/Lobby/scripts.pory"
	delay 20
# 169 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 170 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 171 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 172 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 173 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 174 "data/maps/Lobby/scripts.pory"
	delay 20
# 175 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 157 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 180 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 181 "data/maps/Lobby/scripts.pory"
	closemessage
# 182 "data/maps/Lobby/scripts.pory"
	delay 20
# 183 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 187 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 188 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 184 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_1, speaker = SP_NAME_ROXAS
	return


Lobby_EventScript_Roxas::
# 194 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 247 "data/maps/Lobby/scripts.pory"
	lockall
# 248 "data/maps/Lobby/scripts.pory"
	faceplayer
# 249 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 250 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 251 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 252 "data/maps/Lobby/scripts.pory"
	delay 20
# 253 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 254 "data/maps/Lobby/scripts.pory"
	delay 20
# 255 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 256 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 257 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 258 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 259 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 260 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 261 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 262 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 263 "data/maps/Lobby/scripts.pory"
	lockall
# 264 "data/maps/Lobby/scripts.pory"
	delay 20
# 265 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 266 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 267 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 268 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_1:
# 195 "data/maps/Lobby/scripts.pory"
	lockall
# 196 "data/maps/Lobby/scripts.pory"
	faceplayer
# 197 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 198 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 199 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 202 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 204 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 205 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 206 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 207 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 208 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 209 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 210 "data/maps/Lobby/scripts.pory"
	waitstate
# 211 "data/maps/Lobby/scripts.pory"
	lockall
# 212 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_9
# 218 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 219 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 220 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 221 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 222 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 223 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 224 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 225 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 226 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_12
# 233 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 234 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_16
# 237 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_15:
# 239 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 240 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 241 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_11:
# 243 "data/maps/Lobby/scripts.pory"
	call Achievements_EventScript_Eval_AllAdminsDefeated
# 244 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_5:
# 200 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_9:
# 213 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 214 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 215 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_12:
# 227 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 228 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_X
# 229 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_AUTOCLOSE
# 230 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 231 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_11

Lobby_EventScript_Roxas_16:
# 235 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_15


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 278 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 279 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 280 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 283 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 286 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 289 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 281 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 284 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 287 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 290 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_FakemonDexMenu::
# 298 "data/maps/Lobby/scripts.pory"
	lock
# 299 "data/maps/Lobby/scripts.pory"
	faceplayer
# 300 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 301 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 302 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 303 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 307 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 308 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 309 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 314 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 315 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 320 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 321 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 326 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 327 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 332 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 333 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 338 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 339 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 344 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 345 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 350 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 351 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 356 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
# 361 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_StartChallenge_Text_4, 8
# 362 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1
# 363 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 364 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
# 369 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 370 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33
# 374 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34
# 378 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
# 382 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36
# 386 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37
# 390 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
# 394 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39
# 398 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 403 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 310 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 311 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 312 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 316 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 317 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 318 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 322 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 323 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 324 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 328 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 329 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 330 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 334 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 335 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 336 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 340 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 341 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 342 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 346 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 347 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 348 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 352 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 353 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 354 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 357 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 358 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 365 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2, MSGBOX_AUTOCLOSE
# 366 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33:
# 371 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 372 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 373 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 375 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 376 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 377 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 379 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 380 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 381 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36:
# 383 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 384 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 385 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 387 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 388 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 389 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 391 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 392 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 393 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39:
# 395 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 396 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 397 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 399 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 400 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 401 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31


Lobby_EventScript_ShowFakemonDexInfo::
# 407 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 408 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 409 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 410 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 413 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 415 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 416 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 417 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 418 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 421 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 422 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 423 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 426 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 427 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 428 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 431 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 432 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 433 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 434 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 435 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 411 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 419 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 424 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 429 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_TrainerCardGirl::
# 440 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TrainerCardGirl_Text_0, MSGBOX_NPC
	end


# 162 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 162 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 162 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 164 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 164 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 164 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 164 "data/maps/Lobby/scripts.pory"
	face_player
# 164 "data/maps/Lobby/scripts.pory"
	delay_16
# 164 "data/maps/Lobby/scripts.pory"
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
# 22 "data/maps/Lobby/scripts.pory"
	.string "Batallas dobles$"

Lobby_EventScript_StartChallenge_Text_4:
# 22 "data/maps/Lobby/scripts.pory"
	.string "Salir$"

Lobby_EventScript_StartChallenge_Text_5:
# 28 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Adelante, ¡te deseo mucha\n"
	.string "suerte y sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_6:
# 38 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! El desafío será en modo\n"
	.string "batallas dobles.\p"
	.string "¡Adelante, te deseo mucha suerte y\n"
	.string "sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_7:
# 48 "data/maps/Lobby/scripts.pory"
	.string "¿Así que no te sientes list{OA}?$"

Lobby_EventScript_StartChallenge_Text_8:
# 51 "data/maps/Lobby/scripts.pory"
	.string "Recuerda que las personas de la sala de\n"
	.string "espera pueden ayudar en tu\l"
	.string "preparación.$"

Lobby_EventScript_TeamSelector_Text_0:
# 63 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 68 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_DifficultySelector_Text_0:
# 89 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy la encargada de la selección\n"
	.string "de dificultad del desafío.\p"
	.string "No parece que la dificultad actual sea\n"
	.string "la adecuada para ti.\p"
	.string "¿Quieres cambiar el nivel de dificultad?$"

Lobby_EventScript_DifficultySelector_Text_1:
# 94 "data/maps/Lobby/scripts.pory"
	.string "¡Listo! La dificultad ha sido actualizada.\n¡Buena suerte con el desafío!$"

Lobby_EventScript_Shop_Text_0:
# 114 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 117 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 157 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 159 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 165 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 169 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 172 "data/maps/Lobby/scripts.pory"
	.string "Terminé mi investigación en el\n"
	.string "Archipiélago Suzuka… es una historia\l"
	.string "larga, tendrías que haberlo visto…\p"
	.string "No sabes lo que fue… Pero logré dar con\n"
	.string "el rastro de esa fuerza que estaba\l"
	.string "causando tantos males y estoy listo\l"
	.string "para probar si realmente este bicho es\l"
	.string "tan legendario como dicen las crónicas\l"
	.string "del archipiélago.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_5:
# 175 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate.$"

Lobby_EventScript_Roxas_IntroRematch_Text_0:
# 180 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_IntroRematch_Text_1:
# 184 "data/maps/Lobby/scripts.pory"
	.string "¡Vamos de nuevo! Elige a tu mejor bicho\n"
	.string "y prepárate.$"

Lobby_EventScript_Roxas_Text_0:
# 219 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 221 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 229 "data/maps/Lobby/scripts.pory"
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
# 235 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 237 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 241 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 249 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 253 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 261 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras loco!$"

Lobby_EventScript_Roxas_Text_9:
# 265 "data/maps/Lobby/scripts.pory"
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
# 267 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 300 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 357 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 362 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 365 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 408 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokedex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 411 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 413 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 415 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 419 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 432 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 435 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_TrainerCardGirl_Text_0:
# 440 "data/maps/Lobby/scripts.pory"
	.string "¿Sabías que en la parte de atrás de tu\n"
	.string "tarjeta de entrenador puedes ver tus\l"
	.string "logros?\p"
	.string "¡También puedes ver los requerimientos\n"
	.string "para obtener cada uno!$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 81 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_DifficultySelector_Cancelled::
# 106 "data/maps/Lobby/scripts.pory"
	.string "¡Entendido! Si cambias de opinión,\n"
	.string "estaré por aquí.$"

Lobby_Text_Roxas_PlayerCancelled::
# 273 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"
