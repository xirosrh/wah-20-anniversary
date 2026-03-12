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


CollaboratorsRoom_EventScript_Kaktus_TalkOnly::
# 24 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 25 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 26 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 27 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 28 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 29 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 30 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Kaktus_IntroRematch::
# 34 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 35 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 36 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_INMORTAL_KAKTUS
# 37 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1
# 38 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 39 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 40 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 41 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 42 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 43 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2
# 46 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3
# 48 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2:
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2, speaker = SP_NAME_INMORTAL_KAKTUS
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3:
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_4:
# 49 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 50 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent::
# 55 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 56 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Kaktus::
# 62 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 63 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Kaktus_1
# 104 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
	return

CollaboratorsRoom_EventScript_Kaktus_1:
# 65 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_5
# 68 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle
CollaboratorsRoom_EventScript_Kaktus_4:
# 71 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 72 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 73 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 74 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 75 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 76 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_Text_0
# 77 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 78 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Kaktus_9
# 94 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 95 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 96 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 97 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 98 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 99 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Kaktus_8:
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_5:
# 66 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroRematch
	goto CollaboratorsRoom_EventScript_Kaktus_4

CollaboratorsRoom_EventScript_Kaktus_9:
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 82 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 83 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 84 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 85 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 86 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 87 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 88 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 89 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 90 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 92 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS
	goto CollaboratorsRoom_EventScript_Kaktus_8


CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle::
# 109 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 110 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 111 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 112 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 114 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 116 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


CollaboratorsRoom_EventScript_Gameboycl_TalkOnly::
# 121 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 122 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 123 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 124 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 125 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 126 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 127 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gameboycl_IntroRematch::
# 131 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 132 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 133 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GAMEBOY_CL
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1
# 135 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 136 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 137 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 138 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 139 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 140 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2
# 143 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3
# 145 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2:
# 141 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3:
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_4:
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 147 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent::
# 152 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 153 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 154 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gameboycl::
# 160 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 161 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 162 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gameboycl_1
# 198 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
	return

CollaboratorsRoom_EventScript_Gameboycl_1:
# 163 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL, CollaboratorsRoom_EventScript_Gameboycl_5
# 166 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle
CollaboratorsRoom_EventScript_Gameboycl_4:
# 168 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 169 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 170 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 171 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 172 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 173 "data/maps/CollaboratorsRoom/scripts.pory"
	random 3
# 174 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 175 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 176 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_10
# 178 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_11
# 180 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gameboycl_12
CollaboratorsRoom_EventScript_Gameboycl_8:
# 183 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 184 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 185 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 186 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_14
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
CollaboratorsRoom_EventScript_Gameboycl_13:
# 196 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_5:
# 164 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroRematch
	goto CollaboratorsRoom_EventScript_Gameboycl_4

CollaboratorsRoom_EventScript_Gameboycl_10:
# 177 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_11:
# 179 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_12:
# 181 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_14:
# 187 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 188 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 189 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 190 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 191 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 192 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL
	goto CollaboratorsRoom_EventScript_Gameboycl_13


CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle::
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 210 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 211 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Erkey_TalkOnly::
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 217 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 218 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 219 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 220 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 221 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 222 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Erkey_IntroRematch::
# 226 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 227 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 228 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 229 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 230 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ERKEY
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1
# 232 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 233 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 234 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 235 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 236 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Erkey_IntroRematch_2
# 244 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Erkey_IntroRematch_3
# 246 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Erkey_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_2:
# 238 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 241 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 242 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_3:
# 245 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_4:
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 248 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 250 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Erkey_OnFinishEvent::
# 255 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 256 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 257 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Erkey::
# 262 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 263 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 264 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Erkey_1
# 298 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return

CollaboratorsRoom_EventScript_Erkey_1:
# 265 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY, CollaboratorsRoom_EventScript_Erkey_5
# 268 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle
CollaboratorsRoom_EventScript_Erkey_4:
# 270 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 272 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 274 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 275 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, CollaboratorsRoom_EventScript_Erkey_Text_0
# 277 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 278 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 279 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 280 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 281 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_9
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 293 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 294 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
CollaboratorsRoom_EventScript_Erkey_8:
# 296 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_5:
# 266 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroRematch
	goto CollaboratorsRoom_EventScript_Erkey_4

CollaboratorsRoom_EventScript_Erkey_9:
# 282 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 283 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 285 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 286 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 288 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 289 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 290 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY
	goto CollaboratorsRoom_EventScript_Erkey_8


CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle::
# 303 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 305 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 308 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 310 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 311 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


CollaboratorsRoom_EventScript_Micolo_TalkOnly::
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 318 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 321 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 322 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 324 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 325 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 326 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 327 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 328 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 330 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 334 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 335 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Micolo_IntroRematch::
# 340 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 343 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 344 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MICOLO
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 347 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 349 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 350 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Micolo_IntroRematch_2
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Micolo_IntroRematch_3
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Micolo_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_2:
# 352 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_3:
# 355 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_4:
# 357 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 358 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Micolo_OnFinishEvent::
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 368 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 369 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Micolo::
# 374 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 375 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 376 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Micolo_1
# 427 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return

CollaboratorsRoom_EventScript_Micolo_1:
# 377 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO, CollaboratorsRoom_EventScript_Micolo_5
# 380 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle
CollaboratorsRoom_EventScript_Micolo_4:
# 382 "data/maps/CollaboratorsRoom/scripts.pory"
	special SavePlayerParty
# 383 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 384 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 385 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 386 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 388 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 389 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 390 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_9
# 398 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 399 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 401 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 402 "data/maps/CollaboratorsRoom/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 403 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 404 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, CollaboratorsRoom_EventScript_Micolo_Text_1
# 405 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 406 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 407 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 408 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 409 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_12
# 416 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 417 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 418 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 420 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 421 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 423 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Micolo_11:
# 425 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_5:
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroRematch
	goto CollaboratorsRoom_EventScript_Micolo_4

CollaboratorsRoom_EventScript_Micolo_9:
# 391 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 392 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 393 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 394 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 395 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end

CollaboratorsRoom_EventScript_Micolo_12:
# 410 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 411 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 412 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 413 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 414 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_11


CollaboratorsRoom_EventScript_Lillipup::
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 433 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 434 "data/maps/CollaboratorsRoom/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 436 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmoncry
# 437 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 438 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 439 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 440 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 445 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 446 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 447 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 450 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 456 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 448 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 451 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle::
# 464 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 465 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 467 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 468 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 469 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1
# 471 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 472 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_TalkOnly::
# 477 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 479 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 480 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0
# 481 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1
# 485 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 486 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 487 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return


CollaboratorsRoom_EventScript_MrNightology_IntroRematch::
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 492 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 493 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MRNIGHTOLOGY
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1
# 495 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 497 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3
# 504 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_4
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2:
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2, speaker = SP_NAME_MRNIGHTOLOGY
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3:
# 503 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_4:
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 506 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return


CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent::
# 511 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 512 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology::
# 517 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_MrNightology_1
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return

CollaboratorsRoom_EventScript_MrNightology_1:
# 519 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_MrNightology_6
# 526 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_MrNightology_7
CollaboratorsRoom_EventScript_MrNightology_4:
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_9
# 537 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle
CollaboratorsRoom_EventScript_MrNightology_8:
# 540 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_2
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_ON
# 543 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 544 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_3
# 545 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 546 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 548 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 549 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_WARP_OUT
# 550 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, 3
# 551 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	showobjectat LOCALID_COLLABORATORS_ROOM_REONEKY, MAP_COLLABORATORS_ROOM
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_REONEKY, DIR_SOUTH
# 554 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 555 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 556 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 557 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 559 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY
# 560 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 561 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 562 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_5
# 563 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_6
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 568 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 569 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 570 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 572 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 573 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 574 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, Common_Movement_VersusWithDelay48
# 575 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 576 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 577 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 579 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_MrNightology_Text_6
# 580 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 582 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 583 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_MrNightology_13
# 604 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 605 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 606 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 607 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 608 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, -3
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
CollaboratorsRoom_EventScript_MrNightology_12:
# 612 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_6:
# 522 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_0
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_7:
# 527 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_1
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_9:
# 534 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroRematch
	goto CollaboratorsRoom_EventScript_MrNightology_8

CollaboratorsRoom_EventScript_MrNightology_13:
# 584 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 585 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_Movement_MrNightology_Despegue
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_Movement_MrNightology_Despegue
# 587 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 588 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_7, MSGBOX_AUTOCLOSE_TOP
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FALL
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_7
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 593 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_8, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 596 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 597 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_8
# 598 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_9
# 600 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 601 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY
	goto CollaboratorsRoom_EventScript_MrNightology_12


# 618 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_Movement_MrNightology_Despegue:
# 619 "data/maps/CollaboratorsRoom/scripts.pory"
	face_left
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 621 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	face_right
# 624 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 625 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 627 "data/maps/CollaboratorsRoom/scripts.pory"
	step_end

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle::
# 631 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 632 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 634 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 635 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 636 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FaceAwayPlayer
# 637 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 638 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 639 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 640 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 641 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 642 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 643 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 644 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 646 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 647 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 648 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 649 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 650 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return


CollaboratorsRoom_EventScript_Gosuto_TalkOnly::
# 655 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 656 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 659 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 660 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 661 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 662 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 663 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 664 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 665 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 666 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gosuto_IntroRematch::
# 670 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 671 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 672 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GOSUTO
# 673 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 675 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 676 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 677 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 678 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 679 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2
# 682 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3
# 684 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2:
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3:
# 683 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_4:
# 685 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 686 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent::
# 691 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 692 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 693 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gosuto::
# 698 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 699 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 700 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gosuto_1
# 730 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return

CollaboratorsRoom_EventScript_Gosuto_1:
# 701 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_5
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle
CollaboratorsRoom_EventScript_Gosuto_4:
# 706 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 707 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 708 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 709 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 710 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_Text_0
# 712 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 713 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 714 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 715 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gosuto_9
# 724 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 725 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 726 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
CollaboratorsRoom_EventScript_Gosuto_8:
# 728 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_5:
# 702 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroRematch
	goto CollaboratorsRoom_EventScript_Gosuto_4

CollaboratorsRoom_EventScript_Gosuto_9:
# 716 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 717 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 718 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 719 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 720 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 721 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 722 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO
	goto CollaboratorsRoom_EventScript_Gosuto_8


CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle::
# 736 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 737 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_MusicNote
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 739 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 740 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 741 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 40
# 742 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
	return


CollaboratorsRoom_EventScript_Acimut_TalkOnly::
# 747 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 749 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 750 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 751 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 752 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 753 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 754 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 755 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 756 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 757 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 759 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 760 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 761 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 762 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 763 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 764 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 765 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 768 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Acimut_IntroRematch::
# 784 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 785 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 786 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 787 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ACIMUT
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1
# 789 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 790 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 791 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 792 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 793 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 794 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Acimut_IntroRematch_2
# 797 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Acimut_IntroRematch_3
# 800 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Acimut_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_2:
# 795 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_3:
# 798 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 799 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_4:
# 801 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 802 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 803 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Acimut_OnFinishEvent::
# 808 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 809 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 810 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Acimut::
# 815 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 816 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 817 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Acimut_1
# 851 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return

CollaboratorsRoom_EventScript_Acimut_1:
# 818 "data/maps/CollaboratorsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_COOL, FALSE
# 819 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT, CollaboratorsRoom_EventScript_Acimut_5
# 822 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle
CollaboratorsRoom_EventScript_Acimut_4:
# 824 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 825 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 826 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 827 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 828 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 829 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 830 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ACIMUT, CollaboratorsRoom_EventScript_Acimut_Text_0
# 831 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 832 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 833 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 834 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Acimut_9
# 843 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 844 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 845 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 846 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 847 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
CollaboratorsRoom_EventScript_Acimut_8:
# 849 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_5:
# 820 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroRematch
	goto CollaboratorsRoom_EventScript_Acimut_4

CollaboratorsRoom_EventScript_Acimut_9:
# 835 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 836 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 837 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 838 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 839 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 840 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 841 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT
	goto CollaboratorsRoom_EventScript_Acimut_8


CollaboratorsRoom_EventScript_Alexmad_LongIntro::
# 856 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 857 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 858 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 859 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 860 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 861 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_IdeaWithDelay48
# 862 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 863 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 864 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 865 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 866 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 867 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 868 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 869 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 870 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 871 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 872 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 873 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 874 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 875 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 876 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 877 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
	return


CollaboratorsRoom_EventScript_Alexmad_QRFlow::
# 882 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0, speaker = SP_NAME_ALEXMAD
# 883 "data/maps/CollaboratorsRoom/scripts.pory"
	load_field_pic FP_MAD_QR, 120, 80
# 884 "data/maps/CollaboratorsRoom/scripts.pory"
	waitbuttonpress
# 885 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 886 "data/maps/CollaboratorsRoom/scripts.pory"
	destroy_field_pic FP_MAD_QR
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
# 888 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 889 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_2
# 910 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_QRFlow_1:
# 912 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_QRFlow_2:
# 890 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 891 "data/maps/CollaboratorsRoom/scripts.pory"
	special EnterCode
# 892 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 893 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetCodeFeedback
# 894 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_5
# 904 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 905 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 906 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_AnnoyedWithDelay48
# 907 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow_1

CollaboratorsRoom_EventScript_Alexmad_QRFlow_5:
# 895 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 896 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_TEMP_ALEXMAD_PUZZLE_STARTED
# 897 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_FAILED
# 898 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_ALEXMAD_PUZZLE_CHECKPOINT, 0
# 899 "data/maps/CollaboratorsRoom/scripts.pory"
	getplayerxy VAR_ALEXMAD_PUZZLE_START_X, VAR_ALEXMAD_PUZZLE_START_Y
# 900 "data/maps/CollaboratorsRoom/scripts.pory"
	special InitAlexmadPuzzlePartyOrderCheck
# 901 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle::
# 916 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 917 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Alexmad_IntroRematch::
# 922 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 923 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 924 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ALEXMAD
# 925 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1
# 926 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 927 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 928 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 929 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 930 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 931 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2
# 934 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3
# 937 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_4
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2:
# 932 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3:
# 935 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 936 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_4:
# 938 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 939 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Alexmad_DoBattle::
# 944 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 945 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 946 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_VersusWithDelay48
# 947 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 948 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 949 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ALEXMAD, CollaboratorsRoom_Text_Alexmad_OnDefeat
# 950 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 951 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 952 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 953 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_DoBattle_2
# 963 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 964 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 965 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 966 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 967 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_DoBattle_1:
# 969 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_DoBattle_2:
# 954 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 955 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_SurpriseWithDelay48
# 956 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 957 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 958 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 959 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 960 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 961 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle_1


CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent::
# 973 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 974 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 975 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad::
# 984 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 985 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 986 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_TEMP_ALEXMAD_PUZZLE_STARTED, CollaboratorsRoom_EventScript_Alexmad_2
# 990 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 991 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_5
CollaboratorsRoom_EventScript_Alexmad_4:
# 994 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 995 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 996 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 997 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 998 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 999 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_Movement_0
# 1000 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1001 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 1002 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1003 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 0
# 1004 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_MET_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_8
CollaboratorsRoom_EventScript_Alexmad_7:
# 1010 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_10
# 1026 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_16
# 1053 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_28
# 1056 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_12, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_27:
# 1058 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1059 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_35
# 1062 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1063 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_2:
# 987 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_0, MSGBOX_NPC, speaker = SP_NAME_ALEXMAD
	end

CollaboratorsRoom_EventScript_Alexmad_5:
# 992 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_4

CollaboratorsRoom_EventScript_Alexmad_8:
# 1005 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 1
# 1006 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 1007 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_MET_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_7

CollaboratorsRoom_EventScript_Alexmad_10:
# 1011 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_13
# 1019 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1020 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1021 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 1022 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1023 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_13:
# 1012 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_20
# 1015 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
CollaboratorsRoom_EventScript_Alexmad_19:
# 1017 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_16:
# 1027 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_24
# 1030 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1031 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_QuestionMarkWithDelay48
# 1033 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1034 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Alexmad_23:
# 1036 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_EventScript_Alexmad_Text_7, CollaboratorsRoom_EventScript_Alexmad_Text_8, CollaboratorsRoom_EventScript_Alexmad_Text_9
# 1037 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1038 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_32
# 1040 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_33
# 1050 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_20:
# 1013 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroRematch
	goto CollaboratorsRoom_EventScript_Alexmad_19

CollaboratorsRoom_EventScript_Alexmad_24:
# 1028 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_23

CollaboratorsRoom_EventScript_Alexmad_28:
# 1054 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_11, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_27

CollaboratorsRoom_EventScript_Alexmad_32:
# 1039 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_33:
# 1041 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_39
# 1044 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1045 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HappyWithDelay48
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_38:
# 1048 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_35:
# 1060 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_39:
# 1042 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
	goto CollaboratorsRoom_EventScript_Alexmad_38


CollaboratorsRoom_EventScript_AlexmadPuzzleComplete::
# 1070 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1071 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FaceRight
# 1072 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1073 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_DoubleExclamationMark
# 1074 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1075 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0
# 1076 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1077 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1
# 1079 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_SUCCESS
# 1080 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1081 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1082 "data/maps/CollaboratorsRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 4, 4
# 1083 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1084 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 1085 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1086 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_COMPLETED
# 1087 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1088 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 1089 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_AlexmadPuzzleFailed::
# 1094 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1095 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FacePlayer
# 1096 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FAILURE
# 1097 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_XWithDelay48
# 1098 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1099 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 1100 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


# 96 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_0:
# 96 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 96 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 98 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_1:
# 98 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 98 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 98 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 307 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 332 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0:
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 466 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0:
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 470 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1:
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sweat_drop
	step_end

# 480 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0:
# 480 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sad
	step_end

# 484 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1:
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_annoyed
	step_end

# 523 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_0:
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_left
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 528 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_1:
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 541 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_2:
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 544 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_3:
# 544 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_up
	step_end

# 548 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_4:
# 548 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 562 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_5:
# 562 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
# 562 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
	step_end

# 565 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_6:
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
	step_end

# 591 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_7:
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
	step_end

# 597 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_8:
# 597 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_question_mark
	step_end

# 599 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_9:
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 999 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Alexmad_Movement_0:
# 999 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 999 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 999 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 1075 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0:
# 1075 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
	step_end

# 1077 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1:
# 1077 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
# 1077 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
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

CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_0:
# 24 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_1:
# 27 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0:
# 34 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ey, ¿qué tal? Mi Ludicolo sigue con\n"
	.string "ganas de bailar.$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1:
# 37 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro asalto?$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2:
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vamos!$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3:
# 49 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Será en otra oportunidad entonces!$"

CollaboratorsRoom_EventScript_Kaktus_Text_0:
# 76 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Acaso perdí?$"

CollaboratorsRoom_EventScript_Kaktus_Text_1:
# 83 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ja… perdí.$"

CollaboratorsRoom_EventScript_Kaktus_Text_2:
# 87 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

CollaboratorsRoom_EventScript_Kaktus_Text_3:
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Enhorabuena, crack.$"

CollaboratorsRoom_EventScript_Kaktus_Text_4:
# 94 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

CollaboratorsRoom_EventScript_Kaktus_Text_5:
# 99 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espero la revancha pronto!$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 110 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No soy competitivo ni ambicioso.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Soy más bien una persona mediocre.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_2:
# 116 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso puede jugarme en contra.$"

CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_0:
# 121 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un hack rom es como la arquitectura,\nse construye sobre lo existente.$"

CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_1:
# 123 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El arte aquí no es lo que se cambia,\nsino lo que se quiere transmitir.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0:
# 131 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1:
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2:
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_0:
# 189 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_1:
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "PENDIENTE GAMEBOY$"

CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0:
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0:
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1:
# 219 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si prestas atención.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0:
# 228 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1:
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres volver a luchar?$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2:
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3:
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

CollaboratorsRoom_EventScript_Erkey_Text_0:
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

CollaboratorsRoom_EventScript_Erkey_Text_1:
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

CollaboratorsRoom_EventScript_Erkey_Text_2:
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

CollaboratorsRoom_EventScript_Erkey_Text_3:
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0:
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres buen{OA} con los\n"
	.string "Pokémon que he criado y entrenado.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0:
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1:
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2:
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3:
# 326 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4:
# 334 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0:
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1:
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te atreves?$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2:
# 357 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

CollaboratorsRoom_EventScript_Micolo_Text_0:
# 394 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

CollaboratorsRoom_EventScript_Micolo_Text_1:
# 404 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, me has ganado.$"

CollaboratorsRoom_EventScript_Micolo_Text_2:
# 412 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Admito que eres buen{OA}, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

CollaboratorsRoom_EventScript_Micolo_Text_3:
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

CollaboratorsRoom_EventScript_Lillipup_Text_0:
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pup, pup, pup.$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0:
# 464 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Buscas problemas?\n"
	.string "¡Pues escucha nuestro lema!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1:
# 468 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Uy, me he equivocado!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2:
# 472 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perdona, es la costumbre jeje…\p"
	.string "Bueno, por lo que veo has completado el\n"
	.string "desafío. ¡Enhorabuena!\p"
	.string "Pero… ¡será por poco tiempo!\n"
	.string "¡Ha llegado el momento de ponerte a\l"
	.string "prueba una vez más!$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0:
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ay, si te contase…\p"
	.string "La Beta 1 de mi hack la publiqué en 2010\n"
	.string "y 15 años después, conseguí acabarlo.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1:
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Una larga travesía para que al final, la\n"
	.string "gente te pregunte cuál es el cheat de\l"
	.string "los caramelos infinitos.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2:
# 486 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te parece normal?\n"
	.string "En fin… La vida del romhacker.$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0:
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tú otra vez!$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1:
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te has quedado con ganas de más?$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2:
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Já! Si ya me lo imaginaba…$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3:
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿No?\n"
	.string "Bueno… Ya volverás.$"

CollaboratorsRoom_EventScript_MrNightology_Text_0:
# 540 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo un plan genial para derrotarte y\n"
	.string "para eso lucharé con un amigo.\p"
	.string "Así que…\n"
	.string "¡Que aparezca el invitado especial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_1:
# 545 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Estás preparado?\n"
	.string "¿Sí? Genial.\p"
	.string "¡Vente p'acá!$"

CollaboratorsRoom_EventScript_MrNightology_Text_2:
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ostras!\n"
	.string "¿Cómo lo has hecho?$"

CollaboratorsRoom_EventScript_MrNightology_Text_3:
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Coño! Transmisión instantánea, bro.\n"
	.string "¡No me he pasado entrenando en el\l"
	.string "planeta Yardrat todo este tiempo pa ná!$"

CollaboratorsRoom_EventScript_MrNightology_Text_4:
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah, mira qué bien! ¡Eso me viene genial\n"
	.string "para que la próxima vez no acabe\l"
	.string "reventao con tantas horas de bus!$"

CollaboratorsRoom_EventScript_MrNightology_Text_5:
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sorprendido, ¿no?\n"
	.string "Pues ha llegado la hora…\p"
	.string "¡Prepárate para luchar!$"

CollaboratorsRoom_EventScript_MrNightology_Text_6:
# 579 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¡Pero si era un plan genial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_7:
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡El Team Rocket despega de nuevooooo…!$"

CollaboratorsRoom_EventScript_MrNightology_Text_8:
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya aterrizaje!$"

CollaboratorsRoom_EventScript_MrNightology_Text_9:
# 600 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Y ReoNeky?\n"
	.string "Espero que haya aterrizado en su sala.$"

CollaboratorsRoom_EventScript_MrNightology_Text_10:
# 604 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has hecho todo lo que has podido, pero\n"
	.string "no es suficiente.$"

CollaboratorsRoom_EventScript_MrNightology_Text_11:
# 607 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Dale una vuelta a tu estrategia y…\p"
	.string "¡No nos hagas esperar mucho para la\n"
	.string "revancha!$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0:
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Oh! Pues parece que has superado el\n"
	.string "desafío de las salas.\p"
	.string "¿Qué te parece si te ponemos a prueba y\n"
	.string "vemos de lo que eres capaz?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1:
# 635 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Hacemos esto un poco más divertido?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2:
# 641 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "O mejor dicho, ¿¡qué te parece si lo\n"
	.string "hacemos el doble de divertido!?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3:
# 650 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Muy bien, entra al mundo de las\n"
	.string "tinieblas conmigo…$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0:
# 655 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizás me conoces, quizás no, pero no te\n"
	.string "culpo; paso como una sombra entre las\l"
	.string "tinieblas.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1:
# 659 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero a pesar de permanecer entre las\n"
	.string "tinieblas, he aportado a grandes\l"
	.string "proyectos dando un pequeño grano de\l"
	.string "arena.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2:
# 663 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Que no se diga más y a seguir\n"
	.string "procesando píxeles!$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0:
# 673 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate? ¿Estás segur{OA} de estar\n"
	.string "list{OA} para entrar al mundo de las\l"
	.string "tinieblas?$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1:
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ok, veamos si esta vez logras superar\n"
	.string "tus miedos.$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2:
# 685 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien pensado; aunque puedes volver\n"
	.string "cuando quieras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_0:
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Creo que ya superaste tus miedos y\n"
	.string "superaste las sombras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_1:
# 719 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, parece que encontraste una\n"
	.string "chispa de suerte.\p"
	.string "Aprovecha esa luz mientras puedas,\n"
	.string "porque las sombras son pacientes y las\l"
	.string "tinieblas siempre terminan ganando al\l"
	.string "final.$"

CollaboratorsRoom_EventScript_Gosuto_Text_2:
# 724 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te sientas mal; no cualquiera\n"
	.string "sobrevive a mis tinieblas.$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0:
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espera! ¿Escuchas eso?$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1:
# 742 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Es el sonido de la batalla!$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0:
# 747 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un día empecé a descompilar Pokémon\n"
	.string "FireRed en español para obtener la ROM\l"
	.string "original compilando pokefirered.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1:
# 749 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tuvieron que pasar dos años para\n"
	.string "encontrar motivación en el desafío 30\l"
	.string "días dentro del foro de WaH.\p"
	.string "Durante ese tiempo logré hacer\n"
	.string "coincidencia al 100%.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2:
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Fue el mejor día de mi vida en el mundo\n"
	.string "del rom hacking, superando un reto\l"
	.string "personal muy significativo para mí.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3:
# 765 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Por cierto, aquí la música se escucha\n"
	.string "mejor en estéreo.$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0:
# 784 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La música son matemáticas y puro\n"
	.string "sentimiento ¡como los combates\l"
	.string "Pokémon!$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1:
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿List{OA} para la revancha?$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2:
# 802 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras. Aquí siempre hay\n"
	.string "buena música para combatir.$"

CollaboratorsRoom_EventScript_Acimut_Text_0:
# 830 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué ha pasado aquí?$"

CollaboratorsRoom_EventScript_Acimut_Text_1:
# 837 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ese último movimiento no lo vi venir…$"

CollaboratorsRoom_EventScript_Acimut_Text_2:
# 840 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Espero podamos volver a enfrentarnos\n"
	.string "en un futuro.$"

CollaboratorsRoom_EventScript_Acimut_Text_3:
# 843 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La armonía de tus Pokémon lo es todo…$"

CollaboratorsRoom_EventScript_Acimut_Text_4:
# 847 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si quieres volver a intentarlo, aquí\n"
	.string "estaré.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0:
# 856 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años… ¿te das cuenta?$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1:
# 858 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí crecimos entre bugs, tiles mal\n"
	.string "alineados y scripts que se colgaban en\l"
	.string "el último mapa.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2:
# 862 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah! Si ves a Baro por ahí… no intentes\n"
	.string "ser su amigo.\p"
	.string "Créeme, no termina bien.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3:
# 866 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Y si te topas con Serg!o… salúdalo con\n"
	.string "respeto.\p"
	.string "Es leyenda.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4:
# 869 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Todos le tenemos un cariño especial…\n"
	.string "Y no, no homo.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5:
# 872 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me encanta la playa, hacer mapas bien\n"
	.string "locos y meter bosques dentro de\l"
	.string "cuevas.\p"
	.string "Eso dice muchas cosas de mí.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6:
# 875 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Los hacks dicen muchas cosas de\n"
	.string "nosotros.\p"
	.string "Incluso en nuestra vida personal… nos\n"
	.string "hicieron mejores personas.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0:
# 882 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Escanea el QR con tu móvil y nos vemos\n"
	.string "en el otro mundo.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1:
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lo viste?$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2:
# 890 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces escribe la palabra que viste\n"
	.string "en el video.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3:
# 895 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto… Veo que sí lo viste.\p"
	.string "Entonces sabes lo que tienes que hacer.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4:
# 904 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No… Esa no es.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5:
# 907 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando tengas la respuesta\n"
	.string "correcta.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6:
# 910 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.$"

CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0:
# 916 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cada hack tiene su propia esencia. La\n"
	.string "personalidad de su creador vive dentro\l"
	.string "de él.\p"
	.string "Este lleva lo mejor de grandes nombres\n"
	.string "de la comunidad.\p"
	.string "Más de dos décadas evolucionando.\n"
	.string "Nunca se rindieron… nunca dejaron de\l"
	.string "crear.\p"
	.string "Veamos si tú tampoco te rindes.$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_0:
# 922 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Regresaste…\n"
	.string "Eso ya dice algo.\p"
	.string "En WAH aprendimos que rendirse no es\n"
	.string "una opción.\p"
	.string "Cada error es una versión nueva… cada\n"
	.string "derrota es un parche.\p"
	.string "Y cada parche nos hizo mejores.$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1:
# 925 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate?$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2:
# 938 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras volver, aquí estaré.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0:
# 956 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Excelente…\n"
	.string "Eres digno de estar aquí.\p"
	.string "Me alegra ver que la comunidad nunca\n"
	.string "dejó de ser la mejor.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1:
# 959 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hoy perdí yo…\n"
	.string "Pero quizás mañana podría ganar Samee.\p"
	.string "Nos veremos pronto.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2:
# 963 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veo que no siempre tener el mejor\n"
	.string "equipo es suficiente.\p"
	.string "La estrategia pesa más que pulsar A a lo\n"
	.string "loco.$"

CollaboratorsRoom_EventScript_Alexmad_Text_0:
# 987 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que tienes que hacer, ¿no?$"

CollaboratorsRoom_EventScript_Alexmad_Text_1:
# 992 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sm1, sm2 o…$"

CollaboratorsRoom_EventScript_Alexmad_Text_2:
# 1019 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya lo lograste.$"

CollaboratorsRoom_EventScript_Alexmad_Text_3:
# 1022 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER.\p"
	.string "Siempre fue bueno con los acertijos.\n"
	.string "Sigue adelante, seguro que te irá bien.$"

CollaboratorsRoom_EventScript_Alexmad_Text_4:
# 1028 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Pero también podemos ir directo a la\n"
	.string "batalla.\n"
	.string "¿Qué prefieres?$"

CollaboratorsRoom_EventScript_Alexmad_Text_5:
# 1030 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tu de nuevo! Tengo dos propuestas\n"
	.string "para ti.$"

CollaboratorsRoom_EventScript_Alexmad_Text_6:
# 1033 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_7:
# 1036 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evento$"

CollaboratorsRoom_EventScript_Alexmad_Text_8:
# 1036 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Batalla$"

CollaboratorsRoom_EventScript_Alexmad_Text_9:
# 1036 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Salir$"

CollaboratorsRoom_EventScript_Alexmad_Text_10:
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veamos qué versión eres ahora.$"

CollaboratorsRoom_EventScript_Alexmad_Text_11:
# 1054 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Dime… ¿lo quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_12:
# 1056 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has vuelto, ¿quieres seguir con el\n"
	.string "evento?$"

CollaboratorsRoom_EventScript_Alexmad_Text_13:
# 1062 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.\n"
	.string "El Mitic no espera… pero tampoco se\l"
	.string "repite.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0:
# 1080 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Lo has logrado! Veo que eres buen{OA}.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1:
# 1085 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER. Siempre fue bueno\n"
	.string "con los acertijos.\p"
	.string "Quizás pueda ayudarte en tu camino.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2:
# 1087 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "PENDIENTE PREMIO$"

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0:
# 1098 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, no… así no es.\p"
	.string "Vuelve a hablarme si quieres intentarlo\n"
	.string "de nuevo.$"

CollaboratorsRoom_Text_Gameboycl_OnDefeat::
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

CollaboratorsRoom_Text_Micolo_ChoosePokemon::
# 362 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"

CollaboratorsRoom_RematchMultichoice_Rematch::
# 771 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Luchemos de nuevo!$"

CollaboratorsRoom_RematchMultichoice_TalkOnly::
# 775 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prefiero simplemente hablar.$"

CollaboratorsRoom_RematchMultichoice_Exit::
# 779 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, gracias.$"

CollaboratorsRoom_Text_Alexmad_OnDefeat::
# 979 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años de comunidad y aún me\n"
	.string "sorprenden.$"
