#pragma once

#include <nw4r/g3d/g3d_resmat.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

namespace nw4r {
    namespace g3d {

        // TODO ScnMdlSimple and all subsequent classes
        class ScnMdl : public ScnMdlSimple {
        private:
            char _spacer[80];

        public:
            class CopiedMatAccess {
            private:
                ScnMdl* m_scnMdl;
                u32 m_MatID;
                char spacer[0x28];

            public:
                CopiedMatAccess(ScnMdl* scnMdl, u32 matID);
                ResMatTevColor GetResMatTevColor(bool sync);
            };

            // TODO
            virtual u32 IsDerivedFrom(int* unk1);
            virtual void G3dProc(int unk1, int unk2, int unk3);
            virtual ~ScnMdl();
        };
    }
}

// Size: 392