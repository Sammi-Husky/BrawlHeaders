#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

class stRange {
public:
    float m_left;
    float m_right;
    float m_top;
    float m_bottom;
};

class stPositions {
private:
    char _spacer[100];

public:
    float* getDeadRange(stRange* range);
    float* getCameraRange(stRange* range);
};
static_assert(sizeof(stPositions) == 100, "Class is wrong size!");