#pragma once

#include <nw4r/g3d/g3d_rescommon.h>

namespace nw4r {
    namespace g3d {

        struct GenModeData {
            u8 m_numTexGens;
            u8 m_numLightChans;
            u8 m_activeTevStages;
            u8 m_numIndTexStages;
        };
        struct MiscData {
            u8 m_depthTestBeforeTexture;
            s8 m_lightSet;
            s8 m_fogSet;
            u8 m_pad;
            u8 m_indirectMethod1;
            u8 m_indirectMethod2;
            u8 m_indirectMethod3;
            u8 m_indirectMethod4;
            s8 m_normMapRefLight1;
            s8 m_normMapRefLight2;
            s8 m_normMapRefLight3;
            s8 m_normMapRefLight4;
        };

        struct ResMatData {
            u32 m_size;
            s32 m_offToMdl;
            s32 m_name;
            u32 m_id;
            u32 m_flags;

            GenModeData m_genData;
            MiscData m_misc;

            s32 m_offToShaders;
            u32 m_numTextures;
            s32 m_offToMatRefs;

            s32 m_offToFurData;
            s32 m_offToUserData;
            s32 m_offToDisplayLists;

            // there may be more after this? This is just file format
            // Needs verfication in game
        };

        class ResMat : public ResCommon<ResMatData> {
        };
    } // namespace g3d
} // namespace nw4r
