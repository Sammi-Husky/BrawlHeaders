#pragma once

#include <StaticAssert.h>
#include <so/so_kind.h>
#include <types.h>

class soDamageAttackerInfo {
public:
    char _spacer[4];

    int m_directTaskId;
    soKind m_directSoKind;
    int m_directSoSubKind;

    char _spacer2[4];

    int m_indirectTaskId;
    soKind m_indirectSoKind;
    int m_indirectSoSubKind;
    int m_indirectEntryId;

    char _spacer3[4];
};
static_assert(sizeof(soDamageAttackerInfo) == 40, "Class is wrong size!");
