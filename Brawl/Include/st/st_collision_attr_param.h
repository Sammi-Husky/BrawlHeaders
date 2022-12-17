#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gr/gr_yakumono.h>

struct grGimmickDamageFloor {
    grGimmick::AttackData attackData;
    char _88[4];
    u32 m_index;
    int m_96;

    STATIC_CHECK(sizeof(grGimmickDamageFloor) == 100)
};
