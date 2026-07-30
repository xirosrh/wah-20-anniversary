GoceRoom_MapScripts::
# 5 "data/maps/GoceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, GoceRoom_OnLoad
# 6 "data/maps/GoceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, GoceRoom_OnTransition
# 2 "data/maps/GoceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, GoceRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

GoceRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 3 "data/maps/GoceRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, GoceRoom_OnWarp_PlayerTurnNorth
	.2byte 0


GoceRoom_OnLoad::
# 11 "data/maps/GoceRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GOCE, GoceRoom_OnLoad_2
GoceRoom_OnLoad_1:
	end

GoceRoom_OnLoad_2:
# 12 "data/maps/GoceRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	goto GoceRoom_OnLoad_1


GoceRoom_OnWarp_PlayerTurnNorth::
# 18 "data/maps/GoceRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


GoceRoom_OnTransition::
# 23 "data/maps/GoceRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_Goce
	end


GoceRoom_EventScript_Goce::
# 28 "data/maps/GoceRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_GOCE, GoceRoom_EventScript_Goce_1
# 34 "data/maps/GoceRoom/scripts.pory"
	lock
# 35 "data/maps/GoceRoom/scripts.pory"
	faceplayer
# 36 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_1, speaker = SP_NAME_GOCE
# 37 "data/maps/GoceRoom/scripts.pory"
	playse SE_PIN
# 38 "data/maps/GoceRoom/scripts.pory"
	applymovement LOCALID_GOCEROOM_GOCE, GoceRoom_EventScript_Goce_Movement_0
# 39 "data/maps/GoceRoom/scripts.pory"
	waitmovement 0
# 40 "data/maps/GoceRoom/scripts.pory"
	waitse
# 41 "data/maps/GoceRoom/scripts.pory"
	call GoceRoom_EventScript_GoceBattle
# 42 "data/maps/GoceRoom/scripts.pory"
	delay 10
# 43 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOCE
# 44 "data/maps/GoceRoom/scripts.pory"
	delay 20
# 45 "data/maps/GoceRoom/scripts.pory"
	playse SE_PIN
# 46 "data/maps/GoceRoom/scripts.pory"
	applymovement LOCALID_GOCEROOM_GOCE, Common_Movement_QuestionMarkWithDelay48
# 47 "data/maps/GoceRoom/scripts.pory"
	waitmovement 0
# 48 "data/maps/GoceRoom/scripts.pory"
	waitse
# 49 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_GOCE
# 50 "data/maps/GoceRoom/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 51 "data/maps/GoceRoom/scripts.pory"
	compare VAR_TEMP_0, 5
	goto_if_eq GoceRoom_EventScript_Goce_5
# 57 "data/maps/GoceRoom/scripts.pory"
	applymovementandwait LOCALID_GOCEROOM_GOCE, GoceRoom_EventScript_Goce_Movement_2
# 59 "data/maps/GoceRoom/scripts.pory"
	setobjectxy LOCALID_GOCEROOM_GOCE, 5, 5
# 60 "data/maps/GoceRoom/scripts.pory"
	setobjectxyperm LOCALID_GOCEROOM_GOCE, 5, 5
GoceRoom_EventScript_Goce_4:
# 62 "data/maps/GoceRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 63 "data/maps/GoceRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_GOCE
# 64 "data/maps/GoceRoom/scripts.pory"
	call WahRoomsShared_EventScript_AfterBattle
# 65 "data/maps/GoceRoom/scripts.pory"
	release
	end

GoceRoom_EventScript_Goce_1:
# 29 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Goce_Text_0, MSGBOX_NPC, speaker = SP_NAME_GOCE
# 30 "data/maps/GoceRoom/scripts.pory"
	release
	end

GoceRoom_EventScript_Goce_5:
# 52 "data/maps/GoceRoom/scripts.pory"
	applymovementandwait LOCALID_GOCEROOM_GOCE, GoceRoom_EventScript_Goce_Movement_1
# 54 "data/maps/GoceRoom/scripts.pory"
	setobjectxy LOCALID_GOCEROOM_GOCE, 7, 5
# 55 "data/maps/GoceRoom/scripts.pory"
	setobjectxyperm LOCALID_GOCEROOM_GOCE, 7, 5
	goto GoceRoom_EventScript_Goce_4


GoceRoom_EventScript_GoceBattle::
# 72 "data/maps/GoceRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, GoceRoom_EventScript_GoceBattle_2
# 75 "data/maps/GoceRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_GOCE
# 76 "data/maps/GoceRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 77 "data/maps/GoceRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq GoceRoom_EventScript_GoceBattle_5
# 80 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_ALTERNATIVE, GoceRoom_Text_GoceDefeated
GoceRoom_EventScript_GoceBattle_1:
	return

GoceRoom_EventScript_GoceBattle_2:
# 73 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_MAIN, GoceRoom_Text_GoceDefeated
	goto GoceRoom_EventScript_GoceBattle_1

GoceRoom_EventScript_GoceBattle_5:
# 78 "data/maps/GoceRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_GOCE_MAIN, GoceRoom_Text_GoceDefeated
	goto GoceRoom_EventScript_GoceBattle_1


GoceRoom_EventScript_Ambar::
# 91 "data/maps/GoceRoom/scripts.pory"
	msgbox GoceRoom_EventScript_Ambar_Text_0, MSGBOX_SIGN
	end


# 38 "data/maps/GoceRoom/scripts.pory"
GoceRoom_EventScript_Goce_Movement_0:
# 38 "data/maps/GoceRoom/scripts.pory"
	emote_versus
	step_end

# 52 "data/maps/GoceRoom/scripts.pory"
GoceRoom_EventScript_Goce_Movement_1:
# 53 "data/maps/GoceRoom/scripts.pory"
	lock_facing_direction
# 53 "data/maps/GoceRoom/scripts.pory"
	walk_right
# 53 "data/maps/GoceRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 57 "data/maps/GoceRoom/scripts.pory"
GoceRoom_EventScript_Goce_Movement_2:
# 58 "data/maps/GoceRoom/scripts.pory"
	face_right
# 58 "data/maps/GoceRoom/scripts.pory"
	lock_facing_direction
# 58 "data/maps/GoceRoom/scripts.pory"
	walk_left
# 58 "data/maps/GoceRoom/scripts.pory"
	unlock_facing_direction
	step_end

GoceRoom_EventScript_Goce_Text_0:
# 29 "data/maps/GoceRoom/scripts.pory"
	.string "You may advance to the next challenge\n"
	.string "now.\p"
	.string "There's still a long way to go.$"

GoceRoom_EventScript_Goce_Text_1:
# 36 "data/maps/GoceRoom/scripts.pory"
	.string "Listen, little one. I wasn't the best\n"
	.string "known nor was I around for very long...\p"
	.string "I was but a spark trapped in {COLOR LIGHT_RED}amber{COLOR DARK_GRAY}.\p"
	.string "But that spark was the start of all\n"
	.string "this, and today it's your turn to face\l"
	.string "it.$"

GoceRoom_EventScript_Goce_Text_2:
# 43 "data/maps/GoceRoom/scripts.pory"
	.string "Great battle! You managed to defeat\n"
	.string "the great founder - you must be proud.$"

GoceRoom_EventScript_Goce_Text_3:
# 49 "data/maps/GoceRoom/scripts.pory"
	.string "Huh, so you don't know who I am? They\n"
	.string "knew me as {COLOR RED}Goce{COLOR DARK_GRAY} and as {COLOR RED}Lance{COLOR DARK_GRAY}.\p"
	.string "Either way, what matters isn't my name,\n"
	.string "but that what began stays alive.\p"
	.string "You've just proven to me that it is, kid.\p"
	.string "You may continue.$"

GoceRoom_EventScript_Ambar_Text_0:
# 91 "data/maps/GoceRoom/scripts.pory"
	.string "There are small fragments of amber\n"
	.string "scattered across the floor.$"

GoceRoom_Text_GoceDefeated::
# 86 "data/maps/GoceRoom/scripts.pory"
	.string "Incredible how they've evolved over\n"
	.string "these last 20 years…$"
