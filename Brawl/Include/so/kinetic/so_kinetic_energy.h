#pragma once

#include <so/so_null.h>
#include <so/so_enable.h>
#include <so/so_suspend.h>
#include <mt/mt_vector.h>

class soModuleAccesser;

class soKineticEnergy : public soNullable, public soEnable, public soSuspendable {
public:
    virtual void updateEnergy(soModuleAccesser* moduleAccesser);
    virtual Vec2f getSpeed();
    virtual Vec3f getSpeed3f();
    virtual Vec3f getRotation();
    virtual void resetEnergy(u32, Vec2f*, Vec3f*, soModuleAccesser* moduleAccesser);
    virtual void clearSpeed();
    virtual void clearRotSpeed();
    virtual void mulSpeed(Vec3f* speed);
    virtual void mulAccel(Vec3f* accel);
    virtual void reflectSpeed(Vec3f* speed);
    virtual void reflectAccel(Vec3f* accel);
    virtual void onConsiderGroundFriction();
    virtual void offConsiderGroundFriction();
    virtual ~soKineticEnergy();
};
static_assert(sizeof(soKineticEnergy) == 8, "Class is wrong size!");