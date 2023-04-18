#pragma once

#include <StaticAssert.h>
#include <types.h>

struct gmGlobalRecord1 {

    struct EventSaveData {
        u32 m_easyScores[51];
        u32 m_normalScores[51];
        u32 m_hardScores[51];
    };

    struct MenuData {
        char _0[40];
        bool m_isWidescreen : 1;
        bool m_41_6 : 1;
        bool m_41_5 : 1;
        bool m_41_4 : 1;
        bool m_41_3 : 1;
        bool m_41_2 : 1;
        bool m_41_1 : 1;
        bool m_41_0 : 1;
        char _41[3];
    };

    char _0[812];

    EventSaveData m_eventSaveData[2];

    char _2036[28];

    MenuData m_menuData; // 2064

    char _spacer[0x34B4];
};
static_assert(sizeof(gmGlobalRecord1) == 0x3cf0, "Class is wrong size!");
struct gmGlobalRecord2 {
    char _spacer[0x88e0]; // 0x00
};
static_assert(sizeof(gmGlobalRecord2) == 0x88e0, "Class is wrong size!");
struct nteGlobalData {
    char _spacer[0x88]; // 0x00
};
static_assert(sizeof(nteGlobalData) == 0x88, "Class is wrong size!");
struct AdvLevelSaveData {
    u32 m_clearFlag;       // 0x00
    u32 m_clearDifficulty; // 0x04
    u32 m_unk1;            // 0x08
    s32 m_clearPercent;    // 0x0C
    u32 m_unk2;            // 0x10
};
static_assert(sizeof(AdvLevelSaveData) == 0x14, "Class is wrong size!");

struct adKeep {
    char _0[0x04];                    // 0x00
    AdvLevelSaveData m_levelData[34]; // 0x04
    char _1[0x46AC];                  // 0x2AC
};
static_assert(sizeof(adKeep) == 0x4958, "Class is wrong size!");