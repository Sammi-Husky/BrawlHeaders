#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <gm/gm_lib.h>

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

struct gmPlayerResultInfo {
    gmCharacterKind m_characterKind : 8;
    u8 m_state;
    s8 m_colorFileIdx;
    char _3[5];
    s16 m_hitPointMax;
    u8 m_startStockCount;
    char _11[1];
    s16 m_startDamage;
    u8 m_rank;
    char _15[1];
    u32 m_koCount;
    u32 m_deadCount;
    u16 m_suicideCount;
    u16 m_playerBeatCounts[7];
    u32 m_coins;
    u32 m_pickupCoins;
    u32 m_lostCoins;
    char _26[548];
    int m_rankCount;
    char _604[80];
};
static_assert(sizeof(gmPlayerResultInfo) == 684, "Class is wrong size!");

class gmResultInfo {
public:
    char _0[1];
    GameRule m_gameRule : 8;
    char _3[0xd];
    u8 m_numWinners;
    char _16[15];
    s8 m_winningPlayer;
    char _32[4];
    gmPlayerResultInfo m_playersResultInfo[7];
    char _4824[172];
    int m_time;
};
static_assert(sizeof(gmResultInfo) == 0x1388, "Class is wrong size!");

namespace static_checks {

} // namespace static_checks
