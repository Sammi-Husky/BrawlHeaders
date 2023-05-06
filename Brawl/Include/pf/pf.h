#pragma once

#include <types.h>

struct PFSTR {
    char* path;
    char* pathEnd;
    char* unk;
    int charWidth;
};

struct PFENT {
    char _0x0[0x228];
    u32 _0x228;
    void* cache;
    char _0x230[4];
    u32 _0x234;
    int sector;
    short offset;
};

struct PFENT_ITER {
    char _0x0[0x8];
    u32 _0x8;
    char _0xC[0x2c];
    void* unk;
    char _0x3c[0x31];
};

struct PFVOL {
    char _0x0[0x1640];
    u32 _0x1640;
    u32 _0x1644;
    char _0x1648[0x948];
    u32 _0x1f90;
    char _0x1f94[0x34];
};

extern "C" void PF_enterCritical(void* unk);
extern "C" void PF_exitCritical(void* unk);
extern "C" PFVOL* PFPATH_GetVolumeFromPath(PFSTR* str);
extern "C" int PFENT_ITER_GetEntryOfPath(PFENT_ITER* iter, PFENT* entry, PFVOL* vol, PFSTR* str, int unk);
extern "C" int PFSEC_ReadData(void* cache, void* buffer, int sector, int offset, int len, int* success, int unk);
extern "C" int PFSEC_WriteData(void* cache, void* buffer, int sector, int offset, int len, int* success, int unk);
extern "C" int PFFILE_p_remove(PFVOL* vol, PFSTR* str);
extern "C" int PFCACHE_FlushFATCache(PFVOL* vol);
extern "C" int PFCACHE_FlushDataCacheSpecific(PFVOL* vol, int unk);
extern "C" int PFSTR_InitStr(PFSTR* dst, const char* src, int unk);
extern "C" int PFDIR_p_mkdir(PFVOL* vol, PFSTR* path, int unk1, int unk2);
extern "C" int PFAPI_convertReturnValue(int);
extern "C" int PFENT_RemoveEntry(PFENT* entry, PFENT_ITER* iter);
extern "C" int PFFAT_FreeChain(void*, u32, u32, u32);
extern "C" int PFENT_getcurrentDateTimeForEnt(u16* date, u16* time);