#pragma once

#include <StaticAssert.h>
#include <types.h>

struct soLinkConnection {
    char _[0x34];

    enum Attribute {
        Attribute_Reference_Parent_Stop = 0x0,
        Attribute_Reference_Parent_Shake = 0x1,
        Attribute_Reference_Parent_Scale = 0x2,

        Attribute_Reference_Parent_Visibility = 0x7,

        Attribute_Reference_Parent_Power_Up = 0xA, // glow
    };
};