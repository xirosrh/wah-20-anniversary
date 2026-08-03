OmegaRoom_MapScripts::
# 6 "data/maps/OmegaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, OmegaRoom_OnLoad
# 7 "data/maps/OmegaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OmegaRoom_OnTransition
# 3 "data/maps/OmegaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, OmegaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

OmegaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/OmegaRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, OmegaRoom_OnWarp_PlayerTurnNorth
	.2byte 0


OmegaRoom_OnLoad::
# 12 "data/maps/OmegaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OMEGA, OmegaRoom_OnLoad_2
OmegaRoom_OnLoad_1:
	end

OmegaRoom_OnLoad_2:
# 13 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_BrokenCapsule
# 14 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto OmegaRoom_OnLoad_1


OmegaRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


OmegaRoom_OnTransition::
# 25 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Omega
	end


OmegaRoom_EventScript_StartChallenge::
# 30 "data/maps/OmegaRoom/scripts.pory"
	lock
# 31 "data/maps/OmegaRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 9
# 32 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 33 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 34 "data/maps/OmegaRoom/scripts.pory"
	special SpawnCameraObject
# 35 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 36 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 37 "data/maps/OmegaRoom/scripts.pory"
	delay 50
# 38 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_OmegaAwakens
# 39 "data/maps/OmegaRoom/scripts.pory"
	delay 10
# 40 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 41 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8005, 2
# 42 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8006, 8
# 43 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 44 "data/maps/OmegaRoom/scripts.pory"
	special ShakeCamera
# 45 "data/maps/OmegaRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 46 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 47 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_BrokenCapsule
# 48 "data/maps/OmegaRoom/scripts.pory"
	showobjectat LOCALID_OMEGAROOM_OMEGA, MAP_OMEGA_ROOM
# 49 "data/maps/OmegaRoom/scripts.pory"
	setobjectmovementtype LOCALID_OMEGAROOM_OMEGA, MOVEMENT_TYPE_FACE_DOWN
# 50 "data/maps/OmegaRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_OMEGAROOM_OMEGA, MOVEMENT_TYPE_FACE_DOWN
# 51 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_OMEGAROOM_OMEGA, DIR_SOUTH
# 52 "data/maps/OmegaRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 53 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 54 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_0
# 55 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 56 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 57 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 58 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_1
# 59 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 60 "data/maps/OmegaRoom/scripts.pory"
	delay 50
# 61 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 62 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 63 "data/maps/OmegaRoom/scripts.pory"
	special RemoveCameraObject
# 64 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 65 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_2
# 67 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_PLAYER, OmegaRoom_EventScript_StartChallenge_Movement_3
# 68 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 70 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 71 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 72 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 73 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 74 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 75 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_HappyWithDelay48
# 76 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 77 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 78 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 79 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 80 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 81 "data/maps/OmegaRoom/scripts.pory"
	delay 10
# 82 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 83 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_1
# 84 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 85 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 86 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_4
# 88 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 90 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 91 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_5
# 93 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 95 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_OmegaBattle
# 96 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 97 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_6
# 98 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 99 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 100 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_7
# 101 "data/maps/OmegaRoom/scripts.pory"
	delay 40
# 102 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 103 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_Surprise
# 104 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 105 "data/maps/OmegaRoom/scripts.pory"
	delay 48
# 106 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkDown
# 107 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 108 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 109 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 110 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 111 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 112 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_1
# 113 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 114 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 115 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 116 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_1
# 117 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 119 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 120 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 121 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 122 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 123 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 124 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 125 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_SweatDropWithDelay48
# 126 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 127 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 128 "data/maps/OmegaRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 129 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 130 "data/maps/OmegaRoom/scripts.pory"
	special SpawnCameraObject
# 131 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 4
# 132 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 133 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 134 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 135 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 136 "data/maps/OmegaRoom/scripts.pory"
	special RemoveCameraObject
# 137 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 138 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_8
# 139 "data/maps/OmegaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OMEGA
# 140 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 141 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 142 "data/maps/OmegaRoom/scripts.pory"
	release
	end


OmegaRoom_EventScript_OmegaAwakens::
# 147 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 4, METATILE_room_omega_OMEGA_AWAKENS_1, FALSE
# 148 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 4, METATILE_room_omega_OMEGA_AWAKENS_2, FALSE
# 149 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 4, METATILE_room_omega_OMEGA_AWAKENS_3, FALSE
# 150 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 5, METATILE_room_omega_OMEGA_AWAKENS_4, FALSE
# 151 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 5, METATILE_room_omega_OMEGA_AWAKENS_5, FALSE
# 152 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_omega_OMEGA_AWAKENS_6, FALSE
# 153 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 6, METATILE_room_omega_OMEGA_AWAKENS_7, TRUE
# 154 "data/maps/OmegaRoom/scripts.pory"
	special DrawWholeMapView
	return


OmegaRoom_EventScript_BrokenCapsule::
# 159 "data/maps/OmegaRoom/scripts.pory"
	playse SE_ICE_CRACK
# 160 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 161 "data/maps/OmegaRoom/scripts.pory"
	playse SE_M_BRICK_BREAK
# 162 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 163 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 4, METATILE_room_omega_CAPSULE_BROKEN_1, FALSE
# 164 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 4, METATILE_room_omega_CAPSULE_BROKEN_2, FALSE
# 165 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 4, METATILE_room_omega_CAPSULE_BROKEN_3, FALSE
# 166 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 5, METATILE_room_omega_CAPSULE_BROKEN_4, FALSE
# 167 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 5, METATILE_room_omega_CAPSULE_BROKEN_5, FALSE
# 168 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_omega_CAPSULE_BROKEN_6, FALSE
# 169 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 6, METATILE_room_omega_CAPSULE_BROKEN_7, TRUE
# 170 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 7, METATILE_room_omega_BROKEN_GLASS, FALSE
# 171 "data/maps/OmegaRoom/scripts.pory"
	special DrawWholeMapView
	return


OmegaRoom_EventScript_OmegaBattle::
# 176 "data/maps/OmegaRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, OmegaRoom_EventScript_OmegaBattle_2
# 179 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_OMEGA
# 180 "data/maps/OmegaRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 181 "data/maps/OmegaRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq OmegaRoom_EventScript_OmegaBattle_5
# 184 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_ALTERNATIVE, OmegaRoom_Text_OmegaDefeated
OmegaRoom_EventScript_OmegaBattle_1:
	return

OmegaRoom_EventScript_OmegaBattle_2:
# 177 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_MAIN, OmegaRoom_Text_OmegaDefeated
	goto OmegaRoom_EventScript_OmegaBattle_1

OmegaRoom_EventScript_OmegaBattle_5:
# 182 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_MAIN, OmegaRoom_Text_OmegaDefeated
	goto OmegaRoom_EventScript_OmegaBattle_1


OmegaRoom_EventScript_Omega::
# 195 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_Omega_Text_0, MSGBOX_NPC, speaker = SP_NAME_OMEGA
	end


OmegaRoom_Eventscript_Capsule::
# 200 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_Eventscript_Capsule_Text_0, MSGBOX_SIGN
	end


OmegaRoom_EventScript_Machine1::
# 205 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_Machine1_Text_0, MSGBOX_SIGN
	end


OmegaRoom_EventScript_Machine2::
# 210 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_Machine2_Text_0, MSGBOX_SIGN
	end


OmegaRoom_EventScript_Machine3::
# 215 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_Machine3_Text_0, MSGBOX_SIGN
	end


OmegaRoom_EventScript_Box::
# 220 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_Box_Text_0, MSGBOX_SIGN
	end


# 54 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_0:
# 54 "data/maps/OmegaRoom/scripts.pory"
	emote_double_exclamation_mark
	step_end

# 58 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_1:
# 58 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
	step_end

# 65 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_2:
# 66 "data/maps/OmegaRoom/scripts.pory"
	jump_2_down
	step_end

# 67 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_3:
# 67 "data/maps/OmegaRoom/scripts.pory"
	delay_8
# 67 "data/maps/OmegaRoom/scripts.pory"
	lock_facing_direction
# 67 "data/maps/OmegaRoom/scripts.pory"
	jump_down
# 67 "data/maps/OmegaRoom/scripts.pory"
	unlock_facing_direction
# 67 "data/maps/OmegaRoom/scripts.pory"
	face_up
	step_end

# 87 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_4:
# 87 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
# 87 "data/maps/OmegaRoom/scripts.pory"
	delay_16
	step_end

# 92 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_5:
# 92 "data/maps/OmegaRoom/scripts.pory"
	emote_versus
	step_end

# 97 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_6:
# 97 "data/maps/OmegaRoom/scripts.pory"
	emote_x
	step_end

# 100 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_7:
# 100 "data/maps/OmegaRoom/scripts.pory"
	lock_facing_direction
# 100 "data/maps/OmegaRoom/scripts.pory"
	jump_up
# 100 "data/maps/OmegaRoom/scripts.pory"
	unlock_facing_direction
# 100 "data/maps/OmegaRoom/scripts.pory"
	face_down
# 100 "data/maps/OmegaRoom/scripts.pory"
	delay_16
# 100 "data/maps/OmegaRoom/scripts.pory"
	delay_16
	step_end

# 138 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_8:
# 138 "data/maps/OmegaRoom/scripts.pory"
	walk_up
# 138 "data/maps/OmegaRoom/scripts.pory"
	walk_up
# 138 "data/maps/OmegaRoom/scripts.pory"
	face_down
	step_end

OmegaRoom_EventScript_StartChallenge_Text_0:
# 59 "data/maps/OmegaRoom/scripts.pory"
	.string "Whoa, a new challenger!$"

OmegaRoom_EventScript_StartChallenge_Text_1:
# 73 "data/maps/OmegaRoom/scripts.pory"
	.string "Welcome to the first match of this\n"
	.string "celebration's challenge!\p"
	.string "We've been expecting you.$"

OmegaRoom_EventScript_StartChallenge_Text_2:
# 77 "data/maps/OmegaRoom/scripts.pory"
	.string "Ready for your first battle? Let's see\n"
	.string "if you can beat me!$"

OmegaRoom_EventScript_StartChallenge_Text_3:
# 90 "data/maps/OmegaRoom/scripts.pory"
	.string "Perfect, let's go!$"

OmegaRoom_EventScript_StartChallenge_Text_4:
# 104 "data/maps/OmegaRoom/scripts.pory"
	.string "You really bared your fangs!$"

OmegaRoom_EventScript_StartChallenge_Text_5:
# 107 "data/maps/OmegaRoom/scripts.pory"
	.string "That was a good battle. It leaves me\n"
	.string "wanting more, honestly.\p"
	.string "I'll have to wait until you complete the\n"
	.string "challenge for a rematch.$"

OmegaRoom_EventScript_StartChallenge_Text_6:
# 110 "data/maps/OmegaRoom/scripts.pory"
	.string "Either way, this was only the first room;\n"
	.string "you've still got a long road ahead.$"

OmegaRoom_EventScript_StartChallenge_Text_7:
# 120 "data/maps/OmegaRoom/scripts.pory"
	.string "It'll be interesting to see how far you\n"
	.string "can get in this challenge.$"

OmegaRoom_EventScript_StartChallenge_Text_8:
# 123 "data/maps/OmegaRoom/scripts.pory"
	.string "I'm still active around here, but many\n"
	.string "of your upcoming rivals had already\l"
	.string "retired… and came back especially for\l"
	.string "this celebration.\p"
	.string "But remember, don't underestimate the\n"
	.string "old guard. They're stubborn, and when\l"
	.string "they get serious, you'll know it.$"

OmegaRoom_EventScript_StartChallenge_Text_9:
# 129 "data/maps/OmegaRoom/scripts.pory"
	.string "I'll open the door so you can continue\n"
	.string "your journey.$"

OmegaRoom_EventScript_StartChallenge_Text_10:
# 137 "data/maps/OmegaRoom/scripts.pory"
	.string "Now go on, and show you're here to\n"
	.string "achieve great things.$"

OmegaRoom_EventScript_Omega_Text_0:
# 195 "data/maps/OmegaRoom/scripts.pory"
	.string "What are you waiting for? Go show those\n"
	.string "old-timers you didn't beat me by luck.$"

OmegaRoom_Eventscript_Capsule_Text_0:
# 200 "data/maps/OmegaRoom/scripts.pory"
	.string "It looks like an experimentation pod.$"

OmegaRoom_EventScript_Machine1_Text_0:
# 205 "data/maps/OmegaRoom/scripts.pory"
	.string "The machine gives off a constant hum.\p"
	.string "It looks like no one's checked it in\n"
	.string "years.$"

OmegaRoom_EventScript_Machine2_Text_0:
# 210 "data/maps/OmegaRoom/scripts.pory"
	.string "The machine is completely neglected.\p"
	.string "Small plants have grown between the\n"
	.string "panels and cracks in the metal.$"

OmegaRoom_EventScript_Machine3_Text_0:
# 215 "data/maps/OmegaRoom/scripts.pory"
	.string "The screen is full of glitches and dead\n"
	.string "pixels.\p"
	.string "It's amazing the system is still\n"
	.string "running.$"

OmegaRoom_EventScript_Box_Text_0:
# 220 "data/maps/OmegaRoom/scripts.pory"
	.string "The box is covered in a thick layer of\n"
	.string "dust.\p"
	.string "It looks like no one's touched it in\n"
	.string "years.$"

OmegaRoom_Text_OmegaDefeated::
# 190 "data/maps/OmegaRoom/scripts.pory"
	.string "That was awesome! I didn't expect such\n"
	.string "an entertaining battle.$"
