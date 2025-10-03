AguiarRoom_MapScripts::
	.byte 0


AguiarRoom_EventScript_Aguiar::
# 5 "data/maps/AguiarRoom/scripts.pory"
	lock
# 6 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR, MOVEMENT_TYPE_FACE_DOWN
# 7 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 8 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_AUTOCLOSE
# 9 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, Common_Movement_SmokeCigarette
# 10 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 11 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE
# 12 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 13 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, Common_Movement_HappyWithDelay48
# 14 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 15 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE
# 16 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, Common_Movement_SmokeCigarette
# 17 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 18 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE
# 21 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 22 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, Common_Movement_HappyWithDelay48
# 23 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 24 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE
# 26 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR, MOVEMENT_TYPE_SMOKING_LOOP
# 27 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_EventScript_Aguiar_Text_0:
# 8 "data/maps/AguiarRoom/scripts.pory"
	.string "¡Pero mírate! Al final has llegado hasta\n"
	.string "aquí.\p"
	.string "Y yo que pensaba que iba a pasarme el\n"
	.string "día tirado, con el cigarro y poco más…$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 11 "data/maps/AguiarRoom/scripts.pory"
	.string "No esperaba visitas, pero oye, me viene\n"
	.string "de lujo: así me entretengo un rato.$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 15 "data/maps/AguiarRoom/scripts.pory"
	.string "Aquí todos se lo toman tan en serio,\n"
	.string "como si esto fuese cuestión de vida o\l"
	.string "muerte.\p"
	.string "Yo prefiero reírme, dar un par de\n"
	.string "caladas, y ver qué trae el que se planta\l"
	.string "delante.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 18 "data/maps/AguiarRoom/scripts.pory"
	.string "No te voy a dar discursos épicos ni\n"
	.string "consejos de abuelo, que para eso hay\l"
	.string "otros.\p"
	.string "Si quieres pelear, perfecto. Si pierdo,\n"
	.string "pues nada, me enciendo otro.\p"
	.string "Y si gano… bueno, tampoco me voy a\n"
	.string "hacer un póster con tu cara, ¿eh?$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 24 "data/maps/AguiarRoom/scripts.pory"
	.string "Así que venga, no le demos más vueltas.\n"
	.string "Saca a tus Pokémon, que yo ya tengo\l"
	.string "ganas de ver si al menos me haces dejar\l"
	.string "el cigarro quieto un rato.\p"
	.string "¡Vamos allá!$"
