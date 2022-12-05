#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_array.h>
#include <so/so_collision_group.h>

class soCollision {
    int m_kind;
    int m_indirectTeam;
    soArray<soCollisionGroup> m_collisionGroupArray;
    char _12[7];
    bool m_isNoTeam;
    char _20[4];

    STATIC_CHECK(sizeof(soCollision) == 24)
};


