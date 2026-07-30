AguiarRoom_MapScripts::
# 9 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, AguiarRoom_OnLoad
# 13 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AguiarRoom_OnTransition
# 6 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, AguiarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 10 "data/maps/AguiarRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AguiarRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

AguiarRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 7 "data/maps/AguiarRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, AguiarRoom_OnWarp_PlayerTurnNorth
	.2byte 0

AguiarRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 11 "data/maps/AguiarRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, AguiarRoom_OnFrame
	.2byte 0


AguiarRoom_OnFrame::
# 18 "data/maps/AguiarRoom/scripts.pory"
	special ShowMapNamePopup
# 19 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 20 "data/maps/AguiarRoom/scripts.pory"
	removeobject LOCALID_AGUIARROOM_AGUIAR_SMOKING
# 21 "data/maps/AguiarRoom/scripts.pory"
	getplayerxy VAR_TEMP_A, VAR_TEMP_B
# 22 "data/maps/AguiarRoom/scripts.pory"
	special SpawnCameraObject
# 23 "data/maps/AguiarRoom/scripts.pory"
	directcameramovementtopos 10, 6
# 24 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 25 "data/maps/AguiarRoom/scripts.pory"
	special HideMapNamePopUpWindow
# 26 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 27 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 28 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR, Common_Movement_HappyWithDelay48
# 29 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 30 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 31 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 32 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_TurnOffTV
# 33 "data/maps/AguiarRoom/scripts.pory"
	delay 30
# 34 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR, AguiarRoom_OnFrame_Movement_0
# 35 "data/maps/AguiarRoom/scripts.pory"
	addobject LOCALID_AGUIARROOM_AGUIAR_SMOKING
# 36 "data/maps/AguiarRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 37 "data/maps/AguiarRoom/scripts.pory"
	removeobject LOCALID_AGUIARROOM_AGUIAR
# 38 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 39 "data/maps/AguiarRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_A, VAR_TEMP_B
# 40 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 41 "data/maps/AguiarRoom/scripts.pory"
	special RemoveCameraObject
# 42 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 43 "data/maps/AguiarRoom/scripts.pory"
	release
	end


AguiarRoom_OnLoad::
# 48 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq AguiarRoom_OnLoad_2
AguiarRoom_OnLoad_1:
# 51 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_OnLoad_5
AguiarRoom_OnLoad_4:
	end

AguiarRoom_OnLoad_2:
# 49 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_TurnOnTV
	goto AguiarRoom_OnLoad_1

AguiarRoom_OnLoad_5:
# 52 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto AguiarRoom_OnLoad_4


AguiarRoom_OnWarp_PlayerTurnNorth::
# 58 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


AguiarRoom_OnTransition::
# 63 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Aguiar
	end


AguiarRoom_EventScript_TurnOffTV::
# 68 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_aguiar_TV_OFF_LEFT, TRUE
# 69 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_aguiar_TV_OFF_RIGHT, TRUE
# 70 "data/maps/AguiarRoom/scripts.pory"
	special DrawWholeMapView
	return


AguiarRoom_EventScript_TurnOnTV::
# 75 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 9, 2, METATILE_room_aguiar_TV_ON_LEFT, TRUE
# 76 "data/maps/AguiarRoom/scripts.pory"
	setmetatile 10, 2, METATILE_room_aguiar_TV_ON_RIGHT, TRUE
# 77 "data/maps/AguiarRoom/scripts.pory"
	special DrawWholeMapView
	return


AguiarRoom_EventScript_Aguiar::
# 82 "data/maps/AguiarRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_AGUIAR, AguiarRoom_EventScript_Aguiar_2
# 97 "data/maps/AguiarRoom/scripts.pory"
	lock
# 98 "data/maps/AguiarRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 99 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_5
AguiarRoom_EventScript_Aguiar_4:
# 110 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 111 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_FACE_DOWN
# 112 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 113 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 114 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 115 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 116 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 117 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 118 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 119 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 120 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 121 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 122 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 123 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 124 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 125 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 126 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 127 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 128 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_HappyWithDelay48
# 129 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 130 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 131 "data/maps/AguiarRoom/scripts.pory"
	playse SE_PIN
# 132 "data/maps/AguiarRoom/scripts.pory"
	applymovementandwait LOCALID_AGUIARROOM_AGUIAR_SMOKING, AguiarRoom_EventScript_Aguiar_Movement_0
# 133 "data/maps/AguiarRoom/scripts.pory"
	waitse
# 134 "data/maps/AguiarRoom/scripts.pory"
	call AguiarRoom_EventScript_AguiarBattle
# 135 "data/maps/AguiarRoom/scripts.pory"
	delay 10
# 136 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 137 "data/maps/AguiarRoom/scripts.pory"
	applymovement LOCALID_AGUIARROOM_AGUIAR_SMOKING, Common_Movement_SmokeCigarette
# 138 "data/maps/AguiarRoom/scripts.pory"
	playse SE_REPEL
# 139 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 140 "data/maps/AguiarRoom/scripts.pory"
	delay 20
# 141 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 142 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 143 "data/maps/AguiarRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_AGUIAR
# 144 "data/maps/AguiarRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_AGUIARROOM_AGUIAR_SMOKING, MOVEMENT_TYPE_SMOKING_LOOP
# 145 "data/maps/AguiarRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 146 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_2:
# 83 "data/maps/AguiarRoom/scripts.pory"
	lock
# 84 "data/maps/AguiarRoom/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 85 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_8
AguiarRoom_EventScript_Aguiar_7:
# 88 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 89 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Aguiar_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_AGUIAR
# 90 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, DIR_NORTH
	goto_if_ne AguiarRoom_EventScript_Aguiar_11
AguiarRoom_EventScript_Aguiar_10:
# 94 "data/maps/AguiarRoom/scripts.pory"
	release
	end

AguiarRoom_EventScript_Aguiar_5:
# 100 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR
# 101 "data/maps/AguiarRoom/scripts.pory"
	faceplayer
# 102 "data/maps/AguiarRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 103 "data/maps/AguiarRoom/scripts.pory"
	directmovementtopos LOCALID_PLAYER, 6, 6
# 104 "data/maps/AguiarRoom/scripts.pory"
	waitmovement 0
# 105 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 106 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_AGUIARROOM_AGUIAR_SMOKING, DIR_SOUTH
# 107 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR_SMOKING
# 108 "data/maps/AguiarRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
	goto AguiarRoom_EventScript_Aguiar_4

AguiarRoom_EventScript_Aguiar_8:
# 86 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR
	goto AguiarRoom_EventScript_Aguiar_7

AguiarRoom_EventScript_Aguiar_11:
# 91 "data/maps/AguiarRoom/scripts.pory"
	turnobject LOCALID_AGUIARROOM_AGUIAR_SMOKING, DIR_SOUTH
# 92 "data/maps/AguiarRoom/scripts.pory"
	updateobjectsprite LOCALID_AGUIARROOM_AGUIAR_SMOKING, OBJ_EVENT_GFX_AGUIAR_SMOKING
	goto AguiarRoom_EventScript_Aguiar_10


AguiarRoom_EventScript_AguiarBattle::
# 151 "data/maps/AguiarRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, AguiarRoom_EventScript_AguiarBattle_2
# 154 "data/maps/AguiarRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_AGUIAR
# 155 "data/maps/AguiarRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 156 "data/maps/AguiarRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq AguiarRoom_EventScript_AguiarBattle_5
# 159 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_ALTERNATIVE, AguiarRoom_Text_AguiarDefeated
AguiarRoom_EventScript_AguiarBattle_1:
	return

AguiarRoom_EventScript_AguiarBattle_2:
# 152 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1

AguiarRoom_EventScript_AguiarBattle_5:
# 157 "data/maps/AguiarRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_AGUIAR_MAIN, AguiarRoom_Text_AguiarDefeated
	goto AguiarRoom_EventScript_AguiarBattle_1


AguiarRoom_EventScript_Coffee::
# 170 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Coffee_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Ashtray::
# 175 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Ashtray_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Microwave::
# 180 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Microwave_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Trash::
# 185 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Trash_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Refrigerator::
# 190 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Refrigerator_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_TV::
# 195 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_TV_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Kitchen::
# 202 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Kitchen_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Switch::
# 207 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Switch_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_Drawer::
# 212 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_Drawer_Text_0, MSGBOX_SIGN
	end


AguiarRoom_EventScript_FullOfBooks::
# 217 "data/maps/AguiarRoom/scripts.pory"
	msgbox AguiarRoom_EventScript_FullOfBooks_Text_0, MSGBOX_SIGN
	end


# 34 "data/maps/AguiarRoom/scripts.pory"
AguiarRoom_OnFrame_Movement_0:
# 34 "data/maps/AguiarRoom/scripts.pory"
	walk_down
# 34 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 34 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 34 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 34 "data/maps/AguiarRoom/scripts.pory"
	walk_left
# 34 "data/maps/AguiarRoom/scripts.pory"
	walk_up
# 34 "data/maps/AguiarRoom/scripts.pory"
	face_down
	step_end

# 132 "data/maps/AguiarRoom/scripts.pory"
AguiarRoom_EventScript_Aguiar_Movement_0:
# 132 "data/maps/AguiarRoom/scripts.pory"
	emote_versus
	step_end

AguiarRoom_OnFrame_Text_0:
# 26 "data/maps/AguiarRoom/scripts.pory"
	.string "What a great show! Today really is a\n"
	.string "quiet day.$"

AguiarRoom_OnFrame_Text_1:
# 31 "data/maps/AguiarRoom/scripts.pory"
	.string "Well, time for a couple of drags.$"

AguiarRoom_EventScript_Aguiar_Text_0:
# 89 "data/maps/AguiarRoom/scripts.pory"
	.string "Here I am, same as always: relaxed,\n"
	.string "smoking, and waiting to see who shows\l"
	.string "up.$"

AguiarRoom_EventScript_Aguiar_Text_1:
# 112 "data/maps/AguiarRoom/scripts.pory"
	.string "Well, look at you! You made it all the way\n"
	.string "here after all.\p"
	.string "And here I was thinking I'd spend the\n"
	.string "day lazing around with a cigarette and\l"
	.string "little else…$"

AguiarRoom_EventScript_Aguiar_Text_2:
# 117 "data/maps/AguiarRoom/scripts.pory"
	.string "I wasn't expecting company, but hey, it\n"
	.string "works out great: gives me something to\l"
	.string "do for a while.$"

AguiarRoom_EventScript_Aguiar_Text_3:
# 121 "data/maps/AguiarRoom/scripts.pory"
	.string "Everyone here takes it so seriously, as\n"
	.string "if this were a matter of life or death.\p"
	.string "I'd rather laugh, take a couple of\n"
	.string "drags, and see what whoever shows up\l"
	.string "has to offer.$"

AguiarRoom_EventScript_Aguiar_Text_4:
# 126 "data/maps/AguiarRoom/scripts.pory"
	.string "I'm not going to give you epic speeches\n"
	.string "or grandpa advice - there are others\l"
	.string "for that.\p"
	.string "If you want to fight, great. If I lose,\n"
	.string "well, I'll just light up another.\p"
	.string "And if I win… well, I'm not going to make\n"
	.string "a poster of your face, eh?$"

AguiarRoom_EventScript_Aguiar_Text_5:
# 130 "data/maps/AguiarRoom/scripts.pory"
	.string "So come on, let's not overthink it. Send\n"
	.string "out your Pokémon - I'm curious to see if\l"
	.string "you can at least make me set the\l"
	.string "cigarette down for a bit.\p"
	.string "Here we go!$"

AguiarRoom_EventScript_Aguiar_Text_6:
# 136 "data/maps/AguiarRoom/scripts.pory"
	.string "Well, you sure got me! And here I was\n"
	.string "thinking it'd be another walk in the\l"
	.string "park…$"

AguiarRoom_EventScript_Aguiar_Text_7:
# 141 "data/maps/AguiarRoom/scripts.pory"
	.string "Not bad, not bad at all. You can go\n"
	.string "ahead and keep moving.$"

AguiarRoom_EventScript_Coffee_Text_0:
# 170 "data/maps/AguiarRoom/scripts.pory"
	.string "The cup of coffee is still warm.$"

AguiarRoom_EventScript_Ashtray_Text_0:
# 175 "data/maps/AguiarRoom/scripts.pory"
	.string "The ashtray is full of freshly\n"
	.string "stubbed-out cigarettes.\p"
	.string "Someone definitely has a serious\n"
	.string "addiction.$"

AguiarRoom_EventScript_Microwave_Text_0:
# 180 "data/maps/AguiarRoom/scripts.pory"
	.string "The microwave has stains of reheated\n"
	.string "food.$"

AguiarRoom_EventScript_Trash_Text_0:
# 185 "data/maps/AguiarRoom/scripts.pory"
	.string "The wastebasket is full of cigarette\n"
	.string "butts and ash.$"

AguiarRoom_EventScript_Refrigerator_Text_0:
# 190 "data/maps/AguiarRoom/scripts.pory"
	.string "The fridge gives off an incredibly\n"
	.string "delicious smell.\p"
	.string "There's surely something tasty stored\n"
	.string "inside.$"

AguiarRoom_EventScript_TV_Text_0:
# 195 "data/maps/AguiarRoom/scripts.pory"
	.string "It's a 55-inch TV.\nIt definitely takes up half the room.$"

AguiarRoom_EventScript_Kitchen_Text_0:
# 202 "data/maps/AguiarRoom/scripts.pory"
	.string "It looks like a pretty modern kitchen.\p"
	.string "Everything's spotlessly clean.$"

AguiarRoom_EventScript_Switch_Text_0:
# 207 "data/maps/AguiarRoom/scripts.pory"
	.string "It looks like someone left the Nintendo\n"
	.string "Switch in the middle of a game.$"

AguiarRoom_EventScript_Drawer_Text_0:
# 212 "data/maps/AguiarRoom/scripts.pory"
	.string "It looks like someone uses this drawer\n"
	.string "exclusively to store cigarettes.$"

AguiarRoom_EventScript_FullOfBooks_Text_0:
# 217 "data/maps/AguiarRoom/scripts.pory"
	.string "There are lots of books of all kinds.$"

AguiarRoom_Text_AguiarDefeated::
# 165 "data/maps/AguiarRoom/scripts.pory"
	.string "What a battle! I had a great\n"
	.string "time.$"
