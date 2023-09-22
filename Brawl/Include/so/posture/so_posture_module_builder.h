#pragma once

#include <types.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/event/so_event_observer.h>
#include <so/so_array.h>

class soPostureModuleBuildConfigInterface {

};

template <u32 NumInterpolation, class PostureModule>
class soPostureModuleBuildConfig : public soPostureModuleBuildConfigInterface {

public:
    soArrayVector<soInterpolation<Vec3f>,NumInterpolation> m_interpolationArrayVector;
    PostureModule m_postureModule;

    soPostureModuleBuildConfig(soModuleAccesser* moduleAccesser, soEventObserverRegistrationDesc* registrationDesc) : m_postureModule(moduleAccesser, &m_interpolationArrayVector, registrationDesc) {
        static_class<soPostureModule*>(m_postureModule)->initRot();
    }

};

template <class BuildConfig>
class soPostureModuleBuilder {
    BuildConfig m_buildConfig;

    soPostureModuleBuilder(soModuleAccesser* moduleAccesser, soEventObserverRegistrationDesc* registrationDesc) : soPostureModuleBuildConfig(moduleAccesser, registrationDesc){

    };
};
