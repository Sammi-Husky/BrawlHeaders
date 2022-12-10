#pragma once

#include <nw4r/snd/snd_Sound3DActor.h>
#include <snd/snd_id.h>
#include <types.h>

class snd3DGenerator {
    nw4r::snd::Sound3DActor* m_sndActor;

public:
    snd3DGenerator();
    virtual ~snd3DGenerator();

    void playSE(SndID sndID, int unk, int unk2, int unk4);
    void setPos(Vec3f* pos);
};
