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
	msgbox ReonekyRoom_OnFrame_Text_4
# 49 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 50 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_VersusWithDelay48
# 51 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 52 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_2
# 59 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_3
# 66 "data/maps/ReonekyRoom/scripts.pory"
	release
# 67 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 68 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 69 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE
# 70 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 71 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 72 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 73 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_FIRE
# 74 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 75 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 76 "data/maps/ReonekyRoom/scripts.pory"
	setobjectsubpriority LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM, 0
# 77 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceRight2
# 78 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 79 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_FIREATTACK, Common_Movement_WalkRight3
# 80 "data/maps/ReonekyRoom/scripts.pory"
	release
# 81 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 82 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 83 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 84 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 85 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 86 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 87 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 88 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 89 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 90 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 91 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 92 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 93 "data/maps/ReonekyRoom/scripts.pory"
	release
# 94 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 95 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 96 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_4
# 116 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 117 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 118 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_JumpInPlaceRight2
# 119 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE
# 120 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 121 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 122 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_WalkInPlaceLeft
# 123 "data/maps/ReonekyRoom/scripts.pory"
	release
# 124 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE
# 125 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 126 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_HappyWithDelay48
# 127 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_OnFrame_Movement_5
# 128 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_REONEKY
# 129 "data/maps/ReonekyRoom/scripts.pory"
	release
# 130 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8
# 131 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_9
# 132 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_10
# 133 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 134 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 135 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 136 "data/maps/ReonekyRoom/scripts.pory"
	release
# 137 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE
# 138 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpInPlaceLeft2
# 139 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 140 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_TYPHLOSION
# 141 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 142 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 143 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_REONEKY_ROOM_STATE, 1
# 144 "data/maps/ReonekyRoom/scripts.pory"
	moveobjecttopos LOCALID_REOROOM_REONEKY, 6, 4, DIR_SOUTH
# 145 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 146 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 147 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 148 "data/maps/ReonekyRoom/scripts.pory"
	setobjectxyperm LOCALID_REOROOM_REONEKY, 6, 4
# 149 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_REONEKY, MOVEMENT_TYPE_FACE_DOWN
# 150 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 151 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 156 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 169 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 170 "data/maps/ReonekyRoom/scripts.pory"
	release
# 171 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 172 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2, MSGBOX_AUTOCLOSE
# 173 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_3
# 174 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_5
# 175 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 176 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 177 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_6
# 178 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_7
# 179 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_8
# 180 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_9
# 181 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 182 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, ReonekyRoom_EventScript_Reoneky_Movement_0
# 188 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_EventScript_Reoneky_Text_10
# 189 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_11, MSGBOX_AUTOCLOSE
# 190 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 191 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SweatDropWithDelay48
# 192 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 193 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_12, MSGBOX_AUTOCLOSE
# 194 "data/maps/ReonekyRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 195 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 196 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 197 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 157 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 158 "data/maps/ReonekyRoom/scripts.pory"
	release
# 159 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 160 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 161 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, Common_Movement_QuestionMarkWithDelay48
# 162 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_AUTOCLOSE
# 163 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 164 "data/maps/ReonekyRoom/scripts.pory"
	delay 40
# 165 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1, MSGBOX_AUTOCLOSE
# 166 "data/maps/ReonekyRoom/scripts.pory"
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

# 52 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 53 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 54 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 55 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 56 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 57 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 59 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 60 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 61 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 62 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 63 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 64 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 65 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 96 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_4:
# 97 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 98 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 99 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 99 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 100 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 100 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 101 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 102 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 103 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 104 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 105 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 106 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 107 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 108 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 109 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 110 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 111 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 112 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 113 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 114 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

# 127 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_5:
# 127 "data/maps/ReonekyRoom/scripts.pory"
	emote_happy
# 127 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 127 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
# 127 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_fast_left
	step_end

# 182 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_EventScript_Reoneky_Movement_0:
# 183 "data/maps/ReonekyRoom/scripts.pory"
	emote_versus
# 184 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 185 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 185 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_down
# 186 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
# 187 "data/maps/ReonekyRoom/scripts.pory"
	face_player
	step_end

ReonekyRoom_OnFrame_Text_0:
# 29 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, mantén la distancia!$"

ReonekyRoom_OnFrame_Text_1:
# 34 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseida encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 44 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Te ríes, eh? Aficionado...$"

ReonekyRoom_OnFrame_Text_3:
# 47 "data/maps/ReonekyRoom/scripts.pory"
	.string "Estaba estacionado perfectamente, ¡no\n"
	.string "voy a rendirme ante esta multa injusta!$"

ReonekyRoom_OnFrame_Text_4:
# 48 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Spitfire, cabezazo Zen!$"

ReonekyRoom_OnFrame_Text_5:
# 69 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien, es la nuestra! ¡Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 119 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Venga, a pastar!$"

ReonekyRoom_OnFrame_Text_7:
# 124 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Tú molas, tú mandas colega! ¡Nos\n"
	.string "libramos del fantasma de la multa!$"

ReonekyRoom_OnFrame_Text_8:
# 130 "data/maps/ReonekyRoom/scripts.pory"
	.string "Menos mal que J15 decía que lo tenía\n"
	.string "controlado, vaya tela...$"

ReonekyRoom_OnFrame_Text_9:
# 131 "data/maps/ReonekyRoom/scripts.pory"
	.string "Si es que le tenía que haber hecho caso\n"
	.string "a Keltill...$"

ReonekyRoom_OnFrame_Text_10:
# 132 "data/maps/ReonekyRoom/scripts.pory"
	.string "Va con el Miata tuneao y nunca lo\n"
	.string "multan, solo lo paran para echarse\l"
	.string "fotos...$"

ReonekyRoom_OnFrame_Text_11:
# 137 "data/maps/ReonekyRoom/scripts.pory"
	.string "En fin... Lo has hecho genial colega,\n"
	.string "¡hora de descansar!$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 162 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Otra vez por aquí?$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 165 "data/maps/ReonekyRoom/scripts.pory"
	.string "Relájate, ya me ganaste… Sigue\n"
	.string "adelante que todavía tienes más\l"
	.string "enfrentamientos por delante.\p"
	.string "Yo me quedaré contemplando cómo arde\n"
	.string "la grúa, a veces los problemas se\l"
	.string "consumen solos.$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 172 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Buenas! Vaya espectáculo has\n"
	.string "presenciado, ¿eh?$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 173 "data/maps/ReonekyRoom/scripts.pory"
	.string "A estas alturas ya sabrás que hago\n"
	.string "aquí, así que me presento.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 174 "data/maps/ReonekyRoom/scripts.pory"
        .string "$"

ReonekyRoom_EventScript_Reoneky_Text_5:
# 174 "data/maps/ReonekyRoom/scripts.pory"
        .string "Soy Reoneky, experto en llevar el prefijo \"ex\" tanto ámbito laboral como profesional.$"

ReonekyRoom_EventScript_Reoneky_Text_6:
# 177 "data/maps/ReonekyRoom/scripts.pory"
	.string "Puede parecer que soy un emo, pero me\n"
	.string "considero más instrospectivo que otra\l"
	.string "cosa.$"

ReonekyRoom_EventScript_Reoneky_Text_7:
# 178 "data/maps/ReonekyRoom/scripts.pory"
	.string "Yo no era nadie... Sentía que no era\n"
	.string "nadie... Y eso lo cambió el WAH.$"

ReonekyRoom_EventScript_Reoneky_Text_8:
# 179 "data/maps/ReonekyRoom/scripts.pory"
	.string "Así que fuera sentimentalismos y\n"
	.string "presentaciones, vamos al lío.$"

ReonekyRoom_EventScript_Reoneky_Text_9:
# 180 "data/maps/ReonekyRoom/scripts.pory"
	.string "Mente fría, corazón caliente, así es\n"
	.string "como se juega. ¡A darle caña!$"

ReonekyRoom_EventScript_Reoneky_Text_10:
# 188 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen combate, he disfrutado como un\n"
	.string "niño.$"

ReonekyRoom_EventScript_Reoneky_Text_11:
# 189 "data/maps/ReonekyRoom/scripts.pory"
	.string "Apuntas maneras, el talento tiene\n"
	.string "límites, el esfuerzo y la pasión, no.$"

ReonekyRoom_EventScript_Reoneky_Text_12:
# 193 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Un golpe de suerte ocurre cuando\n"
	.string "aprovechas una buena oportunidad! No\l"
	.string "dejes que te detengan y sobre todo,\l"
	.string "disfruta del momento.$"
