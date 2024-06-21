#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <memory.h>
#include <so/so_array.h>
#include <so/so_kind.h>
#include <so/so_module_accesser.h>
#include <so/so_null.h>
#include <types.h>

class soActivatable {
    virtual ~soActivatable();
    bool m_isActive;
    char _5[3];
};

class StageObject : public gfTask, public soActivatable, public soAnimCmdEventObserver, public soLinkEventObserver {
public:
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

    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, StageObject*, int unk4);

    virtual void notifyArticleEventRemove(int unk1, int* unk2);
    virtual void notifyArticleEventEject(int unk1, int unk2, int* unk3, int* unk4);
    virtual void updateRoughPos();

    void activate(float lr, float, Vec3f* pos, bool);
};
static_assert(sizeof(StageObject) == 100, "Class is wrong size!");
