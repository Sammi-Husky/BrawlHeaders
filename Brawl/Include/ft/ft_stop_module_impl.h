#pragma once

#include <StaticAssert.h>
#include <so/stop/so_stop_module_impl.h>

class ftStopModuleImpl : public soStopModuleImpl {
public:
    ftStopModuleImpl(soModuleAccesser* moduleAccesser);
    virtual ~ftStopModuleImpl();
};
static_assert(sizeof(ftStopModuleImpl) == 0x24,
    "Class is wrong size!");

template <class TStopModule>
class ftStopModuleBuildConfig { };

template <class TStopModuleBuildConfig>
class ftStopModuleBuilder;

template <class TStopModule>
class ftStopModuleBuilder<ftStopModuleBuildConfig<TStopModule> > {
    TStopModule m_stopModule;

public:
    ftStopModuleBuilder(soModuleAccesser* moduleAccesser) :
        m_stopModule(moduleAccesser) { }
    ~ftStopModuleBuilder();

    soStopModule* getModule() {
        return &m_stopModule;
    }
};
