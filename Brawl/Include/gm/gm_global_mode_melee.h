#pragma once

#include <StaticAssert.h>
#include <types.h>

class gmItSwitch {
public:
    char _spacer[0x10];
};

class gmMeleeInitData {
public:
    char _0x0[0x4];             // 0x00
    bool m_0x4_7 : 1;           // 0x04
    bool m_0x4_6 : 1;
    bool m_0x4_5 : 1;
    bool m_0x4_4 : 1;
    bool m_0x4_3 : 1;
    bool m_0x4_2 : 1;
    bool m_0x4_1 : 1;
    bool m_0x4_0 : 1;
    char _0x5[0x3];            // 0x05
    s8 m_eventId;               // 0x08
    char _0x9[0x5];             // 0x09
    u8 m_itemFrequency;         // 0x0E
    char _0xf[0x03];            // 0x0F
    short m_stageID;            // 0x12
    u8 m_subStageID;            // 0x14
    char _0x15[0x3];            // 0x15
    s32 m_timeLimitFrames;      // 0x18
    char _0x1c[0x0C];           // 0x1C
    gmItSwitch m_itSwitchData;  // 0x28
    char _0x38[0x08];           // 0x38
    float m_cameraShakeScale;   // 0x40
    char _0x44[0x04];           // 0x44
    float m_gameSpeed;          // 0x48
    char _0x4c[0x2C];           // 0x4C
    short m_globalOffenseRatio; // 0x78
    short m_globalDefenseRatio; // 0x7A
    char _0x7c[0x14];           // 0x7C

    STATIC_CHECK(sizeof(gmMeleeInitData) == 0x90)
};

class gmPlayerInitData {
public:
    s8 m_slotID;               // 0x00
    u8 m_initState;            // 0x01
    char _0[0x02];             // 0x02
    s8 m_stockCount;           // 0x04
    s8 m_colorFileIdx;         // 0x05
    s8 m_costumeID;            // 0x06
    char _1;                   // 0x07
    s8 m_startPointIdx;        // 0x08
    char _2[0x02];             // 0x09
    s8 m_teamID;               // 0x0B
    char _3[0x0E];             // 0x0C
    bool m_isNoVoice;          // 0x1A
    char _4[0x03];             // 0x1B
    u8 m_cpuType;              // 0x1E
    u8 m_cpuRank;              // 0x1F
    char _5[0x02];             // 0x20
    short m_startDamage;       // 0x22
    short m_hitPointMax;       // 0x24
    char _6[0x02];             // 0x26
    short m_glowAttack;        // 0x28
    short m_glowDefense;       // 0x2A
    float m_attackRatio;       // 0x2C
    float m_damageRatio;       // 0x30
    float m_attackReactionMul; // 0x34
    float m_damageReactionMul; // 0x38
    char _7[0x04];             // 0x3C
    float m_scale;             // 0x40
    float m_visibilityScale;   // 0x44
    float m_gravity;           // 0x48
    char _8[0x10];             // 0x4C

    STATIC_CHECK(sizeof(gmPlayerInitData) == 0x5C)
};

class gmGlobalModeMelee {
public:
    char _0[0x08];                          // 0x00
    gmMeleeInitData m_meleeInitData;        // 0x08
    gmPlayerInitData m_playersInitData[7];  // 0x98
    char _1[4];

    STATIC_CHECK(sizeof(gmGlobalModeMelee) == 0x320)
};