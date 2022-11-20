#pragma once

#include <nw4r/g3d/g3d_rescommon.h>
#include <mt/mt_vector.h>
#include <types.h>

namespace nw4r {
    namespace g3d {

        struct ResNodeData {
            public:
                char _0[32];
                Vec3f m_scale;
                Vec3f m_rotation;
                Vec3f m_translation;
                char _68[140];
        };

        class ResNode : public ResCommon<ResNodeData> {
            /* data */
            public:
                void SetTranslate(float x, float y, float z);
        };

    } // namespace g3d
} // namespace nw4