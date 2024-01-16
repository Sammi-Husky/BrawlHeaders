#pragma once

#include <StaticAssert.h>
#include <em/em_create.h>
#include <gr/gr_gimmick_motion_path.h>
#include <so/stageobject.h>
#include <types.h>

class Enemy : public StageObject, public soStatusEventObserver, public soCollisionAttackEventObserver, public soCollisionSearchEventObserver, public soCaptureEventObserver, public soCollisionAbsorberEventObserver, public soCollisionReflectorEventObserver {

    EnemyKind m_enemyKind;
    char _176[4];
    int m_connectedTriggerId;
    u32 m_difficulty;
    u32 m_level;
    char _192[8];
    grGimmickMotionPath* m_motionPath;
    char _204[16];
    soModuleAccesser moduleAccesser;
    char _444[20820];

    // TODO: virtual functions
};
static_assert(sizeof(Enemy) == 21264, "Class is wrong size!");
