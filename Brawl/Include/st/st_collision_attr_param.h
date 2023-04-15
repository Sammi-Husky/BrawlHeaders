#pragma once

#include <StaticAssert.h>
#include <gr/gr_yakumono.h>
#include <types.h>

struct grGimmickDamageFloor {
    grGimmick::AttackData attackData;
    char _88[4];
    u32 m_index;
    int m_96;
};
static_assert(sizeof(grGimmickDamageFloor) == 100, "Class is wrong size!");
