#pragma once

#include <StaticAssert.h>
#include <so/capture/so_capture_event_presenter.h>
#include <types.h>

class soModuleAccesser;

class soCatchModule {
public:
    virtual ~soCatchModule();
};

class soCatchModuleImpl :
    public soCatchModule,
    public soCaptureEventObserver {
public:
    soModuleAccesser* m_moduleAccesser;
    u8 m_catchState[0x0c];
    s32 m_catchKind;
    u8 m_managerState[0x2c];
    soCatchModuleImpl* m_owner;
    u8 m_runtimeState[0x0d];
    bool m_isActive;
    u8 m_padding[2];

    soCatchModuleImpl(soModuleAccesser* moduleAccesser, s32 catchKind);
    virtual ~soCatchModuleImpl();
};
static_assert(sizeof(soCatchModuleImpl) == 0x64,
    "Class is wrong size!");
static_assert(offsetof(soCatchModuleImpl, m_moduleAccesser) == 0x10,
    "Class is wrong size!");
static_assert(offsetof(soCatchModuleImpl, m_catchKind) == 0x20,
    "Class is wrong size!");
static_assert(offsetof(soCatchModuleImpl, m_owner) == 0x50,
    "Class is wrong size!");

template <class TCatchModule, s32 TCatchKind>
class soCatchModuleBuildConfig { };

template <class TCatchModuleBuildConfig>
class soCatchModuleBuilder;

template <class TCatchModule, s32 TCatchKind>
class soCatchModuleBuilder<
    soCatchModuleBuildConfig<TCatchModule, TCatchKind> > {
    TCatchModule m_catchModule;

public:
    soCatchModuleBuilder(soModuleAccesser* moduleAccesser) :
        m_catchModule(moduleAccesser, TCatchKind) { }
    ~soCatchModuleBuilder();

    soCatchModule* getModule() {
        return &m_catchModule;
    }
};
