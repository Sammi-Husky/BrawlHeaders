#pragma once

#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <so/controller/so_controller_module_impl.h>
#include <so/stageobject.h>
#include <types.h>

namespace soExternalValueAccesser {
    int getTeamNo(StageObject* stageObject);
    Vec3f getPos(StageObject* stageObject);
    float getLr(StageObject* stageObject);
    SituationKind getSituationKind(StageObject* stageObject);
    int getStatusKind(StageObject* stageObject);
    bool getWorkFlag(StageObject* stageObject, u32);
    int getWorkInt(StageObject* stageObject, u32);
    soModuleAccesser* getModuleAccesser(StageObject* stageObject);
    soCollisionHitModule* getCollisionHitModule(StageObject* stageObject);
    soControllerModule* getControllerModule(StageObject* stageObject);
    u32 getTeamOwnerId(StageObject* stageObject);
}
