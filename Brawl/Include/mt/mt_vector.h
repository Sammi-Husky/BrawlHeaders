#pragma once

#include <StaticAssert.h>
#include <math.h>
#include <mt/mt_common.h>
#include <types.h>

class Vec2f {
public:
    float m_x;
    float m_y;

    inline Vec2f operator+(const Vec2f& v) {
        return (Vec2f){this->m_x + v.m_x, this->m_y + v.m_y};
    }

    inline Vec2f operator-(const Vec2f& v) {
        return (Vec2f){this->m_x - v.m_x, this->m_y - v.m_y};
    }

    inline Vec2f operator*(const float c) {
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

    inline float lengthSq() {
        return this->m_x*this->m_x + this->m_y*this->m_y;
    }

    inline float length() {
        float lengthSquared = this->lengthSq();
        if (1.17549e-38 < fabsf(lengthSquared)) {
            return rsqrtf(lengthSquared)*lengthSquared;
        }
        else {
            return 0.0;
        }

    }

    inline float distance(Vec2f* v) {
        Vec2f disp = *this - *v;
        return disp.length();
    }

};
static_assert(sizeof(Vec2f) == 8, "Class is wrong size!");

class Vec3f {
public:
    union {
        struct {
            union {
                struct {
                    float m_x;
                    float m_y;
                };
                Vec2f m_xy;
            };
            float m_z;
        };
        struct {
            float m_roll;
            float m_pitch;
            float m_yaw;
        };
    };


    Vec3f operator+(const Vec3f& v);
    Vec3f operator-(const Vec3f& v);
    Vec3f operator*(const float c);

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

    float lengthSq();
    float length();
    inline float distance(Vec3f* v) {
        Vec3f disp = *this - *v;
        return disp.length();
    }
};
static_assert(sizeof(Vec3f) == 12, "Class is wrong size!");

class Rect2D {
public:
    float m_left;
    float m_right;
    float m_up;
    float m_down;
};

Vec3f operator*(const float c, const Vec3f& v);
