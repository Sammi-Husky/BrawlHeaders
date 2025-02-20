#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

class cmQuake {
public:
    enum Kind {
        None = 0x0,
        M = 0x1,
        Middle = 0x1,
        S_Half = 0x2,
        Small_Hf = 0x2,
        S = 0x3,
        Small = 0x3,
        L = 0x4,
        Large = 0x4,
        XL = 0x5,
        More_Large = 0x5,
    };

    char _[0x274];
};
static_assert(sizeof(cmQuake) == 0x274, "Class is wrong size!");

void cmReqQuake(cmQuake::Kind quakeKind, Vec3f* offset);
void cmRemoveQuake(int index);