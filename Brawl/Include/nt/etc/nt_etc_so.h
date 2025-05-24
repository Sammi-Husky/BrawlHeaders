#pragma once

#include <StaticAssert.h>
#include <gf/gf_thread.h>
#include <types.h>

// TODO rename
class nteSODone {
public:
    virtual void notifyDoneSOProc(s32, s32);
};

class nteSO : public gfThread {
    u32 unk340;
    u8 unk344;
    u32 unk348;
public:
    nteSO();
    ~nteSO();
    bool startup(nteSODone* p1, u32 p2);
    bool finish(nteSODone* p1);
};
static_assert(sizeof(nteSO) == 0x350, "Class is the wrong size!");
