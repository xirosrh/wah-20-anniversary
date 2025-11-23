TokynWarRoom_MapScripts::
	.byte 0


TokynWarRoom_EventScript_Magikarp::
# 5 "data/maps/TokynWarRoom/scripts.pory"
	lock
# 6 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_LEFT, 70, 55, VAR_TEMP_2
# 7 "data/maps/TokynWarRoom/scripts.pory"
	load_field_pic FP_MAGIKARP_JUMPING_RIGHT, 134, 55, VAR_TEMP_3
# 8 "data/maps/TokynWarRoom/scripts.pory"
	delay 100
# 9 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_LEFT, VAR_TEMP_2
# 10 "data/maps/TokynWarRoom/scripts.pory"
	destroy_field_pic FP_MAGIKARP_JUMPING_RIGHT, VAR_TEMP_3
# 11 "data/maps/TokynWarRoom/scripts.pory"
	release
	end

