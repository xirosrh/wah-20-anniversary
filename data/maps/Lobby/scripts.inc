Lobby_MapScripts::
# 2 "data/maps/Lobby/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Lobby_OnTransition
	.byte 0


Lobby_OnTransition::
# 6 "data/maps/Lobby/scripts.pory"
	setrespawn HEAL_LOCATION_LOBBY
	end


Lobby_EventScript_StartChallenge::
# 11 "data/maps/Lobby/scripts.pory"
	lock
# 12 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_LOBBY_POLICE, Common_Movement_FacePlayer
# 13 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_StartChallenge_Text_0, MSGBOX_YESNO
# 14 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_StartChallenge_2
# 18 "data/maps/Lobby/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkDown
# 19 "data/maps/Lobby/scripts.pory"
	turnobject LOCALID_LOBBY_POLICE, DIR_SOUTH
Lobby_EventScript_StartChallenge_1:
# 21 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_StartChallenge_2:
# 15 "data/maps/Lobby/scripts.pory"
	warp MAP_OMEGA_ROOM, WARP_ID_OMEGA_ROOM_INITIAL
# 16 "data/maps/Lobby/scripts.pory"
	waitstate
	goto Lobby_EventScript_StartChallenge_1


Lobby_EventScript_TeamSelector::
# 27 "data/maps/Lobby/scripts.pory"
	lock
# 28 "data/maps/Lobby/scripts.pory"
	faceplayer
# 29 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_0, MSGBOX_YESNO
# 30 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq Lobby_EventScript_TeamSelector_2
# 39 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
Lobby_EventScript_TeamSelector_1:
# 41 "data/maps/Lobby/scripts.pory"
	turnobject VAR_LAST_TALKED, DIR_SOUTH
# 42 "data/maps/Lobby/scripts.pory"
	release
	end

Lobby_EventScript_TeamSelector_2:
# 31 "data/maps/Lobby/scripts.pory"
	special OpenTeamSelectorFromField
# 32 "data/maps/Lobby/scripts.pory"
	waitstate
# 33 "data/maps/Lobby/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq Lobby_EventScript_TeamSelector_5
# 36 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_Text_TeamSelector_TeamSelectionCancelled, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1

Lobby_EventScript_TeamSelector_5:
# 34 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_TeamSelector_Text_1, MSGBOX_AUTOCLOSE
	goto Lobby_EventScript_TeamSelector_1


Lobby_EventScript_Shop::
# 53 "data/maps/Lobby/scripts.pory"
	lock
# 54 "data/maps/Lobby/scripts.pory"
	faceplayer
# 55 "data/maps/Lobby/scripts.pory"
	message Lobby_EventScript_Shop_Text_0
# 56 "data/maps/Lobby/scripts.pory"
	waitmessage
# 57 "data/maps/Lobby/scripts.pory"
	pokemart MyMartItems
# 58 "data/maps/Lobby/scripts.pory"
	msgbox Lobby_EventScript_Shop_Text_1, MSGBOX_AUTOCLOSE
# 59 "data/maps/Lobby/scripts.pory"
	release
	end


	.align 2
# 63 "data/maps/Lobby/scripts.pory"
MyMartItems:
# 64 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 65 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_POTION
# 66 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 67 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ETHER
# 68 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ETHER
# 69 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ELIXIR
# 70 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_ELIXIR
# 71 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVE
# 72 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MAX_REVIVE
# 73 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_REVIVAL_HERB
# 74 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_BAXCALIBURITE
# 75 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DRAGALGITE
# 76 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_TYRANITARITE
# 77 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_DARKRANITE
# 78 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ALAKAZITE
# 79 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE
# 80 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_LUCARIONITE_Z
# 81 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_X
# 82 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_MEWTWONITE_Y
# 83 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_X
# 84 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CHARIZARDITE_Y
# 85 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GALLADITE
# 86 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_GLALITITE
# 87 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_FROSLASSITE
# 88 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_CLEFABLITE
# 89 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_HOUNDOOMINITE
# 90 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_AGGRONITE
# 91 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_ZYGARDITE
# 92 "data/maps/Lobby/scripts.pory"
	.2byte ITEM_VICTREEBELITE
	.2byte ITEM_NONE

Lobby_EventScript_StartChallenge_Text_0:
# 13 "data/maps/Lobby/scripts.pory"
	.string "Pendiente textos, ¿empezar desafío?$"

Lobby_EventScript_TeamSelector_Text_0:
# 29 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! Soy el encargado de la selección\n"
	.string "de equipos para el desafío.\p"
	.string "Veo que equipo actual es bueno, pero\n"
	.string "creo que puedes conseguir uno mejor.\p"
	.string "¿Quieres elegir otro equipo?$"

Lobby_EventScript_TeamSelector_Text_1:
# 34 "data/maps/Lobby/scripts.pory"
	.string "¡Excelente elección! Eso sí es un\n"
	.string "equipo ganador.\p"
	.string "¡Ve por la gloria!$"

Lobby_EventScript_Shop_Text_0:
# 55 "data/maps/Lobby/scripts.pory"
	.string "¡Hola! ¿En qué puedo ayudarte?$"

Lobby_EventScript_Shop_Text_1:
# 58 "data/maps/Lobby/scripts.pory"
	.string "Gracias por tu visita. ¡Que tengas un\n"
	.string "buen día!$"

Lobby_Text_TeamSelector_TeamSelectionCancelled::
# 47 "data/maps/Lobby/scripts.pory"
	.string "¡Vaya, vaya! Un{A} chic{OA} valiente, ¿eh?\nAsí que piensas ganar con ESE equipo…\p¡Buena suerte, la vas a necesitar!$"
