#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_collision_status.h>
#include <mt/mt_vector.h>

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

    virtual ~soGroundShapeImpl();

    STATIC_CHECK(sizeof(soGroundShapeImpl) == 68)
};