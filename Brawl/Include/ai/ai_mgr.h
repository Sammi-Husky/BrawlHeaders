#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <ft/ft_manager.h>
#include <mt/mt_vector.h>

class aiMgr : public gfTask, public ftOutsideEventObserver {
    char _76[828];
public:
    virtual void processBegin();
    virtual void renderDebug();
    virtual ~aiMgr();

    virtual void notifyEventOnDamage(int entryId, bool, void*);
    virtual void notifyEventDead(int entryId, int, int, u32);
    virtual void notifyEventChangeStart(int,int playerNo);
    virtual void notifyEventChangeEnd(int entryId, u32 index, int, int);

    int setDangerZone(Vec2f* p1, Vec2f* p2, int index, bool, bool);

    STATIC_CHECK(sizeof(aiMgr) == 0x388)

};

extern aiMgr* g_aiMgr;