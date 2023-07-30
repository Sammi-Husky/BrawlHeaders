#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <gm/gm_global_mode_melee.h>

struct gmGlobalRecord1 {

    struct EventSaveData {
        u32 m_easyScores[51];
        u32 m_normalScores[51];
        u32 m_hardScores[51];
    };

    struct MenuData {

        union StageSwitch {
            struct {
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool m_dxPStadium : 1;
                bool m_dxZebes : 1;
                bool m_dxBigBlue : 1;
                bool m_dxCorneria : 1;
                bool m_dxCruise : 1;
                bool m_dxGreens : 1;
                bool m_dxOnett : 1;
                bool m_dxGarden : 1;
                bool m_dxYorster : 1;
                bool m_dxShrine : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool : 1;
                bool m_plankton : 1;
                bool m_pictChat : 1;
                bool m_greenHill : 1;
                bool m_metalGear : 1;
                bool m_village : 1;
                bool m_newPork : 1;
                bool m_famicom : 1;
                bool m_palutena : 1;
                bool m_earth : 1;
                bool m_madein : 1;
                bool m_emblem : 1;
                bool m_gW : 1;
                bool m_ice : 1;
                bool m_fZero : 1;
                bool m_tengan : 1;
                bool m_stadium : 1;
                bool m_starFox : 1;
                bool m_halberd : 1;
                bool m_crayon : 1;
                bool m_orpheon : 1;
                bool m_norfair : 1;
                bool m_oldin : 1;
                bool m_pirates : 1;
                bool m_jungle : 1;
                bool m_donkey : 1;
                bool m_kart : 1;
                bool m_marioPast : 1;
                bool m_mansion : 1;
                bool m_dolpic : 1;
                bool m_final : 1;
                bool m_battle : 1;
            };
            struct {
                u32 m_meleeMask;
                u32 m_normalMask;
            };
        };

        u8 m_itemFrequency;
        char _1[7];
        gmItSwitch::ItemSwitch m_itemSwitch;
        char _16[10];
        u8 m_language;
        char _27[5];
        StageSwitch m_stageSwitch;

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