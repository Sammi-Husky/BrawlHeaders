#pragma once

#include <types.h>
#include <so/event/so_event_observer.h>

class soModuleAccesser;
class BaseItem;

class soItemManageEventObserver : public soEventObserver<soItemManageEventObserver> {
public:
    soItemManageEventObserver(short unitID) : soEventObserver<soItemManageEventObserver>(unitID) {};

    virtual void addObserver(short param1, s8 param2);
    virtual bool notifyHaveItemPreCheck(BaseItem* item, bool*);
    virtual void notifyHaveItem(int, BaseItem* item, int, int, int);
    virtual void notifyAttachItem(BaseItem* item, int, int, int, int);
    virtual void notifyUseItem(BaseItem* item, int, int*);
    virtual void notifyThrowItem(BaseItem* item, int, int*);
    virtual void notifyDropItem();
    virtual void notifyShootBulletItem(BaseItem* item);
    virtual void notifyEjectItem(BaseItem* item, int);
    virtual void notifyEjectAttachItem(BaseItem* item, int, int);
    virtual void notifyVisibilityItem(BaseItem* item, int, int, int);
};
static_assert(sizeof(soItemManageEventObserver) == 12, "Class is wrong size!");