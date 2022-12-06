#pragma once

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
    char _spacer5[32];
}; // size 160