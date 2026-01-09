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
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp3
# 9 "data/maps/SayerBlaxRoom/scripts.pory"
	special SpawnCameraObject
# 10 "data/maps/SayerBlaxRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 11 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 12 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 200
# 13 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_FACE_DOWN
# 14 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 15 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 30
# 16 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 17 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 18 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 19 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE
# 20 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 26 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 27 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 33 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown4
# 34 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 35 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 36 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE
# 37 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 38 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_3
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_5
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_VersusWithDelay48
# 57 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_VersusWithDelay48
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 59 "data/maps/SayerBlaxRoom/scripts.pory"
	call SayerBlaxRoom_EventScript_SayerBlaxBattle
# 60 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_4
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_5
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 74 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown2
# 75 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_6, MSGBOX_DEFAULT
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_SweatDropWithDelay48
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 80 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_6
# 85 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_SLEEPING
# 86 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_WalkRight2
# 87 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 88 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 89 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_SAYER_BLAX_ROOM_STATE, 1
# 90 "data/maps/SayerBlaxRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 92 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


SayerBlaxRoom_EventScript_Blax::
# 98 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Blax_Text_0, MSGBOX_AUTOCLOSE
	end


SayerBlaxRoom_EventScript_Sayer::
# 103 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Sayer_Text_0, MSGBOX_AUTOCLOSE
	end


SayerBlaxRoom_EventScript_SayerBlaxBattle::
# 108 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, SayerBlaxRoom_EventScript_SayerBlaxBattle_2
# 111 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BLAX
# 112 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 113 "data/maps/SayerBlaxRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 114 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SAYER
# 115 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 117 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_5
# 124 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_11
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
SayerBlaxRoom_EventScript_SayerBlaxBattle_1:
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	special HealPlayerParty
	return

SayerBlaxRoom_EventScript_SayerBlaxBattle_2:
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_5:
# 118 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_8
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_8:
# 119 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_11:
# 125 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1


# 20 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 21 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 22 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 23 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 24 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 25 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 27 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 28 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
# 29 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 29 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 30 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 38 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 39 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 40 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 41 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
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

# 60 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_4:
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 62 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 63 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 66 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_5:
# 67 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 68 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 69 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_up
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 80 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_6:
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 83 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 16 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar…$"

SayerBlaxRoom_OnFrame_Text_1:
# 19 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_2:
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_3:
# 36 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval.\p"
	.string "Hemos pasado una pandemia incluso…\n"
	.string "Pero si insistes… No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_4:
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_5:
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_6:
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Ha sido un combate espectacular.\n"
	.string "Confirmamos que estoy más oxidado de\l"
	.string "lo que pensaba.$"

SayerBlaxRoom_OnFrame_Text_7:
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Todavía te quedan muchos combates por\n"
	.string "delante, pero aprovecha cada uno de\l"
	.string "ellos para celebrar estos 20 años del\l"
	.string "mejor foro de ROM Hacking y fangaming\l"
	.string "de Pokémon del mundo.\p"
	.string "Dicho esto… Me vuelvo a dormir. ¡Mucha\n"
	.string "suerte!$"

SayerBlaxRoom_OnFrame_Text_8:
# 88 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Y recuerda: No la líes y si puedes, pues\n"
	.string "si.$"

SayerBlaxRoom_EventScript_Blax_Text_0:
# 98 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Zzz… ¡Ve, BLAxTOISE!\p"
	.string "Zzz…$"

SayerBlaxRoom_EventScript_Sayer_Text_0:
# 103 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "No me puedo quejar la verdad, quedé\n"
	.string "bastante contento con la batalla.\p"
	.string "Avanza, fiera.$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0:
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1:
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"

SayerBlaxRoom_Text_BlaxDefeated::
# 135 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_Text_SayerDefeated::
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"
