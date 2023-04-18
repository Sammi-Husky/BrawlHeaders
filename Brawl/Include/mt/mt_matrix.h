#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

class Matrix {
    char _spacer[48];

public:
    void getRotate(Vec3f* outRot);
};
static_assert(sizeof(Matrix) == 48, "Class is wrong size!");