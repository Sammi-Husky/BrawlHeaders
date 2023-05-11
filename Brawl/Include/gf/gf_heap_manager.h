#pragma once

#include <memory.h>
#include <types.h>

class gfHeapManager {
public:
    static int getMaxFreeSize(u32);
    static void dumpAll();
    static void dumpList();

    static void* getMEMAllocator(Heaps::HeapType heapType);
    static void* getHeap(Heaps::HeapType heapType);
};