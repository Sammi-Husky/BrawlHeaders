#pragma once

#include <StaticAssert.h>
#include <types.h>

class gfCallBack {
    gfCallBack* m_next;

public:
    gfCallBack() : m_next(0) { }
    virtual void userProc() = 0;
    virtual ~gfCallBack() { }
};
static_assert(sizeof(gfCallBack) == 0x8, "Class is wrong size!");
