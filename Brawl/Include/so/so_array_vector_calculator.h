#pragma once

#include <types.h>

class soArrayVectorCalcInterface;

namespace soArrayVectorCalculator {
    void shift(soArrayVectorCalcInterface* interface, bool isEmpty, u32 capacity, u32 topIndex);
    void pop(soArrayVectorCalcInterface* interface, bool isEmpty, u32 capacity, u32 lastIndex);
    void clear(soArrayVectorCalcInterface* interface);
    u32 unshift(soArrayVectorCalcInterface* interface, bool isFull, u32 capacity, u32 topIndex, u32 lastIndex);
    u32 push(soArrayVectorCalcInterface* interface, bool isFull, u32 capacity, u32 topIndex, u32 lastIndex);
    u32 insert(soArrayVectorCalcInterface* interface, u32 index, bool isFull, u32 size, u32 capacity, u32 topIndex, u32 lastIndex);
    void erase(soArrayVectorCalcInterface* interface, u32 index, u32 size, u32 capacity, u32 topIndex, u32 lastIndex);
    u32 resize(soArrayVectorCalcInterface* interface, u32 size, bool isEmpty, bool isFull, u32 capacity, u32 topIndex, u32 lastIndex);
    void postInitialize(soArrayVectorCalcInterface* interface, u32 size, u32 capacity);
}

