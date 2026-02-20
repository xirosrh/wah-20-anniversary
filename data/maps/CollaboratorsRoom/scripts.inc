CollaboratorsRoom_MapScripts::
	.byte 0


CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle::
# 5 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 6 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 7 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 8 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 9 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 10 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_3
# 13 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_4
# 15 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_5
# 17 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_6
CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1:
	return

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_3:
# 12 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_4:
# 14 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_5:
# 16 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_6:
# 18 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1


CollaboratorsRoom_EventScript_Kaktus_IntroRematch::
# 24 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_INMORTAL_KAKTUS
# 25 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 26 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 27 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Kaktus_IntroRematch_1
# 31 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 32 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_1:
# 28 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1, speaker = SP_NAME_INMORTAL_KAKTUS
	return


CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent::
# 38 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 39 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Kaktus::
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 45 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 46 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Kaktus_1
# 87 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 88 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 89 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 90 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 93 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_1:
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_5
# 50 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle
CollaboratorsRoom_EventScript_Kaktus_4:
# 53 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 54 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 55 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 56 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 58 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_Text_0
# 59 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 60 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 61 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 62 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Kaktus_9
# 76 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 77 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 82 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Kaktus_8:
# 84 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_5:
# 48 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroRematch
	goto CollaboratorsRoom_EventScript_Kaktus_4

CollaboratorsRoom_EventScript_Kaktus_9:
# 63 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 65 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 66 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 67 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 68 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 69 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 70 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 71 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 72 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 73 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 74 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS
	goto CollaboratorsRoom_EventScript_Kaktus_8


CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle::
# 99 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 101 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 103 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 104 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 105 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 106 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


CollaboratorsRoom_EventScript_Gameboycl_IntroRematch::
# 111 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_GAMEBOY_CL
# 112 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 114 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_1
# 118 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_1:
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent::
# 124 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 125 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gameboycl::
# 131 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 132 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 133 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gameboycl_1
# 168 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 169 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 170 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 171 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 172 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 173 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 174 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_1:
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL, CollaboratorsRoom_EventScript_Gameboycl_5
# 137 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle
CollaboratorsRoom_EventScript_Gameboycl_4:
# 139 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 140 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 141 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 142 "data/maps/CollaboratorsRoom/scripts.pory"
	random 3
# 143 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 145 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_10
# 147 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_11
# 149 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gameboycl_12
CollaboratorsRoom_EventScript_Gameboycl_8:
# 152 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 153 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 154 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 155 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_14
# 163 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
CollaboratorsRoom_EventScript_Gameboycl_13:
# 165 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_5:
# 135 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroRematch
	goto CollaboratorsRoom_EventScript_Gameboycl_4

CollaboratorsRoom_EventScript_Gameboycl_10:
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_11:
# 148 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_12:
# 150 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_14:
# 156 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 157 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 158 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 159 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 160 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 161 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL
	goto CollaboratorsRoom_EventScript_Gameboycl_13


CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle::
# 183 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 184 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 185 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 186 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 187 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Erkey_IntroRematch::
# 192 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 193 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ERKEY
# 195 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 196 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 197 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_IntroRematch_1
# 205 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 206 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_1:
# 198 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 199 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 200 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 201 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
	return


CollaboratorsRoom_EventScript_Erkey_OnFinishEvent::
# 213 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 214 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Erkey::
# 219 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 220 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 221 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Erkey_1
# 255 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 256 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 257 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 258 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 259 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 260 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 261 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_1:
# 222 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY, CollaboratorsRoom_EventScript_Erkey_5
# 225 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle
CollaboratorsRoom_EventScript_Erkey_4:
# 227 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 228 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 229 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 230 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 232 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 233 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, CollaboratorsRoom_EventScript_Erkey_Text_0
# 234 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 235 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 236 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 238 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_9
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 250 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 251 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
CollaboratorsRoom_EventScript_Erkey_8:
# 253 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_5:
# 223 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroRematch
	goto CollaboratorsRoom_EventScript_Erkey_4

CollaboratorsRoom_EventScript_Erkey_9:
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 241 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 242 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 243 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 244 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 245 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 246 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY
	goto CollaboratorsRoom_EventScript_Erkey_8


CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle::
# 266 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 267 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 268 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 270 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 272 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


CollaboratorsRoom_EventScript_Micolo_IntroRematch::
# 278 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 279 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 280 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_MICOLO
# 281 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 282 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 283 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_IntroRematch_1
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 288 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_1:
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


CollaboratorsRoom_EventScript_Micolo_OnFinishEvent::
# 297 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 298 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Micolo::
# 303 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 305 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Micolo_1
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 358 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 359 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 360 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 362 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 365 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 366 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 368 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 369 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 370 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 371 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 372 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_Movement_0
# 374 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 375 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 376 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 377 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_1:
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO, CollaboratorsRoom_EventScript_Micolo_5
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle
CollaboratorsRoom_EventScript_Micolo_4:
# 311 "data/maps/CollaboratorsRoom/scripts.pory"
	special SavePlayerParty
# 312 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 313 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 314 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 315 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 318 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_9
# 327 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 328 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 330 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, CollaboratorsRoom_EventScript_Micolo_Text_1
# 334 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 335 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 337 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 338 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_12
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 347 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 349 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 350 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 352 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Micolo_11:
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_5:
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroRematch
	goto CollaboratorsRoom_EventScript_Micolo_4

CollaboratorsRoom_EventScript_Micolo_9:
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 321 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 322 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 324 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end

CollaboratorsRoom_EventScript_Micolo_12:
# 339 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 340 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 343 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_11


CollaboratorsRoom_EventScript_Lillipup::
# 382 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 383 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 384 "data/maps/CollaboratorsRoom/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 385 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 386 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmoncry
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 388 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 389 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 390 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 395 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 396 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 397 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 403 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 406 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 398 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 401 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 404 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 407 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle::
# 414 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 415 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 416 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 417 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 418 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 420 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1
# 421 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_IntroRematch::
# 427 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_MRNIGHTOLOGY
# 428 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 429 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne CollaboratorsRoom_EventScript_MrNightology_IntroRematch_1
# 434 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_1:
# 430 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent::
# 440 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 441 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology::
# 446 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 447 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_MrNightology_1
# 544 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 545 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 546 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_10
# 548 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 549 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 550 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 551 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_11
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 554 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_1:
# 448 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 449 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 450 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_MrNightology_6
# 455 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_MrNightology_7
CollaboratorsRoom_EventScript_MrNightology_4:
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_9
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle
CollaboratorsRoom_EventScript_MrNightology_8:
# 469 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_2
# 471 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_ON
# 472 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 473 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_3
# 474 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 475 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 476 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 477 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_WARP_OUT
# 479 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, 3
# 480 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 481 "data/maps/CollaboratorsRoom/scripts.pory"
	showobjectat LOCALID_COLLABORATORS_ROOM_REONEKY, MAP_COLLABORATORS_ROOM
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_REONEKY, DIR_SOUTH
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 485 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 486 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 487 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 488 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY
# 489 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 490 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_5
# 492 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 493 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_6
# 495 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 497 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 503 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, Common_Movement_VersusWithDelay48
# 504 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 506 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 507 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_MrNightology_Text_6
# 509 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 511 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 512 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_MrNightology_13
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 534 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 535 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 536 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 537 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 538 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, -3
# 539 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
CollaboratorsRoom_EventScript_MrNightology_12:
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_6:
# 451 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_0
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_7:
# 456 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_1
# 458 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_9:
# 463 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroRematch
	goto CollaboratorsRoom_EventScript_MrNightology_8

CollaboratorsRoom_EventScript_MrNightology_13:
# 513 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 514 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_Movement_MrNightology_Despegue
# 515 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_Movement_MrNightology_Despegue
# 516 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 517 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_7, MSGBOX_AUTOCLOSE_TOP
# 519 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FALL
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_7
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 522 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_8, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 526 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_8
# 527 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_9
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 530 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY
	goto CollaboratorsRoom_EventScript_MrNightology_12


# 558 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_Movement_MrNightology_Despegue:
# 559 "data/maps/CollaboratorsRoom/scripts.pory"
	face_left
# 560 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 561 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 562 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 563 "data/maps/CollaboratorsRoom/scripts.pory"
	face_right
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	step_end

# 78 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_0:
# 78 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 78 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 80 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_1:
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 269 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 373 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_Movement_0:
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 416 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0:
# 416 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 420 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1:
# 420 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sweat_drop
	step_end

# 452 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_0:
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_left
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 457 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_1:
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 470 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_2:
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 473 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_3:
# 473 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_up
	step_end

# 477 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_4:
# 477 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 491 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_5:
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
	step_end

# 494 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_6:
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
	step_end

# 520 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_7:
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
	step_end

# 526 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_8:
# 526 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_question_mark
	step_end

# 528 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_9:
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 547 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_10:
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sad
	step_end

# 551 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_11:
# 551 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_annoyed
	step_end

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_0:
# 5 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, vaya…\n¿Así que completaste el desafío?$"

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_1:
# 8 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces ya no eres un{A} novat{OA}. Veamos si\n"
	.string "sabes aplicar lo aprendido.\p"
	.string "Un combate, sin atajos, sin trucos.\n"
	.string "¿List{OA}?$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0:
# 24 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ey, ¿qué tal? Mi Ludicolo sigue con\n"
	.string "ganas de bailar.\p"
	.string "¿Otro asalto?$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1:
# 28 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vamos!$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2:
# 31 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Será en otra oportunidad entonces!$"

CollaboratorsRoom_EventScript_Kaktus_Text_0:
# 58 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Acaso perdí?$"

CollaboratorsRoom_EventScript_Kaktus_Text_1:
# 65 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ja… perdí.$"

CollaboratorsRoom_EventScript_Kaktus_Text_2:
# 69 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

CollaboratorsRoom_EventScript_Kaktus_Text_3:
# 73 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Enhorabuena, crack.$"

CollaboratorsRoom_EventScript_Kaktus_Text_4:
# 76 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

CollaboratorsRoom_EventScript_Kaktus_Text_5:
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espero la revancha pronto!$"

CollaboratorsRoom_EventScript_Kaktus_Text_6:
# 87 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

CollaboratorsRoom_EventScript_Kaktus_Text_7:
# 90 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No soy competitivo ni ambicioso. Soy\n"
	.string "más bien una persona mediocre.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 106 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso puede jugarme en contra.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0:
# 111 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.\p"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1:
# 118 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_0:
# 158 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_1:
# 163 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "PENDIENTE GAMEBOY$"

CollaboratorsRoom_EventScript_Gameboycl_Text_2:
# 168 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un hack rom es como la arquitectura, se\n"
	.string "construye sobre lo existente.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_3:
# 170 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El arte aquí no es lo que se cambia, sino\n"
	.string "lo que se quiere transmitir.$"

CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0:
# 185 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0:
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1:
# 200 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2:
# 205 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

CollaboratorsRoom_EventScript_Erkey_Text_0:
# 233 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

CollaboratorsRoom_EventScript_Erkey_Text_1:
# 241 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

CollaboratorsRoom_EventScript_Erkey_Text_2:
# 244 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

CollaboratorsRoom_EventScript_Erkey_Text_3:
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

CollaboratorsRoom_EventScript_Erkey_Text_4:
# 255 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

CollaboratorsRoom_EventScript_Erkey_Text_5:
# 258 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si prestas atención.$"

CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0:
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres bueno con los\n"
	.string "Pokémon que he criado y entrenado.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0:
# 280 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar.\p"
	.string "¿Te atreves?$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1:
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

CollaboratorsRoom_EventScript_Micolo_Text_0:
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

CollaboratorsRoom_EventScript_Micolo_Text_1:
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, me has ganado.$"

CollaboratorsRoom_EventScript_Micolo_Text_2:
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Admito que eres bueno, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

CollaboratorsRoom_EventScript_Micolo_Text_3:
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

CollaboratorsRoom_EventScript_Micolo_Text_4:
# 358 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

CollaboratorsRoom_EventScript_Micolo_Text_5:
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

CollaboratorsRoom_EventScript_Micolo_Text_6:
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

CollaboratorsRoom_EventScript_Micolo_Text_7:
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

CollaboratorsRoom_EventScript_Micolo_Text_8:
# 375 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

CollaboratorsRoom_EventScript_Lillipup_Text_0:
# 385 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pup, pup, pup.$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0:
# 414 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Buscas problemas?\n"
	.string "¡Pues escucha nuestro lema!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1:
# 418 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Uy, me he equivocado!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2:
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perdona, es la costumbre jeje...\p"
	.string "Bueno, por lo que veo has completado el\n"
	.string "desafío. ¡Enhorabuena!\p"
	.string "Pero... ¡será por poco tiempo!\n"
	.string "¡Ha llegado el momento de ponerte a\l"
	.string "prueba una vez más!$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0:
# 427 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tú otra vez! ¿Te has quedado con ganas\n"
	.string "de más?$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1:
# 430 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Já! Si ya me lo imaginaba...$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2:
# 434 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿No?\n"
	.string "Bueno... Ya volverás.$"

CollaboratorsRoom_EventScript_MrNightology_Text_0:
# 469 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo un plan genial para derrotarte y\n"
	.string "para eso lucharé con un amigo.\p"
	.string "Así que...\n"
	.string "¡Que aparezca el invitado especial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_1:
# 474 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Estás preparado?\n"
	.string "¿Sí? Genial.\p"
	.string "¡Vente p'acá!$"

CollaboratorsRoom_EventScript_MrNightology_Text_2:
# 493 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ostras!\n"
	.string "¿Cómo lo has hecho?$"

CollaboratorsRoom_EventScript_MrNightology_Text_3:
# 495 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Coño! Transmisión instantánea, bro.\n"
	.string "¡No me he pasado entrenando en el\l"
	.string "planeta Yardrat todo este tiempo pa ná!$"

CollaboratorsRoom_EventScript_MrNightology_Text_4:
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah, mira qué bien! ¡Eso me viene genial\n"
	.string "para que la próxima vez no acabe\l"
	.string "reventao con tantas horas de bus!$"

CollaboratorsRoom_EventScript_MrNightology_Text_5:
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sorprendido, ¿no?\n"
	.string "Pues ha llegado la hora...\p"
	.string "¡Prepárate para luchar!$"

CollaboratorsRoom_EventScript_MrNightology_Text_6:
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¡Pero si era un plan genial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_7:
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡El Team Rocket despega de\n"
	.string "nuevooooo...!$"

CollaboratorsRoom_EventScript_MrNightology_Text_8:
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya aterrizaje!$"

CollaboratorsRoom_EventScript_MrNightology_Text_9:
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Y ReoNeky?\n"
	.string "Espero que haya aterrizado en su sala.$"

CollaboratorsRoom_EventScript_MrNightology_Text_10:
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has hecho todo lo que has podido, pero\n"
	.string "no es suficiente.$"

CollaboratorsRoom_EventScript_MrNightology_Text_11:
# 536 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Dale una vuelta a tu estrategia y...\p"
	.string "¡No nos hagas esperar mucho para la\n"
	.string "revancha!$"

CollaboratorsRoom_EventScript_MrNightology_Text_12:
# 545 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ay, si te contase...\p"
	.string "La Beta 1 de mi hack la publiqué en 2010\n"
	.string "y 15 años después, conseguí acabarlo.$"

CollaboratorsRoom_EventScript_MrNightology_Text_13:
# 549 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Una larga travesía para que al final, la\n"
	.string "gente te pregunte cuál es el cheat de\l"
	.string "los caramelos infinitos.$"

CollaboratorsRoom_EventScript_MrNightology_Text_14:
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te parece normal?\n"
	.string "En fin... La vida del romhacker.$"

CollaboratorsRoom_Text_Gameboycl_OnDefeat::
# 178 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

CollaboratorsRoom_Text_Micolo_ChoosePokemon::
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"
