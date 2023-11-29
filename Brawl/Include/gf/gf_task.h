#pragma once

#include <StaticAssert.h>
#include <types.h>

class gfTask {
public:
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
    u16 m_0x2c;
    u16 m_taskCategory;
    char _unk[0xC];

    gfTask(const char* name, int unk1, int unk2, int unk3, int unk4);
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
    static gfTask* getTask(int taskId);
};
static_assert(sizeof(gfTask) == 0x40, "Class is wrong size!");