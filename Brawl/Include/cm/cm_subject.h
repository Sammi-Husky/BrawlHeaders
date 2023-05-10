#pragma once

#include <types.h>
#include <mt/mt_vector.h>
#include <st/st_positions.h>

class cmSubject {
public:
    char _0[16];
    Vec3f m_pos;
    char _28[16];
    stRange m_range;
    stRange m_60;
    stRange m_76;
    char _92[40];
};
static_assert(sizeof(cmSubject) == 132, "Class is wrong size!");

class cmSubjectList {
    // TODO
public:
    static cmSubject* getSubjectByPlayerNo(u32 playerNo);
};
