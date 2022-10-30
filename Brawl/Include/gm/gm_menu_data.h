#pragma once

#include <StaticAssert.h>
#include <types.h>

struct gmMenuData {
    char _0[0x18];       // 0x0
    u8 m_spMeleeOption1; // 0x18
    u8 m_spMeleeOption2; // 0x19
    u8 m_spMeleeOption3; // 0x1A
    u8 m_spMeleeOption4; // 0x1B
    u8 m_spMeleeOption5; // 0x1C
    u8 m_spMeleeOption6; // 0x1D
    u8 m_spMeleeOption7; // 0x1E
    u8 m_spMeleeOption8; // 0x1F
    char _1[0x68];       // 0x20

    STATIC_CHECK(sizeof(gmMenuData) == 0x88)
};
