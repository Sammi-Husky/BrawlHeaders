#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <memory.h>
#include <so/so_array.h>
#include <so/so_kind.h>
#include <so/so_module_accesser.h>
#include <so/event/so_gimmick_event_presenter.h>
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

    enum AnimCmdType {
        Anim_Cmd_Update_Node_SRT = 0x1,
        Anim_Cmd_Set_Inactive = 0x2,
        Anim_Cmd_Set_Active = 0x3,
        Anim_Cmd_Set_Air = 0x4,
    };

    enum KineticEnergyAttributeId {
        Kinetic_Energy_Attribute_None = 0x0,
        Kinetic_Energy_Attribute_Main = 0x1,
        Kinetic_Energy_Attribute_Damage = 0x2,
        Kinetic_Energy_Attribute_Extern = 0x3,
        Kinetic_Energy_Attribute_Ground = 0x4,
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
    virtual int* getInput();
    virtual double getCollisionLr(int* unk1);
    virtual soKind soGetKind();
    virtual int soGetSubKind();
    virtual bool isActive();
    virtual bool checkTransitionStatus(int unk1);
    virtual void updateNodeSRT();
    virtual void adjustParentGroundCollision(int unk1, float* unk2);
    virtual u32 isTreadPassive(int unk1);
    virtual void notifyLostGround(int* unk1); // TODO

    virtual bool isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, StageObject*, int unk4);

    virtual void notifyArticleEventRemove(int unk1, int* unk2);
    virtual void notifyArticleEventEject(int unk1, int unk2, int* unk3, int* unk4);
    virtual void updateRoughPos();

    void activate(float lr, float, Vec3f* pos, bool);
};
static_assert(sizeof(StageObject) == 100, "Class is wrong size!");
