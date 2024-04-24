#pragma once
#include <so/event/so_event_observer.h>

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
public:
    soAnimCmdEventObserver(short unitID) : soEventObserver<soAnimCmdEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
};
static_assert(sizeof(soAnimCmdEventObserver) == 12, "Class is wrong size!");