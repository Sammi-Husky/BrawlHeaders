#pragma once

#include <types.h>
#include <so/so_event_observer.h>

class soNullable {
    virtual bool isNull();

    bool null;
    char _spacer[3];
};

