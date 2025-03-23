#pragma once

#include <types.h>

s32 srSystemGetDebugLevel();
void* operator new(size_t size);
void* operator new(size_t size, Heaps::HeapType heap);
void operator delete(void* ptr);
void* operator new[](size_t size, Heaps::HeapType heap);
void operator delete[](void* ptr);
