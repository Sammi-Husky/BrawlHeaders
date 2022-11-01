#pragma once

#include <types.h>
#include <mt/mt_vector.h>

class StageObject; // TODO: actually import StageObject

namespace soExternalValueAccesser {
    int getTeamNo(StageObject* stageObject);
    Vec3f getPos(StageObject* stageObject);
}
