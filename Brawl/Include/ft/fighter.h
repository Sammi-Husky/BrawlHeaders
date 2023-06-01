#pragma once

#include <StaticAssert.h>
#include <ft/ft_entry.h>
#include <ft/ft_outside_event_presenter.h>
#include <ft/ft_owner.h>
#include <mt/mt_vector.h>
#include <so/stageobject.h>
#include <types.h>

enum ftKind {
    Fighter_Mario = 0x0,
    Fighter_DonkeyKong = 0x1,
    Fighter_Donkey = 0x1,
    Fighter_Link = 0x2,
    Fighter_Samus = 0x3,
    Fighter_Yoshi = 0x4,
    Fighter_Kirby = 0x5,
    Fighter_Fox = 0x6,
    Fighter_Pikachu = 0x7,
    Fighter_Luigi = 0x7,
    Fighter_CaptainFalcon = 0x9,
    Fighter_Captain = 0x9,
    Fighter_Ness = 0xA,
    Fighter_Bowser = 0xb,
    Fighter_Koopa = 0xb,
    Fighter_Peach = 0xc,
    Fighter_Zelda = 0xd,
    Fighter_Sheik = 0xe,
    Fighter_Popo = 0xf,
    Fighter_Nana = 0x10,
    Fighter_Marth = 0x11,
    Fighter_MrGameAndWatch = 0x12,
    Fighter_GameWatch = 0x12,
    Fighter_Falco = 0x13,
    Fighter_Ganondorf = 0x14,
    Fighter_Ganon = 0x14,
    Fighter_Wario = 0x15,
    Fighter_MetaKnight = 0x16,
    Fighter_Pit = 0x17,
    Fighter_ZeroSuitSamus = 0x18,
    Fighter_SZeroSuit = 0x18,
    Fighter_Olimar = 0x19,
    Fighter_Pimin = 0x19,
    Fighter_Lucas = 0x1a,
    Fighter_DiddyKong = 0x1b,
    Fighter_Diddy = 0x1b,
    Fighter_PokemonTrainer = 0x1c,
    Fighter_PokeTrainer = 0x1c,
    Fighter_Charizard = 0x1d,
    Fighter_PokeLizardon = 0x1d,
    Fighter_Squirtle = 0x1e,
    Fighter_PokeZenigame = 0x1e,
    Fighter_Ivysaur = 0x1f,
    Fighter_PokeFushigisou = 0x1f,
    Fighter_KingDedede = 0x20,
    Fighter_Dedede = 0x20,
    Fighter_Lucario = 0x21,
    Fighter_Ike = 0x22,
    Fighter_ROB = 0x23,
    Fighter_Robot = 0x23,
    Fighter_Jigglypuff = 0x25,
    Fighter_Purin = 0x25,
    Fighter_ToonLink = 0x29,
    Fighter_Wolf = 0x2c,
    Fighter_Snake = 0x2e,
    Fighter_Sonic = 0x2f,
    Fighter_Mewtwo = 0x26,
    Fighter_Roy = 0x27,
    Fighter_PlusleMinun = 0x24,
    Fighter_PraMai = 0x24,
    Fighter_DrMario = 0x28,
    Fighter_ToonZelda = 0x2a,
    Fighter_ToonSheik = 0x2b,
    Fighter_DixieKong = 0x2d,
    Fighter_Dixie = 0x2d,
    Fighter_GigaBowser = 0x30,
    Fighter_GKoopa = 0x30,
    Fighter_WarioMan = 0x31,
    Fighter_Alloy_Red = 0x32,
    Fighter_Zako_Boy = 0x32,
    Fighter_Alloy_Blue = 0x33,
    Fighter_Zako_Girl = 0x33,
    Fighter_Alloy_Yellow = 0x34,
    Fighter_Zako_Child = 0x34,
    Fighter_Alloy_Green = 0x35,
    Fighter_Zako_Ball = 0x35,
    Fighter_MarioD = 0x36,
};

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
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
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
    virtual void notifyEventCollisionSearch(void*, soModuleAccesser* moduleAccesser);
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