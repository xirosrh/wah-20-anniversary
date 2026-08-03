#include "global.h"
#include "event_data.h"
#include "wah_challenge.h"
#include "wah_random_team.h"
#include "constants/flags.h"
#include "constants/opponents.h"
#include "constants/var_values.h"
#include "constants/vars.h"

static const u16 sWahAdminDefeatedFlags[] =
{
    FLAG_DEFEATED_ADMIN_OMEGA,
    FLAG_DEFEATED_ADMIN_GOCE,
    FLAG_DEFEATED_ADMINS_SAYER_AND_BLAX,
    FLAG_DEFEATED_ADMIN_AGUIAR,
    FLAG_DEFEATED_ADMIN_JACK_JOHNSON,
    FLAG_DEFEATED_ADMIN_ANGEL,
    FLAG_DEFEATED_ADMIN_OZUMAS,
    FLAG_DEFEATED_ADMIN_SCAREX,
    FLAG_DEFEATED_ADMIN_DAVZERO,
    FLAG_DEFEATED_ADMIN_BARO,
    FLAG_DEFEATED_ADMIN_CHEVE,
    FLAG_DEFEATED_ADMIN_REY_BOO,
    FLAG_DEFEATED_ADMIN_COSARARA,
    FLAG_DEFEATED_ADMINS_KATHERINE_AND_DRIVE,
    FLAG_DEFEATED_ADMIN_REONEKY,
    FLAG_DEFEATED_ADMIN_GALLEGO,
    FLAG_DEFEATED_ADMIN_EING,
    FLAG_DEFEATED_ADMINS_TOKYN_AND_WAR,
    FLAG_DEFEATED_ADMINS_JAVI4315_AND_JAVS,
    FLAG_DEFEATED_ADMIN_SERGIO,
    FLAG_DEFEATED_ADMIN_XIROS,
    FLAG_DEFEATED_ADMIN_KLEIN,
    FLAG_DEFEATED_ADMIN_PKPOWER,
};

static const u16 sWahChallengeTemporaryFlags[] =
{
    FLAG_FORCE_DOUBLE_BATTLE,
    FLAG_INVERSE_BATTLE,
    FLAG_WAH_CHALLENGE_STARTED_WITH_ELECTRODES,
    FLAG_WAH_CHALLENGE_STARTED_WITHOUT_LEGENDARIES,
    FLAG_WAH_CHALLENGE_FINISHED_WITH_ELECTRODES,
    FLAG_WAH_CHALLENGE_FINISHED_WITHOUT_LEGENDARIES,
};

void ResetWahChallenge(void)
{
    u16 trainerId;
    u8 i;

    // The mode must remain available until the temporary party is restored.
    if (WahRandomTeam_IsActive())
        WahRandomTeam_RestoreAndClear();

    for (i = 0; i < ARRAY_COUNT(sWahAdminDefeatedFlags); i++)
        FlagClear(sWahAdminDefeatedFlags[i]);

    for (trainerId = TRAINER_WAH_ADMIN_CHEVE_MAIN;
         trainerId <= TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE;
         trainerId++)
        TrainerFlagClear(trainerId);

    for (i = 0; i < ARRAY_COUNT(sWahChallengeTemporaryFlags); i++)
        FlagClear(sWahChallengeTemporaryFlags[i]);

    VarSet(VAR_SERGIO_ROOM_STATE, 0);
    RandomizeWahAdminTeams();
    VarSet(VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_NONE);
}
