#pragma once

#include <types.h>

template <class T>
class soEventObserver {
    virtual void addObserver(int param1, int param2);
    char _spacer[0x6];
};
