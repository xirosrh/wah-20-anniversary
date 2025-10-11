ScarexOzumasRoom_MapScripts::
# 4 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ScarexOzumasRoom_OnTransition
	.byte 0


ScarexOzumasRoom_OnTransition::
	return


ScarexOzumasRoom_EventScript_EnterRoom::
# 11 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 12 "data/maps/ScarexOzumasRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 13 "data/maps/ScarexOzumasRoom/scripts.pory"
	special SpawnCameraObject
# 14 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 15 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 16 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 17 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 18 "data/maps/ScarexOzumasRoom/scripts.pory"
	showobjectat LOCALID_SCAREXOZUROOM_OZUMAS, MAP_SCAREX_OZUMAS_ROOM
# 19 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 20 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkDown
# 21 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 22 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 23 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_EnterRoom_Movement_0
# 36 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_QuestionMarkWithDelay48
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_EnterRoom_Text_0, MSGBOX_AUTOCLOSE
# 39 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_1
# 46 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_FaceLeft
# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_2
# 68 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
# 69 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 70 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_SCAREX, MOVEMENT_TYPE_FACE_DOWN
# 71 "data/maps/ScarexOzumasRoom/scripts.pory"
	turnobject LOCALID_SCAREXOZUROOM_OZUMAS, DIR_SOUTH
# 72 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 73 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 74 "data/maps/ScarexOzumasRoom/scripts.pory"
	special RemoveCameraObject
# 75 "data/maps/ScarexOzumasRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 76 "data/maps/ScarexOzumasRoom/scripts.pory"
	release
	end


ScarexOzumasRoom_EventScript_Ozumas::
	end


ScarexOzumasRoom_EventScript_Scarex::
	end


# 23 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_0:
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 28 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_right
# 29 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 30 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_up
# 31 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 32 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_left
# 33 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 34 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
	step_end

# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_1:
# 41 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 42 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 43 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
# 44 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
	step_end

# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_2:
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 49 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 50 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 51 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 52 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 53 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 53 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 54 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 55 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 56 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 57 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 60 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 61 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 61 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 62 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 63 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 64 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 66 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 66 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

ScarexOzumasRoom_EventScript_EnterRoom_Text_0:
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Y Scarex? Se supone ya debería estar\n"
	.string "aquí.$"
