#pragma once

#include <StaticAssert.h>
#include <gm/gm_global_corps.h>
#include <gm/gm_global_mode_melee.h>
#include <gm/gm_global_record.h>
#include <gm/gm_result_info.h>
#include <gm/gm_sel_char_data.h>
#include <gm/gm_set_rule.h>
#include <gm/gm_tournament_data.h>

class GameGlobal {
public:
    /* data */
    char _0[0x8];                       // 0x00
    gmGlobalModeMelee* m_modeMelee;     // 0x08
    char _1[0x04];                      // 0x0C
    gmSelCharData* m_selCharData;       // 0x10
    char _2[0x04];                      // 0x14
    gmResultInfo* m_resultInfo;         // 0x18
    gmSetRule* m_setRule;               // 0x1C
    char _3[0x04];                      // 0x20
    gmGlobalRecord1* m_record1;         // 0x24
    gmGlobalRecord2* m_record2;         // 0x28
    gmTournamentData* m_tournamentData; // 0x2C
    adKeep* m_adKeep;                   // 0x30
    nteGlobalData* m_nteData;           // 0x34
    char _4[0x04];                      // 0x38
    gmGlobalCorps* m_corps;             // 0x3C
    char _5[0x10];                      // 0x40

    gmGlobalRecord1::MenuData* getGlobalRecordMenuDatap();

    static int getLanguage();

    STATIC_CHECK(sizeof(GameGlobal) == 0x50);
};

extern GameGlobal* g_GameGlobal;