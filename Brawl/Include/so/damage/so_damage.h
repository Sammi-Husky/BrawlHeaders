#pragma once

#include <StaticAssert.h>
#include <types.h>

class soDamage {
public:
    float totalDamage;
    float damage;
    float powerMax;
    float reaction;
    char _spacer2[32];
    char teamId;
    char _spacer3[31];
    int vector;
    char _spacer4[40];
    float side;
    char _spacer5[20];
    float m_damage_;
    char _152[8];
};
static_assert(sizeof(soDamage) == 160, "Class is wrong size!"); // size 160