#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <gm/gm_global_mode_melee.h>

class stOperator : public gfTask {
public:
    u8 m_state;
    bool m_isStart;
    bool m_isExit;
    bool m_isPause;
    gmGlobalModeMelee* m_condition;

    virtual void processBegin();
    virtual ~stOperator();

    STATIC_CHECK(sizeof(stOperator) == 72)

};