#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <ac/ac_anim_cmd_impl.h>
#include <so/collision/so_collision_attack_part.h>

class soModuleAccesser;
class BaseItem;

// TODO: Throw the event observers in the respective modules once they're done
// TODO: Verify parameters

template <class T>
class soEventObserver {
    virtual void addObserver(int param1, int param2);
    short _4;
    short _6;
    short m_sendID;

    STATIC_CHECK(sizeof(soEventObserver) == 8)
};

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soAnimCmdEventObserver) == 12)
};

class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soLinkEventObserver) == 12)
};

class soStatusEventObserver : public soEventObserver<soStatusEventObserver> {
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soStatusEventObserver) == 12)
};

class soSituationEventObserver : public soEventObserver<soSituationEventObserver> {
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soSituationEventObserver) == 12)
};

class soCollisionAttackEventObserver : public soEventObserver<soCollisionAttackEventObserver> {
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    char _spacer1[1];
    char _pad[1];

    STATIC_CHECK(sizeof(soCollisionAttackEventObserver) == 12)
};

class soCollisionHitEventObserver : public soEventObserver<soCollisionHitEventObserver> {
    virtual void notifyEventCollisionHit(float, int, int index, int, soModuleAccesser* moduleAccesser, void*);
    virtual void notifyEventCollisionHit2nd(float, float, void*, void*, int index, int, bool);
    virtual void notifyEventChangeCollisionHit(int index, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soCollisionHitEventObserver) == 12)
};


class soCollisionShieldEventObserver : public soEventObserver<soCollisionShieldEventObserver> {
    virtual void notifyEventCollisionShield(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShieldSearch(void*, void*);
    virtual bool notifyEventCollisionShieldCheck();
    char _spacer1[2];
    STATIC_CHECK(sizeof(soCollisionShieldEventObserver) == 12)
};

class soCollisionReflectorEventObserver : public soEventObserver<soCollisionReflectorEventObserver> {
    virtual void notifyEventCollisionReflector(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser); // TODO: This is a guess based on above
    virtual void notifyEventCollisionReflectorSearch(int,int,int);
    virtual bool notifyEventCollisionReflectorCheck();
    char _spacer1[2];
    STATIC_CHECK(sizeof(soCollisionReflectorEventObserver) == 12)
};

class soCollisionAbsorberEventObserver : public soEventObserver<soCollisionAbsorberEventObserver> {
    virtual void notifyEventCollisionAbsorber(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAbsorberCheck();
    char _spacer1[2];

    STATIC_CHECK(sizeof(soCollisionAbsorberEventObserver) == 12)
};

class soCollisionSearchEventObserver : public soEventObserver<soCollisionSearchEventObserver> {
    virtual void notifyEventCollisionSearch(void*, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
    char _spacer1[2];
    STATIC_CHECK(sizeof(soCollisionSearchEventObserver) == 12)
};

struct soGimmickEventInfo {
    int m_state;
    int m_sendID;
};

struct grGimmickEventSpringInfo : soGimmickEventInfo {
    Vec3f m_topPos;
    float m_bounce;
    float m_rot;
};

struct grGimmickEventCatapultInfo : soGimmickEventInfo {
    char _8[0xc];
    float m_motionRatio;
    char _24[4];
};

struct grGimmickEventDoorInfo : soGimmickEventInfo {
    Vec3f m_pos;
    bool m_unk2;
};

struct grGimmickEventBarrelCannonInfo : soGimmickEventInfo {
    Vec3f m_pos;
    unsigned int m_20;
    soCollisionAttackData* m_attackData;
    float m_shootSpeed;
    float m_rot;
    float m_shootTimerSpeed;
    float m_shootAngleOffset;
    float m_shootStunTimerSpeed;
};

struct grGimmickEventElevatorInfo : soGimmickEventInfo {
    bool m_canGoUp;
    bool m_canGoDown;
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
    virtual void notifyEventGimmick(soGimmickEventInfo *eventInfo,int *taskId);
    char _spacer1[2];
    STATIC_CHECK(sizeof(soGimmickEventObserver) == 12)
};

class soCaptureEventObserver : public soEventObserver<soCaptureEventObserver> {
    virtual bool notifyEventCaptureStatus(soModuleAccesser* moduleAccesser, int taskId, int, int);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soCaptureEventObserver) == 12)
};

class soItemManageEventObserver : public soEventObserver<soItemManageEventObserver> {
    virtual bool notifyHaveItemPreCheck(BaseItem* item, bool*);
    virtual void notifyHaveItem(int, BaseItem* item, int, int, int);
    virtual void notifyAttachItem(BaseItem* item, int, int, int, int);
    virtual void notifyUseItem(BaseItem* item, int, int*);
    virtual void notifyThrowItem(BaseItem* item, int, int*);
    virtual void notifyDropItem();
    virtual void notifyShootBulletItem(BaseItem* item);
    virtual void notifyEjectItem(BaseItem* item, int);
    virtual void notifyEjectAttachItem(BaseItem* item, int, int);
    virtual void notifyVisibilityItem(BaseItem* item, int, int, int);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soItemManageEventObserver) == 12)
};

class soMotionEventObserver : public soEventObserver<soMotionEventObserver> {
    virtual void notifyEventChangeMotion(int, int, void*, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soMotionEventObserver) == 12)
};

class soDamageEventObserver : public soEventObserver<soDamageEventObserver> {
    virtual void notifyEventOnDamage(float*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventAddDamage(float*, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soDamageEventObserver) == 12)
};

class soTurnEventObserver : public soEventObserver<soTurnEventObserver> {
    virtual void notifyEventTurn(float, float, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soTurnEventObserver) == 12)
};

class soModelEventObserver : public soEventObserver<soModelEventObserver> {
    virtual void notifyEventConstructInstance(bool, soModuleAccesser* moduleAccesser);
    virtual void notifyEventDestructInstance(soModuleAccesser* moduleAccesser);

    char _spacer1[2];

    STATIC_CHECK(sizeof(soModelEventObserver) == 12)
};
