#pragma once

#include <StaticAssert.h>
#include <so/anim/so_anim_cmd_module_impl.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/collision/so_collision_hit_module_impl.h>
#include <so/collision/so_collision_search_module_impl.h>
#include <so/collision/so_collision_shield_module_impl.h>
#include <so/color/so_color_blend_module_impl.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/damage/so_damage_module_impl.h>
#include <so/effect/so_effect_module_impl.h>
#include <so/ground/so_ground_module_impl.h>
#include <so/model/so_model_module_impl.h>
#include <so/motion/so_motion_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/resource/so_resource_module_impl.h>
#include <so/shadow/so_shadow_module_impl.h>
#include <so/situation/so_situation_module_impl.h>
#include <so/slow/so_slow_module_impl.h>
#include <so/sound/so_sound_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/param/so_param_customize_module_impl.h>
#include <so/camera/so_camera_module_impl.h>
#include <so/link/so_link_module_impl.h>
#include <so/capture/so_capture_module_impl.h>
#include <so/item/so_item_manage_module_impl.h>
#include <so/turn/so_turn_module_impl.h>
#include <so/stop/so_stop_module_impl.h>
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
    void* m_collisionAbsorberModule;
    void* m_collisionCatchModule;
    soCollisionSearchModule* m_collisionSearchModule;
    soDamageModule* m_damageModule;
    void* m_catchModule;
    void* m_captureModule;
    soStopModule* m_stopModule;
    void* m_turnModule;
    void* m_shakeModule;
    soSoundModule* m_soundModule;
    soLinkModule* m_linkModule; // +0x54
    void* m_visibilityModule;
    soControllerModule* m_controllerModule;
    soCameraModule* m_cameraModule;
    soWorkManageModule* m_workManageModule;
    void* m_debugModule;
    soAnimCmdModule* m_animCmdModule;
    soStatusModule* m_statusModule;
    void* m_generalTermDecideModule;
    void* m_switchDecideModule;
    soKineticModule* m_kineticModule;
    soEventManageModule* m_eventManageModule;
    void* m_generateArticleManageModule;
    soEffectModule* m_effectModule;
    void* m_comboModule;
    void* m_areaModule;
    void* m_territoryModule;
    void* m_targetSearchModule;
    void* m_physicsModule;
    void* m_slopeModule;
    soShadowModule* m_shadowModule;
    soItemManageModule* m_itemManageModule;
    soColorBlendModule* m_colorBlendModule;
    void* m_jostleModule;
    void* m_abnormalModule;
    soSlowModule* m_slowModule;
    void* m_reflectModule;
    void* m_heapModule;
    soParamCustomizeModule* m_paramCustomizeModule;
    void* m_glowModule;
};
static_assert(sizeof(soModuleEnumeration) == 204, "Class is wrong size!");

class soModuleAccesser {
public:
    void* vtable2;
    char _4[4];
    StageObject* m_stageObject;
    soModuleEnumeration m_moduleEnumeration;
    soModuleEnumeration* m_enumerationStart; // +0xD8
    void* vtable1;

    inline soModelModule* getModelModule() const
    {
        return this->m_enumerationStart->m_modelModule;
    }

    inline soMotionModule* getMotionModule() const
    {
        return this->m_enumerationStart->m_motionModule;
    }

    inline soPostureModule* getPostureModule() const
    {
        return this->m_enumerationStart->m_postureModule;
    }

    inline soGroundModule* getGroundModule() const
    {
        return this->m_enumerationStart->m_groundModule;
    }

    inline soShadowModule* getShadowModule() const
    {
        return this->m_enumerationStart->m_shadowModule;
    }

    inline soSituationModule* getSituationModule() const
    {
        return this->m_enumerationStart->m_situationModule;
    }

    inline soCollisionAttackModule* getCollisionAttackModule() const
    {
        return this->m_enumerationStart->m_collisionAttackModule;
    }

    inline soCollisionHitModule* getCollisionHitModule() const
    {
        return this->m_enumerationStart->m_collisionHitModule;
    }

    inline soCollisionSearchModule* getCollisionSearchModule() const
    {
        return this->m_enumerationStart->m_collisionSearchModule;
    }

    inline soDamageModule* getDamageModule() const
    {
        return this->m_enumerationStart->m_damageModule;
    }

    inline soSoundModule* getSoundModule() const
    {
        return this->m_enumerationStart->m_soundModule;
    }

    inline soControllerModule* getControllerModule() const
    {
        return this->m_enumerationStart->m_controllerModule;
    }

    inline soCameraModule* getCameraModule() const
    {
        return this->m_enumerationStart->m_cameraModule;
    }

    inline soWorkManageModule* getWorkManageModule() const
    {
        return this->m_enumerationStart->m_workManageModule;
    }

    inline soAnimCmdModule* getAnimCmdModule()  const
    {
        return this->m_enumerationStart->m_animCmdModule;
    }

    inline soStatusModule* getStatusModule() const
    {
        return this->m_enumerationStart->m_statusModule;
    }

    inline soKineticModule* getKineticModule() const
    {
        return this->m_enumerationStart->m_kineticModule;
    }

    inline soEventManageModule* getEventManageModule() const
    {
        return this->m_enumerationStart->m_eventManageModule;
    }

    inline soEffectModule* getEffectModule() const
    {
        return this->m_enumerationStart->m_effectModule;
    }

    inline soSlowModule* getSlowModule() const
    {
        return this->m_enumerationStart->m_slowModule;
    }

    inline soItemManageModule* getItemManageModule() const
    {
        return this->m_enumerationStart->m_itemManageModule;
    }

    inline soColorBlendModule* getColorBlendModule() const
    {
        return this->m_enumerationStart->m_colorBlendModule;
    }

    inline soParamCustomizeModule* getParamCustomizeModule() const
    {
        return this->m_enumerationStart->m_paramCustomizeModule;
    }
};
static_assert(sizeof(soModuleAccesser) == 224, "Class is wrong size!");

class soModuleAccesserNull : public soModuleAccesser {

};

extern soModuleAccesserNull g_soModuleAccesserNull;

template <class T>
class soModuleAccesserBuilder {
    T t;
};
