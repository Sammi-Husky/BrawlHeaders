#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <types.h>

class utUnCopyable : public soNull, public soNullable {
public:
    virtual ~utUnCopyable();
};
