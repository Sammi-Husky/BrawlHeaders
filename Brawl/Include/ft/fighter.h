#pragma once

#include <StaticAssert.h>
#include <ft/ft_entry.h>
#include <ft/ft_outside_event_presenter.h>
#include <ft/ft_owner.h>
#include <mt/mt_vector.h>
#include <so/stageobject.h>
#include <types.h>

class itCustomizerInterface;

class Fighter : public StageObject, public soStatusEventObserver, public soSituationEventObserver, public soCollisionAttackEventObserver, public soCollisionHitEventObserver, public soCollisionShieldEventObserver, public soCollisionReflectorEventObserver, public soCollisionAbsorberEventObserver, public soCollisionSearchEventObserver, public soCaptureEventObserver, public soItemManageEventObserver, public soMotionEventObserver, public soDamageEventObserver, public ftEntryEventObserver, public soTurnEventObserver {
public:
    int m_entryId;
    char _272[44];
    ftOutsideEventPresenter m_outsideEventPresenter;
    char _332[72];

    virtual void processUpdate();
    virtual void processFixPosition();
    virtual void processHit();
    virtual void processFixCamera();
    virtual void processEnd();
    virtual ~Fighter();

    // TODO: Verify parameters
    virtual void postCreate();
    virtual Fighter* getPartner();
    virtual void attachInstance();
    virtual void detachInstance();
    virtual void standbyAdvFollow();
    virtual void onStartFinal(int variantID = -1, itCustomizerInterface** customizer = NULL); // Note: Optional parameters for modding purposes to use custom customizers
    virtual void onEndFinal();
    virtual void toDead(int);
    virtual int checkDead();
    virtual void onDeadEnd();
    virtual void toKnockOut();
    virtual void activate();
    virtual void onActivate();
    virtual void onDeactivate();
    virtual void onStart(int);
    virtual void postStart(int);
    virtual void setCursor(bool);
    virtual void setNameCursor(bool);
    virtual void setLoupe(bool);
    virtual void setLoupeDamage(bool);
    virtual u32 getChangeSucceedOption();
    virtual void changeSucceedCore(void*, int);
    virtual void setupChangeSucceedWork(void*);
    virtual bool setupChangeSucceedEffect();
    virtual void change(void*, int);
    virtual void touchItem(void*);
    virtual bool setMetal(bool setStatus, float health, int unk3);
    virtual void onSetMetal(bool);
    virtual void onHitReflector(soModuleAccesser* moduleAccesser, bool);
    virtual void dropItemCheck(void*, bool);
    virtual bool isHeartSwapEnableCondition();
    virtual void analyzeSeal(void*);
    virtual void notifyEventCollisionAttack(float power, soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackFighter(void* unk, soModuleAccesser* moduleAccesser);
    virtual ftOwner* getOwner();
    virtual ftKind getFtKind();
    virtual bool isInclude(float* rect, Vec3f* out);
    virtual void eatItem(void*);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    virtual void notifyEventCollisionShield(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionShieldSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionShieldCheck();
    virtual void notifyEventCollisionReflector(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionReflectorSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionReflectorCheck();
    virtual void notifyEventCollisionAbsorber(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual bool notifyEventCollisionAbsorberCheck();
    virtual bool notifyEventCaptureStatus(soModuleAccesser* moduleAccesser, int taskId, int, int);
    virtual void notifyEventCollisionSearch(soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
    virtual void notifyEventChangeCollisionHit(int index, soModuleAccesser* moduleAccesser);
    virtual void notifyEventOnDamage(soDamage* damage, bool, soModuleAccesser* moduleAccesser);
    virtual void notifyEventAddDamage(soDamage* damage, soModuleAccesser* moduleAccesser);
    virtual void setTeam(int, int);
    virtual void setVisibility(int);
    virtual void notifyEventTurn(float, float, soModuleAccesser* moduleAccesser);
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
    virtual void notifyEventSetDamage(float);
    virtual void notifyEventChangeAdvUnit();
    virtual void notifyEventBeat();
    virtual void playEatSE();
    virtual void onInhaled();
    virtual bool isInhaled();
    virtual void offInhaled();
    virtual void notifyEventPikminFinalAttack(float, int);
    virtual void trainerStart(float, Vec3f*, Vec3f*, int, bool);
    virtual void trainerRestart(float*, bool, bool);
    virtual void disappear(bool);
    virtual bool isEnableCancel();
    virtual void* getCancelModule();
    virtual void* getStatusGimmickUniqProcessPool();
    virtual void* getVirtualNodeMatrixPool();

    void start(Vec3f* pos, float lr, float damage, int, bool);
    void setCurry(bool setStatus, int unk2);
    void setHammer(bool setStatus, int unk2);
    void setSuperStar(bool setStatus, int unk2, bool unk3);
    void setFlower(bool setStatus, float rate, float size, int unk4, bool unk5);
    void setSlow(bool setStatus, int slowStrength, int duration, bool useTimerEffect);
    void setHeartSwap(int givingPlayerEntryID, int givingPlayerEntryId, bool setStatus);
    void startScaling(bool setStatus, bool isPoison);
    void warp(Vec3f* pos, float lr, bool showEffect);
};
static_assert(sizeof(Fighter) == 404, "Class is wrong size!");