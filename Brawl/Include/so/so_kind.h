#pragma once

#include <types.h>

enum soKind {
    SoKind_Invalid = 0xFFFFFFFF,
    SoKind_Fighter = 0x0,
    SoKind_Enemy = 0x1,
    SoKind_Weapon = 0x2,
    SoKind_Yakumono = 0x3,
    SoKind_Item = 0x4
};