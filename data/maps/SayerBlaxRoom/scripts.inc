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
	call WahRoomsShared_Kecleon_SetSala_SayerBlax
# 17 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq SayerBlaxRoom_OnTransition_2
SayerBlaxRoom_OnTransition_1:
	end

SayerBlaxRoom_OnTransition_2:
# 18 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype LOCALID_SAYERBLAXROOM_SAYER, MOVEMENT_TYPE_FACE_RIGHT
# 19 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxy LOCALID_SAYERBLAXROOM_SAYER, 5, 10
# 20 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_SAYER, 5, 10
	goto SayerBlaxRoom_OnTransition_1


SayerBlaxRoom_OnLoad::
# 26 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX, SayerBlaxRoom_OnLoad_2
SayerBlaxRoom_OnLoad_1:
	end

SayerBlaxRoom_OnLoad_2:
# 27 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto SayerBlaxRoom_OnLoad_1


SayerBlaxRoom_OnWarp_PlayerTurnNorth::
# 33 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


SayerBlaxRoom_OnFrame::
# 38 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShowMapNamePopup
# 39 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp3
# 40 "data/maps/SayerBlaxRoom/scripts.pory"
	special SpawnCameraObject
# 41 "data/maps/SayerBlaxRoom/scripts.pory"
	directcameramovementtopos 6, 5
# 42 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 43 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 50
# 44 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_M_SNORE
# 45 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 150
# 46 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_FACE_DOWN
# 47 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 48 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 30
# 49 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 50 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkLeft
# 51 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 53 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_0
# 59 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 60 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_1
# 61 "data/maps/SayerBlaxRoom/scripts.pory"
	waitse
# 62 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 63 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_2
# 64 "data/maps/SayerBlaxRoom/scripts.pory"
	waitse
# 65 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 66 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_3
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 71 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown3
# 72 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown5
# 73 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement LOCALID_CAMERA
# 74 "data/maps/SayerBlaxRoom/scripts.pory"
	special RemoveCameraObject
# 75 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 76 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 77 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_4
# 85 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 86 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 87 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_JumpDown
# 88 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 89 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_5
# 90 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_6
# 92 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 93 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_7
# 94 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 95 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_JumpDown
# 96 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 97 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_7
# 98 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_8
# 100 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 101 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_5, MSGBOX_DEFAULT, speaker = SP_NAME_SAYER
# 102 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_SAYERBLAXROOM_BLAX, DIR_SOUTH
# 103 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 104 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_VersusWithDelay48
# 105 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_VersusWithDelay48
# 106 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 107 "data/maps/SayerBlaxRoom/scripts.pory"
	call SayerBlaxRoom_EventScript_SayerBlaxBattle
# 108 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_LEDGE
# 109 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_9
# 114 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_10
# 119 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 120 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_SAYER, SayerBlaxRoom_OnFrame_Movement_11
# 122 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovement LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_11
# 123 "data/maps/SayerBlaxRoom/scripts.pory"
	waitmovement 0
# 124 "data/maps/SayerBlaxRoom/scripts.pory"
	delay 20
# 125 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_WalkDown2
# 126 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 128 "data/maps/SayerBlaxRoom/scripts.pory"
	playse SE_PIN
# 129 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, Common_Movement_SweatDropWithDelay48
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
# 131 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_BLAX, SayerBlaxRoom_OnFrame_Movement_12
# 136 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_BLAX, MOVEMENT_TYPE_SLEEPING
# 137 "data/maps/SayerBlaxRoom/scripts.pory"
	applymovementandwait LOCALID_SAYERBLAXROOM_SAYER, Common_Movement_WalkRight2
# 138 "data/maps/SayerBlaxRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_WEST
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, SP_NAME_SAYER
# 140 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 141 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectxyperm LOCALID_SAYERBLAXROOM_SAYER, 5, 10
# 142 "data/maps/SayerBlaxRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_SAYERBLAXROOM_SAYER, MOVEMENT_TYPE_FACE_RIGHT
# 143 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 144 "data/maps/SayerBlaxRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX
# 145 "data/maps/SayerBlaxRoom/scripts.pory"
	release
	end


SayerBlaxRoom_EventScript_Blax::
# 151 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Blax_Text_0, MSGBOX_AUTOCLOSE, SP_NAME_BLAX
	end


SayerBlaxRoom_EventScript_Sayer::
# 156 "data/maps/SayerBlaxRoom/scripts.pory"
	msgbox SayerBlaxRoom_EventScript_Sayer_Text_0, MSGBOX_NPC, SP_NAME_SAYER
	end


SayerBlaxRoom_EventScript_SayerBlaxBattle::
# 161 "data/maps/SayerBlaxRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, SayerBlaxRoom_EventScript_SayerBlaxBattle_2
# 164 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_BLAX
# 165 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 166 "data/maps/SayerBlaxRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 167 "data/maps/SayerBlaxRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_SAYER
# 168 "data/maps/SayerBlaxRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 170 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_0x8005, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_5
# 177 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_11
# 180 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
SayerBlaxRoom_EventScript_SayerBlaxBattle_1:
# 184 "data/maps/SayerBlaxRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
	return

SayerBlaxRoom_EventScript_SayerBlaxBattle_2:
# 162 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_5:
# 171 "data/maps/SayerBlaxRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq SayerBlaxRoom_EventScript_SayerBlaxBattle_8
# 174 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_ALTERNATIVE, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_8:
# 172 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_MAIN, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1

SayerBlaxRoom_EventScript_SayerBlaxBattle_11:
# 178 "data/maps/SayerBlaxRoom/scripts.pory"
	trainerbattle_two_trainers TRAINER_WAH_ADMIN_BLAX_ALTERNATIVE, SayerBlaxRoom_Text_BlaxDefeated, TRAINER_WAH_ADMIN_SAYER_MAIN, SayerBlaxRoom_Text_SayerDefeated
	goto SayerBlaxRoom_EventScript_SayerBlaxBattle_1


# 53 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_0:
# 54 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 55 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_down
# 56 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_left
# 57 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
# 58 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 60 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_1:
# 60 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_question_mark
	step_end

# 63 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_2:
# 63 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
	step_end

# 66 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_3:
# 67 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_in_place_down
# 68 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 77 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_4:
# 78 "data/maps/SayerBlaxRoom/scripts.pory"
	face_up
# 79 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 80 "data/maps/SayerBlaxRoom/scripts.pory"
	face_right
# 81 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
# 82 "data/maps/SayerBlaxRoom/scripts.pory"
	face_left
# 83 "data/maps/SayerBlaxRoom/scripts.pory"
	delay_16
	step_end

# 89 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_5:
# 89 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
	step_end

# 91 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_6:
# 91 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_down
	step_end

# 93 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_7:
# 93 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_right
	step_end

# 99 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_8:
# 99 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_right
	step_end

# 109 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_9:
# 110 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 111 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_left
# 112 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 114 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_10:
# 115 "data/maps/SayerBlaxRoom/scripts.pory"
	lock_facing_direction
# 116 "data/maps/SayerBlaxRoom/scripts.pory"
	jump_2_up
# 117 "data/maps/SayerBlaxRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 121 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_11:
# 121 "data/maps/SayerBlaxRoom/scripts.pory"
	emote_x
	step_end

# 131 "data/maps/SayerBlaxRoom/scripts.pory"
SayerBlaxRoom_OnFrame_Movement_12:
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 132 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_up
# 133 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 133 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 133 "data/maps/SayerBlaxRoom/scripts.pory"
	walk_right
# 134 "data/maps/SayerBlaxRoom/scripts.pory"
	face_down
	step_end

SayerBlaxRoom_OnFrame_Text_0:
# 49 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Fuaaah, ¡qué cansancio! Con lo que me\n"
	.string "hacía falta descansar…$"

SayerBlaxRoom_OnFrame_Text_1:
# 52 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Ya es el día del aniversario?$"

SayerBlaxRoom_OnFrame_Text_2:
# 70 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Tú quién eres?$"

SayerBlaxRoom_OnFrame_Text_3:
# 75 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Cómo, que quieres combatir? Yo me\n"
	.string "jubilé hace muchos años chaval{A}.\p"
	.string "Hemos pasado una pandemia incluso…\n"
	.string "Pero si insistes… No creas que te lo\l"
	.string "pondré fácil.$"

SayerBlaxRoom_OnFrame_Text_4:
# 85 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "¿Y ahora dónde se ha metido Sayer…? Se\n"
	.string "supone nos tocaba combatir a los dos.$"

SayerBlaxRoom_OnFrame_Text_5:
# 101 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Welcome to the jungle!$"

SayerBlaxRoom_OnFrame_Text_6:
# 127 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Ha sido un combate espectacular.\n"
	.string "Confirmamos que estoy más oxidado de\l"
	.string "lo que pensaba.$"

SayerBlaxRoom_OnFrame_Text_7:
# 130 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Todavía te quedan muchos combates por\n"
	.string "delante, pero aprovecha cada uno de\l"
	.string "ellos para celebrar estos 20 años del\l"
	.string "mejor foro de ROM Hacking y fangaming\l"
	.string "de Pokémon del mundo.\p"
	.string "Dicho esto… Me vuelvo a dormir. ¡Mucha\n"
	.string "suerte!$"

SayerBlaxRoom_OnFrame_Text_8:
# 139 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Y recuerda: No la líes y si puedes, pues\n"
	.string "si.$"

SayerBlaxRoom_EventScript_Blax_Text_0:
# 151 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Zzz… ¡Ve, BLAxTOISE!\p"
	.string "Zzz…$"

SayerBlaxRoom_EventScript_Sayer_Text_0:
# 156 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "No me puedo quejar la verdad, quedé\n"
	.string "bastante contento con la batalla.\p"
	.string "Avanza, fiera.$"

SayerBlaxRoom_Text_BlaxDefeated::
# 188 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Bueno, pues has ganado. ¡Enhorabuena!$"

SayerBlaxRoom_Text_SayerDefeated::
# 192 "data/maps/SayerBlaxRoom/scripts.pory"
	.string "Pues sí que la has liado.$"
