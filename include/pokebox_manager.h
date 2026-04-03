#ifndef GUARD_POKEBOX_MANAGER_H
#define GUARD_POKEBOX_MANAGER_H

struct PokeboxSpecies
{
    u16 specie;
    const u8 *description;
    u16 money;
    bool8 (*check)(u8 id);
};

enum{
    MSG_ACTION_CONTROLS,
    MSG_ACTION_FULL_TEAM,
    MSG_ACTION_NOT_TEAM_FULL,
    MSG_ACTION_LOCK_MON,
    MSG_ACTION_MON_IN_TEAM,
    MSG_ACTION_ONLY_ONE_MON_IN_TEAM,
    MSG_ACTION_ADD_MON_PARTY,
    MSG_ACTION_COUNT
};

const u8 *Get_PokeboxMsgAction(u8 index);

bool8 Pokebox_SetActive(u8 id);
bool8 CheckPokebox_IsActive(u8 id);

u8 PokeboxSpeciesList_GetCount(void);
u16 PokeboxSpeciesList_GetSpecie(u8 index);
bool8 PokeboxSpecies_Lock(u8 id);
const u8 *Get_PokeboxDescription(u8 id);
u32 PokeboxSpecies_GetMoney(u8 id);
bool8 PokeboxSpecies_EnoughtMoneyToBuy(u8 id);

#endif