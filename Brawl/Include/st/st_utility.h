#pragma once

#include <types.h>
#include <mt/mt_vector.h>
#include <gr/gr_collision.h>

bool stRayCheck(Vec3f* pos, Vec3f* dir, Vec3f* outHitPos, Vec3f* outCollNormalVec, u8, grCollision*, u8, u8 targetMask);
