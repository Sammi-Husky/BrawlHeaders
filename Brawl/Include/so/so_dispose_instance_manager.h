#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_event_observer.h>

class soDisposeInstanceEventObserver : public soEventObserver<soDisposeInstanceEventObserver> {
    virtual bool isObserv(); // TODO
    virtual void notifyDisposeInstance(bool, int, int taskId);
    virtual void notifyDrawDone(); // TODO
    char _spacer1[2];

    STATIC_CHECK(sizeof(soDisposeInstanceEventObserver) == 12)
};
