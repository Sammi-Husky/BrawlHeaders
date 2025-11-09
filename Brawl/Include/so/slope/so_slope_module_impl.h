#pragma once

#include <StaticAssert.h>
#include <types.h>
#include <so/anim/so_anim_cmd_event_presenter.h>
#include <so/status/so_status_event_presenter.h>
#include <so/so_array.h>

#define SLOPE_STATUS_MASK_PART 0x8
#define SLOPE_STATUS_MASK_R 0x4
#define SLOPE_STATUS_MASK_L 0x2
#define SLOPE_STATUS_MASK_TOP 0x1
#define SLOPE_STATUS_MASK_NONE 0x0
#define SLOPE_STATUS_MASK_LR 0x6
#define SLOPE_STATUS_MASK_TPART 0x9

class soModuleAccesser;

class soSlopeStatusParam {
public:
    union Status {
        u32 m_mask;
        struct {
            u32 : 28;
            bool m_part : 1;
            bool m_r : 1;
            bool m_l : 1;
            bool m_top : 1;
        };
        inline Status() {}
        inline Status(u32 mask) : m_mask(mask) {}
    } m_status;
    int m_0x4;
    bool m_0x8;
    char _0x9[3];
};
static_assert(0xC == sizeof(soSlopeStatusParam), "Class is wrong size!");

class soSlopeModule {
public:
    virtual ~soSlopeModule();
    virtual void activate();
    virtual void setStatus(u32 statusMask, int, bool);
    virtual soSlopeStatusParam::Status getStatus();
    virtual void update(bool);
    virtual void updateModelTopAngle();
    virtual void setTopAngleUnlimit(bool);
    virtual void setPartNode(int);
    virtual void setInvalidStatus(u32 statusMask);
};

class soSlopeModuleImpl : public soSlopeModule, public soStatusEventObserver, public soAnimCmdEventObserver {
    soModuleAccesser* m_moduleAccesser;
    int m_0x20;
    int m_0x24;
    soSlopeStatusParam::Status m_status;
    char _0x2c[8];
    soArrayVector<soSlopeStatusParam, 1> m_statusParamArrayVector;
    float _0x4c;
    char _0x50[28];
    int m_0x6C;
    float m_0x70;
    int m_partNode;
    soSlopeStatusParam::Status m_invalidStatus;
    u8 m_0x7C;
    bool m_isTopAngleUnlimit;
    char _0x7E[2];
public:
    virtual ~soSlopeModuleImpl();
    virtual void activate();
    virtual void setStatus(u32 statusMask, int, bool);
    virtual soSlopeStatusParam::Status getStatus();
    virtual void update(bool);
    virtual void updateModelTopAngle();
    virtual void setTopAngleUnlimit(bool);
    virtual void setPartNode(int);
    virtual void setInvalidStatus(u32 statusMask);

    virtual bool isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
};