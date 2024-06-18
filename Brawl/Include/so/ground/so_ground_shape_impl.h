#pragma once

#include <StaticAssert.h>
#include <gr/gr_collision_status.h>
#include <mt/mt_vector.h>
#include <types.h>

class soModuleAccesser;

class soGroundShapeImpl {
    char _0[4];
    grCollStatus* m_collStatus;
    Vec2f m_savePos;
    Vec2f m_offset;
    float m_24;
    float m_28;
    float m_rhombusUp;
    float m_rhombusDown;
    float m_rhombusWidth;
    int m_rhombusFollowNode;
    float m_downFriction;
    u8 m_materialType;
    char _53[3];
    u8 m_correct;
    u8 m_cliffCheck;
    char _58[6];

public:
    virtual ~soGroundShapeImpl();

    void updateRhombus(soModuleAccesser* moduleAccesser);
    void updateRhombusFollowNode(soModuleAccesser* moduleAccesser);
    void updateRhombusModify(soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soGroundShapeImpl) == 68, "Class is wrong size!");