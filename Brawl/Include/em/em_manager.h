#pragma once

#include <types.h>
#include <StaticAssert.h>

class emManager {

    class Entry {
        char _0[0x18];

        STATIC_CHECK(sizeof(Entry) == 0x18)
    };

    u32 m_numEntries1;
    Entry* m_entries1;
    char _8[4];
    u32 m_numEntries2;
    Entry* m_entries2;
    char _20[4];
    u8 primidFaceType;
    char _25[7];

    static void create(u32 numEntries1, u32 numEntries2, u8 primidFaceType);
    static emManager* getInstance();

    STATIC_CHECK(sizeof(emManager) == 32)
};

