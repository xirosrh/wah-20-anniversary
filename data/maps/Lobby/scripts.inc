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
	msgbox Lobby_EventScript_StartChallenge_Text_1, MSGBOX_YESNO, speaker = SP_NAME_COPE
# 20 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 21 "data/maps/Lobby/scripts.pory"
	closemessage
# 22 "data/maps/Lobby/scripts.pory"
	delay 10
# 23 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_2
# 33 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 34 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_LOBBY_COPE, Common_Movement_SurpriseWithDelay48
# 35 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 36 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 37 "data/maps/Lobby/scripts.pory"
	delay 20
# 38 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 39 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 40 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_COPE, DIR_SOUTH
Lobby_EventScript_StartChallenge_1:
# 42 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_StartChallenge_2:
# 24 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
# 25 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_COPE
# 26 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 27 "data/maps/Lobby/scripts.pory"
	call WahRoomsShared_OpenDoor
# 28 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp
# 29 "data/maps/Lobby/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_LOBBY
# 30 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 31 "data/maps/Lobby/scripts.pory"
	waitstate
	goto Lobby_EventScript_StartChallenge_1


Lobby_EventScript_TeamSelector::
# 48 "data/maps/Lobby/scripts.pory"
	lock
# 49 "data/maps/Lobby/scripts.pory"
	faceplayer
# 50 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 51 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 60 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 62 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 63 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 52 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 53 "data/maps/Lobby/scripts.pory"
	waitstate
# 54 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 57 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 55 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_Shop::
# 74 "data/maps/Lobby/scripts.pory"
	lock
# 75 "data/maps/Lobby/scripts.pory"
	faceplayer
# 76 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 77 "data/maps/Lobby/scripts.pory"
	waitmessage
# 78 "data/maps/Lobby/scripts.pory"
	pokemart Lobby_MartItems
# 79 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 80 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 84 "data/maps/Lobby/scripts.pory"
Lobby_MartItems:
# 85 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 86 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 87 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 88 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 89 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 90 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 91 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 92 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 93 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 94 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 95 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 96 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 97 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 98 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 99 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 100 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 101 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 102 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 103 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 104 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 105 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 106 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 107 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 108 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 109 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 110 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 111 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 112 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 113 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_Roxas_IntroFirstBattle::
# 117 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 118 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 121 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 123 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 124 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 125 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 126 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 127 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 128 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 129 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 130 "data/maps/Lobby/scripts.pory"
	delay 20
# 131 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 132 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 133 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 134 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 135 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 136 "data/maps/Lobby/scripts.pory"
	delay 20
# 137 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 119 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 142 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 143 "data/maps/Lobby/scripts.pory"
	closemessage
# 144 "data/maps/Lobby/scripts.pory"
	delay 20
# 145 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 149 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 150 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 146 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_1, speaker = SP_NAME_ROXAS
	return


Lobby_EventScript_Roxas::
# 156 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 208 "data/maps/Lobby/scripts.pory"
	lockall
# 209 "data/maps/Lobby/scripts.pory"
	faceplayer
# 210 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 211 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 212 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 213 "data/maps/Lobby/scripts.pory"
	delay 20
# 214 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 215 "data/maps/Lobby/scripts.pory"
	delay 20
# 216 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 217 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 218 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 219 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 220 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 221 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 222 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 223 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 224 "data/maps/Lobby/scripts.pory"
	lockall
# 225 "data/maps/Lobby/scripts.pory"
	delay 20
# 226 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 227 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 228 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 229 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_1:
# 157 "data/maps/Lobby/scripts.pory"
	lockall
# 158 "data/maps/Lobby/scripts.pory"
	faceplayer
# 159 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 160 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 161 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 164 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 166 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 167 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 168 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 169 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 170 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 171 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 172 "data/maps/Lobby/scripts.pory"
	waitstate
# 173 "data/maps/Lobby/scripts.pory"
	lockall
# 174 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_9
# 180 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 181 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 182 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 183 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 184 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 185 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 186 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 187 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 188 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_12
# 195 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 196 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_16
# 199 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_15:
# 201 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 202 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 203 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_11:
# 205 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_5:
# 162 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_9:
# 175 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 176 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 177 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_12:
# 189 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 190 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_X
# 191 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_DEFAULT
# 192 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 193 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_11

Lobby_EventScript_Roxas_16:
# 197 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_15


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 239 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 240 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 241 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 244 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 247 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 250 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 242 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 245 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 248 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 251 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_Kaktus_IntroFirstBattle::
# 258 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 259 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 260 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 261 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 262 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 263 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 264 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_Kaktus_IntroFirstBattle_3
# 266 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_Kaktus_IntroFirstBattle_4
# 268 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_Kaktus_IntroFirstBattle_5
# 270 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_Kaktus_IntroFirstBattle_6
Lobby_EventScript_Kaktus_IntroFirstBattle_1:
	return

Lobby_EventScript_Kaktus_IntroFirstBattle_3:
# 265 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1

Lobby_EventScript_Kaktus_IntroFirstBattle_4:
# 267 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1

Lobby_EventScript_Kaktus_IntroFirstBattle_5:
# 269 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1

Lobby_EventScript_Kaktus_IntroFirstBattle_6:
# 271 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1


Lobby_EventScript_Kaktus_IntroRematch::
# 277 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_INMORTAL_KAKTUS
# 278 "data/maps/Lobby/scripts.pory"
	closemessage
# 279 "data/maps/Lobby/scripts.pory"
	delay 20
# 280 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Kaktus_IntroRematch_1
# 284 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 285 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Kaktus_OnFinishEvent
	return

Lobby_EventScript_Kaktus_IntroRematch_1:
# 281 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroRematch_Text_1, speaker = SP_NAME_INMORTAL_KAKTUS
	return


Lobby_EventScript_Kaktus_OnFinishEvent::
# 291 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 292 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Kaktus::
# 297 "data/maps/Lobby/scripts.pory"
	lock
# 298 "data/maps/Lobby/scripts.pory"
	faceplayer
# 299 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Kaktus_1
# 340 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 341 "data/maps/Lobby/scripts.pory"
	delay 20
# 342 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 343 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 344 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 345 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 346 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Kaktus_OnFinishEvent
	return

Lobby_EventScript_Kaktus_1:
# 300 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_KAKTUS, Lobby_EventScript_Kaktus_5
# 303 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Kaktus_IntroFirstBattle
Lobby_EventScript_Kaktus_4:
# 306 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 307 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 308 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 309 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 310 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 311 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, Lobby_EventScript_Kaktus_Text_0
# 312 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 313 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 314 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 315 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Kaktus_9
# 329 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 330 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 331 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 332 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 333 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Kaktus_Movement_0
# 334 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 335 "data/maps/Lobby/scripts.pory"
	waitmovement 0
Lobby_EventScript_Kaktus_8:
# 337 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Kaktus_OnFinishEvent
	return

Lobby_EventScript_Kaktus_5:
# 301 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Kaktus_IntroRematch
	goto Lobby_EventScript_Kaktus_4

Lobby_EventScript_Kaktus_9:
# 316 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 317 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 318 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 319 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 320 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 321 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 322 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 323 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 324 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 325 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 326 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 327 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_KAKTUS
	goto Lobby_EventScript_Kaktus_8


Lobby_EventScript_Gameboycl_IntroFirstBattle::
# 352 "data/maps/Lobby/scripts.pory"
	delay 20
# 353 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 354 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 355 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 356 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 357 "data/maps/Lobby/scripts.pory"
	delay 20
# 358 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 359 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


Lobby_EventScript_Gameboycl_IntroRematch::
# 364 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_GAMEBOY_CL
# 365 "data/maps/Lobby/scripts.pory"
	closemessage
# 366 "data/maps/Lobby/scripts.pory"
	delay 20
# 367 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Gameboycl_IntroRematch_1
# 371 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 372 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Gameboycl_OnFinishEvent
	return

Lobby_EventScript_Gameboycl_IntroRematch_1:
# 368 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


Lobby_EventScript_Gameboycl_OnFinishEvent::
# 377 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 378 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Gameboycl::
# 384 "data/maps/Lobby/scripts.pory"
	lock
# 385 "data/maps/Lobby/scripts.pory"
	faceplayer
# 386 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Gameboycl_1
# 421 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 422 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 423 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 424 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 425 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 426 "data/maps/Lobby/scripts.pory"
	delay 20
# 427 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Gameboycl_OnFinishEvent
	return

Lobby_EventScript_Gameboycl_1:
# 387 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_GAMEBOYCL, Lobby_EventScript_Gameboycl_5
# 390 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Gameboycl_IntroFirstBattle
Lobby_EventScript_Gameboycl_4:
# 392 "data/maps/Lobby/scripts.pory"
	delay 20
# 393 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 394 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 395 "data/maps/Lobby/scripts.pory"
	random 3
# 396 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 397 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 398 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_Gameboycl_10
# 400 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_Gameboycl_11
# 402 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_Gameboycl_12
Lobby_EventScript_Gameboycl_8:
# 405 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 406 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 407 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 408 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Gameboycl_14
# 416 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
Lobby_EventScript_Gameboycl_13:
# 418 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Gameboycl_OnFinishEvent
	return

Lobby_EventScript_Gameboycl_5:
# 388 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Gameboycl_IntroRematch
	goto Lobby_EventScript_Gameboycl_4

Lobby_EventScript_Gameboycl_10:
# 399 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, Lobby_Text_Gameboycl_OnDefeat
	goto Lobby_EventScript_Gameboycl_8

Lobby_EventScript_Gameboycl_11:
# 401 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, Lobby_Text_Gameboycl_OnDefeat
	goto Lobby_EventScript_Gameboycl_8

Lobby_EventScript_Gameboycl_12:
# 403 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, Lobby_Text_Gameboycl_OnDefeat
	goto Lobby_EventScript_Gameboycl_8

Lobby_EventScript_Gameboycl_14:
# 409 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 410 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 411 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 412 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 413 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 414 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_GAMEBOYCL
	goto Lobby_EventScript_Gameboycl_13


Lobby_EventScript_FakemonDexMenu::
# 436 "data/maps/Lobby/scripts.pory"
	lock
# 437 "data/maps/Lobby/scripts.pory"
	faceplayer
# 438 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_Text_0, MSGBOX_AUTOCLOSE
# 439 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 440 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 441 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return


Lobby_EventScript_FakemonDexMenu_ChooseSpecies::
# 445 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 446 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 447 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1:
# 452 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 453 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4:
# 458 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 459 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7:
# 464 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 465 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10:
# 470 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 471 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13:
# 476 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 477 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16:
# 482 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 483 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19:
# 488 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 489 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22:
# 494 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26
# 499 "data/maps/Lobby/scripts.pory"
	dynmultipush Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1, 8
# 500 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2
# 501 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 502 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_gt Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29
# 507 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 508 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33
# 512 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34
# 516 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35
# 520 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36
# 524 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37
# 528 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38
# 532 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39
# 536 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40
Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31:
# 541 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies
	return

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_2:
# 448 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 449 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 450 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_1

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_5:
# 454 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 455 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 456 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_4

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_8:
# 460 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 461 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 462 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_7

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_11:
# 466 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 467 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 468 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_10

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_14:
# 472 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 473 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 474 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_13

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_17:
# 478 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 479 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 480 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_16

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_20:
# 484 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 485 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 486 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_19

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_23:
# 490 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 491 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 492 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_22

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_26:
# 495 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0
# 496 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_29:
# 503 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_3, MSGBOX_AUTOCLOSE
# 504 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_33:
# 509 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_KAOSUNE, 10, 3
# 510 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_KAOSUNE
# 511 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_34:
# 513 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_FREECH, 10, 3
# 514 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_FREECH
# 515 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_35:
# 517 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_PLUGOINK, 10, 3
# 518 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_PLUGOINK
# 519 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_36:
# 521 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_GRITESPEC, 10, 3
# 522 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRITESPEC
# 523 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_37:
# 525 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_MAGIKEN, 10, 3
# 526 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_MAGIKEN
# 527 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_38:
# 529 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_AYEWIRAZ, 10, 3
# 530 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_AYEWIRAZ
# 531 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_39:
# 533 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_ELECTRODES, 10, 3
# 534 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_ELECTRODES
# 535 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_40:
# 537 "data/maps/Lobby/scripts.pory"
	showmonpic SPECIES_EING, 10, 3
# 538 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, SPECIES_EING
# 539 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_ShowFakemonDexInfo
	goto Lobby_EventScript_FakemonDexMenu_ChooseSpecies_31


Lobby_EventScript_ShowFakemonDexInfo::
# 545 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesDexDescriptionForTextbox
# 546 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_0
# 547 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesTypeNames
# 548 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq Lobby_EventScript_ShowFakemonDexInfo_2
# 551 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_2
Lobby_EventScript_ShowFakemonDexInfo_1:
# 553 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_3
# 554 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 0
# 555 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 556 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_6
Lobby_EventScript_ShowFakemonDexInfo_5:
# 559 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 560 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 561 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_9
Lobby_EventScript_ShowFakemonDexInfo_8:
# 564 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 2
# 565 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesAbilityNameAndDescription
# 566 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_ShowFakemonDexInfo_12
Lobby_EventScript_ShowFakemonDexInfo_11:
# 569 "data/maps/Lobby/scripts.pory"
	special BufferSpeciesStats
# 570 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_5
# 571 "data/maps/Lobby/scripts.pory"
	hidemonpic
# 572 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8004
# 573 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_6
	return

Lobby_EventScript_ShowFakemonDexInfo_2:
# 549 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_1
	goto Lobby_EventScript_ShowFakemonDexInfo_1

Lobby_EventScript_ShowFakemonDexInfo_6:
# 557 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_5

Lobby_EventScript_ShowFakemonDexInfo_9:
# 562 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_8

Lobby_EventScript_ShowFakemonDexInfo_12:
# 567 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_ShowFakemonDexInfo_Text_4
	goto Lobby_EventScript_ShowFakemonDexInfo_11


Lobby_EventScript_Erkey_IntroFirstBattle::
# 580 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 581 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 582 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 583 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 584 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


Lobby_EventScript_Erkey_IntroRematch::
# 589 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 590 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 591 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ERKEY
# 592 "data/maps/Lobby/scripts.pory"
	closemessage
# 593 "data/maps/Lobby/scripts.pory"
	delay 20
# 594 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Erkey_IntroRematch_1
# 602 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 603 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 604 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 605 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Erkey_OnFinishEvent
	return

Lobby_EventScript_Erkey_IntroRematch_1:
# 595 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 596 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 597 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 598 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 599 "data/maps/Lobby/scripts.pory"
	delay 30
	return


Lobby_EventScript_Erkey_OnFinishEvent::
# 610 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 611 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Erkey::
# 616 "data/maps/Lobby/scripts.pory"
	lock
# 617 "data/maps/Lobby/scripts.pory"
	faceplayer
# 618 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Erkey_1
# 652 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 653 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 654 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 655 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 656 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 657 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 658 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Erkey_OnFinishEvent
	return

Lobby_EventScript_Erkey_1:
# 619 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ERKEY, Lobby_EventScript_Erkey_5
# 622 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Erkey_IntroFirstBattle
Lobby_EventScript_Erkey_4:
# 624 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 625 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 626 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 627 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 628 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 629 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 630 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, Lobby_EventScript_Erkey_Text_0
# 631 "data/maps/Lobby/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 632 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 633 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 634 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 635 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Erkey_9
# 646 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 647 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 648 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
Lobby_EventScript_Erkey_8:
# 650 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Erkey_OnFinishEvent
	return

Lobby_EventScript_Erkey_5:
# 620 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Erkey_IntroRematch
	goto Lobby_EventScript_Erkey_4

Lobby_EventScript_Erkey_9:
# 636 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 637 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 638 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 639 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 640 "data/maps/Lobby/scripts.pory"
	delay 20
# 641 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 642 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 643 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 644 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ERKEY
	goto Lobby_EventScript_Erkey_8


Lobby_EventScript_Micolo_IntroFirstBattle::
# 663 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 664 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 665 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 666 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Micolo_IntroFirstBattle_Movement_0
# 667 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 668 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 669 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 670 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


Lobby_EventScript_Micolo_IntroRematch::
# 675 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 676 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 677 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_MICOLO
# 678 "data/maps/Lobby/scripts.pory"
	closemessage
# 679 "data/maps/Lobby/scripts.pory"
	delay 20
# 680 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Micolo_IntroRematch_1
# 684 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 685 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Micolo_OnFinishEvent
	return

Lobby_EventScript_Micolo_IntroRematch_1:
# 681 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


Lobby_EventScript_Micolo_OnFinishEvent::
# 694 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 695 "data/maps/Lobby/scripts.pory"
	releaseall
	end


Lobby_EventScript_Micolo::
# 700 "data/maps/Lobby/scripts.pory"
	lock
# 701 "data/maps/Lobby/scripts.pory"
	faceplayer
# 702 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Micolo_1
# 753 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 755 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 756 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 757 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 758 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 759 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 760 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 761 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 762 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 763 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 764 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 765 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 766 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 767 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 768 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 769 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 770 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Micolo_Movement_0
# 771 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 772 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 773 "data/maps/Lobby/scripts.pory"
	delay 30
# 774 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Micolo_OnFinishEvent
	return

Lobby_EventScript_Micolo_1:
# 703 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_MICOLO, Lobby_EventScript_Micolo_5
# 706 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Micolo_IntroFirstBattle
Lobby_EventScript_Micolo_4:
# 708 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 709 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 710 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 711 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 712 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 713 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 714 "data/maps/Lobby/scripts.pory"
	waitstate
# 715 "data/maps/Lobby/scripts.pory"
	lockall
# 716 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Micolo_9
# 724 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 725 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 726 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 727 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 728 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 729 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 730 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, Lobby_EventScript_Micolo_Text_1
# 731 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 732 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 733 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 734 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 735 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Micolo_12
# 742 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 743 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 744 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 745 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 746 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 747 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Kaktus_Movement_0
# 748 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 749 "data/maps/Lobby/scripts.pory"
	waitmovement 0
Lobby_EventScript_Micolo_11:
# 751 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Micolo_OnFinishEvent
	return

Lobby_EventScript_Micolo_5:
# 704 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Micolo_IntroRematch
	goto Lobby_EventScript_Micolo_4

Lobby_EventScript_Micolo_9:
# 717 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 718 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 719 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 720 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 721 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Micolo_12:
# 736 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 737 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 738 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 739 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 740 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_MICOLO
	goto Lobby_EventScript_Micolo_11


Lobby_EventScript_Lillipup::
# 779 "data/maps/Lobby/scripts.pory"
	lock
# 780 "data/maps/Lobby/scripts.pory"
	faceplayer
# 781 "data/maps/Lobby/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 782 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 783 "data/maps/Lobby/scripts.pory"
	waitmoncry
# 784 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 785 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 786 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 787 "data/maps/Lobby/scripts.pory"
	release
	end


# 124 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 124 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 124 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 126 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 126 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 126 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 126 "data/maps/Lobby/scripts.pory"
	face_player
# 126 "data/maps/Lobby/scripts.pory"
	delay_16
# 126 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 333 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Kaktus_Movement_0:
# 333 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 333 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 333 "data/maps/Lobby/scripts.pory"
	face_player
	step_end

# 666 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 666 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 666 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 666 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 666 "data/maps/Lobby/scripts.pory"
	face_player
	step_end

# 770 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Micolo_Movement_0:
# 770 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 770 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 770 "data/maps/Lobby/scripts.pory"
	face_player
# 770 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

Lobby_EventScript_StartChallenge_Text_0:
# 15 "data/maps/Lobby/scripts.pory"
	.string "¡Hola {PLAYER}!$"

Lobby_EventScript_StartChallenge_Text_1:
# 19 "data/maps/Lobby/scripts.pory"
	.string "¿Así que ya estás list{OA} para intentar el\n"
	.string "desafío?$"

Lobby_EventScript_StartChallenge_Text_2:
# 25 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente! Adelante, ¡te deseo mucha\n"
	.string "suerte y sobre todo que te diviertas!$"

Lobby_EventScript_StartChallenge_Text_3:
# 35 "data/maps/Lobby/scripts.pory"
	.string "¿Así que no te sientes list{OA}?$"

Lobby_EventScript_StartChallenge_Text_4:
# 38 "data/maps/Lobby/scripts.pory"
	.string "Recuerda que las personas del Lobby\n"
	.string "pueden ayudar en tu preparación.$"

Lobby_EventScript_TeamSelector_Text_0:
# 50 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 55 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_Shop_Text_0:
# 76 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 79 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 119 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 121 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 127 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 131 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 134 "data/maps/Lobby/scripts.pory"
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
# 137 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate.$"

Lobby_EventScript_Roxas_IntroRematch_Text_0:
# 142 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_IntroRematch_Text_1:
# 146 "data/maps/Lobby/scripts.pory"
	.string "¡Vamos de nuevo! Elige a tu mejor bicho\n"
	.string "y prepárate.$"

Lobby_EventScript_Roxas_Text_0:
# 181 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 183 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 191 "data/maps/Lobby/scripts.pory"
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
# 197 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 199 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 203 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 210 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 214 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 222 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras loco!$"

Lobby_EventScript_Roxas_Text_9:
# 226 "data/maps/Lobby/scripts.pory"
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
# 228 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_Kaktus_IntroFirstBattle_Text_0:
# 258 "data/maps/Lobby/scripts.pory"
	.string "Vaya, vaya…\n¿Así que completaste el desafío?$"

Lobby_EventScript_Kaktus_IntroFirstBattle_Text_1:
# 261 "data/maps/Lobby/scripts.pory"
	.string "Entonces ya no eres un{A} novat{OA}. Veamos si\n"
	.string "sabes aplicar lo aprendido.\p"
	.string "Un combate, sin atajos, sin trucos.\n"
	.string "¿List{OA}?$"

Lobby_EventScript_Kaktus_IntroRematch_Text_0:
# 277 "data/maps/Lobby/scripts.pory"
	.string "Ey, ¿qué tal? Mi Ludicolo sigue con\n"
	.string "ganas de bailar.\p"
	.string "¿Otro asalto?$"

Lobby_EventScript_Kaktus_IntroRematch_Text_1:
# 281 "data/maps/Lobby/scripts.pory"
	.string "¡Vamos!$"

Lobby_EventScript_Kaktus_IntroRematch_Text_2:
# 284 "data/maps/Lobby/scripts.pory"
	.string "¡Será en otra oportunidad entonces!$"

Lobby_EventScript_Kaktus_Text_0:
# 311 "data/maps/Lobby/scripts.pory"
	.string "¿Acaso perdí?$"

Lobby_EventScript_Kaktus_Text_1:
# 318 "data/maps/Lobby/scripts.pory"
	.string "Ja… perdí.$"

Lobby_EventScript_Kaktus_Text_2:
# 322 "data/maps/Lobby/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

Lobby_EventScript_Kaktus_Text_3:
# 326 "data/maps/Lobby/scripts.pory"
	.string "Enhorabuena, crack.$"

Lobby_EventScript_Kaktus_Text_4:
# 329 "data/maps/Lobby/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

Lobby_EventScript_Kaktus_Text_5:
# 334 "data/maps/Lobby/scripts.pory"
	.string "¡Espero la revancha pronto!$"

Lobby_EventScript_Kaktus_Text_6:
# 340 "data/maps/Lobby/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

Lobby_EventScript_Kaktus_Text_7:
# 343 "data/maps/Lobby/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 355 "data/maps/Lobby/scripts.pory"
	.string "No soy competitivo ni ambicioso. Soy\n"
	.string "más bien una persona mediocre.$"

Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 359 "data/maps/Lobby/scripts.pory"
	.string "Eso puede jugarme en contra.$"

Lobby_EventScript_Gameboycl_IntroRematch_Text_0:
# 364 "data/maps/Lobby/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.\p"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

Lobby_EventScript_Gameboycl_IntroRematch_Text_1:
# 371 "data/maps/Lobby/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

Lobby_EventScript_Gameboycl_Text_0:
# 411 "data/maps/Lobby/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

Lobby_EventScript_Gameboycl_Text_1:
# 416 "data/maps/Lobby/scripts.pory"
	.string "PENDIENTE GAMEBOY$"

Lobby_EventScript_Gameboycl_Text_2:
# 421 "data/maps/Lobby/scripts.pory"
	.string "Un hack rom es como la arquitectura, se\n"
	.string "construye sobre lo existente.$"

Lobby_EventScript_Gameboycl_Text_3:
# 423 "data/maps/Lobby/scripts.pory"
	.string "El arte aquí no es lo que se cambia, sino\n"
	.string "lo que se quiere transmitir.$"

Lobby_EventScript_FakemonDexMenu_Text_0:
# 438 "data/maps/Lobby/scripts.pory"
	.string "Soy el experto en las especies\n"
	.string "exclusivas de Whack a Hack.\p"
	.string "Te revelaré todo sobre ellas, pero solo\n"
	.string "de las que hayas visto.\p"
	.string "¡No quiero arruinar el factor sorpresa!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_0:
# 495 "data/maps/Lobby/scripts.pory"
	.string "¡Todas las especies que has visto son\n"
	.string "de público conocimiento!\p"
	.string "¡Ve a combatir a las salas y ya verás de\n"
	.string "las que estoy hablando!$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_1:
# 499 "data/maps/Lobby/scripts.pory"
	.string "Salir$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_2:
# 500 "data/maps/Lobby/scripts.pory"
	.string "¿De cuál especie te gustaría conocer\n"
	.string "más?$"

Lobby_EventScript_FakemonDexMenu_ChooseSpecies_Text_3:
# 503 "data/maps/Lobby/scripts.pory"
	.string "¡Si quieres saber algo más, aquí estaré!$"

Lobby_EventScript_ShowFakemonDexInfo_Text_0:
# 546 "data/maps/Lobby/scripts.pory"
	.string "Ya que no tienes una Pokedex, su\n"
	.string "descripción es:{FONT_SMALL}\p"
	.string "“{STR_VAR_1}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_1:
# 549 "data/maps/Lobby/scripts.pory"
	.string "Su tipo es: {STR_VAR_2}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_2:
# 551 "data/maps/Lobby/scripts.pory"
	.string "Sus tipos son: {STR_VAR_2} y {STR_VAR_3}.$"

Lobby_EventScript_ShowFakemonDexInfo_Text_3:
# 553 "data/maps/Lobby/scripts.pory"
	.string "¡Y esto seguramente no lo sabías!\nSus habilidades son:$"

Lobby_EventScript_ShowFakemonDexInfo_Text_4:
# 557 "data/maps/Lobby/scripts.pory"
	.string "{STR_VAR_1}:\n"
	.string "{FONT_SMALL}“{STR_VAR_2}”$"

Lobby_EventScript_ShowFakemonDexInfo_Text_5:
# 570 "data/maps/Lobby/scripts.pory"
	.string "¡Último dato! ¿Qué tan buenos son sus\n"
	.string "stats base?\p"
	.string "{FONT_SMALL}{STR_VAR_1}$"

Lobby_EventScript_ShowFakemonDexInfo_Text_6:
# 573 "data/maps/Lobby/scripts.pory"
	.string "Y eso es todo sobre {STR_VAR_1}.\nEspero que te haya resultado útil.$"

Lobby_EventScript_Erkey_IntroFirstBattle_Text_0:
# 582 "data/maps/Lobby/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

Lobby_EventScript_Erkey_IntroRematch_Text_0:
# 591 "data/maps/Lobby/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

Lobby_EventScript_Erkey_IntroRematch_Text_1:
# 597 "data/maps/Lobby/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

Lobby_EventScript_Erkey_IntroRematch_Text_2:
# 602 "data/maps/Lobby/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

Lobby_EventScript_Erkey_Text_0:
# 630 "data/maps/Lobby/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

Lobby_EventScript_Erkey_Text_1:
# 638 "data/maps/Lobby/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

Lobby_EventScript_Erkey_Text_2:
# 641 "data/maps/Lobby/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

Lobby_EventScript_Erkey_Text_3:
# 646 "data/maps/Lobby/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

Lobby_EventScript_Erkey_Text_4:
# 652 "data/maps/Lobby/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

Lobby_EventScript_Erkey_Text_5:
# 655 "data/maps/Lobby/scripts.pory"
	.string "Si prestas atención.$"

Lobby_EventScript_Micolo_IntroFirstBattle_Text_0:
# 668 "data/maps/Lobby/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres bueno con los\n"
	.string "Pokémon que he criado y entrenado.$"

Lobby_EventScript_Micolo_IntroRematch_Text_0:
# 677 "data/maps/Lobby/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar. ¿Te\l"
	.string "atreves?$"

Lobby_EventScript_Micolo_IntroRematch_Text_1:
# 684 "data/maps/Lobby/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

Lobby_EventScript_Micolo_Text_0:
# 720 "data/maps/Lobby/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

Lobby_EventScript_Micolo_Text_1:
# 730 "data/maps/Lobby/scripts.pory"
	.string "Vaya, me has ganado.$"

Lobby_EventScript_Micolo_Text_2:
# 738 "data/maps/Lobby/scripts.pory"
	.string "Admito que eres bueno, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

Lobby_EventScript_Micolo_Text_3:
# 748 "data/maps/Lobby/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

Lobby_EventScript_Micolo_Text_4:
# 755 "data/maps/Lobby/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

Lobby_EventScript_Micolo_Text_5:
# 758 "data/maps/Lobby/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

Lobby_EventScript_Micolo_Text_6:
# 761 "data/maps/Lobby/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

Lobby_EventScript_Micolo_Text_7:
# 764 "data/maps/Lobby/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

Lobby_EventScript_Micolo_Text_8:
# 772 "data/maps/Lobby/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

Lobby_EventScript_Lillipup_Text_0:
# 782 "data/maps/Lobby/scripts.pory"
	.string "Pup, pup, pup.$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 68 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_Roxas_PlayerCancelled::
# 234 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_Text_Gameboycl_OnDefeat::
# 431 "data/maps/Lobby/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

Lobby_Text_Micolo_ChoosePokemon::
# 689 "data/maps/Lobby/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"
