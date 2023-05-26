#pragma once

#include <StaticAssert.h>
#include <types.h>

class soDamage {
public:
    float m_totalDamage;
    float m_damage;
    float m_powerMax;
    float m_reaction;
    char _spacer2[32];
    char m_teamId;
    char _spacer3[31];
    int m_vector;
    char _spacer4[40];
    float m_side;
    char _spacer5[20];
    float m_damage_;
    char _152[8];
};
static_assert(sizeof(soDamage) == 160, "Class is wrong size!"); // size 160