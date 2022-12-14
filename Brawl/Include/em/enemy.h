#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <em/em_create.h>
#include <so/stageobject.h>
#include <gr/gr_gimmick_motion_path.h>

class Enemy : public StageObject, public soStatusEventObserver, public soCollisionAttackEventObserver,
        public soCollisionSearchEventObserver, public soCaptureEventObserver, public soCollisionAbsorberEventObserver,
        public soCollisionReflectorEventObserver {

    EnemyID m_enemyID;
    char _176[4];
    EnemyID m_connectedEnemyID;
    u32 m_difficultyLevel;
    char _188[12];
    grGimmickMotionPath* m_motionPath;
    char _204[16];
    soModuleAccesser moduleAccesser;
    char _444[20820];

    // TODO: virtual functions

    STATIC_CHECK(sizeof(Enemy) == 21264)
};
