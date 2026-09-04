#pragma once

#include <StaticAssert.h>
#include <so/so_array.h>
#include <so/so_common_data_accesser.h>
#include <types.h>

class soModuleAccesser;

struct soShakeTerm {
    s32 m_kind;
    float m_amplitude;
    float m_frequency;
    float m_decay;
    s32 m_frame;
    u32 m_flags;
    u32 m_state;
};
static_assert(sizeof(soShakeTerm) == 0x1c,
    "Class is wrong size!");

class soShakeModule {
public:
    virtual ~soShakeModule();
};

class soShakeModuleSimple : public soShakeModule {
public:
    soModuleAccesser* m_moduleAccesser;

    soShakeModuleSimple(
        soModuleAccesser* moduleAccesser,
        soArray<soShakeTerm>* shakeTermArray,
        soShakeData* shakeData);
    virtual ~soShakeModuleSimple();
};
static_assert(sizeof(soShakeModuleSimple) == 0x8,
    "simple shake module size is wrong!");

class soShakeModuleImpl : public soShakeModule {
public:
    soModuleAccesser* m_moduleAccesser;
    soArray<soShakeTerm>* m_shakeTermArray;
    soShakeData* m_shakeData;
    float m_scale;
    s32 m_currentTerm;
    u32 m_flags;

    soShakeModuleImpl(
        soModuleAccesser* moduleAccesser,
        soArray<soShakeTerm>* shakeTermArray,
        soShakeData* shakeData);
    virtual ~soShakeModuleImpl();
};
static_assert(sizeof(soShakeModuleImpl) == 0x1c,
    "Class is wrong size!");

template <u32 TTermCount, class TShakeModule>
class soShakeModuleBuildConfig { };

template <class TShakeModuleBuildConfig>
class soShakeModuleBuilder;

template <u32 TTermCount, class TShakeModule>
class soShakeModuleBuilder<
    soShakeModuleBuildConfig<TTermCount, TShakeModule> > {
    typedef soArrayVector<soShakeTerm, TTermCount> ShakeTermArrayVector;
    typedef soArraySelectHolder<true, ShakeTermArrayVector>
        ShakeTermArrayHolder;
    ShakeTermArrayHolder m_shakeTermArrayHolder;
    TShakeModule m_shakeModule;

public:
    soShakeModuleBuilder(
        soModuleAccesser* moduleAccesser, soShakeData* shakeData);
    ~soShakeModuleBuilder();

    soShakeModule* getModule() {
        return &m_shakeModule;
    }
};
