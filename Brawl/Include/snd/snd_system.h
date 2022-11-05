#pragma once

#include <types.h>
#include <snd/snd_id.h>

class sndSystem {
private:
public:
    void playSE(SndID sndID, int unk, int unk2, int unk3, int unk4);
    void setBGMVol(bool setImmediately, float volume);
};

extern sndSystem* g_sndSystem;