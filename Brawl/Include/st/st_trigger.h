#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <st/st_trigger_observe.h>
#include <types.h>
#include <ut/ut_list.h>
#include <yk/yakumono.h>

enum GimmickKind {
    Gimmick_Valid = 0x0,
    Gimmick_RebirthPoint = 0x5,
    Gimmick_TruckReactor = 0x6,
    Gimmick_Sound = 0xb,
    Gimmick_Wind = 0xc,
    Gimmick_Wind2nd = 0xd,
    Gimmick_BeltConveyor = 0xe,
    Gimmick_Yuka = 0xf,
    Gimmick_Pow = 0x10,
    Gimmick_Water = 0x11,
    Gimmick_HitPointEffect = 0x12,
    Gimmick_ScrollLock = 0x15,
    Gimmick_AreaCommon = 0x1e,
    Gimmick_BarrelCannonStatic = 0x1f,
    Gimmick_BarrelCannonPath = 0x20,
    Gimmick_BarrelCannonStaticAuto = 0x21,
    Gimmick_BarrelCannonPathAuto = 0x22,
    Gimmick_Spring = 0x23,
    Gimmick_Catapult = 0x24,
    Gimmick_Ladder = 0x25,
    Gimmick_DoorGround = 0x28,
    Gimmick_DoorAir = 0x29,
    Gimmick_DoorGroundAuto = 0x2a,
    Gimmick_DoorAirAuto = 0x2b,
    Gimmick_WarpZone = 0x2c,
    Gimmick_Savepoint = 0x2d,
    Gimmick_Eat = 0x2f,
    Gimmick_MotionPath = 0x32,
    Gimmick_Elevator = 0x35,
    Gimmick_Truck = 0x3a,
};

class stTrigger : public utListNode {

    GimmickKind m_gimmickKind;
    int m_id;
    char _spacer[8];
    stObsTriggerCB* m_obsTriggerCB;
    Yakumono* m_yakumono;
    char _spacer2[12];
    bool m_isValidFlag;
    char _spacer3[7];

public:
    void setObserveYakumono(Yakumono* yakumono);
    stObsTriggerSquareBeltConveyorCB* setBeltConveyorTrigger(grGimmickBeltConveyorData* gimmickAreaData);
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

    stTrigger* createTrigger(GimmickKind gimmickKind, int triggerId);
    stTrigger* createTrigger(GimmickKind gimmickKind, stTriggerData* triggerData);
    void setTriggerFlag(stTriggerData* triggerData);
    bool getTriggerFlag(stTriggerData* triggerData, bool defaultFlag);
};
static_assert(sizeof(stTriggerMng) == 100, "Class is wrong size!");

extern stTriggerMng* g_stTriggerMng;