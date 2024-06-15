#pragma once

#include <StaticAssert.h>
#include <nw4r/g3d/g3d_anmchr.h>
#include <nw4r/g3d/g3d_anmscn.h>
#include <nw4r/g3d/g3d_rescommon.h>
#include <nw4r/g3d/g3d_resdict.h>
#include <nw4r/g3d/g3d_resfile.h>
#include <types.h>

namespace nw4r {
    namespace g3d {
        struct ResFileHeaderData {
            char magic[4];
            u16 endian;
            u16 version;
            u32 fileSize;
            u16 headerSize;
            u16 dataBlocks;
        };

        struct ResTopLevelDictData {
            ResBlockHeaderData header;
            ResDicData data;
        };

        struct ResFileData {
            ResFileHeaderData fileHeader;
            ResTopLevelDictData dict;
        };

        // NOTE:
        // This is supposed to be a class,
        // but until we know ResFile's size
        // we can treat it as an opaque pointer
        class ResFile : public ResCommon<ResFileData> {
            /* data */
        public:
            inline ResFile() : ResCommon() {}
            inline ResFile(ResFileData* data) : ResCommon(data) {}
            inline ResFile(void* data) : ResCommon(data) {}

            static void Init(void* arg);

            u32 GetResMdlNumEntries();
            u32 GetResAnmChrNumEntries();
            u32 GetResAnmClrNumEntries();
            u32 GetResAnmVisNumEntries();
            u32 GetResAnmTexPatNumEntries();
            u32 GetResAnmTexSrtNumEntries();
            u32 GetResAnmShpNumEntries();
            u32 GetResAnmScnNumEntries();

            ResAnmChr GetResAnmChr(int index);
            ResAnmClr GetResAnmClr(int index);
            ResAnmVis GetResAnmVis(int index);
            ResAnmTexPat GetResAnmTexPat(int index);
            ResAnmTexSrt GetResAnmTexSrt(int index);
            ResAnmShp GetResAnmShp(int index);
            ResAnmScn GetResAnmScn(int index);
        };
    } // namespace g3d
} // namespace nw4