#pragma once

#include <gr/gr_collision_data.h>
#include <mt/mt_coll2d.h>
#include <mt/mt_matrix.h>

class grCollision;
class Ground;

class grCollisionJoint {
    // 0
    char _spacer[16];
    // 16
    clAABBox2D aabBox;
    // 32
    char _spacer2[16];
    // 48
    grCollision* collision;
    // 52
    grCollisionLine* collisionLineArray;
    // 56
    VtxData* vtxDataArray;
    // 60
    char _spacer3[28];
    // 88
    Ground* ground;
    // 92
    Matrix* matrix;
};