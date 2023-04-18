#pragma once

#include <StaticAssert.h>
#include <types.h>

struct gmSelCharData {
    char _spacer[0x340]; // 0x00
};
static_assert(sizeof(gmSelCharData) == 0x340, "Class is wrong size!");

namespace static_checks {

} // namespace static_checks
