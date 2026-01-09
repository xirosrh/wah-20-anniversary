AguiarRoom_MapScripts::
	.byte 0


AguiarRoom_EventScript_Aguiar::
# 6 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_EventScript_Aguiar_2
# 11 "data/maps/AguiarRoom/scripts.pory"
	lock
# 12 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_FACE_DOWN
# 13 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 14 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE
# 15 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 16 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 17 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE
# 18 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 19 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 20 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 21 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE
# 22 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 23 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 24 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE
# 27 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 29 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 30 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_5, MSGBOX_AUTOCLOSE
# 31 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_AguiarBattle
# 32 "data/maps/AguiarRoom/scripts.pory"
	delay 10
# 33 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_6, MSGBOX_AUTOCLOSE
# 34 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 35 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 36 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_7, MSGBOX_AUTOCLOSE
# 37 "data/maps/AguiarRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 38 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_AGUIAR
# 39 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_SMOKING_LOOP
# 40 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_2:
# 7 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_NPC
# 8 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_EventScript_AguiarBattle::
# 45 "data/maps/AguiarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AguiarRoom_EventScript_AguiarBattle_2
# 48 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_AGUIAR
# 49 "data/maps/AguiarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 50 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AguiarRoom_EventScript_AguiarBattle_5
# 53 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE, AguiarRoom_Text_AguiarDefeated
AguiarRoom_EventScript_AguiarBattle_1:
# 56 "data/maps/AguiarRoom/scripts.pory"
	special HealPlayerParty
	return

AguiarRoom_EventScript_AguiarBattle_2:
# 46 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1

AguiarRoom_EventScript_AguiarBattle_5:
# 51 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1


AguiarRoom_EventScript_Aguiar_Text_0:
# 7 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí sigo, como siempre: tranquilo,\n"
	.string "fumando y esperando a ver quién\l"
	.string "aparece.$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 14 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero mírate! Al final has llegado hasta\n"
	.string "aquí.\p"
	.string "Y yo que pensaba que iba a pasarme el\n"
	.string "día tirado, con el cigarro y poco más…$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 17 "data/maps/AguiarRoom/scripts.pory"
	.string "No esperaba visitas, pero oye, me viene\n"
	.string "de lujo: así me entretengo un rato.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 21 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí todos se lo toman tan en serio,\n"
	.string "como si esto fuese cuestión de vida o\l"
	.string "muerte.\p"
	.string "Yo prefiero reírme, dar un par de\n"
	.string "caladas, y ver qué trae el que se planta\l"
	.string "delante.$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 24 "data/maps/AguiarRoom/scripts.pory"
	.string "No te voy a dar discursos épicos ni\n"
	.string "consejos de abuelo, que para eso hay\l"
	.string "otros.\p"
	.string "Si quieres pelear, perfecto. Si pierdo,\n"
	.string "pues nada, me enciendo otro.\p"
	.string "Y si gano… bueno, tampoco me voy a\n"
	.string "hacer un póster con tu cara, ¿eh?$"

AguiarRoom_EventScript_Aguiar_Text_5:
# 30 "data/maps/AguiarRoom/scripts.pory"
	.string "Así que venga, no le demos más vueltas.\n"
	.string "Saca a tus Pokémon, que yo ya tengo\l"
	.string "ganas de ver si al menos me haces dejar\l"
	.string "el cigarro quieto un rato.\p"
	.string "¡Vamos allá!$"

AguiarRoom_EventScript_Aguiar_Text_6:
# 33 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pues mira que me la has liado! Y yo\n"
	.string "pensando que iba a ser otro paseo…$"

AguiarRoom_EventScript_Aguiar_Text_7:
# 36 "data/maps/AguiarRoom/scripts.pory"
	.string "No está mal, no está nada mal. Ya puedes\n"
	.string "seguir avanzando.$"

AguiarRoom_Text_AguiarDefeated::
# 60 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Vaya combate! Me lo he pasado de\n"
	.string "lujo.$"
