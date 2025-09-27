#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/event/so_event_presenter.h>

class StageObject;
class soModuleAccesser;

struct soLinkEventInfo {
    int m_eventKind;
    int _0x4;
};

class soLinkEventObserver : public soEventObserver<soLinkEventObserver> {
public:
    soLinkEventObserver(short unitID) : soEventObserver<soLinkEventObserver>(unitID) {};

    virtual void addObserver(short param1, s8 param2);
    virtual void notifyEventLink(soLinkEventInfo *eventInfo, soModuleAccesser* moduleAccesser, StageObject*, int unk4);
};
static_assert(sizeof(soLinkEventObserver) == 12, "Class is wrong size!");
