ScarexOzumasRoom_MapScripts::
# 2 "data/maps/ScarexOzumasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ScarexOzumasRoom_OnTransition
	.byte 0


ScarexOzumasRoom_OnTransition::
	return


ScarexOzumasRoom_EventScript_EnterRoom::
# 9 "data/maps/ScarexOzumasRoom/scripts.pory"
	lock
# 10 "data/maps/ScarexOzumasRoom/scripts.pory"
	special SpawnCameraObject
# 11 "data/maps/ScarexOzumasRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 12 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 13 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 14 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 15 "data/maps/ScarexOzumasRoom/scripts.pory"
	showobjectat LOCALID_SCAREXOZUROOM_OZUMAS, MAP_SCAREX_OZUMAS_ROOM
# 16 "data/maps/ScarexOzumasRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SCAREXOZUROOM_OZUMAS, MOVEMENT_TYPE_FACE_DOWN
# 17 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkDown
# 18 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 19 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 20 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, ScarexOzumasRoom_EventScript_EnterRoom_Movement_0
# 33 "data/maps/ScarexOzumasRoom/scripts.pory"
	playse SE_PIN
# 34 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovement LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_QuestionMarkWithDelay48
# 35 "data/maps/ScarexOzumasRoom/scripts.pory"
	msgbox ScarexOzumasRoom_EventScript_EnterRoom_Text_0, MSGBOX_AUTOCLOSE
# 36 "data/maps/ScarexOzumasRoom/scripts.pory"
	waitmovement 0
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_1
# 43 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_FaceLeft
# 44 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_2
# 65 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_SweatDropWithDelay48
	return


ScarexOzumasRoom_EventScript_Ozumas::
	end


ScarexOzumasRoom_EventScript_Scarex::
	end


# 20 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_0:
# 21 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 21 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_down
# 22 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_right
# 23 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_right
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_up
# 28 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 29 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_left
# 30 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_8
# 31 "data/maps/ScarexOzumasRoom/scripts.pory"
	face_down
	step_end

# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_1:
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 39 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
# 41 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
	step_end

# 44 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_2:
# 45 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 45 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 45 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 46 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 47 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 48 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 49 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 50 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 50 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 51 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 52 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 53 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 54 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 55 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 55 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 56 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 57 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 58 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 59 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 60 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 61 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
# 62 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 63 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 63 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end

ScarexOzumasRoom_EventScript_EnterRoom_Text_0:
# 35 "data/maps/ScarexOzumasRoom/scripts.pory"
	.string "¿Y Scarex? Se supone ya debería estar\n"
	.string "aquí.$"
