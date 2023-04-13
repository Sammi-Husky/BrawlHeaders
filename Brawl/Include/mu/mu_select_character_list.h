#pragma once

#include <StaticAssert.h>
#include <types.h>

class muSelctChrList {
public:
    char _0[0x160];
};

static_assert(sizeof(muSelctChrList) == 0x160, "Wrong size for class!");