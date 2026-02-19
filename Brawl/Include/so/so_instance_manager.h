#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>

template <class T>
class soInstanceManagerFixed : public soNullable {
public:
    virtual T& at(s32 index);
    virtual T& atIndex(s32 index);
    virtual s32 getId(s32 index);
    virtual u32 size() const;
    virtual bool isEmpty() const { return size() == 0; }
    virtual bool isContain(s32) const;
};

template <class T>
class soInstanceManager : public soInstanceManagerFixed<T> {
public:
    virtual s32 add(T&, s32);
    virtual void erase(s32);
    virtual void clear();
    virtual void set(const T&, s32 index);
};

template <class T>
class soInstanceManagerSimple : public soInstanceManager<T> {
public:
    virtual s32 add(T&, s32);
    virtual void erase(s32);
    virtual void clear();
    virtual void set(const T&, s32 index);
};

template <class T, class U, class V>
class soInstanceManagerFixedSimple : public soInstanceManagerFixed<T> {
public:
    virtual T& at(s32 index);
    virtual T& atIndex(s32 index);
    virtual s32 getId(s32 index);
    virtual u32 size() const;
    virtual bool isEmpty() const;
    virtual bool isContain(s32) const;

    V* m_array;
};


template <class T, class U>
class soInstanceManagerSimpleEntity : public soInstanceManagerSimple<T>{
public:
    soInstanceManagerFixedSimple<T, soInstanceUnit<T>, soArray<soInstanceUnit<T> > > m_fixedSimple;

    U m_arrayVector;
};

template <class T>
class soInstanceManagerPriorityPolicy {
public:
    virtual void getPriorityArray(soArray<T*>& arr) = 0;
};

template <class T>
class soInstanceManagerAttributePolicy {
public:
    virtual void getAttributeArray(const soInstanceAttribute& attr, soArray<T*>& arr) = 0;
    virtual soInstanceAttributeExt<T> getAttribute(s32) const = 0;
};

template <class T>
class soInstanceManagerFullProperty : public soInstanceManager<T>,
                                      public soInstanceManagerPriorityPolicy<T>,
                                      public soInstanceManagerAttributePolicy<T> {
public:
    virtual s32 add(T& p1, s32 p2) {
        return add(p1, p2, soInstanceAttribute(), -1);
    }

    virtual s32 add(T&, s32, const soInstanceAttribute&, s16);
    virtual u32 capacity();
    virtual T& atIndexFast(s32 index);
    virtual soInstanceUnit<T>& atUnitIndexFast(s32 index);
    virtual s32 getIndex(s32 index) const;
};

template <class T, u32 C>
class soInstanceManagerFullPropertyUniqImpl : public soInstanceManagerFullProperty<T> {
    soArrayList<soInstanceUnitFullProperty<T*>, 11> m_arrayList;
public:
    virtual T& at(s32 index);
    virtual T& atIndex(s32 index);
    virtual s32 getId(s32 index);
    virtual u32 size() const;
    virtual bool isContain(s32) const;
    virtual void erase(s32);
    virtual void clear();
    virtual void set(const T&, s32 index);

    virtual s32 add(T&, s32, const soInstanceAttribute&, s16);
    virtual u32 capacity();
    virtual soInstanceUnit<T>& atUnitIndexFast(s32 index);
    virtual s32 getIndex(s32 index) const;

    virtual void getAttributeArray(const soInstanceAttribute& attr, soArray<T*>& arr);
    virtual soInstanceAttributeExt<T> getAttribute(s32) const;
    virtual void getPriorityArray(soArray<T*>& arr);

};

template <class T, u32 C>
class soInstanceManagerFullPropertyVector : public soInstanceManagerFullProperty<T> {
    soArrayVector<soInstanceUnitFullProperty<T>, C> m_arrayVector; // 0x10
    bool m_unk1;

    s32 getFreeId() const;

    s32 unkFindIndex(s32 p4) const {
        s32 sz = size();
        for (s32 i = 0; i < sz; i++) {
            s32 r0 = m_arrayVector.at(i).m_10;
            if (r0 <= -1)
                return i;
            if (r0 > p4)
                return i;
        }
        return sz;
    }

    s32 indexOfId(s32 id) const {
        if (id <= -1)
            return -1;
        s32 sz = size();
        for (s32 i = 0; i < sz; i++)
            if (id == m_arrayVector.at(i).m_id)
                return i;
        return -1;
    }
public:
    soInstanceManagerFullPropertyVector() : m_unk1(false) { }
    soInstanceManagerFullPropertyVector(bool p1) : m_unk1(p1) { }

    virtual T& at(s32 id) {
        if (id <= -1)
            return m_arrayVector.at(0).m_element;
        s32 i = indexOfId(id);
        return (i < 0) ? m_arrayVector.at(0).m_element : m_arrayVector.at(i).m_element;
    }

    virtual T& atIndex(s32 idx) {
        return m_arrayVector.at(idx).m_element;
    }

    virtual s32 getId(s32 idx) {
        return m_arrayVector.at(idx).m_id;
    }

    virtual u32 size() const {
        return m_arrayVector.size();
    }

    virtual bool isContain(s32 id) const {
        return indexOfId(id) >= 0;
    }

    virtual void erase(s32 id) {
        s32 idx = indexOfId(id);
        if (idx >= 0)
            m_arrayVector.erase(idx);
    }

    virtual void clear() {
        m_arrayVector.clear();
    }

    virtual void set(const T& elm, s32 id) {
        T& ref = at(id);
        ref = elm;
    }

    virtual s32 add(T& p1, s32 p2, const soInstanceAttribute& p3, s16 p4) {
        if (m_arrayVector.isFull() == true)
            return -1;
        if ((!m_unk1 || p2 > -1) && isContain(p2) == true)
            return -1;
        if (!m_unk1 && p2 <= -1) {
            p2 = getFreeId();
            if (p2 <= -1)
                return -1;
        }
        s32 r31 = (p4 <= -1) ? size() : unkFindIndex(p4);
        if (r31 < 0)
            return -1;
        s16 r0 = p3.unk0;
        m_arrayVector.insert(r31, soInstanceUnitFullProperty<T>(p1, p2, r0, p4));
        return p2;
    }

    virtual u32 capacity() {
        return m_arrayVector.capacity();
    }

    virtual T& atIndexFast(s32 idx) {
        return m_arrayVector.atFast(idx).m_element;
    }

    virtual soInstanceUnit<T>& atUnitIndexFast(s32 idx) {
        return m_arrayVector.atFast(idx);
    }

    virtual s32 getIndex(s32 id) const { return indexOfId(id); }

    virtual void getAttributeArray(const soInstanceAttribute& attr, soArray<T*>& arr) {
        s32 sz = m_arrayVector.size();
        for (s32 i = 0; i < sz; i++) {
            soInstanceAttributeExt<T> stack8 = m_arrayVector.at(i).getAttribute();
            if (stack8.unk0 & attr.unk0) {
                stack8.unk4 = &m_arrayVector.at(i).m_element;
                arr.push(stack8.unk4);
            }
        }
    }

    virtual soInstanceAttributeExt<T> getAttribute(s32 id) const {
        s32 idx = indexOfId(id);
        if (idx < 0)
            return soInstanceAttributeExt<T>();
        return m_arrayVector.at(idx).getAttribute();
    }

    virtual void getPriorityArray(soArray<T*>& arr) {
        s32 sz = m_arrayVector.size();
        for (s32 i = 0; i < sz; i++)
            arr.push(&m_arrayVector.at(i).m_element);
    }
};

template<typename T, u32 C>
s32 soInstanceManagerFullPropertyVector<T, C>::getFreeId() const {
    if (m_arrayVector.isFull() == true)
        return 0x7FFF;
    if (this->isEmpty() == true)
        return 0;
    s32 end = m_arrayVector.size() - 1;
    if (m_arrayVector.at(end).m_id < 0x7FFF) {
        end = m_arrayVector.size() - 1;
        return m_arrayVector.at(end).m_id + 1;
    }
    for (s32 i = m_arrayVector.size() - 1; i >= 0; i--) {
        if (i == 0) {
            if (m_arrayVector.at(i).m_id == 0)
                return -1;
            return m_arrayVector.at(i).m_id - 1;
        }
        if (m_arrayVector.at(i).m_id - 1 > m_arrayVector.at(i - 1).m_id)
            return m_arrayVector.at(i).m_id - 1;
    }
    return -1;
}

template <class T>
class soInstanceManagerFullPropertyEccentric : public soInstanceManagerAttributePolicy<T>, public soInstanceManagerPriorityPolicy<T> {
public:
    // Starts at 0x8, because there are 2 vtables.
    soArray<soInstanceUnitFullProperty<T> >* m_array;

    virtual void getPriorityArray(soArray<T*>& arr);
    virtual void getAttributeArray(const soInstanceAttribute& attr, soArray<T*>& arr);
    virtual soInstanceAttributeExt<T> getAttribute(s32) const;
};
