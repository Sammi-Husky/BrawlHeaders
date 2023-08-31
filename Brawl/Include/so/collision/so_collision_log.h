#pragma once

#include <types.h>
#include <mt/mt_vector.h>

class soCollisionLog {
public:
    char _spacer[12];
    int m_taskId;
    Vec3f m_pos;
    short m_life;
    short m_30;
    s8 m_teamId;
    char _33;
    u8 m_category;
    char _35;
    u8 m_collsionIndex;
    u8 m_damageIndex;
    char _38;
    bool m_isAbsolute;
    char _40;
    char _41;
    char _42;
    char _43[1];

}; // size 44
static_assert(sizeof(soCollisionLog) == 44, "Class is wrong size!"); // size 44