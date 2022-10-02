#pragma once

#include <gr/gr_collision_line.h>
#include <gr/gr_collision_joint.h>

class grCollision;

class grCollisionLineWork
{
    // 0
    grCollisionLine* collisionLine;
    // 2
    grCollisionJoint* collisionJoint;
    // 4
    grCollision* collision;
    // 6
    char _spacer[4];
};