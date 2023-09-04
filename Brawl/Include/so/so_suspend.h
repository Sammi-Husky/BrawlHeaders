#pragma once

#include <types.h>

class soSuspendable {
    char _0;
};
static_assert(sizeof(soSuspendable) == 1, "Class is wrong size!");