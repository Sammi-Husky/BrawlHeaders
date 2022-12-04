#pragma once

#include <types.h>
#include <StaticAssert.h>

class soLockable {
    char _spacer[8];

    STATIC_CHECK(sizeof(soLockable) == 8)
};