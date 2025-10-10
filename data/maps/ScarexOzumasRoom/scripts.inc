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
	applymovementandwait LOCALID_SCAREXOZUROOM_OZUMAS, Common_Movement_WalkDown
# 17 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay 20
# 18 "data/maps/ScarexOzumasRoom/scripts.pory"
	call PokemonLeague_EliteFour_CloseRoomDoorMetatiles
# 19 "data/maps/ScarexOzumasRoom/scripts.pory"
	applymovementandwait LOCALID_SCAREXOZUROOM_SCAREX, ScarexOzumasRoom_EventScript_EnterRoom_Movement_0
	return


ScarexOzumasRoom_EventScript_Ozumas::
	end


ScarexOzumasRoom_EventScript_Scarex::
	end


# 19 "data/maps/ScarexOzumasRoom/scripts.pory"
ScarexOzumasRoom_EventScript_EnterRoom_Movement_0:
# 20 "data/maps/ScarexOzumasRoom/scripts.pory"
	fly_up
# 21 "data/maps/ScarexOzumasRoom/scripts.pory"
	set_visible
# 22 "data/maps/ScarexOzumasRoom/scripts.pory"
	fall_down
# 23 "data/maps/ScarexOzumasRoom/scripts.pory"
	emote_x
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_16
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 28 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 29 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 29 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 30 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 31 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 32 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_left_right
# 33 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 34 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 34 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 35 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_right_left
# 36 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 37 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 38 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_down_up
# 39 "data/maps/ScarexOzumasRoom/scripts.pory"
	delay_4
# 40 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
# 41 "data/maps/ScarexOzumasRoom/scripts.pory"
	jump_in_place_up_down
# 42 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 42 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end
