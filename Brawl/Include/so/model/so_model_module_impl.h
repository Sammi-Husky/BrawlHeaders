#pragma once

#include <StaticAssert.h>
#include <memory.h>
#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#include <so/model/so_model_module_simple.h>
#include <so/event/so_event_presenter.h>
#include <so/model/so_model_event_presenter.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <types.h>

class soModuleAccesser;

class soModelModuleImpl : public soModelModuleSimple, public soAnimCmdEventObserver, public soEventPresenter<soModelEventObserver> {
    char _spacer1[156];
    soModuleAccesser* m_moduleAccesser; // +0xC8
public:
    // TODO: types for p2 and p5
    soModelModuleImpl(soModuleAccesser* p1, void* p2, u32 p3, u32 p4, void* p5, float f1);
    // TODO: Verify Params
    virtual void setUpMtx(u32 unk2);
    virtual void setUpMtx(u32* p1, s32 p2);
    virtual void setUpMtxFinal();
    virtual void setUpSkinningMtx();
    virtual void clearSetUpMtx();
    virtual void constructInstance();
    virtual void destructInstance();
    virtual void activate();
    virtual void deactivate();
    virtual void begin();
    virtual void* getScnMdl(bool p1);
    virtual void setScnMdl();
    virtual void setScnMdlExtern(void* p1);
    virtual void detachScnMdl();
    virtual void setLockMtx();
    virtual void clearNodeSetUp();
    virtual void clearNodeSRT(u32 p1);
    virtual void setNodeSRT(u32 p1, Vec3f* scale, Vec3f* rot, Vec3f* xlate);
    virtual Vec3f getNodeScale(u32 p1);
    virtual void setNodeScale(u32 p1, Vec3f* p2);
    virtual Vec3f getNodeRotate(u32 p1);
    virtual void setNodeRotateX(u32 p1, float x);
    virtual void setNodeRotateY(u32 p1, float y);
    virtual void setNodeRotateZ(u32 p1, float z);
    virtual void setNodeRotate(u32 p1, Vec3f* rot);
    virtual Vec3f getNodeTranslate(u32 p1);
    virtual void setNodeTranslate(u32 p1, Vec3f* xlate);
    virtual u32 getCorrectNodeId(u32 p1);
    virtual Vec3f getNodeGlobalPosition(u32 p1, bool p2);
    virtual Vec3f getNodeGlobalPosition(u32 p1, Vec3f* p2, u32 p3, bool p4);
    virtual Vec3f getNodeLocalPosition(u32 p1, bool p2);
    virtual void getNodeLocalMtxFromNode(u32 p1, u32 p2, Matrix* p3, bool p4);
    virtual void getNodeGlobalMtx(u32 p1, Matrix* p2, bool p3);
    virtual void setNodeGlobalMtx(u32 p1, Matrix* p2, bool p3);
    virtual Vec3f getNodeGlobalRotation(u32 nodeIndex, bool p2);
    virtual bool isNode(u32 p1);
    virtual void getNodeNum_overload();
    virtual void setTransNNodeId();
    virtual void getTransNNodeName();
    virtual void getTransNNodeId();
    virtual Vec3f getResFileNodeTranslate(u32 p1);
    virtual Vec3f getResFileNodeRotation(u32 p1);
    virtual void renderNodeAxis(u32 p1, float f1);
    virtual void getScale();
    virtual void setScale();
    virtual void setScaleZ();
    virtual void getLayerType();
    virtual s8 getLoupeNo();
    virtual void setLoupeNo(s8);
    virtual void setVisibility(int unk1, int unk2);
    virtual void setNodeVisibility(u32 p1, bool p2, bool p3);
    virtual void setNodeVisibility(s32 p1, u32* p2, bool p3, bool p4);
    virtual void changeMaterialTex();
    virtual void initVirtualNode();
    virtual void setVirtualNodeUpdate();
    virtual void isAddEnvMapMat();
    virtual void isEnvMap();
    virtual void switchEnvMap(bool);
    virtual void isRefFB();
    virtual void preShadowCalcView();
    virtual void getWorldMtxArray();
    virtual void setShadowNode();
    virtual void setDisposeInstanceImm();
    virtual ~soModelModuleImpl();

    virtual bool isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
};
static_assert(sizeof(soModelModuleImpl) == 204, "Class is wrong size!");

class soModelModuleImplVariable : public soModelModuleImpl {
    u32** unkCC;
public:
    // TODO: types for p2 and p5
    soModelModuleImplVariable(soModuleAccesser* p1, void* p2, u32 p3, u32 p4, void* p5, float f1);
    virtual void setUpMtx(u32* p1, s32 p2);
    virtual void clearNodeSRT(u32 p1);
    virtual void setNodeSRT(u32 p1, Vec3f* scale, Vec3f* rot, Vec3f* xlate);
    virtual Vec3f getNodeScale(u32 p1);
    virtual void setNodeScale(u32 p1, Vec3f* scale);
    virtual Vec3f getNodeRotate(u32 p1);
    virtual void setNodeRotateX(u32 p1, float x);
    virtual void setNodeRotateY(u32 p1, float y);
    virtual void setNodeRotateZ(u32 p1, float z);
    virtual void setNodeRotate(u32 p1, Vec3f* rot);
    virtual Vec3f getNodeTranslate(u32 p1);
    virtual void setNodeTranslate(u32 p1, Vec3f* xlate);
    virtual u32 getNodeId(const char* nodeName);
    virtual u32 getCorrectNodeId(u32 p1);
    virtual u32 getRealNodeId(u32 p1);
    virtual const char* getNodeName(u32 p1);
    virtual Vec3f getNodeGlobalPosition(u32 p1, bool p2);
    virtual Vec3f getNodeGlobalPosition(u32 p1, Vec3f* p2, u32 p3, bool p4);
    virtual Vec3f getNodeLocalPosition(u32 p1, bool p2);
    virtual void getNodeLocalMtxFromNode(u32 p1, u32 p2, Matrix* p3, bool p4);
    virtual void getNodeGlobalMtx(u32 p1, Matrix* p2, bool p3);
    virtual void setNodeGlobalMtx(u32 p1, Matrix* p2, bool p3);
    virtual Vec3f getNodeGlobalRotation(u32 nodeIndex, bool p2);
    virtual bool isNode(u32 p1);
    virtual Vec3f getResFileNodeTranslate(u32 p1);
    virtual Vec3f getResFileNodeRotation(u32 p1);
    virtual Vec3f getNodeGlobalOffsetFromTop(u32 p1);
    virtual Vec3f getTopNodeGlobalPosFromNode(u32 p1, Vec3f* p2);
    virtual void renderNodeAxis(u32 p1, float f1);
    virtual void setNodeVisibility(u32 p1, bool p2, bool p3);
    virtual void setNodeVisibility(s32 p1, u32* p2, bool p3, bool p4);
    virtual void setNodeConvertData(u32** convertData);
    virtual ~soModelModuleImplVariable();
};
static_assert(sizeof(soModelModuleImplVariable) == 0xD0, "Class is wrong size!");
