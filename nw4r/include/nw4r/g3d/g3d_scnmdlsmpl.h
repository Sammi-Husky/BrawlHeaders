#pragma once

#include <nw4r/g3d/g3d_scnobj.h>
#include <nw4r/g3d/g3d_resmdl.h>

namespace nw4r {
    namespace g3d {

        class ScnMdlSimple : public ScnObj {
        public:
            // TODO
            virtual u32 IsDerivedFrom(int *unk1);

            virtual void G3dProc(int unk1, int unk2, int unk3);

            virtual ~ScnMdlSimple();

            char _spacer[12];
            ResMdl* resMdl;
            char _spacer2[76];
        };
    }
}

// Size: 312
