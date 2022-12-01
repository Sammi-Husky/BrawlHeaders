#pragma once

#include <types.h>
#include <mt/mt_vector.h>

struct soAreaData {
    char field0_0x0;
    char field1_0x1;
    short field2_0x2;
    int field3_0x4;
    int field4_0x8;
    int field5_0xc;
    Vec2f m_pos;
    Vec2f m_range;
};

struct soAreaInit {
    soAreaData* data;
    int field_0x4;
};
