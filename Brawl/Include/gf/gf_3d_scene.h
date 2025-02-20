#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <types.h>
#include <nw4r/g3d/g3d_anmscn.h>

class gfSceneRoot : public gfTask {
public:

    char _64[20];
    nw4r::g3d::AnmScnRes* m_anmScnRes;
    char _88[12];
    union TransformFlag {
        u32 m_mask;
        struct {
            bool m_flag31 : 1;      // 0x80000000
            bool m_flag30 : 1;      // 0x40000000
            bool m_flag29 : 1;      // 0x20000000
            bool m_flag28 : 1;      // 0x10000000
            bool m_flag27 : 1;      // 0x8000000
            bool m_flag26 : 1;      // 0x4000000
            bool m_flag25 : 1;       // 0x2000000
            bool m_reverseLr : 1;       // 0x1000000
            bool m_flag23 : 1;       // 0x800000
            bool m_flag22 : 1;       // 0x400000
            bool m_flag21 : 1;       // 0x200000
            bool m_flag20 : 1;       // 0x100000
            bool m_flag19 : 1;       // 0x80000
            bool m_flag18 : 1;       // 0x40000
            bool m_flag17 : 1;       // 0x20000
            bool m_flag16 : 1;       // 0x10000
            bool m_flag15 : 1;      // 0x8000
            bool m_flag14 : 1;      // 0x4000
            bool m_flag13 : 1;      // 0x2000
            bool m_flag12 : 1;      // 0x1000
            bool m_flag11 : 1;      // 0x800
            bool m_flag10 : 1;      // 0x400
            bool m_flag9 : 1;       // 0x200
            bool m_flag8 : 1;       // 0x100
            bool m_flag7 : 1;       // 0x80
            bool m_flag6 : 1;       // 0x40
            bool m_flag5 : 1;       // 0x20
            bool m_flag4 : 1;       // 0x10
            bool m_flag3 : 1;       // 0x8
            bool m_flag2 : 1;       // 0x4
            bool m_flag1 : 1;       // 0x2
            bool m_flag0 : 1;       // 0x1
        };
    } m_transformFlag;

    char _104[1044];
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