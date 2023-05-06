#pragma once

#include <types.h>

class grTenganEvent {
public:
    enum State {
        NoEvent = 0,
        Running = 1,
        ReadyEnd = 2
    };

    float m_framesElapsed;      // +0x0
    float m_minFrames;          // +0x4
    float m_maxFrames;          // +0x8
    float m_framesLeft;         // +0xC
    float m_manualFramesLeft;
    u8 unk14[0x90];
    State m_state;              // +0xA4
    s32 m_phase;                // +0xA8

    grTenganEvent();
    ~grTenganEvent();
    void update(float delta);
    void set(float min, float max);
    bool start();
    void end();
    bool isEvent() const;
    bool isReadyEnd() const;
    s32 getPhase() const;
    void setPhase(s32 phase);
};
static_assert(sizeof(grTenganEvent) == 172, "Class is wrong size!");