#pragma once

struct OSThread {
    char UNK_0x0[0x304];
    void* mStackTop;
    void* mStackBottom;
    char UNK_0x30C[0xC];
};

void OSCreateThread(OSThread* thread, void* (*func)(void*), void* param, void* stack, u32 stackSize, int priority, int attr);
bool OSJoinThread(OSThread* thread, void** val);
int OSResumeThread(OSThread* thread);