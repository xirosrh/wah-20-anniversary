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
        .title = COMPOUND_STRING("Master the Rooms"),
        .description = COMPOUND_STRING("Beat the full challenge once\nand conquer the Hall of Fame!"),
        .target = TRUE,
        .check = CheckWinWahChallenge,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_DOUBLE] = {
        .title = COMPOUND_STRING("Double or Nothing"),
        .description = COMPOUND_STRING("Beat the challenge in Double\nBattle mode. Two decisions\nper turn - can you do it?"),
        .target = TRUE,
        .check = CheckWinWahChallengeDouble,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_INVERSE] = {
        .title = COMPOUND_STRING("The World Upside Down"),
        .description = COMPOUND_STRING("Beat the challenge in Inverse\nBattle mode. Type matchups are\nflipped. Adapt your strategy!"),
        .target = TRUE,
        .check = CheckWinWahChallengeInverse,
    },
    [ACHIEVEMENT_DEFEAT_ALL_ADMINS] = {
        .title = COMPOUND_STRING("Defeat All Admins"),
        .description = COMPOUND_STRING("Beat every WAH admin.\nClearing the room challenge\nwon't be enough!"),
        .target = TRUE,
        .check = CheckDefeatAllAdmins,
    },
    [ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS] = {
        .title = COMPOUND_STRING("Creative Zone Cleanup"),
        .description = COMPOUND_STRING("Defeat every contributor in the\nCreative Zone. Leave no one\nuntested by your skill."),
        .target = TRUE,
        .check = CheckDefeatAllCollaborators,
    },
    [ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS_NO_FAINTS] = {
        .title = COMPOUND_STRING("Flawless Creative Zone"),
        .description = COMPOUND_STRING("Beat every contributor without\nleaving their room and without\nany Pokémon fainting."),
        .target = COLLABORATORS_NO_FAINT_ALL_BITS,
        .check = CheckDefeatAllCollaboratorsNoFaints,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_5_TIMES] = {
        .title = COMPOUND_STRING("Recurring Nightmare"),
        .description = COMPOUND_STRING("Beat the challenge five times.\nIt's not luck anymore. It's obsession."),
        .target = 5,
        .check = CheckWinWahChallengeXTimes,
    },
    [ACHIEVEMENT_DEFEAT_WAH_CHALLENGE_HARD_MODE] = {
        .title = COMPOUND_STRING("Experts Only"),
        .description = COMPOUND_STRING("Beat the challenge on Hard mode.\nThis is where the good are\nseparated from the best."),
        .target = TRUE,
        .check = CheckWinWahChallengeHardMode,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_WITH_ELECTRODES] = {
        .title = COMPOUND_STRING("The Explosive Watermelon"),
        .description = COMPOUND_STRING("Beat the challenge with Watermelon\nElectrode on your team from start\nto finish."),
        .target = TRUE,
        .check = CheckWinWahChallengeWithElectrodeS,
    },
    [UNLOCK_ALL_POKEMON] = {
        .title = COMPOUND_STRING("Complete Collection"),
        .description = COMPOUND_STRING("Unlock every Pokémon the game\nlets you obtain. There is nothing\nleft to discover."),
        .target = TRUE,
        .check = CheckUnlockAllPokemon,
    },
    [ACHIEVEMENT_FOUND_TILE_KECLEON] = {
        .title = COMPOUND_STRING("Tile Uncovered"),
        .description = COMPOUND_STRING("Find Tile (Kecleon) with the\nDevon Detector for the first time.\nNo camouflage lasts forever!"),
        .target = TRUE,
        .check = CheckFoundTileKecleon,
    },
    [ACHIEVEMENT_AVARICIA] = {
        .title = COMPOUND_STRING("Greed"),
        .description = COMPOUND_STRING("Save up 300000 in money.\nNot all of life is battling,\nbut it helps fill your wallet."),
        .target = 300000,
        .check = CheckAvaricia,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_WITHOUT_LEGENDARIES] = {
        .title = COMPOUND_STRING("Path Without Legends"),
        .description = COMPOUND_STRING("Beat the challenge without any\nLegendary or Mythical Pokémon\non your team, from start to finish."),
        .target = TRUE,
        .check = CheckWinWahChallengeWithoutLegendaries,
    },
    [ACHIEVEMENT_DEFEAT_TRANSLATOR_RAIZEN] = {
        .title = COMPOUND_STRING("Lost in Translation"),
        .description = COMPOUND_STRING("Defeat the translator in the\nrest area. Some victories\ndon't need translation."),
        .target = TRUE,
        .check = CheckDefeatTranslatorRaizen,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM] = {
        .title = COMPOUND_STRING("Pure Luck"),
        .description = COMPOUND_STRING("Beat the challenge in\nRandom Team mode.\nWill luck be on your side?"),
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
