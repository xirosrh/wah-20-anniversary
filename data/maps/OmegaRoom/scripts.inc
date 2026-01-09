OmegaRoom_MapScripts::
# 6 "data/maps/OmegaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, OmegaRoom_OnLoad
# 3 "data/maps/OmegaRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, OmegaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

OmegaRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/OmegaRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, OmegaRoom_OnWarp_PlayerTurnNorth
	.2byte 0


OmegaRoom_OnLoad::
# 11 "data/maps/OmegaRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_OMEGA, OmegaRoom_OnLoad_2
OmegaRoom_OnLoad_1:
	end

OmegaRoom_OnLoad_2:
# 12 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_BrokenCapsule
# 13 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto OmegaRoom_OnLoad_1


OmegaRoom_OnWarp_PlayerTurnNorth::
# 19 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


OmegaRoom_EventScript_StartChallenge::
# 23 "data/maps/OmegaRoom/scripts.pory"
	lock
# 24 "data/maps/OmegaRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 9
# 25 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 26 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 27 "data/maps/OmegaRoom/scripts.pory"
	special SpawnCameraObject
# 28 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 6
# 29 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/OmegaRoom/scripts.pory"
	delay 50
# 31 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_OmegaAwakens
# 32 "data/maps/OmegaRoom/scripts.pory"
	delay 10
# 33 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 34 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8005, 2
# 35 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8006, 8
# 36 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 37 "data/maps/OmegaRoom/scripts.pory"
	special ShakeCamera
# 38 "data/maps/OmegaRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 39 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 40 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_BrokenCapsule
# 41 "data/maps/OmegaRoom/scripts.pory"
	showobjectat LOCALID_OMEGAROOM_OMEGA, MAP_OMEGA_ROOM
# 42 "data/maps/OmegaRoom/scripts.pory"
	setobjectmovementtype LOCALID_OMEGAROOM_OMEGA, MOVEMENT_TYPE_FACE_DOWN
# 43 "data/maps/OmegaRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_OMEGAROOM_OMEGA, MOVEMENT_TYPE_FACE_DOWN
# 44 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_OMEGAROOM_OMEGA, DIR_SOUTH
# 45 "data/maps/OmegaRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 46 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_0
# 48 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 49 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 51 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/OmegaRoom/scripts.pory"
	special RemoveCameraObject
# 53 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_1
# 55 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_PLAYER, OmegaRoom_EventScript_StartChallenge_Movement_2
# 56 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 57 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 58 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 59 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 60 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 61 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 62 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 63 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_HappyWithDelay48
# 64 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 65 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 66 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 67 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 68 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
# 69 "data/maps/OmegaRoom/scripts.pory"
	delay 10
# 70 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 71 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_3
# 72 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 73 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_OmegaBattle
# 75 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_4
# 77 "data/maps/OmegaRoom/scripts.pory"
	delay 40
# 78 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 79 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, Common_Movement_SurpriseWithDelay48
# 80 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 81 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 83 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkDown
# 84 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 85 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 86 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 87 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 88 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, Common_Movement_JumpInPlaceDown2
# 89 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 90 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 91 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 92 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 93 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 94 "data/maps/OmegaRoom/scripts.pory"
	playse SE_PIN
# 95 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_SweatDropWithDelay48
# 96 "data/maps/OmegaRoom/scripts.pory"
	delay 20
# 97 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_WalkInPlaceDown
# 98 "data/maps/OmegaRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 99 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_OMEGA
# 100 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_5
# 101 "data/maps/OmegaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OMEGA
# 102 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 103 "data/maps/OmegaRoom/scripts.pory"
	release
	end


OmegaRoom_EventScript_OmegaAwakens::
# 108 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 4, METATILE_room_omega_OMEGA_AWAKENS_1, FALSE
# 109 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 4, METATILE_room_omega_OMEGA_AWAKENS_2, FALSE
# 110 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 4, METATILE_room_omega_OMEGA_AWAKENS_3, FALSE
# 111 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 5, METATILE_room_omega_OMEGA_AWAKENS_4, FALSE
# 112 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 5, METATILE_room_omega_OMEGA_AWAKENS_5, FALSE
# 113 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_omega_OMEGA_AWAKENS_6, FALSE
# 114 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 6, METATILE_room_omega_OMEGA_AWAKENS_7, TRUE
# 115 "data/maps/OmegaRoom/scripts.pory"
	special DrawWholeMapView
	return


OmegaRoom_EventScript_BrokenCapsule::
# 120 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 4, METATILE_room_omega_CAPSULE_BROKEN_1, FALSE
# 121 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 4, METATILE_room_omega_CAPSULE_BROKEN_2, FALSE
# 122 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 4, METATILE_room_omega_CAPSULE_BROKEN_3, FALSE
# 123 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 5, METATILE_room_omega_CAPSULE_BROKEN_4, FALSE
# 124 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 5, METATILE_room_omega_CAPSULE_BROKEN_5, FALSE
# 125 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_omega_CAPSULE_BROKEN_6, FALSE
# 126 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 6, METATILE_room_omega_CAPSULE_BROKEN_7, TRUE
# 127 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 7, METATILE_room_omega_BROKEN_GLASS, FALSE
# 128 "data/maps/OmegaRoom/scripts.pory"
	special DrawWholeMapView
	return


OmegaRoom_EventScript_OmegaBattle::
# 133 "data/maps/OmegaRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, OmegaRoom_EventScript_OmegaBattle_2
# 136 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_OMEGA
# 137 "data/maps/OmegaRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 138 "data/maps/OmegaRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq OmegaRoom_EventScript_OmegaBattle_5
# 141 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_ALTERNATIVE, OmegaRoom_Text_OmegaDefeated
OmegaRoom_EventScript_OmegaBattle_1:
# 144 "data/maps/OmegaRoom/scripts.pory"
	special HealPlayerParty
	return

OmegaRoom_EventScript_OmegaBattle_2:
# 134 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_MAIN, OmegaRoom_Text_OmegaDefeated
	goto OmegaRoom_EventScript_OmegaBattle_1

OmegaRoom_EventScript_OmegaBattle_5:
# 139 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_MAIN, OmegaRoom_Text_OmegaDefeated
	goto OmegaRoom_EventScript_OmegaBattle_1


# 47 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_0:
# 47 "data/maps/OmegaRoom/scripts.pory"
	emote_double_exclamation_mark
# 47 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
# 47 "data/maps/OmegaRoom/scripts.pory"
	delay_16
# 47 "data/maps/OmegaRoom/scripts.pory"
	delay_16
	step_end

# 53 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_1:
# 54 "data/maps/OmegaRoom/scripts.pory"
	jump_2_down
	step_end

# 55 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_2:
# 55 "data/maps/OmegaRoom/scripts.pory"
	delay_8
# 55 "data/maps/OmegaRoom/scripts.pory"
	lock_facing_direction
# 55 "data/maps/OmegaRoom/scripts.pory"
	jump_down
# 55 "data/maps/OmegaRoom/scripts.pory"
	unlock_facing_direction
# 55 "data/maps/OmegaRoom/scripts.pory"
	face_up
	step_end

# 71 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_3:
# 71 "data/maps/OmegaRoom/scripts.pory"
	emote_versus
# 71 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
# 71 "data/maps/OmegaRoom/scripts.pory"
	jump_in_place_down
# 71 "data/maps/OmegaRoom/scripts.pory"
	delay_16
	step_end

# 76 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_4:
# 76 "data/maps/OmegaRoom/scripts.pory"
	emote_x
# 76 "data/maps/OmegaRoom/scripts.pory"
	lock_facing_direction
# 76 "data/maps/OmegaRoom/scripts.pory"
	jump_up
# 76 "data/maps/OmegaRoom/scripts.pory"
	unlock_facing_direction
# 76 "data/maps/OmegaRoom/scripts.pory"
	face_down
# 76 "data/maps/OmegaRoom/scripts.pory"
	delay_16
# 76 "data/maps/OmegaRoom/scripts.pory"
	delay_16
	step_end

# 100 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_5:
# 100 "data/maps/OmegaRoom/scripts.pory"
	walk_up
# 100 "data/maps/OmegaRoom/scripts.pory"
	walk_up
# 100 "data/maps/OmegaRoom/scripts.pory"
	face_down
	step_end

OmegaRoom_EventScript_StartChallenge_Text_0:
# 48 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Ostras, un{A} nuev{OA} contrincante!$"

OmegaRoom_EventScript_StartChallenge_Text_1:
# 61 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Bienvenid{OA} al primer encuentro del\n"
	.string "desafío de esta celebración!\p"
	.string "Te estabamos esperando.$"

OmegaRoom_EventScript_StartChallenge_Text_2:
# 65 "data/maps/OmegaRoom/scripts.pory"
	.string "¿List{OA} para tu primer combate? ¡Veamos\n"
	.string "si eres capaz de derrotarme!$"

OmegaRoom_EventScript_StartChallenge_Text_3:
# 72 "data/maps/OmegaRoom/scripts.pory"
	.string "Perfecto, ¡vamos!$"

OmegaRoom_EventScript_StartChallenge_Text_4:
# 80 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Sí que sacaste los colmillos!$"

OmegaRoom_EventScript_StartChallenge_Text_5:
# 84 "data/maps/OmegaRoom/scripts.pory"
	.string "Ha sido un buen combate. Me quedo con\n"
	.string "ganas de más, la verdad.\p"
	.string "Tocará esperar a que completes el\n"
	.string "desafío para tener una revancha.$"

OmegaRoom_EventScript_StartChallenge_Text_6:
# 87 "data/maps/OmegaRoom/scripts.pory"
	.string "De todas formas, esta fue solo la\n"
	.string "primera sala; todavía tenés un largo\l"
	.string "camino por delante.$"

OmegaRoom_EventScript_StartChallenge_Text_7:
# 90 "data/maps/OmegaRoom/scripts.pory"
	.string "Va a ser interesante ver qué tanto\n"
	.string "puedes avanzar en este desafío.$"

OmegaRoom_EventScript_StartChallenge_Text_8:
# 93 "data/maps/OmegaRoom/scripts.pory"
	.string "Yo sigo activo por aquí, pero muchos de\n"
	.string "tus próximos rivales ya se habían\l"
	.string "retirado… y han vuelto especialmente\l"
	.string "para esta celebración.\p"
	.string "Pero recuerda, no subestimes a la vieja\n"
	.string "guardia. Son tercos, y cuando se ponen\l"
	.string "en serio, se nota.$"

OmegaRoom_EventScript_StartChallenge_Text_9:
# 99 "data/maps/OmegaRoom/scripts.pory"
	.string "Te he abierto la puerta. Ahora avanza, y\n"
	.string "demuestra que estas aquí para lograr\l"
	.string "grandes cosas.$"

OmegaRoom_Text_OmegaDefeated::
# 148 "data/maps/OmegaRoom/scripts.pory"
	.string "¡Qué nivel has demostrado! No esperaba\n"
	.string "un combate tan entretenido.$"
