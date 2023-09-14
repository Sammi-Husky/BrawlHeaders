#pragma once

#include <types.h>

union ipButton {
    struct {
        unsigned int m_bits;
    };

    struct {
        unsigned short : 16;
        bool m_tapJump : 1;
        bool m_rightTaunt : 1;
        bool m_leftTaunt : 1;
        bool m_downTaunt : 1;
        bool m_sideTaunt : 1;
        bool m_upTaunt : 1;
        bool _6 : 1;
        bool m_cStick : 1;
        bool _8 : 1;
        bool _9 : 1;
        bool _10 : 1;
        bool _11 : 1;
        bool m_shield : 1;
        bool m_jump : 1;
        bool m_special : 1;
        bool m_attack : 1;
    };
};
static_assert(sizeof(ipButton) == 4, "Class is wrong size!");