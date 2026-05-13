CollaboratorsRoom_MapScripts::
	.byte 0


CollaboratorsRoom_EventScript_AfterBattleCollaborators::
# 17 "data/maps/CollaboratorsRoom/scripts.pory"
	special Special_UpdateCollaboratorsNoFaintProgress
# 18 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaboratorsNoFaints
# 19 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	return


CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle::
# 25 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 26 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 27 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 28 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 29 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 30 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_3
# 33 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_4
# 35 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_5
# 37 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_6
CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1:
	return

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_3:
# 32 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_4:
# 34 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_5:
# 36 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_6:
# 38 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1


CollaboratorsRoom_EventScript_Kaktus_TalkOnly::
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 45 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 46 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 48 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 49 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 50 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Kaktus_IntroRematch::
# 54 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 55 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 56 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_INMORTAL_KAKTUS
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1
# 58 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 59 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 60 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 61 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 62 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 63 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2
# 66 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3
# 69 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 70 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2:
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2, speaker = SP_NAME_INMORTAL_KAKTUS
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3:
# 67 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
	return


CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent::
# 75 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 76 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 77 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Kaktus::
# 82 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 83 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 84 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Kaktus_1
# 125 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
	return

CollaboratorsRoom_EventScript_Kaktus_1:
# 85 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_5
# 88 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle
CollaboratorsRoom_EventScript_Kaktus_4:
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 93 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 94 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 95 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 96 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_Text_0
# 97 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 98 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 99 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Kaktus_9
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 114 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 116 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 117 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 118 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
CollaboratorsRoom_EventScript_Kaktus_8:
# 121 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 0
# 122 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 123 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_5:
# 86 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroRematch
	goto CollaboratorsRoom_EventScript_Kaktus_4

CollaboratorsRoom_EventScript_Kaktus_9:
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 101 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 103 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 104 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 105 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 106 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 107 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 108 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 109 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 110 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 111 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS
	goto CollaboratorsRoom_EventScript_Kaktus_8


CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle::
# 130 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 131 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 132 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 133 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 135 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 136 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 137 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


CollaboratorsRoom_EventScript_Gameboycl_TalkOnly::
# 142 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 143 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 145 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 147 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 148 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gameboycl_IntroRematch::
# 152 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 153 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 154 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GAMEBOY_CL
# 155 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1
# 156 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 157 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 158 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 159 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 160 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 161 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2
# 164 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3
# 167 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 168 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2:
# 162 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3:
# 165 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
	return


CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent::
# 173 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 174 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 175 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gameboycl::
# 181 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 182 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 183 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gameboycl_1
# 220 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
	return

CollaboratorsRoom_EventScript_Gameboycl_1:
# 184 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL, CollaboratorsRoom_EventScript_Gameboycl_5
# 187 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle
CollaboratorsRoom_EventScript_Gameboycl_4:
# 189 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 190 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 191 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 192 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 193 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	random 3
# 195 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 196 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 197 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_10
# 199 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_11
# 201 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gameboycl_12
CollaboratorsRoom_EventScript_Gameboycl_8:
# 204 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 205 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 206 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_14
# 214 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
CollaboratorsRoom_EventScript_Gameboycl_13:
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 217 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 218 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_5:
# 185 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroRematch
	goto CollaboratorsRoom_EventScript_Gameboycl_4

CollaboratorsRoom_EventScript_Gameboycl_10:
# 198 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_11:
# 200 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_12:
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_14:
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 210 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 211 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 212 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL
	goto CollaboratorsRoom_EventScript_Gameboycl_13


CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle::
# 229 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 230 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 232 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Erkey_TalkOnly::
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 238 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 241 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 242 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 243 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Erkey_IntroRematch::
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 248 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 250 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 251 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ERKEY
# 252 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1
# 253 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 254 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 255 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 256 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 257 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 258 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Erkey_IntroRematch_2
# 265 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Erkey_IntroRematch_3
# 268 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 270 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_2:
# 259 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 260 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 261 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 262 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 263 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_3:
# 266 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return


CollaboratorsRoom_EventScript_Erkey_OnFinishEvent::
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 277 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 278 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Erkey::
# 283 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 285 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Erkey_1
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return

CollaboratorsRoom_EventScript_Erkey_1:
# 286 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY, CollaboratorsRoom_EventScript_Erkey_5
# 289 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle
CollaboratorsRoom_EventScript_Erkey_4:
# 291 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 293 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 294 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 295 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 296 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 297 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, CollaboratorsRoom_EventScript_Erkey_Text_0
# 298 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 299 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 300 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 301 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_9
# 312 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 313 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 314 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
CollaboratorsRoom_EventScript_Erkey_8:
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 2
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 318 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_5:
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroRematch
	goto CollaboratorsRoom_EventScript_Erkey_4

CollaboratorsRoom_EventScript_Erkey_9:
# 302 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 303 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 305 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 308 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 310 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY
	goto CollaboratorsRoom_EventScript_Erkey_8


CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle::
# 325 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 326 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 327 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 328 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 330 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit
	return


CollaboratorsRoom_EventScript_Micolo_TalkOnly::
# 338 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 339 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 340 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 343 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 344 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 347 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 349 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 350 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 352 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 353 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 355 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 357 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 358 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Micolo_IntroRematch::
# 362 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 365 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 366 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MICOLO
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1
# 368 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 369 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 370 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 371 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 372 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Micolo_IntroRematch_2
# 376 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Micolo_IntroRematch_3
# 379 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 380 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_2:
# 374 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_3:
# 377 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return


CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit::
# 385 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_DIFFICULTY
# 386 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_EASY, CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_3
# 389 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_NORMAL, CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_4
# 393 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1:
	return

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_3:
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_4:
# 390 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1


CollaboratorsRoom_EventScript_Micolo_OnFinishEvent::
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 401 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 402 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Micolo::
# 407 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 408 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 409 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Micolo_1
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return

CollaboratorsRoom_EventScript_Micolo_1:
# 410 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO, CollaboratorsRoom_EventScript_Micolo_5
# 413 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle
CollaboratorsRoom_EventScript_Micolo_4:
# 415 "data/maps/CollaboratorsRoom/scripts.pory"
	special SavePlayerParty
# 416 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 417 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 418 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_DIFFICULTY
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_EASY, CollaboratorsRoom_EventScript_Micolo_10
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_NORMAL, CollaboratorsRoom_EventScript_Micolo_11
# 426 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 1
CollaboratorsRoom_EventScript_Micolo_8:
# 429 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 430 "data/maps/CollaboratorsRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 431 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 433 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_14
# 441 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 442 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 443 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 444 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 445 "data/maps/CollaboratorsRoom/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 446 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 447 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, CollaboratorsRoom_EventScript_Micolo_Text_1
# 448 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 449 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 450 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 451 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_17
# 458 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 459 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 460 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 461 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 463 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 464 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
CollaboratorsRoom_EventScript_Micolo_16:
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 3
# 467 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 468 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_5:
# 411 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroRematch
	goto CollaboratorsRoom_EventScript_Micolo_4

CollaboratorsRoom_EventScript_Micolo_10:
# 420 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 2
	goto CollaboratorsRoom_EventScript_Micolo_8

CollaboratorsRoom_EventScript_Micolo_11:
# 423 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 2
	goto CollaboratorsRoom_EventScript_Micolo_8

CollaboratorsRoom_EventScript_Micolo_14:
# 434 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 436 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 437 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 438 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	end

CollaboratorsRoom_EventScript_Micolo_17:
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 455 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 456 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_16


CollaboratorsRoom_EventScript_Lillipup::
# 475 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 476 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 477 "data/maps/CollaboratorsRoom/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 479 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmoncry
# 480 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 481 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle::
# 488 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 489 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 490 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 492 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 493 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1
# 495 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_TalkOnly::
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 503 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 504 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 506 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 507 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1
# 509 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 511 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return


CollaboratorsRoom_EventScript_MrNightology_IntroRematch::
# 515 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 516 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 517 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MRNIGHTOLOGY
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1
# 519 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 522 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2
# 526 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 530 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2:
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2, speaker = SP_NAME_MRNIGHTOLOGY
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3:
# 527 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return


CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent::
# 535 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 536 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology::
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_MrNightology_1
# 639 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return

CollaboratorsRoom_EventScript_MrNightology_1:
# 543 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 544 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 545 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_MrNightology_6
# 550 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_MrNightology_7
CollaboratorsRoom_EventScript_MrNightology_4:
# 557 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_9
# 561 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle
CollaboratorsRoom_EventScript_MrNightology_8:
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_2
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_ON
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 568 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_3
# 569 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 570 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 572 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 573 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_WARP_OUT
# 574 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 11, 3
# 575 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY_TELEPORTING_1
# 576 "data/maps/CollaboratorsRoom/scripts.pory"
	showobjectat LOCALID_COLLABORATORS_ROOM_REONEKY, MAP_COLLABORATORS_ROOM
# 577 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_REONEKY, DIR_SOUTH
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 579 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 580 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY_TELEPORTING_2
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 582 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 583 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY
# 584 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 585 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_5
# 587 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 588 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_6
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 593 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 596 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 597 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 598 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, Common_Movement_VersusWithDelay48
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 600 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 601 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 602 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 603 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_COLLABORATOR_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Text_6, TRAINER_WAH_COLLABORATOR_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Text_7
# 604 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 605 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 606 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_MrNightology_13
# 627 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 629 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 630 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 631 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 632 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 11, -3
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
CollaboratorsRoom_EventScript_MrNightology_12:
# 635 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 4
# 636 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 637 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_6:
# 546 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_0
# 548 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_7:
# 551 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_1
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_9:
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroRematch
	goto CollaboratorsRoom_EventScript_MrNightology_8

CollaboratorsRoom_EventScript_MrNightology_13:
# 607 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 608 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_Movement_MrNightology_Despegue
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_Movement_MrNightology_Despegue
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 611 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 612 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_8, MSGBOX_AUTOCLOSE_TOP
# 613 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FALL
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_7
# 615 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 616 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 617 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_9, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 619 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_8
# 621 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_9
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 624 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY
	goto CollaboratorsRoom_EventScript_MrNightology_12


# 643 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_Movement_MrNightology_Despegue:
# 644 "data/maps/CollaboratorsRoom/scripts.pory"
	face_left
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 646 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 647 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 648 "data/maps/CollaboratorsRoom/scripts.pory"
	face_right
# 649 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 650 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 652 "data/maps/CollaboratorsRoom/scripts.pory"
	step_end

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle::
# 656 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 659 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 660 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 661 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FaceAwayPlayer
# 662 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 663 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 664 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 665 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 666 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 667 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 668 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 669 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 670 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 671 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 672 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 673 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 675 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return


CollaboratorsRoom_EventScript_Gosuto_TalkOnly::
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 681 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 682 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 683 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 684 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 685 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 686 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 687 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 688 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 689 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 690 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 691 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gosuto_IntroRematch::
# 695 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 696 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 697 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GOSUTO
# 698 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0
# 699 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 700 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 701 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 702 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 703 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2
# 707 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3
# 710 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2:
# 705 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3:
# 708 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return


CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent::
# 716 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 717 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 718 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gosuto::
# 723 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 724 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 725 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gosuto_1
# 756 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return

CollaboratorsRoom_EventScript_Gosuto_1:
# 726 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_5
# 729 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle
CollaboratorsRoom_EventScript_Gosuto_4:
# 731 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 732 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 733 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 734 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 735 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 736 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_Text_0
# 737 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 739 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gosuto_9
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 749 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 750 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
CollaboratorsRoom_EventScript_Gosuto_8:
# 752 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 5
# 753 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 754 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_5:
# 727 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroRematch
	goto CollaboratorsRoom_EventScript_Gosuto_4

CollaboratorsRoom_EventScript_Gosuto_9:
# 740 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 741 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 742 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 743 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 744 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 745 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 746 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO
	goto CollaboratorsRoom_EventScript_Gosuto_8


CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle::
# 762 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 763 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNote
# 764 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 765 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Movement_0
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
	return


CollaboratorsRoom_EventScript_Acimut_TalkOnly::
# 772 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 773 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 774 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 775 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 776 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 777 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 778 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 779 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 780 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 781 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 782 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 783 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 784 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 785 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 786 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 787 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 789 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 790 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 791 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 792 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Acimut_IntroRematch::
# 808 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 809 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 810 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 811 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ACIMUT
# 812 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1
# 813 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 814 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 815 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 816 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 817 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 818 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Acimut_IntroRematch_2
# 821 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Acimut_IntroRematch_3
# 825 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 826 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 827 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_2:
# 819 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_3:
# 822 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 823 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return


CollaboratorsRoom_EventScript_Acimut_OnFinishEvent::
# 832 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 833 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 834 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Acimut::
# 839 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 840 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 841 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Acimut_1
# 876 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return

CollaboratorsRoom_EventScript_Acimut_1:
# 842 "data/maps/CollaboratorsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_COOL, FALSE
# 843 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT, CollaboratorsRoom_EventScript_Acimut_5
# 846 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle
CollaboratorsRoom_EventScript_Acimut_4:
# 848 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 849 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 850 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 851 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 852 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 853 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 854 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ACIMUT, CollaboratorsRoom_EventScript_Acimut_Text_0
# 855 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 856 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 857 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Acimut_9
# 866 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 867 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 868 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 869 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 870 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
CollaboratorsRoom_EventScript_Acimut_8:
# 872 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 6
# 873 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 874 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_5:
# 844 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroRematch
	goto CollaboratorsRoom_EventScript_Acimut_4

CollaboratorsRoom_EventScript_Acimut_9:
# 858 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 859 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 860 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 861 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 862 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 863 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 864 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT
	goto CollaboratorsRoom_EventScript_Acimut_8


CollaboratorsRoom_EventScript_Alexmad_LongIntro::
# 881 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 882 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 883 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 884 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 885 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 886 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_IdeaWithDelay48
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 888 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 889 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 890 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 891 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 892 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 893 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 894 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 895 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 896 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 897 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 898 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 899 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 900 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 901 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 902 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
	return


CollaboratorsRoom_EventScript_Alexmad_QRFlow::
# 907 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0, speaker = SP_NAME_ALEXMAD
# 908 "data/maps/CollaboratorsRoom/scripts.pory"
	load_field_pic FP_MAD_QR, 120, 80
# 909 "data/maps/CollaboratorsRoom/scripts.pory"
	waitbuttonpress
# 910 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 911 "data/maps/CollaboratorsRoom/scripts.pory"
	destroy_field_pic FP_MAD_QR
# 912 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
# 913 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 914 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_2
# 935 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_QRFlow_1:
# 937 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_QRFlow_2:
# 915 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 916 "data/maps/CollaboratorsRoom/scripts.pory"
	special EnterCode
# 917 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 918 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetCodeFeedback
# 919 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_5
# 929 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 930 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 931 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_AnnoyedWithDelay48
# 932 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow_1

CollaboratorsRoom_EventScript_Alexmad_QRFlow_5:
# 920 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 921 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_TEMP_ALEXMAD_PUZZLE_STARTED
# 922 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_FAILED
# 923 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_ALEXMAD_PUZZLE_CHECKPOINT, 0
# 924 "data/maps/CollaboratorsRoom/scripts.pory"
	getplayerxy VAR_ALEXMAD_PUZZLE_START_X, VAR_ALEXMAD_PUZZLE_START_Y
# 925 "data/maps/CollaboratorsRoom/scripts.pory"
	special InitAlexmadPuzzlePartyOrderCheck
# 926 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle::
# 941 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 942 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Alexmad_IntroRematch::
# 947 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 948 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 949 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ALEXMAD
# 950 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1
# 951 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 952 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 953 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 954 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 955 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 956 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2
# 959 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3
# 963 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 964 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2:
# 957 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3:
# 960 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 961 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Alexmad_DoBattle::
# 969 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 970 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 971 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_VersusWithDelay48
# 972 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 973 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 974 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ALEXMAD, CollaboratorsRoom_Text_Alexmad_OnDefeat
# 975 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 976 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 977 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_DoBattle_2
# 987 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 988 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 989 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 990 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 991 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_DoBattle_1:
# 993 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 7
# 994 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 995 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_DoBattle_2:
# 978 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 979 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_SurpriseWithDelay48
# 980 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 981 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 982 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 983 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 984 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 985 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle_1


CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent::
# 999 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 1000 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 1001 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad::
# 1010 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1011 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1012 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_TEMP_ALEXMAD_PUZZLE_STARTED, CollaboratorsRoom_EventScript_Alexmad_2
# 1016 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1017 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_5
CollaboratorsRoom_EventScript_Alexmad_4:
# 1020 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 1021 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1022 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 1023 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1024 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_Movement_0
# 1026 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1027 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1028 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 1029 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1030 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 0
# 1031 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_MET_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_8
CollaboratorsRoom_EventScript_Alexmad_7:
# 1037 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_10
# 1053 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_16
# 1081 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_28
# 1084 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_12, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_27:
# 1086 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1087 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_35
# 1090 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1091 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_2:
# 1013 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_0, MSGBOX_NPC, speaker = SP_NAME_ALEXMAD
	end

CollaboratorsRoom_EventScript_Alexmad_5:
# 1018 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_4

CollaboratorsRoom_EventScript_Alexmad_8:
# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 1
# 1033 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 1034 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_MET_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_7

CollaboratorsRoom_EventScript_Alexmad_10:
# 1038 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_13
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1047 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1048 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 1049 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1050 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_13:
# 1039 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_20
# 1042 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
CollaboratorsRoom_EventScript_Alexmad_19:
# 1044 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_16:
# 1054 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_24
# 1057 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1058 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1059 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_QuestionMark
# 1060 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1061 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 60
CollaboratorsRoom_EventScript_Alexmad_23:
# 1063 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_EventScript_Alexmad_Text_7, CollaboratorsRoom_EventScript_Alexmad_Text_8, CollaboratorsRoom_EventScript_Alexmad_Text_9
# 1064 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1065 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_32
# 1067 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_33
# 1077 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1078 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_20:
# 1040 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroRematch
	goto CollaboratorsRoom_EventScript_Alexmad_19

CollaboratorsRoom_EventScript_Alexmad_24:
# 1055 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_23

CollaboratorsRoom_EventScript_Alexmad_28:
# 1082 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_11, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_27

CollaboratorsRoom_EventScript_Alexmad_32:
# 1066 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_33:
# 1068 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_39
# 1071 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1072 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HappyWithDelay48
# 1073 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_38:
# 1075 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_35:
# 1088 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_39:
# 1069 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
	goto CollaboratorsRoom_EventScript_Alexmad_38


CollaboratorsRoom_EventScript_AlexmadPuzzleComplete::
# 1098 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1099 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FaceRight
# 1100 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1101 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_DoubleExclamationMark
# 1102 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1103 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1104 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0
# 1105 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1106 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1107 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1
# 1108 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1109 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_SUCCESS
# 1110 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1111 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1112 "data/maps/CollaboratorsRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 5, 3
# 1113 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1114 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 1115 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1116 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1117 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1118 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1119 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1120 "data/maps/CollaboratorsRoom/scripts.pory"
	giveitem ITEM_TERA_ORB
# 1121 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_TERA_ORB_CHARGED
# 1122 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_TERA_ORB_NO_COST
# 1123 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer
# 1124 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1125 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1126 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_GIVE_LEGENDARIES
# 1127 "data/maps/CollaboratorsRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1129 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1130 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1131 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1132 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1133 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1134 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_GIVE_CLONES
# 1135 "data/maps/CollaboratorsRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
# 1136 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1137 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1138 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1139 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 1140 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1141 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FaceAwayPlayer
# 1142 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1143 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1144 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1145 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1146 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1147 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer
# 1148 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1149 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_COMPLETED
# 1150 "data/maps/CollaboratorsRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
# 1151 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer
# 1152 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1153 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer::
# 1157 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 1158 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1159 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_3
# 1162 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_4
# 1165 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_5
# 1168 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_3:
# 1160 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_4:
# 1163 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_5:
# 1166 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_6:
# 1169 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1


CollaboratorsRoom_EventScript_AlexmadPuzzleFailed::
# 1176 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1177 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FacePlayer
# 1178 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FAILURE
# 1179 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_XWithDelay48
# 1180 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1181 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly::
# 1185 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1186 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1187 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1188 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1189 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1190 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1191 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1192 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1193 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 1194 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1195 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1196 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1197 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1198 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1199 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1200 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1201 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1202 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1203 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1204 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1205 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 1206 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle::
# 1210 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
	return


CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch::
# 1215 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1216 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1217 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1218 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1219 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1220 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1221 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1222 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_RYUZAKI
# 1223 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_2
# 1224 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 1225 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 1226 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1227 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1228 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1229 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_2
# 1232 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_3
# 1235 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1236 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1237 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1238 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_2:
# 1230 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
	return

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_3:
# 1233 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly
	return


CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent::
# 1243 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 1244 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 1245 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Ryuzaki::
# 1250 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1251 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 1252 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Ryuzaki_1
# 1287 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1288 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1289 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 1290 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1291 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1292 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1293 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1294 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1295 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1296 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly
	return

CollaboratorsRoom_EventScript_Ryuzaki_1:
# 1253 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI, CollaboratorsRoom_EventScript_Ryuzaki_5
# 1256 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle
CollaboratorsRoom_EventScript_Ryuzaki_4:
# 1258 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1259 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 1260 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 1261 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1262 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 1263 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_RYUZAKI, CollaboratorsRoom_Text_Ryuzaki_OnDefeat
# 1264 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 1265 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 1266 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Ryuzaki_9
# 1274 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq CollaboratorsRoom_EventScript_Ryuzaki_10
# 1279 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1280 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1281 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
CollaboratorsRoom_EventScript_Ryuzaki_8:
# 1283 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 8
# 1284 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 1285 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Ryuzaki_5:
# 1254 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch
	goto CollaboratorsRoom_EventScript_Ryuzaki_4

CollaboratorsRoom_EventScript_Ryuzaki_9:
# 1267 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1268 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 1269 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1270 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1271 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1272 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1273 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI
	goto CollaboratorsRoom_EventScript_Ryuzaki_8

CollaboratorsRoom_EventScript_Ryuzaki_10:
# 1275 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1276 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1277 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
	goto CollaboratorsRoom_EventScript_Ryuzaki_8


# 115 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_0:
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 117 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_1:
# 117 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 117 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 117 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 329 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 354 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0:
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 490 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0:
# 490 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 494 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1:
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sweat_drop
	step_end

# 504 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0:
# 504 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sad
	step_end

# 508 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1:
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_annoyed
	step_end

# 547 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_0:
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_left
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 552 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_1:
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 565 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_2:
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 568 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_3:
# 568 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_up
	step_end

# 572 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_4:
# 572 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 586 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_5:
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
	step_end

# 589 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_6:
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
	step_end

# 614 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_7:
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
	step_end

# 620 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_8:
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_question_mark
	step_end

# 622 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_9:
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 766 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Movement_0:
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Alexmad_Movement_0:
# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 1104 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0:
# 1104 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
	step_end

# 1107 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1:
# 1107 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
# 1107 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_0:
# 25 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, vaya…\n¿Así que completaste el desafío?$"

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_1:
# 28 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces ya no eres un{A} novat{OA}. Veamos si\n"
	.string "sabes aplicar lo aprendido.\p"
	.string "Un combate, sin atajos, sin trucos.\n"
	.string "¿List{OA}?$"

CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_0:
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_1:
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0:
# 54 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ey, ¿qué tal? Mi Ludicolo sigue con\n"
	.string "ganas de bailar.$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1:
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro asalto?$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2:
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vamos!$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3:
# 69 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Será en otra oportunidad entonces!$"

CollaboratorsRoom_EventScript_Kaktus_Text_0:
# 96 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Acaso perdí?$"

CollaboratorsRoom_EventScript_Kaktus_Text_1:
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ja… perdí.$"

CollaboratorsRoom_EventScript_Kaktus_Text_2:
# 106 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

CollaboratorsRoom_EventScript_Kaktus_Text_3:
# 110 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Enhorabuena, crack.$"

CollaboratorsRoom_EventScript_Kaktus_Text_4:
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

CollaboratorsRoom_EventScript_Kaktus_Text_5:
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espero la revancha pronto!$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 131 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No soy competitivo ni ambicioso.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Soy más bien una persona mediocre.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_2:
# 137 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso puede jugarme en contra.$"

CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_0:
# 142 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un hack rom es como la arquitectura,\nse construye sobre lo existente.$"

CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_1:
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El arte aquí no es lo que se cambia,\nsino lo que se quiere transmitir.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0:
# 152 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1:
# 155 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2:
# 167 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_0:
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_1:
# 214 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando te sientas preparad{OA}, vuelve y\n"
	.string "probamos nuestros equipos en un duelo.$"

CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0:
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0:
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1:
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si prestas atención.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0:
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1:
# 252 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres volver a luchar?$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2:
# 259 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3:
# 268 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

CollaboratorsRoom_EventScript_Erkey_Text_0:
# 297 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

CollaboratorsRoom_EventScript_Erkey_Text_1:
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

CollaboratorsRoom_EventScript_Erkey_Text_2:
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

CollaboratorsRoom_EventScript_Erkey_Text_3:
# 312 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0:
# 331 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres buen{OA} con los\n"
	.string "Pokémon que he criado y entrenado.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0:
# 339 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1:
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2:
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3:
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4:
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0:
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1:
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te atreves?$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2:
# 379 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0:
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Elige dos Pokémon para combatir. Yo\n"
	.string "escogeré uno de mis ejemplares al azar\l"
	.string "para enfrentaros.$"

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_1:
# 393 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"

CollaboratorsRoom_EventScript_Micolo_Text_0:
# 437 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

CollaboratorsRoom_EventScript_Micolo_Text_1:
# 447 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, me has ganado.$"

CollaboratorsRoom_EventScript_Micolo_Text_2:
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Admito que eres buen{OA}, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

CollaboratorsRoom_EventScript_Micolo_Text_3:
# 460 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

CollaboratorsRoom_EventScript_Lillipup_Text_0:
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pup, pup, pup.$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0:
# 488 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Buscas problemas?\n"
	.string "¡Pues escucha nuestro lema!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1:
# 492 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Uy, me he equivocado!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2:
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perdona, es la costumbre jeje…\p"
	.string "Bueno, por lo que veo has completado el\n"
	.string "desafío. ¡Enhorabuena!\p"
	.string "Pero… ¡será por poco tiempo!\n"
	.string "¡Ha llegado el momento de ponerte a\l"
	.string "prueba una vez más!$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0:
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ay, si te contase…\p"
	.string "La Beta 1 de mi hack la publiqué en 2010\n"
	.string "y 15 años después, conseguí acabarlo.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1:
# 506 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Una larga travesía para que al final, la\n"
	.string "gente te pregunte cuál es el cheat de\l"
	.string "los caramelos infinitos.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2:
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te parece normal?\n"
	.string "En fin… La vida del romhacker.$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0:
# 515 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tú otra vez!$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1:
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te has quedado con ganas de más?$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2:
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Já! Si ya me lo imaginaba…$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3:
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿No?\n"
	.string "Bueno… Ya volverás.$"

CollaboratorsRoom_EventScript_MrNightology_Text_0:
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo un plan genial para derrotarte y\n"
	.string "para eso lucharé con un amigo.\p"
	.string "Así que…\n"
	.string "¡Que aparezca el invitado especial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_1:
# 569 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Estás preparado?\n"
	.string "¿Sí? Genial.\p"
	.string "¡Vente p'acá!$"

CollaboratorsRoom_EventScript_MrNightology_Text_2:
# 588 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ostras!\n"
	.string "¿Cómo lo has hecho?$"

CollaboratorsRoom_EventScript_MrNightology_Text_3:
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Coño! Transmisión instantánea, bro.\n"
	.string "¡No me he pasado entrenando en el\l"
	.string "planeta Yardrat todo este tiempo pa ná!$"

CollaboratorsRoom_EventScript_MrNightology_Text_4:
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah, mira qué bien! ¡Eso me viene genial\n"
	.string "para que la próxima vez no acabe\l"
	.string "reventao con tantas horas de bus!$"

CollaboratorsRoom_EventScript_MrNightology_Text_5:
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sorprendido, ¿no?\n"
	.string "Pues ha llegado la hora…\p"
	.string "¡Prepárate para luchar!$"

CollaboratorsRoom_EventScript_MrNightology_Text_6:
# 603 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¡Pero si era un plan genial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_7:
# 603 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿He vuelto a perder?$"

CollaboratorsRoom_EventScript_MrNightology_Text_8:
# 612 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡El Team Rocket despega de nuevooooo…!$"

CollaboratorsRoom_EventScript_MrNightology_Text_9:
# 617 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya aterrizaje!$"

CollaboratorsRoom_EventScript_MrNightology_Text_10:
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Y ReoNeky?\n"
	.string "Espero que haya aterrizado en su sala.$"

CollaboratorsRoom_EventScript_MrNightology_Text_11:
# 627 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has hecho todo lo que has podido, pero\n"
	.string "no es suficiente.$"

CollaboratorsRoom_EventScript_MrNightology_Text_12:
# 630 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Dale una vuelta a tu estrategia y…\p"
	.string "¡No nos hagas esperar mucho para la\n"
	.string "revancha!$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0:
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Oh! Pues parece que has superado el\n"
	.string "desafío de las salas.\p"
	.string "¿Qué te parece si te ponemos a prueba y\n"
	.string "vemos de lo que eres capaz?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1:
# 660 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Hacemos esto un poco más divertido?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2:
# 666 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "O mejor dicho, ¿¡qué te parece si lo\n"
	.string "hacemos el doble de divertido!?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3:
# 675 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Muy bien, entra al mundo de las\n"
	.string "tinieblas conmigo…$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0:
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizás me conoces, quizás no, pero no te\n"
	.string "culpo; paso como una sombra entre las\l"
	.string "tinieblas.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1:
# 684 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero a pesar de permanecer entre las\n"
	.string "tinieblas, he aportado a grandes\l"
	.string "proyectos dando un pequeño grano de\l"
	.string "arena.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2:
# 688 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Que no se diga más y a seguir\n"
	.string "procesando píxeles!$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0:
# 698 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate? ¿Estás segur{OA} de estar\n"
	.string "list{OA} para entrar al mundo de las\l"
	.string "tinieblas?$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1:
# 705 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ok, veamos si esta vez logras superar\n"
	.string "tus miedos.$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2:
# 710 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien pensado; aunque puedes volver\n"
	.string "cuando quieras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_0:
# 736 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Creo que ya superaste tus miedos y\n"
	.string "superaste las sombras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_1:
# 743 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, parece que encontraste una\n"
	.string "chispa de suerte.\p"
	.string "Aprovecha esa luz mientras puedas,\n"
	.string "porque las sombras son pacientes y las\l"
	.string "tinieblas siempre terminan ganando al\l"
	.string "final.$"

CollaboratorsRoom_EventScript_Gosuto_Text_2:
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te sientas mal; no cualquiera\n"
	.string "sobrevive a mis tinieblas.$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0:
# 764 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espera! ¿Escuchas eso?$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1:
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Es el sonido de la batalla!$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0:
# 772 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un día empecé a descompilar Pokémon\n"
	.string "FireRed en español para obtener la ROM\l"
	.string "original compilando pokefirered.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1:
# 774 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tuvieron que pasar dos años para\n"
	.string "encontrar motivación en el desafío 30\l"
	.string "días dentro del foro de WaH.\p"
	.string "Durante ese tiempo logré hacer\n"
	.string "coincidencia al 100%.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2:
# 783 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Fue el mejor día de mi vida en el mundo\n"
	.string "del rom hacking, superando un reto\l"
	.string "personal muy significativo para mí.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3:
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Por cierto, aquí la música se escucha\n"
	.string "mejor en estéreo.$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0:
# 808 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La música son matemáticas y puro\n"
	.string "sentimiento ¡como los combates\l"
	.string "Pokémon!$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1:
# 812 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿List{OA} para la revancha?$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2:
# 826 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras. Aquí siempre hay\n"
	.string "buena música para combatir.$"

CollaboratorsRoom_EventScript_Acimut_Text_0:
# 854 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué ha pasado aquí?$"

CollaboratorsRoom_EventScript_Acimut_Text_1:
# 860 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ese último movimiento no lo vi venir…$"

CollaboratorsRoom_EventScript_Acimut_Text_2:
# 863 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Espero podamos volver a enfrentarnos\n"
	.string "en un futuro.$"

CollaboratorsRoom_EventScript_Acimut_Text_3:
# 866 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La armonía de tus Pokémon lo es todo…$"

CollaboratorsRoom_EventScript_Acimut_Text_4:
# 870 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si quieres volver a intentarlo, aquí\n"
	.string "estaré.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0:
# 881 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años… ¿te das cuenta?$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1:
# 883 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí crecimos entre bugs, tiles mal\n"
	.string "alineados y scripts que se colgaban en\l"
	.string "el último mapa.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2:
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah! Si ves a Baro por ahí… no intentes\n"
	.string "ser su amigo.\p"
	.string "Créeme, no termina bien.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3:
# 891 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Y si te topas con Serg!o… salúdalo con\n"
	.string "respeto.\p"
	.string "Es leyenda.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4:
# 894 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Todos le tenemos un cariño especial…\n"
	.string "Y no, no homo.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5:
# 897 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me encanta la playa, hacer mapas bien\n"
	.string "locos y meter bosques dentro de\l"
	.string "cuevas.\p"
	.string "Eso dice muchas cosas de mí.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6:
# 900 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Los hacks dicen muchas cosas de\n"
	.string "nosotros.\p"
	.string "Incluso en nuestra vida personal… nos\n"
	.string "hicieron mejores personas.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0:
# 907 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Escanea el QR con tu móvil y nos vemos\n"
	.string "en el otro mundo.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1:
# 912 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lo viste?$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2:
# 915 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces escribe la palabra que viste\n"
	.string "en el video.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3:
# 920 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto… Veo que sí lo viste.\p"
	.string "Entonces sabes lo que tienes que hacer.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4:
# 929 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No… Esa no es.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5:
# 932 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando tengas la respuesta\n"
	.string "correcta.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6:
# 935 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.$"

CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0:
# 941 "data/maps/CollaboratorsRoom/scripts.pory"
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
# 947 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Regresaste…\n"
	.string "Eso ya dice algo.\p"
	.string "En WAH aprendimos que rendirse no es\n"
	.string "una opción.\p"
	.string "Cada error es una versión nueva… cada\n"
	.string "derrota es un parche.\p"
	.string "Y cada parche nos hizo mejores.$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1:
# 950 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate?$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2:
# 963 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras volver, aquí estaré.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0:
# 980 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Excelente…\n"
	.string "Eres digno de estar aquí.\p"
	.string "Me alegra ver que la comunidad nunca\n"
	.string "dejó de ser la mejor.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1:
# 983 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hoy perdí yo…\n"
	.string "Pero quizás mañana podría ganar Samee.\p"
	.string "Nos veremos pronto.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2:
# 987 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veo que no siempre tener el mejor\n"
	.string "equipo es suficiente.\p"
	.string "La estrategia pesa más que pulsar A a lo\n"
	.string "loco.$"

CollaboratorsRoom_EventScript_Alexmad_Text_0:
# 1013 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que tienes que hacer, ¿no?$"

CollaboratorsRoom_EventScript_Alexmad_Text_1:
# 1018 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sm1, sm2 o…$"

CollaboratorsRoom_EventScript_Alexmad_Text_2:
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya lo lograste.$"

CollaboratorsRoom_EventScript_Alexmad_Text_3:
# 1049 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER.\p"
	.string "Siempre fue bueno con los acertijos.\n"
	.string "Sigue adelante, seguro que te irá bien.$"

CollaboratorsRoom_EventScript_Alexmad_Text_4:
# 1055 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Pero también podemos ir directo a la\n"
	.string "batalla.\n"
	.string "¿Qué prefieres?$"

CollaboratorsRoom_EventScript_Alexmad_Text_5:
# 1057 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tu de nuevo! Tengo dos propuestas\n"
	.string "para ti.$"

CollaboratorsRoom_EventScript_Alexmad_Text_6:
# 1060 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_7:
# 1063 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evento$"

CollaboratorsRoom_EventScript_Alexmad_Text_8:
# 1063 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Batalla$"

CollaboratorsRoom_EventScript_Alexmad_Text_9:
# 1063 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Salir$"

CollaboratorsRoom_EventScript_Alexmad_Text_10:
# 1073 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veamos qué versión eres ahora.$"

CollaboratorsRoom_EventScript_Alexmad_Text_11:
# 1082 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Dime… ¿lo quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_12:
# 1084 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has vuelto, ¿quieres seguir con el\n"
	.string "evento?$"

CollaboratorsRoom_EventScript_Alexmad_Text_13:
# 1090 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.\n"
	.string "El Mitic no espera… pero tampoco se\l"
	.string "repite.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0:
# 1110 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Lo has logrado! Veo que eres buen{OA}.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1:
# 1115 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER. Siempre fue bueno\n"
	.string "con los acertijos.\p"
	.string "Quizás pueda ayudarte en tu camino.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2:
# 1118 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Toma este objeto.\nNo entiendo bien qué hace, pero\lseguro te será útil.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_3:
# 1124 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Además, ahora podrás encontrar en la PC\n"
	.string "a algunos legendarios de la Isla Mítica.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_4:
# 1129 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizá puedas reemplazar a alguno de tus\n"
	.string "Pokémon con uno de ellos.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_5:
# 1132 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Conoces el poder de los clones?\n"
	.string "Ahora podrás vivirlo en carne propia.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_6:
# 1137 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Estos clones son mucho más fuertes que\n"
	.string "los Pokémon originales.\p"
	.string "Úsalos sabiamente.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_7:
# 1148 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También te daré acceso a este Pokémon\n"
	.string "muy especial.\p"
	.string "Es una herramienta de combate muy\n"
	.string "codiciada.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_8:
# 1152 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "KODER hubiera sonreído al verte salir\n"
	.string "de aquí con tantas cartas en la manga.\p"
	.string "No lo desperdicies.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0:
# 1180 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, no… así no es.\p"
	.string "Vuelve a hablarme si quieres intentarlo\n"
	.string "de nuevo.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_0:
# 1185 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Mi nombre es El Gran Jefe Topo, quiero\n"
	.string "decir, Ryuzaki, aunque recientemente\l"
	.string "algunos desgraciados me están llamando\l"
	.string "Ryutopo para desprestigiarme…\p"
	.string "Y eso que mis animalines favoritos son\n"
	.string "las nutrias…$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_1:
# 1188 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero hay que admitir que es una\n"
	.string "conjugación bastante hilarante.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_2:
# 1191 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lees manga? ¡No me mientas! Sé que sí.\nEn todo caso, aún si no lo haces, hay\luno que me gustaría recomendarte.\pEs Tokyo Ghoul.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_3:
# 1195 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, entiendo esa cara de decepción, ¡no\n"
	.string "soy un adolescente emo en 2017!$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_4:
# 1198 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Su adaptación fue un relajo, pero no es\n"
	.string "la burla que probablemente imaginas.\p"
	.string "El manga trata las bifurcaciones de la\n"
	.string "introspectiva de sus personajes con\l"
	.string "tanto amor que resulta ser una\l"
	.string "experiencia preciosa.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_5:
# 1200 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te estoy desinformando, puedes\n"
	.string "confiar en mí.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_6:
# 1203 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es muy especial para mí… tenía que usar\n"
	.string "descaradamente mi influencia para\l"
	.string "darle visibilidad.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle_Text_0:
# 1210 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es hora de la violencia.\nTe mostraré La Verdad Divina.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_0:
# 1215 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Oh, hola. Tu ausencia me ha dado tiempo\n"
	.string "a componer un pequeño poema. Ten, te lo\l"
	.string "comparto.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_1:
# 1218 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "{FONT_SMALL}“¡Ay, langosta sucia!\nNo es solo cuestión de calandracas\lEs el naufragio del espíritu\lEn el Océano del Carajo”.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_2:
# 1223 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Profundo y seinen, ¿verdad? Bueno,\n"
	.string "seguramente no viniste a oírme hablar\l"
	.string "pinga… ¿Nos fajamos?$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_3:
# 1230 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prepárate para conocer la verdadera\n"
	.string "fuerza de la Jode Jode no Mi: Modelo\l"
	.string "Duende de La Buena Pipa.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_4:
# 1235 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Las moscas no pueden simplemente\n"
	.string "echarse gafas para ver La Luz.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_0:
# 1270 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me fumigaste. Te salvaste de que no\n"
	.string "estamos en territorio ryutámico.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_1:
# 1275 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Ah? ¿No íbamos a pelear? Veo que has\n"
	.string "perfeccionado tus habilidades\l"
	.string "desinformativas…$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_2:
# 1279 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres una burla, asere. Recoge tu baraja.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_3:
# 1287 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hola querid{OA} coyote. No esperaba verte\n"
	.string "por aquí.\p"
	.string "De hecho, no esperaba verme a mí mismo\n"
	.string "ni pinga.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_4:
# 1290 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La vida da más vueltas que una\n"
	.string "cantimplora, ¿verdad?$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_5:
# 1293 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¿Yo? Oh, no te preocupes, no soy\n"
	.string "nadie sospechoso.$"

CollaboratorsRoom_Text_Gameboycl_OnDefeat::
# 224 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

CollaboratorsRoom_RematchMultichoice_Rematch::
# 795 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Luchemos de nuevo!$"

CollaboratorsRoom_RematchMultichoice_TalkOnly::
# 799 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prefiero simplemente hablar.$"

CollaboratorsRoom_RematchMultichoice_Exit::
# 803 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, gracias.$"

CollaboratorsRoom_Text_Alexmad_OnDefeat::
# 1005 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años de comunidad y aún me\n"
	.string "sorprenden.$"

CollaboratorsRoom_Text_Ryuzaki_OnDefeat::
# 1300 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que dicen, la voluntad es la\n"
	.string "fuerza del alma.$"
