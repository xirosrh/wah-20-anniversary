#ifndef GUARD_ACHIEVEMENTS_H
#define GUARD_ACHIEVEMENTS_H


u8 Achievement_GetCount(void);
const u8 *Achievement_GetTitle(u8 index);
const u8 *Achievement_GetDescription(u8 index);
bool8 Achievement_IsComplete(u8 index);

#endif // GUARD_ACHIEVEMENTS_H
