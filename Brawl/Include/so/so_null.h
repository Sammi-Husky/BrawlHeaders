#pragma once

#include <types.h>

class soNull {

};

class soNullableInterface {
    virtual void isNull();
};

class soNullable {
public:
    virtual bool isNull();

    bool null;
    char _spacer[3];
};

