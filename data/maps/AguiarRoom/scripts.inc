AguiarRoom_MapScripts::
# 9 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AguiarRoom_OnLoad
# 13 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AguiarRoom_OnTransition
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
# 18 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 19 "data/maps/AguiarRoom/scripts.pory"
	removeobject LOCALID_AGUIARROOM_AGUIAR_SMOKING
# 20 "data/maps/AguiarRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 21 "data/maps/AguiarRoom/scripts.pory"
	special SpawnCameraObject
# 22 "data/maps/AguiarRoom/scripts.pory"
	directcameramovementtopos 10, 6
# 23 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 24 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR, Common_Movement_HappyWithDelay48
# 26 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 27 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 29 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 30 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_TurnOffTV
# 31 "data/maps/AguiarRoom/scripts.pory"
	delay 30
# 32 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, AguiarRoom_OnFrame_Movement_0
# 33 "data/maps/AguiarRoom/scripts.pory"
	addobject LOCALID_AGUIARROOM_AGUIAR_SMOKING
# 34 "data/maps/AguiarRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 35 "data/maps/AguiarRoom/scripts.pory"
	removeobject LOCALID_AGUIARROOM_AGUIAR
# 36 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 37 "data/maps/AguiarRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 38 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 39 "data/maps/AguiarRoom/scripts.pory"
	special RemoveCameraObject
# 40 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 41 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_OnLoad::
# 46 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq AguiarRoom_OnLoad_2
AguiarRoom_OnLoad_1:
# 49 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_OnLoad_5
AguiarRoom_OnLoad_4:
	end

AguiarRoom_OnLoad_2:
# 47 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_TurnOnTV
	goto AguiarRoom_OnLoad_1

AguiarRoom_OnLoad_5:
# 50 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto AguiarRoom_OnLoad_4


AguiarRoom_OnWarp_PlayerTurnNorth::
# 56 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


AguiarRoom_OnTransition::
# 61 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Aguiar
	end


AguiarRoom_EventScript_TurnOffTV::
# 66 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_aguiar_TV_OFF_LEFT, TRUE
# 67 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_aguiar_TV_OFF_RIGHT, TRUE
# 68 "data/maps/AguiarRoom/scripts.pory"
	special DrawWholeMapView
	return


AguiarRoom_EventScript_TurnOnTV::
# 73 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_aguiar_TV_ON_LEFT, TRUE
# 74 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_aguiar_TV_ON_RIGHT, TRUE
# 75 "data/maps/AguiarRoom/scripts.pory"
	special DrawWholeMapView
	return


AguiarRoom_EventScript_Aguiar::
# 80 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_EventScript_Aguiar_2
# 95 "data/maps/AguiarRoom/scripts.pory"
	lock
# 96 "data/maps/AguiarRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 97 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_5
AguiarRoom_EventScript_Aguiar_4:
# 108 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 109 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_FACE_DOWN
# 110 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 111 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 112 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 113 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 114 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 115 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 116 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 117 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 118 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 119 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 120 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 121 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 122 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 123 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 124 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 127 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 128 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 129 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 130 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 131 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 132 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, AguiarRoom_EventScript_Aguiar_Movement_0
# 133 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 134 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_AguiarBattle
# 135 "data/maps/AguiarRoom/scripts.pory"
	delay 10
# 136 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 137 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 138 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 139 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 140 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 141 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 142 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 143 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_AGUIAR
# 144 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_SMOKING_LOOP
# 145 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_2:
# 81 "data/maps/AguiarRoom/scripts.pory"
	lock
# 82 "data/maps/AguiarRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 83 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_8
AguiarRoom_EventScript_Aguiar_7:
# 86 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 87 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 88 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_11
AguiarRoom_EventScript_Aguiar_10:
# 92 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_5:
# 98 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR
# 99 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 100 "data/maps/AguiarRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 101 "data/maps/AguiarRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 6
# 102 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 103 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 104 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_AGUIARROOM_AGUIAR_SMOKING, DIR_SOUTH
# 105 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR_SMOKING
# 106 "data/maps/AguiarRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto AguiarRoom_EventScript_Aguiar_4

AguiarRoom_EventScript_Aguiar_8:
# 84 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR
	goto AguiarRoom_EventScript_Aguiar_7

AguiarRoom_EventScript_Aguiar_11:
# 89 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_AGUIARROOM_AGUIAR_SMOKING, DIR_SOUTH
# 90 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR_SMOKING
	goto AguiarRoom_EventScript_Aguiar_10


AguiarRoom_EventScript_AguiarBattle::
# 150 "data/maps/AguiarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AguiarRoom_EventScript_AguiarBattle_2
# 153 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_AGUIAR
# 154 "data/maps/AguiarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 155 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AguiarRoom_EventScript_AguiarBattle_5
# 158 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE, AguiarRoom_Text_AguiarDefeated
AguiarRoom_EventScript_AguiarBattle_1:
# 161 "data/maps/AguiarRoom/scripts.pory"
	special HealPlayerParty
	return

AguiarRoom_EventScript_AguiarBattle_2:
# 151 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1

AguiarRoom_EventScript_AguiarBattle_5:
# 156 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1


# 32 "data/maps/AguiarRoom/scripts.pory"
AguiarRoom_OnFrame_Movement_0:
# 32 "data/maps/AguiarRoom/scripts.pory"
	walk_down
# 32 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 32 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 32 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 32 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 32 "data/maps/AguiarRoom/scripts.pory"
	walk_up
# 32 "data/maps/AguiarRoom/scripts.pory"
	face_down
	step_end

# 132 "data/maps/AguiarRoom/scripts.pory"
AguiarRoom_EventScript_Aguiar_Movement_0:
# 132 "data/maps/AguiarRoom/scripts.pory"
	emote_versus
	step_end

AguiarRoom_OnFrame_Text_0:
# 26 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero qué buen programa! Hoy si que es\n"
	.string "un día tranquilo.$"

AguiarRoom_OnFrame_Text_1:
# 29 "data/maps/AguiarRoom/scripts.pory"
	.string "Bueno, hora de dar un par de caladas.$"

AguiarRoom_EventScript_Aguiar_Text_0:
# 87 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí sigo, como siempre: tranquilo,\n"
	.string "fumando y esperando a ver quién\l"
	.string "aparece.$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 110 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero mírate! Al final has llegado hasta\n"
	.string "aquí.\p"
	.string "Y yo que pensaba que iba a pasarme el\n"
	.string "día tirado, con el cigarro y poco más…$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 115 "data/maps/AguiarRoom/scripts.pory"
	.string "No esperaba visitas, pero oye, me viene\n"
	.string "de lujo: así me entretengo un rato.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 119 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí todos se lo toman tan en serio,\n"
	.string "como si esto fuese cuestión de vida o\l"
	.string "muerte.\p"
	.string "Yo prefiero reírme, dar un par de\n"
	.string "caladas, y ver qué trae el que se planta\l"
	.string "delante.$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 124 "data/maps/AguiarRoom/scripts.pory"
	.string "No te voy a dar discursos épicos ni\n"
	.string "consejos de abuelo, que para eso hay\l"
	.string "otros.\p"
	.string "Si quieres pelear, perfecto. Si pierdo,\n"
	.string "pues nada, me enciendo otro.\p"
	.string "Y si gano… bueno, tampoco me voy a\n"
	.string "hacer un póster con tu cara, ¿eh?$"

AguiarRoom_EventScript_Aguiar_Text_5:
# 130 "data/maps/AguiarRoom/scripts.pory"
	.string "Así que venga, no le demos más vueltas.\n"
	.string "Saca a tus Pokémon, que yo ya tengo\l"
	.string "ganas de ver si al menos me haces dejar\l"
	.string "el cigarro quieto un rato.\p"
	.string "¡Vamos allá!$"

AguiarRoom_EventScript_Aguiar_Text_6:
# 136 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pues mira que me la has liado! Y yo\n"
	.string "pensando que iba a ser otro paseo…$"

AguiarRoom_EventScript_Aguiar_Text_7:
# 141 "data/maps/AguiarRoom/scripts.pory"
	.string "No está mal, no está nada mal. Ya puedes\n"
	.string "seguir avanzando.$"

AguiarRoom_Text_AguiarDefeated::
# 165 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Vaya combate! Me lo he pasado de\n"
	.string "lujo.$"
