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
# 28 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVI4315, MOVEMENT_TYPE_FACE_DOWN
# 29 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVS, MOVEMENT_TYPE_FACE_DOWN
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
# 35 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


JavsJavi4315Room_EventScript_MainTrigger::
# 40 "data/maps/JavsJavi4315Room/scripts.pory"
	lockall
# 41 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_EventScript_MainTrigger_2
# 45 "data/maps/JavsJavi4315Room/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 46 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 48 "data/maps/JavsJavi4315Room/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	special SpawnCameraObject
# 50 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtopos 3, 4
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 52 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_0, speaker = SP_NAME_JAVI4315
# 53 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_0
# 55 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 56 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_1
# 58 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 59 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 60 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 61 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 62 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AngryWithDelay48
# 63 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 64 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_WEST
# 65 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 66 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceLeft
# 67 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 68 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_NORTH
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_NORTH
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AnnoyedWithDelay48
# 73 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 50
# 74 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 75 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 76 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 77 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 78 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_DoubleExclamationMarkWithDelay48
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_DoubleExclamationMarkWithDelay48
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 81 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_2
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_3
# 84 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 85 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 5, 5
# 86 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 7, 5
# 87 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_0, VAR_TEMP_1
# 88 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 89 "data/maps/JavsJavi4315Room/scripts.pory"
	special RemoveCameraObject
# 90 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 92 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 93 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 94 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 95 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 96 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 97 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 98 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 99 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 100 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 101 "data/maps/JavsJavi4315Room/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 102 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 103 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 104 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 105 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 106 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_JumpInPlaceDown
# 107 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 108 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 110 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 112 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 113 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 114 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 115 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 116 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 117 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_QuestionMarkWithDelay48
# 118 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 119 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 121 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 122 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkDown
# 123 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkDown
# 124 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 125 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 126 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 127 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 128 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 129 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 130 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 131 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_5
# 133 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_5
# 134 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 135 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 136 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 137 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_6
# 138 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_6
# 139 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 141 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_JavsJavi4315Battle
# 142 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_PostBattle
# 143 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end

JavsJavi4315Room_EventScript_MainTrigger_2:
# 42 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end


JavsJavi4315Room_EventScript_JavsJavi4315Battle::
# 148 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, JavsJavi4315Room_EventScript_JavsJavi4315Battle_2
# 151 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JAVI4315
# 152 "data/maps/JavsJavi4315Room/scripts.pory"
	special ShouldUseAlternativeTeam
# 153 "data/maps/JavsJavi4315Room/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 154 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JAVS
# 155 "data/maps/JavsJavi4315Room/scripts.pory"
	special ShouldUseAlternativeTeam
# 157 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_5
# 164 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_11
# 167 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE, JavsJavi4315Room_Text_JavsDefeated
JavsJavi4315Room_EventScript_JavsJavi4315Battle_1:
	return

JavsJavi4315Room_EventScript_JavsJavi4315Battle_2:
# 149 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_5:
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_8
# 161 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_8:
# 159 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_11:
# 165 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1


JavsJavi4315Room_EventScript_PostBattle::
# 183 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 185 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 186 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 187 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 40
# 188 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 189 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 190 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 191 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_SweatDropWithDelay48
# 192 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 193 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 194 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceRight
# 195 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 196 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkUp
# 197 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 198 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 199 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_ThinkingWithDelay48
# 200 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 201 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_1
# 202 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 203 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 204 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 205 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_2
# 206 "data/maps/JavsJavi4315Room/scripts.pory"
	waitse
# 207 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 208 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_3
# 209 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 210 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 211 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 212 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 213 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 214 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 215 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_OpenDoor
# 216 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 217 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 218 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 219 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVI4315, MOVEMENT_TYPE_FACE_DOWN
# 220 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype2 LOCALID_JAVSJAVIROOM_JAVI4315, MOVEMENT_TYPE_FACE_DOWN
# 221 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVS, MOVEMENT_TYPE_FACE_DOWN
# 222 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype2 LOCALID_JAVSJAVIROOM_JAVS, MOVEMENT_TYPE_FACE_DOWN
# 223 "data/maps/JavsJavi4315Room/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 224 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_TEMP_2, 1
# 225 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	return


JavsJavi4315Room_EventScript_Javi4315::
# 230 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javi4315_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVI4315
	end


JavsJavi4315Room_EventScript_Javs::
# 235 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javs_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVS
	end


JavsJavi4315Room_EventScript_PikachuPainting::
# 240 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PikachuPainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_SmearglePainting::
# 245 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_SmearglePainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_EeveePainting::
# 250 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_EeveePainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_MunchlaxPainting::
# 255 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MunchlaxPainting_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_Boxes1::
# 261 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Boxes1_Text_0, MSGBOX_SIGN
	end


JavsJavi4315Room_EventScript_Boxes2::
# 266 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Boxes2_Text_0, MSGBOX_SIGN
	end


# 54 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_0:
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
	step_end

# 57 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_1:
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
	step_end

# 82 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_2:
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 83 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_3:
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
	step_end

# 91 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_4:
# 91 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
	step_end

# 132 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_5:
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 137 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_6:
# 137 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_versus
	step_end

# 184 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_0:
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_surprise
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_up
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	face_down
	step_end

# 201 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_1:
# 201 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 201 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 201 "data/maps/JavsJavi4315Room/scripts.pory"
	face_left
	step_end

# 205 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_2:
# 205 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_happy
	step_end

# 208 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_3:
# 208 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_in_place_right
# 208 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 208 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

JavsJavi4315Room_EventScript_MainTrigger_Text_0:
# 52 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Dude… what amazing tiles they gave us\n"
	.string "in here!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_1:
# 60 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "They're super cool, right, Javier?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_2:
# 65 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "My name's not Javier…$"

JavsJavi4315Room_EventScript_MainTrigger_Text_3:
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "And that's not all - look at those\n"
	.string "palettes! So well contrasted and\l"
	.string "shaded… are they private?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_4:
# 96 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Well… someone finally wandered in here!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_5:
# 99 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Did you know that, of all the\n"
	.string "misfortunes that could've happened to\l"
	.string "you today, landing on our floor was the\l"
	.string "worst?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_6:
# 103 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "You've never seen a team battle like\n"
	.string "ours, not even in your wildest dreams…\p"
	.string "And you won't see it again, so enjoy it!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_7:
# 108 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Here strategy rules - don't you forget\n"
	.string "it!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_8:
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Ready, Javs?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_9:
# 114 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Ready, Javi69!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_10:
# 125 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Now!$"

JavsJavi4315Room_EventScript_PostBattle_Text_0:
# 189 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "I spent weeks planning this strategy…\p"
	.string "I admit that hurt more than I expected.$"

JavsJavi4315Room_EventScript_PostBattle_Text_1:
# 195 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "And I built my team exactly like you\n"
	.string "asked me to!$"

JavsJavi4315Room_EventScript_PostBattle_Text_2:
# 197 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "The opening was perfect: sun up and\n"
	.string "pressure from turn one.\p"
	.string "What could I have done wrong?$"

JavsJavi4315Room_EventScript_PostBattle_Text_3:
# 202 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "The strategy was fine, but we simply\n"
	.string "had an opponent that was too strong.$"

JavsJavi4315Room_EventScript_PostBattle_Text_4:
# 207 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "At least we had fun!$"

JavsJavi4315Room_EventScript_PostBattle_Text_5:
# 214 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "We'll open the door for you - you're less\n"
	.string "than halfway from the end now.$"

JavsJavi4315Room_EventScript_PostBattle_Text_6:
# 218 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "We'll stay around here admiring the\n"
	.string "room.$"

JavsJavi4315Room_EventScript_Javi4315_Text_0:
# 230 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "I always wanted to create something\n"
	.string "that felt {COLOR GREEN}immortal{COLOR DARK_GRAY}.\p"
	.string "I guess that's why I'm still here,\n"
	.string "turning it all over in my head.$"

JavsJavi4315Room_EventScript_Javs_Text_0:
# 235 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Do you like how the room looks?\p"
	.string "Don't you dare copy its colors without\n"
	.string "my permission!$"

JavsJavi4315Room_EventScript_PikachuPainting_Text_0:
# 240 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Interesting, a Pikachu with both ears…$"

JavsJavi4315Room_EventScript_SmearglePainting_Text_0:
# 245 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "They say a true artist doesn't sign\n"
	.string "their work… but signing it with your tail\l"
	.string "must be another level.$"

JavsJavi4315Room_EventScript_EeveePainting_Text_0:
# 250 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "This Eevee probably hasn't decided\n"
	.string "what to evolve into because first it\l"
	.string "wants to explore its artistic phase…$"

JavsJavi4315Room_EventScript_MunchlaxPainting_Text_0:
# 255 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "This painting radiates peace, nature,\n"
	.string "and hunger… mostly hunger.$"

JavsJavi4315Room_EventScript_Boxes1_Text_0:
# 261 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "One box has a label that reads: “Do not\n"
	.string "stack.”\p"
	.string "Naturally, it has another box on top of\n"
	.string "it.$"

JavsJavi4315Room_EventScript_Boxes2_Text_0:
# 266 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "There are several carefully sealed\n"
	.string "boxes.\p"
	.string "They probably hold frames, catalogs,\n"
	.string "and works that haven't been mounted\l"
	.string "yet.$"

JavsJavi4315Room_Text_Javi4315Defeated::
# 174 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Did we actually lose, Javs?$"

JavsJavi4315Room_Text_JavsDefeated::
# 178 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "How can this be? My strategy was\n"
	.string "foolproof!$"
