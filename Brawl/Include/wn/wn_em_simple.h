#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <ut/ut_list.h>
#include <wn/wn_weapon_builder.h>
#include <so/so_event_observer.h>

class wnemSimple_ModuleAccesserBuildConfig {
    // TODO
};

class utWeaponObjectBase : public utListNode {
    virtual ~utWeaponObjectBase();
    virtual void setDeactivate(int unk);

    STATIC_CHECK(sizeof(utWeaponObjectBase) == 12)
};

class wnemSimple : public utWeaponObjectBase, public wnWeaponBuilder<wnemSimple_ModuleAccesserBuildConfig>, public soDamageEventObserver, public soCollisionSearchEventObserver {
    char _spacer[496];
    // TODO: virtual functions

    STATIC_CHECK(sizeof(wnemSimple) == 9076)
};


