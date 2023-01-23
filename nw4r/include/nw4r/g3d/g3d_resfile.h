#pragma once

#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmscn.h>
#include <nw4r/g3d/g3d_rescommon.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <StaticAssert.h>
#include <types.h>

namespace nw4r
{
    namespace g3d
    {

        struct ResFileData; // TODO

        // NOTE:
        // This is supposed to be a class,
        // but until we know ResFile's size
        // we can treat it as an opaque pointer
        // class ResFile : public ResCommon<ResFileData>
        //{
        //    /* data */
        // public:
        //    inline ResFile(ResFileData *data) : ResCommon(data) {}
        //
        //    static void Init(void *arg);
        //    u32 GetResMdlNumEntries();
        //    u32 GetResAnmChrNumEntries();
        //    CHR0 *GetResAnmChr(int index);
        //    SCN0 *GetResAnmScn(int index);
        //};
        //
        // STATIC_CHECK(sizeof(ResFile) == 0x04)
        class ResFile
        {
        public:
            static void Init(void *arg);
            u32 GetResMdlNumEntries();
            u32 GetResAnmChrNumEntries();
            CHR0 *GetResAnmChr(int index);
            SCN0 *GetResAnmScn(int index);
        };
    } // namespace g3d
} // namespace nw4