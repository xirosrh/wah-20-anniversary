#include "global.h"
#include "event_data.h"
#include "constants/vars.h"
#include "pokebox_manager.h"

static bool8 CheckAchievement_Generic(u8 id);
static bool8 CheckAchievement_Generic2(u8 id);

static const u8 *sPokeboxMsgActionsList[] =
{
    [MSG_ACTION_CONTROLS] = COMPOUND_STRING("{START_BUTTON} Equipo {SELECT_BUTTON} Info. {DPAD_NONE} Mover {A_BUTTON} Añadir"),     
    [MSG_ACTION_FULL_TEAM]     = COMPOUND_STRING("Tu equipo está completo"),
    [MSG_ACTION_NOT_TEAM_FULL] = COMPOUND_STRING("Debes tener 6 Pokémon en el equipo"),
    [MSG_ACTION_LOCK_MON]      = COMPOUND_STRING("Este Pokémon está bloqueado."),
    [MSG_ACTION_MON_IN_TEAM]   = COMPOUND_STRING("Este Pokémon ya está en el equipo."),
    [MSG_ACTION_ONLY_ONE_MON_IN_TEAM] = COMPOUND_STRING("Debes tener un Pokémon en el equipo"), 
    [MSG_ACTION_ADD_MON_PARTY] = COMPOUND_STRING("{STR_VAR_1} añadido al equipo"), 
};

const u8 *Get_PokeboxMsgAction(u8 index) 
{
    if (index >= MSG_ACTION_COUNT)
        return sPokeboxMsgActionsList[0];

    return sPokeboxMsgActionsList[index];
}

static const struct PokeboxSpecies sPokeboxSpeciesList[] =
{
    { 
        .specie = SPECIES_DRAGONITE,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_VOLCARONA,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_GRENINJA,         
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_CINDERACE,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_EXCADRILL,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_AEGISLASH,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_MIMIKYU,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_TOXAPEX,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_FERROTHORN,       
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_CORVIKNIGHT,      
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_SKARMORY,         
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_BLISSEY,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_GASTRODON,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_ROTOM_WASH,       
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_LANDORUS_THERIAN,
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_GLISCOR,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_AMOONGUSS,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_INDEEDEE,         
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_PORYGON2,         
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_HATTERENE,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_REUNICLUS,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_SLOWKING_GALAR,   
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic2 
    },
    { 
        .specie = SPECIES_HEATRAN,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_TAPU_FINI,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_TAPU_KOKO,        
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_KARTANA,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_URSHIFU,          
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
    },
    { 
        .specie = SPECIES_FLUTTER_MANE,     
        .description = COMPOUND_STRING(""), 
        .check = CheckAchievement_Generic 
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

static bool8 CheckAchievement_Generic(u8 id)
{
    return TRUE;
}

static bool8 CheckAchievement_Generic2(u8 id)
{
    return FALSE;
}

bool8 PokeboxSpecies_Lock(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    return sPokeboxSpeciesList[id].check(id);
}
