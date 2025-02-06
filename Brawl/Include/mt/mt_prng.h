#pragma once

#include <types.h>

s32 randi(s32 max);
float randf();
void srandi(s32 seed);
s32 randseed(void);
float randaf(void);

class mtRand {
public:
    virtual void init(s32 p1);
    virtual s32 generate();
    virtual float randf();
    virtual s32 getMax();
    virtual s32 randi();
    s32 getSeed() { return seed; }
    void setSeed(s32 seed) { this->seed = seed; }

    mtRand(s32 v) : seed(v) { }

private:
    s32 seed;
    static const s32 MultVal = 0x41C64E6D;
    static const s32 AddVal = 0x3039;
};

struct mtPrngLog {
    u8 unk0[0x10];
    mtPrngLog(u32, void *);
};

struct mtPrngLogManager {
    u8 unk0[0xC];
    void addLog(mtPrngLog*);
};
