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
	delay 50
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_M_SNORE
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 150
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_FACE_DOWN
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 30
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 49 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 57 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 59 "data/maps/SayerBlaxRoom/scripts.pory"
	waitse
# 60 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 62 "data/maps/SayerBlaxRoom/scripts.pory"
	waitse
# 63 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_3
# 68 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 69 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown3
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 71 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 74 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 75 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_4
# 83 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 84 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 85 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_JumpDown
# 86 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_5
# 88 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 89 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_6
# 90 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_7
# 92 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 93 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_JumpDown
# 94 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 95 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_7
# 96 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_8
# 98 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_SAYER
# 100 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 101 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 102 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_VersusWithDelay48
# 103 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_VersusWithDelay48
# 104 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 105 "data/maps/SayerBlaxRoom/scripts.pory"
	call SayerBlaxRoom_EventScript_SayerBlaxBattle
# 106 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 107 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_9
# 112 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_10
# 117 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 118 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 119 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_11
# 120 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_11
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 122 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 123 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown2
# 124 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 125 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 126 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_SweatDropWithDelay48
# 128 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 129 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_12
# 134 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_SLEEPING
# 135 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_WalkRight2
# 136 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 137 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, SP_NAME_SAYER
# 138 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_SAYER, 5, 10
# 140 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_SAYER, MOVEMENT_TYPE_FACE_RIGHT
# 141 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 142 "data/maps/SayerBlaxRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 143 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


SayerBlaxRoom_EventScript_Blax::
# 149 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Blax_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
	end


SayerBlaxRoom_EventScript_Sayer::
# 154 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Sayer_Text_0, MSGBOX_NPC, SP_NAME_SAYER
	end


SayerBlaxRoom_EventScript_SayerBlaxBattle::
# 159 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, SayerBlaxRoom_EventScript_SayerBlaxBattle_2
# 162 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BLAX
# 163 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 164 "data/maps/SayerBlaxRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 165 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SAYER
# 166 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 168 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_5
# 175 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_11
# 178 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
SayerBlaxRoom_EventScript_SayerBlaxBattle_1:
# 182 "data/maps/SayerBlaxRoom/scripts.pory"
	special HealPlayerParty
	return

SayerBlaxRoom_EventScript_SayerBlaxBattle_2:
# 160 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_5:
# 169 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_8
# 172 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_8:
# 170 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_11:
# 176 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1


# 51 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 56 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 58 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
	step_end

# 61 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
	step_end

# 64 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_3:
# 65 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 75 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_4:
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 78 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 80 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 87 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_5:
# 87 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
	step_end

# 89 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_6:
# 89 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_down
	step_end

# 91 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_7:
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_right
	step_end

# 97 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_8:
# 97 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
	step_end

# 107 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_9:
# 108 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
# 110 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 112 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_10:
# 113 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 114 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_up
# 115 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 119 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_11:
# 119 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
	step_end

# 129 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_12:
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar…$"

SayerBlaxRoom_OnFrame_Text_1:
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_2:
# 68 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_3:
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval{A}.\p"
	.string "Hemos pasado una pandemia incluso…\n"
	.string "Pero si insistes… No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_4:
# 83 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_5:
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_6:
# 125 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Ha sido un combate espectacular.\n"
	.string "Confirmamos que estoy más oxidado de\l"
	.string "lo que pensaba.$"

SayerBlaxRoom_OnFrame_Text_7:
# 128 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Todavía te quedan muchos combates por\n"
	.string "delante, pero aprovecha cada uno de\l"
	.string "ellos para celebrar estos 20 años del\l"
	.string "mejor foro de ROM Hacking y fangaming\l"
	.string "de Pokémon del mundo.\p"
	.string "Dicho esto… Me vuelvo a dormir. ¡Mucha\n"
	.string "suerte!$"

SayerBlaxRoom_OnFrame_Text_8:
# 137 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Y recuerda: No la líes y si puedes, pues\n"
	.string "si.$"

SayerBlaxRoom_EventScript_Blax_Text_0:
# 149 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Zzz… ¡Ve, BLAxTOISE!\p"
	.string "Zzz…$"

SayerBlaxRoom_EventScript_Sayer_Text_0:
# 154 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "No me puedo quejar la verdad, quedé\n"
	.string "bastante contento con la batalla.\p"
	.string "Avanza, fiera.$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_0:
# 160 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_EventScript_SayerBlaxBattle_Text_1:
# 160 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"

SayerBlaxRoom_Text_BlaxDefeated::
# 186 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_Text_SayerDefeated::
# 190 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues si que la has liado.$"
