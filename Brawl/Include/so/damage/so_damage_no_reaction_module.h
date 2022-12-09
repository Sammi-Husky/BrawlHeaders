#pragma once

#include <types.h>
#include <StaticAssert.h>

class soDamageNoReactionModule {
    int m_mode;
    int m_modeStatus;
    char _8[8];
    int m_modeStatus2nd;
    char _20[8];
    bool m_isModeAlways;
    bool m_isModePerfect;
    char _30[2];

    STATIC_CHECK(sizeof(soDamageNoReactionModule) == 32)
};