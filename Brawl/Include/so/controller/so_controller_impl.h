#pragma once

#include <StaticAssert.h>
#include <so/so_null.h>
#include <types.h>

class soController : public soNullable {
public:
    virtual void resetFlick();
    virtual void resetButton();
    virtual void resetTrigger();
    virtual void resetMainStickX();
    virtual void setMainStickX(float);
    virtual void resetMainStickY();
    virtual void setMainStickY(float);
    virtual void resetMainStick();
    virtual void resetSubStickX();
    virtual void resetSubStickY();
    virtual void resetSubStick();
    virtual void reset();
    virtual void update(void*, bool);
    virtual void resetFlickX();
    virtual void resetFlickY();
    virtual void setOff(bool);
    virtual float getStickX();
    virtual float getStickPrevX();
    virtual float getStickY();
    virtual float getStickPrevY();
    virtual float getFlickX();
    virtual float getFlickXDir();
    virtual float getFlickY();
    virtual float getFlickYDir();
    virtual float getFlickNoResetX();
    virtual float getFlickNoResetY();
    virtual float getFlickAfterX();
    virtual float getFlickAfterXDir();
    virtual float getFlickAfterY();
    virtual float getSubStickX();
    virtual float getSubStickPrevX();
    virtual float getSubStickY();
    virtual float getSubStickPrevY();
    virtual int getTrigger();
    virtual u8 getTriggerCount();
    virtual u8 getTriggerCountPrev();
    virtual int getButton();
    virtual int getRelease();
    virtual float getLr();
    virtual u8 getFlickBonus();
    virtual u8 getFlickBonusLr();
    virtual void resetFlickBonus();
    virtual void resetFlickBonusLr();
    virtual ~soController();
};
static_assert(sizeof(soController) == 8, "Class is wrong size!");

class soControllerImpl : public soController {

    class soControllerTriggerData {
        u8 m_countPrev;
        u8 m_count;
    };

public:
    float m_mainStickX;
    float m_mainStickY;
    float m_mainStickPrevX;
    float m_mainStickPrevY;
    char _24[8];
    float m_subStickX;
    float m_subStickY;
    float m_subStickPrevX;
    float m_subStickPrevY;
    char _48[8];
    float m_lr;
    char _60[8];
    int m_button;
    char _72[8];
    int m_trigger;
    int m_release;
    soControllerTriggerData m_triggerData[2];
    char _92[30];
    u8 m_flickX;
    u8 m_flickXDir;
    u8 m_flickY;
    u8 m_flickYDir;
    u8 m_flickNoResetX;
    char _127;
    u8 m_flickNoResetY;
    char _129;
    u8 m_flickAfterX;
    u8 m_flickAfterXDir;
    u8 m_flickAfterY;
    char _133;
    u8 m_flickBonus;
    u8 m_flickBonusLr;
    bool _136;
    bool _isOff;
    char _138[2];

    virtual void resetFlick();
    virtual void resetButton();
    virtual void resetTrigger();
    virtual void resetMainStickX();
    virtual void setMainStickX(float);
    virtual void resetMainStickY();
    virtual void setMainStickY(float);
    virtual void resetMainStick();
    virtual void resetSubStickX();
    virtual void resetSubStickY();
    virtual void resetSubStick();
    virtual void reset();
    virtual void update(void*, bool);
    virtual void resetFlickX();
    virtual void resetFlickY();
    virtual void setOff(bool);
    virtual float getStickX();
    virtual float getStickPrevX();
    virtual float getStickY();
    virtual float getStickPrevY();
    virtual float getFlickX();
    virtual float getFlickXDir();
    virtual float getFlickY();
    virtual float getFlickYDir();
    virtual float getFlickNoResetX();
    virtual float getFlickNoResetY();
    virtual float getFlickAfterX();
    virtual float getFlickAfterXDir();
    virtual float getFlickAfterY();
    virtual float getSubStickX();
    virtual float getSubStickPrevX();
    virtual float getSubStickY();
    virtual float getSubStickPrevY();
    virtual int getTrigger();
    virtual u8 getTriggerCount();
    virtual u8 getTriggerCountPrev();
    virtual int getButton();
    virtual int getRelease();
    virtual float getLr();
    virtual u8 getFlickBonus();
    virtual u8 getFlickBonusLr();
    virtual void resetFlickBonus();
    virtual void resetFlickBonusLr();
    virtual ~soControllerImpl();
};
static_assert(sizeof(soControllerImpl) == 140, "Class is wrong size!");
