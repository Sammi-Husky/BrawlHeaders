#pragma once

#include <types.h>
#include <StaticAssert.h>

struct grCollisionLine {
    // 0
    short m_point0Index;
    // 2
    short m_point1Index;
    // 4
    char _spacer[10];
    // 14
    short m_14;
    // 16
    char _spacer1[1];
    // 17
    char m_materialType;
    // 18
    char _pad[2];

    STATIC_CHECK(sizeof(grCollisionLine) == 20)

};