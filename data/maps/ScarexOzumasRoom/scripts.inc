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
	fly_down
# 23 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
# 24 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_right
# 25 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_left
# 26 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_up
# 27 "data/maps/ScarexOzumasRoom/scripts.pory"
	walk_in_place_down
	step_end
