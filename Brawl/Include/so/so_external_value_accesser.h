#pragma once

#include <types.h>
#include <mt/mt_vector.h>
#include <so/stageobject.h>

namespace soExternalValueAccesser {
    int getTeamNo(StageObject* stageObject);
    Vec3f getPos(StageObject* stageObject);
    float getLr(StageObject* stageObject);
    soModuleAccesser* getModuleAccesser(StageObject* stageObject);
    soCollisionHitModule* getCollisionHitModule(StageObject* stageObject);

}
