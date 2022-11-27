#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <ut/ut_list.h>

template <typename T, int C>
class utStageObjectPool {
    T* m_stageObjects;
    u32 m_numStageObjects;
    utList m_list1;
    utList m_list2;
    bool m_32;
    char _pad[3];

public:

    virtual ~utStageObjectPool();
    virtual void clean();
    virtual void reset();
    virtual utListNode* getObject(bool);
    virtual void releaseObject(utListNode*);

    STATIC_CHECK(sizeof(utStageObjectPool) == 40)
};
