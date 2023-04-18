#pragma once

#include <StaticAssert.h>
#include <gr/gr_collision_data.h>
#include <gr/gr_collision_line.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_matrix.h>
#include <types.h>

class grCollision;
class Ground;

class grCollisionJoint {
    // 0
    char _spacer[16];
    // 16
    clAABBox2D m_aabBox;
    // 32
    char _spacer2[16];
    // 48
    grCollision* m_collision;
    // 52
    grCollisionLine* m_collisionLines;
    // 56
    VtxData* m_vtxDataArray;
    // 60
    char _spacer3[28];
    // 88
    Ground* m_ground;
    // 92
    Matrix* m_matrix;
};
static_assert(sizeof(grCollisionJoint) == 96, "Class is wrong size!");