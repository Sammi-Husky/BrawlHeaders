#pragma once

#include <StaticAssert.h>
#include <mu/mu_menu_controller.h>
#include <mu/mu_object.h>
#include <mu/mu_selchar.h>
#include <mu/mu_select_character_list.h>
#include <mu/mu_select_character_name_entry.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <types.h>

class muSelCharPlayerArea {
protected:
public:
    u32 _0;
    muMenuController menuController;
    char _0xAC[0x1C];
    MuObject* muObject;
    char _0xCC[0x84];
    void* objProcTask;
    muSelCharCBCalcWorld callbacks[7];
    void* selCharHand;
    void* selCharCoin;
    int areaIdx;
    int playerKind;
    int selectedChar;
    int curCostume;
    int teamColor;
    char curTeamSet;
    char _0x1C5[3];
    int nameId;
    char _0x1CC[0x10];
    int controllerId;
    int controllerType;
    char _0x1E4[0x4];
    int selectedZelda;
    int selectedSamus;
    int selectedPoke;
    char _0x1F4[0x8];
    muSelctChrList chrList;
    char _0x35C[0x14];
    muSelctChrNameEntry nameEntry;
    char _0x404[0x34];
    nw4r::g3d::ResFileData* charPicData;
    nw4r::g3d::ResFile charPicRes;
    char _0x440[0x8];

    void setCharPic(int charKind, int playerKind, int curCostume, bool isTeamBattle, int teamColor, int unk);
    nw4r::g3d::ResFile* getCharPicTexResFile(int charKind);
    bool isTeamBattle();
};
static_assert(sizeof(muSelCharPlayerArea) == 0x448, "Wrong size for class!");
