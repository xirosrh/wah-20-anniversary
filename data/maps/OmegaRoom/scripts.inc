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
	call OmegaRoom_EventScript_EmptyCapsule
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
	fadescreen FADE_TO_BLACK
# 34 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 35 "data/maps/OmegaRoom/scripts.pory"
	call OmegaRoom_EventScript_EmptyCapsule
# 36 "data/maps/OmegaRoom/scripts.pory"
	showobjectat LOCALID_OMEGAROOM_OMEGA, MAP_OMEGA_ROOM
# 37 "data/maps/OmegaRoom/scripts.pory"
	setobjectmovementtype LOCALID_OMEGAROOM_OMEGA, MOVEMENT_TYPE_FACE_DOWN
# 38 "data/maps/OmegaRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_OMEGAROOM_OMEGA, MOVEMENT_TYPE_FACE_DOWN
# 39 "data/maps/OmegaRoom/scripts.pory"
	turnobject LOCALID_OMEGAROOM_OMEGA, DIR_SOUTH
# 40 "data/maps/OmegaRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 41 "data/maps/OmegaRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 42 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/OmegaRoom/scripts.pory"
	special RemoveCameraObject
# 44 "data/maps/OmegaRoom/scripts.pory"
	applymovementandwait LOCALID_OMEGAROOM_OMEGA, Common_Movement_JumpInPlaceDown
# 45 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_0
# 46 "data/maps/OmegaRoom/scripts.pory"
	subvar VAR_TEMP_D, 1
# 47 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_0
# 49 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_PLAYER, OmegaRoom_EventScript_StartChallenge_Movement_1
# 50 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/OmegaRoom/scripts.pory"
	delay 30
# 52 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_1
# 53 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_MAIN, OmegaRoom_EventScript_StartChallenge_Text_2
# 54 "data/maps/OmegaRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_OMEGA
# 55 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 56 "data/maps/OmegaRoom/scripts.pory"
	release
	end


OmegaRoom_EventScript_OmegaAwakens::
# 61 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 4, METATILE_room_omega_OMEGA_AWAKENS_1, FALSE
# 62 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 4, METATILE_room_omega_OMEGA_AWAKENS_2, FALSE
# 63 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 4, METATILE_room_omega_OMEGA_AWAKENS_3, FALSE
# 64 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 5, METATILE_room_omega_OMEGA_AWAKENS_4, FALSE
# 65 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 5, METATILE_room_omega_OMEGA_AWAKENS_5, FALSE
# 66 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_omega_OMEGA_AWAKENS_6, FALSE
# 67 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 6, METATILE_room_omega_OMEGA_AWAKENS_7, TRUE
# 68 "data/maps/OmegaRoom/scripts.pory"
	special DrawWholeMapView
	return


OmegaRoom_EventScript_EmptyCapsule::
# 73 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 4, METATILE_room_omega_EMPTY_1, FALSE
# 74 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 4, METATILE_room_omega_EMPTY_2, FALSE
# 75 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 4, METATILE_room_omega_EMPTY_3, FALSE
# 76 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 5, 5, METATILE_room_omega_EMPTY_4, FALSE
# 77 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 5, METATILE_room_omega_EMPTY_5, FALSE
# 78 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 7, 5, METATILE_room_omega_EMPTY_6, FALSE
# 79 "data/maps/OmegaRoom/scripts.pory"
	setmetatile 6, 6, METATILE_room_omega_OMEGA_AWAKENS_7, TRUE
# 80 "data/maps/OmegaRoom/scripts.pory"
	special DrawWholeMapView
	return


# 47 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_0:
# 48 "data/maps/OmegaRoom/scripts.pory"
	jump_2_down
	step_end

# 49 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_1:
# 49 "data/maps/OmegaRoom/scripts.pory"
	emote_question_mark
# 49 "data/maps/OmegaRoom/scripts.pory"
	delay_8
# 49 "data/maps/OmegaRoom/scripts.pory"
	lock_facing_direction
# 49 "data/maps/OmegaRoom/scripts.pory"
	jump_down
# 49 "data/maps/OmegaRoom/scripts.pory"
	unlock_facing_direction
	step_end

OmegaRoom_EventScript_StartChallenge_Text_0:
# 45 "data/maps/OmegaRoom/scripts.pory"
	.string "Ostras, une nuevo desafiante.$"

OmegaRoom_EventScript_StartChallenge_Text_1:
# 52 "data/maps/OmegaRoom/scripts.pory"
	.string "XXX$"

OmegaRoom_EventScript_StartChallenge_Text_2:
# 53 "data/maps/OmegaRoom/scripts.pory"
	.string "XX$"
