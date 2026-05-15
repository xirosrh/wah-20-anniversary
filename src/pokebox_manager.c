#include "global.h"
#include "data.h"
#include "event_data.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "constants/characters.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/achievements.h"
#include "achievements.h"
#include "pokebox_manager.h"
#include "money.h"
#include "pokemon.h"
#include "strings.h"
#include "string_util.h"


static bool8 CheckPokebox_isBuyMon(u8 id);
static bool8 CheckPokebox_WahChallengeCompleted(u8 id);
static bool8 CheckPokebox_WahChallengeDifficultCompleted(u8 id);
static bool8 CheckPokebox_AlexmadEventGiveClones(u8 id);
static bool8 CheckPokebox_AlexmadEventGiveLegendaries(u8 id);
static bool8 CheckPokebox_AlexmadEventCompleted(u8 id);
static bool8 CheckPokebox_AchievementAvaricia(u8 id);
static bool8 CheckPokebox_MetBaroRoomPlugOink(u8 id);
static bool8 CheckPokebox_EingTeamsDefeated(u8 id);
static bool8 CheckPokebox_ReyBooHardBothTeams(u8 id);
static bool8 CheckPokebox_BaroBothTeams(u8 id);
static bool8 CheckPokebox_DefeatAllAdminsAchievement(u8 id);
static bool8 CheckPokebox_DefeatAllCollaboratorsAchievement(u8 id);
static bool8 CheckPokebox_WinWahChallengeDoubleAchievement(u8 id);
static bool8 CheckPokebox_WinWahChallengeInverseAchievement(u8 id);
static bool8 CheckPokebox_BetaMonQuestionnaire(u8 id);

static const u8 *sPokeboxMsgActionsList[] =
{
    [MSG_ACTION_CONTROLS] = COMPOUND_STRING("{START_BUTTON} Equipo {SELECT_BUTTON} Info. {DPAD_NONE} Mover {A_BUTTON} Añadir"),
    [MSG_ACTION_CONTROLS_TEAM] = COMPOUND_STRING("{A_BUTTON} Dejar {B_BUTTON} Atras {DPAD_NONE} Mover {START_BUTTON} Resetear"),    
    [MSG_ACTION_FULL_TEAM]     = COMPOUND_STRING("Tu equipo está completo"),
    [MSG_ACTION_NOT_TEAM_FULL] = COMPOUND_STRING("Debes tener 6 Pokémon en el equipo"),
    [MSG_ACTION_LOCK_MON]      = COMPOUND_STRING("Este Pokémon está bloqueado."),
    [MSG_ACTION_MON_IN_TEAM]   = COMPOUND_STRING("Este Pokémon ya está en el equipo."),
    [MSG_ACTION_ONLY_ONE_MON_IN_TEAM] = COMPOUND_STRING("Debes tener un Pokémon en el equipo"), 
    [MSG_ACTION_ADD_MON_PARTY] = COMPOUND_STRING("{STR_VAR_1} añadido al equipo"), 
    [MSG_ACTION_ONLY_STORAGE_ONE_MON] = COMPOUND_STRING("Solo puedes cambiar un Pokémon del equipo"), 
    [MSG_ACTION_ONLY_STORAGE_THREE_MON] = COMPOUND_STRING("Solo puedes cambiar tres Pokémon del equipo"), 
};

const u8 *Get_PokeboxMsgAction(u8 index) 
{
    if (index >= MSG_ACTION_COUNT)
        return sPokeboxMsgActionsList[0];

    return sPokeboxMsgActionsList[index];
}

const u8 gText_PokeboxBuyThisMon[] = _("¿Quieres comprar a\neste Pokémon?");

static const u8 sText_PokeboxAlexmadEvent[] = _("Completa el evento especial\nde Alexmad.");
static const u8 sText_PokeboxWahChallengeOnce[] = _("Gana el desafio una vez.");
static const u8 sText_PokeboxAchievementAvaricia[] = _("Completa el logro “Avaricia”.");
static const u8 sText_PokeboxMetBaroRoomPlugOink[] = _("Habla con Plug-Oink en la\nsala de Baro.");
static const u8 sText_PokeboxWahChallengeDifficult[] = _("Gana el desafio en modo\ndifícil.");
static const u8 sText_PokeboxEingTeams[] = _("Derrota a ambos equipos\nde Eing (principal y\nalternativo).");
static const u8 sText_PokeboxMolikai[] = _("Derrota a ambos equipos\nde Helix Boo en modo difícil\n(principal y alternativo).");
static const u8 sText_PokeboxBaroTeams[] = _("Derrota a ambos equipos\nde Baro (principal y\nalternativo).");
static const u8 sText_PokeboxAllAdmins[] = _("Completa el logro de\nderrotar a todos los\nadmins.");
static const u8 sText_PokeboxAllCollaborators[] = _("Completa el logro de\nderrotar a todos los\ncolaboradores.");
static const u8 sText_PokeboxWahDouble[] = _("Completa el desafío en modo\nbatallas dobles.");
static const u8 sText_PokeboxWahInverse[] = _("Completa el desafío en modo\nbatallas inversas.");
static const u8 sText_PokeboxBetaMonQuestionnaire[] = _("Responde correctamente su\npregunta en el cuestionario\nde la Sala de estar.");

#define POKEBOX_MON(species_)                                                           \
    {                                                                                   \
        .specie = species_, .ability = ABILITY_NONE, .nature = NATURE_HARDY,            \
        .itemId = ITEM_NONE, .ev = NULL, .isShiny = FALSE,                              \
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE}                           \
    }

static const struct PokeboxSpecies sPokeboxSpeciesList[] =
{
    {
        .mon = {
            .specie = SPECIES_JIRACHI,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_PSYCHIC, MOVE_FLASH_CANNON, MOVE_DOOM_DESIRE, MOVE_MOONLIGHT},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveLegendaries
    },
    {
        .mon = {
            .specie = SPECIES_MEW,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = TRUE,
            .moves = {MOVE_PSYCHIC, MOVE_RECOVER, MOVE_TRANSFORM, MOVE_PSYSTRIKE},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveLegendaries
    },
    {
        .mon = {
            .specie = SPECIES_CELEBI,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = TRUE,
            .moves = {MOVE_PSYCHIC, MOVE_ENERGY_BALL, MOVE_RECOVER, MOVE_GIGA_DRAIN},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveLegendaries
    },
    {
        .mon = {
            .specie = SPECIES_VENUSAUR_C,
            .ability = ABILITY_SPEED_BOOST,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_PETAL_DANCE, MOVE_SLUDGE_WAVE},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveClones
    },
    {
        .mon = {
            .specie = SPECIES_CHARIZARD_C,
            .ability = ABILITY_ROCK_HEAD,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_FLARE_BLITZ, MOVE_BRAVE_BIRD, MOVE_HEAD_SMASH, MOVE_WAVE_CRASH},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveClones
    },
    {
        .mon = {
            .specie = SPECIES_BLASTOISE_C,
            .ability = ABILITY_CONTRARY,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_LIQUIDATION, MOVE_CLOSE_COMBAT, MOVE_PLAY_ROUGH, MOVE_HEAT_CRASH},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveClones
    },
    {
        .mon = {
            .specie = SPECIES_ARMORED_MEWTWO,
            .ability = ABILITY_NONE,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_PSYSTRIKE, MOVE_AURA_SPHERE, MOVE_SHADOW_BALL, MOVE_MOONBLAST},
        },
        .description = sText_PokeboxAlexmadEvent,
        .money = 0,
        .check = CheckPokebox_AlexmadEventCompleted
    },
    {
        .mon = {
            .specie = SPECIES_ELECTRODES,
            .ability = ABILITY_MELONSHIELD,
            .nature = NATURE_MODEST,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_JUICY_EXPLOSION, MOVE_ACID_PULP, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN},
        },
        .description = sText_PokeboxWahChallengeOnce, 
        .money = 0,
        .check = CheckPokebox_WahChallengeCompleted
    },
    {
        .mon = {
            .specie = SPECIES_MOLTRES,
            .ability = ABILITY_PRESSURE,
            .nature = NATURE_TIMID,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_FLAMETHROWER, MOVE_AEROBLAST, MOVE_EARTH_POWER, MOVE_MOONBLAST},
        },
        .description = sText_PokeboxWahChallengeOnce, 
        .money = 0,
        .check = CheckPokebox_WahChallengeCompleted
    },
    { 
        .mon = {
            .specie = SPECIES_DRAGONITE,
            .ability = ABILITY_MULTISCALE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_IRON_HEAD, MOVE_DRAGON_CLAW, MOVE_PLAY_ROUGH, MOVE_EXTREME_SPEED},
        },
        .description = sText_PokeboxWahChallengeOnce, 
        .money = 0,
        .check = CheckPokebox_WahChallengeCompleted
    },
    {
        .mon = {
            .specie = SPECIES_KAOSUNE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves = {MOVE_EARTHQUAKE, MOVE_HEAVY_SLAM, MOVE_SOLAR_BLADE, MOVE_HEAT_CRASH},
        },
        .description = sText_PokeboxWahChallengeDifficult,
        .money = 0,
        .check = CheckPokebox_WahChallengeDifficultCompleted
    },
    {
        .mon = {
            .specie = SPECIES_DIRAEI,
            .ability = ABILITY_CONTRARY,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_PSYCHO_BOOST, MOVE_REST, MOVE_DRACO_METEOR, MOVE_HYPNOSIS},
        },
        .description = sText_PokeboxWahChallengeDifficult,
        .money = 0,
        .check = CheckPokebox_WahChallengeDifficultCompleted
    },
    {
        .mon = {
            .specie = SPECIES_DUN,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_PSYCHIC, MOVE_DRAGON_PULSE, MOVE_EARTH_POWER, MOVE_AIR_SLASH},
        },
        .description = sText_PokeboxWahChallengeDifficult,
        .money = 0,
        .check = CheckPokebox_WahChallengeDifficultCompleted
    },
    {
        .mon = {
            .specie = SPECIES_GOROCHU,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_THUNDERBOLT, MOVE_AURA_SPHERE, MOVE_SURF, MOVE_FOCUS_BLAST},
        },
        .description = sText_PokeboxBetaMonQuestionnaire,
        .money = 0,
        .check = CheckPokebox_BetaMonQuestionnaire
    },
    {
        .mon = {
            .specie = SPECIES_TAABAN,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
        },
        .description = sText_PokeboxBetaMonQuestionnaire,
        .money = 0,
        .check = CheckPokebox_BetaMonQuestionnaire
    },
    {
        .mon = {
            .specie = SPECIES_BOMUSHIKAA,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SCALD, MOVE_FLAMETHROWER, MOVE_WATER_SPOUT, MOVE_ERUPTION},
        },
        .description = sText_PokeboxBetaMonQuestionnaire,
        .money = 0,
        .check = CheckPokebox_BetaMonQuestionnaire
    },
    {
        .mon = {
            .specie = SPECIES_MADAAMU,
            .ability = ABILITY_INTIMIDATE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
        },
        .description = sText_PokeboxBetaMonQuestionnaire,
        .money = 0,
        .check = CheckPokebox_BetaMonQuestionnaire
    },
    {
        .mon = {
            .specie = SPECIES_AKUERIA,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_DRAGON_PULSE, MOVE_SCALD, MOVE_ICE_BEAM, MOVE_TRI_ATTACK},
        },
        .description = sText_PokeboxBetaMonQuestionnaire,
        .money = 0,
        .check = CheckPokebox_BetaMonQuestionnaire
    },
    {
        .mon = {
            .specie = SPECIES_LATIKEN,
            .ability = ABILITY_SPEED_BOOST,
            .nature = NATURE_QUIRKY,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_MIST_BALL, MOVE_BLAZE_KICK, MOVE_DRAGON_CLAW, MOVE_DRAIN_PUNCH}
        },
        .description = sText_PokeboxBetaMonQuestionnaire,
        .money = 0,
        .check = CheckPokebox_BetaMonQuestionnaire
    },
    {
        .mon = {
            .specie = SPECIES_FREECH,
            .nature = NATURE_CALM,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_DRAGON_PULSE, MOVE_ICE_BEAM, MOVE_ICE_SHARD, MOVE_RECOVER},
        },
        .description = sText_PokeboxWahDouble,
        .money = 0,
        .check = CheckPokebox_WinWahChallengeDoubleAchievement
    },
    {
        .mon = {
            .specie = SPECIES_VOLCARONA,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_QUIVER_DANCE, MOVE_FIERY_DANCE, MOVE_BUG_BUZZ, MOVE_FLAMETHROWER},
        },
        .description = sText_PokeboxWahDouble,
        .money = 0,
        .check = CheckPokebox_WinWahChallengeDoubleAchievement
    },
    {
        .mon = {
            .specie = SPECIES_GRENINJA,
            .ability = ABILITY_PROTEAN,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_WATER_SHURIKEN, MOVE_SCALD, MOVE_DARK_PULSE, MOVE_SLUDGE_BOMB},
        },
        .description = sText_PokeboxAllCollaborators,
        .money = 0,
        .check = CheckPokebox_DefeatAllCollaboratorsAchievement
    },
    {
        .mon = {
            .specie = SPECIES_FERALIGATR,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_DRAGON_DANCE, MOVE_SLASH, MOVE_LIQUIDATION, MOVE_BODY_SLAM},
        },
        .description = sText_PokeboxAllCollaborators,
        .money = 0,
        .check = CheckPokebox_DefeatAllCollaboratorsAchievement
    },
    {
        .mon = {
            .specie = SPECIES_EING,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 252, 4, 0),
            .isShiny = FALSE,
            .moves = {MOVE_SING, MOVE_HYPER_VOICE, MOVE_DRACO_METEOR, MOVE_SURF},
        },
        .description = sText_PokeboxEingTeams,
        .money = 0,
        .check = CheckPokebox_EingTeamsDefeated
    },
    {
        .mon = {
            .specie = SPECIES_MOLIKAI,
            .nature = NATURE_CAREFUL,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 4, 0),
            .isShiny = FALSE,
            .moves = {MOVE_XQ4ZC0E, MOVE_TEETER_DANCE, MOVE_CROSS_POISON, MOVE_KNOCK_OFF},
        },
        .description = sText_PokeboxMolikai,
        .money = 0,
        .check = CheckPokebox_ReyBooHardBothTeams
    },
    {
        .mon = {
            .specie = SPECIES_OCEADINO,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 0, 4, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_SCALD, MOVE_ICE_BEAM, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB},
        },
        .description = sText_PokeboxBaroTeams,
        .money = 0,
        .check = CheckPokebox_BaroBothTeams
    },
    {
        .mon = {
            .specie = SPECIES_JARDINO,
            .nature = NATURE_JOLLY,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves = {MOVE_DRAIN_PUNCH, MOVE_SEED_BOMB, MOVE_LEAF_BLADE, MOVE_DRAGON_CLAW},
        },
        .description = sText_PokeboxBaroTeams,
        .money = 0,
        .check = CheckPokebox_BaroBothTeams
    },
    {
        .mon = {
            .specie = SPECIES_TYRADINO,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 4),
            .isShiny = FALSE,
            .moves = {MOVE_BLAZE_KICK, MOVE_SHADOW_CLAW, MOVE_THUNDER_PUNCH, MOVE_SKY_UPPERCUT},
        },
        .description = sText_PokeboxBaroTeams,
        .money = 0,
        .check = CheckPokebox_BaroBothTeams
    },
    {
        .mon = {
            .specie = SPECIES_LUGIA_SHADOW,
            .ability = ABILITY_BERSERK,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(0, 4, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_AEROBLAST, MOVE_DARK_PULSE, MOVE_SHADOW_BALL, MOVE_SUCKER_PUNCH},
        },
        .description = sText_PokeboxAllAdmins,
        .money = 0,
        .check = CheckPokebox_DefeatAllAdminsAchievement
    },
    {
        .mon = {
            .specie = SPECIES_GRITESPEC,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL},
        },
        .description = sText_PokeboxWahInverse,
        .money = 0,
        .check = CheckPokebox_WinWahChallengeInverseAchievement
    },
    {
        .mon = {
            .specie = SPECIES_AYEWIRAZ,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves = {MOVE_PLAY_ROUGH, MOVE_CRUNCH, MOVE_POISON_TAIL, MOVE_PSYCHIC_FANGS},
        },
        .description = sText_PokeboxWahInverse,
        .money = 0,
        .check = CheckPokebox_WinWahChallengeInverseAchievement
    },
    {
        .mon = {
            .specie = SPECIES_MICAEL,
            .ability = ABILITY_PRANKSTER,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_VOODOO, MOVE_ASTRAL_BARRAGE, MOVE_DOUBLE_TEAM, MOVE_DESTINY_BOND},
        },
        .description = sText_PokeboxAchievementAvaricia,
        .money = 0,
        .check = CheckPokebox_AchievementAvaricia
    },
    {
        .mon = {
            .specie = SPECIES_PLUGOINK,
            .ability = ABILITY_NONE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_FLAMETHROWER, MOVE_CHARGE_BEAM, MOVE_SNARL, MOVE_THUNDERBOLT},
        },
        .description = sText_PokeboxMetBaroRoomPlugOink,
        .money = 0,
        .check = CheckPokebox_MetBaroRoomPlugOink
    },
    {
        .mon = {
            .specie = SPECIES_SKARMORY,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_DRILL_RUN, MOVE_IRON_HEAD, MOVE_BRAVE_BIRD, MOVE_ROOST},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_CINDERACE,
            .ability = ABILITY_LIBERO,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_PYRO_BALL, MOVE_SMACK_DOWN, MOVE_IRON_HEAD, MOVE_GUNK_SHOT},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_EXCADRILL,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_DRILL_RUN, MOVE_IRON_HEAD, MOVE_ROCK_SLIDE, MOVE_DRAIN_PUNCH},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_AEGISLASH,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_KINGS_SHIELD, MOVE_SWORDS_DANCE, MOVE_IRON_HEAD, MOVE_SHADOW_SNEAK},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_MIMIKYU,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_PLAY_ROUGH, MOVE_SHADOW_CLAW, MOVE_WOOD_HAMMER, MOVE_DRAIN_PUNCH},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_TOXAPEX,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SCALD, MOVE_SLUDGE_WAVE, MOVE_BANEFUL_BUNKER, MOVE_RECOVER},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_FERROTHORN,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_IRON_HEAD, MOVE_SEED_BOMB, MOVE_SPIKES, MOVE_RAPID_SPIN},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_CORVIKNIGHT,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_BRAVE_BIRD, MOVE_IRON_HEAD, MOVE_BODY_PRESS, MOVE_ROOST},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_BLISSEY,
            .nature = NATURE_CALM,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SOFT_BOILED, MOVE_METRONOME, MOVE_HYPER_BEAM, MOVE_PSYCHIC},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_GLISCOR,
            .ability = ABILITY_POISON_HEAL,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 252, 0, 252, 0, 0),
            .isShiny = FALSE,
            .moves = {MOVE_EARTHQUAKE, MOVE_AERIAL_ACE, MOVE_CRABHAMMER, MOVE_KNOCK_OFF},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_AMOONGUSS,
            .nature = NATURE_ADAMANT,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SPORE, MOVE_SEED_BOMB, MOVE_POISON_JAB, MOVE_FOUL_PLAY},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_PORYGON2,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_TRI_ATTACK, MOVE_RECOVER, MOVE_SHADOW_BALL, MOVE_SIGNAL_BEAM},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_HATTERENE,
            .nature = NATURE_CALM,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_CALM_MIND, MOVE_PSYCHIC, MOVE_MOONBLAST, MOVE_MYSTICAL_FIRE},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_SLOWKING_GALAR,
            .ability = ABILITY_CURIOUS_MEDICINE,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_EERIE_SPELL, MOVE_SLUDGE_BOMB, MOVE_AURA_SPHERE, MOVE_RECOVER},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_HEATRAN,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_MAGMA_STORM, MOVE_FLASH_CANNON, MOVE_EARTH_POWER, MOVE_ERUPTION},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 30000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_MACHAMP,
            .ability = ABILITY_NO_GUARD,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = TRUE,
            .moves = {MOVE_DYNAMIC_PUNCH, MOVE_METEOR_MASH, MOVE_DRAIN_PUNCH, MOVE_FISSURE},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_FLAREON,
            .ability = ABILITY_RECKLESS,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_FLARE_BLITZ, MOVE_WILD_CHARGE, MOVE_EXTREME_SPEED, MOVE_RECOVER},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_JOLTEON,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_WATER_PULSE, MOVE_FLAMETHROWER},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_LEAFEON,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_LEAF_BLADE, MOVE_SOLAR_BLADE, MOVE_QUICK_ATTACK, MOVE_LEECH_LIFE},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_GLACEON,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_ICE_BEAM, MOVE_FREEZE_DRY, MOVE_WATER_PULSE, MOVE_SHADOW_BALL},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_SHEDINJA,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SHADOW_SNEAK, MOVE_SUCKER_PUNCH, MOVE_X_SCISSOR, MOVE_LEECH_LIFE},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_WIGGLYTUFF,
            .ability = ABILITY_COMPETITIVE,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_HYPER_VOICE, MOVE_MOONBLAST, MOVE_METRONOME, MOVE_EARTH_POWER},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_KINGDRA,
            .ability = ABILITY_SNIPER,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SCALD, MOVE_DRAGON_PULSE, MOVE_ICE_BEAM, MOVE_HURRICANE},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_ROTOM,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_FOUL_PLAY, MOVE_VOLT_SWITCH},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_CHERRIM,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_ENERGY_BALL, MOVE_SOLAR_BEAM, MOVE_GIGA_DRAIN, MOVE_WEATHER_BALL},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_CACTURNE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = TRUE,
            .moves = {MOVE_SEED_BOMB, MOVE_NIGHT_SLASH, MOVE_DRAIN_PUNCH, MOVE_THUNDER_PUNCH},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_MEGANIUM,
            .nature = NATURE_MODEST,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SOLAR_BEAM, MOVE_SYNTHESIS, MOVE_MOONBLAST, MOVE_WEATHER_BALL},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_STARAPTOR,
            .ability = ABILITY_INTIMIDATE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_AERIAL_ACE, MOVE_BRAVE_BIRD, MOVE_CLOSE_COMBAT, MOVE_ROOST},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_CHESNAUGHT,
            .ability = ABILITY_BULLETPROOF,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_SEED_BOMB, MOVE_DRAIN_PUNCH, MOVE_ROCK_SLIDE, MOVE_SPIKY_SHIELD},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
    {
        .mon = {
            .specie = SPECIES_DELPHOX,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_MYSTICAL_FIRE, MOVE_PSYSHOCK, MOVE_SHADOW_BALL, MOVE_ENERGY_BALL},
        },
        .description = gText_PokeboxBuyThisMon,
        .money = 15000,
        .check = CheckPokebox_isBuyMon
    },
};

STATIC_ASSERT(ARRAY_COUNT(sPokeboxSpeciesList) <= 64, PokeboxSpeciesListExceedsMonActiveBits);

#undef POKEBOX_MON



u8 PokeboxSpeciesList_GetCount(void)
{
    return ARRAY_COUNT(sPokeboxSpeciesList);
}

const struct TeamSelectorMonData *PokeboxSpeciesList_GetMonData(u8 index)
{
    if (index >= PokeboxSpeciesList_GetCount())
        return NULL;

    return &sPokeboxSpeciesList[index].mon;
}

u16 PokeboxSpeciesList_GetSpecie(u8 index)
{
    const struct TeamSelectorMonData *mon = PokeboxSpeciesList_GetMonData(index);

    if (mon == NULL)
        return SPECIES_NONE;

    return mon->specie;
}

const u8 *Get_PokeboxDescription(u8 id) 
{
    return sPokeboxSpeciesList[id].description;
}


//comprobar si el bit esta activo
bool8 Pokebox_IsActive(u8 index)
{
    if (index >= PokeboxSpeciesList_GetCount())
        return FALSE;

    return ((gSaveBlock2Ptr->monActiveOnPokebox >> index) & 1) != 0;
}

//cambiar el bit a activo
bool8 Pokebox_SetActive(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    if ((gSaveBlock2Ptr->monActiveOnPokebox >> id) & 1)
        return FALSE;

    gSaveBlock2Ptr->monActiveOnPokebox |= (1ull << id);

    return TRUE;
}


static bool8 CheckPokebox_Active(u8 id)
{
    return FALSE;
}

static bool8 CheckPokebox_WahChallengeCompleted(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_WIN_WAH_CHALLENGE);
}

static bool8 CheckPokebox_WahChallengeDifficultCompleted(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_DEFEAT_WAH_CHALLENGE_HARD_MODE);
}

static bool8 CheckPokebox_AlexmadEventGiveClones(u8 id)
{
    (void)id;
    return FlagGet(FLAG_ALEXMAD_EVENT_GIVE_CLONES);
}

static bool8 CheckPokebox_AlexmadEventCompleted(u8 id)
{
    (void)id;
    return FlagGet(FLAG_ALEXMAD_EVENT_COMPLETED);
}

static bool8 CheckPokebox_AlexmadEventGiveLegendaries(u8 id)
{
    (void)id;
    return FlagGet(FLAG_ALEXMAD_EVENT_GIVE_LEGENDARIES);
}

static bool8 CheckPokebox_AchievementAvaricia(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_AVARICIA);
}

static bool8 CheckPokebox_MetBaroRoomPlugOink(u8 id)
{
    (void)id;
    return FlagGet(FLAG_MET_BARO_ROOM_PLUGOINK);
}

static bool8 CheckPokebox_EingTeamsDefeated(u8 id)
{
    (void)id;
    return FlagGet(FLAG_POKEBOX_WON_EING_MAIN) && FlagGet(FLAG_POKEBOX_WON_EING_ALTERNATIVE);
}

static bool8 CheckPokebox_ReyBooHardBothTeams(u8 id)
{
    (void)id;
    return FlagGet(FLAG_POKEBOX_WON_REYBOO_MAIN_HARD) && FlagGet(FLAG_POKEBOX_WON_REYBOO_ALT_HARD);
}

static bool8 CheckPokebox_BaroBothTeams(u8 id)
{
    (void)id;
    return FlagGet(FLAG_POKEBOX_WON_BARO_MAIN) && FlagGet(FLAG_POKEBOX_WON_BARO_ALTERNATIVE);
}

static bool8 CheckPokebox_DefeatAllAdminsAchievement(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_DEFEAT_ALL_ADMINS);
}

static bool8 CheckPokebox_DefeatAllCollaboratorsAchievement(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS);
}

static bool8 CheckPokebox_WinWahChallengeDoubleAchievement(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_WIN_WAH_CHALLENGE_DOUBLE);
}

static bool8 CheckPokebox_WinWahChallengeInverseAchievement(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_WIN_WAH_CHALLENGE_INVERSE);
}

static bool8 CheckPokebox_BetaMonQuestionnaire(u8 id)
{
    switch (PokeboxSpeciesList_GetSpecie(id))
    {
    case SPECIES_GOROCHU:
        return FlagGet(FLAG_POKEBOX_UNLOCK_BETA_GOROCHU);
    case SPECIES_TAABAN:
        return FlagGet(FLAG_POKEBOX_UNLOCK_BETA_TAABAN);
    case SPECIES_BOMUSHIKAA:
        return FlagGet(FLAG_POKEBOX_UNLOCK_BETA_BOMUSHIKAA);
    case SPECIES_MADAAMU:
        return FlagGet(FLAG_POKEBOX_UNLOCK_BETA_MADAAMU);
    case SPECIES_AKUERIA:
        return FlagGet(FLAG_POKEBOX_UNLOCK_BETA_AKUERIA);
    case SPECIES_LATIKEN:
        return FlagGet(FLAG_POKEBOX_UNLOCK_BETA_LATIKEN);
    default:
        return FALSE;
    }
}

static bool8 CheckPokebox_isBuyMon(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    if(sPokeboxSpeciesList[id].money <= 0)
        return FALSE;

    return Pokebox_IsActive(id);
}

bool8 CheckPokebox_IsActive(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    return sPokeboxSpeciesList[id].check(id);
}

bool8 PokeboxSpecies_TryUnlockNew(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;
    if (Pokebox_IsActive(id))
        return FALSE;
    if (!sPokeboxSpeciesList[id].check(id))
        return FALSE;
    Pokebox_SetActive(id);
    return TRUE;
}

u32 PokeboxSpecies_GetMoney(u8 id)
{
    return sPokeboxSpeciesList[id].money;
}

bool8 PokeboxSpecies_EnoughtMoneyToBuy(u8 id)
{
    u32 money = GetMoney(&gSaveBlock1Ptr->money);
    u32 price = PokeboxSpecies_GetMoney(id);

    if(Pokebox_IsActive(id))
        return FALSE;

    if (price == 0)
        return FALSE;

    return money >= price;
}

bool8 PokeboxSpecies_BufferBuyOfferFromSpecies(u16 species)
{
    u8 i;
    u8 count = PokeboxSpeciesList_GetCount();
    u32 money;

    for (i = 0; i < count; i++)
    {
        if (PokeboxSpeciesList_GetSpecie(i) != species)
            continue;

        money = PokeboxSpecies_GetMoney(i);
        if (money == 0)
        {
            gStringVar1[0] = EOS;
            gStringVar2[0] = EOS;
            return FALSE;
        }

        ConvertIntToDecimalStringN(gStringVar1, money, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
        StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        StringCopy(gStringVar2, gStringVar4);
        StringCopy(gStringVar1, GetSpeciesName(species));
        return TRUE;
    }

    gStringVar1[0] = EOS;
    gStringVar2[0] = EOS;
    return FALSE;
}
