SergioRoom_MapScripts::
	.byte 0


SergioRoom_EventScript_Abra::
# 5 "data/maps/SergioRoom/scripts.pory"
	lock
# 6 "data/maps/SergioRoom/scripts.pory"
	release
# 7 "data/maps/SergioRoom/scripts.pory"
	applymovementandwait LOCALID_SERGIOROOM_ABRA, Common_Movement_FacePlayer
# 8 "data/maps/SergioRoom/scripts.pory"
	release
# 9 "data/maps/SergioRoom/scripts.pory"
	playmoncry SPECIES_ABRA, CRY_MODE_ENCOUNTER
# 10 "data/maps/SergioRoom/scripts.pory"
	releaseall
# 11 "data/maps/SergioRoom/scripts.pory"
	delay 20
# 12 "data/maps/SergioRoom/scripts.pory"
	msgbox SergioRoom_EventScript_Abra_Text_0, MSGBOX_YESNO
# 13 "data/maps/SergioRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq SergioRoom_EventScript_Abra_2
SergioRoom_EventScript_Abra_1:
# 22 "data/maps/SergioRoom/scripts.pory"
	release
	end

SergioRoom_EventScript_Abra_2:
# 14 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_2
# 15 "data/maps/SergioRoom/scripts.pory"
	release
# 16 "data/maps/SergioRoom/scripts.pory"
	delay 50
# 17 "data/maps/SergioRoom/scripts.pory"
	updateobjectsprite LOCALID_SERGIOROOM_ABRA, OBJ_EVENT_GFX_ABRA_TELEPORTING_1
# 19 "data/maps/SergioRoom/scripts.pory"
	warp MAP_DRAGON_MOUNTAIN_TOP, WARP_ID_DRAGON_MOUNTAIN_TOP
# 20 "data/maps/SergioRoom/scripts.pory"
	waitstate
	goto SergioRoom_EventScript_Abra_1


SergioRoom_EventScript_Abra_Text_0:
# 12 "data/maps/SergioRoom/scripts.pory"
	.string "Parece que Abra quiere\n"
	.string "teletransportarte a otro lugar.\l"
	.string "¿Deseas ir?$"
