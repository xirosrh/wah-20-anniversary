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
    TEAM_RANDOM,
    TEAM_COUNT
};

#define NUM_PLAYER_TEAMS TEAM_RANDOM
#define NUM_MONS_POOL ( NUM_PLAYER_TEAMS * MAX_TEAM_SIZE)

extern const struct TeamSelectorPlayer gTeamSelectorPlayer[NUM_PLAYER_TEAMS];
extern const struct TeamSelectorMonData gAllTeamMons[];

bool8 StartTeamSelector_CB2();
void CB2_InitTeamSelectorSetUp();
#endif // GUARD_TEAM_SELECTOR_H