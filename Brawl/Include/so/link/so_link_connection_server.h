#pragma once

#include <types.h>

struct soLinkConnection {
    char _[0x34];

public:
    enum Attribute {
        Attribute_Reference_Parent_Scale = 0x2,
        Attribute_Reference_Parent_Power_Up = 0xA, // glow
    };
};