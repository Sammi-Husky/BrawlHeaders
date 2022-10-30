#pragma once

#include <ft/fighter.h>

class ftManager {
    char _spacer[352];

    public:
        int getEntryCount();
        int getEntryIdFromIndex(int index);
        Fighter* getFighter(int entryId, int unk);
};

extern ftManager* g_ftManager;