#pragma once

//#include <so/stageobject.h>

// TODO: Just include stage object instead once it's fixed
enum soKind {
    Invalid = 0xFFFFFFFF,
    Fighter = 0x0,
    Enemy = 0x1,
    Weapon = 0x2,
    Yakumono = 0x3,
    Item = 0x4
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
