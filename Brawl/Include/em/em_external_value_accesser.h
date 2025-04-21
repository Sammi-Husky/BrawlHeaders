#pragma once

#include <StaticAssert.h>
#include <em/enemy.h>
#include <types.h>

namespace emExternalValueAccesser {
    Vec3f getCenterPos(Enemy*);
    u32 getHitStopFrame(Enemy*);
    float getHp(Enemy*, int taskId);
    float getMaxHp(Enemy*, int taskId);
    int getNameMsgId(Enemy*, int taskId);
    float getScore(Enemy*);
    bool isCanAutoRemove(Enemy*);
    bool isCanGetRareItme(Enemy*);
    bool isClipIn(Enemy*);
    bool isFigure(Enemy*);
    void* getFaceTexPtr(Enemy*, int taskId);
}