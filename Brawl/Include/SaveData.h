#pragma once

#include <StaticAssert.h>
#include <types.h>

struct SaveData1 {
    char _spacer[0x3cf0]; // 0x00

    STATIC_CHECK(sizeof(SaveData1) == 0x3cf0)
};
struct SaveData2 {
    char _spacer[0x88e0]; // 0x00

    STATIC_CHECK(sizeof(SaveData2) == 0x88e0)
};
struct SaveData3 {
    char _spacer[0x88]; // 0x00

    STATIC_CHECK(sizeof(SaveData3) == 0x88)
};
struct AdvLevelSaveData {
    u32 m_clearFlag;       // 0x00
    u32 m_clearDifficulty; // 0x04
    u32 m_unk1;            // 0x08
    s32 m_clearPercent;    // 0x0C
    u32 m_unk2;            // 0x10

    STATIC_CHECK(sizeof(AdvLevelSaveData) == 0x14)
};

struct AdvSaveData {
    char _0[0x04];                    // 0x00
    AdvLevelSaveData m_levelData[34]; // 0x04
    char _1[0x46AC];                  // 0x2AC

    STATIC_CHECK(sizeof(AdvSaveData) == 0x4958)
};