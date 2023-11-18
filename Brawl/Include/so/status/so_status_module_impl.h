#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_observer.h>
#include <so/event/so_event_presenter.h>
#include <so/so_null.h>
#include <types.h>

class soModuleAccesser;

class soStatusUniqProcess {
public:
    virtual ~soStatusUniqProcess();
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execMapCorrection(soModuleAccesser* moduleAccesser);
    virtual void execFixPosCounter(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual void execFixCamera(soModuleAccesser* moduleAccesser);
    virtual bool checkDamage(soModuleAccesser* moduleAccesser, void*);
    virtual void checkAttack(soModuleAccesser* moduleAccesser, void*, float);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
    virtual void leaveStop(soModuleAccesser* moduleAccesser, int, bool);
    virtual bool checkTransitionPrecede(soModuleAccesser* moduleAccesser, int*);
};

class soStatusModule : public soNullable {
public:
    virtual void activate(soModuleAccesser* moduleAccesser);
    virtual void deactivate(soModuleAccesser* moduleAccesser);
    virtual bool changeStatusRequest(int status, soModuleAccesser* moduleAccesser);
    virtual void processFixPosition(soModuleAccesser* moduleAccesser, bool);
    virtual void begin();
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execMapCorrection(soModuleAccesser* moduleAccesser);
    virtual void execFixPosCounter(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual void execFixCamera(soModuleAccesser* moduleAccesser);
    virtual bool checkDamage(soModuleAccesser* moduleAccesser, void*);
    virtual void checkAttack(soModuleAccesser* moduleAccesser, void*, float);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
    virtual void leaveStop(soModuleAccesser* moduleAccesser, int, bool);
    virtual int getStatusKind();
    virtual bool isCollisionAttackOccer();
    virtual bool isCollisionAttackTarget(u32* collisionAttackCategory);
    virtual void startWatchChange();
    virtual bool isChanged();
    virtual bool checkTransition(soModuleAccesser* moduleAccesser);
    virtual void enableTransitionTermGroup(int);
    virtual void unableTransitionTermGroup(int);
    virtual void isEnableTransitionTermGroup(int);
    virtual void enableTransitionTermAll(int);
    virtual void clearTransitionTermAll(int);
    virtual void* getLastStatusTransitionInfo();
    virtual void addRangeUniqProc(soStatusUniqProcess* uniqProcs, u32 numUniqProcs);
    virtual char* getStatusName();
    virtual char* getStatusName(int);
    virtual u32 getStatusGroundCorrect(int);
    virtual int getPrevStatusKind(u32);
    virtual void connectStatusDataList(void*);
    virtual void changeStatusForce(int status, soModuleAccesser* moduleAccesser);
    virtual void unableTransitionTerm(int, int);
    virtual void setUniqProc(u32 index, soStatusUniqProcess* uniqProc);
    virtual ~soStatusModule();
    virtual void changeStatus(int status, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soStatusModule) == 8, "Class is wrong size!");

class soStatusModuleImpl : public soStatusModule, public soEventPresenter<soStatusEventObserver>, public soAnimCmdEventObserver, public soCollisionAttackEventObserver {

    char _spacer[100];

public:
    virtual void activate(soModuleAccesser* moduleAccesser);
    virtual void deactivate(soModuleAccesser* moduleAccesser);
    virtual bool changeStatusRequest(int status, soModuleAccesser* moduleAccesser);
    virtual void processFixPosition(soModuleAccesser* moduleAccesser, bool);
    virtual void begin();
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execMapCorrection(soModuleAccesser* moduleAccesser);
    virtual void execFixPosCounter(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual void execFixCamera(soModuleAccesser* moduleAccesser);
    virtual bool checkDamage(soModuleAccesser* moduleAccesser, void*);
    virtual void checkAttack(soModuleAccesser* moduleAccesser, void*, float);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
    virtual void leaveStop(soModuleAccesser* moduleAccesser, int, bool);
    virtual int getStatusKind();
    virtual bool isCollisionAttackOccer();
    virtual bool isCollisionAttackTarget(u32* collisionAttackCategory);
    virtual void startWatchChange();
    virtual bool isChanged();
    virtual bool checkTransition(soModuleAccesser* moduleAccesser);
    virtual void enableTransitionTermGroup(int);
    virtual void unableTransitionTermGroup(int);
    virtual void isEnableTransitionTermGroup(int);
    virtual void enableTransitionTermAll(int);
    virtual void clearTransitionTermAll(int);
    virtual void* getLastStatusTransitionInfo();
    virtual void addRangeUniqProc(soStatusUniqProcess* uniqProcs, u32 numUniqProcs);
    virtual char* getStatusName();
    virtual char* getStatusName(int);
    virtual u32 getStatusGroundCorrect(int);
    virtual int getPrevStatusKind(u32);
    virtual void connectStatusDataList(void*);
    virtual void changeStatusForce(int status, soModuleAccesser* moduleAccesser);
    virtual void unableTransitionTerm(int, int);
    virtual void setUniqProc(u32 index, soStatusUniqProcess* uniqProc);
    virtual ~soStatusModuleImpl();
    virtual void changeStatus(int status, soModuleAccesser* moduleAccesser);

    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventCollisionAttack(float power, soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);;
};
static_assert(sizeof(soStatusModuleImpl) == 144, "Class is wrong size!");

namespace ftStatus {
    enum Kind {
        Stand = 0x00,
        Walk = 0x01,
        Start_Dash = 0x03,
        Run = 0x04,
        Stop = 0x05,
        Turn_1 = 0x06,
        Turn_2 = 0x07,
        Stop_Turn = 0x08,
        Start_Jump = 0x0A,
        Jump = 0x0B,
        Second_Jump = 0x0C,
        Fall_1 = 0x0E,
        Fall_2 = 0x0F,
        Fall_Disabled = 0x10,
        Enter_Crouch = 0x11,
        Crouch = 0x12,
        Crawl_Forwards = 0x13,
        Crawl_Backwards = 0x14,
        Exit_Crouch = 0x15,
        Land_1 = 0x16,
        Land_2 = 0x17,
        Aerial_Attack_Lag = 0x18,
        Land_Disabled = 0x19,

        Enter_Shield = 0x1A,
        Shield = 0x1B,
        Exit_Shield = 0x1C,
        Shield_Stun = 0x1D,
        Spotdodge = 0x1E,
        Roll_Forward = 0x1F,
        Roll_Back = 0x20,
        Air_Dodge = 0x21,
        Spotdodge_1 = 0x22,
        Spotdodge_2 = 0x23,

        Neutral_Attack_Combo = 0x24,
        Rapid_Jab = 0x25,
        R_Attack = 0x26,
        Side_Attack = 0x27,
        Up_Attack = 0x28,
        Down_Attack = 0x29,

        Side_Smash_Windup = 0x2A,
        Side_Smash_Charge = 0x2B,
        Side_Smash_Attack = 0x2C,
        Down_Smash_Windup = 0x2D,
        Down_Smash_Charge = 0x2E,
        Down_Smash_Attack = 0x2F,
        Up_Smash_Windup = 0x30,
        Up_Smash_Charge = 0x31,
        Up_Smash_Attack = 0x32,

        Air_Attack_All = 0x33,

        Grab = 0x34,
        Grabbing_Enemy = 0x35,
        Dash_Grab = 0x36,
        Holding_Enemy = 0x37,
        Pivot_Grab = 0x38,
        Hold = 0x39,
        Grab_Attack = 0x3A,
        Release = 0x3B,
        Throw = 0x3C,
        Grabbed = 0x3D,
        Held = 0x3E,
        Held_Damage = 0x3F,
        Escape = 0x40,
        Jump_Break = 0x41,
        Thrown = 0x42,

        Hitstun_Weak_Hits = 0x43,
        Hitstun_No_Tumble = 0x44,
        Hitstun = 0x45,
        Hit_Ground = 0x46,
        Hit_Wall = 0x47,
        Hit_Ceiling = 0x48,
        Tumble = 0x49,
        Hit_Ground_Tumble = 0x4A,
        Hit_Wall_Tumble = 0x4B,
        Hit_Ceiling_Tumble = 0x4C,
        Lying = 0x4D,
        Roll_From_Lying_On_Ground_1 = 0x4E,
        Struggle_On_Ground = 0x4F,
        Roll_From_Lying_On_Ground_2 = 0x50,
        Get_Up = 0x51,
        Roll_From_Lying_On_Ground_3 = 0x51,
        Get_Up_Attack = 0x53,
        Bounce_On_Ground = 0x54,
        Hit_Ground_Hard = 0x55,
        Fly_Up_Broken_Shield = 0x56,
        Hit_Ground_Hard_Broken_Shield = 0x57,
        Hit_Ground_Softly_Broken_Shield = 0x58,
        Get_Up_From_Lying_On_Ground_Broken_Shield = 0x59,
        Dizziness_Broken_Shield = 0x5A,
        Recover_From_Broken_Shield = 0x5B,
        Fall_Asleep = 0x5C,
        Middle_Of_Sleep = 0x5D,
        Wake_Up_From_Sleep = 0x5E,
        Stunned_From_Deku_Nut = 0x5F,
        Tech_Ground = 0x60,
        Tech_Roll = 0x61,
        Tech_Wall = 0x62,
        Tech_Jump = 0x63,
        Tech_Ceiling = 0x64,

        Run_Into_Wall = 0x65,
        Compress = 0x66,
        Footstool_Jump = 0x67,
        Face_Screen = 0x68,
        Odd_Quick_Landing_Effect = 0x69,
        TPose_Landing_Effect = 0x6A,
        TPose_Landing_Effect_No_Outline = 0x6B,
        TPose_Landing_Effect_Eye_Glimmer = 0x6C,
        Quick_Jerk_Landing_Effect = 0x6D,
        Footstooled_Ground = 0x6E,
        Helpless_Fall = 0x6F,
        Footstooled_Air = 0x70,
        Flop_Down_Spinning_Helpless = 0x71,
        Soft_Landing_Air_Fast_Fall = 0x72,
        Begin_Ledge_Grab_Air_Restore_Jumps = 0x73,
        Ledge_Grab = 0x74,
        Ledge_Hang = 0x75,
        Soft_Landing_Ledge_Action_1 = 0x76,
        On_Ground_Ledge_Action = 0x77,
        Soft_Landing_Ledge_Action_2 = 0x78,
        Ledge_Jump = 0x79,
        Ledge_Jump_Weak = 0x7A,
        Interesting_Pose_Ledge_Action = 0x7B,
        Begin_Teeter = 0x7C,
        Teeter = 0x7D,
        Land_On_Ground_Hard = 0x7E,
        Freeze_Game_1 = 0x7F,
        Landing_Effect = 0x80,
        Tether_Hang = 0x81,
        Freeze_Game_2 = 0x82,
        Big_Smoke_Cloud_Landing_Effect = 0x83,
        Flop_On_Ground_Land_On_Stomach = 0x84,
        Freeze_Game_3 = 0x85,
        Get_Up_From_Lying_On_Stomach = 0x86,
        Land_On_Ground_Softly_Gliding_1 = 0x87,
        Land_On_Ground_Softly_Gliding_2 = 0x88,

        Rear_End_Trip_Running_Over_Banana_Peel = 0x89,
        Rear_End_Trip_Hit_By_Banana_Peel = 0x8A,
        Turn_Around_Trip = 0x8B,
        Fall_Forward_Trip = 0x8C,
        On_Ground_From_Trip = 0x8D,
        Get_Up_From_Trip = 0x8E,
        Attack_From_Trip = 0x8F,
        Roll_Forward_From_Trip = 0x90,
        Roll_Backward_From_Trip = 0x91,
        Climb_Ladder = 0x92,

        Surfacing = 0xB4,
        Treading_Water = 0xB6,
        Swimming_Forward = 0xB7,
        Turn_Around_Swim = 0xB9,
        Floundering = 0xBB,
        Drowning = 0xBC,

        Death = 0xBD,
        Respawn = 0xBE,

        Cannon_Shot = 0xC0,

        Enter_Grounded = 0xC7,
        In_Grounded = 0xC8,
        Exit_Grounded = 0xC9,
        Frozen = 0xCA,
        Exit_Frozen = 0xCB,
        Yoshi_Egg = 0xEC,
        Enlarge_Size_Revert = 0xF2,
        Shrink_Size_Revert = 0xF3,

        Unloaded = 0x10B,
        Taunt = 0x10C,
        Smash_Taunt = 0x10D,
        Entrance = 0x10E,
        Victory = 0x10F,
        Loss = 0x110,

        Neutral_Special = 0x112,
        Side_Special = 0x113,
        Up_Special = 0x114,
        Down_Special = 0x115,
        Final_Smash = 0x116,
        Special_Extra = 0x117
    };
};