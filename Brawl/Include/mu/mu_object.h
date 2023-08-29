#pragma once
#include <gf/gf_model.h>
#include <memory.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_scnobj.h>

class MuObject {

public:
    char unk[0x10]; // this is 0x60 in size
    nw4r::g3d::ScnObj* scnObj;
    gfModelAnimation* gfModelAnimation;
    char unk2[0x44];

    static MuObject* create(nw4r::g3d::ResFile** output, const char* node, char flag, int otherflag, HeapType type);
    static MuObject* create(nw4r::g3d::ResFile** output, int node, char flag, int otherflag, HeapType type);
    void changeAnimN(const char* animName);
    void changeNodeAnimN(const char* animName);
    void changeClrAnimN(const char* animName);
    void changeVisAnimN(const char* animName);
    void changeAnimNIf(const char* animName);
    void changeNodeAnimNIf(const char* animName);
    void changeClrAnimNIf(const char* animName);
    void changeVisAnimNIf(const char* animName);
    void changeTexPatAnimNIf(const char* animName);
    void setFrameVisible(float frame);
    void setFrameMatCol(float frame);
    void setFrameTex(float frame);
    virtual ~MuObject();
};
