#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <st/operator/st_operator.h>

class stOperatorRule : public stOperator {
public:
    void *m_operatorBgm;
    void *m_operatorNetwork;
    void *m_operatorController;
    char _20[32];
    bool m_isGameSet;
    char _53[87];

    virtual void processBegin();
    virtual ~stOperatorRule();
    virtual void setOperatorBgm(void*);
    virtual void setOperatorNetwork(void*);
    virtual void setOperatorController(void*);
    virtual bool isGameSet();
    virtual bool isEnd();
    virtual void startOperator();
    virtual void calcScore();
    virtual bool isSuddenDeath();
    virtual void adjustResultInfo();
    virtual void notifyEventKnockout(u32);
    virtual bool notifyEventDead(int entryId, u32 playerIndex, int);
    virtual void notifyEventStartStage();
    virtual void notifyEventSetupCorps();
    virtual void notifyEventBeat(u32 playerIndex1, u32 playerIndex2);
    virtual void notifyEventYoshiEgg();
    virtual void notifyEventPikminBloom();
    virtual void nortifyNetworkOtherNodeExit();
    virtual void networkWriteRanking();
    virtual void setOpAppearanceHelper(void*);

    STATIC_CHECK(sizeof(stOperatorRule) == 204)
};
