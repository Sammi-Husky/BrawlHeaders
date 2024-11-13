#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_presenter.h>
#include <types.h>

class soDisposeInstanceEventObserver : public soEventObserver<soDisposeInstanceEventObserver> {
public:
    virtual void addObserver(short param1, s8 param2);
    virtual bool isObserv(); // TODO
    virtual void notifyDisposeInstance(bool, int, int taskId);
    virtual void notifyDrawDone(); // TODO
    char _spacer1[2];
};
static_assert(sizeof(soDisposeInstanceEventObserver) == 12, "Class is wrong size!");
