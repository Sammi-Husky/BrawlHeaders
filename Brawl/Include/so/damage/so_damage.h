#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_log.h>

class soDamage {
public:
    float m_totalDamage;
    float m_damage;
    float m_powerMax;
    float m_reaction;
    soCollisionLog m_collisionLog;
    soCollisionAttackData m_attackData;
    float m_lr;
    Vec3f m_pos;
    float m_140;
    float m_144;
    float m_damage_;
    int m_teamOwnerId;
    char _156[4];
};
static_assert(sizeof(soDamage) == 160, "Class is wrong size!"); // size 160