#pragma once

#include <types.h>

struct OSThread {
    char UNK_0x0[0x304];
    void* mStackTop;
    void* mStackBottom;
    char UNK_0x30C[0xC];
};

enum OS_THREAD_ATTR {
    OS_THREAD_ATTR_ATTACH,
    OS_THREAD_ATTR_DETACH
};

void OSCreateThread(OSThread* thread, void* (*func)(void*), void* param, void* stack, u32 stackSize, int priority, OS_THREAD_ATTR attr);
bool OSJoinThread(OSThread* thread, void** val);
int OSResumeThread(OSThread* thread);