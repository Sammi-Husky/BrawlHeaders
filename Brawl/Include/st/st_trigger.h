#pragma once

#include <types.h>
#include <gf/gf_task.h>
#include <st/st_trigger_observe.h>
#include <ut/ut_list.h>
#include <yk/yakumono.h>
#include <StaticAssert.h>

enum GimmickKind {
    GimmickKind_Valid = 0x0,
    GimmickKind_RebirthPoint = 0x5,
    GimmickKind_TruckReactor = 0x6,
    GimmickKind_Wind = 0xc,
    GimmickKind_Wind2nd = 0xd,
    GimmickKind_BeltConveyor = 0xe,
    GimmickKind_Yuka = 0xf,
    GimmickKind_Pow = 0x10,
    GimmickKind_Water = 0x11,
    GimmickKind_HitPointEffect = 0x12,
    GimmickKind_ScrollLock = 0x15,
    GimmickKind_AreaCommon = 0x1e,
    GimmickKind_BarrelCannonStatic = 0x1f,
    GimmickKind_BarrelCannonPath = 0x20,
    GimmickKind_BarrelCannonStaticAuto = 0x21,
    GimmickKind_BarrelCannonPathAuto = 0x22,
    GimmickKind_Spring = 0x23,
    GimmickKind_Catapult = 0x24,
    GimmickKind_Ladder = 0x25,
    GimmickKind_DoorGround = 0x28,
    GimmickKind_DoorAir = 0x29,
    GimmickKind_DoorGroundAuto = 0x2a,
    GimmickKind_DoorAirAuto = 0x2b,
    GimmickKind_WarpZone = 0x2c,
    GimmickKind_Savepoint = 0x2d,
    GimmickKind_Eat = 0x2f,
    GimmickKind_MotionPath = 0x32,
    GimmickKind_Elevator = 0x35,
    GimmickKind_Truck = 0x3a,
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

    STATIC_CHECK(sizeof(stTrigger) == 52)
};

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

    STATIC_CHECK(sizeof(stTriggerMng) == 100)
};

extern stTriggerMng* g_stTriggerMng;