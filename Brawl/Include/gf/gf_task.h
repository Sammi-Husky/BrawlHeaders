#pragma once

#include <StaticAssert.h>
#include <types.h>

class gfTask {
public:
    enum Category {
        Category_None = 0x0,
        Category_Enemy = 0x2,
        Category_Ground = 0x6,
        Category_GrCollision = 0x7,
        Category_Menu = 0x8,
        Category_Fighter = 0xA,
        Category_Item = 0xB,
        Category_Weapon = 0xC,
        Category_Effect = 0xE,
        Category_Info = 0x12,
        Category_Camera = 0x15,
        Category_Visual = 0x1F,
        Category_Stage = 0x21,
        Category_Physics = 0x23,
        Category_AI = 0x24,
        Category_CoinShooter = 0x25,
        Category_Network = 0x26,
        Category_SoCollision = 0x27,
    };

    char* m_taskName;
    gfTask* m_next;
    gfTask* m_prev;
    int m_0xC;
    int m_0x10;
    int m_0x14;
    int m_0x18;
    gfTask* m_connectedTask;
    gfTask* m_attachedTask;
    gfTask* m_nextTask;
    int m_taskId;
    u32 _1 : 9;
    u32 _2 : 8;
    Category m_taskCategory : 8;
    u32 _3 : 7;
    char _unk[0xC];

    gfTask(const char* name, Category category, int unk2, int unk3, int unk4);
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual ~gfTask();

    void exit();
    int getId();
    Category getCategory();
    static gfTask* getTask(int taskId);


};
static_assert(sizeof(gfTask) == 0x40, "Class is wrong size!");