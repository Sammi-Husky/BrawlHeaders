#pragma once

#include <snd/snd_id.h>

class sndSystem {
private:
public:
    void playSE(SndID sndID, int unk, int unk2, int unk3, int unk4);
};

extern sndSystem* g_sndSystem;