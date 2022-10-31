#pragma once

#include <types.h>

class utListEntry {
    utListEntry* next;
    utListEntry* prev;
};

class utListHead {
    utListEntry* next;
    utListEntry* last;
    unsigned int length;
};