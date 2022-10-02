#pragma once

#include <types.h>
#include <gr/gr_collision_linework.h>

class Stage;

class grCollision
{
private:
    // 0
    short index;
    // 2
    short vtxLen;
    // 4
    short lineLen;
    // 6
    short jointLen;
    // 8
    grCollData* collData;
    // 12
    VtxData* vtxDataArray;
    // 16
    Vec2f* vtxPosArray;
    // 20
    grCollisionLine* collisionLineArray;
    // 24
    grCollisionJoint* collisionJointArray;
    // 28
    clAABBox2D aabBox;
    // 44
    char _spacer[4];
    // 48
    void* next;
    // 52
    void* prev;
    // TOTAL_SIZE == 56
public:
    static grCollision* create(Stage* stage, void* colData, Ground* ground, int unk2);
    grCollision(void* colData, int unk1, int unk2);
    ~grCollision();
};
