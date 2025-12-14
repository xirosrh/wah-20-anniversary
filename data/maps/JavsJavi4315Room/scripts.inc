JavsJavi4315Room_MapScripts::
# 2 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JavsJavi4315Room_OnTransition
# 6 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JavsJavi4315Room_OnLoad
# 3 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, JavsJavi4315Room_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

JavsJavi4315Room_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/JavsJavi4315Room/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, JavsJavi4315Room_OnWarp_PlayerTurnNorth
	.2byte 0


JavsJavi4315Room_OnLoad::
# 10 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_OnLoad_2
JavsJavi4315Room_OnLoad_1:
	end

JavsJavi4315Room_OnLoad_2:
# 11 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto JavsJavi4315Room_OnLoad_1


JavsJavi4315Room_OnTransition::
# 17 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_OnTransition_2
JavsJavi4315Room_OnTransition_1:
	end

JavsJavi4315Room_OnTransition_2:
# 18 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxy LOCALID_JAVSJAVIROOM_JAVI4315, 3, 3
# 19 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxy LOCALID_JAVSJAVIROOM_JAVS, 4, 3
# 20 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 3, 3
# 21 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 4, 3
# 22 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVI4315, MOVEMENT_TYPE_FACE_UP
# 23 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectmovementtype LOCALID_JAVSJAVIROOM_JAVS, MOVEMENT_TYPE_FACE_UP
	goto JavsJavi4315Room_OnTransition_1


JavsJavi4315Room_OnWarp_PlayerTurnNorth::
# 29 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


JavsJavi4315Room_EventScript_MainTrigger::
# 34 "data/maps/JavsJavi4315Room/scripts.pory"
	lockall
# 35 "data/maps/JavsJavi4315Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS, JavsJavi4315Room_EventScript_MainTrigger_2
# 39 "data/maps/JavsJavi4315Room/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 7
# 40 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 41 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 42 "data/maps/JavsJavi4315Room/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 43 "data/maps/JavsJavi4315Room/scripts.pory"
	special SpawnCameraObject
# 44 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtopos 4, 4
# 45 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 46 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_0, speaker = SP_NAME_JAVI4315
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_0
# 48 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 50 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 51 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AngryWithDelay48
# 52 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 53 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_WEST
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 55 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceLeft
# 56 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 57 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_NORTH
# 58 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_NORTH
# 59 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 60 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 61 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_AnnoyedWithDelay48
# 62 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 50
# 63 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 64 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 65 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 66 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_DoubleExclamationMarkWithDelay48
# 67 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_DoubleExclamationMarkWithDelay48
# 68 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_1
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_2
# 71 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 72 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVI4315, 5, 5
# 73 "data/maps/JavsJavi4315Room/scripts.pory"
	setobjectxyperm LOCALID_JAVSJAVIROOM_JAVS, 7, 5
# 74 "data/maps/JavsJavi4315Room/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_0, VAR_TEMP_1
# 75 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 76 "data/maps/JavsJavi4315Room/scripts.pory"
	special RemoveCameraObject
# 77 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_3
# 78 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 79 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 80 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 81 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 82 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 83 "data/maps/JavsJavi4315Room/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 84 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 85 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 86 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 87 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 88 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_JumpInPlaceDown
# 89 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 90 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 91 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 92 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 93 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 94 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 95 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 96 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 97 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 98 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 99 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 100 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_QuestionMarkWithDelay48
# 101 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 102 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 103 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 104 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkDown
# 105 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkDown
# 106 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 107 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_MainTrigger_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 108 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 110 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_MainTrigger_Movement_4
# 111 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 112 "data/maps/JavsJavi4315Room/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_JAVI4315_MAIN, JavsJavi4315Room_EventScript_MainTrigger_Text_11, TRAINER_WAH_ADMIN_JAVS_MAIN, JavsJavi4315Room_EventScript_MainTrigger_Text_12
# 113 "data/maps/JavsJavi4315Room/scripts.pory"
	call JavsJavi4315Room_EventScript_PostBattle
# 114 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end

JavsJavi4315Room_EventScript_MainTrigger_2:
# 36 "data/maps/JavsJavi4315Room/scripts.pory"
	releaseall
	end


JavsJavi4315Room_EventScript_PostBattle::
# 119 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 121 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_0
# 122 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 123 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 40
# 124 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 125 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 126 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 127 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_SweatDropWithDelay48
# 128 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_EAST
# 129 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceRight
# 130 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 131 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkUp
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 133 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 134 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_ThinkingWithDelay48
# 135 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 136 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovementandwait LOCALID_JAVSJAVIROOM_JAVS, JavsJavi4315Room_EventScript_PostBattle_Movement_1
# 137 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 138 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 139 "data/maps/JavsJavi4315Room/scripts.pory"
	playse SE_PIN
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, JavsJavi4315Room_EventScript_PostBattle_Movement_2
# 141 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 142 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 143 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 20
# 144 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVI4315, DIR_SOUTH
# 145 "data/maps/JavsJavi4315Room/scripts.pory"
	turnobject LOCALID_JAVSJAVIROOM_JAVS, DIR_SOUTH
# 146 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 10
# 147 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVS, Common_Movement_WalkInPlaceDown
# 148 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVS
# 149 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 150 "data/maps/JavsJavi4315Room/scripts.pory"
	call WahRoomsShared_OpenDoor
# 151 "data/maps/JavsJavi4315Room/scripts.pory"
	delay 30
# 152 "data/maps/JavsJavi4315Room/scripts.pory"
	applymovement LOCALID_JAVSJAVIROOM_JAVI4315, Common_Movement_WalkInPlaceDown
# 153 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_PostBattle_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JAVI4315
# 154 "data/maps/JavsJavi4315Room/scripts.pory"
	waitmovement 0
# 155 "data/maps/JavsJavi4315Room/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS
# 156 "data/maps/JavsJavi4315Room/scripts.pory"
	setvar VAR_JAVS_JAVI4315_ROOM_STATE, 1
	return


JavsJavi4315Room_EventScript_Javi4315::
# 161 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javi4315_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVI4315
	end


JavsJavi4315Room_EventScript_Javs::
# 166 "data/maps/JavsJavi4315Room/scripts.pory"
	msgbox JavsJavi4315Room_EventScript_Javs_Text_0, MSGBOX_NPC, speaker = SP_NAME_JAVS
	end


# 47 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_0:
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_up
# 47 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
	step_end

# 69 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_1:
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 69 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 70 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_2:
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_right
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 70 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
	step_end

# 77 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_3:
# 77 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 77 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
	step_end

# 109 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_MainTrigger_Movement_4:
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_versus
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	jump_in_place_down
# 109 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

# 120 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_0:
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_surprise
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	lock_facing_direction
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_up
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	unlock_facing_direction
# 120 "data/maps/JavsJavi4315Room/scripts.pory"
	face_down
	step_end

# 136 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_1:
# 136 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_down
# 136 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 136 "data/maps/JavsJavi4315Room/scripts.pory"
	face_left
	step_end

# 140 "data/maps/JavsJavi4315Room/scripts.pory"
JavsJavi4315Room_EventScript_PostBattle_Movement_2:
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	emote_happy
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	walk_in_place_right
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
# 140 "data/maps/JavsJavi4315Room/scripts.pory"
	delay_16
	step_end

JavsJavi4315Room_EventScript_MainTrigger_Text_0:
# 46 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Tío… ¡pero qué pedazo de tiles nos han\n"
	.string "colocado aquí!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_1:
# 49 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "A que molan mucho, ¿verdad, Javier?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_2:
# 54 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Que no me llamo Javier…$"

JavsJavi4315Room_EventScript_MainTrigger_Text_3:
# 59 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Y eso no es todo, ¡mira esas paletas!\n"
	.string "Tan bien contrastadas y matizadas…\l"
	.string "¿serán privadas?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_4:
# 78 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Hombre… ¡hasta que alguien ha caído por\n"
	.string "aquí!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_5:
# 81 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Sabías que, de todas las desgracias\n"
	.string "que te pudieron haber pasado hoy, caer\l"
	.string "en nuestro piso era la peor?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_6:
# 85 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "No has presenciado un enfrentamiento\n"
	.string "en equipos como el nuestro ni en tus\l"
	.string "mejores sueños…\p"
	.string "¡Y no volverás a verlo, así que\n"
	.string "disfrútalo!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_7:
# 89 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Aquí la estrategia manda, ¡que no se te\n"
	.string "olvide!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_8:
# 93 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Listo, Javs?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_9:
# 97 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Listo, Javi69!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_10:
# 107 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Ahora!$"

JavsJavi4315Room_EventScript_MainTrigger_Text_11:
# 112 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Acaso hemos perdido, Javs?$"

JavsJavi4315Room_EventScript_MainTrigger_Text_12:
# 112 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Cómo puede ser? ¡Mi estrategia era\n"
	.string "infalible!$"

JavsJavi4315Room_EventScript_PostBattle_Text_0:
# 125 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Me pasé semanas planeando esta\n"
	.string "estrategia… Admito que eso ha dolido\l"
	.string "más de lo que esperaba.$"

JavsJavi4315Room_EventScript_PostBattle_Text_1:
# 130 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Y eso que armé mi equipo exactamente\n"
	.string "como me pediste!$"

JavsJavi4315Room_EventScript_PostBattle_Text_2:
# 132 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "La apertura era perfecta: sol activo y\n"
	.string "presión desde el turno uno. ¿Qué habré\l"
	.string "hecho mal?$"

JavsJavi4315Room_EventScript_PostBattle_Text_3:
# 137 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "La estrategia estuvo bien, pero\n"
	.string "simplemente tuvimos un{A} oponente\l"
	.string "demasiado fuerte.$"

JavsJavi4315Room_EventScript_PostBattle_Text_4:
# 141 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¡Al menos nos divertimos!$"

JavsJavi4315Room_EventScript_PostBattle_Text_5:
# 148 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Te abriremos la puerta, que ya te falta\n"
	.string "menos de la mitad.$"

JavsJavi4315Room_EventScript_PostBattle_Text_6:
# 153 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Nosotros nos quedaremos por aquí\n"
	.string "contemplando la sala.$"

JavsJavi4315Room_EventScript_Javi4315_Text_0:
# 161 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "Siempre quise crear algo que se sintiera\n"
	.string "{COLOR GREEN}inmortal{COLOR DARK_GRAY}.\p"
	.string "Supongo que por eso sigo aquí, dándole\n"
	.string "vueltas a todo.$"

JavsJavi4315Room_EventScript_Javs_Text_0:
# 166 "data/maps/JavsJavi4315Room/scripts.pory"
	.string "¿Te gusta como se ve la sala? ¡Ni se te\n"
	.string "ocurra copiar sus colores sin mi\l"
	.string "permiso!$"
