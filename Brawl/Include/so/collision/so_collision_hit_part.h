#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <so/so_array.h>
#include <so/collision/so_collision.h>
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

class soCollisionHitPart {
    int m_status;
    char _0x4[4];
    soCollisionHitData m_hitData;
    soArrayVector<clTarget, 6> m_clTargetArrayVector;
    char _0x64[4];

public:
    soCollisionHitPart();
    soCollisionHitPart(u8, u32);
    ~soCollisionHitPart();
};
static_assert(sizeof(soCollisionHitPart) == 0x68, "Class is wrong size!");
