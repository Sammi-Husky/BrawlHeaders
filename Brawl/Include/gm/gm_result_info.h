#pragma once

#include <StaticAssert.h>
#include <types.h>

struct gmResultInfo {
    char _spacer[0x1388]; // 0x00

    STATIC_CHECK(sizeof(gmResultInfo) == 0x1388)
};

namespace static_checks {

} // namespace static_checks
