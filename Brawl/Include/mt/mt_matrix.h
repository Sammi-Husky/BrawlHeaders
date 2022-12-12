#pragma once

#include <types.h>
#include <StaticAssert.h>

class Matrix {
    char _spacer[48];

    STATIC_CHECK(sizeof(Matrix) == 48)
};