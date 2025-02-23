#pragma once

#include <StaticAssert.h>
#include <so/area/so_area_instance.h>
#include <so/area/so_area_enviroment_element_checker_impl.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/status/so_status_event_presenter.h>
#include <so/situation/so_situation_event_presenter.h>
#include <gf/gf_area.h>
#include <mt/mt_vector.h>
#include <st/st_area_manager.h>
#include <so/so_null.h>
#include <so/so_array.h>
#include <GX/GXTypes.h>
#include <types.h>

#define AREA_SHAPE_FLAG_FOLLOW_NODE 0x1
#define AREA_SHAPE_FLAG_FIXED 0x2
#define AREA_SHAPE_FLAG_LR 0x4
#define AREA_SHAPE_FLAG_RESET_DISABLE 0x8
#define AREA_SHAPE_FLAG_STATUS_DISABLE 0x10
#define AREA_SHAPE_FLAG_STATUS_ENABLE 0x20
#define AREA_SHAPE_FLAG_IGNORE_SCALE 0x40
#define AREA_SHAPE_FLAG_ENABLE_SITUATION_GROUND 0x80
#define AREA_SHAPE_FLAG_ENABLE_SITUATION_AIR 0x100
#define AREA_SHAPE_FLAG_APPLY_OFFSET_ROT 0x200
#define AREA_SHAPE_FLAG_CHILD 0x400

class soModuleAccesser;

struct soAreaData {

    enum Category {
        Category_Fighter = 0x0,
        Category_Enemy = 0x1,
        Category_Yakumono = 0x2,
        Category_Item = 0x3,
        Category_Weapon = 0x4,
    };

    gfArea::ShapeType m_shapeType : 8;
    gfArea::Group m_group : 8;

    union ShapeFlag {
        u16 m_mask;
        struct {
            bool m_flag15 : 1;      // 0x8000
            bool m_flag14 : 1;      // 0x4000
            bool m_flag13 : 1;      // 0x2000
            bool m_flag12 : 1;      // 0x1000
            bool m_flag11 : 1;      // 0x800
            bool m_child : 1;      // 0x400
            bool m_applyOffsetRot : 1;      // 0x200
            bool m_enableSituationAir : 1;       // 0x100
            bool m_enableSituationGround : 1;       // 0x80
            bool m_ignoreScale : 1;    // 0x40
            bool m_statusEnable : 1;       // 0x20
            bool m_statusDisable : 1;       // 0x10
            bool m_resetDisable : 1;       // 0x8
            bool m_lr : 1;       // 0x4
            bool m_fixed : 1;  // 0x2
            bool m_followNode : 1;     // 0x1
        };
    } m_shapeFlag;

    int m_0x4;
    int m_0x8;
    int m_nodeIndex;
    Vec2f m_offsetPos;
    Vec2f m_range;
};
static_assert(sizeof(soAreaData) == 0x20, "Class is wrong size!");

struct soAreaContactLog {
    char _0x0[0x18];
};
static_assert(sizeof(soAreaContactLog) == 0x18, "Class is wrong size!");

struct soAreaWind {
    char _0x0[4];
};
static_assert(sizeof(soAreaWind) == 0x4, "Class is wrong size!");

class soAreaModule : public soNullable {
public:
    virtual ~soAreaModule();
    virtual void activate(int ownerId);
    virtual void deactivate();
    virtual void update();
    virtual void clearLog();
    virtual void check();
    virtual void clean();
    virtual void setup(soSet<soAreaData>*);
    virtual void addArea(soSet<soAreaData>*);
    virtual void setWhole(u8);
    virtual gfArea::Group getGroup(u32 index);
    virtual void enableArea(int, bool, int);
    virtual bool isEnableArea(int);
    virtual void resetArea(int);
    virtual void setAreaTargetGroupMask(u32 index, u32 mask);
    virtual void setAreaTargetLocalGroupMask(u32 index, u32 mask);
    virtual void setAreaShape(u32 index, Vec2f*, Vec2f*);
    virtual void setAreaShape(u32 index, Vec2f*, float);
    virtual void setAreaShapeType(u32 index, gfArea::ShapeType);
    virtual void setCenterX0(u32 index, bool);
    virtual void setAreaDbgColor(u32 index, GXColor);
    virtual int getAreaId(u32 index);
    virtual bool isExistAreaInstance(int);
    virtual gfArea* getAreaInstance(u32 index);
    virtual int getAreaIndexFromId(int);
    virtual u32 getAreaContactCount(int);
    virtual soAreaContactLog* getAreaContactLog(int, u32);
    virtual soAreaEnviromentElementChecker* getEnviromentElementChecker();
    virtual void setLogOverThrough(bool);
    virtual void eraseWind(int);
    virtual void createWind(u32, u32, stMovementData*);
};

class soAreaModuleImpl : public soAreaModule, public gfAreaEventReciver, public soAnimCmdEventObserver, public soStatusEventObserver, public soSituationEventObserver {
    soArray<soAreaInstance>* m_areaInstanceArray;
    soArray<soAreaContactLog>* m_areaContactLogArray;
    union {
        soAreaEnviromentElementChecker* m_enviromentElementChecker;
        soAreaEnvironmentElementChecker* m_environmentElementChecker;
    };
    soArray<soAreaWind>* m_areaWindArray;
    int m_0x40;
    soAreaData::Category m_category : 8;
    char _0x45[3];
    soModuleAccesser* m_moduleAccesser;

public:
    virtual ~soAreaModuleImpl();
    virtual void activate(int ownerId);
    virtual void deactivate();
    virtual void update();
    virtual void clearLog();
    virtual void check();
    virtual void clean();
    virtual void setup(soSet<soAreaData>*);
    virtual void addArea(soSet<soAreaData>*);
    virtual void setWhole(u8);
    virtual gfArea::Group getGroup(u32 index);
    virtual void enableArea(int, bool, int);
    virtual bool isEnableArea(int);
    virtual void resetArea(int);
    virtual void setAreaTargetGroupMask(u32 index, u32 mask);
    virtual void setAreaTargetLocalGroupMask(u32 index, u32 mask);
    virtual void setAreaShape(u32 index, Vec2f*, Vec2f*);
    virtual void setAreaShape(u32 index, Vec2f*, float);
    virtual void setAreaShapeType(u32 index, gfArea::ShapeType);
    virtual void setCenterX0(u32 index, bool);
    virtual void setAreaDbgColor(u32 index, GXColor);
    virtual int getAreaId(u32 index);
    virtual bool isExistAreaInstance(int);
    virtual gfArea* getAreaInstance(u32 index);
    virtual int getAreaIndexFromId(int);
    virtual u32 getAreaContactCount(int);
    virtual soAreaContactLog* getAreaContactLog(int, u32);
    virtual soAreaEnviromentElementChecker* getEnviromentElementChecker();
    virtual void setLogOverThrough(bool);
    virtual void eraseWind(int);
    virtual void createWind(u32, u32, stMovementData*);

    virtual void reciveEvent(gfArea*, gfArea*);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, s32 unk3);
    virtual bool isObserv(char unk1);
    virtual void notifyEventChangeSituation(SituationKind kind, SituationKind prevKind, soModuleAccesser* moduleAccesser);


};
static_assert(sizeof(soAreaModuleImpl) == 0x4c, "Class is wrong size!");

