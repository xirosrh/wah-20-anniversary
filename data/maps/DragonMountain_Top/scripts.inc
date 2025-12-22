DragonMountain_Top_MapScripts::
	.byte 0


DragonMountan_Top_EventScript_Sergio::
# 5 "data/maps/DragonMountain_Top/scripts.pory"
	lock
# 6 "data/maps/DragonMountain_Top/scripts.pory"
	faceplayer
# 7 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_0, speaker = SP_NAME_UNKNOWN
# 8 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 9 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_TO_BLACK
# 10 "data/maps/DragonMountain_Top/scripts.pory"
	closemessage
# 11 "data/maps/DragonMountain_Top/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 12 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_UNKNOWN
# 13 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 14 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_MOUNTAINTOP_SERGIO, Common_Movement_HappyWithDelay48
# 15 "data/maps/DragonMountain_Top/scripts.pory"
	msgbox DragonMountan_Top_EventScript_Sergio_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_SERGIO
# 16 "data/maps/DragonMountain_Top/scripts.pory"
	special SpawnCameraObject
# 17 "data/maps/DragonMountain_Top/scripts.pory"
	directcameramovementtopos 15, 13
# 18 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement 0
# 19 "data/maps/DragonMountain_Top/scripts.pory"
	setfieldeffectargument 0, LOCALID_MOUNTAINTOP_SERGIO
# 20 "data/maps/DragonMountain_Top/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 21 "data/maps/DragonMountain_Top/scripts.pory"
	delay 15
# 22 "data/maps/DragonMountain_Top/scripts.pory"
	hideobjectat LOCALID_MOUNTAINTOP_SERGIO, MAP_DRAGON_MOUNTAIN_TOP
# 23 "data/maps/DragonMountain_Top/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 24 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 25 "data/maps/DragonMountain_Top/scripts.pory"
	playse SE_PIN
# 26 "data/maps/DragonMountain_Top/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_QuestionMarkWithDelay48
# 27 "data/maps/DragonMountain_Top/scripts.pory"
	delay 30
# 29 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp4
# 30 "data/maps/DragonMountain_Top/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
# 31 "data/maps/DragonMountain_Top/scripts.pory"
	waitmovement LOCALID_CAMERA
# 32 "data/maps/DragonMountain_Top/scripts.pory"
	special RemoveCameraObject
	end


DragonMountan_Top_EventScript_Sergio_Text_0:
# 7 "data/maps/DragonMountain_Top/scripts.pory"
	.string "..............\n"
	.string "..............$"

DragonMountan_Top_EventScript_Sergio_Text_1:
# 12 "data/maps/DragonMountain_Top/scripts.pory"
	.string "¡Ey! ¿Qué creías? ¿Qué me encontrarías\n"
	.string "en la cima de la montaña y\l"
	.string "combatiríamos sin siquiera hablar?$"

DragonMountan_Top_EventScript_Sergio_Text_2:
# 15 "data/maps/DragonMountain_Top/scripts.pory"
	.string "Soy Serg!o... (ver que poner)$"
