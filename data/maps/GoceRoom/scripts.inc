GoceRoom_MapScripts::
	.byte 0


GoceRoom_EventScript_Goce::
# 5 "data/maps/GoceRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GOCE, GoceRoom_EventScript_Goce_2
# 11 "data/maps/GoceRoom/scripts.pory"
	lock
# 12 "data/maps/GoceRoom/scripts.pory"
	faceplayer
# 13 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_1
# 14 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_MAIN, GoceRoom_EventScript_Goce_Text_2
# 15 "data/maps/GoceRoom/scripts.pory"
	delay 10
# 16 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_3, MSGBOX_AUTOCLOSE
# 17 "data/maps/GoceRoom/scripts.pory"
	playse SE_PIN
# 18 "data/maps/GoceRoom/scripts.pory"
	applymovement LOCALID_GOCEROOM_GOCE, Common_Movement_QuestionMarkWithDelay48
# 19 "data/maps/GoceRoom/scripts.pory"
	waitmovement 0
# 20 "data/maps/GoceRoom/scripts.pory"
	waitse
# 21 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_4, MSGBOX_AUTOCLOSE
# 22 "data/maps/GoceRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 23 "data/maps/GoceRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GOCE
# 24 "data/maps/GoceRoom/scripts.pory"
	release
	end

GoceRoom_EventScript_Goce_2:
# 6 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_0, MSGBOX_NPC
# 7 "data/maps/GoceRoom/scripts.pory"
	release
	end


GoceRoom_EventScript_Goce_Text_0:
# 6 "data/maps/GoceRoom/scripts.pory"
	.string "Ya puedes avanzar al siguiente\n"
	.string "desafío.\p"
	.string "Todavía queda mucho por recorrer.$"

GoceRoom_EventScript_Goce_Text_1:
# 13 "data/maps/GoceRoom/scripts.pory"
	.string "A ver, chiquitín. No fui el más conocido\n"
	.string "ni estuve demasiado tiempo...\p"
	.string "Fui apenas una chispa atrapada en\n"
	.string "{COLOR LIGHT_RED}ámbar{COLOR DARK_GRAY}.\p"
	.string "Pero esa chispa fue el inicio de todo\n"
	.string "esto, y hoy te toca enfrentarte a ella.$"

GoceRoom_EventScript_Goce_Text_2:
# 14 "data/maps/GoceRoom/scripts.pory"
	.string "Increíble como han evolucionado en\n"
	.string "estos últimos 20 años...$"

GoceRoom_EventScript_Goce_Text_3:
# 16 "data/maps/GoceRoom/scripts.pory"
	.string "¡Gran batalla! Has podido derrotar al\n"
	.string "gran fundador, seguro estarás orgullos{OA}.$"

GoceRoom_EventScript_Goce_Text_4:
# 21 "data/maps/GoceRoom/scripts.pory"
	.string "Eh, ¿así que no sabes quién soy? Me\n"
	.string "conocieron como {COLOR RED}Goce{COLOR DARK_GRAY} y como {COLOR RED}Lance{COLOR DARK_GRAY}.\p"
	.string "Igual, lo que importa no es mi nombre,\n"
	.string "sino que lo que comenzó siga vivo.\p"
	.string "Tú acabas de demostrarme que lo está,\n"
	.string "niñ{OA}.\p"
	.string "Puedes continuar.$"
