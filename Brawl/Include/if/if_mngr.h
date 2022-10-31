#pragma once

#include <types.h>

class IfMngr {
    public:
        char _spacer[169];
        bool isPauseMenuActive;
        char _spacer2[30];
};

extern IfMngr* g_IfMngr;