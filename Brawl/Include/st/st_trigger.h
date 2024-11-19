#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <st/st_trigger_observe.h>
#include <types.h>
#include <ut/ut_list.h>
#include <yk/yakumono.h>

class stTrigger : public utListNode {

    Gimmick::AreaKind m_gimmickAreaKind;
    int m_id;
    stTriggerData::KeepKind m_keepKind : 8;
    char _spacer[7];
    stObsTriggerCB* m_obsTriggerCB;
    Yakumono* m_yakumono;
    char _spacer2[12];
    bool m_isValid;
    char _spacer3[3];

public:
    virtual ~stTrigger();

    void setObserveYakumono(Yakumono* yakumono);
    stObsTriggerSquareBeltConveyorCB* setBeltConveyorTrigger(grGimmickBeltConveyorData* gimmickAreaData);
    stObsTriggerSquareHitPointEffectCB* setHitPointEffectTrigger(grGimmickHitPointEffectData* gimmickAreaData);
    stObsTriggerSquareWaterCB* setWaterTrigger(grGimmickWaterData* gimmickAreaData);
    stObsTriggerSquareWindCB* setWindTrigger(grGimmickWindData* gimmickAreaData);

    void setAreaSleep(bool);
    void setWindParam(grGimmickWindData2nd* wnd, s32 p2);


};
static_assert(sizeof(stTrigger) == 52, "Class is wrong size!");

class stTriggerMng : public gfTask {
    utList m_triggerList;
    char _spacer[24];

public:
    virtual void processBegin();
    virtual void processFix();
    virtual void processGameProc();
    virtual ~stTriggerMng();

    stTrigger* createTrigger(Gimmick::AreaKind gimmickKind, int triggerId);
    stTrigger* createTrigger(Gimmick::AreaKind gimmickKind, stTriggerData* triggerData);
    void setTriggerFlag(stTriggerData* triggerData);
    bool getTriggerFlag(stTriggerData* triggerData, bool defaultFlag);
};
static_assert(sizeof(stTriggerMng) == 100, "Class is wrong size!");

extern stTriggerMng* g_stTriggerMng;