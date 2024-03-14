#pragma once
#include <gf/gf_model.h>
#include <memory.h>
#include <nw4r/g3d/g3d_resmdl.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_scnobj.h>

class MuObject {

public:
    char unk[0x4];
    nw4r::g3d::ResFile m_resFile;
    nw4r::g3d::ResMdl m_resMdl;
    nw4r::g3d::ScnMdl* m_scnMdl;
    nw4r::g3d::ScnMdl* m_sceneModel;
    gfModelAnimation* m_modelAnim;
    char unk2[0x44];

    static MuObject* create(nw4r::g3d::ResFile* modelSource, const char* node, int drawPriority, nw4r::g3d::ResFile* textureSource, HeapType type);
    static MuObject* create(nw4r::g3d::ResFile* modelSource, int node, int drawPriority, nw4r::g3d::ResFile* textureSource, HeapType type);
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
static_assert(sizeof(MuObject) == 0x60, "Class is wrong size!");