
#include <types.h>
#include <StaticAssert.h>
#include <wn/weapon.h>

template <typename T>
class wnWeaponBuilder : public Weapon {
    char _spacer[8336];
    // TODO: virtual functions

    STATIC_CHECK(sizeof(wnWeaponBuilder) == 8544)
};