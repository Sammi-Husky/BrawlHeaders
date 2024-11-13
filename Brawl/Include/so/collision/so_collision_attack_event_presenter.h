#pragma once

#include <types.h>
#include <so/event/so_event_presenter.h>
#include <so/collision/so_collision_log.h>

class soModuleAccesser;

class soCollisionAttackEventObserver : public soEventObserver<soCollisionAttackEventObserver> {
public:
    soCollisionAttackEventObserver(short unitID) : soEventObserver<soCollisionAttackEventObserver>(unitID) {};

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventCollisionAttack(float power, soCollisionLog* collisionLog, soModuleAccesser* moduleAccesser);;
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
};
static_assert(sizeof(soCollisionAttackEventObserver) == 12, "Class is wrong size!");
