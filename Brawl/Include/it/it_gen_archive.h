#pragma once

#include <StaticAssert.h>
#include <gm/gm_lib.h>
#include <it/it_archive.h>
#include <types.h>

enum itGenKind {
    Item_Gen_Assist = 0,
    Item_Gen_AssistTrophy = 0,
    Item_Gen_Barrel = 3,
    Item_Gen_Crate = 7,
    Item_Gen_Box = 7,
    Item_Gen_Capsule = 9,
    Item_Gen_RollingCrate = 10,
    Item_Gen_CarrierBox = 10,
    Item_Gen_PartyBall = 34,
    Item_Gen_Kusudama = 34,
    Item_Gen_Pokemon = 42,
    Item_Gen_PokeBall = 42,
    Item_Gen_Sandbag = 49,
    Item_Gen_Peanut = 84,
    Item_Gen_Basic = 10000,

    // Custom
    Item_Gen_Rain = 10001,
    Item_Gen_Barrel_Enemy = -3,
    Item_Gen_Crate_Enemy = -7,
    Item_Gen_Box_Enemy = -7,
    Item_Gen_Capsule_Enemy = -9,
    Item_Gen_RollingCrate_Enemy = -10,
    Item_Gen_CarrierBox_Enemy = -10,
    Item_Gen_PartyBall_Enemy = -34,
    Item_Gen_Kusudama_Enemy = -34,
};

struct itGenSheetKind {
    Stages::srStageKind m_stageKind;
    int m_levelId;
};

class itGenArchive {
public:
    itArchive::Type m_itArchiveType;
    itGenSheetKind m_sheetKind;
    int m_archiveId;
    u8 m_16;
    u8 m_17;
    u8 m_18;
    char m_19[1];

    virtual ~itGenArchive();
};
