#pragma once

#include <mt/mt_vector.h>
#include <types.h>

class clAABBox2D {
public:
    float m_unk1;
    float m_unk2;
    float m_unk3;
    float m_unk4;
};

class clCircle2D {
public:
    Vec2f m_centerPos;
    float m_radius;
};

class clRhombus2D {
public:
    Vec2f m_centerPos;
    Vec2f m_upPos;
    Vec2f m_downPos;
    Vec2f m_leftPos;
    Vec2f m_rightPos;
    clAABBox2D m_aabBox;
};

class clSegment2D {
public:
    Vec2f m_p0Pos;
    Vec2f m_p1Pos;
};
