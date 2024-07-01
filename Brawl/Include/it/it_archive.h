#pragma once

#include <StaticAssert.h>
#include <it/item.h>
#include <types.h>

class itArchive {
public:
    enum Type {
        Temp = 0x0,
        Assist = 0x1,
        Common = 0x2,
        D = 0x3,
        Stage = 0x4,
        F = 0x5
    };

    Type m_type;
    u8 m_4;
    char _5[3];
    union {
        struct {
            ItemKind m_itemKind;
        };
        struct {
            itKind m_itKind;
            u32 m_itVariation;
        };
    };
    int m_commonParamArchiveId;
    int m_brresArchiveId;
    int m_paramArchiveId;
    int m_soundGroup;
    int m_32;
    int m_numItemsActive;
    int m_40;

    virtual ~itArchive();
};
static_assert(sizeof(itArchive) == 48, "Class is wrong size!");
