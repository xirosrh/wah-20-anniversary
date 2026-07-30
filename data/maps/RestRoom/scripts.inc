RestRoom_MapScripts::
# 2 "data/maps/RestRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RestRoom_OnTransition
# 3 "data/maps/RestRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RestRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

RestRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 4 "data/maps/RestRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, RestRoom_OnWarp_PlayerTurnNorth
	.2byte 0


RestRoom_OnWarp_PlayerTurnNorth::
# 10 "data/maps/RestRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


RestRoom_OnTransition::
# 14 "data/maps/RestRoom/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
	end


RestRoom_EventScript_Boy1::
# 19 "data/maps/RestRoom/scripts.pory"
	lock
# 20 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 21 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_0, MSGBOX_AUTOCLOSE
# 22 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_WalkInPlaceLastTalkedFacingPlayer
# 23 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_1, MSGBOX_AUTOCLOSE
# 24 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 25 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_SweatDropWithDelay48
# 26 "data/maps/RestRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_GRENINJA
# 27 "data/maps/RestRoom/scripts.pory"
	specialvar VAR_RESULT, Special_BufferPokeboxBuyOfferFromSpecies
# 28 "data/maps/RestRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RestRoom_EventScript_Boy1_2
RestRoom_EventScript_Boy1_1:
# 31 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Boy1_2:
# 29 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy1_Text_2, MSGBOX_AUTOCLOSE
	goto RestRoom_EventScript_Boy1_1


RestRoom_EventScript_Girl1::
# 36 "data/maps/RestRoom/scripts.pory"
	lock
# 37 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 38 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_0, MSGBOX_AUTOCLOSE
# 39 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 40 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_HeartWithDelay48
# 41 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Girl1_Text_1, MSGBOX_AUTOCLOSE
# 42 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Boy2::
# 47 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_Boy2_Text_0, MSGBOX_NPC
	end


RestRoom_EventScript_PlayerCounterpart::
# 52 "data/maps/RestRoom/scripts.pory"
	lock
# 53 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 54 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 55 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_DoubleExclamationMark
# 56 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_0, MSGBOX_AUTOCLOSE
# 57 "data/maps/RestRoom/scripts.pory"
	delay 48
# 58 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_1, MSGBOX_AUTOCLOSE
# 59 "data/maps/RestRoom/scripts.pory"
	delay 10
# 60 "data/maps/RestRoom/scripts.pory"
	playse SE_PIN
# 61 "data/maps/RestRoom/scripts.pory"
	applymovementandwait VAR_LAST_TALKED, Common_Movement_Happy
# 62 "data/maps/RestRoom/scripts.pory"
	msgbox RestRoom_EventScript_PlayerCounterpart_Text_2, MSGBOX_AUTOCLOSE
# 63 "data/maps/RestRoom/scripts.pory"
	delay 48
# 64 "data/maps/RestRoom/scripts.pory"
	release
	end


RestRoom_EventScript_Shop::
# 69 "data/maps/RestRoom/scripts.pory"
	lock
# 70 "data/maps/RestRoom/scripts.pory"
	faceplayer
# 71 "data/maps/RestRoom/scripts.pory"
	goto_if_set FLAG_WAH_CHALLENGE_COMPLETED, RestRoom_EventScript_Shop_4
RestRoom_EventScript_Shop_3:
# 77 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_1
# 78 "data/maps/RestRoom/scripts.pory"
	waitmessage
RestRoom_EventScript_Shop_1:
# 80 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 81 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Shop
# 82 "data/maps/RestRoom/scripts.pory"
	clearflag FLAG_REST_ROOM_MART_PRICE_MULTIPLIER
# 83 "data/maps/RestRoom/scripts.pory"
	release
	end

RestRoom_EventScript_Shop_2:
# 72 "data/maps/RestRoom/scripts.pory"
	message RestRoom_EventScript_Shop_Text_0
# 73 "data/maps/RestRoom/scripts.pory"
	waitmessage
# 74 "data/maps/RestRoom/scripts.pory"
	setflag FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN
	goto RestRoom_EventScript_Shop_1

RestRoom_EventScript_Shop_4:
# 71 "data/maps/RestRoom/scripts.pory"
	goto_if_unset FLAG_WAH_MART_COMBAT_ITEMS_ANNOUNCEMENT_SEEN, RestRoom_EventScript_Shop_2
	goto RestRoom_EventScript_Shop_3


RestRoom_EventScript_Pokebox::
# 88 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_C, 3
# 89 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_D, 4
# 90 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_E, METATILE_lobby_PC_RESTROOM_OFF
# 91 "data/maps/RestRoom/scripts.pory"
	setvar VAR_TEMP_F, METATILE_lobby_PC_RESTROOM_ON
# 92 "data/maps/RestRoom/scripts.pory"
	call WahRoomsShared_EventScript_Pokebox
	end


RestRoom_EventScript_Boy1_Text_0:
# 21 "data/maps/RestRoom/scripts.pory"
	.string "Phew, finally a rest area!$"

RestRoom_EventScript_Boy1_Text_1:
# 23 "data/maps/RestRoom/scripts.pory"
	.string "For a moment I thought all 21 rooms\n"
	.string "were back-to-back with no break…$"

RestRoom_EventScript_Boy1_Text_2:
# 29 "data/maps/RestRoom/scripts.pory"
	.string "I'm struggling; I need to prepare better\n"
	.string "for the next rooms.\p"
	.string "I'll tweak some moves, buy some healing\n"
	.string "items, and…\p"
	.string "I think I'll buy a {STR_VAR_1}! I saw\n"
	.string "it's only {STR_VAR_2} in the PC - it's\l"
	.string "a steal!$"

RestRoom_EventScript_Girl1_Text_0:
# 38 "data/maps/RestRoom/scripts.pory"
	.string "The room designs are incredible!$"

RestRoom_EventScript_Girl1_Text_1:
# 41 "data/maps/RestRoom/scripts.pory"
	.string "A theater, a jungle… even a cinema!\p"
	.string "Can you imagine how much work goes into\n"
	.string "all this?$"

RestRoom_EventScript_Boy2_Text_0:
# 47 "data/maps/RestRoom/scripts.pory"
	.string "The prices in this shop are a total\n"
	.string "ripoff!\p"
	.string "I should have bought everything I\n"
	.string "needed before coming in.$"

RestRoom_EventScript_PlayerCounterpart_Text_0:
# 56 "data/maps/RestRoom/scripts.pory"
	.string "What a surprise, {PLAYER}!$"

RestRoom_EventScript_PlayerCounterpart_Text_1:
# 58 "data/maps/RestRoom/scripts.pory"
	.string "So you're taking part in the challenge\n"
	.string "too?\p"
	.string "Every room teaches us something about\n"
	.string "the community's leaders!\p"
	.string "I've learned a lot from them!$"

RestRoom_EventScript_PlayerCounterpart_Text_2:
# 62 "data/maps/RestRoom/scripts.pory"
	.string "How exciting!$"

RestRoom_EventScript_Shop_Text_0:
# 72 "data/maps/RestRoom/scripts.pory"
	.string "Hi! We've expanded the catalog!\p"
	.string "Now you can also buy battle items.\p"
	.string "How can I help you?\n"
	.string "We're a little pricier here!$"

RestRoom_EventScript_Shop_Text_1:
# 77 "data/maps/RestRoom/scripts.pory"
	.string "Hi! How can I help you?\nWe're a little pricier here!$"
