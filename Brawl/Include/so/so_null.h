#pragma once

#include <StaticAssert.h>
#include <types.h>

class soNull {
// fix for bug in Clang fork not producing empty vtable.
// This is technically incorrect as it will make soNull
// always 4 bytes when the bug only affects multiple
// inheritance, however soNull is never used on it's own
// so this shouldn't be an issue (for now?)
#ifndef __MWERKS__
    int pad;
#endif
};

class soNullableInterface {
    virtual bool isNull();
};

class soNullable {
public:
    virtual bool isNull();

    bool m_isNull;
};
static_assert(sizeof(soNullable) == 8, "Class is wrong size!");
