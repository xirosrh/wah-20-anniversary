#include "global.h"
#include "event_data.h"
#include "constants/vars.h"
#include "achievements.h"

struct AchievementEntry
{
    const u8 *title;
    const u8 *description;
    u8 target;
    bool8 (*check)(u8 taskIndex);
};

static bool8 CheckDummyChallenge(u8 taskIndex);
static bool8 CheckWinWahChallenge(u8 taskIndex);
static bool8 CheckWinWahChallengeXTimes(u8 taskIndex);
static bool8 CheckDefeatAllCollaborators(u8 taskIndex);

static const struct AchievementEntry sAchievements[] =
{
    {
        .title = COMPOUND_STRING("Fulmina a los admins"),
        .description = COMPOUND_STRING("Supera una vez el desafio"),
        .target = TRUE,
        .check = CheckWinWahChallenge,
    },
    {
        .title = COMPOUND_STRING("Basea la existencia de los admins"),
        .description = COMPOUND_STRING("Supera el desafio 5 veces"),
        .target = 5,
        .check = CheckWinWahChallengeXTimes,
    },
    {
        .title = COMPOUND_STRING("Humillate hasta el fondo"),
        .description = COMPOUND_STRING("Pierde el desafio 50 veces"),
        .target = 0,
        .check = CheckDummyChallenge,
    },
    {
        .title = COMPOUND_STRING("Derrota a los colaboradores"),
        .description = COMPOUND_STRING("Derrota a todos los colaboradores\ndel Lobby"),
        .target = TRUE,
        .check = CheckDefeatAllCollaborators,
    }
};

static bool8 CheckDummyChallenge(u8 taskIndex)
{
    (void)taskIndex;
    return TRUE;
}

static bool8 CheckWinWahChallenge(u8 taskIndex)
{
    return FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) == sAchievements[taskIndex].target;
}

static bool8 CheckWinWahChallengeXTimes(u8 taskIndex)
{
    return VarGet(VAR_WAH_CHALLENGE_COMPLETION_COUNT) >= sAchievements[taskIndex].target;
}

static bool8 CheckDefeatAllCollaborators(u8 taskIndex)
{
    return FlagGet(FLAG_DEFEATED_LOBBY_KAKTUS) &&
           FlagGet(FLAG_DEFEATED_LOBBY_ERKEY) &&
           FlagGet(FLAG_DEFEATED_LOBBY_MICOLO) &&
           FlagGet(FLAG_DEFEATED_LOBBY_GAMEBOYCL) == sAchievements[taskIndex].target;
}

u8 Achievement_GetCount(void)
{
    return ARRAY_COUNT(sAchievements);
}

const u8 *Achievement_GetTitle(u8 index)
{
    if (index >= ARRAY_COUNT(sAchievements))
        return NULL;
    return sAchievements[index].title;
}

const u8 *Achievement_GetDescription(u8 index)
{
    if (index >= ARRAY_COUNT(sAchievements))
        return NULL;
    return sAchievements[index].description;
}

bool8 Achievement_IsComplete(u8 index)
{
    if (index >= ARRAY_COUNT(sAchievements))
        return FALSE;
    return sAchievements[index].check(index);
}
