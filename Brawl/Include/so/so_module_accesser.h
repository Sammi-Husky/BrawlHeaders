#pragma once

#include <StaticAssert.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/collision/so_collision_search_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/damage/so_damage_module_impl.h>
#include <so/effect/so_effect_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/model/so_model_module_impl.h>
#include <so/motion/so_motion_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/resource/so_resource_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/slow/so_slow_module_impl.h>
#include <so/sound/so_sound_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <types.h>

class StageObject;

class soModuleEnumeration {
public:
    soResourceModule* m_resourceModule;
    soModelModule* m_modelModule;
    soMotionModule* m_motionModule;
    soPostureModule* m_postureModule;
    soGroundModule* m_groundModule;
    soSituationModule* m_situationModule;
    void* m_teamModule;
    soCollisionAttackModule* m_collisionAttackModule;
    soCollisionHitModule* m_collisionHitModule;
    void* m_collisionShieldModule;
    void* m_collisionReflectorModule;
    void* m_collisionShieldModule2;
    void* m_collisionCatchModule;
    soCollisionSearchModule* m_collisionSearchModule;
    soDamageModule* m_damageModule;
    void* m_catchModule;
    void* m_captureModule;
    void* m_stopModule;
    void* m_turnModule;
    void* m_shakeModule;
    soSoundModule* m_soundModule;
    void* m_linkModule;
    void* m_visibilityModule;
    soControllerModule* m_controllerModule;
    void* m_cameraModule;
    soWorkManageModule* m_workManageModule;
    void* m_debugModule;
    void* m_animCmdModule;
    soStatusModule* m_statusModule;
    void* m_generalTermDisideModule;
    void* m_switchDecideModule;
    void* m_kineticModule;
    soEventManageModule* m_eventManageModule;
    void* m_generateArticleManageModule;
    soEffectModule* m_effectModule;
    void* m_comboModule;
    void* m_areaModule;
    void* m_territoryModule;
    void* m_targetSearchModule;
    void* m_physicsModule;
    void* m_slopeModule;
    void* m_shadowModule;
    void* m_itemManageModule;
    void* m_colorBlendModule;
    void* m_jostleModule;
    void* m_abnormalModule;
    soSlowModule* m_slowModule;
    void* m_reflectModule;
    void* m_heapModule;
    void* m_paramCustomizeModule;
    void* m_glowModule;
};
static_assert(sizeof(soModuleEnumeration) == 204, "Class is wrong size!");

class soModuleAccesser {
public:
    void* vtable2;
    char _4[4];
    StageObject* m_stageObject;
    soModuleEnumeration m_moduleEnumeration;
    soModuleEnumeration* m_enumerationStart;
    void* vtable1;

    inline soMotionModule* getMotionModule()
    {
        return this->m_enumerationStart->m_motionModule;
    }

    inline soPostureModule* getPostureModule()
    {
        return this->m_enumerationStart->m_postureModule;
    }

    inline soGroundModule* getGroundModule()
    {
        return this->m_enumerationStart->m_groundModule;
    }

    inline soSituationModule* getSituationModule()
    {
        return this->m_enumerationStart->m_situationModule;
    }

    inline soCollisionAttackModule* getCollisionAttackModule()
    {
        return this->m_enumerationStart->m_collisionAttackModule;
    }

    inline soCollisionHitModule* getCollisionHitModule()
    {
        return this->m_enumerationStart->m_collisionHitModule;
    }

    inline soCollisionSearchModule* getCollisionSearchModule()
    {
        return this->m_enumerationStart->m_collisionSearchModule;
    }

    inline soDamageModule* getDamageModule()
    {
        return this->m_enumerationStart->m_damageModule;
    }

    inline soSoundModule* getSoundModule()
    {
        return this->m_enumerationStart->m_soundModule;
    }

    inline soControllerModule* getControllerModule()
    {
        return this->m_enumerationStart->m_controllerModule;
    }

    inline soWorkManageModule* getWorkManageModule()
    {
        return this->m_enumerationStart->m_workManageModule;
    }

    inline soStatusModule* getStatusModule()
    {
        return this->m_enumerationStart->m_statusModule;
    }

    inline soEventManageModule* getEventManageModule()
    {
        return this->m_enumerationStart->m_eventManageModule;
    }

    inline soEffectModule* getEffectModule()
    {
        return this->m_enumerationStart->m_effectModule;
    }

    inline soSlowModule* getSlowModule()
    {
        return this->m_enumerationStart->m_slowModule;
    }
};
static_assert(sizeof(soModuleAccesser) == 224, "Class is wrong size!");
