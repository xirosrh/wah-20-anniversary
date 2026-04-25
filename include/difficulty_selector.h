#ifndef GUARD_DIFFICULTY_SELECTOR_H
#define GUARD_DIFFICULTY_SELECTOR_H

#include "constants/difficulty.h"

void StartDifficultySelectorFromField_CB2(void);
void DifficultySelector_SetupUiForIntro(void);
void DifficultySelector_RefreshPanel(enum DifficultyLevel level);
bool8 DifficultySelector_HandleInputIntro(u8 taskId);

#endif // GUARD_DIFFICULTY_SELECTOR_H
