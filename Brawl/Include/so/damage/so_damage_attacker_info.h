#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_kind.h>

class soDamageAttackerInfo {
    char _spacer[4];

    int directAttackerTaskId;
    soKind directAttackerSoKind;
    int directAttackerSoSubKind;

    char _spacer2[4];

    int indirectAttackerTaskId;
    soKind indirectAttackerSoKind;
    int indirectAttackerSoSubKind;
    int indirectAttackerEntryId;

    char _spacer3[4];

    STATIC_CHECK(sizeof(soDamageAttackerInfo) == 40)
};
