#pragma once

#include <types.h>
#include <gf/gf_task.h>
#include <nt/etc/nt_etc_so.h>

class nteDWC : public gfTask, public nteSODone {
    char _0x44[0x384];

public:
    virtual void processDefault();
    virtual ~nteDWC();
    virtual void notifyDoneSOProc(int, int);

    static void* AllocEx(int, size_t size, int align);
    static void FreeEx(int, void*);
};
static_assert(sizeof(nteDWC) == 0x3c8, "Class is wrong size!");