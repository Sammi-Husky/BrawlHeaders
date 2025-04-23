#pragma once

#include <StaticAssert.h>
#include <types.h>

template <class T>
class utQueueInterface {
    char _0x0[2];
    u16 m_size;
public:
    u16 size() { return m_size; };
};

template <class T, u32 C>
class utQueue : utQueueInterface<T>{
public:
    T m_elements[C];
};
