#pragma once

#include <StaticAssert.h>
#include <types.h>

struct gmSelCharData {
    char _spacer[0x340]; // 0x00

    STATIC_CHECK(sizeof(gmSelCharData) == 0x340)
};

namespace static_checks {

} // namespace static_checks
