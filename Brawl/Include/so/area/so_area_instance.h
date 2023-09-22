#pragma once

#include <types.h>

class soAreaInstance {
    char _0[32];

    virtual ~soAreaInstance();
};
static_assert(sizeof(soAreaInstance) == 36, "Class is wrong size!");