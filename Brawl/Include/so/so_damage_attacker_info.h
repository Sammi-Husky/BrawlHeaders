#pragma once

#include <types.h>
//#include <so/stageobject.h>

// TODO: Just include stage object instead once it's fixed
enum soKind {
    So_Kind_Invalid = 0xFFFFFFFF,
    So_Kind_Fighter = 0x0,
    So_Kind_Enemy = 0x1,
    So_Kind_Weapon = 0x2,
    So_Kind_Yakumono = 0x3,
    So_Kind_Item = 0x4
};

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
};
