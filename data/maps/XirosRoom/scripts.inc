XirosRoom_MapScripts::
# 5 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, XirosRoom_OnLoad
# 6 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, XirosRoom_OnTransition
# 7 "data/maps/XirosRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, XirosRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

XirosRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 8 "data/maps/XirosRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, XirosRoom_OnWarp_PlayerTurnNorth
	.2byte 0


XirosRoom_OnLoad::
# 13 "data/maps/XirosRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_XIROS, XirosRoom_OnLoad_2
XirosRoom_OnLoad_1:
	end

XirosRoom_OnLoad_2:
# 14 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto XirosRoom_OnLoad_1


XirosRoom_OnWarp_PlayerTurnNorth::
# 20 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


XirosRoom_OnTransition::
# 25 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Xiros
# 26 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 27 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_2
	end


XirosRoom_EventScript_Xiros::
# 32 "data/maps/XirosRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_XIROS, XirosRoom_EventScript_Xiros_2
# 57 "data/maps/XirosRoom/scripts.pory"
	lock
# 58 "data/maps/XirosRoom/scripts.pory"
	faceplayer
# 59 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 60 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 61 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 62 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 63 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 64 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_SweatDropWithDelay48
# 65 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 66 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_SOUTH
# 67 "data/maps/XirosRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 6
# 68 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 69 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 70 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 71 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 72 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceDown
# 73 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 74 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 75 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 76 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HeartWithDelay48
# 77 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 78 "data/maps/XirosRoom/scripts.pory"
	special SpawnCameraObject
# 79 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_XIROSROOM_XIROS, Common_Movement_WalkUp2
# 80 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
# 81 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 82 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 83 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 84 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 85 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceDown
# 86 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 87 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_XIROSROOM_XIROS, Common_Movement_WalkDown2
# 88 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
# 89 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 90 "data/maps/XirosRoom/scripts.pory"
	special RemoveCameraObject
# 91 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 92 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 93 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 94 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_3
# 99 "data/maps/XirosRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 100 "data/maps/XirosRoom/scripts.pory"
	addobject LOCALID_XIROSROOM_POKEBALL
# 101 "data/maps/XirosRoom/scripts.pory"
	showobjectat LOCALID_XIROSROOM_POKEBALL, MAP_XIROS_ROOM
# 102 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_POKEBALL, Common_Movement_WalkDiagSouthEast
# 103 "data/maps/XirosRoom/scripts.pory"
	playse SE_BALL_OPEN
# 104 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 105 "data/maps/XirosRoom/scripts.pory"
	removeobject LOCALID_XIROSROOM_POKEBALL
# 106 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 107 "data/maps/XirosRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 108 "data/maps/XirosRoom/scripts.pory"
	addobject LOCALID_XIROSROOM_ELECTRODE
# 109 "data/maps/XirosRoom/scripts.pory"
	waitse
# 110 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 111 "data/maps/XirosRoom/scripts.pory"
	release
# 112 "data/maps/XirosRoom/scripts.pory"
	delay 30
# 113 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 114 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_ELECTRODE, XirosRoom_EventScript_Xiros_Movement_4
# 115 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 116 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_ELECTRODE, XirosRoom_EventScript_Xiros_Movement_4
# 117 "data/maps/XirosRoom/scripts.pory"
	waitse
# 118 "data/maps/XirosRoom/scripts.pory"
	playmoncry SPECIES_ELECTRODE, CRY_MODE_NORMAL
# 119 "data/maps/XirosRoom/scripts.pory"
	waitmoncry
# 120 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_ELECTRODE, XirosRoom_EventScript_Xiros_Movement_5
# 121 "data/maps/XirosRoom/scripts.pory"
	release
# 122 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_WEST
# 123 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 124 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 125 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 126 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_SOUTH
# 127 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_ELECTRODE, DIR_SOUTH
# 128 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_12, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 129 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 130 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_JumpInPlaceDown
# 131 "data/maps/XirosRoom/scripts.pory"
	waitse
# 132 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 133 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_JumpInPlaceDown
# 134 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_13, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 135 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceLeft
# 136 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_ELECTRODE, DIR_EAST
# 137 "data/maps/XirosRoom/scripts.pory"
	playse SE_BALL_OPEN
# 138 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 139 "data/maps/XirosRoom/scripts.pory"
	removeobject LOCALID_XIROSROOM_ELECTRODE
# 140 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 141 "data/maps/XirosRoom/scripts.pory"
	delay 30
# 142 "data/maps/XirosRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 143 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 144 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkDown
# 145 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 146 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 147 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_6
# 148 "data/maps/XirosRoom/scripts.pory"
	call XirosRoom_EventScript_XirosBattle
# 149 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 150 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_7
# 151 "data/maps/XirosRoom/scripts.pory"
	waitse
# 152 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 153 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_4
# 154 "data/maps/XirosRoom/scripts.pory"
	waitse
# 155 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 156 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_4
# 157 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 158 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 159 "data/maps/XirosRoom/scripts.pory"
	delay 20
# 160 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_WalkInPlaceDown
# 161 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 162 "data/maps/XirosRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 163 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 164 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 165 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 166 "data/maps/XirosRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_XIROS
# 167 "data/maps/XirosRoom/scripts.pory"
	release
	end

XirosRoom_EventScript_Xiros_2:
# 33 "data/maps/XirosRoom/scripts.pory"
	lock
# 34 "data/maps/XirosRoom/scripts.pory"
	faceplayer
# 35 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 36 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 37 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 38 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 39 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 40 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_0
# 41 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 42 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_ThinkingWithDelay48
# 44 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 45 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_1
# 46 "data/maps/XirosRoom/scripts.pory"
	waitse
# 47 "data/maps/XirosRoom/scripts.pory"
	playse SE_LEDGE
# 48 "data/maps/XirosRoom/scripts.pory"
	applymovement LOCALID_XIROSROOM_XIROS, XirosRoom_EventScript_Xiros_Movement_2
# 49 "data/maps/XirosRoom/scripts.pory"
	msgbox XirosRoom_EventScript_Xiros_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_XIROS
# 50 "data/maps/XirosRoom/scripts.pory"
	waitmovement 0
# 51 "data/maps/XirosRoom/scripts.pory"
	playse SE_PIN
# 52 "data/maps/XirosRoom/scripts.pory"
	applymovementandwait LOCALID_XIROSROOM_XIROS, Common_Movement_HappyWithDelay48
# 53 "data/maps/XirosRoom/scripts.pory"
	turnobject LOCALID_XIROSROOM_XIROS, DIR_SOUTH
# 54 "data/maps/XirosRoom/scripts.pory"
	release
	end


XirosRoom_EventScript_XirosBattle::
# 172 "data/maps/XirosRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, XirosRoom_EventScript_XirosBattle_2
# 175 "data/maps/XirosRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_XIROS
# 176 "data/maps/XirosRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 177 "data/maps/XirosRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq XirosRoom_EventScript_XirosBattle_5
# 180 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_ALTERNATIVE, XirosRoom_Text_XirosDefeated
XirosRoom_EventScript_XirosBattle_1:
# 183 "data/maps/XirosRoom/scripts.pory"
	special HealPlayerParty
	return

XirosRoom_EventScript_XirosBattle_2:
# 173 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_MAIN, XirosRoom_Text_XirosDefeated
	goto XirosRoom_EventScript_XirosBattle_1

XirosRoom_EventScript_XirosBattle_5:
# 178 "data/maps/XirosRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_XIROS_MAIN, XirosRoom_Text_XirosDefeated
	goto XirosRoom_EventScript_XirosBattle_1


# 40 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_0:
# 40 "data/maps/XirosRoom/scripts.pory"
	lock_facing_direction
# 40 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
# 40 "data/maps/XirosRoom/scripts.pory"
	unlock_facing_direction
# 40 "data/maps/XirosRoom/scripts.pory"
	face_player
	step_end

# 45 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_1:
# 45 "data/maps/XirosRoom/scripts.pory"
	delay_16
# 45 "data/maps/XirosRoom/scripts.pory"
	delay_16
# 45 "data/maps/XirosRoom/scripts.pory"
	lock_facing_direction
# 45 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
	step_end

# 48 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_2:
# 48 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
# 48 "data/maps/XirosRoom/scripts.pory"
	unlock_facing_direction
# 48 "data/maps/XirosRoom/scripts.pory"
	face_player
	step_end

# 94 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_3:
# 95 "data/maps/XirosRoom/scripts.pory"
	lock_facing_direction
# 96 "data/maps/XirosRoom/scripts.pory"
	walk_up
# 97 "data/maps/XirosRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 114 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_4:
# 114 "data/maps/XirosRoom/scripts.pory"
	jump_in_place_down
	step_end

# 120 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_5:
# 120 "data/maps/XirosRoom/scripts.pory"
	walk_left
# 120 "data/maps/XirosRoom/scripts.pory"
	walk_up
# 120 "data/maps/XirosRoom/scripts.pory"
	walk_in_place_right
	step_end

# 147 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_6:
# 147 "data/maps/XirosRoom/scripts.pory"
	emote_versus
# 147 "data/maps/XirosRoom/scripts.pory"
	delay_16
# 147 "data/maps/XirosRoom/scripts.pory"
	walk_in_place_down
# 147 "data/maps/XirosRoom/scripts.pory"
	delay_16
	step_end

# 150 "data/maps/XirosRoom/scripts.pory"
XirosRoom_EventScript_Xiros_Movement_7:
# 150 "data/maps/XirosRoom/scripts.pory"
	emote_happy
	step_end

XirosRoom_EventScript_Xiros_Text_0:
# 35 "data/maps/XirosRoom/scripts.pory"
	.string "¿Aún sigues aquí? Ya que estás,\n"
	.string "aprovecho para decirte una cosa más.$"

XirosRoom_EventScript_Xiros_Text_1:
# 38 "data/maps/XirosRoom/scripts.pory"
	.string "No te obsesiones demasiado con\n"
	.string "compararte todo el tiempo, porque a\l"
	.string "veces vas a sentir que estás adelante,\l"
	.string "y otras veces que te quedaste atrás.$"

XirosRoom_EventScript_Xiros_Text_2:
# 41 "data/maps/XirosRoom/scripts.pory"
	.string "Al final, el camino es largo, y la\n"
	.string "verdadera carrera es siempre con uno\l"
	.string "mismo.$"

XirosRoom_EventScript_Xiros_Text_3:
# 49 "data/maps/XirosRoom/scripts.pory"
	.string "Ahora sigue, a tu ritmo, pero siempre\n"
	.string "avanzando.$"

XirosRoom_EventScript_Xiros_Text_4:
# 59 "data/maps/XirosRoom/scripts.pory"
	.string "Así que llegaste hasta acá, ¡a la sala\n"
	.string "número veinte!\p"
	.string "Un lugar al que no se llega por\n"
	.string "casualidad.$"

XirosRoom_EventScript_Xiros_Text_5:
# 62 "data/maps/XirosRoom/scripts.pory"
	.string "Voy a tratar de ser más breve que Zero\n"
	.string "en mi discurso, pero a mi también me\l"
	.string "gusta reflexionar, así que no prometo\l"
	.string "nada…$"

XirosRoom_EventScript_Xiros_Text_6:
# 71 "data/maps/XirosRoom/scripts.pory"
	.string "En el camino te cruzaste con muchas\n"
	.string "personas, algunas conocidas, otras que\l"
	.string "quizá solo habías escuchado nombrar\l"
	.string "alguna vez, pero todas dejaron algo en\l"
	.string "este recorrido.$"

XirosRoom_EventScript_Xiros_Text_7:
# 74 "data/maps/XirosRoom/scripts.pory"
	.string "Cada encuentro, cada charla y cada\n"
	.string "combate forma parte de una historia\l"
	.string "más grande, aunque a veces no lo\l"
	.string "notemos en el momento.$"

XirosRoom_EventScript_Xiros_Text_8:
# 84 "data/maps/XirosRoom/scripts.pory"
	.string "Es normal que en algún punto las cosas\n"
	.string "parezcan difíciles o incluso imposibles,\l"
	.string "porque nadie nace sabiendo, ni empieza\l"
	.string "un gran desafío o proyecto teniendo\l"
	.string "todas las respuestas.$"

XirosRoom_EventScript_Xiros_Text_9:
# 86 "data/maps/XirosRoom/scripts.pory"
	.string "Lo importante no es saberlo todo, sino\n"
	.string "animarse a buscar, porque cuando uno\l"
	.string "busca de verdad, siempre aparece\l"
	.string "alguien dispuesto a ayudar.$"

XirosRoom_EventScript_Xiros_Text_10:
# 91 "data/maps/XirosRoom/scripts.pory"
	.string "Es lo lindo de esta comunidad, ¿no\n"
	.string "crees?$"

XirosRoom_EventScript_Xiros_Text_11:
# 123 "data/maps/XirosRoom/scripts.pory"
	.string "Este es Electrode Sandía, un símbolo de\n"
	.string "una época que muchos recuerdan con\l"
	.string "cariño y nostalgia, cuando todo parecía\l"
	.string "más simple.$"

XirosRoom_EventScript_Xiros_Text_12:
# 128 "data/maps/XirosRoom/scripts.pory"
	.string "Personalmente nunca creí que la época\n"
	.string "dorada fuera un momento que quedó\l"
	.string "atrás en el tiempo.$"

XirosRoom_EventScript_Xiros_Text_13:
# 134 "data/maps/XirosRoom/scripts.pory"
	.string "Para mí, la época dorada es hoy, y\n"
	.string "también será mañana, mientras sigan\l"
	.string "existiendo personas con ganas de\l"
	.string "motivar, ayudar y empujar las cosas un\l"
	.string "poco más adelante.$"

XirosRoom_EventScript_Xiros_Text_14:
# 145 "data/maps/XirosRoom/scripts.pory"
	.string "Hagamos que este momento también\n"
	.string "cuente.$"

XirosRoom_EventScript_Xiros_Text_15:
# 157 "data/maps/XirosRoom/scripts.pory"
	.string "¡Wow! ¡Que gran combate! Me encanta tu\n"
	.string "forma de combatir.\p"
	.string "¡Sobretodo la pasión que le pones a\n"
	.string "cada movimiento!$"

XirosRoom_EventScript_Xiros_Text_16:
# 161 "data/maps/XirosRoom/scripts.pory"
	.string "Todavía te queda un último\n"
	.string "enfrentamiento, y si conocés un poco la\l"
	.string "historia de este lugar, seguramente ya\l"
	.string "te estés imaginando quién te espera.\p"
	.string "Aprovecha la oportunidad, que no todos\n"
	.string "tienen la suerte de encontrarlo.$"

XirosRoom_Text_XirosDefeated::
# 187 "data/maps/XirosRoom/scripts.pory"
	.string "¡Muy buen combate!$"
