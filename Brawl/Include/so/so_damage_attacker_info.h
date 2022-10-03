#pragma once

//#include <so/stageobject.h>

// TODO: Just include stage object instead once it's fixed
enum soKind {
    INVALID = 0xFFFFFFFF,
    FIGHTER = 0x0,
    ENEMY = 0x1,
    WEAPON = 0x2,
    YAKUMONO = 0x3,
    ITEM = 0x4
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

    char _spacer3[8];
};
