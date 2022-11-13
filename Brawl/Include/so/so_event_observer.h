#pragma once

#include <types.h>

template <class T>
class soEventObserver {
    virtual void addObserver(int param1, int param2);
    char _spacer[0x6];

    STATIC_CHECK(sizeof(soEventObserver) == 8)
};

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(int* unk1, int unk2, int unk3);

    char _spacer1[2];

    STATIC_CHECK(sizeof(soAnimCmdEventObserver) == 12)
};

class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
    //virtual void addObserver(int unk1, char unk2);
    virtual void notifyEventLink(int* unk1, int unk2, int unk3, int unk4);

    char _spacer1[2];

    STATIC_CHECK(sizeof(soLinkEventObserver) == 12)
};

class soCollisionAttackEventObserver : public soEventObserver<soCollisionAttackEventObserver> {
    //virtual void addObserver(int unk1, char unk2);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, void* unk3);
    virtual void notifyEventCollisionAttackCheck(int unk);

    char _spacer1[1];
    char _pad[1];

    STATIC_CHECK(sizeof(soCollisionAttackEventObserver) == 12)
};
