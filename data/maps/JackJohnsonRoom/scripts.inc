JackJohnsonRoom_MapScripts::
# 5 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JackJohnsonRoom_OnTransition
# 6 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JackJohnsonRoom_OnLoad
# 2 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

JackJohnsonRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 3 "data/maps/JackJohnsonRoom/scripts.pory"
	map_script_2 VAR_JACK_JOHNSON_ROOM_STATE, 0, JackJohnsonRoom_OnFrame
	.2byte 0


JackJohnsonRoom_OnLoad::
# 10 "data/maps/JackJohnsonRoom/scripts.pory"
	compare VAR_JACK_JOHNSON_ROOM_STATE, 0
	goto_if_eq JackJohnsonRoom_OnLoad_1
	return

JackJohnsonRoom_OnLoad_1:
# 12 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 5, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_1, 0
# 13 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 6, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_2, 0
# 14 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 7, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_3, 0
# 15 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 8, METATILE_Room_Jack_Johnson_CURTAIN_MIDDLE_4, 0
# 17 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 18 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 19 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 20 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 21 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 22 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 23 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 24 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 25 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 26 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 27 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 28 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 29 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 30 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 31 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 32 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 33 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_1, 0
# 34 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_2, 0
# 35 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_3, 0
# 36 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME1_4, 0
# 39 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 40 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 41 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 42 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 43 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 44 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 45 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 46 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 47 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 48 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 49 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 50 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 51 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 52 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 53 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 54 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
# 55 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_1, 0
# 56 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_2, 0
# 57 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_3, 0
# 58 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME1_4, 0
	return


JackJohnsonRoom_OnTransition::
# 64 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_NPC1_BALL
# 65 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_NPC3_BALL
# 66 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_NPC4_BALL
# 67 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_SPOINK_LEFT
# 68 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_SPOINK_RIGHT
# 69 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_JACKROOM_HIDE_ELECTRODE
	end


JackJohnsonRoom_EventScript_OpenCurtain1::
# 74 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 75 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 76 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 77 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 6, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 79 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_5, 0
# 80 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_6, 0
# 81 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_7, 0
# 82 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_8, 0
# 83 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 84 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 85 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 86 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 87 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 88 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 89 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 90 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 91 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 92 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 93 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 94 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 95 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_1, 0
# 96 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_2, 0
# 97 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_3, 0
# 98 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME2_4, 0
# 101 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_5, 0
# 102 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_6, 0
# 103 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_7, 0
# 104 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_8, 0
# 105 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 106 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 107 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 108 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
# 109 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 110 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 111 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 112 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
# 113 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 114 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 115 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 116 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
# 117 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_1, 0
# 118 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_2, 0
# 119 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_3, 0
# 120 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME2_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain2::
# 128 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 129 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 130 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 131 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 132 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_5, 0
# 133 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_6, 0
# 134 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_7, 0
# 135 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_8, 0
# 136 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_1, 0
# 137 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_2, 0
# 138 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_3, 0
# 139 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_4, 0
# 140 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_1, 0
# 141 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_2, 0
# 142 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_3, 0
# 143 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_4, 0
# 144 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_1, 0
# 145 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_2, 0
# 146 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_3, 0
# 147 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME3_4, 0
# 150 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 151 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 152 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 153 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 154 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_5, 0
# 155 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_6, 0
# 156 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_7, 0
# 157 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_8, 0
# 158 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_1, 0
# 159 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_2, 0
# 160 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_3, 0
# 161 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_4, 0
# 162 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_1, 0
# 163 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_2, 0
# 164 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_3, 0
# 165 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_4, 0
# 166 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_1, 0
# 167 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_2, 0
# 168 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_3, 0
# 169 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME3_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain3::
# 177 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 178 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 179 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 180 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 8, METATILE_Room_Jack_Johnson_FLOOR, 0
# 181 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_5, 0
# 182 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_6, 0
# 183 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_7, 0
# 184 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_8, 0
# 185 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_1, 0
# 186 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_2, 0
# 187 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_3, 0
# 188 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME4_4, 0
# 191 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 5, METATILE_Room_Jack_Johnson_CURTAIN_ROD, 0
# 192 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_FLOOR, 0
# 193 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_FLOOR, 0
# 194 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 8, METATILE_Room_Jack_Johnson_PAPER, 0
# 195 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_5, 0
# 196 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_6, 0
# 197 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_7, 0
# 198 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_8, 0
# 199 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_1, 0
# 200 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_2, 0
# 201 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_3, 0
# 202 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME4_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain4::
# 208 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_5, 0
# 209 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_6, 0
# 210 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_7, 0
# 211 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 2, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_8, 0
# 212 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_1, 0
# 213 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_2, 0
# 214 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_3, 0
# 215 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME5_4, 0
# 218 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_5, 0
# 219 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_6, 0
# 220 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_7, 0
# 221 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 10, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_8, 0
# 222 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_1, 0
# 223 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_2, 0
# 224 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_3, 0
# 225 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME5_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain5::
# 231 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 5, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_1, 0
# 232 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 6, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_2, 0
# 233 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 7, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_3, 0
# 234 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 1, 8, METATILE_Room_Jack_Johnson_CURTAIN_LEFT_FRAME6_4, 0
# 237 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 5, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_1, 0
# 238 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 6, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_2, 0
# 239 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 7, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_3, 0
# 240 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 11, 8, METATILE_Room_Jack_Johnson_CURTAIN_RIGHT_FRAME6_4, 0
	return


JackJohnsonRoom_EventScript_OpenCurtain::
# 245 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain1
# 246 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 247 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 248 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain2
# 249 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 250 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 251 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain3
# 252 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 253 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 254 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain4
# 255 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 256 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
# 257 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain5
# 258 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
# 259 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 5
	return


JackJohnsonRoom_EventScript_TurnOnLights::
# 264 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 3, 6, METATILE_Room_Jack_Johnson_LEFT_LIGHT_FIXTURE_ON, 0
# 265 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_1, 0
# 266 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_2, 0
# 267 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 4, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_3, 0
# 268 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 5, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_4, 0
# 269 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 9, 6, METATILE_Room_Jack_Johnson_RIGHT_LIGHT_FIXTURE_ON, 0
# 270 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_1, 0
# 271 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 6, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_2, 0
# 272 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 7, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_3, 0
# 273 "data/maps/JackJohnsonRoom/scripts.pory"
	setmetatile 8, 7, METATILE_Room_Jack_Johnson_FLOOR_LIGHT_4, 0
# 274 "data/maps/JackJohnsonRoom/scripts.pory"
	special DrawWholeMapView
	return


JackJohnsonRoom_OnFrame::
# 279 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 280 "data/maps/JackJohnsonRoom/scripts.pory"
	special SpawnCameraObject
# 281 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 9
# 282 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 283 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 284 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkInPlaceUp
# 285 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtopos 6, 7
# 286 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 287 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_OpenCurtain
# 288 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 290 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkInPlaceUp
# 291 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 292 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkInPlaceDown
# 293 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkInPlaceDown
# 294 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkInPlaceDown
# 295 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkInPlaceDown
# 296 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 297 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 298 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_2, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 299 "data/maps/JackJohnsonRoom/scripts.pory"
	call JackJohnsonRoom_EventScript_TurnOnLights
# 300 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 301 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_3, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 302 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkLeftLockFacingDirection
# 303 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkRightLockFacingDirection
# 304 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkLeftLockFacingDirection
# 305 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkRightLockFacingDirection
# 306 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 307 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 10
# 308 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_WalkDownLockFacingDirection
# 309 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_WalkDownLockFacingDirection
# 310 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_WalkUpLockFacingDirection
# 311 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkUpLockFacingDirection
# 312 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 313 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_4, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 314 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 315 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_FirstCombinationNpc1And3
# 316 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 317 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_FirstCombinationNpc2And4
# 318 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 319 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_JumpDownLockFacingDirection
# 320 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpUpLockFacingDirection
# 321 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpInPlaceLeft
# 322 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, Common_Movement_JumpInPlaceRight
# 323 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC3
# 324 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_JumpDownFaceLeft
# 325 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, Common_Movement_JumpDownFaceRight
# 326 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_5, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 327 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 328 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 329 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 330 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_SecondCombinationNpcs
# 331 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 332 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 333 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 334 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 335 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 336 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 337 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 338 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 339 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 340 "data/maps/JackJohnsonRoom/scripts.pory"
	release
# 341 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 342 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_0
# 347 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_6, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 348 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 349 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 350 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_7, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 351 "data/maps/JackJohnsonRoom/scripts.pory"
	lock
# 352 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, Common_Movement_FaceLeft
# 353 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, Common_Movement_WalkDown
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_1
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_2
# 356 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 357 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_8, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 358 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_Movement_JumpRoundNpc1
# 359 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_Movement_JumpRoundNpc3
# 360 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_Movement_JumpRoundNpc4
# 361 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_Movement_JumpRoundNpc2
# 362 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC2
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_3
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_4
# 365 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_5
# 366 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_6
# 367 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC1
# 368 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_FACE_DOWN
# 369 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_FACE_DOWN
# 370 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_FACE_DOWN
# 371 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_FACE_DOWN
# 372 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 373 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 374 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 375 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 376 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_NPC3_BALL
# 377 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_NPC4_BALL
# 378 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC3_BALL
# 379 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC4_BALL
# 380 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC3_BALL, MAP_JACK_JOHNSON_ROOM
# 381 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC4_BALL, MAP_JACK_JOHNSON_ROOM
# 382 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3_BALL, Common_Movement_WalkDiagSouthEast
# 383 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4_BALL, Common_Movement_WalkDiagSouthEast
# 384 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 385 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 386 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 387 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC3_BALL
# 388 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC4_BALL
# 389 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_SPOINK_LEFT
# 390 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_SPOINK_RIGHT
# 391 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_LEFT
# 392 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_SPOINK_RIGHT
# 393 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 394 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_LEFT, JackJohnsonRoom_Movement_SpoinkHighJump
# 395 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_SPOINK_RIGHT, JackJohnsonRoom_Movement_SpoinkHighJump
# 396 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 397 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 398 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_SPOINK_LEFT
# 399 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_SPOINK_RIGHT
# 400 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 401 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_7
# 405 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_8
# 411 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_9
# 417 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_10
# 423 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement LOCALID_JACKROOM_NPC4
# 424 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_NPC1_BALL
# 425 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_NPC1_BALL
# 426 "data/maps/JackJohnsonRoom/scripts.pory"
	showobjectat LOCALID_JACKROOM_NPC1_BALL, MAP_JACK_JOHNSON_ROOM
# 427 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1_BALL, Common_Movement_WalkDiagSouthEast
# 428 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 429 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_BALL_OPEN
# 430 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 431 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_NPC1_BALL
# 432 "data/maps/JackJohnsonRoom/scripts.pory"
	clearflag FLAG_JACKROOM_HIDE_ELECTRODE
# 433 "data/maps/JackJohnsonRoom/scripts.pory"
	addobject LOCALID_JACKROOM_ELECTRODE
# 434 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 435 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_9, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 436 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC1, JackJohnsonRoom_OnFrame_Movement_11
# 441 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC4, JackJohnsonRoom_OnFrame_Movement_12
# 446 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC3, JackJohnsonRoom_OnFrame_Movement_13
# 451 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_14
# 456 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 458 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 459 "data/maps/JackJohnsonRoom/scripts.pory"
	setweather WEATHER_NONE
# 460 "data/maps/JackJohnsonRoom/scripts.pory"
	doweather
# 461 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_RESULT, 2
# 462 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_ORB
# 463 "data/maps/JackJohnsonRoom/scripts.pory"
	special DoOrbEffect
# 464 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8004, 1
# 465 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8005, 1
# 466 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8006, 8
# 467 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_0x8007, 5
# 468 "data/maps/JackJohnsonRoom/scripts.pory"
	special ShakeCamera
# 469 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 470 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_NPC2, JackJohnsonRoom_OnFrame_Movement_15
# 476 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 477 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 30
# 478 "data/maps/JackJohnsonRoom/scripts.pory"
	special FadeOutOrbEffect
# 479 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_TO_WHITE
# 480 "data/maps/JackJohnsonRoom/scripts.pory"
	removeobject LOCALID_JACKROOM_ELECTRODE
# 481 "data/maps/JackJohnsonRoom/scripts.pory"
	waitstate
# 482 "data/maps/JackJohnsonRoom/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 483 "data/maps/JackJohnsonRoom/scripts.pory"
	getobjectxy LOCALID_JACKROOM_JACK, CURRENT_POSITION, VAR_TEMP_C, VAR_TEMP_D
# 484 "data/maps/JackJohnsonRoom/scripts.pory"
	directcameramovementtoposwithvars VAR_TEMP_C, VAR_TEMP_D
# 485 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 486 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 487 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_DoubleExclamationMarkWithDelay48
# 488 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_10, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 489 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 490 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_WalkUp6
# 491 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp6
# 492 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 493 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_WEST
# 494 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_11, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 495 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 496 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_NPC2, Common_Movement_SadWithDelay48
# 497 "data/maps/JackJohnsonRoom/scripts.pory"
	waitse
# 498 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_16
# 503 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_12, speaker = SP_NAME_JACK_JOHNSON
# 504 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_SOUTH
# 505 "data/maps/JackJohnsonRoom/scripts.pory"
	playse SE_PIN
# 506 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_ExclamationMarkWithDelay48
# 507 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_13, MSGBOX_AUTOCLOSE
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_CAMERA, JackJohnsonRoom_OnFrame_Movement_17
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, JackJohnsonRoom_OnFrame_Movement_18
# 510 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 511 "data/maps/JackJohnsonRoom/scripts.pory"
	special RemoveCameraObject
# 512 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_14, speaker = SP_NAME_JACK_JOHNSON
# 513 "data/maps/JackJohnsonRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_WAH_ADMIN_JACK_JOHNSON_MAIN, JackJohnsonRoom_OnFrame_Text_15
# 514 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC2, 3, 6
# 515 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC4, 5, 6
# 516 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC3, 7, 6
# 517 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxy LOCALID_JACKROOM_NPC1, 9, 6
# 518 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC2, 3, 6
# 519 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC4, 5, 6
# 520 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC3, 7, 6
# 521 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectxyperm LOCALID_JACKROOM_NPC1, 9, 6
# 522 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 523 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_16, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 524 "data/maps/JackJohnsonRoom/scripts.pory"
	call WahRoomsShared_OpenDoor
# 525 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovementandwait LOCALID_JACKROOM_JACK, Common_Movement_WalkUp4
# 526 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_OnFrame_Text_17, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 527 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC1, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 528 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC2, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 529 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC3, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 530 "data/maps/JackJohnsonRoom/scripts.pory"
	setobjectmovementtype2 LOCALID_JACKROOM_NPC4, MOVEMENT_TYPE_WALK_IN_PLACE_DOWN
# 531 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC1, DIR_SOUTH
# 532 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC2, DIR_SOUTH
# 533 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC3, DIR_SOUTH
# 534 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_NPC4, DIR_SOUTH
# 535 "data/maps/JackJohnsonRoom/scripts.pory"
	setvar VAR_JACK_JOHNSON_ROOM_STATE, 1
# 536 "data/maps/JackJohnsonRoom/scripts.pory"
	setflag FLAG_DEFEATED_ADMIN_JACK_JOHNSON
# 537 "data/maps/JackJohnsonRoom/scripts.pory"
	release
	end


# 541 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SpoinkHighJump:
# 542 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
# 543 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_up
# 544 "data/maps/JackJohnsonRoom/scripts.pory"
	fly_down
# 545 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_down
	step_end

# 548 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc1:
# 549 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 549 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 549 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 550 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 551 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 551 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 551 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 552 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 552 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 553 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 553 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 553 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 554 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 557 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc3:
# 558 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 559 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 560 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 561 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 561 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 561 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 561 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 562 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 563 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_left
# 564 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 564 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 565 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 566 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 566 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 567 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 570 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc4:
# 571 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 572 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 573 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 574 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 575 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 576 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 576 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 576 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 577 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 577 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 578 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 579 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 580 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 580 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 581 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 582 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 583 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 586 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_JumpRoundNpc2:
# 587 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 587 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 588 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 589 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 590 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 590 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 591 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_left
# 592 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 592 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 593 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 594 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_3_left
# 595 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 596 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 597 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 598 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_in_place_up
# 599 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 603 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc1And3:
# 604 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right
# 605 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 606 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 607 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 608 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_right
# 609 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
	step_end

# 612 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_FirstCombinationNpc2And4:
# 613 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left
# 614 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 615 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 616 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 617 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 618 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 621 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_Movement_SecondCombinationNpcs:
# 622 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 622 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up_down
# 623 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 623 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_left_right
# 624 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 624 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down_up
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 625 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_right_left
# 626 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_down
	step_end

JackJohnsonRoom_EventScript_Jack::
# 630 "data/maps/JackJohnsonRoom/scripts.pory"
	applymovement LOCALID_JACKROOM_JACK, Common_Movement_JumpInPlaceUp2
# 631 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_Jack_Text_0, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 632 "data/maps/JackJohnsonRoom/scripts.pory"
	waitmovement 0
# 633 "data/maps/JackJohnsonRoom/scripts.pory"
	delay 20
# 634 "data/maps/JackJohnsonRoom/scripts.pory"
	faceplayer
# 635 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_Jack_Text_1, MSGBOX_AUTOCLOSE, speaker = SP_NAME_JACK_JOHNSON
# 636 "data/maps/JackJohnsonRoom/scripts.pory"
	turnobject LOCALID_JACKROOM_JACK, DIR_NORTH
	end


JackJohnsonRoom_EventScript_NPC1::
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC1_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_NPC2::
# 646 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC2_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_NPC3::
# 651 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC3_Text_0, MSGBOX_AUTOCLOSE
	end


JackJohnsonRoom_EventScript_NPC4::
# 656 "data/maps/JackJohnsonRoom/scripts.pory"
	msgbox JackJohnsonRoom_EventScript_NPC4_Text_0, MSGBOX_AUTOCLOSE
	end


# 342 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_0:
# 343 "data/maps/JackJohnsonRoom/scripts.pory"
	emote_happy
# 344 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_in_place_up
# 345 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 345 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

# 354 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_1:
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 354 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 355 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_2:
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 355 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 363 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_3:
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 363 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
	step_end

# 364 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_4:
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 364 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 365 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_5:
# 365 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 365 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 365 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 365 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 366 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_6:
# 366 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 366 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_up
# 366 "data/maps/JackJohnsonRoom/scripts.pory"
	face_down
	step_end

# 401 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_7:
# 402 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 403 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 403 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 403 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 404 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 405 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_8:
# 406 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 407 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
# 408 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 409 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 410 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 411 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_9:
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 412 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 413 "data/maps/JackJohnsonRoom/scripts.pory"
	face_left
# 414 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 415 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 415 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_right
# 416 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 417 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_10:
# 418 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 418 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_down
# 419 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
# 420 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 421 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 421 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_fast_left
# 422 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 436 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_11:
# 437 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 438 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 438 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_up
# 439 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 441 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_12:
# 442 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 443 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_left
# 443 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_left
# 444 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 446 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_13:
# 447 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 448 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_right
# 448 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_right
# 449 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 451 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_14:
# 452 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 453 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 453 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 454 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 470 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_15:
# 471 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
# 472 "data/maps/JackJohnsonRoom/scripts.pory"
	lock_facing_direction
# 473 "data/maps/JackJohnsonRoom/scripts.pory"
	jump_2_left
# 474 "data/maps/JackJohnsonRoom/scripts.pory"
	unlock_facing_direction
	step_end

# 498 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_16:
# 499 "data/maps/JackJohnsonRoom/scripts.pory"
	face_up
# 500 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
# 501 "data/maps/JackJohnsonRoom/scripts.pory"
	face_right
	step_end

# 508 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_17:
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 508 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
	step_end

# 509 "data/maps/JackJohnsonRoom/scripts.pory"
JackJohnsonRoom_OnFrame_Movement_18:
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	walk_down
# 509 "data/maps/JackJohnsonRoom/scripts.pory"
	delay_16
	step_end

JackJohnsonRoom_OnFrame_Text_0:
# 283 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Es hora de comenzar el ensayo…\n"
	.string "¡Cortinas!$"

JackJohnsonRoom_OnFrame_Text_1:
# 288 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Desde el principio! ¡Quiero que cada\n"
	.string "movimiento sea perfecto!$"

JackJohnsonRoom_OnFrame_Text_2:
# 298 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Luces!$"

JackJohnsonRoom_OnFrame_Text_3:
# 301 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Empecemos!$"

JackJohnsonRoom_OnFrame_Text_4:
# 313 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Uno, dos… salto ya!$"

JackJohnsonRoom_OnFrame_Text_5:
# 326 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Giro! ¡Más energía, que parezca un\n"
	.string "huracán!$"

JackJohnsonRoom_OnFrame_Text_6:
# 347 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Perfecto! ¡Lo hemos clavado!$"

JackJohnsonRoom_OnFrame_Text_7:
# 350 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Formación!$"

JackJohnsonRoom_OnFrame_Text_8:
# 357 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Ahora!$"

JackJohnsonRoom_OnFrame_Text_9:
# 435 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Preparados para la detonación\n"
	.string "elegante!$"

JackJohnsonRoom_OnFrame_Text_10:
# 488 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Alto!$"

JackJohnsonRoom_OnFrame_Text_11:
# 494 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Qué estabas haciendo? Ya viste como\n"
	.string "es esto: una distracción y a volar.$"

JackJohnsonRoom_OnFrame_Text_12:
# 503 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Estuvo cerca… muy cerca, pero hasta\n"
	.string "que salga impecable, no descansaremos.$"

JackJohnsonRoom_OnFrame_Text_13:
# 507 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Y tú? ¿Qué haces ahí parado?$"

JackJohnsonRoom_OnFrame_Text_14:
# 512 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Si no vas a unirte al ensayo… voy a\n"
	.string "tener que retarte a un combate.$"

JackJohnsonRoom_OnFrame_Text_15:
# 513 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Has tomado el mando, enhorabuena.$"

JackJohnsonRoom_OnFrame_Text_16:
# 523 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Magnífico… impecable. Cada movimiento\n"
	.string "ha caído en su sitio, es un placer ver\l"
	.string "algo tan bien ejecutado…\p"
	.string "No suelo disfrutar perdiendo, pero…\n"
	.string "esto ha sido arte puro.\p"
	.string "Te abriré el camino.$"

JackJohnsonRoom_OnFrame_Text_17:
# 526 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "Y ustedes… ¡a trabajar!$"

JackJohnsonRoom_EventScript_Jack_Text_0:
# 631 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Eso es! ¡Más rápido!$"

JackJohnsonRoom_EventScript_Jack_Text_1:
# 635 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¿Sigues ahí? Pues venga, no te quedes\n"
	.string "mirando…\l"
	.string "¡Súmate al ensayo!$"

JackJohnsonRoom_EventScript_NPC1_Text_0:
# 641 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Debemos ser los mejores!$"

JackJohnsonRoom_EventScript_NPC2_Text_0:
# 646 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡No puedo fallar de nuevo!$"

JackJohnsonRoom_EventScript_NPC3_Text_0:
# 651 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡No me distraigas!$"

JackJohnsonRoom_EventScript_NPC4_Text_0:
# 656 "data/maps/JackJohnsonRoom/scripts.pory"
	.string "¡Quiero ir a dormir!$"
