
#include <StaticAssert.h>
#include <types.h>
#include <wn/weapon.h>

template <typename T>
class wnWeaponBuilder : public Weapon {
    char _spacer[8336];
    // TODO: virtual functions
};
static_assert(sizeof(wnWeaponBuilder<void>) == 8544, "Class is wrong size!");