#pragma once

class utList {
    utList* nextEntry;
    utList* prevEntry;
    unsigned int utArchiveType;
    int index;
    int unk;
    void* utArchiveResource;
    void* utArchiveEventObserver;
};