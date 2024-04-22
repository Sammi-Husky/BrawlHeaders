#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <so/anim_cmd/so_anim_cmd.h>
#include <types.h>

// TODO: Verify this.
class acAnimCmd: soNullable {
public:
    virtual int getGroup() = 0;
};

class acAnimCmdImpl : public acAnimCmd {
public:
    // TODO
    virtual int getGroup();

    soAnimCmd* m_latestWaitCmd;
};
static_assert(sizeof(acAnimCmdImpl) == 0xC, "Class is the wrong size!");