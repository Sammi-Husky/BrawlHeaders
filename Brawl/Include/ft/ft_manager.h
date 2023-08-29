#pragma once

#include <StaticAssert.h>
#include <ft/fighter.h>
#include <gm/gm_result_info.h>
#include <mt/mt_vector.h>
#include <so/damage/so_damage_attacker_info.h>
#include <so/so_dispose_instance_manager.h>
#include <so/event/so_event_observer.h>
#include <so/so_log_event_presenter.h>
#include <so/so_null.h>
#include <types.h>

class ftOutsideEventObserver : public soEventObserver<ftOutsideEventObserver> {
public:
    ftOutsideEventObserver(short unitID) : soEventObserver<ftOutsideEventObserver>(unitID) {};

    virtual void addObserver(int param1, int param2);
    // TODO: Verify params
    virtual void notifyEventOnDamage(int entryId, u32 hp, soDamage* damage);
    virtual void notifyEventSetDamage(int entryId, float, int, bool, bool);
    virtual void notifyEventRecover(int entryId, int);
    virtual void notifyEventOutsideDeadArea(int entryId, int, bool*);
    virtual void notifyEventAppeal(int entryId, int);
    virtual void notifyEventDead(int entryId, int deadCount, int, int);
    virtual void notifyEventBeat(int entryId1, int entryId2);
    virtual void notifyEventSuicide(int entryId);
    virtual void notifyEventChangeStart(int, int playerNo);
    virtual void notifyEventChangeEnd(int entryId, u32 index, int, int);
    virtual void notifyEventChangeAppear();
    virtual void notifyEventAddDragoonParts(int entryId, int);
    virtual void notifyEventCompDragoonParts(int entryId);
    virtual void notifyEventRemoveDragoonParts(int entryId, int);
    virtual void notifyEventResetDragoonParts(int entryId);
    virtual void notifyEventReEntryRequestFighter();
    virtual void notifyEventSetCursor(int entryId, u32 index);
    virtual void notifyEventSetNameCursor(int entryId, u32 index);
    virtual void notifyEventSetLoupe(int entryId, u32 index);
    virtual void notifyEventStartFinal();
    virtual void notifyEventEndFinal();
    virtual void notifyEventRemoveEntry(int entryId);
    virtual void notifyEventFinalSlow(float, int, u32);
    virtual void notifyEventFinalSlowCancel();
    virtual void notifyEventFinalStop();
    virtual void notifyEventFinalStopCancel();
    virtual void notifyEventEntryEnd(int entryId);
    virtual void notifyEventResultEnd(int entryId);
    virtual void notifyEventGetItem(int, int, int, int, int);
    virtual void notifyEventSucceedHit(int entryId, u32 consecutiveHits, float totalDamage);
    virtual void notifyEventResultWin(int entryId, int);
    virtual void notifyEventYoshiEggStart(int entryId);
    virtual void notifyEventYoshiEggEnd(int entryId);
    virtual void notifyEventOnInput(int entryId);
    virtual void notifyEventPikminMakeBloomAll();
    virtual void notifyEventKirbyCopySetup(int entryId, int);
    virtual void notifyEventKirbyCopyCancel(int entryId, int);
    virtual void notifyEventKnockout(int entryId);
    virtual void notifyEventHeartSwapStart(int entryId1, int entryId2);
    virtual void notifyEventHeartSwapEnd();

    char _spacer1[2];
};
static_assert(sizeof(ftOutsideEventObserver) == 12, "Class is wrong size!");

class ftManagerAbstract : public soNull, public gfTask, public ftOutsideEventObserver, public soDisposeInstanceEventObserver, public soLogEventObserver {
    // Note: Done so that vtable placement is proper
};

class ftManager : public ftManagerAbstract {

public:
    char _104[2];
    GameRule m_gameRule : 8;
    char _107[2];
    bool m_isStamina;
    char _110[70];
    soEventManageModuleImpl m_eventManageModule;
    char m_200[4];
    short m_manageID;
    char _206[146];

    virtual ~ftManager();

    virtual void processBegin();
    virtual void processUpdate();
    virtual void processHit();
    virtual void processEnd();
    virtual void processDebug();

    virtual void notifyEventKirbyCopySetup(int entryId, int);
    virtual void notifyEventKirbyCopyCancel(int entryId, int);

    virtual void notifyDisposeInstance(bool, int, int taskId);
    virtual void notifyDrawDone();

    virtual void notifyEventEntryEnd(int entryId);
    virtual void notifyEventResultEnd(int entryId);

    virtual void notifyLogEventCollisionHit(float, int taskId1, int taskId2, int);
    virtual void notifyLogEventDead(int entryId1, int entryId2, int, int);

    bool isValidEntryId(int entryId);
    int getEntryCount();
    int getEntryId(int playerNo);
    int getEntryIdFromIndex(int index);
    int getEntryIdFromTaskId(int taskId, int* unk);
    int getPlayerNo(int entryId);
    bool isFighterActivate(int entryId, int);
    Fighter* getFighter(int entryId, int unk);
    Fighter* getSubFighter(int entryId);
    ftOwner* getOwner(int entryId);
    int getTeam(int entryId, bool unk2, bool unk3);
    Fighter* searchNearFighter(float unk1, float radius, Vec3f* pos, int team, bool unk4);
    void setHeal(int entryId, float heal);
    void setCurry(int entryId);
    void setSuperStar(int entryId);
    void setSlow(int inflictingTeam, bool setStatus, int slowStrength, int slowDuration);
    void setTimerSlow(int inflictingEntryId, bool setStatus, int slowStrength, int slowDuration);
    void setScaling(int entryId, int unk1, int unk2);
    void setInfiniteScaling(int entryId, int unk1, int unk2);
    void setThunder(int inflictingEntryId, int unk2);
    void setWarpFighter(int entryId, Vec3f* pos, float lr, bool showEffect);

    void pickupCoin(int entryId, int amount);
    void setDead(int entryId, int unk1, int unk2);
    void setBeat(int losingEntryId, int winningEntryId);
    void setSuicide(int entryId);
    bool isProcessHeartSwap(int entryId);
    void toKnockOutHeartSwapOpposite(int entryId, soDamageAttackerInfo* attackerInfo);
};
static_assert(sizeof(ftManager) == 0x160, "Class is wrong size!");

extern ftManager* g_ftManager;