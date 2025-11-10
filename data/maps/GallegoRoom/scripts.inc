GallegoRoom_MapScripts::
	.byte 0


GallegoRoom_EventScript_Gallego::
# 4 "data/maps/GallegoRoom/scripts.pory"
	lock
# 5 "data/maps/GallegoRoom/scripts.pory"
	applymovementandwait LOCALID_GALLEGOROOM_GALLEGO, GallegoRoom_EventScript_Gallego_Movement_0
# 6 "data/maps/GallegoRoom/scripts.pory"
	msgbox GallegoRoom_EventScript_Gallego_Text_0, MSGBOX_AUTOCLOSE
# 7 "data/maps/GallegoRoom/scripts.pory"
	release
	end


# 5 "data/maps/GallegoRoom/scripts.pory"
GallegoRoom_EventScript_Gallego_Movement_0:
# 5 "data/maps/GallegoRoom/scripts.pory"
	reveal_trainer
	step_end

GallegoRoom_EventScript_Gallego_Text_0:
# 6 "data/maps/GallegoRoom/scripts.pory"
	.string "prueba$"
