#pragma once

#include <types.h>

namespace gfMemoryPool {
    static void* alloc(void* heapAddr, size_t size, int align);
    static void* create(void* heapAddr, size_t size, const char* heapName);

    /**
     * @brief Custom function to create a memory pool at a specific address
     *
     * @param heapAddr Start address of the memory pool
     * @param heapName Name to assign the memory pool
     * @param heapID ID of the memory pool
     * @param size Size of the memory pool
     * @param arena Whether this pool resides in MEM1 or MEM2
     */
    static void* create(void* heapAddr, const char* heapName, int heapID, size_t size, int arena)
    {
        void* pool = create(heapAddr, size, heapName);
        *(u32*)(0x80494958 + (heapID * 0x10) + 0x0) = (u32)heapName;
        *(u32*)(0x80494958 + (heapID * 0x10) + 0x4) = (u32)heapAddr;
        *(u32*)(0x80494958 + (heapID * 0x10) + 0x8) = (u32)size;
        *(u32*)(0x80494958 + (heapID * 0x10) + 0xC) = (u32)arena;
        return pool;
    }
} // namespace gfMemoryPool
