#pragma once

#include <types.h>

union ipButton {
    struct {
        unsigned int m_bits;
    };

    struct {
        unsigned short : 16;
        bool m_flickJump : 1;
        bool m_appealSR : 1;
        bool m_appealSL : 1;
        bool m_appealLw : 1;
        bool m_appealS : 1;
        bool m_appealHi : 1;
        bool _6 : 1;
        bool m_cStick : 1;
        bool _8 : 1;
        bool _9 : 1;
        bool _10 : 1;
        bool _11 : 1;
        bool m_guard : 1;
        bool m_jump : 1;
        bool m_special : 1;
        bool m_attack : 1;
    };

    enum buttonBits
    {
        _FLICK_JUMP = 0x8000,
        _APPEAL_SR = 0x4000,
        _APPEAL_SL = 0x2000,
        _APPEAL_LW = 0x1000,
        _APPEAL_S = 0x0800,
        _APPEAL_HI = 0x0400,
        __6 = 0x0200,
        _C_STICK = 0x0100,
        __8 = 0x0080,
        __9 = 0x0040,
        __10 = 0x0020,
        __11 = 0x0010,
        _GUARD = 0x0008,
        _JUMP = 0x0004,
        _SPECIAL = 0x0002,
        _ATTACK = 0x0001,
    };

};
static_assert(sizeof(ipButton) == 4, "Class is wrong size!");