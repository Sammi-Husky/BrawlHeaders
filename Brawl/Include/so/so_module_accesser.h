#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_resource_module_impl.h>
#include <so/so_model_module_impl.h>
#include <so/so_motion_module_impl.h>
#include <so/so_posture_module_impl.h>
#include <so/so_ground_module_impl.h>
#include <so/so_status_module_impl.h>

class StageObject;

class soModuleEnumeration {
public:
    soResourceModule* m_resourceModule;
    soModelModule* m_modelModule;
    soMotionModule* m_motionModule;
    soPostureModule* m_postureModule;
    soGroundModule* m_groundModule;
    void* m_situationModule;
    void* m_teamModule;
    void* m_collisionAttackModule;
    void* m_collisionHitModule;
    void* m_collisionShieldModule;
    void* m_collisionReflectorModule;
    void* m_collisionShieldModule2;
    void* m_collisionCatchModule;
    void* m_collisionSearchModule;
    void* m_damageModule;
    void* m_catchModule;
    void* m_captureModule;
    void* m_stopModule;
    void* m_turnModule;
    void* m_shakeModule;
    void* m_soundModule;
    void* m_linkModule;
    void* m_visibilityModule;
    void* m_controllerModule;
    void* m_cameraModule;
    void* m_workManageModule;
    void* m_debugModule;
    void* m_animCmdModule;
    soStatusModule* m_statusModule;
    void* m_generalTermDisideModule;
    void* m_switchDecideModule;
    void* m_kineticModule;
    void* m_eventManageModule;
    void* m_generateArticleManageModule;
    void* m_effectModule;
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
    void* m_slowModule;
    void* m_reflectModule;
    void* m_heapModule;
    void* m_paramCustomizeModule;
    void* m_glowModule;

    STATIC_CHECK(sizeof(soModuleEnumeration) == 204)
};

class soModuleAccesser {
public:
    void* vtable2;
    char _4[4];
    StageObject* m_stageObject;
    soModuleEnumeration m_moduleEnumeration;
    soModuleEnumeration* m_enumerationStart;
    void* vtable1;

    inline soMotionModule* getMotionModule() {
        return this->m_enumerationStart->m_motionModule;
    }

    inline soPostureModule* getPostureModule() {
        return this->m_enumerationStart->m_postureModule;
    }

    inline soGroundModule* getGroundModule() {
        return this->m_enumerationStart->m_groundModule;
    }

    inline soStatusModule* getStatusModule() {
        return this->m_enumerationStart->m_statusModule;
    }

    STATIC_CHECK(sizeof(soModuleAccesser) == 224)
};
