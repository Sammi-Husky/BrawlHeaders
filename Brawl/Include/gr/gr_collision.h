#pragma once

#include <gr/gr_collision_linework.h>
#include <types.h>
#include <StaticAssert.h>

class Stage;

class grCollision {
private:
    // 0
    short m_index;
    // 2
    short m_vtxLen;
    // 4
    short m_lineLen;
    // 6
    short m_jointLen;
    // 8
    grCollData* m_collData;
    // 12
    VtxData* m_vtxDataArray;
    // 16
    Vec2f* m_vtxPosArray;
    // 20
    grCollisionLine* m_collisionLineArray;
    // 24
    grCollisionJoint* m_collisionJointArray;
    // 28
    clAABBox2D m_aabBox;
    // 44
    char _spacer[4];
    // 48
    void* m_next;
    // 52
    void* m_prev;
    // TOTAL_SIZE == 56
public:
    static grCollision* create(Stage* stage, void* colData, Ground* ground, int unk2);
    grCollision(void* colData, int unk1, int unk2);
    ~grCollision();

    STATIC_CHECK(sizeof(grCollision) == 56)
};
