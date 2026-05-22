JavsJavi4315Room_MapScripts::
# 4 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JavsJavi4315Room_OnTransition
# 8 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JavsJavi4315Room_OnLoad
# 5 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, JavsJavi4315Room_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

JavsJavi4315Room_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 6 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, JavsJavi4315Room_OnWarp_PlayerTurnNorth
	.2byte 0


JavsJavi4315Room_OnLoad::
# 12 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_OnLoad_2
JavsJavi4315Room_OnLoad_1:
	end

JavsJavi4315Room_OnLoad_2:
# 13 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto JavsJavi4315Room_OnLoad_1


JavsJavi4315Room_OnTransition::
# 19 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_JavsJavi
# 20 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_OnTransition_2
JavsJavi4315Room_OnTransition_1:
	end

JavsJavi4315Room_OnTransition_2:
# 21 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxy LOCALID_JAVSJAVIROOM_JAVI4315, 2, 3
# 22 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxy LOCALID_JAVSJAVIROOM_JAVS, 3, 3
# 23 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 2, 3
# 24 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 3, 3
# 25 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVI4315, MOVEMENT_TYPE_FACE_UP
# 26 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVS, MOVEMENT_TYPE_FACE_UP
	goto JavsJavi4315Room_OnTransition_1


JavsJavi4315Room_OnWarp_PlayerTurnNorth::
# 32 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


JavsJavi4315Room_EventScript_MainTrigger::
# 37 "data/maps/JavsJavi4315Room/scripts.pory"
	lockall
# 38 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_EventScript_MainTrigger_2
# 42 "data/maps/JavsJavi4315Room/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 43 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 44 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 45 "data/maps/JavsJavi4315Room/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 46 "data/maps/JavsJavi4315Room/scripts.pory"
	special SpawnCameraObject
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtopos 3, 4
# 48 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_0, speaker = SP_NAME_JAVI4315
# 50 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_0
# 52 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 53 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_1
# 55 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 56 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 58 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 59 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AngryWithDelay48
# 60 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 61 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_WEST
# 62 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 63 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceLeft
# 64 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 65 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_NORTH
# 66 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_NORTH
# 67 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 68 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AnnoyedWithDelay48
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 50
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 73 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 74 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 75 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_DoubleExclamationMarkWithDelay48
# 76 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_DoubleExclamationMarkWithDelay48
# 77 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 78 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_2
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_3
# 81 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 5, 5
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 7, 5
# 84 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_0, VAR_TEMP_1
# 85 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 86 "data/maps/JavsJavi4315Room/scripts.pory"
	special RemoveCameraObject
# 87 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 88 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 89 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 90 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 92 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 93 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 94 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 95 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 96 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 97 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 98 "data/maps/JavsJavi4315Room/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 99 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 100 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 101 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 102 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 103 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_JumpInPlaceDown
# 104 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 105 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 106 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 107 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 108 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 110 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 112 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 113 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 114 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_QuestionMarkWithDelay48
# 115 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 116 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 117 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 118 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 119 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkDown
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkDown
# 121 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 122 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 123 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 124 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 125 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 126 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 127 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 128 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 129 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_5
# 130 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_5
# 131 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 133 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 134 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_6
# 135 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_6
# 136 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 137 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 138 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_JavsJavi4315Battle
# 139 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_PostBattle
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end

JavsJavi4315Room_EventScript_MainTrigger_2:
# 39 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end


JavsJavi4315Room_EventScript_JavsJavi4315Battle::
# 145 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, JavsJavi4315Room_EventScript_JavsJavi4315Battle_2
# 148 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JAVI4315
# 149 "data/maps/JavsJavi4315Room/scripts.pory"
	special ShouldUseAlternativeTeam
# 150 "data/maps/JavsJavi4315Room/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 151 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JAVS
# 152 "data/maps/JavsJavi4315Room/scripts.pory"
	special ShouldUseAlternativeTeam
# 154 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_5
# 161 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_11
# 164 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE, JavsJavi4315Room_Text_JavsDefeated
JavsJavi4315Room_EventScript_JavsJavi4315Battle_1:
	return

JavsJavi4315Room_EventScript_JavsJavi4315Battle_2:
# 146 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_5:
# 155 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_8
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_8:
# 156 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_11:
# 162 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1


JavsJavi4315Room_EventScript_PostBattle::
# 180 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 182 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 183 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 40
# 185 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 186 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 187 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 188 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_SweatDropWithDelay48
# 189 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 190 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 191 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceRight
# 192 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 193 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkUp
# 194 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 195 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 196 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_ThinkingWithDelay48
# 197 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 198 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_1
# 199 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 200 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 201 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 202 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_2
# 203 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 204 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 205 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_3
# 206 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 207 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 208 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 209 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 210 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 211 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 212 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_OpenDoor
# 213 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 214 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 215 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 216 "data/maps/JavsJavi4315Room/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 217 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_TEMP_2, 1
# 218 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	return


JavsJavi4315Room_EventScript_Javi4315::
# 223 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javi4315_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVI4315
	end


JavsJavi4315Room_EventScript_Javs::
# 228 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javs_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVS
	end


JavsJavi4315Room_EventScript_PikachuPainting::
# 233 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PikachuPainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_SmearglePainting::
# 238 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_SmearglePainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_EeveePainting::
# 243 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_EeveePainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_MunchlaxPainting::
# 248 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MunchlaxPainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_Boxes1::
# 254 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Boxes1_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_Boxes2::
# 259 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Boxes2_Text_0, MSGBOX_SIGN
	end


# 51 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_0:
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
	step_end

# 54 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_1:
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
	step_end

# 79 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_2:
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 80 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_3:
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
	step_end

# 88 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_4:
# 88 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
	step_end

# 129 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_5:
# 129 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 129 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 134 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_6:
# 134 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_versus
	step_end

# 181 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_0:
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_surprise
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_up
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	face_down
	step_end

# 198 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_1:
# 198 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 198 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 198 "data/maps/JavsJavi4315Room/scripts.pory"
	face_left
	step_end

# 202 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_2:
# 202 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_happy
	step_end

# 205 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_3:
# 205 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_in_place_right
# 205 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 205 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

JavsJavi4315Room_EventScript_MainTrigger_Text_0:
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Tío… ¡pero qué pedazo de tiles nos han\n"
	.string "colocado aquí!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_1:
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "A que molan mucho, ¿verdad, Javier?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_2:
# 62 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Que no me llamo Javier…$"

JavsJavi4315Room_EventScript_MainTrigger_Text_3:
# 67 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Y eso no es todo, ¡mira esas paletas!\n"
	.string "Tan bien contrastadas y matizadas…\l"
	.string "¿serán privadas?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_4:
# 93 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Hombre… ¡hasta que alguien ha caído por\n"
	.string "aquí!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_5:
# 96 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Sabías que, de todas las desgracias\n"
	.string "que te pudieron haber pasado hoy, caer\l"
	.string "en nuestro piso era la peor?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_6:
# 100 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "No has presenciado un enfrentamiento\n"
	.string "en equipos como el nuestro ni en tus\l"
	.string "mejores sueños…\p"
	.string "¡Y no volverás a verlo, así que\n"
	.string "disfrútalo!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_7:
# 105 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Aquí la estrategia manda, ¡que no se te\n"
	.string "olvide!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_8:
# 108 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Listo, Javs?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_9:
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Listo, Javi69!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_10:
# 122 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Ahora!$"

JavsJavi4315Room_EventScript_PostBattle_Text_0:
# 186 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Me pasé semanas planeando esta\n"
	.string "estrategia…\p"
	.string "Admito que eso ha dolido más de lo que\n"
	.string "esperaba.$"

JavsJavi4315Room_EventScript_PostBattle_Text_1:
# 192 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Y eso que armé mi equipo exactamente\n"
	.string "como me pediste!$"

JavsJavi4315Room_EventScript_PostBattle_Text_2:
# 194 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "La apertura era perfecta: sol activo y\n"
	.string "presión desde el turno uno.\p"
	.string "¿Qué habré hecho mal?$"

JavsJavi4315Room_EventScript_PostBattle_Text_3:
# 199 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "La estrategia estuvo bien, pero\n"
	.string "simplemente tuvimos un{A} oponente\l"
	.string "demasiado fuerte.$"

JavsJavi4315Room_EventScript_PostBattle_Text_4:
# 204 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Al menos nos divertimos!$"

JavsJavi4315Room_EventScript_PostBattle_Text_5:
# 211 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Te abriremos la puerta, que ya te falta\n"
	.string "menos de la mitad.$"

JavsJavi4315Room_EventScript_PostBattle_Text_6:
# 215 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Nosotros nos quedaremos por aquí\n"
	.string "contemplando la sala.$"

JavsJavi4315Room_EventScript_Javi4315_Text_0:
# 223 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Siempre quise crear algo que se sintiera\n"
	.string "{COLOR GREEN}inmortal{COLOR DARK_GRAY}.\p"
	.string "Supongo que por eso sigo aquí, dándole\n"
	.string "vueltas a todo.$"

JavsJavi4315Room_EventScript_Javs_Text_0:
# 228 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Te gusta cómo se ve la sala? ¡Ni se te\n"
	.string "ocurra copiar sus colores sin mi\l"
	.string "permiso!$"

JavsJavi4315Room_EventScript_PikachuPainting_Text_0:
# 233 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Interesante, un Pikachu con ambas\n"
	.string "orejas…$"

JavsJavi4315Room_EventScript_SmearglePainting_Text_0:
# 238 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Dicen que un verdadero artista no firma\n"
	.string "sus obras… pero firmarlas con la cola\l"
	.string "debe ser otro nivel.$"

JavsJavi4315Room_EventScript_EeveePainting_Text_0:
# 243 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Seguramente este Eevee aún no decide\n"
	.string "en qué evolucionar porque primero\l"
	.string "quiere explorar su etapa artística…$"

JavsJavi4315Room_EventScript_MunchlaxPainting_Text_0:
# 248 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Este cuadro transmite paz, naturaleza\n"
	.string "y hambre… principalmente hambre.$"

JavsJavi4315Room_EventScript_Boxes1_Text_0:
# 254 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Una caja tiene una etiqueta que dice:\n"
	.string "“No apilar”.\p"
	.string "Naturalmente, tiene otra caja encima.$"

JavsJavi4315Room_EventScript_Boxes2_Text_0:
# 259 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Hay varias cajas cuidadosamente\n"
	.string "selladas.\p"
	.string "Probablemente guardan marcos,\n"
	.string "catálogos y obras que aún no fueron\l"
	.string "montadas.$"

JavsJavi4315Room_Text_Javi4315Defeated::
# 171 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Acaso hemos perdido, Javs?$"

JavsJavi4315Room_Text_JavsDefeated::
# 175 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Cómo puede ser? ¡Mi estrategia era\n"
	.string "infalible!$"
