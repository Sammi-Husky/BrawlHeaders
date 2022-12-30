#pragma once

#include <StaticAssert.h>
#include <types.h>

struct PlayerCorpsInit {
    u8 m_slotID;               // 0x00
    u8 m_costumeID;            // 0x01
    s8 m_stockCount;           // 0x02
    u8 m_cpuType;              // 0x03
    s8 m_cpuRank;              // 0x04
    char _1[0x03];             // 0x05
    float m_attackReactionMul; // 0x08
    float m_damageReactionMul; // 0x0C
    float m_scale;             // 0x10

    STATIC_CHECK(sizeof(PlayerCorpsInit) == 0x14)
    STATIC_CHECK(sizeof(PlayerCorpsInit) == 0x14)
};

class gmGlobalCorps {
public:
    u8 _0;                                  // 0x00
    s8 m_numFightersToBeat;                 // 0x01
    u8 _1;                                  // 0x02
    s8 m_numFightersInCurrentStage;         // 0x03
    char _2[0x19];                          // 0x04
    s8 m_remainingFightersToBeat;           // 0x1D
    char _3[0x06];                          // 0x1E
    PlayerCorpsInit m_playersInitData[0x24]; // 0x24

    STATIC_CHECK(sizeof(gmGlobalCorps) == 0x2f4)
};
