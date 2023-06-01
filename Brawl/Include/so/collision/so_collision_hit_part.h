#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>

struct soCollisionHitData {
    Vec3f m_startOffsetPos;
    Vec3f m_endOffsetPos;
    float m_size;
    unsigned int m_nodeIndex : 9;
    unsigned int m_0x1c_1 : 23;
};
static_assert(sizeof(soCollisionHitData) == 32, "Class is wrong size!");

struct soCollisionHitPartsInfo {
    soCollisionHitData* m_partsHitData;
    u32 m_numHitParts;
};
static_assert(sizeof(soCollisionHitPartsInfo) == 8, "Class is wrong size!");