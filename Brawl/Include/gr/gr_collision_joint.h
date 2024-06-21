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
public:
    // 0
    char _spacer[16];
    // 16
    clAABBox2D m_aabBox;
    // 32
    char _spacer2[16];
    // 48
    grCollision* m_collision;
    // 52
    grCollisionLine* m_lines;
    // 56
    grCollData::VtxData* m_vtxDatas;
    // 60
    char _spacer3[20];
    // 80
    u16 m_nodeIndex;
    // 82
    union {
        struct {
            bool m_0x52_15 : 1;
            bool m_rightLedgeDisabled : 1;
            bool m_leftLedgeDisabled : 1;
            bool m_0x52_12 : 1;
            bool m_0x52_11 : 1;
            bool m_0x52_10 : 1;
            bool m_0x52_9 : 1;
            bool m_0x52_8 : 1;
            bool m_0x52_7 : 1;
            bool m_0x52_6 : 1;
            bool m_0x52_5 : 1;
            bool m_0x52_4 : 1;
            bool m_0x52_3 : 1;
            bool m_0x52_2 : 1;
            bool m_0x52_1 : 1;
            bool m_0x52_0 : 1;
        };
        u16 m_flags;
    };

    // 84
    bool m_0x54_7 : 1;
    bool m_0x54_6 : 1;
    bool m_0x54_5 : 1;
    bool m_0x54_4 : 1;
    bool m_0x54_3 : 1;
    bool m_0x54_2 : 1;
    bool m_0x54_1 : 1;
    bool m_0x54_0 : 1;
    // 85
    u8 _0x55;
    // 86
    bool m_0x56_7 : 1;
    bool m_0x56_6 : 1;
    bool m_0x56_5 : 1;
    bool m_0x56_4 : 1;
    bool m_0x56_3 : 1;
    bool m_0x56_2 : 1;
    bool m_0x56_1 : 1;
    bool m_0x56_0 : 1;
    // 88
    Ground* m_ground;
    // 92
    Matrix* m_matrix;
};
static_assert(sizeof(grCollisionJoint) == 96, "Class is wrong size!");