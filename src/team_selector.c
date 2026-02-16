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
#include "pokeball.h"
#include "pokemon.h"
#include "script_pokemon_util.h"
#include "event_data.h"
#include "pokemon.h"

//========== SECCIÓN: VARIABLES ==========//

#define tTimer data[7]

#define ICON_CATEGORY_X 231
#define ICON_CATEGORY_Y 97

#define TAG_ITEM_ICON 5400
#define ITEM_SPRITE_POS_X 80
#define ITEM_SPRITE_POS_Y 101

#define NUM_MAX_CHARACTHERS 7

static const u8 sSpecialWordList[][NUM_MAX_CHARACTHERS] = {
    { CHAR_X, CHAR_I, CHAR_R, CHAR_O, CHAR_S, EOS, EOS },
};

struct TeamSelector
{
    u8 monTeamNum;//indice del equipo selecionado
    u8 indexSelectedMon;//indice de pokemon selecionado
    u8 frontMonId;//id del front sprite
    u8 itemId;//ide del sprite item
    u8 monSpritesIds[MAX_TEAM_SIZE]; //id de los icons sprites de cada mon
    u8 categoryIconIds[4]; // ids de los iconos de categoria
    bool8 isGeneratedRandomTeam; // indica si hay generado un equipo random
    u8 monIndexRandomTeam[MAX_TEAM_SIZE]; // indice de los pokemon random en la pool
    u16 teamAbilities[TEAM_COUNT][MAX_TEAM_SIZE];// id de la habilidad de cada poke

    u8 windowIdMsg;
    u8 optionSelectMsg;//1 SI, 0 NO
    bool8 fromField; 
};

static EWRAM_DATA struct TeamSelector teamSelectorObj = {0};

const u8 sTextColorWhite[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
const u8 sTextColorBlack[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_RED};


static void LoadMoveIconType(u16 move, u8 indexMove);
static void LoadMoveCateroyIcon(u16 move, u8 indexMove);
void LoadAllDataCurrenteSelectedMon(bool8 loadMonIcons);
static void ClearMonSprites(bool8 hiddenCategoryIcons, bool8 destroyMonIcons);
static void GenerateRandomTeam();
static void Task_HandleTeamSelector(u8 taskId);
static void Task_HandleWantThisTeam(u8 taskId);
static void Task_HandleExitConfirm(u8 taskId);
static void Task_ExitWithoutSelection(u8 taskId);
static void CreateExitConfirmWindow(void);
static void RemoveExitConfirmWindow(void);

const u32 TeamSelectorBG23_Tileset[] = INCBIN_U32("graphics/team_selector/bg23_tileset.4bpp.lz");
const u32 TeamSelectorBG2_Tilemap[] = INCBIN_U32("graphics/team_selector/bg2_tilemap.bin.lz");
const u32 TeamSelectorBG3_Tilemap[] = INCBIN_U32("graphics/team_selector/bg3_tilemap.bin.lz");
const u16 TeamSelectorBG_Palette[] = INCBIN_U16("graphics/team_selector/bg23.gbapal");


enum BgsTeamSelector
{
    BG_MSGS,
    BG_WINDOWS,
    BG_MENU,
    BG_SLICE,
};


static const struct BgTemplate TeamSelectorBgTemplates[] =
{
    [BG_MSGS] = 
    {
        .bg = 0, 
        .charBaseIndex = 0, 
        .mapBaseIndex = 26, 
        .priority = 0 
    },
    [BG_WINDOWS] =
    {
        .bg = 1, 
        .charBaseIndex = 1, 
        .mapBaseIndex = 27, 
        .priority = 1 
    },
    [BG_MENU] =
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
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
    InitBgsFromTemplates(0, TeamSelectorBgTemplates, ARRAY_COUNT(TeamSelectorBgTemplates));

    LZ77UnCompVram(TeamSelectorBG23_Tileset, (void*) BG_CHAR_ADDR(TeamSelectorBgTemplates[BG_SLICE].charBaseIndex));
    LZ77UnCompVram(TeamSelectorBG3_Tilemap, (u16*) BG_SCREEN_ADDR(TeamSelectorBgTemplates[BG_SLICE].mapBaseIndex));

    LZ77UnCompVram(TeamSelectorBG2_Tilemap, (u16*) BG_SCREEN_ADDR(TeamSelectorBgTemplates[BG_MENU].mapBaseIndex)); 

    LoadPalette(TeamSelectorBG_Palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    ResetAllBgsCoordinates(); 

    ShowBg(BG_MSGS);
    ShowBg(BG_WINDOWS);
    ShowBg(BG_MENU);
    ShowBg(BG_SLICE);
}

static void VBlank_CB_TeamSelector(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_TeamSelector(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

//========== SECCIÓN: FUNCIONES DE CARGA DE WINDOWS ==========//

enum
{
    WINDOW_NAME,
    WINDOW_ABILITY,
    WINDOW_ABILITY_DESCRIPTION,
    WINDOW_MOVES,
    WINDOW_MOVE_TYPE,
    WINDOW_MON_TYPE,
    WINDOW_L_BUTTON,
    WINDOW_R_BUTTON,
    WINDOW_RANDOM_TEAM,
    WINDOW_MSG,
    WINDOW_COUNT,
};

static const struct WindowTemplate sWindowTemplatesTeamSelector[] =
{
    [WINDOW_NAME]
    {
        .bg = 1, 
        .tilemapLeft = 1, 
        .tilemapTop = 15, 
        .width = 9, 
        .height = 2, 
        .paletteNum = 0, 
        .baseBlock = 1 
    },
    [WINDOW_ABILITY]
    {
        .bg = 1,
        .tilemapLeft = 13,
        .tilemapTop = 5,
        .width = 12,
        .height = 2,
        .paletteNum = 0,
        .baseBlock =  19
    },
    [WINDOW_ABILITY_DESCRIPTION]
    {
        .bg = 1,
        .tilemapLeft = 13,
        .tilemapTop = 7,
        .width = 19,
        .height = 2,
        .paletteNum = 0,
        .baseBlock = 43
    },
    [WINDOW_MOVES]
    {
        .bg = 1,
        .tilemapLeft = 13,
        .tilemapTop = 11,
        .width = 10,
        .height = 10,
        .paletteNum = 0,
        .baseBlock = 81
    },
    [WINDOW_MOVE_TYPE]
    {
        .bg = 1,
        .tilemapLeft = 24,
        .tilemapTop = 11,
        .width = 4,
        .height = 10,
        .paletteNum = 6,
        .baseBlock = 181
    },
    [WINDOW_MON_TYPE]
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 17,
        .width = 9,
        .height = 2,
        .paletteNum = 6,
        .baseBlock = 221
    },
    [WINDOW_L_BUTTON]
    {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 1,
        .width = 2,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 239
    },
    [WINDOW_R_BUTTON]
    {
        .bg = 1,
        .tilemapLeft = 27,
        .tilemapTop = 1,
        .width = 3,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 243
    },
    [WINDOW_RANDOM_TEAM]
    {
        .bg = 1,
        .tilemapLeft = 11,
        .tilemapTop = 1,
        .width = 2,
        .height = 6,
        .paletteNum = 15,
        .baseBlock = 249
    },
    DUMMY_WIN_TEMPLATE,
};


static const struct WindowTemplate sMsgTeamSelector_WindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 8,
    .width = 28,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 261
};

static void InitWindowTeamSelector(void)
{
	InitWindows(sWindowTemplatesTeamSelector);
    DeactivateAllTextPrinters();
	LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP); 

    PutWindowTilemap(WINDOW_NAME);
    PutWindowTilemap(WINDOW_ABILITY);
    PutWindowTilemap(WINDOW_ABILITY_DESCRIPTION);
    PutWindowTilemap(WINDOW_MOVES);
    PutWindowTilemap(WINDOW_MOVE_TYPE);
    PutWindowTilemap(WINDOW_MON_TYPE);
    PutWindowTilemap(WINDOW_L_BUTTON);
    PutWindowTilemap(WINDOW_R_BUTTON);
    PutWindowTilemap(WINDOW_RANDOM_TEAM);
}

void DrawMenuCursor(bool8 isYes)
{
    u8 width, height;
    u8 x = (isYes) ? 6*8 : 17*8;
    u8 x_fill = (!isYes) ? 6*8 : 17*8;

    width = GetMenuCursorDimensionByFont(FONT_SMALL, 0);
    height = GetMenuCursorDimensionByFont(FONT_SMALL, 1);

    FillWindowPixelRect(teamSelectorObj.windowIdMsg, PIXEL_FILL(1), x_fill, 2*8, width, height);
    AddTextPrinterParameterized(teamSelectorObj.windowIdMsg, FONT_SMALL, gText_SelectorArrow3, x, 2*8, 0, 0);
    CopyWindowToVram(teamSelectorObj.windowIdMsg, COPYWIN_FULL);
}

static void CreateMsgWindow()
{
    u8 windowId;
    u8 x;

    const u8 gText_WantThisTeam[] = _("¿Seguro que quieres este equipo?");
    const u8 gText_YesNo[] = _("Sí{CLEAR_TO 88}No");

    windowId = AddWindow(&sMsgTeamSelector_WindowTemplate);
    teamSelectorObj.windowIdMsg = windowId;

    PutWindowTilemap(windowId);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    LoadWindowGfx(windowId, gSaveBlock2Ptr->optionsWindowFrameType, 1, BG_PLTT_ID(14));
    DrawTextBorderOuter(windowId, 1, 14);

    x = GetStringCenterAlignXOffset(FONT_SMALL, gText_WantThisTeam, sMsgTeamSelector_WindowTemplate.width*8);
    AddTextPrinterParameterized(windowId, FONT_SMALL, gText_WantThisTeam, x, 0, 0, NULL);
    
    x = GetStringCenterAlignXOffset(FONT_SMALL, gText_YesNo, sMsgTeamSelector_WindowTemplate.width*8);
    AddTextPrinterParameterized(windowId, FONT_SMALL, gText_YesNo, x, 16, 0, NULL);
    
    teamSelectorObj.optionSelectMsg = 1;
    DrawMenuCursor(TRUE);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void RemoveWindowMsgWantThisTeam()
{
    ClearDialogWindowAndFrameToTransparent(teamSelectorObj.windowIdMsg, TRUE);
    ClearStdWindowAndFrameToTransparent(teamSelectorObj.windowIdMsg, FALSE);
    CopyWindowToVram(teamSelectorObj.windowIdMsg, COPYWIN_GFX);
    RemoveWindow(teamSelectorObj.windowIdMsg);
}

static void CreateExitConfirmWindow(void)
{
    u8 windowId;
    u8 x;

    const u8 gText_WantToExit[] = _("¿Quieres salir?");
    const u8 gText_YesNo[] = _("Sí{CLEAR_TO 88}No");

    windowId = AddWindow(&sMsgTeamSelector_WindowTemplate);
    teamSelectorObj.windowIdMsg = windowId;

    PutWindowTilemap(windowId);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    LoadWindowGfx(windowId, gSaveBlock2Ptr->optionsWindowFrameType, 1, BG_PLTT_ID(14));
    DrawTextBorderOuter(windowId, 1, 14);

    x = GetStringCenterAlignXOffset(FONT_SMALL, gText_WantToExit, sMsgTeamSelector_WindowTemplate.width*8);
    AddTextPrinterParameterized(windowId, FONT_SMALL, gText_WantToExit, x, 0, 0, NULL);
    
    x = GetStringCenterAlignXOffset(FONT_SMALL, gText_YesNo, sMsgTeamSelector_WindowTemplate.width*8);
    AddTextPrinterParameterized(windowId, FONT_SMALL, gText_YesNo, x, 16, 0, NULL);
    
    teamSelectorObj.optionSelectMsg = 1;
    DrawMenuCursor(TRUE);
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void RemoveExitConfirmWindow(void)
{
    ClearDialogWindowAndFrameToTransparent(teamSelectorObj.windowIdMsg, TRUE);
    ClearStdWindowAndFrameToTransparent(teamSelectorObj.windowIdMsg, FALSE);
    CopyWindowToVram(teamSelectorObj.windowIdMsg, COPYWIN_GFX);
    RemoveWindow(teamSelectorObj.windowIdMsg);
}

static void PrintLRButtons()
{
    const u8 gText_L_Button[] = _("{L_BUTTON}");
    const u8 gText_R_Button[] = _("{R_BUTTON}");
    const u8 gText_Select_Button[] = _("{SELECT_BUTTON}");

    FillWindowPixelBuffer(WINDOW_L_BUTTON, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_R_BUTTON, PIXEL_FILL(0));

    if(teamSelectorObj.monTeamNum > 0)
    {
        AddTextPrinterParameterized3(WINDOW_L_BUTTON, FONT_NORMAL, 0, 0, sTextColorWhite, 0, gText_L_Button);
    }

    if(teamSelectorObj.monTeamNum < TEAM_RANDOM)
    {
        AddTextPrinterParameterized3(WINDOW_R_BUTTON, FONT_NORMAL, 8, 0, sTextColorWhite, 0, gText_R_Button);
    }else{
        AddTextPrinterParameterized3(WINDOW_R_BUTTON, FONT_NORMAL, 0, 0, sTextColorWhite, 0, gText_Select_Button);
    }

    CopyWindowToVram(WINDOW_L_BUTTON, 3);
    CopyWindowToVram(WINDOW_R_BUTTON, 3);
}

static void PrintAbilityMon(const struct TeamSelectorMonData *mon)
{
    u8 indexAbility = 0;
    u8 abilityNum = (mon->ability != ABILITY_NONE) 
    ? mon->ability 
    : teamSelectorObj.teamAbilities[teamSelectorObj.monTeamNum][teamSelectorObj.indexSelectedMon];

    FillWindowPixelBuffer(WINDOW_ABILITY, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_ABILITY_DESCRIPTION, PIXEL_FILL(0));

    if(abilityNum == ABILITY_NONE)
    {
        do {
            indexAbility = Random() % NUM_ABILITY_SLOTS;
            abilityNum = gSpeciesInfo[mon->specie].abilities[indexAbility];
        } while ( abilityNum == ABILITY_NONE);

        teamSelectorObj.teamAbilities[teamSelectorObj.monTeamNum][teamSelectorObj.indexSelectedMon] = abilityNum;
    }

    AddTextPrinterParameterized3(WINDOW_ABILITY, FONT_SMALL, 0, 0, sTextColorWhite, 0, gAbilitiesInfo[abilityNum].name);

    AddTextPrinterParameterized3(WINDOW_ABILITY_DESCRIPTION, FONT_SMALL, 0, 3, sTextColorBlack, 0, gAbilitiesInfo[abilityNum].description);

    CopyWindowToVram(WINDOW_ABILITY, 3);
    CopyWindowToVram(WINDOW_ABILITY_DESCRIPTION, 3);
}

static void PrintMovesMon(const struct TeamSelectorMonData *mon)
{
    u8 i;
    u8 y = 4;

    FillWindowPixelBuffer(WINDOW_MOVES, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_MOVE_TYPE, PIXEL_FILL(15));

    for (i = 0; i < ARRAY_COUNT(mon->moves); i++)
    {
        if(mon->moves[i] == MOVE_NONE)
            StringCopy(gStringVar1, gText_OneDash);
        else
            StringCopy(gStringVar1, GetMoveName(mon->moves[i]));
        
        AddTextPrinterParameterized3(WINDOW_MOVES, FONT_SMALL, 0, y, sTextColorWhite, 0, gStringVar1);
        LoadMoveCateroyIcon(mon->moves[i], i);
        LoadMoveIconType(mon->moves[i], i);
        y += 16; 
    }
    
    CopyWindowToVram(WINDOW_MOVES, 3);
}

static void PrintNameMon(const struct TeamSelectorMonData *mon)
{
    FillWindowPixelBuffer(WINDOW_NAME, PIXEL_FILL(0));
    AddTextPrinterParameterized3(WINDOW_NAME, FONT_NORMAL, 0, 0, sTextColorWhite, 0, GetSpeciesName(mon->specie));
    CopyWindowToVram(WINDOW_NAME, 3);
}

static void LoadMoveIconType(u16 move, u8 indexMove)
{
    enum Type type = GetMoveType(move);
    BlitMenuInfoIcon(WINDOW_MOVE_TYPE, type, 0, 4 + (16 * indexMove));   
    CopyWindowToVram(WINDOW_MOVE_TYPE, 3);
}

static void LoadMonIconType(u16 specie)
{
    u8 type1 = gSpeciesInfo[specie].types[0];
    u8 type2 = gSpeciesInfo[specie].types[1];

    FillWindowPixelBuffer(WINDOW_MON_TYPE, PIXEL_FILL(15));

    BlitMenuInfoIcon(WINDOW_MON_TYPE, type1, 0, 2);  
    if( type1 != type2)
        BlitMenuInfoIcon(WINDOW_MON_TYPE, type2, 40, 2);  

    CopyWindowToVram(WINDOW_MON_TYPE, 3);
}

static void ShowMoveCateroyIcon(u16 move, u8 indexMove)
{
    u8 categoryIconId = 0xFF;
    enum DamageCategory category;

    if(teamSelectorObj.categoryIconIds[indexMove] == 0xFF)
        return;

    categoryIconId = teamSelectorObj.categoryIconIds[indexMove];

    category = GetBattleMoveCategory(move);
    StartSpriteAnim(&gSprites[categoryIconId], category);
    gSprites[categoryIconId].invisible = FALSE;
}

static void LoadMoveCateroyIcon(u16 move, u8 indexMove)
{   
    u8 categoryIconId = 0xFF;
    enum DamageCategory category;

    if(move == MOVE_NONE)
        return;

    if(teamSelectorObj.categoryIconIds[indexMove] != 0xFF)
    {
        ShowMoveCateroyIcon( move, indexMove);
        return;
    }

    category = GetBattleMoveCategory(move);
    
    categoryIconId = CreateSprite(&gSpriteTemplate_CategoryIcons, ICON_CATEGORY_X, ICON_CATEGORY_Y + (16 * indexMove), 1);

    StartSpriteAnim(&gSprites[categoryIconId], category);
    gSprites[categoryIconId].invisible = FALSE;
    gSprites[categoryIconId].oam.priority = 1; 

    teamSelectorObj.categoryIconIds[indexMove] = categoryIconId;
}

static void LoadMonIconSprites()
{
    u8 i = 0, indexMon = 0;
    u8 spriteId = 0;
    u8 x = 39;

    const struct TeamSelectorMonData *mon;

    for (i = 0; i < MAX_TEAM_SIZE; i++)
    {
        if(teamSelectorObj.monSpritesIds[i] != 0xFF)
            continue;
            
        if(teamSelectorObj.isGeneratedRandomTeam && teamSelectorObj.monTeamNum == TEAM_RANDOM)
            indexMon = teamSelectorObj.monIndexRandomTeam[i];
        else
           indexMon = gTeamSelectorPlayer[teamSelectorObj.monTeamNum].team[i];

        mon = &gAllTeamMons[indexMon];
        spriteId = CreateMonIcon(mon->specie, SpriteCallbackDummy, x, 12, 0, 0);
        gSprites[spriteId].oam.priority = 1;
        x += 32;

       teamSelectorObj.monSpritesIds[i] = spriteId;
    }
}

static void LoadItemSprite(u16 itemId)
{
    u8 itemIdSprite = 0xFF;

    if(teamSelectorObj.itemId != 0xFF || itemId == ITEM_NONE)
        return;

    itemIdSprite = AddItemIconSprite(TAG_ITEM_ICON, TAG_ITEM_ICON, itemId);
    gSprites[itemIdSprite].x2 = ITEM_SPRITE_POS_X;
    gSprites[itemIdSprite].y2 = ITEM_SPRITE_POS_Y;
    gSprites[itemIdSprite].oam.priority = 1;
    teamSelectorObj.itemId = itemIdSprite;
}

static void UpdateSelectedMonIcon()
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(teamSelectorObj.monSpritesIds); i++)
    {
        if(teamSelectorObj.monSpritesIds[i] == 0xFF)
            continue;

        if(teamSelectorObj.indexSelectedMon == i) 
        { 
            gSprites[teamSelectorObj.monSpritesIds[i]].oam.objMode = ST_OAM_OBJ_NORMAL;
            continue;
        }

        if(gSprites[teamSelectorObj.monSpritesIds[i]].oam.objMode == ST_OAM_OBJ_BLEND)
            continue;

        gSprites[teamSelectorObj.monSpritesIds[i]].oam.objMode = ST_OAM_OBJ_BLEND;
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(7, 11));
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP);

    }

}


static void GetIVsByNature(const struct TeamSelectorMonData *mon, u8 *ivs)
{
    const struct NatureInfo natureMod = gNaturesInfo[mon->nature];

    for (u8 i = 0; i < NUM_STATS; i++)
    {
        ivs[i] = (natureMod.statDown == i) ? 0 : 31;
    }
}

static u8 GetAbilitySlotForSpecies(u16 species, u16 abilityId)
{
    if (abilityId == ABILITY_NONE)
        return NUM_ABILITY_SLOTS;
    for (u8 slot = 0; slot < NUM_ABILITY_SLOTS; slot++)
    {
        if (GetAbilityBySpecies(species, slot) == (enum Ability)abilityId)
            return slot;
    }
    return NUM_ABILITY_SLOTS;
}

static void GiveTeamPlayer()
{
    const struct TeamSelectorMonData *mon;
    u8 i;
    u8 indexMon = 0;
    enum PokeBall  ball = BALL_POKE;
    enum ShinyMode shiny;
    enum Type typeTera = TYPE_NONE;

    u8 gender;
    u8 evs[6];
    u8 ivs[6];

    u16 tempMoves[4];

    for ( i = 0; i < MAX_TEAM_SIZE; i++)
    {
        
        if(teamSelectorObj.isGeneratedRandomTeam && teamSelectorObj.monTeamNum == TEAM_RANDOM)
            indexMon = teamSelectorObj.monIndexRandomTeam[i];
        else
            indexMon = gTeamSelectorPlayer[teamSelectorObj.monTeamNum].team[i];

        mon = &gAllTeamMons[indexMon];
        shiny = mon->isShiny ? SHINY_MODE_ALWAYS : SHINY_MODE_RANDOM;
        memcpy(tempMoves, mon->moves, sizeof(tempMoves));
        memcpy(evs, mon->ev, sizeof(evs));
        GetIVsByNature(mon, ivs);

        gender = (Random() < gSpeciesInfo[mon->specie].genderRatio) ? MON_FEMALE : MON_MALE;
        ScriptGiveMonParameterized(0, i, mon->specie, 100, mon->itemId, ball, mon->nature, GetAbilitySlotForSpecies(mon->specie, mon->ability), gender, evs, ivs, tempMoves, shiny, FALSE, typeTera, FALSE);
    }
    gPlayerPartyCount = MAX_TEAM_SIZE;
}

//========== SECCIÓN: FUNCIONES ÚTILES ==========//

static void Task_FadeOut(u8 taskId);
static void Task_HandleWantThisTeam(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT) && teamSelectorObj.optionSelectMsg != TRUE)
    {
        DrawMenuCursor(TRUE);
        teamSelectorObj.optionSelectMsg = !teamSelectorObj.optionSelectMsg;
    }

    if (JOY_NEW(DPAD_RIGHT) && teamSelectorObj.optionSelectMsg != FALSE)
    {
        DrawMenuCursor(FALSE);
        teamSelectorObj.optionSelectMsg = !teamSelectorObj.optionSelectMsg;
    }

    if (JOY_NEW(A_BUTTON))
    {
        if(teamSelectorObj.optionSelectMsg == FALSE)
        {
            RemoveWindowMsgWantThisTeam();
            gTasks[taskId].func = Task_HandleTeamSelector;
        }else{
            GiveTeamPlayer();
            FlagSet(FLAG_SYS_POKEMON_GET);
            BeginNormalPaletteFade(PALETTES_ALL, 10, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_FadeOut;
        }
    }

    if (JOY_NEW(B_BUTTON))
    {
        RemoveWindowMsgWantThisTeam();
        gTasks[taskId].func = Task_HandleTeamSelector;
    }
}

static void Task_ExitWithoutSelection(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gSpecialVar_Result = FALSE;
        ClearMonSprites(FALSE, TRUE);
        RemoveExitConfirmWindow();
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
        DestroyTask(taskId);
    }
}

static void Task_HandleExitConfirm(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT) && teamSelectorObj.optionSelectMsg != TRUE)
    {
        DrawMenuCursor(TRUE);
        teamSelectorObj.optionSelectMsg = !teamSelectorObj.optionSelectMsg;
    }

    if (JOY_NEW(DPAD_RIGHT) && teamSelectorObj.optionSelectMsg != FALSE)
    {
        DrawMenuCursor(FALSE);
        teamSelectorObj.optionSelectMsg = !teamSelectorObj.optionSelectMsg;
    }

    if (JOY_NEW(A_BUTTON))
    {
        if(teamSelectorObj.optionSelectMsg == FALSE)
        {
            RemoveExitConfirmWindow();
            gTasks[taskId].func = Task_HandleTeamSelector;
        }
        else
        {
            BeginNormalPaletteFade(PALETTES_ALL, 10, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_ExitWithoutSelection;
        }
    }

    if (JOY_NEW(B_BUTTON))
    {
        RemoveExitConfirmWindow();
        gTasks[taskId].func = Task_HandleTeamSelector;
    }
}

static void Task_HandleTeamSelector(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    if( JOY_NEW(SELECT_BUTTON) && teamSelectorObj.monTeamNum == TEAM_RANDOM)
    {
        GenerateRandomTeam();
        ClearMonSprites(TRUE, TRUE);
        teamSelectorObj.indexSelectedMon = 0;
        LoadAllDataCurrenteSelectedMon(TRUE);
        UpdateSelectedMonIcon();
    }

    if ( JOY_NEW(R_BUTTON) && teamSelectorObj.monTeamNum <= TEAM_COUNT - 1 && teamSelectorObj.monTeamNum != TEAM_RANDOM)
    {
        if( teamSelectorObj.monTeamNum !=  TEAM_RANDOM)
            teamSelectorObj.monTeamNum += 1;

        if(teamSelectorObj.monTeamNum == TEAM_RANDOM && !teamSelectorObj.isGeneratedRandomTeam)
        {
            teamSelectorObj.isGeneratedRandomTeam = TRUE;
            GenerateRandomTeam();
        }

        ClearMonSprites(TRUE, TRUE);
        teamSelectorObj.indexSelectedMon = 0;
        LoadAllDataCurrenteSelectedMon(TRUE);
        UpdateSelectedMonIcon();
    }

    if (JOY_NEW(L_BUTTON) && teamSelectorObj.monTeamNum > 0)
    {
        teamSelectorObj.monTeamNum -= 1;
        ClearMonSprites(TRUE, TRUE);
        teamSelectorObj.indexSelectedMon = 0;
        LoadAllDataCurrenteSelectedMon(TRUE);
        UpdateSelectedMonIcon();
    }

    if (JOY_NEW(DPAD_LEFT) && teamSelectorObj.indexSelectedMon >  0)
    {
        ClearMonSprites(TRUE, FALSE);
        teamSelectorObj.indexSelectedMon -= 1;
        LoadAllDataCurrenteSelectedMon(FALSE);
        UpdateSelectedMonIcon();
    }

    if (JOY_NEW(DPAD_RIGHT) && teamSelectorObj.indexSelectedMon < MAX_TEAM_SIZE-1)
    {
        ClearMonSprites(TRUE, FALSE);
        teamSelectorObj.indexSelectedMon += 1;
        LoadAllDataCurrenteSelectedMon(FALSE);
        UpdateSelectedMonIcon();
    }

    if(JOY_NEW(A_BUTTON))
    {
        CreateMsgWindow();
        gTasks[taskId].func = Task_HandleWantThisTeam;
    }

    if (JOY_NEW(B_BUTTON) && teamSelectorObj.fromField)
    {
        CreateExitConfirmWindow();
        gTasks[taskId].func = Task_HandleExitConfirm;
    }
}

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
        ClearMonSprites(FALSE, TRUE);
        RemoveWindowMsgWantThisTeam();
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_ReturnToFieldContinueScript);
        DestroyTask(taskId);
    }
}

void LoadAllDataCurrenteSelectedMon(bool8 loadMonIcons)
{

    const struct TeamSelectorMonData *mon;
    u8 indexMon = 0;

    if(loadMonIcons)
    {
        LoadMonIconSprites();
        UpdateSelectedMonIcon();
    }

    if(teamSelectorObj.isGeneratedRandomTeam && teamSelectorObj.monTeamNum == TEAM_RANDOM)
        indexMon = teamSelectorObj.monIndexRandomTeam[teamSelectorObj.indexSelectedMon];
    else
        indexMon = gTeamSelectorPlayer[teamSelectorObj.monTeamNum].team[teamSelectorObj.indexSelectedMon];

    mon = &gAllTeamMons[indexMon];

    teamSelectorObj.frontMonId = CreateMonPicSprite(mon->specie, mon->isShiny, 0, TRUE, 39, 71, 15, TAG_NONE);
    gSprites[teamSelectorObj.frontMonId].oam.priority = 1;
    LoadItemSprite(mon->itemId);

    PrintLRButtons();
    PrintNameMon(mon);
    PrintMovesMon(mon);
    PrintAbilityMon(mon);
    LoadMonIconType(mon->specie);
}

static void ClearMonSprites(bool8 hiddenCategoryIcons, bool8 destroyMonIcons)
{
    u8 i;

    //FrontSprite
    if(teamSelectorObj.frontMonId != 0xFF) 
    {
        FreeAndDestroyMonPicSprite(teamSelectorObj.frontMonId);
        teamSelectorObj.frontMonId = 0xFF;
    }

    if(teamSelectorObj.itemId != 0xFF) 
    {
        FreeSpriteTilesByTag(TAG_ITEM_ICON);
        FreeSpritePaletteByTag(TAG_ITEM_ICON);
        DestroySprite(&gSprites[teamSelectorObj.itemId]);
        teamSelectorObj.itemId = 0xFF;
    }

    //category Icons
    for (i = 0; i < ARRAY_COUNT(teamSelectorObj.categoryIconIds); i++)
    {
        if(teamSelectorObj.categoryIconIds[i] == 0xFF)
            continue;

        if(hiddenCategoryIcons) {
            gSprites[teamSelectorObj.categoryIconIds[i]].invisible = !gSprites[teamSelectorObj.categoryIconIds[i]].invisible;
        }else{
            DestroySprite(&gSprites[teamSelectorObj.categoryIconIds[i]]);
            teamSelectorObj.categoryIconIds[i] = 0xFF;
        }
    }

    //mon icons
    for (i = 0; i < MAX_TEAM_SIZE; i++)
    {
        if(!destroyMonIcons) break;

        if(teamSelectorObj.monSpritesIds[i] == 0xFF)
            continue;
            
        FreeAndDestroyMonIconSprite(&gSprites[teamSelectorObj.monSpritesIds[i]]);
        teamSelectorObj.monSpritesIds[i] = 0xFF;
    }
}

static void ConvertNameToUpper(u8 *name)
{
    s8 i;

    for (i = 0; i < NUM_MAX_CHARACTHERS; i++)
    {
        if (name[i] == EOS)
            break;

        if (name[i] >= CHAR_a && name[i] <= CHAR_z)
            name[i] -= 26;
    }
}

static bool8 CheckPlayerName(void)
{
    s8 i, z;
    u8 playerNameUpper[NUM_MAX_CHARACTHERS];

    memset(playerNameUpper, EOS, sizeof(playerNameUpper));
    StringCopy(playerNameUpper, gSaveBlock2Ptr->playerName);
    ConvertNameToUpper(playerNameUpper);

    for (z = 0; z < ARRAY_COUNT(sSpecialWordList); z++)
    {
        bool8 match = TRUE;

        for (i = 0; i < NUM_MAX_CHARACTHERS; i++)
        {
            if (playerNameUpper[i] == EOS && sSpecialWordList[z][i] == EOS)
                break;

            if (playerNameUpper[i] != sSpecialWordList[z][i])
            {
                match = FALSE;
                break;
            }
        }

        if (match)
            return TRUE;
    }

    return FALSE;
}

static void AddSpecialMonToRandomTeamByPlayerName()
{
    u8 i;
    u8 indexToReplace = 0xFF;
    u8 indexSpecialMon = 119; //indice de electrode sandia
    const struct TeamSelectorMonData *mon1;
    const struct TeamSelectorMonData *mon2;

    if(!CheckPlayerName())
        return;

    for (i = 0; i < ARRAY_COUNT(teamSelectorObj.monIndexRandomTeam); i++)
    {
        mon1 = &gAllTeamMons[teamSelectorObj.monIndexRandomTeam[i]];
        mon2 = &gAllTeamMons[teamSelectorObj.monIndexRandomTeam[i]];
        
        if(mon1->specie == mon2->specie) {
            indexToReplace = 0xFF;
            break;
        }

        if( gSpeciesInfo[mon1->specie].types[0] == gSpeciesInfo[mon2->specie].types[0] || 
            gSpeciesInfo[mon1->specie].types[0] == gSpeciesInfo[mon2->specie].types[1] ||
            gSpeciesInfo[mon1->specie].types[1] == gSpeciesInfo[mon2->specie].types[0] || 
            gSpeciesInfo[mon1->specie].types[1] == gSpeciesInfo[mon2->specie].types[1]
        ){
            indexToReplace = i;
            break;
        }
    }

    if(indexToReplace != 0xFF)
        teamSelectorObj.monIndexRandomTeam[indexToReplace] = indexSpecialMon;
    else
        teamSelectorObj.monIndexRandomTeam[Random() % 6] = indexSpecialMon;
}

static void GenerateRandomTeam()
{

    for (u8 i = 0; i < 6; i++)
    {
        u8 idx;
        bool8 repeated;

        do
        {
            repeated = FALSE;
            idx = Random() % NUM_MONS_POOL;

            for (u8 j = 0; j < i; j++)
            {
                if (teamSelectorObj.monIndexRandomTeam[j] == idx)
                {
                    repeated = TRUE;
                    break;
                }
            }
        } while (repeated);

        teamSelectorObj.monIndexRandomTeam[i] = idx;
        teamSelectorObj.teamAbilities[TEAM_RANDOM][i] = ABILITY_NONE;
    }

    AddSpecialMonToRandomTeamByPlayerName();
}


//========== SECCIÓN: GFX SETUP FUNC ==========//

    // teamSelectorObj
    // u8 monTeamNum;
    // u8 indexSelectedMon;
    // u8 frontMonId;
    // u16 monSpritesIds[6];
    // u8 categoryIconIds[4];

void CB2_InitTeamSelectorSetUp(void)
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
        VBlank_CB_TeamSelector();
        CB2_TeamSelector();
        gMain.state++;
        break;
    case 2:
        LoadBgs();
        InitWindowTeamSelector();
        // LoadMessageBoxAndBorderGfx();
        FadeOutAndPlayNewMapMusic(MUS_WEATHER_GROUDON, 4); 
        gMain.state++;
        break;
    case 3:
       
        ListMenuLoadStdPalAt(BG_PLTT_ID(6), 1);//cargar paleta iconos de tipo
        LoadMonIconPalettes();

        LoadCompressedSpriteSheet(&gSpriteSheet_CategoryIcons);
        LoadSpritePalette(&gSpritePal_CategoryIcons);

        teamSelectorObj.monTeamNum = 0;
        teamSelectorObj.indexSelectedMon = 0;
        teamSelectorObj.frontMonId = 0xFF;
        teamSelectorObj.itemId = 0xFF;
        teamSelectorObj.isGeneratedRandomTeam = FALSE;

        memset(teamSelectorObj.monSpritesIds, 0xFF, sizeof(teamSelectorObj.monSpritesIds));
        memset(teamSelectorObj.categoryIconIds, 0xFF, sizeof(teamSelectorObj.categoryIconIds));
        memset(teamSelectorObj.monIndexRandomTeam, 0xFF, sizeof(teamSelectorObj.monIndexRandomTeam));
        gMain.state++;
        break;
    case 4:
        CreateTask(Task_MovementBgs, 0);
        LoadAllDataCurrenteSelectedMon(TRUE);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
    default:
        SetVBlankCallback(VBlank_CB_TeamSelector);
        SetMainCallback2(CB2_TeamSelector);
        CreateTask(Task_HandleTeamSelector, 1);
    }
}

bool8 StartTeamSelector_CB2(void)
{
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        teamSelectorObj.fromField = FALSE; 
        CleanupOverworldWindowsAndTilemaps();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetMainCallback2(CB2_InitTeamSelectorSetUp);

        return TRUE;
    }

    return FALSE;
}

void StartTeamSelectorFromField_CB2(void)
{
    gMain.state = 0;
    teamSelectorObj.fromField = TRUE;
    CleanupOverworldWindowsAndTilemaps();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    SetMainCallback2(CB2_InitTeamSelectorSetUp);
}