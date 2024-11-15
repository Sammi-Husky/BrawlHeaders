#pragma once

#include <StaticAssert.h>
#include <gr/collision/gr_collision.h>
#include <gr/collision/gr_collision_shape_circle.h>
#include <gr/collision/gr_collision_shape_rhombus.h>
#include <types.h>

class grCollStatus {
public:
    enum Setting {
        Setting_None = 0x0,
        Setting_Ground = 0x1,
        Setting_Air = 0x2,
        Setting_Cliff = 0x3,
    };

    // 0
    grCollStatus* m_next;
    // 4
    grCollStatus* m_prev;
    // 8
    Setting m_setting : 8;
    u32 m_0x8_0 : 24;

    char _spacer[2];
    // 14
    short m_exclusiveLineAttr;
    // 16
    int m_taskId;
    // 20
    char _spacer2[65];
    // 85
    char m_cliffTeam;
    // 86
    char _spacer3[6];
    // 92
    grCollShape* m_prevCollShape;
    // 96
    grCollShape* m_currentCollShape;
    // 100
    char _spacer4[10];
    // 110
    char m_targetLineCategory;
    // 111
    char _spacer5[6];
    // 117
    union {
        struct {
            bool m_touchFlag7 : 1;
            bool m_touchFlag6 : 1;
            bool m_touchFlag5 : 1;
            bool m_touchFlag4 : 1;
            bool m_touchFlag3 : 1;
            bool m_touchFlag2 : 1;
            bool m_touchFlag1 : 1;
            bool m_touchFlag0 : 1;
        };
        u8 m_touchFlags;
    };
    // 118
    char _spacer6[10];
    // 128
    grCollision* m_collision;
    // 132
    Vec2f m_unk;
    // 140
    Vec2f m_touchLineSpeed;
    // 148
    char _spacer7[32];
    // 180
    Vec2f m_180[3];
    // 204
    char _spacer8[8];
    // 212
    grCollisionLineWork m_collLineWorkArray[19];
    // 516
    grCollShape m_collShape;
    // 520
    char _spacer9[116];
    // TOTAL SIZE == 636
};
static_assert(sizeof(grCollStatus) == 636, "Class is wrong size!");

class grCollStatusEventReceiver {
public:
    virtual void receive(int, bool);
};