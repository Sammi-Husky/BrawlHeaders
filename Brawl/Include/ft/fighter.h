#pragma once

#include <types.h>

class Fighter {
public:
    char _spacer[268];
    int entryId;
    char _spacer2[60];

    bool setMetal(bool setStatus, float health, int unk3); // TODO: should be virtual
    void setCurry(bool setStatus, int unk2);
    void setHammer(bool setStatus, int unk2);
    void setSuperStar(bool setStatus, int unk2, bool unk3);
    void setFlower(bool setStatus, float rate, float size, int unk4, bool unk5);
    void setSlow(bool setStatus, int slowStrength, int duration, bool unk4);
    void setHeartSwap(int givingPlayerEntryID, int givingPlayerEntryId, bool setStatus);
    void startScaling(bool setStatus, bool isPoison);


};