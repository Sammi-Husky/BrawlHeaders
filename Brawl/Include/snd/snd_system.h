#pragma once

#include <types.h>
#include <snd/snd_id.h>

class sndSystem {
    char _0[0xbd0];
private:
public:
    void playSE(SndID sndID, int unk, int unk2, int unk3, int unk4);
    void setBGMVol(bool setImmediately, float volume);

    STATIC_CHECK(sizeof(sndSystem) == 0xbd0)
};

extern sndSystem* g_sndSystem;