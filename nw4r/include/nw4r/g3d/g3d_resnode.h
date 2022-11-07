#pragma once

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

        class ResNode {

        public:
            ResNodeData* m_nodeData;
        };

    } // namespace g3d
} // namespace nw4