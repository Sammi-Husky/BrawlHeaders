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

    enum Render {
        Render_Pre,
        Render_Opa,
        Render_Xlu,
    };

    enum TaskType {
        Type_0,
        Type_1,
    };

    char* m_taskName;
    gfTask* m_prev;     // TODO: suspend list and priority list prev?
    gfTask* m_next;     // TODO: suspend list and priority list next?
    gfTask* m_0xC;      // TODO: category list prev?
    gfTask* m_0x10;     // TODO: category list next?
    gfTask* m_0x14;     // TODO: unk31 list prev?
    gfTask* m_0x18;     // TODO: unk31 list next?
    gfTask* m_connectedTask;
    gfTask* m_attachedTask;
    gfTask* m_nextTask;
    u32 m_taskId;
    u8 _0 : 1;
    bool unk2C_b6 : 1;
    bool unk2C_b5 : 1;
    u8 _1: 2;
    bool unk2C_b2 : 1;
    bool unk2C_b1 : 1;
    bool unk2C_b0 : 1;
    u32 _2 : 1;
    s32 m_status : 8; // TODO: Task state?
    Category m_taskCategory : 8;
    u32 _4 : 7;
    u8 unk30;
    u8 unk31;
    u8 unk32[0x2];
    u16 unk34;
    char _unk[0x4];

    bool getFlag1() const { return unk2C_b1; }
    s32 getStatus() const { return m_status; }
    void setStatus(s32 st) { m_status = st; }

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

    void process(TaskType taskType);
    void render(Render kind);
    void setPaused(bool paused);
    void unlink();
    void exit();
    int getId();
    Category getCategory();
    static gfTask* getTask(int taskId);
};
static_assert(sizeof(gfTask) == 0x40, "Class is wrong size!");
