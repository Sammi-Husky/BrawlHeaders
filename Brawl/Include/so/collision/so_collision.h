#pragma once

#include <StaticAssert.h>
#include <so/collision/so_collision_group.h>
#include <so/so_array.h>
#include <types.h>

#define COLLISION_CATEGORY_MASK_FLOOR 0x200
#define COLLISION_CATEGORY_MASK_ITEM_E 0x100
#define COLLISION_CATEGORY_MASK_GIMMICK 0x40
#define COLLISION_CATEGORY_MASK_ITEM 0x8
#define COLLISION_CATEGORY_MASK_ENEMY 0x2
#define COLLISION_CATEGORY_MASK_FIGHTER 0x1
#define COLLISION_CATEGORY_MASK_ALL 0x3FF
#define COLLISION_CATEGORY_MASK_NO_GIMMICK 0x3BF
#define COLLISION_CATEGORY_MASK_NO_ITEM 0x27F

#define COLLISION_PART_MASK_LEG 0x8
#define COLLISION_PART_MASK_KNEE 0x4
#define COLLISION_PART_MASK_ARM 0x2
//#define COLLISION_PART_MASK_BODY 0x1
#define COLLISION_PART_MASK_ALL 0xF
#define COLLISION_PART_MASK_BODY 0x9
#define COLLISION_PART_MASK_ETC 0x2
#define COLLISION_PART_MASK_LEGS 0xC
#define COLLISION_PART_MASK_BODY_LEGS 0xD

#define COLLISION_SITUATION_MASK_G 0x1
#define COLLISION_SITUATION_MASK_GROUND 0x1
#define COLLISION_SITUATION_MASK_AIR 0x2
#define COLLISION_SITUATION_MASK_A 0x2
#define COLLISION_SITUATION_MASK_GA 0x3
#define COLLISION_SITUATION_MASK_ODD 0x4
#define COLLISION_SITUATION_MASK_ALL 0x7



struct clTarget {
    int m_0;
    int m_4;

    clTarget();
    ~clTarget();
};
static_assert(sizeof(clTarget) == 0x8, "Class is wrong size!");

class soCollision {
    int m_kind;
    int m_indirectTeam;
    soArray<soCollisionGroup>* m_collisionGroupArray;
    int m_taskId;
    u8 m_category;
    char _17[2];
    bool m_isNoTeam;
    char _20[4];
};
static_assert(sizeof(soCollision) == 24, "Class is wrong size!");
