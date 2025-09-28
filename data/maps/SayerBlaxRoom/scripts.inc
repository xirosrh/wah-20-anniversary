SayerBlaxRoom_MapScripts::
# 2 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SayerBlaxRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SayerBlaxRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script_2 VAR_SAYER_BLAX_ROOM_STATE, 0, SayerBlaxRoom_OnFrame
	.2byte 0


SayerBlaxRoom_OnFrame::
# 8 "data/maps/SayerBlaxRoom/scripts.pory"
	lock
# 9 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp3
# 10 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 11 "data/maps/SayerBlaxRoom/scripts.pory"
	special SpawnCameraObject
# 12 "data/maps/SayerBlaxRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 13 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 14 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 15 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 16 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 17 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 23 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 24 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 30 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 31 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown4
# 33 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 34 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 35 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 36 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 37 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_3
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_GOCE_MAIN, SayerBlaxRoom_OnFrame_Text_5, TRAINER_WAH_ADMIN_OMEGA_MAIN, SayerBlaxRoom_OnFrame_Text_6
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_SAYER_BLAX_ROOM_STATE, 1
# 56 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


# 17 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 18 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 19 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 20 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 21 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 22 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 25 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 26 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
# 27 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 27 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 28 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 37 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 38 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 39 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 40 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 41 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 47 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_3:
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
# 49 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_right
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 16 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar...\p"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_1:
# 31 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_2:
# 35 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval.\p"
	.string "Hemos pasado una pandemia incluso...\n"
	.string "Pero si insistes... No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_3:
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_4:
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_5:
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Perdi blax$"

SayerBlaxRoom_OnFrame_Text_6:
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Perdi sayer$"
