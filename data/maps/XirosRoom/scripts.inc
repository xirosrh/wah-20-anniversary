XirosRoom_MapScripts::
# 5 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, XirosRoom_OnLoad
# 6 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, XirosRoom_OnTransition
# 7 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, XirosRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

XirosRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/XirosRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, XirosRoom_OnWarp_PlayerTurnNorth
	.2byte 0


XirosRoom_OnLoad::
# 13 "data/maps/XirosRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_XIROS, XirosRoom_OnLoad_2
XirosRoom_OnLoad_1:
	end

XirosRoom_OnLoad_2:
# 14 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto XirosRoom_OnLoad_1


XirosRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


XirosRoom_OnTransition::
# 25 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Xiros
# 26 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 27 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_2
	end


XirosRoom_EventScript_Xiros::
# 32 "data/maps/XirosRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_XIROS, XirosRoom_EventScript_Xiros_2
# 56 "data/maps/XirosRoom/scripts.pory"
	lock
# 57 "data/maps/XirosRoom/scripts.pory"
	faceplayer
# 58 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 59 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 60 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 61 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 62 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_SweatDropWithDelay48
# 64 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 65 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_SOUTH
# 66 "data/maps/XirosRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 6
# 67 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 68 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 69 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 70 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 71 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceDown
# 72 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 73 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 74 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HeartWithDelay48
# 76 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 77 "data/maps/XirosRoom/scripts.pory"
	special SpawnCameraObject
# 78 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_XIROSROOM_XIROS, Common_Movement_WalkUp2
# 79 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 80 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 81 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 82 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 83 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 84 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceDown
# 85 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 86 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_XIROSROOM_XIROS, Common_Movement_WalkDown2
# 87 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 88 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/XirosRoom/scripts.pory"
	special RemoveCameraObject
# 90 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 91 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 93 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_3
# 98 "data/maps/XirosRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 99 "data/maps/XirosRoom/scripts.pory"
	addobject LOCALID_XIROSROOM_POKEBALL
# 100 "data/maps/XirosRoom/scripts.pory"
	showobjectat LOCALID_XIROSROOM_POKEBALL, MAP_XIROS_ROOM
# 101 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 102 "data/maps/XirosRoom/scripts.pory"
	playse SE_BALL_OPEN
# 103 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 104 "data/maps/XirosRoom/scripts.pory"
	removeobject LOCALID_XIROSROOM_POKEBALL
# 105 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 106 "data/maps/XirosRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 107 "data/maps/XirosRoom/scripts.pory"
	addobject LOCALID_XIROSROOM_ELECTRODE
# 108 "data/maps/XirosRoom/scripts.pory"
	waitse
# 109 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 110 "data/maps/XirosRoom/scripts.pory"
	release
# 111 "data/maps/XirosRoom/scripts.pory"
	delay 30
# 112 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 113 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_ELECTRODE, XirosRoom_EventScript_Xiros_Movement_4
# 114 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 115 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_ELECTRODE, XirosRoom_EventScript_Xiros_Movement_4
# 116 "data/maps/XirosRoom/scripts.pory"
	waitse
# 117 "data/maps/XirosRoom/scripts.pory"
	playmoncry SPECIES_ELECTRODE, CRY_MODE_NORMAL
# 118 "data/maps/XirosRoom/scripts.pory"
	waitmoncry
# 119 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_ELECTRODE, XirosRoom_EventScript_Xiros_Movement_5
# 120 "data/maps/XirosRoom/scripts.pory"
	release
# 121 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_WEST
# 122 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 123 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 124 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 125 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_SOUTH
# 126 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_ELECTRODE, DIR_SOUTH
# 127 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 128 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 129 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_JumpInPlaceDown
# 130 "data/maps/XirosRoom/scripts.pory"
	waitse
# 131 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 132 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_JumpInPlaceDown
# 133 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 134 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceLeft
# 135 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_ELECTRODE, DIR_EAST
# 136 "data/maps/XirosRoom/scripts.pory"
	playse SE_BALL_OPEN
# 137 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 138 "data/maps/XirosRoom/scripts.pory"
	removeobject LOCALID_XIROSROOM_ELECTRODE
# 139 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 140 "data/maps/XirosRoom/scripts.pory"
	delay 30
# 141 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 142 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 143 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkDown
# 144 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 145 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 146 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_6
# 147 "data/maps/XirosRoom/scripts.pory"
	call XirosRoom_EventScript_XirosBattle
# 148 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 149 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_7
# 150 "data/maps/XirosRoom/scripts.pory"
	waitse
# 151 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 152 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_4
# 153 "data/maps/XirosRoom/scripts.pory"
	waitse
# 154 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 155 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_4
# 156 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 157 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 158 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceDown
# 159 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 160 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 161 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 162 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 163 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 164 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_XIROS
# 165 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 166 "data/maps/XirosRoom/scripts.pory"
	release
	end

XirosRoom_EventScript_Xiros_2:
# 33 "data/maps/XirosRoom/scripts.pory"
	lock
# 34 "data/maps/XirosRoom/scripts.pory"
	faceplayer
# 35 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 36 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 37 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 38 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 39 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 40 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_0
# 41 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 42 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 44 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 45 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_1
# 46 "data/maps/XirosRoom/scripts.pory"
	waitse
# 47 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 48 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_2
# 49 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 50 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 52 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_SOUTH
# 53 "data/maps/XirosRoom/scripts.pory"
	release
	end


XirosRoom_EventScript_XirosBattle::
# 171 "data/maps/XirosRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, XirosRoom_EventScript_XirosBattle_2
# 174 "data/maps/XirosRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_XIROS
# 175 "data/maps/XirosRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 176 "data/maps/XirosRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq XirosRoom_EventScript_XirosBattle_5
# 179 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_ALTERNATIVE, XirosRoom_Text_XirosDefeated
XirosRoom_EventScript_XirosBattle_1:
	return

XirosRoom_EventScript_XirosBattle_2:
# 172 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_MAIN, XirosRoom_Text_XirosDefeated
	goto XirosRoom_EventScript_XirosBattle_1

XirosRoom_EventScript_XirosBattle_5:
# 177 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_MAIN, XirosRoom_Text_XirosDefeated
	goto XirosRoom_EventScript_XirosBattle_1


XirosRoom_EventScript_Tanque::
# 190 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Tanque_Text_0, MSGBOX_SIGN
	end


XirosRoom_EventScript_Holograma::
# 195 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Holograma_Text_0, MSGBOX_SIGN
	end


XirosRoom_EventScript_Lampara::
# 200 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Lampara_Text_0, MSGBOX_SIGN
	end


XirosRoom_EventScript_Server::
# 205 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Server_Text_0, MSGBOX_SIGN
	end


XirosRoom_EventScript_Pantalla::
# 210 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Pantalla_Text_0, MSGBOX_SIGN
	end


XirosRoom_EventScript_Unknown::
# 215 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Unknown_Text_0, MSGBOX_SIGN
	end


# 40 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_0:
# 40 "data/maps/XirosRoom/scripts.pory"
	lock_facing_direction
# 40 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
# 40 "data/maps/XirosRoom/scripts.pory"
	unlock_facing_direction
# 40 "data/maps/XirosRoom/scripts.pory"
	face_player
	step_end

# 45 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_1:
# 45 "data/maps/XirosRoom/scripts.pory"
	delay_16
# 45 "data/maps/XirosRoom/scripts.pory"
	delay_16
# 45 "data/maps/XirosRoom/scripts.pory"
	lock_facing_direction
# 45 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
	step_end

# 48 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_2:
# 48 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
# 48 "data/maps/XirosRoom/scripts.pory"
	unlock_facing_direction
# 48 "data/maps/XirosRoom/scripts.pory"
	face_player
	step_end

# 93 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_3:
# 94 "data/maps/XirosRoom/scripts.pory"
	lock_facing_direction
# 95 "data/maps/XirosRoom/scripts.pory"
	walk_up
# 96 "data/maps/XirosRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 113 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_4:
# 113 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
	step_end

# 119 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_5:
# 119 "data/maps/XirosRoom/scripts.pory"
	walk_left
# 119 "data/maps/XirosRoom/scripts.pory"
	walk_up
# 119 "data/maps/XirosRoom/scripts.pory"
	walk_in_place_right
	step_end

# 146 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_6:
# 146 "data/maps/XirosRoom/scripts.pory"
	emote_versus
# 146 "data/maps/XirosRoom/scripts.pory"
	delay_16
# 146 "data/maps/XirosRoom/scripts.pory"
	walk_in_place_down
# 146 "data/maps/XirosRoom/scripts.pory"
	delay_16
	step_end

# 149 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_7:
# 149 "data/maps/XirosRoom/scripts.pory"
	emote_happy
	step_end

XirosRoom_EventScript_Xiros_Text_0:
# 35 "data/maps/XirosRoom/scripts.pory"
	.string "Still here? Well, since you are, let me\n"
	.string "tell you one more thing.$"

XirosRoom_EventScript_Xiros_Text_1:
# 38 "data/maps/XirosRoom/scripts.pory"
	.string "Don't get too obsessed with comparing\n"
	.string "yourself all the time, because\l"
	.string "sometimes you'll feel ahead, and other\l"
	.string "times that you've fallen behind.$"

XirosRoom_EventScript_Xiros_Text_2:
# 41 "data/maps/XirosRoom/scripts.pory"
	.string "In the end, the road is long, and the\n"
	.string "real race is always against yourself.$"

XirosRoom_EventScript_Xiros_Text_3:
# 49 "data/maps/XirosRoom/scripts.pory"
	.string "Now keep going, at your own pace, but\n"
	.string "always moving forward.$"

XirosRoom_EventScript_Xiros_Text_4:
# 58 "data/maps/XirosRoom/scripts.pory"
	.string "So you made it here, to room number\n"
	.string "twenty!\p"
	.string "A place you don't reach by chance.$"

XirosRoom_EventScript_Xiros_Text_5:
# 61 "data/maps/XirosRoom/scripts.pory"
	.string "I'll try to be briefer than Zero in my\n"
	.string "speech, but I like to reflect too, so I\l"
	.string "can't promise anything…$"

XirosRoom_EventScript_Xiros_Text_6:
# 70 "data/maps/XirosRoom/scripts.pory"
	.string "Along the way you crossed paths with\n"
	.string "many people, some familiar, others you'd\l"
	.string "maybe only heard mentioned once, but\l"
	.string "all of them left something on this\l"
	.string "journey.$"

XirosRoom_EventScript_Xiros_Text_7:
# 73 "data/maps/XirosRoom/scripts.pory"
	.string "Every encounter, every chat, and every\n"
	.string "battle is part of a bigger story, even if\l"
	.string "we don't always notice it in the moment.$"

XirosRoom_EventScript_Xiros_Text_8:
# 83 "data/maps/XirosRoom/scripts.pory"
	.string "It's normal for things to seem hard or\n"
	.string "even impossible at some point, because\l"
	.string "no one is born knowing, nor starts a big\l"
	.string "challenge or project with all the\l"
	.string "answers.$"

XirosRoom_EventScript_Xiros_Text_9:
# 85 "data/maps/XirosRoom/scripts.pory"
	.string "What matters isn't knowing everything,\n"
	.string "but daring to search, because when you\l"
	.string "truly search, someone willing to help\l"
	.string "always turns up.$"

XirosRoom_EventScript_Xiros_Text_10:
# 90 "data/maps/XirosRoom/scripts.pory"
	.string "That's the beautiful thing about this\n"
	.string "community, don't you think?$"

XirosRoom_EventScript_Xiros_Text_11:
# 122 "data/maps/XirosRoom/scripts.pory"
	.string "This is Watermelon Electrode, a symbol\n"
	.string "of an era many remember with fondness\l"
	.string "and nostalgia, when everything seemed\l"
	.string "simpler.$"

XirosRoom_EventScript_Xiros_Text_12:
# 127 "data/maps/XirosRoom/scripts.pory"
	.string "Personally, I never believed the golden\n"
	.string "age was a moment left behind in time.$"

XirosRoom_EventScript_Xiros_Text_13:
# 133 "data/maps/XirosRoom/scripts.pory"
	.string "For me, the golden age is today, and it'll\n"
	.string "be tomorrow too, as long as there are\l"
	.string "still people eager to motivate, help,\l"
	.string "and push things a little further\l"
	.string "forward.$"

XirosRoom_EventScript_Xiros_Text_14:
# 144 "data/maps/XirosRoom/scripts.pory"
	.string "Let's make this moment count too.$"

XirosRoom_EventScript_Xiros_Text_15:
# 156 "data/maps/XirosRoom/scripts.pory"
	.string "Wow! What a great battle! I love your\n"
	.string "battling style.\p"
	.string "Especially the passion you put into\n"
	.string "every move!$"

XirosRoom_EventScript_Xiros_Text_16:
# 159 "data/maps/XirosRoom/scripts.pory"
	.string "You've still got one last showdown, and\n"
	.string "if you know a bit of this place's\l"
	.string "history, you can probably already\l"
	.string "imagine who's waiting for you.\p"
	.string "Make the most of it - not everyone is\n"
	.string "lucky enough to find him.$"

XirosRoom_EventScript_Tanque_Text_0:
# 190 "data/maps/XirosRoom/scripts.pory"
	.string "It's a tank full of a liquid that doesn't\n"
	.string "look like water.\p"
	.string "There's bubbling inside it.$"

XirosRoom_EventScript_Holograma_Text_0:
# 195 "data/maps/XirosRoom/scripts.pory"
	.string "It's a hologram of a cube floating in\n"
	.string "the air.$"

XirosRoom_EventScript_Lampara_Text_0:
# 200 "data/maps/XirosRoom/scripts.pory"
	.string "It's a futuristic lamp that glows with\n"
	.string "blue light.$"

XirosRoom_EventScript_Server_Text_0:
# 205 "data/maps/XirosRoom/scripts.pory"
	.string "The blinking lights show it's running\n"
	.string "quantum calculations.$"

XirosRoom_EventScript_Pantalla_Text_0:
# 210 "data/maps/XirosRoom/scripts.pory"
	.string "It seems to show very complex\n"
	.string "calculations and graphs.$"

XirosRoom_EventScript_Unknown_Text_0:
# 215 "data/maps/XirosRoom/scripts.pory"
	.string "This is a...\n"
	.string "What is this?$"

XirosRoom_Text_XirosDefeated::
# 185 "data/maps/XirosRoom/scripts.pory"
	.string "Great battle!$"
