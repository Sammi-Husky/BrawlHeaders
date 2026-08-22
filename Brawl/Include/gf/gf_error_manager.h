#pragma once

#include <StaticAssert.h>
#include <gf/gf_homemenu.h>
#include <gf/gf_pad_system.h>
#include <ms/ms_message.h>
#include <mv/mv_movie_player.h>
#include <nw4r/ut/ut_Color.h>
#include <types.h>
#include <snd/snd_system.h>

class gfErrorManager {
public:
    bool m_isFatal : 1;
    bool m_isSuspended : 1; // i.e., waiting for you to re-insert the disc
    bool m_unused : 1;
    bool m_isMoviePaused : 1;
    s32 m_errorCode : 8;
    s32 m_reasonCode; // A subcode for certain kinds of errors
    nw4r::ut::Color m_msgBgColor;
    nw4r::ut::Color m_msgTextColor;
    void* m_fontData;
    Message* m_msgScreen;
    u32 m_updateDone;

    // UBFIX: This constructor does not initialize m_updateDone
    gfErrorManager();
    void update();
    void renderPre();
    void render();
    void notifyError(u32 errorCode, u32 reasonCode);
    void notifyErrorRecovery(bool skip);

    bool isRecoverable(u32 code) const {
        return (code == 1 || code == 2 || code == 3);
    }

    void notifyErrorHelper(bool& res, u32 errCode) {
        if (m_isSuspended) {
            if (m_isFatal)
                return;
            res = !isRecoverable(errCode) ? 1 : res;
        } else {
            if (mvMoviePlayer::getInstance()) {
                m_isMoviePaused = mvMoviePlayer::getInstance()->isPause();
                if (!m_isMoviePaused)
                    mvMoviePlayer::getInstance()->setPause();
            }
            if (g_sndSystem)
                g_sndSystem->specialPause();
            if (g_gfHomeMenu)
                g_gfHomeMenu->kill();
            res = true;
            m_isSuspended = true;
            g_gfPadSystem->pauseNotify();
        }
    }

    static gfErrorManager* getInstance();
    static gfErrorManager* create();
};
static_assert(sizeof(gfErrorManager) == 0x1C, "Class is the wrong size!");
