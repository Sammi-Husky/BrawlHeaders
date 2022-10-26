
#include <types.h>

namespace nw4r {
    namespace g3d {

        // NOTE:
        // This is supposed to be a class,
        // but until we know ResMdl's size
        // we can treat it as an opaque pointer
        class ResMdl{
            /* data */
        };

        u32 GetResNodeNumEntries(ResMdl** resMdl);



    } // namespace g3d
} // namespace nw4