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
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp3
# 10 "data/maps/SayerBlaxRoom/scripts.pory"
	special SpawnCameraObject
# 11 "data/maps/SayerBlaxRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 12 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 13 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 14 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 15 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 16 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 22 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 23 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 28 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 29 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown4
# 30 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 31 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 33 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 34 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_3
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 49 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_OnFrame_Text_5, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_OnFrame_Text_6
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_4
# 57 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_5
# 63 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 65 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown2
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 67 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_7, MSGBOX_DEFAULT
# 68 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 69 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_SweatDropWithDelay48
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 71 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_6
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_WalkRight2
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE
# 78 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_SAYER_BLAX_ROOM_STATE, 1
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


# 16 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 17 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 18 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 19 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 20 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 21 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 23 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 24 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
# 25 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 25 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 26 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 34 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 35 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 36 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 37 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 38 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 39 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 40 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 43 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_3:
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_right
	step_end

# 51 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_4:
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 57 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_5:
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 59 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 60 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_up
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 71 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_6:
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 74 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 15 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar...\p"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_1:
# 28 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_2:
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval.\p"
	.string "Hemos pasado una pandemia incluso...\n"
	.string "Pero si insistes... No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_3:
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_4:
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_5:
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_OnFrame_Text_6:
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"

SayerBlaxRoom_OnFrame_Text_7:
# 67 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Ha sido un combate espectacular.\n"
	.string "Confirmamos que estoy más oxidado de\l"
	.string "lo que pensaba.$"

SayerBlaxRoom_OnFrame_Text_8:
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Todavía te quedan muchos combates por\n"
	.string "delante, pero aprovecha cada uno de\l"
	.string "ellos para celebrar estos 20 años del\l"
	.string "mejor foro de ROM Hacking y fangaming\l"
	.string "de Pokémon del mundo.\p"
	.string "Dicho esto... Me vuelvo a dormir. ¡Mucha\n"
	.string "suerte!$"

SayerBlaxRoom_OnFrame_Text_9:
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Y recuerda: No la líes y si puedes, pues\n"
	.string "si.$"
