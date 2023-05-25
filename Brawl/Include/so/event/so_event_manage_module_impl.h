#pragma once

#include <types.h>
#include <so/event/so_event_system.h>

class soEventManageModule : public soNullable {
};
static_assert(sizeof(soEventManageModule) == 8, "Class is wrong size!");

class soEventManageModuleImpl : public soEventManageModule, public soEventManager {
public:
    void* m_12;
    short m_manageId;
    short _pad;

    virtual void addUnit(soEventUnit*);
    virtual void eraseUnit(u32);
    virtual bool isNullUnit(u32);
    virtual void eraseObserver(u32, int);
    virtual u32 getObserverCapacity(u32 index);
    virtual u32 getObserverSize(u32 index);
    virtual bool isExist(short);
    virtual int getManageId();
    virtual soEventUnit* getEventUnit(short);


};
static_assert(sizeof(soEventManageModuleImpl) == 20, "Class is wrong size!");
