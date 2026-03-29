#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "sprite.h"
#include "window.h"
#include "random.h"
#include "move.h"
#include "pokemon_summary_screen.h"
#include "battle_util.h"
#include "trainer_pokemon_sprites.h"
#include "pokemon_icon.h"
#include "team_selector.h"
#include "team_selector_player.h"
#include "pokebox_manager.h"
#include "pokebox.h"
#include "pokeball.h"
#include "pokemon.h"
#include "script_pokemon_util.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"

//========== SECCIÓN: VARIABLES ==========//

#define tTimer data[7]

#define MAX_MON_ICONS_IN_BOX 16

#define NUM_MON_ICON_ROW 4

#define MON_ICON_POS_X 119
#define MON_ICON_POS_Y 46

#define INCREMENT_MON_ICON_POS_X 34
#define INCREMENT_MON_ICON_POS_Y 32

#define MON_ICON_TEAM_ROWS 3
#define MON_ICON_TEAM_COLS 2

#define INITIAL_POS_X_BG_TEAM_PLAYER -144

#define MON_ICON_PLAYER_TEAM_POS_X 124
#define MON_ICON_PLAYER_TEAM_POS_Y 48

#define INCREMENT_MON_ICON_PLAYER_TEAM_POS_X 41
#define INCREMENT_MON_ICON_PLAYER_TEAM_POS_Y 40

struct PokeBox
{
    u8 currentPageNum;
    u8 frontMonId;//id del front sprite
    u8 itemId;//id del sprite item
    u8 selectorId;//id del sprite del selector

    u8 row;
    u8 column;

    u8 row_team;
    u8 col_team;

    u8 boxMonIconCategoyIds[4]; //id de las categorias de los movs
    u8 boxMonSpritesIds[NUM_MON_ICON_ROW][NUM_MON_ICON_ROW]; //id de los icons sprites de cada mon en la box
    u8 playerTeamMonSpritesIds[MON_ICON_TEAM_ROWS][MON_ICON_TEAM_COLS]; //id de los icons sprites en la party
};

#define tBgSlice data[1]
#define tTimer data[7]

static EWRAM_DATA struct PokeBox pokeBoxObj = {0};

const u8 sTextColorWhitePokebox[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
const u8 sTextColorBlackPokebox[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_LIGHT_GRAY};

const u8 sTextColorBlackMonInfo2PagePokebox[]= {TEXT_COLOR_TRANSPARENT, 8, 6};

const u16 PokeboxBG_Palette[] = INCBIN_U16("graphics/pokebox/bg_pal0.gbapal");

const u32 PokeboxBG1_Tileset[] = INCBIN_U32("graphics/pokebox/bg1_tileset.4bpp.lz");
const u32 PokeboxBG1_Tilemap[] = INCBIN_U32("graphics/pokebox/bg1_tilemap.bin.lz");

const u32 PokeboxBG2_Tileset[] = INCBIN_U32("graphics/pokebox/bg2_tileset.4bpp.lz");
const u32 PokeboxBG2_Tilemap[] = INCBIN_U32("graphics/pokebox/bg2_tilemap.bin.lz");

const u32 PokeboxBG3_Tileset[] = INCBIN_U32("graphics/pokebox/bg3_tileset.4bpp.lz");
const u32 PokeboxBG3_Tilemap[] = INCBIN_U32("graphics/pokebox/bg3_tilemap.bin.lz");

static u8 getTotalNumPages();
static u16 GetSelectedPokemonIndex(void);
bool8 IsLockMon(u8 i);
static void Task_HandlePokebox(u8 taskId);
static void Task_HandleTeamPlayerPokebox(u8 taskId);
static void Task_ShowMonInfo(u8 taskId);
static void Task_AddMonTeamPlayer(u8 taskId);
static void Task_StorageMonInPokebox(u8 taskId);
static void Task_FadeOut(u8 taskId);

//========== SECCIÓN: SPRITES ==========//

#define SELECTOR_TAG 5400
static const u8 Pokebox_SelectorSprite[] = INCBIN_U8("graphics/pokebox/selector.4bpp");

static const struct OamData gSpriteOamDataPokebox32x32 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct SpriteSheet sSpriteSheet_Selector =
{
    .data = Pokebox_SelectorSprite, 
    .size = 512, 
    .tag = SELECTOR_TAG,
};

static const struct SpritePalette spritePalette_Selector =
{
    .data = PokeboxBG_Palette,
    .tag = SELECTOR_TAG,
};

static const struct SpriteTemplate sSelectorSpriteTemplate =
{
    .tileTag = SELECTOR_TAG,
    .paletteTag = SELECTOR_TAG,
    .oam = &gSpriteOamDataPokebox32x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static void LoadSelectorSprite(void)
{
    LoadSpriteSheet(&sSpriteSheet_Selector);
    LoadSpritePalette(&spritePalette_Selector);
}

static u8 CreateSelectorSprite()
{
    return CreateSprite(&sSelectorSpriteTemplate, MON_ICON_POS_X, MON_ICON_POS_Y, 0);
}

static void ResetSelectorPosition()
{
    pokeBoxObj.row = 0;
    pokeBoxObj.column = 0;
    gSprites[pokeBoxObj.selectorId].x = MON_ICON_POS_X;
    gSprites[pokeBoxObj.selectorId].y = MON_ICON_POS_Y;
}

static void SetVisibilitySpriteSelector(bool8 isInvisible)
{
    gSprites[pokeBoxObj.selectorId].invisible = isInvisible;
}

static void UpdateSelectorPosition(bool8 isTeamPlayer)
{
    if(!isTeamPlayer)
    {
        gSprites[pokeBoxObj.selectorId].x = MON_ICON_POS_X + (pokeBoxObj.column * INCREMENT_MON_ICON_POS_X);
        gSprites[pokeBoxObj.selectorId].y = MON_ICON_POS_Y + (pokeBoxObj.row * INCREMENT_MON_ICON_POS_Y);
    }else{
        gSprites[pokeBoxObj.selectorId].x = MON_ICON_PLAYER_TEAM_POS_X + (pokeBoxObj.col_team * INCREMENT_MON_ICON_PLAYER_TEAM_POS_X);
        gSprites[pokeBoxObj.selectorId].y = MON_ICON_PLAYER_TEAM_POS_Y + (pokeBoxObj.row_team * INCREMENT_MON_ICON_PLAYER_TEAM_POS_Y);
    }
}

//========== SECCIÓN: BGS ==========//
enum BgsPokeBox
{
    BG_WINDOWS,
    BG_1,
    BG_2,
    BG_SLICE,
};

static const struct BgTemplate PokeBoxBgTemplates[] =
{
    [BG_WINDOWS] =
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 10,
        .priority = 0
    },
    [BG_1] =
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 25,
        .screenSize = 1,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    [BG_2] =
    {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 29,
        .priority = 2
    },
    [BG_SLICE] =
    {
        .bg = 3,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 3
    }
};

//========== SECCIÓN: FUNCIONES DE CARGA DE BGS ==========//

static void LoadBgs(void)
{
    InitBgsFromTemplates(0, PokeBoxBgTemplates, ARRAY_COUNT(PokeBoxBgTemplates));

    LZ77UnCompVram(PokeboxBG3_Tileset, (void*) BG_CHAR_ADDR(PokeBoxBgTemplates[BG_SLICE].charBaseIndex));
    LZ77UnCompVram(PokeboxBG3_Tilemap, (u16*) BG_SCREEN_ADDR(PokeBoxBgTemplates[BG_SLICE].mapBaseIndex));

    LZ77UnCompVram(PokeboxBG2_Tileset, (void*) BG_CHAR_ADDR(PokeBoxBgTemplates[BG_2].charBaseIndex));
    LZ77UnCompVram(PokeboxBG2_Tilemap, (u16*) BG_SCREEN_ADDR(PokeBoxBgTemplates[BG_2].mapBaseIndex));

    LZ77UnCompVram(PokeboxBG1_Tileset, (void*) BG_CHAR_ADDR(PokeBoxBgTemplates[BG_1].charBaseIndex));
    LZ77UnCompVram(PokeboxBG1_Tilemap, (u16*) BG_SCREEN_ADDR(PokeBoxBgTemplates[BG_1].mapBaseIndex));

    LoadPalette(PokeboxBG_Palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    ResetAllBgsCoordinates();

    SetGpuReg(REG_OFFSET_BG1HOFS, INITIAL_POS_X_BG_TEAM_PLAYER);

    ShowBg(BG_WINDOWS);
    ShowBg(BG_1);
    ShowBg(BG_2);
    ShowBg(BG_SLICE);
}

static void VBlank_CB_PokeBox(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_PokeBox(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

//========== SECCIÓN: FUNCIONES DE CARGA DE WINDOWS ==========//

enum
{
    WINDOW_MSG,
    WINDOW_NAME,
    WINDOW_MON_TYPE,
    WINDOW_SWAP_BOX,
    WINDOW_MON_INFO,
    WINDOW_MON_INFO_2,
    WINDOW_COUNT,
};

static const struct WindowTemplate sWindowTemplatesPokeBox[] =
{
    [WINDOW_MSG]
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 0,
        .width = 26,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WINDOW_NAME]
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 13,
        .width = 9,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 53
    },
    [WINDOW_MON_TYPE]
    {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 15,
        .width = 9,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 71
    },
    [WINDOW_SWAP_BOX]
    {
        .bg = 0,
        .tilemapLeft = 13,
        .tilemapTop = 2,
        .width = 16,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 89
    },
    [WINDOW_MON_INFO]
    {
        .bg = 0,
        .tilemapLeft = 13,
        .tilemapTop = 4,
        .width = 17,
        .height = 8,
        .paletteNum = 15,
        .baseBlock = 121
    },
    [WINDOW_MON_INFO_2]
    {
        .bg = 0,
        .tilemapLeft = 13,
        .tilemapTop = 12,
        .width = 17,
        .height = 8,
        .paletteNum = 6,
        .baseBlock = 257
    },

    DUMMY_WIN_TEMPLATE,
};


static void InitWindowPokeBox(void)
{
	InitWindows(sWindowTemplatesPokeBox);
    DeactivateAllTextPrinters();
	LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    PutWindowTilemap(WINDOW_MSG);
    PutWindowTilemap(WINDOW_NAME);
    PutWindowTilemap(WINDOW_MON_TYPE);
    PutWindowTilemap(WINDOW_SWAP_BOX);
    PutWindowTilemap(WINDOW_MON_INFO);
    PutWindowTilemap(WINDOW_MON_INFO_2);
}

static void PrintNameMonPokebox(u16 specie)
{
    FillWindowPixelBuffer(WINDOW_NAME, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WINDOW_NAME, FONT_NORMAL, 0, 0, sTextColorWhitePokebox, 0, GetSpeciesName(specie));
    CopyWindowToVram(WINDOW_NAME, 3);
}

static void PrintMsgActions(u8 msgAction)
{
    u8 x;

    FillWindowPixelBuffer(WINDOW_MSG, PIXEL_FILL(0));
   
    if(msgAction != MSG_ACTION_ADD_MON_PARTY)
    {
        x = GetStringCenterAlignXOffset(FONT_SMALL, Get_PokeboxMsgAction(msgAction), sWindowTemplatesPokeBox[WINDOW_MSG].width*8);
        AddTextPrinterParameterized3(WINDOW_MSG, FONT_SMALL, x, 0, sTextColorWhitePokebox, 0, Get_PokeboxMsgAction(msgAction));
    }else{
        StringExpandPlaceholders(gStringVar2, Get_PokeboxMsgAction(msgAction));
        x = GetStringCenterAlignXOffset(FONT_SMALL, gStringVar2, sWindowTemplatesPokeBox[WINDOW_MSG].width*8);
        AddTextPrinterParameterized3(WINDOW_MSG, FONT_SMALL, x, 0, sTextColorWhitePokebox, 0, gStringVar2);
    }

    CopyWindowToVram(WINDOW_MSG, 3);
}

static void PrintTextSwapBox()
{
    u8 x;
    
    const u8 gText_L_Button[] = _("{L_BUTTON}");
    const u8 gText_Box_Name[] = _("CAJA {STR_VAR_2}");
    const u8 gText_R_Button[] = _("{R_BUTTON}");

    FillWindowPixelBuffer(WINDOW_SWAP_BOX, PIXEL_FILL(0));

    if(pokeBoxObj.currentPageNum > 0)
        AddTextPrinterParameterized3(WINDOW_SWAP_BOX, FONT_NORMAL, 0, 0, sTextColorWhitePokebox, 0, gText_L_Button);

    if(pokeBoxObj.currentPageNum < getTotalNumPages()-1)
        AddTextPrinterParameterized3(WINDOW_SWAP_BOX, FONT_NORMAL, 112, 0, sTextColorWhitePokebox, 0, gText_R_Button);

    ConvertIntToDecimalStringN(gStringVar2, pokeBoxObj.currentPageNum, STR_CONV_MODE_RIGHT_ALIGN, 2);
    StringExpandPlaceholders(gStringVar3, gText_Box_Name);

    x = GetStringCenterAlignXOffset(FONT_SMALL, gStringVar3, sWindowTemplatesPokeBox[WINDOW_SWAP_BOX].width*8);
    AddTextPrinterParameterized3(WINDOW_SWAP_BOX, FONT_NORMAL, x, 0, sTextColorWhitePokebox, 0, gStringVar3);

    CopyWindowToVram(WINDOW_SWAP_BOX, 3);
}

static void PrintAllDataMon(u16 specie)
{
    if(IsLockMon( pokeBoxObj.row * NUM_MON_ICON_ROW + pokeBoxObj.column))
        specie = SPECIES_NONE;

    PrintNameMonPokebox(specie);
    LoadMonIconType(WINDOW_MON_TYPE, specie, 0, 3, 0);
}

static void ClearWindoMonData(bool8 clearSwapBox)
{
    FillWindowPixelBuffer(WINDOW_NAME, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_MON_TYPE, PIXEL_FILL(0));
    CopyWindowToVram(WINDOW_NAME, 3);
    CopyWindowToVram(WINDOW_MON_TYPE, 3);

    if(clearSwapBox)
    {
        FillWindowPixelBuffer(WINDOW_SWAP_BOX, PIXEL_FILL(0));
        CopyWindowToVram(WINDOW_SWAP_BOX, 3);
    }
}

static void PrintAbility(u16 specie, u16 ability)
{
    u16 indexAbility;

    if(ability == ABILITY_NONE)
    {
        do {
            indexAbility = Random() % NUM_ABILITY_SLOTS;
            ability = gSpeciesInfo[specie].abilities[indexAbility];
        } while ( ability == ABILITY_NONE);
    }

    AddTextPrinterParameterized3(WINDOW_MON_INFO, FONT_NORMAL, 0, 0, sTextColorBlackPokebox, 0, gAbilitiesInfo[ability].name);
    AddTextPrinterParameterized3(WINDOW_MON_INFO, FONT_SMALL, 0, 16, sTextColorBlackPokebox, 0, gAbilitiesInfo[ability].description);
}

static void LoadMoveCateroyIcon(u16 move, u8 indexMove);

static void PrintMoves(u8 windowId, const u16* moves)
{
    u8 i;
    u8 y = 0;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));

    for (i = 0; i < 4; i++)
    {
        if(moves[i] == MOVE_NONE)
            StringCopy(gStringVar1, gText_OneDash);
        else
            StringCopy(gStringVar1, GetMoveName(moves[i]));
        
        AddTextPrinterParameterized3(windowId, FONT_SMALL, 0, y, sTextColorBlackMonInfo2PagePokebox, 0, gStringVar1);
        LoadMoveIconType(windowId, moves[i], i, 88, 2);
        LoadMoveCateroyIcon(moves[i], i);
        y += 16;
    }
    
    CopyWindowToVram(windowId, 3);
}

static void PrintMonTextInfoPage()
{
    FillWindowPixelBuffer(WINDOW_MON_INFO, PIXEL_FILL(0));

    u16 index = GetSelectedPokemonIndex();
    u16 ability = ABILITY_NONE;

    if (index < MON_TEAM_SELECTOR_COUNT)
    {
        PrintAbility(gAllTeamMons[index].specie, gAllTeamMons[index].ability);
        PrintMoves(WINDOW_MON_INFO_2, gAllTeamMons[index].moves);

    }/*else{

    }*/

    CopyWindowToVram(WINDOW_MON_INFO, 3);
}

static void LoadMoveCateroyIcon(u16 move, u8 indexMove)
{   
    u8 categoryIconId = 0xFF;
    enum DamageCategory category;

    if(move == MOVE_NONE)
        return;

    if(pokeBoxObj.boxMonIconCategoyIds[indexMove] != 0xFF)
    {
        gSprites[pokeBoxObj.boxMonIconCategoyIds[indexMove]].invisible = FALSE;
        return;
    }

    category = GetBattleMoveCategory(move);
    
    categoryIconId = CreateSprite(&gSpriteTemplate_CategoryIcons, 232, 103 + (16 * indexMove), 1);

    StartSpriteAnim(&gSprites[categoryIconId], category);
    gSprites[categoryIconId].invisible = FALSE;
    gSprites[categoryIconId].oam.priority = 1; 
    pokeBoxObj.boxMonIconCategoyIds[indexMove] = categoryIconId;
}

static void ClearMonTextInfoPage(bool8 destroyCategoryIcons)
{
    u8 i;

    FillWindowPixelBuffer(WINDOW_MON_INFO, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_MON_INFO_2, PIXEL_FILL(0));

    for (i = 0; i < 4; i++)
    {
        if(pokeBoxObj.boxMonIconCategoyIds[i] == 0xFF) 
            continue;

        if(!destroyCategoryIcons)
            gSprites[pokeBoxObj.boxMonIconCategoyIds[i]].invisible = TRUE;
        else
        {
            DestroySprite(&gSprites[pokeBoxObj.boxMonIconCategoyIds[i]]);
            pokeBoxObj.boxMonIconCategoyIds[i] = 0xFF;
        }
    }

    CopyWindowToVram(WINDOW_MON_INFO, 3);
    CopyWindowToVram(WINDOW_MON_INFO_2, 3);
}

static u8 getTotalNumPages()
{
    u16 totalCount = MON_TEAM_SELECTOR_COUNT + PokeboxSpeciesList_GetCount();
    return (totalCount + MAX_MON_ICONS_IN_BOX - 1) / MAX_MON_ICONS_IN_BOX;
}

u8 GetFirstFreeSlotMonParty()
{
    u8 i;
    u16 specie;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        specie =  GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);

        if(specie == SPECIES_NONE)
            return i;
    }

    return 0xFF;
}

bool8 HasMonInParty(u16 specieBox)
{
    u8 i;
    u16 specie;

    for(i = 0; i < PARTY_SIZE; i++)
    {
        specie =  GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);
        if(specie == specieBox)
            return TRUE;
    }

    return FALSE;
}

static u16 GetSelectedPokemonIndex(void)
{
    return pokeBoxObj.currentPageNum * MAX_MON_ICONS_IN_BOX
         + pokeBoxObj.row * NUM_MON_ICON_ROW
         + pokeBoxObj.column;
}

bool8 IsLockMon(u8 i)
{
    u16 index = pokeBoxObj.currentPageNum * MAX_MON_ICONS_IN_BOX + i;

    if (index >= MON_TEAM_SELECTOR_COUNT)
    {
        u16 secondIndex = index - MON_TEAM_SELECTOR_COUNT;
        return PokeboxSpecies_Lock(secondIndex);
    }else{
        //gAllTeamMons[selectedIndex]
        return FALSE;
    }

    return TRUE;
}

void LoadCurrentMonData()
{
    u16 species;
    bool8 isShiny = FALSE;
    bool8 isLock = FALSE;
    u16 index = GetSelectedPokemonIndex();

    if (index < MON_TEAM_SELECTOR_COUNT)
    {   
        species = gAllTeamMons[index].specie;
        isShiny = gAllTeamMons[index].isShiny; 
    }
    else
    {
        u16 secondIndex = index - MON_TEAM_SELECTOR_COUNT;
        species = PokeboxSpeciesList_GetSpecie(secondIndex);
        isLock = PokeboxSpecies_Lock(secondIndex);
    }

    pokeBoxObj.frontMonId = CreateMonPicSprite(species, isShiny, 0, TRUE, 38, 58, 15, TAG_NONE);
    gSprites[pokeBoxObj.frontMonId].oam.priority = 1;

    if(isLock)
    {
        gSprites[pokeBoxObj.frontMonId].oam.objMode = ST_OAM_OBJ_BLEND;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 7));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
    }

    PrintAllDataMon(species);
}

static void CompactAndMovePlayerTeamSprites(void)
{
    u8 writeIndex = 0;
    u8 row, col, newRow, newCol;
    u8 spriteId;

    for (u8 i = 0; i < PARTY_SIZE; i++)
    {
        row = i / MON_ICON_TEAM_COLS;
        col = i % MON_ICON_TEAM_COLS;

        spriteId = pokeBoxObj.playerTeamMonSpritesIds[row][col];
        if (spriteId == 0xFF)
            continue;

        // Calculamos la nueva posición en el array compactado
        newRow = writeIndex / MON_ICON_TEAM_COLS;
        newCol = writeIndex % MON_ICON_TEAM_COLS;

        if (newRow != row || newCol != col)
        {
            pokeBoxObj.playerTeamMonSpritesIds[newRow][newCol] = spriteId;
            pokeBoxObj.playerTeamMonSpritesIds[row][col] = 0xFF;
            gSprites[spriteId].x = MON_ICON_PLAYER_TEAM_POS_X + newCol * INCREMENT_MON_ICON_PLAYER_TEAM_POS_X;
            gSprites[spriteId].y = MON_ICON_PLAYER_TEAM_POS_Y + newRow * INCREMENT_MON_ICON_PLAYER_TEAM_POS_Y;
        }

        writeIndex++;
    }

    // Rellenamos los slots restantes con 0xFF
    for (; writeIndex < PARTY_SIZE; writeIndex++)
    {
        newRow = writeIndex / MON_ICON_TEAM_COLS;
        newCol = writeIndex % MON_ICON_TEAM_COLS;
        pokeBoxObj.playerTeamMonSpritesIds[newRow][newCol] = 0xFF;
    }
}

void LoadCurrentMonDataPlayerTeam()
{
    u16 species;
    bool8 isShiny = FALSE;
    u16 index = pokeBoxObj.row_team * 2 + pokeBoxObj.col_team;

    species = GetMonData(&gPlayerParty[index], MON_DATA_SPECIES_OR_EGG);

    if(species == SPECIES_NONE)
    {
        ClearWindoMonData(FALSE);
        return;
    }

    pokeBoxObj.frontMonId = CreateMonPicSprite(species, isShiny, 0, TRUE, 38, 58, 15, TAG_NONE);
    gSprites[pokeBoxObj.frontMonId].oam.priority = 1;

    PrintAllDataMon(species);
}

void LoadMonIconSprites()
{
    u8 spriteId;
    u16 species;
    u8 i, row, col;

    u16 totalCount = MON_TEAM_SELECTOR_COUNT + PokeboxSpeciesList_GetCount();

    for (i = 0; i <  MAX_MON_ICONS_IN_BOX ; i++)
    {

        u16 index = pokeBoxObj.currentPageNum * MAX_MON_ICONS_IN_BOX + i;

        if (index >= totalCount)
            break;

        row = i / NUM_MON_ICON_ROW;
        col = i % NUM_MON_ICON_ROW;

        u8 x = MON_ICON_POS_X + col * INCREMENT_MON_ICON_POS_X;
        u8 y = MON_ICON_POS_Y + row * INCREMENT_MON_ICON_POS_Y;

        if (index < MON_TEAM_SELECTOR_COUNT)
            species = gAllTeamMons[index].specie;
        else
        {
            u16 secondIndex = index - MON_TEAM_SELECTOR_COUNT;
            species = PokeboxSpeciesList_GetSpecie(secondIndex);
        }

        spriteId = CreateMonIcon(species, SpriteCallbackDummy, x, y, 0, 0);
        gSprites[spriteId].oam.priority = 1;

        if(IsLockMon(i))
        {
            gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 7));
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
        }

        // if(!IsLockMon(i) && HasMonInParty(species))
        // {
        //     gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
        //     SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        //     SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(9, 7));
        //     SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);
        // }

        pokeBoxObj.boxMonSpritesIds[row][col] = spriteId;
    }
}

static void LoadMonIconPlayerTeam()
{
    u8 i, row, col;
    u8 spriteId;
    u16 specie = SPECIES_NONE;

    if(gPlayerPartyCount == 0)
        return;

    for(i = 0; i < gPlayerPartyCount; i++)
    {
        col = i % MON_ICON_TEAM_COLS;
        row = i / MON_ICON_TEAM_COLS;

        u8 x = MON_ICON_PLAYER_TEAM_POS_X + col * INCREMENT_MON_ICON_PLAYER_TEAM_POS_X;
        u8 y = MON_ICON_PLAYER_TEAM_POS_Y + row * INCREMENT_MON_ICON_PLAYER_TEAM_POS_Y;
        
        specie =  GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG);

        if(specie == SPECIES_NONE)
            continue;

        spriteId = CreateMonIcon(specie, SpriteCallbackDummy, x, y, 0, GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY));        
        gSprites[spriteId].invisible = FALSE;

        pokeBoxObj.playerTeamMonSpritesIds[row][col] = spriteId;
    }
}

static void HidenMonIconsBox(bool8 invisible)
{
    u8 row, col;

    for (row = 0; row < NUM_MON_ICON_ROW; row++)
    {
        for (col = 0; col < NUM_MON_ICON_ROW; col++)
        {
            u8 spriteId = pokeBoxObj.boxMonSpritesIds[row][col];

            if (spriteId == 0xFF)
                continue;

            gSprites[spriteId].invisible = invisible;
        }
    }
}

static void ClearMonData(bool8 destroyMonIcons)
{
    u8 row, col;


    if(pokeBoxObj.frontMonId != 0xFF) 
    {
        FreeAndDestroyMonPicSprite(pokeBoxObj.frontMonId);
        pokeBoxObj.frontMonId = 0xFF;
    }

    if(destroyMonIcons)
    {
        for (row = 0; row < NUM_MON_ICON_ROW; row++)
        {
            for (col = 0; col < NUM_MON_ICON_ROW; col++)
            {
                u8 spriteId = pokeBoxObj.boxMonSpritesIds[row][col];

                if (spriteId == 0xFF)
                    continue;

                FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
                pokeBoxObj.boxMonSpritesIds[row][col] = 0xFF;
            }
        }
    }
}

static void ClearMonDataPlayerTeam(bool8 destroyMonIcons)
{
    u8 row, col;

    if(pokeBoxObj.frontMonId != 0xFF) 
    {
        FreeAndDestroyMonPicSprite(pokeBoxObj.frontMonId);
        pokeBoxObj.frontMonId = 0xFF;
    }

    if(destroyMonIcons)
    {
        for (row = 0; row < MON_ICON_TEAM_ROWS; row++)
        {
            for (col = 0; col < MON_ICON_TEAM_COLS; col++)
            {
                u8 spriteId = pokeBoxObj.playerTeamMonSpritesIds[row][col];

                if (spriteId == 0xFF)
                    continue;

                FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
                pokeBoxObj.playerTeamMonSpritesIds[row][col] = 0xFF;
            }
        }
    }
}

static void Task_SlideLeftBgTeamPlayer(u8 taskId)
{
    if(++gTasks[taskId].tTimer % 2 == 0)
    {
        gTasks[taskId].tBgSlice += 12;
        SetGpuReg(REG_OFFSET_BG1HOFS, INITIAL_POS_X_BG_TEAM_PLAYER + gTasks[taskId].tBgSlice);
    }

    if(gTasks[taskId].tBgSlice >= 144)
    {
        gTasks[taskId].tTimer = 0;
        LoadMonIconPlayerTeam();
        UpdateSelectorPosition(TRUE);
        SetVisibilitySpriteSelector(FALSE);
        LoadCurrentMonDataPlayerTeam();
        gTasks[taskId].func = Task_HandleTeamPlayerPokebox;
    }

    gTasks[taskId].tTimer += 2;
}

static void Task_SlideRightBgTeamPlayer(u8 taskId)
{
    if(++gTasks[taskId].tTimer % 2 == 0)
    {
        gTasks[taskId].tBgSlice -= 12;
        SetGpuReg(REG_OFFSET_BG1HOFS, INITIAL_POS_X_BG_TEAM_PLAYER + gTasks[taskId].tBgSlice);
    }

    if(gTasks[taskId].tBgSlice <= 0)
    {
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tBgSlice = 0;
        LoadMonIconSprites();
        UpdateSelectorPosition(FALSE);
        SetVisibilitySpriteSelector(FALSE);
        LoadCurrentMonData();
        PrintTextSwapBox();
        gTasks[taskId].func = Task_HandlePokebox;
    }

}

static void Task_HandleTeamPlayerPokebox(u8 taskId)
{
    if (JOY_NEW(B_BUTTON) || JOY_NEW(START_BUTTON))
    {
        SetVisibilitySpriteSelector(TRUE);
        ClearMonDataPlayerTeam(TRUE);
        gTasks[taskId].func = Task_SlideRightBgTeamPlayer;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        gTasks[taskId].func = Task_StorageMonInPokebox;
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (pokeBoxObj.col_team < MON_ICON_TEAM_COLS -1)
        {
            pokeBoxObj.col_team += 1;
            UpdateSelectorPosition(TRUE);
            SetVisibilitySpriteSelector(FALSE);
            ClearMonDataPlayerTeam(FALSE);
            LoadCurrentMonDataPlayerTeam();
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (pokeBoxObj.col_team > 0)
        {
            pokeBoxObj.col_team -= 1;
            UpdateSelectorPosition(TRUE);
            ClearMonDataPlayerTeam(FALSE);
            LoadCurrentMonDataPlayerTeam();
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (pokeBoxObj.row_team > 0)
        {
            pokeBoxObj.row_team -= 1;
            UpdateSelectorPosition(TRUE);
            ClearMonDataPlayerTeam(FALSE);
            LoadCurrentMonDataPlayerTeam();
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (pokeBoxObj.row_team < MON_ICON_TEAM_ROWS -1)
        {
            pokeBoxObj.row_team += 1;
            UpdateSelectorPosition(TRUE);
            ClearMonDataPlayerTeam(FALSE);
            LoadCurrentMonDataPlayerTeam();
        }
    }
    
    if (JOY_NEW(DPAD_ANY)) {
        PrintMsgActions(MSG_ACTION_CONTROLS);
    }
}

static void Task_HandlePokebox(u8 taskId)
{
    u8 newRow = pokeBoxObj.row;
    u8 newCol = pokeBoxObj.column;

    if (gPaletteFade.active)
        return;

    if (JOY_NEW(START_BUTTON))
    {
        SetVisibilitySpriteSelector(TRUE);
        ClearWindoMonData(TRUE);
        ClearMonData(TRUE);
        gTasks[taskId].func = Task_SlideLeftBgTeamPlayer;
    }
    else if (JOY_NEW(SELECT_BUTTON))
    {
        HidenMonIconsBox(TRUE);
        SetVisibilitySpriteSelector(TRUE);
        gTasks[taskId].func = Task_ShowMonInfo;
    }
    else if (JOY_NEW(A_BUTTON))
    {
        gTasks[taskId].func = Task_AddMonTeamPlayer;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        if(GetFirstFreeSlotMonParty() != 0xFF)
        {
            PrintMsgActions(MSG_ACTION_NOT_TEAM_FULL);
        }else{
            BeginNormalPaletteFade(PALETTES_ALL, 10, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_FadeOut;
        }
    }
    else if (JOY_NEW(L_BUTTON) && pokeBoxObj.currentPageNum > 0)
    {
        ClearMonData(TRUE);
        pokeBoxObj.currentPageNum -= 1;
        LoadMonIconSprites();
        ResetSelectorPosition();
        LoadCurrentMonData();
        PrintTextSwapBox();
    }
    else if (JOY_NEW(R_BUTTON) && pokeBoxObj.currentPageNum < getTotalNumPages()-1)
    {
        ClearMonData(TRUE);
        pokeBoxObj.currentPageNum += 1;
        LoadMonIconSprites();
        ResetSelectorPosition();
        LoadCurrentMonData();
        PrintTextSwapBox();
    }
    else if (JOY_NEW(DPAD_RIGHT))
    {
        if (newCol + 1 < NUM_MON_ICON_ROW)
            newCol++;
        if (pokeBoxObj.boxMonSpritesIds[newRow][newCol] != 0xFF)
        {
            pokeBoxObj.column = newCol;
            UpdateSelectorPosition(FALSE);
            ClearMonData(FALSE);
            LoadCurrentMonData();
        }
    }
    else if (JOY_NEW(DPAD_LEFT))
    {
        if (newCol > 0)
            newCol--;
        if (pokeBoxObj.boxMonSpritesIds[newRow][newCol] != 0xFF)
        {
            pokeBoxObj.column = newCol;
            UpdateSelectorPosition(FALSE);
            ClearMonData(FALSE);
            LoadCurrentMonData();
        }
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (newRow > 0)
            newRow--;
        if (pokeBoxObj.boxMonSpritesIds[newRow][newCol] != 0xFF)
        {
            pokeBoxObj.row = newRow;
            UpdateSelectorPosition(FALSE);
            ClearMonData(FALSE);
            LoadCurrentMonData();
        }
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (newRow + 1 < NUM_MON_ICON_ROW) 
            newRow++;
        if (pokeBoxObj.boxMonSpritesIds[newRow][newCol] != 0xFF)
        {
            pokeBoxObj.row = newRow;
            UpdateSelectorPosition(FALSE);
            ClearMonData(FALSE);
            LoadCurrentMonData();
        }
    }
    
    if(JOY_NEW(DPAD_ANY))
    {
        PrintMsgActions(MSG_ACTION_CONTROLS);
    }
}

static void Task_WaitToReturnHandlePokebox(u8 taskId)
{
    if (JOY_NEW(SELECT_BUTTON) || JOY_NEW(B_BUTTON))
    {
        ClearMonTextInfoPage(TRUE);
        HidenMonIconsBox(FALSE);
        SetVisibilitySpriteSelector(FALSE);
        gTasks[taskId].func = Task_HandlePokebox;
    }
}

static void Task_ShowMonInfo(u8 taskId)
{
    PrintMonTextInfoPage();
    gTasks[taskId].func = Task_WaitToReturnHandlePokebox;
}

static void Task_AddMonTeamPlayer(u8 taskId)
{
    u16 specie = SPECIES_NONE;
    bool8 addMon = FALSE;
    const struct TeamSelectorMonData *mon;
    u8 slot = GetFirstFreeSlotMonParty();
    u16 index = GetSelectedPokemonIndex();

    if(slot == 0xFF)
    {
        PrintMsgActions(MSG_ACTION_FULL_TEAM);
        gTasks[taskId].func = Task_HandlePokebox;
        return;
    }

    if (index < MON_TEAM_SELECTOR_COUNT)
    {
        mon = &gAllTeamMons[index];

        if(HasMonInParty(mon->specie))
            PrintMsgActions(MSG_ACTION_MON_IN_TEAM);
        else{
            GiveMonTeamFromSelector(slot, mon);
            specie = mon->specie;
            addMon = TRUE;
        }
    }
    else{
        specie = PokeboxSpeciesList_GetSpecie(index - MON_TEAM_SELECTOR_COUNT);
        if(IsLockMon( pokeBoxObj.row * NUM_MON_ICON_ROW + pokeBoxObj.column))
            PrintMsgActions(MSG_ACTION_LOCK_MON);
        else if(HasMonInParty(specie))
            PrintMsgActions(MSG_ACTION_MON_IN_TEAM);
        else{
            ScriptGiveMon(specie, 100, ITEM_NONE);
            addMon = TRUE;
        }
    }

    if(addMon && specie != SPECIES_NONE)
    {
        StringCopy(gStringVar1, GetSpeciesName(specie));
        PrintMsgActions(MSG_ACTION_ADD_MON_PARTY);
        CalculatePlayerPartyCount();
    }

    gTasks[taskId].func = Task_HandlePokebox;
}

static void Task_StorageMonInPokebox(u8 taskId)
{
    u16 index = pokeBoxObj.row_team * 2 + pokeBoxObj.col_team;
    u8 spriteId = pokeBoxObj.playerTeamMonSpritesIds[pokeBoxObj.row_team][pokeBoxObj.col_team];
 
    u16 specie =  GetMonData(&gPlayerParty[index], MON_DATA_SPECIES_OR_EGG);

    if(specie == SPECIES_NONE || spriteId == 0xFF)
    {
        gTasks[taskId].func = Task_HandleTeamPlayerPokebox;
        return;
    }

    if(gPlayerPartyCount == 1)
    {
        PrintMsgActions(MSG_ACTION_ONLY_ONE_MON_IN_TEAM);
    }
    else
    {
        ClearMonDataPlayerTeam(FALSE);
        ClearWindoMonData(FALSE);
        FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
        pokeBoxObj.playerTeamMonSpritesIds[pokeBoxObj.row_team][pokeBoxObj.col_team] = 0xFF;

        ZeroMonData(&gPlayerParty[index]);

        CompactPartySlots();
        CalculatePlayerPartyCount();
        CompactAndMovePlayerTeamSprites();
    }

    gTasks[taskId].func = Task_HandleTeamPlayerPokebox;
}

//========== SECCIÓN: FUNCIONES ÚTILES ==========//

#define tBG3HOFS data[4]
#define tBG3VOFS data[5]

static void Task_MovementBgs(u8 taskId)
{
    if (gTasks[taskId].tTimer % 4 == 0)
    {
        SetGpuReg(REG_OFFSET_BG3HOFS, ++gTasks[taskId].tBG3HOFS);
        SetGpuReg(REG_OFFSET_BG3VOFS, ++gTasks[taskId].tBG3VOFS);
    }

    gTasks[taskId].tTimer += 1;
}

#undef tBG3HOFS
#undef tBG3VOFS

static void Task_FadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSpecialVar_Result = TRUE;
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}


//========== SECCIÓN: GFX SETUP FUNC ==========//

void CB2_InitPokeBoxSetUp(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        DmaClearLarge16(3, (void *) VRAM, VRAM_SIZE, 4096);
        FreeAllSpritePalettes();
        gMain.state++;
    case 1:
        VBlank_CB_PokeBox();
        CB2_PokeBox();
        gMain.state++;
        break;
    case 2:
        LoadBgs();
        InitWindowPokeBox();
        gMain.state++;
        break;
    case 3:

        ListMenuLoadStdPalAt(BG_PLTT_ID(6), 1);//cargar paleta iconos de tipo
        LoadMonIconPalettes();

        LoadCompressedSpriteSheet(&gSpriteSheet_CategoryIcons);
        LoadSpritePalette(&gSpritePal_CategoryIcons);

        LoadSelectorSprite();
        pokeBoxObj.selectorId = CreateSelectorSprite();

        pokeBoxObj.currentPageNum = 0;
        pokeBoxObj.row_team = 0;
        pokeBoxObj.col_team = 0;

        memset(pokeBoxObj.boxMonSpritesIds, 0xFF, sizeof(pokeBoxObj.boxMonSpritesIds));
        memset(pokeBoxObj.playerTeamMonSpritesIds, 0xFF, sizeof(pokeBoxObj.playerTeamMonSpritesIds));
        memset(pokeBoxObj.boxMonIconCategoyIds, 0xFF, sizeof(pokeBoxObj.boxMonIconCategoyIds));
        
        gMain.state++;
        break;
    case 4:
        CreateTask(Task_MovementBgs, 0);
        LoadMonIconSprites();
        LoadCurrentMonData();
        PrintMsgActions(MSG_ACTION_CONTROLS);
        PrintTextSwapBox();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
    default:
        SetVBlankCallback(VBlank_CB_PokeBox);
        SetMainCallback2(CB2_PokeBox);
        CreateTask(Task_HandlePokebox, 1);
    }
}

void StartPokeBox_CB2(void)
{
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        // PokeBoxObj.fromField = FALSE;
        CleanupOverworldWindowsAndTilemaps();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetMainCallback2(CB2_InitPokeBoxSetUp);
    }
}

void StartPokeBoxFromField_CB2(void)
{
    gMain.state = 0;
    // PokeBoxObj.fromField = TRUE;
    CleanupOverworldWindowsAndTilemaps();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gMain.savedCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    SetMainCallback2(CB2_InitPokeBoxSetUp);
}