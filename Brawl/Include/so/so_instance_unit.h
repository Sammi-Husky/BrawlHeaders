#pragma once

#include <StaticAssert.h>
#include <types.h>

struct soInstanceAttribute {
    s16 unk0;

    soInstanceAttribute() : unk0(0) { }
    soInstanceAttribute(s16 p1) : unk0(p1) { }
};

template <typename T>
struct soInstanceAttributeExt : public soInstanceAttribute {
    T* unk4;
    u8 unk8[0x4];
    soInstanceAttributeExt() { }
    soInstanceAttributeExt(s16 p1) : soInstanceAttribute(p1) { }
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

    soInstanceUnit() : m_id(-1) { }
    soInstanceUnit(T& elm, s32 id) : m_element(elm), m_id(id) { }
};

// FIXME: Need to prevent the inlining of these constructors and getAttribute
// in the methods of soInstanceManagerFullPropertyVector
template <typename T>
class soInstanceUnitFullProperty : public soInstanceUnit<T> {
public:
    s16 m_attribute;
    s16 m_10;

    soInstanceUnitFullProperty() : m_attribute(0), m_10(-1) { }
    soInstanceUnitFullProperty(T& elm, s32 id, const s16& attr, s16 p4) :
        soInstanceUnit<T>(elm, id), m_attribute(attr), m_10(p4) { }
    ~soInstanceUnitFullProperty() { }

    soInstanceAttributeExt<T> getAttribute() const {
        return soInstanceAttributeExt<T>(m_attribute);
    }
};

// TODO: inferred class
template <typename T>
class soInstanceUnitFullPropertyWrapper {
public:
    s16 m_attr;
    soInstanceUnitFullProperty<T> m_prop;

    soInstanceUnitFullPropertyWrapper() { }
    soInstanceUnitFullPropertyWrapper(const soInstanceAttribute& attr, T& elm, s32 id, s16 p4) :
        m_attr(attr.unk0), m_prop(elm, id, m_attr, p4) { }
    ~soInstanceUnitFullPropertyWrapper() { }
};
