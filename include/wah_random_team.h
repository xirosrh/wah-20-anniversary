#ifndef GUARD_WAH_RANDOM_TEAM_H
#define GUARD_WAH_RANDOM_TEAM_H

bool8 WahRandomTeam_BackupParty(void);
bool8 WahRandomTeam_GenerateParty(void);
bool8 WahRandomTeam_BackupAndGenerate(void);
bool8 WahRandomTeam_RestoreAndClear(void);
bool8 WahRandomTeam_HasBackup(void);
bool8 WahRandomTeam_IsActive(void);

void Special_StartWahRandomTeam(void);

#endif // GUARD_WAH_RANDOM_TEAM_H
