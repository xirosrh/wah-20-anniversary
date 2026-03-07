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
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 40 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Kaktus::
# 45 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 46 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 47 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Kaktus_1
# 88 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 89 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 90 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 92 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 93 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 94 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_1:
# 48 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_5
# 51 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroFirstBattle
CollaboratorsRoom_EventScript_Kaktus_4:
# 54 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 55 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 56 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 57 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 58 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 59 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_Kaktus_Text_0
# 60 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 61 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 62 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 63 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Kaktus_9
# 77 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 78 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 80 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 82 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 83 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Kaktus_8:
# 85 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Kaktus_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Kaktus_5:
# 49 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Kaktus_IntroRematch
	goto CollaboratorsRoom_EventScript_Kaktus_4

CollaboratorsRoom_EventScript_Kaktus_9:
# 64 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 65 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XWithDelay48
# 66 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 67 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 68 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 69 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 70 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 71 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 72 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 73 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 74 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Kaktus_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_INMORTAL_KAKTUS
# 75 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS
	goto CollaboratorsRoom_EventScript_Kaktus_8


CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle::
# 100 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 101 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 102 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 103 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 104 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 105 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 106 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 107 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
	return


CollaboratorsRoom_EventScript_Gameboycl_IntroRematch::
# 112 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_GAMEBOY_CL
# 113 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 114 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 115 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_1
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 120 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_1:
# 116 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent::
# 125 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 126 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 127 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gameboycl::
# 133 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 134 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 135 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gameboycl_1
# 170 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 171 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 172 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 173 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 174 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 175 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 176 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_1:
# 136 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL, CollaboratorsRoom_EventScript_Gameboycl_5
# 139 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle
CollaboratorsRoom_EventScript_Gameboycl_4:
# 141 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 142 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 143 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 144 "data/maps/CollaboratorsRoom/scripts.pory"
	random 3
# 145 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 146 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 147 "data/maps/CollaboratorsRoom/scripts.pory"
	case 0, CollaboratorsRoom_EventScript_Gameboycl_10
# 149 "data/maps/CollaboratorsRoom/scripts.pory"
	case 1, CollaboratorsRoom_EventScript_Gameboycl_11
# 151 "data/maps/CollaboratorsRoom/scripts.pory"
	case 2, CollaboratorsRoom_EventScript_Gameboycl_12
CollaboratorsRoom_EventScript_Gameboycl_8:
# 154 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 155 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 156 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 157 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gameboycl_14
# 165 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
CollaboratorsRoom_EventScript_Gameboycl_13:
# 167 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gameboycl_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gameboycl_5:
# 137 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gameboycl_IntroRematch
	goto CollaboratorsRoom_EventScript_Gameboycl_4

CollaboratorsRoom_EventScript_Gameboycl_10:
# 148 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_1, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_11:
# 150 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_2, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_12:
# 152 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GAMEBOY_CL_3, CollaboratorsRoom_Text_Gameboycl_OnDefeat
	goto CollaboratorsRoom_EventScript_Gameboycl_8

CollaboratorsRoom_EventScript_Gameboycl_14:
# 158 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 159 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 160 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gameboycl_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GAMEBOY_CL
# 161 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 162 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 163 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL
	goto CollaboratorsRoom_EventScript_Gameboycl_13


CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle::
# 185 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 186 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 187 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 188 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 189 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
	return


CollaboratorsRoom_EventScript_Erkey_IntroRematch::
# 194 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 195 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 196 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_ERKEY
# 197 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 198 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 199 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_IntroRematch_1
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 208 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 209 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 210 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_IntroRematch_1:
# 200 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 201 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 203 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 204 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
	return


CollaboratorsRoom_EventScript_Erkey_OnFinishEvent::
# 215 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 216 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 217 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Erkey::
# 222 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 223 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 224 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Erkey_1
# 258 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 259 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 260 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 261 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 262 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 263 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 264 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_1:
# 225 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY, CollaboratorsRoom_EventScript_Erkey_5
# 228 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle
CollaboratorsRoom_EventScript_Erkey_4:
# 230 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 231 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 232 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 233 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 234 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 235 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_INVERSE_BATTLE
# 236 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_ERKEY, CollaboratorsRoom_EventScript_Erkey_Text_0
# 237 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_INVERSE_BATTLE
# 238 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 239 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 240 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 241 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Erkey_9
# 252 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 253 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 254 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
CollaboratorsRoom_EventScript_Erkey_8:
# 256 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Erkey_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Erkey_5:
# 226 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Erkey_IntroRematch
	goto CollaboratorsRoom_EventScript_Erkey_4

CollaboratorsRoom_EventScript_Erkey_9:
# 242 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 243 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SmileWithDelay48
# 244 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 245 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 246 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Erkey_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ERKEY
# 248 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 249 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 250 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY
	goto CollaboratorsRoom_EventScript_Erkey_8


CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle::
# 269 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 270 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 271 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 272 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0
# 274 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 275 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 276 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 277 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


CollaboratorsRoom_EventScript_Micolo_IntroRematch::
# 282 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 283 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_MICOLO
# 285 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 286 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 287 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_IntroRematch_1
# 291 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 292 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_IntroRematch_1:
# 288 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_Text_Micolo_ChoosePokemon, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
	return


CollaboratorsRoom_EventScript_Micolo_OnFinishEvent::
# 301 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 302 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 303 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_Micolo::
# 308 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 309 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 310 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Micolo_1
# 361 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 364 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 365 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 366 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 367 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 368 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 369 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 370 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 371 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 372 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 373 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 374 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_XD
# 375 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 376 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 377 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_Movement_0
# 379 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 380 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 381 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 382 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_1:
# 311 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO, CollaboratorsRoom_EventScript_Micolo_5
# 314 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle
CollaboratorsRoom_EventScript_Micolo_4:
# 316 "data/maps/CollaboratorsRoom/scripts.pory"
	special SavePlayerParty
# 317 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
# 318 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 319 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_0x8004, FRONTIER_LVL_OPEN
# 320 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 321 "data/maps/CollaboratorsRoom/scripts.pory"
	special ChoosePartyForBattleFrontier
# 322 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 323 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 324 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_9
# 332 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 333 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 334 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 335 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 336 "data/maps/CollaboratorsRoom/scripts.pory"
	special ReducePlayerPartyToSelectedMons
# 337 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 338 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_MICOLO, CollaboratorsRoom_EventScript_Micolo_Text_1
# 339 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 340 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 341 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 342 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 343 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Micolo_12
# 350 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 351 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 352 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 353 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 354 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 355 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_1
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 357 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
CollaboratorsRoom_EventScript_Micolo_11:
# 359 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Micolo_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Micolo_5:
# 312 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Micolo_IntroRematch
	goto CollaboratorsRoom_EventScript_Micolo_4

CollaboratorsRoom_EventScript_Micolo_9:
# 325 "data/maps/CollaboratorsRoom/scripts.pory"
	special LoadPlayerParty
# 326 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 327 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 328 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 329 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end

CollaboratorsRoom_EventScript_Micolo_12:
# 344 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 345 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Micolo_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MICOLO
# 347 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 348 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO
	goto CollaboratorsRoom_EventScript_Micolo_11


CollaboratorsRoom_EventScript_Lillipup::
# 387 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 388 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 389 "data/maps/CollaboratorsRoom/scripts.pory"
	playmoncry SPECIES_LILLIPUP, CRY_MODE_NORMAL
# 390 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Lillipup_Text_0, MSGBOX_AUTOCLOSE
# 391 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmoncry
# 392 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 393 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 394 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_EAST
# 395 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer::
# 400 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 401 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 402 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_NORTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3
# 405 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_SOUTH, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4
# 408 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5
# 411 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6
CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1:
	return

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_3:
# 403 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_4:
# 406 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceUp
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_5:
# 409 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceRight
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1

CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_6:
# 412 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WalkInPlaceLeft
	goto CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer_1


CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle::
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 420 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 421 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 422 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 423 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 424 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 425 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1
# 426 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 427 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_IntroRematch::
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_MRNIGHTOLOGY
# 433 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 434 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne CollaboratorsRoom_EventScript_MrNightology_IntroRematch_1
# 439 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 440 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_1:
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1, speaker = SP_NAME_MRNIGHTOLOGY
	return


CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent::
# 445 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 446 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_MrNightology::
# 451 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 452 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_MrNightology_1
# 549 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 550 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 551 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_10
# 553 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 554 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 555 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 556 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_11
# 557 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 559 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_1:
# 453 "data/maps/CollaboratorsRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 454 "data/maps/CollaboratorsRoom/scripts.pory"
	switch VAR_RESULT
# 455 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_WEST, CollaboratorsRoom_EventScript_MrNightology_6
# 460 "data/maps/CollaboratorsRoom/scripts.pory"
	case DIR_EAST, CollaboratorsRoom_EventScript_MrNightology_7
CollaboratorsRoom_EventScript_MrNightology_4:
# 467 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_9
# 471 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle
CollaboratorsRoom_EventScript_MrNightology_8:
# 474 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 475 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_2
# 476 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_ON
# 477 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_3
# 479 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 480 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_POKENAV_HANG_UP
# 481 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 483 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_WARP_OUT
# 484 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, 3
# 485 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_1
# 486 "data/maps/CollaboratorsRoom/scripts.pory"
	showobjectat LOCALID_COLLABORATORS_ROOM_REONEKY, MAP_COLLABORATORS_ROOM
# 487 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_REONEKY, DIR_SOUTH
# 488 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 489 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 490 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_BRENDAN_TELEPORTING_2
# 491 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 492 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 493 "data/maps/CollaboratorsRoom/scripts.pory"
	updateobjectsprite LOCALID_COLLABORATORS_ROOM_REONEKY, OBJ_EVENT_GFX_REONEKY
# 494 "data/maps/CollaboratorsRoom/scripts.pory"
	release
# 495 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_5
# 497 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_6
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_REONEKY
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 502 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_MRNIGHTOLOGY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 503 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_EventScript_MrNightology_Movement_4
# 504 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 506 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 507 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 508 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, Common_Movement_VersusWithDelay48
# 509 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 510 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 511 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 512 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 513 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_KAKTUS, CollaboratorsRoom_EventScript_MrNightology_Text_6
# 514 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 515 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 516 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 517 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_MrNightology_13
# 538 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 539 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 540 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 542 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 543 "data/maps/CollaboratorsRoom/scripts.pory"
	setobjectxy LOCALID_COLLABORATORS_ROOM_REONEKY, 9, -3
# 544 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
CollaboratorsRoom_EventScript_MrNightology_12:
# 546 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_MrNightology_OnFinishEvent
	return

CollaboratorsRoom_EventScript_MrNightology_6:
# 456 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_0
# 458 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_7:
# 461 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, CollaboratorsRoom_EventScript_MrNightology_Movement_1
# 463 "data/maps/CollaboratorsRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto CollaboratorsRoom_EventScript_MrNightology_4

CollaboratorsRoom_EventScript_MrNightology_9:
# 468 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_MrNightology_IntroRematch
	goto CollaboratorsRoom_EventScript_MrNightology_8

CollaboratorsRoom_EventScript_MrNightology_13:
# 518 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 519 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_Movement_MrNightology_Despegue
# 520 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_COLLABORATORS_ROOM_REONEKY, CollaboratorsRoom_Movement_MrNightology_Despegue
# 521 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 522 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_7, MSGBOX_AUTOCLOSE_TOP
# 524 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FALL
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_7
# 526 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_NOT_EFFECTIVE
# 527 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_8, MSGBOX_DEFAULT, speaker = SP_NAME_MRNIGHTOLOGY
# 529 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 530 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 531 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_8
# 532 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_Movement_9
# 534 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_MrNightology_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_MRNIGHTOLOGY
# 535 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY
	goto CollaboratorsRoom_EventScript_MrNightology_12


# 563 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_Movement_MrNightology_Despegue:
# 564 "data/maps/CollaboratorsRoom/scripts.pory"
	face_left
# 565 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 566 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 567 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 568 "data/maps/CollaboratorsRoom/scripts.pory"
	face_right
# 569 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_4
# 570 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 571 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_up
# 572 "data/maps/CollaboratorsRoom/scripts.pory"
	step_end

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle::
# 576 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 577 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SurpriseWithDelay48
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 579 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 580 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 581 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FaceAwayPlayer
# 582 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 583 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 584 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 585 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_FacePlayer
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 587 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 588 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 589 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 590 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 591 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Kaktus_Movement_0
# 592 "data/maps/CollaboratorsRoom/scripts.pory"
	waitse
# 593 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 594 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_Movement_0
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return


CollaboratorsRoom_EventScript_Gosuto_IntroRematch::
# 600 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 601 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_QuestionMarkWithDelay48
# 602 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0, MSGBOX_YESNO, speaker = SP_NAME_GOSUTO
# 603 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 604 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 605 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Gosuto_IntroRematch_1
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 610 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_1:
# 606 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
	return


CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent::
# 615 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_WEST
# 616 "data/maps/CollaboratorsRoom/scripts.pory"
	call Achievements_EventScript_Eval_DefeatAllCollaborators
# 617 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_Gosuto::
# 622 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 623 "data/maps/CollaboratorsRoom/scripts.pory"
	faceplayer
# 624 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, CollaboratorsRoom_EventScript_Gosuto_1
# 654 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 655 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 656 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 657 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 659 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 660 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 661 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 662 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 663 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 664 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HappyWithDelay48
# 665 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_1:
# 625 "data/maps/CollaboratorsRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_5
# 628 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle
CollaboratorsRoom_EventScript_Gosuto_4:
# 630 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 631 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_VersusWithDelay48
# 632 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_VersusWithDelay48
# 633 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 634 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag B_FLAG_NO_WHITEOUT
# 635 "data/maps/CollaboratorsRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_COLLABORATOR_GOSUTO, CollaboratorsRoom_EventScript_Gosuto_Text_0
# 636 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag B_FLAG_NO_WHITEOUT
# 637 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetBattleOutcome
# 638 "data/maps/CollaboratorsRoom/scripts.pory"
	special HealPlayerParty
# 639 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq CollaboratorsRoom_EventScript_Gosuto_9
# 648 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 649 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 650 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
CollaboratorsRoom_EventScript_Gosuto_8:
# 652 "data/maps/CollaboratorsRoom/scripts.pory"
	goto CollaboratorsRoom_EventScript_Gosuto_OnFinishEvent
	return

CollaboratorsRoom_EventScript_Gosuto_5:
# 626 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_Gosuto_IntroRematch
	goto CollaboratorsRoom_EventScript_Gosuto_4

CollaboratorsRoom_EventScript_Gosuto_9:
# 640 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 641 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 642 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 643 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Gosuto_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOSUTO
# 644 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 645 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_WinkWithDelay48
# 646 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO
	goto CollaboratorsRoom_EventScript_Gosuto_8


CollaboratorsRoom_EventScript_Alexmad::
# 671 "data/maps/CollaboratorsRoom/scripts.pory"
	lock
# 672 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 673 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 675 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 676 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 30
# 677 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 678 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0
# 679 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Alexmad_Movement_0
# 681 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 682 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovement VAR_LAST_TALKED, CollaboratorsRoom_EventScript_Micolo_Movement_0
# 683 "data/maps/CollaboratorsRoom/scripts.pory"
	waitmovement 0
# 684 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 685 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 686 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 687 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 688 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 689 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_IdeaWithDelay48
# 690 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 691 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 692 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 693 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 694 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 695 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 696 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 697 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 698 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 699 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 700 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 701 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 702 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_ThinkingWithDelay48
# 703 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 704 "data/maps/CollaboratorsRoom/scripts.pory"
	call CollaboratorsRoom_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 705 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 10
# 706 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_8, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
# 707 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 708 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_2
CollaboratorsRoom_EventScript_Alexmad_1:
# 738 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end

CollaboratorsRoom_EventScript_Alexmad_2:
# 709 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_9, speaker = SP_NAME_ALEXMAD
# 710 "data/maps/CollaboratorsRoom/scripts.pory"
	load_field_pic FP_MAD_QR, 120, 80
# 711 "data/maps/CollaboratorsRoom/scripts.pory"
	waitbuttonpress
# 712 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 713 "data/maps/CollaboratorsRoom/scripts.pory"
	destroy_field_pic FP_MAD_QR
# 714 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_10, MSGBOX_YESNO, speaker = SP_NAME_ALEXMAD
# 715 "data/maps/CollaboratorsRoom/scripts.pory"
	closemessage
# 716 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_4
	goto CollaboratorsRoom_EventScript_Alexmad_1

CollaboratorsRoom_EventScript_Alexmad_4:
# 717 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 718 "data/maps/CollaboratorsRoom/scripts.pory"
	special EnterCode
# 719 "data/maps/CollaboratorsRoom/scripts.pory"
	waitstate
# 720 "data/maps/CollaboratorsRoom/scripts.pory"
	special GetCodeFeedback
# 721 "data/maps/CollaboratorsRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq CollaboratorsRoom_EventScript_Alexmad_6
# 730 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 731 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 732 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_AnnoyedWithDelay48
# 733 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 734 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_NORTH
	goto CollaboratorsRoom_EventScript_Alexmad_1

CollaboratorsRoom_EventScript_Alexmad_6:
# 722 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_Alexmad_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 723 "data/maps/CollaboratorsRoom/scripts.pory"
	setflag FLAG_TEMP_ALEXMAD_PUZZLE_STARTED
# 724 "data/maps/CollaboratorsRoom/scripts.pory"
	clearflag FLAG_TEMP_ALEXMAD_PUZZLE_FAILED
# 725 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_ALEXMAD_PUZZLE_CHECKPOINT, 0
# 726 "data/maps/CollaboratorsRoom/scripts.pory"
	setvar VAR_ALEXMAD_PUZZLE_STEPS, 0
# 727 "data/maps/CollaboratorsRoom/scripts.pory"
	release
	end


CollaboratorsRoom_EventScript_AlexmadPuzzleComplete::
# 743 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 744 "data/maps/CollaboratorsRoom/scripts.pory"
	turnobject LOCALID_COLLABORATORS_ROOM_ALEXMAD, DIR_WEST
# 745 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 746 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_DoubleExclamationMark
# 747 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_PIN
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0
# 749 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_LEDGE
# 750 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1
# 752 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_SUCCESS
# 753 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 754 "data/maps/CollaboratorsRoom/scripts.pory"
	delay 20
# 755 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, Common_Movement_WalkLeft2
# 756 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	applymovementandwait LOCALID_COLLABORATORS_ROOM_ALEXMAD, CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_2
# 759 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


CollaboratorsRoom_EventScript_AlexmadPuzzleFailed::
# 764 "data/maps/CollaboratorsRoom/scripts.pory"
	lockall
# 765 "data/maps/CollaboratorsRoom/scripts.pory"
	playse SE_FAILURE
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	msgbox CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ALEXMAD
# 767 "data/maps/CollaboratorsRoom/scripts.pory"
	releaseall
	end


# 79 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_0:
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 79 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 81 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Kaktus_Movement_1:
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 81 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 273 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Movement_0:
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 273 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
	step_end

# 378 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Micolo_Movement_0:
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	unlock_facing_direction
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 378 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 421 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_0:
# 421 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
	step_end

# 425 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Movement_1:
# 425 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sweat_drop
	step_end

# 457 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_0:
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_left
# 457 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 462 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_1:
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_down
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 462 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 475 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_2:
# 475 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
	step_end

# 478 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_3:
# 478 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_up
	step_end

# 482 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_4:
# 482 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 496 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_5:
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_exclamation_mark
# 496 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
	step_end

# 499 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_6:
# 499 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
	step_end

# 525 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_7:
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	face_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
# 525 "data/maps/CollaboratorsRoom/scripts.pory"
	slide_down
	step_end

# 531 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_8:
# 531 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_question_mark
	step_end

# 533 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_9:
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_right
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_left
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
# 533 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_in_place_down
	step_end

# 552 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_10:
# 552 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_sad
	step_end

# 556 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_MrNightology_Movement_11:
# 556 "data/maps/CollaboratorsRoom/scripts.pory"
	emote_annoyed
	step_end

# 680 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_Alexmad_Movement_0:
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	face_player
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	lock_facing_direction
# 680 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_down
	step_end

# 748 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_0:
# 748 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_left
	step_end

# 750 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_1:
# 750 "data/maps/CollaboratorsRoom/scripts.pory"
	jump_in_place_left
# 750 "data/maps/CollaboratorsRoom/scripts.pory"
	delay_16
	step_end

# 758 "data/maps/CollaboratorsRoom/scripts.pory"
CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Movement_2:
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	walk_right
# 758 "data/maps/CollaboratorsRoom/scripts.pory"
	face_up
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
# 59 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Acaso perdí?$"

CollaboratorsRoom_EventScript_Kaktus_Text_1:
# 66 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ja… perdí.$"

CollaboratorsRoom_EventScript_Kaktus_Text_2:
# 70 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero esto es lo bonito de esta\n"
	.string "comunidad.\p"
	.string "Siempre hay alguien nuevo que te\n"
	.string "sorprende.$"

CollaboratorsRoom_EventScript_Kaktus_Text_3:
# 74 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Enhorabuena, crack.$"

CollaboratorsRoom_EventScript_Kaktus_Text_4:
# 77 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eres buen{OA}, pero aún te falta entrenar\n"
	.string "para poder vencerme.$"

CollaboratorsRoom_EventScript_Kaktus_Text_5:
# 82 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Espero la revancha pronto!$"

CollaboratorsRoom_EventScript_Kaktus_Text_6:
# 88 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Sabes? Mucha gente en la comunidad\n"
	.string "empezó viendo tutoriales míos.$"

CollaboratorsRoom_EventScript_Kaktus_Text_7:
# 91 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aunque si te soy sincero… el primero que\n"
	.string "hice me dio tanta verguenza que lo\l"
	.string "borré.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_0:
# 103 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No soy competitivo ni ambicioso. Soy\n"
	.string "más bien una persona mediocre.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroFirstBattle_Text_1:
# 107 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso puede jugarme en contra.$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_0:
# 112 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Kanto y Johto se unen en el mismo azul,\n"
	.string "el agua no recuerda fronteras.\p"
	.string "¿Quieres luchar contra uno de mis 3\n"
	.string "equipos?$"

CollaboratorsRoom_EventScript_Gameboycl_IntroRematch_Text_1:
# 119 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo mejor de la vida no es competir, sino\n"
	.string "compartir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_0:
# 160 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Definitivamente prefiero compartir por\n"
	.string "sobre competir.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_1:
# 165 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "PENDIENTE GAMEBOY$"

CollaboratorsRoom_EventScript_Gameboycl_Text_2:
# 170 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Un hack rom es como la arquitectura, se\n"
	.string "construye sobre lo existente.$"

CollaboratorsRoom_EventScript_Gameboycl_Text_3:
# 172 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El arte aquí no es lo que se cambia, sino\n"
	.string "lo que se quiere transmitir.$"

CollaboratorsRoom_EventScript_Erkey_IntroFirstBattle_Text_0:
# 187 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo fuerte será débil. Lo débil será\n"
	.string "decisivo.\p"
	.string "¡Prepárate para un {COLOR RED}combate inverso{COLOR DARK_GRAY}!$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_0:
# 196 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra vez?\n"
	.string "Las reglas siguen al revés… por si\l"
	.string "acaso.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_1:
# 202 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto. Veamos si esta vez lo\n"
	.string "dominas.$"

CollaboratorsRoom_EventScript_Erkey_IntroRematch_Text_2:
# 207 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando quieras.\n"
	.string "Aquí nada vuelve a la normalidad.$"

CollaboratorsRoom_EventScript_Erkey_Text_0:
# 236 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo has sabido manejar a la perfección.$"

CollaboratorsRoom_EventScript_Erkey_Text_1:
# 244 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien jugado. Cuando las reglas cambian,\n"
	.string "tú te adaptaste.$"

CollaboratorsRoom_EventScript_Erkey_Text_2:
# 247 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Eso es el espíritu de Whack a Hack.$"

CollaboratorsRoom_EventScript_Erkey_Text_3:
# 252 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "La costumbre pesa más de lo que parece.\n"
	.string "Aquí se paga caro.$"

CollaboratorsRoom_EventScript_Erkey_Text_4:
# 258 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí cada combate enseña algo.$"

CollaboratorsRoom_EventScript_Erkey_Text_5:
# 261 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Si prestas atención.$"

CollaboratorsRoom_EventScript_Micolo_IntroFirstBattle_Text_0:
# 275 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, has superado el desafío de las\n"
	.string "salas.\p"
	.string "Comprobemos pues si eres bueno con los\n"
	.string "Pokémon que he criado y entrenado.$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_0:
# 284 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otra batalla? Elegiré de nuevo un\n"
	.string "Pokémon de mi equipo al azar.\p"
	.string "¿Te atreves?$"

CollaboratorsRoom_EventScript_Micolo_IntroRematch_Text_1:
# 291 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Cuando quieras… Mis ejemplares no se\n"
	.string "van a poner peor por esperar.$"

CollaboratorsRoom_EventScript_Micolo_Text_0:
# 328 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te da miedo enfrentarte a uno de mis\n"
	.string "ejemplares? Con lo que te costó pasar\l"
	.string "las salas…$"

CollaboratorsRoom_EventScript_Micolo_Text_1:
# 338 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, me has ganado.$"

CollaboratorsRoom_EventScript_Micolo_Text_2:
# 346 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Admito que eres bueno, si contara con mi\n"
	.string "pequeñín seguro que te hubiera ganado,\l"
	.string "enhorabuena.$"

CollaboratorsRoom_EventScript_Micolo_Text_3:
# 356 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No lo haces mal, pero tendrás que\n"
	.string "hacerlo muchísimo mejor si quieres\l"
	.string "ganarme.$"

CollaboratorsRoom_EventScript_Micolo_Text_4:
# 363 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "A la mayoría de los de las salas no los\n"
	.string "conozco, solo a tres.\p"
	.string "Al resto hasta que no les entregué los\n"
	.string "Pokémon, no sabía quienes eran.$"

CollaboratorsRoom_EventScript_Micolo_Text_5:
# 366 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sí, la mayoría de los Pokémon en este\n"
	.string "edificio los crié yo, incluídos todos los\l"
	.string "que puedes llegar a usar.\p"
	.string "Todos entrenados por mí y listos para\n"
	.string "luchar.$"

CollaboratorsRoom_EventScript_Micolo_Text_6:
# 369 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "También ayudé al arquitecto del\n"
	.string "edificio a tener al Pokémon de sus\l"
	.string "sueños.\p"
	.string "No veas lo cansino que era hablando de\n"
	.string "la ilusión que le daría tenerlo e incluso\l"
	.string "presumirá de él en su sala como un\l"
	.string "hipócrita mientras se limpia las babas.$"

CollaboratorsRoom_EventScript_Micolo_Text_7:
# 372 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Lo que no sabe es que le di un ejemplar\n"
	.string "casi perfecto, el perfecto lo tengo\l"
	.string "guardado y listo para ayudarte cuando\l"
	.string "elijas su equipo.$"

CollaboratorsRoom_EventScript_Micolo_Text_8:
# 380 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "El resto fueron la mano de obra para\n"
	.string "construir este sitio.$"

CollaboratorsRoom_EventScript_Lillipup_Text_0:
# 390 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pup, pup, pup.$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_0:
# 419 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Buscas problemas?\n"
	.string "¡Pues escucha nuestro lema!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_1:
# 423 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Uy, me he equivocado!$"

CollaboratorsRoom_EventScript_MrNightology_IntroFirstBattle_Text_2:
# 427 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perdona, es la costumbre jeje…\p"
	.string "Bueno, por lo que veo has completado el\n"
	.string "desafío. ¡Enhorabuena!\p"
	.string "Pero… ¡será por poco tiempo!\n"
	.string "¡Ha llegado el momento de ponerte a\l"
	.string "prueba una vez más!$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_0:
# 432 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Tú otra vez! ¿Te has quedado con ganas\n"
	.string "de más?$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_1:
# 435 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Já! Si ya me lo imaginaba…$"

CollaboratorsRoom_EventScript_MrNightology_IntroRematch_Text_2:
# 439 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿No?\n"
	.string "Bueno… Ya volverás.$"

CollaboratorsRoom_EventScript_MrNightology_Text_0:
# 474 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo un plan genial para derrotarte y\n"
	.string "para eso lucharé con un amigo.\p"
	.string "Así que…\n"
	.string "¡Que aparezca el invitado especial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_1:
# 479 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Estás preparado?\n"
	.string "¿Sí? Genial.\p"
	.string "¡Vente p'acá!$"

CollaboratorsRoom_EventScript_MrNightology_Text_2:
# 498 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ostras!\n"
	.string "¿Cómo lo has hecho?$"

CollaboratorsRoom_EventScript_MrNightology_Text_3:
# 500 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Coño! Transmisión instantánea, bro.\n"
	.string "¡No me he pasado entrenando en el\l"
	.string "planeta Yardrat todo este tiempo pa ná!$"

CollaboratorsRoom_EventScript_MrNightology_Text_4:
# 501 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah, mira qué bien! ¡Eso me viene genial\n"
	.string "para que la próxima vez no acabe\l"
	.string "reventao con tantas horas de bus!$"

CollaboratorsRoom_EventScript_MrNightology_Text_5:
# 505 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sorprendido, ¿no?\n"
	.string "Pues ha llegado la hora…\p"
	.string "¡Prepárate para luchar!$"

CollaboratorsRoom_EventScript_MrNightology_Text_6:
# 513 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Qué? ¡Pero si era un plan genial!$"

CollaboratorsRoom_EventScript_MrNightology_Text_7:
# 523 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡El Team Rocket despega de nuevooooo…!$"

CollaboratorsRoom_EventScript_MrNightology_Text_8:
# 528 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Vaya aterrizaje!$"

CollaboratorsRoom_EventScript_MrNightology_Text_9:
# 534 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Y ReoNeky?\n"
	.string "Espero que haya aterrizado en su sala.$"

CollaboratorsRoom_EventScript_MrNightology_Text_10:
# 538 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Has hecho todo lo que has podido, pero\n"
	.string "no es suficiente.$"

CollaboratorsRoom_EventScript_MrNightology_Text_11:
# 541 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Dale una vuelta a tu estrategia y…\p"
	.string "¡No nos hagas esperar mucho para la\n"
	.string "revancha!$"

CollaboratorsRoom_EventScript_MrNightology_Text_12:
# 550 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ay, si te contase…\p"
	.string "La Beta 1 de mi hack la publiqué en 2010\n"
	.string "y 15 años después, conseguí acabarlo.$"

CollaboratorsRoom_EventScript_MrNightology_Text_13:
# 554 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Una larga travesía para que al final, la\n"
	.string "gente te pregunte cuál es el cheat de\l"
	.string "los caramelos infinitos.$"

CollaboratorsRoom_EventScript_MrNightology_Text_14:
# 558 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Te parece normal?\n"
	.string "En fin… La vida del romhacker.$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_0:
# 578 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Oh! Pues parece que has superado el\n"
	.string "desafío de las salas.\p"
	.string "¿Qué te parece si te ponemos a prueba y\n"
	.string "vemos de lo que eres capaz?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_1:
# 580 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Hacemos esto un poco más divertido?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_2:
# 586 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "O mejor dicho, ¿¡qué te parece si lo\n"
	.string "hacemos el doble de divertido!?$"

CollaboratorsRoom_EventScript_Gosuto_IntroFirstBattle_Text_3:
# 595 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Muy bien, entra al mundo de las\n"
	.string "tinieblas conmigo…$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_0:
# 602 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Otro combate? ¿Estás seguro de estar\n"
	.string "listo para entrar al mundo de las\l"
	.string "tinieblas?$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_1:
# 606 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Ok, veamos si esta vez logras superar\n"
	.string "tus miedos.$"

CollaboratorsRoom_EventScript_Gosuto_IntroRematch_Text_2:
# 609 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Bien pensado; aunque puedes volver\n"
	.string "cuando quieras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_0:
# 635 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Creo que ya superaste tus miedos y\n"
	.string "superaste las sombras.$"

CollaboratorsRoom_EventScript_Gosuto_Text_1:
# 643 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vaya, parece que encontraste una\n"
	.string "chispa de suerte.\p"
	.string "Aprovecha esa luz mientras puedas,\n"
	.string "porque las sombras son pacientes y las\l"
	.string "tinieblas siempre terminan ganando al\l"
	.string "final.$"

CollaboratorsRoom_EventScript_Gosuto_Text_2:
# 648 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No te sientas mal; no cualquiera\n"
	.string "sobrevive a mis tinieblas.$"

CollaboratorsRoom_EventScript_Gosuto_Text_3:
# 654 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Quizás me conoces, quizás no, pero no te\n"
	.string "culpo; paso como una sombra entre las\l"
	.string "tinieblas.$"

CollaboratorsRoom_EventScript_Gosuto_Text_4:
# 658 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Pero a pesar de permanecer entre las\n"
	.string "tinieblas, he aportado a grandes\l"
	.string "proyectos dando un pequeño grano de\l"
	.string "arena.$"

CollaboratorsRoom_EventScript_Gosuto_Text_5:
# 662 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Que no se diga más y a seguir\n"
	.string "procesando píxeles!$"

CollaboratorsRoom_EventScript_Alexmad_Text_0:
# 674 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Sm1, sm2… o sm3.$"

CollaboratorsRoom_EventScript_Alexmad_Text_1:
# 684 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "20 años… ¿te das cuenta?$"

CollaboratorsRoom_EventScript_Alexmad_Text_2:
# 686 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Aquí crecimos entre bugs, tiles mal\n"
	.string "alineados y scripts que se colgaban en\l"
	.string "el último mapa.$"

CollaboratorsRoom_EventScript_Alexmad_Text_3:
# 690 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Ah! Si ves a Baro por ahí… no intentes\n"
	.string "ser su amigo.\p"
	.string "Créeme, no termina bien.$"

CollaboratorsRoom_EventScript_Alexmad_Text_4:
# 694 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Y si te topas con Serg!o… salúdalo con\n"
	.string "respeto.\p"
	.string "Es leyenda.$"

CollaboratorsRoom_EventScript_Alexmad_Text_5:
# 697 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Todos le tenemos un cariño especial…\n"
	.string "Y no, no homo.$"

CollaboratorsRoom_EventScript_Alexmad_Text_6:
# 700 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me encanta la playa, hacer mapas bien\n"
	.string "locos y meter bosques dentro de\l"
	.string "cuevas.\p"
	.string "Eso dice muchas cosas de mí.$"

CollaboratorsRoom_EventScript_Alexmad_Text_7:
# 703 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Los hacks dicen muchas cosas de\n"
	.string "nosotros.\p"
	.string "Incluso en la vida real… nos hicieron\n"
	.string "mejores personas.$"

CollaboratorsRoom_EventScript_Alexmad_Text_8:
# 706 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Tengo para ti un evento al puro estilo\n"
	.string "del Mitic.\p"
	.string "Dime… ¿lo quieres hacer?$"

CollaboratorsRoom_EventScript_Alexmad_Text_9:
# 709 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Escanea el QR con tu móvil y nos vemos\n"
	.string "en el otro mundo.$"

CollaboratorsRoom_EventScript_Alexmad_Text_10:
# 714 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¿Lo viste?$"

CollaboratorsRoom_EventScript_Alexmad_Text_11:
# 717 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Entonces escribe la palabra que viste\n"
	.string "en el video.$"

CollaboratorsRoom_EventScript_Alexmad_Text_12:
# 722 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Perfecto… Veo que sí lo viste.\p"
	.string "Entonces sabes lo que tienes que hacer.$"

CollaboratorsRoom_EventScript_Alexmad_Text_13:
# 730 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No… Esa no es.$"

CollaboratorsRoom_EventScript_Alexmad_Text_14:
# 733 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Vuelve cuando tengas la respuesta\n"
	.string "correcta.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_0:
# 753 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "¡Lo has logrado! Veo que eres buen{OA}.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleComplete_Text_1:
# 756 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Me recuerdas a KODER. Siempre fue bueno\n"
	.string "con los acertijos.\p"
	.string "Quizás pueda ayudarte en tu camino.$"

CollaboratorsRoom_EventScript_AlexmadPuzzleFailed_Text_0:
# 766 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "No, no… así no es.\p"
	.string "Vuelve a hablarme si quieres intentarlo\n"
	.string "de nuevo.$"

CollaboratorsRoom_Text_Gameboycl_OnDefeat::
# 180 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Evolucionar también es mirar atrás.$"

CollaboratorsRoom_Text_Micolo_ChoosePokemon::
# 296 "data/maps/CollaboratorsRoom/scripts.pory"
	.string "Luchemos con un Pokémon cada uno.\n"
	.string "Selecciona el tuyo, ¡yo elegiré uno de mi\l"
	.string "equipo al azar!$"
