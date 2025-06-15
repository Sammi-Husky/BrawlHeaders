#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <em/em_extend_param_accesser.h>
#include <em/killer/em_killer.h>
#include <em/resource/em_resource_module_impl.h>
#include <types.h>

struct emKillerParam {

};

class emKillerParamAccesser : public emExtendParamAccesser {
public:
    emKillerParamAccesser();
    virtual ~emKillerParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2);
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2);
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2);
};
static_assert(sizeof(emKillerParamAccesser) == 0xC, "Class is the wrong size!");

extern emKillerParamAccesser g_emBulletBillParamAccesser;
