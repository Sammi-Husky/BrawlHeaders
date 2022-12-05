#pragma once

#include <types.h>
#include <StaticAssert.h>

class soCollisionGroup {
    char _spacer[120];

    STATIC_CHECK(sizeof(soCollisionGroup) == 120)
};


