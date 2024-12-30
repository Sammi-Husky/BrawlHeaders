#pragma once

#include <StaticAssert.h>

class soInfo {
public:
    virtual ~soInfo() { }
};
static_assert(sizeof(soInfo) == 0x4, "Class has the wrong size!");
