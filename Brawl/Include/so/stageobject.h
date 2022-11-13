#pragma once

#include <containers.h>
#include <gf/gf_task.h>
#include <memory.h>
#include <so/so_null.h>
#include <so/so_module_accesser.h>
#include <StaticAssert.h>

enum soKind {
    So_Kind_Invalid = 0xFFFFFFFF,
    So_Kind_Fighter = 0x0,
    So_Kind_Enemy = 0x1,
    So_Kind_Weapon = 0x2,
    So_Kind_Yakumono = 0x3,
    So_Kind_Item = 0x4
};

class soActivatable {
    virtual ~soActivatable();
    u32 isActive;
};

class StageObject : public gfTask, public soActivatable, public soAnimCmdEventObserver, public soLinkEventObserver {
public:
    soModuleAccesser* moduleAccesser;
    StageObject(char* name, int unk1, int unk2, int unk3, int unk4, soModuleAccesser* moduleAccesser);
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
    virtual void updatePosture(u32 unk1);
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
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);

    virtual void notifyArticleEventRemove(int unk1, int* unk2);
    virtual void notifyArticleEventEject(int unk1, int unk2, int* unk3, int* unk4);
    virtual void updateRoughPos();

    STATIC_CHECK(sizeof(StageObject) == 100)
};
