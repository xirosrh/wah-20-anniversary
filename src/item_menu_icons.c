#include "global.h"
#include "berry.h"
#include "decompress.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_icon.h"
#include "item_menu_icons.h"
#include "malloc.h"
#include "menu_helpers.h"
#include "menu.h"
#include "sprite.h"
#include "trig.h"
#include "window.h"
#include "util.h"
#include "constants/items.h"

enum {
    TAG_BAG_GFX = 100,
    TAG_ROTATING_BALL_GFX,
    TAG_ITEM_ICON,
    TAG_ITEM_ICON_ALT,
    TAG_POCKET_ICON_GFX,
    TAG_POCKET_ICON_PAL_NORMAL,
    TAG_POCKET_ICON_PAL_SELECTED,
    TAG_POCKET_SWITCH_ARROW,
    TAG_SCROLL_ARROW_UP,
    // 109 is TAG_SWAP_LINE in menu_helpers.c - DO NOT USE
    TAG_SCROLL_ARROW_DOWN = 110,
    TAG_SCROLL_ARROW_PAL,
};
#define TAG_BERRY_CHECK_CIRCLE_GFX 10000
#define TAG_BERRY_PIC_PAL 30020

#define POCKET_ICON_SIZE (16 * 16 / 2)
#define POCKET_ICON_TOTAL_SIZE (POCKET_ICON_SIZE * 5)

struct TilesPal
{
    const u32 *tiles;
    const u16 *pal;
};

// this file's functions
static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite);
static void SpriteCB_ShakeBagSprite(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite);
static void SpriteCB_SwitchPocketRotatingBallContinue(struct Sprite *sprite);

// static const rom data
static const u16 sRotatingBall_Pal[] = INCBIN_U16("graphics/bag/rotating_ball.gbapal");
static const u8 sRotatingBall_Gfx[] = INCBIN_U8("graphics/bag/rotating_ball.4bpp");

static const u16 sPocketSwitchArrow_Pal[] = INCBIN_U16("graphics/bag/arrow.gbapal");
static const u8 sPocketSwitchArrow_Gfx[] = INCBIN_U8("graphics/bag/arrow.4bpp");

static const u16 sScrollArrow_Pal[] = INCBIN_U16("graphics/bag/arrow_scroll.gbapal");
static const u8 sScrollArrowUp_Gfx[] = INCBIN_U8("graphics/bag/arrow_up.4bpp");
static const u8 sScrollArrowDown_Gfx[] = INCBIN_U8("graphics/bag/arrow_down.4bpp");

static const struct OamData sBagOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_Bag_Closed[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_Items[] =
{
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_KeyItems[] =
{
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_Pokeballs[] =
{
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_TMsHMs[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_Bag_Berries[] =
{
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_END
};

static const union AnimCmd *const sBagSpriteAnimTable[] =
{
    [POCKET_ITEMS]      = sSpriteAnim_Bag_Items,
    [POCKET_POKE_BALLS] = sSpriteAnim_Bag_Pokeballs,
    [POCKET_TM_HM]      = sSpriteAnim_Bag_TMsHMs,
    [POCKET_BERRIES]    = sSpriteAnim_Bag_Berries,
    [POCKET_KEY_ITEMS]  = sSpriteAnim_Bag_KeyItems,
    [POCKET_DUMMY]       = sSpriteAnim_Bag_Closed,
};

static const union AffineAnimCmd sSpriteAffineAnim_BagNormal[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_BagShake[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 254, 2),
    AFFINEANIMCMD_FRAME(0, 0, 2, 4),
    AFFINEANIMCMD_FRAME(0, 0, 254, 4),
    AFFINEANIMCMD_FRAME(0, 0, 2, 2),
    AFFINEANIMCMD_END
};

enum {
    ANIM_BAG_NORMAL,
    ANIM_BAG_SHAKE,
};

static const union AffineAnimCmd *const sBagAffineAnimCmds[] =
{
    [ANIM_BAG_NORMAL] = sSpriteAffineAnim_BagNormal,
    [ANIM_BAG_SHAKE]  = sSpriteAffineAnim_BagShake
};

const struct CompressedSpriteSheet gBagMaleSpriteSheet =
{
    gBagMaleTiles, 0x3000, TAG_BAG_GFX
};

const struct CompressedSpriteSheet gBagFemaleSpriteSheet =
{
    gBagFemaleTiles, 0x3000, TAG_BAG_GFX
};

const struct SpritePalette gBagPaletteTable =
{
    gBagPalette, TAG_BAG_GFX
};

const struct CompressedSpriteSheet gBagPocketIconsSpriteSheet =
{
    gBagPocketIcons_Gfx, POCKET_ICON_TOTAL_SIZE, TAG_POCKET_ICON_GFX
};

const struct SpritePalette gBagPocketIconsPaletteNormal =
{
    gBagPocketIcons_Pal, TAG_POCKET_ICON_PAL_NORMAL
};

const struct SpritePalette gBagPocketIconsPaletteSelected =
{
    gBagPocketIconsSel_Pal, TAG_POCKET_ICON_PAL_SELECTED
};

static const struct OamData sPocketIconOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_NORMAL,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AffineAnimCmd sPocketIconAffineAnim_Normal[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sPocketIconAffineAnim_Rock[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 253, 6),
    AFFINEANIMCMD_FRAME(0, 0, 3, 12),
    AFFINEANIMCMD_FRAME(0, 0, 253, 6),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

enum {
    ANIM_POCKET_ICON_NORMAL,
    ANIM_POCKET_ICON_ROCK,
};

static const union AffineAnimCmd *const sPocketIconAffineAnimTable[] =
{
    [ANIM_POCKET_ICON_NORMAL] = sPocketIconAffineAnim_Normal,
    [ANIM_POCKET_ICON_ROCK]   = sPocketIconAffineAnim_Rock,
};

static const union AnimCmd sSpriteAnim_PocketIcon_Items[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PocketIcon_Balls[] =
{
    ANIMCMD_FRAME(4, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PocketIcon_TMs[] =
{
    ANIMCMD_FRAME(8, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PocketIcon_Berries[] =
{
    ANIMCMD_FRAME(12, 0),
    ANIMCMD_END
};

static const union AnimCmd sSpriteAnim_PocketIcon_KeyItems[] =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sPocketIconAnimTable[] =
{
    [POCKET_ITEMS]      = sSpriteAnim_PocketIcon_Items,
    [POCKET_POKE_BALLS] = sSpriteAnim_PocketIcon_Balls,
    [POCKET_TM_HM]      = sSpriteAnim_PocketIcon_TMs,
    [POCKET_BERRIES]    = sSpriteAnim_PocketIcon_Berries,
    [POCKET_KEY_ITEMS]  = sSpriteAnim_PocketIcon_KeyItems,
};

static const struct SpriteTemplate sPocketIconSpriteTemplate =
{
    .tileTag = TAG_POCKET_ICON_GFX,
    .paletteTag = TAG_POCKET_ICON_PAL_NORMAL,
    .oam = &sPocketIconOamData,
    .anims = sPocketIconAnimTable,
    .images = NULL,
    .affineAnims = sPocketIconAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static void SpriteCB_PocketSwitchArrowBounce(struct Sprite *sprite);

static const struct OamData sPocketSwitchArrowOamData =
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
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_PocketSwitchArrow[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sPocketSwitchArrowAnimTable[] =
{
    sSpriteAnim_PocketSwitchArrow,
};

static const struct SpriteSheet sPocketSwitchArrowSpriteSheet =
{
    sPocketSwitchArrow_Gfx, sizeof(sPocketSwitchArrow_Gfx), TAG_POCKET_SWITCH_ARROW
};

static const struct SpritePalette sPocketSwitchArrowPalette =
{
    sPocketSwitchArrow_Pal, TAG_POCKET_SWITCH_ARROW
};

static const struct SpriteTemplate sPocketSwitchArrowSpriteTemplate =
{
    .tileTag = TAG_POCKET_SWITCH_ARROW,
    .paletteTag = TAG_POCKET_SWITCH_ARROW,
    .oam = &sPocketSwitchArrowOamData,
    .anims = sPocketSwitchArrowAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PocketSwitchArrowBounce,
};

static void SpriteCB_ScrollArrowBounce(struct Sprite *sprite);

static const struct OamData sScrollArrowOamData =
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
    .affineParam = 0
};

static const struct SpriteSheet sScrollArrowUpSpriteSheet =
{
    sScrollArrowDown_Gfx, sizeof(sScrollArrowDown_Gfx), TAG_SCROLL_ARROW_UP
};

static const struct SpriteSheet sScrollArrowDownSpriteSheet =
{
    sScrollArrowUp_Gfx, sizeof(sScrollArrowUp_Gfx), TAG_SCROLL_ARROW_DOWN
};

static const struct SpritePalette sScrollArrowPalette =
{
    sScrollArrow_Pal, TAG_SCROLL_ARROW_PAL
};

static const struct SpriteTemplate sScrollArrowUpSpriteTemplate =
{
    .tileTag = TAG_SCROLL_ARROW_UP,
    .paletteTag = TAG_SCROLL_ARROW_PAL,
    .oam = &sScrollArrowOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ScrollArrowBounce,
};

static const struct SpriteTemplate sScrollArrowDownSpriteTemplate =
{
    .tileTag = TAG_SCROLL_ARROW_DOWN,
    .paletteTag = TAG_SCROLL_ARROW_PAL,
    .oam = &sScrollArrowOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_ScrollArrowBounce,
};

static const struct SpriteTemplate sBagSpriteTemplate =
{
    .tileTag = TAG_BAG_GFX,
    .paletteTag = TAG_BAG_GFX,
    .oam = &sBagOamData,
    .anims = sBagSpriteAnimTable,
    .images = NULL,
    .affineAnims = sBagAffineAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct OamData sRotatingBallOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 4,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 2,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAffineAnim_RotatingBallStationary[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sRotatingBallSpriteAnimTable[] =
{
    sSpriteAffineAnim_RotatingBallStationary
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingBallRotation1[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 8, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sSpriteAffineAnim_RotatingBallRotation2[] =
{
    AFFINEANIMCMD_FRAME(0, 0, 248, 16),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd *const sRotatingBallAnimCmds[] =
{
    sSpriteAffineAnim_RotatingBallRotation1,
};

static const union AffineAnimCmd *const sRotatingBallAnimCmds_FullRotation[] =
{
    sSpriteAffineAnim_RotatingBallRotation2,
};

static const struct SpriteSheet sRotatingBallTable =
{
    sRotatingBall_Gfx, sizeof(sRotatingBall_Gfx), TAG_ROTATING_BALL_GFX
};

static const struct SpritePalette sRotatingBallPaletteTable =
{
    sRotatingBall_Pal, TAG_ROTATING_BALL_GFX
};

static const struct SpriteTemplate sRotatingBallSpriteTemplate =
{
    .tileTag = TAG_ROTATING_BALL_GFX,
    .paletteTag = TAG_ROTATING_BALL_GFX,
    .oam = &sRotatingBallOamData,
    .anims = sRotatingBallSpriteAnimTable,
    .images = NULL,
    .affineAnims = sRotatingBallAnimCmds,
    .callback = SpriteCB_SwitchPocketRotatingBallInit,
};

static const struct OamData sBerryPicOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 7,
    .affineParam = 0
};

static const struct OamData sBerryPicRotatingOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 7,
    .affineParam = 0
};

static const union AnimCmd sAnim_BerryPic[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryPicSpriteAnimTable[] =
{
    sAnim_BerryPic
};

static const struct SpriteTemplate sBerryPicSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation1[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 253, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 255, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd sSpriteAffineAnim_BerryPicRotation2[] =
{
    AFFINEANIMCMD_FRAME(-1, -1, 3, 96),
    AFFINEANIMCMD_FRAME(0, 0, 0, 16),
    AFFINEANIMCMD_FRAME(-2, -2, 1, 64),
    AFFINEANIMCMD_FRAME(-8, 0, 0, 16),
    AFFINEANIMCMD_FRAME(0, -8, 0, 16),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_JUMP(0)
};

static const union AffineAnimCmd *const sBerryPicRotatingAnimCmds[] =
{
    sSpriteAffineAnim_BerryPicRotation1,
    sSpriteAffineAnim_BerryPicRotation2
};

static const struct SpriteTemplate sBerryPicRotatingSpriteTemplate =
{
    .tileTag = TAG_NONE,
    .paletteTag = TAG_BERRY_PIC_PAL,
    .oam = &sBerryPicRotatingOamData,
    .anims = sBerryPicSpriteAnimTable,
    .images = NULL,
    .affineAnims = sBerryPicRotatingAnimCmds,
    .callback = SpriteCallbackDummy,
};

static const struct TilesPal sBerryPicTable[] =
{
    [ITEM_TO_BERRY(ITEM_CHERI_BERRY)  - 1]          = {gBerryPic_Cheri,  gBerryPalette_Cheri},
    [ITEM_TO_BERRY(ITEM_CHESTO_BERRY) - 1]          = {gBerryPic_Chesto, gBerryPalette_Chesto},
    [ITEM_TO_BERRY(ITEM_PECHA_BERRY)  - 1]          = {gBerryPic_Pecha,  gBerryPalette_Pecha},
    [ITEM_TO_BERRY(ITEM_RAWST_BERRY)  - 1]          = {gBerryPic_Rawst,  gBerryPalette_Rawst},
    [ITEM_TO_BERRY(ITEM_ASPEAR_BERRY) - 1]          = {gBerryPic_Aspear, gBerryPalette_Aspear},
    [ITEM_TO_BERRY(ITEM_LEPPA_BERRY)  - 1]          = {gBerryPic_Leppa,  gBerryPalette_Leppa},
    [ITEM_TO_BERRY(ITEM_ORAN_BERRY)   - 1]          = {gBerryPic_Oran,   gBerryPalette_Oran},
    [ITEM_TO_BERRY(ITEM_PERSIM_BERRY) - 1]          = {gBerryPic_Persim, gBerryPalette_Persim},
    [ITEM_TO_BERRY(ITEM_LUM_BERRY)    - 1]          = {gBerryPic_Lum,    gBerryPalette_Lum},
    [ITEM_TO_BERRY(ITEM_SITRUS_BERRY) - 1]          = {gBerryPic_Sitrus, gBerryPalette_Sitrus},
    [ITEM_TO_BERRY(ITEM_FIGY_BERRY)   - 1]          = {gBerryPic_Figy,   gBerryPalette_Figy},
    [ITEM_TO_BERRY(ITEM_WIKI_BERRY)   - 1]          = {gBerryPic_Wiki,   gBerryPalette_Wiki},
    [ITEM_TO_BERRY(ITEM_MAGO_BERRY)   - 1]          = {gBerryPic_Mago,   gBerryPalette_Mago},
    [ITEM_TO_BERRY(ITEM_AGUAV_BERRY)  - 1]          = {gBerryPic_Aguav,  gBerryPalette_Aguav},
    [ITEM_TO_BERRY(ITEM_IAPAPA_BERRY) - 1]          = {gBerryPic_Iapapa, gBerryPalette_Iapapa},
    [ITEM_TO_BERRY(ITEM_RAZZ_BERRY)   - 1]          = {gBerryPic_Razz,   gBerryPalette_Razz},
    [ITEM_TO_BERRY(ITEM_BLUK_BERRY)   - 1]          = {gBerryPic_Bluk,   gBerryPalette_Bluk},
    [ITEM_TO_BERRY(ITEM_NANAB_BERRY)  - 1]          = {gBerryPic_Nanab,  gBerryPalette_Nanab},
    [ITEM_TO_BERRY(ITEM_WEPEAR_BERRY) - 1]          = {gBerryPic_Wepear, gBerryPalette_Wepear},
    [ITEM_TO_BERRY(ITEM_PINAP_BERRY)  - 1]          = {gBerryPic_Pinap,  gBerryPalette_Pinap},
    [ITEM_TO_BERRY(ITEM_POMEG_BERRY)  - 1]          = {gBerryPic_Pomeg,  gBerryPalette_Pomeg},
    [ITEM_TO_BERRY(ITEM_KELPSY_BERRY) - 1]          = {gBerryPic_Kelpsy, gBerryPalette_Kelpsy},
    [ITEM_TO_BERRY(ITEM_QUALOT_BERRY) - 1]          = {gBerryPic_Qualot, gBerryPalette_Qualot},
    [ITEM_TO_BERRY(ITEM_HONDEW_BERRY) - 1]          = {gBerryPic_Hondew, gBerryPalette_Hondew},
    [ITEM_TO_BERRY(ITEM_GREPA_BERRY)  - 1]          = {gBerryPic_Grepa,  gBerryPalette_Grepa},
    [ITEM_TO_BERRY(ITEM_TAMATO_BERRY) - 1]          = {gBerryPic_Tamato, gBerryPalette_Tamato},
    [ITEM_TO_BERRY(ITEM_CORNN_BERRY)  - 1]          = {gBerryPic_Cornn,  gBerryPalette_Cornn},
    [ITEM_TO_BERRY(ITEM_MAGOST_BERRY) - 1]          = {gBerryPic_Magost, gBerryPalette_Magost},
    [ITEM_TO_BERRY(ITEM_RABUTA_BERRY) - 1]          = {gBerryPic_Rabuta, gBerryPalette_Rabuta},
    [ITEM_TO_BERRY(ITEM_NOMEL_BERRY)  - 1]          = {gBerryPic_Nomel,  gBerryPalette_Nomel},
    [ITEM_TO_BERRY(ITEM_SPELON_BERRY) - 1]          = {gBerryPic_Spelon, gBerryPalette_Spelon},
    [ITEM_TO_BERRY(ITEM_PAMTRE_BERRY) - 1]          = {gBerryPic_Pamtre, gBerryPalette_Pamtre},
    [ITEM_TO_BERRY(ITEM_WATMEL_BERRY) - 1]          = {gBerryPic_Watmel, gBerryPalette_Watmel},
    [ITEM_TO_BERRY(ITEM_DURIN_BERRY)  - 1]          = {gBerryPic_Durin,  gBerryPalette_Durin},
    [ITEM_TO_BERRY(ITEM_BELUE_BERRY)  - 1]          = {gBerryPic_Belue,  gBerryPalette_Belue},
    [ITEM_TO_BERRY(ITEM_CHILAN_BERRY) - 1]          = {gBerryPic_Chilan, gBerryPalette_Chilan},
    [ITEM_TO_BERRY(ITEM_OCCA_BERRY)   - 1]          = {gBerryPic_Occa, gBerryPalette_Occa},
    [ITEM_TO_BERRY(ITEM_PASSHO_BERRY) - 1]          = {gBerryPic_Passho, gBerryPalette_Passho},
    [ITEM_TO_BERRY(ITEM_WACAN_BERRY)  - 1]          = {gBerryPic_Wacan, gBerryPalette_Wacan},
    [ITEM_TO_BERRY(ITEM_RINDO_BERRY)  - 1]          = {gBerryPic_Rindo, gBerryPalette_Rindo},
    [ITEM_TO_BERRY(ITEM_YACHE_BERRY)  - 1]          = {gBerryPic_Yache, gBerryPalette_Yache},
    [ITEM_TO_BERRY(ITEM_CHOPLE_BERRY) - 1]          = {gBerryPic_Chople, gBerryPalette_Chople},
    [ITEM_TO_BERRY(ITEM_KEBIA_BERRY)  - 1]          = {gBerryPic_Kebia, gBerryPalette_Kebia},
    [ITEM_TO_BERRY(ITEM_SHUCA_BERRY)  - 1]          = {gBerryPic_Shuca, gBerryPalette_Shuca},
    [ITEM_TO_BERRY(ITEM_COBA_BERRY)   - 1]          = {gBerryPic_Coba, gBerryPalette_Coba},
    [ITEM_TO_BERRY(ITEM_PAYAPA_BERRY) - 1]          = {gBerryPic_Payapa, gBerryPalette_Payapa},
    [ITEM_TO_BERRY(ITEM_TANGA_BERRY)  - 1]          = {gBerryPic_Tanga, gBerryPalette_Tanga},
    [ITEM_TO_BERRY(ITEM_CHARTI_BERRY) - 1]          = {gBerryPic_Charti, gBerryPalette_Charti},
    [ITEM_TO_BERRY(ITEM_KASIB_BERRY)  - 1]          = {gBerryPic_Kasib, gBerryPalette_Kasib},
    [ITEM_TO_BERRY(ITEM_HABAN_BERRY)  - 1]          = {gBerryPic_Haban, gBerryPalette_Haban},
    [ITEM_TO_BERRY(ITEM_COLBUR_BERRY) - 1]          = {gBerryPic_Colbur, gBerryPalette_Colbur},
    [ITEM_TO_BERRY(ITEM_BABIRI_BERRY) - 1]          = {gBerryPic_Babiri, gBerryPalette_Babiri},
    [ITEM_TO_BERRY(ITEM_ROSELI_BERRY) - 1]          = {gBerryPic_Roseli, gBerryPalette_Roseli},
    [ITEM_TO_BERRY(ITEM_LIECHI_BERRY) - 1]          = {gBerryPic_Liechi, gBerryPalette_Liechi},
    [ITEM_TO_BERRY(ITEM_GANLON_BERRY) - 1]          = {gBerryPic_Ganlon, gBerryPalette_Ganlon},
    [ITEM_TO_BERRY(ITEM_SALAC_BERRY)  - 1]          = {gBerryPic_Salac,  gBerryPalette_Salac},
    [ITEM_TO_BERRY(ITEM_PETAYA_BERRY) - 1]          = {gBerryPic_Petaya, gBerryPalette_Petaya},
    [ITEM_TO_BERRY(ITEM_APICOT_BERRY) - 1]          = {gBerryPic_Apicot, gBerryPalette_Apicot},
    [ITEM_TO_BERRY(ITEM_LANSAT_BERRY) - 1]          = {gBerryPic_Lansat, gBerryPalette_Lansat},
    [ITEM_TO_BERRY(ITEM_STARF_BERRY)  - 1]          = {gBerryPic_Starf,  gBerryPalette_Starf},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) - 1]          = {gBerryPic_Enigma, gBerryPalette_Enigma},
    [ITEM_TO_BERRY(ITEM_MICLE_BERRY)  - 1]          = {gBerryPic_Micle, gBerryPalette_Micle},
    [ITEM_TO_BERRY(ITEM_CUSTAP_BERRY) - 1]          = {gBerryPic_Custap, gBerryPalette_Custap},
    [ITEM_TO_BERRY(ITEM_JABOCA_BERRY) - 1]          = {gBerryPic_Jaboca, gBerryPalette_Jaboca},
    [ITEM_TO_BERRY(ITEM_ROWAP_BERRY)  - 1]          = {gBerryPic_Rowap, gBerryPalette_Rowap},
    [ITEM_TO_BERRY(ITEM_KEE_BERRY)    - 1]          = {gBerryPic_Kee, gBerryPalette_Kee},
    [ITEM_TO_BERRY(ITEM_MARANGA_BERRY)- 1]          = {gBerryPic_Maranga, gBerryPalette_Maranga},
    [ITEM_TO_BERRY(ITEM_ENIGMA_BERRY_E_READER) - 1] = {gBerryPic_Enigma, gBerryPalette_Enigma},
};

const struct CompressedSpriteSheet gBerryCheckCircleSpriteSheet =
{
    gBerryCheckCircle_Gfx, 0x800, TAG_BERRY_CHECK_CIRCLE_GFX
};

const struct SpritePalette gBerryCheckCirclePaletteTable =
{
    gBerryCheck_Pal, TAG_BERRY_CHECK_CIRCLE_GFX
};

static const struct OamData sBerryCheckCircleOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0
};

static const union AnimCmd sSpriteAnim_BerryCheckCircle[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd *const sBerryCheckCircleSpriteAnimTable[] =
{
    sSpriteAnim_BerryCheckCircle
};

static const struct SpriteTemplate sBerryCheckCircleSpriteTemplate =
{
    .tileTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .paletteTag = TAG_BERRY_CHECK_CIRCLE_GFX,
    .oam = &sBerryCheckCircleOamData,
    .anims = sBerryCheckCircleSpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// code
void RemoveBagSprite(u8 id)
{
    u8 *spriteId = &gBagMenu->spriteIds[id];
    if (*spriteId != SPRITE_NONE)
    {
        FreeSpriteTilesByTag(id + TAG_BAG_GFX);
        FreeSpritePaletteByTag(id + TAG_BAG_GFX);
        FreeSpriteOamMatrix(&gSprites[*spriteId]);
        DestroySprite(&gSprites[*spriteId]);
        *spriteId = SPRITE_NONE;
    }
}

void AddBagVisualSprite(u8 bagPocketId)
{
    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_BAG];
    *spriteId = CreateSprite(&sBagSpriteTemplate, 68, 66, 0);
    SetBagVisualPocketId(bagPocketId, FALSE);
}

#define sPocketId data[0]

void SetBagVisualPocketId(u8 bagPocketId, bool8 isSwitchingPockets)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_BAG]];
    if (isSwitchingPockets)
    {
        sprite->y2 = -5;
        sprite->callback = SpriteCB_BagVisualSwitchingPockets;
        sprite->sPocketId = bagPocketId;
        StartSpriteAnim(sprite, POCKET_DUMMY);
    }
    else
    {
        StartSpriteAnim(sprite, bagPocketId);
    }
}

static void SpriteCB_BagVisualSwitchingPockets(struct Sprite *sprite)
{
    if (sprite->y2 != 0)
    {
        sprite->y2++;
    }
    else
    {
        StartSpriteAnim(sprite, sprite->sPocketId);
        sprite->callback = SpriteCallbackDummy;
    }
}

#undef sPocketId

void ShakeBagSprite(void)
{
    struct Sprite *sprite = &gSprites[gBagMenu->spriteIds[ITEMMENUSPRITE_BAG]];
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, ANIM_BAG_SHAKE);
        sprite->callback = SpriteCB_ShakeBagSprite;
    }
}

static void SpriteCB_ShakeBagSprite(struct Sprite *sprite)
{
    // Wait for shaking to end
    if (sprite->affineAnimEnded)
    {
        StartSpriteAffineAnim(sprite, ANIM_BAG_NORMAL);
        sprite->callback = SpriteCallbackDummy;
    }
}

void AddSwitchPocketRotatingBallSprite(s16 rotationDirection)
{
    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_BALL];
    LoadSpriteSheet(&sRotatingBallTable);
    LoadSpritePalette(&sRotatingBallPaletteTable);
    *spriteId = CreateSprite(&sRotatingBallSpriteTemplate, 16, 16, 0);
    gSprites[*spriteId].data[0] = rotationDirection;
}

static void UpdateSwitchPocketRotatingBallCoords(struct Sprite *sprite)
{
    sprite->centerToCornerVecX = sprite->data[1] - ((sprite->data[3] + 1) & 1);
    sprite->centerToCornerVecY = sprite->data[1] - ((sprite->data[3] + 1) & 1);
}

static void SpriteCB_SwitchPocketRotatingBallInit(struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
    if (sprite->data[0] == -1)
        sprite->affineAnims = sRotatingBallAnimCmds;
    else
        sprite->affineAnims = sRotatingBallAnimCmds_FullRotation;

    InitSpriteAffineAnim(sprite);
    sprite->data[1] = sprite->centerToCornerVecX;
    sprite->data[1] = sprite->centerToCornerVecY;
    UpdateSwitchPocketRotatingBallCoords(sprite);
    sprite->callback = SpriteCB_SwitchPocketRotatingBallContinue;
}

static void SpriteCB_SwitchPocketRotatingBallContinue(struct Sprite *sprite)
{
    sprite->data[3]++;
    UpdateSwitchPocketRotatingBallCoords(sprite);
    if (sprite->data[3] == 16)
        RemoveBagSprite(ITEMMENUSPRITE_BALL);
}

void AddBagItemIconSprite(u16 itemId, u8 id)
{
    u8 *spriteId = &gBagMenu->spriteIds[id + ITEMMENUSPRITE_ITEM];
    if (*spriteId == SPRITE_NONE)
    {
        u8 iconSpriteId;

        // Either TAG_ITEM_ICON or TAG_ITEM_ICON_ALT
        FreeSpriteTilesByTag(id + TAG_ITEM_ICON);
        FreeSpritePaletteByTag(id + TAG_ITEM_ICON);
        iconSpriteId = AddItemIconSprite(id + TAG_ITEM_ICON, id + TAG_ITEM_ICON, itemId);
        if (iconSpriteId != MAX_SPRITES)
        {
            *spriteId = iconSpriteId;
            gSprites[iconSpriteId].x2 = 55;
            gSprites[iconSpriteId].y2 = 92;
        }
    }
}

void RemoveBagItemIconSprite(u8 id)
{
// BUG: For one frame, the item you scroll to in the Bag menu
// will have an incorrect palette and may be seen as a flicker.
#ifdef BUGFIX
    u8 *spriteId = &gBagMenu->spriteIds[ITEMMENUSPRITE_ITEM];

    if (spriteId[id ^ 1] != SPRITE_NONE)
        gSprites[spriteId[id ^ 1]].invisible = TRUE;

    if (spriteId[id] != SPRITE_NONE)
    {
        DestroySpriteAndFreeResources(&gSprites[spriteId[id]]);
        spriteId[id] = SPRITE_NONE;
    }
#else
    RemoveBagSprite(id + ITEMMENUSPRITE_ITEM);
#endif
}

void CreateItemMenuSwapLine(void)
{
    CreateSwapLineSprites(&gBagMenu->spriteIds[ITEMMENUSPRITE_SWAP_LINE], ITEMMENU_SWAP_LINE_LENGTH);
}

void SetItemMenuSwapLineInvisibility(bool8 invisible)
{
    SetSwapLineSpritesInvisibility(&gBagMenu->spriteIds[ITEMMENUSPRITE_SWAP_LINE], ITEMMENU_SWAP_LINE_LENGTH, invisible);
}

void UpdateItemMenuSwapLinePos(u8 y)
{
    UpdateSwapLineSpritesPos(&gBagMenu->spriteIds[ITEMMENUSPRITE_SWAP_LINE], ITEMMENU_SWAP_LINE_LENGTH | SWAP_LINE_HAS_MARGIN, 120, (y + 1) * 16);
}

static void ArrangeBerryGfx(void *src, void *dest)
{
    u8 i, j;

    memset(dest, 0, 0x800);

    // Create top margin
    dest += 0x100;

    for (i = 0; i < 6; i++)
    {
        // Create left margin
        dest += 0x20;

        // Copy one row of berry's icon
        for (j = 0; j < 6; j++)
        {
            memcpy(dest, src, 0x20);
            dest += 0x20;
            src += 0x20;
        }

        // Create right margin
        if (i != 5)
            dest += 0x20;
    }
}

#define BERRY_SPRITE_SIZE ((64*64)/2) // 0x800

struct BerryDynamicGfx
{
    ALIGNED(4) u8 gfx[BERRY_SPRITE_SIZE];
    struct SpriteFrameImage images[1];
};

static struct BerryDynamicGfx *LoadBerryGfx(u8 berryId)
{
    struct SpritePalette pal;

    pal.data = sBerryPicTable[berryId].pal;
    pal.tag = TAG_BERRY_PIC_PAL + berryId;
    LoadSpritePalette(&pal);
    struct BerryDynamicGfx *gfxAlloced = Alloc(sizeof(struct BerryDynamicGfx));
    void *buffer = malloc_and_decompress(sBerryPicTable[berryId].tiles, NULL);
    ArrangeBerryGfx(buffer, gfxAlloced->gfx);
    Free(buffer);

    return gfxAlloced;
}

static u32 CreateBerrySprite(const struct SpriteTemplate *sprTemplate, u32 berryId, s32 x, s32 y)
{
    u32 spriteId;
    struct BerryDynamicGfx *dynamicGfx = LoadBerryGfx(berryId);
    struct SpriteTemplate newSprTemplate = *sprTemplate;

    newSprTemplate.paletteTag += berryId;
    newSprTemplate.images = dynamicGfx->images;

    dynamicGfx->images[0].data = dynamicGfx->gfx;
    dynamicGfx->images[0].size = BERRY_SPRITE_SIZE;
    dynamicGfx->images[0].relativeFrames = FALSE;

    spriteId = CreateSprite(&newSprTemplate, x, y, 0);
    StoreWordInTwoHalfwords((u16 *) &gSprites[spriteId].data[BERRY_ICON_GFX_PTR_DATA_ID], (u32) dynamicGfx);
    return spriteId;
}

u32 CreateBerryTagSprite(u32 id, s32 x, s32 y)
{
    return CreateBerrySprite(&sBerryPicSpriteTemplate, id, x, y);
}

// For throwing berries into the Berry Blender
u32 CreateSpinningBerrySprite(u32 berryId, s32 x, s32 y, bool32 startAffine)
{
    u32 spriteId = CreateBerrySprite(&sBerryPicRotatingSpriteTemplate, berryId, x, y);
    if (startAffine)
        StartSpriteAffineAnim(&gSprites[spriteId], 1);

    return spriteId;
}

void DestroyBerryIconSprite(u32 spriteId, u32 berryId, bool32 freePal)
{
    DestroyBerryIconSpritePtr(&gSprites[spriteId], berryId, freePal);
}

void DestroyBerryIconSpritePtr(struct Sprite *sprite, u32 berryId, bool32 freePal)
{
    u32 gfxBuffer;

    LoadWordFromTwoHalfwords((u16 *) &sprite->data[BERRY_ICON_GFX_PTR_DATA_ID], &gfxBuffer);
    Free((void *)gfxBuffer);
    DestroySprite(sprite);
    if (freePal)
        FreeBerryIconSpritePalette(berryId);
}

void FreeBerryIconSpritePalette(u32 berryId)
{
    FreeSpritePaletteByTag(TAG_BERRY_PIC_PAL + berryId);
}

u8 CreateBerryFlavorCircleSprite(s16 x)
{
    return CreateSprite(&sBerryCheckCircleSpriteTemplate, x, 116, 0);
}

static const u8 sPocketIconXPositions[POCKETS_COUNT] = {
    [POCKET_ITEMS]      = 25,
    [POCKET_POKE_BALLS] = 50,
    [POCKET_TM_HM]      = 73,
    [POCKET_BERRIES]    = 41,
    [POCKET_KEY_ITEMS]  = 64,
};

static const u8 sPocketIconYPositions[POCKETS_COUNT] = {
    [POCKET_ITEMS]      = 38,
    [POCKET_POKE_BALLS] = 38,
    [POCKET_TM_HM]      = 38,
    [POCKET_BERRIES]    = 56,
    [POCKET_KEY_ITEMS]  = 56,
};

static const u8 sPocketIconSpriteIndices[POCKETS_COUNT] = {
    [POCKET_ITEMS]      = ITEMMENUSPRITE_POCKET_ICON_ITEMS,
    [POCKET_POKE_BALLS] = ITEMMENUSPRITE_POCKET_ICON_BALLS,
    [POCKET_TM_HM]      = ITEMMENUSPRITE_POCKET_ICON_TMS,
    [POCKET_BERRIES]    = ITEMMENUSPRITE_POCKET_ICON_BERRIES,
    [POCKET_KEY_ITEMS]  = ITEMMENUSPRITE_POCKET_ICON_KEYITEMS,
};

void AddPocketIconSprites(u8 selectedPocket)
{
    u8 i;
    u8 spriteId;
    u8 normalPalNum = IndexOfSpritePaletteTag(TAG_POCKET_ICON_PAL_NORMAL);
    u8 selectedPalNum = IndexOfSpritePaletteTag(TAG_POCKET_ICON_PAL_SELECTED);

    for (i = 0; i < POCKETS_COUNT; i++)
    {
        spriteId = CreateSprite(&sPocketIconSpriteTemplate, sPocketIconXPositions[i], sPocketIconYPositions[i], 0);
        if (spriteId != MAX_SPRITES)
        {
            gBagMenu->spriteIds[sPocketIconSpriteIndices[i]] = spriteId;
            StartSpriteAnim(&gSprites[spriteId], i);
            if (i == selectedPocket)
                gSprites[spriteId].oam.paletteNum = selectedPalNum;
            else
                gSprites[spriteId].oam.paletteNum = normalPalNum;
        }
    }
}

void SetPocketIconSelected(u8 selectedPocket)
{
    u8 i;
    u8 normalPalNum = IndexOfSpritePaletteTag(TAG_POCKET_ICON_PAL_NORMAL);
    u8 selectedPalNum = IndexOfSpritePaletteTag(TAG_POCKET_ICON_PAL_SELECTED);

    for (i = 0; i < POCKETS_COUNT; i++)
    {
        u8 spriteId = gBagMenu->spriteIds[sPocketIconSpriteIndices[i]];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        {
            if (i == selectedPocket)
            {
                gSprites[spriteId].oam.paletteNum = selectedPalNum;
                StartSpriteAffineAnim(&gSprites[spriteId], ANIM_POCKET_ICON_ROCK);
            }
            else
            {
                gSprites[spriteId].oam.paletteNum = normalPalNum;
                StartSpriteAffineAnim(&gSprites[spriteId], ANIM_POCKET_ICON_NORMAL);
            }
        }
    }
}

void RemovePocketIconSprites(void)
{
    u8 i;
    for (i = 0; i < POCKETS_COUNT; i++)
    {
        u8 spriteId = gBagMenu->spriteIds[sPocketIconSpriteIndices[i]];
        if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        {
            DestroySprite(&gSprites[spriteId]);
            gBagMenu->spriteIds[sPocketIconSpriteIndices[i]] = SPRITE_NONE;
        }
    }
}

#define POCKET_ARROW_LEFT_X   13
#define POCKET_ARROW_RIGHT_X  83
#define POCKET_ARROW_Y        13

#define sArrowFrequency data[0]
#define sArrowSinePos   data[1]

static void SpriteCB_PocketSwitchArrowBounce(struct Sprite *sprite)
{
    sprite->x2 = (gSineTable[(u8)(sprite->sArrowSinePos)] * 2) / 256;
    sprite->sArrowSinePos += sprite->sArrowFrequency;
}

#undef sArrowFrequency
#undef sArrowSinePos

void AddPocketSwitchArrowSprites(void)
{
    u8 spriteId;

    if (GetSpriteTileStartByTag(TAG_POCKET_SWITCH_ARROW) == 0xFFFF)
    {
        LoadSpriteSheet(&sPocketSwitchArrowSpriteSheet);
        LoadSpritePalette(&sPocketSwitchArrowPalette);
    }

    spriteId = CreateSprite(&sPocketSwitchArrowSpriteTemplate, POCKET_ARROW_LEFT_X, POCKET_ARROW_Y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gBagMenu->spriteIds[ITEMMENUSPRITE_ARROW_LEFT] = spriteId;
        gSprites[spriteId].data[0] = 8;
        gSprites[spriteId].data[1] = 0;
    }

    spriteId = CreateSprite(&sPocketSwitchArrowSpriteTemplate, POCKET_ARROW_RIGHT_X, POCKET_ARROW_Y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gBagMenu->spriteIds[ITEMMENUSPRITE_ARROW_RIGHT] = spriteId;
        gSprites[spriteId].hFlip = TRUE;
        gSprites[spriteId].data[0] = -8;
        gSprites[spriteId].data[1] = 0;
    }
}

void RemovePocketSwitchArrowSprites(void)
{
    u8 spriteId;

    spriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ARROW_LEFT];
    if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
    {
        DestroySprite(&gSprites[spriteId]);
        gBagMenu->spriteIds[ITEMMENUSPRITE_ARROW_LEFT] = SPRITE_NONE;
    }

    spriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_ARROW_RIGHT];
    if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
    {
        DestroySprite(&gSprites[spriteId]);
        gBagMenu->spriteIds[ITEMMENUSPRITE_ARROW_RIGHT] = SPRITE_NONE;
    }
}

#define SCROLL_ARROW_X        172
#define SCROLL_ARROW_UP_Y     14
#define SCROLL_ARROW_DOWN_Y   150

#define sScrollFrequency data[0]
#define sScrollSinePos   data[1]

static void SpriteCB_ScrollArrowBounce(struct Sprite *sprite)
{
    // Vertical bounce using y2
    sprite->y2 = (gSineTable[(u8)(sprite->sScrollSinePos)] * 2) / 256;
    sprite->sScrollSinePos += sprite->sScrollFrequency;
}

#undef sScrollFrequency
#undef sScrollSinePos

void AddScrollArrowSprites(void)
{
    u8 spriteId;

    if (GetSpriteTileStartByTag(TAG_SCROLL_ARROW_UP) == 0xFFFF)
    {
        LoadSpriteSheet(&sScrollArrowUpSpriteSheet);
        LoadSpriteSheet(&sScrollArrowDownSpriteSheet);
        LoadSpritePalette(&sScrollArrowPalette);
    }

    spriteId = CreateSprite(&sScrollArrowUpSpriteTemplate, SCROLL_ARROW_X, SCROLL_ARROW_UP_Y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_UP] = spriteId;
        gSprites[spriteId].data[0] = -8;
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = TRUE;
    }

    spriteId = CreateSprite(&sScrollArrowDownSpriteTemplate, SCROLL_ARROW_X, SCROLL_ARROW_DOWN_Y, 0);
    if (spriteId != MAX_SPRITES)
    {
        gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_DOWN] = spriteId;
        gSprites[spriteId].data[0] = 8;
        gSprites[spriteId].data[1] = 0;
        gSprites[spriteId].invisible = TRUE;
    }
}

void RemoveScrollArrowSprites(void)
{
    u8 spriteId;

    spriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_UP];
    if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
    {
        DestroySprite(&gSprites[spriteId]);
        gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_UP] = SPRITE_NONE;
    }

    spriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_DOWN];
    if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
    {
        DestroySprite(&gSprites[spriteId]);
        gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_DOWN] = SPRITE_NONE;
    }

    FreeSpriteTilesByTag(TAG_SCROLL_ARROW_UP);
    FreeSpriteTilesByTag(TAG_SCROLL_ARROW_DOWN);
    FreeSpritePaletteByTag(TAG_SCROLL_ARROW_PAL);
}

void UpdateScrollArrowVisibility(void)
{
    u8 pocket = gBagPosition.pocket;
    u16 scrollPos = gBagPosition.scrollPosition[pocket];
    u8 numItems = gBagMenu->numItemStacks[pocket];
    u8 numShown = gBagMenu->numShownItems[pocket];
    u8 spriteId;

    spriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_UP];
    if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        gSprites[spriteId].invisible = (scrollPos == 0);

    spriteId = gBagMenu->spriteIds[ITEMMENUSPRITE_SCROLL_ARROW_DOWN];
    if (spriteId != SPRITE_NONE && spriteId < MAX_SPRITES)
        gSprites[spriteId].invisible = (scrollPos + numShown >= numItems);
}
