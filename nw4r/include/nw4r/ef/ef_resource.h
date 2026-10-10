#pragma once

#include <nw4r/ut/ut_list.h>
#include <types.h>

namespace nw4r {
    namespace ef {

        struct EffectProject;
        struct TextureProject;

        class Resource {
        public:
            ut::List m_breffList;
            u32 m_numEmitter;
            ut::List m_breftList;
            u32 m_numTexture;

            static Resource* GetInstance();

            EffectProject* Add(u8* data);
            TextureProject* AddTexture(u8* data);
            u32 RelocateCommand(EffectProject* effProject, TextureProject* texProject,
                                EffectProject* commonEffProject, TextureProject* commonTexProject);
            bool RemoveEffectProject(EffectProject* effProject);
            bool RemoveTextureProject(TextureProject* texProject);
        };

    } // namespace ef
} // namespace nw4r
