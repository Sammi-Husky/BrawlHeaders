#pragma once
#include <memory.h>
#include <gf/gf_model.h>
#include <nw4r/g3d/g3d_scnobj.h>
#include <nw4r/g3d/g3d_resfile.h>

class MuObject
{

public:
    char unk[0x10]; // this is 0x60 in size
    nw4r::g3d::ScnObj *scnObj;
    gfModelAnimation *gfModelAnimation;
    char unk2[0x44];

    static MuObject *create(nw4r::g3d::ResFile **output, char *node, char flag, int otherflag, HeapType type);
    static MuObject *create(nw4r::g3d::ResFile **output, int node, char flag, int otherflag, HeapType type);
    void changeAnimN(char *animName);
    void changeNodeAnimN(char *animName);
    void changeClrAnimN(char *animName);
    void changeVisAnimN(char *animName);
    void changeAnimNIf(char *animName);
    void changeNodeAnimNIf(char *animName);
    void changeClrAnimNIf(char *animName);
    void changeVisAnimNIf(char *animName);
    void changeTexPatAnimNIf(char *animName);
    void setFrameVisible(float frame);
    void setFrameMatCol(float frame);
    virtual ~MuObject();
};
