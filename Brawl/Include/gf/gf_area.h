#pragma once

#include <mt/mt_vector.h>
#include <types.h>

class gfArea {

public:
    enum ShapeType {
        Shape_Rectangle = 0x0,
        Shape_Circle = 0x1,
        Shape_Triangle = 0x2,
    };

    char _0x0[8];
    int m_checkTargetGroup;
    int m_checkTargetLocalGroup;
    int m_id;
    int m_teamId;
    ShapeType m_shapeType;
    char _0x1C[4];
    Vec2f m_pos;
    char _0x28[4];
    char _aaabBox[0x10];
    int m_ownerId;
    char _0x40[4];

    virtual bool testIntersectShape(void* unk);
    virtual void debugDrawImp();
    virtual void notifyIntersect(int unk);
    virtual void update();
    virtual bool testIncludePos(Vec2f* pos);
};
static_assert(sizeof(gfArea) == 0x48, "Class is wrong size!");