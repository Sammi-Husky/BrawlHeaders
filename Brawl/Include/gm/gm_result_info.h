#pragma once

#include <StaticAssert.h>
#include <types.h>

enum GameRule {
    Game_Rule_Time = 0x0,
    Game_Rule_Stock = 0x1,
    Game_Rule_Coin = 0x2
};

enum GameDecision {
    Game_Decision_Timeup = 0x0,
    Game_Decision_Gameset = 0x1,
    Game_Decision_Complete = 0x2,
    Game_Decision_Failure = 0x3,
    Game_Decision_Success = 0x4
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
