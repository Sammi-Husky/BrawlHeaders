#pragma once

#include <StaticAssert.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <types.h>

class emExtendParamAccesser : public soParamAccesser {
public:
    emExtendParamAccesser(u32 index);
    virtual ~emExtendParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, u32, u32) = 0;
    virtual int getParamInt(soModuleAccesser* moduleAccesser, u32, u32) = 0;
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, u32, u32) = 0;

    static void reset(emExtendParamAccesser* acc, u32 index);
    static emExtendParamAccesser* getAccesser(u32 index);
};
static_assert(sizeof(emExtendParamAccesser) == 0xC, "Class is the wrong size!");
