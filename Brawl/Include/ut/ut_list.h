#pragma once

#include <types.h>

class utListNode {
    utListNode* next;
    utListNode* prev;
};

class utListHead {
    utListNode* next;
    utListNode* last;
    unsigned int length;
};