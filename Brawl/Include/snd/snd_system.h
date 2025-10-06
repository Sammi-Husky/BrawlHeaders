#pragma once

#include <StaticAssert.h>
#include <snd/snd_id.h>
#include <types.h>

class FrameHeap
{
public:
    u32* m_heapPtr;
    u32* m_currLevel;
    u8* _unk08;
    u8* _unk0C;
};
static_assert(sizeof(FrameHeap) == 0x10, "Class is wrong size!");

class SoundHeap
{
public:
    virtual ~SoundHeap();
    virtual u32 Alloc(u32);

    u32 m_mutex;
    u8 _unk08[0x14];
    FrameHeap m_frameHeap;
};
const u32 offset = offsetof(SoundHeap, SoundHeap::m_frameHeap);
static_assert(sizeof(SoundHeap) == 0x2C, "Class is wrong size!");

class sndHeapSys
{
public:
    char _0[0x258];
    SoundHeap m_heapArr[0xC];
    char _468[0x9C];
};
static_assert(sizeof(sndHeapSys) == 0x504, "Class is wrong size!");

class sndSystem {
public:
    char _0[0x2D0];
    sndHeapSys* m_sndHeapSys;
    char _2D4[0x8FC];

    int loadSoundGroup(SndGroupID sndGroupId, int, bool isRequest);
    void freeGroup(int heapLevel, int);
    bool loadArchiveHeader();
    bool setupBuffers();
    void loadCommon();

    s32 playSE(SndID sndID, int unk, int unk2, int unk3, int unk4);
    void stopSE(s32 p1, s32 p2);
    void setBGMVol(bool setImmediately, float volume);
    s32 prepareSE(SndID p1, s32 p2, s32 p3);
    void setPan(s32 p1, float p2);
    void startSE(s32 p1, s32 p2, s32 p3);
    bool playBGM(int bgmId, u32 fade, bool);
    int getBGMId();
};
static_assert(sizeof(sndSystem) == 0xbd0, "Class is wrong size!");

extern sndSystem* g_sndSystem;
