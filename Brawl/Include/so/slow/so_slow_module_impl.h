#pragma once

#include <types.h>
#include <StaticAssert.h>
#include <so/so_null.h>
#include <so/slow/so_slow_module_simple.h>
#include <so/so_event_observer.h>

class soModuleAccesser;

class soSlowModuleImpl : public soSlowModuleSimple, public soAnimCmdEventObserver {
    char _36[4];
    int m_frame;
    u8 m_44;
    char _45[3];
    int m_wholeFrame;
    int m_mag;
public:
    virtual ~soSlowModuleImpl();
    virtual void activate();
    virtual void deactivate();
    virtual void update(bool);
    virtual void resetSkip();
    virtual void set(int mag, int frame);
    virtual int getMag();
    virtual int getFrame();
    virtual void clear();
    virtual void setWhole(bool, int wholeFrame);
    virtual void clearWhole();
    virtual u8 getWholeMag();
    virtual void setWholeFrame(int wholeFrame);
    virtual int getWholeFrame();

    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);

    STATIC_CHECK(sizeof(soSlowModuleImpl) == 56)
};
