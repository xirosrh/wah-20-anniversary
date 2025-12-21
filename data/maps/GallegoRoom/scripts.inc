GallegoRoom_MapScripts::
# 5 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GallegoRoom_OnLoad
# 2 "data/maps/GallegoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GallegoRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/GallegoRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, GallegoRoom_OnWarp_PlayerTurnNorth
	.2byte 0


GallegoRoom_OnLoad::
# 9 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_OnLoad_2
GallegoRoom_OnLoad_1:
	end

GallegoRoom_OnLoad_2:
# 10 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto GallegoRoom_OnLoad_1


GallegoRoom_OnWarp_PlayerTurnNorth::
# 16 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


GallegoRoom_EventScript_Gallego::
# 21 "data/maps/GallegoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GALLEGO, GallegoRoom_EventScript_Gallego_2
# 31 "data/maps/GallegoRoom/scripts.pory"
	lock
# 32 "data/maps/GallegoRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 33 "data/maps/GallegoRoom/scripts.pory"
	switch VAR_RESULT
# 34 "data/maps/GallegoRoom/scripts.pory"
	case DIR_SOUTH, GallegoRoom_EventScript_Gallego_6
# 42 "data/maps/GallegoRoom/scripts.pory"
	case DIR_EAST, GallegoRoom_EventScript_Gallego_7
GallegoRoom_EventScript_Gallego_4:
# 49 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_2
# 50 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_2, MSGBOX_AUTOCLOSE_TOP
# 51 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_3
# 64 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_3, MSGBOX_AUTOCLOSE_TOP
# 65 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 66 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 67 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 68 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 69 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceDown
# 70 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 71 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 72 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 73 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_4
# 81 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 82 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 83 "data/maps/GallegoRoom/scripts.pory"
	delay 40
# 84 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 85 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 86 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HeartWithDelay48
# 87 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 88 "data/maps/GallegoRoom/scripts.pory"
	special SpawnCameraObject
# 89 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkUp2
# 90 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 91 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 92 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 93 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_FacePlayer
# 94 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 95 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 97 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkDown2
# 98 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 99 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 100 "data/maps/GallegoRoom/scripts.pory"
	special RemoveCameraObject
# 101 "data/maps/GallegoRoom/scripts.pory"
	delay 50
# 102 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_5
# 107 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 108 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 109 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_6
# 110 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 111 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_SurpriseWithDelay48
# 112 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_GALLEGOROOM_GALLEGO, DIR_NORTH
# 113 "data/maps/GallegoRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_SOUTH
# 114 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 115 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 116 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_WalkInPlaceUp
# 117 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 118 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_7
# 124 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp
# 125 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_13, speaker = SP_NAME_GALLEGO
# 126 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 127 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_8
# 135 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_14, speaker = SP_NAME_GALLEGO
# 136 "data/maps/GallegoRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GALLEGO_MAIN, GallegoRoom_EventScript_Gallego_Text_15
# 137 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 138 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 139 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 140 "data/maps/GallegoRoom/scripts.pory"
	delay 60
# 141 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 142 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 143 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_SweatDropWithDelay48
# 144 "data/maps/GallegoRoom/scripts.pory"
	delay 30
# 145 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_18, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 146 "data/maps/GallegoRoom/scripts.pory"
	applymovement LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_9
# 153 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_19, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 154 "data/maps/GallegoRoom/scripts.pory"
	waitmovement 0
# 155 "data/maps/GallegoRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 156 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_20, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 157 "data/maps/GallegoRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GALLEGO
# 158 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_2:
# 22 "data/maps/GallegoRoom/scripts.pory"
	lock
# 23 "data/maps/GallegoRoom/scripts.pory"
	faceplayer
# 24 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 25 "data/maps/GallegoRoom/scripts.pory"
	playse SE_PIN
# 26 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, Common_Movement_HappyWithDelay48
# 27 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GALLEGO
# 28 "data/maps/GallegoRoom/scripts.pory"
	release
	end

GallegoRoom_EventScript_Gallego_6:
# 35 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_0
	goto GallegoRoom_EventScript_Gallego_4

GallegoRoom_EventScript_Gallego_7:
# 43 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, GallegoRoom_EventScript_Gallego_Movement_1
	goto GallegoRoom_EventScript_Gallego_4


# 35 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_0:
# 36 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 37 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 37 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 38 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 39 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 43 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_1:
# 44 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 45 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 46 "data/maps/GallegoRoom/scripts.pory"
	face_up
	step_end

# 49 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_2:
# 49 "data/maps/GallegoRoom/scripts.pory"
	reveal_trainer
# 49 "data/maps/GallegoRoom/scripts.pory"
	walk_in_place_up
	step_end

# 52 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_3:
# 53 "data/maps/GallegoRoom/scripts.pory"
	emote_thinking
# 54 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 54 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 54 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 55 "data/maps/GallegoRoom/scripts.pory"
	face_left
# 56 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 56 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 57 "data/maps/GallegoRoom/scripts.pory"
	face_right
# 58 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 58 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 59 "data/maps/GallegoRoom/scripts.pory"
	face_up
# 60 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 60 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 61 "data/maps/GallegoRoom/scripts.pory"
	face_down
# 62 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 62 "data/maps/GallegoRoom/scripts.pory"
	delay_16
	step_end

# 73 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_4:
# 74 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 75 "data/maps/GallegoRoom/scripts.pory"
	emote_double_exclamation_mark
# 76 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 77 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 77 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 78 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 79 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 102 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_5:
# 103 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 104 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 104 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 104 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 105 "data/maps/GallegoRoom/scripts.pory"
	walk_right
	step_end

# 109 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_6:
# 109 "data/maps/GallegoRoom/scripts.pory"
	walk_down
# 109 "data/maps/GallegoRoom/scripts.pory"
	face_right
	step_end

# 118 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_7:
# 119 "data/maps/GallegoRoom/scripts.pory"
	walk_left
# 120 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 120 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 120 "data/maps/GallegoRoom/scripts.pory"
	walk_up
# 121 "data/maps/GallegoRoom/scripts.pory"
	walk_right
# 122 "data/maps/GallegoRoom/scripts.pory"
	face_down
	step_end

# 127 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_8:
# 128 "data/maps/GallegoRoom/scripts.pory"
	emote_versus
# 129 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 130 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 131 "data/maps/GallegoRoom/scripts.pory"
	delay_16
# 132 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 133 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

# 146 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_9:
# 147 "data/maps/GallegoRoom/scripts.pory"
	lock_facing_direction
# 148 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 149 "data/maps/GallegoRoom/scripts.pory"
	jump_in_place_up
# 150 "data/maps/GallegoRoom/scripts.pory"
	unlock_facing_direction
# 151 "data/maps/GallegoRoom/scripts.pory"
	face_player
	step_end

GallegoRoom_EventScript_Gallego_Text_0:
# 24 "data/maps/GallegoRoom/scripts.pory"
	.string "La chispa que ha vuelto a encender mi\n"
	.string "sueño ha prendido una llama que crece\l"
	.string "por momentos.$"

GallegoRoom_EventScript_Gallego_Text_1:
# 27 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Continúa en busca del tuyo, y\n"
	.string "volveremos a encontrarnos en el camino!$"

GallegoRoom_EventScript_Gallego_Text_2:
# 50 "data/maps/GallegoRoom/scripts.pory"
	.string "Ay, no, creo que me ha visto… No puedo\n"
	.string "dejar que me encuentren todavía…\p"
	.string "¿Y si me quedo muy quieto? ¿Seré capaz\n"
	.string "de escabullirme?$"

GallegoRoom_EventScript_Gallego_Text_3:
# 64 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, tendré que aceptarlo, supongo\n"
	.string "que no podía ocultarme para siempre.$"

GallegoRoom_EventScript_Gallego_Text_4:
# 70 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Hola! Soy Gallego13, y llevo años\n"
	.string "observando desde las sombras.\p"
	.string "Casi podría decir que en vez de irme, me\n"
	.string "escondí.\p"
	.string "De vez en cuando echaba un ojo por\n"
	.string "nuestra querida comunidad, sin decir\l"
	.string "nada, viendo los avances y cómo\l"
	.string "evolucionaba…\p"
	.string "Nunca quise que fuese tan largo, pero\n"
	.string "los estudios y después la vida me\l"
	.string "hicieron perder la noción del tiempo.\p"
	.string "Antes de que me diera cuenta, me\n"
	.string "acostumbré a ver este mundo desde la\l"
	.string "distancia.$"

GallegoRoom_EventScript_Gallego_Text_5:
# 81 "data/maps/GallegoRoom/scripts.pory"
	.string "Y mira tú, veinte años ya… ¡veinte!$"

GallegoRoom_EventScript_Gallego_Text_6:
# 84 "data/maps/GallegoRoom/scripts.pory"
	.string "El aniversario me ha pillado totalmente\n"
	.string "por sorpresa. ¡Si hasta hace diez años\l"
	.string "desde que me dejé ver por última vez!\p"
	.string "Y aún con esas, ese pedazo de mi vida lo\n"
	.string "recuerdo como si hubiese sido ayer.$"

GallegoRoom_EventScript_Gallego_Text_7:
# 87 "data/maps/GallegoRoom/scripts.pory"
	.string "Siempre tuve el sueño de crear un juego\n"
	.string "que capturara el alma de la segunda\l"
	.string "generación, con aquella estética y ese\l"
	.string "'no sé qué' del que siempre he estado\l"
	.string "enamorado.\p"
	.string "Me pasé años picando piedra entre\n"
	.string "bytes en hexadecimal y rutinas de ASM,\l"
	.string "insertando gráficos y música a las\l"
	.string "bravas en la ROM…$"

GallegoRoom_EventScript_Gallego_Text_8:
# 92 "data/maps/GallegoRoom/scripts.pory"
	.string "Pero me iba a volver loco con todo\n"
	.string "aquello… demasiado difícil, los bugs\l"
	.string "aparecían como setas a cada cambio.$"

GallegoRoom_EventScript_Gallego_Text_9:
# 94 "data/maps/GallegoRoom/scripts.pory"
	.string "Y justo cuando lo dejé, cuando me rendí,\n"
	.string "aparecieron las herramientas modernas.\p"
	.string "El disassembly, los motores… todo lo que\n"
	.string "habría necesitado entonces, apareció,\l"
	.string "casi como si fuese una burla a mi\l"
	.string "esfuerzo.$"

GallegoRoom_EventScript_Gallego_Text_10:
# 108 "data/maps/GallegoRoom/scripts.pory"
	.string "Como ves, aún conservo mis viejas Game\n"
	.string "Boy Color.$"

GallegoRoom_EventScript_Gallego_Text_11:
# 114 "data/maps/GallegoRoom/scripts.pory"
	.string "Algunas ni siquiera encienden, pero\n"
	.string "siguen ahí.\p"
	.string "A pesar de todo, después de tanto\n"
	.string "tiempo, mi sueño todavía vive…\p"
	.string "El sueño no tiene fin: la maquinaria en\n"
	.string "mi cabeza todavía no se ha detenido…$"

GallegoRoom_EventScript_Gallego_Text_12:
# 117 "data/maps/GallegoRoom/scripts.pory"
	.string "En fin, suficiente reflexión por ahora.$"

GallegoRoom_EventScript_Gallego_Text_13:
# 125 "data/maps/GallegoRoom/scripts.pory"
	.string "Vamos a ver si no se me ha olvidado\n"
	.string "combatir en este tiempo.$"

GallegoRoom_EventScript_Gallego_Text_14:
# 135 "data/maps/GallegoRoom/scripts.pory"
	.string "¡Enséñame cuánto ha evolucionado la\n"
	.string "nueva generación!$"

GallegoRoom_EventScript_Gallego_Text_15:
# 136 "data/maps/GallegoRoom/scripts.pory"
	.string "Uff.. pues sí que me he quedado\n"
	.string "anticuado.$"

GallegoRoom_EventScript_Gallego_Text_16:
# 137 "data/maps/GallegoRoom/scripts.pory"
	.string "Parece que las nuevas generaciones de\n"
	.string "entrenadores son mucho más duras de\l"
	.string "roer.\p"
	.string "Pero verte combatir me devuelve la\n"
	.string "chispa de antaño.$"

GallegoRoom_EventScript_Gallego_Text_17:
# 141 "data/maps/GallegoRoom/scripts.pory"
	.string "Es curioso… abandoné justo antes de\n"
	.string "que todo se volviera más fácil, y aun\l"
	.string "así, sigo pensando en volver.\p"
	.string "No puedo negar que soy un cabezota sin\n"
	.string "remedio…$"

GallegoRoom_EventScript_Gallego_Text_18:
# 145 "data/maps/GallegoRoom/scripts.pory"
	.string "Supongo que algunos sueños no se\n"
	.string "apagan.$"

GallegoRoom_EventScript_Gallego_Text_19:
# 153 "data/maps/GallegoRoom/scripts.pory"
	.string "Ve, continúa, ¡busca tu sueño y\n"
	.string "abrázalo con fuerza!$"

GallegoRoom_EventScript_Gallego_Text_20:
# 156 "data/maps/GallegoRoom/scripts.pory"
	.string "Yo me quedaré aquí un rato más…\n"
	.string "recordando mis viejos intentos y\l"
	.string "soñando con un nuevo y emocionante\l"
	.string "comienzo.$"
