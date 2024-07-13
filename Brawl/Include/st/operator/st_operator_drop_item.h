#pragma once

#include <st/operator/st_operator.h>
#include <mt/mt_vector.h>
#include <types.h>

#define FRAMES_REQUIRED_START_BOMB_DROP 1200.0

class stOperatorDropItem : public stOperator {
public:
    bool m_isSuddenDeath;
    char _0x9[0x3];
    float m_framesElapsedStartBombDrop;
    float m_framesElapsedBombDrop;
    Vec3f m_itemDropPos;
    float m_framesElapsedItemDrop;
    float m_framesRequiredItemDrop;
    float m_framesElapsed;
    u8 m_itemFrequencyIndex;
    char _0x2D[3];

    virtual ~stOperatorDropItem();
};
static_assert(sizeof(stOperatorDropItem) == 112, "Class is wrong size!");

class stOperatorDropItemMelee : public stOperatorDropItem {
public:
    virtual ~stOperatorDropItemMelee();
    virtual void processBegin();
    virtual void startOperator();
};
static_assert(sizeof(stOperatorDropItem) == 112, "Class is wrong size!");

