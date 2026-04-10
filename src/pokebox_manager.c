#include "global.h"
#include "event_data.h"
#include "constants/vars.h"
#include "pokebox_manager.h"
#include "money.h"


static bool8 CheckPokebox_isBuyMon(u8 id);
static bool8 CheckPokebox_Active(u8 id);

static const u8 *sPokeboxMsgActionsList[] =
{
    [MSG_ACTION_CONTROLS] = COMPOUND_STRING("{START_BUTTON} Equipo {SELECT_BUTTON} Info. {DPAD_NONE} Mover {A_BUTTON} Añadir"),     
    [MSG_ACTION_FULL_TEAM]     = COMPOUND_STRING("Tu equipo está completo"),
    [MSG_ACTION_NOT_TEAM_FULL] = COMPOUND_STRING("Debes tener 6 Pokémon en el equipo"),
    [MSG_ACTION_LOCK_MON]      = COMPOUND_STRING("Este Pokémon está bloqueado."),
    [MSG_ACTION_MON_IN_TEAM]   = COMPOUND_STRING("Este Pokémon ya está en el equipo."),
    [MSG_ACTION_ONLY_ONE_MON_IN_TEAM] = COMPOUND_STRING("Debes tener un Pokémon en el equipo"), 
    [MSG_ACTION_ADD_MON_PARTY] = COMPOUND_STRING("{STR_VAR_1} añadido al equipo"), 
    [MSG_ACTION_ONLY_STORAGE_ONE_MON] = COMPOUND_STRING("Solo puedes cambiar un Pokémon del equipo"), 
    [MSG_ACTION_ONLY_STORAGE_THREE_MON] = COMPOUND_STRING("Solo puedes cambiar tres Pokémon del equipo"), 
};

const u8 *Get_PokeboxMsgAction(u8 index) 
{
    if (index >= MSG_ACTION_COUNT)
        return sPokeboxMsgActionsList[0];

    return sPokeboxMsgActionsList[index];
}

const u8 gText_PokeboxBuyThisMon[] = _("¿Quieres comprar a\neste Pokémon?");

static const struct PokeboxSpecies sPokeboxSpeciesList[] =
{
    { 
        .specie = SPECIES_DRAGONITE,        
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_Active
    },
    { 
        .specie = SPECIES_VOLCARONA,        
        .description = gText_PokeboxBuyThisMon, 
        .money = 10000,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .specie = SPECIES_GRENINJA,         
        .description = gText_PokeboxBuyThisMon, 
        .money = 200,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .specie = SPECIES_CINDERACE,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_EXCADRILL,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_AEGISLASH,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_MIMIKYU,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_TOXAPEX,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_FERROTHORN,       
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_CORVIKNIGHT,      
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_SKARMORY,         
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_BLISSEY,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_GASTRODON,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_ROTOM_WASH,       
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_LANDORUS_THERIAN,
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_GLISCOR,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_AMOONGUSS,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_INDEEDEE,         
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_PORYGON2,         
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_HATTERENE,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_REUNICLUS,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_SLOWKING_GALAR,   
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_HEATRAN,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_TAPU_FINI,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_TAPU_KOKO,        
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_KARTANA,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_URSHIFU,          
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .specie = SPECIES_FLUTTER_MANE,     
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
};



u8 PokeboxSpeciesList_GetCount(void)
{
    return ARRAY_COUNT(sPokeboxSpeciesList);
}

u16 PokeboxSpeciesList_GetSpecie(u8 index)
{
    if (index >= PokeboxSpeciesList_GetCount())
        return SPECIES_NONE;

    return sPokeboxSpeciesList[index].specie;
}

const u8 *Get_PokeboxDescription(u8 id) 
{
    return sPokeboxSpeciesList[id].description;
}


//comprobar si el bit esta activo
bool8 Pokebox_IsActive(u8 index)
{
    if (index >= PokeboxSpeciesList_GetCount())
        return FALSE;

    return ((gSaveBlock2Ptr->monActiveOnPokebox >> index) & 1) != 0;
}

//cambiar el bit a activo
bool8 Pokebox_SetActive(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    if ((gSaveBlock2Ptr->monActiveOnPokebox >> id) & 1)
        return FALSE;

    gSaveBlock2Ptr->monActiveOnPokebox |= (1u << id);

    return TRUE;
}


static bool8 CheckPokebox_Active(u8 id)
{
    return FALSE;
}

static bool8 CheckPokebox_isBuyMon(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    if(sPokeboxSpeciesList[id].money <= 0)
        return FALSE;

    return Pokebox_IsActive(id);
}

bool8 CheckPokebox_IsActive(u8 id)
{
    bool8 isActive = FALSE;

    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    isActive = sPokeboxSpeciesList[id].check(id);

    // if(isActive) Pokebox_SetActive(id);

    return isActive;
}

u32 PokeboxSpecies_GetMoney(u8 id)
{
    return sPokeboxSpeciesList[id].money;
}

bool8 PokeboxSpecies_EnoughtMoneyToBuy(u8 id)
{
    u32 money = GetMoney(&gSaveBlock1Ptr->money);

    if(Pokebox_IsActive(id))
        return FALSE;

    return money >= PokeboxSpecies_GetMoney(id);
}


