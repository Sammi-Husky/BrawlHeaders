#pragma once

#include <types.h>

class utListNode {
public:
    utListNode* m_next;
    utListNode* m_prev;
};

class utList {
public:
    utListNode* m_first;
    utListNode* m_last;
    unsigned int m_length;

    void addTail(utListNode*);
};