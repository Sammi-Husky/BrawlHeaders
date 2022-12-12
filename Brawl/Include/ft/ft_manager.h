#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <mt/mt_vector.h>
#include <ft/fighter.h>
#include <so/damage/so_damage_attacker_info.h>
#include <so/so_event_observer.h>

class ftOutsideEventObserver : public soEventObserver<ftOutsideEventObserver> {
public:
    // TODO: Verify params
    virtual void notifyEventOnDamage(int entryId, bool, void*);
    virtual void notifyEventSetDamage(int entryId, float, int, bool, bool);
    virtual void notifyEventRecover(int entryId, int);
    virtual void notifyEventOutsideDeadArea(int entryId, int, int*);
    virtual void notifyEventAppeal(int entryId, int);
    virtual void notifyEventDead(int entryId, int, int, u32);
    virtual void notifyEventBeat(int entryId1, int entryId2);
    virtual void notifyEventSuicide(int entryId);
    virtual void notifyEventChangeStart(int,int playerNo);
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
    virtual void notifyEventSucceedHit(int entryId, float, u32);
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
    STATIC_CHECK(sizeof(ftOutsideEventObserver) == 12)

};

class ftManager {
    char _spacer[352];

    public:
        bool isValidEntryId(int entryId);
        int getEntryCount();
        int getEntryIdFromIndex(int index);
        int getEntryIdFromTaskId(int taskId, int* unk);
        Fighter* getFighter(int entryId, int unk);
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

        void setDead(int entryId, int unk1, int unk2);
        void setBeat(int losingEntryId, int winningEntryId);
        void setSuicide(int entryId);
        bool isProcessHeartSwap(int entryId);
        void toKnockOutHeartSwapOpposite(int entryId, soDamageAttackerInfo* attackerInfo);

        STATIC_CHECK(sizeof(ftManager) == 352)
};

extern ftManager* g_ftManager;