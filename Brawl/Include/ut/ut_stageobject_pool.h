#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <ut/ut_list.h>

template <typename T, int C>
class utStageObjectPool {
    char _0[36];

    virtual ~utStageObjectPool();
    virtual void clean();
    virtual void reset();
    virtual void* getObject(bool);
    virtual void releaseObject(utListNode*);

    STATIC_CHECK(sizeof(utStageObjectPool) == 24)
};
