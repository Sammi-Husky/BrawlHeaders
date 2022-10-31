#pragma once

#include <types.h>

struct grCollisionLine {
    // 0
    short point0Index;
    // 2
    short point1Index;
    // 4
    char _spacer[12];
    // 16
    char materialType;
};