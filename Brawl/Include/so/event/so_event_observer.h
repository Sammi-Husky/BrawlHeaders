#pragma once

#include <StaticAssert.h>
#include <ac/ac_anim_cmd_impl.h>
#include <gf/gf_task.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/damage/so_damage.h>
#include <so/event/so_event_system.h>
#include <types.h>

class soModuleAccesser;
class StageObject;
class BaseItem;
class soCollisionAttackModule;
class soCollisionSearchModule;
class soCollisionLog;

// TODO: Throw the event observers in the respective modules once they're done
// TODO: Verify parameters

template <class T>
class soEventObserver {
public:
    virtual void addObserver(int param1, int param2);
    short m_manageID;
    short m_unitID;
    short m_sendID;

    soEventObserver(short unitID) {
        m_manageID = -1;
        m_unitID = unitID;
        m_sendID = -1;
    }

    void removeObserver() {
        if (soEventSystem::getInstance()->m_instanceManager.isContain(m_manageID)) {
            soEventSystem::getInstance()->getManager(m_manageID)->eraseObserver(m_unitID, m_sendID);
        }
        this->m_sendID = -1;
        this->m_manageID = -1;
    }

    ~soEventObserver() {
        removeObserver();
    }

    void setupObserver(short manageId) {
        bool bVar5 = false;
        bool bVar4 = false;
        bool bVar3 = false;
        bool bVar2 = false;
        if (-1 < m_manageID && -1 < m_unitID) {
            bVar2 = true;
        }
        if (bVar2 && -1 < m_sendID) {
            bVar3 = true;
        }
        if (bVar3) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(this->m_manageID)) {
                bVar4 = true;
            }
        }
        if (bVar4) {
            if (soEventSystem::getInstance()->getManager(this->m_manageID)->isExist(m_unitID)) {
                bVar5 = true;
            }
        }
        if (bVar5) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(this->m_manageID)) {
                soEventSystem::getInstance()->getManager(this->m_manageID)->eraseObserver(m_unitID, m_sendID);
            }
            m_sendID = -1;
            m_manageID = -1;
        }
        if (-1 < manageId && -1 < m_unitID) {
            if (soEventSystem::getInstance()->m_instanceManager.isContain(manageId)) {
                soEventManager* eventManager = soEventSystem::getInstance()->getManager(manageId);
                if (!eventManager->isNullUnit(m_unitID)) {
                    int sendId;
                    if (eventManager->isExist(m_unitID)) {
                        soEventUnitWrapper<T>* eventUnit = dynamic_cast<soEventUnitWrapper<T>*>(eventManager->getEventUnit(m_unitID));
                        if (eventUnit == NULL) {
                            sendId = -1;
                        }
                        else {
                            sendId = eventUnit->addObserverSub(static_cast<T*>(this), -1);
                        }
                    }
                    else {
                        sendId = -1;
                    }
                    this->m_sendID = sendId;
                    if (-1 < sendId) {
                        this->m_manageID = manageId;
                    }
                }
            }
        }
    }
};
static_assert(sizeof(soEventObserver<void>) == 0xC, "Class is wrong size!");

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
public:
    soAnimCmdEventObserver(short unitID) : soEventObserver<soAnimCmdEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
};
static_assert(sizeof(soAnimCmdEventObserver) == 12, "Class is wrong size!");

class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
public:
    soLinkEventObserver(short unitID) : soEventObserver<soLinkEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, StageObject*, int unk4);
};
static_assert(sizeof(soLinkEventObserver) == 12, "Class is wrong size!");

struct soStatusData {
};

class soStatusEventObserver : public soEventObserver<soStatusEventObserver> {
public:
    soStatusEventObserver(short unitID) : soEventObserver<soStatusEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soStatusEventObserver) == 12, "Class is wrong size!");

class soSituationEventObserver : public soEventObserver<soSituationEventObserver> {
public:
    soSituationEventObserver(short unitID) : soEventObserver<soSituationEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soSituationEventObserver) == 12, "Class is wrong size!");

class soCollisionAttackEventObserver : public soEventObserver<soCollisionAttackEventObserver> {
public:
    soCollisionAttackEventObserver(short unitID) : soEventObserver<soCollisionAttackEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
};
static_assert(sizeof(soCollisionAttackEventObserver) == 12, "Class is wrong size!");

class soCollisionHitEventObserver : public soEventObserver<soCollisionHitEventObserver> {
public:
    soCollisionHitEventObserver(short unitID) : soEventObserver<soCollisionHitEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionHit(float, int, int index, int, soModuleAccesser* moduleAccesser, void*);
    virtual void notifyEventCollisionHit2nd(float, float, void*, void*, int index, int, bool);
    virtual void notifyEventChangeCollisionHit(int index, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soCollisionHitEventObserver) == 12, "Class is wrong size!");

class soCollisionShieldEventObserver : public soEventObserver<soCollisionShieldEventObserver> {
public:
    soCollisionShieldEventObserver(short unitID) : soEventObserver<soCollisionShieldEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionShield(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionShieldSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionShieldCheck();
};
static_assert(sizeof(soCollisionShieldEventObserver) == 12, "Class is wrong size!");

class soCollisionReflectorEventObserver : public soEventObserver<soCollisionReflectorEventObserver> {
public:
    soCollisionReflectorEventObserver(short unitID) : soEventObserver<soCollisionReflectorEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionReflector(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionReflectorSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionReflectorCheck();
};
static_assert(sizeof(soCollisionReflectorEventObserver) == 12, "Class is wrong size!");

class soCollisionAbsorberEventObserver : public soEventObserver<soCollisionAbsorberEventObserver> {
public:
    soCollisionAbsorberEventObserver(short unitID) : soEventObserver<soCollisionAbsorberEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventCollisionAbsorber(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual bool notifyEventCollisionAbsorberCheck();
};
static_assert(sizeof(soCollisionAbsorberEventObserver) == 12, "Class is wrong size!");

class soCollisionSearchEventObserver : public soEventObserver<soCollisionSearchEventObserver> {
public:
    soCollisionSearchEventObserver(short unitID) : soEventObserver<soCollisionSearchEventObserver>(unitID) {};

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
    soGimmickEventObserver(short unitID) : soEventObserver<soGimmickEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventGimmick(soGimmickEventInfo* eventInfo, int* taskId);
};
static_assert(sizeof(soGimmickEventObserver) == 12, "Class is wrong size!");

class soCaptureEventObserver : public soEventObserver<soCaptureEventObserver> {
public:
    soCaptureEventObserver(short unitID) : soEventObserver<soCaptureEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual bool notifyEventCaptureStatus(soModuleAccesser* moduleAccesser, int taskId, int, int);
};
static_assert(sizeof(soCaptureEventObserver) == 12, "Class is wrong size!");

class soItemManageEventObserver : public soEventObserver<soItemManageEventObserver> {
public:
    soItemManageEventObserver(short unitID) : soEventObserver<soItemManageEventObserver>(unitID) {};

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
    soMotionEventObserver(short unitID) : soEventObserver<soMotionEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeMotion(int, int, void*, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soMotionEventObserver) == 12, "Class is wrong size!");

class soDamageEventObserver : public soEventObserver<soDamageEventObserver> {
public:
    soDamageEventObserver(short unitID) : soEventObserver<soDamageEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventOnDamage(soDamage* damage, bool, soModuleAccesser* moduleAccesser);
    virtual void notifyEventAddDamage(soDamage* damage, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soDamageEventObserver) == 12, "Class is wrong size!");

class soTurnEventObserver : public soEventObserver<soTurnEventObserver> {
public:
    soTurnEventObserver(short unitID) : soEventObserver<soTurnEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventTurn(float, float, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soTurnEventObserver) == 12, "Class is wrong size!");

class soModelEventObserver : public soEventObserver<soModelEventObserver> {
public:
    soModelEventObserver(short unitID) : soEventObserver<soModelEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventConstructInstance(bool, soModuleAccesser* moduleAccesser);
    virtual void notifyEventDestructInstance(soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soModelEventObserver) == 12, "Class is wrong size!");
