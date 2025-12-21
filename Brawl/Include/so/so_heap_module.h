#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <sr/sr_common.h>
#include <types.h>

class soHeapModule : public soNullable {
public:
    soHeapModule() { }
    virtual ~soHeapModule() { }
    virtual HeapType getInstanceHeap() const = 0;
    virtual void setInstanceHeap(HeapType heap) { }
    virtual HeapType getNWModelInstanceHeap() const = 0;
    virtual HeapType getNWMotionInstanceHeap() const = 0;
    virtual u32 getSlotNo() const = 0;
};
static_assert(sizeof(soHeapModule) == 8, "Class is wrong size!");
