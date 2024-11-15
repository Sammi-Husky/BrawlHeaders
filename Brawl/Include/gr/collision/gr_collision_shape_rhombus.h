#pragma once

#include <StaticAssert.h>
#include <gr/collision/gr_collision_shape.h>
#include <types.h>

class grCollShapeRhombus : public grCollShape {
    clRhombus2D m_rhombus;
public:
    virtual void init();
    virtual int getType();
    virtual void getAABBox(clAABBox2D* aabBox);
    virtual void setDownPos(Vec2f* downPos);
    virtual void setLeftPos(Vec2f* leftPos);
    virtual void setRightPos(Vec2f* rightPos);
    virtual void setCenterPos(Vec2f* centerPos);
    virtual void setTopPos(Vec2f* topPos);
    virtual Vec2f getCenterPos();
    virtual Vec2f getDownPos();
    virtual Vec2f getLeftPos();
    virtual Vec2f getRightPos();
    virtual Vec2f getTopPos();
    virtual void move(Vec2f* displacement);
    virtual void set(grCollShape* collShape);
    virtual float getHeight();
    virtual float getWidth();
    virtual void test();
    virtual void updateAABBox();
    virtual void setLR(Vec2f* centerPos, Vec2f* unk1, Vec2f* unk2);
    virtual void setUD(Vec2f* centerPos, Vec2f* unk1, Vec2f* unk2);
    virtual void setLR(Vec2f* unk1, Vec2f* unk2);
    virtual void modifyDownY(float downY);
};
static_assert(sizeof(grCollShapeRhombus) == 60, "Class is wrong size!");