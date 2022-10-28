#pragma once

#include <snd/snd_id.h>

class snd3DGenerator {
    void* sound3DActor;

    public:
        snd3DGenerator();
        virtual ~snd3DGenerator();

        void playSE(SndID sndID, int unk, int unk2, int unk4);
};
