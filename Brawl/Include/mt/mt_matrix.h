#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

class Matrix {
private:
    float m_elements[3][4];

public:
    inline float& operator()(int row, int col) {
        return m_elements[row][col];
    }
    inline float operator()(int row, int col) const { // for const objects
        return m_elements[row][col];
    }

    void setIdentity();
    void getRotate(Vec3f* outRot);
};
static_assert(sizeof(Matrix) == 48, "Class is wrong size!");