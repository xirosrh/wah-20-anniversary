AngelRoom_MapScripts::
# 5 "data/maps/AngelRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AngelRoom_OnLoad
# 2 "data/maps/AngelRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AngelRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

AngelRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/AngelRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, AngelRoom_OnWarp_PlayerTurnNorth
	.2byte 0


AngelRoom_OnWarp_PlayerTurnNorth::
# 10 "data/maps/AngelRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


AngelRoom_OnLoad::
# 14 "data/maps/AngelRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_ANGEL, AngelRoom_OnLoad_2
AngelRoom_OnLoad_1:
	end

AngelRoom_OnLoad_2:
# 15 "data/maps/AngelRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto AngelRoom_OnLoad_1


AngelRoom_EventScript_Angel::
# 20 "data/maps/AngelRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_ANGEL, AngelRoom_EventScript_Angel_2
# 25 "data/maps/AngelRoom/scripts.pory"
	lock
# 26 "data/maps/AngelRoom/scripts.pory"
	faceplayer
# 27 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/AngelRoom/scripts.pory"
	applymovement LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_0
# 34 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 35 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 36 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 37 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 38 "data/maps/AngelRoom/scripts.pory"
	delay 10
# 39 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 40 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_HappyWithDelay48
# 41 "data/maps/AngelRoom/scripts.pory"
	waitse
# 42 "data/maps/AngelRoom/scripts.pory"
	delay 30
# 43 "data/maps/AngelRoom/scripts.pory"
	getobjectfacingdirection LOCALID_PLAYER, VAR_TEMP_0
# 44 "data/maps/AngelRoom/scripts.pory"
	switch VAR_TEMP_0
# 45 "data/maps/AngelRoom/scripts.pory"
	case DIR_NORTH, AngelRoom_EventScript_Angel_6
# 48 "data/maps/AngelRoom/scripts.pory"
	case DIR_SOUTH, AngelRoom_EventScript_Angel_7
# 51 "data/maps/AngelRoom/scripts.pory"
	case DIR_WEST, AngelRoom_EventScript_Angel_8
# 54 "data/maps/AngelRoom/scripts.pory"
	case DIR_EAST, AngelRoom_EventScript_Angel_9
AngelRoom_EventScript_Angel_4:
# 58 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 59 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 60 "data/maps/AngelRoom/scripts.pory"
	switch VAR_TEMP_0
# 61 "data/maps/AngelRoom/scripts.pory"
	case DIR_NORTH, AngelRoom_EventScript_Angel_12
# 64 "data/maps/AngelRoom/scripts.pory"
	case DIR_SOUTH, AngelRoom_EventScript_Angel_13
# 67 "data/maps/AngelRoom/scripts.pory"
	case DIR_WEST, AngelRoom_EventScript_Angel_14
# 70 "data/maps/AngelRoom/scripts.pory"
	case DIR_EAST, AngelRoom_EventScript_Angel_15
AngelRoom_EventScript_Angel_10:
# 74 "data/maps/AngelRoom/scripts.pory"
	waitse
# 75 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_4, speaker = SP_NAME_ANGEL
# 77 "data/maps/AngelRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_ANGEL_MAIN, AngelRoom_EventScript_Angel_Text_5
# 78 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 79 "data/maps/AngelRoom/scripts.pory"
	playse SE_PIN
# 80 "data/maps/AngelRoom/scripts.pory"
	applymovement LOCALID_ANGELROOM_ANGEL, Common_Movement_SurpriseWithDelay48
# 81 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 82 "data/maps/AngelRoom/scripts.pory"
	waitmovement 0
# 83 "data/maps/AngelRoom/scripts.pory"
	delay 20
# 84 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_ANGEL
# 85 "data/maps/AngelRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 86 "data/maps/AngelRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_ANGEL
# 87 "data/maps/AngelRoom/scripts.pory"
	release
	end

AngelRoom_EventScript_Angel_2:
# 21 "data/maps/AngelRoom/scripts.pory"
	msgbox AngelRoom_EventScript_Angel_Text_0, MSGBOX_NPC, speaker = SP_NAME_ANGEL
# 22 "data/maps/AngelRoom/scripts.pory"
	release
	end

AngelRoom_EventScript_Angel_6:
# 46 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkUp2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_7:
# 49 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkDown2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_8:
# 52 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkLeft2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_9:
# 55 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, Common_Movement_WalkRight2
	goto AngelRoom_EventScript_Angel_4

AngelRoom_EventScript_Angel_12:
# 62 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_1
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_13:
# 65 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_2
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_14:
# 68 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_3
	goto AngelRoom_EventScript_Angel_10

AngelRoom_EventScript_Angel_15:
# 71 "data/maps/AngelRoom/scripts.pory"
	applymovementandwait LOCALID_ANGELROOM_ANGEL, AngelRoom_EventScript_Angel_Movement_4
	goto AngelRoom_EventScript_Angel_10


# 28 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_0:
# 29 "data/maps/AngelRoom/scripts.pory"
	emote_double_exclamation_mark
# 30 "data/maps/AngelRoom/scripts.pory"
	lock_facing_direction
# 31 "data/maps/AngelRoom/scripts.pory"
	jump_in_place_down
# 32 "data/maps/AngelRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 62 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_1:
# 62 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 62 "data/maps/AngelRoom/scripts.pory"
	jump_2_down
# 62 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 62 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 65 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_2:
# 65 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 65 "data/maps/AngelRoom/scripts.pory"
	jump_2_up
# 65 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 65 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 68 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_3:
# 68 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 68 "data/maps/AngelRoom/scripts.pory"
	jump_2_right
# 68 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 68 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

# 71 "data/maps/AngelRoom/scripts.pory"
AngelRoom_EventScript_Angel_Movement_4:
# 71 "data/maps/AngelRoom/scripts.pory"
	emote_versus
# 71 "data/maps/AngelRoom/scripts.pory"
	jump_2_left
# 71 "data/maps/AngelRoom/scripts.pory"
	delay_16
# 71 "data/maps/AngelRoom/scripts.pory"
	delay_16
	step_end

AngelRoom_EventScript_Angel_Text_0:
# 21 "data/maps/AngelRoom/scripts.pory"
	.string "¡Me alegro de verte de nuevo! Espero\n"
	.string "que sigas siendo tan fuerte como la\l"
	.string "última vez.$"

AngelRoom_EventScript_Angel_Text_1:
# 34 "data/maps/AngelRoom/scripts.pory"
	.string "¡Cuánto tiempo!$"

AngelRoom_EventScript_Angel_Text_2:
# 37 "data/maps/AngelRoom/scripts.pory"
	.string "Ha pasado mucho desde la última vez,\n"
	.string "¿verdad?\p"
	.string "Espero que este reencuentro… ¡SEA\n"
	.string "MEMORABLE!$"

AngelRoom_EventScript_Angel_Text_3:
# 58 "data/maps/AngelRoom/scripts.pory"
	.string "Veamos tu potencial.$"

AngelRoom_EventScript_Angel_Text_4:
# 75 "data/maps/AngelRoom/scripts.pory"
	.string "¡Ven! ¡Atácame con todo lo que tengas!$"

AngelRoom_EventScript_Angel_Text_5:
# 77 "data/maps/AngelRoom/scripts.pory"
	.string "¿Así que este es el poder de la nueva\n"
	.string "generación?$"

AngelRoom_EventScript_Angel_Text_6:
# 81 "data/maps/AngelRoom/scripts.pory"
	.string "¡Increíble! ¡El poder de la nueva\n"
	.string "generación es asombroso!$"

AngelRoom_EventScript_Angel_Text_7:
# 84 "data/maps/AngelRoom/scripts.pory"
	.string "No esperaba perder y aún así, no me\n"
	.string "dejaste opciones.\p"
	.string "Dejo en tus manos el legado de toda mi\n"
	.string "generación. ¡Espero de verdad que\l"
	.string "volvamos a encontrarnos algún día y\l"
	.string "poder volver a pelear juntos!$"
