#pragma once

#include <StaticAssert.h>
#include <so/collision/so_collision_group.h>
#include <so/so_array.h>
#include <types.h>

class soCollision {
    int m_kind;
    int m_indirectTeam;
    soArray<soCollisionGroup>* m_collisionGroupArray;
    int m_taskId;
    u8 m_category;
    char _17[2];
    bool m_isNoTeam;
    char _20[4];
};
static_assert(sizeof(soCollision) == 24, "Class is wrong size!");
