#pragma once

#include <types.h>

namespace nw4r {
    namespace g3d {

        struct SHP0 {
            char _spacer2[0x20];
            unsigned short m_animLength;
        };

        class AnmObjShpRes {
        public:
            virtual u32 IsDerivedFrom(int *unk1);

            virtual void G3dProc(int unk1, int unk2, int unk3);

            virtual ~AnmObjShpRes();

            virtual int *GetTypeObj();

            virtual int GetTypeName();

            virtual void SetFrame(float frame);

            virtual float GetFrame();

            virtual void UpdateFrame();

            virtual void SetUpdateRate(float updateRate);

            virtual float GetUpdateRate();

            virtual int Bind(int *unk1);

            virtual void Release();

            virtual int *GetResult(int *unk1, int unk2);

            virtual int Attach(int unk1, int *unk2); // TODO
            virtual int *Detach(int unk1);           // TODO
            virtual void DetachAll();

            virtual void SetWeight(float unk1, int *unk2); //TODO
            virtual float GetWeight(int unk1);             // TODO

            AnmObjShpRes *Construct(int *unk1, int *unk2, int *unk3, int *unk4, u32 unk5);

            char _spacer[40];

            SHP0* m_anmShpFile;

            char _spacer3[8];

            STATIC_CHECK(sizeof(AnmObjShpRes) == 56)
        };
    }
}

// Size: 56