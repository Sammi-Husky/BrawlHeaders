#pragma once

#include <snd/snd_id.h>
#include <types.h>

class sndSystem {
    char _0[0xbd0];

private:
public:
    int loadSoundGroup(SndGroupID sndGroupId, int, bool isRequest);
    void freeGroup(int heapLevel, int);

    void playSE(SndID sndID, int unk, int unk2, int unk3, int unk4);
    void stopSE(s32 p1, s32 p2);
    void setBGMVol(bool setImmediately, float volume);
    s32 prepareSE(SndID p1, s32 p2, s32 p3);
    void setPan(s32 p1, float p2);
    void startSE(s32 p1, s32 p2, s32 p3);
    bool playBGM(int bgmId, u32 fade, bool);
    int getBGMId();
};
static_assert(sizeof(sndSystem) == 0xbd0, "Class is wrong size!");

extern sndSystem* g_sndSystem;