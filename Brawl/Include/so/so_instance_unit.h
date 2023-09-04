#pragma once

#include <types.h>

// TODO: Verify that this returns in r3
struct soInstanceAttribute {
    short _0 : 16;
};

template <class T>
class soInstanceUnit {
public:
    T m_element;
    int m_id;
};

template <class T>
class soInstanceUnitFullProperty : public soInstanceUnit<T> {
public:
    short m_attribute;
    short m_10;
};