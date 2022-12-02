#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_null.h>
#include <so/so_event_observer.h>
#include <so/so_event_presenter.h>

class soModuleAccesser;

class soStatusUniqProcess {
public:
    virtual ~soStatusUniqProcess();
    virtual void initStatus(soModuleAccesser* moduleAccesser);
    virtual void exitStatus(soModuleAccesser* moduleAccesser, int);
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execMapCorrection(soModuleAccesser* moduleAccesser);
    virtual void execFixPosCounter(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual void execFixCamera(soModuleAccesser* moduleAccesser);
    virtual bool checkDamage(soModuleAccesser* moduleAccesser, void*);
    virtual void checkAttack(soModuleAccesser* moduleAccesser, void*, float);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
    virtual void leaveStop(soModuleAccesser* moduleAccesser, int, bool);
    virtual bool checkTransitionPrecede(soModuleAccesser* moduleAccesser, int*);
};

class soStatusModule : public soNullable {
public:
    virtual void activate(soModuleAccesser* moduleAccesser);
    virtual void deactivate(soModuleAccesser* moduleAccesser);
    virtual bool changeStatusRequest(int status, soModuleAccesser* moduleAccesser);
    virtual void processFixPosition(soModuleAccesser* moduleAccesser, bool);
    virtual void begin();
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execMapCorrection(soModuleAccesser* moduleAccesser);
    virtual void execFixPosCounter(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual void execFixCamera(soModuleAccesser* moduleAccesser);
    virtual bool checkDamage(soModuleAccesser* moduleAccesser, void*);
    virtual void checkAttack(soModuleAccesser* moduleAccesser, void*, float);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
    virtual void leaveStop(soModuleAccesser* moduleAccesser, int, bool);
    virtual int getStatusKind();
    virtual bool isCollisionAttackOccer();
    virtual bool isCollisionAttackTarget(u32* collisionAttackCategory);
    virtual void startWatchChange();
    virtual bool isChanged();
    virtual bool checkTransition(soModuleAccesser* moduleAccesser);
    virtual void enableTransitionTermGroup(int);
    virtual void unableTransitionTermGroup(int);
    virtual void isEnableTransitionTermGroup(int);
    virtual void enableTransitionTermAll(int);
    virtual void clearTransitionTermAll(int);
    virtual void* getLastStatusTransitionInfo();
    virtual void addRangeUniqProc(soStatusUniqProcess* uniqProcs, u32 numUniqProcs);
    virtual char* getStatusName();
    virtual char* getStatusName(int);
    virtual u32 getStatusGroundCorrect(int);
    virtual int getPrevStatusKind(u32);
    virtual void connectStatusDataList(void*);
    virtual void changeStatusForce(int status, soModuleAccesser* moduleAccesser);
    virtual void unableTransitionTerm(int,int);
    virtual void setUniqProc(u32 index, soStatusUniqProcess* uniqProc);
    virtual ~soStatusModule();
    virtual void changeStatus(int status, soModuleAccesser* moduleAccesser);

    STATIC_CHECK(sizeof(soStatusModule) == 8)
};

class soStatusModuleImpl : public soStatusModule, public soEventPresenter<soStatusEventObserver>, public soAnimCmdEventObserver, public soCollisionAttackEventObserver {

    char _spacer[100];

public:
    virtual void activate(soModuleAccesser* moduleAccesser);
    virtual void deactivate(soModuleAccesser* moduleAccesser);
    virtual bool changeStatusRequest(int status, soModuleAccesser* moduleAccesser);
    virtual void processFixPosition(soModuleAccesser* moduleAccesser, bool);
    virtual void begin();
    virtual void execStatus(soModuleAccesser* moduleAccesser);
    virtual void execStop(soModuleAccesser* moduleAccesser);
    virtual void execMapCorrection(soModuleAccesser* moduleAccesser);
    virtual void execFixPosCounter(soModuleAccesser* moduleAccesser);
    virtual void execFixPos(soModuleAccesser* moduleAccesser);
    virtual void execFixCamera(soModuleAccesser* moduleAccesser);
    virtual bool checkDamage(soModuleAccesser* moduleAccesser, void*);
    virtual void checkAttack(soModuleAccesser* moduleAccesser, void*, float);
    virtual bool onChangeLr(soModuleAccesser* moduleAccesser, float, float);
    virtual void leaveStop(soModuleAccesser* moduleAccesser, int, bool);
    virtual int getStatusKind();
    virtual bool isCollisionAttackOccer();
    virtual bool isCollisionAttackTarget(u32* collisionAttackCategory);
    virtual void startWatchChange();
    virtual bool isChanged();
    virtual bool checkTransition(soModuleAccesser* moduleAccesser);
    virtual void enableTransitionTermGroup(int);
    virtual void unableTransitionTermGroup(int);
    virtual void isEnableTransitionTermGroup(int);
    virtual void enableTransitionTermAll(int);
    virtual void clearTransitionTermAll(int);
    virtual void* getLastStatusTransitionInfo();
    virtual void addRangeUniqProc(soStatusUniqProcess* uniqProcs, u32 numUniqProcs);
    virtual char* getStatusName();
    virtual char* getStatusName(int);
    virtual u32 getStatusGroundCorrect(int);
    virtual int getPrevStatusKind(u32);
    virtual void connectStatusDataList(void*);
    virtual void changeStatusForce(int status, soModuleAccesser* moduleAccesser);
    virtual void unableTransitionTerm(int,int);
    virtual void setUniqProc(u32 index, soStatusUniqProcess* uniqProc);
    virtual ~soStatusModuleImpl();
    virtual void changeStatus(int status, soModuleAccesser* moduleAccesser);

    virtual bool notifyEventCollisionAttackCheck(u32 flags);
    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventCollisionAttack(void* unk1, void* unk2, soModuleAccesser* moduleAccesser);

    STATIC_CHECK(sizeof(soStatusModuleImpl) == 144)
};

