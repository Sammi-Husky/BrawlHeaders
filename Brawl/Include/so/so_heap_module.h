#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <sr/sr_common.h>
#include <types.h>

class soHeapModule : public soNullable {
public:
    soHeapModule() { }
    virtual ~soHeapModule() { }
    virtual HeapType getInstanceHeap() const;
    virtual void setInstanceHeap(HeapType heap) { }
    virtual HeapType getNWModelInstanceHeap() const;
    virtual HeapType getNWMotionInstanceHeap() const;
    virtual u32 getSlotNo() const;
};
static_assert(sizeof(soHeapModule) == 8, "Class is wrong size!");
