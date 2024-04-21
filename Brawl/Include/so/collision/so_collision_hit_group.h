#pragma once

#include <StaticAssert.h>
#include <so/collision/so_collision_hit_part.h>
#include <types.h>

class soCollisionHitGroup {
    int m_index;
    char _4[2];
    short m_partSize;
    float m_8;
    float m_12;
    char _16[4];
    float m_20;
    char _24[4];
    int m_whole;
    int m_global;
    int m_xluFrameGlobal;
    int m_invincibleFrameGlobal;
    u32 m_situation;
    char _48[1];
    bool m_49;
    bool m_50;
    u8 m_51;
    u8 m_globalOffset;
    char _53[3];

public:
    void setInvincibleGlobal();

    soCollisionHitGroup();
    ~soCollisionHitGroup();
};
static_assert(sizeof(soCollisionHitGroup) == 56, "Class is wrong size!");