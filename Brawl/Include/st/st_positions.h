#pragma once

#include <mt/mt_vector.h>

class stPositions {
private:
    char _spacer[100];

public:
    float* getDeadRange(float range[2][2]);
};