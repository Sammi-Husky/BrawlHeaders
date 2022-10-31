#pragma once

#include <types.h>

struct soAreaData {
    char field0_0x0;
    char field1_0x1;
    short field2_0x2;
    int field3_0x4;
    int field4_0x8;
    int field5_0xc;
    float field6_0x10;
    float field7_0x14;
    float field8_0x18;
    float field9_0x1c;
};

struct soAreaInit {
    soAreaData* data;
    int field_0x4;
};
