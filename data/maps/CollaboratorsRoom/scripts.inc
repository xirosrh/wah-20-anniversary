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
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
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
# 49 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 50 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2:
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2, speaker = SP_NAME_INMORTAL_KAKTUS
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3:
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
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
	waitmovement 0
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
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
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
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
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 147 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2:
# 141 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3:
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
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
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 188 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 189 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 190 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 191 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 192 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL
	goto CollaboratorsRoom_EventScript_Gameboycl_13


CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle::
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 210 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Erkey_TalkOnly::
# 215 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 217 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 218 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 219 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 220 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 221 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Erkey_IntroRematch::
# 225 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 226 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 227 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 228 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 229 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ERKEY
# 230 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 232 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 233 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 234 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 235 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 236 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Erkey_IntroRematch_2
# 243 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Erkey_IntroRematch_3
# 246 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 248 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_2:
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 238 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 241 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_3:
# 244 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return


CollaboratorsRoom_EventScript_Erkey_OnFinishEvent::
# 254 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 255 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 256 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Erkey::
# 261 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 262 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 263 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Erkey_1
# 297 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return

CollaboratorsRoom_EventScript_Erkey_1:
# 264 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY, CollaboratorsRoom_EventScript_Erkey_5
# 267 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle
CollaboratorsRoom_EventScript_Erkey_4:
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 270 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 272 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 274 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 275 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, CollaboratorsRoom_EventScript_Erkey_Text_0
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 277 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 278 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 279 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 280 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_9
# 291 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 293 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
CollaboratorsRoom_EventScript_Erkey_8:
# 295 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_5:
# 265 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroRematch
	goto CollaboratorsRoom_EventScript_Erkey_4

CollaboratorsRoom_EventScript_Erkey_9:
# 281 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 282 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 283 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 285 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 286 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 288 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 289 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY
	goto CollaboratorsRoom_EventScript_Erkey_8


CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle::
# 302 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 303 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 305 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 308 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 310 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit
	return


CollaboratorsRoom_EventScript_Micolo_TalkOnly::
# 315 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 318 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 321 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 322 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 324 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 325 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 326 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 327 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 328 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 330 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 334 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 335 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Micolo_IntroRematch::
# 339 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 340 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 343 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MICOLO
# 344 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 347 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 349 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 350 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Micolo_IntroRematch_2
# 353 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Micolo_IntroRematch_3
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 357 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_2:
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_3:
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return


CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit::
# 362 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_DIFFICULTY
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_EASY, CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_3
# 366 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_NORMAL, CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_4
# 370 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1:
	return

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_3:
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_4:
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1


CollaboratorsRoom_EventScript_Micolo_OnFinishEvent::
# 377 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 379 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Micolo::
# 384 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 385 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 386 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Micolo_1
# 446 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return

CollaboratorsRoom_EventScript_Micolo_1:
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO, CollaboratorsRoom_EventScript_Micolo_5
# 390 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle
CollaboratorsRoom_EventScript_Micolo_4:
# 392 "data/maps/CollaboratorsRoom/scripts.pory"
	special SavePlayerParty
# 393 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 394 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 395 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_DIFFICULTY
# 396 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_EASY, CollaboratorsRoom_EventScript_Micolo_10
# 399 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_NORMAL, CollaboratorsRoom_EventScript_Micolo_11
# 403 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 1
CollaboratorsRoom_EventScript_Micolo_8:
# 406 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 407 "data/maps/CollaboratorsRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 408 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 409 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 410 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_14
# 418 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 420 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 421 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 423 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 424 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, CollaboratorsRoom_EventScript_Micolo_Text_1
# 425 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 426 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 427 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 428 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 429 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_17
# 436 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 437 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 438 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 439 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 440 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 441 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 442 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
CollaboratorsRoom_EventScript_Micolo_16:
# 444 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_5:
# 388 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroRematch
	goto CollaboratorsRoom_EventScript_Micolo_4

CollaboratorsRoom_EventScript_Micolo_10:
# 397 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 2
	goto CollaboratorsRoom_EventScript_Micolo_8

CollaboratorsRoom_EventScript_Micolo_11:
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 2
	goto CollaboratorsRoom_EventScript_Micolo_8

CollaboratorsRoom_EventScript_Micolo_14:
# 411 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 412 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 413 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 414 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 415 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end

CollaboratorsRoom_EventScript_Micolo_17:
# 430 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 431 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 433 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 434 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_16


CollaboratorsRoom_EventScript_Lillipup::
# 451 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 455 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmoncry
# 456 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 458 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 459 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 464 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 465 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 469 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 472 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 475 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 467 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 473 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 476 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle::
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 485 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 486 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 487 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 488 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 489 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1
# 490 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_TalkOnly::
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 497 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 503 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1
# 504 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 506 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return


CollaboratorsRoom_EventScript_MrNightology_IntroRematch::
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 511 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 512 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MRNIGHTOLOGY
# 513 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1
# 514 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 515 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 516 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 517 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2:
# 519 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2, speaker = SP_NAME_MRNIGHTOLOGY
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3:
# 522 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return


CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent::
# 530 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 531 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology::
# 536 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 537 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_MrNightology_1
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return

CollaboratorsRoom_EventScript_MrNightology_1:
# 538 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 539 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 540 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_MrNightology_6
# 545 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_MrNightology_7
CollaboratorsRoom_EventScript_MrNightology_4:
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_9
# 556 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle
CollaboratorsRoom_EventScript_MrNightology_8:
# 559 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 560 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_2
# 561 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_ON
# 562 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 563 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_3
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 568 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_WARP_OUT
# 569 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, 3
# 570 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	showobjectat LOCALID_COLLABORATORS_ROOM_REONEKY, MAP_COLLABORATORS_ROOM
# 572 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_REONEKY, DIR_SOUTH
# 573 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 574 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 575 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 576 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 577 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY
# 579 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 580 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_5
# 582 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 583 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 584 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_6
# 585 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 587 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 588 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 593 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, Common_Movement_VersusWithDelay48
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 596 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 597 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 598 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_MrNightology_Text_6
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 600 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 601 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 602 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_MrNightology_13
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 624 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 625 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 627 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, -3
# 629 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
CollaboratorsRoom_EventScript_MrNightology_12:
# 631 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_6:
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_0
# 543 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_7:
# 546 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_1
# 548 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_9:
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroRematch
	goto CollaboratorsRoom_EventScript_MrNightology_8

CollaboratorsRoom_EventScript_MrNightology_13:
# 603 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 604 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_Movement_MrNightology_Despegue
# 605 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_Movement_MrNightology_Despegue
# 606 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 607 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 608 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_7, MSGBOX_AUTOCLOSE_TOP
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FALL
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_7
# 611 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 612 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 613 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_8, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 615 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 616 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_8
# 617 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_9
# 619 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY
	goto CollaboratorsRoom_EventScript_MrNightology_12


# 637 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_Movement_MrNightology_Despegue:
# 638 "data/maps/CollaboratorsRoom/scripts.pory"
	face_left
# 639 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 640 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 641 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 642 "data/maps/CollaboratorsRoom/scripts.pory"
	face_right
# 643 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 644 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 646 "data/maps/CollaboratorsRoom/scripts.pory"
	step_end

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle::
# 650 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 652 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 653 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 654 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 655 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FaceAwayPlayer
# 656 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 659 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 660 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 661 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 662 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 663 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 664 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 665 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 666 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 667 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 668 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 669 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return


CollaboratorsRoom_EventScript_Gosuto_TalkOnly::
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 675 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 676 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 677 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 678 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 679 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 681 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 682 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 683 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 684 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 685 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gosuto_IntroRematch::
# 689 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 690 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 691 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GOSUTO
# 692 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0
# 693 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 694 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 695 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 696 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 697 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 698 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2
# 701 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 705 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2:
# 699 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3:
# 702 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return


CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent::
# 710 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 712 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gosuto::
# 717 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 718 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 719 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gosuto_1
# 749 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return

CollaboratorsRoom_EventScript_Gosuto_1:
# 720 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_5
# 723 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle
CollaboratorsRoom_EventScript_Gosuto_4:
# 725 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 726 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 727 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 728 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 729 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 730 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_Text_0
# 731 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 732 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 733 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 734 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gosuto_9
# 743 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 744 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 745 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
CollaboratorsRoom_EventScript_Gosuto_8:
# 747 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_5:
# 721 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroRematch
	goto CollaboratorsRoom_EventScript_Gosuto_4

CollaboratorsRoom_EventScript_Gosuto_9:
# 735 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 736 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 737 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 739 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 740 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 741 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO
	goto CollaboratorsRoom_EventScript_Gosuto_8


CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle::
# 755 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 756 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNote
# 757 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 759 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 60
# 760 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
	return


CollaboratorsRoom_EventScript_Acimut_TalkOnly::
# 765 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 768 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 769 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 770 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 771 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 772 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 773 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 774 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 775 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 776 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 777 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 778 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 779 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 780 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 781 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 782 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 783 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 784 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 785 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Acimut_IntroRematch::
# 801 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 802 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 803 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 804 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ACIMUT
# 805 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1
# 806 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 807 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 808 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 809 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 810 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 811 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Acimut_IntroRematch_2
# 814 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Acimut_IntroRematch_3
# 818 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 819 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 820 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_2:
# 812 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_3:
# 815 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 816 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return


CollaboratorsRoom_EventScript_Acimut_OnFinishEvent::
# 825 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 826 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 827 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Acimut::
# 832 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 833 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 834 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Acimut_1
# 868 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return

CollaboratorsRoom_EventScript_Acimut_1:
# 835 "data/maps/CollaboratorsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_COOL, FALSE
# 836 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT, CollaboratorsRoom_EventScript_Acimut_5
# 839 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle
CollaboratorsRoom_EventScript_Acimut_4:
# 841 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 842 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 843 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 844 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 845 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 846 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 847 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ACIMUT, CollaboratorsRoom_EventScript_Acimut_Text_0
# 848 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 849 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 850 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 851 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Acimut_9
# 860 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 861 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 862 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 863 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 864 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
CollaboratorsRoom_EventScript_Acimut_8:
# 866 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_5:
# 837 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroRematch
	goto CollaboratorsRoom_EventScript_Acimut_4

CollaboratorsRoom_EventScript_Acimut_9:
# 852 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 853 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 854 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 855 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 856 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 857 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 858 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT
	goto CollaboratorsRoom_EventScript_Acimut_8


CollaboratorsRoom_EventScript_Alexmad_LongIntro::
# 873 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 874 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 875 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 876 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 877 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 878 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_IdeaWithDelay48
# 879 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 880 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 881 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 882 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 883 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 884 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 885 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 886 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 888 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 889 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 890 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 891 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 892 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 893 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 894 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
	return


CollaboratorsRoom_EventScript_Alexmad_QRFlow::
# 899 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0, speaker = SP_NAME_ALEXMAD
# 900 "data/maps/CollaboratorsRoom/scripts.pory"
	load_field_pic FP_MAD_QR, 120, 80
# 901 "data/maps/CollaboratorsRoom/scripts.pory"
	waitbuttonpress
# 902 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 903 "data/maps/CollaboratorsRoom/scripts.pory"
	destroy_field_pic FP_MAD_QR
# 904 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
# 905 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 906 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_2
# 927 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_QRFlow_1:
# 929 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_QRFlow_2:
# 907 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 908 "data/maps/CollaboratorsRoom/scripts.pory"
	special EnterCode
# 909 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 910 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetCodeFeedback
# 911 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_5
# 921 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 922 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 923 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_AnnoyedWithDelay48
# 924 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow_1

CollaboratorsRoom_EventScript_Alexmad_QRFlow_5:
# 912 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 913 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_TEMP_ALEXMAD_PUZZLE_STARTED
# 914 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_FAILED
# 915 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_ALEXMAD_PUZZLE_CHECKPOINT, 0
# 916 "data/maps/CollaboratorsRoom/scripts.pory"
	getplayerxy VAR_ALEXMAD_PUZZLE_START_X, VAR_ALEXMAD_PUZZLE_START_Y
# 917 "data/maps/CollaboratorsRoom/scripts.pory"
	special InitAlexmadPuzzlePartyOrderCheck
# 918 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle::
# 933 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 934 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Alexmad_IntroRematch::
# 939 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 940 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 941 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ALEXMAD
# 942 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1
# 943 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 944 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 945 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 946 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 947 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 948 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2
# 951 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3
# 955 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 956 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2:
# 949 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3:
# 952 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 953 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Alexmad_DoBattle::
# 961 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 962 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 963 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_VersusWithDelay48
# 964 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 965 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 966 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ALEXMAD, CollaboratorsRoom_Text_Alexmad_OnDefeat
# 967 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 968 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 969 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 970 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_DoBattle_2
# 980 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 981 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 982 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 983 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 984 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_DoBattle_1:
# 986 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_DoBattle_2:
# 971 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 972 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_SurpriseWithDelay48
# 973 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 974 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 975 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 976 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 977 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 978 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle_1


CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent::
# 990 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 991 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 992 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad::
# 1001 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1002 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1003 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_TEMP_ALEXMAD_PUZZLE_STARTED, CollaboratorsRoom_EventScript_Alexmad_2
# 1007 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1008 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_5
CollaboratorsRoom_EventScript_Alexmad_4:
# 1011 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 1012 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1013 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 1014 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1015 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_Movement_0
# 1016 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1017 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 1018 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1019 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 0
# 1020 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_MET_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_8
CollaboratorsRoom_EventScript_Alexmad_7:
# 1026 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_10
# 1042 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_16
# 1070 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_28
# 1073 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_12, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_27:
# 1075 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1076 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_35
# 1079 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1080 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_2:
# 1004 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_0, MSGBOX_NPC, speaker = SP_NAME_ALEXMAD
	end

CollaboratorsRoom_EventScript_Alexmad_5:
# 1009 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_4

CollaboratorsRoom_EventScript_Alexmad_8:
# 1021 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 1
# 1022 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 1023 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_MET_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_7

CollaboratorsRoom_EventScript_Alexmad_10:
# 1027 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_13
# 1035 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1036 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1037 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 1038 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1039 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_13:
# 1028 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_20
# 1031 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
CollaboratorsRoom_EventScript_Alexmad_19:
# 1033 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_16:
# 1043 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_24
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1047 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1048 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_QuestionMark
# 1049 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1050 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 60
CollaboratorsRoom_EventScript_Alexmad_23:
# 1052 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_EventScript_Alexmad_Text_7, CollaboratorsRoom_EventScript_Alexmad_Text_8, CollaboratorsRoom_EventScript_Alexmad_Text_9
# 1053 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1054 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_32
# 1056 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_33
# 1066 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1067 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_20:
# 1029 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroRematch
	goto CollaboratorsRoom_EventScript_Alexmad_19

CollaboratorsRoom_EventScript_Alexmad_24:
# 1044 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_23

CollaboratorsRoom_EventScript_Alexmad_28:
# 1071 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_11, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_27

CollaboratorsRoom_EventScript_Alexmad_32:
# 1055 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_33:
# 1057 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_39
# 1060 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1061 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HappyWithDelay48
# 1062 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_38:
# 1064 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_35:
# 1077 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_39:
# 1058 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
	goto CollaboratorsRoom_EventScript_Alexmad_38


CollaboratorsRoom_EventScript_AlexmadPuzzleComplete::
# 1087 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1088 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FaceRight
# 1089 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1090 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_DoubleExclamationMark
# 1091 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1092 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0
# 1093 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1094 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1
# 1096 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_SUCCESS
# 1097 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1098 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1099 "data/maps/CollaboratorsRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 4, 4
# 1100 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1101 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 1102 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1103 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_COMPLETED
# 1104 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1105 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 1106 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_AlexmadPuzzleFailed::
# 1111 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1112 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FacePlayer
# 1113 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FAILURE
# 1114 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_XWithDelay48
# 1115 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1116 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 1117 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly::
# 1122 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1123 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1124 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1125 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1126 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1127 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1129 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1130 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 1131 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1132 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1133 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1134 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1135 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1136 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1137 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1138 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1139 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1140 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1141 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1142 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 1143 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle::
# 1147 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
	return


CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch::
# 1152 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1153 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1154 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1155 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1156 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1157 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1158 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1159 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_RYUZAKI
# 1160 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_2
# 1161 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 1162 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 1163 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1164 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1165 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1166 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_2
# 1169 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_3
# 1172 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1173 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1174 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1175 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_2:
# 1167 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
	return

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_3:
# 1170 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly
	return


CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent::
# 1180 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 1181 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 1182 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Ryuzaki::
# 1187 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1188 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 1189 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Ryuzaki_1
# 1223 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1224 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1225 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 1226 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1227 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1228 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1229 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1230 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1231 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1232 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly
	return

CollaboratorsRoom_EventScript_Ryuzaki_1:
# 1190 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI, CollaboratorsRoom_EventScript_Ryuzaki_5
# 1193 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle
CollaboratorsRoom_EventScript_Ryuzaki_4:
# 1195 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1196 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 1197 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 1198 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1199 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 1200 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_RYUZAKI, CollaboratorsRoom_Text_Ryuzaki_OnDefeat
# 1201 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 1202 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 1203 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 1204 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Ryuzaki_9
# 1212 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq CollaboratorsRoom_EventScript_Ryuzaki_10
# 1217 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1218 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1219 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
CollaboratorsRoom_EventScript_Ryuzaki_8:
# 1221 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Ryuzaki_5:
# 1191 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch
	goto CollaboratorsRoom_EventScript_Ryuzaki_4

CollaboratorsRoom_EventScript_Ryuzaki_9:
# 1205 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1206 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 1207 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1208 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1209 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1210 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1211 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI
	goto CollaboratorsRoom_EventScript_Ryuzaki_8

CollaboratorsRoom_EventScript_Ryuzaki_10:
# 1213 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1214 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1215 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
	goto CollaboratorsRoom_EventScript_Ryuzaki_8


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

# 306 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 331 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0:
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 485 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0:
# 485 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 489 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1:
# 489 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sweat_drop
	step_end

# 499 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0:
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sad
	step_end

# 503 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1:
# 503 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_annoyed
	step_end

# 542 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_0:
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_left
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 547 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_1:
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 560 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_2:
# 560 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 563 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_3:
# 563 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_up
	step_end

# 567 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_4:
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 581 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_5:
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
	step_end

# 584 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_6:
# 584 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
	step_end

# 610 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_7:
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
	step_end

# 616 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_8:
# 616 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_question_mark
	step_end

# 618 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_9:
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 1015 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Alexmad_Movement_0:
# 1015 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 1015 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 1015 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 1092 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0:
# 1092 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
	step_end

# 1094 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1:
# 1094 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
# 1094 "data/maps/CollaboratorsRoom/scripts.pory"
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
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
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
# 188 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_1:
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando te sientas preparad{OA}, vuelve y\n"
	.string "probamos nuestros equipos en un duelo.$"

CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0:
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0:
# 215 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1:
# 218 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si prestas atención.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0:
# 227 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1:
# 230 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres volver a luchar?$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2:
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3:
# 246 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

CollaboratorsRoom_EventScript_Erkey_Text_0:
# 275 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

CollaboratorsRoom_EventScript_Erkey_Text_1:
# 283 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

CollaboratorsRoom_EventScript_Erkey_Text_2:
# 286 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

CollaboratorsRoom_EventScript_Erkey_Text_3:
# 291 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0:
# 308 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres buen{OA} con los\n"
	.string "Pokémon que he criado y entrenado.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0:
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1:
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2:
# 322 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3:
# 325 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4:
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0:
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1:
# 344 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te atreves?$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2:
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0:
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Elige dos Pokémon para combatir. Yo\n"
	.string "escogeré uno de mis ejemplares al azar\l"
	.string "para enfrentaros.$"

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_1:
# 370 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"

CollaboratorsRoom_EventScript_Micolo_Text_0:
# 414 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

CollaboratorsRoom_EventScript_Micolo_Text_1:
# 424 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, me has ganado.$"

CollaboratorsRoom_EventScript_Micolo_Text_2:
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Admito que eres buen{OA}, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

CollaboratorsRoom_EventScript_Micolo_Text_3:
# 438 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

CollaboratorsRoom_EventScript_Lillipup_Text_0:
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pup, pup, pup.$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0:
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Buscas problemas?\n"
	.string "¡Pues escucha nuestro lema!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1:
# 487 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Uy, me he equivocado!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2:
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perdona, es la costumbre jeje…\p"
	.string "Bueno, por lo que veo has completado el\n"
	.string "desafío. ¡Enhorabuena!\p"
	.string "Pero… ¡será por poco tiempo!\n"
	.string "¡Ha llegado el momento de ponerte a\l"
	.string "prueba una vez más!$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0:
# 497 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ay, si te contase…\p"
	.string "La Beta 1 de mi hack la publiqué en 2010\n"
	.string "y 15 años después, conseguí acabarlo.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1:
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Una larga travesía para que al final, la\n"
	.string "gente te pregunte cuál es el cheat de\l"
	.string "los caramelos infinitos.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2:
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te parece normal?\n"
	.string "En fin… La vida del romhacker.$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0:
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tú otra vez!$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1:
# 513 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te has quedado con ganas de más?$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2:
# 519 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Já! Si ya me lo imaginaba…$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3:
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿No?\n"
	.string "Bueno… Ya volverás.$"

CollaboratorsRoom_EventScript_MrNightology_Text_0:
# 559 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo un plan genial para derrotarte y\n"
	.string "para eso lucharé con un amigo.\p"
	.string "Así que…\n"
	.string "¡Que aparezca el invitado especial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_1:
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Estás preparad{OA}?\n"
	.string "¿Sí? Genial.\p"
	.string "¡Vente p'acá!$"

CollaboratorsRoom_EventScript_MrNightology_Text_2:
# 583 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ostras!\n"
	.string "¿Cómo lo has hecho?$"

CollaboratorsRoom_EventScript_MrNightology_Text_3:
# 585 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Coño! Transmisión instantánea, bro.\n"
	.string "¡No me he pasado entrenando en el\l"
	.string "planeta Yardrat todo este tiempo pa ná!$"

CollaboratorsRoom_EventScript_MrNightology_Text_4:
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah, mira qué bien! ¡Eso me viene genial\n"
	.string "para que la próxima vez no acabe\l"
	.string "reventao con tantas horas de bus!$"

CollaboratorsRoom_EventScript_MrNightology_Text_5:
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sorprendido, ¿no?\n"
	.string "Pues ha llegado la hora…\p"
	.string "¡Prepárate para luchar!$"

CollaboratorsRoom_EventScript_MrNightology_Text_6:
# 598 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¡Pero si era un plan genial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_7:
# 608 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡El Team Rocket despega de nuevooooo…!$"

CollaboratorsRoom_EventScript_MrNightology_Text_8:
# 613 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya aterrizaje!$"

CollaboratorsRoom_EventScript_MrNightology_Text_9:
# 619 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Y ReoNeky?\n"
	.string "Espero que haya aterrizado en su sala.$"

CollaboratorsRoom_EventScript_MrNightology_Text_10:
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has hecho todo lo que has podido, pero\n"
	.string "no es suficiente.$"

CollaboratorsRoom_EventScript_MrNightology_Text_11:
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Dale una vuelta a tu estrategia y…\p"
	.string "¡No nos hagas esperar mucho para la\n"
	.string "revancha!$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0:
# 652 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Oh! Pues parece que has superado el\n"
	.string "desafío de las salas.\p"
	.string "¿Qué te parece si te ponemos a prueba y\n"
	.string "vemos de lo que eres capaz?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1:
# 654 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Hacemos esto un poco más divertido?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2:
# 660 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "O mejor dicho, ¿¡qué te parece si lo\n"
	.string "hacemos el doble de divertido!?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3:
# 669 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Muy bien, entra al mundo de las\n"
	.string "tinieblas conmigo…$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0:
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizás me conoces, quizás no, pero no te\n"
	.string "culpo; paso como una sombra entre las\l"
	.string "tinieblas.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1:
# 678 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero a pesar de permanecer entre las\n"
	.string "tinieblas, he aportado a grandes\l"
	.string "proyectos dando un pequeño grano de\l"
	.string "arena.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2:
# 682 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Que no se diga más y a seguir\n"
	.string "procesando píxeles!$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0:
# 692 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate? ¿Estás segur{OA} de estar\n"
	.string "list{OA} para entrar al mundo de las\l"
	.string "tinieblas?$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1:
# 699 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ok, veamos si esta vez logras superar\n"
	.string "tus miedos.$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2:
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien pensado; aunque puedes volver\n"
	.string "cuando quieras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_0:
# 730 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Creo que ya superaste tus miedos y\n"
	.string "superaste las sombras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_1:
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, parece que encontraste una\n"
	.string "chispa de suerte.\p"
	.string "Aprovecha esa luz mientras puedas,\n"
	.string "porque las sombras son pacientes y las\l"
	.string "tinieblas siempre terminan ganando al\l"
	.string "final.$"

CollaboratorsRoom_EventScript_Gosuto_Text_2:
# 743 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te sientas mal; no cualquiera\n"
	.string "sobrevive a mis tinieblas.$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0:
# 757 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espera! ¿Escuchas eso?$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1:
# 760 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Es el sonido de la batalla!$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0:
# 765 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un día empecé a descompilar Pokémon\n"
	.string "FireRed en español para obtener la ROM\l"
	.string "original compilando pokefirered.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1:
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tuvieron que pasar dos años para\n"
	.string "encontrar motivación en el desafío 30\l"
	.string "días dentro del foro de WaH.\p"
	.string "Durante ese tiempo logré hacer\n"
	.string "coincidencia al 100%.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2:
# 776 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Fue el mejor día de mi vida en el mundo\n"
	.string "del rom hacking, superando un reto\l"
	.string "personal muy significativo para mí.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3:
# 781 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Por cierto, aquí la música se escucha\n"
	.string "mejor en estéreo.$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0:
# 801 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La música son matemáticas y puro\n"
	.string "sentimiento ¡como los combates\l"
	.string "Pokémon!$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1:
# 805 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿List{OA} para la revancha?$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2:
# 819 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras. Aquí siempre hay\n"
	.string "buena música para combatir.$"

CollaboratorsRoom_EventScript_Acimut_Text_0:
# 847 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué ha pasado aquí?$"

CollaboratorsRoom_EventScript_Acimut_Text_1:
# 854 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ese último movimiento no lo vi venir…$"

CollaboratorsRoom_EventScript_Acimut_Text_2:
# 857 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Espero podamos volver a enfrentarnos\n"
	.string "en un futuro.$"

CollaboratorsRoom_EventScript_Acimut_Text_3:
# 860 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La armonía de tus Pokémon lo es todo…$"

CollaboratorsRoom_EventScript_Acimut_Text_4:
# 864 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si quieres volver a intentarlo, aquí\n"
	.string "estaré.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0:
# 873 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años… ¿te das cuenta?$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1:
# 875 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí crecimos entre bugs, tiles mal\n"
	.string "alineados y scripts que se colgaban en\l"
	.string "el último mapa.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2:
# 879 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah! Si ves a Baro por ahí… no intentes\n"
	.string "ser su amigo.\p"
	.string "Créeme, no termina bien.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3:
# 883 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Y si te topas con Serg!o… salúdalo con\n"
	.string "respeto.\p"
	.string "Es leyenda.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4:
# 886 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Todos le tenemos un cariño especial…\n"
	.string "Y no, no homo.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5:
# 889 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me encanta la playa, hacer mapas bien\n"
	.string "locos y meter bosques dentro de\l"
	.string "cuevas.\p"
	.string "Eso dice muchas cosas de mí.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6:
# 892 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Los hacks dicen muchas cosas de\n"
	.string "nosotros.\p"
	.string "Incluso en nuestra vida personal… nos\n"
	.string "hicieron mejores personas.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0:
# 899 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Escanea el QR con tu móvil y nos vemos\n"
	.string "en el otro mundo.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1:
# 904 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lo viste?$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2:
# 907 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces escribe la palabra que viste\n"
	.string "en el video.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3:
# 912 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto… Veo que sí lo viste.\p"
	.string "Entonces sabes lo que tienes que hacer.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4:
# 921 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No… Esa no es.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5:
# 924 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando tengas la respuesta\n"
	.string "correcta.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6:
# 927 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.$"

CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0:
# 933 "data/maps/CollaboratorsRoom/scripts.pory"
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
# 939 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Regresaste…\n"
	.string "Eso ya dice algo.\p"
	.string "En WAH aprendimos que rendirse no es\n"
	.string "una opción.\p"
	.string "Cada error es una versión nueva… cada\n"
	.string "derrota es un parche.\p"
	.string "Y cada parche nos hizo mejores.$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1:
# 942 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate?$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2:
# 955 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras volver, aquí estaré.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0:
# 973 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Excelente…\n"
	.string "Eres digno de estar aquí.\p"
	.string "Me alegra ver que la comunidad nunca\n"
	.string "dejó de ser la mejor.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1:
# 976 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hoy perdí yo…\n"
	.string "Pero quizás mañana podría ganar Samee.\p"
	.string "Nos veremos pronto.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2:
# 980 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veo que no siempre tener el mejor\n"
	.string "equipo es suficiente.\p"
	.string "La estrategia pesa más que pulsar A a lo\n"
	.string "loco.$"

CollaboratorsRoom_EventScript_Alexmad_Text_0:
# 1004 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que tienes que hacer, ¿no?$"

CollaboratorsRoom_EventScript_Alexmad_Text_1:
# 1009 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sm1, sm2 o…$"

CollaboratorsRoom_EventScript_Alexmad_Text_2:
# 1035 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya lo lograste.$"

CollaboratorsRoom_EventScript_Alexmad_Text_3:
# 1038 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER.\p"
	.string "Siempre fue bueno con los acertijos.\n"
	.string "Sigue adelante, seguro que te irá bien.$"

CollaboratorsRoom_EventScript_Alexmad_Text_4:
# 1044 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Pero también podemos ir directo a la\n"
	.string "batalla.\n"
	.string "¿Qué prefieres?$"

CollaboratorsRoom_EventScript_Alexmad_Text_5:
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tu de nuevo! Tengo dos propuestas\n"
	.string "para ti.$"

CollaboratorsRoom_EventScript_Alexmad_Text_6:
# 1049 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_7:
# 1052 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evento$"

CollaboratorsRoom_EventScript_Alexmad_Text_8:
# 1052 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Batalla$"

CollaboratorsRoom_EventScript_Alexmad_Text_9:
# 1052 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Salir$"

CollaboratorsRoom_EventScript_Alexmad_Text_10:
# 1062 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veamos qué versión eres ahora.$"

CollaboratorsRoom_EventScript_Alexmad_Text_11:
# 1071 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Dime… ¿lo quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_12:
# 1073 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has vuelto, ¿quieres seguir con el\n"
	.string "evento?$"

CollaboratorsRoom_EventScript_Alexmad_Text_13:
# 1079 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.\n"
	.string "El Mitic no espera… pero tampoco se\l"
	.string "repite.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0:
# 1097 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Lo has logrado! Veo que eres buen{OA}.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1:
# 1102 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER. Siempre fue bueno\n"
	.string "con los acertijos.\p"
	.string "Quizás pueda ayudarte en tu camino.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2:
# 1104 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "PENDIENTE PREMIO$"

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0:
# 1115 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, no… así no es.\p"
	.string "Vuelve a hablarme si quieres intentarlo\n"
	.string "de nuevo.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_0:
# 1122 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Mi nombre es El Gran Jefe Topo, quiero\n"
	.string "decir, Ryuzaki, aunque recientemente\l"
	.string "algunos desgraciados me están llamando\l"
	.string "Ryutopo para desprestigiarme…\p"
	.string "Y eso que mis animalines favoritos son\n"
	.string "las nutrias…$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_1:
# 1125 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero hay que admitir que es una\n"
	.string "conjugación bastante hilarante.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_2:
# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lees manga? ¡No me mientas! Sé que sí.\nEn todo caso, aún si no lo haces, hay\luno que me gustaría recomendarte.\pEs Tokyo Ghoul.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_3:
# 1132 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, entiendo esa cara de decepción, ¡no\n"
	.string "soy un adolescente emo en 2017!$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_4:
# 1135 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Su adaptación fue un relajo, pero no es\n"
	.string "la burla que probablemente imaginas.\p"
	.string "El manga trata las bifurcaciones de la\n"
	.string "introspectiva de sus personajes con\l"
	.string "tanto amor que resulta ser una\l"
	.string "experiencia preciosa.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_5:
# 1137 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te estoy desinformando, puedes\n"
	.string "confiar en mí.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_6:
# 1140 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es muy especial para mí… tenía que usar\n"
	.string "descaradamente mi influencia para\l"
	.string "darle visibilidad.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle_Text_0:
# 1147 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es hora de la violencia.\nTe mostraré La Verdad Divina.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_0:
# 1152 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Oh, hola. Tu ausencia me ha dado tiempo\n"
	.string "a componer un pequeño poema. Ten, te lo\l"
	.string "comparto.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_1:
# 1155 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "{FONT_SMALL}“¡Ay, langosta sucia!\nNo es solo cuestión de calandracas\lEs el naufragio del espíritu\lEn el Océano del Carajo”.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_2:
# 1160 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Profundo y seinen, ¿verdad? Bueno,\n"
	.string "seguramente no viniste a oírme hablar\l"
	.string "pinga… ¿Nos fajamos?$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_3:
# 1167 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prepárate para conocer la verdadera\n"
	.string "fuerza de la Jode Jode no Mi: Modelo\l"
	.string "Duende de La Buena Pipa.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_4:
# 1172 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Las moscas no pueden simplemente\n"
	.string "echarse gafas para ver La Luz.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_0:
# 1208 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me fumigaste. Te salvaste de que no\n"
	.string "estamos en territorio ryutámico.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_1:
# 1213 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Ah? ¿No íbamos a pelear? Veo que has\n"
	.string "perfeccionado tus habilidades\l"
	.string "desinformativas…$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_2:
# 1217 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres una burla, asere. Recoge tu baraja.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_3:
# 1223 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hola querid{OA} coyote. No esperaba verte\n"
	.string "por aquí.\p"
	.string "De hecho, no esperaba verme a mí mismo\n"
	.string "ni pinga.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_4:
# 1226 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La vida da más vueltas que una\n"
	.string "cantimplora, ¿verdad?$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_5:
# 1229 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¿Yo? Oh, no te preocupes, no soy\n"
	.string "nadie sospechoso.$"

CollaboratorsRoom_Text_Gameboycl_OnDefeat::
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

CollaboratorsRoom_RematchMultichoice_Rematch::
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Luchemos de nuevo!$"

CollaboratorsRoom_RematchMultichoice_TalkOnly::
# 792 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prefiero simplemente hablar.$"

CollaboratorsRoom_RematchMultichoice_Exit::
# 796 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, gracias.$"

CollaboratorsRoom_Text_Alexmad_OnDefeat::
# 996 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años de comunidad y aún me\n"
	.string "sorprenden.$"

CollaboratorsRoom_Text_Ryuzaki_OnDefeat::
# 1236 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que dicen, la voluntad es la\n"
	.string "fuerza del alma.$"
