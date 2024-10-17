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
    enum StatusKind {
        Status_Wait = 0x0,
        Status_Walk = 0x1,
        Status_Walk_Brake = 0x2,
        Status_Dash = 0x3,
        Status_Run = 0x4,
        Status_Run_Brake = 0x5,
        Status_Turn = 0x6,
        Status_Turn_Dash = 0x7,
        Status_Turn_Run = 0x8,
        Status_Turn_Run_Brake = 0x9,
        Status_Jump_Squat = 0xA,
        Status_Jump = 0xB,
        Status_Jump_Aerial = 0xC,
        Status_Fly = 0xD,
        Status_Fall = 0xE,
        Status_Fall_Aerial = 0xF,
        Status_Fall_Special = 0x10,
        Status_Squat = 0x11,
        Status_Squat_Wait = 0x12,
        Status_Squat_F = 0x13,
        Status_Squat_B = 0x14,
        Status_Squat_Rv = 0x15,
        Status_Landing = 0x16,
        Status_Landing_Light = 0x17,
        Status_Landing_Attack_Air = 0x18,
        Status_Landing_Fall_Special = 0x19,
        Status_Guard_On = 0x1A,
        Status_Guard = 0x1B,
        Status_Guard_Off = 0x1C,
        Status_Guard_Damage = 0x1D,
        Status_Escape = 0x1E,
        Status_Escape_F = 0x1F,
        Status_Escape_B = 0x20,
        Status_Escape_Air = 0x21,
        Status_Rebound_Stop = 0x22,
        Status_Rebound = 0x23,
        Status_Attack = 0x24,
        Status_Attack_100 = 0x25,
        Status_Attack_Dash = 0x26,
        Status_Attack_S3 = 0x27,
        Status_Attack_Hi3 = 0x28,
        Status_Attack_Lw3 = 0x29,
        Status_Attack_S4_Start = 0x2A,
        Status_Attack_S4_Hold = 0x2B,
        Status_Attack_S4 = 0x2C,
        Status_Attack_Lw4_Start = 0x2D,
        Status_Attack_Lw4_Hold = 0x2E,
        Status_Attack_Lw4 = 0x2F,
        Status_Attack_Hi4_Start = 0x30,
        Status_Attack_Hi4_Hold = 0x31,
        Status_Attack_Hi4 = 0x32,
        Status_Attack_Air = 0x33,
        Status_Catch = 0x34,
        Status_Catch_Pull = 0x35,
        Status_Catch_Dash = 0x36,
        Status_Catch_Dash_Pull = 0x37,
        Status_Catch_Turn = 0x38,
        Status_Catch_Wait = 0x39,
        Status_Catch_Attack = 0x3A,
        Status_Catch_Cut = 0x3B,
        Status_Throw = 0x3C,
        Status_Capture_Pulled = 0x3D,
        Status_Capture_Wait = 0x3E,
        Status_Capture_Damage = 0x3F,
        Status_Capture_Cut = 0x40,
        Status_Capture_Jump = 0x41,
        Status_Capture_Thrown = 0x42,
        Status_Damage = 0x43,
        Status_Damage_Air = 0x44,
        Status_Damage_Fly = 0x45,
        Status_Damage_Fly_Roll = 0x46,
        Status_Damage_Fly_Reflect_Lr = 0x47,
        Status_Damage_Fly_Reflect_U = 0x48,
        Status_Damage_Fall = 0x49,
        Status_Down = 0x4A,
        Status_Down_Spot = 0x4B,
        Status_Down_Continue = 0x4C,
        Status_Down_Wait = 0x4D,
        Status_Down_Wait_Continue = 0x4E,
        Status_Down_Eat = 0x4F,
        Status_Lay_Down = 0x50,
        Status_Down_Stand = 0x51,
        Status_Down_Stand_Fb = 0x52,
        Status_Down_Stand_Attack = 0x53,
        Status_Down_Damage = 0x54,
        Status_Down_Reflect_Lr = 0x55,
        Status_Shield_Break_Fly = 0x56,
        Status_Shield_Break_Fall = 0x57,
        Status_Shield_Break_Down = 0x58,
        Status_FuraFura_Stand = 0x59,
        Status_FuraFura = 0x5A,
        Status_FuraFura_End = 0x5B,
        Status_Damage_Song_Start = 0x5C,
        Status_Damage_Song = 0x5D,
        Status_Damage_Song_End = 0x5E,
        Status_Bind = 0x5F,
        Status_Passive = 0x60,
        Status_Passive_Fb = 0x61,
        Status_Passive_Wall = 0x62,
        Status_Passive_Wall_Jump = 0x63,
        Status_Passive_Ceil = 0x64,
        Status_Stop_Wall = 0x65,
        Status_Stop_Ceil = 0x66,
        Status_Wall_Jump = 0x67,
        Status_Attach_Wall = 0x68,
        Status_Attach_Wall_Wait = 0x69,
        Status_Detach_Wall = 0x6A,
        Status_Detach_Wall_Fall = 0x6B,
        Status_Detach_Wall_Jump = 0x6C,
        Status_Tread_Jump = 0x6D,
        Status_Tread_Damage = 0x6E,
        Status_Tread_Damage_Rv = 0x6F,
        Status_Tread_Damage_Air = 0x70,
        Status_Tread_Fall = 0x71,
        Status_Pass = 0x72,
        Status_Cliff_Catch_Move = 0x73,
        Status_Cliff_Catch = 0x74,
        Status_Cliff_Wait = 0x75,
        Status_Cliff_Attack = 0x76,
        Status_Cliff_Climb = 0x77,
        Status_Cliff_Escape = 0x78,
        Status_Cliff_Jump1 = 0x79,
        Status_Cliff_Jump2 = 0x7A,
        Status_Cliff_Jump3 = 0x7B,
        Status_Ottoto = 0x7C,
        Status_Ottoto_Wait = 0x7D,
        Status_Miss_Foot = 0x7E,
        Status_Air_Lasso = 0x7F,
        Status_Air_Lasso_Reach = 0x80,
        Status_Air_Lasso_Hang = 0x81,
        Status_Air_Lasso_Rewind = 0x82,
        Status_Air_Lasso_Failure = 0x83,
        Status_Glide_Start = 0x84,
        Status_Glide = 0x85,
        Status_Glide_Landing = 0x86,
        Status_Glide_Attack = 0x87,
        Status_Glide_End = 0x88,
        Status_Slip = 0x89,
        Status_Slip_Down = 0x8A,
        Status_Slip_Turn = 0x8B,
        Status_Slip_Dash = 0x8C,
        Status_Slip_Wait = 0x8D,
        Status_Slip_Stand = 0x8E,
        Status_Slip_Stand_Attack = 0x8F,
        Status_Slip_Stand_F = 0x90,
        Status_Slip_Stand_B = 0x91,
        Status_Ladder_Catch = 0x92,
        Status_Ladder_Catch_End = 0x93,
        Status_Ladder_Wait = 0x94,
        Status_Ladder_End = 0x95,
        Status_Item_Light_Pickup = 0x96,
        Status_Item_Heavy_Pickup = 0x97,
        Status_Item_Lift_Wait = 0x98,
        Status_Item_Lift_Turn = 0x99,
        Status_Item_Lift_Walk = 0x9A,
        Status_Item_Throw = 0x9B,
        Status_Item_Throw_Dash = 0x9C,
        Status_Item_Throw_Heavy = 0x9D,
        Status_Item_Swing = 0x9E,
        Status_Item_Swing_S3 = 0x9F,
        Status_Item_Swing_S4_Start = 0xA0,
        Status_Item_Swing_S4 = 0xA1,
        Status_Item_Swing_S4_Hold = 0xA2,
        Status_Item_Swing_Dash = 0xA3,
        Status_Item_Shoot_Wait = 0xA4,
        Status_Item_Shoot_Walk_F = 0xA5,
        Status_Item_Shoot_Walk_Brake_F = 0xA6,
        Status_Item_Shoot_Walk_B = 0xA7,
        Status_Item_Shoot_Walk_Brake_B = 0xA8,
        Status_Item_Shoot_Dash_F = 0xA9,
        Status_Item_Shoot_Dash_B = 0xAA,
        Status_Item_Shoot_Jump_Squat = 0xAB,
        Status_Item_Shoot_Jump = 0xAC,
        Status_Item_Shoot_Air = 0xAD,
        Status_Item_Shoot_Landing = 0xAE,
        Status_Item_Screw_Jump = 0xAF,
        Status_Item_Screw_Jump_Aerial = 0xB0,
        Status_Item_Screw_Fall = 0xB1,
        Status_Item_Assist_Hoist = 0xB2,
        Status_Swim_Dive = 0xB3,
        Status_Swim_Rise = 0xB4,
        Status_Swim_Up = 0xB5,
        Status_Swim_Wait = 0xB6,
        Status_Swim = 0xB7,
        Status_Swim_End = 0xB8,
        Status_Swim_Turn = 0xB9,
        Status_Swim_Jump = 0xBA,
        Status_Swim_Drown = 0xBB,
        Status_Swim_Drown_Out = 0xBC,
        Status_Dead = 0xBD,
        Status_Rebirth = 0xBE,
        Status_Gimmick_Door = 0xBF,
        Status_Gimmick_Barrel = 0xC0,
        Status_Gimmick_Catapult = 0xC1,
        Status_Gimmick_Truck = 0xC2,
        Status_Gimmick_Spring = 0xC3,
        Status_Gimmick_Spring_Jump = 0xC4,

        Status_Gimmick_Eaten = 0xC6,
        Status_Bury = 0xC7,
        Status_Bury_Wait = 0xC8,
        Status_Bury_Jump = 0xC9,
        Status_Ice = 0xCA,
        Status_Ice_Jump = 0xCB,
        Status_Bitten_Wario_Start = 0xCC,
        Status_Bitten_Wario = 0xCD,
        Status_Bitten_Wario_End = 0xCE,
        Status_Clung_Captain = 0xCF,
        Status_Swallowed = 0xD0,
        Status_Swallowed_Drink = 0xD1,
        Status_Swallowed_Capture = 0xD2,
        Status_Swallowed_Thrown_Star = 0xD3,
        Status_Swallowed_Thrown = 0xD4,
        Status_Swallowed_Canceled = 0xD5,
        Status_Clung_Diddy = 0xD6,
        Status_Clung_Damage_Diddy = 0xD7,
        Status_Clung_Thrown_Diddy = 0xD8,
        Status_Shouldered_Donkey_Start = 0xD9,
        Status_Shouldered_Donkey = 0xDA,
        Status_Shouldered_Donkey_Thrown = 0xDB,
        Status_Warptar = 0xDC,
        Status_Warpstar_Jump = 0xDD,
        Status_Dragoon_Ride = 0xDE,
        Status_Hammer_Wait = 0xDF,
        Status_Hammer_Walk = 0xE0,
        Status_Hammer_Turn = 0xE1,
        Status_Hammer_Jump_Squat = 0xE2,
        Status_Hammer_Jump = 0xE3,
        Status_Hammer_Fall = 0xE4,
        Status_Hammer_Landing = 0xE5,
        Status_Clung_Ganon = 0xE6,
        Status_Catched_Ganon = 0xE7,
        Status_Catched_Air_Ganon = 0xE8,
        Status_Catched_Air_Fall_Ganon = 0xE9,
        Status_Catched_Air_End_Ganon = 0xEA,
        Status_Capture_Yoshi = 0xEB,
        Status_Yoshi_Egg = 0xEC,
        Status_Link_Final = 0xED,
        Status_Koopa_Dived = 0xEE,

        Status_Pit_Fall = 0xF0,
        Status_Throw_Kirby = 0xF1,
        Status_Kind_Big = 0xF2,
        Status_Kind_Small = 0xF3,
        Status_Kind_Heart_Swap = 0xF4,
        Status_Kind_Heart_Swap_End = 0xF5,
        Status_Kind_Adv_Follow = 0xF6,
        Status_Ike_Final_Damage_Fly = 0xF7,
        Status_Ike_Final_Damage = 0xF8,
        Status_Ike_Final_Damage_Fall = 0xF9,
        Status_Capture_Masterhand = 0xFA,
        Status_Final_Visual_Attack_Other = 0xFB,
        Status_Captain_Final_Start = 0xFC,
        Status_Captain_Final_FuraFura = 0xFD,
        Status_Captain_Final_Clash = 0xFE,
        Status_Captain_Final_End = 0xFF,
        Status_Kirby_Final_Damage_Fly = 0x100,
        Status_Kirby_Final_Damage_Wait = 0x101,

        Status_Capture_Bucyulus = 0x105,
        Status_Capture_Bucyulus_End = 0x106,

        Status_Standby = 0x10B,
        Status_Appeal  = 0x10C,
        Status_Smash_Appeal = 0x10D,
        Status_Entry = 0x10E,
        Status_Win = 0x10F,
        Status_Lose = 0x110,
        Status_Test_Motion = 0x111
    };

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