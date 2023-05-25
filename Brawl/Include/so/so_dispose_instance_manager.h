#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_observer.h>
#include <types.h>

class soDisposeInstanceEventObserver : public soEventObserver<soDisposeInstanceEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual bool isObserv(); // TODO
    virtual void notifyDisposeInstance(bool, int, int taskId);
    virtual void notifyDrawDone(); // TODO
    char _spacer1[2];
};
static_assert(sizeof(soDisposeInstanceEventObserver) == 12, "Class is wrong size!");
