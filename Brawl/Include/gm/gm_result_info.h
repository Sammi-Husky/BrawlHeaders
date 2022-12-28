#pragma once

#include <StaticAssert.h>
#include <types.h>

enum GameRule {
    GameRule_Time = 0x0,
    GameRule_Stock = 0x1,
    GameRule_Coin = 0x2
};

class gmResultInfo {
public:
    char _0[1];
    GameRule m_gameRule : 8;
    char _3[0xd];
    u8 m_numWinners;
    char _16[0x1378];

    STATIC_CHECK(sizeof(gmResultInfo) == 0x1388)
};

namespace static_checks {

} // namespace static_checks
