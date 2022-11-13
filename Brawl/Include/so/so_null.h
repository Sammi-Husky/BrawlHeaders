#pragma once

#include <types.h>
#include <so/so_event_observer.h>

class soNullable {
    virtual bool isNull();

    bool null;
    char _spacer[3];
};

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
    virtual void addObserver(int unk1, char unk2);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(int* unk1, int unk2, int unk3);

    char _spacer1[2];
};
