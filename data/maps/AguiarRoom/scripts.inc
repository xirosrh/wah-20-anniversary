AguiarRoom_MapScripts::
# 9 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AguiarRoom_OnLoad
# 6 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AguiarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 10 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AguiarRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AguiarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/AguiarRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, AguiarRoom_OnWarp_PlayerTurnNorth
	.2byte 0

AguiarRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/AguiarRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, AguiarRoom_OnFrame
	.2byte 0


AguiarRoom_OnFrame::
# 17 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 18 "data/maps/AguiarRoom/scripts.pory"
	removeobject LOCALID_AGUIARROOM_AGUIAR_SMOKING
# 19 "data/maps/AguiarRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 20 "data/maps/AguiarRoom/scripts.pory"
	special SpawnCameraObject
# 21 "data/maps/AguiarRoom/scripts.pory"
	directcameramovementtopos 10, 6
# 22 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 23 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 24 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR, Common_Movement_HappyWithDelay48
# 26 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 27 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 28 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 29 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_TurnOffTV
# 30 "data/maps/AguiarRoom/scripts.pory"
	delay 30
# 31 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, AguiarRoom_OnFrame_Movement_0
# 32 "data/maps/AguiarRoom/scripts.pory"
	addobject LOCALID_AGUIARROOM_AGUIAR_SMOKING
# 33 "data/maps/AguiarRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 34 "data/maps/AguiarRoom/scripts.pory"
	removeobject LOCALID_AGUIARROOM_AGUIAR
# 35 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 36 "data/maps/AguiarRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 37 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 38 "data/maps/AguiarRoom/scripts.pory"
	special RemoveCameraObject
# 39 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 40 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_OnLoad::
# 45 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq AguiarRoom_OnLoad_2
AguiarRoom_OnLoad_1:
# 48 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_OnLoad_5
AguiarRoom_OnLoad_4:
	end

AguiarRoom_OnLoad_2:
# 46 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_TurnOnTV
	goto AguiarRoom_OnLoad_1

AguiarRoom_OnLoad_5:
# 49 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto AguiarRoom_OnLoad_4


AguiarRoom_OnWarp_PlayerTurnNorth::
# 55 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


AguiarRoom_EventScript_TurnOffTV::
# 60 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_aguiar_TV_OFF_LEFT, TRUE
# 61 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_aguiar_TV_OFF_RIGHT, TRUE
# 62 "data/maps/AguiarRoom/scripts.pory"
	special DrawWholeMapView
	return


AguiarRoom_EventScript_TurnOnTV::
# 67 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_aguiar_TV_ON_LEFT, TRUE
# 68 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_aguiar_TV_ON_RIGHT, TRUE
# 69 "data/maps/AguiarRoom/scripts.pory"
	special DrawWholeMapView
	return


AguiarRoom_EventScript_Aguiar::
# 74 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_EventScript_Aguiar_2
# 89 "data/maps/AguiarRoom/scripts.pory"
	lock
# 90 "data/maps/AguiarRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 91 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_5
AguiarRoom_EventScript_Aguiar_4:
# 102 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 103 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_FACE_DOWN
# 104 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 105 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 106 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 107 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 108 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 109 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 110 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 111 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 112 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 113 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 114 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 115 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 116 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 117 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 118 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 119 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 120 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 121 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 122 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 123 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 124 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, AguiarRoom_EventScript_Aguiar_Movement_0
# 125 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 126 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_AguiarBattle
# 127 "data/maps/AguiarRoom/scripts.pory"
	delay 10
# 128 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 129 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 130 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 131 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 132 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 133 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 134 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 135 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_AGUIAR
# 136 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_SMOKING_LOOP
# 137 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_2:
# 75 "data/maps/AguiarRoom/scripts.pory"
	lock
# 76 "data/maps/AguiarRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 77 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_8
AguiarRoom_EventScript_Aguiar_7:
# 80 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 81 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 82 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_11
AguiarRoom_EventScript_Aguiar_10:
# 86 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_5:
# 92 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR
# 93 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 94 "data/maps/AguiarRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 95 "data/maps/AguiarRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 6
# 96 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 97 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 98 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_AGUIARROOM_AGUIAR_SMOKING, DIR_SOUTH
# 99 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR_SMOKING
# 100 "data/maps/AguiarRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto AguiarRoom_EventScript_Aguiar_4

AguiarRoom_EventScript_Aguiar_8:
# 78 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR
	goto AguiarRoom_EventScript_Aguiar_7

AguiarRoom_EventScript_Aguiar_11:
# 83 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_AGUIARROOM_AGUIAR_SMOKING, DIR_SOUTH
# 84 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR_SMOKING
	goto AguiarRoom_EventScript_Aguiar_10


AguiarRoom_EventScript_AguiarBattle::
# 142 "data/maps/AguiarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AguiarRoom_EventScript_AguiarBattle_2
# 145 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_AGUIAR
# 146 "data/maps/AguiarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 147 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AguiarRoom_EventScript_AguiarBattle_5
# 150 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE, AguiarRoom_Text_AguiarDefeated
AguiarRoom_EventScript_AguiarBattle_1:
# 153 "data/maps/AguiarRoom/scripts.pory"
	special HealPlayerParty
	return

AguiarRoom_EventScript_AguiarBattle_2:
# 143 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1

AguiarRoom_EventScript_AguiarBattle_5:
# 148 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1


# 31 "data/maps/AguiarRoom/scripts.pory"
AguiarRoom_OnFrame_Movement_0:
# 31 "data/maps/AguiarRoom/scripts.pory"
	walk_down
# 31 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 31 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 31 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 31 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 31 "data/maps/AguiarRoom/scripts.pory"
	walk_up
# 31 "data/maps/AguiarRoom/scripts.pory"
	face_down
	step_end

# 124 "data/maps/AguiarRoom/scripts.pory"
AguiarRoom_EventScript_Aguiar_Movement_0:
# 124 "data/maps/AguiarRoom/scripts.pory"
	emote_versus
	step_end

AguiarRoom_OnFrame_Text_0:
# 23 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero qué buen programa! Hoy sí que es\n"
	.string "un día tranquilo.$"

AguiarRoom_OnFrame_Text_1:
# 28 "data/maps/AguiarRoom/scripts.pory"
	.string "Bueno, hora de dar un par de caladas.$"

AguiarRoom_EventScript_Aguiar_Text_0:
# 81 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí sigo, como siempre: tranquilo,\n"
	.string "fumando y esperando a ver quién\l"
	.string "aparece.$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 104 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero mírate! Al final has llegado hasta\n"
	.string "aquí.\p"
	.string "Y yo que pensaba que iba a pasarme el\n"
	.string "día tirado, con el cigarro y poco más…$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 109 "data/maps/AguiarRoom/scripts.pory"
	.string "No esperaba visitas, pero oye, me viene\n"
	.string "de lujo: así me entretengo un rato.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 113 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí todos se lo toman tan en serio,\n"
	.string "como si esto fuese cuestión de vida o\l"
	.string "muerte.\p"
	.string "Yo prefiero reírme, dar un par de\n"
	.string "caladas, y ver qué trae el que se planta\l"
	.string "delante.$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 118 "data/maps/AguiarRoom/scripts.pory"
	.string "No te voy a dar discursos épicos ni\n"
	.string "consejos de abuelo, que para eso hay\l"
	.string "otros.\p"
	.string "Si quieres pelear, perfecto. Si pierdo,\n"
	.string "pues nada, me enciendo otro.\p"
	.string "Y si gano… bueno, tampoco me voy a\n"
	.string "hacer un póster con tu cara, ¿eh?$"

AguiarRoom_EventScript_Aguiar_Text_5:
# 122 "data/maps/AguiarRoom/scripts.pory"
	.string "Así que venga, no le demos más vueltas.\n"
	.string "Saca a tus Pokémon, que yo ya tengo\l"
	.string "ganas de ver si al menos me haces dejar\l"
	.string "el cigarro quieto un rato.\p"
	.string "¡Vamos allá!$"

AguiarRoom_EventScript_Aguiar_Text_6:
# 128 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pues mira que me la has liado! Y yo\n"
	.string "pensando que iba a ser otro paseo…$"

AguiarRoom_EventScript_Aguiar_Text_7:
# 133 "data/maps/AguiarRoom/scripts.pory"
	.string "No está mal, no está nada mal. Ya puedes\n"
	.string "seguir avanzando.$"

AguiarRoom_Text_AguiarDefeated::
# 157 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Vaya combate! Me lo he pasado de\n"
	.string "lujo.$"
