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
	applymovementandwait LOCALID_LOBBY_POLICE, Common_Movement_FacePlayer
# 13 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_YESNO
# 14 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_2
# 18 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 19 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_POLICE, DIR_SOUTH
Lobby_EventScript_StartChallenge_1:
# 21 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_StartChallenge_2:
# 15 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 16 "data/maps/Lobby/scripts.pory"
	waitstate
	goto Lobby_EventScript_StartChallenge_1


Lobby_EventScript_TeamSelector::
# 27 "data/maps/Lobby/scripts.pory"
	lock
# 28 "data/maps/Lobby/scripts.pory"
	faceplayer
# 29 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 30 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 39 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 41 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 42 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 31 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 32 "data/maps/Lobby/scripts.pory"
	waitstate
# 33 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 36 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 34 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_Shop::
# 53 "data/maps/Lobby/scripts.pory"
	lock
# 54 "data/maps/Lobby/scripts.pory"
	faceplayer
# 55 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 56 "data/maps/Lobby/scripts.pory"
	waitmessage
# 57 "data/maps/Lobby/scripts.pory"
	pokemart Lobby_MartItems
# 58 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 59 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 63 "data/maps/Lobby/scripts.pory"
Lobby_MartItems:
# 64 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 65 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 66 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 67 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 68 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 69 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 70 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 71 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 72 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 73 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 74 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 75 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 76 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 77 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 78 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 79 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 80 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 81 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 82 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 83 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 84 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 85 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 86 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 87 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 88 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 89 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 90 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 91 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 92 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_Roxas_IntroFirstBattle::
# 96 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 97 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_IntroFirstBattle_2
# 100 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_IntroFirstBattle_1:
# 102 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 103 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 104 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 105 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 106 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 107 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 108 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 109 "data/maps/Lobby/scripts.pory"
	delay 20
# 110 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 111 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 112 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 113 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 114 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 115 "data/maps/Lobby/scripts.pory"
	delay 20
# 116 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	return

Lobby_EventScript_Roxas_IntroFirstBattle_2:
# 98 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_IntroFirstBattle_1


Lobby_EventScript_Roxas_IntroRematch::
# 121 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ROXAS
# 122 "data/maps/Lobby/scripts.pory"
	closemessage
# 123 "data/maps/Lobby/scripts.pory"
	delay 20
# 124 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Roxas_IntroRematch_1
# 128 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 129 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_IntroRematch_1:
# 125 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_IntroRematch_Text_1, speaker = SP_NAME_ROXAS
	return


Lobby_EventScript_Roxas::
# 135 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Roxas_1
# 187 "data/maps/Lobby/scripts.pory"
	lockall
# 188 "data/maps/Lobby/scripts.pory"
	faceplayer
# 189 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 190 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 191 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 192 "data/maps/Lobby/scripts.pory"
	delay 20
# 193 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 194 "data/maps/Lobby/scripts.pory"
	delay 20
# 195 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 196 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Angry
# 197 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 198 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 199 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 200 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1
# 201 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 202 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 203 "data/maps/Lobby/scripts.pory"
	lockall
# 204 "data/maps/Lobby/scripts.pory"
	delay 20
# 205 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 206 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 207 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 208 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_1:
# 136 "data/maps/Lobby/scripts.pory"
	lockall
# 137 "data/maps/Lobby/scripts.pory"
	faceplayer
# 138 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 139 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
# 140 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ROXAS, Lobby_EventScript_Roxas_5
# 143 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroFirstBattle
Lobby_EventScript_Roxas_4:
# 145 "data/maps/Lobby/scripts.pory"
	special SavePlayerParty
# 146 "data/maps/Lobby/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 147 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8005, 1
# 148 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 149 "data/maps/Lobby/scripts.pory"
	fadescreen FADE_TO_BLACK
# 150 "data/maps/Lobby/scripts.pory"
	special ChoosePartyForBattleFrontier
# 151 "data/maps/Lobby/scripts.pory"
	waitstate
# 152 "data/maps/Lobby/scripts.pory"
	lockall
# 153 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq Lobby_EventScript_Roxas_9
# 159 "data/maps/Lobby/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 160 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 161 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 162 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ROXAS, Lobby_EventScript_Roxas_Text_1
# 163 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 164 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 165 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 166 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 167 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Roxas_12
# 174 "data/maps/Lobby/scripts.pory"
	checkplayergender
# 175 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq Lobby_EventScript_Roxas_16
# 178 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_15:
# 180 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 181 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 182 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
Lobby_EventScript_Roxas_11:
# 184 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_5:
# 141 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Roxas_IntroRematch
	goto Lobby_EventScript_Roxas_4

Lobby_EventScript_Roxas_9:
# 154 "data/maps/Lobby/scripts.pory"
	special LoadPlayerParty
# 155 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Roxas_PlayerCancelled, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
# 156 "data/maps/Lobby/scripts.pory"
	releaseall
	end

Lobby_EventScript_Roxas_12:
# 168 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 169 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_X
# 170 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_2, MSGBOX_DEFAULT
# 171 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 172 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ROXAS
	goto Lobby_EventScript_Roxas_11

Lobby_EventScript_Roxas_16:
# 176 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Roxas_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ROXAS
	goto Lobby_EventScript_Roxas_15


Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 218 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 219 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 220 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 223 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 226 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 229 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 221 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 224 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 227 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 230 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


Lobby_EventScript_Kaktus_IntroFirstBattle::
# 237 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 238 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 239 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 240 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 241 "data/maps/Lobby/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 242 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 243 "data/maps/Lobby/scripts.pory"
	case DIR_NORTH, Lobby_EventScript_Kaktus_IntroFirstBattle_3
# 245 "data/maps/Lobby/scripts.pory"
	case DIR_SOUTH, Lobby_EventScript_Kaktus_IntroFirstBattle_4
# 247 "data/maps/Lobby/scripts.pory"
	case DIR_WEST, Lobby_EventScript_Kaktus_IntroFirstBattle_5
# 249 "data/maps/Lobby/scripts.pory"
	case DIR_EAST, Lobby_EventScript_Kaktus_IntroFirstBattle_6
Lobby_EventScript_Kaktus_IntroFirstBattle_1:
	return

Lobby_EventScript_Kaktus_IntroFirstBattle_3:
# 244 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1

Lobby_EventScript_Kaktus_IntroFirstBattle_4:
# 246 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1

Lobby_EventScript_Kaktus_IntroFirstBattle_5:
# 248 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1

Lobby_EventScript_Kaktus_IntroFirstBattle_6:
# 250 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto Lobby_EventScript_Kaktus_IntroFirstBattle_1


Lobby_EventScript_Kaktus_IntroRematch::
# 256 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_INMORTAL_KAKTUS
# 257 "data/maps/Lobby/scripts.pory"
	closemessage
# 258 "data/maps/Lobby/scripts.pory"
	delay 20
# 259 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Kaktus_IntroRematch_1
# 263 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 264 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Kaktus_OnFinishEvent
	return

Lobby_EventScript_Kaktus_IntroRematch_1:
# 260 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_IntroRematch_Text_1, speaker = SP_NAME_INMORTAL_KAKTUS
	return


Lobby_EventScript_Kaktus_OnFinishEvent::
# 270 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 271 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Kaktus::
# 276 "data/maps/Lobby/scripts.pory"
	lock
# 277 "data/maps/Lobby/scripts.pory"
	faceplayer
# 278 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Kaktus_1
# 319 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 320 "data/maps/Lobby/scripts.pory"
	delay 20
# 321 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 322 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 323 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 324 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 325 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Kaktus_OnFinishEvent
	return

Lobby_EventScript_Kaktus_1:
# 279 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_KAKTUS, Lobby_EventScript_Kaktus_5
# 282 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Kaktus_IntroFirstBattle
Lobby_EventScript_Kaktus_4:
# 285 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 286 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 287 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 288 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 289 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 290 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, Lobby_EventScript_Kaktus_Text_0
# 291 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 292 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 293 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 294 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Kaktus_9
# 308 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 309 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 310 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0
# 311 "data/maps/Lobby/scripts.pory"
	playse SE_LEDGE
# 312 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Lobby_EventScript_Kaktus_Movement_0
# 313 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 314 "data/maps/Lobby/scripts.pory"
	waitmovement 0
Lobby_EventScript_Kaktus_8:
# 316 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Kaktus_OnFinishEvent
	return

Lobby_EventScript_Kaktus_5:
# 280 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Kaktus_IntroRematch
	goto Lobby_EventScript_Kaktus_4

Lobby_EventScript_Kaktus_9:
# 295 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 296 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 297 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 298 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 299 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 300 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 301 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 302 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 303 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 304 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 305 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 306 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_KAKTUS
	goto Lobby_EventScript_Kaktus_8


Lobby_EventScript_Gameboycl_IntroFirstBattle::
# 331 "data/maps/Lobby/scripts.pory"
	delay 20
# 332 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 333 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 334 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 335 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 336 "data/maps/Lobby/scripts.pory"
	delay 20
# 337 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 338 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


Lobby_EventScript_Gameboycl_IntroRematch::
# 343 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_GAMEBOY_CL
# 344 "data/maps/Lobby/scripts.pory"
	closemessage
# 345 "data/maps/Lobby/scripts.pory"
	delay 20
# 346 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Gameboycl_IntroRematch_1
# 350 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 351 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Gameboycl_OnFinishEvent
	return

Lobby_EventScript_Gameboycl_IntroRematch_1:
# 347 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


Lobby_EventScript_Gameboycl_OnFinishEvent::
# 356 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 357 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Gameboycl::
# 363 "data/maps/Lobby/scripts.pory"
	lock
# 364 "data/maps/Lobby/scripts.pory"
	faceplayer
# 365 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Gameboycl_1
# 400 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 401 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 402 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 403 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 404 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 405 "data/maps/Lobby/scripts.pory"
	delay 20
# 406 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Gameboycl_OnFinishEvent
	return

Lobby_EventScript_Gameboycl_1:
# 366 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_GAMEBOYCL, Lobby_EventScript_Gameboycl_5
# 369 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Gameboycl_IntroFirstBattle
Lobby_EventScript_Gameboycl_4:
# 371 "data/maps/Lobby/scripts.pory"
	delay 20
# 372 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 373 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 374 "data/maps/Lobby/scripts.pory"
	random 3
# 375 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 376 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 377 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_Gameboycl_10
# 379 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_Gameboycl_11
# 381 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_Gameboycl_12
Lobby_EventScript_Gameboycl_8:
# 384 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 385 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 386 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 387 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Gameboycl_14
# 395 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
Lobby_EventScript_Gameboycl_13:
# 397 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Gameboycl_OnFinishEvent
	return

Lobby_EventScript_Gameboycl_5:
# 367 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Gameboycl_IntroRematch
	goto Lobby_EventScript_Gameboycl_4

Lobby_EventScript_Gameboycl_10:
# 378 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, Lobby_Text_Gameboycl_OnDefeat
	goto Lobby_EventScript_Gameboycl_8

Lobby_EventScript_Gameboycl_11:
# 380 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, Lobby_Text_Gameboycl_OnDefeat
	goto Lobby_EventScript_Gameboycl_8

Lobby_EventScript_Gameboycl_12:
# 382 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, Lobby_Text_Gameboycl_OnDefeat
	goto Lobby_EventScript_Gameboycl_8

Lobby_EventScript_Gameboycl_14:
# 388 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 389 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 390 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 391 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 392 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 393 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_GAMEBOYCL
	goto Lobby_EventScript_Gameboycl_13


Lobby_EventScript_FakemonDexMenu::
# 415 "data/maps/Lobby/scripts.pory"
	lock
# 416 "data/maps/Lobby/scripts.pory"
	faceplayer
# 417 "data/maps/Lobby/scripts.pory"
	setvar VAR_0x8000, 0
# 418 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_KAOSUNE
# 419 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_2
Lobby_EventScript_FakemonDexMenu_1:
# 424 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_FREECH
# 425 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_5
Lobby_EventScript_FakemonDexMenu_4:
# 430 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_PLUGOINK
# 431 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_8
Lobby_EventScript_FakemonDexMenu_7:
# 436 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_GRITESPEC
# 437 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_11
Lobby_EventScript_FakemonDexMenu_10:
# 442 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_MAGIKEN
# 443 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_14
Lobby_EventScript_FakemonDexMenu_13:
# 448 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_AYEWIRAZ
# 449 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_17
Lobby_EventScript_FakemonDexMenu_16:
# 454 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_ELECTRODES
# 455 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_20
Lobby_EventScript_FakemonDexMenu_19:
# 460 "data/maps/Lobby/scripts.pory"
	getseenmon SPECIES_EING
# 461 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Lobby_EventScript_FakemonDexMenu_23
Lobby_EventScript_FakemonDexMenu_22:
# 466 "data/maps/Lobby/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq Lobby_EventScript_FakemonDexMenu_26
# 471 "data/maps/Lobby/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, 0, 0, DYN_MULTICHOICE_CB_NONE
# 472 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_gt Lobby_EventScript_FakemonDexMenu_29
# 476 "data/maps/Lobby/scripts.pory"
	switch VAR_RESULT
# 477 "data/maps/Lobby/scripts.pory"
	case 0, Lobby_EventScript_FakemonDexMenu_33
# 479 "data/maps/Lobby/scripts.pory"
	case 1, Lobby_EventScript_FakemonDexMenu_34
# 481 "data/maps/Lobby/scripts.pory"
	case 2, Lobby_EventScript_FakemonDexMenu_35
# 483 "data/maps/Lobby/scripts.pory"
	case 3, Lobby_EventScript_FakemonDexMenu_36
# 485 "data/maps/Lobby/scripts.pory"
	case 4, Lobby_EventScript_FakemonDexMenu_37
# 487 "data/maps/Lobby/scripts.pory"
	case 5, Lobby_EventScript_FakemonDexMenu_38
# 489 "data/maps/Lobby/scripts.pory"
	case 6, Lobby_EventScript_FakemonDexMenu_39
# 491 "data/maps/Lobby/scripts.pory"
	case 7, Lobby_EventScript_FakemonDexMenu_40
Lobby_EventScript_FakemonDexMenu_31:
# 494 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_2:
# 420 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KAOSUNE
# 421 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 0
# 422 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_1

Lobby_EventScript_FakemonDexMenu_5:
# 426 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_FREECH
# 427 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 1
# 428 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_4

Lobby_EventScript_FakemonDexMenu_8:
# 432 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PLUGOINK
# 433 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 2
# 434 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_7

Lobby_EventScript_FakemonDexMenu_11:
# 438 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_GRITESPEC
# 439 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 3
# 440 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_10

Lobby_EventScript_FakemonDexMenu_14:
# 444 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKEN
# 445 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 4
# 446 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_13

Lobby_EventScript_FakemonDexMenu_17:
# 450 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AYEWIRAZ
# 451 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 5
# 452 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_16

Lobby_EventScript_FakemonDexMenu_20:
# 456 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ELECTRODES
# 457 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 6
# 458 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_19

Lobby_EventScript_FakemonDexMenu_23:
# 462 "data/maps/Lobby/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_EING
# 463 "data/maps/Lobby/scripts.pory"
	dynmultipush gStringVar1, 7
# 464 "data/maps/Lobby/scripts.pory"
	addvar VAR_0x8000, 1
	goto Lobby_EventScript_FakemonDexMenu_22

Lobby_EventScript_FakemonDexMenu_26:
# 467 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_FakemonDex_NoneSeen
# 468 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_29:
# 473 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_FakemonDexMenu_33:
# 478 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Kaosune
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_34:
# 480 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Freech
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_35:
# 482 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Plugoink
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_36:
# 484 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Gritespec
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_37:
# 486 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Magiken
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_38:
# 488 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Ayewiraz
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_39:
# 490 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Electrodes
	goto Lobby_EventScript_FakemonDexMenu_31

Lobby_EventScript_FakemonDexMenu_40:
# 492 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_Fakemon_Eing
	goto Lobby_EventScript_FakemonDexMenu_31


Lobby_EventScript_Erkey_IntroFirstBattle::
# 535 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 536 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 537 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 538 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 539 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


Lobby_EventScript_Erkey_IntroRematch::
# 544 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 545 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 546 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ERKEY
# 547 "data/maps/Lobby/scripts.pory"
	closemessage
# 548 "data/maps/Lobby/scripts.pory"
	delay 20
# 549 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_Erkey_IntroRematch_1
# 557 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 558 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 559 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 560 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Erkey_OnFinishEvent
	return

Lobby_EventScript_Erkey_IntroRematch_1:
# 550 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 551 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 552 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 553 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 554 "data/maps/Lobby/scripts.pory"
	delay 30
	return


Lobby_EventScript_Erkey_OnFinishEvent::
# 565 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 566 "data/maps/Lobby/scripts.pory"
	release
	end


Lobby_EventScript_Erkey::
# 571 "data/maps/Lobby/scripts.pory"
	lock
# 572 "data/maps/Lobby/scripts.pory"
	faceplayer
# 573 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, Lobby_EventScript_Erkey_1
# 607 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 608 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 609 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 610 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 611 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 612 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 613 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Erkey_OnFinishEvent
	return

Lobby_EventScript_Erkey_1:
# 574 "data/maps/Lobby/scripts.pory"
	goto_if_set FLAG_DEFEATED_LOBBY_ERKEY, Lobby_EventScript_Erkey_5
# 577 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Erkey_IntroFirstBattle
Lobby_EventScript_Erkey_4:
# 579 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 580 "data/maps/Lobby/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 581 "data/maps/Lobby/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 582 "data/maps/Lobby/scripts.pory"
	waitmovement 0
# 583 "data/maps/Lobby/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 584 "data/maps/Lobby/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 585 "data/maps/Lobby/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, Lobby_EventScript_Erkey_Text_0
# 586 "data/maps/Lobby/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 587 "data/maps/Lobby/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 588 "data/maps/Lobby/scripts.pory"
	special GetBattleOutcome
# 589 "data/maps/Lobby/scripts.pory"
	special HealPlayerParty
# 590 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Lobby_EventScript_Erkey_9
# 601 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 602 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 603 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
Lobby_EventScript_Erkey_8:
# 605 "data/maps/Lobby/scripts.pory"
	goto Lobby_EventScript_Erkey_OnFinishEvent
	return

Lobby_EventScript_Erkey_5:
# 575 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_Erkey_IntroRematch
	goto Lobby_EventScript_Erkey_4

Lobby_EventScript_Erkey_9:
# 591 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 592 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 593 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 594 "data/maps/Lobby/scripts.pory"
	call Lobby_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 595 "data/maps/Lobby/scripts.pory"
	delay 20
# 596 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 597 "data/maps/Lobby/scripts.pory"
	playse SE_PIN
# 598 "data/maps/Lobby/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 599 "data/maps/Lobby/scripts.pory"
	setflag FLAG_DEFEATED_LOBBY_ERKEY
	goto Lobby_EventScript_Erkey_8


# 103 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_0:
# 103 "data/maps/Lobby/scripts.pory"
	lock_facing_direction
# 103 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
	step_end

# 105 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Roxas_IntroFirstBattle_Movement_1:
# 105 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 105 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 105 "data/maps/Lobby/scripts.pory"
	face_player
# 105 "data/maps/Lobby/scripts.pory"
	delay_16
# 105 "data/maps/Lobby/scripts.pory"
	delay_16
	step_end

# 312 "data/maps/Lobby/scripts.pory"
Lobby_EventScript_Kaktus_Movement_0:
# 312 "data/maps/Lobby/scripts.pory"
	jump_in_place_down
# 312 "data/maps/Lobby/scripts.pory"
	unlock_facing_direction
# 312 "data/maps/Lobby/scripts.pory"
	face_player
	step_end

Lobby_EventScript_StartChallenge_Text_0:
# 13 "data/maps/Lobby/scripts.pory"
	.string "Pendiente textos, ¿empezar desafío?$"

Lobby_EventScript_TeamSelector_Text_0:
# 29 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 34 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_Shop_Text_0:
# 55 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 58 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_0:
# 98 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡El nuevo campeón!\n"
	.string "¡Felicidades loco!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_1:
# 100 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, mira vos! ¡La nueva campeona!\n"
	.string "¡Felicidades loca!$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_2:
# 106 "data/maps/Lobby/scripts.pory"
	.string "Veo que se la diste a esos traidores de\n"
	.string "las salas… Me alegra que alguien les\l"
	.string "bajara los humos.$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_3:
# 110 "data/maps/Lobby/scripts.pory"
	.string "¿Te acordas de lo que te conté la ultima\n"
	.string "vez?$"

Lobby_EventScript_Roxas_IntroFirstBattle_Text_4:
# 113 "data/maps/Lobby/scripts.pory"
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
# 116 "data/maps/Lobby/scripts.pory"
	.string "Vamos a hacerlo más interesante: un\n"
	.string "mano a mano.\p"
	.string "Elige a tu mejor bicho y prepárate.$"

Lobby_EventScript_Roxas_IntroRematch_Text_0:
# 121 "data/maps/Lobby/scripts.pory"
	.string "¡Apa, tu de nuevo! ¿Quieres volver a\n"
	.string "combatir contra mi legendario?$"

Lobby_EventScript_Roxas_IntroRematch_Text_1:
# 125 "data/maps/Lobby/scripts.pory"
	.string "¡Vamos de nuevo! Elige a tu mejor bicho\n"
	.string "y prepárate.$"

Lobby_EventScript_Roxas_Text_0:
# 160 "data/maps/Lobby/scripts.pory"
	.string "¡A ver si te la bancas!$"

Lobby_EventScript_Roxas_Text_1:
# 162 "data/maps/Lobby/scripts.pory"
	.string "¡Nooooo!$"

Lobby_EventScript_Roxas_Text_2:
# 170 "data/maps/Lobby/scripts.pory"
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
# 176 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos el campeón te la bancaste.$"

Lobby_EventScript_Roxas_Text_4:
# 178 "data/maps/Lobby/scripts.pory"
	.string "Mamita lo que me imaginaba… El poder de\n"
	.string "este bicho es de otro planeta, ni vos\l"
	.string "que sos la campeona te la bancaste.$"

Lobby_EventScript_Roxas_Text_5:
# 182 "data/maps/Lobby/scripts.pory"
	.string "Si algún día te das una vuelta por el\n"
	.string "Archipiélago Suzuka, anda con cuidado\l"
	.string "maquina, porque allá este no te perdona\l"
	.string "ni media.\p"
	.string "Suerte la próxima.$"

Lobby_EventScript_Roxas_Text_6:
# 189 "data/maps/Lobby/scripts.pory"
	.string "No te molestes en preguntar… A mí\n"
	.string "tampoco me dejan pasar estos…$"

Lobby_EventScript_Roxas_Text_7:
# 193 "data/maps/Lobby/scripts.pory"
	.string "Dicen que haber sido Líder de WAH en el\n"
	.string "Archipiélago Suzuka durante solo dos\l"
	.string "semanas no es “trayectoria suficiente”\l"
	.string "para participar.$"

Lobby_EventScript_Roxas_Text_8:
# 201 "data/maps/Lobby/scripts.pory"
	.string "¡Unos caraduras loco!$"

Lobby_EventScript_Roxas_Text_9:
# 205 "data/maps/Lobby/scripts.pory"
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
# 207 "data/maps/Lobby/scripts.pory"
	.string "Che, discúlpame, mejor me voy a seguir\n"
	.string "con mis investigaciones.\p"
	.string "¡Suerte, espero que a vos sí te den\n"
	.string "bola!$"

Lobby_EventScript_Kaktus_IntroFirstBattle_Text_0:
# 237 "data/maps/Lobby/scripts.pory"
	.string "Vaya, vaya…\n¿Así que completaste el desafío?$"

Lobby_EventScript_Kaktus_IntroFirstBattle_Text_1:
# 240 "data/maps/Lobby/scripts.pory"
	.string "Entonces ya no eres un{A} novat{OA}. Veamos si\n"
	.string "sabes aplicar lo aprendido.\p"
	.string "Un combate, sin atajos, sin trucos.\n"
	.string "¿List{OA}?$"

Lobby_EventScript_Kaktus_IntroRematch_Text_0:
# 256 "data/maps/Lobby/scripts.pory"
	.string "Ey, ¿qué tal? Mi Ludicolo sigue con\n"
	.string "ganas de bailar.\p"
	.string "¿Otro asalto?$"

Lobby_EventScript_Kaktus_IntroRematch_Text_1:
# 260 "data/maps/Lobby/scripts.pory"
	.string "¡Vamos!$"

Lobby_EventScript_Kaktus_IntroRematch_Text_2:
# 263 "data/maps/Lobby/scripts.pory"
	.string "¡Será en otra oportunidad entonces!$"

Lobby_EventScript_Kaktus_Text_0:
# 290 "data/maps/Lobby/scripts.pory"
	.string "¿Acaso perdí?$"

Lobby_EventScript_Kaktus_Text_1:
# 297 "data/maps/Lobby/scripts.pory"
	.string "Ja… perdí.$"

Lobby_EventScript_Kaktus_Text_2:
# 301 "data/maps/Lobby/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

Lobby_EventScript_Kaktus_Text_3:
# 305 "data/maps/Lobby/scripts.pory"
	.string "Enhorabuena, crack.$"

Lobby_EventScript_Kaktus_Text_4:
# 308 "data/maps/Lobby/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

Lobby_EventScript_Kaktus_Text_5:
# 313 "data/maps/Lobby/scripts.pory"
	.string "¡Espero la revancha pronto!$"

Lobby_EventScript_Kaktus_Text_6:
# 319 "data/maps/Lobby/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

Lobby_EventScript_Kaktus_Text_7:
# 322 "data/maps/Lobby/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 334 "data/maps/Lobby/scripts.pory"
	.string "No soy competitivo ni ambicioso. Soy\n"
	.string "más bien una persona mediocre.$"

Lobby_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 338 "data/maps/Lobby/scripts.pory"
	.string "Eso puede jugarme en contra.$"

Lobby_EventScript_Gameboycl_IntroRematch_Text_0:
# 343 "data/maps/Lobby/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.\p"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

Lobby_EventScript_Gameboycl_IntroRematch_Text_1:
# 350 "data/maps/Lobby/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

Lobby_EventScript_Gameboycl_Text_0:
# 390 "data/maps/Lobby/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

Lobby_EventScript_Gameboycl_Text_1:
# 395 "data/maps/Lobby/scripts.pory"
	.string "PENDIENTE GAMEBOY$"

Lobby_EventScript_Gameboycl_Text_2:
# 400 "data/maps/Lobby/scripts.pory"
	.string "Un hack rom es como la arquitectura, se\n"
	.string "construye sobre lo existente.$"

Lobby_EventScript_Gameboycl_Text_3:
# 402 "data/maps/Lobby/scripts.pory"
	.string "El arte aquí no es lo que se cambia, sino\n"
	.string "lo que se quiere transmitir.$"

Lobby_EventScript_Erkey_IntroFirstBattle_Text_0:
# 537 "data/maps/Lobby/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

Lobby_EventScript_Erkey_IntroRematch_Text_0:
# 546 "data/maps/Lobby/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

Lobby_EventScript_Erkey_IntroRematch_Text_1:
# 552 "data/maps/Lobby/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

Lobby_EventScript_Erkey_IntroRematch_Text_2:
# 557 "data/maps/Lobby/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

Lobby_EventScript_Erkey_Text_0:
# 585 "data/maps/Lobby/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

Lobby_EventScript_Erkey_Text_1:
# 593 "data/maps/Lobby/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

Lobby_EventScript_Erkey_Text_2:
# 596 "data/maps/Lobby/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

Lobby_EventScript_Erkey_Text_3:
# 601 "data/maps/Lobby/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

Lobby_EventScript_Erkey_Text_4:
# 607 "data/maps/Lobby/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

Lobby_EventScript_Erkey_Text_5:
# 610 "data/maps/Lobby/scripts.pory"
	.string "Si prestas atención.$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 47 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"

Lobby_Text_Roxas_PlayerCancelled::
# 213 "data/maps/Lobby/scripts.pory"
	.string "¿Así que le tenés miedo a mi bicho\n"
	.string "legendario? ¡Y aún así ganaste las\l"
	.string "salas!$"

Lobby_Text_Gameboycl_OnDefeat::
# 410 "data/maps/Lobby/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

Lobby_Text_FakemonDex_NoneSeen::
# 498 "data/maps/Lobby/scripts.pory"
	.string "Aún no has visto ningún fakemon en tu Pokédex.$"

Lobby_Text_Fakemon_Kaosune::
# 502 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Kaosune (placeholder).$"

Lobby_Text_Fakemon_Freech::
# 506 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Freech (placeholder).$"

Lobby_Text_Fakemon_Plugoink::
# 510 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Plugoink (placeholder).$"

Lobby_Text_Fakemon_Gritespec::
# 514 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Gritespec (placeholder).$"

Lobby_Text_Fakemon_Magiken::
# 518 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Magiken (placeholder).$"

Lobby_Text_Fakemon_Ayewiraz::
# 522 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Ayewiraz (placeholder).$"

Lobby_Text_Fakemon_Electrodes::
# 526 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Electrodes (placeholder).$"

Lobby_Text_Fakemon_Eing::
# 530 "data/maps/Lobby/scripts.pory"
	.string "Información sobre Eing (placeholder).$"
