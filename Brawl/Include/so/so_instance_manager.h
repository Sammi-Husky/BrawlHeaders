#pragma once

#include <types.h>
#include <so/so_array.h>
#include <so/so_instance_unit.h>

template <class T>
class soInstanceManagerFixed : public soNullable {
public:
    virtual T* at(int index);
    virtual T* atIndex(int index);
    virtual int getId(int index);
    virtual u32 size();
    virtual bool isEmpty();
    virtual bool isContain(int);
};

template <class T>
class soInstanceManager : public soInstanceManagerFixed<T> {
    virtual int add(T*, int);
    virtual void erase(int);
    virtual void clear();
    virtual void set(T*, int index);
};

template <class T>
class soInstanceManagerSimple : public soInstanceManager<T> {
public:
    virtual int add(T*, int);
    virtual void erase(int);
    virtual void clear();
    virtual void set(T*, int index);
};

template <class T, class U, class V>
class soInstanceManagerFixedSimple : public soInstanceManagerFixed<T> {
public:
    virtual T* at(int index);
    virtual T* atIndex(int index);
    virtual int getId(int index);
    virtual u32 size();
    virtual bool isEmpty();
    virtual bool isContain(int);

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
    virtual void getPriorityArray(soArray<T>*);
};

template <class T>
class soInstanceManagerAttributePolicy {
public:
    virtual void getAttributeArray(soInstanceAttribute*, soArray<T>*);
    virtual soInstanceAttribute getAttribute(int);
};

template <class T>
class soInstanceManagerFullProperty : public soInstanceManager<T> {
public:
    virtual int add(T*, int);

    virtual int add(T*, int, soInstanceAttribute*, short);
    virtual u32 capacity();
    virtual T* atIndexFast(int index);
    virtual soInstanceUnit<T>* atUnitIndexFast(int index);
    virtual int getIndex(int index);
};

template <class T, u32 C>
class soInstanceManagerFullPropertyUniqImpl : public soInstanceManagerFullProperty<T> {
    soArrayList<soInstanceUnitFullProperty<T*>, 11> m_arrayList;
public:
    virtual T* at(int index);
    virtual T* atIndex(int index);
    virtual int getId(int index);
    virtual u32 size();
    virtual bool isContain(int);
    virtual void erase(int);
    virtual void clear();
    virtual void set(T*, int index);

    virtual int add(T*, int, soInstanceAttribute*, short);
    virtual u32 capacity();
    virtual soInstanceUnit<T>* atUnitIndexFast(int index);
    virtual int getIndex(int index);

    virtual void getAttributeArray(soInstanceAttribute*, soArray<T>*);
    virtual soInstanceAttribute getAttribute(int);
    virtual void getPriorityArray(soArray<T>*);

};

template <class T, u32 C>
class soInstanceManagerFullPropertyVector: 
    public soInstanceManagerFullProperty<T>,
    public soInstanceManagerPriorityPolicy<T>,
    public soInstanceManagerAttributePolicy<T> {
        // Starts at 0x10, because there are 4 vtables.
        soArrayVector<soInstanceUnitFullProperty<T>, C> m_arrayVector;
};