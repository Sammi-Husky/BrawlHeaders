#pragma once

#include <gf/gf_model.h>
#include <types.h>

namespace nw4r {
    namespace g3d {

        struct ResFileData; // TODO

        // NOTE:
        // This is supposed to be a class,
        // but until we know ResFile's size
        // we can treat it as an opaque pointer
        class ResFile : public ResCommon<ResFileData> {
            /* data */
        public:
            u32 GetResMdlNumEntries();
            u32 GetResAnmChrNumEntries();
        };

    } // namespace g3d
} // namespace nw4