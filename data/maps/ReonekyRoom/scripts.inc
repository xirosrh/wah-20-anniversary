ReonekyRoom_MapScripts::
# 5 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ReonekyRoom_OnTransition
# 2 "data/maps/ReonekyRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ReonekyRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

ReonekyRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/ReonekyRoom/scripts.pory"
	map_script_2 VAR_REONEKY_ROOM_STATE, 0, ReonekyRoom_OnFrame
	.2byte 0


ReonekyRoom_OnTransition::
# 9 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_REONEKY_ROOM_STATE, 0
	goto_if_eq ReonekyRoom_OnTransition_2
ReonekyRoom_OnTransition_1:
# 13 "data/maps/ReonekyRoom/scripts.pory"
	compare VAR_REONEKY_ROOM_STATE, 1
	goto_if_eq ReonekyRoom_OnTransition_5
ReonekyRoom_OnTransition_4:
	end

ReonekyRoom_OnTransition_2:
# 10 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 11 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
	goto ReonekyRoom_OnTransition_1

ReonekyRoom_OnTransition_5:
# 14 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 15 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 16 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxy LOCALID_REOROOM_REONEKY, 6, 4
# 17 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
	goto ReonekyRoom_OnTransition_4


ReonekyRoom_OnFrame::
# 23 "data/maps/ReonekyRoom/scripts.pory"
	release
# 24 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 25 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 26 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 5, 7
# 27 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 28 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 29 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 30 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 31 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 32 "data/maps/ReonekyRoom/scripts.pory"
	release
# 33 "data/maps/ReonekyRoom/scripts.pory"
	delay 80
# 34 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1
# 35 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 36 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 37 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 42 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 43 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 44 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 45 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 46 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 47 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3
# 48 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 49 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 50 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 51 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_VersusWithDelay48
# 52 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 53 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_2
# 60 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_3
# 67 "data/maps/ReonekyRoom/scripts.pory"
	release
# 68 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 69 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 70 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE
# 71 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 72 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 73 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 74 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_FIRE
# 75 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 76 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 77 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 78 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight2
# 79 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 80 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 81 "data/maps/ReonekyRoom/scripts.pory"
	release
# 82 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 83 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 84 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 85 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 86 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 87 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 88 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 89 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 90 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 91 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 92 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 93 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 94 "data/maps/ReonekyRoom/scripts.pory"
	release
# 95 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 96 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 97 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_4
# 117 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 118 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 119 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight2
# 120 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE
# 121 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 122 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 123 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 124 "data/maps/ReonekyRoom/scripts.pory"
	release
# 125 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 126 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 127 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 128 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_5
# 129 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 130 "data/maps/ReonekyRoom/scripts.pory"
	release
# 131 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 132 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 133 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 134 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 135 "data/maps/ReonekyRoom/scripts.pory"
	release
# 136 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE
# 137 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft2
# 138 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 139 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_TYPHLOSION
# 140 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 141 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 142 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_REONEKY_ROOM_STATE, 1
# 143 "data/maps/ReonekyRoom/scripts.pory"
	moveobjecttopos LOCALID_REOROOM_REONEKY, 6, 4, DIR_SOUTH
# 144 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 145 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 146 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 147 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 148 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 149 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 150 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 155 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 165 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 166 "data/maps/ReonekyRoom/scripts.pory"
	release
# 167 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 168 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE
# 169 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 170 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 171 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 172 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE
# 173 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 174 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3, MSGBOX_AUTOCLOSE
# 175 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 176 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 177 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE
# 178 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 179 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 185 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5
# 186 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_EventScript_Reoneky_Text_6
# 187 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_7, MSGBOX_AUTOCLOSE
# 188 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 189 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 190 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 191 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE
# 192 "data/maps/ReonekyRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 193 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 194 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 195 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 156 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 157 "data/maps/ReonekyRoom/scripts.pory"
	release
# 158 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 159 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE
# 160 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 161 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 162 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


# 37 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 38 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 39 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 39 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 40 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 41 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 43 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 43 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
# 43 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 43 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 43 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 43 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 43 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 53 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 54 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 55 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 56 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 57 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 58 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 60 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 61 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 62 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 63 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 64 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 65 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 66 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 97 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 98 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 99 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 100 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 100 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 101 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 101 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 102 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 103 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 104 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 105 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 106 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 107 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 108 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 109 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 110 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 111 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 112 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 113 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 114 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 115 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 128 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 128 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 128 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 128 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 128 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 179 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 180 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
# 181 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 182 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 182 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 183 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 184 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

ReonekyRoom_OnFrame_Text_0:
# 29 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 34 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 44 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionado…$"

ReonekyRoom_OnFrame_Text_3:
# 47 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 49 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 70 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 120 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 125 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 131 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela…\p"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill… Va con el Miata tuneao y\l"
	.string "nunca lo multan, solo lo paran para\l"
	.string "echarse fotos…$"

ReonekyRoom_OnFrame_Text_9:
# 136 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin… Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 159 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad!\p"
	.string "No dejes que te detengan y sobre todo,\n"
	.string "disfruta del momento.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 168 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 172 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.\p"
	.string "Soy Reoneky, experto en llevar el\n"
	.string "prefijo 'ex' tanto ámbito laboral como\l"
	.string "profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 174 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 177 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie… Sentía que no era\n"
	.string "nadie… Y eso lo cambió el WAH.\p"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.\p"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega.$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 185 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 186 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"

ReonekyRoom_EventScript_Reoneky_Text_7:
# 187 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"
