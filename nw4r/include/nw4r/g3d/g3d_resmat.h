#pragma once

#include <GX.h>
#include <nw4r/g3d/g3d_rescommon.h>
#include <types.h>

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

        struct ResTevColorDL {
            union {
                struct
                {
                    u8 m_tevColor[3][20];
                    u8 _padding[4];
                    u8 m_tevKColor[4][10];
                    u8 _padding2[0x18];
                } dl;
                u8 data[0x80];
            };
        };

        class ResMatTevColor : public ResCommon<ResTevColorDL> {
        private:
        public:
            void GXSetTevColor(u32 id, GXColor color);
        };

        class ResMat : public ResCommon<ResMatData> {
        public:
            void DCStore(bool sync);
        };
    } // namespace g3d
} // namespace nw4r
