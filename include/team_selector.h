#ifndef GUARD_TEAM_SELECTOR_H
#define GUARD_TEAM_SELECTOR_H


#define MAX_TEAM_SIZE 6

struct TeamSelectorMonData
{
    u16  specie;
    u16 ability;
    u8 nature;
    u16 itemId;
    const u8 *ev;
    bool8 isShiny;
    u16 moves[4];
};

struct TeamSelectorPlayer
{
    u8 teamSize;
    u8 team[MAX_TEAM_SIZE];
};

enum{
    TEAM_1, 
    TEAM_2,
    TEAM_3,
    TEAM_4,
    TEAM_5,
    TEAM_6,
    TEAM_7,
    TEAM_8,
    TEAM_9,
    TEAM_10,
    TEAM_11,
    TEAM_12,
    TEAM_13,
    TEAM_14,
    TEAM_15,
    TEAM_16,
    TEAM_17,
    TEAM_18,
    TEAM_19,
    TEAM_20,
    TEAM_RANDOM,
    TEAM_COUNT
};

#define NUM_PLAYER_TEAMS TEAM_RANDOM
#define NUM_MONS_POOL ( NUM_PLAYER_TEAMS * MAX_TEAM_SIZE)

extern const struct TeamSelectorPlayer gTeamSelectorPlayer[NUM_PLAYER_TEAMS];
extern const struct TeamSelectorMonData gAllTeamMons[];

bool8 StartTeamSelector_CB2();
void CB2_InitTeamSelectorSetUp();
void StartTeamSelectorFromField_CB2(void);
#endif // GUARD_TEAM_SELECTOR_H