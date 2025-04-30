#pragma once

#include <StaticAssert.h>

class gfReturnStatusCallback {
public:
    gfReturnStatusCallback* m_next;
    virtual bool returnStatus() const = 0;
};
static_assert(sizeof(gfReturnStatusCallback) == 0x8, "Class is the wrong size!");

class gfReturnStatusCallbackList {
    gfReturnStatusCallback* m_head;
public:
    void add(gfReturnStatusCallback* node);
    bool remove(gfReturnStatusCallback* node);
    bool process() const;
};
static_assert(sizeof(gfReturnStatusCallbackList) == 0x4, "Class is the wrong size!");
