#pragma once

#include <gf/gf_model.h>
#include <types.h>

namespace nw4r {
    namespace g3d {

        // NOTE:
        // This is supposed to be a class,
        // but until we know ResFile's size
        // we can treat it as an opaque pointer
        struct ResFile {
            /* data */
        };

        u32 GetResMdlNumEntries(ResFile** file);
        u32 GetResAnmChrNumEntries(gfModelAnimation* modelAnim);

    } // namespace g3d
} // namespace nw4