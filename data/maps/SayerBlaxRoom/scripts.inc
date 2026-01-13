SayerBlaxRoom_MapScripts::
# 10 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SayerBlaxRoom_OnLoad
# 4 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SayerBlaxRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 7 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SayerBlaxRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

SayerBlaxRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 5 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, SayerBlaxRoom_OnFrame
	.2byte 0

SayerBlaxRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, SayerBlaxRoom_OnWarp_PlayerTurnNorth
	.2byte 0


SayerBlaxRoom_OnLoad::
# 14 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX, SayerBlaxRoom_OnLoad_2
SayerBlaxRoom_OnLoad_1:
	end

SayerBlaxRoom_OnLoad_2:
# 15 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto SayerBlaxRoom_OnLoad_1


SayerBlaxRoom_OnWarp_PlayerTurnNorth::
# 21 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


SayerBlaxRoom_OnFrame::
# 26 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp3
# 27 "data/maps/SayerBlaxRoom/scripts.pory"
	special SpawnCameraObject
# 28 "data/maps/SayerBlaxRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 29 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 200
# 31 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_FACE_DOWN
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 33 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 30
# 34 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 35 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 36 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 37 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 38 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown4
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 56 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 65 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_3
# 69 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_5
# 71 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 74 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_VersusWithDelay48
# 75 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_VersusWithDelay48
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	call SayerBlaxRoom_EventScript_SayerBlaxBattle
# 78 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_4
# 84 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_5
# 90 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 92 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown2
# 93 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 94 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_6, MSGBOX_DEFAULT
# 95 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_SweatDropWithDelay48
# 97 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 98 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_6
# 103 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_SLEEPING
# 104 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_WalkRight2
# 105 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 106 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 107 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 108 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 110 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


SayerBlaxRoom_EventScript_Blax::
# 116 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Blax_Text_0, MSGBOX_AUTOCLOSE
	end


SayerBlaxRoom_EventScript_Sayer::
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Sayer_Text_0, MSGBOX_AUTOCLOSE
	end


SayerBlaxRoom_EventScript_SayerBlaxBattle::
# 126 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, SayerBlaxRoom_EventScript_SayerBlaxBattle_2
# 129 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BLAX
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SAYER
# 133 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 135 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_5
# 142 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_11
# 145 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
SayerBlaxRoom_EventScript_SayerBlaxBattle_1:
# 149 "data/maps/SayerBlaxRoom/scripts.pory"
	special HealPlayerParty
	return

SayerBlaxRoom_EventScript_SayerBlaxBattle_2:
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_5:
# 136 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_8
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_8:
# 137 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_11:
# 143 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1


# 38 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 39 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 40 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 41 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 45 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 57 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 59 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 60 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 62 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 65 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_3:
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
# 67 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_right
	step_end

# 78 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_4:
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 80 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 84 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_5:
# 85 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 86 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 87 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_up
# 88 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 98 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_6:
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 100 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 100 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 100 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 101 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 34 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar…$"

SayerBlaxRoom_OnFrame_Text_1:
# 37 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_2:
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_3:
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval.\p"
	.string "Hemos pasado una pandemia incluso…\n"
	.string "Pero si insistes… No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_4:
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_5:
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_6:
# 94 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Ha sido un combate espectacular.\n"
	.string "Confirmamos que estoy más oxidado de\l"
	.string "lo que pensaba.$"

SayerBlaxRoom_OnFrame_Text_7:
# 97 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Todavía te quedan muchos combates por\n"
	.string "delante, pero aprovecha cada uno de\l"
	.string "ellos para celebrar estos 20 años del\l"
	.string "mejor foro de ROM Hacking y fangaming\l"
	.string "de Pokémon del mundo.\p"
	.string "Dicho esto… Me vuelvo a dormir. ¡Mucha\n"
	.string "suerte!$"

SayerBlaxRoom_OnFrame_Text_8:
# 106 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Y recuerda: No la líes y si puedes, pues\n"
	.string "si.$"

SayerBlaxRoom_EventScript_Blax_Text_0:
# 116 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Zzz… ¡Ve, BLAxTOISE!\p"
	.string "Zzz…$"

SayerBlaxRoom_EventScript_Sayer_Text_0:
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "No me puedo quejar la verdad, quedé\n"
	.string "bastante contento con la batalla.\p"
	.string "Avanza, fiera.$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0:
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1:
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"

SayerBlaxRoom_Text_BlaxDefeated::
# 153 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_Text_SayerDefeated::
# 157 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"
