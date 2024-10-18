#pragma once

#include <types.h>
#include <so/event/so_event_observer.h>
#include <so/collision/so_collision_log.h>

class soModuleAccesser;
class soCollisionAttackModule;
class soCollisionSearchModule;

class soCollisionShieldEventObserver : public soEventObserver<soCollisionShieldEventObserver> {
public:
    soCollisionShieldEventObserver() : soEventObserver<soCollisionShieldEventObserver>(0xe) {};
    soCollisionShieldEventObserver(short unitID) : soEventObserver<soCollisionShieldEventObserver>(unitID) {};
    soCollisionShieldEventObserver(short, s8);

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventCollisionShield(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionShieldSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionShieldCheck();
};
static_assert(sizeof(soCollisionShieldEventObserver) == 12, "Class is wrong size!");

class soCollisionReflectorEventObserver : public soEventObserver<soCollisionReflectorEventObserver> {
public:
    soCollisionReflectorEventObserver() : soEventObserver<soCollisionReflectorEventObserver>(0xf) {};
    soCollisionReflectorEventObserver(short unitID) : soEventObserver<soCollisionReflectorEventObserver>(unitID) {};
    soCollisionReflectorEventObserver(short, s8);

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventCollisionReflector(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual void notifyEventCollisionReflectorSearch(soCollisionSearchModule* searchModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionReflectorCheck();
};
static_assert(sizeof(soCollisionReflectorEventObserver) == 12, "Class is wrong size!");

class soCollisionAbsorberEventObserver : public soEventObserver<soCollisionAbsorberEventObserver> {
public:
    soCollisionAbsorberEventObserver(short unitID) : soEventObserver<soCollisionAbsorberEventObserver>(unitID) {};

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventCollisionAbsorber(soCollisionAttackModule* attackModule, soCollisionLog* collisionLog, u32 groupIndex, soModuleAccesser* moduleAccesser, float power, float posX, float);
    virtual bool notifyEventCollisionAbsorberCheck();
};
static_assert(sizeof(soCollisionAbsorberEventObserver) == 12, "Class is wrong size!");
