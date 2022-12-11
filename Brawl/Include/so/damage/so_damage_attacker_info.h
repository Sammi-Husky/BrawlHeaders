#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_kind.h>

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

    STATIC_CHECK(sizeof(soDamageAttackerInfo) == 40)
};
