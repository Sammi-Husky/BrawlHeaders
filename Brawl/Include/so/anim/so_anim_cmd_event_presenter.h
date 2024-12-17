#pragma once

#include <types.h>
#include <so/event/so_event_presenter.h>
#include <ac/ac_anim_cmd_impl.h>

class soModuleAccesser;

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
public:
    soAnimCmdEventObserver(short unitID) : soEventObserver<soAnimCmdEventObserver>(unitID) {};

    virtual void addObserver(short param1, s8 param2);
    virtual bool isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
};
static_assert(sizeof(soAnimCmdEventObserver) == 12, "Class is wrong size!");
