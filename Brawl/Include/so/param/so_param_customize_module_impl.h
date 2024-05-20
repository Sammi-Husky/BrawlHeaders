#pragma once

#include <so/so_null.h>

class soParamCustomizeModule : soNullable {
public:
    virtual ~soParamCustomizeModule();
    virtual void activate();
    virtual void setDefault();
    virtual void addCustomize(u8);
    virtual void removeCustomize(u8);
    virtual bool isCustomize(u8);
    virtual float getAttackPowerMul();
    virtual void setAttackPowerMulPattern(float);
    virtual float getAttackPowerMulPattern();
    virtual void setAttackPowerMulScale(float);
    virtual float getAttackPowerMulScale();
    virtual float getAttackPowerMulArticle();
    virtual float getAttackReactionMul();
    virtual float getWalkSpeedMul();
    virtual int getParamInt(u32, u32);
    virtual float getParamFloat(u32, u32);
    virtual void* getParamIndefinite(u32, u32);
};
static_assert(sizeof(soParamCustomizeModule) == 8, "Class is wrong size!");

class soParamCustomizeModuleImpl : soParamCustomizeModule {
    float m_attackPowerMulPattern;
    float m_attackPowerMulScale;

public:
    virtual ~soParamCustomizeModuleImpl();
    virtual void activate();
    virtual void setDefault();
    virtual void addCustomize(u8);
    virtual void removeCustomize(u8);
    virtual bool isCustomize(u8);
    virtual float getAttackPowerMul();
    virtual void setAttackPowerMulPattern(float);
    virtual float getAttackPowerMulPattern();
    virtual void setAttackPowerMulScale(float);
    virtual float getAttackPowerMulScale();
    virtual float getAttackPowerMulArticle();
    virtual float getAttackReactionMul();
    virtual float getWalkSpeedMul();
    virtual int getParamInt(u32, u32);
    virtual float getParamFloat(u32, u32);
    virtual void* getParamIndefinite(u32, u32);
};
static_assert(sizeof(soParamCustomizeModuleImpl) == 16, "Class is wrong size!");