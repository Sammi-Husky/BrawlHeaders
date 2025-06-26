#pragma once

#include <StaticAssert.h>
#include <so/area/so_area_module_impl.h>
#include <so/so_module_accesser.h>
#include <types.h>

class emAreaModuleImpl : public soAreaModuleImpl {
public:
    static s32 getTargetFoundDistance(soModuleAccesser* acc, s32 p2);
    static bool isTargetFoundDir(soModuleAccesser* acc, s32 p2, s32 p3);
};
// TODO size assertion
