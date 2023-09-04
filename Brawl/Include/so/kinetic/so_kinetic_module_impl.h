#pragma once

#include <so/so_null.h>
#include <so/so_instance_manager.h>
#include <so/event/so_event_observer.h>
#include <so/kinetic/so_kinetic_energy.h>

class soKineticModule : public soNullable {
public:
    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy* kineticEnergy, int, soInstanceAttribute*, short);
    virtual void eraseEnergy(int index);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int index);
    virtual bool isContain(int index);
    virtual void updateEnergy(soModuleAccesser* moduleAccesser, soInstanceAttribute*);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2f getSumSpeed(soInstanceAttribute*);
    virtual Vec3f getSumSpeed3f(soInstanceAttribute*);
    virtual Vec3f getSumRotation(soInstanceAttribute*);
    virtual void setConsiderGroundFriction(bool, soInstanceAttribute*);
    virtual void mulSpeed(Vec3f* speed, soInstanceAttribute*);
    virtual void mulAccel(Vec3f* accel, soInstanceAttribute*);
    virtual void reflectSpeed(Vec3f* speed, soInstanceAttribute*);
    virtual void reflectAccel(Vec3f* accel, soInstanceAttribute*);
    virtual void changeKinetic(int kineticType, soModuleAccesser* moduleAccesser);
    virtual int getKineticType();
    virtual void addSpeed(Vec3f* speed, soModuleAccesser* moduleAccesser);
    virtual void addSpeedOutside(int, Vec3f* speed);
};
static_assert(sizeof(soKineticModule) == 8, "Class is wrong size!");

class soKineticModuleImpl : public soKineticModule, public soAnimCmdEventObserver {
    soInstanceManagerFullProperty<soKineticEnergy*>* m_kineticEnergyInstanceManager;
    int m_kineticType;
    soModuleAccesser* m_moduleAccesser;

public:

    virtual void activate();
    virtual void deactivate();
    virtual void addEnergy(soKineticEnergy* kineticEnergy, int, soInstanceAttribute*, short);
    virtual void eraseEnergy(int index);
    virtual void eraseEnergyAll();
    virtual soKineticEnergy* getEnergy(int index);
    virtual bool isContain(int index);
    virtual void updateEnergy(soModuleAccesser* moduleAccesser, soInstanceAttribute*);
    virtual void clearSpeedAll();
    virtual void suspendEnergyAll();
    virtual void resumeEnergyAll();
    virtual void unableEnergyAll();
    virtual Vec2f getSumSpeed(soInstanceAttribute*);
    virtual Vec3f getSumSpeed3f(soInstanceAttribute*);
    virtual Vec3f getSumRotation(soInstanceAttribute*);
    virtual void setConsiderGroundFriction(bool, soInstanceAttribute*);
    virtual void mulSpeed(Vec3f* speed, soInstanceAttribute*);
    virtual void mulAccel(Vec3f* accel, soInstanceAttribute*);
    virtual void reflectSpeed(Vec3f* speed, soInstanceAttribute*);
    virtual void reflectAccel(Vec3f* accel, soInstanceAttribute*);
    virtual void changeKinetic(int kineticType, soModuleAccesser* moduleAccesser);
    virtual int getKineticType();

    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual u32 isObserv(char unk1);

};
static_assert(sizeof(soKineticModuleImpl) == 32, "Class is wrong size!");
