#include "global.h"
#include "event_data.h"
#include "constants/achievements.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/maps.h"
#include "achievements.h"
#include "constants/difficulty.h"
#include "difficulty.h"
#include "pokemon.h"
#include "money.h"
#include "pokebox_manager.h"

#define COLLABORATORS_NO_FAINT_PROGRESS_VAR VAR_TEMP_0
#define COLLABORATORS_NO_FAINT_ALL_BITS ((1 << 10) - 1)

struct AchievementEntry
{
    const u8 *title;
    const u8 *description;
    u32 target;
    bool8 (*check)(u8 id);
};

static bool8 CheckUnlockAllPokemon(u8 id);
static bool8 CheckWinWahChallenge(u8 id);
static bool8 CheckWinWahChallengeDouble(u8 id);
static bool8 CheckWinWahChallengeInverse(u8 id);
static bool8 CheckWinWahChallengeRandom(u8 id);
static bool8 CheckDefeatAllAdmins(u8 id);
static bool8 CheckWinWahChallengeXTimes(u8 id);
static bool8 CheckDefeatAllCollaborators(u8 id);
static bool8 CheckDefeatAllCollaboratorsNoFaints(u8 id);
static bool8 CheckWinWahChallengeHardMode(u8 id);
static bool8 CheckWinWahChallengeWithElectrodeS(u8 id);
static bool8 CheckWinWahChallengeWithoutLegendaries(u8 id);
static bool8 CheckFoundTileKecleon(u8 id);
static bool8 CheckAvaricia(u8 id);
static bool8 CheckDefeatTranslatorRaizen(u8 id);

static const struct AchievementEntry sAchievements[ACHIEVEMENT_COUNT] = {
    [ACHIEVEMENT_WIN_WAH_CHALLENGE] = {
        .title = COMPOUND_STRING("Domina las salas"),
        .description = COMPOUND_STRING("¡Supera el desafío completo una vez\ny conquista el salón de la fama!"),
        .target = TRUE,
        .check = CheckWinWahChallenge,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_DOUBLE] = {
        .title = COMPOUND_STRING("Doble o nada"),
        .description = COMPOUND_STRING("Supera el desafío en modalidad\nbatallas dobles. Dos decisiones\npor turno, ¿lo lograrás?"),
        .target = TRUE,
        .check = CheckWinWahChallengeDouble,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_INVERSE] = {
        .title = COMPOUND_STRING("El mundo al revés"),
        .description = COMPOUND_STRING("Supera el desafío en modo batallas\ninversas. Las efectividades de tipo\nse invierten. ¡Adapta tu estrategia!"),
        .target = TRUE,
        .check = CheckWinWahChallengeInverse,
    },
    [ACHIEVEMENT_DEFEAT_ALL_ADMINS] = {
        .title = COMPOUND_STRING("Derrota a todos los admins"),
        .description = COMPOUND_STRING("Derrota a todos los admins de WAH.\n¡Superar el desafío de las salas\nno será suficiente!"),
        .target = TRUE,
        .check = CheckDefeatAllAdmins,
    },
    [ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS] = {
        .title = COMPOUND_STRING("Limpieza de la zona creativa"),
        .description = COMPOUND_STRING("Derrota a todos los colaboradores\nde la zona creativa.\nNadie queda sin probar tu nivel."),
        .target = TRUE,
        .check = CheckDefeatAllCollaborators,
    },
    [ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS_NO_FAINTS] = {
        .title = COMPOUND_STRING("Zona creativa impecable"),
        .description = COMPOUND_STRING("Derrota a todos los colaboradores\nsin salir de su sala y sin que se\ndebilite ningún Pokémon."),
        .target = COLLABORATORS_NO_FAINT_ALL_BITS,
        .check = CheckDefeatAllCollaboratorsNoFaints,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_5_TIMES] = {
        .title = COMPOUND_STRING("Pesadilla recurrente"),
        .description = COMPOUND_STRING("Supera el desafío cinco veces.\nYa no es suerte. Es obsesión."),
        .target = 5,
        .check = CheckWinWahChallengeXTimes,
    },
    [ACHIEVEMENT_DEFEAT_WAH_CHALLENGE_HARD_MODE] = {
        .title = COMPOUND_STRING("Solo para expertos"),
        .description = COMPOUND_STRING("Supera el desafío en modo difícil.\nAquí es donde se separan los\nbuenos de los mejores."),
        .target = TRUE,
        .check = CheckWinWahChallengeHardMode,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_WITH_ELECTRODES] = {
        .title = COMPOUND_STRING("La sandía explosiva"),
        .description = COMPOUND_STRING("Supera el desafío con Electrode\nSandía en tu equipo de principio\na fin."),
        .target = TRUE,
        .check = CheckWinWahChallengeWithElectrodeS,
    },
    [UNLOCK_ALL_POKEMON] = {
        .title = COMPOUND_STRING("Colección completa"),
        .description = COMPOUND_STRING("Consigue todos los Pokémon que el\njuego te permite desbloquear.\nYa no queda nada por descubrir."),
        .target = TRUE,
        .check = CheckUnlockAllPokemon,
    },
    [ACHIEVEMENT_FOUND_TILE_KECLEON] = {
        .title = COMPOUND_STRING("Tile al descubierto"),
        .description = COMPOUND_STRING("Encuentra a Tile (Kecleon) con el\nDetector Devon por primera vez.\n¡Ningún camuflaje es para siempre!"),
        .target = TRUE,
        .check = CheckFoundTileKecleon,
    },
    [ACHIEVEMENT_AVARICIA] = {
        .title = COMPOUND_STRING("Avaricia"),
        .description = COMPOUND_STRING("Acumula 300000 de dinero.\nNo todo en la vida es combatir,\npero ayuda a llenar la cartera."),
        .target = 300000,
        .check = CheckAvaricia,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_WITHOUT_LEGENDARIES] = {
        .title = COMPOUND_STRING("Camino sin leyendas"),
        .description = COMPOUND_STRING("Supera el desafío sin ningún\nPokémon legendario ni mítico\nen tu equipo, de principio a fin."),
        .target = TRUE,
        .check = CheckWinWahChallengeWithoutLegendaries,
    },
    [ACHIEVEMENT_DEFEAT_TRANSLATOR_RAIZEN] = {
        .title = COMPOUND_STRING("Perdido en la traducción"),
        .description = COMPOUND_STRING("Derrota al traductor en la zona\nde descanso. Hay victorias que\nno necesitan traducción."),
        .target = TRUE,
        .check = CheckDefeatTranslatorRaizen,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM] = {
        .title = COMPOUND_STRING("Pura suerte"),
        .description = COMPOUND_STRING("Supera el desafío en modo\nequipo aleatorio.\n¿La suerte estará de tu lado?"),
        .target = TRUE,
        .check = CheckWinWahChallengeRandom,
    },
};

static bool8 CheckWinWahChallenge(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) == sAchievements[id].target;
}

static bool8 CheckWinWahChallengeHardMode(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) == sAchievements[id].target && GetCurrentDifficultyLevel() == DIFFICULTY_HARD;
}

static bool8 CheckWinWahChallengeWithElectrodeS(u8 id)
{
    if (FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) != sAchievements[id].target)
        return FALSE;

    return FlagGet(FLAG_WAH_CHALLENGE_STARTED_WITH_ELECTRODES)
        && FlagGet(FLAG_WAH_CHALLENGE_FINISHED_WITH_ELECTRODES);
}

static bool8 CheckWinWahChallengeWithoutLegendaries(u8 id)
{
    if (FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) != sAchievements[id].target)
        return FALSE;

    return FlagGet(FLAG_WAH_CHALLENGE_STARTED_WITHOUT_LEGENDARIES)
        && FlagGet(FLAG_WAH_CHALLENGE_FINISHED_WITHOUT_LEGENDARIES);
}

static bool8 CheckUnlockAllPokemon(u8 id)
{
    u8 i;
    u8 count = PokeboxSpeciesList_GetCount();

    (void)id;

    for (i = 0; i < count; i++)
    {
        if (!Pokebox_IsActive(i))
            return FALSE;
    }

    return TRUE;
}

static bool8 CheckFoundTileKecleon(u8 id)
{
    return FlagGet(FLAG_FOUND_TILE_KECLEON) == sAchievements[id].target;
}

static bool8 CheckAvaricia(u8 id)
{
    return GetMoney(&gSaveBlock1Ptr->money) >= sAchievements[id].target;
}

static bool8 CheckDefeatTranslatorRaizen(u8 id)
{
    return FlagGet(FLAG_DEFEATED_REST_ROOM_RAIZEN) == sAchievements[id].target;
}





static bool8 CheckWinWahChallengeDouble(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_DOUBLE_COMPLETED) == sAchievements[id].target;
}

static bool8 CheckWinWahChallengeInverse(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_INVERSE_COMPLETED) == sAchievements[id].target;
}

static bool8 CheckWinWahChallengeRandom(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_RANDOM_COMPLETED) == sAchievements[id].target;
}

static bool8 CheckWinWahChallengeXTimes(u8 id)
{
    return VarGet(VAR_WAH_CHALLENGE_COMPLETION_COUNT) >= sAchievements[id].target;
}

static bool8 CheckDefeatAllCollaborators(u8 id)
{
    return FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_KAKTUS) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_ERKEY) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_MICOLO) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_MRNIGHTOLOGY) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_GOSUTO) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_ALEXMAD) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_ACIMUT) &&
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_RYUZAKI) && 
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_CACO);
}

static bool8 CheckDefeatAllCollaboratorsNoFaints(u8 id)
{
    return gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_COLLABORATORS_ROOM)
        && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_COLLABORATORS_ROOM)
        && VarGet(COLLABORATORS_NO_FAINT_PROGRESS_VAR) == sAchievements[id].target;
}

static bool8 CheckDefeatAllAdmins(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) && FlagGet(FLAG_DEFEATED_LOBBY_ROXAS);
}

u8 Achievement_GetCount(void)
{
    return ACHIEVEMENT_COUNT;
}

const u8 *Achievement_GetTitle(u8 index)
{
    if (index >= ACHIEVEMENT_COUNT)
        return NULL;
    return sAchievements[index].title;
}

const u8 *Achievement_GetDescription(u8 index)
{
    if (index >= ACHIEVEMENT_COUNT)
        return NULL;
    return sAchievements[index].description;
}

bool8 Achievement_IsComplete(u8 index)
{
    if (index >= ACHIEVEMENT_COUNT)
        return FALSE;
    return (gSaveBlock2Ptr->achievements >> index) & 1;
}

bool8 Achievement_CheckAndMarkComplete(u8 id)
{
    if (id >= ACHIEVEMENT_COUNT)
        return FALSE;
    if ((gSaveBlock2Ptr->achievements >> id) & 1)
        return FALSE;
    if (!sAchievements[id].check(id))
        return FALSE;
    gSaveBlock2Ptr->achievements |= (1u << id);
    return TRUE;
}
