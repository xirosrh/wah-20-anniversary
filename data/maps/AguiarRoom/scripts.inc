AguiarRoom_MapScripts::
# 6 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AguiarRoom_OnLoad
# 3 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AguiarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

AguiarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/AguiarRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, AguiarRoom_OnWarp_PlayerTurnNorth
	.2byte 0


AguiarRoom_OnLoad::
# 11 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_OnLoad_2
AguiarRoom_OnLoad_1:
	end

AguiarRoom_OnLoad_2:
# 12 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto AguiarRoom_OnLoad_1


AguiarRoom_OnWarp_PlayerTurnNorth::
# 18 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


AguiarRoom_EventScript_Aguiar::
# 23 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_EventScript_Aguiar_2
# 28 "data/maps/AguiarRoom/scripts.pory"
	lock
# 29 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_FACE_DOWN
# 30 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 31 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE
# 32 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 33 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 34 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE
# 35 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 36 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 37 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 38 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE
# 39 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 40 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 41 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE
# 44 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 45 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 46 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 47 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_5, MSGBOX_AUTOCLOSE
# 48 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_AguiarBattle
# 49 "data/maps/AguiarRoom/scripts.pory"
	delay 10
# 50 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_6, MSGBOX_AUTOCLOSE
# 51 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 52 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 53 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_7, MSGBOX_AUTOCLOSE
# 54 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 55 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_AGUIAR
# 56 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_SMOKING_LOOP
# 57 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_2:
# 24 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_NPC
# 25 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_EventScript_AguiarBattle::
# 62 "data/maps/AguiarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AguiarRoom_EventScript_AguiarBattle_2
# 65 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_AGUIAR
# 66 "data/maps/AguiarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 67 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AguiarRoom_EventScript_AguiarBattle_5
# 70 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE, AguiarRoom_Text_AguiarDefeated
AguiarRoom_EventScript_AguiarBattle_1:
# 73 "data/maps/AguiarRoom/scripts.pory"
	special HealPlayerParty
	return

AguiarRoom_EventScript_AguiarBattle_2:
# 63 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1

AguiarRoom_EventScript_AguiarBattle_5:
# 68 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1


AguiarRoom_EventScript_Aguiar_Text_0:
# 24 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí sigo, como siempre: tranquilo,\n"
	.string "fumando y esperando a ver quién\l"
	.string "aparece.$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 31 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero mírate! Al final has llegado hasta\n"
	.string "aquí.\p"
	.string "Y yo que pensaba que iba a pasarme el\n"
	.string "día tirado, con el cigarro y poco más…$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 34 "data/maps/AguiarRoom/scripts.pory"
	.string "No esperaba visitas, pero oye, me viene\n"
	.string "de lujo: así me entretengo un rato.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 38 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí todos se lo toman tan en serio,\n"
	.string "como si esto fuese cuestión de vida o\l"
	.string "muerte.\p"
	.string "Yo prefiero reírme, dar un par de\n"
	.string "caladas, y ver qué trae el que se planta\l"
	.string "delante.$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 41 "data/maps/AguiarRoom/scripts.pory"
	.string "No te voy a dar discursos épicos ni\n"
	.string "consejos de abuelo, que para eso hay\l"
	.string "otros.\p"
	.string "Si quieres pelear, perfecto. Si pierdo,\n"
	.string "pues nada, me enciendo otro.\p"
	.string "Y si gano… bueno, tampoco me voy a\n"
	.string "hacer un póster con tu cara, ¿eh?$"

AguiarRoom_EventScript_Aguiar_Text_5:
# 47 "data/maps/AguiarRoom/scripts.pory"
	.string "Así que venga, no le demos más vueltas.\n"
	.string "Saca a tus Pokémon, que yo ya tengo\l"
	.string "ganas de ver si al menos me haces dejar\l"
	.string "el cigarro quieto un rato.\p"
	.string "¡Vamos allá!$"

AguiarRoom_EventScript_Aguiar_Text_6:
# 50 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pues mira que me la has liado! Y yo\n"
	.string "pensando que iba a ser otro paseo…$"

AguiarRoom_EventScript_Aguiar_Text_7:
# 53 "data/maps/AguiarRoom/scripts.pory"
	.string "No está mal, no está nada mal. Ya puedes\n"
	.string "seguir avanzando.$"

AguiarRoom_Text_AguiarDefeated::
# 77 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Vaya combate! Me lo he pasado de\n"
	.string "lujo.$"
