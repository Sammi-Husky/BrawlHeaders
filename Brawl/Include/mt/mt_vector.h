#pragma once

#include <types.h>

class Vec2f {
public:
    float x;
    float y;
};

class Vec3f {
public:
    float x;
    float y;
    float z;

    Vec3f operator+(const Vec3f& v);
    Vec3f operator-(const Vec3f& v);
    Vec3f operator*(const float c);

    inline void operator+=(const Vec3f& v) {
        *this = *this + v;
    }
    inline void operator-=(const Vec3f& v) {
        *this = *this - v;
    }
    inline void operator*=(const float c) {
        *this = *this * c;
    }
};

Vec3f operator*(const float c, const Vec3f& v);

