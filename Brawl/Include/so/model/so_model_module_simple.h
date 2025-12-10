#pragma once

#include <StaticAssert.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <gf/gf_3d_scene.h>
#include <so/resource/so_resource_module_impl.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <mt/mt_vector.h>
#include <so/so_null.h>
#include <types.h>

class soModelModule : private soNull, public soNullable {
public:
    // TODO: Verify Params
    virtual void setUpMtx(u32 nodeId);
    virtual void setUpMtx(u32* nodeIds, s32 numNodeIds);
    virtual void setUpMtxFinal();
    virtual void setUpSkinningMtx();
    virtual void clearSetUpMtx();
    virtual void constructInstance(gfSceneRoot::LayerType, u32 flags, bool, s8, nw4r::g3d::ResFile, const char*, const char*, s16 mdlResId, void*, u8 loupeNo, int
                                   priorityDrawXlu);
    virtual void destructInstance();
    virtual void activate();
    virtual void deactivate();
    virtual void begin(bool);
    virtual nw4r::g3d::ScnMdl *getScnMdl();
    virtual nw4r::g3d::ScnMdl *getScnMdl(bool );
    virtual void setScnMdl(nw4r::g3d::ScnMdl*, void*, gfSceneRoot::LayerType);
    virtual void setScnMdlExtern(nw4r::g3d::ScnMdl *);
    virtual void detachScnMdl(void*);
    virtual void resetLayerType();
    virtual void setLockMtx(bool);
    virtual void clearNodeSetUp();
    virtual void clearNodeSRT(u32 p1);
    virtual void setNodeSRT(u32 , Vec3f* scale, Vec3f* rot, Vec3f* xlate);
    virtual Vec3f getNodeScale(u32 nodeIndex);
    virtual void setNodeScale(u32 , Vec3f* );
    virtual Vec3f getNodeRotate(u32 nodeIndex);
    virtual void setNodeRotateX(u32 , float x);
    virtual void setNodeRotateY(u32 , float y);
    virtual void setNodeRotateZ(u32 , float z);
    virtual void setNodeRotate(u32 , Vec3f* rot);
    virtual Vec3f getNodeTranslate(u32 p1);
    virtual void setNodeTranslate(u32 , Vec3f* xlate);
    virtual int getNodeId(const char *nodeName);
    virtual int getCorrectNodeId(u32);
    virtual int getRealNodeId(u32);
    virtual const char* getNodeName(u32 p1);
    virtual Vec3f getNodeGlobalPosition(u32 correctNodeId, bool );
    virtual Vec3f getNodeGlobalPosition(u32 correctNodeId, Vec3f* p2, bool, bool );
    virtual Vec3f getNodeLocalPosition(u32 correctNodeId, bool );
    virtual void getNodeLocalMtxFromNode(u32 node1, u32 node2, Matrix* outMtx, bool );
    virtual void getNodeGlobalMtx(u32 index, Matrix* outMtx, bool );
    virtual void setNodeGlobalMtx(u32 index, Matrix* , bool );
    virtual Vec3f getNodeGlobalRotation(u32 nodeIndex, bool );
    virtual bool isNode(int);
    virtual u32 getNodeNum();
    virtual u32 getNodeNum(bool);
    virtual void setTransNNodeId(int);
    virtual const char *getTransNNodeName();
    virtual int getTransNNodeId();
    virtual Vec3f getResFileNodeTranslate(u32 nodeIndex);
    virtual Vec3f getResFileNodeRotation(u32 nodeIndex);
    virtual Vec3f getNodeGlobalOffsetFromTop(u32 p1);
    virtual Vec3f getTopNodeGlobalPosFromNode(u32 p1, Vec3f* p2);
    virtual void renderNodeAxis(u32 nodeIndex, float );
    virtual float getScale();
    virtual void setScale(float);
    virtual void setScaleZ(float);
    virtual gfSceneRoot::LayerType getLayerType();
    virtual void setAnmObj();
    virtual void removeAnmObj();
    virtual void setOption();
    virtual void getResMdl();
    virtual s8 getLoupeNo();
    virtual void setLoupeNo(s8);
    virtual void setVisibility(bool visibility);
    virtual void setVisibility(bool visibility, bool);
    virtual void setNodeVisibility(u32, bool visibility);
    virtual void setNodeVisibility(u32 , bool visibility, bool );
    virtual void setNodeVisibility(int , u32 *, bool visibility);
    virtual void setNodeVisibility(int, u32* , bool visibility, bool );
    virtual void changeMaterialTex(soResourceModule*, const char*resMat, const char*resPlt, nw4r::g3d::ResFile);
    virtual void initVirtualNode(int, u32, u32, void*, Matrix*);
    virtual void setVirtualNodeUpdate(u32 virtualNodeIndex, bool);
    virtual bool isAddEnvMapMat();
    virtual bool isEnvMap();
    virtual void switchEnvMap(bool);
    virtual bool isRefFB();
    virtual void preShadowCalcView();
    virtual Matrix *getWorldMtxArray();
    virtual void setNodeConvertData(u32** convertData);
    virtual void setShadowNode(int);
    virtual void setDisposeInstanceImm(bool);
    virtual ~soModelModule();
};

class soModelModuleSimple : public soModelModule {
    // 0xC
    int m_unk1;

    // 0x10
    int m_unk2;
public:
    // TODO: Verify Params
    virtual void setUpMtx(u32 nodeId);
    virtual void setUpMtx(u32* nodeIds, s32 numNodeIds);
    virtual void setUpMtxFinal();
    virtual void setUpSkinningMtx();
    virtual void clearSetUpMtx();
    virtual void constructInstance(gfSceneRoot::LayerType, u32 flags, bool, s8, nw4r::g3d::ResFile, const char*, const char*, s16 mdlResId, void*, u8 loupeNo, int
                                   priorityDrawXlu);
    virtual void destructInstance();
    virtual void activate();
    virtual void deactivate();
    virtual void begin(bool);
    virtual nw4r::g3d::ScnMdl *getScnMdl();
    virtual nw4r::g3d::ScnMdl *getScnMdl(bool );
    virtual void setScnMdl(nw4r::g3d::ScnMdl*, void*, gfSceneRoot::LayerType);
    virtual void setScnMdlExtern(nw4r::g3d::ScnMdl *);
    virtual void detachScnMdl(void*);
    virtual void resetLayerType();
    virtual void setLockMtx(bool);
    virtual void clearNodeSetUp();
    virtual void clearNodeSRT(u32 p1);
    virtual void setNodeSRT(u32 , Vec3f* scale, Vec3f* rot, Vec3f* xlate);
    virtual Vec3f getNodeScale(u32 nodeIndex);
    virtual void setNodeScale(u32 , Vec3f* );
    virtual Vec3f getNodeRotate(u32 nodeIndex);
    virtual void setNodeRotateX(u32 , float x);
    virtual void setNodeRotateY(u32 , float y);
    virtual void setNodeRotateZ(u32 , float z);
    virtual void setNodeRotate(u32 , Vec3f* rot);
    virtual Vec3f getNodeTranslate(u32 p1);
    virtual void setNodeTranslate(u32 , Vec3f* xlate);
    virtual int getNodeId(const char *nodeName);
    virtual int getCorrectNodeId(u32);
    virtual int getRealNodeId(u32);
    virtual const char* getNodeName(u32 p1);
    virtual Vec3f getNodeGlobalPosition(u32 correctNodeId, bool );
    virtual Vec3f getNodeGlobalPosition(u32 correctNodeId, Vec3f* p2, bool, bool );
    virtual Vec3f getNodeLocalPosition(u32 correctNodeId, bool );
    virtual void getNodeLocalMtxFromNode(u32 node1, u32 node2, Matrix* outMtx, bool );
    virtual void getNodeGlobalMtx(u32 index, Matrix* outMtx, bool );
    virtual void setNodeGlobalMtx(u32 index, Matrix* , bool );
    virtual Vec3f getNodeGlobalRotation(u32 nodeIndex, bool );
    virtual bool isNode(int);
    virtual u32 getNodeNum();
    virtual u32 getNodeNum(bool);
    virtual void setTransNNodeId(int);
    virtual const char *getTransNNodeName();
    virtual int getTransNNodeId();
    virtual Vec3f getResFileNodeTranslate(u32 nodeIndex);
    virtual Vec3f getResFileNodeRotation(u32 nodeIndex);
    virtual Vec3f getNodeGlobalOffsetFromTop(u32 p1);
    virtual Vec3f getTopNodeGlobalPosFromNode(u32 p1, Vec3f* p2);
    virtual void renderNodeAxis(u32 nodeIndex, float );
    virtual float getScale();
    virtual void setScale(float);
    virtual void setScaleZ(float);
    virtual gfSceneRoot::LayerType getLayerType();
    virtual void setAnmObj();
    virtual void removeAnmObj();
    virtual void setOption();
    virtual void getResMdl();
    virtual s8 getLoupeNo();
    virtual void setLoupeNo(s8);
    virtual void setVisibility(bool visibility);
    virtual void setVisibility(bool visibility, bool);
    virtual void setNodeVisibility(u32, bool visibility);
    virtual void setNodeVisibility(u32 , bool visibility, bool );
    virtual void setNodeVisibility(int , u32 *, bool visibility);
    virtual void setNodeVisibility(int, u32* , bool visibility, bool );
    virtual void changeMaterialTex(soResourceModule*, const char*resMat, const char*resPlt, nw4r::g3d::ResFile);
    virtual void initVirtualNode(int, u32, u32, void*, Matrix*);
    virtual void setVirtualNodeUpdate(u32 virtualNodeIndex, bool);
    virtual bool isAddEnvMapMat();
    virtual bool isEnvMap();
    virtual void switchEnvMap(bool);
    virtual bool isRefFB();
    virtual void preShadowCalcView();
    virtual Matrix *getWorldMtxArray();
    virtual void setNodeConvertData(u32** convertData);
    virtual void setShadowNode(int);
    virtual void setDisposeInstanceImm(bool);
    virtual ~soModelModuleSimple();
};
static_assert(sizeof(soModelModuleSimple) == 20, "Class is wrong size!");
