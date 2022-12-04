#pragma once

#include <types.h>

class soNull {

};

class soNullable {
public:
    virtual bool isNull();

    bool null;
    char _spacer[3];
};

