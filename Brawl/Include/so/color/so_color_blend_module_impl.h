#pragma once
#include <so/so_null.h>
#include <so/anim/so_anim_chr.h>
#include <so/event/so_event_observer.h>
#include <GX/GXTypes.h>

class soColorBlendModule: public soNullable {
public:
    // TODO: Fill out params for most of these.
    virtual bool isNull() = 0;                                 // 0x8
    virtual ~soColorBlendModule();                             // 0xc
    virtual void activate() = 0;                               // 0x10
    virtual void deactivate() = 0;                             // 0x14
    virtual void update() = 0;                                 // 0x18
    virtual void updateMaterial() = 0;                         // 0x1C
    virtual void offAll() = 0;                                 // 0x20
    virtual void setFlash() = 0;                               // 0x24
    virtual void setFlashColorFrame() = 0;                     // 0x28
    virtual void offFlash() = 0;                               // 0x2C
    virtual void setLight() = 0;                               // 0x30
    virtual void setLightColor() = 0;                          // 0x34
    virtual void setLightColorFrame() = 0;                     // 0x38
    virtual void setLightDir() = 0;                            // 0x3C
    virtual void offLight() = 0;                               // 0x40
    virtual void setPri() = 0;                                 // 0x44
    virtual void setSubColor(GXColor color, char enabled) = 0; // 0x48
    virtual char isEnableSubColor() = 0;                       // 0x4C
    virtual GXColor getSubColor() = 0;                         // 0x50
    virtual void getColorBlend() = 0;                          // 0x54
    virtual void getLightSet() = 0;                            // 0x58
};

class soColorBlendModuleImpl: 
    public soColorBlendModule, 
    public soStatusEventObserver,
    public soAnimCmdEventObserver,
    public soModelEventObserver
{
public:
    // char _vtables[4];
    // 0x2C
    char _unk[0x154 - 0x2C];

    virtual bool isNull();
    virtual ~soColorBlendModuleImpl();
    virtual void activate();
    virtual void deactivate();
    virtual void update();
    virtual void updateMaterial();
    virtual void offAll();
    virtual void setFlash();
    virtual void setFlashColorFrame();
    virtual void offFlash();
    virtual void setLight();
    virtual void setLightColor();
    virtual void setLightColorFrame();
    virtual void setLightDir();
    virtual void offLight();
    virtual void setPri();
    virtual void setSubColor(GXColor color, char enabled);
    virtual char isEnableSubColor();
    virtual GXColor getSubColor();
    virtual void getColorBlend();
    virtual void getLightSet();

    virtual u32 isObserv(char unk1);
    virtual bool notifyEventAnimCmd(acAnimCmd* acmd, soModuleAccesser* moduleAccesser, int unk3);
    virtual void notifyEventChangeStatus(int statusKind, int prevStatusKind, soStatusData* statusData, soModuleAccesser* moduleAccesser);
    virtual void notifyEventConstructInstance(bool, soModuleAccesser* moduleAccesser);
};
static_assert(0x154 == sizeof(soColorBlendModuleImpl), "Class is wrong size!");

class soColorBlendModuleNull: public soColorBlendModule {
    virtual ~soColorBlendModuleNull();
    virtual void activate();
    virtual void deactivate();
    virtual void update();
    virtual void updateMaterial();
    virtual void offAll();
    virtual void setFlash();
    virtual void setFlashColorFrame();
    virtual void offFlash();
    virtual void setLight();
    virtual void setLightColor();
    virtual void setLightColorFrame();
    virtual void setLightDir();
    virtual void offLight();
    virtual void setPri();
    virtual void setSubColor(GXColor color, char enabled);
    virtual char isEnableSubColor();
    virtual GXColor getSubColor();
    virtual void getColorBlend();
    virtual void getLightSet();

    soColorBlendModuleNull* getNullInstance();
};