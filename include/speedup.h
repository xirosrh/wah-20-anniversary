#ifndef GUARD_SPEEDUP_H
#define GUARD_SPEEDUP_H

#include "global.h"
#include "gba/types.h"

#define MAX_SPEEDUP 10

void StartSpeedup(void);
void StopSpeedup(void);
void CheckSpeedupControls(void);
bool32 SpeedupShouldSkip(void);
bool32 SpeedupIsPaused(void);

#endif // GUARD_SPEEDUP_H
