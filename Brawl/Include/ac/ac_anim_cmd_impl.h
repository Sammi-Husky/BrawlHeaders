#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <so/anim/so_anim_cmd.h>
#include <types.h>

// TODO: Verify and add virtual functions.
class acAnimCmd: soNullable {
public:
    // There are more methods than just this one,
    // but I only defined one to force it to be considered
    // a virtual class with a vtable of its own.
    virtual int getGroup() = 0;
};

class acAnimCmdImpl : public acAnimCmd {
public:
    // TODO
    virtual int getGroup();

    soAnimCmd* m_latestWaitCmd;
};
static_assert(sizeof(acAnimCmdImpl) == 0xC, "Class is the wrong size!");