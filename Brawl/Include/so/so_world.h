#pragma once

#include <types.h>
#include <StaticAssert.h>

class soWorld {
public:
    float m_gravityUp;
    float m_gravityDown;
    float m_8;
    u8 m_12;
    u8 m_13;
    char _14[2];

    STATIC_CHECK(sizeof(soWorld) == 0x10)
};

extern soWorld* g_soWorld;
