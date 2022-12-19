#pragma once

#include <types.h>
#include <StaticAssert.h>

class Vec2f {
public:
    float m_x;
    float m_y;

    STATIC_CHECK(sizeof(Vec2f) == 8)
};

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
    Vec3f operator*(const float c);
    inline Vec3f operator/(const float c) {
        return *this*(1/c);
    }

    inline void operator+=(const Vec3f& v) {
        *this = *this + v;
    }
    inline void operator-=(const Vec3f& v) {
        *this = *this - v;
    }
    inline void operator*=(const float c) {
        *this = *this * c;
    }

    STATIC_CHECK(sizeof(Vec3f) == 12)
};

Vec3f operator*(const float c, const Vec3f& v);

