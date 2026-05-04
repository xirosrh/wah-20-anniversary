#include "global.h"
#include "task.h"
#include "sprite.h"
#include "graphics.h"
#include "decompress.h"
#include "trig.h"
#include "random.h"
#include "gba/defines.h"

#define TAG_ACHIEVEMENT_CONFETTI 1002

#define tFrameCount data[0]

#define sSineIdx data[0]
#define sExtraY  data[1]

static void SpriteCB_AchievementConfetti(struct Sprite *sprite);
static void Task_AchievementConfetti(u8 taskId);

static const struct CompressedSpriteSheet sSpriteSheet_AchievementConfetti[] =
{
    {.data = gConfetti_Gfx, .size = 0x220, .tag = TAG_ACHIEVEMENT_CONFETTI},
    {},
};

static const struct SpritePalette sSpritePalette_AchievementConfetti[] =
{
    {.data = gConfetti_Pal, .tag = TAG_ACHIEVEMENT_CONFETTI},
    {},
};

static const struct OamData sOamData_AchievementConfetti =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PinkA[]   = { ANIMCMD_FRAME( 0, 30), ANIMCMD_END };
static const union AnimCmd sAnim_RedA[]    = { ANIMCMD_FRAME( 1, 30), ANIMCMD_END };
static const union AnimCmd sAnim_BlueA[]   = { ANIMCMD_FRAME( 2, 30), ANIMCMD_END };
static const union AnimCmd sAnim_RedB[]    = { ANIMCMD_FRAME( 3, 30), ANIMCMD_END };
static const union AnimCmd sAnim_BlueB[]   = { ANIMCMD_FRAME( 4, 30), ANIMCMD_END };
static const union AnimCmd sAnim_YellowA[] = { ANIMCMD_FRAME( 5, 30), ANIMCMD_END };
static const union AnimCmd sAnim_WhiteA[]  = { ANIMCMD_FRAME( 6, 30), ANIMCMD_END };
static const union AnimCmd sAnim_GreenA[]  = { ANIMCMD_FRAME( 7, 30), ANIMCMD_END };
static const union AnimCmd sAnim_PinkB[]   = { ANIMCMD_FRAME( 8, 30), ANIMCMD_END };
static const union AnimCmd sAnim_BlueC[]   = { ANIMCMD_FRAME( 9, 30), ANIMCMD_END };
static const union AnimCmd sAnim_YellowB[] = { ANIMCMD_FRAME(10, 30), ANIMCMD_END };
static const union AnimCmd sAnim_WhiteB[]  = { ANIMCMD_FRAME(11, 30), ANIMCMD_END };
static const union AnimCmd sAnim_GreenB[]  = { ANIMCMD_FRAME(12, 30), ANIMCMD_END };
static const union AnimCmd sAnim_PinkC[]   = { ANIMCMD_FRAME(13, 30), ANIMCMD_END };
static const union AnimCmd sAnim_RedC[]    = { ANIMCMD_FRAME(14, 30), ANIMCMD_END };
static const union AnimCmd sAnim_YellowC[] = { ANIMCMD_FRAME(15, 30), ANIMCMD_END };
static const union AnimCmd sAnim_WhiteC[]  = { ANIMCMD_FRAME(16, 30), ANIMCMD_END };

static const union AnimCmd *const sAnims_AchievementConfetti[] =
{
    sAnim_PinkA,   sAnim_RedA,    sAnim_BlueA,
    sAnim_RedB,    sAnim_BlueB,   sAnim_YellowA,
    sAnim_WhiteA,  sAnim_GreenA,  sAnim_PinkB,
    sAnim_BlueC,   sAnim_YellowB, sAnim_WhiteB,
    sAnim_GreenB,  sAnim_PinkC,   sAnim_RedC,
    sAnim_YellowC, sAnim_WhiteC
};

static const struct SpriteTemplate sSpriteTemplate_AchievementConfetti =
{
    .tileTag = TAG_ACHIEVEMENT_CONFETTI,
    .paletteTag = TAG_ACHIEVEMENT_CONFETTI,
    .oam = &sOamData_AchievementConfetti,
    .anims = sAnims_AchievementConfetti,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_AchievementConfetti
};

static void SpriteCB_AchievementConfetti(struct Sprite *sprite)
{
    if (sprite->y2 > 168)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 rand;
        u8 sineIdx;

        sprite->y2++;
        sprite->y2 += sprite->sExtraY;

        sineIdx = sprite->sSineIdx;
        rand = (Random() % 4) + 8;
        sprite->x2 = rand * gSineTable[sineIdx] / 256;

        sprite->sSineIdx += 4;
    }
}

static void CreateAchievementConfettiSprite(void)
{
    u8 spriteId;
    struct Sprite *sprite;
    s16 posX = Random() % DISPLAY_WIDTH;
    s16 posY = -(Random() % 8);

    spriteId = CreateSprite(&sSpriteTemplate_AchievementConfetti, posX, posY, 0);
    sprite = &gSprites[spriteId];
    StartSpriteAnim(sprite, Random() % ARRAY_COUNT(sAnims_AchievementConfetti));

    if (Random() & 3)
        sprite->sExtraY = 0;
    else
        sprite->sExtraY = 1;
}

static void Task_AchievementConfetti(u8 taskId)
{
    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
        if ((gTasks[taskId].tFrameCount & 3) == 0 && gTasks[taskId].tFrameCount > 110)
            CreateAchievementConfettiSprite();
    }
}

void StartAchievementConfetti(void)
{
    if (FindTaskIdByFunc(Task_AchievementConfetti) != TASK_NONE)
        return;

    LoadCompressedSpriteSheet(sSpriteSheet_AchievementConfetti);
    LoadSpritePalette(sSpritePalette_AchievementConfetti);

    u8 taskId = CreateTask(Task_AchievementConfetti, 5);
    gTasks[taskId].tFrameCount = 400;
}

void StopAchievementConfetti(void)
{
    u8 taskId = FindTaskIdByFunc(Task_AchievementConfetti);
    if (taskId != TASK_NONE)
        DestroyTask(taskId);

    u32 i;
    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse && gSprites[i].template == &sSpriteTemplate_AchievementConfetti)
            DestroySprite(&gSprites[i]);
    }

    FreeSpriteTilesByTag(TAG_ACHIEVEMENT_CONFETTI);
    FreeSpritePaletteByTag(TAG_ACHIEVEMENT_CONFETTI);
}

#undef tFrameCount
#undef sSineIdx
#undef sExtraY
