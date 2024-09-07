#pragma once

#include <StaticAssert.h>
#include <types.h>

class muSelCharCBCalcWorld {
public:
    virtual ~muSelCharCBCalcWorld();
    virtual void ExecCallback_CALC_WORLD(u32, u32);
    virtual void ExecCallback_CALC_MAT(u32);
    virtual void ExecCallback_CALC_VIEW(u32);
    virtual void ExecCallback_DRAW_OPA(u32);
    virtual void ExecCallback_DRAW_XLU(u32);

    char _0[0x8];
};

static_assert(sizeof(muSelCharCBCalcWorld) == 0xC, "Wrong size for class!");