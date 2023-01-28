#pragma once

#include <types.h>
#include <memory.h>

class gfHeapManager
{
public:

    static int getMaxFreeSize(u32);
    static void dumpAll();
    static void dumpList();

    static void *getMEMAllocator(Heaps::HeapType heapType);
};