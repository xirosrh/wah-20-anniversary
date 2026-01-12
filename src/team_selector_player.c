#include "global.h"
#include "team_selector.h"
#include "data.h"


enum {
    MON_HITMONCHAN,
    MON_BRONZONG,
    MON_LANTURN,
    MON_MAGCARGO,
    MON_HONCHKROW,
    MON_DRAGALGE,
    MON_TINKATON,
    MON_ARMAROUGE,
    MON_BAXCALIBUR,
    MON_SHIFTRY,
    MON_GOLEM,
    MON_MISMAGIUS,
    MON_DIGGERSBY,
    MON_LOPUNNY,
    MON_MUDSDALE,
    MON_RAPIDASH,
    MON_FARIGIRAF,
    MON_SCOVILLAIN
};

const struct TeamSelectorPlayer gTeamSelectorPlayer[NUM_PLAYER_TEAMS] =
    {
        [TEAM_1] =
            {
                .teamSize = 6,
                .team =
                    {
                        MON_HITMONCHAN, MON_BRONZONG, MON_LANTURN, MON_MAGCARGO, MON_HONCHKROW, MON_DRAGALGE
                    },
            },

        [TEAM_2] =
            {
                .teamSize = 6,
                .team =
                    {
                        MON_TINKATON, MON_ARMAROUGE, MON_BAXCALIBUR, MON_SHIFTRY, MON_GOLEM, MON_MISMAGIUS
                    },
            },
        
        [TEAM_3] =
            {
                .teamSize = 6,
                .team =
                    {
                        MON_DIGGERSBY, MON_LOPUNNY, MON_MUDSDALE, MON_RAPIDASH, MON_FARIGIRAF, MON_SCOVILLAIN
                    },
            },
};

const struct TeamSelectorMonData gAllTeamMons[NUM_MONS_POOL] =
    {
        [MON_HITMONCHAN] = {
            .specie = SPECIES_HITMONCHAN,
            .ability = ABILITY_NONE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_ASSAULT_VEST,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_MACH_PUNCH,
                    MOVE_BULLET_PUNCH,
                    MOVE_DRAIN_PUNCH,
                    MOVE_THUNDER_PUNCH},
        },
        [MON_BRONZONG] = {
            .specie = SPECIES_BRONZONG,
            .ability = ABILITY_NONE,
            .nature = NATURE_BRAVE,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(0, 252, 4, 0, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_GYRO_BALL,
                    MOVE_ZEN_HEADBUTT,
                    MOVE_EARTHQUAKE,
                    MOVE_ROCK_SLIDE},
        },
        [MON_LANTURN] = {
            .specie = SPECIES_LANTURN,
            .ability = ABILITY_NONE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_SCALD,
                    MOVE_CHARGE_BEAM,
                    MOVE_TWIN_BEAM,
                    MOVE_ICE_BEAM},
        },
        [MON_MAGCARGO] = {
            .specie = SPECIES_MAGCARGO,
            .ability = ABILITY_NONE,
            .nature = NATURE_NAIVE,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 0, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_FLAMETHROWER,
                    MOVE_ROCK_SLIDE,
                    MOVE_EARTH_POWER,
                    MOVE_ERUPTION},
        },
        [MON_HONCHKROW] = {
            .specie = SPECIES_HONCHKROW,
            .ability = ABILITY_NONE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_NIGHT_SLASH,
                    MOVE_FOUL_PLAY,
                    MOVE_AERIAL_ACE,
                    MOVE_ROOST},
        },
        [MON_DRAGALGE] = {
            .specie = SPECIES_DRAGALGE,
            .ability = ABILITY_NONE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_BLACK_SLUDGE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_SCALD,
                    MOVE_SLUDGE_BOMB,
                    MOVE_DRAGON_PULSE,
                    MOVE_SLUDGE_WAVE},
        },
        [MON_TINKATON] = {
            .specie = SPECIES_TINKATON,
            .ability = ABILITY_NONE,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_ASSAULT_VEST,
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 4, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_GIGATON_HAMMER,
                    MOVE_PLAY_ROUGH,
                    MOVE_KNOCK_OFF,
                    MOVE_EARTHQUAKE},
        },
        [MON_ARMAROUGE] = {
            .specie = SPECIES_ARMAROUGE,
            .ability = ABILITY_NONE,
            .nature = NATURE_MODEST,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 4, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_EXPANDING_FORCE,
                    MOVE_SCORCHING_SANDS,
                    MOVE_FLAMETHROWER,
                    MOVE_AURA_SPHERE},
        },
        [MON_BAXCALIBUR] = {
            .specie = SPECIES_BAXCALIBUR,
            .ability = ABILITY_NONE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_GLAIVE_RUSH,
                    MOVE_DRAGON_CLAW,
                    MOVE_ICE_SHARD,
                    MOVE_CRUNCH},
        },
        [MON_SHIFTRY] = {
            .specie = SPECIES_SHIFTRY,
            .ability = ABILITY_NONE,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 4, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_LEAF_BLADE,
                    MOVE_NIGHT_SLASH,
                    MOVE_ROCK_SLIDE,
                    MOVE_AERIAL_ACE},
        },
        [MON_GOLEM] = {
            .specie = SPECIES_GOLEM,
            .ability = ABILITY_NONE,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_ASSAULT_VEST,
            .ev = TRAINER_PARTY_EVS(4, 252, 252, 0, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_HEAD_SMASH,
                    MOVE_EARTHQUAKE,
                    MOVE_DRAIN_PUNCH,
                    MOVE_ICE_PUNCH},
        },
        [MON_MISMAGIUS] = {
            .specie = SPECIES_MISMAGIUS,
            .ability = ABILITY_NONE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_SHADOW_BALL,
                    MOVE_CALM_MIND,
                    MOVE_ENERGY_BALL,
                    MOVE_THUNDERBOLT},
        },
        [MON_DIGGERSBY] = {
            .specie = SPECIES_DIGGERSBY,
            .ability = ABILITY_NONE, // puedes asignar la habilidad que corresponda si quieres
            .nature = NATURE_JOLLY,
            .itemId = ITEM_ASSAULT_VEST,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_QUICK_ATTACK,
                    MOVE_EARTHQUAKE,
                    MOVE_DRAIN_PUNCH,
                    MOVE_FIRE_PUNCH},
        },
        [MON_LOPUNNY] = {
            .specie = SPECIES_LOPUNNY,
            .ability = ABILITY_NONE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_LOPUNNITE,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_HIGH_JUMP_KICK,
                    MOVE_BOUNCE,
                    MOVE_MEGA_KICK,
                    MOVE_FAKE_OUT},
        },
        [MON_MUDSDALE] = {
            .specie = SPECIES_MUDSDALE,
            .ability = ABILITY_NONE,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_EARTHQUAKE,
                    MOVE_ROCK_SLIDE,
                    MOVE_DOUBLE_KICK,
                    MOVE_HEAVY_SLAM},
        },
        [MON_RAPIDASH] = {
            .specie = SPECIES_RAPIDASH,
            .ability = ABILITY_NONE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_FLARE_BLITZ,
                    MOVE_MEGAHORN,
                    MOVE_DRILL_RUN,
                    MOVE_POISON_JAB},
        },
        [MON_FARIGIRAF] = {
            .specie = SPECIES_FARIGIRAF,
            .ability = ABILITY_NONE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_TWIN_BEAM,
                    MOVE_HYPER_VOICE,
                    MOVE_CHARGE_BEAM,
                    MOVE_NASTY_PLOT},
        },
        [MON_SCOVILLAIN] = {
            .specie = SPECIES_SCOVILLAIN,
            .ability = ABILITY_NONE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_LEFTOVERS,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves =
                {
                    MOVE_GIGA_DRAIN,
                    MOVE_FLAMETHROWER,
                    MOVE_ENERGY_BALL,
                    MOVE_BURNING_JEALOUSY},
        }
};
// .ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 0, 0),