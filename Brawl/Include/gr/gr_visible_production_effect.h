#pragma once

#include <types.h>
#include <gr/gr_gimmick.h>

class grVisibleProductionEffect : public grVisibleProduction {
    virtual ~grVisibleProductionEffect();
    virtual void initialize();
    virtual void remove();
    virtual void productFlowStandby();
    virtual void productFlowStart();
    virtual void productFlowProducing();
    virtual void productFlowEnd();
    virtual void setForcedEnding();

    grGimmick* m_ground;
    char _spacer[52];
};
