#pragma once

#include <types.h>
#include <StaticAssert.h>

class IfPlayer {
    char _0[1492];
    virtual ~IfPlayer();

    STATIC_CHECK(sizeof(IfPlayer) == 1496)

};