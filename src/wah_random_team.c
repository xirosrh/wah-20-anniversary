#include "global.h"
#include "event_data.h"
#include "pokebox_manager.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "random.h"
#include "team_selector.h"
#include "wah_random_team.h"
#include "constants/var_values.h"
#include "constants/vars.h"

#define WAH_RANDOM_TEAM_BACKUP_BOX        0
#define WAH_RANDOM_TEAM_BACKUP_FIRST_SLOT 0

STATIC_ASSERT(PARTY_SIZE == MAX_TEAM_SIZE, WahRandomTeamMustFillParty);
STATIC_ASSERT(WAH_RANDOM_TEAM_BACKUP_FIRST_SLOT + PARTY_SIZE <= IN_BOX_COUNT, WahRandomTeamBackupMustFitInBox);

static bool8 IsSpeciesAlreadySelected(u16 species, const u16 *selectedSpecies, u8 selectedCount)
{
    u8 i;

    for (i = 0; i < selectedCount; i++)
    {
        if (selectedSpecies[i] == species)
            return TRUE;
    }

    return FALSE;
}

static bool8 IsEligibleCandidate(const struct TeamSelectorMonData *mon, const u16 *selectedSpecies, u8 selectedCount)
{
    return mon != NULL
        && mon->specie != SPECIES_NONE
        && !IsSpeciesAlreadySelected(mon->specie, selectedSpecies, selectedCount);
}

static u16 CountEligibleCandidates(const u16 *selectedSpecies, u8 selectedCount)
{
    u16 count = 0;
    u16 i;

    for (i = 0; i < NUM_MONS_POOL; i++)
    {
        if (IsEligibleCandidate(&gAllTeamMons[i], selectedSpecies, selectedCount))
            count++;
    }

    for (i = 0; i < PokeboxSpeciesList_GetCount(); i++)
    {
        if (Pokebox_IsActive(i)
         && IsEligibleCandidate(PokeboxSpeciesList_GetMonData(i), selectedSpecies, selectedCount))
            count++;
    }

    return count;
}

static const struct TeamSelectorMonData *GetEligibleCandidate(u16 candidateIndex, const u16 *selectedSpecies, u8 selectedCount)
{
    const struct TeamSelectorMonData *mon;
    u16 i;

    for (i = 0; i < NUM_MONS_POOL; i++)
    {
        mon = &gAllTeamMons[i];
        if (!IsEligibleCandidate(mon, selectedSpecies, selectedCount))
            continue;

        if (candidateIndex == 0)
            return mon;
        candidateIndex--;
    }

    for (i = 0; i < PokeboxSpeciesList_GetCount(); i++)
    {
        if (!Pokebox_IsActive(i))
            continue;

        mon = PokeboxSpeciesList_GetMonData(i);
        if (!IsEligibleCandidate(mon, selectedSpecies, selectedCount))
            continue;

        if (candidateIndex == 0)
            return mon;
        candidateIndex--;
    }

    return NULL;
}

bool8 WahRandomTeam_HasBackup(void)
{
    u8 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (!GetBoxMonData(GetBoxedMonPtr(WAH_RANDOM_TEAM_BACKUP_BOX, WAH_RANDOM_TEAM_BACKUP_FIRST_SLOT + i),
                           MON_DATA_SANITY_HAS_SPECIES, NULL))
            return FALSE;
    }

    return TRUE;
}

bool8 WahRandomTeam_IsActive(void)
{
    return VarGet(VAR_WAH_CHALLENGE_MODE) == VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM;
}

bool8 WahRandomTeam_RestoreAndClear(void)
{
    u8 i;

    if (!WahRandomTeam_HasBackup())
        return FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        BoxMonAtToMon(WAH_RANDOM_TEAM_BACKUP_BOX, WAH_RANDOM_TEAM_BACKUP_FIRST_SLOT + i, &gPlayerParty[i]);
        ZeroBoxMonAt(WAH_RANDOM_TEAM_BACKUP_BOX, WAH_RANDOM_TEAM_BACKUP_FIRST_SLOT + i);
    }

    gPlayerPartyCount = PARTY_SIZE;
    return TRUE;
}

bool8 WahRandomTeam_BackupParty(void)
{
    u8 i;

    if (CalculatePlayerPartyCount() != PARTY_SIZE)
        return FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
        SetBoxMonAt(WAH_RANDOM_TEAM_BACKUP_BOX, WAH_RANDOM_TEAM_BACKUP_FIRST_SLOT + i, &gPlayerParty[i].box);

    return TRUE;
}

bool8 WahRandomTeam_GenerateParty(void)
{
    const struct TeamSelectorMonData *mon;
    u16 selectedSpecies[PARTY_SIZE];
    u16 candidateCount;
    u8 i;

    if (!WahRandomTeam_HasBackup())
        return FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        candidateCount = CountEligibleCandidates(selectedSpecies, i);
        if (candidateCount == 0)
        {
            WahRandomTeam_RestoreAndClear();
            return FALSE;
        }

        mon = GetEligibleCandidate(RandomUniform(RNG_NONE, 0, candidateCount - 1), selectedSpecies, i);
        if (mon == NULL)
        {
            WahRandomTeam_RestoreAndClear();
            return FALSE;
        }

        selectedSpecies[i] = mon->specie;
        GiveMonTeamFromSelector(i, mon, FALSE);
    }

    gPlayerPartyCount = PARTY_SIZE;
    return TRUE;
}

bool8 WahRandomTeam_BackupAndGenerate(void)
{
    if (!WahRandomTeam_BackupParty())
        return FALSE;

    return WahRandomTeam_GenerateParty();
}

void Special_StartWahRandomTeam(void)
{
    gSpecialVar_Result = WahRandomTeam_BackupAndGenerate();
}
