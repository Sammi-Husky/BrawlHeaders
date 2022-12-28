#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gf/gf_scene.h>
#include <st/operator/st_operator_rule_melee.h>

class scMelee : public gfScene {
public:
    void* m_loaderPlayers[7];
    void* m_loaderStage;
    char _40[12];
    void* m_loaderStageStarFox;
    char _56[8];
    void* m_operatorBgm;
    void* m_operatorAppearanceFighter;
    void* m_operatorReadyGo;
    void* m_operatorReadyGoSuddenDeath;
    char _76[4];
    stOperatorRule* m_operatorRuleGameMode;
    stOperatorRuleMelee* m_operatorRuleMelee;
    void* m_operatorNoContest;
    void* m_operatorNetwork;
    void* m_operatorController;
    void* m_operatorInfoMelee;
    void* m_operatorFighterRebirths[7];
    void* m_operatorFighterChange;
    void* m_operatorDefeatBoss;
    void* m_operatorEndProduction;
    void* m_operatorAppearanceHelper;
    char _152[4];
    void* m_operatorDebugIntrusions[2];
    void* m_operatorDebugFighterReset;
    void* m_operatorDebugStagePause;
    void* m_eventRule;
    char _176[36];
    int m_endNum;
    char _216[40];

    virtual void start();
    virtual void process();
    virtual void exit();
    virtual ~scMelee();
    virtual int getEndNum();

    STATIC_CHECK(sizeof(scMelee) == 256)
};
