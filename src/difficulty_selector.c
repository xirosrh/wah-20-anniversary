#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "difficulty.h"
#include "difficulty_selector.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// --- Graphics ---
static const u16 sDifficulty_Pal[] = INCBIN_U16("graphics/cope_speech/difficulty/palette.gbapal");
static const u32 sDifficulty_Tiles[] = INCBIN_U32("graphics/cope_speech/difficulty/tiles.4bpp.lz");
static const u32 sDifficultyInterface_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/interface.bin.lz");
static const u32 sDifficultyEasy_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/easy.bin.lz");
static const u32 sDifficultyNormal_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/normal.bin.lz");
static const u32 sDifficultyHard_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/hard.bin.lz");
static const u32 sDifficultyBg_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/bg.bin.lz");

static const u16 sMainMenuTextPal[] = INCBIN_U16("graphics/interface/main_menu_text.gbapal");

static const u16 sPalEasy[] = {RGB(8, 21, 8)};
static const u16 sPalNormal[] = {RGB(14, 14, 31)};
static const u16 sPalHard[] = {RGB(31, 14, 14)};

static const u8 sTextWhite[3] = {0, 1, 2};
static const u8 sTextBlack[3] = {0, 2, 3};

// Window indices must match intro cope gender/difficulty layout (MSG unused on this screen).
enum
{
    WINDOW_MSG_BOX,
    WINDOW_TITLE_BOX,
    WINDOW_YESNO_BOX,
    WINDOW_EASY_BOX,
    WINDOW_NORMAL_BOX,
    WINDOW_HARD_BOX,
    WINDOW_DIFFICULTY_BOX,
};

static const struct BgTemplate sBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sWindowTemplates[] =
{
    [WINDOW_MSG_BOX] =
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 300
    },
    [WINDOW_TITLE_BOX] =
    {
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 30,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 700
    },
    [WINDOW_YESNO_BOX] =
    {
        .bg = 1,
        .tilemapLeft = 25,
        .tilemapTop = 14,
        .width = 4,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 760
    },
    [WINDOW_EASY_BOX] =
    {
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 776
    },
    [WINDOW_NORMAL_BOX] =
    {
        .bg = 1,
        .tilemapLeft = 11,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 792
    },
    [WINDOW_HARD_BOX] =
    {
        .bg = 1,
        .tilemapLeft = 21,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 808
    },
    [WINDOW_DIFFICULTY_BOX] =
    {
        .bg = 1,
        .tilemapLeft = 12,
        .tilemapTop = 7,
        .width = 18,
        .height = 11,
        .paletteNum = 15,
        .baseBlock = 824
    },
    DUMMY_WIN_TEMPLATE,
};

#define tDifficulty data[1]

static void CB2_InitDifficultySelector(void);
static void CB2_DifficultySelectorMain(void);
static void VBlank_CB_DifficultySelector(void);
static void SetupDifficultyWindowBlend(void);
static void Task_DifficultySelectorField(u8 taskId);
static void Task_ExitDifficultySelectorToField(u8 taskId);
static void LoadDifficultyGraphicsToBgs(void);
static void PrintDifficultyStaticWindowText(void);

static void SetupDifficultyWindowBlend(void)
{
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

static void VBlank_CB_DifficultySelector(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    if (!gPaletteFade.active)
    {
        ChangeBgX(3, 128, BG_COORD_ADD);
        ChangeBgY(3, 128, BG_COORD_SUB);
    }
}

static void CB2_DifficultySelectorMain(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

void DifficultySelector_RefreshPanel(enum DifficultyLevel level)
{
    const u8 headerY = 1;
    u8 bodyY = headerY + GetFontAttribute(FONT_NORMAL, FONTATTR_MAX_LETTER_HEIGHT)
        + GetFontAttribute(FONT_NORMAL, FONTATTR_LINE_SPACING) + 1;

    FillWindowPixelBuffer(WINDOW_DIFFICULTY_BOX, PIXEL_FILL(0));

    if (level == DIFFICULTY_EASY)
    {
        LZ77UnCompVram(sDifficultyEasy_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplates[2].mapBaseIndex));
        LoadPalette(sPalEasy, BG_PLTT_ID(0) + 10, PLTT_SIZEOF(1));
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, headerY, sTextBlack, TEXT_SKIP_DRAW, gText_Difficulty_CharacteristicsHeader);
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, bodyY, sTextBlack, TEXT_SKIP_DRAW, gText_Easy_Description);
    }
    else if (level == DIFFICULTY_NORMAL)
    {
        LZ77UnCompVram(sDifficultyNormal_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplates[2].mapBaseIndex));
        LoadPalette(sPalNormal, BG_PLTT_ID(0) + 10, PLTT_SIZEOF(1));
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, headerY, sTextBlack, TEXT_SKIP_DRAW, gText_Difficulty_CharacteristicsHeader);
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, bodyY, sTextBlack, TEXT_SKIP_DRAW, gText_Normal_Description);
    }
    else if (level == DIFFICULTY_HARD)
    {
        LZ77UnCompVram(sDifficultyHard_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplates[2].mapBaseIndex));
        LoadPalette(sPalHard, BG_PLTT_ID(0) + 10, PLTT_SIZEOF(1));
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, headerY, sTextBlack, TEXT_SKIP_DRAW, gText_Difficulty_CharacteristicsHeader);
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, bodyY, sTextBlack, TEXT_SKIP_DRAW, gText_Hard_Description);
    }
    CopyWindowToVram(WINDOW_DIFFICULTY_BOX, COPYWIN_FULL);
}

static void LoadDifficultyGraphicsToBgs(void)
{
    LoadPalette(sDifficulty_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LZ77UnCompVram(sDifficulty_Tiles, (void *)VRAM + BG_CHAR_SIZE * sBgTemplates[1].charBaseIndex);
    LZ77UnCompVram(sDifficultyInterface_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplates[2].mapBaseIndex));
    LZ77UnCompVram(sDifficultyBg_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplates[3].mapBaseIndex));
}

static void PrintDifficultyStaticWindowText(void)
{
    u8 x;

    x = (240 - GetStringWidth(FONT_NORMAL, gText_Choose_Difficulty, 0)) / 2;
    AddTextPrinterParameterized3(WINDOW_TITLE_BOX, FONT_NORMAL, x, 0, sTextWhite, TEXT_SKIP_DRAW, gText_Choose_Difficulty);
    x = (64 - GetStringWidth(FONT_NORMAL, gText_Cope_Easy, 0)) / 2;
    AddTextPrinterParameterized3(WINDOW_EASY_BOX, FONT_NORMAL, x, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Cope_Easy);
    x = (64 - GetStringWidth(FONT_NORMAL, gText_Cope_Normal, 0)) / 2;
    AddTextPrinterParameterized3(WINDOW_NORMAL_BOX, FONT_NORMAL, x, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Cope_Normal);
    x = (64 - GetStringWidth(FONT_NORMAL, gText_Cope_Hard, 0)) / 2;
    AddTextPrinterParameterized3(WINDOW_HARD_BOX, FONT_NORMAL, x, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Cope_Hard);
}

void DifficultySelector_SetupUiForIntro(void)
{
    LoadDifficultyGraphicsToBgs();

    FillWindowPixelBuffer(WINDOW_TITLE_BOX, PIXEL_FILL(10));
    FillWindowPixelBuffer(WINDOW_YESNO_BOX, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_EASY_BOX, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_NORMAL_BOX, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_HARD_BOX, PIXEL_FILL(0));
    FillWindowPixelBuffer(WINDOW_DIFFICULTY_BOX, PIXEL_FILL(0));
    PutWindowTilemap(WINDOW_EASY_BOX);
    PutWindowTilemap(WINDOW_NORMAL_BOX);
    PutWindowTilemap(WINDOW_HARD_BOX);
    PutWindowTilemap(WINDOW_DIFFICULTY_BOX);

    PrintDifficultyStaticWindowText();

    DifficultySelector_RefreshPanel(DIFFICULTY_EASY);

    CopyWindowToVram(WINDOW_TITLE_BOX, COPYWIN_FULL);
    CopyWindowToVram(WINDOW_YESNO_BOX, COPYWIN_FULL);
    CopyWindowToVram(WINDOW_EASY_BOX, COPYWIN_FULL);
    CopyWindowToVram(WINDOW_NORMAL_BOX, COPYWIN_FULL);
    CopyWindowToVram(WINDOW_HARD_BOX, COPYWIN_FULL);

    SetupDifficultyWindowBlend();
}

bool8 DifficultySelector_HandleInputIntro(u8 taskId)
{
    if (JOY_NEW(DPAD_LEFT) && gTasks[taskId].tDifficulty > DIFFICULTY_EASY)
    {
        gTasks[taskId].tDifficulty--;
        DifficultySelector_RefreshPanel((enum DifficultyLevel)gTasks[taskId].tDifficulty);
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(DPAD_RIGHT) && gTasks[taskId].tDifficulty < DIFFICULTY_HARD)
    {
        gTasks[taskId].tDifficulty++;
        DifficultySelector_RefreshPanel((enum DifficultyLevel)gTasks[taskId].tDifficulty);
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }

    return FALSE;
}

static void Task_ExitDifficultySelectorToField(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
        DestroyTask(taskId);
    }
}

static void Task_DifficultySelectorField(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_SELECT);
        gSpecialVar_Result = FALSE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExitDifficultySelectorToField;
        return;
    }

    if (JOY_NEW(DPAD_LEFT) && gTasks[taskId].tDifficulty > DIFFICULTY_EASY)
    {
        gTasks[taskId].tDifficulty--;
        DifficultySelector_RefreshPanel((enum DifficultyLevel)gTasks[taskId].tDifficulty);
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(DPAD_RIGHT) && gTasks[taskId].tDifficulty < DIFFICULTY_HARD)
    {
        gTasks[taskId].tDifficulty++;
        DifficultySelector_RefreshPanel((enum DifficultyLevel)gTasks[taskId].tDifficulty);
        PlaySE(SE_SELECT);
    }
    else if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        SetCurrentDifficultyLevel((enum DifficultyLevel)gTasks[taskId].tDifficulty);
        gSpecialVar_Result = TRUE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_ExitDifficultySelectorToField;
    }
}

static void CB2_InitDifficultySelector(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetPaletteFade();
        FreeAllSpritePalettes();
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        gMain.state++;
        // fallthrough
    case 1:
        VBlank_CB_DifficultySelector();
        CB2_DifficultySelectorMain();
        gMain.state++;
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWindowTemplates);
        ResetAllBgsCoordinates();
        ChangeBgX(2, 8 << 8, BG_COORD_ADD);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        FadeOutAndPlayNewMapMusic(MUS_WEATHER_GROUDON, 4);
        gMain.state++;
        break;
    case 3:
        LoadDifficultyGraphicsToBgs();
        FillWindowPixelBuffer(WINDOW_TITLE_BOX, PIXEL_FILL(10));
        FillWindowPixelBuffer(WINDOW_YESNO_BOX, PIXEL_FILL(0));
        FillWindowPixelBuffer(WINDOW_EASY_BOX, PIXEL_FILL(0));
        FillWindowPixelBuffer(WINDOW_NORMAL_BOX, PIXEL_FILL(0));
        FillWindowPixelBuffer(WINDOW_HARD_BOX, PIXEL_FILL(0));
        FillWindowPixelBuffer(WINDOW_DIFFICULTY_BOX, PIXEL_FILL(0));
        PutWindowTilemap(WINDOW_EASY_BOX);
        PutWindowTilemap(WINDOW_NORMAL_BOX);
        PutWindowTilemap(WINDOW_HARD_BOX);
        PutWindowTilemap(WINDOW_DIFFICULTY_BOX);
        PrintDifficultyStaticWindowText();
        CopyWindowToVram(WINDOW_TITLE_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_YESNO_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_EASY_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_NORMAL_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_HARD_BOX, COPYWIN_FULL);
        DifficultySelector_RefreshPanel(GetCurrentDifficultyLevel());
        SetupDifficultyWindowBlend();
        gMain.state++;
        break;
    case 4:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        // fallthrough
    default:
        SetVBlankCallback(VBlank_CB_DifficultySelector);
        SetMainCallback2(CB2_DifficultySelectorMain);
        {
            u8 taskId = CreateTask(Task_DifficultySelectorField, 0);
            gTasks[taskId].tDifficulty = GetCurrentDifficultyLevel();
        }
        break;
    }
}

void StartDifficultySelectorFromField_CB2(void)
{
    gMain.state = 0;
    CleanupOverworldWindowsAndTilemaps();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    gMain.savedCallback = CB2_ReturnToFieldContinueScriptPlayMapMusic;
    SetMainCallback2(CB2_InitDifficultySelector);
}

#undef tDifficulty
