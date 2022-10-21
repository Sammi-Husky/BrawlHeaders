#pragma once

#include <gf/gf_task.h>
#include <st/st_trigger_observe.h>
#include <yk/yakumono.h>
#include <ut/ut_list.h>

enum GimmickKind {
    Gimmick_Kind_Valid = 0x0,
    Gimmick_Kind_AreaCommon = 0x1e,
    Gimmick_Kind_Cannon1 = 0x1f,
    Gimmick_Kind_Cannon2 = 0x20,
    Gimmick_Kind_Cannon3 = 0x21,
    Gimmick_Kind_Cannon4 = 0x22,
    Gimmick_Kind_Spring = 0x23,
    Gimmick_Kind_Catapult = 0x24,
    Gimmick_Kind_Ladder = 0x25,
    Gimmick_Kind_DoorOpen = 0x28,
    Gimmick_Kind_DoorEnterGround = 0x29,
    Gimmick_Kind_DoorEnterAir = 0x2a,
    Gimmick_Kind_DoorEnterUnk = 0x2b,
    Gimmick_Kind_Savepoint = 0x2d,
    Gimmick_Kind_Eat = 0x2f,
    Gimmick_Kind_Elevator = 0x35,
    Gimmick_Kind_Truck = 0x3a,
};

struct stTriggerData {
    unsigned short triggerId;
    bool isValidFlag;
    char unk2;
};

class stTrigger : public utListEntry {
    GimmickKind gimmickKind;
    int id;
    char _spacer[8];
    stObsTriggerCB* obsTriggerCB;
    Yakumono* yakumono;
    char _spacer2[12];
    bool isValidFlag;
    char _spacer3[7];

    public:
        void setObserveYakumono(Yakumono* yakumono);
};

class stTriggerMng : public gfTask {
    utListHead triggerHead;
    char _spacer[21];
    public:

        virtual void processBegin();
        virtual void processFix();
        virtual void processGameProc();
        virtual ~stTriggerMng();

        stTrigger* createTrigger(GimmickKind gimmickKind, int triggerId);
        stTrigger* createTrigger(GimmickKind gimmickKind, stTriggerData* triggerData);
        void setTriggerFlag(stTriggerData* triggerData);
};

extern stTriggerMng* g_stTriggerMng;