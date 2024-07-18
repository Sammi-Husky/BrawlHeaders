#pragma once

#include <types.h>
#include <mt/mt_vector.h>

enum DeadType {
    Dead_None = -1,
    Dead_Top = 0,
    Dead_Bottom = 1,
    Dead_Left = 2,
    Dead_Right = 3,
};

namespace soGroundUtil {
    DeadType checkDeadArea(Vec3f* pos, float, float);
}