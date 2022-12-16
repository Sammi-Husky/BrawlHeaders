#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <it/item.h>
#include <so/so_dispose_instance_manager.h>

class itManager : public gfTask, public soDisposeInstanceEventObserver {

    char _spacer[5236];

public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processUpdate();
    virtual void processFixPosition();
    virtual void processDebug();
    virtual void renderDebug();
    virtual ~itManager();

    virtual void notifyDisposeInstance(bool, int, int taskId);
    virtual void notifyDrawDone();


    STATIC_CHECK(sizeof(itManager) == 0x14c0)
};

