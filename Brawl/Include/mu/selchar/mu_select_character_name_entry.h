#pragma once

#include <StaticAssert.h>
#include <types.h>

class muSelctChrNameEntry {
public:
    char _0[0x94];
};

static_assert(sizeof(muSelctChrNameEntry) == 0x94, "Wrong size for class!");