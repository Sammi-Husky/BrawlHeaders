#pragma once

#include <StaticAssert.h>
#include <types.h>

/* Masks for the bitfields for each button in gfPadButtons */
#define GF_PAD_BUTTON_BIT_START 0x1000
#define GF_PAD_BUTTON_BIT_Y 0x0800
#define GF_PAD_BUTTON_BIT_X 0x0400
#define GF_PAD_BUTTON_BIT_B 0x0200
#define GF_PAD_BUTTON_BIT_A 0x0100
#define GF_PAD_BUTTON_BIT_L 0x0040
#define GF_PAD_BUTTON_BIT_R 0x0020
#define GF_PAD_BUTTON_BIT_Z 0x0010
#define GF_PAD_BUTTON_BIT_DPAD_UP 0x0008
#define GF_PAD_BUTTON_BIT_DPAD_DOWN 0x0004
#define GF_PAD_BUTTON_BIT_DPAD_LEFT 0x0002
#define GF_PAD_BUTTON_BIT_DPAD_RIGHT 0x0001

#pragma push
#pragma enumsalwaysint off // These are char enums.
enum gfPadError {
    GF_PAD_ERROR_NONE = 0,
    GF_PAD_ERROR_NO_CONTROLLER = -1,
    GF_PAD_ERROR_NOT_READY =  -2,
    GF_PAD_ERROR_TRANSFER = -3
};

enum gfPadType {
    GF_PAD_TYPE_GCC = 0,
    GF_PAD_TYPE_WII_CLASSIC = 1,
    GF_PAD_TYPE_WIIMOTE = 2,
    GF_PAD_TYPE_WIIMOTE_NUNCHUK = 3
};
#pragma pop

union gfPadButtons {
    u32 bits;
    struct {
        u16 _padding;
        u16 _0x0: 3;
        u16 m_start: 1;
        u16 m_y: 1;
        u16 m_x: 1;
        u16 m_b: 1;
        u16 m_a: 1;
        u16 _0x9: 1;
        u16 m_l: 1;
        u16 m_r: 1;
        u16 m_z: 1;
        u16 m_dpadUp: 1;
        u16 m_dpadDown: 1;
        u16 m_dpadRight: 1;
        u16 m_dpadLeft: 1;
    };
};

struct gfPadStatus {
    gfPadButtons m_buttonsCurrentFrame; // 0x0
    gfPadButtons m_buttonsCurrentFrame2; // 0x4
    gfPadButtons m_buttonsHeld; // 0x8
    gfPadButtons m_buttonsPressedThisFrame; // 0xC
    gfPadButtons m_buttonsReleasedThisFrame; // 0x10
    gfPadButtons m_buttonsPressedThisFrame2; // 0x14

    /*
     * These floats all have to do with wiimote motion tracking. I can't be bothered
     * at the moment to figure out precisely what values they correspond to, but
     * they are always 0 if you are using a gamecube controller.
     */
    float _0x18;
    float _0x1c;
    float _0x20;
    float _0x24;
    float _0x28;
    float _0x2c;

    char m_stickX;
    char m_stickY;
    char m_substickX;
    char m_substickY;
    char m_lTriggerAnalog;
    char m_rTriggerAnalog;
    char _0x36;

    char _0x37;
    gfPadError m_error;
    char _0x39;
    char _0x3a;
    char _0x3b;

    gfPadType m_controllerType;

    void init();
    void clamp();
    void update(gfPadStatus* previousPad);
    bool isButtonAOn();
    bool isButtonAOnEdge();
    bool isButtonAOnRepeat();
    bool isButtonStartOnEdge();

    void convSysStatusToMenuStatus(gfPadStatus* destination);

};
static_assert(sizeof(gfPadStatus) == 0x40, "Class is the wrong size!");