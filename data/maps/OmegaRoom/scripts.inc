OmegaRoom_MapScripts::
	.byte 0


OmegaRoom_EventScript_StartChallenge::
# 5 "data/maps/OmegaRoom/scripts.pory"
	lock
# 6 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_0, MSGBOX_AUTOCLOSE
# 7 "data/maps/OmegaRoom/scripts.pory"
	getplayerxy VAR_TEMP_C, VAR_TEMP_D
# 8 "data/maps/OmegaRoom/scripts.pory"
	getobjectxy LOCALID_OMEGAROOM_OMEGA, CURRENT_POSITION, VAR_TEMP_A, VAR_TEMP_B
# 12 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, Common_Movement_JumpInPlaceDown
# 13 "data/maps/OmegaRoom/scripts.pory"
	waitmovement 0
# 14 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_1
# 15 "data/maps/OmegaRoom/scripts.pory"
	subvar VAR_TEMP_D, 1
# 18 "data/maps/OmegaRoom/scripts.pory"
	applymovement LOCALID_OMEGAROOM_OMEGA, OmegaRoom_EventScript_StartChallenge_Movement_0
# 24 "data/maps/OmegaRoom/scripts.pory"
	msgbox OmegaRoom_EventScript_StartChallenge_Text_2
# 25 "data/maps/OmegaRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_OMEGA_MAIN, OmegaRoom_EventScript_StartChallenge_Text_3
# 26 "data/maps/OmegaRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 27 "data/maps/OmegaRoom/scripts.pory"
	release
	end


# 18 "data/maps/OmegaRoom/scripts.pory"
OmegaRoom_EventScript_StartChallenge_Movement_0:
# 19 "data/maps/OmegaRoom/scripts.pory"
	walk_down
# 20 "data/maps/OmegaRoom/scripts.pory"
	jump_2_down
	step_end

OmegaRoom_EventScript_StartChallenge_Text_0:
# 6 "data/maps/OmegaRoom/scripts.pory"
	.string "holi$"

OmegaRoom_EventScript_StartChallenge_Text_1:
# 14 "data/maps/OmegaRoom/scripts.pory"
	.string "Ostras, une nuevo desafiante.$"

OmegaRoom_EventScript_StartChallenge_Text_2:
# 24 "data/maps/OmegaRoom/scripts.pory"
	.string "XXX$"

OmegaRoom_EventScript_StartChallenge_Text_3:
# 25 "data/maps/OmegaRoom/scripts.pory"
	.string "XX$"
