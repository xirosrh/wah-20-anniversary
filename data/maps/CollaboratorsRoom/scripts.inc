CollaboratorsRoom_MapScripts::
# 14 "data/maps/CollaboratorsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, CollaboratorsRoom_OnReturnToField
# 15 "data/maps/CollaboratorsRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CollaboratorsRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

CollaboratorsRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 16 "data/maps/CollaboratorsRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 1, CollaboratorsRoom_EventScript_AlexmadPuzzleSwapFeedback
	.2byte 0


CollaboratorsRoom_OnReturnToField::
# 21 "data/maps/CollaboratorsRoom/scripts.pory"
	special QueueAlexmadPartySwapFeedbackIfNeeded
	end


CollaboratorsRoom_EventScript_AfterBattleCollaborators::
# 26 "data/maps/CollaboratorsRoom/scripts.pory"
	special Special_UpdateCollaboratorsNoFaintProgress
# 27 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 28 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaboratorsNoFaints
# 29 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	return


CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle::
# 35 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 36 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 37 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 38 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 39 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 40 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 41 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_3
# 43 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_4
# 45 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_5
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_6
CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1:
	return

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_3:
# 42 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_4:
# 44 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_5:
# 46 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_6:
# 48 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_1


CollaboratorsRoom_EventScript_Kaktus_TalkOnly::
# 54 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 55 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 56 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 58 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 59 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 60 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Kaktus_IntroRematch::
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 65 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 66 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_INMORTAL_KAKTUS
# 67 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1
# 68 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 69 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 70 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 71 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 72 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 73 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2
# 76 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_2:
# 74 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2, speaker = SP_NAME_INMORTAL_KAKTUS
	return

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_3:
# 77 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
	return


CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent::
# 85 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 86 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Kaktus::
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 92 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 93 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Kaktus_1
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_TalkOnly
	return

CollaboratorsRoom_EventScript_Kaktus_1:
# 94 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_5
# 97 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle
CollaboratorsRoom_EventScript_Kaktus_4:
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 101 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 103 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 104 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 105 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_Text_0
# 106 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 107 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 108 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Kaktus_9
# 122 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 123 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 124 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 125 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 126 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 127 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 128 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
CollaboratorsRoom_EventScript_Kaktus_8:
# 130 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 0
# 131 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 132 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_5:
# 95 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroRematch
	goto CollaboratorsRoom_EventScript_Kaktus_4

CollaboratorsRoom_EventScript_Kaktus_9:
# 109 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 110 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 111 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 112 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 114 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 116 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 117 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 118 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 120 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS
	goto CollaboratorsRoom_EventScript_Kaktus_8


CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle::
# 139 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 140 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 141 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 142 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 143 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 145 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


CollaboratorsRoom_EventScript_Gameboycl_TalkOnly::
# 151 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 152 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 153 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 154 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 155 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 156 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 157 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gameboycl_IntroRematch::
# 161 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 162 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 163 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GAMEBOY_CL
# 164 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1
# 165 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 166 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 167 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 168 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 169 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 170 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2
# 173 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3
# 176 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 177 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_2:
# 171 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_3:
# 174 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
	return


CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent::
# 182 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 183 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gameboycl::
# 189 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 190 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 191 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gameboycl_1
# 228 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_TalkOnly
	return

CollaboratorsRoom_EventScript_Gameboycl_1:
# 192 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL, CollaboratorsRoom_EventScript_Gameboycl_5
# 195 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle
CollaboratorsRoom_EventScript_Gameboycl_4:
# 197 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 198 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 199 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 200 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 201 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	random 3
# 203 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 204 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 205 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_10
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_11
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gameboycl_12
CollaboratorsRoom_EventScript_Gameboycl_8:
# 212 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 213 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 214 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_14
# 222 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
CollaboratorsRoom_EventScript_Gameboycl_13:
# 224 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 225 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 226 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_5:
# 193 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroRematch
	goto CollaboratorsRoom_EventScript_Gameboycl_4

CollaboratorsRoom_EventScript_Gameboycl_10:
# 206 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_11:
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_12:
# 210 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_14:
# 215 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 217 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 218 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 219 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 220 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL
	goto CollaboratorsRoom_EventScript_Gameboycl_13


CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle::
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 238 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Erkey_TalkOnly::
# 245 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 246 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 248 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 250 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 251 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Erkey_IntroRematch::
# 255 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 256 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 257 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 258 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 259 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ERKEY
# 260 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1
# 261 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 262 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 263 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 264 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 265 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 266 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Erkey_IntroRematch_2
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Erkey_IntroRematch_3
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 277 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 278 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 279 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_2:
# 267 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 268 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 270 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_3:
# 274 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return


CollaboratorsRoom_EventScript_Erkey_OnFinishEvent::
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 285 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Erkey::
# 290 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 291 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Erkey_1
# 327 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_TalkOnly
	return

CollaboratorsRoom_EventScript_Erkey_1:
# 293 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY, CollaboratorsRoom_EventScript_Erkey_5
# 296 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle
CollaboratorsRoom_EventScript_Erkey_4:
# 298 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 299 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 300 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 301 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 302 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 303 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, CollaboratorsRoom_EventScript_Erkey_Text_0
# 305 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 306 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 307 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 308 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_9
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 321 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
CollaboratorsRoom_EventScript_Erkey_8:
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 2
# 324 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 325 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_5:
# 294 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroRematch
	goto CollaboratorsRoom_EventScript_Erkey_4

CollaboratorsRoom_EventScript_Erkey_9:
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 310 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 311 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 312 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 313 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 314 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 315 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY
	goto CollaboratorsRoom_EventScript_Erkey_8


CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle::
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 334 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 335 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 337 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 338 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 339 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 340 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit
	return


CollaboratorsRoom_EventScript_Micolo_TalkOnly::
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 347 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 349 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 350 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 352 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 353 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 355 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 357 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 358 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 359 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 360 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 362 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 365 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Micolo_IntroRematch::
# 369 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 370 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 371 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 372 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MICOLO
# 374 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1
# 375 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 376 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 377 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 379 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 380 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Micolo_IntroRematch_2
# 383 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Micolo_IntroRematch_3
# 386 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_2:
# 381 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_3:
# 384 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return


CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit::
# 392 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_DIFFICULTY
# 393 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_EASY, CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_3
# 396 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_NORMAL, CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_4
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1:
	return

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_3:
# 394 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_4:
# 397 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_1


CollaboratorsRoom_EventScript_Micolo_OnFinishEvent::
# 407 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 408 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Micolo::
# 413 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 414 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 415 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Micolo_1
# 476 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_TalkOnly
	return

CollaboratorsRoom_EventScript_Micolo_1:
# 416 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO, CollaboratorsRoom_EventScript_Micolo_5
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle
CollaboratorsRoom_EventScript_Micolo_4:
# 421 "data/maps/CollaboratorsRoom/scripts.pory"
	special SavePlayerParty
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 423 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 424 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_DIFFICULTY
# 425 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_EASY, CollaboratorsRoom_EventScript_Micolo_10
# 428 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIFFICULTY_NORMAL, CollaboratorsRoom_EventScript_Micolo_11
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 1
CollaboratorsRoom_EventScript_Micolo_8:
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 436 "data/maps/CollaboratorsRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 437 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 438 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 439 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_14
# 447 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 448 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 449 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 450 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 451 "data/maps/CollaboratorsRoom/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, CollaboratorsRoom_EventScript_Micolo_Text_1
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 455 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 456 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_17
# 464 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 465 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 467 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 468 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 469 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 470 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
CollaboratorsRoom_EventScript_Micolo_16:
# 472 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 3
# 473 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 474 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_5:
# 417 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroRematch
	goto CollaboratorsRoom_EventScript_Micolo_4

CollaboratorsRoom_EventScript_Micolo_10:
# 426 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 2
	goto CollaboratorsRoom_EventScript_Micolo_8

CollaboratorsRoom_EventScript_Micolo_11:
# 429 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 2
	goto CollaboratorsRoom_EventScript_Micolo_8

CollaboratorsRoom_EventScript_Micolo_14:
# 440 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 441 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 442 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 443 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 444 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	end

CollaboratorsRoom_EventScript_Micolo_17:
# 458 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 459 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 460 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 461 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_16


CollaboratorsRoom_EventScript_Lillipup::
# 481 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 485 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmoncry
# 486 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 487 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 488 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 489 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle::
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 495 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 497 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_TalkOnly::
# 507 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 509 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0
# 511 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 512 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 513 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 514 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1
# 515 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 516 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 517 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return


CollaboratorsRoom_EventScript_MrNightology_IntroRematch::
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 522 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_MRNIGHTOLOGY
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 526 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 527 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2
# 532 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3
# 535 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 536 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_2:
# 530 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2, speaker = SP_NAME_MRNIGHTOLOGY
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_3:
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return


CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent::
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology::
# 547 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 548 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_MrNightology_1
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_TalkOnly
	return

CollaboratorsRoom_EventScript_MrNightology_1:
# 549 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 550 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 551 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_MrNightology_6
# 556 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_MrNightology_7
CollaboratorsRoom_EventScript_MrNightology_4:
# 563 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_9
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle
CollaboratorsRoom_EventScript_MrNightology_8:
# 570 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_2
# 572 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_ON
# 573 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 574 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_3
# 575 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 576 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 577 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 579 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_WARP_OUT
# 580 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 11, 3
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY_TELEPORTING_1
# 582 "data/maps/CollaboratorsRoom/scripts.pory"
	showobjectat LOCALID_COLLABORATORS_ROOM_REONEKY, MAP_COLLABORATORS_ROOM
# 583 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_REONEKY, DIR_SOUTH
# 584 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 585 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY_TELEPORTING_2
# 587 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 588 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_5
# 593 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_6
# 596 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 597 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 598 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 599 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 600 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 601 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 602 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 603 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 604 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, Common_Movement_VersusWithDelay48
# 605 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 606 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 607 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 608 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_COLLABORATOR_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Text_6, TRAINER_WAH_COLLABORATOR_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Text_7
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 611 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 612 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_MrNightology_13
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 634 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 635 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 636 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 637 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 638 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 11, -3
# 639 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
CollaboratorsRoom_EventScript_MrNightology_12:
# 641 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 4
# 642 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 643 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_6:
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_0
# 554 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_7:
# 557 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_1
# 559 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_9:
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroRematch
	goto CollaboratorsRoom_EventScript_MrNightology_8

CollaboratorsRoom_EventScript_MrNightology_13:
# 613 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 614 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_Movement_MrNightology_Despegue
# 615 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_Movement_MrNightology_Despegue
# 616 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 617 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_8, MSGBOX_AUTOCLOSE_TOP
# 619 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FALL
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_7
# 621 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_9, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 624 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 625 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_8
# 627 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_9
# 629 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 630 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY
	goto CollaboratorsRoom_EventScript_MrNightology_12


# 649 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_Movement_MrNightology_Despegue:
# 650 "data/maps/CollaboratorsRoom/scripts.pory"
	face_left
# 651 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 652 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 653 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 654 "data/maps/CollaboratorsRoom/scripts.pory"
	face_right
# 655 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 656 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	step_end

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle::
# 662 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 663 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 664 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 665 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 666 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 667 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FaceAwayPlayer
# 668 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 669 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 670 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 671 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 672 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 673 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 675 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 676 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 677 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 678 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 679 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 681 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return


CollaboratorsRoom_EventScript_Gosuto_TalkOnly::
# 686 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 687 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 688 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 689 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 690 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 691 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 692 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 693 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 694 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 695 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 696 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 697 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Gosuto_IntroRematch::
# 701 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 702 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 703 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_GOSUTO
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0
# 705 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 706 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 707 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 708 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 709 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 710 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2
# 713 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3
# 716 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 717 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_2:
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_3:
# 714 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return


CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent::
# 722 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 723 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gosuto::
# 728 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 729 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 730 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gosuto_1
# 761 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_TalkOnly
	return

CollaboratorsRoom_EventScript_Gosuto_1:
# 731 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_5
# 734 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle
CollaboratorsRoom_EventScript_Gosuto_4:
# 736 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 737 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 739 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 740 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 741 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_Text_0
# 742 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 743 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 744 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gosuto_9
# 753 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 754 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 755 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
CollaboratorsRoom_EventScript_Gosuto_8:
# 757 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 5
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 759 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_5:
# 732 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroRematch
	goto CollaboratorsRoom_EventScript_Gosuto_4

CollaboratorsRoom_EventScript_Gosuto_9:
# 745 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 746 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 747 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 749 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 750 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 751 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO
	goto CollaboratorsRoom_EventScript_Gosuto_8


CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle::
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 768 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNote
# 769 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 770 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 771 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Movement_0
# 772 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
	return


CollaboratorsRoom_EventScript_Acimut_TalkOnly::
# 777 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 778 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 779 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 780 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 781 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 782 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 783 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 784 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 785 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 786 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 787 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 789 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 790 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 791 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 792 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 793 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 794 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 795 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 796 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 797 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Acimut_IntroRematch::
# 813 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 814 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 815 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_MusicNoteWithDelay48
# 816 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ACIMUT
# 817 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1
# 818 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 819 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 820 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 821 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 822 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 823 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Acimut_IntroRematch_2
# 826 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Acimut_IntroRematch_3
# 830 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 831 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 832 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_2:
# 824 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Acimut_IntroRematch_3:
# 827 "data/maps/CollaboratorsRoom/scripts.pory"
	fadedefaultbgm
# 828 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return


CollaboratorsRoom_EventScript_Acimut_OnFinishEvent::
# 837 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
# 838 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Acimut::
# 843 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 844 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 845 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Acimut_1
# 880 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_TalkOnly
	return

CollaboratorsRoom_EventScript_Acimut_1:
# 846 "data/maps/CollaboratorsRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_COOL, FALSE
# 847 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT, CollaboratorsRoom_EventScript_Acimut_5
# 850 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle
CollaboratorsRoom_EventScript_Acimut_4:
# 852 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 853 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 854 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 855 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 856 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 857 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 858 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ACIMUT, CollaboratorsRoom_EventScript_Acimut_Text_0
# 859 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 860 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 861 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Acimut_9
# 870 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 871 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 872 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 873 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 874 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
CollaboratorsRoom_EventScript_Acimut_8:
# 876 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 6
# 877 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 878 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Acimut_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Acimut_5:
# 848 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Acimut_IntroRematch
	goto CollaboratorsRoom_EventScript_Acimut_4

CollaboratorsRoom_EventScript_Acimut_9:
# 862 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 863 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 864 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 865 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 866 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 867 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Acimut_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ACIMUT
# 868 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT
	goto CollaboratorsRoom_EventScript_Acimut_8


CollaboratorsRoom_EventScript_Alexmad_LongIntro::
# 885 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 886 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 888 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 889 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 890 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_IdeaWithDelay48
# 891 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 892 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 893 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 894 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 895 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 896 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 897 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 898 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 899 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 900 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 901 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 902 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 903 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 904 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 905 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 906 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
	return


CollaboratorsRoom_EventScript_Alexmad_QRFlow::
# 911 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0, speaker = SP_NAME_ALEXMAD
# 912 "data/maps/CollaboratorsRoom/scripts.pory"
	load_field_pic FP_MAD_QR, 120, 80
# 913 "data/maps/CollaboratorsRoom/scripts.pory"
	waitbuttonpress
# 914 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 915 "data/maps/CollaboratorsRoom/scripts.pory"
	destroy_field_pic FP_MAD_QR
# 916 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
# 917 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 918 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 919 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_2
# 943 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_QRFlow_1:
# 945 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_QRFlow_2:
# 920 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 921 "data/maps/CollaboratorsRoom/scripts.pory"
	special EnterCode
# 922 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 923 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetCodeFeedback
# 924 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_QRFlow_5
# 937 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 938 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 939 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_AnnoyedWithDelay48
# 940 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow_1

CollaboratorsRoom_EventScript_Alexmad_QRFlow_5:
# 925 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 926 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_TEMP_ALEXMAD_PUZZLE_STARTED
# 927 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_FAILED
# 928 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_SWAP_FEEDBACK_PENDING
# 929 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_SWAP_FEEDBACK_SHOWN
# 930 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 931 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_ALEXMAD_PUZZLE_CHECKPOINT, 0
# 932 "data/maps/CollaboratorsRoom/scripts.pory"
	getplayerxy VAR_ALEXMAD_PUZZLE_START_X, VAR_ALEXMAD_PUZZLE_START_Y
# 933 "data/maps/CollaboratorsRoom/scripts.pory"
	special InitAlexmadPuzzlePartyOrderCheck
# 934 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle::
# 949 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 950 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Alexmad_IntroRematch::
# 955 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 956 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 957 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_ALEXMAD
# 958 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1
# 959 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 960 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 961 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 962 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 963 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 964 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2
# 967 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3
# 971 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 972 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_2:
# 965 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_3:
# 968 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 969 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Alexmad_DoBattle::
# 977 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 978 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 979 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_VersusWithDelay48
# 980 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 981 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 982 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ALEXMAD, CollaboratorsRoom_Text_Alexmad_OnDefeat
# 983 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 984 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 985 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_DoBattle_2
# 995 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 996 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 997 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 998 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 999 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_DoBattle_1:
# 1001 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 7
# 1002 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 1003 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_DoBattle_2:
# 986 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 987 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_SurpriseWithDelay48
# 988 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 989 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 990 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 991 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 992 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 993 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle_1


CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent::
# 1007 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_NORTH
# 1008 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Alexmad::
# 1017 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1018 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1019 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_TEMP_ALEXMAD_PUZZLE_STARTED, CollaboratorsRoom_EventScript_Alexmad_2
# 1023 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1024 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_5
CollaboratorsRoom_EventScript_Alexmad_4:
# 1027 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 1028 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1029 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 1030 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1031 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_Movement_0
# 1033 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1034 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1035 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0
# 1036 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1037 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 0
# 1038 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_MET_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_8
CollaboratorsRoom_EventScript_Alexmad_7:
# 1044 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_ALEXMAD_EVENT_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_10
# 1060 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_16
# 1088 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_28
# 1091 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_12, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_27:
# 1093 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1094 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1095 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_35
# 1098 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1099 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_2:
# 1020 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_0, MSGBOX_NPC, speaker = SP_NAME_ALEXMAD
	end

CollaboratorsRoom_EventScript_Alexmad_5:
# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_4

CollaboratorsRoom_EventScript_Alexmad_8:
# 1039 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_C, 1
# 1040 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_LongIntro
# 1041 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_MET_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_7

CollaboratorsRoom_EventScript_Alexmad_10:
# 1045 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Alexmad_13
# 1053 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1054 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1055 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 1056 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1057 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_13:
# 1046 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_20
# 1049 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
CollaboratorsRoom_EventScript_Alexmad_19:
# 1051 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_16:
# 1061 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_TEMP_C, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_24
# 1064 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1065 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1066 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_QuestionMark
# 1067 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1068 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 60
CollaboratorsRoom_EventScript_Alexmad_23:
# 1070 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_EventScript_Alexmad_Text_7, CollaboratorsRoom_EventScript_Alexmad_Text_8, CollaboratorsRoom_EventScript_Alexmad_Text_9
# 1071 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1072 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Alexmad_32
# 1074 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Alexmad_33
# 1084 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1085 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Alexmad_20:
# 1047 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroRematch
	goto CollaboratorsRoom_EventScript_Alexmad_19

CollaboratorsRoom_EventScript_Alexmad_24:
# 1062 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_23

CollaboratorsRoom_EventScript_Alexmad_28:
# 1089 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_11, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_Alexmad_27

CollaboratorsRoom_EventScript_Alexmad_32:
# 1073 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_33:
# 1075 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_Alexmad_39
# 1078 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1079 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HappyWithDelay48
# 1080 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
CollaboratorsRoom_EventScript_Alexmad_38:
# 1082 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_DoBattle
	return

CollaboratorsRoom_EventScript_Alexmad_35:
# 1096 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_QRFlow
	return

CollaboratorsRoom_EventScript_Alexmad_39:
# 1076 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle
	goto CollaboratorsRoom_EventScript_Alexmad_38


CollaboratorsRoom_EventScript_AlexmadPuzzleSwapFeedback::
# 1106 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1107 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FacePlayer
# 1108 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1109 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_SurpriseWithDelay48
# 1110 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleSwapFeedback_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1111 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_SWAP_FEEDBACK_PENDING
# 1112 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1113 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_TEMP_ALEXMAD_PUZZLE_SWAP_FEEDBACK_SHOWN
# 1114 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_AlexmadPuzzleComplete::
# 1119 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1120 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FaceRight
# 1121 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1122 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_DoubleExclamationMark
# 1123 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1124 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1125 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0
# 1126 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1127 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1
# 1129 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1130 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_SUCCESS
# 1131 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1132 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1133 "data/maps/CollaboratorsRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 5, 3
# 1134 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1135 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 1136 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1137 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1138 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1139 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1140 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1141 "data/maps/CollaboratorsRoom/scripts.pory"
	giveitem ITEM_TERA_ORB
# 1142 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_TERA_ORB_CHARGED
# 1143 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_TERA_ORB_NO_COST
# 1144 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1145 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 1146 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer
# 1147 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1148 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1149 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_GIVE_LEGENDARIES
# 1150 "data/maps/CollaboratorsRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
# 1151 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1152 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1153 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1154 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1155 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1156 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1157 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_GIVE_CLONES
# 1158 "data/maps/CollaboratorsRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
# 1159 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1160 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1161 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1162 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_HeartWithDelay48
# 1163 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1164 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FaceAwayPlayer
# 1165 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1166 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1167 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1168 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1169 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1170 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer
# 1171 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1172 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_ALEXMAD_EVENT_COMPLETED
# 1173 "data/maps/CollaboratorsRoom/scripts.pory"
	call Pokebox_EventScript_ShowUnlocks
# 1174 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer
# 1175 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1176 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return


WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer::
# 1180 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 1181 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1182 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_3
# 1185 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_4
# 1188 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_5
# 1191 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_6
WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1:
	return

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_3:
# 1183 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceDown
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_4:
# 1186 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceUp
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_5:
# 1189 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceRight
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1

WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_6:
# 1192 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkInPlaceLeft
	goto WahRoomsShared_EventScript_WalkInPlaceAlexmadFacingPlayer_1


CollaboratorsRoom_EventScript_AlexmadPuzzleFailed::
# 1199 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 1200 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_FacePlayer
# 1201 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FAILURE
# 1202 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_XWithDelay48
# 1203 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 1204 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_unset FLAG_TEMP_ALEXMAD_PUZZLE_SWAP_FEEDBACK_SHOWN, CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_2
CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_1:
# 1209 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Alexmad_OnFinishEvent
	return

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_2:
# 1205 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1206 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_ThinkingWithDelay48
# 1207 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
	goto CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_1


CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly::
# 1213 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1214 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1215 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1216 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1217 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1218 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1219 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1220 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1221 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 1222 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 1223 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1224 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1225 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1226 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1227 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1228 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1229 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1230 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1231 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1232 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1233 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 1234 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle::
# 1238 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
	return


CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch::
# 1243 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1244 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1245 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1246 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1247 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1248 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1249 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1250 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_RYUZAKI
# 1251 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_2
# 1252 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 1253 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 1254 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1255 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1256 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1257 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_2
# 1260 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_3
# 1263 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1264 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1265 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1266 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_2:
# 1258 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
	return

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_3:
# 1261 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly
	return


CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent::
# 1271 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 1272 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Ryuzaki::
# 1277 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1278 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 1279 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Ryuzaki_1
# 1314 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1315 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1316 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 1317 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1318 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1319 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1320 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1321 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1322 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1323 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly
	return

CollaboratorsRoom_EventScript_Ryuzaki_1:
# 1280 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI, CollaboratorsRoom_EventScript_Ryuzaki_5
# 1283 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle
CollaboratorsRoom_EventScript_Ryuzaki_4:
# 1285 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1286 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 1287 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 1288 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1289 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 1290 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_RYUZAKI, CollaboratorsRoom_Text_Ryuzaki_OnDefeat
# 1291 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 1292 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1293 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Ryuzaki_9
# 1301 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_FORFEITED
	goto_if_eq CollaboratorsRoom_EventScript_Ryuzaki_10
# 1306 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1307 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1308 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
CollaboratorsRoom_EventScript_Ryuzaki_8:
# 1310 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 8
# 1311 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 1312 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Ryuzaki_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Ryuzaki_5:
# 1281 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch
	goto CollaboratorsRoom_EventScript_Ryuzaki_4

CollaboratorsRoom_EventScript_Ryuzaki_9:
# 1294 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1295 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 1296 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1297 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1298 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1299 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1300 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI
	goto CollaboratorsRoom_EventScript_Ryuzaki_8

CollaboratorsRoom_EventScript_Ryuzaki_10:
# 1302 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Ryuzaki_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_RYUZAKI
# 1303 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1304 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
	goto CollaboratorsRoom_EventScript_Ryuzaki_8


CollaboratorsRoom_EventScript_Caco_IntroFirstBattle::
# 1332 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 1333 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1334 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 1336 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1337 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 1339 "data/maps/CollaboratorsRoom/scripts.pory"
	checkplayergender
# 1340 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_2
# 1343 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_1:
# 1345 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1346 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 1347 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1348 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1349 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 1350 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1351 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 1352 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1353 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1354 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AngryWithDelay48
# 1355 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
	return

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_2:
# 1341 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
	goto CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_1


CollaboratorsRoom_EventScript_Caco_TalkOnly::
# 1360 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 1361 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1362 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1363 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1364 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1365 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 1366 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1367 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 1368 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1369 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1370 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 1371 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Caco_OnFinishEvent
	return


CollaboratorsRoom_EventScript_Caco_IntroRematch::
# 1375 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1377 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 1380 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1381 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ExclamationMark
# 1382 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1383 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Alexmad_Movement_0
# 1384 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 1385 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 1386 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1387 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 1388 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1389 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1390 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 1391 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1392 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 1393 "data/maps/CollaboratorsRoom/scripts.pory"
	setspeaker SP_NAME_CACO
# 1394 "data/maps/CollaboratorsRoom/scripts.pory"
	message CollaboratorsRoom_EventScript_Alexmad_Text_6
# 1395 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmessage
# 1396 "data/maps/CollaboratorsRoom/scripts.pory"
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, CollaboratorsRoom_RematchMultichoice_Rematch, CollaboratorsRoom_RematchMultichoice_TalkOnly, CollaboratorsRoom_RematchMultichoice_Exit
# 1397 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 1399 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1400 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Caco_IntroRematch_2
# 1404 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Caco_IntroRematch_3
# 1407 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1408 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1409 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1410 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Caco_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Caco_IntroRematch_2:
# 1401 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1402 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
	return

CollaboratorsRoom_EventScript_Caco_IntroRematch_3:
# 1405 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Caco_TalkOnly
	return


CollaboratorsRoom_EventScript_Caco_OnFinishEvent::
# 1415 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 1416 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Caco::
# 1421 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 1423 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Caco_1
# 1466 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Caco_TalkOnly
	return

CollaboratorsRoom_EventScript_Caco_1:
# 1424 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_CACO, CollaboratorsRoom_EventScript_Caco_5
# 1427 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Caco_IntroFirstBattle
CollaboratorsRoom_EventScript_Caco_4:
# 1430 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 1431 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1432 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 1433 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 1434 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 1436 "data/maps/CollaboratorsRoom/scripts.pory"
	random 3
# 1437 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 1438 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 1439 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Caco_10
# 1441 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Caco_11
# 1443 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Caco_12
CollaboratorsRoom_EventScript_Caco_8:
# 1446 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 1448 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 1450 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Caco_14
# 1457 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1458 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1459 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMarkWithDelay48
CollaboratorsRoom_EventScript_Caco_13:
# 1461 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, 9
# 1462 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_AfterBattleCollaborators
# 1463 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Caco_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Caco_5:
# 1425 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Caco_IntroRematch
	goto CollaboratorsRoom_EventScript_Caco_4

CollaboratorsRoom_EventScript_Caco_10:
# 1440 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_CACO_1, CollaboratorsRoom_Text_Caco_OnDefeat
	goto CollaboratorsRoom_EventScript_Caco_8

CollaboratorsRoom_EventScript_Caco_11:
# 1442 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_CACO_2, CollaboratorsRoom_Text_Caco_OnDefeat
	goto CollaboratorsRoom_EventScript_Caco_8

CollaboratorsRoom_EventScript_Caco_12:
# 1444 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_CACO_3, CollaboratorsRoom_Text_Caco_OnDefeat
	goto CollaboratorsRoom_EventScript_Caco_8

CollaboratorsRoom_EventScript_Caco_14:
# 1451 "data/maps/CollaboratorsRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 1452 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Caco_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_CACO
# 1453 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 1454 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 1455 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_CACO
	goto CollaboratorsRoom_EventScript_Caco_13


CollaboratorsRoom_EventScript_Notes::
# 1475 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Notes_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_MaidenPoster::
# 1480 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MaidenPoster_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Library::
# 1485 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Library_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Coffee::
# 1490 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Coffee_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Projector::
# 1495 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Projector_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Desk::
# 1500 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Desk_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Trash::
# 1505 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Trash_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Brainstorming::
# 1510 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Brainstorming_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Desk2::
# 1515 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Desk2_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Computer::
# 1520 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Computer_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Notes2::
# 1525 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Notes2_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Notes3::
# 1530 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Notes3_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Notes4::
# 1535 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Notes4_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Notes5::
# 1540 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Notes5_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_Notes6::
# 1545 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Notes6_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_ExaminePaperScraps::
# 1550 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_ExaminePaperScraps_Text_0, MSGBOX_SIGN
	end


CollaboratorsRoom_EventScript_NotesTable::
# 1555 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_NotesTable_Text_0, MSGBOX_SIGN
	end


# 124 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_0:
# 124 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 124 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 126 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_1:
# 126 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 126 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 126 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 336 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 361 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_TalkOnly_Movement_0:
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 496 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0:
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 500 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1:
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sweat_drop
	step_end

# 510 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_0:
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sad
	step_end

# 514 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Movement_1:
# 514 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_annoyed
	step_end

# 553 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_0:
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_left
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 558 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_1:
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 571 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_2:
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 574 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_3:
# 574 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_up
	step_end

# 578 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_4:
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 592 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_5:
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
	step_end

# 595 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_6:
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
	step_end

# 620 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_7:
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 620 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
	step_end

# 626 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_8:
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_question_mark
	step_end

# 628 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_9:
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 771 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Movement_0:
# 771 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 771 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 771 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Alexmad_Movement_0:
# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 1032 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 1125 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0:
# 1125 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
	step_end

# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1:
# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_right
# 1128 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_0:
# 35 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, vaya…\n¿Así que completaste el desafío?$"

CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle_Text_1:
# 38 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces ya no eres un{A} novat{OA}... veamos\n"
	.string "si sabes aplicar lo aprendido.\p"
	.string "Un combate, sin atajos, sin trucos.\n"
	.string "¿List{OA}?$"

CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_0:
# 54 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

CollaboratorsRoom_EventScript_Kaktus_TalkOnly_Text_1:
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_0:
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ey, ¿qué tal? Mi Ludicolo sigue con\n"
	.string "ganas de bailar.$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_1:
# 67 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro asalto?$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_2:
# 74 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vamos!$"

CollaboratorsRoom_EventScript_Kaktus_IntroRematch_Text_3:
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Será en otra oportunidad entonces!$"

CollaboratorsRoom_EventScript_Kaktus_Text_0:
# 105 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Acaso perdí?$"

CollaboratorsRoom_EventScript_Kaktus_Text_1:
# 111 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ja… perdí.$"

CollaboratorsRoom_EventScript_Kaktus_Text_2:
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

CollaboratorsRoom_EventScript_Kaktus_Text_3:
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Enhorabuena, crack.$"

CollaboratorsRoom_EventScript_Kaktus_Text_4:
# 122 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

CollaboratorsRoom_EventScript_Kaktus_Text_5:
# 128 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espero la revancha pronto!$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 140 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No soy competitivo ni ambicioso.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 143 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Soy más bien una persona mediocre.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_2:
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso puede jugarme en contra.$"

CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_0:
# 151 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un hack rom es como la arquitectura,\nse construye sobre lo existente.$"

CollaboratorsRoom_EventScript_Gameboycl_TalkOnly_Text_1:
# 153 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El arte aquí no es lo que se cambia,\nsino lo que se quiere transmitir.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0:
# 161 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1:
# 164 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_2:
# 176 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_0:
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_1:
# 222 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando te sientas preparad{OA}, vuelve y\n"
	.string "probamos nuestros equipos en un duelo.$"

CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0:
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_0:
# 245 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

CollaboratorsRoom_EventScript_Erkey_TalkOnly_Text_1:
# 248 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si prestas atención.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0:
# 257 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1:
# 260 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Quieres volver a luchar?$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2:
# 267 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_3:
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

CollaboratorsRoom_EventScript_Erkey_Text_0:
# 304 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

CollaboratorsRoom_EventScript_Erkey_Text_1:
# 311 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien jugado.$"

CollaboratorsRoom_EventScript_Erkey_Text_2:
# 314 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando las reglas cambian, tú te\n"
	.string "adaptaste.\p"
	.string "Eso es el espíritu de Whack a Hack.$"

CollaboratorsRoom_EventScript_Erkey_Text_3:
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0:
# 338 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres buen{OA} con los\n"
	.string "Pokémon que he criado y entrenado.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_0:
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_1:
# 349 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_2:
# 352 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_3:
# 355 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

CollaboratorsRoom_EventScript_Micolo_TalkOnly_Text_4:
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0:
# 371 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1:
# 374 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te atreves?$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_2:
# 386 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_0:
# 394 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Elige dos Pokémon para combatir. Yo\n"
	.string "escogeré uno de mis ejemplares al azar\l"
	.string "para enfrentaros.$"

CollaboratorsRoom_EventScript_Micolo_ExplainPartyLimit_Text_1:
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"

CollaboratorsRoom_EventScript_Micolo_Text_0:
# 443 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

CollaboratorsRoom_EventScript_Micolo_Text_1:
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, me has ganado.$"

CollaboratorsRoom_EventScript_Micolo_Text_2:
# 460 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Admito que eres buen{OA}, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

CollaboratorsRoom_EventScript_Micolo_Text_3:
# 466 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

CollaboratorsRoom_EventScript_Lillipup_Text_0:
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pup, pup, pup.$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0:
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Buscas problemas?\n"
	.string "¡Pues escucha nuestro lema!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1:
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Uy, me he equivocado!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2:
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perdona, es la costumbre je, je…\p"
	.string "Bueno, por lo que veo has completado el\n"
	.string "desafío.\p"
	.string "¡Enhorabuena!\p"
	.string "Pero… ¡será por poco tiempo!\n"
	.string "¡Ha llegado el momento de ponerte a\l"
	.string "prueba una vez más!$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_0:
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ay, si te contase…\p"
	.string "La Beta 1 de mi hack la publiqué en 2010\n"
	.string "y 15 años después, conseguí acabarlo.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_1:
# 512 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Una larga travesía para que al final, la\n"
	.string "gente te pregunte cuál es el cheat de\l"
	.string "los caramelos infinitos.$"

CollaboratorsRoom_EventScript_MrNightology_TalkOnly_Text_2:
# 516 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te parece normal?\n"
	.string "En fin… La vida del romhacker.$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0:
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tú otra vez!$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1:
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te has quedado con ganas de más?$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2:
# 530 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Já! Si ya me lo imaginaba…$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_3:
# 535 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿No?\n"
	.string "Bueno… Ya volverás.$"

CollaboratorsRoom_EventScript_MrNightology_Text_0:
# 570 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo un plan genial para derrotarte y\n"
	.string "para eso lucharé con un amigo.\p"
	.string "Así que…\n"
	.string "¡Que aparezca el invitado especial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_1:
# 575 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Estás preparado?\n"
	.string "¿Sí? Genial.\p"
	.string "¡Vente p'acá!$"

CollaboratorsRoom_EventScript_MrNightology_Text_2:
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ostras!\n"
	.string "¿Cómo lo has hecho?$"

CollaboratorsRoom_EventScript_MrNightology_Text_3:
# 596 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Coño! Transmisión instantánea, bro.\n"
	.string "¡No me he pasado entrenando en el\l"
	.string "planeta Yardrat todo este tiempo pa ná!$"

CollaboratorsRoom_EventScript_MrNightology_Text_4:
# 597 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah, mira qué bien! ¡Eso me viene genial\n"
	.string "para que la próxima vez no acabe\l"
	.string "reventao con tantas horas de bus!$"

CollaboratorsRoom_EventScript_MrNightology_Text_5:
# 601 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sorprendido, ¿no?\n"
	.string "Pues ha llegado la hora…\p"
	.string "¡Prepárate para luchar!$"

CollaboratorsRoom_EventScript_MrNightology_Text_6:
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¡Pero si era un plan genial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_7:
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿He vuelto a perder?$"

CollaboratorsRoom_EventScript_MrNightology_Text_8:
# 618 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡El Team Rocket despega de nuevooooo…!$"

CollaboratorsRoom_EventScript_MrNightology_Text_9:
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya aterrizaje!$"

CollaboratorsRoom_EventScript_MrNightology_Text_10:
# 629 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Y ReoNeky?\n"
	.string "Espero que haya aterrizado en su sala.$"

CollaboratorsRoom_EventScript_MrNightology_Text_11:
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has hecho todo lo que has podido, pero\n"
	.string "no es suficiente.$"

CollaboratorsRoom_EventScript_MrNightology_Text_12:
# 636 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Dale una vuelta a tu estrategia y…\p"
	.string "¡No nos hagas esperar mucho para la\n"
	.string "revancha!$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0:
# 664 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Oh! Pues parece que has superado el\n"
	.string "desafío de las salas.\p"
	.string "¿Qué te parece si te ponemos a prueba y\n"
	.string "vemos de lo que eres capaz?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1:
# 666 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Hacemos esto un poco más divertido?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2:
# 672 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "O mejor dicho, ¿¡qué te parece si lo\n"
	.string "hacemos el doble de divertido!?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3:
# 681 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Muy bien, entra al mundo de las\n"
	.string "tinieblas conmigo…$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_0:
# 686 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizás me conoces, quizás no, pero no te\n"
	.string "culpo; paso como una sombra entre las\l"
	.string "tinieblas.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_1:
# 690 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero a pesar de permanecer entre las\n"
	.string "tinieblas, he aportado a grandes\l"
	.string "proyectos dando un pequeño grano de\l"
	.string "arena.$"

CollaboratorsRoom_EventScript_Gosuto_TalkOnly_Text_2:
# 694 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Que no se diga más y a seguir\n"
	.string "procesando píxeles!$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0:
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate? ¿Estás segur{OA} de estar\n"
	.string "list{OA} para entrar al mundo de las\l"
	.string "tinieblas?$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1:
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ok, veamos si esta vez logras superar\n"
	.string "tus miedos.$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2:
# 716 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien pensado; aunque puedes volver\n"
	.string "cuando quieras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_0:
# 741 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Creo que ya superaste tus miedos y\n"
	.string "superaste las sombras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_1:
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, parece que encontraste una\n"
	.string "chispa de suerte.\p"
	.string "Aprovecha esa luz mientras puedas,\n"
	.string "porque las sombras son pacientes y las\l"
	.string "tinieblas siempre terminan ganando al\l"
	.string "final.$"

CollaboratorsRoom_EventScript_Gosuto_Text_2:
# 753 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te sientas mal; no cualquiera\n"
	.string "sobrevive a mis tinieblas.$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_0:
# 769 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espera! ¿Escuchas eso?$"

CollaboratorsRoom_EventScript_Acimut_IntroFirstBattle_Text_1:
# 772 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Es el sonido de la batalla!$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_0:
# 777 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un día empecé a descompilar Pokémon\n"
	.string "FireRed en español para obtener la ROM\l"
	.string "original compilando pokefirered.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_1:
# 779 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tuvieron que pasar dos años para\n"
	.string "encontrar motivación en el desafío 30\l"
	.string "días dentro del foro de WaH.\p"
	.string "Durante ese tiempo logré hacer\n"
	.string "coincidencia al 100%.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_2:
# 788 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Fue el mejor día de mi vida en el mundo\n"
	.string "del rom hacking, superando un reto\l"
	.string "personal muy significativo para mí.$"

CollaboratorsRoom_EventScript_Acimut_TalkOnly_Text_3:
# 793 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Por cierto, aquí la música se escucha\n"
	.string "mejor en estéreo.$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_0:
# 813 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La música son matemáticas y puro\n"
	.string "sentimiento.\p"
	.string "¡Como los combates Pokémon!$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_1:
# 817 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿List{OA} para la revancha?$"

CollaboratorsRoom_EventScript_Acimut_IntroRematch_Text_2:
# 831 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras. Aquí siempre hay\n"
	.string "buena música para combatir.$"

CollaboratorsRoom_EventScript_Acimut_Text_0:
# 858 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué ha pasado aquí?$"

CollaboratorsRoom_EventScript_Acimut_Text_1:
# 864 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ese último movimiento no lo vi venir…$"

CollaboratorsRoom_EventScript_Acimut_Text_2:
# 867 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Espero podamos volver a enfrentarnos\n"
	.string "en un futuro.$"

CollaboratorsRoom_EventScript_Acimut_Text_3:
# 870 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La armonía de tus Pokémon lo es todo…$"

CollaboratorsRoom_EventScript_Acimut_Text_4:
# 874 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si quieres volver a intentarlo, aquí\n"
	.string "estaré.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_0:
# 885 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años… ¿te das cuenta?$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_1:
# 887 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí crecimos entre bugs, tiles mal\n"
	.string "alineados y scripts que se colgaban en\l"
	.string "el último mapa.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_2:
# 891 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah! Si ves a Baro por ahí… no intentes\n"
	.string "ser su amigo.\p"
	.string "Créeme, no termina bien.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_3:
# 895 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Y si te topas con Serg!o… salúdalo con\n"
	.string "respeto.\p"
	.string "Es leyenda.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_4:
# 898 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Todos le tenemos un cariño especial…\n"
	.string "Y no, no homo.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_5:
# 901 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me encanta la playa, hacer mapas bien\n"
	.string "locos y meter bosques dentro de\l"
	.string "cuevas.\p"
	.string "Eso dice muchas cosas de mí.$"

CollaboratorsRoom_EventScript_Alexmad_LongIntro_Text_6:
# 904 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Los hacks dicen muchas cosas de\n"
	.string "nosotros.\p"
	.string "Incluso en nuestra vida personal… nos\n"
	.string "hicieron mejores personas.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_0:
# 911 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Escanea el QR con tu móvil y nos vemos\n"
	.string "en el otro mundo.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_1:
# 916 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lo viste?$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_2:
# 920 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces escribe la palabra que viste\n"
	.string "en el video.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_3:
# 925 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto… Veo que sí lo viste.\p"
	.string "Entonces sabes lo que tienes que hacer.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_4:
# 937 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No… esa no es.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_5:
# 940 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Recuerda que en el video explico los 3\n"
	.string "pasos que necesitas para completar el\l"
	.string "evento.\p"
	.string "La contraseña es tan solo el primer\n"
	.string "paso.\p"
	.string "Vuelve cuando tengas la respuesta\n"
	.string "correcta.$"

CollaboratorsRoom_EventScript_Alexmad_QRFlow_Text_6:
# 943 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.$"

CollaboratorsRoom_EventScript_Alexmad_IntroFirstBattle_Text_0:
# 949 "data/maps/CollaboratorsRoom/scripts.pory"
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
# 955 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Regresaste…\n"
	.string "Eso ya dice algo.\p"
	.string "En WAH aprendimos que rendirse no es\n"
	.string "una opción.\p"
	.string "Cada error es una versión nueva… cada\n"
	.string "derrota es un parche.\p"
	.string "Y cada parche nos hizo mejores.$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_1:
# 958 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate?$"

CollaboratorsRoom_EventScript_Alexmad_IntroRematch_Text_2:
# 971 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras volver, aquí estaré.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_0:
# 988 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Excelente…\n"
	.string "Eres digno de estar aquí.\p"
	.string "Me alegra ver que la comunidad nunca\n"
	.string "dejó de ser la mejor.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_1:
# 991 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hoy perdí yo…\n"
	.string "Pero quizás mañana podría ganar Samee.\p"
	.string "Nos veremos pronto.$"

CollaboratorsRoom_EventScript_Alexmad_DoBattle_Text_2:
# 995 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veo que no siempre tener el mejor\n"
	.string "equipo es suficiente.\p"
	.string "La estrategia pesa más que pulsar A a lo\n"
	.string "loco.$"

CollaboratorsRoom_EventScript_Alexmad_Text_0:
# 1020 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que tienes que hacer, ¿no?$"

CollaboratorsRoom_EventScript_Alexmad_Text_1:
# 1025 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sm1, sm2 o…$"

CollaboratorsRoom_EventScript_Alexmad_Text_2:
# 1053 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya lo lograste.$"

CollaboratorsRoom_EventScript_Alexmad_Text_3:
# 1056 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER.\p"
	.string "Siempre fue bueno con los acertijos.\n"
	.string "Sigue adelante, seguro que te irá bien.$"

CollaboratorsRoom_EventScript_Alexmad_Text_4:
# 1062 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Pero también podemos ir directo a la\n"
	.string "batalla.\n"
	.string "¿Qué prefieres?$"

CollaboratorsRoom_EventScript_Alexmad_Text_5:
# 1064 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tu de nuevo! Tengo dos propuestas\n"
	.string "para ti.$"

CollaboratorsRoom_EventScript_Alexmad_Text_6:
# 1067 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_7:
# 1070 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evento$"

CollaboratorsRoom_EventScript_Alexmad_Text_8:
# 1070 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Batalla$"

CollaboratorsRoom_EventScript_Alexmad_Text_9:
# 1070 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Salir$"

CollaboratorsRoom_EventScript_Alexmad_Text_10:
# 1080 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Veamos qué versión eres ahora.$"

CollaboratorsRoom_EventScript_Alexmad_Text_11:
# 1089 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Dime… ¿lo quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_12:
# 1091 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has vuelto, ¿quieres seguir con el\n"
	.string "evento?$"

CollaboratorsRoom_EventScript_Alexmad_Text_13:
# 1098 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando estés list{OA}.\n"
	.string "El Mitic no espera… pero tampoco se\l"
	.string "repite.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleSwapFeedback_Text_0:
# 1110 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien ahí… solo te falta la última parte\n"
	.string "del evento.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0:
# 1131 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Lo has logrado! Veo que eres buen{OA}.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1:
# 1136 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER. Siempre fue bueno\n"
	.string "con los acertijos.\p"
	.string "Quizás pueda ayudarte en tu camino.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_2:
# 1139 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Toma este objeto.\nNo entiendo bien qué hace, pero\lseguro te será útil.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_3:
# 1147 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Además, ahora podrás encontrar en la PC\n"
	.string "a algunos legendarios de la Isla Mítica.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_4:
# 1152 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizá puedas reemplazar a alguno de tus\n"
	.string "Pokémon con uno de ellos.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_5:
# 1155 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Conoces el poder de los clones?\n"
	.string "Ahora podrás vivirlo en carne propia.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_6:
# 1160 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Estos clones son mucho más fuertes que\n"
	.string "los Pokémon originales.\p"
	.string "Úsalos sabiamente.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_7:
# 1171 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También te daré acceso a este Pokémon\n"
	.string "muy especial.\p"
	.string "Es una herramienta de combate muy\n"
	.string "codiciada.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_8:
# 1175 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "KODER hubiera sonreído al verte salir\n"
	.string "de aquí con tantas cartas en la manga.\p"
	.string "No lo desperdicies.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0:
# 1203 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, no… así no es.\p"
	.string "Vuelve a hablarme si quieres intentarlo\n"
	.string "de nuevo.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_1:
# 1207 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Recuerda lo que dije, que a veces los\n"
	.string "últimos serán los…\l"
	.string "…\p"
	.string "Mejor vuelve a intentarlo.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_0:
# 1213 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Mi nombre es El Gran Jefe Topo, quiero\n"
	.string "decir, Ryuzaki, aunque recientemente\l"
	.string "algunos desgraciados me están llamando\l"
	.string "Ryutopo para desprestigiarme…\p"
	.string "Y eso que mis animalines favoritos son\n"
	.string "las nutrias…$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_1:
# 1216 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero hay que admitir que es una\n"
	.string "conjugación bastante hilarante.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_2:
# 1219 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lees manga? ¡No me mientas! Sé que sí.\nEn todo caso, aún si no lo haces, hay\luno que me gustaría recomendarte.\pEs Tokyo Ghoul.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_3:
# 1223 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, entiendo esa cara de decepción, ¡no\n"
	.string "soy un adolescente emo en 2017!$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_4:
# 1226 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Su adaptación fue un relajo, pero no es\n"
	.string "la burla que probablemente imaginas.\p"
	.string "El manga trata las bifurcaciones de la\n"
	.string "introspectiva de sus personajes con\l"
	.string "tanto amor que resulta ser una\l"
	.string "experiencia preciosa.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_5:
# 1228 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te estoy desinformando, puedes\n"
	.string "confiar en mí.$"

CollaboratorsRoom_EventScript_Ryuzaki_TalkOnly_Text_6:
# 1231 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es muy especial para mí… tenía que usar\n"
	.string "descaradamente mi influencia para\l"
	.string "darle visibilidad.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroFirstBattle_Text_0:
# 1238 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es hora de la violencia.\nTe mostraré La Verdad Divina.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_0:
# 1243 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Oh, hola. Tu ausencia me ha dado tiempo\n"
	.string "a componer un pequeño poema.\p"
	.string "Ten, te lo comparto.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_1:
# 1246 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "{FONT_SMALL}“¡Ay, langosta sucia!\nNo es solo cuestión de calandracas\lEs el naufragio del espíritu\lEn el Océano del Carajo”.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_2:
# 1251 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Profundo y seinen, ¿verdad?\p"
	.string "Bueno, seguramente no viniste a oírme\n"
	.string "hablar pinga… ¿Nos fajamos?$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_3:
# 1258 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prepárate para conocer la verdadera\n"
	.string "fuerza de la Jode Jode no Mi: Modelo\l"
	.string "Duende de La Buena Pipa.$"

CollaboratorsRoom_EventScript_Ryuzaki_IntroRematch_Text_4:
# 1263 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Las moscas no pueden simplemente\n"
	.string "echarse gafas para ver La Luz.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_0:
# 1297 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me fumigaste. Te salvaste de que no\n"
	.string "estamos en territorio ryutámico.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_1:
# 1302 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Ah? ¿No íbamos a pelear? Veo que has\n"
	.string "perfeccionado tus habilidades\l"
	.string "desinformativas…$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_2:
# 1306 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres una burla, asere. Recoge tu baraja.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_3:
# 1314 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hola querid{OA} coyote. No esperaba verte\n"
	.string "por aquí.\p"
	.string "De hecho, no esperaba verme a mí mismo\n"
	.string "ni pinga.$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_4:
# 1317 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La vida da más vueltas que una\n"
	.string "cantimplora, ¿verdad?$"

CollaboratorsRoom_EventScript_Ryuzaki_Text_5:
# 1320 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¿Yo? Oh, no te preocupes, no soy\n"
	.string "nadie sospechoso.$"

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_0:
# 1333 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Tú otra vez? Tienes un aura distinta a\n"
	.string "la primera vez...\p"
	.string "Y te aseguro que no son alucinaciones\n"
	.string "por el café.$"

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_1:
# 1341 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Esa mirada... no me digas que has ganado\n"
	.string "el desafío...\p"
	.string "¿De verdad eres el nuevo campeón?$"

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_2:
# 1343 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Esa mirada... no me digas que has ganado\n"
	.string "el desafío...\p"
	.string "¿De verdad eres la nueva campeona?$"

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_3:
# 1347 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya! No esperaba eso... Pero a que\n"
	.string "adivino: ¡No me has traído un café!$"

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_4:
# 1352 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Llevo aquí encerrado desde que\n"
	.string "empezamos el desarrollo ¡y ni siquiera\l"
	.string "puedes traerme un Latte templado!$"

CollaboratorsRoom_EventScript_Caco_IntroFirstBattle_Text_5:
# 1355 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Prepárate para sufrir la cólera del\n"
	.string "desarrollador sin cafeína!$"

CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_0:
# 1361 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Has probado ya el PC de la Sala de\n"
	.string "espera?\p"
	.string "Porque si sigues buscando el de los\n"
	.string "Centros Pokémon, vas list{OA}.$"

CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_1:
# 1363 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Me costó mil noches de insomnio y otros\n"
	.string "tantos cabezazos contra el teclado\l"
	.string "lograr que funcionara bien!$"

CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_2:
# 1366 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Así que ya estás tardando en ir a\n"
	.string "probarlo!$"

CollaboratorsRoom_EventScript_Caco_TalkOnly_Text_3:
# 1368 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Y ni se te ocurra asomar la nariz por\n"
	.string "aquí de nuevo si no es con una buena\l"
	.string "taza de café humeante en la mano.\l"
	.string "¡Venga, muévete!$"

CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_0:
# 1375 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Puaj! Este café sabe a rayos.\p"
	.string "Creo que lleva en la taza desde que\n"
	.string "empezamos, pero debo beberlo...\p"
	.string "Es lo único que mantiene mis neuronas\n"
	.string "conectadas.$"

CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_1:
# 1386 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Eyy! ¿No te han enseñado que no se\n"
	.string "debe escuchar a hurtadillas?$"

CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_2:
# 1388 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tu cara... me suena de verla antes. ¿Eras\n"
	.string "un{A} beta-tester o algo así?$"

CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_3:
# 1391 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bueno, ya que estás aquí, me vendrá\n"
	.string "bien para despejar la mente.$"

CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_4:
# 1402 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡No te servirá de nada haber programado\n"
	.string "tu victoria!$"

CollaboratorsRoom_EventScript_Caco_IntroRematch_Text_5:
# 1407 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Más te vale que la próxima vez traigas\n"
	.string "cafeína!$"

CollaboratorsRoom_EventScript_Caco_Text_0:
# 1452 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vale, lo admito... combates mejor de lo\n"
	.string "que yo programo.\p"
	.string "Pero sigo necesitando ese café.$"

CollaboratorsRoom_EventScript_Caco_Text_1:
# 1457 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lo ves? La falta de sueño me hace\n"
	.string "peligroso.\p"
	.string "¡Vuelve cuando tengas el café!$"

CollaboratorsRoom_EventScript_Notes_Text_0:
# 1475 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Las notas están llenas de tachones y\n"
	.string "dibujos extraños.\p"
	.string "Es imposible descifrar lo que quiso\n"
	.string "escribir.$"

CollaboratorsRoom_EventScript_MaidenPoster_Text_0:
# 1480 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El póster muestra a MAIDEN junto a su\n"
	.string "WOOPER variocolor.\p"
	.string "Detrás, se ve un hermoso {COLOR BLUE}cielo azul{COLOR DARK_GRAY}.$"

CollaboratorsRoom_EventScript_Library_Text_0:
# 1485 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La estantería está repleta de libros\n"
	.string "históricos de WAH.\p"
	.string "Uno parece hablar del origen de\n"
	.string "ELECTRODE SANDÍA.$"

CollaboratorsRoom_EventScript_Coffee_Text_0:
# 1490 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Es una taza de café. Parece estar\n"
	.string "hirviendo.$"

CollaboratorsRoom_EventScript_Projector_Text_0:
# 1495 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Parece un proyector de películas.\n"
	.string "Se encuentra apagado.$"

CollaboratorsRoom_EventScript_Desk_Text_0:
# 1500 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El cajón guarda antiguos bocetos y\n"
	.string "diseños.\p"
	.string "Muchos tienen escrito “cancelado” al\n"
	.string "costado.$"

CollaboratorsRoom_EventScript_Trash_Text_0:
# 1505 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La papelera está repleta de hojas\n"
	.string "tachadas.\p"
	.string "Da la impresión de que nada fue fácil de\n"
	.string "decidir.$"

CollaboratorsRoom_EventScript_Brainstorming_Text_0:
# 1510 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La pizarra está cubierta de diagramas y\n"
	.string "flechas.\p"
	.string "Parece una sesión de ideas llevada al\n"
	.string "extremo.$"

CollaboratorsRoom_EventScript_Desk2_Text_0:
# 1515 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El cajón guarda decenas de apuntes\n"
	.string "sobre combates y niveles.\p"
	.string "Parece que ajustar la dificultad tomó\n"
	.string "muchísimo tiempo.$"

CollaboratorsRoom_EventScript_Computer_Text_0:
# 1520 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La torre de la computadora hace un\n"
	.string "ruido constante y preocupante.\p"
	.string "Parece estar sobrecalentándose.$"

CollaboratorsRoom_EventScript_Notes2_Text_0:
# 1525 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Son varias hojas que se encuentran en\n"
	.string "el suelo.\p"
	.string "Parecen tener la partitura de una\n"
	.string "melodía bastante compleja.$"

CollaboratorsRoom_EventScript_Notes3_Text_0:
# 1530 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Son varias hojas que se encuentran en\n"
	.string "el suelo.\p"
	.string "Tienen un listado de Pokémon y sus\n"
	.string "estadísticas.\p"
	.string "Hay un Pokémon que se llama Latiken.$"

CollaboratorsRoom_EventScript_Notes4_Text_0:
# 1535 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Son varias hojas que se encuentran en\n"
	.string "el suelo.\p"
	.string "Tienen el plano del diseño de una sala,\n"
	.string "pero están tachados.$"

CollaboratorsRoom_EventScript_Notes5_Text_0:
# 1540 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Son varias hojas que se encuentran en\n"
	.string "el suelo.\p"
	.string "Tienen varias ideas que fueron\n"
	.string "descartadas.$"

CollaboratorsRoom_EventScript_Notes6_Text_0:
# 1545 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Son varias hojas que se encuentran en\n"
	.string "el suelo.\p"
	.string "Están vacías.$"

CollaboratorsRoom_EventScript_ExaminePaperScraps_Text_0:
# 1550 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hay pedazos de papel rotos esparcidos\n"
	.string "por el suelo.$"

CollaboratorsRoom_EventScript_NotesTable_Text_0:
# 1555 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Hay varios papeles con apuntes en la\n"
	.string "mesa.\p"
	.string "Incluye un listado de los Pokémon\n"
	.string "disponibles para el desafío.$"

CollaboratorsRoom_Text_Gameboycl_OnDefeat::
# 232 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

CollaboratorsRoom_RematchMultichoice_Rematch::
# 800 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Luchemos de nuevo!$"

CollaboratorsRoom_RematchMultichoice_TalkOnly::
# 804 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Prefiero simplemente hablar.$"

CollaboratorsRoom_RematchMultichoice_Exit::
# 808 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, gracias.$"

CollaboratorsRoom_Text_Alexmad_OnDefeat::
# 1012 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años de comunidad y aún me\n"
	.string "sorprenden.$"

CollaboratorsRoom_Text_Ryuzaki_OnDefeat::
# 1327 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ya sabes lo que dicen, la voluntad es la\n"
	.string "fuerza del alma.$"

CollaboratorsRoom_Text_Caco_OnDefeat::
# 1470 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A veces, para uno poder avanzar, debe\n"
	.string "de aceptar su error.$"
