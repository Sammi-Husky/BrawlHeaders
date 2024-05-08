#pragma once

#include <StaticAssert.h>
#include <nw4r/g3d/g3d_anmchr.h>
#include <types.h>

struct soAnimChr {
    nw4r::g3d::AnmObjChrRes* m_anmChrRes;
    // 0x4
    float m_animFrame;
    // 0x8
    float m_frame_;
    // 0xc
    float m_frameSpeedModifier;
    // 0x10
    float m_rate;

    float m_frame;

    bool m_loopFlag : 1;
    bool _24_6 : 1;
    bool _24_5 : 1;
    bool _24_4 : 1;
    bool _24_3 : 1;
    bool _24_2 : 1;
    bool _24_1 : 1;
    bool _24_0 : 1;

    char _pad[3];
};
static_assert(sizeof(soAnimChr) == 28, "Class is wrong size!");
