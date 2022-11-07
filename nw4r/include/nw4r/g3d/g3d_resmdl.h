#pragma once

#include <nw4r/g3d/g3d_rescommon.h>
#include <nw4r/g3d/g3d_resmat.h>
#include <nw4r/g3d/g3d_resnode.h>
#include <types.h>

namespace nw4r {
    namespace g3d {

        struct ResMdlData; // TODO

        class ResMdl : public ResCommon<ResMdlData> {
            /* data */

        public:
            ResMat GetResMat(const char* name) const;
            u32 GetResNodeNumEntries();
            ResNode GetResNode(const u64 nodeIndex) const;

        };

    } // namespace g3d
} // namespace nw4