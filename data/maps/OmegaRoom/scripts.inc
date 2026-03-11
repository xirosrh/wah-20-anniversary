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
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_1
# 59 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 60 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
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
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_4
# 84 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 85 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 86 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_5
# 88 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 89 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 90 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 91 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 92 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_6
# 93 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 94 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 95 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_OmegaBattle
# 96 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 97 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_7
# 98 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 99 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 100 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_8
# 101 "data/maps/OmegaRoom/scripts.pory"
	delay 40
# 102 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 103 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, Common_Movement_SurpriseWithDelay48
# 104 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 105 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 106 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 107 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkDown
# 108 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 109 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 110 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 111 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 112 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 113 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_4
# 114 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 115 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 116 "data/maps/OmegaRoom/scripts.pory"
	playse SE_LEDGE
# 117 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_4
# 118 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 119 "data/maps/OmegaRoom/scripts.pory"
	waitse
# 120 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 121 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 122 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 123 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 124 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 125 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_SweatDropWithDelay48
# 127 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 128 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 129 "data/maps/OmegaRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 130 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 131 "data/maps/OmegaRoom/scripts.pory"
	special SpawnCameraObject
# 132 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 4
# 133 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 134 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 135 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 136 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 137 "data/maps/OmegaRoom/scripts.pory"
	special RemoveCameraObject
# 138 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 139 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_9
# 140 "data/maps/OmegaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OMEGA
# 141 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
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
# 187 "data/maps/OmegaRoom/scripts.pory"
	special HealPlayerParty
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
# 196 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_Omega_Text_0, MSGBOX_NPC, speaker = SP_NAME_OMEGA
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
# 58 "data/maps/OmegaRoom/scripts.pory"
	delay_16
# 58 "data/maps/OmegaRoom/scripts.pory"
	delay_16
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

# 83 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_4:
# 83 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
	step_end

# 87 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_5:
# 87 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
# 87 "data/maps/OmegaRoom/scripts.pory"
	delay_16
	step_end

# 92 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_6:
# 92 "data/maps/OmegaRoom/scripts.pory"
	emote_versus
	step_end

# 97 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_7:
# 97 "data/maps/OmegaRoom/scripts.pory"
	emote_x
	step_end

# 100 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_8:
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

# 139 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_9:
# 139 "data/maps/OmegaRoom/scripts.pory"
	walk_up
# 139 "data/maps/OmegaRoom/scripts.pory"
	walk_up
# 139 "data/maps/OmegaRoom/scripts.pory"
	face_down
	step_end

OmegaRoom_EventScript_StartChallenge_Text_0:
# 59 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Ostras, un{A} nuev{OA} contrincante!$"

OmegaRoom_EventScript_StartChallenge_Text_1:
# 73 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Bienvenid{OA} al primer encuentro del\n"
	.string "desafío de esta celebración!\p"
	.string "Te estabamos esperando.$"

OmegaRoom_EventScript_StartChallenge_Text_2:
# 77 "data/maps/OmegaRoom/scripts.pory"
	.string "¿List{OA} para tu primer combate? ¡Veamos\n"
	.string "si eres capaz de derrotarme!$"

OmegaRoom_EventScript_StartChallenge_Text_3:
# 90 "data/maps/OmegaRoom/scripts.pory"
	.string "Perfecto, ¡vamos!$"

OmegaRoom_EventScript_StartChallenge_Text_4:
# 104 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Sí que sacaste los colmillos!$"

OmegaRoom_EventScript_StartChallenge_Text_5:
# 108 "data/maps/OmegaRoom/scripts.pory"
	.string "Ha sido un buen combate. Me quedo con\n"
	.string "ganas de más, la verdad.\p"
	.string "Tocará esperar a que completes el\n"
	.string "desafío para tener una revancha.$"

OmegaRoom_EventScript_StartChallenge_Text_6:
# 111 "data/maps/OmegaRoom/scripts.pory"
	.string "De todas formas, esta fue solo la\n"
	.string "primera sala; todavía tenés un largo\l"
	.string "camino por delante.$"

OmegaRoom_EventScript_StartChallenge_Text_7:
# 121 "data/maps/OmegaRoom/scripts.pory"
	.string "Va a ser interesante ver qué tanto\n"
	.string "puedes avanzar en este desafío.$"

OmegaRoom_EventScript_StartChallenge_Text_8:
# 124 "data/maps/OmegaRoom/scripts.pory"
	.string "Yo sigo activo por aquí, pero muchos de\n"
	.string "tus próximos rivales ya se habían\l"
	.string "retirado… y han vuelto especialmente\l"
	.string "para esta celebración.\p"
	.string "Pero recuerda, no subestimes a la vieja\n"
	.string "guardia. Son tercos, y cuando se ponen\l"
	.string "en serio, se nota.$"

OmegaRoom_EventScript_StartChallenge_Text_9:
# 130 "data/maps/OmegaRoom/scripts.pory"
	.string "Te abriré la puerta para que puedas\n"
	.string "continuar con tu viaje.$"

OmegaRoom_EventScript_StartChallenge_Text_10:
# 138 "data/maps/OmegaRoom/scripts.pory"
	.string "Ahora avanza, y demuestra que estas\n"
	.string "aquí para lograr grandes cosas.$"

OmegaRoom_EventScript_Omega_Text_0:
# 196 "data/maps/OmegaRoom/scripts.pory"
	.string "¿Qué estás esperando? Ve a demostrar a\n"
	.string "esos viejos que no me has ganado por\l"
	.string "casualidad.$"

OmegaRoom_Text_OmegaDefeated::
# 191 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Qué nivel has demostrado! No esperaba\n"
	.string "un combate tan entretenido.$"
