CheveRoom_MapScripts::
	.byte 0


CheveRoom_EventScript_CheveChallenge::
# 4 "data/maps/CheveRoom/scripts.pory"
	lock
# 5 "data/maps/CheveRoom/scripts.pory"
	msgbox CheveRoom_EventScript_CheveChallenge_Text_0
# 6 "data/maps/CheveRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_CHEVE_MAIN, CheveRoom_EventScript_CheveChallenge_Text_1
# 7 "data/maps/CheveRoom/scripts.pory"
	release
	end


CheveRoom_EventScript_CheveChallenge_Text_0:
# 5 "data/maps/CheveRoom/scripts.pory"
	.string "Holi$"

CheveRoom_EventScript_CheveChallenge_Text_1:
# 6 "data/maps/CheveRoom/scripts.pory"
	.string "asd$"
