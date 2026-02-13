//--------------------------------------------------------------
// Acimut's Instruments HQ 21024Hz
//--------------------------------------------------------------

// PIANO

const u8 KeySplit_FE7_Piano[] =
{
    SPLIT(NOTE_CN , NOTE_D2, SAMPLE_0),
    SPLIT(NOTE_DS2, NOTE_G2, SAMPLE_1),
    SPLIT(NOTE_GS2, NOTE_D3, SAMPLE_2),
    SPLIT(NOTE_DS3, NOTE_B3, SAMPLE_3),
    SPLIT(NOTE_C4 , NOTE_G4, SAMPLE_4),
    SPLIT(NOTE_GS4, NOTE_D5, SAMPLE_5),
    SPLIT(NOTE_DS5, NOTE_A5, SAMPLE_6),
    SPLIT(NOTE_AS5, NOTE_E6, SAMPLE_7),
    SPLIT(NOTE_F6 , NOTE_CS7, SAMPLE_8),
    SPLIT(NOTE_D7 , NOTE_G9, SAMPLE_9),
};

//copia de piano de FE7
const struct Instrument FE7_AcousticGrandPiano[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_37, 255, 254, 0, 235),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_40, 255, 254, 0, 235),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_47, 255, 254, 0, 235),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_55, 255, 254, 0, 235),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_63, 255, 254, 0, 235),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_72, 255, 254, 0, 235),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_77, 255, 254, 0, 235),
    [SAMPLE_7] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_83, 255, 254, 0, 235),
    [SAMPLE_8] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_91, 255, 254, 0, 235),
    [SAMPLE_9] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_FE7000_piano_102, 255, 254, 0, 235),
};

// CHROMATIC PERCUSION

const struct Instrument Instrument_AGM_Celesta[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_60, 220, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_60, 220, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_72, 220, 0, 255, 192),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_84, 220, 0, 255, 192),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_96, 220, 0, 255, 192),
};

const struct Instrument Instrument_AGM_Vibraphone[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_60, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_60, 255, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_72, 255, 0, 255, 192),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_84, 255, 0, 255, 192),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_011_Vibraphone_96, 255, 0, 255, 192),
};

const struct Instrument Instrument_AGM_Marimba[] =
{
    [SAMPLE_0]  = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_012_Marimba_48, 255, 0, 255, 250),
    [SAMPLE_1]  = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_012_Marimba_60, 255, 0, 255, 250),
    [SAMPLE_2]  = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_012_Marimba_72, 255, 0, 255, 250),
    [SAMPLE_3]  = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_012_Marimba_84, 255, 0, 255, 250),
    [SAMPLE_4]  = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_012_Marimba_96, 255, 0, 255, 250),
};

// ORGAN

// GUITAR

const u8 KeySplit_AGM_Guitar[] =
{
    SPLIT(NOTE_CN , NOTE_GS2, SAMPLE_0),
    SPLIT(NOTE_A2 , NOTE_FS3, SAMPLE_1),
    SPLIT(NOTE_G3 , NOTE_DS4, SAMPLE_2),
    SPLIT(NOTE_E4 , NOTE_CS5, SAMPLE_3),
    SPLIT(NOTE_D5 , NOTE_GS5, SAMPLE_4),
    SPLIT(NOTE_A5 , NOTE_G9 , SAMPLE_5),
};

const struct Instrument Instrument_AGM_Acoustic_Guitar_Nylon[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_024_Acoustic_Guitar_Nylon_40, 255, 0, 255, 208),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_024_Acoustic_Guitar_Nylon_50, 255, 0, 255, 208),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_024_Acoustic_Guitar_Nylon_59, 255, 0, 255, 208),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_024_Acoustic_Guitar_Nylon_69, 255, 0, 255, 208),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_024_Acoustic_Guitar_Nylon_76, 255, 0, 255, 208),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_024_Acoustic_Guitar_Nylon_84, 255, 0, 255, 208),
};

const struct Instrument Instrument_AGM_Acoustic_Guitar_Steel[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_025_Acoustic_Guitar_Steel_40, 255, 0, 255, 208),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_025_Acoustic_Guitar_Steel_50, 255, 0, 255, 208),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_025_Acoustic_Guitar_Steel_59, 255, 0, 255, 208),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_025_Acoustic_Guitar_Steel_69, 255, 0, 255, 208),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_025_Acoustic_Guitar_Steel_76, 255, 0, 255, 208),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_025_Acoustic_Guitar_Steel_84, 255, 0, 255, 208),
};

const u8 KeySplit_AGM_Electric_Guitar_Jazz[] =
{
    SPLIT(NOTE_CN , NOTE_E2 , SAMPLE_0),
    SPLIT(NOTE_F2 , NOTE_B2 , SAMPLE_1),
    SPLIT(NOTE_C3 , NOTE_F3 , SAMPLE_2),
    SPLIT(NOTE_FS3, NOTE_C4 , SAMPLE_3),
    SPLIT(NOTE_CS4, NOTE_G4 , SAMPLE_4),
    SPLIT(NOTE_GS4, NOTE_D5 , SAMPLE_5),
    SPLIT(NOTE_DS5, NOTE_G9 , SAMPLE_6),
};

const struct Instrument Instrument_AGM_Electric_Guitar_Jazz[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_40, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_47, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_53, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_60, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_67, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_74, 255, 0, 255, 165),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_026_Electric_Guitar_Jazz_83, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_OverdrivenGuitar[] =
{
    SPLIT(NOTE_CN , NOTE_FS2, SAMPLE_0),
    SPLIT(NOTE_G2 , NOTE_C3 , SAMPLE_1),
    SPLIT(NOTE_CS3, NOTE_FS3, SAMPLE_2),
    SPLIT(NOTE_G3 , NOTE_C4 , SAMPLE_3),
    SPLIT(NOTE_CS4, NOTE_FS4, SAMPLE_4),
    SPLIT(NOTE_G4 , NOTE_C5 , SAMPLE_5),
    SPLIT(NOTE_CS5, NOTE_FS5, SAMPLE_6),
    SPLIT(NOTE_G5 , NOTE_C6 , SAMPLE_7),
    SPLIT(NOTE_CS6, NOTE_FS6, SAMPLE_8),
    SPLIT(NOTE_G6 , NOTE_G9 , SAMPLE_9),
};

const struct Instrument Instrument_AGM_OverdrivenGuitar[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_42, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_48, 255, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_54, 255, 0, 255, 192),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_60, 255, 0, 255, 192),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_66, 255, 0, 255, 192),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_72, 255, 0, 255, 192),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_78, 255, 0, 255, 192),
    [SAMPLE_7] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_84, 255, 0, 255, 192),
    [SAMPLE_8] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_90, 255, 0, 255, 192),
    [SAMPLE_9] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_029_Overdriven_Guitar_96, 255, 0, 255, 192),
};

// BASS

const u8 KeySplit_AGM_Bass[] =
{
    SPLIT(NOTE_CN , NOTE_A1 , SAMPLE_0),//33
    SPLIT(NOTE_AS1, NOTE_DS2, SAMPLE_1),//39
    SPLIT(NOTE_E2 , NOTE_D3 , SAMPLE_2),//50
    SPLIT(NOTE_DS3, NOTE_CS4, SAMPLE_3),//61
    SPLIT(NOTE_D4 , NOTE_G9 , SAMPLE_4),
};

const struct Instrument Instrument_AGM_Acoustic_Bass[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_032_Acoustic_Bass_28, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_032_Acoustic_Bass_39, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_032_Acoustic_Bass_39, 255, 0, 255, 165),//
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_032_Acoustic_Bass_60, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_032_Acoustic_Bass_60, 255, 0, 255, 165),//
};

const struct Instrument Instrument_AGM_Electric_Bass_Finger[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_033_Electric_Bass_Finger_33, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_033_Electric_Bass_Finger_38, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_033_Electric_Bass_Finger_43, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_033_Electric_Bass_Finger_56, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_033_Electric_Bass_Finger_62, 255, 0, 255, 165),
};

const struct Instrument Instrument_AGM_Electric_Bass_Pick[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_034_Electric_Bass_Pick_35, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_034_Electric_Bass_Pick_35, 255, 0, 255, 165),//
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_034_Electric_Bass_Pick_45, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_034_Electric_Bass_Pick_60, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_034_Electric_Bass_Pick_60, 255, 0, 255, 165),//
};

const struct Instrument Instrument_AGM_Fretless_Bass[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_035_Fretless_Bass_32, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_035_Fretless_Bass_35, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_035_Fretless_Bass_44, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_035_Fretless_Bass_59, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_035_Fretless_Bass_59, 255, 0, 255, 165),//
};

const u8 KeySplit_AGM_Slap_Bass[] =
{
    SPLIT(NOTE_CN , NOTE_A1 , SAMPLE_0),
    SPLIT(NOTE_AS1, NOTE_B2 , SAMPLE_1),
    SPLIT(NOTE_C3 , NOTE_AS3, SAMPLE_2),
    SPLIT(NOTE_B3 , NOTE_G9 , SAMPLE_3),
};

const struct Instrument Instrument_AGM_Slap_Bass_1[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_036_Slap_Bass_1_28, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_036_Slap_Bass_1_42, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_036_Slap_Bass_1_54, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_036_Slap_Bass_1_59, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_Synth_Bass[] =
{
    SPLIT(NOTE_CN , NOTE_F1 , SAMPLE_0),
    SPLIT(NOTE_FS1, NOTE_F2 , SAMPLE_1),
    SPLIT(NOTE_FS2, NOTE_F3 , SAMPLE_2),
    SPLIT(NOTE_FS3, NOTE_F4 , SAMPLE_3),
    SPLIT(NOTE_FS4, NOTE_F5 , SAMPLE_4),
    SPLIT(NOTE_FS5, NOTE_F6 , SAMPLE_5),
    SPLIT(NOTE_FS6, NOTE_G9 , SAMPLE_6),
};

const struct Instrument Instrument_AGM_Synth_Bass_1[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_36, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_36, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_48, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_60, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_72, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_84, 255, 0, 255, 165),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_038_Synth_Bass_1_96, 255, 0, 255, 165),
};

const struct Instrument Instrument_AGM_Synth_Bass_2[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_24, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_36, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_48, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_60, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_72, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_84, 255, 0, 255, 165),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_039_Synth_Bass_2_84, 255, 0, 255, 165),
};

// STRINGS

const u8 KeySplit_AGM_Timpani[] =
{
    SPLIT(NOTE_CN , NOTE_GS2, SAMPLE_0),
    SPLIT(NOTE_A2 , NOTE_G9 , SAMPLE_1),
};

const struct Instrument Instrument_AGM_Timpani[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_047_Timpani_44, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_047_Timpani_49, 255, 0, 255, 192),
};

const u8 KeySplit_AGM_Pizzicato_Strings[] =
{
    SPLIT(NOTE_CN , NOTE_F1 , SAMPLE_0),
    SPLIT(NOTE_FS1, NOTE_CS2, SAMPLE_1),
    SPLIT(NOTE_D2 , NOTE_C3 , SAMPLE_2),
    SPLIT(NOTE_CS3, NOTE_C4 , SAMPLE_3),
    SPLIT(NOTE_CS4, NOTE_CS5, SAMPLE_4),
    SPLIT(NOTE_D5 , NOTE_CS6, SAMPLE_5),
    SPLIT(NOTE_D6 , NOTE_G9 , SAMPLE_6),
};

const struct Instrument Instrument_AGM_Pizzicato_Strings[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_28, 255, 0, 255, 235),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_37, 255, 0, 255, 235),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_48, 255, 0, 255, 235),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_60, 255, 0, 255, 235),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_73, 255, 0, 255, 235),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_85, 255, 0, 255, 235),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_045_Pizzicato_Strings_96, 255, 0, 255, 235),
};

// ENSEMBLE

// BRASS

// Acimut's Trumpet v9
const u8 KeySplit_AGM_Trumpet[] =
{
    SPLIT(NOTE_CN ,NOTE_C4 , SAMPLE_0),
    SPLIT(NOTE_CS4,NOTE_FS4, SAMPLE_1),
    SPLIT(NOTE_G4 ,NOTE_C5 , SAMPLE_2),
    SPLIT(NOTE_CS5,NOTE_FS5, SAMPLE_3),
    SPLIT(NOTE_G5 ,NOTE_B5 , SAMPLE_4),
    SPLIT(NOTE_C6 ,NOTE_G9 , SAMPLE_5),
};

const struct Instrument Instrument_AGM_Trumpet[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_056_Trumpet_57, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_056_Trumpet_63, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_056_Trumpet_69, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_056_Trumpet_75, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_056_Trumpet_81, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_056_Trumpet_87, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_Trombone[] =
{
    SPLIT(NOTE_CN , NOTE_GS2, SAMPLE_0),
    SPLIT(NOTE_A2 , NOTE_F3 , SAMPLE_1),
    SPLIT(NOTE_FS3, NOTE_B3 , SAMPLE_2),
    SPLIT(NOTE_C4 , NOTE_F4 , SAMPLE_3),
    SPLIT(NOTE_FS4, NOTE_G9 , SAMPLE_4),
};

const struct Instrument Instrument_AGM_Trombone[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_057_Trombone_44, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_057_Trombone_53, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_057_Trombone_59, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_057_Trombone_65, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_057_Trombone_71, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_Tuba[] =
{
    SPLIT(NOTE_CN ,NOTE_F1 , SAMPLE_0),
    SPLIT(NOTE_FS1,NOTE_E2 , SAMPLE_1),
    SPLIT(NOTE_F2 ,NOTE_B2 , SAMPLE_2),
    SPLIT(NOTE_C3 ,NOTE_E3 , SAMPLE_3),
    SPLIT(NOTE_F3 ,NOTE_E4 , SAMPLE_4),
    SPLIT(NOTE_F4 ,NOTE_G9 , SAMPLE_5),
};

const struct Instrument Instrument_AGM_Tuba[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_058_Tuba_29, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_058_Tuba_40, 255, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_058_Tuba_47, 255, 0, 255, 192),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_058_Tuba_52, 255, 0, 255, 192),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_058_Tuba_64, 255, 0, 255, 192),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_058_Tuba_74, 255, 0, 255, 192),
};

const u8 KeySplit_AGM_Muted_Trumpet[] =
{
    SPLIT(NOTE_CN , NOTE_C4 , SAMPLE_0),
    SPLIT(NOTE_CS4, NOTE_FS4, SAMPLE_1),
    SPLIT(NOTE_G4 , NOTE_B4 , SAMPLE_2),
    SPLIT(NOTE_C5 , NOTE_G9 , SAMPLE_3),
};

const struct Instrument Instrument_AGM_Muted_Trumpet[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_059_Muted_Trumpet_60, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_059_Muted_Trumpet_66, 255, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_059_Muted_Trumpet_71, 255, 0, 255, 192),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_059_Muted_Trumpet_77, 255, 0, 255, 192),
};

const u8 KeySplit_AGM_FrenchHorn[] =
{
    SPLIT(NOTE_CN , NOTE_DS2, SAMPLE_0),
    SPLIT(NOTE_E2 , NOTE_DS3, SAMPLE_1),
    SPLIT(NOTE_E3 , NOTE_DS4, SAMPLE_2),
    SPLIT(NOTE_E4 , NOTE_G9 , SAMPLE_3),
};

const struct Instrument Instrument_AGM_FrenchHorn[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_060_French_Horn_39, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_060_French_Horn_51, 255, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_060_French_Horn_63, 255, 0, 255, 192),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_060_French_Horn_75, 255, 0, 255, 192),
};

const u8 KeySplit_AGM_Brass_Section[] =
{
    SPLIT(NOTE_CN , NOTE_FS4, SAMPLE_0),
    SPLIT(NOTE_G4 , NOTE_FS5, SAMPLE_1),
    SPLIT(NOTE_G5 , NOTE_G9 , SAMPLE_2),
};

const struct Instrument Instrument_AGM_Brass_Section[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_061_Brass_Section_60, 255, 0, 255, 192),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_061_Brass_Section_72, 255, 0, 255, 192),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_061_Brass_Section_84, 255, 0, 255, 192),
};

const u8 KeySplit_AGM_Synth_Brass[] =
{
    SPLIT(NOTE_CN , NOTE_F4 , SAMPLE_0),
    SPLIT(NOTE_FS4, NOTE_F5 , SAMPLE_1),
    SPLIT(NOTE_FS5, NOTE_G9 , SAMPLE_2),
};

const struct Instrument Instrument_AGM_Synth_Brass_1[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_062_Synth_Brass_1_60, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_062_Synth_Brass_1_72, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_062_Synth_Brass_1_84, 255, 0, 255, 165),
};

const struct Instrument Instrument_AGM_Synth_Brass_2[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_063_Synth_Brass_2_60, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_063_Synth_Brass_2_72, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_063_Synth_Brass_2_72, 255, 0, 255, 165),
};

// REED

const u8 KeySplit_AGM_Soprano_Sax[] =
{
    SPLIT(NOTE_CN , NOTE_C4 , SAMPLE_0),
    SPLIT(NOTE_CS4, NOTE_FS4, SAMPLE_1),
    SPLIT(NOTE_G4 , NOTE_C5 , SAMPLE_2),
    SPLIT(NOTE_CS5, NOTE_G5 , SAMPLE_3),
    SPLIT(NOTE_GS5, NOTE_G9 , SAMPLE_4),
};

const struct Instrument Instrument_AGM_Soprano_Sax[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_064_Soprano_Sax_60, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_064_Soprano_Sax_66, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_064_Soprano_Sax_72, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_064_Soprano_Sax_78, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_064_Soprano_Sax_84, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_Alto_Sax[] =
{
    SPLIT(NOTE_CN , NOTE_E3 , SAMPLE_0),
    SPLIT(NOTE_F3 , NOTE_G3 , SAMPLE_1),
    SPLIT(NOTE_GS3, NOTE_AS3, SAMPLE_2),
    SPLIT(NOTE_B3 , NOTE_CS4, SAMPLE_3),
    SPLIT(NOTE_D4 , NOTE_E4 , SAMPLE_4),
    SPLIT(NOTE_F4 , NOTE_G4 , SAMPLE_5),
    SPLIT(NOTE_GS4, NOTE_AS4, SAMPLE_6),
    SPLIT(NOTE_B4 , NOTE_CS5, SAMPLE_7),
    SPLIT(NOTE_D5 , NOTE_E5 , SAMPLE_8),
    SPLIT(NOTE_F5 , NOTE_G5 , SAMPLE_9),
    SPLIT(NOTE_GS5, NOTE_G9 , SAMPLE_10),
};

const struct Instrument Instrument_AGM_Alto_Sax[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_52, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_55, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_58, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_61, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_64, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_67, 255, 0, 255, 165),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_70, 255, 0, 255, 165),
    [SAMPLE_7] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_73, 255, 0, 255, 165),
    [SAMPLE_8] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_75, 255, 0, 255, 165),
    [SAMPLE_9] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_78, 255, 0, 255, 165),
    [SAMPLE_10] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_065_Alto_Sax_84, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_Tenor_Sax[] =
{
    SPLIT(NOTE_CN , NOTE_A2 , SAMPLE_0),
    SPLIT(NOTE_AS2, NOTE_E3 , SAMPLE_1),
    SPLIT(NOTE_F3 , NOTE_A3 , SAMPLE_2),
    SPLIT(NOTE_AS3, NOTE_C4 , SAMPLE_3),
    SPLIT(NOTE_CS4, NOTE_F4 , SAMPLE_4),
    SPLIT(NOTE_FS4, NOTE_C5 , SAMPLE_5),
    SPLIT(NOTE_CS5, NOTE_E5 , SAMPLE_6),
    SPLIT(NOTE_F5 , NOTE_G9 , SAMPLE_7),
};

const struct Instrument Instrument_AGM_Tenor_Sax[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_45, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_52, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_57, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_60, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_65, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_72, 255, 0, 255, 165),
    [SAMPLE_6] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_76, 255, 0, 255, 165),
    [SAMPLE_7] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_066_Tenor_Sax_81, 255, 0, 255, 165),
};

const u8 KeySplit_AGM_Baritone_Sax[] =
{
    SPLIT(NOTE_CN , NOTE_D2 , SAMPLE_0),
    SPLIT(NOTE_DS2, NOTE_G2 , SAMPLE_1),
    SPLIT(NOTE_GS2, NOTE_CS3, SAMPLE_2),
    SPLIT(NOTE_D3 , NOTE_FS3, SAMPLE_3),
    SPLIT(NOTE_G3 , NOTE_C4 , SAMPLE_4),
    SPLIT(NOTE_CS4, NOTE_G9 , SAMPLE_5),
};

const struct Instrument Instrument_AGM_Baritone_Sax[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_067_Baritone_Sax_37, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_067_Baritone_Sax_41, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_067_Baritone_Sax_49, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_067_Baritone_Sax_53, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_067_Baritone_Sax_59, 255, 0, 255, 165),
    [SAMPLE_5] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_067_Baritone_Sax_66, 255, 0, 255, 165),
};

// PIPE

const u8 KeySplit_AGM_Flute[] =
{
    SPLIT(NOTE_CN , NOTE_CS4, SAMPLE_0),
    SPLIT(NOTE_D4 , NOTE_G4 , SAMPLE_1),
    SPLIT(NOTE_GS4, NOTE_E5 , SAMPLE_2),
    SPLIT(NOTE_F5 , NOTE_CS6, SAMPLE_3),
    SPLIT(NOTE_D6 , NOTE_G9 , SAMPLE_4),
};

const struct Instrument Instrument_AGM_Flute[] =
{
    [SAMPLE_0] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_073_Flute_61, 255, 0, 255, 165),
    [SAMPLE_1] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_073_Flute_67, 255, 0, 255, 165),
    [SAMPLE_2] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_073_Flute_76, 255, 0, 255, 165),
    [SAMPLE_3] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_073_Flute_85, 255, 0, 255, 165),
    [SAMPLE_4] = SOUND_SAMPLE(NOTE_C4, 0, gDirectSoundWaveData_Acimut_GM_073_Flute_94, 255, 0, 255, 165),
};

// SYNTH LEAD

// SYNTH PAD

// SYNTH EFFECTS

// ETHNIC

// PERCUSIVE

// SOUND EFFECTS

