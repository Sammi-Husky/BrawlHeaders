#pragma once

#include <memory.h>
#include <MEM.h>
#include <types.h>

class gfHeapManager {
public:
    static int getMaxFreeSize(u32);
    static void dumpAll();
    static void dumpList();
    static void createHeap(int heapId, const char* heapName, int memArena, int heapSize);

    static void* getMEMAllocator(Heaps::HeapType heapType);
    static void* getHeap(Heaps::HeapType heapType);
};