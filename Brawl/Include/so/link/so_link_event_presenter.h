#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/event/so_event_presenter.h>

class StageObject;
class soModuleAccesser;

struct soLinkEventArgs {
    int m_eventKind;
    bool _0x4;
protected:
    inline soLinkEventArgs(int eventKind) : m_eventKind(eventKind), _0x4(false) {}
};
static_assert(sizeof(soLinkEventArgs) == 8, "Class is wrong size!");


class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
public:
    soLinkEventObserver(short unitID) : soEventObserver<soLinkEventObserver>(unitID) {};

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventLink(soLinkEventArgs *eventInfo, soModuleAccesser* moduleAccesser, StageObject*, int unk4);
};
static_assert(sizeof(soLinkEventObserver) == 12, "Class is wrong size!");
