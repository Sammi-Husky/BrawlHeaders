#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <if/if_player.h>

class IfMngr {
    public:
        char _spacer[169];
        bool m_isPauseMenuActive;
        char _spacer2[30];

    STATIC_CHECK(sizeof(IfMngr) == 200)
};

extern IfMngr* g_IfMngr;