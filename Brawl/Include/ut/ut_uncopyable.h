#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_null.h>

class utUnCopyable : public soNull, public soNullable {
public:
    virtual ~utUnCopyable();
};
