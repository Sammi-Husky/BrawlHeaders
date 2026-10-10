#pragma once

#include <StaticAssert.h>
#include <nw4r/g3d/g3d_rescommon.h>
#include <revolution/GX/GXTypes.h>
#include <types.h>

namespace nw4r {
    namespace g3d {

        struct ResTexData {
            char magic[4];
            u32 size;
            u32 revision;
            s32 toResFileData;
            s32 toTexData;
            s32 name;
            u32 flag;
            u16 width;
            u16 height;
        };

        class ResTex : public ResCommon<ResTexData> {

            /* data */
            public:
                inline ResTex() : ResCommon() {}
                inline ResTex(void* data) : ResCommon(data) {}

                bool IsCIFmt() const { return ref().flag & 1; }

                bool GetTexObjParam(void** texData, u16* width, u16* height, GXTexFmt* fmt,
                                    f32* minLod, f32* maxLod, GXBool* mipmap) const;
                bool GetTexObjCIParam(void** texData, u16* width, u16* height, GXCITexFmt* fmt,
                                      f32* minLod, f32* maxLod, GXBool* mipmap) const;
        };

    } // namespace g3d
} // namespace nw4r
