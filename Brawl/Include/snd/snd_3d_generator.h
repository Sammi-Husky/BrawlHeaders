#pragma once

#include <snd/snd_3d_actor.h>
#include <snd/snd_id.h>
#include <types.h>

class snd3DGenerator {
    Snd3dActor* m_sndActor;

public:
    snd3DGenerator();
    virtual ~snd3DGenerator();

    void playSE(SndID sndID, int unk, int unk2, int unk4);
    void setPos(Vec3f* pos);
};
