#pragma once

#include <nw4r/g3d/g3d_rescommon.h>
#include <mt/mt_vector.h>
#include <types.h>
#include <StaticAssert.h>

namespace nw4r {
    namespace g3d {

        struct ResNodeData {
            public:
                char _0[8];
                u32 m_nodeNameStrOffset;
                u32 m_nodeIndex;
                char _32[16];
                Vec3f m_scale;
                Vec3f m_rotation;
                Vec3f m_translation;
                char _68[140];

                STATIC_CHECK(sizeof(ResNodeData) == 208)
        };

        class ResNode : public ResCommon<ResNodeData> {
            /* data */
            public:
                void SetTranslate(float x, float y, float z);
        };

    } // namespace g3d
} // namespace nw4