#pragma once

#include <types.h>
#include <memory.h>

class gfHeapManager
{
    int getMaxFreeSize(u32);
    void dumpAll();
    void dumpList();

public:
    static void *getMEMAllocator(Heaps::HeapType heapType);
};