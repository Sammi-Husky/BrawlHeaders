#pragma once

#include <StaticAssert.h>
#include <types.h>

struct VtxData {
    char _spacer[8];
};

struct JointData {
    char _spacer[108];
};

struct LineData {
    short m_pointX;
    short m_pointY;
    char _spacer[12];
};

class grCollData {
    short m_vtxLen;
    short m_lineLen;
    short m_jointLen;
    short m_unk1;
    VtxData* m_vtxDataArray;
    LineData* m_lineDataArray;
    JointData* m_jointDataArray;
};
static_assert(sizeof(grCollData) == 20, "Class is wrong size!");
