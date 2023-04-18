#pragma once

#include <so/so_null.h>
#include <types.h>

template <size_t N>
struct bit_width {
    u8 bits[1 + sizeof(bit_width<N / 2>)];
};

template <>
struct bit_width<1> {
    u8 bits[1];
};

template <class T>
class soArrayFixed : public soNullableInterface {
public:
    virtual bool isNull();
    virtual T* at(u32);
    virtual T* at(int);
    virtual u32 size();
    virtual bool isEmpty();
    virtual ~soArrayFixed();
};

template <class T>
class soArrayContractible : public soArrayFixed<T> {
public:
    virtual ~soArrayContractible();
    virtual void shift();
    virtual void pop();
    virtual void clear();
};

template <class T>
class soArray : public soArrayContractible<T> {
public:
    virtual ~soArray();

    virtual void unshift(T*);
    virtual void push(T*);
    virtual void insert(int, T*);
    virtual void erase(int);
    virtual u32 capacity();
    virtual bool isFull();
    virtual void set(int, T*, int);
};

template <class T, class s> // TODO: Not sure what second template argument is
class soArrayListUnit {
    T m_element;
    int m_4;
    int m_8;
};

template <class T, u32 C>
class soArrayList : public soArray<T> {
    u32 m_a : sizeof(bit_width<C>) + 1;
    u32 m_b : sizeof(bit_width<C>) + 1;
    u32 m_c : sizeof(bit_width<C>) + 1;
    u32 m_size : sizeof(bit_width<C>) + 1;

    soArrayListUnit<T, int> m_units[C];

public:
    virtual bool isNull();
    virtual T* at(u32);
    virtual T* at(int);
    virtual u32 size() { return m_size; };
    virtual ~soArrayList();
    virtual void shift();
    virtual void pop();
    virtual void clear();
    virtual void unshift(T*);
    virtual void push(T*);
    virtual void insert(int, T*);
    virtual void erase(int);
    virtual u32 capacity() { return C; };
    virtual bool isFull();
    virtual void set(int, T*, int);
};

class soArrayVectorCalcInterface {
public:
    virtual void substitution(u32, u32);
    virtual void onFull();
    virtual void offFull();
    virtual void setTopIndex(u32);
    virtual void setLastIndex(u32);
    virtual ~soArrayVectorCalcInterface();
};

template <class T>
class soArrayVectorAbstract : public soArray<T>, public soArrayVectorCalcInterface {
public:
    virtual bool isNull();
    virtual T* at(u32);
    virtual T* at(int);
    virtual ~soArrayVectorAbstract();
    virtual void shift();
    virtual void pop();
    virtual void clear();
    virtual void unshift(T*);
    virtual void push(T*);
    virtual void insert(int, T*);
    virtual void erase(int);
    virtual u32 capacity();
    virtual bool isFull();
    virtual void set(int, T*, int);

    virtual T* atFastAbstractSub(int);
    virtual void substitution(u32, u32);
    virtual T* getArrayValueConst(u32);
    virtual u32 getTopIndex();
    virtual u32 getLastIndex();
    virtual void setSize(u32);
};

template <class T, u32 C>
class soArrayVector : public soArrayVectorAbstract<T> {
    u32 m_a : sizeof(bit_width<C>) + 1;
    u32 m_b : sizeof(bit_width<C>) + 1;
    u32 m_size : sizeof(bit_width<C>) + 1;

    T m_elements[C];

    virtual u32 size() { return m_size; };
    virtual ~soArrayVector();
    virtual u32 capacity(){ return C };
    virtual bool isFull();

    virtual T* atFastAbstractSub(int);
    virtual T* getArrayValueConst(u32);
    virtual u32 getTopIndex();
    virtual u32 getLastIndex();
    virtual void setSize(u32);
    virtual void setTopIndex(u32);
    virtual void setLastIndex(u32);
    virtual void onFull();
    virtual void offFull();
};