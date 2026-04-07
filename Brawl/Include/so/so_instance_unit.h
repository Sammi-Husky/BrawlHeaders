#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <type_traits>

template <class T>
class soInstanceUnit {
public:
    T m_element;
    int m_id;

    soInstanceUnit() : m_id(-1) { }
    soInstanceUnit(T& elm, s32 id) : m_element(elm), m_id(id) { }
};

template <typename T>
class soInstanceUnitFullProperty : public soInstanceUnit<T> {
public:
    typename std::remove_pointer<T>::type::AttributeFlag m_attribute;
    s16 m_10;

    soInstanceUnitFullProperty() : m_attribute(0), m_10(-1) { }
    soInstanceUnitFullProperty(T& elm, s32 id, typename std::remove_pointer<T>::type::AttributeFlag attr, s16 p4) :
        soInstanceUnit<T>(elm, id), m_attribute(attr), m_10(p4) { }
    ~soInstanceUnitFullProperty() { }

    typename std::remove_pointer<T>::type::AttributeFlag getAttribute() const {
        return m_attribute;
    }
};

// TODO: inferred class
template <typename T>
class soInstanceUnitFullPropertyWrapper {
public:
    typename std::remove_pointer<T>::type::AttributeFlag m_attr;
    soInstanceUnitFullProperty<T> m_prop;

    soInstanceUnitFullPropertyWrapper() { }
    soInstanceUnitFullPropertyWrapper(typename std::remove_pointer<T>::type::AttributeFlag attr, T& elm, s32 id, s16 p4) :
        m_attr(attr), m_prop(elm, id, m_attr, p4) { }
    ~soInstanceUnitFullPropertyWrapper() { }
};
