#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "menu_helpers.h"
#include "naming_screen.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon.h"
#include "random.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "team_selector.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/vars.h"

// ============================================================================
// FORWARD DECLARATIONS
// ============================================================================
static void TaskInitCopeSpeechWaitForFade(u8 taskId);
static void TaskChooseOptions(u8 taskId);
static void TaskCopeSpeech_AnimationBall(u8 taskId);
static void TaskCopeSpeech_ShowMon(u8 taskId);
static void TaskCopeSpeech_WaitMonFinishAnim(u8 taskId);
static void TaskCopeSpeech_CopeDialogue1(u8 taskId);
static void TaskCopeSpeech_WaitPressA(u8 taskId);
static void TaskCopeSpeech_CopeDialogue2(u8 taskId);
static void TaskCopeSpeech_CopeDialogue3(u8 taskId);
static void TaskCopeSpeech_DoFaceBeforeEndEndSpeech(u8 taskId);
static void TaskCopeSpeech_OpenDoor(u8 taskId);
static void TaskCopeSpeech_Cleanup(u8 taskId);
static void TaskCopeSpeech_FadeOut(u8 taskId);
static void SpriteCallbackCopeMovement(struct Sprite *sprite);
static void CB2_ReturnFromNamingScreen(void);

// ============================================================================
// CONSTANTS & CONFIGURATION
// ============================================================================

// Sprite tags
#define TAG_COPE_SPRITE     100
#define CINTA_COPE_TAG      101

// BG configuration
#define MAX_SLICE_BG_3      33
#define COPE_SPRITE_X       115
#define COPE_CINTA_X        130
#define COPE_CINTA_Y        22
#define COPE_BODY_Y         40
#define COPE_LEGS_Y         104

// Animation states for Cope sprite
enum {
    COPE_BASE,
    COPE_SHOW_BALL,
    COPE_THROW_BALL,
    COPE_LEGS
};

// Scene flow states
enum {
    SCENE_CHOOSE_GENDER,
    SCENE_AFTER_NAMING_SCREEN,
    SCENE_CHOOSE_DIFFICULTY,
    SCENE_COPE_SPEECH_END,
};

// Difficulty levels
enum {
    DIFFICULTY_EASY,
    DIFFICULTY_NORMAL,
    DIFFICULTY_HARD,
};

// Window IDs
enum {
    WINDOW_MSG_BOX,
    WINDOW_TITLE_BOX,
    WINDOW_YESNO_BOX,
    WINDOW_EASY_BOX,
    WINDOW_NORMAL_BOX,
    WINDOW_HARD_BOX,
    WINDOW_DIFFICULTY_BOX,
};

// ============================================================================
// TASK DATA ACCESSORS
// ============================================================================
#define tOptionChoose         data[0]   // Current option selection state
#define tDifficulty           data[1]   // Selected difficulty level
#define tScene                data[2]   // Current scene/flow state
#define tSpritePlayerMaleId   data[3]   // Sprite ID for male player portrait
#define tSpritePlayerFemaleId data[4]   // Sprite ID for female player portrait
#define tPlayerGender         data[5]   // Player gender (MALE/FEMALE)
#define tSpriteId             data[6]   // Generic sprite ID holder
#define tSliceBgsState        data[7]   // BG scrolling animation counter
#define tConfirmSelection     data[8]   // Yes/No confirmation state
#define tSpriteCopeBodyId     data[9]   // Cope body sprite ID
#define tSpriteCopeLegsId     data[10]  // Cope legs sprite ID
#define tSpriteCopeCintaId    data[11]  // Cope ribbon sprite ID
#define tMonSpriteId          data[12]  // Pokémon sprite ID (Kecleon)
#define tTimer                data[13]  // Generic timer counter
#define tSliceBg3             data[14]  // BG3 horizontal offset for door anim
#define tState                data[15]  // Sub-state machine for complex tasks

// Sprite-local data (for CintaCope movement)
#define sMoveUp               data[0]   // Direction flag for vertical oscillation
#define sTimer                data[1]   // Frame counter for movement timing

// ============================================================================
// EWRAM VARIABLES
// ============================================================================
static EWRAM_DATA u8 sTaskId;  // Global task ID for functions without taskId parameter

// ============================================================================
// GRAPHICS DATA - GENDER SELECTION
// ============================================================================
static const u16 sGender_Pal[] = INCBIN_U16("graphics/cope_speech/gender/palette.gbapal");
static const u32 sGender_Tiles[] = INCBIN_U32("graphics/cope_speech/gender/tiles.4bpp.lz");
static const u32 sGenderMaleFemale_Map[] = INCBIN_U32("graphics/cope_speech/gender/male-female.bin.lz");
static const u32 sGenderMale_Map[] = INCBIN_U32("graphics/cope_speech/gender/male.bin.lz");
static const u32 sGenderFemale_Map[] = INCBIN_U32("graphics/cope_speech/gender/female.bin.lz");
static const u32 sGenderBg_Map[] = INCBIN_U32("graphics/cope_speech/gender/bg.bin.lz");

// ============================================================================
// GRAPHICS DATA - DIFFICULTY SELECTION
// ============================================================================
static const u16 sDifficulty_Pal[] = INCBIN_U16("graphics/cope_speech/difficulty/palette.gbapal");
static const u32 sDifficulty_Tiles[] = INCBIN_U32("graphics/cope_speech/difficulty/tiles.4bpp.lz");
static const u32 sDifficultyInterface_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/interface.bin.lz");
static const u32 sDifficultyEasy_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/easy.bin.lz");
static const u32 sDifficultyNormal_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/normal.bin.lz");
static const u32 sDifficultyHard_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/hard.bin.lz");
static const u32 sDifficultyBg_Map[] = INCBIN_U32("graphics/cope_speech/difficulty/bg.bin.lz");

// ============================================================================
// GRAPHICS DATA - INTRO/COPE SPEECH
// ============================================================================
static const u16 sIntro_Pal[] = INCBIN_U16("graphics/cope_speech/intro/palette.gbapal");
static const u32 sIntro_Tiles[] = INCBIN_U32("graphics/cope_speech/intro/tiles.4bpp.lz");
static const u32 sIntroBg_Map[] = INCBIN_U32("graphics/cope_speech/intro/bg.bin.lz");
static const u32 sIntroDoor_Map[] = INCBIN_U32("graphics/cope_speech/intro/door.bin.lz");

// ============================================================================
// PALETTES & COLORS
// ============================================================================
static const u16 sMainMenuTextPal[] = INCBIN_U16("graphics/interface/main_menu_text.gbapal");
static const u16 sMayGrey_Pal[] = INCBIN_U16("graphics/trainers/front_pics/may_grey.gbapal");
static const u16 sBrendanGrey_Pal[] = INCBIN_U16("graphics/trainers/front_pics/brendan_grey.gbapal");
static const u8 sTextWhite[3] = {0, 1, 2};
static const u8 sTextBlack[3] = {0, 2, 3};
static const u16 sPalEasy[] = {RGB(8, 21, 8)};
static const u16 sPalNormal[] = {RGB(14, 14, 31)};
static const u16 sPalHard[] = {RGB(31, 14, 14)};
extern const u16 gTrainerPalette_Brendan[];
extern const u16 gTrainerPalette_May[];

// ============================================================================
// BG TEMPLATES
// ============================================================================
static const struct BgTemplate sBgTemplateCopeSpeech[] =
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

// ============================================================================
// WINDOW TEMPLATES
// ============================================================================
static const struct WindowTemplate sWindowTemplate_Gender[] =
{
    [WINDOW_MSG_BOX]{
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 27,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 300
    },
    [WINDOW_TITLE_BOX]{
        .bg = 1,
        .tilemapLeft = 0,
        .tilemapTop = 18,
        .width = 30,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 700
    },
    [WINDOW_YESNO_BOX]{
        .bg = 1,
        .tilemapLeft = 25,
        .tilemapTop = 14,
        .width = 4,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 760
    },
    [WINDOW_EASY_BOX]{
        .bg = 1,
        .tilemapLeft = 1,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 776
    },
    [WINDOW_NORMAL_BOX]{
        .bg = 1,
        .tilemapLeft = 11,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 792
    },
    [WINDOW_HARD_BOX]{
        .bg = 1,
        .tilemapLeft = 21,
        .tilemapTop = 2,
        .width = 8,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 808
    },
    [WINDOW_DIFFICULTY_BOX]{
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

// ============================================================================
// SPRITE DEFINITIONS - OAM DATA
// ============================================================================
static const struct OamData gSpriteOamData64x64 =
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

// ============================================================================
// SPRITE DEFINITIONS - COPE SPRITE
// ============================================================================
static const u16 CopePal[] = INCBIN_U16("graphics/cope_speech/cope.gbapal");
static const u8 CopeSprite[] = INCBIN_U8("graphics/cope_speech/copeSprite.4bpp");
static const u8 CintaCopeSprite[] = INCBIN_U8("graphics/cope_speech/cintaSprite.4bpp");

static const struct SpriteSheet spriteSheetCope =
{
    .data = CopeSprite,
    .size = sizeof(CopeSprite),
    .tag = TAG_COPE_SPRITE,
};

static const struct SpritePalette spritePaletteCope =
{
    .data = CopePal,
    .tag = TAG_COPE_SPRITE,
};

// Cope sprite animations
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
    [COPE_THROW_BALL] = sAnim_CopeThrowBall,
    [COPE_LEGS] = sAnim_CopeLegs
};

static const struct SpriteTemplate spriteTemplateCope =
{
    .tileTag = TAG_COPE_SPRITE,
    .paletteTag = TAG_COPE_SPRITE,
    .oam = &gSpriteOamData64x64,
    .anims = sAnims_CopeSprite,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// ============================================================================
// SPRITE DEFINITIONS - CINTA COPE (RIBBON)
// ============================================================================
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

// ============================================================================
// PRESET NAMES FOR NAMING SCREEN
// ============================================================================
static const u8 *const sMalePresetNames[] = {
    COMPOUND_STRING("Stu"),
    COMPOUND_STRING("Milton"),
    COMPOUND_STRING("Tom"),
    COMPOUND_STRING("Kenny"),
    COMPOUND_STRING("Reid"),
    COMPOUND_STRING("Jude"),
    COMPOUND_STRING("Jaxson"),
    COMPOUND_STRING("Easton"),
    COMPOUND_STRING("Walker"),
    COMPOUND_STRING("Teru"),
    COMPOUND_STRING("Johnny"),
    COMPOUND_STRING("Brett"),
    COMPOUND_STRING("Seth"),
    COMPOUND_STRING("Terry"),
    COMPOUND_STRING("Casey"),
    COMPOUND_STRING("Darren"),
    COMPOUND_STRING("Landon"),
    COMPOUND_STRING("Collin"),
    COMPOUND_STRING("Stanley"),
    COMPOUND_STRING("Quincy")
};

static const u8 *const sFemalePresetNames[] = {
    COMPOUND_STRING("Kimmy"),
    COMPOUND_STRING("Tiara"),
    COMPOUND_STRING("Bella"),
    COMPOUND_STRING("Jayla"),
    COMPOUND_STRING("Allie"),
    COMPOUND_STRING("Lianna"),
    COMPOUND_STRING("Sara"),
    COMPOUND_STRING("Monica"),
    COMPOUND_STRING("Camila"),
    COMPOUND_STRING("Aubree"),
    COMPOUND_STRING("Ruthie"),
    COMPOUND_STRING("Hazel"),
    COMPOUND_STRING("Nadine"),
    COMPOUND_STRING("Tanja"),
    COMPOUND_STRING("Yasmin"),
    COMPOUND_STRING("Nicola"),
    COMPOUND_STRING("Lillie"),
    COMPOUND_STRING("Terra"),
    COMPOUND_STRING("Lucy"),
    COMPOUND_STRING("Halie")
};

#define NUM_PRESET_NAMES min(ARRAY_COUNT(sMalePresetNames), ARRAY_COUNT(sFemalePresetNames))

// ============================================================================
// HELPER FUNCTIONS
// ============================================================================

static void LoadCopeSpritesToVRAM(void)
{
    LoadSpriteSheet(&spriteSheetCope);
    LoadSpriteSheet(&sSpriteSheet_CintaCope);
    LoadSpritePalette(&spritePaletteCope);
}

static u8 CreateCopeSprite(s16 y, u8 animIndex)
{
    u8 spriteId = CreateSprite(&spriteTemplateCope, COPE_SPRITE_X, y, 0);
    StartSpriteAnim(&gSprites[spriteId], animIndex);
    return spriteId;
}

static void SetupCopeSpritePriorities(u8 bodyId, u8 cintaId, u8 legsId)
{
    gSprites[bodyId].oam.priority = 1;
    gSprites[cintaId].oam.priority = 1;
    gSprites[legsId].oam.priority = 1;
    gSprites[bodyId].callback = SpriteCallbackCopeMovement;
}

static void SetupWindowBlendRegisters(void)
{
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 8));
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

// ============================================================================
// BACKGROUND LOADING FUNCTIONS
// ============================================================================

static void LoadGenderBgs(void)
{
    LZ77UnCompVram(sGender_Tiles, (void *)VRAM + BG_CHAR_SIZE * sBgTemplateCopeSpeech[1].charBaseIndex);
    LZ77UnCompVram(sGenderBg_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[3].mapBaseIndex));
    LoadPalette(sGender_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    
    if (gTasks[sTaskId].tScene == SCENE_AFTER_NAMING_SCREEN)
    {
        if (gTasks[sTaskId].tPlayerGender == FEMALE)
            LZ77UnCompVram(sGenderFemale_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
        else
            LZ77UnCompVram(sGenderMale_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
    }
    else // SCENE_CHOOSE_GENDER
    {
        LZ77UnCompVram(sGenderMaleFemale_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
    }
}

static void UpdateGenderSprites(u8 taskId)
{
    if (gTasks[taskId].tPlayerGender == FEMALE)
    {
        LoadPalette(gTrainerPalette_May, OBJ_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(sBrendanGrey_Pal, OBJ_PLTT_ID(2), PLTT_SIZE_4BPP);
    }
    else
    {
        LoadPalette(sMayGrey_Pal, OBJ_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(gTrainerPalette_Brendan, OBJ_PLTT_ID(2), PLTT_SIZE_4BPP);
    }
}

static void LoadGenderSprites(u8 taskId)
{
    if (gTasks[taskId].tScene == SCENE_AFTER_NAMING_SCREEN)
    {
        if (gTasks[taskId].tPlayerGender == FEMALE)
            gTasks[taskId].tSpriteId = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(FEMALE), TRUE, 120, 72, 1, TAG_NONE);
        else
            gTasks[taskId].tSpriteId = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(MALE), TRUE, 120, 72, 2, TAG_NONE);
    }
    else // SCENE_CHOOSE_GENDER
    {
        gTasks[taskId].tSpritePlayerFemaleId = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(FEMALE), TRUE, 48, 72, 1, TAG_NONE);
        gTasks[taskId].tSpritePlayerMaleId = CreateTrainerPicSprite(PlayerGenderToFrontTrainerPicId(MALE), TRUE, 192, 72, 2, TAG_NONE);
        gTasks[taskId].tPlayerGender = FEMALE;
        gTasks[taskId].tSliceBgsState = 8;
    }
}

static u8 LoadCopeSprite(u8 y, s8 animNum)
{
    u8 id = CreateSprite(&spriteTemplateCope, COPE_SPRITE_X, y, 0);
    StartSpriteAnim(&gSprites[id], animNum);
    return id;
}

static void LoadCopeSpeechBgs(void)
{
    LZ77UnCompVram(sIntro_Tiles, (void *)VRAM + BG_CHAR_SIZE * sBgTemplateCopeSpeech[1].charBaseIndex);
    LZ77UnCompVram(sIntroBg_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
    LZ77UnCompVram(sIntroDoor_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[3].mapBaseIndex));
    LoadPalette(sIntro_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
}

// ============================================================================
// SPRITE CALLBACKS & VBLANK
// ============================================================================

static void SpriteCallbackCopeMovement(struct Sprite *sprite)
{
    if (++sprite->sTimer == 15)
    {
        if (sprite->sMoveUp == TRUE) {
            sprite->y--;
            sprite->sMoveUp = FALSE;
        } else {
            sprite->y++;
            sprite->sMoveUp = TRUE;
        }
        sprite->sTimer = 0;
    }
}

static void ScrollBackground(void)
{    
    u8 speed = 1;
    
    ChangeBgX(3, 128, BG_COORD_ADD);
    ChangeBgY(3, 128, BG_COORD_SUB);
    
    if (!gPaletteFade.active && gTasks[sTaskId].tSliceBgsState != 0)
    {
        gTasks[sTaskId].tSliceBgsState--;
        if (gTasks[sTaskId].tPlayerGender == FEMALE)
        {
            ChangeBgX(2, speed << 8, BG_COORD_SUB);
            gSprites[gTasks[sTaskId].tSpritePlayerFemaleId].x += speed;
            gSprites[gTasks[sTaskId].tSpritePlayerMaleId].x += speed;
        }
        else
        {
            ChangeBgX(2, speed << 8, BG_COORD_ADD);
            gSprites[gTasks[sTaskId].tSpritePlayerFemaleId].x -= speed;
            gSprites[gTasks[sTaskId].tSpritePlayerMaleId].x -= speed;
        }
    }
}

static void VBlank_CB2_Gender(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScrollBackground();
}

static void VBlank_CB2_CopeSpeech(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_CopeSpeech(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

// ============================================================================
// INITIALIZATION FUNCTIONS
// ============================================================================

void CB2_InitCopeSpeech(void)
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
        LoadCopeSpritesToVRAM();
        ResetAllBgsCoordinates();
        gMain.state++;
        break;

    case 2:
        SetVBlankCallback(VBlank_CB2_Gender);
        SetMainCallback2(CB2_CopeSpeech);
        PlayBGM(MUS_ROUTE101);

        BeginNormalPaletteFade(PALETTES_ALL, 60, 16, 0, RGB_BLACK);
        taskId = CreateTask(TaskInitCopeSpeechWaitForFade, 0);
        gTasks[taskId].tSpriteCopeBodyId = CreateCopeSprite(COPE_BODY_Y, COPE_BASE);
        gTasks[taskId].tSpriteCopeLegsId = CreateCopeSprite(COPE_LEGS_Y, COPE_LEGS);
        gTasks[taskId].tSpriteCopeCintaId = CreateSprite(&sCintaCopeSpriteTemplate, COPE_CINTA_X, COPE_CINTA_Y, 0);
        SetupCopeSpritePriorities(
            gTasks[taskId].tSpriteCopeBodyId,
            gTasks[taskId].tSpriteCopeCintaId,
            gTasks[taskId].tSpriteCopeLegsId
        );
        break;
    }
}

void CB2_InitCopeSpeech_FromNewMainMenu(void)
{
    u8 x;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sBgTemplateCopeSpeech, ARRAY_COUNT(sBgTemplateCopeSpeech));
    InitWindows(sWindowTemplate_Gender);
    SetVBlankCallback(NULL);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();
        
    ResetAllBgsCoordinates();
    ChangeBgX(2, 8 << 8, BG_COORD_ADD);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    
    ResetTasks();
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    
    sTaskId = CreateTask(TaskInitCopeSpeechWaitForFade, 0);
    gTasks[sTaskId].tTimer = 0;
    gTasks[sTaskId].tScene = SCENE_CHOOSE_GENDER;
    
    LoadGenderBgs();
    LoadGenderSprites(sTaskId);
    UpdateGenderSprites(sTaskId);
    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    
    // PlayBGM(MUS_ROUTE101);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    
    SetupWindowBlendRegisters();
    SetVBlankCallback(VBlank_CB2_Gender);
    SetMainCallback2(CB2_CopeSpeech);
    
    FillWindowPixelBuffer(WINDOW_TITLE_BOX, PIXEL_FILL(10));
    PutWindowTilemap(WINDOW_TITLE_BOX);
    x = (240 - GetStringWidth(FONT_NORMAL, gText_GirlOrBoy, 0)) / 2;
    AddTextPrinterParameterized3(WINDOW_TITLE_BOX, FONT_NORMAL, x, 0, sTextWhite, TEXT_SKIP_DRAW, gText_GirlOrBoy);
    CopyWindowToVram(WINDOW_TITLE_BOX, COPYWIN_FULL);
}

// ============================================================================
// TASK: INITIAL WAIT FOR FADE
// ============================================================================

static void TaskInitCopeSpeechWaitForFade(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].func = TaskChooseOptions;
    }
}

// ============================================================================
// NAMING SCREEN FUNCTIONS
// ============================================================================

void SetDefaultPlayerName(u8 nameId)
{
    const u8 *name;
    u8 i;

    if (gSaveBlock2Ptr->playerGender == MALE)
        name = sMalePresetNames[nameId];
    else
        name = sFemalePresetNames[nameId];
    
    for (i = 0; i < PLAYER_NAME_LENGTH; i++)
        gSaveBlock2Ptr->playerName[i] = name[i];
    gSaveBlock2Ptr->playerName[PLAYER_NAME_LENGTH] = EOS;
}

static void TaskStartNamingScreen(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        FreeAndDestroyMonPicSprite(gTasks[taskId].tSpritePlayerMaleId);
        FreeAndDestroyMonPicSprite(gTasks[taskId].tSpritePlayerFemaleId);
        SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
        DestroyTask(taskId);
        DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerGender, 0, 0, CB2_ReturnFromNamingScreen);
    }
}

// ============================================================================
// UI UPDATE FUNCTIONS
// ============================================================================

static void UpdateOptionSelected(void)
{
    FillWindowPixelBuffer(WINDOW_YESNO_BOX, PIXEL_FILL(10));
    if (gTasks[sTaskId].tOptionChoose == TRUE)
        AddTextPrinterParameterized3(WINDOW_YESNO_BOX, FONT_NORMAL, 0, 0, sTextWhite, TEXT_SKIP_DRAW, gText_Cope_YesNo);
    else
        AddTextPrinterParameterized3(WINDOW_YESNO_BOX, FONT_NORMAL, 0, 0, sTextWhite, TEXT_SKIP_DRAW, gText_Cope_NoYes);
    CopyWindowToVram(WINDOW_YESNO_BOX, COPYWIN_GFX);
}

static void UpdateDifficultySelected(void)
{
    FillWindowPixelBuffer(WINDOW_DIFFICULTY_BOX, PIXEL_FILL(0));
    
    if (gTasks[sTaskId].tDifficulty == DIFFICULTY_EASY)
    {
        LZ77UnCompVram(sDifficultyEasy_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
        LoadPalette(sPalEasy, BG_PLTT_ID(0) + 10, PLTT_SIZEOF(1));
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Easy_Description);
    }
    else if (gTasks[sTaskId].tDifficulty == DIFFICULTY_NORMAL)
    {
        LZ77UnCompVram(sDifficultyNormal_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
        LoadPalette(sPalNormal, BG_PLTT_ID(0) + 10, PLTT_SIZEOF(1));
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Normal_Description);
    }
    else if (gTasks[sTaskId].tDifficulty == DIFFICULTY_HARD)
    {
        LZ77UnCompVram(sDifficultyHard_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
        LoadPalette(sPalHard, BG_PLTT_ID(0) + 10, PLTT_SIZEOF(1));
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Hard_Description);
    }
    CopyWindowToVram(WINDOW_DIFFICULTY_BOX, COPYWIN_FULL);
}

// ============================================================================
// CALLBACK: RETURN FROM NAMING SCREEN
// ============================================================================

static void CB2_ReturnFromNamingScreen(void)
{
    u8 x;
    u16 savedIme;

    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sBgTemplateCopeSpeech, ARRAY_COUNT(sBgTemplateCopeSpeech));
    SetVBlankCallback(NULL);
    DmaFill16(3, 0, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex), BG_SCREEN_SIZE);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();

    ResetAllBgsCoordinates();
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);

    ResetTasks();
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    FreeAllWindowBuffers();

    sTaskId = CreateTask(TaskInitCopeSpeechWaitForFade, 0);
    gTasks[sTaskId].tTimer = 0;
    gTasks[sTaskId].tScene = SCENE_AFTER_NAMING_SCREEN;
    gTasks[sTaskId].tOptionChoose = TRUE;
    gTasks[sTaskId].tPlayerGender = gSaveBlock2Ptr->playerGender;

    InitWindows(sWindowTemplate_Gender);
    LoadGenderBgs();
    LoadGenderSprites(sTaskId);
    UpdateGenderSprites(sTaskId);
    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

    SetupWindowBlendRegisters();
    SetVBlankCallback(VBlank_CB2_Gender);
    SetMainCallback2(CB2_CopeSpeech);

    FillWindowPixelBuffer(WINDOW_TITLE_BOX, PIXEL_FILL(10));
    FillWindowPixelBuffer(WINDOW_YESNO_BOX, PIXEL_FILL(10));
    PutWindowTilemap(WINDOW_TITLE_BOX);
    PutWindowTilemap(WINDOW_YESNO_BOX);

    StringExpandPlaceholders(gStringVar4, gText_SoItsPlayer);
    x = (240 - GetStringWidth(FONT_NORMAL, gStringVar4, 0)) / 2;
    AddTextPrinterParameterized3(WINDOW_TITLE_BOX, FONT_NORMAL, x, 0, sTextWhite, TEXT_SKIP_DRAW, gStringVar4);
    CopyWindowToVram(WINDOW_TITLE_BOX, COPYWIN_FULL);
    UpdateOptionSelected();
    
    savedIme = REG_IME;
    REG_IME = 0;
    REG_IE |= 1;
    REG_IME = savedIme;
}

// ============================================================================
// CALLBACK: RETURN FROM TEAM SELECTOR
// ============================================================================

static void CB2_ReturnFromTeamSelector(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    InitBgsFromTemplates(0, sBgTemplateCopeSpeech, ARRAY_COUNT(sBgTemplateCopeSpeech));
    SetVBlankCallback(NULL);
    DmaFill16(3, 0, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex), BG_SCREEN_SIZE);
    DmaFill16(3, 0, VRAM, VRAM_SIZE);
    DmaFill32(3, 0, OAM, OAM_SIZE);
    DmaFill16(3, 0, PLTT, PLTT_SIZE);
    ResetPaletteFade();

    ResetAllBgsCoordinates();
    ResetTasks();
    ScanlineEffect_Stop();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    FreeAllWindowBuffers();

    InitWindows(sWindowTemplate_Gender);
    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    LoadCopeSpeechBgs();
    LoadCopeSpritesToVRAM();
    
    sTaskId = CreateTask(TaskCopeSpeech_CopeDialogue3, 0);
    gTasks[sTaskId].tScene = SCENE_COPE_SPEECH_END;

    FillWindowPixelBuffer(WINDOW_MSG_BOX, PIXEL_FILL(1));
    PutWindowTilemap(WINDOW_MSG_BOX);

    LoadMainMenuWindowFrameTiles(0, 408);
    LoadMessageBoxGfx(0, 696, BG_PLTT_ID(15));
    NewGameBirchSpeech_ShowDialogueWindow(WINDOW_MSG_BOX, TRUE);
    CopyWindowToVram(WINDOW_MSG_BOX, COPYWIN_GFX);
    NewGameBirchSpeech_ClearWindow(WINDOW_MSG_BOX);
    
    gTasks[sTaskId].tSpriteCopeBodyId = LoadCopeSprite(COPE_BODY_Y, COPE_BASE);
    gTasks[sTaskId].tSpriteCopeLegsId = LoadCopeSprite(COPE_LEGS_Y, COPE_LEGS);
    gTasks[sTaskId].tSpriteCopeCintaId = CreateSprite(&sCintaCopeSpriteTemplate, COPE_CINTA_X, COPE_CINTA_Y, 0);
    SetupCopeSpritePriorities(
        gTasks[sTaskId].tSpriteCopeBodyId,
        gTasks[sTaskId].tSpriteCopeCintaId,
        gTasks[sTaskId].tSpriteCopeLegsId
    );
            
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
    ShowBg(0);
    ShowBg(2);
    ShowBg(3);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetVBlankCallback(VBlank_CB2_CopeSpeech);
    SetMainCallback2(CB2_CopeSpeech);
}

// ============================================================================
// TASK: SELECT DIFFICULTY
// ============================================================================

static void TaskSelectDifficulty(u8 taskId)
{
    u8 x;
    
    if (!gPaletteFade.active)
    {
        DestroySpriteAndFreeResources(&gSprites[gTasks[taskId].tSpriteId]);
        FreeAndDestroyMonPicSprite(gTasks[taskId].tSpriteId);

        LoadPalette(sDifficulty_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LZ77UnCompVram(sDifficulty_Tiles, (void *)VRAM + BG_CHAR_SIZE * sBgTemplateCopeSpeech[1].charBaseIndex);
        LZ77UnCompVram(sDifficultyInterface_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[2].mapBaseIndex));
        LZ77UnCompVram(sDifficultyBg_Map, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[3].mapBaseIndex));
        
        gTasks[sTaskId].tOptionChoose = TRUE;
        gTasks[sTaskId].tScene = SCENE_CHOOSE_DIFFICULTY;
        gTasks[sTaskId].tDifficulty = DIFFICULTY_EASY;
        gTasks[sTaskId].tConfirmSelection = FALSE;
        UpdateDifficultySelected();
        
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
        
        gTasks[taskId].func = TaskChooseOptions;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

        x = (240 - GetStringWidth(FONT_NORMAL, gText_Choose_Difficulty, 0)) / 2;
        AddTextPrinterParameterized3(WINDOW_TITLE_BOX, FONT_NORMAL, x, 0, sTextWhite, TEXT_SKIP_DRAW, gText_Choose_Difficulty);
        x = (64 - GetStringWidth(FONT_NORMAL, gText_Cope_Easy, 0)) / 2;
        AddTextPrinterParameterized3(WINDOW_EASY_BOX, FONT_NORMAL, x, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Cope_Easy);
        x = (64 - GetStringWidth(FONT_NORMAL, gText_Cope_Normal, 0)) / 2;
        AddTextPrinterParameterized3(WINDOW_NORMAL_BOX, FONT_NORMAL, x, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Cope_Normal);
        x = (64 - GetStringWidth(FONT_NORMAL, gText_Cope_Hard, 0)) / 2;
        AddTextPrinterParameterized3(WINDOW_HARD_BOX, FONT_NORMAL, x, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Cope_Hard);
        AddTextPrinterParameterized3(WINDOW_DIFFICULTY_BOX, FONT_NORMAL, 4, 0, sTextBlack, TEXT_SKIP_DRAW, gText_Easy_Description);
        CopyWindowToVram(WINDOW_TITLE_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_YESNO_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_EASY_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_NORMAL_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_HARD_BOX, COPYWIN_FULL);
        CopyWindowToVram(WINDOW_DIFFICULTY_BOX, COPYWIN_FULL);
    }
}

// ============================================================================
// TASK: INIT COPE SPEECH (MAIN DIALOGUE SEQUENCE)
// ============================================================================

static void TaskInitCopeSpeech(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case 0:
        if (!gPaletteFade.active)
        {
            HideBg(1);
            HideBg(2);
            HideBg(3);
            DestroySpriteAndFreeResources(&gSprites[gTasks[taskId].tSpriteId]);
            FreeAndDestroyMonPicSprite(gTasks[taskId].tSpriteId);
            DmaFill16(3, 0, (u16 *)BG_SCREEN_ADDR(sBgTemplateCopeSpeech[1].mapBaseIndex), BG_SCREEN_SIZE);
            SetVBlankCallback(VBlank_CB2_CopeSpeech);

            LoadCopeSpeechBgs();
            LoadCopeSpritesToVRAM();
            ResetAllBgsCoordinates();

            FillWindowPixelBuffer(WINDOW_MSG_BOX, PIXEL_FILL(0));
            PutWindowTilemap(WINDOW_MSG_BOX);

            LoadMainMenuWindowFrameTiles(0, 408);
            LoadMessageBoxGfx(0, 696, BG_PLTT_ID(15));
            NewGameBirchSpeech_ShowDialogueWindow(WINDOW_MSG_BOX, TRUE);
            CopyWindowToVram(WINDOW_MSG_BOX, COPYWIN_GFX);
            NewGameBirchSpeech_ClearWindow(WINDOW_MSG_BOX);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            ShowBg(2);
            ShowBg(3);
            
            gTasks[taskId].tSpriteCopeBodyId = CreateCopeSprite(COPE_BODY_Y, COPE_BASE);
            gTasks[taskId].tSpriteCopeLegsId = CreateCopeSprite(COPE_LEGS_Y, COPE_LEGS);
            gTasks[taskId].tSpriteCopeCintaId = CreateSprite(&sCintaCopeSpriteTemplate, COPE_CINTA_X, COPE_CINTA_Y, 0);
            SetupCopeSpritePriorities(
                gTasks[taskId].tSpriteCopeBodyId,
                gTasks[taskId].tSpriteCopeCintaId,
                gTasks[taskId].tSpriteCopeLegsId
            );
            gTasks[taskId].tState++;
        }
        break;
        
    case 1:
        if (!gPaletteFade.active)
        {
            StringExpandPlaceholders(gStringVar4, gText_Cope_Welcome);
            AddTextPrinterForMessage(TRUE);
            gTasks[taskId].func = TaskCopeSpeech_AnimationBall;
            gTasks[taskId].tState++;
        }
        break;
        
    default:
        break;
    }
}

// ============================================================================
// TASK: CHOOSE OPTIONS (GENDER / CONFIRMATION / DIFFICULTY)
// ============================================================================

static void TaskChooseOptions(u8 taskId)
{
    // --- SCENE: CHOOSE GENDER ---
    if (gTasks[taskId].tScene == SCENE_CHOOSE_GENDER)
    {
        if (JOY_NEW(DPAD_RIGHT) && gTasks[taskId].tPlayerGender == FEMALE && gTasks[taskId].tSliceBgsState == 0)
        {
            gTasks[taskId].tPlayerGender = MALE;
            gTasks[taskId].tSliceBgsState = 16;
            UpdateGenderSprites(taskId);
        }
        else if (JOY_NEW(DPAD_LEFT) && gTasks[taskId].tPlayerGender == MALE && gTasks[taskId].tSliceBgsState == 0)
        {
            gTasks[taskId].tPlayerGender = FEMALE;
            gTasks[taskId].tSliceBgsState = 16;
            UpdateGenderSprites(taskId);
        }
        else if (JOY_NEW(A_BUTTON) && gTasks[taskId].tSliceBgsState == 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gSaveBlock2Ptr->playerGender = gTasks[taskId].tPlayerGender;
            gTasks[taskId].func = TaskStartNamingScreen;
        }
    }
    
    // --- SCENE: AFTER NAMING SCREEN (CONFIRMATION) ---
    if (gTasks[taskId].tScene == SCENE_AFTER_NAMING_SCREEN)
    {
        if (JOY_NEW(DPAD_UP | DPAD_DOWN))
        {
             gTasks[taskId].tOptionChoose ^= 1;
             UpdateOptionSelected();
        }
        else if (JOY_NEW(A_BUTTON))
        {
            if (gTasks[taskId].tOptionChoose == FALSE)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = TaskStartNamingScreen;
            }
            else
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = TaskSelectDifficulty;
            }
        }
    }
    
    // --- SCENE: CHOOSE DIFFICULTY ---
    if (gTasks[taskId].tScene == SCENE_CHOOSE_DIFFICULTY)
    {
        if (JOY_NEW(DPAD_LEFT) && gTasks[taskId].tDifficulty > DIFFICULTY_EASY)
        {
             gTasks[taskId].tDifficulty--;
             UpdateDifficultySelected();
        }
        else if (JOY_NEW(DPAD_RIGHT) && gTasks[taskId].tDifficulty < DIFFICULTY_HARD)
        {
             gTasks[taskId].tDifficulty++;
            UpdateDifficultySelected();
        }
        else if (JOY_NEW(A_BUTTON))
        {
            VarSet(VAR_DIFFICULTY, gTasks[taskId].tDifficulty);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = TaskInitCopeSpeech;
        }
    }
}

// ============================================================================
// TASKS: COPE SPEECH DIALOGUE SEQUENCE
// ============================================================================

static void TaskCopeSpeech_AnimationBall(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        StartSpriteAnim(&gSprites[gTasks[taskId].tSpriteCopeBodyId], COPE_THROW_BALL);
        PlaySE(SE_BALL_THROW);
        gTasks[taskId].func = TaskCopeSpeech_ShowMon;
    }
}

static void TaskCopeSpeech_ShowMon(u8 taskId)
{
    if (++gTasks[taskId].tTimer > 34 && !IsSEPlaying())
    {
        PlaySE(SE_BALL_OPEN);
        StartSpriteAnim(&gSprites[gTasks[taskId].tSpriteCopeBodyId], COPE_SHOW_BALL);
        gTasks[taskId].tMonSpriteId = CreateMonSpriteFromNationalDexNumber(SPECIES_KECLEON, 87, 85, 5);
        PokemonSummaryDoMonAnimation(&gSprites[gTasks[taskId].tMonSpriteId], SPECIES_KECLEON, FALSE);
        gTasks[taskId].func = TaskCopeSpeech_WaitMonFinishAnim;
    }
}

static void TaskCopeSpeech_WaitMonFinishAnim(u8 taskId)
{
    if (gSprites[gTasks[taskId].tMonSpriteId].animEnded)
    {
        StartSpriteAnim(&gSprites[gTasks[taskId].tMonSpriteId], 0);
        gTasks[taskId].func = TaskCopeSpeech_CopeDialogue1;
    }
}

static void TaskCopeSpeech_CopeDialogue1(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active() && !IsSEPlaying() && JOY_NEW(A_BUTTON))
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
    if (IsCryFinished() && !RunTextPrintersAndIsPrinter0Active() && JOY_NEW(A_BUTTON))
    {
        FillWindowPixelBuffer(WINDOW_MSG_BOX, PIXEL_FILL(1));
        StringExpandPlaceholders(gStringVar4, gText_Cope_ExplainChalenge);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = TaskCopeSpeech_DoFaceBeforeEndEndSpeech;
    }
}

static void TaskCopeSpeech_CopeDialogue3(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        StringExpandPlaceholders(gStringVar4, gText_Cope_Farewell);
        AddTextPrinterForMessage(TRUE);
        gTasks[taskId].func = TaskCopeSpeech_WaitPressA;
    }
}

static void TaskCopeSpeech_WaitPressA(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active() && JOY_NEW(A_BUTTON))
    {
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        CopyWindowToVram(0, COPYWIN_GFX);
        RemoveWindow(0);
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tSliceBg3 = 0;
        gTasks[taskId].func = TaskCopeSpeech_OpenDoor;
    }
}

static void TaskCopeSpeech_OpenDoor(u8 taskId)
{
    if (gTasks[taskId].tTimer % 4 == 0)
    {
        gTasks[taskId].tSliceBg3 += 1;
        SetGpuReg(REG_OFFSET_BG3HOFS, gTasks[taskId].tSliceBg3);

        if (gTasks[taskId].tSliceBg3 >= MAX_SLICE_BG_3)
            gTasks[taskId].func = TaskCopeSpeech_DoFaceBeforeEndEndSpeech;
    }
    gTasks[taskId].tTimer++;
}

static void TaskCopeSpeech_DoFaceBeforeEndEndSpeech(u8 taskId)
{
    if (!RunTextPrintersAndIsPrinter0Active())
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = TaskCopeSpeech_Cleanup;
    }
}

static void TaskCopeSpeech_Cleanup(u8 taskId)
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

static void TaskCopeSpeech_FadeOut(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        if (gTasks[sTaskId].tScene == SCENE_COPE_SPEECH_END)
            SetMainCallback2(CB2_NewGame);
        else
        {
            NewGameInitData();
            FlagSet(FLAG_SYS_POKEMON_GET);
            gMain.savedCallback = CB2_ReturnFromTeamSelector;
            SetMainCallback2(StartTeamSelector_CB2);
        }
        DestroyTask(taskId);
        FreeAllWindowBuffers();
    }
}

#undef tOptionChoose
#undef tDifficulty
#undef tScene
#undef tSpritePlayerMaleId
#undef tSpritePlayerFemaleId
#undef tPlayerGender
#undef tSpriteId
#undef tSliceBgsState
#undef tConfirmSelection
#undef tSpriteCopeBodyId
#undef tSpriteCopeLegsId
#undef tSpriteCopeCintaId
#undef tMonSpriteId
#undef tTimer
#undef tSliceBg3
#undef tState
#undef sMoveUp
#undef sTimer
