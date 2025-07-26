#pragma once

#include <StaticAssert.h>
#include <types.h>

class gfErrorManager {
public:
    void notifyError(u32 p1, u32 p2);
    void notifyErrorRecovery(bool p1);
    static gfErrorManager* getInstance();
};
// TODO size assertion
