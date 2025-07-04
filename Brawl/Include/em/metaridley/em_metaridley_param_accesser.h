#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <em/em_extend_param_accesser.h>
#include <em/metaridley/em_metaridley.h>
#include <em/resource/em_resource_module_impl.h>
#include <types.h>

struct emMetaridleyParam {

};

class emMetaridleyParamAccesser : public emExtendParamAccesser {
public:
    emMetaridleyParamAccesser();
    virtual ~emMetaridleyParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2);
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2);
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2);
};
static_assert(sizeof(emMetaridleyParamAccesser) == 0xC, "Class is the wrong size!");

extern emMetaridleyParamAccesser g_emMetaRidleyParamAccesser;
