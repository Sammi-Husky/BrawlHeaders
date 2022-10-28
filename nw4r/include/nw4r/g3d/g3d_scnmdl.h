#pragma once

#include <nw4r/g3d/g3d_scnmdlsmpl.h>

namespace nw4r {
    namespace g3d {

        class ScnMdl : public ScnMdlSimple {
        public:
            class CopiedMatAccess {
            private:
                ScnMdl* m_scnMdl;
                u32 m_MatID;
                char spacer[0x28];

            public:
                CopiedMatAccess(ScnMdl* scnMdl, u32 matID);
            };

            // TODO
            virtual u32 IsDerivedFrom(int* unk1);

            virtual void G3dProc(int unk1, int unk2, int unk3);

            virtual ~ScnMdl();

            char _spacer[80];
        };
    }
}

// Size: 392