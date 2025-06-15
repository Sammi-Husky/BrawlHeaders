#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <em/em_extend_param_accesser.h>
#include <em/faulong/em_faulong.h>
#include <types.h>

struct emFaulongParam {

};

class emFaulongParamAccesser : public emExtendParamAccesser {
public:
    emFaulongParamAccesser();
    virtual ~emFaulongParamAccesser();
    virtual float getParamFloat(soModuleAccesser* moduleAccesser, s32 p2);
    virtual s32 getParamInt(soModuleAccesser* moduleAccesser, s32 p2);
    virtual void* getParamIndefinite(soModuleAccesser* moduleAccesser, s32 p2);
};
static_assert(sizeof(emFaulongParamAccesser) == 0xC, "Class is the wrong size!");

extern emFaulongParamAccesser g_emTrowlonParamAccesser;
