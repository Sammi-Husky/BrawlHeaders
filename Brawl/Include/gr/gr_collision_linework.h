#pragma once

#include <gr/gr_collision_joint.h>
#include <gr/gr_collision_line.h>
#include <types.h>
#include <StaticAssert.h>

class grCollision;

class grCollisionLineWork {
    // 0
    grCollisionLine* m_collisionLine;
    // 4
    grCollisionJoint* m_collisionJoint;
    // 8
    grCollision* m_collision;
    // 12
    char _spacer[4];

    STATIC_CHECK(sizeof(grCollisionLineWork) == 16)
};