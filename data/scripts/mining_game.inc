MiningGame_Event::
	lock
	callnative IsMiningPlaceActive
	compare VAR_RESULT, 1
	goto_if_eq MiningGame_Event_2
	msgbox MiningGame_Text_AquiHasPicadoHacePoco, MSGBOX_DEFAULT
	closemessage
MiningGame_Event_1:
	release
	end

MiningGame_Event_2:
	msgbox MiningGame_Text_QuieresIntentarPicarla, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MiningGame_Event_6
MiningGame_Event_5:
	closemessage
	goto MiningGame_Event_1

MiningGame_Event_6:
	callnative DesactiveMiningPlace
	fadescreen FADE_TO_BLACK
	special DoSpecialMiningGame
	goto MiningGame_Event_5

MiningGame_Text_QuieresIntentarPicarla:
	.string "This wall looks a little loose.\n"
	.string "Want to try digging it up?$"

MiningGame_Text_AquiHasPicadoHacePoco:
	.string "You dug here recently.$"
