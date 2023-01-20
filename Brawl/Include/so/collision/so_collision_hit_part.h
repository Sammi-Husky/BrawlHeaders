#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <mt/mt_vector.h>

struct soCollisionHitData {
    Vec3f m_startOffset;
    Vec3f m_endOffset;
    float m_size;
    unsigned int m_nodeIndex : 9;
    unsigned int m_0x1c_1 : 23;

    STATIC_CHECK(sizeof(soCollisionHitData) == 32)
};

struct soCollisionHitPartsInfo {
    soCollisionHitData* m_partsHitData;
    u32 m_numHitParts;

    STATIC_CHECK(sizeof(soCollisionHitPartsInfo) == 8)
};