#pragma once

#include <types.h>
#include <StaticAssert.h>

class soNull {

};

class soNullableInterface {
    virtual bool isNull();
};

class soNullable {
public:
    virtual bool isNull();

    bool m_null;
    char _spacer[3];

    STATIC_CHECK(sizeof(soNullable) == 8)
};

