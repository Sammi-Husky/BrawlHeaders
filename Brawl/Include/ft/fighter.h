#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <so/stageobject.h>
#include <ft/ft_owner.h>

class ftEntryEventObserver : public soEventObserver<ftEntryEventObserver> {
    virtual void notifyEventSetDamage(float);
    virtual void notifyEventBeat();
    virtual void notifyEventDeadPartner(int index);
    virtual void notifyEventPartnerResourcePrepared();
    virtual void notifyEventChangeAdvUnit();
    virtual void notifyEventWarp();
    virtual void notifyEventPokemonStart(int);
    virtual void notifyEventPokemonRequestChange(Vec3f*, float*);
    virtual void notifyEventPokemonTrainerUpdate();
    virtual void notifyEventPokemonCollect();
    virtual void notifyEventPokemonChangeCancel();
    virtual void notifyEventPokemonSpecial(int, int);
    virtual void notifyEventPokemonAppeal();
    virtual void notifyEventSetRumble(int, int);
    virtual void notifyEventStopRumble(int);
    virtual void notifyEventPokemonRebirthEnd();
    virtual void notifyEventPokemonAttack();
    virtual void notifyEventPokemonInflict();
    virtual void notifyEventPokemonDamage();
    virtual void notifyEventPokeTrainerReplace(u8);
    virtual void notifyEventPikminFinalAttack(float, int);
    virtual void notifyEventKirbyResourceLoaded(int index);
    virtual void notifyEventKirbyResourceUnLoaded(int index);
    virtual void notifyEventExitFighter(int, int);
    char _spacer1[2];

    STATIC_CHECK(sizeof(ftEntryEventObserver) == 12)
};

class Fighter : public StageObject, public soStatusEventObserver, public soSituationEventObserver,
        public soCollisionAttackEventObserver, public soCollisionHitEventObserver, public soCollisionShieldEventObserver,
        public soCollisionReflectorEventObserver, public soCollisionAbsorberEventObserver, public soCollisionSearchEventObserver,
        public soCaptureEventObserver, public soItemManageEventObserver, public soMotionEventObserver, public soDamageEventObserver,
        public ftEntryEventObserver, public soTurnEventObserver {
public:
    int entryId;
    char _spacer2[60];

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
    virtual void onStartFinal();
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
    virtual void change(void*,int);
    virtual void touchItem(void*);
    virtual bool setMetal(bool setStatus, float health, int unk3);
    virtual void onSetMetal(bool);
    virtual void onHitReflector(soModuleAccesser* moduleAccesser, bool);
    virtual void dropItemCheck(void*, bool);
    virtual bool isHeartSwapEnableCondition();
    virtual void analyzeSeal(void*);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackFighter(void* unk, soModuleAccesser* moduleAccesser);
    virtual ftOwner* getOwner();
    virtual int getFtKind();
    virtual bool isInclude(float* rect, Vec3f* out);
    virtual void eatItem(void*);
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    virtual void notifyEventCollisionShield(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShieldSearch(void*, void*);
    virtual bool notifyEventCollisionShieldCheck();
    virtual void notifyEventCollisionReflector(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser); // TODO: This is a guess based on above
    virtual void notifyEventCollisionReflectorSearch(int,int,int);
    virtual bool notifyEventCollisionReflectorCheck();
    virtual void notifyEventCollisionAbsorber(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAbsorberCheck();
    virtual bool notifyEventCaptureStatus(soModuleAccesser* moduleAccesser, int taskId, int, int);
    virtual void notifyEventCollisionSearch(void*, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
    virtual void notifyEventChangeCollisionHit(int index, soModuleAccesser* moduleAccesser);
    virtual void notifyEventOnDamage(float*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventAddDamage(float*, soModuleAccesser* moduleAccesser);
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

    void setCurry(bool setStatus, int unk2);
    void setHammer(bool setStatus, int unk2);
    void setSuperStar(bool setStatus, int unk2, bool unk3);
    void setFlower(bool setStatus, float rate, float size, int unk4, bool unk5);
    void setSlow(bool setStatus, int slowStrength, int duration, bool useTimerEffect);
    void setHeartSwap(int givingPlayerEntryID, int givingPlayerEntryId, bool setStatus);
    void startScaling(bool setStatus, bool isPoison);
    void warp(Vec3f* pos, float lr, bool showEffect);

    STATIC_CHECK(sizeof(Fighter) == 332)
};