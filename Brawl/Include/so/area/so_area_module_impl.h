#pragma once

#include <gf/gf_area.h>
#include <mt/mt_vector.h>
#include <types.h>

struct soAreaData {
    gfArea::ShapeType m_shapeType : 8;
    u8 m_group;

    union Flags {
        u16 m_mask;
        struct {
            bool m_flag15 : 1;      // 0x8000
            bool m_flag14 : 1;      // 0x4000
            bool m_flag13 : 1;      // 0x2000
            bool m_flag12 : 1;      // 0x1000
            bool m_flag11 : 1;      // 0x800
            bool m_flag10 : 1;      // 0x400
            bool m_useRot : 1;      // 0x200
            bool m_flag8 : 1;       // 0x100
            bool m_flag7 : 1;       // 0x80
            bool m_useScale : 1;    // 0x40
            bool m_flag5 : 1;       // 0x20
            bool m_flag4 : 1;       // 0x10
            bool m_flag3 : 1;       // 0x8
            bool m_useLr : 1;       // 0x4
            bool m_fixedShape : 1;  // 0x2
            bool m_useNode : 1;     // 0x1
        };
    } m_flags;

    int m_0x4;
    int m_0x8;
    int m_nodeId;
    Vec2f m_offsetPos;
    Vec2f m_range;
};
static_assert(sizeof(soAreaData) == 0x20, "Class is wrong size!");

struct soAreaInit {
    soAreaData* m_areasData;
    u32 m_numAreas;
};
