#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "palette.h"
#include "sprite.h"
#include "task.h"
#include "gpu_regs.h"
#include "main.h"
#include "intro.h"
#include "expansion_intro.h"
#include "constants/rgb.h"

#if EXPANSION_INTRO == TRUE

// Background layer indices
enum
{
    WAH_SPLASH_BG2,  // Logo layer
    WAH_SPLASH_BG3   // Background layer
};

// Graphics data
static const u32 sBgTiles_WahBackground[] = INCBIN_U32("graphics/expansion_intro/wah_background.4bpp.smol");
static const u32 sBgTiles_WahLogo[] = INCBIN_U32("graphics/expansion_intro/wah_logo.4bpp.smol");
static const u32 sBgMap_WahBackground[] = INCBIN_U32("graphics/expansion_intro/wah_background.bin.smolTM");
static const u32 sBgMap_WahLogo[] = INCBIN_U32("graphics/expansion_intro/wah_logo.bin.smolTM");
static const u16 sBgPal_WahSplash[] = INCBIN_U16("graphics/expansion_intro/wah_splash.gbapal");

// Background color (coral #fb7272) for blending
// #fb7272 = RGB(251, 114, 114) → GBA 5-bit: RGB(31, 14, 14)
#define WAH_BG_COLOR RGB(31, 14, 14)

// Timing constants
#define SPLASH_DISPLAY_TIME 180  // 3 seconds at 60fps
#define LOGO_FADE_DELAY 30       // Half second before logo fades in

// Palette masks
#define BG_PALETTE_MASK (1 << 0)    // Palette slot 0 (background)
#define LOGO_PALETTE_MASK (1 << 1)  // Palette slot 1 (logo)

// Function declarations
static void VBlankCB_ExpansionIntro(void);
static void ExpansionIntro_InitBgs(void);
static void ExpansionIntro_LoadGraphics(void);

// BG templates
static const struct BgTemplate sBgTemplates_WahSplashScreen[] =
{
    [WAH_SPLASH_BG2] = {
        .bg = 2,
        .charBaseIndex = 1,
        .mapBaseIndex = 20,
        .screenSize = 2,
        .paletteMode = 0
    },
    [WAH_SPLASH_BG3] = {
        .bg = 3,
        .charBaseIndex = 2,
        .mapBaseIndex = 22,
        .screenSize = 2,
        .paletteMode = 0
    },
};

void CB2_ExpansionIntro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

#define tState data[0]
#define tFrameCounter data[1]

void Task_HandleExpansionIntro(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        // Initialize
        SetVBlankCallback(VBlankCB_ExpansionIntro);
        ExpansionIntro_InitBgs();
        ExpansionIntro_LoadGraphics();

        // Show only background layer
        ShowBg(3);
        // BG2 (logo) stays hidden for now

        // Fade in ONLY the background palette (slot 0) from black
        BeginNormalPaletteFade(BG_PALETTE_MASK, 0, 16, 0, RGB_BLACK);
        tState++;
        break;

    case 1:
        // Wait for background fade to complete
        if (!gPaletteFade.active)
        {
            tFrameCounter = 0;
            tState++;
        }
        break;

    case 2:
        // Short delay before showing logo
        if (++tFrameCounter >= LOGO_FADE_DELAY)
        {
            // Show logo layer
            ShowBg(2);
            // Fade in logo palette (slot 1) from coral to actual colors
            // First, set the "unfaded" buffer for palette 1 to actual colors (already done in LoadGraphics)
            // The faded buffer currently has coral - fade from that to unfaded
            BeginNormalPaletteFade(LOGO_PALETTE_MASK, 0, 16, 0, WAH_BG_COLOR);
            tFrameCounter = 0;
            tState++;
        }
        break;

    case 3:
        // Wait for logo fade, then wait for display time or input
        if (!gPaletteFade.active)
        {
            if (tFrameCounter >= SPLASH_DISPLAY_TIME || gMain.newKeys != 0)
            {
                // Fade out BOTH palettes to black
                BeginNormalPaletteFade(BG_PALETTE_MASK | LOGO_PALETTE_MASK, 0, 0, 16, RGB_BLACK);
                tState++;
            }
            else
            {
                tFrameCounter++;
            }
        }
        else if (gMain.newKeys != 0)
        {
            // Allow skip even during logo fade
            BeginNormalPaletteFade(BG_PALETTE_MASK | LOGO_PALETTE_MASK, 0, 0, 16, RGB_BLACK);
            tState++;
        }
        break;

    case 4:
        // Wait for fade out, then transition to intro
        if (!gPaletteFade.active)
        {
            ResetSpriteData();
            FreeAllSpritePalettes();
            DestroyTask(taskId);
            CreateTask(Task_Scene1_Load, 0);
            SetMainCallback2(MainCB2_Intro);
        }
        break;
    }
}

#undef tState
#undef tFrameCounter

static void VBlankCB_ExpansionIntro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void ExpansionIntro_InitBgs(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sBgTemplates_WahSplashScreen, ARRAY_COUNT(sBgTemplates_WahSplashScreen));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    HideBg(0);
    HideBg(1);
    HideBg(2);
    HideBg(3);
}

static void ExpansionIntro_LoadGraphics(void)
{
    // Load background (BG3) tiles and tilemap
    DecompressDataWithHeaderVram(sBgTiles_WahBackground, (void *)BG_CHAR_ADDR(sBgTemplates_WahSplashScreen[WAH_SPLASH_BG3].charBaseIndex));
    DecompressDataWithHeaderVram(sBgMap_WahBackground, (u16 *)BG_SCREEN_ADDR(sBgTemplates_WahSplashScreen[WAH_SPLASH_BG3].mapBaseIndex));

    // Load logo (BG2) tiles and tilemap
    DecompressDataWithHeaderVram(sBgTiles_WahLogo, (void *)BG_CHAR_ADDR(sBgTemplates_WahSplashScreen[WAH_SPLASH_BG2].charBaseIndex));
    DecompressDataWithHeaderVram(sBgMap_WahLogo, (u16 *)BG_SCREEN_ADDR(sBgTemplates_WahSplashScreen[WAH_SPLASH_BG2].mapBaseIndex));

    // Load palettes to unfaded buffer
    LoadPalette(sBgPal_WahSplash, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sBgPal_WahSplash, BG_PLTT_ID(1), PLTT_SIZE_4BPP);

    // Pre-blend BOTH palettes to their initial fade states BEFORE any BG is shown
    // This prevents any flash between LoadPalette and BeginNormalPaletteFade
    // Background starts fully black
    BlendPalettes(BG_PALETTE_MASK, 16, RGB_BLACK);
    // Logo starts fully coral (invisible against coral background)
    BlendPalettes(LOGO_PALETTE_MASK, 16, WAH_BG_COLOR);
}

#endif // EXPANSION_INTRO
