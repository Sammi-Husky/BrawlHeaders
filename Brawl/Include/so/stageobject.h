#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <memory.h>
#include <so/so_array.h>
#include <so/so_kind.h>
#include <so/so_module_accesser.h>
#include <so/event/so_gimmick_event_presenter.h>
#include <so/link/so_link_event_presenter.h>
#include <so/so_null.h>
#include <types.h>

#define KINETIC_ENERGY_ATTRIBUTE_MASK_NONE 0x0
#define KINETIC_ENERGY_ATTRIBUTE_MASK_MAIN 0x1
#define KINETIC_ENERGY_ATTRIBUTE_MASK_DAMAGE 0x2
#define KINETIC_ENERGY_ATTRIBUTE_MASK_EXTERN 0x4
#define KINETIC_ENERGY_ATTRIBUTE_MASK_GROUND 0x8

class soActivatable {
    virtual ~soActivatable();
    bool m_isActive;
    char _5[3];
};

class StageObject : public gfTask, public soActivatable, public soAnimCmdEventObserver, public soLinkEventObserver {
public:

    enum LinkEventKind {
        Link_Event_Yoshi_Special_N_Catch = 29,
        Link_Event_Yoshi_Special_N_Swallow = 30,
    };

    enum AnimCmdType {
        Anim_Cmd_Update_Node_SRT = 0x1,
        Anim_Cmd_Set_Inactive = 0x2,
        Anim_Cmd_Set_Active = 0x3,
        Anim_Cmd_Set_Air = 0x4,
    };

    enum KineticEnergyReserveAttribute {
        Kinetic_Energy_Reserve_None = 0x0,
        Kinetic_Energy_Reserve_Main = 0x1,
        Kinetic_Energy_Reserve_Damage = 0x2,
        Kinetic_Energy_Reserve_Extern = 0x3,
        Kinetic_Energy_Reserve_Ground = 0x4,
    };

    soModuleAccesser* m_moduleAccesser;
    StageObject(const char* name, int unk1, int unk2, int unk3, int unk4, soModuleAccesser* moduleAccesser);
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processFixCamera();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void processDebug();
    virtual void renderDebug();
    virtual ~StageObject();

    // TODO: Verify params?
    virtual void updatePosture(bool);
    virtual void processFixPositionPreAnimCmd();
    virtual Input* getInput();
    virtual float getCollisionLr(soModuleAccesser*);
    virtual soKind soGetKind();
    virtual int soGetSubKind();
    virtual bool isActive();
    virtual bool checkTransitionStatus(u32);
    virtual void updateNodeSRT();
    virtual void adjustParentGroundCollision(int unk1, float* unk2);
    virtual bool isTreadPassive();
    virtual void notifyLostGround(soModuleAccesser*);

    virtual bool isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventLink(soLinkEventArgs *eventInfo, soModuleAccesser* moduleAccesser, StageObject*, int unk4);

    virtual void notifyArticleEventRemove(int unk1, int* unk2);
    virtual void notifyArticleEventEject(int unk1, int unk2, int* unk3, int* unk4);
    virtual void updateRoughPos();

    void activate(Vec3f* pos, float lr, float, bool);
};
static_assert(sizeof(StageObject) == 0x64, "Class is wrong size!");
