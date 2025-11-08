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
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 10 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
	end


ReonekyRoom_OnFrame::
# 15 "data/maps/ReonekyRoom/scripts.pory"
	release
# 16 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp2
# 17 "data/maps/ReonekyRoom/scripts.pory"
	special SpawnCameraObject
# 18 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 5, 7
# 19 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 20 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkInPlaceRight
# 21 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE
# 22 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 23 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_DoubleExclamationMark
# 24 "data/maps/ReonekyRoom/scripts.pory"
	release
# 25 "data/maps/ReonekyRoom/scripts.pory"
	delay 80
# 26 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_1
# 27 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 29 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_0
# 34 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 35 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_REONEKY, ReonekyRoom_OnFrame_Movement_1
# 36 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE
# 37 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 38 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 39 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_3
# 40 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_4
# 41 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 42 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_VersusWithDelay48
# 43 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_THUNDERBOLT2
# 44 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_Movement_TyphlosionThunderPunch
# 45 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, ReonekyRoom_OnFrame_Movement_2
# 52 "data/maps/ReonekyRoom/scripts.pory"
	release
# 53 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 54 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_WalkLeftLockFacingDirection
# 55 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_5
# 56 "data/maps/ReonekyRoom/scripts.pory"
	delay 20
# 57 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_TYPHLOSION, Common_Movement_JumpLeftLockFacingDirection
# 58 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FLAME_WHEEL
# 59 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_FIRE
# 60 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_FIREATTACK
# 61 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_FIREATTACK, MAP_REONEKY_ROOM
# 62 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_TYPHLOSION, ReonekyRoom_Movement_TyphlosionFireWheel
# 63 "data/maps/ReonekyRoom/scripts.pory"
	applymovement LOCALID_REOROOM_FIREATTACK, ReonekyRoom_Movement_FireWheel
# 64 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement LOCALID_REOROOM_FIREATTACK
# 65 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_M_FIRE_PUNCH
# 66 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_CRANE, Common_Movement_CraneStartBurning
# 67 "data/maps/ReonekyRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_REOROOM_CRANE, MOVEMENT_TYPE_CRANE_BURNING_UP
# 68 "data/maps/ReonekyRoom/scripts.pory"
	playmoncry SPECIES_HAUNTER, CRY_MODE_ENCOUNTER
# 69 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 70 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_CRANE, DIR_SOUTH
# 71 "data/maps/ReonekyRoom/scripts.pory"
	clearflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 72 "data/maps/ReonekyRoom/scripts.pory"
	addobject LOCALID_REOROOM_HAUNTER
# 73 "data/maps/ReonekyRoom/scripts.pory"
	showobjectat LOCALID_REOROOM_HAUNTER, MAP_REONEKY_ROOM
# 74 "data/maps/ReonekyRoom/scripts.pory"
	delay 30
# 75 "data/maps/ReonekyRoom/scripts.pory"
	release
# 76 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 77 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 78 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_HAUNTER, ReonekyRoom_OnFrame_Movement_3
# 98 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_HAUNTER
# 99 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_HAUNTER
# 100 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_6
# 101 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 102 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 103 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_7
# 104 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE
# 105 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 106 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 107 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_TYPHLOSION
# 108 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_TYPHLOSION
# 109 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_REONEKYROOM_HIDE_FIRE
# 110 "data/maps/ReonekyRoom/scripts.pory"
	removeobject LOCALID_REOROOM_FIREATTACK
# 111 "data/maps/ReonekyRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 112 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_REONEKY_ROOM_STATE, 1
# 113 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_REOROOM_REONEKY, DIR_SOUTH
# 114 "data/maps/ReonekyRoom/scripts.pory"
	directcameramovementtopos 6, 11
# 115 "data/maps/ReonekyRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/ReonekyRoom/scripts.pory"
	special RemoveCameraObject
# 117 "data/maps/ReonekyRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 118 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


ReonekyRoom_EventScript_Reoneky::
# 123 "data/maps/ReonekyRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_REONEKY, ReonekyRoom_EventScript_Reoneky_2
# 130 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 131 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 132 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_1
# 133 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 134 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_ThinkingWithDelay48
# 135 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_2
# 136 "data/maps/ReonekyRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_REONEKY_MAIN, ReonekyRoom_EventScript_Reoneky_Text_3
# 137 "data/maps/ReonekyRoom/scripts.pory"
	playse SE_PIN
# 138 "data/maps/ReonekyRoom/scripts.pory"
	applymovementandwait LOCALID_REOROOM_REONEKY, Common_Movement_SmileWithDelay48
# 139 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_4, MSGBOX_AUTOCLOSE
# 140 "data/maps/ReonekyRoom/scripts.pory"
	call PokemonLeague_EliteFour_OpenRoomDoorMetatiles
# 141 "data/maps/ReonekyRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_REONEKY
# 142 "data/maps/ReonekyRoom/scripts.pory"
	setvar VAR_REONEKY_ROOM_STATE, 2
# 143 "data/maps/ReonekyRoom/scripts.pory"
	release
	end

ReonekyRoom_EventScript_Reoneky_2:
# 124 "data/maps/ReonekyRoom/scripts.pory"
	lock
# 125 "data/maps/ReonekyRoom/scripts.pory"
	faceplayer
# 126 "data/maps/ReonekyRoom/scripts.pory"
	msgbox ReonekyRoom_EventScript_Reoneky_Text_0, MSGBOX_NPC
# 127 "data/maps/ReonekyRoom/scripts.pory"
	release
	end


# 148 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_Movement_TyphlosionThunderPunch:
# 149 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 150 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 151 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 152 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 153 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 157 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_Movement_TyphlosionFireWheel:
# 158 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
# 159 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 160 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 161 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 162 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 163 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 164 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 167 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_Movement_FireWheel:
# 168 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 169 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 170 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_up
# 171 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 172 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 173 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 174 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 175 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 29 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_0:
# 30 "data/maps/ReonekyRoom/scripts.pory"
	emote_xd
# 31 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 31 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
# 32 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 33 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_left
	step_end

# 35 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_1:
# 35 "data/maps/ReonekyRoom/scripts.pory"
	emote_angry
# 35 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 35 "data/maps/ReonekyRoom/scripts.pory"
	jump_in_place_right
# 35 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 35 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 35 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
	step_end

# 45 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_2:
# 46 "data/maps/ReonekyRoom/scripts.pory"
	emote_x
# 47 "data/maps/ReonekyRoom/scripts.pory"
	lock_facing_direction
# 48 "data/maps/ReonekyRoom/scripts.pory"
	walk_in_place_left
# 49 "data/maps/ReonekyRoom/scripts.pory"
	walk_right
# 50 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 51 "data/maps/ReonekyRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 78 "data/maps/ReonekyRoom/scripts.pory"
ReonekyRoom_OnFrame_Movement_3:
# 79 "data/maps/ReonekyRoom/scripts.pory"
	emote_cry
# 80 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_right
# 81 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 81 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_down
# 82 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 82 "data/maps/ReonekyRoom/scripts.pory"
	walk_fast_left
# 83 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 84 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 85 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 86 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 87 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 88 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 89 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 90 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 91 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 92 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
# 93 "data/maps/ReonekyRoom/scripts.pory"
	delay_16
# 94 "data/maps/ReonekyRoom/scripts.pory"
	set_visible
# 95 "data/maps/ReonekyRoom/scripts.pory"
	delay_8
# 96 "data/maps/ReonekyRoom/scripts.pory"
	set_invisible
	step_end

ReonekyRoom_OnFrame_Text_0:
# 21 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Typhlosion, mantén la posición!$"

ReonekyRoom_OnFrame_Text_1:
# 26 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Esa grúa poseída encarna la injusticia\n"
	.string "administrativa!$"

ReonekyRoom_OnFrame_Text_2:
# 36 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡No te rías, espectro de la\n"
	.string "ineficiencia!$"

ReonekyRoom_OnFrame_Text_3:
# 39 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡No pienso rendirme ante esta multa\n"
	.string "injusta! ¡Fueron solo unos minutos!$"

ReonekyRoom_OnFrame_Text_4:
# 40 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Typhlosion, usa Puño Trueno!$"

ReonekyRoom_OnFrame_Text_5:
# 55 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Bien! ¡Ahora Rueda Fuego!$"

ReonekyRoom_OnFrame_Text_6:
# 100 "data/maps/ReonekyRoom/scripts.pory"
	.string "¡Sí! ¡Por fin nos libramos del fantasma\n"
	.string "de la multa!$"

ReonekyRoom_OnFrame_Text_7:
# 103 "data/maps/ReonekyRoom/scripts.pory"
	.string "Y Keltill decía que nada malo podía\n"
	.string "pasar con J15 al mando...$"

ReonekyRoom_OnFrame_Text_8:
# 104 "data/maps/ReonekyRoom/scripts.pory"
	.string "Buen trabajo, regresa a tu Poké Ball.$"

ReonekyRoom_EventScript_Reoneky_Text_0:
# 126 "data/maps/ReonekyRoom/scripts.pory"
	.string "La puerta está abierta. Procura no\n"
	.string "hacer ruido, aún huele a burocracia\l"
	.string "quemada.$"

ReonekyRoom_EventScript_Reoneky_Text_1:
# 132 "data/maps/ReonekyRoom/scripts.pory"
	.string "¿Vienes a tramitar reclamaciones o a\n"
	.string "desafiarme?\p"
	.string "En cualquier caso, tengo toda la\n"
	.string "documentación lista.$"

ReonekyRoom_EventScript_Reoneky_Text_2:
# 135 "data/maps/ReonekyRoom/scripts.pory"
	.string "No daré ni un paso atrás. Tras esa grúa\n"
	.string "estaba el abuso de poder… y ahora\l"
	.string "estás tú.$"

ReonekyRoom_EventScript_Reoneky_Text_3:
# 136 "data/maps/ReonekyRoom/scripts.pory"
	.string "Así se sella un expediente impecable.$"

ReonekyRoom_EventScript_Reoneky_Text_4:
# 139 "data/maps/ReonekyRoom/scripts.pory"
	.string "Firma aquí: acabas de ganarte el\n"
	.string "derecho a continuar.$"
