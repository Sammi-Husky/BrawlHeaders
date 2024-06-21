#pragma once

#include <so/so_module_accesser.h>
#include <types.h>

class soValueAccesser {
public:
    virtual ~soValueAccesser();
    virtual float getVariableFloatCore(soModuleAccesser* moduleAccesser, u32);
    virtual int getVariableIntCore(soModuleAccesser* moduleAccesser, u32);
    virtual void* getVariableIndefiniteCore(soModuleAccesser* moduleAccesser, u32);
    virtual float getConstantFloatCore(soModuleAccesser* moduleAccesser, u32);
    virtual int getConstantIntCore(soModuleAccesser* moduleAccesser, u32);
    virtual void* getConstantIndefiniteCore(soModuleAccesser* moduleAccesser, u32);
    virtual bool isControllerValueCore(soModuleAccesser* moduleAccesser, u32);
    virtual bool isEnableSpeedOperationCore(soModuleAccesser* moduleAccesser);

    static float getVariableFloat(soModuleAccesser* moduleAccesser, u32, u32);
    static int getVariableInt(soModuleAccesser* moduleAccesser, u32, u32);
    static void* getVariableIndefinite(soModuleAccesser* moduleAccesser, u32, u32);

    static float getConstantFloat(soModuleAccesser* moduleAccesser, u32, u32);
    static int getConstantInt(soModuleAccesser* moduleAccesser, u32, u32);
    static void* getConstantIndefinite(soModuleAccesser* moduleAccesser, u32, u32);

    static float getValueFloat(soModuleAccesser* moduleAccesser, u32, u32);
    static int getValueInt(soModuleAccesser* moduleAccesser, u32, u32);
};
