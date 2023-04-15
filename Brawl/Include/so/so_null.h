#pragma once

#include <StaticAssert.h>
#include <types.h>

class soNull {
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
