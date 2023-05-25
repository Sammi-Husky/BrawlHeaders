#pragma once

#include <StaticAssert.h>
#include <so/event/so_event_observer.h>
#include <types.h>

class ftEntryEventObserver : public soEventObserver<ftEntryEventObserver> {
public:
    virtual void addObserver(int param1, int param2);
    virtual void notifyEventSetDamage(float);
    virtual void notifyEventBeat();
    virtual void notifyEventDeadPartner(int index);
    virtual void notifyEventPartnerResourcePrepared();
    virtual void notifyEventChangeAdvUnit();
    virtual void notifyEventWarp();
    virtual void notifyEventPokemonStart(int);
    virtual void notifyEventPokemonRequestChange(Vec3f*, float*);
    virtual void notifyEventPokemonTrainerUpdate();
    virtual void notifyEventPokemonCollect();
    virtual void notifyEventPokemonChangeCancel();
    virtual void notifyEventPokemonSpecial(int, int);
    virtual void notifyEventPokemonAppeal();
    virtual void notifyEventSetRumble(int, int);
    virtual void notifyEventStopRumble(int);
    virtual void notifyEventPokemonRebirthEnd();
    virtual void notifyEventPokemonAttack();
    virtual void notifyEventPokemonInflict();
    virtual void notifyEventPokemonDamage();
    virtual void notifyEventPokeTrainerReplace(u8);
    virtual void notifyEventPikminFinalAttack(float, int);
    virtual void notifyEventKirbyResourceLoaded(int index);
    virtual void notifyEventKirbyResourceUnLoaded(int index);
    virtual void notifyEventExitFighter(int, int);
    char _spacer1[2];
};
static_assert(sizeof(ftEntryEventObserver) == 12, "Class is wrong size!");