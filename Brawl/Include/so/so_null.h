#pragma once

#include <types.h>

class soNullable {
    virtual bool isNull();

    bool null;
    char _spacer[3];
};

