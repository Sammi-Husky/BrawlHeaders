#pragma once

#include <types.h>
#include <StaticAssert.h>

class Matrix {
    char _spacer[48];

public:
    void getRotate(Vec3f* outRot);

    STATIC_CHECK(sizeof(Matrix) == 48)
};