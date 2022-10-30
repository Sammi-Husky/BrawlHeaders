#pragma once

#include <StaticAssert.h>
#include <types.h>

struct gmTournamentData {
    char _spacer[0x510]; // 0x00

    STATIC_CHECK(sizeof(gmTournamentData) == 0x510)
};