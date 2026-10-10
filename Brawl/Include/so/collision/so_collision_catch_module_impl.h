#pragma once

#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <mt/mt_vector.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/collision/so_collision.h>
#include <so/collision/so_collision_catch_event_presenter.h>
#include <so/event/so_event_presenter.h>
#include <so/status/so_status_event_presenter.h>
#include <so/so_array.h>
#include <types.h>

class soModuleAccesser;

struct soCollisionCatchData {
    Vec3f m_offsetPos;
    float m_size;
    u32 m_nodeIndex;
    soCollision::CategoryMask m_targetCategory;
    u32 m_flags;
};
static_assert(sizeof(soCollisionCatchData) == 0x1c,
    "Class is wrong size!");

class soCollisionCatchPart {
public:
    soCollisionCatchData m_catchData;
    soArrayVector<clTarget, 6> m_clTargetArrayVector;
    u32 m_debugState;

    soCollisionCatchPart(soCollision::Category selfCategory);
    ~soCollisionCatchPart();
};
static_assert(sizeof(soCollisionCatchPart) == 0x5c,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchPart, m_catchData) == 0x00,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchPart, m_clTargetArrayVector) == 0x1c,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchPart, m_debugState) == 0x58,
    "Class is wrong size!");

class soCollisionCatchModule {
public:
    virtual ~soCollisionCatchModule();
};

class soCollisionCatchModuleImpl :
    public soCollisionCatchModule,
    public soStatusEventObserver,
    public soAnimCmdEventObserver,
    public soEventPresenter<soCollisionCatchEventObserver> {
public:
    soModuleAccesser* m_moduleAccesser;
    soArray<soCollisionCatchPart>* m_collisionCatchPartArray;
    s32 m_currentPartIndex;
    float m_scale;
    u32 m_logState;
    soArrayVector<soCollisionGroup, 1> m_collisionGroupArrayVector;
    soCollision m_collision;
    u8 m_collisionLogState[8];
    bool m_isActive;
    bool m_checkCatch;
    bool m_collisionOccurred;
    bool m_isCatchable;

    soCollisionCatchModuleImpl(
        soModuleAccesser* moduleAccesser, int taskId,
        gfTask::Category taskCategory,
        soArray<soCollisionCatchPart>* collisionCatchPartArray,
        soEventObserverRegistrationDesc* registrationDesc,
        bool checkCatch, bool isCatchable);
    virtual ~soCollisionCatchModuleImpl();
};
static_assert(sizeof(soCollisionCatchModuleImpl) == 0xe4,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchModuleImpl, m_moduleAccesser) == 0x28,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchModuleImpl, m_collisionCatchPartArray) == 0x2c,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchModuleImpl, m_collisionGroupArrayVector) == 0x3c,
    "Class is wrong size!");
static_assert(offsetof(soCollisionCatchModuleImpl, m_collision) == 0xc0,
    "Class is wrong size!");

template <
    soCollision::Category TCategory, u32 TPartCount,
    class TCollisionCatchModule, bool TCheckCatch, bool TIsCatchable>
class soCollisionCatchModuleBuildConfig { };

template <class TCollisionCatchBuildConfig>
class soCollisionCatchModuleBuilder;

template <
    soCollision::Category TCategory, u32 TPartCount,
    class TCollisionCatchModule, bool TCheckCatch, bool TIsCatchable>
class soCollisionCatchModuleBuilder<
    soCollisionCatchModuleBuildConfig<
        TCategory, TPartCount, TCollisionCatchModule,
        TCheckCatch, TIsCatchable> > {
    soArrayVector<soCollisionCatchPart, TPartCount>
        m_collisionCatchPartArrayVector;
    TCollisionCatchModule m_collisionCatchModule;

public:
    soCollisionCatchModuleBuilder(
        soModuleAccesser* moduleAccesser, int taskId,
        gfTask::Category taskCategory,
        soEventObserverRegistrationDesc* registrationDesc);
    ~soCollisionCatchModuleBuilder();

    soCollisionCatchModule* getModule() {
        return &m_collisionCatchModule;
    }
};
