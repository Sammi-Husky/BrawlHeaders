#pragma once

#include <StaticAssert.h>
#include <types.h>

class soNull {
#ifndef __MWERKS__
    int pad; // fix for bug in Clang fork not producing empty vtable
#endif
};

class soNullableInterface {
    virtual bool isNull();
};

class soNullable {
public:
    virtual bool isNull();

    bool m_isNull;
    char _spacer[3];
};
static_assert(sizeof(soNullable) == 8, "Class is wrong size!");
