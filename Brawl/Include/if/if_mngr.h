#pragma once

#include <StaticAssert.h>
#include <if/if_player.h>
#include <types.h>

class IfMngr {
public:
    char _spacer[169];
    bool m_isPauseMenuActive;
    char _spacer2[30];
};
static_assert(sizeof(IfMngr) == 200, "Class is wrong size!");

extern IfMngr* g_IfMngr;