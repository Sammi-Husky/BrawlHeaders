#pragma once

#include <types.h>
#include <gf/gf_task.h>
#include <st/st_trigger_observe.h>
#include <ut/ut_list.h>
#include <yk/yakumono.h>

enum GimmickKind {
    Gimmick_Kind_Valid = 0x0,
    Gimmick_Kind_RebirthPoint = 0x5,
    Gimmick_Kind_Wind = 0xc,
    Gimmick_Kind_Wind2nd = 0xd,
    Gimmick_Kind_BeltConveyor = 0xe,
    Gimmick_Kind_Yuka = 0xf,
    Gimmick_Kind_Pow = 0x10,
    Gimmick_Kind_Water = 0x11,
    Gimmick_Kind_HitPointEffect = 0x12,
    Gimmick_Kind_ScrollLock = 0x15,
    Gimmick_Kind_AreaCommon = 0x1e,
    Gimmick_Kind_BarrelCannonStatic = 0x1f,
    Gimmick_Kind_BarrelCannonPath = 0x20,
    Gimmick_Kind_BarrelCannonStaticAuto = 0x21,
    Gimmick_Kind_BarrelCannonPathAuto = 0x22,
    Gimmick_Kind_Spring = 0x23,
    Gimmick_Kind_Catapult = 0x24,
    Gimmick_Kind_Ladder = 0x25,
    Gimmick_Kind_DoorGround = 0x28,
    Gimmick_Kind_DoorAir = 0x29,
    Gimmick_Kind_DoorGroundAuto = 0x2a,
    Gimmick_Kind_DoorUnk = 0x2b,
    Gimmick_Kind_WarpZone = 0x2c,
    Gimmick_Kind_Savepoint = 0x2d,
    Gimmick_Kind_Eat = 0x2f,
    Gimmick_Kind_Elevator = 0x35,
    Gimmick_Kind_Truck = 0x3a,
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
    struct TriggerData {
        unsigned short m_triggerId;
        int _padding : 31;
        bool m_isValidFlag : 1;
        char m_unk2;
    };

    void setObserveYakumono(Yakumono* yakumono);
    stObsTriggerSquareBeltConveyorCB* setBeltConveyorTrigger(SquareBeltConveyorGimmickAreaData* gimmickAreaData);
};

class stTriggerMng : public gfTask {
    utListHead m_triggerHead;
    char _spacer[21];

public:
    virtual void processBegin();
    virtual void processFix();
    virtual void processGameProc();
    virtual ~stTriggerMng();

    stTrigger* createTrigger(GimmickKind gimmickKind, int triggerId);
    stTrigger* createTrigger(GimmickKind gimmickKind, stTrigger::TriggerData* triggerData);
    void setTriggerFlag(stTrigger::TriggerData* triggerData);
    bool getTriggerFlag(stTrigger::TriggerData* triggerData, bool defaultFlag);
};

extern stTriggerMng* g_stTriggerMng;