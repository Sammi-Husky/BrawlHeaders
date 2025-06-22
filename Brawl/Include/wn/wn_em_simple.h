#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_presenter.h>
#include <types.h>
#include <ut/ut_list.h>
#include <wn/wn_weapon_builder.h>

class wnemSimple_ModuleAccesserBuildConfig {
    // TODO
};

class utWeaponObjectBase : public utListNode {
    virtual ~utWeaponObjectBase();
    virtual void setDeactivate(int unk);
};
static_assert(sizeof(utWeaponObjectBase) == 12, "Class is wrong size!");

class wnemSimple : public utWeaponObjectBase, public wnWeaponBuilder<wnemSimple_ModuleAccesserBuildConfig>, public soDamageEventObserver, public soCollisionSearchEventObserver {
public:
    u8 unk2184[0x50];
    float unk21D4;
    float unk21D8;
    u8 unk21DC[0x198];

    wnemSimple();
    virtual ~wnemSimple();
    // TODO: virtual functions
};
static_assert(sizeof(wnemSimple) == 0x2374, "Class is wrong size!");
