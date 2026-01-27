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


const u32 WahCredits_Tileset[] = INCBIN_U32("graphics/wah_credits/wahCredits_tiles.4bpp.lz");
const u32 WahCredits_Tilemap[] = INCBIN_U32("graphics/wah_credits/wahCredits_map.bin.lz");
const u16 WahCredits_Palette[] = INCBIN_U16("graphics/wah_credits/wahCredits.gbapal");

enum{
    BG_CREDITS_1,
    BG_CREDITS_2,
    BG_LOGO
};

static const struct BgTemplate CreditsBgTemplates[] =
{
    [BG_CREDITS_1] = 
    {
        .bg = 0, 
        .charBaseIndex = 0, 
        .mapBaseIndex = 26, 
        .priority = 0 
    },
    [BG_CREDITS_2] =
    {
        .bg = 1, 
        .charBaseIndex = 1, 
        .mapBaseIndex = 27, 
        .priority = 1 
    },
    [BG_LOGO] =
    {
        .bg = 2,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 2
    }
};

//========== SECCIÓN: FUNCIONES DE CARGA DE BGS ==========//

static void LoadBgs(void)
{
    InitBgsFromTemplates(0, CreditsBgTemplates, ARRAY_COUNT(CreditsBgTemplates));

    LZ77UnCompVram(WahCredits_Tileset, (void*) BG_CHAR_ADDR(CreditsBgTemplates[BG_LOGO].charBaseIndex));
    LZ77UnCompVram(WahCredits_Tilemap, (u16*) BG_SCREEN_ADDR(CreditsBgTemplates[BG_LOGO].mapBaseIndex));

    LoadPalette(WahCredits_Palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    ResetAllBgsCoordinates(); 

    ShowBg(BG_CREDITS_1);
    ShowBg(BG_CREDITS_2);
    ShowBg(BG_LOGO);
}

static void VBlank_CB_Credits(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_Credits(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

//========== SECCIÓN: FUNCIONES DE CARGA DE WINDOWS ==========//

enum
{
    WINDOW_CREDITS_1,
    WINDOW_CREDITS_2,
    WINDOW_COUNT,
};

static const struct WindowTemplate sWindowTemplatesCredits[] =
{
    [WINDOW_CREDITS_1]
    {
        .bg = 0, 
        .tilemapLeft = 1, 
        .tilemapTop = 0, 
        .width = 9, 
        .height = 20, 
        .paletteNum = 0, 
        .baseBlock = 1 
    },
    [WINDOW_CREDITS_2]
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 0,
        .width = 9,
        .height = 20,
        .paletteNum = 0,
        .baseBlock =  181
    },
    DUMMY_WIN_TEMPLATE,
};

static void InitWindowCredits(void)
{
	InitWindows(sWindowTemplatesCredits);
    DeactivateAllTextPrinters();
	LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP); 

    PutWindowTilemap(WINDOW_CREDITS_1);
    PutWindowTilemap(WINDOW_CREDITS_2);
}

static const u8 *const sListCredits[35] =
{
    COMPOUND_STRING("Alex"),
    COMPOUND_STRING("Bruno"),
    COMPOUND_STRING("Carlos"),
    COMPOUND_STRING("Dante"),
    COMPOUND_STRING("Ethan"),
    COMPOUND_STRING("Fabio"),
    COMPOUND_STRING("Gael"),
    COMPOUND_STRING("Hector"),
    COMPOUND_STRING("Ivan"),
    COMPOUND_STRING("Javier"),
    COMPOUND_STRING("Kevin"),
    COMPOUND_STRING("Leo"),
    COMPOUND_STRING("Marco"),
    COMPOUND_STRING("Nico"),
    COMPOUND_STRING("Oscar"),
    COMPOUND_STRING("Pablo"),
    COMPOUND_STRING("Ruben"),
    COMPOUND_STRING("Sergio"),
    COMPOUND_STRING("Tomas"),
    COMPOUND_STRING("Victor"),
    COMPOUND_STRING("Axiom"),
    COMPOUND_STRING("Blaze"),
    COMPOUND_STRING("Cryo"),
    COMPOUND_STRING("Drako"),
    COMPOUND_STRING("Flux"),
    COMPOUND_STRING("Hex"),
    COMPOUND_STRING("Kairo"),
    COMPOUND_STRING("Nyx"),
    COMPOUND_STRING("Orbit"),
    COMPOUND_STRING("Pixel"),
    COMPOUND_STRING("Quartz"),
    COMPOUND_STRING("Razor"),
    COMPOUND_STRING("Synth"),
    COMPOUND_STRING("Vortex"),
    COMPOUND_STRING("Zer0"),
};

void PrintCredits(u8 windowId)
{
    u8 i;
    u8 x = 0;
    u8 y = 0;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));

    for ( i = 0; i < ARRAY_COUNT(sListCredits); i++)
    {
        if(y > 155) break;
        
        x = GetStringCenterAlignXOffset(FONT_SMALL, sListCredits[i], sWindowTemplatesCredits[0].width*8);
        AddTextPrinterParameterized(windowId, FONT_SMALL, sListCredits[i], x, y, 0, NULL);

        y += 12;
    }
    
    CopyWindowToVram(windowId, COPYWIN_FULL);
}

void CB2_InitCreditsSetUp(void)
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
        VBlank_CB_Credits();
        CB2_Credits();
        gMain.state++;
        break;
    case 2:
        LoadBgs();
        InitWindowCredits();
        FadeOutAndPlayNewMapMusic(MUS_WEATHER_GROUDON, 4); 
        gMain.state++;
        break;
    case 3:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;

    default:
        SetVBlankCallback(VBlank_CB_Credits);
        SetMainCallback2(CB2_Credits);
        // CreateTask(Task_HandleCredits, 1);
        PrintCredits(WINDOW_CREDITS_1);
    }
}

bool8 StartCredits_CB2(void)
{
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        CleanupOverworldWindowsAndTilemaps();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetMainCallback2(CB2_InitCreditsSetUp);

        return TRUE;
    }

    return FALSE;
}