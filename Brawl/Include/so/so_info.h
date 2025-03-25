#pragma once

#include <StaticAssert.h>
#include <types.h>

class soInfo {
public:
    virtual ~soInfo() { }
    virtual bool isInvalidKind(int kind);
    virtual int getInvalidKind();
    const char* getNamePtr(int kind);
    virtual u32 getMotionNum(int kind);
    virtual u32 getStatusNum(int kind);

};
static_assert(sizeof(soInfo) == 0x4, "Class has the wrong size!");
