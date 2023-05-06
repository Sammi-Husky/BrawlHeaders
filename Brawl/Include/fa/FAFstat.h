#pragma once

#include <types.h>

struct pfstat {
    int filesize;
    s16 accessDate;
    s16 modifiedTime;
    s16 modifiedDate;
    s16 createdTime;
    s16 createdDate;
    u16 unk;
    char flags;
};

extern "C" int FAFstat(const char* filepath, pfstat* st);