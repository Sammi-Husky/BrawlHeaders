#pragma once

#include <mt/mt_vector.h>

class stRange {
public:
    float left;
    float right;
    float top;
    float bottom;
};

class stPositions {
private:
    char _spacer[100];

public:
    float* getDeadRange(stRange* range);
};