#pragma once

#include <StaticAssert.h>
#include <so/so_event_observer.h>
#include <types.h>

class soDisposeInstanceEventObserver : public soEventObserver<soDisposeInstanceEventObserver> {
    virtual bool isObserv(); // TODO
    virtual void notifyDisposeInstance(bool, int, int taskId);
    virtual void notifyDrawDone(); // TODO
    char _spacer1[2];
};
static_assert(sizeof(soDisposeInstanceEventObserver) == 12, "Class is wrong size!");
