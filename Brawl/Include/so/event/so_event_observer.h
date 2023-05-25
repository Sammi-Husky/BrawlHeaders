#pragma once

#include <StaticAssert.h>
#include <ac/ac_anim_cmd_impl.h>
#include <gf/gf_task.h>
#include <so/collision/so_collision_attack_part.h>
#include <types.h>

class soModuleAccesser;
class StageObject;
class BaseItem;

// TODO: Throw the event observers in the respective modules once they're done
// TODO: Verify parameters

template <class T>
class soEventObserver {
public:
    virtual void addObserver(int param1, int param2);
    short m_manageID;
    short m_6;
    short m_sendID;

    inline soEventObserver() {
        m_manageID = -1;
        m_6 = 0;
        m_sendID = -1;
    }
};
static_assert(sizeof(soEventObserver<void>) == 0xC, "Class is wrong size!");

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
};
static_assert(sizeof(soAnimCmdEventObserver) == 12, "Class is wrong size!");

class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, StageObject*, int unk4);
};
static_assert(sizeof(soLinkEventObserver) == 12, "Class is wrong size!");

class soStatusEventObserver : public soEventObserver<soStatusEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soStatusEventObserver) == 12, "Class is wrong size!");

class soSituationEventObserver : public soEventObserver<soSituationEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soSituationEventObserver) == 12, "Class is wrong size!");

class soCollisionAttackEventObserver : public soEventObserver<soCollisionAttackEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
};
static_assert(sizeof(soCollisionAttackEventObserver) == 12, "Class is wrong size!");

class soCollisionHitEventObserver : public soEventObserver<soCollisionHitEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionHit(float, int, int index, int, soModuleAccesser* moduleAccesser, void*);
    virtual void notifyEventCollisionHit2nd(float, float, void*, void*, int index, int, bool);
    virtual void notifyEventChangeCollisionHit(int index, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soCollisionHitEventObserver) == 12, "Class is wrong size!");

class soCollisionShieldEventObserver : public soEventObserver<soCollisionShieldEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionShield(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShieldSearch(void*, void*);
    virtual bool notifyEventCollisionShieldCheck();
};
static_assert(sizeof(soCollisionShieldEventObserver) == 12, "Class is wrong size!");

class soCollisionReflectorEventObserver : public soEventObserver<soCollisionReflectorEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionReflector(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser); // TODO: This is a guess based on above
    virtual void notifyEventCollisionReflectorSearch(int, int, int);
    virtual bool notifyEventCollisionReflectorCheck();
};
static_assert(sizeof(soCollisionReflectorEventObserver) == 12, "Class is wrong size!");

class soCollisionAbsorberEventObserver : public soEventObserver<soCollisionAbsorberEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionAbsorber(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAbsorberCheck();
};
static_assert(sizeof(soCollisionAbsorberEventObserver) == 12, "Class is wrong size!");

class soCollisionSearchEventObserver : public soEventObserver<soCollisionSearchEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionSearch(void*, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
};
static_assert(sizeof(soCollisionSearchEventObserver) == 12, "Class is wrong size!");

struct soGimmickEventInfo {
    int m_state;
    int m_sendID;
};

struct grGimmickEventSpringInfo : soGimmickEventInfo {
    Vec3f m_topPos;
    float m_bounce;
    float m_rot;
};

struct grGimmickEventLadderInfo : soGimmickEventInfo {
    Vec3f m_upperNode;
    Vec3f m_underNode;
    bool m_restrictUpExit;
    bool m_33;
};

struct grGimmickEventCatapultInfo : soGimmickEventInfo {
    float m_8;
    float m_12;
    float m_lr;
    float m_launchSpeed;
    float m_vector;
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
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventGimmick(soGimmickEventInfo* eventInfo, int* taskId);
};
static_assert(sizeof(soGimmickEventObserver) == 12, "Class is wrong size!");

class soCaptureEventObserver : public soEventObserver<soCaptureEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual bool notifyEventCaptureStatus(soModuleAccesser* moduleAccesser, int taskId, int, int);
};
static_assert(sizeof(soCaptureEventObserver) == 12, "Class is wrong size!");

class soItemManageEventObserver : public soEventObserver<soItemManageEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
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
};
static_assert(sizeof(soItemManageEventObserver) == 12, "Class is wrong size!");

class soMotionEventObserver : public soEventObserver<soMotionEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeMotion(int, int, void*, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soMotionEventObserver) == 12, "Class is wrong size!");

class soDamageEventObserver : public soEventObserver<soDamageEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventOnDamage(float*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventAddDamage(float*, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soDamageEventObserver) == 12, "Class is wrong size!");

class soTurnEventObserver : public soEventObserver<soTurnEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventTurn(float, float, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soTurnEventObserver) == 12, "Class is wrong size!");

class soModelEventObserver : public soEventObserver<soModelEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventConstructInstance(bool, soModuleAccesser* moduleAccesser);
    virtual void notifyEventDestructInstance(soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soModelEventObserver) == 12, "Class is wrong size!");
