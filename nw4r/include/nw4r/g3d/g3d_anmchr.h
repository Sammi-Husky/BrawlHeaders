#pragma once

#include <types.h>

namespace nw4r {
    namespace g3d {

        struct CHR0 {
            //char* getString() {
            //    auto thisINT = reinterpret_cast<unsigned int>(this);
            //    return (char*) (thisINT + this->stringOffset);
            //}

            char _spacer[0x14];
            unsigned int m_stringOffset;
            char _spacer2[0x1C - 0x14 - 4];
            unsigned short m_animLength;
        };

        class AnmObjChrRes {
        public:
            virtual u32 IsDerivedFrom(int* unk1);

            virtual void G3dProc(int unk1, int unk2, int unk3);

            virtual ~AnmObjChrRes();

            virtual int* GetTypeObj();

            virtual int GetTypeName();

            virtual void SetFrame(float frame);

            virtual float GetFrame();

            virtual void UpdateFrame();

            virtual void SetUpdateRate(float updateRate);

            virtual float GetUpdateRate();

            virtual int Bind(int* unk1);

            virtual void Release();

            virtual int* GetResult(int* unk1, int unk2);

            virtual int Attach(int unk1, int* unk2); // TODO
            virtual int* Detach(int unk1);           // TODO
            virtual void DetachAll();

            virtual void SetWeight(float unk1, int* unk2); //TODO
            virtual float GetWeight(int unk1);             // TODO
            virtual int Bind(int* unk1, u32 unk2, int unk3);

            virtual void Release(int* unk1, u32 unk2, int unk3);

            AnmObjChrRes* Construct(int* unk1, int* unk2, int* unk3, int* unk4, u32 unk5);

            char _spacer[40];

            CHR0* m_anmChrFile;

            char _spacer2[4];
        };
    }
}

// Size: 52