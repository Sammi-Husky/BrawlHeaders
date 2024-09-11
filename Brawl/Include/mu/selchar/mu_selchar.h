#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <types.h>

class muSelCharPlayerArea;

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

class muSelCharTask : public gfTask {
public:
    char _0x40[4];
    muSelCharPlayerArea* m_selCharPlayerAreas[4];
    char _0x54[0x600];

    virtual void processDefault();
    virtual ~muSelCharTask();

    void dispHighScore(int, int, int);
};

static_assert(sizeof(muSelCharTask) == 0x654, "Wrong size for class!");