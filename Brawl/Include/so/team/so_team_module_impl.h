#pragma once

#include <StaticAssert.h>
#include <ft/ft_team.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/status/so_status_event_presenter.h>
#include <types.h>

class soModuleAccesser;
class soEventObserverRegistrationDesc;

class soTeamModule {
public:
    virtual ~soTeamModule();

    bool m_isActive;
    u8 m_padding[3];
};
static_assert(sizeof(soTeamModule) == 0x8,
    "soTeamModule size is wrong!");

class soTeamEventPresenter {
public:
    virtual ~soTeamEventPresenter();

    s16 m_manageId;
    s16 m_unitId;
    void* m_eventUnit;
};
static_assert(sizeof(soTeamEventPresenter) == 0xC,
    "soTeamEventPresenter size is wrong!");

class soTeamModuleImpl :
    public soTeamModule,
    public soStatusEventObserver,
    public soAnimCmdEventObserver {
public:
    soModuleAccesser* m_moduleAccesser;
    soTeam* m_team;
    soTeam* m_effectiveTeam;
    soTeam* m_indirectTeam;
    s32 m_eventManagerId;
    soTeamEventPresenter m_eventPresenter;
    bool m_isEnabled;
    u8 m_padding[3];

    soTeamModuleImpl(
        soTeam* team, soTeam* effectiveTeam, soTeam* indirectTeam,
        soModuleAccesser* moduleAccesser,
        soEventObserverRegistrationDesc* registrationDesc);
    virtual ~soTeamModuleImpl();
};
static_assert(sizeof(soTeamModuleImpl) == 0x44,
    "soTeamModuleImpl size is wrong!");

class soTeamModuleBuildConfigTag { };

template <class TTeamModule>
class soTeamModuleBuilder {
public:
    soTeamModuleBuildConfigTag m_configTag;
    ftTeam m_team;
    ftTeamIndirect m_indirectTeam;
    TTeamModule m_module;

    soTeamModuleBuilder(s32 teamKind, soModuleAccesser* moduleAccesser);
    ~soTeamModuleBuilder();

    TTeamModule* getModule() {
        return &m_module;
    }
};
