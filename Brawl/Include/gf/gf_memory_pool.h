#pragma once

#include <types.h>

namespace gfMemoryPool {
    static void* alloc(void* heapAddr, size_t size, int align);
} // namespace gfMemoryPool
