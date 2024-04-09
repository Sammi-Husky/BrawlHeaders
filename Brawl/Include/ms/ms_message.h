#pragma once

#include <types.h>
#include <ms/ms_text_writer_base.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <memory.h>

class Message : public ms::TextWriterBase<char> {
public:

    Message(u32, HeapType heapType);
    virtual ~Message();

    char _164[316];

    bool allocMsgBuf(u32 msgSizes, u32 numMsgs, HeapType heapType);
    bool attachMsgBuf(u32 index, nw4r::g3d::ScnMdlSimple* sceneModel, const char* nodeName, u8, int, float);
    bool changeMsgBuf(int index);
    void clearMsgBuf();
    void setWindow(float, float, float, float);
    void setFace(u8);
    void setFixedWidth(float);
    void setColor(int);
    void setScale(float, float);
    void setCursorX(float);
    void setCursorY(float);
    void printf(const char* format, ...);

    static void getPrintIndexData(void* msgbin, u32 index, char** outStr, u32* outLen);


};
static_assert(sizeof(Message) == 480, "Class is wrong size!");