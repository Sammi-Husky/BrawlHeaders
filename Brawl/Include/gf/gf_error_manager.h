#pragma once

#include <StaticAssert.h>
#include <types.h>

class gfErrorManager {
public:
    bool unk0_b7 : 1;
    bool unk0_b6 : 1;
    bool unk0_b5 : 1;
    bool unk0_b4 : 1;
    bool unk0_b3 : 1;

    void notifyError(u32 p1, u32 p2);
    void notifyErrorRecovery(bool p1);
    static gfErrorManager* getInstance();
};
// TODO size assertion
