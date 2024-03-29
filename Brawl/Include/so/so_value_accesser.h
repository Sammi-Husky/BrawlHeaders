#pragma once

#include <so/so_module_accesser.h>
#include <types.h>

namespace soValueAccesser {
    int getConstantInt(soModuleAccesser* moduleAccesser, u32, u32);
    int getValueInt(soModuleAccesser* moduleAccesser, u32, u32);
    float getValueFloat(soModuleAccesser* moduleAccesser, u32, u32);
}
