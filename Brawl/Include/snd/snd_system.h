#pragma once

#include <snd/snd_id.h>
#include <types.h>

class sndSystem {
    char _0[0xbd0];

private:
public:
    void playSE(SndID sndID, int unk, int unk2, int unk3, int unk4);
    void setBGMVol(bool setImmediately, float volume);
};
static_assert(sizeof(sndSystem) == 0xbd0, "Class is wrong size!");

extern sndSystem* g_sndSystem;