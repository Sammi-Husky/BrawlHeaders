#pragma once

struct FAFStat {
    int filesize;
    int unk[0x14];
};

extern "C" int FAFstat(const char* filepath, FAFStat* st);