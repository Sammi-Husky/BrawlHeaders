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
    Vec3f operator*(const int c);
};

