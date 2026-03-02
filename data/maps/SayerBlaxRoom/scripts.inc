SayerBlaxRoom_MapScripts::
# 10 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SayerBlaxRoom_OnLoad
# 11 "data/maps/SayerBlaxRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SayerBlaxRoom_OnTransition
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


SayerBlaxRoom_OnTransition::
# 16 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq SayerBlaxRoom_OnTransition_2
SayerBlaxRoom_OnTransition_1:
	end

SayerBlaxRoom_OnTransition_2:
# 17 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype LOCALID_SAYERBLAXROOM_SAYER, MOVEMENT_TYPE_FACE_RIGHT
# 18 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxy LOCALID_SAYERBLAXROOM_SAYER, 5, 10
# 19 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_SAYER, 5, 10
	goto SayerBlaxRoom_OnTransition_1


SayerBlaxRoom_OnLoad::
# 25 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX, SayerBlaxRoom_OnLoad_2
SayerBlaxRoom_OnLoad_1:
	end

SayerBlaxRoom_OnLoad_2:
# 26 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto SayerBlaxRoom_OnLoad_1


SayerBlaxRoom_OnWarp_PlayerTurnNorth::
# 32 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


SayerBlaxRoom_OnFrame::
# 37 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp3
# 38 "data/maps/SayerBlaxRoom/scripts.pory"
	special SpawnCameraObject
# 39 "data/maps/SayerBlaxRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 40 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 41 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 200
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_FACE_DOWN
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 30
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 49 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 56 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 62 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown3
# 63 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 65 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 67 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 68 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 78 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_JumpDown
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 80 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_3
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_4
# 83 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 84 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_5
# 85 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 86 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_JumpDown
# 87 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 88 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_5
# 89 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 90 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_6
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 92 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_SAYER
# 93 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 94 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 95 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_VersusWithDelay48
# 96 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_VersusWithDelay48
# 97 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 98 "data/maps/SayerBlaxRoom/scripts.pory"
	call SayerBlaxRoom_EventScript_SayerBlaxBattle
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_7
# 105 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_8
# 111 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 112 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 113 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown2
# 114 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 115 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 116 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 117 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_SweatDropWithDelay48
# 118 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 119 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_9
# 124 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_SLEEPING
# 125 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_WalkRight2
# 126 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, SP_NAME_SAYER
# 128 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 129 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_SAYER, 5, 10
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_SAYER, MOVEMENT_TYPE_FACE_RIGHT
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 133 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


SayerBlaxRoom_EventScript_Blax::
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Blax_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
	end


SayerBlaxRoom_EventScript_Sayer::
# 144 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Sayer_Text_0, MSGBOX_NPC, SP_NAME_SAYER
	end


SayerBlaxRoom_EventScript_SayerBlaxBattle::
# 149 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, SayerBlaxRoom_EventScript_SayerBlaxBattle_2
# 152 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BLAX
# 153 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 154 "data/maps/SayerBlaxRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 155 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SAYER
# 156 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 158 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_5
# 165 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_11
# 168 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
SayerBlaxRoom_EventScript_SayerBlaxBattle_1:
# 172 "data/maps/SayerBlaxRoom/scripts.pory"
	special HealPlayerParty
	return

SayerBlaxRoom_EventScript_SayerBlaxBattle_2:
# 150 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_5:
# 159 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_8
# 162 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_8:
# 160 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_11:
# 166 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1


# 49 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 56 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 57 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 59 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 68 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 69 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 71 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 74 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 80 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_3:
# 80 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
	step_end

# 82 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_4:
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_down
	step_end

# 84 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_5:
# 84 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_right
	step_end

# 90 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_6:
# 90 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
	step_end

# 99 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_7:
# 100 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 101 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 102 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
# 103 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 105 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_8:
# 106 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
# 107 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 108 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_up
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 119 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_9:
# 120 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 120 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 120 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 120 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 122 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar…$"

SayerBlaxRoom_OnFrame_Text_1:
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_2:
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_3:
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval.\p"
	.string "Hemos pasado una pandemia incluso…\n"
	.string "Pero si insistes… No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_4:
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_5:
# 92 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_6:
# 115 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Ha sido un combate espectacular.\n"
	.string "Confirmamos que estoy más oxidado de\l"
	.string "lo que pensaba.$"

SayerBlaxRoom_OnFrame_Text_7:
# 118 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Todavía te quedan muchos combates por\n"
	.string "delante, pero aprovecha cada uno de\l"
	.string "ellos para celebrar estos 20 años del\l"
	.string "mejor foro de ROM Hacking y fangaming\l"
	.string "de Pokémon del mundo.\p"
	.string "Dicho esto… Me vuelvo a dormir. ¡Mucha\n"
	.string "suerte!$"

SayerBlaxRoom_OnFrame_Text_8:
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Y recuerda: No la líes y si puedes, pues\n"
	.string "si.$"

SayerBlaxRoom_EventScript_Blax_Text_0:
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Zzz… ¡Ve, BLAxTOISE!\p"
	.string "Zzz…$"

SayerBlaxRoom_EventScript_Sayer_Text_0:
# 144 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "No me puedo quejar la verdad, quedé\n"
	.string "bastante contento con la batalla.\p"
	.string "Avanza, fiera.$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0:
# 150 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1:
# 150 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"

SayerBlaxRoom_Text_BlaxDefeated::
# 176 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_Text_SayerDefeated::
# 180 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"
