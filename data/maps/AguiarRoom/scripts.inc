AguiarRoom_MapScripts::
	.byte 0


AguiarRoom_EventScript_Aguiar::
# 5 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_EventScript_Aguiar_2
# 10 "data/maps/AguiarRoom/scripts.pory"
	lock
# 11 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_FACE_DOWN
# 12 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 13 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE
# 14 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 15 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 16 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE
# 17 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 19 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 20 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE
# 21 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 22 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 23 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE
# 26 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 27 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 28 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 29 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_5, MSGBOX_AUTOCLOSE
# 30 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_EventScript_Aguiar_Text_6
# 31 "data/maps/AguiarRoom/scripts.pory"
	delay 10
# 32 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_7, MSGBOX_AUTOCLOSE
# 33 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 34 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 35 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_8, MSGBOX_AUTOCLOSE
# 36 "data/maps/AguiarRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 37 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_AGUIAR
# 38 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_SMOKING_LOOP
# 39 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_2:
# 6 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_NPC
# 7 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_EventScript_Aguiar_Text_0:
# 6 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí sigo, como siempre: tranquilo,\n"
	.string "fumando y esperando a ver quién\l"
	.string "aparece.$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 13 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero mírate! Al final has llegado hasta\n"
	.string "aquí.\p"
	.string "Y yo que pensaba que iba a pasarme el\n"
	.string "día tirado, con el cigarro y poco más…$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 16 "data/maps/AguiarRoom/scripts.pory"
	.string "No esperaba visitas, pero oye, me viene\n"
	.string "de lujo: así me entretengo un rato.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 20 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí todos se lo toman tan en serio,\n"
	.string "como si esto fuese cuestión de vida o\l"
	.string "muerte.\p"
	.string "Yo prefiero reírme, dar un par de\n"
	.string "caladas, y ver qué trae el que se planta\l"
	.string "delante.$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 23 "data/maps/AguiarRoom/scripts.pory"
	.string "No te voy a dar discursos épicos ni\n"
	.string "consejos de abuelo, que para eso hay\l"
	.string "otros.\p"
	.string "Si quieres pelear, perfecto. Si pierdo,\n"
	.string "pues nada, me enciendo otro.\p"
	.string "Y si gano… bueno, tampoco me voy a\n"
	.string "hacer un póster con tu cara, ¿eh?$"

AguiarRoom_EventScript_Aguiar_Text_5:
# 29 "data/maps/AguiarRoom/scripts.pory"
	.string "Así que venga, no le demos más vueltas.\n"
	.string "Saca a tus Pokémon, que yo ya tengo\l"
	.string "ganas de ver si al menos me haces dejar\l"
	.string "el cigarro quieto un rato.\p"
	.string "¡Vamos allá!$"

AguiarRoom_EventScript_Aguiar_Text_6:
# 30 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Vaya combate! Me lo he pasado de\n"
	.string "lujo.$"

AguiarRoom_EventScript_Aguiar_Text_7:
# 32 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pues mira que me la has liado! Y yo\n"
	.string "pensando que iba a ser otro paseo…$"

AguiarRoom_EventScript_Aguiar_Text_8:
# 35 "data/maps/AguiarRoom/scripts.pory"
	.string "No está mal, no está nada mal. Ya puedes\n"
	.string "seguir avanzando.$"
