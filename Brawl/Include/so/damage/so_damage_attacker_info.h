#pragma once

#include <StaticAssert.h>
#include <so/so_kind.h>
#include <types.h>

class soDamageAttackerInfo {
public:
    char _spacer[4];

    int m_directAttackerTaskId;
    soKind m_directAttackerSoKind;
    int m_directAttackerSoSubKind;

    char _spacer2[4];

    int m_indirectAttackerTaskId;
    soKind m_indirectAttackerSoKind;
    int m_indirectAttackerSoSubKind;
    int m_indirectAttackerEntryId;

    char _spacer3[4];
};
static_assert(sizeof(soDamageAttackerInfo) == 40, "Class is wrong size!");
