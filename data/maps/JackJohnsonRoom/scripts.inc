JackJohnsonRoom_MapScripts::
# 14 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JackJohnsonRoom_OnTransition
# 15 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JackJohnsonRoom_OnLoad
# 19 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JackJohnsonRoom_OnResume
# 11 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
# 16 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	.byte 0

JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 12 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script_2 VAR_TEMP_0, 0, JackJohnsonRoom_OnFrame
	.2byte 0

JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 17 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script_2 VAR_TEMP_8, 0, JackJohnsonRoom_OnWarp_PlayerTurnNorth
	.2byte 0


JackJohnsonRoom_OnResume::
# 23 "data/maps/JackJohnsonRoom/scripts.pory"
	checktrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN
	goto_if 1, JackJohnsonRoom_OnResume_2
# 24 "data/maps/JackJohnsonRoom/scripts.pory"
	checktrainerflag TRAINER_WAH_ADMIN_JACK_JOHNSON_ALTERNATIVE
	goto_if 1, JackJohnsonRoom_OnResume_2
JackJohnsonRoom_OnResume_1:
	end

JackJohnsonRoom_OnResume_2:
# 25 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC2, 3, 6
# 26 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC4, 5, 6
# 27 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC3, 7, 6
# 28 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC1, 9, 6
# 29 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC2, 3, 6
# 30 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC4, 5, 6
# 31 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC3, 7, 6
# 32 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC1, 9, 6
# 33 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 34 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 35 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 36 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
	goto JackJohnsonRoom_OnResume_1


JackJohnsonRoom_OnWarp_PlayerTurnNorth::
# 42 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
	end


JackJohnsonRoom_OnLoad::
# 47 "data/maps/JackJohnsonRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ADMIN_JACK_JOHNSON, JackJohnsonRoom_OnLoad_1
# 51 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 5, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_1, 0
# 52 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 6, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_2, 0
# 53 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 7, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_3, 0
# 54 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 8, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_4, 0
# 56 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 57 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 58 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 59 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 60 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 61 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 62 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 63 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 64 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 65 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 66 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 67 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 68 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 69 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 70 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 71 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 72 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 73 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 74 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 75 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 78 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 79 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 80 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 81 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 82 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 83 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 86 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 89 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 90 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 91 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 92 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 93 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 94 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 95 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
	return

JackJohnsonRoom_OnLoad_1:
# 48 "data/maps/JackJohnsonRoom/scripts.pory"
	call WahRoomsShared_SetDoorAsOpen
	return


JackJohnsonRoom_OnTransition::
# 103 "data/maps/JackJohnsonRoom/scripts.pory"
	call WahRoomsShared_Kecleon_SetSala_JackJohnson
# 104 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_TEMP_1
# 105 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_TEMP_2
# 106 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_TEMP_3
# 107 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_TEMP_4
# 108 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_TEMP_5
# 109 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_TEMP_6
	end


JackJohnsonRoom_EventScript_OpenCurtain1::
# 114 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 115 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 116 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 117 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 119 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_5, 0
# 120 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_6, 0
# 121 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_7, 0
# 122 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_8, 0
# 123 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 124 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 125 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 126 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 127 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 128 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 129 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 130 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 131 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 132 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 133 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 134 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 135 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 137 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 141 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_5, 0
# 142 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_6, 0
# 143 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_7, 0
# 144 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_8, 0
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 146 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 147 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 148 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
# 149 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 150 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 151 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 152 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
# 153 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 154 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 155 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 156 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
# 157 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 158 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 159 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 160 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain2::
# 168 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 169 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 170 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 171 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 172 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_5, 0
# 173 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_6, 0
# 174 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_7, 0
# 175 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_8, 0
# 176 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_1, 0
# 177 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_2, 0
# 178 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_3, 0
# 179 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_4, 0
# 180 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_1, 0
# 181 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_2, 0
# 182 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_3, 0
# 183 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_4, 0
# 184 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_1, 0
# 185 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_2, 0
# 186 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_3, 0
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_4, 0
# 190 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 191 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 192 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 193 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 194 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_5, 0
# 195 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_6, 0
# 196 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_7, 0
# 197 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_8, 0
# 198 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_1, 0
# 199 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_2, 0
# 200 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_3, 0
# 201 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_4, 0
# 202 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_1, 0
# 203 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_2, 0
# 204 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_3, 0
# 205 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_4, 0
# 206 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_1, 0
# 207 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_2, 0
# 208 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_3, 0
# 209 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain3::
# 217 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 218 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 219 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 220 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 221 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_5, 0
# 222 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_6, 0
# 223 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_7, 0
# 224 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_8, 0
# 225 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_1, 0
# 226 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_2, 0
# 227 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_3, 0
# 228 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_4, 0
# 231 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 232 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 233 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 234 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_PAPER, 0
# 235 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_5, 0
# 236 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_6, 0
# 237 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_7, 0
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_8, 0
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_1, 0
# 240 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_2, 0
# 241 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_3, 0
# 242 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain4::
# 248 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_5, 0
# 249 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_6, 0
# 250 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_7, 0
# 251 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_8, 0
# 252 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_1, 0
# 253 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_2, 0
# 254 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_3, 0
# 255 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_4, 0
# 258 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_5, 0
# 259 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_6, 0
# 260 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_7, 0
# 261 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_8, 0
# 262 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_1, 0
# 263 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_2, 0
# 264 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_3, 0
# 265 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain5::
# 271 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_1, 0
# 272 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_2, 0
# 273 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_3, 0
# 274 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_4, 0
# 277 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_1, 0
# 278 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_2, 0
# 279 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_3, 0
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain::
# 285 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_TRUCK_UNLOAD
# 286 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain1
# 287 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 288 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 289 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain2
# 290 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 291 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 292 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain3
# 293 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 294 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 295 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain4
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 297 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 298 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain5
# 299 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 300 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
	return


JackJohnsonRoom_EventScript_TurnOnLights::
# 305 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_LEFT_LIGHT_FIXTURE_ON, 0
# 306 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_1, 0
# 307 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_2, 0
# 308 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_3, 0
# 309 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_4, 0
# 310 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_RIGHT_LIGHT_FIXTURE_ON, 0
# 311 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_1, 0
# 312 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_2, 0
# 313 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_3, 0
# 314 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_4, 0
# 315 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 316 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_M_ENCORE
	return


JackJohnsonRoom_OnFrame::
# 321 "data/maps/JackJohnsonRoom/scripts.pory"
	special ShowMapNamePopup
# 322 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 323 "data/maps/JackJohnsonRoom/scripts.pory"
	special SpawnCameraObject
# 324 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 325 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 326 "data/maps/JackJohnsonRoom/scripts.pory"
	special HideMapNamePopUpWindow
# 327 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 328 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkInPlaceUp
# 329 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 330 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 331 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain
# 332 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 333 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkInPlaceUp
# 334 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 335 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkInPlaceDown
# 336 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkInPlaceDown
# 337 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkInPlaceDown
# 338 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkInPlaceDown
# 339 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 340 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 341 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 342 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_TurnOnLights
# 343 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 344 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 345 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkLeftLockFacingDirection
# 346 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkRightLockFacingDirection
# 347 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkLeftLockFacingDirection
# 348 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkRightLockFacingDirection
# 349 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 350 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 10
# 351 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkDownLockFacingDirection
# 352 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkDownLockFacingDirection
# 353 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkUpLockFacingDirection
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkUpLockFacingDirection
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 356 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 357 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 358 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 359 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 360 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 361 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 362 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_JumpDownLockFacingDirection
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpUpLockFacingDirection
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpInPlaceLeft
# 365 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_JumpInPlaceRight
# 366 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC3
# 367 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpDownFaceLeft
# 368 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpDownFaceRight
# 369 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 370 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 371 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 372 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 373 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 374 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 375 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 376 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 377 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 378 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 379 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 380 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 381 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 382 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 383 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 384 "data/maps/JackJohnsonRoom/scripts.pory"
	release
# 385 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 386 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_0
# 387 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 388 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 389 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_LEDGE
# 390 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_1
# 394 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 395 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 396 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 397 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 398 "data/maps/JackJohnsonRoom/scripts.pory"
	lock
# 399 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_FaceLeft
# 400 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkDown
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_2
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_3
# 403 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 404 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 405 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_JumpRoundNpc1
# 406 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_JumpRoundNpc3
# 407 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_JumpRoundNpc4
# 408 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_JumpRoundNpc2
# 409 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_4
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_5
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_6
# 413 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_7
# 414 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC1
# 415 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_FACE_DOWN
# 416 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_FACE_DOWN
# 417 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_FACE_DOWN
# 418 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_FACE_DOWN
# 419 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 420 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 421 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 422 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 423 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_TEMP_2
# 424 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_TEMP_3
# 425 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC3_BALL
# 426 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC4_BALL
# 427 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC3_BALL, MAP_JACK_JOHNSON_ROOM
# 428 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC4_BALL, MAP_JACK_JOHNSON_ROOM
# 429 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3_BALL, Common_Movement_WalkDiagSouthEast
# 430 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4_BALL, Common_Movement_WalkDiagSouthEast
# 431 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 432 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 433 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 434 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC3_BALL
# 435 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC4_BALL
# 436 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_TEMP_4
# 437 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_TEMP_5
# 438 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_LEFT
# 439 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_RIGHT
# 440 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 441 "data/maps/JackJohnsonRoom/scripts.pory"
	playmoncry SPECIES_SPOINK, CRY_MODE_NORMAL
# 442 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_LEFT, JackJohnsonRoom_Movement_SpoinkHighJump
# 443 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_RIGHT, JackJohnsonRoom_Movement_SpoinkHighJump
# 444 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 445 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 446 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_SPOINK_LEFT
# 447 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_SPOINK_RIGHT
# 448 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 449 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_8
# 453 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_9
# 459 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_10
# 465 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_11
# 471 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC4
# 472 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_TEMP_1
# 473 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC1_BALL
# 474 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC1_BALL, MAP_JACK_JOHNSON_ROOM
# 475 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1_BALL, Common_Movement_WalkDiagSouthEast
# 476 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 477 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 478 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 479 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC1_BALL
# 480 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_TEMP_6
# 481 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_ELECTRODE
# 482 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 483 "data/maps/JackJohnsonRoom/scripts.pory"
	playmoncry SPECIES_ELECTRODE, CRY_MODE_NORMAL
# 484 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmoncry
# 485 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 486 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_12
# 491 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_13
# 496 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_14
# 501 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_15
# 506 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	setweather WEATHER_NONE
# 510 "data/maps/JackJohnsonRoom/scripts.pory"
	doweather
# 511 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_RESULT, 2
# 512 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_ORB
# 513 "data/maps/JackJohnsonRoom/scripts.pory"
	special DoOrbEffect
# 514 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 515 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 516 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8006, 8
# 517 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 518 "data/maps/JackJohnsonRoom/scripts.pory"
	special ShakeCamera
# 519 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 520 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_16
# 526 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 527 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 528 "data/maps/JackJohnsonRoom/scripts.pory"
	special FadeOutOrbEffect
# 529 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 530 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 531 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_M_EXPLOSION
# 532 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_ELECTRODE
# 533 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 534 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 535 "data/maps/JackJohnsonRoom/scripts.pory"
	getobjectxy LOCALID_JACKROOM_JACK, CURRENT_POSITION, VAR_TEMP_C, VAR_TEMP_D
# 536 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_C, VAR_TEMP_D
# 537 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 538 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 539 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_DoubleExclamationMarkWithDelay48
# 540 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 541 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 542 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_WalkUp6
# 543 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp6
# 544 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 545 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_WEST
# 546 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 547 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 548 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_NPC2, Common_Movement_SadWithDelay48
# 549 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 550 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_17
# 555 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_12, speaker = SP_NAME_JACK_JOHNSON
# 556 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_SOUTH
# 557 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 558 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_ExclamationMarkWithDelay48
# 559 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 560 "data/maps/JackJohnsonRoom/scripts.pory"
	playbgm MUS_WI_TRAINER_BATTLE, FALSE
# 561 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_CAMERA, JackJohnsonRoom_OnFrame_Movement_18
# 563 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_19
# 564 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 565 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_14, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 566 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_PLAYER, Common_Movement_WalkUp3
# 567 "data/maps/JackJohnsonRoom/scripts.pory"
	special RemoveCameraObject
# 568 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_15, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 569 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 570 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_20
# 571 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 572 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_JackBattle
# 574 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 575 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 576 "data/maps/JackJohnsonRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 577 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkUp
# 578 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 579 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 580 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 581 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 582 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 583 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 584 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 585 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 586 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 587 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 588 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_JACK_JOHNSON
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	release
	end


# 593 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SpoinkHighJump:
# 594 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
# 595 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_up
# 596 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_down
# 597 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
	step_end

# 600 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc1:
# 601 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 601 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 601 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 602 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 603 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 603 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 603 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 604 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 604 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 605 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 605 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 605 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 606 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 609 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc3:
# 610 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 611 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 612 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 613 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 613 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 613 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 613 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 614 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 614 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 614 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 615 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_left
# 616 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 616 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 617 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 618 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 618 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 619 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 622 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc4:
# 623 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 624 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 626 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 627 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 628 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 628 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 628 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 629 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 629 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 630 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 631 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 632 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 632 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 633 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 634 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 635 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 638 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc2:
# 639 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 639 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 640 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 642 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 642 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 643 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 644 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 644 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 645 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 646 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_3_left
# 647 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 648 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 649 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 650 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_up
# 651 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 655 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc1And3:
# 656 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right
# 657 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 658 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 659 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 660 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 661 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
	step_end

# 664 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc2And4:
# 665 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 666 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 667 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 668 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 669 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 670 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 673 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SecondCombinationNpcs:
# 674 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 674 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 675 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 675 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 676 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 676 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 677 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 677 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 678 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down
	step_end

JackJohnsonRoom_EventScript_JackBattle::
# 682 "data/maps/JackJohnsonRoom/scripts.pory"
	goto_if_unset FLAG_WAH_CHALLENGE_COMPLETED, JackJohnsonRoom_EventScript_JackBattle_2
# 685 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8004, TEAM_INDEX_JACK_JOHNSON
# 686 "data/maps/JackJohnsonRoom/scripts.pory"
	special ShouldUseAlternativeTeam
# 687 "data/maps/JackJohnsonRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq JackJohnsonRoom_EventScript_JackBattle_5
# 690 "data/maps/JackJohnsonRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_JACK_JOHNSON_ALTERNATIVE, JackJohnsonRoom_Text_JackDefeated
JackJohnsonRoom_EventScript_JackBattle_1:
# 693 "data/maps/JackJohnsonRoom/scripts.pory"
	special HealPlayerParty
	return

JackJohnsonRoom_EventScript_JackBattle_2:
# 683 "data/maps/JackJohnsonRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN, JackJohnsonRoom_Text_JackDefeated
	goto JackJohnsonRoom_EventScript_JackBattle_1

JackJohnsonRoom_EventScript_JackBattle_5:
# 688 "data/maps/JackJohnsonRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN, JackJohnsonRoom_Text_JackDefeated
	goto JackJohnsonRoom_EventScript_JackBattle_1


JackJohnsonRoom_EventScript_Jack::
# 702 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_LEDGE
# 703 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_EventScript_Jack_Movement_0
# 704 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 705 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 706 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_LEDGE
# 707 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_EventScript_Jack_Movement_0
# 708 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 709 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 710 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_Jack_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 711 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 712 "data/maps/JackJohnsonRoom/scripts.pory"
	faceplayer
# 713 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_Jack_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 714 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_NORTH
	end


JackJohnsonRoom_EventScript_NPC1::
# 719 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC1_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_NPC2::
# 724 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC2_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_NPC3::
# 729 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC3_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_NPC4::
# 734 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC4_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_BrockPoster::
# 739 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_BrockPoster_Text_0, MSGBOX_SIGN
	end


# 386 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_0:
# 386 "data/maps/JackJohnsonRoom/scripts.pory"
	emote_happy
	step_end

# 390 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_1:
# 391 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up
# 392 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 392 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

# 401 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_2:
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 402 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_3:
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 410 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_4:
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
	step_end

# 411 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_5:
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 412 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_6:
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 413 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_7:
# 413 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 413 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 413 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 449 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_8:
# 450 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 451 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 451 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 451 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 452 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 453 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_9:
# 454 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 455 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
# 456 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 457 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 458 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 459 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_10:
# 460 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 460 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 461 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
# 462 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 463 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 463 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 464 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 465 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_11:
# 466 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 466 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 467 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
# 468 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 469 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 469 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 470 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 486 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_12:
# 487 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 488 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 488 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 489 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 491 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_13:
# 492 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 493 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_left
# 493 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_left
# 494 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 496 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_14:
# 497 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 498 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_right
# 498 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_right
# 499 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 501 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_15:
# 502 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 503 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 503 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 504 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 520 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_16:
# 521 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
# 522 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 523 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 524 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 550 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_17:
# 551 "data/maps/JackJohnsonRoom/scripts.pory"
	face_up
# 552 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 553 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 562 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_18:
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
	step_end

# 563 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_19:
# 563 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 563 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 563 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 563 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

# 570 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_20:
# 570 "data/maps/JackJohnsonRoom/scripts.pory"
	emote_versus
	step_end

# 703 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_EventScript_Jack_Movement_0:
# 703 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up
	step_end

JackJohnsonRoom_OnFrame_Text_0:
# 327 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Es hora de comenzar el ensayo…\n"
	.string "¡Cortinas!$"

JackJohnsonRoom_OnFrame_Text_1:
# 332 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Desde el principio! ¡Quiero que cada\n"
	.string "movimiento sea perfecto!$"

JackJohnsonRoom_OnFrame_Text_2:
# 341 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Luces!$"

JackJohnsonRoom_OnFrame_Text_3:
# 344 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Empecemos!$"

JackJohnsonRoom_OnFrame_Text_4:
# 356 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Uno, dos… salto ya!$"

JackJohnsonRoom_OnFrame_Text_5:
# 370 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Giro! ¡Más energía, que parezca un\n"
	.string "huracán!$"

JackJohnsonRoom_OnFrame_Text_6:
# 395 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Perfecto! ¡Lo hemos clavado!$"

JackJohnsonRoom_OnFrame_Text_7:
# 397 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Formación!$"

JackJohnsonRoom_OnFrame_Text_8:
# 404 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Ahora!$"

JackJohnsonRoom_OnFrame_Text_9:
# 485 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Preparados para la detonación\n"
	.string "elegante!$"

JackJohnsonRoom_OnFrame_Text_10:
# 540 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Alto!$"

JackJohnsonRoom_OnFrame_Text_11:
# 546 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Qué estabas haciendo? Ya viste como\n"
	.string "es esto: una distracción y a volar.$"

JackJohnsonRoom_OnFrame_Text_12:
# 555 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Estuvo cerca… muy cerca, pero hasta\n"
	.string "que salga impecable, no descansaremos.$"

JackJohnsonRoom_OnFrame_Text_13:
# 561 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Y tú? ¿Qué haces ahí parado?$"

JackJohnsonRoom_OnFrame_Text_14:
# 565 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Ven aquí inmediatamente!$"

JackJohnsonRoom_OnFrame_Text_15:
# 568 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Si no vas a unirte al ensayo… voy a\n"
	.string "tener que retarte a un combate.$"

JackJohnsonRoom_OnFrame_Text_16:
# 575 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Magnífico… impecable. Cada movimiento\n"
	.string "ha caído en su sitio, es un placer ver\l"
	.string "algo tan bien ejecutado…\p"
	.string "No suelo disfrutar perdiendo, pero…\n"
	.string "esto ha sido arte puro.\p"
	.string "Te abriré el camino.$"

JackJohnsonRoom_OnFrame_Text_17:
# 578 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Y ustedes… ¡a trabajar!$"

JackJohnsonRoom_EventScript_Jack_Text_0:
# 710 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Eso es! ¡Más rápido!$"

JackJohnsonRoom_EventScript_Jack_Text_1:
# 713 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Sigues ahí? Pues venga, no te quedes\n"
	.string "mirando…\l"
	.string "¡Súmate al ensayo!$"

JackJohnsonRoom_EventScript_NPC1_Text_0:
# 719 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Debemos ser los mejores!$"

JackJohnsonRoom_EventScript_NPC2_Text_0:
# 724 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡No puedo fallar de nuevo!$"

JackJohnsonRoom_EventScript_NPC3_Text_0:
# 729 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡No me distraigas!$"

JackJohnsonRoom_EventScript_NPC4_Text_0:
# 734 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Quiero ir a dormir!$"

JackJohnsonRoom_EventScript_BrockPoster_Text_0:
# 739 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Es un poster con una foto de Oscar\n"
	.string "Brock.\p"
	.string "¿Realmente tiene esos músculos o será\n"
	.string "Photoshop?$"

JackJohnsonRoom_Text_JackDefeated::
# 697 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Has tomado el mando, enhorabuena.$"
