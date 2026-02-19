#pragma once

#include <StaticAssert.h>
#include <types.h>

struct soInstanceAttribute {
    s16 unk0;

    soInstanceAttribute() : unk0(0) { }
};

template <typename T>
struct soInstanceAttributeExt : public soInstanceAttribute {
    T* unk4;
    u8 unk8[0x4];
    soInstanceAttributeExt() { }
};

template <typename T>
struct soInstanceAttributeExt2 {
    T* unk0;
    soInstanceAttribute unk4;
    soInstanceAttributeExt2(T* p1) : unk0(p1) { }
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
    s16 m_attribute;
    s16 m_10;

    soInstanceUnitFullProperty();
    soInstanceUnitFullProperty(T& p1, s32 p2, const s16& p3, s16 p4);
    ~soInstanceUnitFullProperty() { }

    soInstanceAttributeExt<T> getAttribute() const;
};
