#pragma once

#include <gf/gf_task.h>
#include <yk/yakumono.h>
#include <ut/ut_list.h>

struct TriggerData {
    unsigned short triggerIndex;
    char unk1;
    char unk2;
};

class stTrigger : utList {
    Yakumono* yakumono;
    char _spacer[20];

    public:
        void setObserveYakumono(Yakumono* yakumono);
};

class stTriggerMng : gfTask {
    stTrigger* triggerHead;
    char _spacer[29];
    public:

        virtual void processBegin();
        virtual void processFix();
        virtual void processGameProc();
        virtual ~stTriggerMng();

        stTrigger* createTrigger(u32 utArchiveType, int index);
};

extern stTriggerMng* g_stTriggerMng;