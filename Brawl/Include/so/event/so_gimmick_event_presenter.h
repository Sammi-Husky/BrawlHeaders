#pragma once

#include <so/collision/so_collision_attack_part.h>
#include <types.h>

enum GimmickEventKind {
    Gimmick_Barrel_Event_In = 0x2,
    Gimmick_Barrel_Event_Shoot_Trigger = 0x3,
    Gimmick_Barrel_Event_Shoot = 0x4,
    Gimmick_Barrel_Event_Set_Speed = 0x5,
    Gimmick_Barrel_Event_Set_Path = 0x6,
    Gimmick_Barrel_Event_End_Path = 0x7,
    Gimmick_Barrel_Event_Break = 0x8,
    Gimmick_Barrel_Event_Pos = 0x9,

    Gimmick_Catapult_Event_On = 0xC,
    Gimmick_Catapult_Event_Shoot = 0xD,
    Gimmick_Catapult_Event_Pos = 0xE,

    Gimmick_Door_Event_In = 0x11,

    Gimmick_Ladder_Event_Get_Info = 0x14,

    Gimmick_Spring_Event_On = 0x17,
    Gimmick_Spring_Event_Shoot = 0x18,
    Gimmick_Spring_Event_Pos = 0x19,

    Gimmick_Chappy_Event_In = 0x27,
    Gimmick_Chappy_Event_Pos = 0x28,

    Gimmick_Event_Boot = 0x32,
    Gimmick_Event_Exit = 0x33,
    Gimmick_Event_Disable = 0x34,
};

struct soGimmickEventInfo {
    GimmickEventKind m_kind;
    int m_sendID;
};

struct grGimmickSpringEventInfo : soGimmickEventInfo {
    Vec3f m_topPos;
    float m_bounce;
    float m_rot;
};

struct grGimmickLadderEventInfo : soGimmickEventInfo {
    Vec3f m_upperNode;
    Vec3f m_underNode;
    bool m_restrictUpExit;
    bool m_33;
};

struct grGimmickCatapultEventInfo : soGimmickEventInfo {
    float m_8;
    float m_12;
    float m_lr;
    float m_launchSpeed;
    float m_vector;
};

struct grGimmickDoorEventInfo : soGimmickEventInfo {
    Vec3f m_pos;
    bool m_unk2;
};

struct grGimmickBarrelEventInfo : soGimmickEventInfo {
    Vec3f m_pos;
    unsigned int m_20;
    soCollisionAttackData* m_attackData;
    float m_shootSpeed;
    float m_rot;
    float m_shootTimerSpeed;
    float m_shootAngleOffset;
    float m_shootStunTimerSpeed;
};

struct grGimmickElevatorEventInfo : soGimmickEventInfo {
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

