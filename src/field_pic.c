#include "global.h"
#include "event_data.h"
#include "decompress.h"
#include "field_effect.h"
#include "field_pic.h"
#include "field_weather.h"
#include "sprite.h"
#include "constants/field_pics.h"

#define TAG_PIC 0x3333

struct Pic
{
    const u32 *gfx;
    const u16 *pal;
    u8 shape;
    u8 size;
    const union AnimCmd *const *anims;
    SpriteCallback callback;
};

static const union AnimCmd sAnimCmdCutAttack[] =
{
    ANIMCMD_FRAME(0, 10),
    ANIMCMD_FRAME(16, 10),
    ANIMCMD_FRAME(32, 10),
    ANIMCMD_FRAME(64, 10),
    ANIMCMD_END,
};

static const union AnimCmd *const sAnimsCutAttack[] =
{
    sAnimCmdCutAttack
};



static const u32 sPicCutAttack[] = INCBIN_U32("graphics/field_pics/cut.4bpp.lz");
static const u16 sCutAttackPal[] = INCBIN_U16("graphics/field_pics/cut.gbapal");

static const struct Pic sPics[] =
{
    [FP_CUT_ATTACK] = {sPicCutAttack, sCutAttackPal, SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), sAnimsCutAttack},
};

static EWRAM_DATA u8 sLastPicId = 0;

void LoadFieldPicSpecial()
{
    u32 id = VarGet(gSpecialVar_0x8004);
    s16 x = (s16)(VarGet(gSpecialVar_0x8005));
    s16 y = (s16)(VarGet(gSpecialVar_0x8006));
    bool8 applyWeather = VarGet(gSpecialVar_0x8007);
    u8 lastPicId = DoLoadFieldPic(id, x, y, FALSE, applyWeather);
    gSpecialVar_Result = lastPicId;
}

void LoadFieldPic(u32 id, s16 x, s16 y, bool8 applyWeather)
{
    DoLoadFieldPic(id, x, y, FALSE, applyWeather);
}

u8 DoLoadFieldPic(u32 id, s16 x, s16 y, bool8 loadOnFadedBuffer, bool8 applyWeather)
{
    u8 paletteNum;
    struct CompressedSpriteSheet sheet;
    struct SpritePalette palSheet;
    struct SpriteTemplate spriteTempl;
    struct OamData oam = {0};

    gSpecialVar_Result = 0xFF;

    if (id >= ARRAY_COUNT(sPics))
        return 0;

    if (GetSpriteTileStartByTag(TAG_PIC + id) == 0xFFFF)
    {
        const u8 *gfxPtr = (const u8*)(sPics[id].gfx); // To get the size, the pointer needs to be casted to u8.

        sheet.tag = TAG_PIC + id;
        sheet.data = sPics[id].gfx;
        sheet.size = (gfxPtr[3] << 16) | (gfxPtr[2] << 8) | gfxPtr[1];
        
        LoadCompressedSpriteSheet(&sheet);
    }

    paletteNum = IndexOfSpritePaletteTag(TAG_PIC + id);
    if (paletteNum == 0xFF)
    {
        palSheet.tag = TAG_PIC + id;
        palSheet.data = sPics[id].pal;
        paletteNum = LoadSpritePalette(&palSheet);
    }
    if(applyWeather) {
        UpdateSpritePaletteWithWeather(paletteNum, FALSE);
    }
    oam.size = sPics[id].size;
    oam.shape = sPics[id].shape;
    oam.priority = 1;

    spriteTempl = gDummySpriteTemplate;
    spriteTempl.oam = &oam;
    spriteTempl.paletteTag = spriteTempl.tileTag = TAG_PIC + id;
    if (sPics[id].callback)
        spriteTempl.callback = sPics[id].callback;
    if (sPics[id].anims)
        spriteTempl.anims = sPics[id].anims;
    sLastPicId = CreateSprite(&spriteTempl, x, y, 0);
    if (sLastPicId == MAX_SPRITES)
        return 0;

   return sLastPicId;
}

void HideFieldPic(void)
{
    u32 spriteId = VarGet(gSpecialVar_0x8004);

    if (spriteId == 0xFF)
        gSprites[sLastPicId].invisible = TRUE;
    else
        gSprites[spriteId].invisible = TRUE;
}

void ShowFieldPic(void)
{
    u32 spriteId = VarGet(gSpecialVar_0x8004);

    if (spriteId == 0xFF)
        gSprites[sLastPicId].invisible = FALSE;
    else
        gSprites[spriteId].invisible = FALSE;
}

void ChangeFieldPicFrame(void)
{
    u32 num = VarGet(gSpecialVar_0x8004);
    u32 spriteId = VarGet(gSpecialVar_0x8005);

    if (spriteId == 0xFF)
        StartSpriteAnim(&gSprites[sLastPicId], num);
    else
        StartSpriteAnim(&gSprites[spriteId], num);
}

void DestroyFieldPicSpecial(void)
{
    u32 id = VarGet(gSpecialVar_0x8004);
    u32 spriteId = VarGet(gSpecialVar_0x8005);
    DestroyFieldPic(id, spriteId);
}

void DestroyFieldPic(u32 id, u32 spriteId)
{
    if (spriteId == 0xFF)
        DestroySprite(&gSprites[sLastPicId]);
    else
        DestroySprite(&gSprites[spriteId]);

    if (id != 0xFF)
    {
        FreeSpritePaletteByTag(TAG_PIC + id);
        FreeSpriteTilesByTag(TAG_PIC + id);
    }
}
