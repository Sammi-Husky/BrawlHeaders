#pragma once

#include <types.h>
#include <mt/mt_vector.h>
#include <StaticAssert.h>

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

    STATIC_CHECK(sizeof(stPositions) == 100)
};