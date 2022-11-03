#pragma once

#include <types.h>
#include <ft/fighter.h>

namespace ftExternalValueAccesser {
    float getWeight(Fighter* fighter);
    Vec3f getHipPos(Fighter* fighter);
}