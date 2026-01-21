#include "global.h"
#include "bg.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "menu_helpers.h"
#include "main_menu.h"
#include "trainer_pokemon_sprites.h"
#include "constants/species.h"
#include "pokemon.h"

static void TaskInitCopeSpeechWaitForFade(u8 taskId);
static void TaskInitCopeSpeech(u8 taskId);
static void TaskTimer(u8 taskId);
static void TaskCopeSpeech_AnimationBall(u8 taskId);
static void TaskCopeSpeech_ShowMon(u8 taskId);
static void TaskCopeSpeech_WaitMonFinishAnim(u8 taskId);
static void TaskCopeSpeech_CopeDialogue1(u8 taskId);
static void TaskCopeSpeech_WaitPressA(u8 taskId);
static void TaskCopeSpeech_CopeDialogue2(u8 taskId);
static void TaskCopeSpeech_DoFaceBeforeEndEndSpeech(u8 taskId);
static void TaskCopeSpeech_OpenDoor(u8 taskId);
static void TaskCopeSpeech_NewGameCleanup(u8 taskId);
static void TaskCopeSpeech_FadeOut(u8 taskId);


//BG
static const u32 sBg1_Tiles[] = INCBIN_U32("graphics/cope_speech/bgs/bg1_tileset.4bpp.lz");
static const u32 sBg1_Map[] = INCBIN_U32("graphics/cope_speech/bgs/bg1_tilemap.bin.lz");

static const u32 sBg2_Tiles[] = INCBIN_U32("graphics/cope_speech/bgs/bg2_tileset.4bpp.lz");
static const u32 sBg2_Map[] = INCBIN_U32("graphics/cope_speech/bgs/bg2_tilemap.bin.lz");

static const u16 sBg1Pal[] = INCBIN_U16("graphics/cope_speech/bgs/bg1.gbapal");

#define TAG_COPE_SPRITE 100
#define CINTA_COPE_TAG  101

#define MAX_SLICE_BG_2 33
//------------------------------------------------------------------------------
//BGS
//------------------------------------------------------------------------------

static const struct BgTemplate sBgTemplateCopeSpeech[3] =
    {
        {
            .bg = 0,
            .charBaseIndex = 0, // incrementos de 0x4000
            .mapBaseIndex = 6,  // incrementos 0x800
            .screenSize = 0,
            .paletteMode = 0,
            .priority = 0,
            .baseTile = 0,
        },

        {
            .bg = 1,
            .charBaseIndex = 1, // incrementos de 0x4000
            .mapBaseIndex = 30, // incrementos 0x800
            .screenSize = 0,
            .paletteMode = 0,
            .priority = 1,
            .baseTile = 0,
        },
        {
            .bg = 2,
            .charBaseIndex = 2,
            .mapBaseIndex = 26,
            .screenSize = 2,
            .paletteMode = 0,
            .priority = 2,
            .baseTile = 0,
        },

        // {
        //     .bg = 3,
        //     .charBaseIndex = 3, //2,
        //     .mapBaseIndex = 30, //fijo
        //     .screenSize = 2,
        //     .paletteMode = 0,
        //     .priority = 2,
        //     .baseTile = 0,
        // },
};



static void LoadCopeSpeechBgs()
{
    InitBgsFromTemplates(0, sBgTemplateCopeSpeech, ARRAY_COUNT(sBgTemplateCopeSpeech));

    LZ77UnCompVram(sBg1_Tiles, (void *)VRAM + 0x4000 * sBgTemplateCopeSpeech[1].charBaseIndex);
    LZ77UnCompVram(sBg1_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[1].mapBaseIndex));

    LZ77UnCompVram(sBg2_Tiles, (void *)VRAM + 0x4000 * sBgTemplateCopeSpeech[2].charBaseIndex);
    LZ77UnCompVram(sBg2_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));

    LoadPalette(sBg1Pal, 0x00, 0x20);

    ResetAllBgsCoordinates();

    HideBg(3);
    ShowBg(2);
    ShowBg(1);
    ShowBg(0);
}


//------------------------------------------------------------------------------
//WINDOWS
//------------------------------------------------------------------------------

enum{
    WINDOW_MSG_BOX
};

static const struct WindowTemplate sWindowTemplate_CopeSpeech[] =
{
    [WINDOW_MSG_BOX]{
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 1
    },

    DUMMY_WIN_TEMPLATE,
};

//------------------------------------------------------------------------------
//SPRITES
//------------------------------------------------------------------------------

static const struct OamData gSpriteOamData64 =
{
    .y = 0,
    .affineMode = 0,
    .objMode = 0,
    .mosaic = 0,
    .bpp = 0,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData gSpriteOamData16x32 =
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

//Cope SPRITE
static const u16 CopePal[] = INCBIN_U16("graphics/cope_speech/cope.gbapal");
static const u8 CopeSprite[] = INCBIN_U8("graphics/cope_speech/copeSprite.4bpp");
static const u8 CintaCopeSprite[] = INCBIN_U8("graphics/cope_speech/cintaSprite.4bpp");


static const struct SpriteSheet spriteSheetCope =
{
            .data = CopeSprite, //GRÁFICO ----------
            .size = 8192, //TAMAÑO DEL GRÁFICO
            .tag = TAG_COPE_SPRITE, //LUGAR DONDE SE CARGA EL GRÁFICO ----------
};

static const struct SpritePalette spritePaletteCope =
{
        .data = CopePal,
        .tag = TAG_COPE_SPRITE, //LUGAR DONDE SE CARGA LA PALETA ----------
};

enum{
    COPE_BASE,
    COPE_SHOW_BALL,
    Cope_THROW_BALL,
    COPE_LEGS
};

static const union AnimCmd sAnim_CopeBase[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CopeShowBall[] =
{
    ANIMCMD_FRAME(64, 10),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CopeThrowBall[] =
{
    ANIMCMD_FRAME(64, 10),
    ANIMCMD_FRAME(128, 24),
    ANIMCMD_END,
};

static const union AnimCmd sAnim_CopeLegs[] =
{
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnims_CopeSprite[] =
{
    [COPE_BASE] = sAnim_CopeBase,
    [COPE_SHOW_BALL] = sAnim_CopeShowBall,
    [Cope_THROW_BALL] = sAnim_CopeThrowBall,
    [COPE_LEGS] = sAnim_CopeLegs
};

#define sMoveUp data[1]
#define sTimer data[7]

void SpriteCallbackCopeMovement(struct Sprite *sprite)
{
    if(++ sprite->sTimer == 15)
    {
         if(sprite->sMoveUp == TRUE){
            sprite->y--;
            sprite->sMoveUp = FALSE;
        }else{
            sprite->y++;
            sprite->sMoveUp = TRUE;
        }
        sprite->sTimer = 0;
    }
}
#undef sMoveUp
#undef sTimer


static const struct SpriteTemplate spriteTemplateCope =
{
    .tileTag = TAG_COPE_SPRITE, //LUGAR DONDE SE CARGA EL GRÁFICO ----------
    .paletteTag = TAG_COPE_SPRITE, //LUGAR DONDE SE CARGA LA PALETA ----------
    .oam = &gSpriteOamData64, //OAM DATA DEL ICONO ----------
    .anims = sAnims_CopeSprite, //TABLA DE ANIMACIÓN DEL ICONO ----------
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy, //ANIMACIÓN DEL ICONO ----------
};


static const struct SpriteSheet sSpriteSheet_CintaCope =
{
    .data = CintaCopeSprite, 
    .size = 1024, 
    .tag = CINTA_COPE_TAG,
};

static const union AnimCmd sAnimCintaCope[] =
{
    ANIMCMD_FRAME(0,   20),
    ANIMCMD_FRAME(16,   20),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnimsCintaCope[] =
{
    sAnimCintaCope,
};

static const struct SpriteTemplate sCintaCopeSpriteTemplate =
{
    .tileTag = CINTA_COPE_TAG,
    .paletteTag = TAG_COPE_SPRITE,
    .oam = &gSpriteOamData16x32,
    .anims = sAnimsCintaCope,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackCopeMovement,
};


void LoadSpriteGraphicsAndPal()
{
    LoadSpriteSheet(&spriteSheetCope);
    LoadSpriteSheet(&sSpriteSheet_CintaCope);
    LoadSpritePalette(&spritePaletteCope);
}

u8 LoadCopeSprite(u8 y, s8 animNum){
    u8 id;
    id = CreateSprite(&spriteTemplateCope, 115,y, 0);
    StartSpriteAnim(&gSprites[id], animNum);

    return id;
}

//------------------------------------------------------------------------------
//OTROS
//------------------------------------------------------------------------------



static void VBlanck_CB2_CopeSpeech()
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_CopeSpeech()
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

#define tSpriteCopeBodyId data[1]
#define tSpriteCopeLegsId data[2]
#define tSpriteCopeCintaId data[3]
#define tMonSpriteId data[6]
#define tTimer data[7]


void CB2_InitCopeSpeech()
{
    u8 taskId;

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
        break;

    case 1:
        LoadCopeSpeechBgs();
        LoadSpriteGraphicsAndPal();
        gMain.state++;
        break;

    case 2:
        SetVBlankCallback(VBlanck_CB2_CopeSpeech);
        SetMainCallback2(CB2_CopeSpeech);
        PlayBGM(MUS_ROUTE101);

        BeginNormalPaletteFade(PALETTES_ALL, 60, 16, 0, RGB_BLACK);
        taskId = CreateTask(TaskInitCopeSpeechWaitForFade, 0);
        gTasks[taskId].tSpriteCopeBodyId = LoadCopeSprite(40,COPE_BASE);
        gTasks[taskId].tSpriteCopeLegsId = LoadCopeSprite(104,COPE_LEGS);
        gTasks[taskId].tSpriteCopeCintaId =  CreateSprite(&sCintaCopeSpriteTemplate, 130, 22, 0);
        gSprites[gTasks[taskId].tSpriteCopeBodyId].oam.priority=1;
        gSprites[gTasks[taskId].tSpriteCopeCintaId].oam.priority=1;
        gSprites[gTasks[taskId].tSpriteCopeBodyId].callback = SpriteCallbackCopeMovement;
        gSprites[gTasks[taskId].tSpriteCopeLegsId].oam.priority=1;
        break;
    }
}

void CB2_InitCopeSpeech_FromNewMainMenu(void)
{
    u8 taskId;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sBgTemplateCopeSpeech, ARRAY_COUNT(sBgTemplateCopeSpeech));
    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
    
    LZ77UnCompVram(sBg1_Tiles, (void *)VRAM + 0x4000 * sBgTemplateCopeSpeech[1].charBaseIndex);
    LZ77UnCompVram(sBg1_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[1].mapBaseIndex));
    LZ77UnCompVram(sBg2_Tiles, (void *)VRAM + 0x4000 * sBgTemplateCopeSpeech[2].charBaseIndex);
    LZ77UnCompVram(sBg2_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
    LoadPalette(sBg1Pal, 0x00, 0x20);
    
    ResetAllBgsCoordinates();
    HideBg(3);
    ShowBg(2);
    ShowBg(1);
    ShowBg(0);
    
    ResetTasks();
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();

    LoadSpriteSheet(&spriteSheetCope);
    LoadSpriteSheet(&sSpriteSheet_CintaCope);
    LoadSpritePalette(&spritePaletteCope);
    
    taskId = CreateTask(TaskInitCopeSpeechWaitForFade, 0);
    gTasks[taskId].tSpriteCopeBodyId = LoadCopeSprite(40, COPE_BASE);
    gTasks[taskId].tSpriteCopeLegsId = LoadCopeSprite(104, COPE_LEGS);
    gTasks[taskId].tSpriteCopeCintaId = CreateSprite(&sCintaCopeSpriteTemplate, 130, 22, 0);
    gSprites[gTasks[taskId].tSpriteCopeBodyId].oam.priority = 1;
    gSprites[gTasks[taskId].tSpriteCopeCintaId].oam.priority = 1;
    gSprites[gTasks[taskId].tSpriteCopeBodyId].callback = SpriteCallbackCopeMovement;
    gSprites[gTasks[taskId].tSpriteCopeLegsId].oam.priority = 1;
    gTasks[taskId].tTimer = 0;
    
    PlayBGM(MUS_ROUTE101);
    BeginNormalPaletteFade(PALETTES_ALL, 60, 16, 0, RGB_BLACK);
    
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    
    SetVBlankCallback(VBlanck_CB2_CopeSpeech);
    SetMainCallback2(CB2_CopeSpeech);
    InitWindows(sWindowTemplate_CopeSpeech);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, 0xFC, BG_PLTT_ID(15));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void TaskInitCopeSpeechWaitForFade(u8 taskId)
{
    if(!gPaletteFade.active)
    {
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].func= TaskTimer;
    }
}

static void TaskTimer(u8 taskId)
{
    if(++gTasks[taskId].tTimer > 60)
    {
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].func = TaskInitCopeSpeech;
    }
}

static void TaskInitCopeSpeech(u8 taskId)
{
    InitWindows(sWindowTemplate_CopeSpeech);
    LoadMainMenuWindowFrameTiles(0, 0xF3);
    LoadMessageBoxGfx(0, 0xFC, BG_PLTT_ID(15));
    NewGameBirchSpeech_ShowDialogueWindow(0, TRUE);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_GFX);
    NewGameBirchSpeech_ClearWindow(0);
    StringExpandPlaceholders(gStringVar4, gText_Cope_Welcome);
    AddTextPrinterForMessage(TRUE);
    gTasks[taskId].func = TaskCopeSpeech_AnimationBall;
}


static void TaskCopeSpeech_AnimationBall(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StartSpriteAnim(&gSprites[gTasks[taskId].tSpriteCopeBodyId], Cope_THROW_BALL);
        PlaySE(SE_BALL_THROW);
        gTasks[taskId].func = TaskCopeSpeech_ShowMon;
    }
}


static void TaskCopeSpeech_ShowMon(u8 taskId)
{
    if(++gTasks[taskId].tTimer > 34 && !IsSEPlaying())
    {
        PlaySE(SE_BALL_OPEN);
        StartSpriteAnim(&gSprites[gTasks[taskId].tSpriteCopeBodyId], COPE_SHOW_BALL);
        gTasks[taskId].tMonSpriteId = CreateMonSpriteFromNationalDexNumber(SPECIES_KECLEON, 87, 85, 5);
        StartSpriteAnim(&gSprites[gTasks[taskId].tSpriteCopeBodyId], COPE_SHOW_BALL);
        PokemonSummaryDoMonAnimation(&gSprites[gTasks[taskId].tMonSpriteId], SPECIES_KECLEON, FALSE);
        gTasks[taskId].func = TaskCopeSpeech_WaitMonFinishAnim;
    }
}

static void TaskCopeSpeech_WaitMonFinishAnim(u8 taskId)
{
    if(gSprites[gTasks[taskId].tMonSpriteId].animEnded)
    {
        StartSpriteAnim(&gSprites[gTasks[taskId].tMonSpriteId], 0);
        gTasks[taskId].func = TaskCopeSpeech_CopeDialogue1;
    }
}

static void TaskCopeSpeech_CopeDialogue1(u8 taskId)
{
    if(!RunTextPrintersAndIsPrinter0Active() && !IsSEPlaying() && JOY_NEW(A_BUTTON))
    {
        StopCryAndClearCrySongs();
        FillWindowPixelBuffer(WINDOW_MSG_BOX, PIXEL_FILL(1));
        StringExpandPlaceholders(gStringVar4, gText_Cope_Pokemon);
        AddTextPrinterForMessage(TRUE);
        PlayCry_ByMode(SPECIES_KECLEON, 0, CRY_MODE_NORMAL);
        gTasks[taskId].func = TaskCopeSpeech_CopeDialogue2;
    }
}



static void TaskCopeSpeech_CopeDialogue2(u8 taskId)
{
    if(IsCryFinished() && !RunTextPrintersAndIsPrinter0Active() && JOY_NEW(A_BUTTON))
    {
        FillWindowPixelBuffer(WINDOW_MSG_BOX, PIXEL_FILL(1));
        StringExpandPlaceholders(gStringVar4, gText_Cope_ExplainChalenge);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = TaskCopeSpeech_WaitPressA;
    }
}

#define tSliceBg2 data[4]
static void TaskCopeSpeech_WaitPressA(u8 taskId)
{
    if(!RunTextPrintersAndIsPrinter0Active() && JOY_NEW(A_BUTTON))
    {
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        // ClearStdWindowAndFrameToTransparent(0, FALSE);
        CopyWindowToVram(0, COPYWIN_GFX);
        RemoveWindow(0);
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tSliceBg2 = 0;
        gTasks[taskId].func = TaskCopeSpeech_OpenDoor;
    }
}


static void TaskCopeSpeech_OpenDoor(u8 taskId)
{
    if(gTasks[taskId].tTimer % 4 == 0)
    {
        gTasks[taskId].tSliceBg2+=1;
        SetGpuReg(REG_OFFSET_BG2HOFS, gTasks[taskId].tSliceBg2);

        if(gTasks[taskId].tSliceBg2 >= MAX_SLICE_BG_2)
            gTasks[taskId].func = TaskCopeSpeech_DoFaceBeforeEndEndSpeech;
    }
}


static void TaskCopeSpeech_DoFaceBeforeEndEndSpeech(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 0x10, RGB_BLACK);
        gTasks[taskId].func = TaskCopeSpeech_NewGameCleanup;
    }
}

static void TaskCopeSpeech_NewGameCleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        DestroySpriteAndFreeResources(&gSprites[gTasks[taskId].tSpriteCopeBodyId]);
        DestroySpriteAndFreeResources(&gSprites[gTasks[taskId].tSpriteCopeLegsId]);
        FreeAndDestroyMonPicSprite(gTasks[taskId].tMonSpriteId);
        gTasks[taskId].func = TaskCopeSpeech_FadeOut;
    }
}

static void Task_OpenCopeSpeechFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        SetMainCallback2(CB2_InitCopeSpeech);
    }
}

static void TaskCopeSpeech_FadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_NewGame);
        DestroyTask(taskId);
        FreeAllWindowBuffers();
    }
}

bool8 StartCopeSpeech_CB2()
{
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        // CleanupOverworldWindowsAndTilemaps();
        BeginNormalPaletteFade(0xFFFFFFFF, 10, 16, 0, RGB_BLACK);
        CreateTask(Task_OpenCopeSpeechFadeIn, 0);
        return TRUE;
    }
    return FALSE;
}



