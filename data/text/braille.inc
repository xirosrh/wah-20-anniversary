@ NOTE: The brailleformat macro in this file is leftover from RS.
@       The numbers are simply skipped over. If you'd like to omit
@       this macro you must also stop it from skipping over this
@       section by editing ScrCmd_braillemessage.

@ For some reason esp version uses 0x3F character before commans and periods(which are actually 0x10 - ')

Underwater_SealedChamber_Braille_GoUpHere::
	brailleformat 4, 6, 26, 13, 7, 9
	.braille "GO UP HERE"
	.byte 0x3F
	.braille "'$"

SealedChamber_OuterRoom_Braille_ABC:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "ABC$"

SealedChamber_OuterRoom_Braille_GHI:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "GHI$"

SealedChamber_OuterRoom_Braille_MNO:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "MNO$"

SealedChamber_OuterRoom_Braille_TUV:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "TUV$"

SealedChamber_OuterRoom_Braille_DEF:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "DEF$"

SealedChamber_OuterRoom_Braille_JKL:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "JKL$"

SealedChamber_OuterRoom_Braille_PQRS:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "PQRS$"

SealedChamber_OuterRoom_Braille_Period:
	brailleformat 9, 6, 19, 13, 12, 9
	.byte 0x3F
	.braille "'$"

SealedChamber_OuterRoom_Braille_WXYZ:
	brailleformat 7, 6, 21, 13, 10, 9
	.braille "WXYZ$"

SealedChamber_OuterRoom_Braille_Comma:
	brailleformat 9, 6, 19, 13, 12, 9
	.byte 0x3F
	.braille ",$"

SealedChamber_OuterRoom_Braille_DigHere:
	brailleformat 7, 4, 23, 15, 10, 7
	.braille "DIG HERE"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_FirstWailordLastRelicanth:
	brailleformat 0, 0, 29, 19, 3, 3
	.braille "FIRST\n"
	.braille "WAILORD"
	.byte 0x3F
	.braille "'\n"
	.braille "LAST\n"
	.braille "RELICANTH"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_InThisCaveWeHaveLived:
	brailleformat 2, 0, 26, 19, 5, 3
	.braille "THIS CAVE\n"
	.braille "HAS BEEN\n"
	.braille "OUR\n"
	.braille "HOME"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_WeOweAllToThePokemon:
	brailleformat 7, 2, 23, 17, 10, 5
	.braille "WHAT WE ARE"
	.byte 0x3F
	.braille ",\n"
	.braille "WE OWE IT\n"
	.braille "TO THE\n"
	.braille "POKEMON"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_ButWeSealedThePokemonAway:
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "BUT WE\n"
	.braille "SEALED THEM\n"
	.braille "AWAY FOR\n"
	.braille "EVER"
	.byte 0x3F, 0x10
	.braille "$"

SealedChamber_InnerRoom_Braille_WeFearedIt:
	brailleformat 5, 6, 25, 13, 8, 9
	.braille "WE FELT\n"
	.braille "FEAR"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_ThoseWithCourageHope:
	brailleformat 6, 0, 24, 19, 9, 3
	.braille "THOSE WHO\n"
	.braille "POSSESS\n"
	.braille "COURAGE AND\n"
	.braille "HOPE"
	.byte 0x3F
	.braille "'$"

SealedChamber_InnerRoom_Braille_OpenDoorEternalPokemonWaits:
	brailleformat 3, 2, 27, 17, 6, 5
	.braille "OPEN THE\n"
	.braille "DOOR TO\n"
	.braille "AN ETERNAL\n"
	.braille "POKEMON"
	.byte 0x3F
	.braille "'$"

DesertRuins_Braille_UseRockSmash:
	brailleformat 1, 0, 27, 19, 4, 3
	.braille "LEFT"
	.byte 0x3F
	.braille "' LEFT"
	.byte 0x3F
	.braille "'\n"
	.braille "DOWN DOWN"
	.byte 0x3F
	.braille "'\n"
	.braille "THEN"
	.byte 0x3F
	.braille ", USE\n"
	.braille "ROCK SMASH"
	.byte 0x3F
	.braille "'$"

IslandCave_Braille_RunLapAroundWall:
	brailleformat 5, 0, 25, 19, 8, 3
	.braille "STAND BY\n"
	.braille "THE WALL"
	.byte 0x3F
	.braille "'\n"
	.braille "RUN ONE LAP\n"
	.braille "AROUND"
	.byte 0x3F
	.braille "'$"

AncientTomb_Braille_ShineInTheMiddle:
	brailleformat 3, 0, 25, 19, 6, 3
	.braille "THOSE WHO WISH\n"
	.braille "LIKE WE DO"
	.byte 0x3F
	.braille ",\n"
	.braille "SHINE\n"
	.braille "IN THE MIDDLE"
	.byte 0x3F
	.braille "'$"
