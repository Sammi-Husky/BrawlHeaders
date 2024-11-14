#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <st/st_trigger_observe.h>
#include <types.h>
#include <ut/ut_list.h>
#include <yk/yakumono.h>

enum GimmickAreaKind {
    Gimmick_Area_None = 0x0,
    Gimmick_Area_RebirthPoint = 0x5,
    Gimmick_Area_Reactor = 0x6,
    Gimmick_Area_Camera = 0x7,
    Gimmick_Area_Sound = 0xb,
    Gimmick_Area_Wind = 0xc,
    Gimmick_Area_Wind_2nd = 0xd,
    Gimmick_Area_BeltConveyor = 0xe,
    Gimmick_Area_Yuka = 0xf,
    Gimmick_Area_Pow = 0x10,
    Gimmick_Area_Water = 0x11,
    Gimmick_Area_HitPoint_Effect = 0x12,
    Gimmick_Area_ScrollLock = 0x15,
    Gimmick_Area_Common = 0x1e,
    Gimmick_Area_Barrel_Natural = 0x1f,
    Gimmick_Area_Barrel_Path = 0x20,
    Gimmick_Area_Barrel_Natural_Auto  = 0x21,
    Gimmick_Area_Barrel_Path_Auto = 0x22,
    Gimmick_Area_Spring = 0x23,
    Gimmick_Area_Catapult = 0x24,
    Gimmick_Area_Ladder = 0x25,
    Gimmick_Area_Door = 0x28,
    Gimmick_Area_Door_Air = 0x29,
    Gimmick_Area_Door_Auto = 0x2a,
    Gimmick_Area_Block = 0x2b,
    Gimmick_Area_Warp = 0x2c,
    Gimmick_Area_SavePoint = 0x2d,
    Gimmick_Area_Peripheral_Lock = 0x2f,
    Gimmick_Area_MotionPath = 0x32,
    Gimmick_Area_Elevator = 0x35,
    Gimmick_Area_Truck = 0x3a,

    // alternate names
    Gimmick_Area_Barrel_Static = 0x1f,
    Gimmick_Area_Barrel_Static_Auto  = 0x21,
};

class stTrigger : public utListNode {

    GimmickAreaKind m_gimmickAreaKind;
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

    void setAreaSleep(u32 p1);
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

    stTrigger* createTrigger(GimmickAreaKind gimmickKind, int triggerId);
    stTrigger* createTrigger(GimmickAreaKind gimmickKind, stTriggerData* triggerData);
    void setTriggerFlag(stTriggerData* triggerData);
    bool getTriggerFlag(stTriggerData* triggerData, bool defaultFlag);
};
static_assert(sizeof(stTriggerMng) == 100, "Class is wrong size!");

extern stTriggerMng* g_stTriggerMng;