#pragma once

#include <StaticAssert.h>
#include <types.h>

class Vec2f {
public:
    float m_x;
    float m_y;

    Vec2f operator+(const Vec2f& v) {
        return (Vec2f){this->m_x + v.m_x, this->m_y + v.m_y};
    }

    Vec2f operator-(const Vec2f& v) {
        return (Vec2f){this->m_x - v.m_x, this->m_y - v.m_y};
    }

    Vec2f operator*(const float c) {
        Vec2f res;
        res.m_x = m_x * c;
        res.m_y = m_y * c;
        return res;
    }

    inline Vec2f operator/(const float c)
    {
        return *this * (1 / c);
    }

    inline void operator+=(const Vec2f& v)
    {
        *this = *this + v;
    }
    inline void operator-=(const Vec2f& v)
    {
        *this = *this - v;
    }
    inline void operator*=(const float c)
    {
        *this = *this * c;
    }

};
static_assert(sizeof(Vec2f) == 8, "Class is wrong size!");

class Vec3f {
public:
    union {
        struct {
            float m_x;
            float m_y;
        };
        Vec2f m_xy;
    };
    float m_z;

    Vec3f operator+(const Vec3f& v);
    Vec3f operator-(const Vec3f& v);
    Vec3f operator*(const float c) {
        Vec3f res;
        res.m_x = m_x * c;
        res.m_y = m_y * c;
        res.m_z = m_z * c;
        return res;
    }
    inline Vec3f operator/(const float c)
    {
        return *this * (1 / c);
    }

    inline void operator+=(const Vec3f& v)
    {
        *this = *this + v;
    }
    inline void operator-=(const Vec3f& v)
    {
        *this = *this - v;
    }
    inline void operator*=(const float c)
    {
        *this = *this * c;
    }
};
static_assert(sizeof(Vec3f) == 12, "Class is wrong size!");

Vec3f operator*(const float c, const Vec3f& v);
