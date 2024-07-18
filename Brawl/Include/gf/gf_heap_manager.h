#pragma once

#include <MEM/mem_allocator.h>
#include <memory.h>
#include <types.h>

class gfHeapManager {
public:
    static int getMaxFreeSize(u32);
    static void dumpAll();
    static void dumpList();
    static void createHeap(int heapId, const char* heapName, int memArena, int heapSize);

    static void* alloc(Heaps::HeapType heapType, size_t size);
    static MEMAllocator* getMEMAllocator(Heaps::HeapType heapType);
    static void* getHeap(Heaps::HeapType heapType);
};