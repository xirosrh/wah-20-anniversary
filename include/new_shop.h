#ifndef GUARD_NEW_SHOP_H
#define GUARD_NEW_SHOP_H

#ifdef MUDSKIP_SHOP_UI
void NewShop_CreatePokemartMenu(const u16 *);
void NewShop_CreateDecorationShop1Menu(const u16 *);
void NewShop_CreateDecorationShop2Menu(const u16 *);
void CB2_ExitSellNewShopMenu(void);

#ifdef MUDSKIP_OUTFIT_SYSTEM
void NewShop_CreateOutfitShopMenu(const u16 *);
#endif // MUDSKIP_OUTFIT_SYSTEM

void NewShop_CreateVariablePokemartMenu(const u16 *);
void NewShop_CreateCoinPokemartMenu(const u16 *);
void NewShop_CreatePointsPokemartMenu(const u16 *);
void OpenWahRoomsSharedMart(void);

void FormatTextByWidth(u8 *result, s32 maxWidth, u8 fontId, const u8 *str, s16 letterSpacing);

#endif // MUDSKIP_SHOP_UI

#endif // GUARD_NEW_SHOP_H
