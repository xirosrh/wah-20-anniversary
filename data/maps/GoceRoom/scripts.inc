GoceRoom_MapScripts::
# 5 "data/maps/GoceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoceRoom_OnLoad
# 2 "data/maps/GoceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoceRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GoceRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/GoceRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, GoceRoom_OnWarp_PlayerTurnNorth
	.2byte 0


GoceRoom_OnLoad::
# 10 "data/maps/GoceRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GOCE, GoceRoom_OnLoad_2
GoceRoom_OnLoad_1:
	end

GoceRoom_OnLoad_2:
# 11 "data/maps/GoceRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto GoceRoom_OnLoad_1


GoceRoom_OnWarp_PlayerTurnNorth::
# 17 "data/maps/GoceRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


GoceRoom_EventScript_Goce::
# 22 "data/maps/GoceRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GOCE, GoceRoom_EventScript_Goce_1
# 28 "data/maps/GoceRoom/scripts.pory"
	lock
# 29 "data/maps/GoceRoom/scripts.pory"
	faceplayer
# 30 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_1, speaker = SP_NAME_GOCE
# 32 "data/maps/GoceRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, GoceRoom_EventScript_Goce_5
# 35 "data/maps/GoceRoom/scripts.pory"
	setvar VAR_0x8004, 2
# 36 "data/maps/GoceRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 37 "data/maps/GoceRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GoceRoom_EventScript_Goce_12
# 40 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_ALTERNATIVE, GoceRoom_EventScript_Goce_Text_2
GoceRoom_EventScript_Goce_4:
# 43 "data/maps/GoceRoom/scripts.pory"
	delay 10
# 44 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOCE
# 45 "data/maps/GoceRoom/scripts.pory"
	delay 20
# 46 "data/maps/GoceRoom/scripts.pory"
	playse SE_PIN
# 47 "data/maps/GoceRoom/scripts.pory"
	applymovement LOCALID_GOCEROOM_GOCE, Common_Movement_QuestionMarkWithDelay48
# 48 "data/maps/GoceRoom/scripts.pory"
	waitmovement 0
# 49 "data/maps/GoceRoom/scripts.pory"
	waitse
# 50 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOCE
# 51 "data/maps/GoceRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 52 "data/maps/GoceRoom/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq GoceRoom_EventScript_Goce_9
# 58 "data/maps/GoceRoom/scripts.pory"
	applymovementandwait LOCALID_GOCEROOM_GOCE, GoceRoom_EventScript_Goce_Movement_1
# 60 "data/maps/GoceRoom/scripts.pory"
	setobjectxy LOCALID_GOCEROOM_GOCE, 5, 5
# 61 "data/maps/GoceRoom/scripts.pory"
	setobjectxyperm LOCALID_GOCEROOM_GOCE, 5, 5
GoceRoom_EventScript_Goce_8:
# 63 "data/maps/GoceRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 64 "data/maps/GoceRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GOCE
# 65 "data/maps/GoceRoom/scripts.pory"
	release
	end

GoceRoom_EventScript_Goce_1:
# 23 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_0, MSGBOX_NPC, speaker = SP_NAME_GOCE
# 24 "data/maps/GoceRoom/scripts.pory"
	release
	end

GoceRoom_EventScript_Goce_5:
# 33 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_MAIN, GoceRoom_EventScript_Goce_Text_2
	goto GoceRoom_EventScript_Goce_4

GoceRoom_EventScript_Goce_9:
# 53 "data/maps/GoceRoom/scripts.pory"
	applymovementandwait LOCALID_GOCEROOM_GOCE, GoceRoom_EventScript_Goce_Movement_0
# 55 "data/maps/GoceRoom/scripts.pory"
	setobjectxy LOCALID_GOCEROOM_GOCE, 7, 5
# 56 "data/maps/GoceRoom/scripts.pory"
	setobjectxyperm LOCALID_GOCEROOM_GOCE, 7, 5
	goto GoceRoom_EventScript_Goce_8

GoceRoom_EventScript_Goce_12:
# 38 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_MAIN, GoceRoom_EventScript_Goce_Text_2
	goto GoceRoom_EventScript_Goce_4


# 53 "data/maps/GoceRoom/scripts.pory"
GoceRoom_EventScript_Goce_Movement_0:
# 54 "data/maps/GoceRoom/scripts.pory"
	lock_facing_direction
# 54 "data/maps/GoceRoom/scripts.pory"
	walk_right
# 54 "data/maps/GoceRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 58 "data/maps/GoceRoom/scripts.pory"
GoceRoom_EventScript_Goce_Movement_1:
# 59 "data/maps/GoceRoom/scripts.pory"
	face_right
# 59 "data/maps/GoceRoom/scripts.pory"
	lock_facing_direction
# 59 "data/maps/GoceRoom/scripts.pory"
	walk_left
# 59 "data/maps/GoceRoom/scripts.pory"
	unlock_facing_direction
	step_end

GoceRoom_EventScript_Goce_Text_0:
# 23 "data/maps/GoceRoom/scripts.pory"
	.string "Ya puedes avanzar al siguiente\n"
	.string "desafío.\p"
	.string "Todavía queda mucho por recorrer.$"

GoceRoom_EventScript_Goce_Text_1:
# 30 "data/maps/GoceRoom/scripts.pory"
	.string "A ver, chiquitín. No fui el más conocido\n"
	.string "ni estuve demasiado tiempo...\p"
	.string "Fui apenas una chispa atrapada en\n"
	.string "{COLOR LIGHT_RED}ámbar{COLOR DARK_GRAY}.\p"
	.string "Pero esa chispa fue el inicio de todo\n"
	.string "esto, y hoy te toca enfrentarte a ella.$"

GoceRoom_EventScript_Goce_Text_2:
# 33 "data/maps/GoceRoom/scripts.pory"
	.string "Increíble como han evolucionado en\n"
	.string "estos últimos 20 años...$"

GoceRoom_EventScript_Goce_Text_3:
# 44 "data/maps/GoceRoom/scripts.pory"
	.string "¡Gran batalla! Has podido derrotar al\n"
	.string "gran fundador, seguro estarás orgullos{OA}.$"

GoceRoom_EventScript_Goce_Text_4:
# 50 "data/maps/GoceRoom/scripts.pory"
	.string "Eh, ¿así que no sabes quién soy? Me\n"
	.string "conocieron como {COLOR RED}Goce{COLOR DARK_GRAY} y como {COLOR RED}Lance{COLOR DARK_GRAY}.\p"
	.string "Igual, lo que importa no es mi nombre,\n"
	.string "sino que lo que comenzó siga vivo.\p"
	.string "Tú acabas de demostrarme que lo está,\n"
	.string "niñ{OA}.\p"
	.string "Puedes continuar.$"
