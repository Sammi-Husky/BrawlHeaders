#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <gf/gf_task.h>
#include <ac/ac_anim_cmd_impl.h>

class soModuleAccesser;

template <class T>
class soEventObserver {
    virtual void addObserver(int param1, int param2);
    short _4;
    short _6;
    short sendID;

    STATIC_CHECK(sizeof(soEventObserver) == 8)
};

class soAnimCmdEventObserver : public soEventObserver<soAnimCmdEventObserver> {
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soAnimCmdEventObserver) == 12)
};

class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
    //virtual void addObserver(int unk1, char unk2);
    virtual void notifyEventLink(void* unk1, soModuleAccesser* moduleAccesser, gfTask* task, int unk4);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soLinkEventObserver) == 12)
};

class soStatusEventObserver : public soEventObserver<soStatusEventObserver> {
    virtual void notifyEventChangeStatus(int unk1, int unk2, void* unk3, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soStatusEventObserver) == 12)
};

class soSituationEventObserver : public soEventObserver<soSituationEventObserver> {
    virtual void notifyEventChangeSituation(int unk1, int unk2, soModuleAccesser* moduleAccesser);
    char _spacer1[2];

    STATIC_CHECK(sizeof(soSituationEventObserver) == 12)
};

class soCollisionAttackEventObserver : public soEventObserver<soCollisionAttackEventObserver> {
    //virtual void addObserver(int unk1, char unk2);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    char _spacer1[1];
    char _pad[1];

    STATIC_CHECK(sizeof(soCollisionAttackEventObserver) == 12)
};


class soCollisionShieldEventObserver : public soEventObserver<soCollisionShieldEventObserver> {
    virtual void notifyEventCollisionShield(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser);
    virtual void notifyEventCollisionShieldSearch(void*, void*);
    virtual bool notifyEventCollisionShieldCheck();
    char _spacer1[2];
    STATIC_CHECK(sizeof(soCollisionShieldEventObserver) == 12)
};

class soCollisionReflectorEventObserver : public soEventObserver<soCollisionReflectorEventObserver> {
    virtual void notifyEventCollisionReflector(float, float, float, void*, void*, int, soModuleAccesser* moduleAccesser); // TODO: This is a guess based on above
    virtual void notifyEventCollisionReflectorSearch(int,int,int);
    virtual bool notifyEventCollisionReflectorCheck();
    char _spacer1[2];
    STATIC_CHECK(sizeof(soCollisionReflectorEventObserver) == 12)
};

class soCollisionSearchEventObserver : public soEventObserver<soCollisionSearchEventObserver> {
    virtual void notifyEventCollisionSearch(void*, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventCollisionSearchCheck();
    char _spacer1[2];
    STATIC_CHECK(sizeof(soCollisionSearchEventObserver) == 12)
};

struct soGimmickEventInfo {
    int state;
    int sendID;
};

class soGimmickEventObserver : public soEventObserver<soGimmickEventObserver> {
    virtual void notifyEventGimmick(soGimmickEventInfo *eventInfo,int *taskId);
    char _spacer1[2];
    STATIC_CHECK(sizeof(soGimmickEventObserver) == 12)
};
