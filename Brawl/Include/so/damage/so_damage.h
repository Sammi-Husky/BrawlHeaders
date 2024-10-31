#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_log.h>

struct soDamageLog {
    float m_reaction;
    int m_level;
    int m_height;
    Vec2f m_speed;
    float m_angle;
    float m_lr;
    float m_damageFrame;
    float m_hitStopFrame;
    soCollisionAttackData::Attribute m_attribute;
    float m_damageAdd;
    int m_teamId;
    float m_hitStopDelay;
    Vec2f m_0x34;
    int m_taskId;
    int m_teamOwnerId;
    gfTask::Category m_taskCategory : 8;
    bool : 1;
    bool : 1;
    bool : 1;
    bool : 1;
    bool : 1;
    bool m_isDirect : 1;
    bool : 1;
    bool : 1;
    char _0x46[2];
};
static_assert(sizeof(soDamageLog) == 0x48, "Class is wrong size!");

class soDamage {
public:
    float m_damage;
    float m_damageAdd;
    float m_powerMax;
    float m_reaction;
    soCollisionLog m_collisionLog;
    soCollisionAttackData m_attackData;
    float m_lr;
    Vec3f m_pos;
    float m_140;
    float m_144;
    float m_damageAdd_;
    int m_teamOwnerId;
    char _156[4];
};
static_assert(sizeof(soDamage) == 160, "Class is wrong size!"); // size 160