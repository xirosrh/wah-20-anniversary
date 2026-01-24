#include "m4a.h"

#define NUM_TRACKS_BGM 16
#define NUM_TRACKS_SE1 3
#define NUM_TRACKS_SE2 9
#define NUM_TRACKS_SE3 1

/*static */struct MusicPlayerTrack gMPlayTrack_BGM[NUM_TRACKS_BGM];
/*static */struct MusicPlayerTrack gMPlayTrack_SE1[NUM_TRACKS_SE1];
/*static */struct MusicPlayerTrack gMPlayTrack_SE2[NUM_TRACKS_SE2];
/*static */struct MusicPlayerTrack gMPlayTrack_SE3[NUM_TRACKS_SE3];

const struct MusicPlayer gMPlayTable[] = 
{
    [MUSIC_PLAYER_BGM] = {&gMPlayInfo_BGM, gMPlayTrack_BGM, NUM_TRACKS_BGM, 0},
    [MUSIC_PLAYER_SE1] = {&gMPlayInfo_SE1, gMPlayTrack_SE1, NUM_TRACKS_SE1, 1},
    [MUSIC_PLAYER_SE2] = {&gMPlayInfo_SE2, gMPlayTrack_SE2, NUM_TRACKS_SE2, 1},
    [MUSIC_PLAYER_SE3] = {&gMPlayInfo_SE3, gMPlayTrack_SE3, NUM_TRACKS_SE3, 0}
};
