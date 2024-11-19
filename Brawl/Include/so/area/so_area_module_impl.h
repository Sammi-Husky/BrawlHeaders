#pragma once

#include <gf/gf_area.h>
#include <mt/mt_vector.h>
#include <types.h>

#define AREA_SHAPE_FLAG_FOLLOW_NODE 0x1
#define AREA_SHAPE_FLAG_FIXED 0x2
#define AREA_SHAPE_FLAG_LR 0x4
#define AREA_SHAPE_FLAG_RESET_DISABLE 0x8
#define AREA_SHAPE_FLAG_STATUS_DISABLE 0x10
#define AREA_SHAPE_FLAG_STATUS_ENABLE 0x20
#define AREA_SHAPE_FLAG_IGNORE_SCALE 0x40
#define AREA_SHAPE_FLAG_ENABLE_SITUATION_GROUND 0x80
#define AREA_SHAPE_FLAG_ENABLE_SITUATION_AIR 0x100
#define AREA_SHAPE_FLAG_APPLY_OFFSET_ROT 0x200
#define AREA_SHAPE_FLAG_CHILD 0x400

struct soAreaData {

    enum Category {
        Category_Fighter = 0x0,
        Category_Enemy = 0x1,
        Category_Yakumono = 0x2,
        Category_Item = 0x3,
        Category_Weapon = 0x4,
    };

    gfArea::ShapeType m_shapeType : 8;
    gfArea::Group m_group : 8;

    union ShapeFlag {
        u16 m_mask;
        struct {
            bool m_flag15 : 1;      // 0x8000
            bool m_flag14 : 1;      // 0x4000
            bool m_flag13 : 1;      // 0x2000
            bool m_flag12 : 1;      // 0x1000
            bool m_flag11 : 1;      // 0x800
            bool m_child : 1;      // 0x400
            bool m_applyOffsetRot : 1;      // 0x200
            bool m_enableSituationAir : 1;       // 0x100
            bool m_enableSituationGround : 1;       // 0x80
            bool m_ignoreScale : 1;    // 0x40
            bool m_statusEnable : 1;       // 0x20
            bool m_statusDisable : 1;       // 0x10
            bool m_resetDisable : 1;       // 0x8
            bool m_lr : 1;       // 0x4
            bool m_fixed : 1;  // 0x2
            bool m_followNode : 1;     // 0x1
        };
    } m_shapeFlag;

    int m_0x4;
    int m_0x8;
    int m_nodeIndex;
    Vec2f m_offsetPos;
    Vec2f m_range;

};
static_assert(sizeof(soAreaData) == 0x20, "Class is wrong size!");
