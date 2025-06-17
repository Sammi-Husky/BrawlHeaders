#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <em/em_extend_param_accesser.h>
#include <em/falconflyer/em_falconflyer.h>
#include <em/resource/em_resource_module_impl.h>
#include <types.h>

struct emFalconflyerParam {

};

class emFalconflyerParamAccesser : public emExtendParamAccesser {
public:
    emFalconflyerParamAccesser();
    virtual ~emFalconflyerParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2);
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2);
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2);
};
static_assert(sizeof(emFalconflyerParamAccesser) == 0xC, "Class is the wrong size!");

extern emFalconflyerParamAccesser g_emFalconFlyerParamAccesser;
