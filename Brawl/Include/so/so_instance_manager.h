#pragma once

#include <types.h>
#include <so/so_array.h>

template <class T>
class soInstanceUnit {
public:
    char _0[4];
    int m_id;
};

template <class T>
class soInstanceManagerFixed : public soNullable {
public:
    virtual T* at(u32 index);
    virtual T* atIndex(u32 index);
    virtual int getId(u32 index);
    virtual u32 size();
    virtual bool isEmpty();
    virtual bool isContain(u32);
};

template <class T>
class soInstanceManager : public soInstanceManagerFixed<T> {

};

template <class T>
class soInstanceManagerSimple : public soInstanceManager<T> {
public:
    virtual int add(T*, int);
    virtual void remove(u32);
    virtual void clear();
    virtual void set(T*, u32 index);
};

template <class T, class U, class V>
class soInstanceManagerFixedSimple : public soInstanceManagerFixed<T> {
public:
    virtual T* at(u32 index);
    virtual T* atIndex(u32 index);
    virtual int getId(u32 index);
    virtual u32 size();
    virtual bool isEmpty();
    virtual bool isContain(u32);

    V* m_array;
};


template <class T, class U>
class soInstanceManagerSimpleEntity : public soInstanceManagerSimple<T>{
public:
    soInstanceManagerFixedSimple<T, soInstanceUnit<T>, soArray<soInstanceUnit<T> > > m_fixedSimple;

    U m_arrayVector;
};

