#pragma once

#include <StaticAssert.h>
#include <so/kinetic/so_kinetic_energy.h>

class soKineticEnergyNormal : public soKineticEnergy {
public:
    soKineticEnergyNormal();

    Vec2f m_speed;
    Vec2f m_accel;
    Vec2f m_speedMax;
    Vec2f m_brake;

    void enable() {
        m_isEnable = true;
    }
};
static_assert(sizeof(soKineticEnergyNormal) == 0x28, "Class is wrong size!");
static_assert(offsetof(soKineticEnergyNormal, m_speed) == 0x08, "Class is wrong size!");
static_assert(offsetof(soKineticEnergyNormal, m_accel) == 0x10, "Class is wrong size!");
static_assert(offsetof(soKineticEnergyNormal, m_speedMax) == 0x18, "Class is wrong size!");
static_assert(offsetof(soKineticEnergyNormal, m_brake) == 0x20, "Class is wrong size!");
