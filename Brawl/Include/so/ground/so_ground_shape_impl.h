#pragma once

#include <StaticAssert.h>
#include <gr/collision/gr_collision_status.h>
#include <mt/mt_vector.h>
#include <types.h>

class soModuleAccesser;

class soGroundShapeImpl {
public:
    enum CorrectKind {
        Correct_None = 0x0,
        Correct_Ground = 0x1,
        Correct_Ground_Cliff_Stop = 0x2,
        Correct_Ground_Ottotto = 0x3,
        Correct_Cliff = 0x4,
        Correct_Air = 0x5,
        Correct_Air_Passable = 0x6,
        Correct_Keep = 0x7,
        Correct_Ground_Cliff_Stop_Front = 0x8,
    };

    enum CliffCheckKind {
        Cliff_Check_None = 0x0,
        Cliff_Check_Always = 0x1,
        Cliff_Check_Always_Both_Sides = 0x2,
        Cliff_Check_On_Drop = 0x3,
        Cliff_Check_On_Drop_Both_Sides = 0x4,
    };

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
    grCollisionLine::MaterialType m_collMaterialType : 8;
    char _53[3];
    CorrectKind m_correctKind : 8;
    CliffCheckKind m_cliffCheck : 8;
    char _58[6];

    virtual ~soGroundShapeImpl();

    void updateRhombus(soModuleAccesser* moduleAccesser);
    void updateRhombusFollowNode(soModuleAccesser* moduleAccesser);
    void updateRhombusModify(soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soGroundShapeImpl) == 68, "Class is wrong size!");