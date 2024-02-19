#pragma once

#include <types.h>
#include <ft/ft_slot.h>

class ftSlotManager {
public:
    ftSlot* m_slots;
    u32 m_slotCount;
    char _0x8[0x538];
};
static_assert(sizeof(ftSlotManager) == 0x540, "Class is wrong size!");

extern ftSlotManager* g_ftSlotManager;