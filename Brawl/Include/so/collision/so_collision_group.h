#pragma once

#include <StaticAssert.h>
#include <types.h>

class soCollisionGroup {
    char _spacer[120];
};
static_assert(sizeof(soCollisionGroup) == 120, "Class is wrong size!");
