#pragma once

#include <types.h>

struct gmStageData {
    struct ItemCollectionData {
        u16 m_numCollections;
        short m_itVariations[256];
        u8 m_itKinds[256];
    };

    short m_exSetting;
    char _2[2];
    float m_motionRatio;
    float m_motionSubRatio;
    ItemCollectionData m_itemCollectionData;
    char _782[2310];
};
static_assert(sizeof(gmStageData) == 3092, "Class is wrong size!");