#ifndef GUARD_VOICEGROUPS_H
#define GUARD_VOICEGROUPS_H

#include "constants/general_midi.h"
#include "gba/m4a_internal.h"

union VoiceGroup;

//copy of struct ToneData, exclusive for instruments
struct Instrument
{
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    struct WaveData *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct VoiceSquare
{
    u8 type;
    u8 key;
    u8 pan;
    u8 sweep;
    u32 duty_cycle;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct VoiceProgrammable
{
    u8 type;
    u8 key;
    u8 pan;
    u8 unk3;
    struct WaveData *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct VoiceNoise
{
    u8 type;
    u8 key;
    u8 pan;
    u8 unk3;
    u32 period;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};

struct InstrumentSplit
{
    u8 type;
    u8 key;
    u8 dummy1;
    u8 dummy2;
    const struct Instrument *instrument;
    const u8 * keysplit_table_ptr;
};

union VoiceGroup
{
    struct ToneData toneData;
    struct Instrument instrument;
    struct VoiceSquare square;
    struct VoiceProgrammable programmable;
    struct VoiceNoise noise;
    struct InstrumentSplit instrumentSplit;
};


// for key split table purpose
#define SAMPLE_0    0
#define SAMPLE_1    1
#define SAMPLE_2    2
#define SAMPLE_3    3
#define SAMPLE_4    4
#define SAMPLE_5    5
#define SAMPLE_6    6
#define SAMPLE_7    7
#define SAMPLE_8    8
#define SAMPLE_9    9
#define SAMPLE_10   10
#define SAMPLE_11   11
#define SAMPLE_12   12
#define SAMPLE_13   13
#define SAMPLE_14   14
#define SAMPLE_15   15
#define SAMPLE_16   16
#define SAMPLE_17   17
#define SAMPLE_18   18
#define SAMPLE_19   19
#define SAMPLE_20   20
#define SAMPLE_21   21
#define SAMPLE_22   22
#define SAMPLE_23   23
#define SAMPLE_24   24
#define SAMPLE_25   25
#define SAMPLE_26   26
#define SAMPLE_27   27
#define SAMPLE_28   28
#define SAMPLE_29   29
#define SAMPLE_30   30
#define SAMPLE_31   31
#define SAMPLE_32   32


#define SPLIT(start_note, end_note, sample_number)    [start_note ... end_note] = sample_number

#define SAMPLE_DATA(_type,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)\
    {                                                   \
        .type = _type,                                  \
        .key = base_midi_key,                           \
        .pan_sweep = (pan)?(0x80|pan):0,                \
        .wav = (struct WaveData*)&sample_data_pointer,  \
        .attack = _attack,                              \
        .decay = _decay,                                \
        .sustain = _sustain,                            \
        .release = _release                             \
    }

// old macro
#define VOICE_DIRECTSOUND(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    {.toneData = SAMPLE_DATA(0,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)}

#define VOICE_DIRECTSOUND_NO_RESAMPLE(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    {.toneData = SAMPLE_DATA(8,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)}

#define VOICE_DIRECTSOUND_ALT(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    {.toneData = SAMPLE_DATA(16,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)}

// instruments for voicegroup (program sound sample)
#define INSTRUMENT(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    {.instrument = SAMPLE_DATA(0,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)}

#define INSTRUMENT_NO_RESAMPLE(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    {.instrument = SAMPLE_DATA(8,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)}

#define INSTRUMENT_ALT(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    {.instrument = SAMPLE_DATA(16,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)}

// wave samples for program number (instrument)
#define SOUND_SAMPLE(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    SAMPLE_DATA(0,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)

#define SOUND_SAMPLE_RAW(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    SAMPLE_DATA(8,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)

#define SOUND_SAMPLE_ALT(base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release) \
    SAMPLE_DATA(16,base_midi_key,pan,sample_data_pointer,_attack,_decay,_sustain,_release)


#define VOICE_SQUARE(_type,base_midi_key,_pan,_sweep,_duty_cycle,_attack,_decay,_sustain,_release)\
    {                                   \
        .type = _type,                  \
        .key = base_midi_key,           \
        .pan = (_pan)?(0x80|_pan):0,    \
        .sweep = _sweep,                \
        .duty_cycle = (_duty_cycle & 3),\
        .attack = (_attack & 7),        \
        .decay = (_decay & 7),          \
        .sustain = (_sustain & 15),     \
        .release = (_release & 7)       \
    }

#define VOICE_SQUARE_1(base_midi_key,_pan,_sweep,_duty_cycle,_attack,_decay,_sustain,_release) \
    {.square = VOICE_SQUARE(1,base_midi_key,_pan,_sweep,_duty_cycle,_attack,_decay,_sustain,_release)}

#define VOICE_SQUARE_1_ALT(base_midi_key,_pan,_sweep,_duty_cycle,_attack,_decay,_sustain,_release) \
    {.square = VOICE_SQUARE(9,base_midi_key,_pan,_sweep,_duty_cycle,_attack,_decay,_sustain,_release)}

#define VOICE_SQUARE_2(base_midi_key,_pan,_duty_cycle,_attack,_decay,_sustain,_release) \
    {.square = VOICE_SQUARE(2,base_midi_key,_pan,0,_duty_cycle,_attack,_decay,_sustain,_release)}

#define VOICE_SQUARE_2_ALT(base_midi_key,_pan,_duty_cycle,_attack,_decay,_sustain,_release) \
    {.square = VOICE_SQUARE(10,base_midi_key,_pan,0,_duty_cycle,_attack,_decay,_sustain,_release)}


#define PROGRAMMABLE_WAVE(_type,base_midi_key,_pan,wave_samples_pointer,_attack,_decay,_sustain,_release)\
    {                                                   \
        .type = _type,                                  \
        .key = base_midi_key,                           \
        .pan = (_pan)?(0x80|_pan):0,                    \
        .wav = (struct WaveData*)&wave_samples_pointer, \
        .attack = (_attack & 7),                        \
        .decay = (_decay & 7),                          \
        .sustain = (_sustain & 15),                     \
        .release = (_release & 7)                       \
    }

#define VOICE_PROGRAMMABLE_WAVE(base_midi_key,_pan,wave_samples_pointer,_attack,_decay,_sustain,_release) \
    {.programmable = PROGRAMMABLE_WAVE(3,base_midi_key,_pan,wave_samples_pointer,_attack,_decay,_sustain,_release)}

#define VOICE_PROGRAMMABLE_WAVE_ALT(base_midi_key,_pan,wave_samples_pointer,_attack,_decay,_sustain,_release) \
    {.programmable = PROGRAMMABLE_WAVE(11,base_midi_key,_pan,wave_samples_pointer,_attack,_decay,_sustain,_release)}


#define VOICE_NOISE(base_midi_key,_pan,_period,_attack,_decay,_sustain,_release) \
    {.noise =                           \
        {                               \
            .type = 4,                  \
            .key = base_midi_key,       \
            .pan = (_pan)?(0x80|_pan):0,\
            .period = (_period & 1),    \
            .attack = (_attack & 7),    \
            .decay = (_decay & 7),      \
            .sustain = (_sustain & 15), \
            .release = (_release & 7)   \
        }                               \
    }

#define VOICE_NOISE_ALT(base_midi_key,_pan,_period,_attack,_decay,_sustain,_release) \
    {.noise =                           \
        {                               \
            .type = 12,                 \
            .key = base_midi_key,       \
            .pan = (_pan)?(0x80|_pan):0,\
            .period = (_period & 1),    \
            .attack = (_attack & 7),    \
            .decay = (_decay & 7),      \
            .sustain = (_sustain & 15), \
            .release = (_release & 7)   \
        }                               \
    }


#define VOICE_KEYSPLIT(instrument_pointer, keysplit_table_pointer)  \
    {.instrumentSplit =                                             \
        {                                                           \
            .type = TONEDATA_TYPE_SPL,                              \
            .instrument = instrument_pointer,                       \
            .keysplit_table_ptr = keysplit_table_pointer            \
        }                                                           \
    }

// voice_keysplit
#define INSTRUMENT_SPLIT(instrument_pointer, keysplit_table_pointer)\
    {.instrumentSplit =                                             \
        {                                                           \
            .type = TONEDATA_TYPE_SPL,                              \
            .instrument = instrument_pointer,                       \
            .keysplit_table_ptr = keysplit_table_pointer            \
        }                                                           \
    }

#define VOICE_KEYSPLIT_ALL(instrument_pointer)  \
    {.instrumentSplit =                         \
        {                                       \
            .type = TONEDATA_TYPE_RHY,          \
            .instrument = instrument_pointer,   \
        }                                       \
    }

// voice_keysplit_all
#define INSTRUMENT_SPLIT_ALL(instrument_pointer)\
    {.instrumentSplit =                         \
        {                                       \
            .type = TONEDATA_TYPE_RHY,          \
            .instrument = instrument_pointer,   \
        }                                       \
    }

// voice_keysplit_all
#define DRUM_SET(instrument_pointer)            \
    {.instrumentSplit =                         \
        {                                       \
            .type = TONEDATA_TYPE_RHY,          \
            .instrument = instrument_pointer,   \
        }                                       \
    }


#define CRY(sample)                         \
    {                                       \
        .type = 32,                         \
        .key = NOTE_C4,                     \
        .wav = (struct WaveData*)&sample,   \
        .attack = 255,                      \
        .decay = 0,                         \
        .sustain = 255,                     \
        .release = 0                        \
    }

#define CRY_REVERSE(sample)                 \
    {                                       \
        .type = 48,                         \
        .key = NOTE_C4,                     \
        .wav = (struct WaveData*)&sample,   \
        .attack = 255,                      \
        .decay = 0,                         \
        .sustain = 255,                     \
        .release = 0                        \
    }

#define DEFAULT_VOICE_SQUARE   VOICE_SQUARE_1(NOTE_C4, 0, 0, 2, 0, 0, 15, 0)

#endif // GUARD_VOICEGROUPS_H
