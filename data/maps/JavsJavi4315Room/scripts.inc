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
	goto_if_unset FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_OnTransition_2
JavsJavi4315Room_OnTransition_1:
	end

JavsJavi4315Room_OnTransition_2:
# 20 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxy LOCALID_JAVSJAVIROOM_JAVI4315, 3, 3
# 21 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxy LOCALID_JAVSJAVIROOM_JAVS, 4, 3
# 22 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 3, 3
# 23 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 4, 3
# 24 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVI4315, MOVEMENT_TYPE_FACE_UP
# 25 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVS, MOVEMENT_TYPE_FACE_UP
	goto JavsJavi4315Room_OnTransition_1


JavsJavi4315Room_OnWarp_PlayerTurnNorth::
# 31 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


JavsJavi4315Room_EventScript_MainTrigger::
# 36 "data/maps/JavsJavi4315Room/scripts.pory"
	lockall
# 37 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_EventScript_MainTrigger_2
# 41 "data/maps/JavsJavi4315Room/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 42 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 43 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 44 "data/maps/JavsJavi4315Room/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 45 "data/maps/JavsJavi4315Room/scripts.pory"
	special SpawnCameraObject
# 46 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtopos 4, 4
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 48 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_0, speaker = SP_NAME_JAVI4315
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_0
# 50 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 52 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 53 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AngryWithDelay48
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 55 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_WEST
# 56 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceLeft
# 58 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 59 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_NORTH
# 60 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_NORTH
# 61 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 62 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 63 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AnnoyedWithDelay48
# 64 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 50
# 65 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 66 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 67 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 68 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_DoubleExclamationMarkWithDelay48
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_DoubleExclamationMarkWithDelay48
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_1
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_2
# 73 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 74 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 5, 5
# 75 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 7, 5
# 76 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_0, VAR_TEMP_1
# 77 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 78 "data/maps/JavsJavi4315Room/scripts.pory"
	special RemoveCameraObject
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_3
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 81 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 84 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 85 "data/maps/JavsJavi4315Room/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 86 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 87 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 88 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 89 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 90 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_JumpInPlaceDown
# 91 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 92 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 93 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 94 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 95 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 96 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 97 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 98 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 99 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 100 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 101 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 102 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_QuestionMarkWithDelay48
# 103 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 104 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 105 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 106 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkDown
# 107 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkDown
# 108 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 110 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 112 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 113 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 114 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_JavsJavi4315Battle
# 115 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_PostBattle
# 116 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end

JavsJavi4315Room_EventScript_MainTrigger_2:
# 38 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end


JavsJavi4315Room_EventScript_JavsJavi4315Battle::
# 121 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, JavsJavi4315Room_EventScript_JavsJavi4315Battle_2
# 124 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JAVI4315
# 125 "data/maps/JavsJavi4315Room/scripts.pory"
	special ShouldUseAlternativeTeam
# 126 "data/maps/JavsJavi4315Room/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 127 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JAVS
# 128 "data/maps/JavsJavi4315Room/scripts.pory"
	special ShouldUseAlternativeTeam
# 130 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_5
# 137 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_11
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE, JavsJavi4315Room_Text_JavsDefeated
JavsJavi4315Room_EventScript_JavsJavi4315Battle_1:
# 144 "data/maps/JavsJavi4315Room/scripts.pory"
	special HealPlayerParty
	return

JavsJavi4315Room_EventScript_JavsJavi4315Battle_2:
# 122 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_5:
# 131 "data/maps/JavsJavi4315Room/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JavsJavi4315Room_EventScript_JavsJavi4315Battle_8
# 134 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_ALTERNATIVE, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_8:
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1

JavsJavi4315Room_EventScript_JavsJavi4315Battle_11:
# 138 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_ALTERNATIVE, JavsJavi4315Room_Text_Javi4315Defeated, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_Text_JavsDefeated
	goto JavsJavi4315Room_EventScript_JavsJavi4315Battle_1


JavsJavi4315Room_EventScript_PostBattle::
# 157 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 159 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 160 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 161 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 40
# 162 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 163 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 164 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 165 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_SweatDropWithDelay48
# 166 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 167 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceRight
# 168 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 169 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkUp
# 170 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 171 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 172 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_ThinkingWithDelay48
# 173 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 174 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_1
# 175 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 176 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 177 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 178 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_2
# 179 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 180 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 181 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 182 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 183 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 184 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 185 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 186 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 187 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 188 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_OpenDoor
# 189 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 190 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 191 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 192 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 193 "data/maps/JavsJavi4315Room/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 194 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_TEMP_2, 1
	return


JavsJavi4315Room_EventScript_Javi4315::
# 199 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javi4315_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVI4315
	end


JavsJavi4315Room_EventScript_Javs::
# 204 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javs_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVS
	end


# 49 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_0:
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
	step_end

# 71 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_1:
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 72 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_2:
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
	step_end

# 79 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_3:
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
	step_end

# 111 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_4:
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_versus
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 158 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_0:
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_surprise
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_up
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
# 158 "data/maps/JavsJavi4315Room/scripts.pory"
	face_down
	step_end

# 174 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_1:
# 174 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 174 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 174 "data/maps/JavsJavi4315Room/scripts.pory"
	face_left
	step_end

# 178 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_2:
# 178 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_happy
# 178 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_in_place_right
# 178 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 178 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

JavsJavi4315Room_EventScript_MainTrigger_Text_0:
# 48 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Tío… ¡pero qué pedazo de tiles nos han\n"
	.string "colocado aquí!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_1:
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "A que molan mucho, ¿verdad, Javier?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_2:
# 56 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Que no me llamo Javier…$"

JavsJavi4315Room_EventScript_MainTrigger_Text_3:
# 61 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Y eso no es todo, ¡mira esas paletas!\n"
	.string "Tan bien contrastadas y matizadas…\l"
	.string "¿serán privadas?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_4:
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Hombre… ¡hasta que alguien ha caído por\n"
	.string "aquí!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_5:
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Sabías que, de todas las desgracias\n"
	.string "que te pudieron haber pasado hoy, caer\l"
	.string "en nuestro piso era la peor?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_6:
# 87 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "No has presenciado un enfrentamiento\n"
	.string "en equipos como el nuestro ni en tus\l"
	.string "mejores sueños…\p"
	.string "¡Y no volverás a verlo, así que\n"
	.string "disfrútalo!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_7:
# 91 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Aquí la estrategia manda, ¡que no se te\n"
	.string "olvide!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_8:
# 95 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Listo, Javs?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_9:
# 99 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Listo, Javi69!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_10:
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Ahora!$"

JavsJavi4315Room_EventScript_PostBattle_Text_0:
# 163 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Me pasé semanas planeando esta\n"
	.string "estrategia… Admito que eso ha dolido\l"
	.string "más de lo que esperaba.$"

JavsJavi4315Room_EventScript_PostBattle_Text_1:
# 168 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Y eso que armé mi equipo exactamente\n"
	.string "como me pediste!$"

JavsJavi4315Room_EventScript_PostBattle_Text_2:
# 170 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "La apertura era perfecta: sol activo y\n"
	.string "presión desde el turno uno. ¿Qué habré\l"
	.string "hecho mal?$"

JavsJavi4315Room_EventScript_PostBattle_Text_3:
# 175 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "La estrategia estuvo bien, pero\n"
	.string "simplemente tuvimos un{A} oponente\l"
	.string "demasiado fuerte.$"

JavsJavi4315Room_EventScript_PostBattle_Text_4:
# 179 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Al menos nos divertimos!$"

JavsJavi4315Room_EventScript_PostBattle_Text_5:
# 186 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Te abriremos la puerta, que ya te falta\n"
	.string "menos de la mitad.$"

JavsJavi4315Room_EventScript_PostBattle_Text_6:
# 191 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Nosotros nos quedaremos por aquí\n"
	.string "contemplando la sala.$"

JavsJavi4315Room_EventScript_Javi4315_Text_0:
# 199 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Siempre quise crear algo que se sintiera\n"
	.string "{COLOR GREEN}inmortal{COLOR DARK_GRAY}.\p"
	.string "Supongo que por eso sigo aquí, dándole\n"
	.string "vueltas a todo.$"

JavsJavi4315Room_EventScript_Javs_Text_0:
# 204 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Te gusta como se ve la sala? ¡Ni se te\n"
	.string "ocurra copiar sus colores sin mi\l"
	.string "permiso!$"

JavsJavi4315Room_Text_Javi4315Defeated::
# 148 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Acaso hemos perdido, Javs?$"

JavsJavi4315Room_Text_JavsDefeated::
# 152 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Cómo puede ser? ¡Mi estrategia era\n"
	.string "infalible!$"
