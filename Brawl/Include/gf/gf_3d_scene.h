#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <types.h>
#include <nw4r/g3d/g3d_anmscn.h>

class gfSceneRoot : public gfTask {
public:

    char _64[20];
    nw4r::g3d::AnmScnRes* m_anmScnRes;
    char _88[1060];
    float m_shadowPitch;
    float m_shadowYaw;
    float m_1156;
    char _1160[132];

    virtual void processAnim();
    virtual void processFixCamera();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void renderDebug();
    virtual ~gfSceneRoot();

    void setCurrentFrame(float);
    void removeResAnmScn();
};
static_assert(sizeof(gfSceneRoot) == 1292, "Class is wrong size!");

extern gfSceneRoot* g_gfSceneRoot;