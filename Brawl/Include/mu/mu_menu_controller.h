#pragma once

#include <StaticAssert.h>

class muMenuController {
public:
    char _unk[0xA8];
};
static_assert(sizeof(muMenuController) == 0xA8, "Wrong size for class!");