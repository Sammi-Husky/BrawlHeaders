#pragma once
#include <so/event/so_event_observer.h>

class soStatusEventObserver : public soEventObserver<soStatusEventObserver> {
public:
    soStatusEventObserver(short unitID) : soEventObserver<soStatusEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soStatusEventObserver) == 12, "Class is wrong size!");
