#pragma once

#include <StaticAssert.h>
#include <gf/gf_callback.h>
#include <types.h>

class gfApplication {
public:
    u8 unk0[0xE4];
    int m_e4;
    u8 unkE8[0x2C];
    gfCallBackList m_114;
    u8 unk118[0x8];
};
static_assert(sizeof(gfApplication) == 0x120, "Class is wrong size!");

extern gfApplication* g_gfGameApplication;
