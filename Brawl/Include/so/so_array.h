#pragma once

#include <so/so_null.h>
#include <types.h>
#include <so/so_array_vector_calculator.h>

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

    virtual bool isNull() { return false; };
    virtual T* at(u32) = 0;
    virtual T* at(int) = 0;
    virtual u32 size() = 0;
    virtual bool isEmpty() { return this->size() == 0; };
    virtual ~soArrayFixed() { };
};

template <class T>
class soArrayContractible : public soArrayFixed<T> {
public:
    virtual ~soArrayContractible() {};
    virtual void shift() = 0;
    virtual void pop() = 0;
    virtual void clear() = 0;
};

template <class T>
class soArray : public soArrayContractible<T> {
public:
    virtual ~soArray() {};

    virtual void unshift(T*) = 0;
    virtual void push(T*) = 0;
    virtual void insert(u32, T*) = 0;
    virtual void erase(u32) = 0;
    virtual u32 capacity() = 0;
    virtual bool isFull() = 0;
    virtual void set(u32 startingIndex, T* element, u32 numIndicesToSet) = 0;
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
    virtual ~soArrayList() {};
    virtual void shift();
    virtual void pop();
    virtual void clear();
    virtual void unshift(T*);
    virtual void push(T*);
    virtual void insert(u32, T*);
    virtual void erase(u32);
    virtual u32 capacity() { return C; };
    virtual bool isFull();
    virtual void set(u32 startingIndex, T* element, u32 numIndicesToSet);
};

class soArrayVectorCalcInterface {
public:
    virtual void substitution(u32, u32) = 0;
    virtual void onFull() = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(u32) = 0;
    virtual void setLastIndex(u32) = 0;
    virtual ~soArrayVectorCalcInterface() {};
};

template <class T>
class soArrayVectorAbstract : public soArray<T>, public soArrayVectorCalcInterface {
public:
    virtual bool isNull() {
        return false;
    };
    virtual T* at(u32 index) {
        return this->atFastAbstractSub(index);
    };
    virtual T* at(int index) {
        return this->atFastAbstractSub(index);
    };
    virtual ~soArrayVectorAbstract() { };
    virtual void shift() {
        soArrayVectorCalculator::shift(this, this->isEmpty(), this->capacity(), this->getTopIndex());
        this->setSize(this->size() - 1);
    };
    virtual void pop() {
        soArrayVectorCalculator::pop(this, this->isEmpty(), this->capacity(), this->getLastIndex());
        this->setSize(this->size() - 1);
    };
    virtual void clear() {
        soArrayVectorCalculator::clear(this);
        this->setSize(0);
    };
    virtual void unshift(T* newElement) {
        u32 topIndex = soArrayVectorCalculator::unshift(this, this->isFull(), this->capacity(), this->getTopIndex(), this->getLastIndex());
        T* element = this->getArrayValueConst(topIndex);
        *element = *newElement;
        this->setSize(this->size() + 1);
    };
    virtual void push(T* newElement) {
        u32 lastIndex = soArrayVectorCalculator::push(this, this->isFull(), this->capacity(), this->getTopIndex(), this->getLastIndex());
        T* element = this->getArrayValueConst(lastIndex);
        *element = *newElement;
        this->setSize(this->size() + 1);
    };
    virtual void insert(u32 index, T* newElement) {
        u32 lastIndex = soArrayVectorCalculator::insert(this, index, this->isFull(), this->size(), this->capacity(), this->getTopIndex(), this->getLastIndex());
        T* element = this->getArrayValueConst(lastIndex);
        *element = *newElement;
        this->setSize(this->size() + 1);
    };
    virtual void erase(u32 index) {
        soArrayVectorCalculator::erase(this, index, this->size(), this->capacity(), this->getTopIndex(), this->getLastIndex());
        this->setSize(this->size() - 1);
    };
    virtual u32 capacity() = 0;
    virtual void set(u32 startingIndex, T* elementToCopy, u32 numIndicesToSet) {
        if (this->size() <= startingIndex + numIndicesToSet) {
            numIndicesToSet = this->size() - startingIndex;
        }
        for (u32 i = 0; i < numIndicesToSet; i++) {
            T* element = this->at(i + startingIndex);
            *element = *elementToCopy;
        }
    };

    virtual T* atFastAbstractSub(u32 index) = 0;
    virtual void substitution(u32 subIndex, u32 targetIndex) {
        T* subElement = this->getArrayValueConst(subIndex);
        T* targetElement = this->getArrayValueConst(targetIndex);
        *targetElement = *subElement;
    };
    virtual T* getArrayValueConst(u32) = 0;
    virtual u32 getTopIndex() = 0;
    virtual u32 getLastIndex() = 0;
    virtual void setSize(u32) = 0;
};

template <class T, u32 C>
class soArrayVector : public soArrayVectorAbstract<T> {
    u32 m_topIndex : sizeof(bit_width<C>) + 1;
    u32 m_lastIndex : sizeof(bit_width<C>) + 1;
    u32 m_size : sizeof(bit_width<C>) + 1;
    bool m_isFull : 1;

    T m_elements[C];

public:
    virtual u32 size() { return m_size; };
    virtual ~soArrayVector() { };
    virtual u32 capacity() { return C; };
    virtual bool isFull() { return m_isFull; };

    virtual T* atFastAbstractSub(u32 index) {
        int iVar1 = this->m_topIndex + index;
        if (C - 1 < iVar1) {
            iVar1 -= C;
        }
        return &this->m_elements[iVar1];

    };
    virtual T* getArrayValueConst(u32 index) {
        return &this->m_elements[index];
    };
    virtual u32 getTopIndex() { return m_topIndex; };
    virtual u32 getLastIndex() { return m_lastIndex; };
    virtual void setSize(u32 size) { m_size = size; };
    virtual void setTopIndex(u32 topIndex) { m_topIndex = topIndex;};
    virtual void setLastIndex(u32 lastIndex) { m_lastIndex = lastIndex; };
    virtual void onFull() { m_isFull = true; };
    virtual void offFull() { m_isFull = false; };

    soArrayVector() {
        m_topIndex = 0;
        m_lastIndex = 0;
        m_size = 0;
        m_isFull = false;
    };
    soArrayVector(u32 size, T* element) {
        m_topIndex = 0;
        m_lastIndex = 0;
        m_size = 0;
        m_isFull = false;
        size = soArrayVectorCalculator::resize(this, size, this->isEmpty(), this->isFull(), this->capacity(), this->getTopIndex(), this->getLastIndex());
        for (u32 i = 0; i < size; i++) {
            this->push(element);
        }
    };
};