#pragma once

#include <StaticAssert.h>
#include <types.h>

class gmResultInfo {
public:
    char _0[1];
    u8 m_1;
    char _2[0x1386];

    STATIC_CHECK(sizeof(gmResultInfo) == 0x1388)
};

namespace static_checks {

} // namespace static_checks
