#include "global.h"
#include "data.h"
#include "event_data.h"
#include "constants/vars.h"
#include "constants/flags.h"
#include "constants/characters.h"
#include "constants/abilities.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/achievements.h"
#include "achievements.h"
#include "pokebox_manager.h"
#include "money.h"
#include "pokemon.h"
#include "strings.h"
#include "string_util.h"


static bool8 CheckPokebox_isBuyMon(u8 id);
static bool8 CheckPokebox_Active(u8 id);
static bool8 CheckPokebox_WahChallengeCompleted(u8 id);
static bool8 CheckPokebox_AlexmadEventGiveClones(u8 id);
static bool8 CheckPokebox_AlexmadEventGiveLegendaries(u8 id);
static bool8 CheckPokebox_AlexmadEventCompleted(u8 id);
static bool8 CheckPokebox_AchievementAvaricia(u8 id);

static const u8 *sPokeboxMsgActionsList[] =
{
    [MSG_ACTION_CONTROLS] = COMPOUND_STRING("{START_BUTTON} Equipo {SELECT_BUTTON} Info. {DPAD_NONE} Mover {A_BUTTON} Añadir"),
    [MSG_ACTION_CONTROLS_TEAM] = COMPOUND_STRING("{A_BUTTON} Dejar {B_BUTTON} Atras {DPAD_NONE} Mover {START_BUTTON} Resetear"),    
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

#define POKEBOX_MON(species_)                                                           \
    {                                                                                   \
        .specie = species_, .ability = ABILITY_NONE, .nature = NATURE_HARDY,            \
        .itemId = ITEM_NONE, .ev = NULL, .isShiny = FALSE,                              \
        .moves = {MOVE_NONE, MOVE_NONE, MOVE_NONE, MOVE_NONE}                           \
    }

static const struct PokeboxSpecies sPokeboxSpeciesList[] =
{
    {
        .mon = POKEBOX_MON(SPECIES_JIRACHI),
        .description = COMPOUND_STRING("Completa el evento especial de Alexmad."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveLegendaries
    },
    {
        .mon = POKEBOX_MON(SPECIES_MEW),
        .description = COMPOUND_STRING("Gana el desafio una vez."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveLegendaries
    },
    {
        .mon = POKEBOX_MON(SPECIES_CELEBI),
        .description = COMPOUND_STRING("Gana el desafio una vez."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveLegendaries
    },
    {
        .mon = {
            .specie = SPECIES_VENUSAUR_C,
            .ability = ABILITY_SPEED_BOOST,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_THUNDERBOLT, MOVE_SHADOW_BALL, MOVE_PETAL_DANCE, MOVE_SLUDGE_WAVE},
        },
        .description = COMPOUND_STRING("Gana el desafio una vez."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveClones
    },
    {
        .mon = {
            .specie = SPECIES_CHARIZARD_C,
            .ability = ABILITY_ROCK_HEAD,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 0, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_FLARE_BLITZ, MOVE_BRAVE_BIRD, MOVE_HEAD_SMASH, MOVE_WAVE_CRASH},
        },
        .description = COMPOUND_STRING("Completa el evento especial de Alexmad."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveClones
    },
    {
        .mon = {
            .specie = SPECIES_BLASTOISE_C,
            .ability = ABILITY_CONTRARY,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 0, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_LIQUIDATION, MOVE_CLOSE_COMBAT, MOVE_PLAY_ROUGH, MOVE_HEAT_CRASH},
        },
        .description = COMPOUND_STRING("Completa el evento especial de Alexmad."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventGiveClones
    },
    {
        .mon = POKEBOX_MON(SPECIES_MEWTWO), //TODO Xiros: Armored mewtwo
        .description = COMPOUND_STRING("Completa el evento especial de Alexmad."),
        .money = 0,
        .check = CheckPokebox_AlexmadEventCompleted
    },
    {
        .mon = {
            .specie = SPECIES_ELECTRODES,
            .ability = ABILITY_MELONSHIELD,
            .nature = NATURE_MODEST,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_JUICY_EXPLOSION, MOVE_ACID_PULP, MOVE_THUNDERBOLT, MOVE_GIGA_DRAIN},
        },
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_WahChallengeCompleted
    },
    {
        .mon = {
            .specie = SPECIES_MOLTRES,
            .ability = ABILITY_PRESSURE,
            .nature = NATURE_TIMID,
            .ev = TRAINER_PARTY_EVS(252, 0, 252, 252, 252, 252),
            .isShiny = FALSE,
            .moves = {MOVE_FLAMETHROWER, MOVE_AEROBLAST, MOVE_EARTH_POWER, MOVE_MOONBLAST},
        },
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_WahChallengeCompleted
    },
    { 
        .mon = {
            .specie = SPECIES_DRAGONITE,
            .ability = ABILITY_MULTISCALE,
            .nature = NATURE_JOLLY,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(252, 252, 252, 252, 0, 252),
            .isShiny = FALSE,
            .moves = {MOVE_IRON_HEAD, MOVE_DRAGON_CLAW, MOVE_PLAY_ROUGH, MOVE_EXTREME_SPEED},
        },
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_WahChallengeCompleted
    },  
    { 
        .mon = POKEBOX_MON(SPECIES_GOROCHU),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_DUN),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 1000,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_TAABAN),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_BLESSPARCE),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_MADAAMU),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_AKUERIA),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_VOLCARONA),
        .description = gText_PokeboxBuyThisMon, 
        .money = 10000,
        .check = CheckPokebox_isBuyMon
    },
    { 
        .mon = POKEBOX_MON(SPECIES_GRENINJA),
        .description = gText_PokeboxBuyThisMon, 
        .money = 200,
        .check = CheckPokebox_isBuyMon
    },

    { 
        .mon = POKEBOX_MON(SPECIES_CINDERACE),
        .description = COMPOUND_STRING("Gana el desafio una vez."), 
        .money = 0,
        .check = CheckPokebox_isBuyMon 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_EXCADRILL),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_AEGISLASH),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_MIMIKYU),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_TOXAPEX),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_FERROTHORN),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_CORVIKNIGHT),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_SKARMORY),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_BLISSEY),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_GASTRODON),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_ROTOM_WASH),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_LANDORUS_THERIAN),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_GLISCOR),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_AMOONGUSS),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_INDEEDEE),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_PORYGON2),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_HATTERENE),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_REUNICLUS),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_SLOWKING_GALAR),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_HEATRAN),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_TAPU_FINI),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_TAPU_KOKO),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_KARTANA),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_URSHIFU),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    { 
        .mon = POKEBOX_MON(SPECIES_FLUTTER_MANE),
        .description = COMPOUND_STRING(""), 
        .money = 0,
        .check = CheckPokebox_Active 
    },
    {
        .mon = {
            .specie = SPECIES_MICAEL,
            .ability = ABILITY_PRANKSTER,
            .nature = NATURE_TIMID,
            .itemId = ITEM_NONE,
            .ev = TRAINER_PARTY_EVS(4, 0, 0, 252, 252, 0),
            .isShiny = FALSE,
            .moves = {MOVE_VOODOO, MOVE_ASTRAL_BARRAGE, MOVE_DOUBLE_TEAM, MOVE_DESTINY_BOND},
        },
        .description = COMPOUND_STRING("Completa el logro “Avaricia”."),
        .money = 0,
        .check = CheckPokebox_AchievementAvaricia
    },
};

STATIC_ASSERT(ARRAY_COUNT(sPokeboxSpeciesList) <= 64, PokeboxSpeciesListExceedsMonActiveBits);

#undef POKEBOX_MON



u8 PokeboxSpeciesList_GetCount(void)
{
    return ARRAY_COUNT(sPokeboxSpeciesList);
}

const struct TeamSelectorMonData *PokeboxSpeciesList_GetMonData(u8 index)
{
    if (index >= PokeboxSpeciesList_GetCount())
        return NULL;

    return &sPokeboxSpeciesList[index].mon;
}

u16 PokeboxSpeciesList_GetSpecie(u8 index)
{
    const struct TeamSelectorMonData *mon = PokeboxSpeciesList_GetMonData(index);

    if (mon == NULL)
        return SPECIES_NONE;

    return mon->specie;
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

    gSaveBlock2Ptr->monActiveOnPokebox |= (1ull << id);

    return TRUE;
}


static bool8 CheckPokebox_Active(u8 id)
{
    return FALSE;
}

static bool8 CheckPokebox_WahChallengeCompleted(u8 id)
{
    (void)id;
    return FlagGet(FLAG_WAH_CHALLENGE_COMPLETED);
}

static bool8 CheckPokebox_AlexmadEventGiveClones(u8 id)
{
    (void)id;
    return FlagGet(FLAG_ALEXMAD_EVENT_GIVE_CLONES);
}

static bool8 CheckPokebox_AlexmadEventCompleted(u8 id)
{
    (void)id;
    return FlagGet(FLAG_ALEXMAD_EVENT_COMPLETED);
}

static bool8 CheckPokebox_AlexmadEventGiveLegendaries(u8 id)
{
    (void)id;
    return FlagGet(FLAG_ALEXMAD_EVENT_GIVE_LEGENDARIES);
}

static bool8 CheckPokebox_AchievementAvaricia(u8 id)
{
    (void)id;
    return Achievement_IsComplete(ACHIEVEMENT_AVARICIA);
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
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;

    return sPokeboxSpeciesList[id].check(id);
}

bool8 PokeboxSpecies_TryUnlockNew(u8 id)
{
    if (id >= PokeboxSpeciesList_GetCount())
        return FALSE;
    if (Pokebox_IsActive(id))
        return FALSE;
    if (!sPokeboxSpeciesList[id].check(id))
        return FALSE;
    Pokebox_SetActive(id);
    return TRUE;
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

bool8 PokeboxSpecies_BufferBuyOfferFromSpecies(u16 species)
{
    u8 i;
    u8 count = PokeboxSpeciesList_GetCount();
    u32 money;

    for (i = 0; i < count; i++)
    {
        if (PokeboxSpeciesList_GetSpecie(i) != species)
            continue;

        money = PokeboxSpecies_GetMoney(i);
        if (money == 0)
        {
            gStringVar1[0] = EOS;
            gStringVar2[0] = EOS;
            return FALSE;
        }

        ConvertIntToDecimalStringN(gStringVar1, money, STR_CONV_MODE_LEFT_ALIGN, MAX_MONEY_DIGITS);
        StringExpandPlaceholders(gStringVar4, gText_PokedollarVar1);
        StringCopy(gStringVar2, gStringVar4);
        StringCopy(gStringVar1, GetSpeciesName(species));
        return TRUE;
    }

    gStringVar1[0] = EOS;
    gStringVar2[0] = EOS;
    return FALSE;
}
