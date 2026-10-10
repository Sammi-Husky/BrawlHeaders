#pragma once

#include <StaticAssert.h>
#include <MEM/mem_allocator.h>
#include <gf/gf_memory_pool.h>
#include <memory.h>
#include <sr/sr_common.h>
#include <types.h>

struct HeapCreateInfo {
    const char* m_name;
    int m_heapId;
    int m_memArena;
    int m_size;
};

class gfHeapManager {
public:
    static void initialize();
    static void setHeap(int heapId, gfMemoryPool* pool);
    static void clearHeap(int heapId);
    static void createHeaps(const HeapCreateInfo* infos);
    static void destroyHeaps(const HeapCreateInfo* infos);
    static void destroyHeap(int heapId);
    static int getMaxFreeSize(Heaps::HeapType heapType);
    static void dumpAll();
    static void dumpList();
    static void createHeap(int heapId, const char* heapName, int memArena, int heapSize);

    static void* alloc(Heaps::HeapType heapType, size_t size);
    static void* alloc(Heaps::HeapType heapType, size_t size, s32 align);
    static void* allocClear(Heaps::HeapType heapType, size_t size);
    static void free(void* ptr);
    static MEMAllocator* getMEMAllocator(Heaps::HeapType heapType);
    static void* getHeap(Heaps::HeapType heapType);
};
