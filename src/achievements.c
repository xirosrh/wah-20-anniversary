#include "global.h"
#include "event_data.h"
#include "constants/achievements.h"
#include "constants/vars.h"
#include "achievements.h"

struct AchievementEntry
{
    const u8 *title;
    const u8 *description;
    u8 target;
    bool8 (*check)(u8 id);
};

static bool8 CheckDummyChallenge(u8 id);
static bool8 CheckWinWahChallenge(u8 id);
static bool8 CheckDefeatAllAdmins(u8 id);
static bool8 CheckWinWahChallengeXTimes(u8 id);
static bool8 CheckDefeatAllCollaborators(u8 id);

static const struct AchievementEntry sAchievements[ACHIEVEMENT_COUNT] = {
    [ACHIEVEMENT_WIN_WAH_CHALLENGE] = {
        .title = COMPOUND_STRING("Supera todas las salas"),
        .description = COMPOUND_STRING("Supera una vez el desafio"),
        .target = TRUE,
        .check = CheckWinWahChallenge,
    },
    [ACHIEVEMENT_DEFEAT_ALL_ADMINS] = {
        .title = COMPOUND_STRING("Derrota a todos los admins"),
        .description = COMPOUND_STRING("Derrota a todos los admins de WAH.\nCon ganar las salas no será suficiente."),
        .target = TRUE,
        .check = CheckDefeatAllAdmins,
    },
    [ACHIEVEMENT_WIN_WAH_CHALLENGE_5_TIMES] = {
        .title = COMPOUND_STRING("Basea la existencia de los admins"),
        .description = COMPOUND_STRING("Supera el desafio 5 veces"),
        .target = 5,
        .check = CheckWinWahChallengeXTimes,
    },
    [ACHIEVEMENT_LOSE_50_TIMES] = {
        .title = COMPOUND_STRING("Humillate hasta el fondo"),
        .description = COMPOUND_STRING("Pierde el desafio 50 veces"),
        .target = 0,
        .check = CheckDummyChallenge,
    },
    [ACHIEVEMENT_DEFEAT_ALL_COLLABORATORS] = {
        .title = COMPOUND_STRING("Derrota a los colaboradores"),
        .description = COMPOUND_STRING("Derrota a todos los colaboradores\ndel Lobby"),
        .target = TRUE,
        .check = CheckDefeatAllCollaborators,
    },
};

static bool8 CheckDummyChallenge(u8 id)
{
    (void)id;
    return TRUE;
}

static bool8 CheckWinWahChallenge(u8 id)
{
    return FlagGet(FLAG_WAH_CHALLENGE_COMPLETED) == sAchievements[id].target;
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
           FlagGet(FLAG_DEFEATED_COLLABORATORS_ROOM_GAMEBOYCL);
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
