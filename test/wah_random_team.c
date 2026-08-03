#include "global.h"
#include "achievements.h"
#include "event_data.h"
#include "load_save.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "team_selector.h"
#include "test/test.h"
#include "wah_challenge.h"
#include "wah_random_team.h"
#include "constants/achievements.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/pokemon.h"
#include "constants/var_values.h"
#include "constants/vars.h"

static const u16 sOriginalSpecies[PARTY_SIZE] =
{
    SPECIES_BULBASAUR,
    SPECIES_CHARMANDER,
    SPECIES_SQUIRTLE,
    SPECIES_PIKACHU,
    SPECIES_EEVEE,
    SPECIES_CROBAT,
};

static void CreateOriginalParty(struct BoxPokemon *originalBoxMons)
{
    u8 i;

    memset(gPlayerParty, 0, sizeof(gPlayerParty));
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u32 item = ITEM_LEFTOVERS;

        CreateMon(&gPlayerParty[i], sOriginalSpecies[i], 50 + i, 31, TRUE, i + 1, OT_ID_PRESET, 0x12340000 + i);
        SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &item);
        SetMonMoveSlot(&gPlayerParty[i], MOVE_PROTECT, 0);
        originalBoxMons[i] = gPlayerParty[i].box;
    }
    gPlayerPartyCount = PARTY_SIZE;
}

static bool32 MonMatchesConfig(struct Pokemon *mon, const struct TeamSelectorMonData *config);

static bool32 MonMatchesAnyTeamSelectorConfig(struct Pokemon *mon)
{
    u16 i;

    for (i = 0; i < NUM_MONS_POOL; i++)
    {
        if (MonMatchesConfig(mon, &gAllTeamMons[i]))
            return TRUE;
    }

    return FALSE;
}

static bool32 MonMatchesConfig(struct Pokemon *mon, const struct TeamSelectorMonData *config)
{
    u8 expectedEvs[NUM_STATS];
    u8 move;
    u8 stat;

    if (config->specie != GetMonData(mon, MON_DATA_SPECIES)
     || GetMonData(mon, MON_DATA_LEVEL) != 100
     || config->nature != GetNature(mon)
     || config->itemId != GetMonData(mon, MON_DATA_HELD_ITEM))
        return FALSE;

    if (config->ability != ABILITY_NONE && config->ability != GetMonAbility(mon))
        return FALSE;

    for (move = 0; move < MAX_MON_MOVES; move++)
    {
        if (config->moves[move] != GetMonData(mon, MON_DATA_MOVE1 + move))
            return FALSE;
        if (config->moves[move] != MOVE_NONE
         && GetMonData(mon, MON_DATA_PP1 + move) != CalculatePPWithBonus(config->moves[move], 0, move))
            return FALSE;
    }

    if (config->isShiny && !GetMonData(mon, MON_DATA_IS_SHINY))
        return FALSE;

    CopyTrainerPartyEvsToStatEvs(config->ev, expectedEvs);
    for (stat = 0; stat < NUM_STATS; stat++)
    {
        u8 expectedIv = (gNaturesInfo[config->nature].statDown == stat) ? 0 : MAX_PER_STAT_IVS;

        if (GetMonData(mon, MON_DATA_HP_EV + stat) != expectedEvs[stat]
         || GetMonData(mon, MON_DATA_HP_IV + stat) != expectedIv)
            return FALSE;
    }

    return TRUE;
}

TEST("WAH random team backs up, generates unique configured mons, and restores")
{
    struct BoxPokemon originalBoxMons[PARTY_SIZE];
    u8 i;

    memset(gPokemonStoragePtr, 0, sizeof(*gPokemonStoragePtr));
    for (i = 0; i < PARTY_SIZE; i++)
    {
        CreateMon(&gPlayerParty[i], SPECIES_WOBBUFFET, 100, 31, TRUE, 100 + i, OT_ID_PRESET, 200 + i);
        SetBoxMonAt(0, i, &gPlayerParty[i].box);
    }
    gSaveBlock2Ptr->monActiveOnPokebox = 0;
    CreateOriginalParty(originalBoxMons);
    VarSet(VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM);

    EXPECT(WahRandomTeam_BackupAndGenerate());
    EXPECT(WahRandomTeam_HasBackup());
    EXPECT_EQ(gPlayerPartyCount, PARTY_SIZE);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u8 j;
        u16 species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);

        EXPECT(memcmp(GetBoxedMonPtr(0, i), &originalBoxMons[i], sizeof(struct BoxPokemon)) == 0);
        EXPECT(MonMatchesAnyTeamSelectorConfig(&gPlayerParty[i]));
        for (j = 0; j < i; j++)
            EXPECT_NE(species, GetMonData(&gPlayerParty[j], MON_DATA_SPECIES));
    }

    EXPECT(WahRandomTeam_RestoreAndClear());
    EXPECT_EQ(gPlayerPartyCount, PARTY_SIZE);
    EXPECT(!WahRandomTeam_HasBackup());

    for (i = 0; i < PARTY_SIZE; i++)
    {
        EXPECT(memcmp(&gPlayerParty[i].box, &originalBoxMons[i], sizeof(struct BoxPokemon)) == 0);
        EXPECT(!GetBoxMonData(GetBoxedMonPtr(0, i), MON_DATA_SANITY_HAS_SPECIES));
    }
}

TEST("WAH challenge reset does not replace the party in other modes")
{
    struct BoxPokemon backupBoxMons[PARTY_SIZE];
    struct Pokemon currentParty[PARTY_SIZE];
    u8 i;

    memset(gPokemonStoragePtr, 0, sizeof(*gPokemonStoragePtr));
    CreateOriginalParty(backupBoxMons);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        SetBoxMonAt(0, i, &backupBoxMons[i]);
        CreateMon(&gPlayerParty[i], SPECIES_WOBBUFFET, 100, 31, TRUE, 100 + i, OT_ID_PRESET, 200 + i);
        currentParty[i] = gPlayerParty[i];
    }
    gPlayerPartyCount = PARTY_SIZE;
    VarSet(VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_STANDARD);

    ResetWahChallenge();

    EXPECT_EQ(VarGet(VAR_WAH_CHALLENGE_MODE), VAR_VALUE_WAH_CHALLENGE_MODE_NONE);
    for (i = 0; i < PARTY_SIZE; i++)
    {
        EXPECT(memcmp(&gPlayerParty[i], &currentParty[i], sizeof(struct Pokemon)) == 0);
        EXPECT(memcmp(GetBoxedMonPtr(0, i), &backupBoxMons[i], sizeof(struct BoxPokemon)) == 0);
    }
}

TEST("WAH random team does not change save structure sizes")
{
    EXPECT_EQ(sizeof(struct SaveBlock1), 15564);
    EXPECT_EQ(sizeof(struct SaveBlock2), 3908);
    EXPECT_EQ(sizeof(struct SaveBlock3), 4);
    EXPECT_EQ(sizeof(struct PokemonStorage), 34144);
}

TEST("WAH challenge reset restores the random party and preserves rewards")
{
    struct BoxPokemon originalBoxMons[PARTY_SIZE];
    u8 i;

    memset(gPokemonStoragePtr, 0, sizeof(*gPokemonStoragePtr));
    gSaveBlock2Ptr->monActiveOnPokebox = 0;
    CreateOriginalParty(originalBoxMons);
    VarSet(VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM);

    EXPECT(WahRandomTeam_BackupAndGenerate());
    FlagSet(FLAG_DEFEATED_ADMIN_OMEGA);
    FlagSet(FLAG_FORCE_DOUBLE_BATTLE);
    FlagSet(FLAG_WAH_CHALLENGE_STARTED_WITHOUT_LEGENDARIES);
    TrainerFlagSet(TRAINER_WAH_ADMIN_CHEVE_MAIN);
    TrainerFlagSet(TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE);
    VarSet(VAR_SERGIO_ROOM_STATE, 7);

    FlagSet(FLAG_WAH_CHALLENGE_RANDOM_COMPLETED);
    VarSet(VAR_WAH_CHALLENGE_RANDOM_COMPLETION_COUNT, 3);
    gSaveBlock2Ptr->achievements &= ~(1u << ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM);
    EXPECT(Achievement_CheckAndMarkComplete(ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM));

    ResetWahChallenge();

    EXPECT_EQ(VarGet(VAR_WAH_CHALLENGE_MODE), VAR_VALUE_WAH_CHALLENGE_MODE_NONE);
    EXPECT(!WahRandomTeam_HasBackup());
    EXPECT(!FlagGet(FLAG_DEFEATED_ADMIN_OMEGA));
    EXPECT(!FlagGet(FLAG_FORCE_DOUBLE_BATTLE));
    EXPECT(!FlagGet(FLAG_WAH_CHALLENGE_STARTED_WITHOUT_LEGENDARIES));
    EXPECT(!TrainerFlagGet(TRAINER_WAH_ADMIN_CHEVE_MAIN));
    EXPECT(!TrainerFlagGet(TRAINER_WAH_ADMIN_KLEIN_ALTERNATIVE));
    EXPECT_EQ(VarGet(VAR_SERGIO_ROOM_STATE), 0);
    EXPECT(FlagGet(FLAG_WAH_CHALLENGE_RANDOM_COMPLETED));
    EXPECT_EQ(VarGet(VAR_WAH_CHALLENGE_RANDOM_COMPLETION_COUNT), 3);
    EXPECT(Achievement_IsComplete(ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM));
    EXPECT(!Achievement_CheckAndMarkComplete(ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM));
    for (i = 0; i < PARTY_SIZE; i++)
        EXPECT(memcmp(&gPlayerParty[i].box, &originalBoxMons[i], sizeof(struct BoxPokemon)) == 0);

    FlagClear(FLAG_WAH_CHALLENGE_RANDOM_COMPLETED);
    gSaveBlock2Ptr->achievements &= ~(1u << ACHIEVEMENT_WIN_WAH_CHALLENGE_RANDOM);
}

TEST("WAH random team survives saving and reloading during the challenge")
{
    struct BoxPokemon originalBoxMons[PARTY_SIZE];
    struct BoxPokemon savedBackup[PARTY_SIZE];
    struct Pokemon generatedParty[PARTY_SIZE];
    u8 i;

    memset(gPokemonStoragePtr, 0, sizeof(*gPokemonStoragePtr));
    gSaveBlock2Ptr->monActiveOnPokebox = 0;
    CreateOriginalParty(originalBoxMons);
    VarSet(VAR_WAH_CHALLENGE_MODE, VAR_VALUE_WAH_CHALLENGE_MODE_RANDOM);
    EXPECT(WahRandomTeam_BackupAndGenerate());
    memcpy(generatedParty, gPlayerParty, sizeof(generatedParty));
    for (i = 0; i < PARTY_SIZE; i++)
        savedBackup[i] = *GetBoxedMonPtr(0, i);

    SavePlayerParty();
    memset(gPlayerParty, 0, sizeof(gPlayerParty));
    memset(gPokemonStoragePtr, 0, sizeof(*gPokemonStoragePtr));
    gPlayerPartyCount = 0;
    for (i = 0; i < PARTY_SIZE; i++)
        SetBoxMonAt(0, i, &savedBackup[i]);
    LoadPlayerParty();

    EXPECT_EQ(gPlayerPartyCount, PARTY_SIZE);
    EXPECT(memcmp(gPlayerParty, generatedParty, sizeof(generatedParty)) == 0);
    EXPECT(WahRandomTeam_HasBackup());
    ResetWahChallenge();
    for (i = 0; i < PARTY_SIZE; i++)
        EXPECT(memcmp(&gPlayerParty[i].box, &originalBoxMons[i], sizeof(struct BoxPokemon)) == 0);
}
