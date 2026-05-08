#pragma once

#include <StaticAssert.h>
#include <gm/gm_lib.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>

class ftExtendParamAccesser : public soParamAccesser {
    Fighters::ftFighterKind m_kind;
public:
    ftExtendParamAccesser(Fighters::ftFighterKind kind);
    static ftExtendParamAccesser* getAccesser(Fighters::ftFighterKind kind);
    static bool isExistAccesser(Fighters::ftFighterKind kind);

    virtual ~ftExtendParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2) = 0;
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2) = 0;
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2) { return nullptr; }
    virtual void setup() = 0;
};
static_assert(sizeof(ftExtendParamAccesser) == 0x10, "Class is the wrong size!");
