#pragma once

#include <types.h>

#define INPUT_PAD_BUTTON_MASK_ATTACK 0x1
#define INPUT_PAD_BUTTON_MASK_SPECIAL 0x2
#define INPUT_PAD_BUTTON_MASK_JUMP 0x4
#define INPUT_PAD_BUTTON_MASK_GUARD 0x8
#define INPUT_PAD_BUTTON_MASK_STOCK_SHARE 0x10
#define INPUT_PAD_BUTTON_MASK_SMASH 0x20
#define INPUT_PAD_BUTTON_MASK_DIR_L 0x40
#define INPUT_PAD_BUTTON_MASK_DIR_Hi 0x80
#define INPUT_PAD_BUTTON_MASK_DIR_R 0xC0
#define INPUT_PAD_BUTTON_MASK_CSTICK 0x100
#define INPUT_PAD_BUTTON_MASK_APPEAL_HI 0x400
#define INPUT_PAD_BUTTON_MASK_APPEAL_S 0x800
#define INPUT_PAD_BUTTON_MASK_APPEAL_LW 0x1000
#define INPUT_PAD_BUTTON_MASK_APPEAL_S_L 0x2000
#define INPUT_PAD_BUTTON_MASK_APPEAL_S_R 0x4000
#define INPUT_PAD_BUTTON_MASK_FLICK_JUMP 0x8000

struct ipPadButton {

    enum Dir {
        Dir_Lw = 0x0,
        Dir_L = 0x1,    // left dpad
        Dir_Hi = 0x2,   // up dpad or jump
        Dir_R = 0x3,    // right dpad
    };

    union {
        struct {
            unsigned int m_mask;
        };
        struct {
            unsigned short : 16;
            bool m_flickJump : 1;
            bool m_appealSR : 1;
            bool m_appealSL : 1;
            bool m_appealLw : 1;
            bool m_appealS : 1;
            bool m_appealHi : 1;
            bool _6 : 1;
            bool m_cStick : 1;
            Dir m_dir : 2;
            bool m_smash : 1;
            bool m_stockShare : 1;
            bool m_guard : 1;
            bool m_jump : 1;
            bool m_special : 1;
            bool m_attack : 1;
        };
    };

    inline ipPadButton() { };
    inline ipPadButton(u32 mask) : m_mask(mask) {};
};
static_assert(sizeof(ipPadButton) == 4, "Class is wrong size!");

struct ipPadTrigger {
    float m_l;
    float m_r;
};
static_assert(sizeof(ipPadTrigger) == 8, "Class is wrong size!");

class Input {
    char _0[4];
public:
    virtual ~Input();
    virtual void update();
    virtual float getStickMain();
    virtual float getStickSub();
    virtual ipPadButton getButton();
    virtual ipPadTrigger getTrigger();
    virtual int getContNo();
    virtual void setRumble(u32, u32, int, u8);   // TODO:: Verify parameters
    virtual void stopRumble();
    virtual void removeRumble();
    virtual void removeRumbleId(int, int); // TODO:: Verify parameters
    virtual void removeRumbleMask(u32);
};
static_assert(sizeof(Input) == 8, "Class is wrong size!");