#pragma once

#include <StaticAssert.h>
#include <gf/gf_archive.h>
#include <gf/gf_model.h>
#include <gf/gf_task.h>
#include <gr/gr_collision_status.h>
#include <memory.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <so/so_array.h>
#include <types.h>

class Stage;

class Ground : public gfTask {
public:
    // 0
    nw4r::g3d::ResFile m_resFile;
    // 4
    nw4r::g3d::ScnMdl** m_sceneModels; // TODO: supposed to be a wrapper of some kind
    // 8
    gfModelAnimation** m_modelAnims;
    // C
    grCollision* m_collision;
    // 10
    Ground* m_nextGround;
    // 14
    char _spacer2[0x8];
    // 1C
    u16 m_mdlIndex;
    // 1E
    char _spacer3[2];
    // 20
    void* m_stageData;
    // 24
    float m_motionRatio;
    // 28
    char _align[4];
    // 2c
    union {
        struct {
            bool m_visibilityFlag7 : 1;
            bool m_visibilityFlag6 : 1;
            bool m_visibilityFlag5 : 1;
            bool m_visibilityFlag4 : 1;
            bool m_visibilityFlag3 : 1;
            bool m_visibilityFlag2 : 1;
            bool m_visibilityFlag1 : 1;
            bool m_visibilityFlag0 : 1;
        };
        u8 m_visibilityFlags;
    };
    // 2d
    char _spacer[3];
    // 30
    HeapType m_heapType;
    // 34
    char _spacer5[40];

    Ground(const char* taskName);
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processGameProc();
    virtual void renderPre();
    virtual void renderDebug();
    virtual ~Ground();

    virtual void update(float deltaFrame);
    virtual void loadGroundData(u32 unk1, u32 unk2, u32 unk3);
    virtual void bindData(gfArchive* data);
    virtual void setupMelee();
    virtual void setVisibility(u32 unk1);
    virtual void setVisibilityByClipping(u32 unk1);
    virtual void setVisibilityAttachedEffect(u32 unk1);
    virtual void receiveCollMsg(int direction, grCollStatus* collStatus, grCollisionJoint* collisionJoint);
    virtual void receiveCollMsg_Landing(grCollStatus* collStatus, grCollisionJoint* collisionJoint, bool isFirstContact);
    virtual void receiveCollMsg_Heading(grCollStatus* collStatus, grCollisionJoint* collisionJoint, bool isFirstContact);
    virtual void receiveCollMsg_Wall(grCollStatus* collStatus, grCollisionJoint* collisionJoint);
    virtual void receiveCollMsg_Attack(grCollStatus* collStatus, grCollisionJoint* collisionJoint);
    virtual void unloadData();
    virtual int getModelCount();
    virtual void startup(gfArchive* data, u32 unk1, u32 unk2);
    virtual bool setNode();
    virtual void setStageData(void* stageData);
    virtual void* getStageData();
    virtual void initStageData();
    virtual void setMdlIndex(int mdlIndex);
    virtual short getMdlIndex();
    virtual bool isEnableCalcCollision();
    virtual void enableCalcCollision();
    virtual void disableCalcCollision();
    virtual u32 getNodeIndex(u32 sceneModelIndex, const char* nodeName);
    virtual bool getNodePosition(Vec3f* nodePos, u32 sceneModelIndex, u32 nodeIndex);
    virtual bool getNodePosition(Vec3f* nodePos, u32 sceneModelIndex, const char* nodeName);
    virtual bool getNodeMatrix(Matrix* nodeMtx, u32 sceneModelIndex, u32 nodeIndex);
    virtual bool getNodeMatrix(Matrix* nodeMtx, u32 sceneModelIndex, const char* nodeName);
    virtual bool setNodeVisibility(bool setVisibility, u32 sceneModelIndex, u32 nodeIndex, bool recursive, bool recursive_);
    virtual bool setNodeVisibility(bool setVisibility, u32 sceneModelIndex, const char* nodeName, bool recursive, bool recursive_);
    virtual bool setNodeVisibilityAll(bool unk1, u32 sceneModelIndex);
    virtual bool isNodeVisible(u32 sceneModelIndex, u32 nodeIndex);
    virtual bool setNodeCollision(bool setCollision, u32 sceneModelIndex, u32 nodeIndex, bool recursive);
    virtual bool setNodeCollision(bool setCollision, u32 sceneModelIndex, const char* nodeName, bool recursive);
    virtual bool getNodeScale(Vec3f* nodeScale, u32 sceneModelIndex, u32 nodeIndex);
    virtual bool getNodeScale(Vec3f* nodeScale, u32 sceneModelIndex, const char* nodeName);
    virtual void setValid(u32 unk1);
    virtual void setValidAttachedEffect(u32 unk1);
    virtual void setInitializeFlag();
    virtual void setInitializeInfo(int initializeInfo);
    virtual bool getInitializeInfo(int initializeInfo);
    virtual void setMotionRatio(float ratio);
    virtual void setMotionFrame(float frame, u32 animIndex);
    virtual float getMotionFrame(u32 anim);
    virtual void setMotionLoop(bool shouldLoop, u32 animIndex);
    virtual void setMatAlphaMul(u32 unk1, u32 sceneModelIndex); // TODO
    virtual void setMatAlpha(u32 unk1, u32 sceneModelIndex);    // TODO
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual bool adventureEventGetItem(int unk1, int* unk2);
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag(char flag);

    bool getNodeIndex(u32* nodeIndex, u32 sceneModelIndex, const char* nodeName);
    void addSceneRoot(nw4r::g3d::ScnMdl* sceneModel, int unk2);
    bool isCollisionStatusOwnerTask(grCollStatus* collStatus, int* unk2);
    bool searchNode(const char* unk1, const char* nodeName, int* unk3, u32* nodeIndex);
    void setBlendColorDisable();
    void setBlendColorEnable();
    void setDontMoveGround();
    void setEnableCollisionStatus(bool enableColl);
    void setEnableCollisionStatusByClipping(bool enableColl);
    void setVisibilityByClipping(int unk1, u32 sceneModelIndex);
    void updateG3dProcCalcWorldForce();
};
static_assert(sizeof(Ground) == 0x9C, "Class is wrong size!");

// Size: 196
