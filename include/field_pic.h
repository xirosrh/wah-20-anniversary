#ifndef GUARD_FIELD_PIC_H
#define GUARD_FIELD_PIC_H

void LoadFieldPic(u32 id, s16 x, s16 y, bool8 apply_weather);
u8 DoLoadFieldPic(u32 id, s16 x, s16 y, bool8 loadOnFadedBuffer, bool8 apply_weather);
void HideFieldPic(void);
void ShowFieldPic(void);
void DestroyFieldPic(u32 id, u32 spriteId);

#endif //GUARD_FIELD_PIC_H