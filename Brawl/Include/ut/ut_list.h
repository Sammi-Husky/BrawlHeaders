#pragma once

#include <types.h>

class utListNode {
    utListNode* m_next;
    utListNode* m_prev;
};

class utList {
    utListNode* m_first;
    utListNode* m_last;
    unsigned int m_length;
};