#pragma once

#include <so/collision/so_collision_attack_part.h>
#include <st/st_trigger_observe.h>
#include <types.h>

namespace Gimmick {
    enum EventKind {
        Barrel_Event_In = 0x2,
        Barrel_Event_Shoot_Trigger = 0x3,
        Barrel_Event_Shoot = 0x4,
        Barrel_Event_Set_Speed = 0x5,
        Barrel_Event_Set_Path = 0x6,
        Barrel_Event_End_Path = 0x7,
        Barrel_Event_Break = 0x8,
        Barrel_Event_Pos = 0x9,

        Event_On = 0xC,
        Event_Shoot = 0xD,
        Event_Pos = 0xE,

        Door_Event_In = 0x11,

        Ladder_Event_Get_Info = 0x14,

        Spring_Event_On = 0x17,
        Spring_Event_Shoot = 0x18,
        Spring_Event_Pos = 0x19,

        Chappy_Event_In = 0x27,
        Chappy_Event_Pos = 0x28,

        Event_Boot = 0x32,
        Event_Exit = 0x33,
        Event_Disable = 0x34,
    };
}


struct soGimmickEventInfo {
    Gimmick::EventKind m_kind;
    int m_sendID;
};

struct soGimmickSpringEventInfo : soGimmickEventInfo {
    Vec3f m_topPos;
    float m_bounce;
    float m_rot;
};

struct soGimmickLadderEventInfo : soGimmickEventInfo {
    Vec3f m_upperNodePos;
    Vec3f m_underNodePos;
    bool m_restrictUpExit;
    bool m_33;
};

struct soGimmickCatapultEventInfo : soGimmickEventInfo {
    float m_8;
    float m_12;
    float m_lr;
    float m_launchSpeed;
    float m_vector;
};

struct soGimmickDoorEventInfo : soGimmickEventInfo {
    Vec3f m_pos;
    bool m_unk2;
};

struct soGimmickBarrelEventInfo : soGimmickEventInfo {
    Vec3f m_pos;
    unsigned int m_20;
    soCollisionAttackData* m_attackData;
    float m_shootSpeed;
    float m_rot;
    float m_shootTimerSpeed;
    float m_shootAngleOffset;
    float m_shootStunTimerSpeed;
};

struct soGimmickElevatorEventInfo : soGimmickEventInfo {
    bool m_canGoUp;
    bool m_canGoDown;
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
public:
    soGimmickEventObserver() : soEventObserver<soGimmickEventObserver>(0x3) {};
    soGimmickEventObserver(short unitID) : soEventObserver<soGimmickEventObserver>(unitID) {};
    soGimmickEventObserver(short param1, s8 param2);

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventGimmick(soGimmickEventInfo* eventInfo, int* taskId);
};
static_assert(sizeof(soGimmickEventObserver) == 12, "Class is wrong size!");

