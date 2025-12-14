#ifndef GUARD_TRAINER_SEE_H
#define GUARD_TRAINER_SEE_H

struct ApproachingTrainer
{
    u8 objectEventId;
    u8 radius; // plus 1
    const u8 *trainerScriptPtr;
    u8 taskId;
};

extern u16 gWhichTrainerToFaceAfterBattle;
extern u8 gPostBattleMovementScript[4];
extern struct ApproachingTrainer gApproachingTrainers[2];
extern u8 gNoOfApproachingTrainers;
extern bool8 gTrainerApproachedPlayer;
extern u8 gApproachingTrainerId;

bool8 CheckForTrainersWantingBattle(void);
void SetBuriedTrainerMovement(struct ObjectEvent *objEvent);
void DoTrainerApproach(void);
void TryPrepareSecondApproachingTrainer(void);
u8 FldEff_ExclamationMarkIcon(void);
u8 FldEff_QuestionMarkIcon(void);
u8 FldEff_HeartIcon(void);
u8 GetCurrentApproachingTrainerObjectEventId(void);
u8 GetChosenApproachingTrainerObjectEventId(u8 arrayId);
void PlayerFaceTrainerAfterBattle(void);
u8 FldEff_DoubleExclMarkIcon(void);
u8 FldEff_XIcon(void);
u8 FldEff_SweatDropIcon(void);
u8 FldEff_ThinkingIcon(void);
u8 FldEff_VersusIcon(void);
u8 FldEff_HappyIcon(void);
u8 FldEff_SleepingIcon(void);
u8 FldEff_SadIcon(void);
u8 FldEff_SmileIcon(void);
u8 FldEff_CryIcon(void);
u8 FldEff_AngryIcon(void);
u8 FldEff_SurpriseIcon(void);
u8 FldEff_VIcon(void);
u8 FldEff_IdeaIcon(void);
u8 FldEff_XdIcon(void);
u8 FldEff_WinkIcon(void);
u8 FldEff_AnnoyedIcon(void);

#endif // GUARD_TRAINER_SEE_H
