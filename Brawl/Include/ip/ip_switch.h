#pragma once

#include <types.h>
#include <ip/ip_padrec.h>

class ipSwitch {
public:
    char _0[24];
    ipKeyRecorder* m_keyRecorder;
    char _28[12];
};
static_assert(sizeof(ipSwitch) == 0x28, "Class is wrong size!");

extern ipSwitch* g_ipSwitch;