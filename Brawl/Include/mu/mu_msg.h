#pragma once

#include <ms/ms_message.h>

class MuMsg {
public:
    enum AlignMode {
        Align_Center = 0x0,
        Align_Left = 0x1,
        Align_Right = 0x2,
    };

private:

    class WindowSetting {
        char _0[0x48];
    };
    static_assert(sizeof(WindowSetting) == 0x48, "Class is wrong size!");

    bool : 1;
    bool : 1;
    bool : 1;
    bool : 1;
    bool m_isMsgDataSet : 1;
    bool : 1;
    bool : 1;
    bool : 1;
    s8 m_fontId;
    char _2[2];
    void* m_msgData;
    Message* m_message;
    char _12[4];
    u32 m_numMsgs;
    HeapType m_heapType;
    int m_24;

public:
    bool allocMsgBuf(u32 msgSizes, u32 numMsgs);
    void setMsgData(void* msgBinData);
    void attachScnMdlSimple(u32 msgIndex, nw4r::g3d::ScnMdlSimple* sceneModel, u32 boneTextIndex, float fontSize);
    void setFontWidthModeAuto(u32 msgIndex);
    void setAlignMode(u32 msgIndex, AlignMode alignMode);
    void setFontColor(u32 msgIndex, u8 r, u8 g, u8 b, u8 a);
    void FUN_800b9448(u32 msgIndex, bool);
    void FUN_800b9460(u32 msgIndex, u8, u8, u8, float);
    void printf(u32 msgIndex, const char* format, ...);
    bool printIndex(u32 msgIndex, u32 lineIndex, void* msgBinData);

    static MuMsg* create(u32 fontSetting, HeapType heapType, u32);
};
static_assert(sizeof(MuMsg) == 0x1c, "Class is wrong size!");
