#pragma once

#include <gr/gr_collision.h>
#include <gr/gr_collision_shape_circle.h>
#include <gr/gr_collision_shape_rhombus.h>

class grCollStatus {
public:
    // 0
    grCollStatus* next;
    // 4
    grCollStatus* prev;
    // 8
    char _spacer[6];
    // 14
    short exclusiveLineAttr;
    // 16
    int taskId;
    // 20
    char _spacer2[65];
    // 85
    char cliffTeam;
    // 86
    char _spacer3[6];
    // 92
    grCollShape* prevCollShape;
    // 96
    grCollShape* currentCollShape;
    // 100
    char _spacer4[10];
    // 110
    char targetLineCategory;
    // 111
    char _spacer5[6];
    // 117
    char touchFlags;
    // 118
    char _spacer6[10];
    // 128
    grCollision* collision;
    // 132
    Vec2f unk;
    // 140
    Vec2f touchLineSpeed;
    // 144
    char _spacer7[68];
    // 212
    grCollisionLineWork collLineWorkArray[19];
    // 516
    grCollShape collShape;
    // 520
    char _spacer8[116];
    // TOTAL SIZE == 636
};