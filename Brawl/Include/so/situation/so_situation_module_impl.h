#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_observer.h>
#include <so/event/so_event_presenter.h>
#include <types.h>

class soModuleAccesser;

class soSituationModule {
public:
    virtual ~soSituationModule();
    virtual void activate();
    virtual void deactivate();
    virtual int getKind();
    virtual int getPrevKind();
    virtual bool isSituationChanged();
    virtual void setKind(int kind, bool);
    virtual void setKeepAir(bool);
    virtual void update();
};
static_assert(sizeof(soSituationModule) == 4, "Class is wrong size!");

class soSituationModuleImpl : public soSituationModule, public soStatusEventObserver, public soAnimCmdEventObserver, public soEventPresenter<soSituationEventObserver> {
    soModuleAccesser* m_moduleAccesser;
    int m_kind;
    int m_prevKind;
    char _52[8];

public:
    virtual ~soSituationModuleImpl();
    virtual void activate();
    virtual void deactivate();
    virtual int getKind();
    virtual int getPrevKind();
    virtual bool isSituationChanged();
    virtual void setKind(int kind, bool);
    virtual void setKeepAir(bool);
    virtual void update();

    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
};
static_assert(sizeof(soSituationModuleImpl) == 60, "Class is wrong size!");