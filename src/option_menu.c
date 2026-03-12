#include "global.h"
#include "option_menu.h"
#include "bg.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "list_menu.h"
#include "gba/m4a_internal.h"
#include "constants/rgb.h"
#include "speedup.h"

#define tTextSpeed data[1]
#define tBattleSceneOff data[2]
#define tBattleStyle data[3]
#define tSound data[4]
#define tButtonMode data[5]
#define tWalkSpeed data[6]
#define tSpeedup data[7]

enum
{
    MENUITEM_TEXTSPEED,
    MENUITEM_BATTLESCENE,
    MENUITEM_BATTLESTYLE,
    MENUITEM_SOUND,
    MENUITEM_BUTTONMODE,
    MENUITEM_WALKSPEED,
    MENUITEM_SPEEDUP,
    MENUITEM_CANCEL,
    MENUITEM_COUNT,
};

enum
{
    WIN_HEADER,
    WIN_OPTIONS
};

#define Y_DIFF 16
#define OPTIONS_ON_SCREEN 7

static void Task_OptionMenuFadeIn(u8 taskId);
static void Task_OptionMenuProcessInput(u8 taskId);
static void Task_OptionMenuSave(u8 taskId);
static void Task_OptionMenuFadeOut(u8 taskId);
static void HighlightOptionMenuItem(void);
static u8 TextSpeed_ProcessInput(u8 selection);
static void TextSpeed_DrawChoices(u8 selection, u8 y);
static u8 BattleScene_ProcessInput(u8 selection);
static void BattleScene_DrawChoices(u8 selection, u8 y);
static u8 BattleStyle_ProcessInput(u8 selection);
static void BattleStyle_DrawChoices(u8 selection, u8 y);
static u8 Sound_ProcessInput(u8 selection);
static void Sound_DrawChoices(u8 selection, u8 y);
static u8 ButtonMode_ProcessInput(u8 selection);
static void ButtonMode_DrawChoices(u8 selection, u8 y);
static u8 WalkSpeed_ProcessInput(u8 selection);
static void WalkSpeed_DrawChoices(u8 selection, u8 y);
static u8 Speedup_ProcessInput(u8 selection);
static void Speedup_DrawChoices(u8 selection, u8 y);
static void DrawHeaderText(void);
static void DrawOptionMenuTexts(void);
static void DrawBgWindowFrames(void);
static void DrawItemChoices(u8 taskId, u8 menuItem, u8 y);
static void DrawItemLabel(u8 menuItem, u8 y);
static void ScrollMenu(u8 direction);

EWRAM_DATA static bool8 sArrowPressed = FALSE;
EWRAM_DATA static u8 sMenuCursor = 0;
EWRAM_DATA static u16 sScrollOffset = 0;
EWRAM_DATA static u8 sScrollArrowsTaskId = 0;

static const u8 gText_Option[]             = _("Opciones");
static const u8 gText_TextSpeedSlow[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Lento");
static const u8 gText_TextSpeedMid[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Medio");
static const u8 gText_TextSpeedFast[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Rápido");
static const u8 gText_TextSpeedInstant[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Instantáneo");
static const u8 gText_BattleSceneOn[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Sí");
static const u8 gText_BattleSceneOff[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}No");
static const u8 gText_BattleStyleShift[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Cambiar");
static const u8 gText_BattleStyleSet[]     = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Mantener");
static const u8 gText_SoundMono[]          = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Mono");
static const u8 gText_SoundStereo[]        = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Estéreo");
static const u8 gText_ButtonTypeNormal[]   = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal");
static const u8 gText_ButtonTypeLR[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}LR");
static const u8 gText_ButtonTypeLEqualsA[] = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}L=A");
static const u8 gText_WalkSpeedNormal[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Normal");
static const u8 gText_WalkSpeedFast[]      = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Rápido");
static const u8 gText_WalkSpeedFaster[]    = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Muy rápido");
static const u8 gText_WalkSpeedMax[]       = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Máximo");
static const u8 gText_SpeedupOff[]         = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}Apagado");
static const u8 gText_SpeedupX[]           = _("{COLOR GREEN}{SHADOW LIGHT_GREEN}x");

static const u16 sOptionMenuText_Pal[] = INCBIN_U16("graphics/interface/option_menu_text.gbapal");
// note: this is only used in the Japanese release
static const u8 sEqualSignGfx[] = INCBIN_U8("graphics/interface/option_menu_equals_sign.4bpp");

static const u8 *const sOptionMenuItemsNames[MENUITEM_COUNT] =
{
    [MENUITEM_TEXTSPEED]   = COMPOUND_STRING("Veloc. texto"),
    [MENUITEM_BATTLESCENE] = COMPOUND_STRING("Anim. combate"),
    [MENUITEM_BATTLESTYLE] = COMPOUND_STRING("Tipo combate"),
    [MENUITEM_SOUND]       = COMPOUND_STRING("Sonido"),
    [MENUITEM_BUTTONMODE]  = COMPOUND_STRING("Controles"),
    [MENUITEM_WALKSPEED]   = COMPOUND_STRING("Vel. caminar"),
    [MENUITEM_SPEEDUP]     = COMPOUND_STRING("Turbo batalla"),
    [MENUITEM_CANCEL]      = COMPOUND_STRING("Salir"),
};

static const struct WindowTemplate sOptionMenuWinTemplates[] =
{
    [WIN_HEADER] = {
        .bg = 1,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 2,
        .paletteNum = 1,
        .baseBlock = 2
    },
    [WIN_OPTIONS] = {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 5,
        .width = 26,
        .height = 14,
        .paletteNum = 1,
        .baseBlock = 0x36
    },
    DUMMY_WIN_TEMPLATE
};

static const struct BgTemplate sOptionMenuBgTemplates[] =
{
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 0,
        .charBaseIndex = 1,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }
};

static const u16 sOptionMenuBg_Pal[] = {RGB(17, 18, 31)};

static void MainCB2(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_InitOptionMenu(void)
{
    switch (gMain.state)
    {
    default:
    case 0:
        SetVBlankCallback(NULL);
        gMain.state++;
        break;
    case 1:
        DmaClearLarge16(3, (void *)(VRAM), VRAM_SIZE, 0x1000);
        DmaClear32(3, OAM, OAM_SIZE);
        DmaClear16(3, PLTT, PLTT_SIZE);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sOptionMenuBgTemplates, ARRAY_COUNT(sOptionMenuBgTemplates));
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        ChangeBgX(2, 0, BG_COORD_SET);
        ChangeBgY(2, 0, BG_COORD_SET);
        ChangeBgX(3, 0, BG_COORD_SET);
        ChangeBgY(3, 0, BG_COORD_SET);
        InitWindows(sOptionMenuWinTemplates);
        DeactivateAllTextPrinters();
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WIN01_BG1 | WINOUT_WIN01_CLR);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_DARKEN);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 4);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        ShowBg(0);
        ShowBg(1);
        gMain.state++;
        break;
    case 2:
        ResetPaletteFade();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        gMain.state++;
        break;
    case 3:
        LoadBgTiles(1, GetWindowFrameTilesPal(0)->tiles, 0x120, 0x1A2);
        gMain.state++;
        break;
    case 4:
        LoadPalette(sOptionMenuBg_Pal, BG_PLTT_ID(0), sizeof(sOptionMenuBg_Pal));
        LoadPalette(GetWindowFrameTilesPal(0)->pal, BG_PLTT_ID(7), PLTT_SIZE_4BPP);
        gMain.state++;
        break;
    case 5:
        LoadPalette(sOptionMenuText_Pal, BG_PLTT_ID(1), sizeof(sOptionMenuText_Pal));
        gMain.state++;
        break;
    case 6:
        PutWindowTilemap(WIN_HEADER);
        DrawHeaderText();
        gMain.state++;
        break;
    case 7:
        sMenuCursor = 0;
        sScrollOffset = 0;
        gMain.state++;
        break;
    case 8:
        PutWindowTilemap(WIN_OPTIONS);
        DrawOptionMenuTexts();
        gMain.state++;
    case 9:
        DrawBgWindowFrames();
        gMain.state++;
        break;
    case 10:
    {
        u8 taskId = CreateTask(Task_OptionMenuFadeIn, 0);
        u8 i;

        sMenuCursor = 0;
        sScrollOffset = 0;
        sScrollArrowsTaskId = TASK_NONE;

        gTasks[taskId].tTextSpeed = gSaveBlock2Ptr->optionsTextSpeed;
        gTasks[taskId].tBattleSceneOff = gSaveBlock2Ptr->optionsBattleSceneOff;
        gTasks[taskId].tBattleStyle = gSaveBlock2Ptr->optionsBattleStyle;
        gTasks[taskId].tSound = gSaveBlock2Ptr->optionsSound;
        gTasks[taskId].tButtonMode = gSaveBlock2Ptr->optionsButtonMode;
        gTasks[taskId].tWalkSpeed = gSaveBlock2Ptr->optionsWalkSpeed;
        gTasks[taskId].tSpeedup = gSaveBlock2Ptr->optionsSpeedup;

        for (i = 0; i < OPTIONS_ON_SCREEN && i < MENUITEM_COUNT; i++)
            DrawItemChoices(taskId, i, i * Y_DIFF);

        HighlightOptionMenuItem();

        if (MENUITEM_COUNT > OPTIONS_ON_SCREEN)
            sScrollArrowsTaskId = AddScrollIndicatorArrowPairParameterized(SCROLL_ARROW_UP, DISPLAY_WIDTH / 2, 28, 148, MENUITEM_COUNT - OPTIONS_ON_SCREEN, TAG_NONE, TAG_NONE, &sScrollOffset);

        CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        gMain.state++;
        break;
    }
    case 11:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetVBlankCallback(VBlankCB);
        SetMainCallback2(MainCB2);
        return;
    }
}

static void Task_OptionMenuFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_OptionMenuProcessInput;
}

static void Task_OptionMenuProcessInput(u8 taskId)
{
    if (JOY_NEW(A_BUTTON))
    {
        if (sMenuCursor == MENUITEM_CANCEL)
            gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(B_BUTTON))
    {
        gTasks[taskId].func = Task_OptionMenuSave;
    }
    else if (JOY_NEW(DPAD_UP))
    {
        if (sMenuCursor > 0)
        {
            sMenuCursor--;
            if (sMenuCursor < sScrollOffset)
            {
                sScrollOffset = sMenuCursor;
                ScrollMenu(1);
            }
        }
        else
        {
            sMenuCursor = MENUITEM_CANCEL;
            if (MENUITEM_COUNT > OPTIONS_ON_SCREEN)
            {
                sScrollOffset = MENUITEM_COUNT - OPTIONS_ON_SCREEN;
                DrawOptionMenuTexts();
                {
                    u8 i;
                    for (i = 0; i < OPTIONS_ON_SCREEN; i++)
                        DrawItemChoices(taskId, sScrollOffset + i, i * Y_DIFF);
                }
                CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
            }
        }
        HighlightOptionMenuItem();
    }
    else if (JOY_NEW(DPAD_DOWN))
    {
        if (sMenuCursor < MENUITEM_CANCEL)
        {
            sMenuCursor++;
            if (sMenuCursor >= sScrollOffset + OPTIONS_ON_SCREEN)
            {
                sScrollOffset = sMenuCursor - OPTIONS_ON_SCREEN + 1;
                ScrollMenu(0);
            }
        }
        else
        {
            sMenuCursor = 0;
            sScrollOffset = 0;
            DrawOptionMenuTexts();
            {
                u8 i;
                for (i = 0; i < OPTIONS_ON_SCREEN && i < MENUITEM_COUNT; i++)
                    DrawItemChoices(taskId, i, i * Y_DIFF);
            }
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
        }
        HighlightOptionMenuItem();
    }
    else
    {
        u8 previousOption;
        u8 y = (sMenuCursor - sScrollOffset) * Y_DIFF;

        switch (sMenuCursor)
        {
        case MENUITEM_TEXTSPEED:
            previousOption = gTasks[taskId].tTextSpeed;
            gTasks[taskId].tTextSpeed = TextSpeed_ProcessInput(gTasks[taskId].tTextSpeed);
            if (previousOption != gTasks[taskId].tTextSpeed)
                TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed, y);
            break;
        case MENUITEM_BATTLESCENE:
            previousOption = gTasks[taskId].tBattleSceneOff;
            gTasks[taskId].tBattleSceneOff = BattleScene_ProcessInput(gTasks[taskId].tBattleSceneOff);
            if (previousOption != gTasks[taskId].tBattleSceneOff)
                BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff, y);
            break;
        case MENUITEM_BATTLESTYLE:
            previousOption = gTasks[taskId].tBattleStyle;
            gTasks[taskId].tBattleStyle = BattleStyle_ProcessInput(gTasks[taskId].tBattleStyle);
            if (previousOption != gTasks[taskId].tBattleStyle)
                BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle, y);
            break;
        case MENUITEM_SOUND:
            previousOption = gTasks[taskId].tSound;
            gTasks[taskId].tSound = Sound_ProcessInput(gTasks[taskId].tSound);
            if (previousOption != gTasks[taskId].tSound)
                Sound_DrawChoices(gTasks[taskId].tSound, y);
            break;
        case MENUITEM_BUTTONMODE:
            previousOption = gTasks[taskId].tButtonMode;
            gTasks[taskId].tButtonMode = ButtonMode_ProcessInput(gTasks[taskId].tButtonMode);
            if (previousOption != gTasks[taskId].tButtonMode)
                ButtonMode_DrawChoices(gTasks[taskId].tButtonMode, y);
            break;
        case MENUITEM_WALKSPEED:
            previousOption = gTasks[taskId].tWalkSpeed;
            gTasks[taskId].tWalkSpeed = WalkSpeed_ProcessInput(gTasks[taskId].tWalkSpeed);
            if (previousOption != gTasks[taskId].tWalkSpeed)
                WalkSpeed_DrawChoices(gTasks[taskId].tWalkSpeed, y);
            break;
        case MENUITEM_SPEEDUP:
            previousOption = gTasks[taskId].tSpeedup;
            gTasks[taskId].tSpeedup = Speedup_ProcessInput(gTasks[taskId].tSpeedup);
            if (previousOption != gTasks[taskId].tSpeedup)
                Speedup_DrawChoices(gTasks[taskId].tSpeedup, y);
            break;
        default:
            return;
        }

        if (sArrowPressed)
        {
            sArrowPressed = FALSE;
            CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
        }
    }
}

static void Task_OptionMenuSave(u8 taskId)
{
    gSaveBlock2Ptr->optionsTextSpeed = gTasks[taskId].tTextSpeed;
    gSaveBlock2Ptr->optionsBattleSceneOff = gTasks[taskId].tBattleSceneOff;
    gSaveBlock2Ptr->optionsBattleStyle = gTasks[taskId].tBattleStyle;
    gSaveBlock2Ptr->optionsSound = gTasks[taskId].tSound;
    gSaveBlock2Ptr->optionsButtonMode = gTasks[taskId].tButtonMode;
    gSaveBlock2Ptr->optionsWalkSpeed = gTasks[taskId].tWalkSpeed;
    gSaveBlock2Ptr->optionsSpeedup = gTasks[taskId].tSpeedup;

    if (sScrollArrowsTaskId != TASK_NONE)
    {
        RemoveScrollIndicatorArrowPair(sScrollArrowsTaskId);
        sScrollArrowsTaskId = TASK_NONE;
    }

    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    gTasks[taskId].func = Task_OptionMenuFadeOut;
}

static void Task_OptionMenuFadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        DestroyTask(taskId);
        FreeAllWindowBuffers();
        SetMainCallback2(gMain.savedCallback);
    }
}

static void HighlightOptionMenuItem(void)
{
    u8 visibleCursor = sMenuCursor - sScrollOffset;
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(16, DISPLAY_WIDTH - 16));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(visibleCursor * Y_DIFF + 40, visibleCursor * Y_DIFF + 56));
}

static void DrawOptionMenuChoice(const u8 *text, u8 x, u8 y, u8 style)
{
    u8 dst[32];
    u16 i;

    for (i = 0; *text != EOS && i < ARRAY_COUNT(dst) - 1; i++)
        dst[i] = *(text++);

    if (style != 0)
    {
        dst[2] = TEXT_COLOR_RED;
        dst[5] = TEXT_COLOR_LIGHT_RED;
    }

    dst[i] = EOS;
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, dst, x, y + 1, TEXT_SKIP_DRAW, NULL);
}

static u8 TextSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < OPTIONS_TEXT_SPEED_INSTANT)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = OPTIONS_TEXT_SPEED_INSTANT;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void TextSpeed_DrawChoices(u8 selection, u8 y)
{
    static const u8 *const sTextSpeedStrings[] = {
        gText_TextSpeedSlow,
        gText_TextSpeedMid,
        gText_TextSpeedFast,
        gText_TextSpeedInstant,
    };

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 88, y, 110, Y_DIFF);
    DrawOptionMenuChoice(sTextSpeedStrings[selection], 88, y, 1);
}

static u8 BattleScene_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleScene_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleSceneOn, 88, y, styles[0]);
    DrawOptionMenuChoice(gText_BattleSceneOff, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleSceneOff, 198), y, styles[1]);
}

static u8 BattleStyle_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        sArrowPressed = TRUE;
    }

    return selection;
}

static void BattleStyle_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_BattleStyleShift, 88, y, styles[0]);
    DrawOptionMenuChoice(gText_BattleStyleSet, GetStringRightAlignXOffset(FONT_NORMAL, gText_BattleStyleSet, 198), y, styles[1]);
}

static u8 Sound_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_LEFT | DPAD_RIGHT))
    {
        selection ^= 1;
        SetPokemonCryStereo(selection);
        sArrowPressed = TRUE;
    }

    return selection;
}

static void Sound_DrawChoices(u8 selection, u8 y)
{
    u8 styles[2];

    styles[0] = 0;
    styles[1] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_SoundMono, 88, y, styles[0]);
    DrawOptionMenuChoice(gText_SoundStereo, GetStringRightAlignXOffset(FONT_NORMAL, gText_SoundStereo, 198), y, styles[1]);
}

static u8 ButtonMode_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection <= 1)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection != 0)
            selection--;
        else
            selection = 2;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void ButtonMode_DrawChoices(u8 selection, u8 y)
{
    s32 widthNormal, widthLR, widthLA, xLR;
    u8 styles[3];

    styles[0] = 0;
    styles[1] = 0;
    styles[2] = 0;
    styles[selection] = 1;

    DrawOptionMenuChoice(gText_ButtonTypeNormal, 88, y, styles[0]);

    widthNormal = GetStringWidth(FONT_NORMAL, gText_ButtonTypeNormal, 0);
    widthLR = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLR, 0);
    widthLA = GetStringWidth(FONT_NORMAL, gText_ButtonTypeLEqualsA, 0);

    widthLR -= 110;
    xLR = (widthNormal - widthLR - widthLA) / 2 + 88;
    DrawOptionMenuChoice(gText_ButtonTypeLR, xLR, y, styles[1]);

    DrawOptionMenuChoice(gText_ButtonTypeLEqualsA, GetStringRightAlignXOffset(FONT_NORMAL, gText_ButtonTypeLEqualsA, 198), y, styles[2]);
}

static u8 WalkSpeed_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < OPTIONS_WALK_SPEED_MAX)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection > 0)
            selection--;
        else
            selection = OPTIONS_WALK_SPEED_MAX;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void WalkSpeed_DrawChoices(u8 selection, u8 y)
{
    static const u8 *const sWalkSpeedStrings[] = {
        gText_WalkSpeedNormal,
        gText_WalkSpeedFast,
        gText_WalkSpeedFaster,
        gText_WalkSpeedMax,
    };

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 88, y, 110, Y_DIFF);
    DrawOptionMenuChoice(sWalkSpeedStrings[selection], 88, y, 1);
}

static u8 Speedup_ProcessInput(u8 selection)
{
    if (JOY_NEW(DPAD_RIGHT))
    {
        if (selection < MAX_SPEEDUP)
            selection++;
        else
            selection = 0;

        sArrowPressed = TRUE;
    }
    if (JOY_NEW(DPAD_LEFT))
    {
        if (selection > 0)
            selection--;
        else
            selection = MAX_SPEEDUP;

        sArrowPressed = TRUE;
    }
    return selection;
}

static void Speedup_DrawChoices(u8 selection, u8 y)
{
    u8 text[16] = {EOS};
    u16 i;

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 88, y, 110, Y_DIFF);

    if (selection == 0)
    {
        DrawOptionMenuChoice(gText_SpeedupOff, 88, y, 1);
    }
    else
    {
        u8 displayNum = selection;  // 1->x1, 2->x2, ..., 10->x10
        for (i = 0; i < 6; i++)
            text[i] = gText_SpeedupX[i];
        text[i++] = CHAR_x;
        text[i++] = CHAR_SPACER;
        if (displayNum >= 10)
        {
            text[i++] = (displayNum / 10) + CHAR_0;
            text[i++] = (displayNum % 10) + CHAR_0;
        }
        else
        {
            text[i++] = displayNum + CHAR_0;
        }
        text[i] = EOS;
        DrawOptionMenuChoice(text, 88, y, 1);
    }
}

static void DrawItemLabel(u8 menuItem, u8 y)
{
    AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuItemsNames[menuItem], 8, y + 1, TEXT_SKIP_DRAW, NULL);
}

static void DrawItemChoices(u8 taskId, u8 menuItem, u8 y)
{
    switch (menuItem)
    {
    case MENUITEM_TEXTSPEED:
        TextSpeed_DrawChoices(gTasks[taskId].tTextSpeed, y);
        break;
    case MENUITEM_BATTLESCENE:
        BattleScene_DrawChoices(gTasks[taskId].tBattleSceneOff, y);
        break;
    case MENUITEM_BATTLESTYLE:
        BattleStyle_DrawChoices(gTasks[taskId].tBattleStyle, y);
        break;
    case MENUITEM_SOUND:
        Sound_DrawChoices(gTasks[taskId].tSound, y);
        break;
    case MENUITEM_BUTTONMODE:
        ButtonMode_DrawChoices(gTasks[taskId].tButtonMode, y);
        break;
    case MENUITEM_WALKSPEED:
        WalkSpeed_DrawChoices(gTasks[taskId].tWalkSpeed, y);
        break;
    case MENUITEM_SPEEDUP:
        Speedup_DrawChoices(gTasks[taskId].tSpeedup, y);
        break;
    }
}

static void ScrollMenu(u8 direction)
{
    u8 menuItem, pos;
    u8 taskId = FindTaskIdByFunc(Task_OptionMenuProcessInput);

    if (taskId == TASK_NONE)
        taskId = FindTaskIdByFunc(Task_OptionMenuFadeIn);

    if (direction == 0)
    {
        menuItem = sScrollOffset + OPTIONS_ON_SCREEN - 1;
        pos = OPTIONS_ON_SCREEN - 1;
        ScrollWindow(WIN_OPTIONS, 0, Y_DIFF, PIXEL_FILL(1));
    }
    else
    {
        menuItem = sScrollOffset;
        pos = 0;
        ScrollWindow(WIN_OPTIONS, 1, Y_DIFF, PIXEL_FILL(1));
    }

    FillWindowPixelRect(WIN_OPTIONS, PIXEL_FILL(1), 0, pos * Y_DIFF, 26 * 8, Y_DIFF);
    DrawItemLabel(menuItem, pos * Y_DIFF);
    if (taskId != TASK_NONE)
        DrawItemChoices(taskId, menuItem, pos * Y_DIFF);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_GFX);
}

static void DrawHeaderText(void)
{
    FillWindowPixelBuffer(WIN_HEADER, PIXEL_FILL(1));
    AddTextPrinterParameterized(WIN_HEADER, FONT_NORMAL, gText_Option, 8, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_HEADER, COPYWIN_FULL);
}

static void DrawOptionMenuTexts(void)
{
    u8 i;

    FillWindowPixelBuffer(WIN_OPTIONS, PIXEL_FILL(1));
    for (i = 0; i < OPTIONS_ON_SCREEN && (sScrollOffset + i) < MENUITEM_COUNT; i++)
        AddTextPrinterParameterized(WIN_OPTIONS, FONT_NORMAL, sOptionMenuItemsNames[sScrollOffset + i], 8, (i * Y_DIFF) + 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(WIN_OPTIONS, COPYWIN_FULL);
}

#define TILE_TOP_CORNER_L 0x1A2
#define TILE_TOP_EDGE     0x1A3
#define TILE_TOP_CORNER_R 0x1A4
#define TILE_LEFT_EDGE    0x1A5
#define TILE_RIGHT_EDGE   0x1A7
#define TILE_BOT_CORNER_L 0x1A8
#define TILE_BOT_EDGE     0x1A9
#define TILE_BOT_CORNER_R 0x1AA

static void DrawBgWindowFrames(void)
{
    //                     bg, tile,              x, y, width, height, palNum
    // Draw title window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  0, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  0,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  1,  1,  2,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1,  3,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2,  3, 27,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28,  3,  1,  1,  7);

    // Draw options list window frame
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_L,  1,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_EDGE,      2,  4, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_TOP_CORNER_R, 28,  4,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_LEFT_EDGE,     1,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_RIGHT_EDGE,   28,  5,  1, 18,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_L,  1, 19,  1,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_EDGE,      2, 19, 26,  1,  7);
    FillBgTilemapBufferRect(1, TILE_BOT_CORNER_R, 28, 19,  1,  1,  7);

    CopyBgTilemapBufferToVram(1);
}
