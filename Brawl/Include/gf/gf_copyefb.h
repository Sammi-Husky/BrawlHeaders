#pragma once

#include <types.h>
#include <GX.h>

class gfCopyEFBMgr {
    char _0[112];

public:
    bool isValid(int index);
    GXTexObj* getCopyEFBTex(int index);
    static gfCopyEFBMgr* getInstance();
};
static_assert(sizeof(gfCopyEFBMgr) == 112, "Class is wrong size!");
