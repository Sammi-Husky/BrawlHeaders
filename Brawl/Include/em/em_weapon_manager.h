#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <types.h>
#include <ut/ut_stageobject_pool.h>
#include <wn/wn_em_simple.h>

class emWeaponManager : public utStageObjectPool<wnemSimple, 39> {
    char _spacer[0x270];

public:
    virtual ~emWeaponManager();
    virtual void activateObject(wnemSimple* wnem, float, float, int, int, void*, int, Vec3f*, int, int, u8, int, u16);
    virtual void deactivateObject(wnemSimple* wnem);
    virtual void resetProcFncList();
    virtual void resetManageWeaponList();

    static void create();
    static void remove();
    static emWeaponManager* getInstance();
};
static_assert(sizeof(emWeaponManager) == 0x298, "Class is wrong size!");