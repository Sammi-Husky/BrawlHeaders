#pragma once

#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmscn.h>
#include <StaticAssert.h>
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

            inline ResFile(ResFileData* data) : ResCommon(data) {}

            u32 GetResMdlNumEntries();
            u32 GetResAnmChrNumEntries();
            CHR0* GetResAnmChr(int index);
            SCN0* GetResAnmScn(int index);
        };

        STATIC_CHECK(sizeof(ResFile) == 0x04)

    } // namespace g3d
} // namespace nw4